/*
움직이는 장애물
->이동하면서 
*/
#include "Stdafx.h"

class Monster
{
public:
	Monster();
	~Monster();
	
	D3DXVECTOR3 Getm1_vector();//몬스터1
	LPDIRECT3DTEXTURE9 Getm1_texture();

	D3DXVECTOR3 Getm2_vector();//몬스터2
	LPDIRECT3DTEXTURE9 Getm2_texture();

	void Loadm1(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	void Loadm2(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	
	void m1_move();
	void m2_move();
	
	RECT* Get_m1Image();
	void show_monster1();//이미지 스프라이트
	RECT* Get_m2Image();
	void show_monster2();//이미지 스프라이트

private:
	D3DXVECTOR3 m1_vector;
	LPDIRECT3DTEXTURE9 m1_texture;
	D3DXVECTOR3 m2_vector;
	LPDIRECT3DTEXTURE9 m2_texture;
	
	float m1_x;
	float m1_y;
	float m2_x;
	float m2_y;

	RECT m1_Image;
	RECT m2_Image;
	int Monster_check;//애니메이션
	float dis;
};