#include"EnemyAnimData.h":

static TexAnim enemy1Idle[] =
{
	{ 0,15 },
	{ 1,15 },
	{ 2,15 },
	{ 3,15 },
};

static TexAnim enemy1Jump[] =
{
	{ 4,10 },
	{ 5,50 },
	{ 6,50 },
	{ 7,70 },
};

static TexAnim enemy1Die[] =
{
	{ 8,2 },
	{ 9,2 },
	{ 10,2 },
	{ 11,2 },

};

TexAnimData enemy1_anim_data[] =
{
	ANIMDATA(enemy1Idle),
	ANIMDATA(enemy1Jump),
	ANIMDATA(enemy1Die),
};

static TexAnim enemy2Idle[] =
{
	{ 0,15 },
	{ 1,15 },
	
};

static TexAnim enemy2Jump[] =
{
	{ 4,10 },
	{ 5,50 },
	{ 6,50 },
	{ 7,70 },
};

static TexAnim enemy2Damage[] =
{
	{ 9,10 },
	{ 10,50 },
	{ 4,50 },
	{ 6,70 },
};

static TexAnim enemy2Die[] =
{
	{ 8,10 },
	{ 9,10 },
	{ 10,10 },
	{ 11,10 },
	
};

TexAnimData enemy2_anim_data[] =
{
	ANIMDATA(enemy2Idle),
	ANIMDATA(enemy2Jump),
	ANIMDATA(enemy2Damage),
	ANIMDATA(enemy2Die),
};

static TexAnim boss1Idle[] =
{
	{ 0,25 },
	{ 1,30 },
	{ 2,30 },
	{ 1,30 },
};

static TexAnim boss1Attack1[] =//ãﬂê⁄
{
	{ 7,100 },
	{ 8,30 },
	{ 9,15 },
	{ 10,15 },
	{ 11,15 },
	{ 12,15 },
};

static TexAnim boss1Attack2[] =
{
	

	{ 2,120 },
	{ 4,40 },
	{ 5,20 },
	{ 6,120 },
	{ 5,20 },
};

static TexAnim boss1Damage[] =
{
	{ 14,20 },
	{ 15,20 },
	{ 16,20 },
	

};

static TexAnim boss1Change[] =
{
	{ 18,20 },
	{ 19,20 },
	{ 20,20 },
	{ 21,20 },
	{ 22,20 },
};

TexAnimData boss1_anim_data[] =
{
	ANIMDATA(boss1Idle),
	ANIMDATA(boss1Attack1),
	ANIMDATA(boss1Attack2),
	ANIMDATA(boss1Damage),
	ANIMDATA(boss1Change),
};