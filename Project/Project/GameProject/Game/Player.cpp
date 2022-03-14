#include "Player.h"
#include "PlayerAnimData.h"
#include "Bullet.h"
#include "EnemyManager.h"
#include "../Global.h"

Player::Player(const CVector3D& pos, bool flip) : Base(eType_Player,1)
{
	m_img = COPY_RESOURCE("Player", CImage);
	//�摜�T�C�Y�ݒ�
	m_img.SetSize(256, 256);
	//�摜�̒��S�ʒu�ݒ�
	m_img.SetCenter(128, 256);
	m_img.ChangeAnimation(0);
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
}

void Player::Update()
{
	switch (m_state) 
	{
		//�ʏ���
	case eState_Idle:
		StateIdle();
		break;
	case eState_Jump:
		StateJump();
		break;
	case eState_Attack1:
		StateAttack1();
		break;
	case eState_Attack2:
		StateAttack2();
		break;
	case eState_Attack3:
		StateAttack3();
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

		if (m_pos.z >= 1000)
		{
			m_pos.z = 1000;
		}
		if (m_pos.z <= 600)
		{
			m_pos.z = 600;
		}

		if (m_mutekiTime > 0)
		{
			m_mutekiTime--;
		}

	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();

	//�X�N���[���l�ݒ�
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
	//�ړ��t���O
	bool MoveFlag = false;

	//���ړ�
	if (HOLD(CInput::eLeft)) 
	{
		//�ړ��ʂ�ݒ�
		m_pos.x -= WalkSpeed;
		//���]�t���O
		m_flip = true;
		MoveFlag = true;
		m_rect = RectLeft;
	}
	//�E�ړ�
	if (HOLD(CInput::eRight))
	{
		//�ړ��ʂ�ݒ�
		m_pos.x += WalkSpeed;
		//���]�t���O
		m_flip = false;
		MoveFlag = true;
		m_rect = RectRight;
	}
	//��ړ�
	if (HOLD(CInput::eUp))
	{
		m_pos.z -= WalkSpeed;
		MoveFlag = true;
	}
	//���ړ�
	if (HOLD(CInput::eDown))
	{
		m_pos.z += WalkSpeed;
		MoveFlag = true;
	}

	//�W�����v
	if (PUSH(CInput::eButton3))
	{
		m_state = eState_Jump;
		const float JumpPower = 10.0f;
		m_vec.y = JumpPower;
		m_bound = false;
	}

	//�U����ԂɈȍ~
	if (PUSH(CInput::eButton1))
	{
		m_state = eState_Attack1;
	}

	//�ړ����Ȃ�
	if (MoveFlag) {
		//�����A�j���[�V����
		m_img.ChangeAnimation(2);
	}
	else {
		//�ҋ@�A�j���[�V����
		m_img.ChangeAnimation(0);
	}
}

void Player::StateJump()
{
	//�ړ���
	const float WalkSpeed = 6.0f;
	//�ړ��t���O
	bool MoveFlag = false;

	//���ړ�
	if (HOLD(CInput::eLeft))
	{
		//�ړ��ʂ�ݒ�
		m_pos.x -= WalkSpeed;
		//���]�t���O
		m_flip = true;
	}
	//�E�ړ�
	if (HOLD(CInput::eRight))
	{
		//�ړ��ʂ�ݒ�
		m_pos.x += WalkSpeed;
		//���]�t���O
		m_flip = false;
	}
	//��ړ�
	if (HOLD(CInput::eUp))
	{
		//�ړ��ʂ�ݒ�
		m_pos.z -= WalkSpeed;
	}
	//���ړ�
	if (HOLD(CInput::eDown))
	{
		//�ړ��ʂ�ݒ�
		m_pos.z += WalkSpeed;
	}
	if (m_bound)
	{
		m_state = eState_Idle;
	}

	if (m_vec.y >= 0) {
		//�㏸�A�j���[�V����
		m_img.ChangeAnimation(3);
	}
	else {
		//���~�A�j���[�V����
		m_img.ChangeAnimation(5);
	}
}

void Player::StateAttack1()
{
	m_img.ChangeAnimation(6, false);
	
	if(m_img.CheckAnimationEnd())
	{
		if (HOLD(CInput::eButton1))
		{
			m_state = eState_Attack2;
		}
		else
		{
			m_state = eState_Idle;
		}
	}

	//�e�̐���
	if (m_img.GetIndex() == 7 && Fire == false)
	{
		if (m_flip)
		{
			new Bullet(eType_NomalBullet, CVector3D(m_pos.x - 80, m_pos.y + 171, m_pos.z), false);
		}

		if (!m_flip)
		{
			new Bullet(eType_NomalBullet, CVector3D(m_pos.x + 80, m_pos.y + 171, m_pos.z), true);
		}
		Fire = true;
	}
	/*
	if (!m_img.CheckAnimationEnd() && PUSH(CInput::eButton1))
	{
		m_state = eState_Attack2;
	}
	else if (m_img.CheckAnimationEnd())
	{
		m_state = eState_Idle;
	}
	*/
}

void Player::StateAttack2()
{
	//m_img.ChangeAnimation(eAnimAttack2);

	if (m_img.CheckAnimationEnd())
	{
		if (HOLD(CInput::eButton1))
		{
			m_state = eState_Attack3;
		}
		else
		{
			m_state = eState_Idle;
			//�e�̒e���C�t���O�̃��Z�b�g
			Fire = false;
		}
	}
}

void Player::StateAttack3()
{
	//m_img.ChangeAnimation(eAnimAttack3);

	if (m_img.CheckAnimationEnd())
	{
			m_state = eState_Idle;
			//�e�̒e���C�t���O�̃��Z�b�g
			Fire = false;
	}
}

void Player::Collision(Task* t)
{
	switch (t->GetID())
	{
	case eType_Enemy:
		if (Base* b = dynamic_cast<Base*>(t))
		{
			if (m_mutekiTime > 0)
			{
				break;
			}
			if (CollisionRect(b, this))
			{
				m_mutekiTime = 180;
				m_hp -= 10;
				//SetKill();
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
