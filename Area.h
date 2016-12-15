#pragma once
class Area
{
	int nSj[ 4 ];
	int nNtr;
	int nSjAreaX[ 4 ][ 12 ];
	int nSjAreaY[ 4 ][ 12 ];
	int nSjAreaZ[ 4 ][ 12 ];
	int nNtrAreaX[ 14 ];
	int nNtrAreaY[ 14 ];
	int nNtrAreaZ[ 14 ];
public:
	Area(void);
	~Area(void);
	
	int Sj( int sj );
	int Ntr();
	bool SjCheck( int sj , int team );
	bool NtrCheck( int team );
	int SjArea( int sj , int index , char ch , int num );
	int SjArea( int sj , int index , char ch );
	int NtrArea( int index , char ch , int num );
	int NtrArea( int index , char ch );
};

