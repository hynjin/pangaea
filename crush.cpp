/*
��ֹ��� ��ǥ������ �޾ƿͼ�
ĳ���Ϳ� ��ֹ��� �浿���� Ȯ��
*/
#include "crush.h"

crush ::crush()
{
	
}
crush :: ~crush()
{

}
void crush :: call()
{
	objh=ob.obj();
}

int crush:: obj_check(double ghostx,double ghosty,int &check)
{
	for(unsigned int i=0;i<objh.size();i++)
	{
		if(ghostx>(objh[i].vector.x-ch_x/3) && (ghostx+ch_x)<(objh[i].vector.x+obj_x+obj_x/3))
		{
			if((ghosty+ch_y)>=objh[i].vector.y && (ghosty+ch_y)<=(objh[i].vector.y+obj_y))//Y ���� �ʿ�
			{
				return check=0;
			}
		}
		else if(ghosty>768)
			return check=0;
	}

	return check=4;
}

void crush :: Getdark(D3DXVECTOR3 dark_vector)
{
	darkx=dark_vector.x;
	darky=dark_vector.y;
}

//���� �ٺ��ΰ� ����