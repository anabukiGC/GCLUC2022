#include"EnemyAnimData.h":

static TexAnim enemy2Idle[] =
{
	{ 0,15 },
	{ 1,15 },
	
};

static TexAnim enemy2Jump[] =
{
	{ 4,10 },
	{ 5,20 },
	{ 6,20 },
	{ 7,10 },
};

static TexAnim enemy2Die[] =
{
	{ 8,2 },
	{ 9,2 },
	{ 10,2 },
	{ 11,2 },
	
};

TexAnimData enemy2_anim_data[] =
{
	ANIMDATA(enemy2Idle),
	ANIMDATA(enemy2Jump),
	ANIMDATA(enemy2Die),
};