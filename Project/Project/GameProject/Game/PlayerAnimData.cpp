#include "PlayerAnimData.h"

//待機モーション(瞬きなし)
static TexAnim playerIdle1[] =
{
	{ 0,20},
	{ 1,20},
	{ 2,20},
	{ 3,20},
};
//待機モーション(瞬きあり)
static TexAnim playerIdle2[] =
{
	{ 5,20},
	{ 6,20},
	{ 7,20},
	{ 8,20},
};
//歩きモーション
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
//ジャンプ(上昇)
static TexAnim playerJumpUp[] = 
{
	{ 24,3 },
};
//ジャンプ(対空)
static TexAnim playerJumpStand[] = 
{
	{ 25,4 },
};
//ジャンプ(下降)
static TexAnim playerJumpDown[] = 
{
	{ 26,6 },
};

//1段階攻撃かまえモーション
static TexAnim playerReady1[] =
{
	{ 27,6 },
	{ 28,6 },
	{ 29,6 },
	{ 30,6 },
	{ 31,6 },
	{ 32,6 },
};
//1段階攻撃チャージモーション
static TexAnim playerChrage1[] =
{
	{ 36,6 },
	{ 37,6 },
};
//1段階通常攻撃モーション
static TexAnim playerNomalAttack1[] =
{
	{ 34,3 },
	{ 35,3 },
};
//1段階チャージ攻撃モーション
static TexAnim playerChrageAttack1[] =
{
	{ 39,3 },
	{ 40,3 },
};
//2段階武器チェンジモーション
static TexAnim playerWeponChenge1[] =
{
	{ 42,3 },
	{ 43,3 },
};
//2段階通常攻撃モーション
static TexAnim playerAttack2[] =
{
	{ 45,3 },
	{ 46,3 },
	{ 47,3 },
	{ 48,3 },
	{ 49,3 },
	{ 50,3 },
	{ 51,3 },
	{ 52,3 },
	{ 53,3 },
	{ 54,3 },
	{ 55,3 },
	{ 56,3 },
	{ 57,3 },
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
};