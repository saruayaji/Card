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
		//①移動する
		if (player.data.walking_flag == 1 && player.data.attack_flag == 0) {//歩行フラグがONかつ攻撃フラグがＯＦＦなら
			walkingUpdatePlayer(player.data.muki);//移動変化関数（向きに応じて座標を変化させる関数）
		}

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
