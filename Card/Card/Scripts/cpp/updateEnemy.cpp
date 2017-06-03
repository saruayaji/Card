
#include "GV.h"

//敵の更新処理
void updateEnemy() {


	int i = 0;
	while (i < ENEMY_NUM) {//敵の人数繰り返す

		if (enemy[i].data.x % MAP_SIZE == 0 && enemy[i].data.y % MAP_SIZE == 0) {//座標が32で割り切れたら入力可能(マスとして管理しているため)
			enemy[i].data.walking_flag = 1;//一先ず歩行フラグON
			enemy[i].data.nextWalking_flag = 1;


			if (EnemyIsAbleToGo(enemy[i].data.x, enemy[i].data.y, enemy[i].data.muki, i) == 0)continue;//enemy[i].data.walking_flag = 0;//移動しようとした行先が壁のとき再び乱数を取得する
			else if (EnemyIsAbleToGo(enemy[i].data.x, enemy[i].data.y, enemy[i].data.muki, i) == 2) continue;//移動しようとした行先がプレイヤーの移動しようたマスのとき再び乱数を取得する

		}
		walkingUpdateEnemy(i, enemy[i].data.muki);

		i++;
	}

}

void decideAction() {
	int i = 0;
	while (i < ENEMY_NUM) {//敵の人数繰り返す
		if (enemy[i].data.x % MAP_SIZE == 0 && enemy[i].data.y % MAP_SIZE == 0 && enemy[i].state.deadOrAlive == ALIVE) {//座標が32で割り切れたら入力可能(マスとして管理しているため)
			int muki = enemy[i].data.muki;//敵の向きを保存しておく
			enemy[i].data.walking_flag = 1;//一先ず歩行フラグON
			enemy[i].data.nextWalking_flag = 1;

			enemy[i].data.muki = moveroot(enemy[i].data.x, enemy[i].data.y, player.data.nextPosX, player.data.nextPosY,enemy[i].data.muki);//moverootを使って移動か攻撃かを判定

			if (enemy[i].data.muki / 10 == 1) {//moverootが10～19の場合、攻撃フラグを立てる
				enemy[i].data.walking_flag = 0;
				enemy[i].data.attack_flag = 1;
				

			}
			else { //それ以外は移動フラグを立てる
				enemy[i].data.walking_flag = 1;
				enemy[i].data.attack_flag = 0;
			}
			enemy[i].data.muki %= 10;//2桁になったmukiを向きだけの情報に戻す
			if (enemy[i].data.walking_flag == 1) {
				if (EnemyIsAbleToGo(enemy[i].data.x, enemy[i].data.y, enemy[i].data.muki, i) == 0)enemy[i].data.walking_flag = 0;//移動しようとした行先が壁のとき再び乱数を取得する
				else if (EnemyIsAbleToGo(enemy[i].data.x, enemy[i].data.y, enemy[i].data.muki, i) == 2) enemy[i].data.attack_flag = 1;//移動しようとした行先がプレイヤーの移動しようたマスのとき再び乱数を取得する
			}



			/*
			if (enemy[i].data.muki == 10) {
			enemy[i].data.walking_flag = 0;
			enemy[i].data.attack_flag = 1;

			}
			else {
			enemy[i].data.walking_flag = 1;
			enemy[i].data.attack_flag = 0;
			}

			if (enemy[i].data.walking_flag == 1) {
			if (EnemyIsAbleToGo(enemy[i].data.x, enemy[i].data.y, enemy[i].data.muki, i) == 0)enemy[i].data.walking_flag = 0;//移動しようとした行先が壁のとき再び乱数を取得する
			else if (EnemyIsAbleToGo(enemy[i].data.x, enemy[i].data.y, enemy[i].data.muki, i) == 2) enemy[i].data.attack_flag = 1;//移動しようとした行先がプレイヤーの移動しようたマスのとき再び乱数を取得する
			}
			
			*/
		}
		i++;
	}

}

int decideDirection(int enemyX, int enemyY, int playerX, int playerY, int enemymuki,int i) {//敵（NPC）が向きだけを変更。プレイヤーの方向を向く（使うかわからないが一応）
	int enemyToPlayerX = playerX - enemyX;//敵からプレイヤーまでのXの距離
	int enemyToPlayerY = playerY - enemyY;//敵からプレイヤーまでのYの距離

	int returndata = 0;
	if (enemyToPlayerX >= MAP_SIZE && enemyToPlayerY >= MAP_SIZE)returndata += 5;  // + +   右下に移動
	else if (enemyToPlayerX >= MAP_SIZE && enemyToPlayerY <= -MAP_SIZE)returndata += 4; // + -   右上に移動
	else if (enemyToPlayerX <= -MAP_SIZE && enemyToPlayerY >= MAP_SIZE)returndata += 7; // - +   左下に移動
	else if (enemyToPlayerX <= -MAP_SIZE && enemyToPlayerY <= -MAP_SIZE)returndata += 6;// - -   左上に移動
	else if (enemyToPlayerX >= MAP_SIZE)returndata += 2;// +    右に移動
	else if (enemyToPlayerX <= -MAP_SIZE)returndata += 1;// +    左に移動
	else if (enemyToPlayerY >= MAP_SIZE)returndata += 0;// +    下に移動
	else if (enemyToPlayerY <= -MAP_SIZE)returndata += 3;// +    上に移動
	
	return returndata;
}

int moveroot(int enemyX, int enemyY, int playerX, int playerY,int enemymuki) {//攻撃か移動かを敵とプレイヤーの座標距離で判断する
	int enemyToPlayerX = playerX - enemyX;//敵からプレイヤーまでのXの距離
	int enemyToPlayerY = playerY - enemyY;//敵からプレイヤーまでのYの距離

	int returndata = 0;

	if ((abs(enemyToPlayerX) <= MAP_SIZE) && (abs(enemyToPlayerY) <= MAP_SIZE))returndata+=10; //隣接した場合攻撃で返す 10++

	if		(enemyToPlayerX >= MAP_SIZE && enemyToPlayerY >= MAP_SIZE)returndata+=5;  // + +   右下に移動
	else if (enemyToPlayerX >= MAP_SIZE && enemyToPlayerY <= -MAP_SIZE)returndata += 4; // + -   右上に移動
	else if (enemyToPlayerX <= -MAP_SIZE && enemyToPlayerY >= MAP_SIZE)returndata += 7; // - +   左下に移動
	else if (enemyToPlayerX <= -MAP_SIZE && enemyToPlayerY <= -MAP_SIZE)returndata += 6;// - -   左上に移動
	else if (enemyToPlayerX >= MAP_SIZE)returndata += 2;// +    右に移動
	else if (enemyToPlayerX <= -MAP_SIZE)returndata += 1;// +    左に移動
	else if (enemyToPlayerY >= MAP_SIZE)returndata += 0;// +    下に移動
	else if (enemyToPlayerY <= -MAP_SIZE)returndata += 3;// +    上に移動
	
	return returndata;

}