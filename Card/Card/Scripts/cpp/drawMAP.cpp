#include "../h/GV.h"


//   MAP�̕\��
void drawMAP(MAP map) {
	for (int i = 0; i < MAXHEIGHT; i++) {//��ʂ̕������[�v
		for (int j = 0; j < MAXWIDTH; j++) {//��ʂ̍��������[�v
			int MaptipPosX = (j * MAP_SIZE) - player.data.x + startXpos, MaptipPosY = (i * MAP_SIZE) - player.data.y + startYpos;

			int tipnum = map.tipData[i][j];
			if (tipnum >= 0 && tipnum<32)DrawGraph(MaptipPosX, MaptipPosY, map.stageGraph[tipnum], TRUE);
			if (tipnum == 39) {
				DrawGraph(MaptipPosX, MaptipPosY, map.stageGraph[1], TRUE);
				//DrawGraph(MaptipPosX, MaptipPosY, StageGraph00[38], TRUE); // �摜��`�悷
			}
			if (tipnum == 50) {
				DrawGraph(MaptipPosX, MaptipPosY, map.stageGraph[1], TRUE);
				DrawGraph(MaptipPosX, MaptipPosY - 18, map.stageGraph[6], TRUE);
			}

		}
	}

}



//MAP�ŏ�̃��C���[�̕`��(�`��ň�ԏ�ɕ`�悵��������)
//������������drawMap()�Ɣ��̂ŋᖡ���ׂ��H�H�H
void drawHeightMap() {
	for (int i = 0; i < MAXHEIGHT; i++) {//��ʂ̕������[�v
		for (int j = 0; j < MAXWIDTH; j++) {//��ʂ̍��������[�v
			int MaptipPosX = (j * MAP_SIZE) - player.data.x + startXpos, MaptipPosY = (i * MAP_SIZE) - player.data.y + startYpos;

			if (stage00.tipData[i][j] == 39) {
				DrawGraph(MaptipPosX, MaptipPosY, StageGraph00[38], TRUE); // �摜��`�悷
			}
		}
	}
}



