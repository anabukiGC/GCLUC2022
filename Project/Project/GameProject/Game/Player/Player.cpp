#include "Player.h"
#include "PlayerAnimData.h"
#include "Bullet.h"
#include "EnemyManager.h"
#include "Laser.h"
#include "PlayerEffect.h"
#include "Enemy.h"
#include "AttackObject.h"
#include "../Global.h"

std::vector<Player*> Player::m_players(2);

Player::Player(int kind,const CVector3D& pos, bool flip) : Base(eType_Player,ePriorityPlayer)
{
	if (kind == eSword)
	{
		m_img = COPY_RESOURCE("SwordPlayer", CImage);
		m_scale = 1.3;
		//�摜�T�C�Y�ݒ�
		m_img.SetSize(256 * m_scale, 256 * m_scale);
	}
	else
	{
		m_img = COPY_RESOURCE("GunPlayer", CImage);
		m_scale = 1.0;
		//�摜�T�C�Y�ݒ�
		m_img.SetSize(256 * m_scale, 256 * m_scale);
	}

	m_img.ChangeAnimation(eAnimIdle);
	m_pos = pos;
	RectRight = RectBox(-80, 0, 40, 238, 32, -32);
	RectLeft = RectBox(-40, 0, 80, 238, 32, -32);
	m_rect = RectRight;
	time = 0;
	//�{�^���̉�������
	HoldTime = 0;

	m_hp = 100;//�ύX�p
	m_max_hp = 100;

	m_p_hp = new PlayerHp(this);//�|�C���^�[�n���̂�this

	//���]�t���O
	m_flip = flip;

	m_bound = false;
	m_jump = false;

	JumpPosition = 0;
	GetY = false;
	JumpTime = 0;

	m_mutekiTime = 0;

	Fire = false;

	m_state_attack = 0;
	m_state_attack2 = 0;
	m_state_attack3 = 0;

	m_secondAttackTime = 0;

	//�v���C���[�̎��
	m_kind = kind;

	m_players[kind] = this;
}

void Player::Update()
{
	m_key_dir = CInput::GetLStick(m_kind);
	//���ړ�
	if (HOLD_PAD(m_kind, CInput::eLeft))
	{
		m_key_dir.x = -1;
	}
	//�E�ړ�
	else if (HOLD_PAD(m_kind, CInput::eRight))
	{
		m_key_dir.x = 1;
	}
	//��ړ�
	if (HOLD_PAD(m_kind, CInput::eUp))
	{
		m_key_dir.y = -1;
	}
	//���ړ�
	else if (HOLD_PAD(m_kind, CInput::eDown))
	{
		m_key_dir.y = 1;
	}

	switch (m_state) 
	{
		//�ʏ���
	case eState_Idle:
		StateIdle();
		break;
	case eState_Jump:
		StateJump();
		break;
	case eState_JumpAttack:
		StateJumpAttack();
		break;
	case eState_SwordAttack1:
		StateSwordAttack1();
		break;
	case eState_SwordAttack2:
		StateSwordAttack2();
		break;
	case eState_SwordAttack3:
		StateSwordAttack3();
		break;
	case eState_GunAttack1:
		StateGunAttack1();
		break;
	case eState_GunAttack2:
		StateGunAttack2();
		break;
	case eState_GunAttack3:
		StateGunAttack3();
		break;
	case eState_Damage:
		StateDamage();
		break;
	case eState_Die:
		StateDie();
		break;
	}
		m_vec.y -= GRAVITY;
		m_pos.y += m_vec.y;

		if (m_pos.y <= 0) 
		{//���@�n�ʗp
			m_pos.y = 0;
			m_vec.y = 0;
			m_bound = true;
		}

		if (m_pos.z >= 500)
		{
			m_pos.z = 500;
		}

		if (m_pos.z <= 0)
		{
			m_pos.z = 0;
		}

		if (m_mutekiTime > 0)
		{
			m_mutekiTime--;
		}

	//�D��x�ύX
	ChangePriority(ePriorityPlayer + m_pos.z);

	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();

	//�X�N���[���l�ݒ�
	if (Player::GetPlayer(Player::eSword))
	{
		if (m_kind == eSword)
		{
			if (EnemyManager* b = dynamic_cast<EnemyManager*>(TaskManager::GetInstance()->GetTask(eType_EnemyManager)))
			{
				if (b->GetWave())
				{
				}
				else
				{
					m_scroll.x = m_pos.x - SCREEN_WIDTH / 2;
				}
			}
		}
	}
	else
	{
		if (m_kind == eGun)
		{
			if (EnemyManager* b = dynamic_cast<EnemyManager*>(TaskManager::GetInstance()->GetTask(eType_EnemyManager)))
			{
				if (b->GetWave())
				{
				}
				else
				{
					m_scroll.x = m_pos.x - SCREEN_WIDTH / 2;
				}
			}
		}
	}
	
	//���ړ�����
	if (m_pos.x <= m_scroll.x - m_rect.m_left)
	{
		m_pos.x = m_scroll.x - m_rect.m_left;
	}
	if (m_pos.x >= m_scroll.x + SCREEN_WIDTH)
	{
		m_pos.x = m_scroll.x + SCREEN_WIDTH;
	}
}

