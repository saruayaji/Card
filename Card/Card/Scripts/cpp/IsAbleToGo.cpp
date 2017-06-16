#include "../h/GV.h"

//■進めるかどうか判定をする。
int isAbleToGo(int index, int x, int y, int muki) {//進めるかを判定する

	if (stage00.Switch == ON) {			//今ステージ００にいたら
		switch (muki) {
		case 0:

			for (int i = 0; i < ENEMY_NUM; i++) {//プレイヤーの移動先に敵がいたら
				if ((myChara[index].data.x == enemyChara[i].data.x) && (myChara[index].data.y + MAP_SIZE == enemyChara[i].data.y) && (enemyChara[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (stage00.tipData[y / MAP_SIZE + 1][x / MAP_SIZE] == 1 || stage00.tipData[y / MAP_SIZE + 1][x / MAP_SIZE] == 39) {
				if (myChara[index].data.nextWalking_flag == 1) {//nextPointを一度だけ更新
					myChara[index].data.nextPosY += MAP_SIZE;
					myChara[index].data.nextWalking_flag = 0;
				}
				return 1;//向いた先が１または３９で進めるなら１を返す
			}
			break;

		case 1:

			for (int i = 0; i < ENEMY_NUM; i++) {//プレイヤーの移動先に敵がいたら
				if ((myChara[index].data.x - MAP_SIZE == enemyChara[i].data.x) && (myChara[index].data.y == enemyChara[i].data.y) && (enemyChara[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (x / MAP_SIZE - 1 < 0)return 0;
			if (stage00.tipData[y / MAP_SIZE][x / MAP_SIZE - 1] == 1 || stage00.tipData[y / MAP_SIZE][x / MAP_SIZE - 1] == 39) {
				if (myChara[index].data.nextWalking_flag == 1) {//nextPointを一度だけ更新
					myChara[index].data.nextPosX -= MAP_SIZE;
					myChara[index].data.nextWalking_flag = 0;
				}

				return 1;//向いた先が１または３９で進めるなら１を返す
			}
			break;

		case 2:

			for (int i = 0; i < ENEMY_NUM; i++) {//プレイヤーの移動先に敵がいたら
				if ((myChara[index].data.x + MAP_SIZE == enemyChara[i].data.x) && (myChara[index].data.y == enemyChara[i].data.y) && (enemyChara[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (stage00.tipData[y / MAP_SIZE][x / MAP_SIZE + 1] == 1 || stage00.tipData[y / MAP_SIZE][x / MAP_SIZE + 1] == 39) {
				if (myChara[index].data.nextWalking_flag == 1) {//nextPointを一度だけ更新
					myChara[index].data.nextPosX += MAP_SIZE;
					myChara[index].data.nextWalking_flag = 0;
				}
				return 1;//向いた先が１または３９で進めるなら１を返す
			}
			break;
		case 3:

			for (int i = 0; i < ENEMY_NUM; i++) {//プレイヤーの移動先に敵がいたら
				if ((myChara[index].data.x == enemyChara[i].data.x) && (myChara[index].data.y - MAP_SIZE == enemyChara[i].data.y) && (enemyChara[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (stage00.tipData[y / MAP_SIZE - 1][x / MAP_SIZE] == 1 || stage00.tipData[y / MAP_SIZE - 1][x / MAP_SIZE] == 39) {
				if (myChara[index].data.nextWalking_flag == 1) {//nextPointを一度だけ更新
					myChara[index].data.nextPosY -= MAP_SIZE;
					myChara[index].data.nextWalking_flag = 0;
				}
				return 1;//向いた先が１または３９で進めるなら１を返す
			}
			break;
		case 4:

			for (int i = 0; i < ENEMY_NUM; i++) {//プレイヤーの移動先（その左右）に敵がいたら
				if (((myChara[index].data.x + MAP_SIZE == enemyChara[i].data.x) && (myChara[index].data.y - MAP_SIZE == enemyChara[i].data.y) && (enemyChara[i].state.deadOrAlive == ALIVE))
					|| ((myChara[index].data.x + MAP_SIZE == enemyChara[i].data.x) && (myChara[index].data.y == enemyChara[i].data.y))
					|| ((myChara[index].data.x == enemyChara[i].data.x) && (myChara[index].data.y - MAP_SIZE == enemyChara[i].data.y))) return 0;
			}
			if (stage00.tipData[y / MAP_SIZE - 1][x / MAP_SIZE + 1] == 1 || stage00.tipData[y / MAP_SIZE - 1][x / MAP_SIZE + 1] == 39) {
				if (myChara[index].data.nextWalking_flag == 1) {//nextPointを一度だけ更新
					myChara[index].data.nextPosX += MAP_SIZE;
					myChara[index].data.nextPosY -= MAP_SIZE;
					myChara[index].data.nextWalking_flag = 0;
				}
				return 1;//向いた先が１または３９で進めるなら１を返す
			}
			break;

		case 5:

			for (int i = 0; i < ENEMY_NUM; i++) {//プレイヤーの移動先（その左右）に敵がいたら
				if (((myChara[index].data.x + MAP_SIZE == enemyChara[i].data.x) && (myChara[index].data.y + MAP_SIZE == enemyChara[i].data.y) && (enemyChara[i].state.deadOrAlive == ALIVE))
					|| ((myChara[index].data.x + MAP_SIZE == enemyChara[i].data.x) && (myChara[index].data.y == enemyChara[i].data.y))
					|| ((myChara[index].data.x == enemyChara[i].data.x) && (myChara[index].data.y + MAP_SIZE == enemyChara[i].data.y))) return 0;
			}
			if (stage00.tipData[y / MAP_SIZE + 1][x / MAP_SIZE + 1] == 1 || stage00.tipData[y / MAP_SIZE + 1][x / MAP_SIZE + 1] == 39) {
				if (myChara[index].data.nextWalking_flag == 1) {//nextPointを一度だけ更新
					myChara[index].data.nextPosX += MAP_SIZE;
					myChara[index].data.nextPosY += MAP_SIZE;
					myChara[index].data.nextWalking_flag = 0;
				}
				return 1;//向いた先が１または３９で進めるなら１を返す
			}
			break;
		case 6:

			for (int i = 0; i < ENEMY_NUM; i++) {//プレイヤーの移動先（その左右）に敵がいたら
				if (((myChara[index].data.x - MAP_SIZE == enemyChara[i].data.x) && (myChara[index].data.y - MAP_SIZE == enemyChara[i].data.y) && (enemyChara[i].state.deadOrAlive == ALIVE))
					|| ((myChara[index].data.x - MAP_SIZE == enemyChara[i].data.x) && (myChara[index].data.y == enemyChara[i].data.y))
					|| ((myChara[index].data.x == enemyChara[i].data.x) && (myChara[index].data.y - MAP_SIZE == enemyChara[i].data.y))) return 0;
			}
			if (stage00.tipData[y / MAP_SIZE - 1][x / MAP_SIZE - 1] == 1 || stage00.tipData[y / MAP_SIZE - 1][x / MAP_SIZE - 1] == 39) {
				if (myChara[index].data.nextWalking_flag == 1) {//nextPointを一度だけ更新
					myChara[index].data.nextPosX -= MAP_SIZE;
					myChara[index].data.nextPosY -= MAP_SIZE;
					myChara[index].data.nextWalking_flag = 0;
				}
				return 1;//向いた先が１または３９で進めるなら１を返す
			}
			break;
		case 7:

			for (int i = 0; i < ENEMY_NUM; i++) {//プレイヤーの移動先（その左右）に敵がいたら
				if (((myChara[index].data.x - MAP_SIZE == enemyChara[i].data.x) && (myChara[index].data.y + MAP_SIZE == enemyChara[i].data.y) && (enemyChara[i].state.deadOrAlive == ALIVE))
					|| ((myChara[index].data.x - MAP_SIZE == enemyChara[i].data.x) && (myChara[index].data.y == enemyChara[i].data.y))
					|| ((myChara[index].data.x == enemyChara[i].data.x) && (myChara[index].data.y + MAP_SIZE == enemyChara[i].data.y))) return 0;
			}
			if (stage00.tipData[y / MAP_SIZE + 1][x / MAP_SIZE - 1] == 1 || stage00.tipData[y / MAP_SIZE + 1][x / MAP_SIZE - 1] == 39) {
				if (myChara[index].data.nextWalking_flag == 1) {//nextPointを一度だけ更新
					myChara[index].data.nextPosX -= MAP_SIZE;
					myChara[index].data.nextPosY += MAP_SIZE;
					myChara[index].data.nextWalking_flag = 0;
				}
				return 1;//向いた先が１または３９で進めるなら１を返す
			}
			break;

		}
		return 0;//進めない場合0を返す

	}

	else
		DrawString(300, 150, "stage00がＯＮになってないぞー", GetColor(255, 0, 0));
	return 0;
	//他のステージに変わったときここので上と同じようにstage00だけ変えて判定



}