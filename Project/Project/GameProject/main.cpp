#include <GLLibrary.h>
#include "TaskManager.h"
#include "PlayerAnimData.h"
#include "EnemyAnimData.h"
#include "Global.h"
#include "BackGround.h"
#include"Ranking.h"

#include"Title.h"
void MainLoop(void) {
	TaskManager::GetInstance()->KillCheckAll();
	TaskManager::GetInstance()->UpdateAll();
	TaskManager::GetInstance()->CollisionAll();
	TaskManager::GetInstance()->UpdatePriority();
	TaskManager::GetInstance()->DrawAll();


	/*if (PUSH(CInput::eButton3)) {
		Ranking::GetInstance()->Add(100);
		Ranking::GetInstance()->WriteScore();
		Ranking::GetInstance()->ReadScore();
	}*/
}
void Init(void)
{
	

	glClearColor(0.0, 0.0, 0.0, 0.0);
	//glClearColor(0.0, 1.0, 0.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);//ブレンドの有効化
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//固定シェーダー用
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_ALPHA_TEST);

	CFPS::SetFPS(60);
	//フレーム制御初期化
	CFPS::Init();
	//ボタンの設定
	CInput::Init();
	CInput::SetButton(0, CInput::eButton1, VK_LBUTTON);
	CInput::SetButton(0, CInput::eButton2, VK_RBUTTON);
	CInput::SetButton(0, CInput::eButton3, VK_SPACE);
	CInput::SetButton(0, CInput::eButton4, VK_LSHIFT);
	CInput::SetButton(0, CInput::eUp, 'W');
	CInput::SetButton(0, CInput::eDown, 'S');
	CInput::SetButton(0, CInput::eLeft, 'A');
	CInput::SetButton(0, CInput::eRight, 'D');

	CInput::SetButton(0, CInput::eButton7, 'Z');
	CInput::SetButton(0, CInput::eButton8, 'X');

	CInput::SetButton(1, CInput::eButton1, VK_LBUTTON);
	CInput::SetButton(1, CInput::eButton2, VK_RBUTTON);
	CInput::SetButton(1, CInput::eButton3, VK_SPACE);
	CInput::SetButton(1, CInput::eButton4, VK_LSHIFT);
	CInput::SetButton(1, CInput::eUp, 'W');
	CInput::SetButton(1, CInput::eDown, 'S');
	CInput::SetButton(1, CInput::eLeft, 'A');
	CInput::SetButton(1, CInput::eRight, 'D');

