#include "PlayerAnimData.h"

//�ҋ@���[�V����(�u���Ȃ�)
static TexAnim gunPlayerIdle1[] =
{
	{ 0,20},
	{ 1,20},
	{ 2,20},
	{ 3,20},
};
//�ҋ@���[�V����(�u������)
static TexAnim gunPlayerIdle2[] =
{
	{ 5,20},
	{ 6,20},
	{ 7,20},
	{ 8,20},
};
//�������[�V����
static TexAnim swordPlayerWalk[] =
{
	{ 10,5},
	{ 11,5},
	{ 12,5},
	{ 13,5},
	{ 14,5},
	{ 15,5},
	{ 16,5},
	{ 17,5},
};
//�������[�V����
static TexAnim gunPlayerWalk[] =
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
static TexAnim PlayerJumpUp[] =
{
	{ 24,3 },
};
//�W�����v(�΋�)
static TexAnim PlayerJumpStand[] =
{
	{ 25,4 },
};
//�W�����v(���~)
static TexAnim PlayerJumpDown[] =
{
	{ 26,6 },
};
//�W�����v�A�^�b�N
static TexAnim PlayerJumpAttack[] =
{
	{ 52,6 },
	{ 53,6 },
	{ 54,6 },
};

//1�i�K�U�����܂����[�V����
static TexAnim gunPlayerReady1[] =
{
	{ 27,6 },
	{ 28,6 },
	{ 29,6 },
	{ 30,6 },
	{ 31,6 },
	{ 32,6 },
};
//1�i�K�`���[�W���[�V����
static TexAnim gunPlayerChrage1[] =
{
	{ 36,6 },
	{ 37,6 },
};
//1�i�K�ʏ�U�����[�V����
static TexAnim swordPlayerAttack1[] =
{
	{ 27,3 },
	{ 28,3 },
	{ 29,3 },
	{ 30,3 },
};
//1�i�K�ʏ�U�����[�V����
static TexAnim gunPlayerAttack1[] =
{
	{ 34,3 },
	{ 35,3 },
};
//1�i�K�`���[�W�U�����[�V����
static TexAnim gunPlayerChrageAttack1[] =
{
	{ 39,3 },
	{ 40,3 },
};
//2�i�K����`�F���W���[�V����
static TexAnim gunPlayerWeponChenge1[] =
{
	{ 42,3 },
	{ 43,3 },
};
//2�i�K�ʏ�U�����[�V����
static TexAnim swordPlayerAttack2[] =
{
	{ 32,6 },
	{ 33,6 },
	{ 34,6 },
	{ 35,6 },
};
//2�i�K�ʏ�U�����[�V����
static TexAnim gunPlayerAttack2[] =
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
static TexAnim gunPlayerWeponChenge2[] =
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
static TexAnim gunPlayerChrage3[] =
{
	{ 72,6 },
	{ 73,6 },
};
//3�i�K�U�����[�V����
static TexAnim swordPlayerAttack3[] =
{
	{ 39,6 },
	{ 40,6 },
	{ 41,6 },
	{ 42,6 },
	{ 43,6 },
	{ 44,6 },
	{ 45,6 },
	{ 46,6 },
	{ 47,6 },
};
//3�i�K�U�����[�V����
static TexAnim gunPlayerAttack3[] =
{
	{ 75,6 },
	{ 76,120 },
};
//��e���[�V����
static TexAnim PlayerDamage[] =
{
	{ 78,10 },
	{ 79,20 },
};
//���j���[�V����
static TexAnim swordPlayerDie[] =
{
	{ 81,6 },
	{ 82,6 },
};
//���j���[�V����
static TexAnim gunPlayerDie[] =
{
	{ 81,6 },
	{ 82,6 },
	{ 83,6 },
	{ 84,6 },
};

TexAnimData player_anim_data[] =
{
	ANIMDATA(gunPlayerIdle1),				//0
	ANIMDATA(gunPlayerIdle2),				//1
	ANIMDATA(swordPlayerWalk),				//2
	ANIMDATA(gunPlayerWalk),				//3
	ANIMDATA(PlayerJumpUp),					//4
	ANIMDATA(PlayerJumpStand),				//5
	ANIMDATA(PlayerJumpDown),				//6
	ANIMDATA(PlayerJumpAttack),				//7
	ANIMDATA(gunPlayerReady1),				//8
	ANIMDATA(gunPlayerChrage1),				//9
	ANIMDATA(swordPlayerAttack1),			//10
	ANIMDATA(gunPlayerAttack1),				//11
	ANIMDATA(gunPlayerChrageAttack1),		//12
	ANIMDATA(gunPlayerWeponChenge1),		//13
	ANIMDATA(swordPlayerAttack2),			//14
	ANIMDATA(gunPlayerAttack2),				//15
	ANIMDATA(gunPlayerWeponChenge2),		//16
	ANIMDATA(gunPlayerChrage3),				//17
	ANIMDATA(swordPlayerAttack3),			//18
	ANIMDATA(gunPlayerAttack3),				//19
	ANIMDATA(PlayerDamage),					//20
	ANIMDATA(swordPlayerDie),				//21
	ANIMDATA(gunPlayerDie),					//22
};