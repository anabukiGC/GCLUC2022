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
		//画像サイズ設定
		m_img.SetSize(256 * m_scale, 256 * m_scale);
	}
	else
	{
		m_img = COPY_RESOURCE("GunPlayer", CImage);
		m_scale = 1.0;
		//画像サイズ設定
		m_img.SetSize(256 * m_scale, 256 * m_scale);
	}

	m_img.ChangeAnimation(eAnimIdle);
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

	//プレイヤーの種類
	m_kind = kind;

	m_players[kind] = this;
}

void Player::Update()
{
	m_key_dir = CInput::GetLStick(m_kind);
	//左移動
	if (HOLD_PAD(m_kind, CInput::eLeft))
	{
		m_key_dir.x = -1;
	}
	//右移動
	else if (HOLD_PAD(m_kind, CInput::eRight))
	{
		m_key_dir.x = 1;
	}
	//上移動
	if (HOLD_PAD(m_kind, CInput::eUp))
	{
		m_key_dir.y = -1;
	}
	//下移動
	else if (HOLD_PAD(m_kind, CInput::eDown))
	{
		m_key_dir.y = 1;
	}

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
	//画像の中心位置設定
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
	//移動量
	const float WalkSpeed = 6.0f;

	m_pos.x += m_key_dir.x* WalkSpeed;
	m_pos.z += m_key_dir.y * WalkSpeed;
	const float free_space = 0.0001f;


	//移動フラグ
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

	//ジャンプ
	if (PUSH_PAD(m_kind, CInput::eButton3))
	{
		m_state = eState_Jump;
		const float JumpPower = 10.0f;
		m_vec.y = JumpPower;
		m_bound = false;
	}

	//攻撃状態に以降
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

	//移動中なら
	if (MoveFlag) {
		//歩くアニメーション
		m_img.ChangeAnimation(eAnimGunWalk);
	}
	else {
		//待機アニメーション
		m_img.ChangeAnimation(eAnimIdle);
	}
}

void Player::StateJump()
{
	//移動量
	const float WalkSpeed = 6.0f;

	m_pos.x += m_key_dir.x * WalkSpeed;
	m_pos.z += m_key_dir.y * WalkSpeed;
	const float free_space = 0.0001f;


	//移動フラグ
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

	//ジャンプ攻撃
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
		//上昇アニメーション
		m_img.ChangeAnimation(eAnimJumpUp, false);
	}
	else {
		//下降アニメーション
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
	//その場で停止
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
