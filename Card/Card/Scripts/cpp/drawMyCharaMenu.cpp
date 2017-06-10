#include "../h/GV.h"


//ゲーム中のメニュー画面など
void drawMyCharaMenu() {

	//メニュー欄の枠を描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawBox(500, 40, 638, 240, Cr[0] = GetColor(0, 80, 150), TRUE);
	DrawBox(500, 40, 639, 240, Cr[1] = GetColor(255, 255, 250), FALSE);
	//DrawBox(400, 300, 630, 470, Cr[0] = GetColor(0, 80, 150), TRUE);
	//DrawBox(400, 300, 630, 470, Cr[1] = GetColor(255, 255, 250), FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	/*
	//文字列表示
	DrawFormatString(210, 40, Cr[1] = GetColor(255, 0, 0), "SP%d/%d ", player.status.SP, player.status.MAXSP);
	DrawFormatString(110, 442, Cr[1] = GetColor(255, 0, 0), "EXP  %d/%d ", player.status.EXP, player.status.MAXEXP);
	DrawFormatString(20, 310, Cr[1] = GetColor(0, 255, 0), "ATK%d DFE%d", player.status.ATK, player.status.DFE);
	*/
	//select文字列			
	DrawString(player.select.openMyCharaMenuPointX, player.select.openMyCharaMenuPointY, "■", Cr[0] = (0, 0, 0));
	DrawString(520, 50, "移動", Cr[0] = (0, 0, 0));
	DrawString(520, 70, "スキル", Cr[0] = (0, 0, 0));
	DrawString(520, 90, "ステート", Cr[0] = (0, 0, 0));
	DrawString(520, 110, "マップ攻撃", Cr[0] = (0, 0, 0));
	DrawString(520, 130, "アイテム", Cr[0] = (0, 0, 0));
	DrawString(520, 150, "装備", Cr[0] = (0, 0, 0));
	DrawString(520, 170, "？", Cr[0] = (0, 0, 0));
	DrawString(520, 190, "警戒", Cr[0] = (0, 0, 0));


}


