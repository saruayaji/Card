#include "../h/GV.h"



// ---------------------------------------- 更新処理 ------------------------------------------------------------------------------------------------------
void update() {

	switch (mainState) {
	case TITLE:
		updateTitle();
		break;


	case GAME:
		// ゲームの更新処理を行う
		updatePlayer();	//プレイヤー更新処理
		updateGameMenu();//メニュー更新処理
		updateMyCharaMenu();//キャラメニュー更新処理

		break;

	case GAMEOVER:
		// spaceキーを押してから離すと反応
		if (beforeSpaceKey == 1 && keyBuffer[KEY_INPUT_SPACE] == 0) {
			init();
		}
		break;

	case GAMECLEAR:
		// spaceキーを押してから離すと反応
		if (beforeSpaceKey == 1 && keyBuffer[KEY_INPUT_SPACE] == 0) {
			init();
		}
		break;
	}

}
