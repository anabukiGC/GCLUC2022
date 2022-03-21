#include "GameOver.h"
#include "Title.h"
#include"../Global.h"
#include "TaskManager.h"
#include "Ranking.h"
#include "RankingScore.h"
#include"UI.h"
GameOver::GameOver(const CVector2D& pos) : Base(eType_Scene, 10000)
{
	m_img = COPY_RESOURCE("GameOver", CImage);
	m_pos = pos;
	m_img.SetSize(1920, 1080);
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
	if (PUSH(CInput::eButton3)) 
	{
		SetKill();
	}
}


void GameOver::Draw()
{

	m_img.Draw();

}