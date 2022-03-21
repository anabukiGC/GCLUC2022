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
	auto ranking = Ranking::GetInstance()->GetScore();//�����L���O������
	int i = 0;//���W�ύX�p
	const CVector2D pos[3] = {//���W�z��
		CVector2D(500, 900),//�P��
		CVector2D((SCREEN_WIDTH / 2) , SCREEN_HEIGHT - 195),//�Q
		CVector2D((SCREEN_WIDTH / 2) , SCREEN_HEIGHT - 95),//�R
	};
	float scale[3] = {//�T�C�Y�z��
		1.0,
		0.5,
		0.5

	};
	new RankingScore(g_score, CVector2D((SCREEN_WIDTH / 2 - 200) - i * 150, 475),2);//�X�R�A�\��
	for (auto& v : ranking)/*�͈�for�@auto�Ŏ����^�ϊ�*/
	{
		new RankingScore(v,pos[i],scale[i]);
		i++;


	}

	
	m_img = COPY_RESOURCE("Clear", CImage);
	if (g_time / 60 < 120) {//2���ȓ��Ȃ�
		g_score += 2000;
	}
	if (g_time / 60 < 180) {//3���ȓ��Ȃ�
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
