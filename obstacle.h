/*
���� �ν��ϴ� �κ�
��, ����, ��ֹ�, ���������� ���� ��ǥ�� ����
*/
#include "Stdafx.h"
#include <vector>
using namespace std;

typedef struct node
{
	D3DXVECTOR3 vector;//�ٷ� ���ͷ� ��ֹ� �����ϱ� ����(�Լ��� ���ϼ� ��������)
}node;

class obstacle
{
public:
	obstacle();
	~obstacle();

	void obj_plus(float x,float y);//��ֹ� ��ǥ ����

	void obj_clear();//��ֹ� ��ǥ ���� ����


	vector<node> obj();

private:
	vector<node>obj_v;
};