void Player::Draw()
{
	//�摜�̒��S�ʒu�ݒ�
	if (m_flip)
	{
		m_img.SetCenter(128 + 24 * m_scale, 256);
	}
	else
	{
		m_img.SetCenter(128 - 24 * m_scale, 256);
	}

	if (m_mutekiTime % 20 > 10)
	{
		m_img.SetColor(1, 1, 1, 0.5);
	}
	else
	{
		m_img.SetColor(1, 1, 1, 1);
	}
	Base::Draw3D();
}


void Player::StateIdle()
{
	//�ړ���
	const float WalkSpeed = 6.0f;

	m_pos.x += m_key_dir.x* WalkSpeed;
	m_pos.z += m_key_dir.y * WalkSpeed;
	const float free_space = 0.0001f;


	//�ړ��t���O
	bool MoveFlag = false;

	if (m_key_dir.LengthSq() > free_space)
	{
		MoveFlag = true;
	}
	if (m_key_dir.x < -free_space)
	{
		m_rect = RectLeft;
		m_flip = true;
	}
	else if (m_key_dir.x > free_space)
	{
		m_rect = RectRight;
		m_flip = false;
	}

	//�W�����v
	if (PUSH_PAD(m_kind, CInput::eButton3))
	{
		m_state = eState_Jump;
		const float JumpPower = 10.0f;
		m_vec.y = JumpPower;
		m_bound = false;
	}

	//�U����ԂɈȍ~
	if (PUSH_PAD(m_kind, CInput::eButton1))
	{
		if (m_kind == eGun)
		{
			m_state = eState_GunAttack1;
		}
		if (m_kind == eSword)
		{
			m_state = eState_SwordAttack1;
		}
		m_state_attack = 0;
		m_state_attack2 = 0;
		m_state_attack3 = 0;
	}

	//�ړ����Ȃ�
	if (MoveFlag) {
		//�����A�j���[�V����
		m_img.ChangeAnimation(eAnimGunWalk);
	}
	else {
		//�ҋ@�A�j���[�V����
		m_img.ChangeAnimation(eAnimIdle);
	}
}

