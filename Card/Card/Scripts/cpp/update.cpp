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
		//�@�ړ�����
		if (player.data.walking_flag == 1 && player.data.attack_flag == 0) {//���s�t���O��ON���U���t���O���n�e�e�Ȃ�
			walkingUpdatePlayer(player.data.muki);//�ړ��ω��֐��i�����ɉ����č��W��ω�������֐��j
		}

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
