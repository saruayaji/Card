#include "../h/GV.h"
//�^�C�g����ʂ̍X�V����
void updateTitle() {

	if (titleState == titleSelect) {
		// space�L�[�������Ă��痣���Ɣ���
		if (beforeSpaceKey == 1 && keyBuffer[KEY_INPUT_SPACE] == 0) {//�X�y�[�X����������
			if(player.select.titleMenuPointY == 300 || player.select.titleMenuPointY == 325)
					mainState = GAME;
			else 	DxLib_End();//�I������������ DX���C�u�����g�p�̏I������
			
		}



		if (keyBuffer[KEY_INPUT_DOWN] == 0 && beforeDownKey == 1) {//�����������
			PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
			if (player.select.titleMenuPointY == 300) player.select.titleMenuPointY = 325;
			else if (player.select.titleMenuPointY == 325)player.select.titleMenuPointY = 350;
			else player.select.titleMenuPointY = 300;
		}

		if (keyBuffer[KEY_INPUT_UP] == 0 && beforeUpKey == 1) {
			PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
			if (player.select.titleMenuPointY == 300) player.select.titleMenuPointY = 350;
			else if (player.select.titleMenuPointY == 325)player.select.titleMenuPointY = 300;
			else player.select.titleMenuPointY = 325;
		}

	}
}