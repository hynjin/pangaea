/*
�����̴� ��ֹ�
->�̵��ϸ鼭 
*/
#include "Stdafx.h"

class Monster
{
public:
	Monster();
	~Monster();
	
	D3DXVECTOR3 Getm1_vector();//����1
	LPDIRECT3DTEXTURE9 Getm1_texture();

	D3DXVECTOR3 Getm2_vector();//����2
	LPDIRECT3DTEXTURE9 Getm2_texture();

	void Loadm1(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	void Loadm2(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	
	void m1_move();
	void m2_move();
	
	RECT* Get_m1Image();
	void show_monster1();//�̹��� ��������Ʈ
	RECT* Get_m2Image();
	void show_monster2();//�̹��� ��������Ʈ

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
	int Monster_check;//�ִϸ��̼�
	float dis;
};