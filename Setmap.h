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
	
	D3DXVECTOR3 Getstart_vector();//이미지의 좌표를 vector에 저장(vector.h와는 다름)

	D3DXVECTOR3 Getobj_vector(int);//여기에서 int는 direct에서 장애물을 for문으로 한번에 출력하기 위해 사용
	D3DXVECTOR3 Getsj_vector(int);//신전
	D3DXVECTOR3 Getntr_vector();//넥타르
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
	D3DXVECTOR3 obj_vector;// 다이렉트 3차원 벡터
	D3DXVECTOR3 sj_vector;
	D3DXVECTOR3 ntr_vector;
	D3DXVECTOR3 back_vector;//배경
	D3DXVECTOR3 watch_vector;
	D3DXVECTOR3 shield_vector;
	D3DXVECTOR3 trap_vector;

	D3DXVECTOR3 gameover_vector;
	
	RECT MSGdrawPosition;//이건 여기에 필요가..없나?뭐지 이거

	int o_cnt;
	int s_cnt;
	int n_cnt;

	node objh;
	node sjh;
	node ntrh;

	int obj_n;//장애물 갯수
	int sj_n;
};