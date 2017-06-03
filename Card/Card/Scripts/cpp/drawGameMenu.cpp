#include "GV.h"


//ゲーム中のメニュー画面など
void drawGameMenu() {

	//メニュー欄の枠を描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawBox(10, 40, 180, 120, Cr[0] = GetColor(0, 80, 150), TRUE);
	DrawBox(10, 40, 180, 120, Cr[1] = GetColor(255, 255, 250), FALSE);
	DrawBox(10, 300, 630, 470, Cr[0] = GetColor(0, 80, 150), TRUE);
	DrawBox(10, 300, 630, 470, Cr[1] = GetColor(255, 255, 250), FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//SPバーの表示
	DrawBox(200, 40, 200 + WD, 60, GetColor(0, 0, 255), FALSE);//メーターの枠を描画
	DrawBox(200, 40, 200 + WD*player.status.SP / player.status.MAXSP, 60, GetColor(0, 0, 255), TRUE);//メーターの中身を描画
																									 //ＥＸＰバーの表示
	DrawBox(100, 440, 100 + WD, 460, GetColor(0, 0, 255), FALSE);//メーターの枠を描画
	DrawBox(100, 440, 100 + WD*player.status.EXP / player.status.MAXEXP, 460, GetColor(0, 200, 200), TRUE);//メーターの中身を描画


																										   //文字列表示
	DrawFormatString(210, 40, Cr[1] = GetColor(255, 0, 0), "SP%d/%d ", player.status.SP, player.status.MAXSP);
	DrawFormatString(110, 442, Cr[1] = GetColor(255, 0, 0), "EXP  %d/%d ", player.status.EXP, player.status.MAXEXP);
	DrawFormatString(20, 310, Cr[1] = GetColor(0, 255, 0), "ATK%d DFE%d", player.status.ATK, player.status.DFE);

	//select文字列			
	DrawString(player.select.openGameMenuPointX, player.select.openGameMenuPointY, "■", Cr[0] = (0, 0, 0));
	DrawString(30, 45, "持ち物", Cr[0] = (0, 0, 0));
	DrawString(30, 70, "状態", Cr[0] = (0, 0, 0));
	DrawString(130, 45, "設定", Cr[0] = (0, 0, 0));

}


