/*
�̹����� �θ���
�̹����� �׸���
ĳ������ �̵��� ó���ϰ�
�����Լ��� �����ְ�...
*/
#include "directX.h"

DirectX::DirectX(void)
{
	ch1_X=0;//ĳ���� ��� ��ġ
	ch1_Y=400;
	ch2_X=300;//ĳ���� ��� ��ġ
	ch2_Y=400;
	check=0;//���� �Լ��� ��� ����Ǵ��� üũ
	obj_num=57;//�� �׸��� �Լ��� ���
}


DirectX::~DirectX(void)
{
}


void DirectX::CreateDevice(HWND hWnd)
{
	//�ٷ��κ� 

 //�׷���ī�� �������̽� ����
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
 
 if(NULL==m_pD3D)
  throw E_FAIL;
//Direct3DCreate9�� Direct3D�� ����ϱ� ���ؼ�  IDirect3D9Ex��� �������̽��� ����ϴ�.
//Direct3DCreate9�Լ��� ���ڴ� �׻� D3D_SDK_VERSION�Դϴ�. Direct3D�� SDK�� ����ؾ��ϱ� �����Դϴ�.
// ���� ����� ���ø����̼��� ���� �ٸ� �����̶�� NULL �� ��ȯ�մϴ�.

 ZeroMemory(&d3dpp, sizeof(d3dpp));// ����� ����ü�����Ͽ� �ʱ�ȭ == memset(&(&d3dpp, 0,  sizeof(D3DPRESENT_PARAMETERS))
 d3dpp.Windowed = TRUE;//â��� ����- Ǯ��ũ���� false�� �α⵵��, ������ ������ TRUE  
 d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;//������۸�(�����)���� ȭ����ȯ�� ��� �Ұ��ΰ�? - ���� ȿ������ SWAPȿ��
 d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;//���� ����ȭ�鿡 ���缭 �ĸ���� ����
 d3dpp.EnableAutoDepthStencil = TRUE;//  ���� ����(Z����)�� ����� �Ұ��ΰ� - ���Ľ� ���� ��� ����.
 d3dpp.AutoDepthStencilFormat = D3DFMT_D16; // ���� �ܰ踦 ������� ����ȭ �� ���ΰ�? 
											// D16�� 16��Ʈ��(�뷫 65000������ ���� ��츦 ǥ���� �� �ֽ��ϴ�.
											// �������� ����ϹǷ� D32�� ����������
m_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,hWnd,D3DCREATE_SOFTWARE_VERTEXPROCESSING,&d3dpp, &m_pd3dDevice);
 // ����̽��� ���� ���� �����Ѵ�. 
 // D3DADAPTER_DEFAULT ����Ʈ ���� ī�带 ����Ѵ�(��κ��� ����ī�尡 �ϳ��̴�)
 // D3DDEVTYPE_HAL HAL����̽��� �����Ѵ� (HW������ġ�� ����ϰڴٴ� �ǹ�);
 // ����ó���� ���ī�忡�� �����ϴ� SWó���� �����Ѵ�.(HW�� ������ ��� ���� ���� ������ ����)

 // �׷����������̽��� �����ϰ� m_pd3dDevice��� �̸��� �ٿ��־���.
 //�츮�� ������ m_pd3dDevice�� ���� �׷���ī�忡 ����� ���� �� �ִ�.


 //HAL�̶�?
 //�پ��� ������ �׷���ī�� ��ġ���� ���� ũ�� Ĩ�� ������� Nvidia �� Radeon�� �ְ�, ���⼭ ����� ���۷����� �����ϰų�,
 //�Ǵ� �پ��� �ɼ��� ���ٿ�, �پ��� �����(�Ⱑ����Ʈ, �Ƽ���, �̿���, �����̾� ���)���� �׷���ī�带 �������ϴ�.
 //���ظ� �������� �����, �Ȱ��� ȭ�鿡 �ϳ��� ���� ���� �Լ� ������, �ȸ��� SetPixel();�̶�� ���� �� �ְ�,
 //�ٸ� ȸ��� DrawPixel(); �̶�� ���� �� �ֽ��ϴ�. �̷��� ������ ������ ���ϰ� ���α׷��� �� �ҽ��� �����ÿ� 
 //� �׷���ī��� �����ǰ�, � �׷���ī��� ���������� �������� �ʴ� ������ ����� �߻���ų �� ������,
 //ġ���� ������ ���߽�ų �����Ұ� �����մϴ�. ���� �̿� ���� ǥ��(����Ʈ��/�Ծ�)���ν�, ������ ��ɿ� ����
 // ǥ�رԾ��� Micro Soft���� ���������ν�, ��������� �� �Ծุ ���Ѽ� �ϵ��� �����ϰ� �Ǹ�, 
 //�� ���߻簡 �׷���ī�带 ������ε� ���� �����ϴ��� DirectX������ �ش� �׷���ī�尡 �������� �����ϰ� �� �� �ְ� �˴ϴ�.
 // �� �Ծ��� �ٷ� HAL�Դϴ�. 
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 D3DXCreateSprite(m_pd3dDevice,&m_pSprite);

}

