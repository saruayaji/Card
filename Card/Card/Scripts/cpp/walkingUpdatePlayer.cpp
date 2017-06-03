#include "../h/GV.h"


//■実際に座標を向きに応じて変化させる
void walkingUpdatePlayer(int muki) {
	switch (muki) {
	case 0:

		player.data.y+=4;//下向きならch.y座標を増やす				32の倍数代入で主人公の歩行速度UP
		break;
	case 1:
		player.data.x-= 4;//左向きならch.x座標を減らす
		break;
	case 2:
		player.data.x+= 4; //右向きならch.x座標を増やす
		break;
	case 3:
		player.data.y-= 4;//上向きならch.y座標を減らす
		break;
	case 4:
		player.data.y-= 4;//右上向きならch.y座標を減らす
		player.data.x+= 4;
		break;
	case 5:
		player.data.y+= 4;//右下向きならch.y座標を減らす
		player.data.x+= 4;
		break;
	case 6:
		player.data.y-= 4;//左上向きならch.y座標を減らす
		player.data.x-= 4;
		break;
	case 7:
		player.data.y+= 4;//左下向きならch.y座標を減らす
		player.data.x-= 4;
		break;
	}
}
