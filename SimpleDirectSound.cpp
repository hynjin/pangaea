#include "SimpleDirectSound.h"


SimpleDirectSound::BufferNode::BufferNode( unsigned nID , LPDIRECTSOUNDBUFFER pIDirectSoundBuffer )
{
	m_nID = nID;
	m_pIDirectSoundBuffer = pIDirectSoundBuffer;
}

void SimpleDirectSound::BufferNode::Release()
{
	if ( m_pIDirectSoundBuffer )
	{
		m_pIDirectSoundBuffer ->Release();
		m_pIDirectSoundBuffer = NULL;
	}
}

unsigned SimpleDirectSound::BufferNode::getID()
{
	return m_nID;
}
LPDIRECTSOUNDBUFFER SimpleDirectSound::BufferNode::getIDirectSoundBuffer()
{
	return m_pIDirectSoundBuffer;
}




SimpleDirectSound::SimpleDirectSound(void)
{
	m_pIDirectSound= NULL;
	m_pIDirectSoundBuffers .clear();
}
SimpleDirectSound::~SimpleDirectSound(void)
{
	Release();
}

bool SimpleDirectSound::Initialize( HWND hWnd )
{
	if ( FAILED( DirectSoundCreate8( NULL , &m_pIDirectSound , NULL ) ) ) return false;
	if ( FAILED( m_pIDirectSound ->SetCooperativeLevel( hWnd , DSSCL_PRIORITY ) ) )
	{
		Release();
		return false;
	}
	return true;
}
bool SimpleDirectSound::Release()
{
	for ( unsigned loop = 0 ; loop < m_pIDirectSoundBuffers .size() ; ++loop )
	{
		m_pIDirectSoundBuffers[ loop ] .Release();
	}
	m_pIDirectSoundBuffers .clear();

	if ( m_pIDirectSound )
	{
		m_pIDirectSound ->Release();
		m_pIDirectSound = NULL;
	}
	return true;
}

bool SimpleDirectSound::LoadWave( LPWSTR pszFileName , unsigned &nID )
{
	HMMIO hMmio;
	MMCKINFO ckInfoRIFF;
	MMCKINFO ckInfoFmt;
	PCMWAVEFORMAT PCMWaveFormat;
	WAVEFORMATEX WaveFormatEx;

	hMmio = mmioOpenW( pszFileName , NULL , MMIO_ALLOCBUF | MMIO_READ );
	if ( !hMmio ) return false;

	ckInfoRIFF .fccType = mmioFOURCC( 'W' , 'A' , 'V' , 'E' );
	if ( mmioDescend( hMmio , &ckInfoRIFF , NULL , MMIO_FINDRIFF ) )
	{
		mmioClose( hMmio , 0 );
		return false;
	}
	ckInfoFmt .ckid = mmioFOURCC( 'f' , 'm' , 't' , ' ' );
	if ( mmioDescend( hMmio , &ckInfoFmt , &ckInfoRIFF , MMIO_FINDCHUNK ) )
	{
		mmioClose( hMmio , 0 );
		return false;
	}
	if( mmioRead( hMmio , ( HPSTR )&PCMWaveFormat , sizeof( PCMWaveFormat ) ) != sizeof( PCMWaveFormat ) )
	{
		mmioClose( hMmio , 0 );
		return false;
	}
	memcpy( &WaveFormatEx , &PCMWaveFormat , sizeof( PCMWaveFormat) );
	WaveFormatEx .cbSize = 0;

	if ( mmioAscend( hMmio , &ckInfoFmt , 0 ) )
	{
		mmioClose( hMmio , 0 );
		return false;
	}
	ckInfoFmt .ckid = mmioFOURCC( 'd' , 'a' , 't' , 'a' );
	if ( mmioDescend( hMmio , &ckInfoFmt , &ckInfoRIFF , MMIO_FINDCHUNK ) )
	{
		mmioClose( hMmio , 0 );
		return false;
	}
	BYTE *pData = new BYTE[ ckInfoFmt .cksize ];

	if ( !pData )
	{
		mmioClose( hMmio , 0 );
		return false;
	}
	if ( mmioRead( hMmio , ( LPSTR )pData , ckInfoFmt .cksize ) != ckInfoFmt .cksize )
	{
		mmioClose( hMmio , 0 );
		return false;
	}
	mmioClose( hMmio , 0 );
	
	DSBUFFERDESC DirectSoundBufferDesc;

	ZeroMemory( &DirectSoundBufferDesc , sizeof( DSBUFFERDESC ) );

	DirectSoundBufferDesc .dwSize = sizeof( DSBUFFERDESC );
	DirectSoundBufferDesc .dwFlags = DSBCAPS_STATIC | DSBCAPS_LOCSOFTWARE | DSBCAPS_CTRLPOSITIONNOTIFY;
	DirectSoundBufferDesc .dwBufferBytes = ckInfoFmt .cksize;
	DirectSoundBufferDesc .lpwfxFormat = &WaveFormatEx;

	LPDIRECTSOUNDBUFFER pIDirectSoundBuffer;

	if ( FAILED( m_pIDirectSound ->CreateSoundBuffer( &DirectSoundBufferDesc , &pIDirectSoundBuffer , NULL ) ) ) return false;

	VOID *pBufferFirst;
	VOID *pBufferSecond;
	DWORD dwLengthFirst;
	DWORD dwLengthSecond;

	if ( FAILED( pIDirectSoundBuffer ->Lock( 0 , ckInfoFmt .cksize , &pBufferFirst , &dwLengthFirst , &pBufferSecond , &dwLengthSecond , 0 ) ) )
	{
		pIDirectSoundBuffer ->Release();
		return false;
	}
	memcpy( pBufferFirst , pData , dwLengthFirst );
	memcpy( pBufferSecond , pData + dwLengthFirst , dwLengthSecond );

	delete[] pData;

	pIDirectSoundBuffer ->Unlock( pBufferFirst , dwLengthFirst , pBufferSecond , dwLengthSecond );
	
	nID = m_uCount;
	++m_uCount;
	m_pIDirectSoundBuffers .push_back( BufferNode( nID , pIDirectSoundBuffer ) );
	return true;
}
bool SimpleDirectSound::UnloadWave( unsigned nID )
{
	std::vector<BufferNode>::iterator temp = m_pIDirectSoundBuffers .begin();

	for ( unsigned loop = 0 ; loop < m_pIDirectSoundBuffers .size() ; ++loop )
	{
		if ( m_pIDirectSoundBuffers[ loop ] .getID() == nID )
		{
			m_pIDirectSoundBuffers[ loop ] .Release();
			m_pIDirectSoundBuffers .erase( temp );
			return true;
		}
		++temp;
	}
	return false;
}

