/*
��ֹ��� �ε��������� �Ǵ��ϴ� �κ�
���ٰ� ��Ҵ���
���� ��� �ִ���
��ֹ��� ��Ҵ���
���� �Ǵ�
*/
#pragma once
#include "Stdafx.h"
#include "Define.h"
#include "loading.h"

class crush
{
public:
	crush();
	~crush();

	void call();
	int obj_check(double,double,int &che);

	void Getdark(D3DXVECTOR3 dark_vector);//�����̴� ��ֹ��� ��ǥ�� �޾ƿ�
	
	class obstacle ob;

	vector<node> objh;

	int cnt;

private:
	loading load;
	
	float darkx;
	float darky;

};