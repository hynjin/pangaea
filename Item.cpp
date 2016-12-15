#include "Item.h"


Item::Item(void)
{
	nPlayer1p = 0;
	nPlayer2p = 0;
	
	srand(time(NULL));
	wnum=rand()%3;
	snum=rand()%3;
	tnum=rand()%3;
    w1 = clock();
	s1 = clock();
	t1 = clock();
//        if ((t2 - t1) > (3 * CLOCKS_PER_SEC))break;
}


Item::~Item(void)
{
}
void Item :: load_watch(float &x, float &y)
{
	w2 = clock();
	if((w2-w1)%(1000) == 0)
		wnum=rand()%3;
	if(wnum==0)
	{
		x=128;
		y=384;
	}
	else if(wnum==1)
	{
		x=768;
		y=384;
	}
	else if(wnum==2)
	{
		x=512;
		y=192;
	}
}
void Item :: load_shield(float &x, float &y)
{
	s2 = clock();
	if((s2-s1)%(1000)  == 0)
		snum=rand()%3;
	if(snum==0)
	{
		x=512;
		y=512;
	}
	else if(snum==1)
	{
		x=704;
		y=64;
	}
	else if(snum==2)
	{
		x=128;
		y=576;
	}

}
void Item :: load_trap(float &x, float &y)
{
	t2 = clock();
	if((t2-t1)%(1000)  == 0)
		tnum=rand()%3;
	if(tnum==0)
	{
		x=448;
		y=256;
	}
	else if(tnum==1)
	{
		x=64;
		y=448;
	}
	else if(tnum==2)
	{
		x=960;
		y=576;
	}
}

int Item::Player1p( int nItem )
{
	return nPlayer1p = nItem;
}
int Item::Player1p()
{
	return nPlayer1p;
}
int Item::Player2p( int nItem )
{
	return nPlayer2p = nItem;
}
int Item::Player2p()
{
	return nPlayer2p;
}