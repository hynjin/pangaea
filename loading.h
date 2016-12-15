#pragma once

#pragma once
#include "Stdafx.h"
#include "Define.h"
#include "Setmap.h"


class loading
{
public:
	loading();
	~loading();
	
	void Loadstart(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	void Loadch1(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);//이미지 로딩
	void Loadch2(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	void Loadobj(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	void Loadback(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);
	void Loadgameover(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice);

	Setmap Setmap;


	LPDIRECT3DTEXTURE9 Getstart_texture();//texture 정보 받아옴
	LPDIRECT3DTEXTURE9 Getobj_texture();
	LPDIRECT3DTEXTURE9 Getch1_texture();
	LPDIRECT3DTEXTURE9 Getch2_texture();
	LPDIRECT3DTEXTURE9 Getback_texture();
	LPDIRECT3DTEXTURE9 Getgameover_texture();

private:
	LPDIRECT3DTEXTURE9 obj_texture;
	LPDIRECT3DTEXTURE9 ch1_texture;
	LPDIRECT3DTEXTURE9 ch2_texture;
	LPDIRECT3DTEXTURE9 back_texture;
	LPDIRECT3DTEXTURE9 gameover_texture;
	LPDIRECT3DTEXTURE9 start_texture;
};