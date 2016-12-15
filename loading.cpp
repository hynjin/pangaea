/*
이미지를 불러오는 부분
*/
#include "loading.h"

loading :: loading()
{
}

loading :: ~loading()
{
}

void loading :: Loadstart(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("start.png"),WINDOWSIZE_X,WINDOWSIZE_Y,D3DCOLOR_XRGB(0,0,0),start_texture)))
	 {
	  MessageBox(hWnd,_T("시작 이미지 로딩에 실패하였습니다."),_T("시작 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
void loading :: Loadobj(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("badack.png"),obj_x,obj_y,D3DCOLOR_XRGB(0,0,0),obj_texture)))
	 {
	  MessageBox(hWnd,_T("벽독 이미지 로딩에 실패하였습니다."),_T("벽돌 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
void loading :: Loadch1(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("tump.png"),ch_x,ch_y,D3DCOLOR_XRGB(0,0,0),ch1_texture)))
	 {
	  MessageBox(hWnd,_T("무덤 이미지 로딩에 실패하였습니다."),_T("무덤 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
void loading :: Loadch2(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("tump.png"),ch_x,ch_y,D3DCOLOR_XRGB(0,0,0),ch2_texture)))
	 {
	  MessageBox(hWnd,_T("무덤 이미지 로딩에 실패하였습니다."),_T("무덤 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
void loading :: Loadback(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("back.bmp"),WINDOWSIZE_X,WINDOWSIZE_Y,D3DCOLOR_XRGB(0,0,0),back_texture)))
	 {
	  MessageBox(hWnd,_T("배경 이미지 로딩에 실패하였습니다."),_T("배경 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
void loading :: Loadgameover(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("gameover.png"),300,400,D3DCOLOR_XRGB(0,0,0),gameover_texture)))
	 {
	  MessageBox(hWnd,_T("게임오버 이미지 로딩에 실패하였습니다."),_T("게임오버 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}

LPDIRECT3DTEXTURE9 loading :: Getobj_texture()
{
	return this->obj_texture;
}
LPDIRECT3DTEXTURE9 loading :: Getch1_texture()
{
	return this->ch1_texture;
}
LPDIRECT3DTEXTURE9 loading :: Getch2_texture()
{
	return this->ch2_texture;
}
LPDIRECT3DTEXTURE9 loading :: Getgameover_texture()
{
	return this->gameover_texture;
}
LPDIRECT3DTEXTURE9 loading :: Getstart_texture()
{
	return this->start_texture;
}
LPDIRECT3DTEXTURE9 loading :: Getback_texture()
{
	return this->back_texture;
}