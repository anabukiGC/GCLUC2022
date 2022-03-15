#include "Game.h"
#include "../TaskSystem/TaskManager.h"
#include "Player.h"
#include "PlayerAnimData.h"
#include "Enemy.h"
#include "EnemyAnimData.h"
#include "EnemyManager.h"
#include "Boss.h"
#include "../Global.h"
#include "BackGround.h"
#include"Ranking.h"
Game::Game() :Base(eType_Scene,0)
{
	new Player(CVector3D(100, 0, 1000), false);
	new EnemyManager();
	new BackGround();
}

Game::~Game()
{
}

void Game::Update()
{
}

void Game::Draw()
{
}
