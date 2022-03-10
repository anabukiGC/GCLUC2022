#include "Player.h"
#include "../Global.h"

Player::Player(const CVector3D& pos, bool flip) : Base(0,0)
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

	m_is_ground = true;

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
	}

	//重力による落下
	/*
	if (m_is_ground == false)
	{
		m_vec.y -= GRAVITY;
		m_pos += m_vec;
	}
	*/

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

	//ジャンプ
	if (PUSH(CInput::eButton3))
	{
		m_state = eState_Jump;
	}

	//攻撃状態に以降
	if (PUSH(CInput::eMouseL))
	{
		m_state = eState_Attack;
	}

	//移動中なら
	if (MoveFlag) {
		//歩くアニメーション
		//m_img.ChangeAnimation(eAnimWalk);
	}
	else {
		//待機アニメーション
		//m_img.ChangeAnimation(eAnimstand);
	}
}

void Player::StateJump()
{
	JumpTime++;

	const float JumpPower = 5.0f;
	//ジャンプ時Y座標取得
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
