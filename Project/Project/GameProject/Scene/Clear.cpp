#include "Clear.h"
#include "Title.h"
#include"../Global.h"
#include "TaskManager.h"
#include "Ranking.h"
#include "RankingScore.h"
#include"UI.h"
Clear::Clear() : Base(eType_Scene, 10)
{
	SOUND("Boss2")->Stop();
	SOUND("Clear")->Play(true);
	auto ranking = Ranking::GetInstance()->GetScore();//ランキングを入れる
	int i = 0;//座標変更用
	const CVector2D pos[3] = {//座標配列
		CVector2D(500, 900),//１位
		CVector2D((SCREEN_WIDTH / 2) , SCREEN_HEIGHT - 195),//２
		CVector2D((SCREEN_WIDTH / 2) , SCREEN_HEIGHT - 95),//３
	};
	float scale[3] = {//サイズ配列
		1.0,
		0.5,
		0.5

	};
	new RankingScore(g_score, CVector2D((SCREEN_WIDTH / 2 - 200) - i * 150, 475),2);//スコア表示
	for (auto& v : ranking)/*範囲for　autoで自動型変換*/
	{
		new RankingScore(v,pos[i],scale[i]);
		i++;


	}

	
	m_img = COPY_RESOURCE("Clear", CImage);
	if (g_time / 60 < 120) {//2分以内なら
		g_score += 2000;
	}
	if (g_time / 60 < 180) {//3分以内なら
		g_score += 1000;
	}


	Ranking::GetInstance()->Add(g_score);
	Ranking::GetInstance()->WriteScore();
	
}

Clear::~Clear()
{
	TaskManager::GetInstance()->SetKillAll();
	g_score = 0;
	g_time = 0;
	m_scroll.x = 0;
	m_scroll.y = 0;
	new Title();
}

void Clear::Update()
{
	if (PUSH(CInput::eButton3)) {
		SetKill();
	}
}
	

void Clear::Draw()
{

		m_img.Draw();
		
}
