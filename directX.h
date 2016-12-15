#pragma once
#include "Stdafx.h"
#include "loading.h"
#include "move.h"
#include "dark.h"

class DirectX
{
		D3DPRESENT_PARAMETERS d3dpp;
		LPDIRECT3DDEVICE9 m_pd3dDevice; //렌더링에 사용할 D3D 디바이스
		LPD3DXSPRITE m_pSprite;//D3DXSprite 객체
		LPDIRECT3D9 m_pD3D;//D3DDevice 사용할 객체 변수

		loading loading;
		Dark dark;//움직이는 장애물

		HWND winhandle;

		int check;//장애물 좌표를 한번만 불러오기 위하여 사용

	public:

		DirectX(void);
		~DirectX(void);

		void CreateDevice(HWND hWnd);
		void ImageSetting(HWND hWnd);//한번만 호출되는 부분 이미지 로딩
		void DrawImage();//Render에서 계속 불러지는 부분, 이미지를 그림
		void ghost_DrawImage();//캐릭터의 이동을 표시하기 위해
		void Render();//test.cpp의 LOOP에서 게속 불러지는 부분

		void send_ob();//저장된 장애물 좌표 받아옴

		float ch1_X;//캐릭터의 좌표
		float ch1_Y;
		float ch2_X;//캐릭터의 좌표
		float ch2_Y;

		class move move;

		int obj_num;//장애물을 그릴때 for문을 이용하여 그리기 위하여 사용
};

