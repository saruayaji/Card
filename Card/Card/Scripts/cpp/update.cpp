#include "../h/GV.h"



// ---------------------------------------- �X�V���� ------------------------------------------------------------------------------------------------------
void update() {

	switch (mainState) {
	case TITLE:
		updateTitle();
		break;


	case GAME:
		// �Q�[���̍X�V�������s��
		updatePlayer();	//�v���C���[�X�V����
		updateGameMenu();//���j���[�X�V����
		updateMyCharaMenu();//�L�������j���[�X�V����

		break;

	case GAMEOVER:
		// space�L�[�������Ă��痣���Ɣ���
		if (beforeSpaceKey == 1 && keyBuffer[KEY_INPUT_SPACE] == 0) {
			init();
		}
		break;

	case GAMECLEAR:
		// space�L�[�������Ă��痣���Ɣ���
		if (beforeSpaceKey == 1 && keyBuffer[KEY_INPUT_SPACE] == 0) {
			init();
		}
		break;
	}

}
