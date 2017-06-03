#define _GLOBAL_INSTANCE_ 
#include "../h/GV.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//■----------■-----------■-----------main関数--------------■------------■----------■----------------------------------------------------------------------------//////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//ウィンドウのタイトル指定
	SetMainWindowText("TDU不思議のダンジョン");

	//ＤＸライブラリ初期化
	if (DxLib_Init() == -1) {
		return -1;
	}

	// 画面モードの変更
	SetGraphMode(WINDOW_W, WINDOW_H, 32);

	//描画先を裏画面に設定]
	SetDrawScreen(DX_SCREEN_BACK);

	//ゲームの初期化
	init();

	//１秒に６０回画面を更新
	int nextTime = GetNowCount() + 1000 / 60;

	//ESCキーを押すまでループする
	while (ProcessMessage() == 0 && keyBuffer[KEY_INPUT_ESCAPE] == 0) {

		input();	// 入力処理

		update();	// 更新処理

		draw();		// 描画処理

					// 時間が余った場合、sleepする
		if (nextTime > GetNowCount()) {
			Sleep(nextTime - GetNowCount());
		}
		nextTime = GetNowCount() + 1000 / 60;
	}

	// DXライブラリ使用の終了処理
	DxLib_End();


	// ソフトの終了
	return 0;
}




