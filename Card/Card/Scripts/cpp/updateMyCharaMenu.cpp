#include "../h/GV.h"

//�@�Q�[�����j���[�̍X�V����
void  updateMyCharaMenu() {
	//Z�L�[�������ꂽ�烁�j���[�J��
	if (player.collisonFlag && beforeZKey == 1 && keyBuffer[KEY_INPUT_Z] == 0) {
		int collisonObjectkind = searchObjectMyChara();
		if (collisonObjectkind != -1) {
			gameState = openMyCharaMenu;
			PlaySound("�u�U�[2.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
		}
	}

	//�b����������߂�
	if (gameState == openMyCharaMenu && keyBuffer[KEY_INPUT_C] == 1) {
		gameState = noState;
		initMyCharaMenu();//���j���[�Z���N�g�|�C���g�̍��W������
	}


	if (gameState == openMyCharaMenu) {

		if (keyBuffer[KEY_INPUT_DOWN] == 0 && beforeDownKey == 1) {
			PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
			if (player.select.openMyCharaMenuPointY == 190) {
				player.select.openMyCharaMenuPointY = 50;
			}
			else {
				player.select.openMyCharaMenuPointY += 20;
			}
		}
		
		if (keyBuffer[KEY_INPUT_UP] == 0 && beforeUpKey == 1) {
			PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
			if (player.select.openMyCharaMenuPointY == 50) {
				player.select.openMyCharaMenuPointY = 190;
			}
			else {
				player.select.openMyCharaMenuPointY -= 20;
			}
		}
	}

}