void Player::StateJump()
{
	//�ړ���
	const float WalkSpeed = 6.0f;

	m_pos.x += m_key_dir.x * WalkSpeed;
	m_pos.z += m_key_dir.y * WalkSpeed;
	const float free_space = 0.0001f;


	//�ړ��t���O
	bool MoveFlag = false;

	if (m_key_dir.LengthSq() > free_space)
	{
		MoveFlag = true;
	}
	if (m_key_dir.x < -free_space)
	{
		m_rect = RectLeft;
		m_flip = true;
	}
	else if (m_key_dir.x > free_space)
	{
		m_rect = RectRight;
		m_flip = false;
	}

	//�W�����v�U��
	if (PUSH_PAD(m_kind , CInput::eButton1))
	{
		if (m_kind == eSword)
		{
			m_state = eState_JumpAttack;
		}
	}

	if (m_bound)
	{
		m_state = eState_Idle;
	}

	if (m_vec.y >= 0) {
		//�㏸�A�j���[�V����
		m_img.ChangeAnimation(eAnimJumpUp, false);
	}
	else {
		//���~�A�j���[�V����
		m_img.ChangeAnimation(eAnimJumpDown,false);
	}
}

void Player::StateJumpAttack()
{
	m_img.ChangeAnimation(eAnimJumpAttack, false);

	if (m_img.GetIndex() == 2)
	{
		if (m_flip)
		{
			new PlayerEffect(eType_PlayerEffect1, CVector3D(m_pos.x - 150, m_pos.y + 120, m_pos.z), m_flip);
		}
		if (!m_flip)
		{
			new PlayerEffect(eType_PlayerEffect1, CVector3D(m_pos.x + 170, m_pos.y + 120, m_pos.z), m_flip);
		}

	}

	if (m_img.CheckAnimationEnd())
	{
		m_state = eState_Jump;
	}
	if (m_bound)
	{
		m_state = eState_Idle;
	}
}

void Player::StateSwordAttack1()
{
	m_img.ChangeAnimation(eAnimSwordAttack1, false);
	
	if (m_img.GetIndex() == 2)
	{
		if (m_flip)
		{
			new PlayerEffect(eType_PlayerEffect1, CVector3D(m_pos.x - 150, m_pos.y + 170, m_pos.z), m_flip);
		}
		if (!m_flip)
		{
			new PlayerEffect(eType_PlayerEffect1, CVector3D(m_pos.x + 170, m_pos.y + 170, m_pos.z), m_flip);
		}
		
	}

	if (m_img.CheckAnimationEnd())
	{
		if (HOLD_PAD(m_kind, CInput::eButton1))
		{
			m_state = eState_SwordAttack2;
		}
		else
		{
			m_state = eState_Idle;
		}
	}
}

void Player::StateSwordAttack2()
{
	m_img.ChangeAnimation(eAnimSwordAttack2, false);

	if (m_img.GetIndex() == 2)
	{
		if (m_flip)
		{
			new PlayerEffect(eType_PlayerEffect2, CVector3D(m_pos.x - 150, m_pos.y + 120, m_pos.z), m_flip);
		}
		if (!m_flip)
		{
			new PlayerEffect(eType_PlayerEffect2, CVector3D(m_pos.x + 170, m_pos.y + 120, m_pos.z), m_flip);
		}

	}

	if (m_img.CheckAnimationEnd())
	{
		if (HOLD_PAD(m_kind, CInput::eButton1))
		{
			m_state = eState_SwordAttack3;
		}
		else
		{
			m_state = eState_Idle;
		}
	}
}

void Player::StateSwordAttack3()
{
	m_img.ChangeAnimation(eAnimSwordAttack3, false);

	if (m_img.GetIndex() == 8)
	{
		if (m_flip)
		{
			new PlayerEffect(eType_PlayerEffect3, CVector3D(m_pos.x - 150, m_pos.y + 100, m_pos.z), m_flip);
		}
		if (!m_flip)
		{
			new PlayerEffect(eType_PlayerEffect3, CVector3D(m_pos.x + 170, m_pos.y + 100, m_pos.z), m_flip);
		}
	}

	if (m_img.CheckAnimationEnd())
	{
			m_state = eState_Idle;
	}
}

