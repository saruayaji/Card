#include "GV.h"


void attackUpdateEnemy(int x, int y, int muki, int i) {//攻撃の更新処理
	if (player.data.x % MAP_SIZE == 0 && player.data.y % MAP_SIZE == 0 && enemy[i].state.deadOrAlive == ALIVE) {//座標が32で割り切れたら入力可能(マスとして管理しているため)
		player.status.HP -= 10;
	}


}
