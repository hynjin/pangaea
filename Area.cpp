#include "Area.h"


Area::Area(void)
{
	nNtr = 0;

	for ( unsigned loopSj = 0 ; loopSj < 4 ; ++loopSj )
	{
		int x;
		int y;

		nSj[ loopSj ] = 0;

		for ( unsigned loopSjArea = 0 ; loopSjArea < 12 ; ++loopSjArea )
		{
			switch ( loopSj )
			{
			case 0:
				x=576;
				y=64;
				break;
			case 1:
				x=128;
				y=448;
				break;
			case 2:
				x=832;
				y=448;
				break;
			case 3:
				x=384;
				y=576;
				break;
			}
			switch ( loopSjArea )
			{
			case 0:
				nSjAreaX[ loopSj ][ loopSjArea ] = x - 64;
				nSjAreaY[ loopSj ][ loopSjArea ] = y - 64;
				nSjAreaZ[ loopSj ][ loopSjArea ] = 0;
				break;
			case 1:
				nSjAreaX[ loopSj ][ loopSjArea ] = x;
				nSjAreaY[ loopSj ][ loopSjArea ] = y - 64;
				nSjAreaZ[ loopSj ][ loopSjArea ] = 0;
				break;
			case 2:
				nSjAreaX[ loopSj ][ loopSjArea ] = x + 64;
				nSjAreaY[ loopSj ][ loopSjArea ] = y - 64;
				nSjAreaZ[ loopSj ][ loopSjArea ] = 0;
				break;
			case 3:
				nSjAreaX[ loopSj ][ loopSjArea ] = x + 64 * 2;
				nSjAreaY[ loopSj ][ loopSjArea ] = y - 64;
				nSjAreaZ[ loopSj ][ loopSjArea ] = 0;
				break;
			case 4:
				nSjAreaX[ loopSj ][ loopSjArea ] = x - 64;
				nSjAreaY[ loopSj ][ loopSjArea ] = y;
				nSjAreaZ[ loopSj ][ loopSjArea ] = 0;
				break;
			case 5:
				nSjAreaX[ loopSj ][ loopSjArea ] = x + 64 * 2;
				nSjAreaY[ loopSj ][ loopSjArea ] = y;
				nSjAreaZ[ loopSj ][ loopSjArea ] = 0;
				break;
			case 6:
				nSjAreaX[ loopSj ][ loopSjArea ] = x - 64;
				nSjAreaY[ loopSj ][ loopSjArea ] = y + 64;
				nSjAreaZ[ loopSj ][ loopSjArea ] = 0;
				break;
			case 7:
				nSjAreaX[ loopSj ][ loopSjArea ] = x + 64 * 2;
				nSjAreaY[ loopSj ][ loopSjArea ] = y + 64;
				nSjAreaZ[ loopSj ][ loopSjArea ] = 0;
				break;
			case 8:
				nSjAreaX[ loopSj ][ loopSjArea ] = x - 64;
				nSjAreaY[ loopSj ][ loopSjArea ] = y + 64 * 2;
				nSjAreaZ[ loopSj ][ loopSjArea ] = 0;
				break;
			case 9:
				nSjAreaX[ loopSj ][ loopSjArea ] = x;
				nSjAreaY[ loopSj ][ loopSjArea ] = y + 64 * 2;
				nSjAreaZ[ loopSj ][ loopSjArea ] = 0;
				break;
			case 10:
				nSjAreaX[ loopSj ][ loopSjArea ] = x + 64;
				nSjAreaY[ loopSj ][ loopSjArea ] = y + 64 * 2;
				nSjAreaZ[ loopSj ][ loopSjArea ] = 0;
				break;
			case 11:
				nSjAreaX[ loopSj ][ loopSjArea ] = x + 64 * 2;
				nSjAreaY[ loopSj ][ loopSjArea ] = y + 64 * 2;
				nSjAreaZ[ loopSj ][ loopSjArea ] = 0;
				break;
			}
		}
	}
	for ( unsigned loopNtrArea = 0 ; loopNtrArea < 14 ; ++loopNtrArea )
	{
		int x=448;
		int y=320;

		switch ( loopNtrArea )
		{
		case 0:
			nNtrAreaX[ loopNtrArea ] = x - 64;
			nNtrAreaY[ loopNtrArea ] = y - 64;
			nNtrAreaZ[ loopNtrArea ] = 0;
			break;
		case 1:
			nNtrAreaX[ loopNtrArea ] = x;
			nNtrAreaY[ loopNtrArea ] = y - 64;
			nNtrAreaZ[ loopNtrArea ] = 0;
			break;
		case 2:
			nNtrAreaX[ loopNtrArea ] = x + 64;
			nNtrAreaY[ loopNtrArea ] = y - 64;
			nNtrAreaZ[ loopNtrArea ] = 0;
			break;
		case 3:
			nNtrAreaX[ loopNtrArea ] = x + 64 * 2;
			nNtrAreaY[ loopNtrArea ] = y - 64;
			nNtrAreaZ[ loopNtrArea ] = 0;
			break;
		case 4:
			nNtrAreaX[ loopNtrArea ] = x + 64 * 3;
			nNtrAreaY[ loopNtrArea ] = y - 64;
			nNtrAreaZ[ loopNtrArea ] = 0;
			break;
		case 5:
			nNtrAreaX[ loopNtrArea ] = x - 64;
			nNtrAreaY[ loopNtrArea ] = y;
			nNtrAreaZ[ loopNtrArea ] = 0;
			break;
		case 6:
			nNtrAreaX[ loopNtrArea ] = x + 64 * 3;
			nNtrAreaY[ loopNtrArea ] = y;
			nNtrAreaZ[ loopNtrArea ] = 0;
			break;
		case 7:
			nNtrAreaX[ loopNtrArea ] = x - 64;
			nNtrAreaY[ loopNtrArea ] = y + 64;
			nNtrAreaZ[ loopNtrArea ] = 0;
			break;
		case 8:
			nNtrAreaX[ loopNtrArea ] = x + 64 * 3;
			nNtrAreaY[ loopNtrArea ] = y + 64;
			nNtrAreaZ[ loopNtrArea ] = 0;
			break;
		case 9:
			nNtrAreaX[ loopNtrArea ] = x - 64;
			nNtrAreaY[ loopNtrArea ] = y + 64 * 2;
			nNtrAreaZ[ loopNtrArea ] = 0;
			break;
		case 10:
			nNtrAreaX[ loopNtrArea ] = x;
			nNtrAreaY[ loopNtrArea ] = y + 64 * 2;
			nNtrAreaZ[ loopNtrArea ] = 0;
			break;
		case 11:
			nNtrAreaX[ loopNtrArea ] = x + 64;
			nNtrAreaY[ loopNtrArea ] = y + 64 * 2;
			nNtrAreaZ[ loopNtrArea ] = 0;
			break;
		case 12:
			nNtrAreaX[ loopNtrArea ] = x + 64 * 2;
			nNtrAreaY[ loopNtrArea ] = y + 64 * 2;
			nNtrAreaZ[ loopNtrArea ] = 0;
			break;
		case 13:
			nNtrAreaX[ loopNtrArea ] = x + 64 * 3;
			nNtrAreaY[ loopNtrArea ] = y + 64 * 2;
			nNtrAreaZ[ loopNtrArea ] = 0;
			break;
		}
	}
}