bool SimpleDirectSound::Play( unsigned nID , bool bLoop)
{
	for ( unsigned loop = 0 ; loop < m_pIDirectSoundBuffers .size() ; ++loop )
	{
		if ( m_pIDirectSoundBuffers[ loop ] .getID() == nID )
		{
			if ( bLoop )
			{
				if ( FAILED( m_pIDirectSoundBuffers[ loop ] .getIDirectSoundBuffer() ->Play( 0 , 0 , 1 ) ) ) return false;
			}
			else
			{
				if ( FAILED( m_pIDirectSoundBuffers[ loop ] .getIDirectSoundBuffer() ->Play( 0 , 0 , 0 ) ) ) return false;
			}
			return true;
		}
	}
	return false;
}
bool SimpleDirectSound::Pause( unsigned nID )
{
	for ( unsigned loop = 0 ; loop < m_pIDirectSoundBuffers .size() ; ++loop )
	{
		if ( m_pIDirectSoundBuffers[ loop ] .getID() == nID )
		{
			if ( FAILED( m_pIDirectSoundBuffers[ loop ] .getIDirectSoundBuffer() ->Stop() ) ) return false;
			return true;
		}
	}
	return false;
}
bool SimpleDirectSound::Stop( unsigned nID )
{
	for ( unsigned loop = 0 ; loop < m_pIDirectSoundBuffers .size() ; ++loop )
	{
		if ( m_pIDirectSoundBuffers[ loop ] .getID() == nID )
		{
			if ( FAILED( m_pIDirectSoundBuffers[ loop ] .getIDirectSoundBuffer() ->Stop() ) ) return false;
			m_pIDirectSoundBuffers[ loop ] .getIDirectSoundBuffer() ->SetCurrentPosition( 0 );
			return true;
		}
	}
	return false;
}

bool SimpleDirectSound::Volume( unsigned nID , int nVolume )
{
	for ( unsigned loop = 0 ; loop < m_pIDirectSoundBuffers .size() ; ++loop )
	{
		if ( m_pIDirectSoundBuffers[ loop ] .getID() == nID )
		{
			if ( FAILED( m_pIDirectSoundBuffers[ loop ] .getIDirectSoundBuffer() ->SetVolume( DSVOLUME_TO_DB( nVolume ) ) ) )
			{
				return false;
			}
			return true;
		}
	}
	return false;
}
bool SimpleDirectSound::Panning( unsigned nID , int nPanning )
{
	for ( unsigned loop = 0 ; loop < m_pIDirectSoundBuffers .size() ; ++loop )
	{
		if ( m_pIDirectSoundBuffers[ loop ] .getID() == nID )
		{
			if ( FAILED( m_pIDirectSoundBuffers[ loop ] .getIDirectSoundBuffer() ->SetPan( nPanning ) ) )
			{
				return false;
			}
			return true;
		}
	}
	return false;
}

int SimpleDirectSound::Status( unsigned nID )
{
	for ( unsigned loop = 0 ; loop < m_pIDirectSoundBuffers .size() ; ++loop )
	{
		if ( m_pIDirectSoundBuffers[ loop ] .getID() == nID )
		{
			DWORD temp;
			m_pIDirectSoundBuffers[ loop ] .m_pIDirectSoundBuffer ->GetStatus( &temp );

			if ( DSBSTATUS_PLAYING & temp )
			{
				return 1;
			}
			return 0;
		}
	}
	return -1;
}