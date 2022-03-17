#include "PlayerAnimData.h"

//�ҋ@���[�V����(�u���Ȃ�)
static TexAnim playerIdle1[] =
{
	{ 0,20},
	{ 1,20},
	{ 2,20},
	{ 3,20},
};
//�ҋ@���[�V����(�u������)
static TexAnim playerIdle2[] =
{
	{ 5,20},
	{ 6,20},
	{ 7,20},
	{ 8,20},
};
//�������[�V����
static TexAnim playerWalk[] =
{
	{ 10,5},
	{ 11,5},
	{ 12,5},
	{ 13,5},
	{ 14,5},
	{ 15,5},
	{ 16,5},
	{ 17,5},
	{ 18,5},
	{ 19,5},
	{ 20,5},
	{ 21,5},
};
//�W�����v(�㏸)
static TexAnim playerJumpUp[] = 
{
	{ 24,3 },
};
//�W�����v(�΋�)
static TexAnim playerJumpStand[] = 
{
	{ 25,4 },
};
//�W�����v(���~)
static TexAnim playerJumpDown[] = 
{
	{ 26,6 },
};

//1�i�K�U�����܂����[�V����
static TexAnim playerReady1[] =
{
	{ 27,6 },
	{ 28,6 },
	{ 29,6 },
	{ 30,6 },
	{ 31,6 },
	{ 32,6 },
};
//1�i�K�`���[�W���[�V����
static TexAnim playerChrage1[] =
{
	{ 36,6 },
	{ 37,6 },
};
//1�i�K�ʏ�U�����[�V����
static TexAnim playerNomalAttack1[] =
{
	{ 34,3 },
	{ 35,3 },
};
//1�i�K�`���[�W�U�����[�V����
static TexAnim playerChrageAttack1[] =
{
	{ 39,3 },
	{ 40,3 },
};
//2�i�K����`�F���W���[�V����
static TexAnim playerWeponChenge1[] =
{
	{ 42,3 },
	{ 43,3 },
};
//2�i�K�ʏ�U�����[�V����
static TexAnim playerAttack2[] =
{
	{ 45,6 },
	{ 46,6 },
	{ 47,6 },
	{ 48,6 },
	{ 49,6 },
	{ 50,6 },
	{ 51,6 },
	{ 52,6 },
	{ 53,6 },
	{ 54,6 },
	{ 55,6 },
	{ 56,6 },
	{ 57,6 },
};
//3�i�K����`�F���W���[�V����
static TexAnim playerWeponChenge2[] =
{
	{ 64,3 },
	{ 65,3 },
	{ 66,3 },
	{ 67,3 },
	{ 68,3 },
	{ 69,3 },
	{ 70,3 },
};
//3�i�K�`���[�W���[�V����
static TexAnim playerChrage3[] =
{
	{ 72,6 },
	{ 73,6 },
};
//3�i�K�U�����[�V����
static TexAnim playerAttack3[] =
{
	{ 75,6 },
	{ 76,6 },
};

TexAnimData player_anim_data[] =
{
	ANIMDATA(playerIdle1),			//0
	ANIMDATA(playerIdle2),			//1
	ANIMDATA(playerWalk),			//2
	ANIMDATA(playerJumpUp),			//3
	ANIMDATA(playerJumpStand),		//4
	ANIMDATA(playerJumpDown),		//5
	ANIMDATA(playerReady1),			//6
	ANIMDATA(playerChrage1),		//7
	ANIMDATA(playerNomalAttack1),	//8
	ANIMDATA(playerChrageAttack1),	//9
	ANIMDATA(playerWeponChenge1),	//10
	ANIMDATA(playerAttack2),		//11
	ANIMDATA(playerWeponChenge2),	//12
	ANIMDATA(playerChrage3),		//13
	ANIMDATA(playerAttack3),		//14
};