void DirectX::ImageSetting(HWND hWnd)//�̹����� loading Ŭ�������� �޾ƿ�
{
	loading.Loadstart(hWnd,m_pd3dDevice);
	loading.Loadback(hWnd,m_pd3dDevice);
	loading.Loadgameover(hWnd,m_pd3dDevice);
	loading.Loadch1(hWnd,m_pd3dDevice);
	loading.Loadch2(hWnd,m_pd3dDevice);
	dark.Loaddark(hWnd,m_pd3dDevice);
	
	move.Loadghost(hWnd,m_pd3dDevice);

	winhandle = hWnd;
}

void DirectX::DrawImage()//��ӹٲ�(�ε��� �� �ȿ� ������ ���� ���� ��� �ε��ϴ� ����)
{//�׸� �׸��� ���� Setmap���� �޾ƿ�
	m_pSprite->Draw(loading.Getback_texture(),NULL,NULL,&loading.Setmap.Getback_vector(),D3DCOLOR_XRGB(255,255,255));//���׸���

	for(int i=0;i<15;obj_num++,i++)//�ʱ�ȭ �Ǳ� ���� ��� ������ �ϳ��� �׸��� ���� for�� ���
		m_pSprite->Draw(loading.Getobj_texture(),NULL,NULL,&loading.Setmap.Getobj_vector(obj_num),D3DCOLOR_XRGB(255,255,255));//�����׸���
	

	m_pSprite->Draw(dark.Getdark_texture(),dark.Get_Image(),NULL,&dark.Getdark_vector(),D3DCOLOR_XRGB(255,255,255));
	dark.show_dark();
	dark.dark_move(1);

	move.crush.Getdark(dark.Getdark_vector());

	if(check==1)
	{
		send_ob();
		move.crush.call();
	}
}

void DirectX::ghost_DrawImage()//��ӹٲ�(�ε��� �� �ȿ� ������ ���� ���� ��� �ε��ϴ� ����)
{
	m_pSprite->Draw(move.Getghost_texture(),move.Get_Image(),NULL,&move.Getghost_vector(ch1_X,ch1_Y),D3DCOLOR_XRGB(255,255,255));
}


void DirectX::Render()//����ϰ� ������ ��! ������ ���� ���׵� ���� ��! ���⼭ ��� ���� �߻��̶�� ��!
{	
	m_pd3dDevice->Clear(0,NULL,D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER,D3DCOLOR_XRGB(14,14,72),1.0f,0);
	// ȭ�� �ʱ�ȭ 
	///// �ĸ���۸� �Ķ���(0,0,255)���� �����
	
	if(SUCCEEDED(m_pd3dDevice->BeginScene()))// �ĸ���ۿ� �׸�������
		{
			m_pSprite->Begin(D3DXSPRITE_ALPHABLEND); 
			if(check==0)//ó������
			{
				this->m_pSprite->Draw(loading.Getstart_texture(),NULL,NULL,&loading.Setmap.Getstart_vector(),D3DCOLOR_XRGB(255,255,255));
				if(GetAsyncKeyState(VK_RETURN) & 0x8000)
					check++;
			}
			else//���� ���� ������ ���=�������
			{
				this->DrawImage();
				this->ghost_DrawImage();

				if(GetAsyncKeyState(VK_SPACE) & 0x8000 )//������ ������ ����
				{
					for(int i=0;i<50;i++)
					{
						{
							m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
							this->DrawImage();
							this->m_pSprite->Draw(move.Getghost_texture(),move.Get_Image(),NULL,&move.jump(ch1_X,ch1_Y,i),D3DCOLOR_XRGB(255,255,255));
							m_pSprite->End();
						} 
						m_pd3dDevice->EndScene();//����� �� �׷ȴٴ� ���� �˸���.
						m_pd3dDevice->Present( NULL, NULL, NULL, NULL );//���� ���ۿ� �ĸ� ���۸� ��ü�Ѵ�
						}
				}
			/*	else if(move.clear(ch1_X,ch1_Y)==6)//������
				{
					dark.dark_stop();
					this->m_pSprite->Draw(loading.Getclear_texture(),NULL,NULL,&loading.Setmap.Getclear_vector(),D3DCOLOR_XRGB(255,255,255));
				}*/
				else if(GetAsyncKeyState(VK_UP) & 0x8000)
					 move.upmove(ch1_X,ch1_Y);
				else if(GetAsyncKeyState(VK_DOWN) & 0x8000)
					 move.downmove(ch1_X,ch1_Y);
				else if(GetAsyncKeyState(VK_LEFT) & 0x8000)
					 move.leftmove(ch1_X,ch1_Y);
				else if(GetAsyncKeyState(VK_RIGHT) & 0x8000)
					move.rightmove(ch1_X,ch1_Y);
				
			}
			m_pSprite->End();
		}
		m_pd3dDevice->EndScene();//����� �� �׷ȴٴ� ���� �˸���.
		m_pd3dDevice->Present( NULL, NULL, NULL, NULL );//���� ���ۿ� �ĸ� ���۸� ��ü�Ѵ�.
		
}


//����̽�(BeginScene) => ��������Ʈ(Begin) => ��������Ʈ(Draw)=>...=>(Draw)
//=> ��������Ʈ(End) => ����̽�(EndScene) => ����̽�(Present)



void DirectX::send_ob()//��ֹ� ��ǥ �޾ƿ���
{
	move.crush.ob=loading.Setmap.obs;
}