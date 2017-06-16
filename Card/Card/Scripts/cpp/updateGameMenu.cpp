#include "../h/GV.h"

//�@�Q�[�����j���[�̍X�V����
void  updateGameMenu() {
	//�w�L�[�������ꂽ�烁�j���[�J��
	if (player.data.walking_flag == 0 && keyBuffer[KEY_INPUT_X] == 1 && gameState == noState) {//X��������Ă���Ȃ�
		gameState = openGameMenu;
		PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t

	}
	//�b����������߂�
	if (gameState == openGameMenu && keyBuffer[KEY_INPUT_C] == 1) {
		gameState = noState;
		PlaySound("�u�U�[1.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
		initOpenGameMenu();//���j���[�Z���N�g�|�C���g�̍��W������
	}

	if (gameState == openGameMenu) {

		if (keyBuffer[KEY_INPUT_DOWN] == 0 && beforeDownKey == 1){
			PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
			if (player.select.openGameMenuPointY == 95) {
				player.select.openGameMenuPointY = 45;
			}
			else {
				player.select.openGameMenuPointY += 25;
			}
		}
		
		if(keyBuffer[KEY_INPUT_UP] == 0 && beforeUpKey == 1){
			PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
			if (player.select.openGameMenuPointY == 45) {
				player.select.openGameMenuPointY = 95;
			}
			else {
				player.select.openGameMenuPointY -= 25;
			}

		}

		if ((keyBuffer[KEY_INPUT_RIGHT] == 0 && beforeRightKey == 1) ||
			(keyBuffer[KEY_INPUT_LEFT] == 0 && beforeLeftKey == 1)) {
			PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
			if (player.select.openGameMenuPointX == 13) {
				player.select.openGameMenuPointX = 133;
			}
			else {
				player.select.openGameMenuPointX = 13;
			}
		}


	}

}