#include "Clear.h"
#include "Title.h"
#include"../Global.h"
#include "TaskManager.h"
#include "Ranking.h"
Clear::Clear() : Base(eType_Scene, 10)
{
	m_img = COPY_RESOURCE("Clear", CImage);
	if (g_time / 60 < 60) {//１分以内なら
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
		auto ranking = Ranking::GetInstance()->GetScore();//ランキングを入れる
		int i = 0;//座標変更用
		for (auto& v : ranking)/*範囲for　autoで自動型変換*/
		{

			FONT_T()->Draw(SCREEN_WIDTH / 2,SCREEN_HEIGHT /2+i * 64, 0, 0, 0, "%d", v);//仮表示
				i++;
		}
		
}