void Player::StateGunAttack1()
{
	switch (m_state_attack)
	{
	case 0:
		Fire = false;
		HoldTime = 0;
		m_secondAttackTime = 0;
		m_img.ChangeAnimation(eAnimGunReady1, false);
		if (m_img.CheckAnimationEnd())
		{
			m_state_attack++;
		}
		break;
	case 1:
		m_img.ChangeAnimation(eAnimGunChrage1, true);
		HoldTime++;
		if (FREE_PAD(m_kind,CInput::eButton1))
		{
			if (HoldTime >= 60)
			{
				m_state_attack = 2;
			}
			else
			{
				m_state_attack = 3;
			}
		}
		if (HoldTime >= 100)
		{
			m_state_attack = 2;
		}
		break;
	case 2:
		m_img.ChangeAnimation(eAnimGunAttack1, false);
		if (m_img.GetIndex() == 1 && Fire == false)
		{
			if (m_flip)
			{
				new Bullet(eType_NomalBullet, CVector3D(m_pos.x - 80, m_pos.y + 171, m_pos.z), m_flip);
			}

			if (!m_flip)
			{
				new Bullet(eType_NomalBullet, CVector3D(m_pos.x + 80, m_pos.y + 171, m_pos.z), m_flip);
			}
			Fire = true;
			m_state_attack = 4;
		}
		break;
	case 3:
		m_img.ChangeAnimation(eAnimGunChrageAttack1, false);

		if (m_img.GetIndex() == 1 && Fire == false)
		{
			if (m_flip)
			{
				new Bullet(eType_NomalBullet, CVector3D(m_pos.x - 80, m_pos.y + 171, m_pos.z), m_flip);
			}

			if (!m_flip)
			{
				new Bullet(eType_NomalBullet, CVector3D(m_pos.x + 80, m_pos.y + 171, m_pos.z), m_flip);
			}
			Fire = true;
			m_state_attack = 4;
		}
		break;
	case 4:
		m_secondAttackTime++;
		if (m_secondAttackTime < 120 && HOLD_PAD(m_kind, CInput::eButton1))
		{
			m_state = eState_GunAttack2;
		}
		else
		{
			m_state = eState_Idle;
		}
		break;
	}
}

void Player::StateGunAttack2()
{
	switch (m_state_attack2)
	{
	case 0:
		Fire = false;
		HoldTime = 0;
		m_secondAttackTime = 0;
		m_img.ChangeAnimation(eAnimGunWeponChenge1, false);
		if (m_img.CheckAnimationEnd())
		{
			m_state_attack2++;
		}
		break;
	case 1:
		m_img.ChangeAnimation(eAnimGunAttack2, false);
		if (m_img.GetIndex() == 2 && Fire == false)
		{
			if (m_flip)
			{
				new Bullet(eType_NomalBullet2, CVector3D(m_pos.x + 66, m_pos.y + 153, m_pos.z), m_flip, DtoR(-30));
			}
			if(!m_flip)
			{
				new Bullet(eType_NomalBullet2, CVector3D(m_pos.x - 66, m_pos.y + 153, m_pos.z), m_flip, DtoR(-30));
			}
		}
		if (m_img.GetIndex() == 4 && Fire == false)
		{
			if (m_flip)
			{
				new Bullet(eType_NomalBullet2, CVector3D(m_pos.x + 74, m_pos.y + 176, m_pos.z), m_flip, DtoR(0));
			}
			if (!m_flip)
			{
				new Bullet(eType_NomalBullet2, CVector3D(m_pos.x - 74, m_pos.y + 176, m_pos.z), m_flip, DtoR(0));
			}
		}
		if (m_img.GetIndex() == 6 && Fire == false)
		{
			if (m_flip)
			{
				new Bullet(eType_NomalBullet2, CVector3D(m_pos.x + 70, m_pos.y + 194, m_pos.z), m_flip, DtoR(60));
			}
			if (!m_flip)
			{
				new Bullet(eType_NomalBullet2, CVector3D(m_pos.x - 70, m_pos.y + 194, m_pos.z), m_flip, DtoR(60));
			}
		}
		if (m_img.GetIndex() == 8 && Fire == false)
		{
			if (m_flip)
			{
				new Bullet(eType_NomalBullet2, CVector3D(m_pos.x + 51, m_pos.y + 232, m_pos.z), m_flip, DtoR(80));
			}
			if (!m_flip)
			{
				new Bullet(eType_NomalBullet2, CVector3D(m_pos.x - 51, m_pos.y + 232, m_pos.z), m_flip, DtoR(80));
			}
			Fire = true;
			m_state_attack2 = 2;
		}

		if (m_img.CheckAnimationEnd())
		{
			m_state_attack2 = 2;
		}
		break;
	case 2:
		m_secondAttackTime++;
		if (m_secondAttackTime < 120 && HOLD_PAD(m_kind, CInput::eButton1))
		{
			m_state = eState_GunAttack3;
		}
		else
		{
			m_state = eState_Idle;
		}
		break;
	}
}

