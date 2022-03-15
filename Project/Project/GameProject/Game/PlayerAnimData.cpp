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
	{ 12,20},
	{ 13,20},
	{ 14,20},
	{ 15,20},
};
//�������[�V����
static TexAnim playerWalk[] =
{
	{ 24,5},
	{ 25,5},
	{ 26,5},
	{ 27,5},
	{ 28,5},
	{ 29,5},
	{ 30,5},
	{ 31,5},
	{ 32,5},
	{ 33,5},
	{ 34,5},
	{ 35,5},
};
//�W�����v(�㏸)
static TexAnim playerJumpUp[] = 
{
	{ 36,3 },
};
//�W�����v(�΋�)
static TexAnim playerJumpStand[] = 
{
	{ 37,4 },
};
//�W�����v(���~)
static TexAnim playerJumpDown[] = 
{
	{ 38,6 },
};
//��i�K�U���ҋ@���[�V����
static TexAnim playerAttack1[] =
{
	{ 48,3 },
	{ 49,3 },
	{ 50,3 },
	{ 51,3 },
	{ 52,3 },
	{ 53,3 },
	{ 54,3 },
	{ 55,3 },
};
//��i�K�U�����[�V����
static TexAnim playerAttack2[] =
{
	{ 60,3 },
	{ 61,3 },
	{ 72,3 },
	{ 73,3 },
	{ 74,3 },
	{ 75,3 },
	{ 76,3 },
	{ 77,3 },
	{ 78,3 },
	{ 79,3 },
	{ 80,3 },
	{ 81,3 },
	{ 82,3 },
	{ 83,3 },
	{ 84,3 },
};

static TexAnim playerWeapon3[] =
{
	{ 97,3 },
	{ 98,3 },
	{ 99,3 },
	{ 100,3 },
	{ 101,3 },
	{ 102,3 },
	{ 103,3 },
};

TexAnimData player_anim_data[] =
{
	ANIMDATA(playerIdle1),			//0
	ANIMDATA(playerIdle2),			//1
	ANIMDATA(playerWalk),			//2
	ANIMDATA(playerJumpUp),			//3
	ANIMDATA(playerJumpStand),		//4
	ANIMDATA(playerJumpDown),		//5
	ANIMDATA(playerAttack1),		//6
	ANIMDATA(playerAttack2),		//7
	ANIMDATA(playerWeapon3),		//8
};