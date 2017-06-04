#include "../h/GV.h"

//　ゲームメニューの更新処理
void  updateMyCharaMenu() {
	//Zキーが押されたらメニュー開く
	if (player.collisonFlag && beforeZKey == 1 && keyBuffer[KEY_INPUT_Z] == 0) {
		int collisonObjectkind = searchObjectMyChara();
		if (collisonObjectkind != -1) {
			gameState = openMyCharaMenu;
			PlaySound("ブザー2.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
		}
	}

	//Ｃを押したら戻る
	if (gameState == openMyCharaMenu && keyBuffer[KEY_INPUT_C] == 1) {
		gameState = noState;
		initMyCharaMenu();//メニューセレクトポイントの座標初期化
	}


	if (gameState == openMyCharaMenu) {

		if (keyBuffer[KEY_INPUT_DOWN] == 0 && beforeDownKey == 1) {
			PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
			if (player.select.openMyCharaMenuPointY == 190) {
				player.select.openMyCharaMenuPointY = 50;
			}
			else {
				player.select.openMyCharaMenuPointY += 20;
			}
		}
		
		if (keyBuffer[KEY_INPUT_UP] == 0 && beforeUpKey == 1) {
			PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
			if (player.select.openMyCharaMenuPointY == 50) {
				player.select.openMyCharaMenuPointY = 190;
			}
			else {
				player.select.openMyCharaMenuPointY -= 20;
			}
		}
	}

}