Area::~Area(void)
{
}

int Area::Sj( int sj )
{
	return nSj[ sj ];
}
int Area::Ntr()
{
	return nNtr;
}
bool Area::SjCheck( int sj , int team )
{
	bool bFlag = true;

	for ( unsigned loop = 0 ; loop < 12 ; ++loop )
	{
		if ( nSjAreaZ[ sj ][ loop ] != team )
		{
			bFlag = false;
			break;
		}
	}
	if ( bFlag )
	{
		nSj[ sj ] = team;
	}
	return bFlag;
}
bool Area::NtrCheck( int team )
{
	bool bFlag = true;

	for ( unsigned loop = 0 ; loop < 12 ; ++loop )
	{
		if ( nNtrAreaZ[ loop ] != team )
		{
			bFlag = false;
			break;
		}
	}
	if ( bFlag )
	{
		nNtr = team;
	}
	return bFlag;
}

int Area::SjArea( int sj , int index , char ch , int num )
{
	switch ( ch )
	{
	case 'x':
		return nSjAreaX[ sj ][ index ] = num;
	case 'y':
		return nSjAreaY[ sj ][ index ] = num;
	case 'z':
		return nSjAreaZ[ sj ][ index ] = num;
	}
	return -1;
}

int Area::SjArea( int sj , int index , char ch )
{
	switch ( ch )
	{
	case 'x':
		return nSjAreaX[ sj ][ index ];
	case 'y':
		return nSjAreaY[ sj ][ index ];
	case 'z':
		return nSjAreaZ[ sj ][ index ];
	}
	return -1;
}

int Area::NtrArea( int index , char ch , int num )
{
	switch ( ch )
	{
	case 'x':
		return nNtrAreaX[ index ] = num;
	case 'y':
		return nNtrAreaY[ index ] = num;
	case 'z':
		return nNtrAreaZ[ index ] = num;
	}
	return -1;
}

int Area::NtrArea( int index , char ch )
{
	switch ( ch )
	{
	case 'x':
		return nNtrAreaX[ index ];
	case 'y':
		return nNtrAreaY[ index ];
	case 'z':
		return nNtrAreaZ[ index ];
	}
	return -1;
}