void Player::StateGunAttack3()
{
	switch (m_state_attack3)
	{
	case 0:
		Fire = false;
		HoldTime = 0;
		m_secondAttackTime = 0;
		m_img.ChangeAnimation(eAnimGunWeponChenge2, false);
		if (m_img.CheckAnimationEnd())
		{
			m_state_attack3++;
		}
		break;
	case 1:
		m_img.ChangeAnimation(eAnimGunChrage3, true);
		HoldTime++;
		if (FREE_PAD(m_kind, CInput::eButton1))
		{
			if (HoldTime >= 60 * 2)
			{
				m_state_attack3 = 2;
			}
			else
			{
				m_state_attack3 = 3;
			}
		}
		break;
	case 2:
		m_img.ChangeAnimation(eAnimGunAttack3, false);
		if (m_img.GetIndex() == 1 && Fire == false)
		{
			if (m_flip)
			{
				new Laser(CVector3D(m_pos.x - 1000, m_pos.y + 211, m_pos.z), m_flip, 60 * 2);
			}

			if (!m_flip)
			{
				new Laser(CVector3D(m_pos.x + 50, m_pos.y + 211, m_pos.z), m_flip, 60 * 2);
			}
			Fire = true;
		}
		if (m_img.CheckAnimationEnd())
		{
			m_state = eState_Idle;
		}
		break;
	case 3:
		m_img.ChangeAnimation(eAnimGunAttack3, false);

		if (m_img.GetIndex() == 1 && Fire == false)
		{
			if (m_flip)
			{
				new Laser(CVector3D(m_pos.x - 1000, m_pos.y + 211, m_pos.z), m_flip, 60 * 2);
			}

			if (!m_flip)
			{
				new Laser(CVector3D(m_pos.x + 50, m_pos.y + 211, m_pos.z), m_flip, 60 * 2);
			}
			Fire = true;
		}

		if (m_img.CheckAnimationEnd())
		{
			m_state = eState_Idle;
		}
		break;
	}
}

void Player::StateDamage()
{
	m_img.ChangeAnimation(eAnimDamage, false);

	if (m_img.CheckAnimationEnd() && m_hp > 0) 
	{
		m_state = eState_Idle;
	}
	if (m_img.CheckAnimationEnd() && m_hp <= 0) 
	{
		m_state = eState_Die;
	}
}

void Player::StateDie()
{
	//���̏�Œ�~
	if(m_kind == eSword)
	m_img.ChangeAnimation(eAnimSwordDie, false);
	if (m_kind == eGun)
	m_img.ChangeAnimation(eAnimGunDie, false);
}

void Player::Collision(Task* t)
{
	switch (t->GetID())
	{
	case eType_EnemyAttack1:
		if (AttackObject* enemy = dynamic_cast<AttackObject*>(t))
		{
			if (CollisionRect(enemy, this))
			{
				if (m_mutekiTime <= 0)
				{
					m_mutekiTime = 180;
					m_hp -= 20;
					m_state = eState_Damage;
				}
			}
		}
		break;
	}
}

int Player::GetHp()
{
	return m_hp;
}

int Player::GetMaxHp()
{
	return 0;
}
