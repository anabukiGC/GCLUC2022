#include "Player.h"
#include "PlayerAnimData.h"
#include "Bullet.h"
#include "EnemyManager.h"
#include "../Global.h"

Player::Player(const CVector3D& pos, bool flip) : Base(eType_Player,ePriorityPlayer)
{
	m_img = COPY_RESOURCE("Player", CImage);
	//画像サイズ設定
	m_img.SetSize(256, 256);
	//画像の中心位置設定
	m_img.SetCenter(128, 256);
	m_img.ChangeAnimation(0);
	m_pos = pos;
	RectRight = RectBox(-80, 0, 40, 238, 32, -32);
	RectLeft = RectBox(-40, 0, 80, 238, 32, -32);
	m_rect = RectRight;
	time = 0;
	//ボタンの押し時間
	HoldTime = 0;

	m_hp = 100;//変更用
	m_max_hp = 100;

	m_p_hp = new PlayerHp(this);//ポインター渡すのでthis

	//反転フラグ
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
	case eState_JumpAttack:
		StateJumpAttack();
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

	//優先度変更
	ChangePriority(ePriorityPlayer + m_pos.z);

	//アニメーション更新
	m_img.UpdateAnimation();

	//スクロール値設定
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
	//横移動制限
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
	//移動量
	const float WalkSpeed = 6.0f;
	//移動フラグ
	bool MoveFlag = false;

	//左移動
	if (HOLD_PAD(0, CInput::eLeft))
	{
		//移動量を設定
		m_pos.x -= WalkSpeed;
		//反転フラグ
		m_flip = true;
		MoveFlag = true;
		m_rect = RectLeft;
	}
	//右移動
	if (HOLD_PAD(0, CInput::eRight))
	{
		//移動量を設定
		m_pos.x += WalkSpeed;
		//反転フラグ
		m_flip = false;
		MoveFlag = true;
		m_rect = RectRight;
	}
	//上移動
	if (HOLD_PAD(0, CInput::eUp))
	{
		m_pos.z -= WalkSpeed;
		MoveFlag = true;
	}
	//下移動
	if (HOLD_PAD(0, CInput::eDown))
	{
		m_pos.z += WalkSpeed;
		MoveFlag = true;
	}

	//ジャンプ
	if (PUSH_PAD(0, CInput::eButton3))
	{
		m_state = eState_Jump;
		const float JumpPower = 10.0f;
		m_vec.y = JumpPower;
		m_bound = false;
	}

	//攻撃状態に以降
	if (PUSH_PAD(0, CInput::eButton1))
	{
		m_state = eState_Attack1;
		m_state_attack = 0;
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
	if (HOLD_PAD(0, CInput::eLeft))
	{
		//移動量を設定
		m_pos.x -= WalkSpeed;
		//反転フラグ
		m_flip = true;
	}
	//右移動
	if (HOLD_PAD(0, CInput::eRight))
	{
		//移動量を設定
		m_pos.x += WalkSpeed;
		//反転フラグ
		m_flip = false;
	}
	//上移動
	if (HOLD_PAD(0, CInput::eUp))
	{
		//移動量を設定
		m_pos.z -= WalkSpeed;
	}
	//下移動
	if (HOLD_PAD(0, CInput::eDown))
	{
		//移動量を設定
		m_pos.z += WalkSpeed;
	}

	//ジャンプ攻撃
	if (PUSH_PAD(0, CInput::eButton1))
	{
		//m_state = eState_Attack1;
	}

	if (m_bound)
	{
		m_state = eState_Idle;
	}

	if (m_vec.y >= 0) {
		//上昇アニメーション
		m_img.ChangeAnimation(3, false);
	}
	else {
		//下降アニメーション
		m_img.ChangeAnimation(5,false);
	}
}

void Player::StateJumpAttack()
{
}

void Player::StateAttack1()
{
	switch (m_state_attack)
	{
	case 0:
		Fire = false;
		HoldTime = 0;
		m_secondAttackTime = 0;
		m_img.ChangeAnimation(6, false);
		if (m_img.CheckAnimationEnd())
		{
			m_state_attack++;
		}
		break;
	case 1:
		m_img.ChangeAnimation(7, true);
		HoldTime++;
		if (FREE_PAD(0,CInput::eButton1))
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
		m_img.ChangeAnimation(9, false);
		if (m_img.GetIndex() == 1 && Fire == false)
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
			m_state_attack = 4;
		}
		break;
	case 3:
		m_img.ChangeAnimation(8, false);

		if (m_img.GetIndex() == 1 && Fire == false)
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
			m_state_attack = 4;
		}
		break;
	case 4:
		m_secondAttackTime++;
		if (m_secondAttackTime < 120 && HOLD_PAD(0, CInput::eButton1))
		{
			m_state = eState_Attack2;
		}
		else
		{
			m_state = eState_Idle;
		}
		break;
	}
}

