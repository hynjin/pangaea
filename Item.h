#pragma once
#include <iostream>
#include "time.h"
class Item
{
	int nPlayer1p;
	int nPlayer2p;

	int wnum;
	int snum;
	int tnum;

	clock_t w1, w2;
	clock_t s1, s2;
	clock_t t1, t2;

public:
	Item(void);
	~Item(void);
	void load_watch(float &x, float &y);
	void load_shield(float &x, float &y);
	void load_trap(float &x, float &y);

	int Player1p( int nItem );
	int Player1p();
	int Player2p( int nItem );
	int Player2p();
};
