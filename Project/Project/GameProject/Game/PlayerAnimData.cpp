#include "PlayerAnimData.h"

//待機モーション(瞬きあり)
static TexAnim playerIdle1[] =
{
	{ 0,20},
	{ 1,20},
	{ 2,20},
	{ 3,20},
};
//待機モーション(瞬きなし)
static TexAnim playerIdle2[] =
{
	{ 4,20 },
	{ 5,20},
	{ 6,20},
	{ 7,20},
};
TexAnimData player_anim_data[] =
{
	ANIMDATA(playerIdle1),
	ANIMDATA(playerIdle2),
};