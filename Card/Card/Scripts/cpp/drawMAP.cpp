#include "../h/GV.h"


//   MAPの表示
void drawMAP(MAP map) {
	for (int i = 0; i < MAXHEIGHT; i++) {//画面の幅分ループ
		for (int j = 0; j < MAXWIDTH; j++) {//画面の高さ分ループ
			int MaptipPosX = (j * MAP_SIZE) - player.data.x + startXpos, MaptipPosY = (i * MAP_SIZE) - player.data.y + startYpos;

			int tipnum = map.tipData[i][j];
			if (tipnum >= 0 && tipnum<32)DrawGraph(MaptipPosX, MaptipPosY, map.stageGraph[tipnum], TRUE);
			if (tipnum == 39) {
				DrawGraph(MaptipPosX, MaptipPosY, map.stageGraph[1], TRUE);
				//DrawGraph(MaptipPosX, MaptipPosY, StageGraph00[38], TRUE); // 画像を描画す
			}
			if (tipnum == 50) {
				DrawGraph(MaptipPosX, MaptipPosY, map.stageGraph[1], TRUE);
				DrawGraph(MaptipPosX, MaptipPosY - 18, map.stageGraph[6], TRUE);
			}

		}
	}

}



//MAP最上のレイヤーの描画(描画で一番上に描画したいもの)
//◆正直処理がdrawMap()と被るので吟味すべき？？？
void drawHeightMap() {
	for (int i = 0; i < MAXHEIGHT; i++) {//画面の幅分ループ
		for (int j = 0; j < MAXWIDTH; j++) {//画面の高さ分ループ
			int MaptipPosX = (j * MAP_SIZE) - player.data.x + startXpos, MaptipPosY = (i * MAP_SIZE) - player.data.y + startYpos;

			if (stage00.tipData[i][j] == 39) {
				DrawGraph(MaptipPosX, MaptipPosY, StageGraph00[38], TRUE); // 画像を描画す
			}
		}
	}
}



