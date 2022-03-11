#include <GLLibrary.h>
#include "TaskSystem/TaskManager.h"
#include "Game/Player.h"
#include "Game/PlayerAnimData.h"
#include "Game/Enemy.h"
#include "Game/EnemyAnimData.h"
#include "../GameProject/Game/EnemyManager.h"
#include "Game/Boss.h"
#include "Global.h"
#include "Game/BackGround.h"



void MainLoop(void) {
	TaskManager::GetInstance()->KillCheckAll();
	TaskManager::GetInstance()->UpdateAll();
	TaskManager::GetInstance()->CollisionAll();
	TaskManager::GetInstance()->DrawAll();
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
	ADD_RESOURCE("Player", CImage::CreateImage("Image/Player/Player2.png", player_anim_data, 256, 256));
	ADD_RESOURCE("Enemy1", CImage::CreateImage("Image/Enemy/Enemy1.png", enemy1_anim_data, 256, 256));
	ADD_RESOURCE("Enemy2", CImage::CreateImage("Image/Enemy/Enemy2.png", enemy2_anim_data, 256, 256));
	ADD_RESOURCE("Boss1", CImage::CreateImage("Image/Boss/Boss.png", boss1_anim_data, 512, 512));
	ADD_RESOURCE("HP", CImage::CreateImage("Image/UI/Block.png"));
    ADD_RESOURCE("HP2", CImage::CreateImage("Image/UI/Block2.png"));
    ADD_RESOURCE("BackGround1", CImage::CreateImage("Image/Map/BackGround1.png"));
	ADD_RESOURCE("BackGround2", CImage::CreateImage("Image/Map/BackGround2.png"));
	ADD_RESOURCE("BackGround3", CImage::CreateImage("Image/Map/BackGround3.png"));
	ADD_RESOURCE("BackGround4", CImage::CreateImage("Image/Map/BackGround4.png"));
	ADD_RESOURCE("NomalBullet", CImage::CreateImage("Image/Player/Player2Bullet1.png"));
	new Player(CVector3D(100, 0, 1000),false);
	new Enemy(CVector3D(1600, 0, 500),1);
	new Boss(CVector3D(1100, 0, -300), 1);
	new EnemyManager();
	new BackGround();
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
	glfwSwapInterval(1);
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
