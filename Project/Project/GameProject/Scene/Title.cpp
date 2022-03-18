#include "Title.h"
#include "Game.h"
#include "TaskManager.h"
#include"../Global.h"
#include"Clear.h"
Title::Title() : Base(eType_Scene, 11)
{
	m_img = COPY_RESOURCE("Title", CImage);
}

Title::~Title()
{
	//new Clear();
	new Game();
}

void Title::Update()
{
	if (PUSH(CInput::eButton3)) {
		SetKill();
	}
}

void Title::Draw()
{
	m_img.Draw();
	
}
