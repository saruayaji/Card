#include "../h/GV.h"
//タイトル画面の更新処理
void updateTitle() {

	if (titleState == titleSelect) {
		// spaceキーを押してから離すと反応
		if (beforeSpaceKey == 1 && keyBuffer[KEY_INPUT_SPACE] == 0) {//スペースを押したら
			if(player.select.titleMenuPointY == 300 || player.select.titleMenuPointY == 325)
					mainState = GAME;
			else 	DxLib_End();//終わるを押したら DXライブラリ使用の終了処理
			
		}



		if (keyBuffer[KEY_INPUT_DOWN] == 0 && beforeDownKey == 1) {//上を押したら
			PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
			if (player.select.titleMenuPointY == 300) player.select.titleMenuPointY = 325;
			else if (player.select.titleMenuPointY == 325)player.select.titleMenuPointY = 350;
			else player.select.titleMenuPointY = 300;
		}

		if (keyBuffer[KEY_INPUT_UP] == 0 && beforeUpKey == 1) {
			PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
			if (player.select.titleMenuPointY == 300) player.select.titleMenuPointY = 350;
			else if (player.select.titleMenuPointY == 325)player.select.titleMenuPointY = 300;
			else player.select.titleMenuPointY = 325;
		}

	}
}