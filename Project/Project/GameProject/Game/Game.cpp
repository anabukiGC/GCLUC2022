#include "Game.h"
#include "../TaskSystem/TaskManager.h"
#include "Player.h"
#include "PlayerAnimData.h"
#include "EnemyAnimData.h"
#include "EnemyManager.h"

#include "BackGround.h"
#include"Ranking.h"
#include"../Scene/Clear.h"
#include"UI.h"
Game::Game() :Base(eType_Scene,0)
{
	new Player(CVector3D(100, 0, 1000), false);
	new EnemyManager();
	new BackGround();
	
}

Game::~Game()
{

	new Clear();
}

void Game::Update()
{

	if (m_clear == true) {
		SetKill();
	}
	
}

void Game::Draw()
{
}
