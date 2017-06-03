#include "GV.h"

//■敵が進めるかどうか判定をする。
int EnemyIsAbleToGo(int x, int y, int muki, int This) {//進めるかを判定する

	if (stage00.Switch == ON) {			//今ステージ００にいたら
		switch (muki) {
		case 0:
			for (int i = 0; i < ENEMY_NUM; i++) {//行き先に他のモンスターがいたら進まない
				if ((x == enemy[i].data.nextPosX) && (y + MAP_SIZE == enemy[i].data.nextPosY) && (enemy[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (stage00.tipData[y / MAP_SIZE + 1][x / MAP_SIZE] == 1 || stage00.tipData[y / MAP_SIZE + 1][x / MAP_SIZE] == 39) {
				if (x == player.data.nextPosX && y + MAP_SIZE == player.data.nextPosY)return 0;//プレイヤーの行こうとしているマスに移動はできない
				if (enemy[This].data.nextWalking_flag == 1) {//エネミーのnextPosを一度だけ更新
					enemy[This].data.nextPosY += MAP_SIZE;
					enemy[This].data.nextWalking_flag = 0;
				}
				return 1;//向いた先が１または３９で進めるなら１を返す
			}
			break;
		case 1:
			for (int i = 0; i < ENEMY_NUM; i++) {//行き先に他のモンスターがいたら進まない
				if ((x - MAP_SIZE == enemy[i].data.nextPosX) && (y == enemy[i].data.nextPosY) && (enemy[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (x / MAP_SIZE - 1 < 0)return 0;
			if (stage00.tipData[y / MAP_SIZE][x / MAP_SIZE - 1] == 1 || stage00.tipData[y / MAP_SIZE][x / MAP_SIZE - 1] == 39) {
				if (x - MAP_SIZE == player.data.nextPosX && y == player.data.nextPosY)return 0;//プレイヤーの行こうとしているマスに移動はできない
				if (enemy[This].data.nextWalking_flag == 1) {//エネミーのnextPosを一度だけ更新
					enemy[This].data.nextPosX -= MAP_SIZE;
					enemy[This].data.nextWalking_flag = 0;
				}
				return 1;//向いた先が１または３９で進めるなら１を返す
			}
			break;
		case 2:
			for (int i = 0; i < ENEMY_NUM; i++) {//行き先に他のモンスターがいたら進まない
				if ((x + MAP_SIZE == enemy[i].data.nextPosX) && (y == enemy[i].data.nextPosY) && (enemy[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (stage00.tipData[y / MAP_SIZE][x / MAP_SIZE + 1] == 1 || stage00.tipData[y / MAP_SIZE][x / MAP_SIZE + 1] == 39) {
				if (x + MAP_SIZE == player.data.nextPosX && y == player.data.nextPosY)return 0;//プレイヤーの行こうとしているマスに移動はできない
				if (enemy[This].data.nextWalking_flag == 1) {//エネミーのnextPosを一度だけ更新
					enemy[This].data.nextPosX += MAP_SIZE;
					enemy[This].data.nextWalking_flag = 0;
				}
				return 1;//向いた先が１または３９で進めるなら１を返す
			}
			break;
		case 3:
			for (int i = 0; i < ENEMY_NUM; i++) {//行き先に他のモンスターがいたら進まない
				if ((x == enemy[i].data.nextPosX) && (y - MAP_SIZE == enemy[i].data.nextPosY) && (enemy[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (stage00.tipData[y / MAP_SIZE - 1][x / MAP_SIZE] == 1) {
				if (x == player.data.nextPosX && y - MAP_SIZE == player.data.nextPosY)return 0;//プレイヤーの行こうとしているマスに移動はできない
				if (enemy[This].data.nextWalking_flag == 1) {//エネミーのnextPosを一度だけ更新
					enemy[This].data.nextPosY -= MAP_SIZE;
					enemy[This].data.nextWalking_flag = 0;
				}
				return 1;//向いた先が１または３９で進めるなら１を返す
			}
			break;

		case 4:
			for (int i = 0; i < ENEMY_NUM; i++) {//行き先と行き先の左右に他のモンスターがいたら進まない
				if ((((x + MAP_SIZE == enemy[i].data.nextPosX) && (y - MAP_SIZE == enemy[i].data.nextPosY))
					|| ((x + MAP_SIZE == enemy[i].data.nextPosX) && (y == enemy[i].data.nextPosY))
					|| ((x == enemy[i].data.nextPosX) && (y - MAP_SIZE == enemy[i].data.nextPosY))) && (enemy[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (stage00.tipData[y / MAP_SIZE - 1][x / MAP_SIZE + 1] == 1) {
				if ((x + MAP_SIZE == player.data.nextPosX && y - MAP_SIZE == player.data.nextPosY)//プレイヤーの行こうとしているマス（その左右）に移動はできない
					|| (x + MAP_SIZE == player.data.nextPosX && y == player.data.nextPosY)
					|| (x == player.data.nextPosX) && (y - MAP_SIZE == player.data.nextPosY))return 0;
				if (enemy[This].data.nextWalking_flag == 1) {//エネミーのnextPosを一度だけ更新
					enemy[This].data.nextPosX += MAP_SIZE;
					enemy[This].data.nextPosY -= MAP_SIZE;
					enemy[This].data.nextWalking_flag = 0;
				}
				return 1;//向いた先が１または３９で進めるなら１を返す
			}
			break;
		case 5:
			for (int i = 0; i < ENEMY_NUM; i++) {//行き先と行き先の左右に他のモンスターがいたら進まない
				if ((((x + MAP_SIZE == enemy[i].data.nextPosX) && (y + MAP_SIZE == enemy[i].data.nextPosY))
					|| ((x + MAP_SIZE == enemy[i].data.nextPosX) && (y == enemy[i].data.nextPosY))
					|| ((x == enemy[i].data.nextPosX) && (y + MAP_SIZE == enemy[i].data.nextPosY))) && (enemy[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (stage00.tipData[y / MAP_SIZE + 1][x / MAP_SIZE + 1] == 1) {
				if ((x + MAP_SIZE == player.data.nextPosX && y + MAP_SIZE == player.data.nextPosY)//プレイヤーの行こうとしているマス（その左右）に移動はできない
					|| (x + MAP_SIZE == player.data.nextPosX && y == player.data.nextPosY)
					|| (x == player.data.nextPosX) && (y + MAP_SIZE == player.data.nextPosY))return 0;
				if (enemy[This].data.nextWalking_flag == 1) {//エネミーのnextPosを一度だけ更新
					enemy[This].data.nextPosX += MAP_SIZE;
					enemy[This].data.nextPosY += MAP_SIZE;
					enemy[This].data.nextWalking_flag = 0;
				}
				return 1;//向いた先が１または３９で進めるなら１を返す
			}
			break;
		case 6:
			for (int i = 0; i < ENEMY_NUM; i++) {//行き先と行き先の左右に他のモンスターがいたら進まない
				if ((((x - MAP_SIZE == enemy[i].data.nextPosX) && (y - MAP_SIZE == enemy[i].data.nextPosY))
					|| ((x - MAP_SIZE == enemy[i].data.nextPosX) && (y == enemy[i].data.nextPosY))
					|| ((x == enemy[i].data.nextPosX) && (y - MAP_SIZE == enemy[i].data.nextPosY))) && (enemy[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (stage00.tipData[y / MAP_SIZE - 1][x / MAP_SIZE - 1] == 1) {
				if ((x - MAP_SIZE == player.data.nextPosX && y - MAP_SIZE == player.data.nextPosY)//プレイヤーの行こうとしているマス（その左右）に移動はできない
					|| (x - MAP_SIZE == player.data.nextPosX && y == player.data.nextPosY)
					|| (x == player.data.nextPosX) && (y - MAP_SIZE == player.data.nextPosY))return 0;
				if (enemy[This].data.nextWalking_flag == 1) {//エネミーのnextPosを一度だけ更新
					enemy[This].data.nextPosX -= MAP_SIZE;
					enemy[This].data.nextPosY -= MAP_SIZE;
					enemy[This].data.nextWalking_flag = 0;
				}
				return 1;//向いた先が１または３９で進めるなら１を返す
			}
			break;
		case 7:
			for (int i = 0; i < ENEMY_NUM; i++) {//行き先と行き先の左右に他のモンスターがいたら進まない
				if ((((x - MAP_SIZE == enemy[i].data.nextPosX) && (y + MAP_SIZE == enemy[i].data.nextPosY))
					|| ((x - MAP_SIZE == enemy[i].data.nextPosX) && (y == enemy[i].data.nextPosY))
					|| ((x == enemy[i].data.nextPosX) && (y + MAP_SIZE == enemy[i].data.nextPosY))) && (enemy[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (stage00.tipData[y / MAP_SIZE + 1][x / MAP_SIZE - 1] == 1) {
				if ((x - MAP_SIZE == player.data.nextPosX && y + MAP_SIZE == player.data.nextPosY)//プレイヤーの行こうとしているマス（その左右）に移動はできない
					|| (x - MAP_SIZE == player.data.nextPosX && y == player.data.nextPosY)
					|| (x == player.data.nextPosX) && (y + MAP_SIZE == player.data.nextPosY))return 0;
				if (enemy[This].data.nextWalking_flag == 1) {//エネミーのnextPosを一度だけ更新
					enemy[This].data.nextPosX -= MAP_SIZE;
					enemy[This].data.nextPosY += MAP_SIZE;
					enemy[This].data.nextWalking_flag = 0;
				}
				return 1;//向いた先が１または３９で進めるなら１を返す
			}
		}
		return 0;//進めない場合0を返す

	}

	else
		DrawString(300, 150, "stage00がＯＮになってないぞー", GetColor(255, 0, 0));
	return 0;
	//他のステージに変わったときここので上と同じようにstage00だけ変えて判定



}