#include "Title.h"
#include "Game.h"
#include "TaskManager.h"
#include"../Global.h"
#include"Clear.h"
#include"Select.h"
Title::Title() : Base(eType_Scene, 11)
{
	m_img = COPY_RESOURCE("Title", CImage);
	new Select(CVector2D(SCREEN_WIDTH / 2 +150, SCREEN_HEIGHT / 2-450),1);
	new Select(CVector2D(SCREEN_WIDTH/2-250, SCREEN_HEIGHT/2-450), 3);//Start
	new Select(CVector2D(SCREEN_WIDTH / 2-250, SCREEN_HEIGHT / 2-600), 2);//HowTO
}

Title::~Title()
{
	TaskManager::GetInstance()->SetKillAll();
	if(m_start == true){
	new Game();
	}
	if (m_start == false) {
		new Game();
	}
}

void Title::Update()
{
	Select* s = dynamic_cast<Select*>(TaskManager::GetInstance()->GetTask(eType_Select));
	
	if (s->m_stop==false && PUSH(CInput::eButton3)) {//あそびかた
		m_start = false;
		SetKill();
	}
	if (s->m_stop == true && PUSH(CInput::eButton3)) {//スタート
		m_start = true;
		SetKill();
	}

}

void Title::Draw()
{
	m_img.Draw();
	
}
