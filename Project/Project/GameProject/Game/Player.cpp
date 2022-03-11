#include "Player.h"
#include "PlayerAnimData.h"
#include "../Global.h"

Player::Player(const CVector3D& pos, bool flip) : Base(eType_Player,1)
{
	m_img = COPY_RESOURCE("Player", CImage);
	//画像サイズ設定
	m_img.SetSize(256, 256);
	//画像の中心位置設定
	m_img.SetCenter(128, 256);
	m_img.ChangeAnimation(0);
	m_pos = pos;
	m_rect = RectBox(-128, -256, 128, 0, 32, -32);
	time = 0;

	//反転フラグ
	m_flip = flip;

	m_bound = false;
	m_jump = false;

	JumpPosition = 0;
	GetY = false;
	JumpTime = 0;
}

void Player::Update()
{
	switch (m_state) 
	{
		//通常状態
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
		{//仮　地面用
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
	//アニメーション更新
	m_img.UpdateAnimation();

	//スクロール値設定
	m_scroll.x = m_pos.x - SCREEN_WIDTH/2;
}

void Player::Draw()
{
	Base::Draw3D();
}


void Player::StateIdle()
{
	//移動量
	const float WalkSpeed = 6.0f;
	//移動フラグ
	bool MoveFlag = false;

	//左移動
	if (HOLD(CInput::eLeft)) 
	{
		//移動量を設定
		m_pos.x -= WalkSpeed;
		//反転フラグ
		m_flip = true;
		MoveFlag = true;
	}
	//右移動
	if (HOLD(CInput::eRight))
	{
		//移動量を設定
		m_pos.x += WalkSpeed;
		//反転フラグ
		m_flip = false;
		MoveFlag = true;
	}
	//上移動
	if (HOLD(CInput::eUp))
	{
		m_pos.z -= WalkSpeed;
		MoveFlag = true;
	}
	//下移動
	if (HOLD(CInput::eDown))
	{
		m_pos.z += WalkSpeed;
		MoveFlag = true;
	}

	//ジャンプ
	if (PUSH(CInput::eButton3))
	{
		m_state = eState_Jump;
		const float JumpPower = 10.0f;
		m_vec.y = JumpPower;
		m_bound = false;
	}

	//攻撃状態に以降
	if (PUSH(CInput::eButton1))
	{
		m_state = eState_Attack1;
	}

	//移動中なら
	if (MoveFlag) {
		//歩くアニメーション
		m_img.ChangeAnimation(2);
	}
	else {
		//待機アニメーション
		m_img.ChangeAnimation(0);
	}
}

void Player::StateJump()
{
	//移動量
	const float WalkSpeed = 6.0f;
	//移動フラグ
	bool MoveFlag = false;

	//左移動
	if (HOLD(CInput::eLeft))
	{
		//移動量を設定
		m_pos.x -= WalkSpeed;
		//反転フラグ
		m_flip = true;
	}
	//右移動
	if (HOLD(CInput::eRight))
	{
		//移動量を設定
		m_pos.x += WalkSpeed;
		//反転フラグ
		m_flip = false;
	}
	//上移動
	if (HOLD(CInput::eUp))
	{
		//移動量を設定
		m_pos.z -= WalkSpeed;
	}
	//下移動
	if (HOLD(CInput::eDown))
	{
		//移動量を設定
		m_pos.z += WalkSpeed;
	}
	if (m_bound)
	{
		m_state = eState_Idle;
	}

	if (m_vec.y >= 0) {
		//上昇アニメーション
		m_img.ChangeAnimation(3);
	}
	else {
		//下降アニメーション
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

		}
		else
		{
			m_state = eState_Idle;
		}
	}
}

void Player::StateAttack3()
{
	//m_img.ChangeAnimation(eAnimAttack3);

	if (m_img.CheckAnimationEnd())
	{
		if (HOLD(CInput::eButton1))
		{

		}
		else
		{
			m_state = eState_Idle;
		}
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
				SetKill();
			}
		}
		break;
	}
}
