#include "../h/GV.h"


void drawConsole() {
	/*
	//矢印の表示
	if (keyBuffer[KEY_INPUT_C] == 1) {
		if (player.data.muki == 0)arrow.x = startXpos, arrow.y = startYpos + MAP_SIZE;
		else if (player.data.muki == 1)arrow.x = startXpos - MAP_SIZE, arrow.y = startYpos;
		else if (player.data.muki == 2)arrow.x = startXpos + MAP_SIZE, arrow.y = startYpos;
		else if (player.data.muki == 3)arrow.x = startXpos, arrow.y = startYpos - MAP_SIZE;
		else if (player.data.muki == 4)arrow.x = startXpos + MAP_SIZE, arrow.y = startYpos - MAP_SIZE;
		else if (player.data.muki == 5)arrow.x = startXpos + MAP_SIZE, arrow.y = startYpos + MAP_SIZE;
		else if (player.data.muki == 6)arrow.x = startXpos - MAP_SIZE, arrow.y = startYpos - MAP_SIZE;
		else if (player.data.muki == 7)arrow.x = startXpos - MAP_SIZE, arrow.y = startYpos + MAP_SIZE;

		DrawGraph(arrow.x, arrow.y, arrowGraph[player.data.muki], TRUE);//矢印の描画
	}

	*/

	//コンソール
	DrawFormatString(200, 0, Cr[1] = GetColor(255, 0, 0), "%d         gamestate %d", myCharaSearchObjectMyChara(), gameState);


/*
	DrawFormatString(200, 350, Cr[1] = GetColor(255, 0, 0), "向き %d 移動%d攻撃%d時間%dAct%d 自タ%d タ%d AX%d AY%d", player.data.muki, player.data.walking_flag, player.data.attack_flag, normalAttack.time, player.state.actState, player.data.turn, turn_Now, player.data.actionPosX, player.data.actionPosY);
	DrawFormatString(250, 375, Cr[1] = GetColor(255, 0, 0), "敵向き%d　移動%d攻撃%d  ", enemy[0].data.muki, enemy[0].data.walking_flag, enemy[0].data.attack_flag);

	DrawFormatString(210, 425, Cr[1] = GetColor(255, 0, 0), "敵座標の絶対値Ｘ%d　Ｙ%d next%d %d %d ", enemy[0].data.x, enemy[0].data.y, enemy[0].data.nextPosX, enemy[0].data.nextPosY, enemy[0].data.nextWalking_flag);
	//DrawFormatString(250, 325, Cr[1] = GetColor(255, 0, 0), "nectPosX%d Y%dマス ", player.data.nextPosX, player.data.nextPosY);
	*/
//	DrawFormatString(250, 450, Cr[1] = GetColor(255, 0, 0), "自座標X%d Y%d/%d,%dマス ", player.data.x, player.data.y, player.data.x / MAP_SIZE, player.data.y / MAP_SIZE);
	//printfDx("テスト\n改行");
}

