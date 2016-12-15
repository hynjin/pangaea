/*
맵 설정 하는 부분
loding 에서 이미지를 부른다면
이곳에서는 이미지의 좌표를 설정
*/
#include "Setmap.h"

Setmap :: Setmap()
{
	o_cnt=0;
	s_cnt=0;
	n_cnt=0;
	obj_n=57;//장애물 갯수
	sj_n=4;
}

Setmap :: ~Setmap()
{

}
D3DXVECTOR3 Setmap ::  Getwatch_vector()
{
	item.load_watch(watch_vector.x,watch_vector.y);
	return this->watch_vector;
}
D3DXVECTOR3 Setmap :: Getshield_vector()
{
	item.load_shield(shield_vector.x,shield_vector.y);
	return this->shield_vector;
}
D3DXVECTOR3 Setmap :: Gettrap_vector()
{
	item.load_trap(trap_vector.x,trap_vector.y);
	return this->trap_vector;
}
D3DXVECTOR3 Setmap :: Getstart_vector()
{
	return this->start_vector;
}

D3DXVECTOR3 Setmap :: Getback_vector()
{
	return this->back_vector;
}

D3DXVECTOR3 Setmap :: Getgameover_vector()
{
	gameover_vector.x=0;
	gameover_vector.y=0;
	return this->gameover_vector;
}
D3DXVECTOR3 Setmap ::  Getntr_vector()//넥타르
{
	ntr_vector.x=448;
	ntr_vector.y=320;
	if(s_cnt==1)
	{
		obs.ntr_plus(ntr_vector.x,ntr_vector.y);
	}
	s_cnt++;
	return this->ntr_vector;
}
D3DXVECTOR3 Setmap :: Getsj_vector(int num)//신전
{
	if(num%sj_n==0)
	{
		sj_vector.x=576;
		sj_vector.y=64;
	}
	else if(num%sj_n==1)
	{
		sj_vector.x=128;
		sj_vector.y=448;
	}
	else if(num%sj_n==2)
	{
		sj_vector.x=832;
		sj_vector.y=448;
	}
	else if(num%sj_n==3)
	{
		sj_vector.x=384;
		sj_vector.y=576;
	}
	if(s_cnt<sj_n)
	{
		obs.sj_plus(sj_vector.x,sj_vector.y);
	}
	return this->sj_vector;
}
D3DXVECTOR3 Setmap :: Getobj_vector(int num)
{
	if(num%obj_n==0)
	{
		obj_vector.x=64;
		obj_vector.y=0;
	}
	else if(num%obj_n==1)
	{
		obj_vector.x=192;
		obj_vector.y=0;
	}
	else if(num%obj_n==2)
	{
		obj_vector.x=384;
		obj_vector.y=0;
	}
	else if(num%obj_n==3)
	{
		obj_vector.x=448;
		obj_vector.y=0;
	}
	else if(num%obj_n==4)
	{
		obj_vector.x=768;
		obj_vector.y=0;
	}
	else if(num%obj_n==5)
	{
		obj_vector.x=896;
		obj_vector.y=0;
	}
	else if(num%obj_n==6)
	{
		obj_vector.x=0;
		obj_vector.y=64;
	}
	else if(num%obj_n==7)
	{
		obj_vector.x=64;
		obj_vector.y=64;
	}
	else if(num%obj_n==8)
	{
		obj_vector.x=192;
		obj_vector.y=64;
	}
	else if(num%obj_n==9)
	{
		obj_vector.x=256;
		obj_vector.y=64;
	}
	else if(num%obj_n==10)
	{
		obj_vector.x=384;
		obj_vector.y=64;
	}
	else if(num%obj_n==11)
	{
		obj_vector.x=768;
		obj_vector.y=64;
	}
	else if(num%obj_n==12)
	{
		obj_vector.x=896;
		obj_vector.y=64;
	}
	else if(num%obj_n==13)
	{
		obj_vector.x=960;
		obj_vector.y=64;
	}
	else if(num%obj_n==14)
	{
		obj_vector.x=64;
		obj_vector.y=128;
	}
	else if(num%obj_n==15)
	{
		obj_vector.x=256;
		obj_vector.y=128;
	}
	else if(num%obj_n==16)
	{
		obj_vector.x=384;
		obj_vector.y=128;
	}
	else if(num%obj_n==17)
	{
		obj_vector.x=64;
		obj_vector.y=192;
	}
	else if(num%obj_n==18)
	{
		obj_vector.x=256;
		obj_vector.y=192;
	}
	else if(num%obj_n==19)
	{
		obj_vector.x=384;
		obj_vector.y=192;
	}
	else if(num%obj_n==20)
	{
		obj_vector.x=448;
		obj_vector.y=192;
	}
	else if(num%obj_n==21)
	{
		obj_vector.x= 896;
		obj_vector.y=192;
	}
	else if(num%obj_n==22)
	{
		obj_vector.x= 960;
		obj_vector.y=192;
	}
	else if(num%obj_n==23)
	{
		obj_vector.x=256;
		obj_vector.y=256;
	}
	
	else if(num%obj_n==24)
	{
		obj_vector.x=0;
		obj_vector.y=320;
	}
	else if(num%obj_n==25)
	{
		obj_vector.x=64;
		obj_vector.y=320;
	}
	else if(num%obj_n==26)
	{
		obj_vector.x=704;
		obj_vector.y=320;
	}
	else if(num%obj_n==27)
	{
		obj_vector.x=768;
		obj_vector.y=320;
	}
	else if(num%obj_n==28)
	{
		obj_vector.x=896;
		obj_vector.y=320;
	}
	else if(num%obj_n==29)
	{
		obj_vector.x=960;
		obj_vector.y=320;
	}
	else if(num%obj_n==30)
	{
		obj_vector.x=0;
		obj_vector.y=384;
	}
	else if(num%obj_n==31)
	{
		obj_vector.x=320;
		obj_vector.y=384;
	}
	else if(num%obj_n==32)
	{
		obj_vector.x=0;
		obj_vector.y=448;
	}
	else if(num%obj_n==33)
	{
		obj_vector.x=320;
		obj_vector.y=448;
	}
	else if(num%obj_n==34)
	{
		obj_vector.x=0;
		obj_vector.y=512;
	}
	else if(num%obj_n==35)
	{
		obj_vector.x=576;
		obj_vector.y=512;
	}
	else if(num%obj_n==36)
	{
		obj_vector.x=640;
		obj_vector.y=512;
	}
	else if(num%obj_n==37)
	{
		obj_vector.x=704;
		obj_vector.y=512;
	}
	else if(num%obj_n==38)
	{
		obj_vector.x=0;
		obj_vector.y=576;
	}
	else if(num%obj_n==39)
	{
		obj_vector.x=576;
		obj_vector.y=576;
	}
	else if(num%obj_n==40)
	{
		obj_vector.x=704;
		obj_vector.y=576;
	}
	else if(num%obj_n==41)
	{
		obj_vector.x=0;
		obj_vector.y=640;
	}
	else if(num%obj_n==42)
	{
		obj_vector.x=64;
		obj_vector.y=640;
	}
	else if(num%obj_n==43)
	{
		obj_vector.x=576;
		obj_vector.y=640;
	}
	else if(num%obj_n==44)
	{
		obj_vector.x=960;
		obj_vector.y=640;
	}
	else if(num%obj_n==45)
	{
		obj_vector.x=0;
		obj_vector.y=704;
	}
	else if(num%obj_n==46)
	{
		obj_vector.x=64;
		obj_vector.y=704;
	}
	else if(num%obj_n==47)
	{
		obj_vector.x=128;
		obj_vector.y=704;
	}
	else if(num%obj_n==48)
	{
		obj_vector.x=192;
		obj_vector.y=704;
	}
	else if(num%obj_n==49)
	{
		obj_vector.x=256;
		obj_vector.y=704;
	}
	else if(num%obj_n==50)
	{
		obj_vector.x=576;
		obj_vector.y=704;
	}
	else if(num%obj_n==51)
	{
		obj_vector.x=640;
		obj_vector.y=704;
	}
	else if(num%obj_n==52)
	{
		obj_vector.x=704;
		obj_vector.y=704;
	}
	else if(num%obj_n==53)
	{
		obj_vector.x=768;
		obj_vector.y=704;
	}
	else if(num%obj_n==54)
	{
		obj_vector.x=832;
		obj_vector.y=704;
	}
	else if(num%obj_n==55)
	{
		obj_vector.x=896;
		obj_vector.y=704;
	}
	else if(num%obj_n==56)
	{
		obj_vector.x=960;
		obj_vector.y=704;
	}
	else if(num%obj_n==57)
	{
		obj_vector.x=1024;
		obj_vector.y=704;
	}
	if(o_cnt<obj_n)
	{
			obs.obj_plus(obj_vector.x,obj_vector.y);
	}
	o_cnt++;
	return this->obj_vector;
}