#include "GameOver.h"
#include "Title.h"
#include"../Global.h"
#include "TaskManager.h"
#include "Ranking.h"
#include "RankingScore.h"
#include"UI.h"
GameOver::GameOver() : Base(eType_Scene, 10)
{
	SOUND("Game")->Stop();
	SOUND("Boss2")->Stop();
	SOUND("Boss")->Stop();
	SOUND("GameOver")->Play(true);
	m_img = COPY_RESOURCE("GameOver", CImage);
}

GameOver::~GameOver()
{
	TaskManager::GetInstance()->SetKillAll();
	g_score = 0;
	g_time = 0;
	m_scroll.x = 0;
	m_scroll.y = 0;
	new Title();
}

void GameOver::Update()
{
	if (PUSH(CInput::eButton3)) {
		SetKill();
	}
}


void GameOver::Draw()
{

	m_img.Draw();

}