//マウスをウインドウ内に制限
//	CInput::SetMouseInside(true);
//マウス非表示
//	CInput::ShowCursor(false);

	CInput::Update();
	CInput::Update();


	//ライト設定
	CLight::SetType(0, CLight::eLight_Direction);
	CLight::SetPos(0, CVector3D(0, 200, 200));
	CLight::SetDir(0, CVector3D(-1, -2, -1).GetNormalize());
	CLight::SetColor(0, CVector3D(0.2f, 0.2f, 0.2f), CVector3D(0.8f, 0.8f, 0.8f));


	CLight::SetFogParam(CVector4D(1, 1, 1, 1), 100000, 100000);
	//カメラ初期化

	CCamera::GetCamera()->LookAt(CVector3D(10, 10, 10),
		CVector3D(0, 0, 0),
		CVector3D(0.0, 1.0, 0.0));

	SetCurrentDirectory("data");


	CShader::GetInstance("StaticMesh");
	CShader::GetInstance("SkinMesh");
	CSound::GetInstance();
	//初期化
	ADD_RESOURCE("SwordPlayer", CImage::CreateImage("Image/Player/Player1.png", player_anim_data, 256, 256));
	ADD_RESOURCE("GunPlayer", CImage::CreateImage("Image/Player/Player2.png", player_anim_data, 256, 256));
	ADD_RESOURCE("Enemy1", CImage::CreateImage("Image/Enemy/Enemy1.png", enemy1_anim_data, 256, 256));
	ADD_RESOURCE("Enemy2", CImage::CreateImage("Image/Enemy/Enemy2.png", enemy2_anim_data, 256, 256));
	ADD_RESOURCE("EnemyBullet", CImage::CreateImage("Image/Enemy/EnemyBullet.png"));
	ADD_RESOURCE("Bonus", CImage::CreateImage("Image/Enemy/Bonus.png", enemy3_anim_data, 256, 256));
	ADD_RESOURCE("Boss1", CImage::CreateImage("Image/Boss/Boss.png", boss1_anim_data, 512, 512));
	ADD_RESOURCE("Boss2", CImage::CreateImage("Image/Boss/Boss2.png", boss2_anim_data, 512, 512));
	ADD_RESOURCE("BossHP", CImage::CreateImage("Image/UI/BossBar.png"));
    ADD_RESOURCE("EnemyHP", CImage::CreateImage("Image/UI/EnemyBar.png"));
	ADD_RESOURCE("Player1HP", CImage::CreateImage("Image/Player/Player1HP.png"));
	ADD_RESOURCE("Player2HP", CImage::CreateImage("Image/Player/Player2HP.png"));
    ADD_RESOURCE("BackGround1", CImage::CreateImage("Image/Map/BackGround1.png"));
	ADD_RESOURCE("BackGround2", CImage::CreateImage("Image/Map/BackGround2.png"));
	ADD_RESOURCE("BackGround3", CImage::CreateImage("Image/Map/BackGround3.png"));
	ADD_RESOURCE("BackGround4", CImage::CreateImage("Image/Map/BackGround4.png"));
	ADD_RESOURCE("Stage1", CImage::CreateImage("Image/Map/Stage1.png"));
	ADD_RESOURCE("NomalBullet1", CImage::CreateImage("Image/Player/Player2Bullet1.png"));
	ADD_RESOURCE("ChargeBullet1", CImage::CreateImage("Image/Player/Player2ChargeBullet1.png"));
	ADD_RESOURCE("NomalBullet2", CImage::CreateImage("Image/Player/Player2Bullet2.png"));
	ADD_RESOURCE("ChargeBullet2", CImage::CreateImage("Image/Player/Player2ChargeBullet2.png"));
	ADD_RESOURCE("Shadow", CImage::CreateImage("Image/UI/Shadow.png"));
	ADD_RESOURCE("Title", CImage::CreateImage("Image/Scene/Title.png"));
	ADD_RESOURCE("Clear", CImage::CreateImage("Image/Scene/Clear.png"));
	ADD_RESOURCE("GameOver", CImage::CreateImage("Image/Scene/GameOver.png"));
	ADD_RESOURCE("ScoreTime", CImage::CreateImage("Image/UI/UI.png"));
	ADD_RESOURCE("TitleRogo", CImage::CreateImage("Image/UI/TitleRogo.png"));
	ADD_RESOURCE("Meteor", CImage::CreateImage("Image/Boss/Meteor.png", boss2_meteor_data, 128, 128));
	ADD_RESOURCE("PlayerEffect", CImage::CreateImage("Image/Player/PlayerEffect.png"));
	ADD_RESOURCE("Debuff", CImage::CreateImage("Image/UI/Debuff.png"));
	ADD_RESOURCE("ClearScore", CImage::CreateImage("Image/UI/ClearScore.png"));
	ADD_RESOURCE("1st", CImage::CreateImage("Image/UI/1st.png"));
	ADD_RESOURCE("Start", CImage::CreateImage("Image/UI/Start.png"));
	ADD_RESOURCE("Select", CImage::CreateImage("Image/UI/Select.png"));
	ADD_RESOURCE("HowTo", CImage::CreateImage("Image/UI/HowTo.png"));
	ADD_RESOURCE("BossBoad", CImage::CreateImage("Image/UI/BossBoad.png"));
	ADD_RESOURCE("EnemyBoad", CImage::CreateImage("Image/UI/EnemyBoad.png"));
	ADD_RESOURCE("BossLaser", CImage::CreateImage("Image/Boss/BossLaser.png",boss_laser_data,1000,300));
	ADD_RESOURCE("HowTo2", CImage::CreateImage("Image/Scene/HowTo2.png"));

	SOUND("Title")->Load("BGM/BGM_Title.wav");
	SOUND("Game")->Load("BGM/BGM_Game.wav");
	SOUND("Clear")->Load("BGM/BGM_Clear.wav");
	SOUND("GameOver")->Load("BGM/BGM_GameOver.wav");
	SOUND("Boss")->Load("BGM/BGM_Boss.wav");
	SOUND("Boss2")->Load("BGM/BGM_Boss2.wav");
	SOUND("SE_Bonus")->Load("SE/SE_Bonus.wav");
	SOUND("SE_BossAttack")->Load("SE/SE_BossAttack.wav");
	SOUND("SE_BossLaser")->Load("SE/SE_BossLaser.wav");
	SOUND("SE_Charge")->Load("SE/SE_Charge.wav");
	SOUND("SE_Debuff")->Load("SE/SE_Debuff.wav");
	SOUND("SE_Enemy1")->Load("SE/SE_Enemy1.wav");
	SOUND("SE_Enemy2")->Load("SE/SE_Enemy2.wav");
	SOUND("SE_Enemy2Bullet")->Load("SE/SE_Enemy2Bullet.wav");
	SOUND("SE_Jump")->Load("SE/SE_Jump.wav");
	SOUND("SE_Meteo")->Load("SE/SE_Meteo.wav");
	SOUND("SE_Miss")->Load("SE/SE_Miss.wav");
	SOUND("SE_Player1")->Load("SE/SE_Player1.wav");
	SOUND("SE_Player2")->Load("SE/SE_Player2.wav");
	SOUND("SE_Select")->Load("SE/SE_Select.wav");
	new Title();
	Ranking::GetInstance()->ReadScore();
}


