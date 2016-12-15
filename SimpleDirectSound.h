#pragma once
#pragma comment ( lib , "dsound.lib" )
#pragma comment ( lib , "winmm.lib" )
#include <dsound.h>
#include <Windows.h>
#include <MMSystem.h>
#include <vector>
#define DSVOLUME_TO_DB(volume) ((DWORD)(-30*(100-volume)))




class SimpleDirectSound
{
	class BufferNode
	{
		unsigned m_nID;
	public:
		LPDIRECTSOUNDBUFFER m_pIDirectSoundBuffer;
		BufferNode( unsigned nID , LPDIRECTSOUNDBUFFER pIDirectSoundBuffer );

		void Release();

		unsigned getID();
		LPDIRECTSOUNDBUFFER getIDirectSoundBuffer();
	};

	unsigned m_uCount;

	LPDIRECTSOUND8 m_pIDirectSound;
public:
	std::vector<BufferNode> m_pIDirectSoundBuffers;
	SimpleDirectSound(void);
	~SimpleDirectSound(void);

	bool Initialize( HWND hWnd );
	bool Release();

	bool LoadWave( LPWSTR pSrcFile , unsigned &nID );
	bool UnloadWave( unsigned nID );

	bool Play( unsigned nID , bool bLoop );
	bool Pause( unsigned nID );
	bool Stop( unsigned nID );

	bool Volume( unsigned nID , int nVolume );
	bool Panning( unsigned nID , int nPanning );

	int Status( unsigned nID );
};

