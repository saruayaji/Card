#include "../h/GV.h"

void walkingUpdateEnemy(int i, int muki) {
	/*向き情報に則した移動管理*/
	if (enemyChara[i].data.walking_flag == 1) {//歩行フラグがONなら
		switch (muki) {
		case 0:
			enemyChara[i].data.y++;//下向きならch.y座標を増やす
			break;
		case 1:
			enemyChara[i].data.x--;//左向きならch.x座標を減らす
			break;
		case 2:
			enemyChara[i].data.x++; //右向きならch.x座標を増やす
			break;
		case 3:
			enemyChara[i].data.y--;//上向きならch.y座標を減らす
			break;
		case 4:
			enemyChara[i].data.y--;//右上向きならch.y座標を減らす
			enemyChara[i].data.x++;
			break;
		case 5:
			enemyChara[i].data.y++;//右下向きならch.y座標を減らす
			enemyChara[i].data.x++;
			break;
		case 6:
			enemyChara[i].data.y--;//左上向きならch.y座標を減らす
			enemyChara[i].data.x--;
			break;
		case 7:
			enemyChara[i].data.y++;//左下向きならch.y座標を減らす
			enemyChara[i].data.x--;
			break;
		}
	}



}