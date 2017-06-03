#include "GV.h"
#include <string>
#define DAMEGEmes 0

void drawMessage(int type) {
	if (type == DAMEGEmes) {
		DrawFormatString(str.x, str.y, Cr[1] = GetColor(255, 0, 0), "%sに%dダメージを与えた", enemy[3].name, player.status.ATK);

	if (str.y >= 480) { str.y = 200;}
	else { str.y+=2; }

	}
}

//攻撃メッセージと被攻撃メッセごとに引数を変えてcharを文字出力するのはどうか。プレイヤーや敵に名前（char）を作ることにはなる