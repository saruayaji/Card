#include "GV.h"


void attackUpdatePlayer(int x, int y, int muki) {//何秒間攻撃更新処理をしているか（アニメーションやSEに合わせてtimeを変える）
	normalAttack.time++;
	if (normalAttack.time == 1) {

		for (int i = 0; i < ENEMY_NUM; i++) {
			if (player.data.actionPosX == enemy[i].data.x && player.data.actionPosY == enemy[i].data.y && enemy[i].state.deadOrAlive == ALIVE) {//前（actionPos）に敵がいるなら
				if (player.status.ATK <= enemy[i].status.DFE) { enemy[i].status.HP -= 0; }//プレイヤーの攻撃力 ＜ 敵の防御力　の場合　与ダメは0となる。
				
				else enemy[i].status.HP -= player.status.ATK - enemy[i].status.DFE;//それ以外（ATK>DFEの場合）与ダメ　＝　自ATK - 敵DFE　
				if (enemy[i].status.HP <= 0) {//敵を倒したら
					player.status.EXP += enemy[i].status.EXP;
					enemy[i].state.deadOrAlive = DEAD;
				}
			}
		}


	}

	if (normalAttack.time == 32) {
		player.data.attack_flag = 0, normalAttack.time = 0;
		player.state.actState = act_End;//normalAttack.time(攻撃モーション時間)が終わったらプレイヤーの攻撃を終了（act_End）とする
		player.data.turn++;//プレイヤーのターン終わり
	}
	else {
		player.data.walking_flag = 0;
		player.state.actState = act_Now;//normalAttack.time(攻撃モーション時間)が終わっていなかったらプレイヤーの攻撃途中（act_Now）とする
	}

}