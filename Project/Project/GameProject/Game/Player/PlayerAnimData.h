#pragma once
#include <GLLibrary.h>

//!�A�j���[�V�����̎��
enum {
	eAnimIdle = 0,
	eAnimIdle2,
	eAnimGunWalk,
	eAnimSwordWalk,
	eAnimJumpUp,
	eAnimJumpStand,
	eAnimJumpDown,
	eAnimGunReady1,
	eAnimGunChrage1,
	eAnimSwordAttack1,
	eAnimGunAttack1,
	eAnimGunChrageAttack1,
	eAnimGunWeponChenge1,
	eAnimSwordAttack2,
	eAnimGunAttack2,
	eAnimGunWeponChenge2,
	eAnimGunChrage3,
	eAnimSwordAttack3,
	eAnimGunAttack3,
	eAnimDamage,
	eAnimSwordDie,
	eAnimGunDie,
};

//�v���C���[�̃A�j���[�V�����f�[�^
extern TexAnimData player_anim_data[];
