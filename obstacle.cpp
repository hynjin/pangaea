/*
벡터를 이용하여
장애물의 좌표위치를
저장 또는 삭제
*/
#include "obstacle.h"

obstacle :: obstacle()
{
	
}

obstacle :: ~obstacle()
{
}


void obstacle :: obj_plus(float x,float y)
{
	node ex;
	ex.vector.x=x;
	ex.vector.y=y;
	obj_v.push_back(ex);
}

void obstacle :: obj_clear()
{
	obj_v.clear();//왜 여기에 clear를 쓰면 문제가 생기는데 pop_back이면 문제가 없는가...?
}

vector<node> obstacle :: obj()
{
	return this->obj_v;
}
