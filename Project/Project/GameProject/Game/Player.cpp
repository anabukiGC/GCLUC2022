#include "Player.h"
#include "../Global.h"

Player::Player(const CVector3D& pos, bool flip) : Base(0,0)
{
	m_img = COPY_RESOURCE("Player", CImage);
	//�摜�T�C�Y�ݒ�
	m_img.SetSize(256, 256);
	//�摜�̒��S�ʒu�ݒ�
	m_img.SetCenter(128, 256);
	m_img.ChangeAnimation(0);
	m_pos = pos;
	m_rect = RectBox(-128, -256, 128, 0, 32, -32);
	time = 0;

	//���]�t���O
	m_flip = flip;

	m_is_ground = true;

	JumpPosition = 0;
	GetY = false;
	JumpTime = 0;
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
	}

	//�d�͂ɂ�闎��
	/*
	if (m_is_ground == false)
	{
		m_vec.y -= GRAVITY;
		m_pos += m_vec;
	}
	*/

	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();

	//�X�N���[���l�ݒ�
	m_scroll.x = m_pos.x - SCREEN_WIDTH/2;
}

void Player::Draw()
{
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
	}
	//�E�ړ�
	if (HOLD(CInput::eRight))
	{
		//�ړ��ʂ�ݒ�
		m_pos.x += WalkSpeed;
		//���]�t���O
		m_flip = false;
		MoveFlag = true;
	}

	//�W�����v
	if (PUSH(CInput::eButton3))
	{
		m_state = eState_Jump;
	}

	//�U����ԂɈȍ~
	if (PUSH(CInput::eMouseL))
	{
		m_state = eState_Attack;
	}

	//�ړ����Ȃ�
	if (MoveFlag) {
		//�����A�j���[�V����
		//m_img.ChangeAnimation(eAnimWalk);
	}
	else {
		//�ҋ@�A�j���[�V����
		//m_img.ChangeAnimation(eAnimstand);
	}
}

void Player::StateJump()
{
	JumpTime++;

	const float JumpPower = 5.0f;
	//�W�����v��Y���W�擾
	if (GetY == false)
	{
		JumpPosition = m_pos.y;
		GetY = true;
	}
	if (JumpTime <= 30)
	{
		m_pos.y += JumpPower;
	}
	if (JumpTime >= 35)
	{
		m_pos.y -= JumpPower;
	}
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
	}
	//�E�ړ�
	if (HOLD(CInput::eRight))
	{
		//�ړ��ʂ�ݒ�
		m_pos.x += WalkSpeed;
		//���]�t���O
		m_flip = false;
		MoveFlag = true;
	}

	if (m_pos.y <= JumpPosition)
	{
		JumpTime = 0;
		GetY = false;
		m_state = eState_Idle;
	}
}

void Player::StateAttack()
{
	//m_img.ChangeAnimation(eAnimAttack);
	if (!m_img.CheckAnimationEnd() && PUSH(CInput::eMouseL))
	{

	}
	if(m_img.CheckAnimationEnd())
	{
		m_state = eState_Idle;
	}
}

void Player::Collision(Task* t)
{
	switch (t->GetID())
	{
	case eType_Enemy:
		if (Base* b = dynamic_cast<Base*>(t))
		{
			if (CollisionRect(b, this))
			{
				//SetKill();
			}
		}
		break;
	}
}