void Release()
{
	CLoadThread::ClearInstance();
	CSound::ClearInstance();
	CResourceManager::ClearInstance();
}

static void ResizeCallback(GLFWwindow* window, int w, int h)
{
	CCamera::GetCamera()->Viewport(0, 0, (float)w, (float)h);
	//CCamera::GetCamera()->SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	CCamera::GetCamera()->SetSize((float)w, (float)h);


	CCamera::GetCurrent()->Perspective(Utility::DgreeToRadian(45.0), (float)w / (float)h, 1.0, 10000.0);

	GL::UpdateWindosRect(GL::window_x, GL::window_y, w, h);


}
static void WheelCallback(GLFWwindow* _window, double _offsetx, double _offsety) {
	CInput::AddMouseWheel((int)_offsety);

}
static void PosCallback(GLFWwindow* _window, int x, int y) {
	GL::UpdateWindosRect(x, y, GL::window_width, GL::window_height);
	CInput::UpdateClipCursor(true);

}
static void FocusCallback(GLFWwindow* _window, int f) {
	CInput::UpdateClipCursor(f);
	GL::focus = f;
}

static void error_callback(int error, const char* description)
{
	printf("Error: %s\n", description);
}

//フルスクリーン?ウインドウモードの切り替え
//Alt+Enterで切り替える
void CheckFullScreen() {
	static int key_enter = 0;
	int key_enter_buf = key_enter;
	if (key_enter_buf ^ (key_enter = glfwGetKey(GL::window, GLFW_KEY_ENTER)) && key_enter && (glfwGetKey(GL::window, GLFW_KEY_LEFT_ALT) || glfwGetKey(GL::window, GLFW_KEY_RIGHT_ALT))) {
		GL::ChangeFullScreen(!GL::full_screen);
	}
}

int __main(int* argcp, char** argv) {
	// メモリリーク検出
	//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//OpenGL4.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) return -1;
	//	glutInit(argcp, argv);


	GL::window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simple", nullptr, nullptr);
	glfwGetWindowSize(GL::window, &GL::window_width, &GL::window_height);
	glfwGetWindowPos(GL::window, &GL::window_x, &GL::window_y);

	glfwSetFramebufferSizeCallback(GL::window, ResizeCallback);
	glfwSetScrollCallback(GL::window, WheelCallback);
	glfwSetWindowFocusCallback(GL::window, FocusCallback);
	glfwSetWindowPosCallback(GL::window, PosCallback);
	if (!GL::window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(GL::window);
	glfwSwapInterval(0);//１ならつないだデバイスのFPSに合わせる０なら通常
	ResizeCallback(GL::window, SCREEN_WIDTH, SCREEN_HEIGHT);

	GLenum err = glewInit();
	if (err == GLEW_OK) {
		printf("%s\n", glewGetString(GLEW_VERSION));
	}
	else {
		printf("%s\n", glewGetErrorString(err));
		getchar();
		return -1;
	}
	HDC glDc = wglGetCurrentDC();
	GL::hWnd = WindowFromDC(glDc);

	//コマンドライン引数に-fullscreenでフルスクリーン起動
	//-monitor 番号　で別のモニターでフルスクリーン
	bool fullscreen = GL::full_screen;
	int monitor_no = 0;
	if (*argcp >= 2) {
		for (int i = 1; i < *argcp; i++) {
			char* op = argv[i];
			if (strcmp(op, "-fullscreen") == 0) {
				fullscreen = true;
			}else
			if (strcmp(op, "-window") == 0) {
				fullscreen = false;
			}else
			if(strcmp(op, "-monitor") == 0) {
				if (i < *argcp - 1) {
					monitor_no = atoi(argv[++i]);
				}
			}
		}
	}
	GL::ChangeFullScreen(fullscreen, monitor_no);

	Init();

	while (!glfwWindowShouldClose(GL::window)) {
		CheckFullScreen();

		CInput::Update();
		//各バッファーをクリア
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		MainLoop();


		glfwSwapBuffers(GL::window);


		CFPS::Wait();

		char title[32];
		sprintf_s(title, "sample fps:%d dt:%.3f", CFPS::GetFPS(), CFPS::GetDeltaTime());
		glfwSetWindowTitle(GL::window, title);

		glfwPollEvents();
		if (glfwGetKey(GL::window, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(GL::window, GL_TRUE);
		}

	}

	glfwTerminate();


	Release();
	return 0;
}

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR argv, INT argc)
{
	return __main(&__argc, __argv);
}

int main(int argc, char** argv)
{
	return __main(&argc, argv);
}
