#include "Game.h"
#include "TaskManager.h"
#include "Player.h"
#include "PlayerAnimData.h"
#include "EnemyAnimData.h"
#include "EnemyManager.h"
#include"../Global.h"
#include "BackGround.h"
#include"Ranking.h"
#include"Clear.h"
#include"UI.h"
#include "GameOver.h"

Game::Game() :Base(eType_Scene,0)
{
	new Player(Player::eSword, CVector3D(100, 0, 1000), false);
	new EnemyManager();
	new BackGround();
	new UI(CVector2D(0,1000),1);//スコア
	new UI(CVector2D(0, 100), 2);//タイム
}

Game::~Game()
{
	TaskManager::GetInstance()->SetKillAll();
	new Clear();
	
	
}

void Game::Update()
{
	DIJOYSTATE2* ps = CInput::GetPadData(Player::eGun);
	if (!Player::GetPlayer(Player::eGun) && ps)
	{
		if (PUSH_PAD(Player::eGun, CInput::eButton1))
		{
			if (Player* p = Player::GetPlayer(Player::eSword))
			{
				new Player(Player::eGun, p->m_pos + CVector3D(-200, 0, 0), false);
			}
		}
	}

#if _DEBUG
	if (!Player::GetPlayer(Player::eSword) && PUSH_PAD(0, CInput::eButton7))
	{
		new Player(Player::eSword, CVector3D(0, 0, 0), false);
	}
	if (!Player::GetPlayer(Player::eGun) && PUSH_PAD(0, CInput::eButton8))
	{
		new Player(Player::eGun, CVector3D(0, 0, 0), false);
	}
#endif // _DEBUG


	if ((!Player::GetPlayer(Player::eSword) || Player::GetPlayer(Player::eSword)->GetHp() <= 0) &&
		(!Player::GetPlayer(Player::eGun) || Player::GetPlayer(Player::eGun)->GetHp() <= 0))
	{
		new GameOver(CVector2D(0, 0));
	}

	g_time++;
	if (m_clear == true) {//ゲームクリアなら
		SetKill();
	}
	
}

void Game::Draw()
{
}