void Player::StateAttack2()
{
	switch (m_state_attack2)
	{
	case 0:
		Fire = false;
		HoldTime = 0;
		m_secondAttackTime = 0;
		m_img.ChangeAnimation(10, false);
		if (m_img.CheckAnimationEnd())
		{
			m_state_attack2++;
		}
		break;
	case 1:
		m_img.ChangeAnimation(11, false);
		if (m_img.GetIndex() == 2 && Fire == false)
		{
			if (m_flip)
			{
				new Bullet(eType_NomalBullet2, CVector3D(m_pos.x + 86, m_pos.y + 153, m_pos.z), false);
			}
			else
			{
				new Bullet(eType_NomalBullet2, CVector3D(m_pos.x - 86, m_pos.y + 153, m_pos.z), false);
			}
		}
		if (m_img.GetIndex() == 4 && Fire == false)
		{
			if (m_flip)
			{
				new Bullet(eType_NomalBullet2, CVector3D(m_pos.x + 94, m_pos.y + 176, m_pos.z), false);
			}
			else
			{
				new Bullet(eType_NomalBullet2, CVector3D(m_pos.x - 94, m_pos.y + 176, m_pos.z), false);
			}
		}
		if (m_img.GetIndex() == 6 && Fire == false)
		{
			if (m_flip)
			{
				new Bullet(eType_NomalBullet2, CVector3D(m_pos.x + 90, m_pos.y + 194, m_pos.z), false);
			}
			else
			{
				new Bullet(eType_NomalBullet2, CVector3D(m_pos.x - 90, m_pos.y + 194, m_pos.z), false);
			}
		}
		if (m_img.GetIndex() == 8 && Fire == false)
		{
			if (m_flip)
			{
				new Bullet(eType_NomalBullet2, CVector3D(m_pos.x + 71, m_pos.y + 232, m_pos.z), false);
			}
			else
			{
				new Bullet(eType_NomalBullet2, CVector3D(m_pos.x - 71, m_pos.y + 232, m_pos.z), false);
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
		if (m_secondAttackTime < 15 && HOLD_PAD(0, CInput::eButton1))
		{
			m_state = eState_Attack3;
		}
		else
		{
			m_state = eState_Idle;
		}
		break;
	}
}

void Player::StateAttack3()
{
	switch (m_state_attack3)
	{
	case 0:
		Fire = false;
		HoldTime = 0;
		m_secondAttackTime = 0;
		m_img.ChangeAnimation(12, false);
		if (m_img.CheckAnimationEnd())
		{
			m_state_attack3++;
		}
		break;
	case 1:
		m_img.ChangeAnimation(13, true);
		HoldTime++;
		if (FREE_PAD(0, CInput::eButton1))
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
		m_img.ChangeAnimation(14, false);
		if (m_img.GetIndex() == 1 && Fire == false)
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
		if (m_img.CheckAnimationEnd())
		{
			m_state = eState_Idle;
		}
		break;
	case 3:
		m_img.ChangeAnimation(14, false);

		if (m_img.GetIndex() == 1 && Fire == false)
		{
			if (m_flip)
			{
				new Bullet(eType_ChargeBullet2, CVector3D(m_pos.x - 80, m_pos.y + 171, m_pos.z), false);
			}

			if (!m_flip)
			{
				new Bullet(eType_ChargeBullet2, CVector3D(m_pos.x + 80, m_pos.y + 171, m_pos.z), true);
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
