/*
���͸� �̿��Ͽ�
��ֹ��� ��ǥ��ġ��
���� �Ǵ� ����
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
	obj_v.clear();//�� ���⿡ clear�� ���� ������ ����µ� pop_back�̸� ������ ���°�...?
}

vector<node> obstacle :: obj()
{
	return this->obj_v;
}
