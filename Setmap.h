#pragma once

#pragma once
#include "Stdafx.h"
#include "Define.h"
#include "obstacle.h"
#include "Area.h"
#include "Item.h"

class Setmap
{
public:
	Setmap();
	~Setmap();
	
	D3DXVECTOR3 Getstart_vector();//�̹����� ��ǥ�� vector�� ����(vector.h�ʹ� �ٸ�)

	D3DXVECTOR3 Getobj_vector(int);//���⿡�� int�� direct���� ��ֹ��� for������ �ѹ��� ����ϱ� ���� ���
	D3DXVECTOR3 Getsj_vector(int);//����
	D3DXVECTOR3 Getntr_vector();//��Ÿ��
	D3DXVECTOR3 Getback_vector();
	D3DXVECTOR3 Getwatch_vector();
	D3DXVECTOR3 Getshield_vector();
	D3DXVECTOR3 Gettrap_vector();

	D3DXVECTOR3 Getgameover_vector();

	obstacle obs;
	Area area;
	Item item;
	

private:
	D3DXVECTOR3 start_vector;
	D3DXVECTOR3 obj_vector;// ���̷�Ʈ 3���� ����
	D3DXVECTOR3 sj_vector;
	D3DXVECTOR3 ntr_vector;
	D3DXVECTOR3 back_vector;//���
	D3DXVECTOR3 watch_vector;
	D3DXVECTOR3 shield_vector;
	D3DXVECTOR3 trap_vector;

	D3DXVECTOR3 gameover_vector;
	
	RECT MSGdrawPosition;//�̰� ���⿡ �ʿ䰡..����?���� �̰�

	int o_cnt;
	int s_cnt;
	int n_cnt;

	node objh;
	node sjh;
	node ntrh;

	int obj_n;//��ֹ� ����
	int sj_n;
};