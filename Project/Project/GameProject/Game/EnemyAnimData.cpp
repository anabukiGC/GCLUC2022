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
	ANIMDATA(enemy2Die),
};