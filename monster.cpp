#include "monster.h"
#include "stdio.h"

Monster :: Monster()
{
	m1_x=64;
	m1_y=384;
	m2_x=704;
	m2_y=0;

	m1_Image.top = 0;
	m1_Image.bottom = 64;
	m1_Image.left = 0;
	m1_Image.right = 64;
	
	m2_Image.top = 0;
	m2_Image.bottom = 64;
	m2_Image.left = 0;
	m2_Image.right = 64;



	dis=1.2;//장애물이 이동하는 거리->속도 관여
	Monster_check=0;
}
Monster :: ~Monster()
{

}
void Monster :: Loadm1(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("m_1.png"),64*2,64,NULL,m1_texture)))
	 {
	  MessageBox(hWnd,_T("몬스터1 로딩에 실패하였습니다."),_T("몬스터1 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
void Monster :: Loadm2(HWND hWnd, LPDIRECT3DDEVICE9 m_pd3dDevice)
{
	if(FAILED(CreateSpriteTexture(m_pd3dDevice,_T("m_2.png"),64*2,64,NULL,m2_texture)))
	 {
	  MessageBox(hWnd,_T("몬스터2 로딩에 실패하였습니다."),_T("몬스터2 이미지 로딩 실패."),MB_OK);
	  PostMessage( hWnd, WM_CLOSE, 0, 0 );
	 }
}
D3DXVECTOR3 Monster :: Getm1_vector()
{
	m1_vector.x=m1_x;
	m1_vector.y=m1_y;
	
	return this->m1_vector;
}
D3DXVECTOR3 Monster :: Getm2_vector()
{
	m2_vector.x=m2_x;
	m2_vector.y=m2_y;
	
	return this->m2_vector;
}
void Monster :: show_monster1()//리소스가 없어서 일단 애니메이션은 안넣음
{
	if(Monster_check%50 < 25 )//아래쪽
	{
		m1_Image.left = 0;
		m1_Image.right = 64*1;
	}
	else
	{
		m1_Image.left = 64*1;
		m1_Image.right = 64*2;
	}
	Monster_check ++;
}
RECT* Monster::Get_m1Image()
{
	return &this->m1_Image;
}
void Monster :: show_monster2()//리소스가 없어서 일단 애니메이션은 안넣음
{
	if(Monster_check%50 < 25 )//아래쪽
	{
		m2_Image.left = 64*0;
		m2_Image.right = 64*1;
	}
	else
	{
		m2_Image.left = 64*1;
		m2_Image.right = 64*2;
	}
}
RECT* Monster::Get_m2Image()
{
	return &this->m2_Image;
}
LPDIRECT3DTEXTURE9 Monster :: Getm1_texture()
{
	m1_Image.left;
	m1_Image.right;
	return this->m1_texture;
}
LPDIRECT3DTEXTURE9 Monster :: Getm2_texture()
{
	m2_Image.left;
	m2_Image.right;
	return this->m2_texture;
}

void Monster :: m1_move()
{
	if((m1_x>=62 && m1_x<=256) && (m1_y>=382 && m1_y <= 386))
		m1_x += dis*1.15;
	else if((m1_x >=256 && m1_x <= 258) && (m1_y >= 384 && m1_y <= 576))
		m1_y += dis*1.15;
	else if((m1_x <= 258 && m1_x >= 64) && (m1_y >= 576 && m1_y <= 578))
		m1_x -= dis*1.15;
	else if((m1_x >= 62 && m1_x <= 64) && (m1_y >= 384 && m1_y <= 578))
		m1_y -= dis*1.15;
}
void Monster :: m2_move()
{
	if((m2_x>=512 && m2_x<=706) && (m2_y >= -1 && m2_y <= 2))
		m2_x -= dis;
	else if((m2_x >=510 && m2_x <= 512) && (m2_y >= 0 && m2_y <= 192))
		m2_y += dis;
	else if((m2_x <=704  && m2_x >= 510) && (m2_y >= 192 && m2_y <= 195))
		m2_x += dis;
	else if((m2_x >= 704 && m2_x <= 706) && (m2_y <= 256 && m2_y >= 2))
		m2_y -= dis;
}
