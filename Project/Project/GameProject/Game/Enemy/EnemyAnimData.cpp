#include"EnemyAnimData.h":

static TexAnim enemy1Idle[] =
{
	{ 0,15 },
	{ 1,15 },
	{ 2,15 },
	{ 3,15 },
};

static TexAnim enemy1Attack[] =
{
	{ 5,10 },
	{ 6,30 },
	{ 7,50 },
	
};
static TexAnim enemy1Damage[] =
{
	{ 14,2 },
	{ 15,2 },
	{ 16,2 },


};
static TexAnim enemy1Die[] =
{
	{ 10,2 },
	{11,2 },
	{ 12,2 },
	

};

TexAnimData enemy1_anim_data[] =
{
	ANIMDATA(enemy1Idle),
	ANIMDATA(enemy1Attack),
	ANIMDATA(enemy1Damage),
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
static TexAnim enemy3Idle[] =
{
	{ 6,15 },
	{ 5,15 },
	{ 4,15 },
	{ 3,15 },
};

static TexAnim enemy3Jump[] =
{
	{ 13,10 },
	{ 12,10 },
	{ 11,10 },
	{ 10,10 },
	{ 9,10 },
	{ 8,10 },
	{ 7,10 },
};

static TexAnim enemy3Damage[] =
{
	{ 27,2 },
	{ 26,2 },
	{ 25,2 },
};

static TexAnim enemy3Die[] =
{
	{ 20,10 },
	{ 19,10 },
	{ 18,10 },
	{ 17,10 },

};
static TexAnim enemy3Away[] =
{
	{ 34,10 },
	{ 33,10 },
	{ 32,10 },
	{ 31,10 },
	{ 30,10 },
	{ 29,10 },

};
TexAnimData enemy3_anim_data[] =
{
	ANIMDATA(enemy3Idle),
	ANIMDATA(enemy3Jump),
	ANIMDATA(enemy3Damage),
	ANIMDATA(enemy3Die),
	ANIMDATA(enemy3Away),
};

static TexAnim boss1Idle[] =
{
	{ 0,25 },
	{ 1,30 },
	{ 2,30 },
	{ 1,30 },
};

static TexAnim boss1Attack1[] =//?ߐ?
{
	{ 7,15 },
	{ 8,15 },
	{ 9,15 },
	{ 8,5 },
	{ 7,5 },
	{ 8,5 },
	{ 9,5 },
	{ 10,5 },
	{ 11,5 },
	{ 12,5 },
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

static TexAnim boss2Attack1[] =//?ߐ?
{
	{ 10,30 },
	{ 11,30 },
	{ 12,30 },
	
	
	
};

static TexAnim boss2Attack2[] =
{


	{ 25,10 },
	{ 26,10 },
	{ 27,40 },
	{ 28,80 },
	
};
static TexAnim boss2Attack3[] =//覐?
{
	{ 15,30 },
	{ 16,30 },
	{ 17,30 },
	{ 18,50 },


};
static TexAnim boss2Damage[] =
{
	{ 20,5 },
	{ 21,5 },
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
static TexAnim boss2Die[] =
{
	
	{ 5,20 },
	{ 4,20 },
	{ 3,20 },
	{ 2,20 },
	{ 1,20 },
	{ 0,80 },
	{ 1,20 },
	{ 2,20 },
	{ 3,20 },
	{ 4,20 },
	{ 5,20 },
	{ 30,20 },
	{ 31,20 },
	{ 32,20 },
	{ 33,20 },
	{ 34,20 },



};
TexAnimData boss2_anim_data[] =
{
	ANIMDATA(boss2Idle),
	ANIMDATA(boss2Attack1),
	ANIMDATA(boss2Attack2),
	ANIMDATA(boss2Attack3),
	ANIMDATA(boss2Damage),
	ANIMDATA(boss2Change),
	ANIMDATA(boss2Die),
};
static TexAnim Meteor[] =
{
	{ 0,20 },

};
static TexAnim MeteorBreak[] =
{
	{ 4,10 },
	{ 5,10 },
	{ 6,10 },
	{ 7,10 },

};
TexAnimData boss2_meteor_data[] =
{
	ANIMDATA(Meteor),
	ANIMDATA(MeteorBreak),
	
};
static TexAnim Laser[] =
{
	{ 0,5 },
	{ 1,5 },
	{ 2,5 },
	{ 0,5 },
	{ 1,5 },
	{ 2,5 },
	{ 0,5 },
	{ 1,5 },
	{ 2,5 },
};

TexAnimData boss_laser_data[] =
{
	ANIMDATA(Laser),
	

};