#include "../h/GV.h"

//　ゲームメニューの更新処理
void  updateGameMenu() {
	/*
	//Ｘキーが押されたらメニュー開く
	if (player.data.walking_flag == 0 && keyBuffer[KEY_INPUT_X] == 1 && gameState == noState) {//Xが押されているなら
		gameState = openGameMenu;
		PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏

	}
	//Ｃを押したら戻る
	if (gameState == openGameMenu && keyBuffer[KEY_INPUT_C] == 1) {
		gameState = noState;
		PlaySound("ブザー1.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
		initOpenGameMenu();//メニューセレクトポイントの座標初期化





		initAllMyCharaNowMS();
	}
	*/
	switch (player.gameMenu.state)
	{
	case noState:
		if (beforeXKey == 1 && keyBuffer[KEY_INPUT_X] == 0 && player.data.walking_flag == 0) {
			gameState = openGameMenu;//7
			player.gameMenu.state = SELECT;
			PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏	
		}

		break;



	case SELECT:
		if (keyBuffer[KEY_INPUT_DOWN] == 0 && beforeDownKey == 1) {
			PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
			if (player.select.openGameMenuPointY == 95) {
				player.select.openGameMenuPointY = 45;
			}
			else {
				player.select.openGameMenuPointY += 25;
			}
		}

		if (keyBuffer[KEY_INPUT_UP] == 0 && beforeUpKey == 1) {
			PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
			if (player.select.openGameMenuPointY == 45) {
				player.select.openGameMenuPointY = 95;
			}
			else {
				player.select.openGameMenuPointY -= 25;
			}

		}

		if ((keyBuffer[KEY_INPUT_RIGHT] == 0 && beforeRightKey == 1) ||
			(keyBuffer[KEY_INPUT_LEFT] == 0 && beforeLeftKey == 1)) {
			PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
			if (player.select.openGameMenuPointX == 13) {
				player.select.openGameMenuPointX = 133;
			}
			else {
				player.select.openGameMenuPointX = 13;
			}
		}

		//Ｃを押したら戻る
		if (beforeCKey == 1 && keyBuffer[KEY_INPUT_C] == 0) {
			gameState = noState;
			player.gameMenu.state = noState;
			PlaySound("キャンセル1.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
			initOpenGameMenu();//メニューセレクトポイントの座標初期化
		}
		break;
	}

}