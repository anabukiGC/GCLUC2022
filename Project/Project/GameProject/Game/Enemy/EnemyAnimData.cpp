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
	{ 12,2 },
	{ 13,2 },
	{ 14,2 },
	{ 15,2 },
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
	{ 7,15 },
	{ 8,15 },
	{ 9,15 },
	{ 8,15 },
	{ 7,15 },
	{ 8,15 },
	{ 9,15 },
	{ 10,15 },
	{ 11,15 },
	{ 12,15 },
};

static TexAnim boss1Attack2[] =
{
	

	{ 2,60 },
	{ 4,10 },
	{ 5,10 },
	{ 6,120 },
	{ 5,10 },
};

static TexAnim boss1Damage[] =
{
	{ 14,2 },
	{ 15,2 },
	{ 16,2 },
	

};

static TexAnim boss1Change[] =
{
	{ 18,20 },
	{ 19,20 },
	{ 20,20 },
	{ 21,20 },
	{ 22,80 },
	{ 24,10 },
	{ 25,10 },
	{ 26,10 },
	{ 27,10 },
	{ 28,10 },
	{ 29,10 },

};

TexAnimData boss1_anim_data[] =
{
	ANIMDATA(boss1Idle),
	ANIMDATA(boss1Attack1),
	ANIMDATA(boss1Attack2),
	ANIMDATA(boss1Damage),
	ANIMDATA(boss1Change),
};

static TexAnim boss2Idle[] =
{
	{ 5,20 },
	{ 6,20 },
	{ 7,20 },
	
};

static TexAnim boss2Attack1[] =//ãﬂê⁄
{
	{ 15,30 },
	{ 16,30 },
	{ 17,30 },
	{ 18,50 },
	
	
};

static TexAnim boss2Attack2[] =
{


	{ 2,60 },
	{ 4,10 },
	{ 5,10 },
	{ 6,120 },
	{ 5,10 },
};

static TexAnim boss2Damage[] =
{
	
	{ 21,10 },
	{ 22,10 },

};

static TexAnim boss2Change[] =
{
	{ 0,20 },
	{ 1,20 },
	{ 2,20 },
	{ 3,20 },
	{ 4,20 },
	{ 5,40 },

};

TexAnimData boss2_anim_data[] =
{
	ANIMDATA(boss2Idle),
	ANIMDATA(boss2Attack1),
	ANIMDATA(boss2Attack2),
	ANIMDATA(boss2Damage),
	ANIMDATA(boss2Change),
};
