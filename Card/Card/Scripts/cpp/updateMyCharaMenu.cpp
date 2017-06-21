#include "../h/GV.h"

//　ゲームメニューの更新処理
void  updateMyCharaMenu() {
	/*
	//Zキーが押されたらメニュー開く
	if (player.collisonFlag && beforeZKey == 1 && keyBuffer[KEY_INPUT_Z] == 0) {
		int collisonObjectkind = searchObjectMyChara();
		if (collisonObjectkind != -1) {
			gameState = openMyCharaMenu;
			player.mycharaFocus.state = SELECT;
			PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
		}
	}

*/


		switch (player.mycharaFocus.state)
		{
		case noState://-----------------------メニューを開くかどうか
		
			if (player.collisonFlag && beforeZKey == 1 && keyBuffer[KEY_INPUT_Z] == 0) {
				 player.collisonObjectkind = searchObjectMyChara();
				if (player.collisonObjectkind != -1) {
					gameState = openMyCharaMenu;
					player.mycharaFocus.state = SELECT;
					PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
				}
			}
		break;

		case SELECT://-----------------------項目選択状態------------------------------------------

			if (keyBuffer[KEY_INPUT_DOWN] == 0 && beforeDownKey == 1) {
				PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
				if (player.select.openMyCharaMenuPointY == 190) {
					player.select.openMyCharaMenuPointY = 50;
					player.mycharaFocus.selectIndex = 0;
				}
				else {
					player.select.openMyCharaMenuPointY += 20;
					player.mycharaFocus.selectIndex += 1;
				}
			}

			if (keyBuffer[KEY_INPUT_UP] == 0 && beforeUpKey == 1) {
				PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
				if (player.select.openMyCharaMenuPointY == 50) {
					player.select.openMyCharaMenuPointY = 190;
					player.mycharaFocus.selectIndex = 7;
				}
				else {
					player.select.openMyCharaMenuPointY -= 20;
					player.mycharaFocus.selectIndex -= 1;
				}
			}
			//Ｃを押したら戻る
			if (beforeCKey == 1 && keyBuffer[KEY_INPUT_C] == 0) {
				gameState = noState;
				player.mycharaFocus.state = noState;
				PlaySound("キャンセル1.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
				initMyCharaMenu();//メニューセレクトポイントの座標初期化
			}
			
			//Zを押したら
			if (beforeZKey == 1 && keyBuffer[KEY_INPUT_Z] == 0) {
				if (player.mycharaFocus.selectIndex == 0){
					PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
					player.mycharaFocus.state = MOVE;
					//初期座標を設定
					initGetMyCharaMoveData();

				}
				if (player.mycharaFocus.selectIndex == 1) {
					PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
					player.mycharaFocus.state = SKILL;
				}
				if (player.mycharaFocus.selectIndex == 2) {
					PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
					player.mycharaFocus.state = STATE;
				}
				if (player.mycharaFocus.selectIndex == 3) {
					PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
					player.mycharaFocus.state = MAPATK;
				}
				if (player.mycharaFocus.selectIndex == 4) {
					PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
					player.mycharaFocus.state = ITEM;
				}
				if (player.mycharaFocus.selectIndex == 5) {
					PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
					player.mycharaFocus.state = EQU;
				}
				if (player.mycharaFocus.selectIndex == 6) {
					//PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
					//player.mycharaFocus.state = SKILL;
				}
				if (player.mycharaFocus.selectIndex == 7) {
					PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
					player.mycharaFocus.state = WARMING;
				}
			}
			break;
		case MOVE://------------------------------「移動」を選択---------------------------------------------------------------------

			updateMyChara();//選択したキャラの移動処理
			
			//Ｃを押したら戻る
			if (beforeCKey == 1 && keyBuffer[KEY_INPUT_C] == 0) {
				if (myChara[player.collisonObjectkind].data.x % MAP_SIZE == 0 && myChara[player.collisonObjectkind].data.y % MAP_SIZE == 0) {
					//キャラ座標を初期座標に戻す（キャンセル処理）
					initSetMyCharaMoveData();
					player.mycharaFocus.state = SELECT;
					PlaySound("キャンセル1.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
					initMyCharaMenu();//メニューセレクトポイントの座標初期化
				}
				else {
					
				}
			}
			break;
		case SKILL:

			//Ｃを押したら戻る
			if (beforeCKey == 1 && keyBuffer[KEY_INPUT_C] == 0) {
				player.mycharaFocus.state = SELECT;
				PlaySound("キャンセル1.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
				//initMyCharaMenu();//メニューセレクトポイントの座標初期化
			}
			break;
		case STATE:
			
			//Ｃを押したら戻る
			if (beforeCKey == 1 && keyBuffer[KEY_INPUT_C] == 0) {
				player.mycharaFocus.state = SELECT;
				PlaySound("キャンセル1.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
				//initMyCharaMenu();//メニューセレクトポイントの座標初期化
			}
			break;
		case MAPATK:

			//Ｃを押したら戻る
			if (beforeCKey == 1 && keyBuffer[KEY_INPUT_C] == 0) {
				player.mycharaFocus.state = SELECT;
				PlaySound("キャンセル1.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
				//initMyCharaMenu();//メニューセレクトポイントの座標初期化
			}
			break;
		case ITEM:

			//Ｃを押したら戻る
			if (beforeCKey == 1 && keyBuffer[KEY_INPUT_C] == 0) {
				player.mycharaFocus.state = SELECT;
				PlaySound("キャンセル1.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
				//initMyCharaMenu();//メニューセレクトポイントの座標初期化
			}
			break;
		case EQU:

			//Ｃを押したら戻る
			if (beforeCKey == 1 && keyBuffer[KEY_INPUT_C] == 0) {
				player.mycharaFocus.state = SELECT;
				PlaySound("キャンセル1.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
				//initMyCharaMenu();//メニューセレクトポイントの座標初期化
			}
			break;
		case WARMING:

			//Ｃを押したら戻る
			if (beforeCKey == 1 && keyBuffer[KEY_INPUT_C] == 0) {
				player.mycharaFocus.state = SELECT;
				PlaySound("キャンセル1.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
				//initMyCharaMenu();//メニューセレクトポイントの座標初期化
			}
			break;
			/*
		default:
			player.mycharaFocus.mycharaFocusflag = SELECT;
			*/
		}
	}

