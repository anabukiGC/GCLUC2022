#include "Game.h"
#include "../TaskSystem/TaskManager.h"
#include "Player.h"
#include "PlayerAnimData.h"
#include "EnemyAnimData.h"
#include "EnemyManager.h"
#include"../Global.h"
#include "BackGround.h"
#include"Ranking.h"
#include"../Scene/Clear.h"
#include"UI.h"
Game::Game() :Base(eType_Scene,0)
{
	new Player(CVector3D(100, 0, 1000), false);
	new EnemyManager();
	new BackGround();
	new UI(CVector2D(0,1000),1);//スコア
	new UI(CVector2D(0, 1000), 2);//タイム
}

Game::~Game()
{
	TaskManager::GetInstance()->SetKillAll();
	new Clear();
	new UI(CVector2D(0, 400), 3);
	
}

void Game::Update()
{
	g_time++;
	if (m_clear == true) {//ゲームクリアなら
		SetKill();
	}
	
}

void Game::Draw()
{
}
