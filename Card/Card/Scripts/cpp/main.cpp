#define _GLOBAL_INSTANCE_ 
#include "../h/GV.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//��----------��-----------��-----------main�֐�--------------��------------��----------��----------------------------------------------------------------------------//////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//�E�B���h�E�̃^�C�g���w��
	SetMainWindowText("TDU�s�v�c�̃_���W����");

	//�c�w���C�u����������
	if (DxLib_Init() == -1) {
		return -1;
	}

	// ��ʃ��[�h�̕ύX
	SetGraphMode(WINDOW_W, WINDOW_H, 32);

	//�`���𗠉�ʂɐݒ�]
	SetDrawScreen(DX_SCREEN_BACK);

	//�Q�[���̏�����
	init();

	//�P�b�ɂU�O���ʂ��X�V
	int nextTime = GetNowCount() + 1000 / 60;

	//ESC�L�[�������܂Ń��[�v����
	while (ProcessMessage() == 0 && keyBuffer[KEY_INPUT_ESCAPE] == 0) {

		input();	// ���͏���

		update();	// �X�V����

		draw();		// �`�揈��

					// ���Ԃ��]�����ꍇ�Asleep����
		if (nextTime > GetNowCount()) {
			Sleep(nextTime - GetNowCount());
		}
		nextTime = GetNowCount() + 1000 / 60;
	}

	// DX���C�u�����g�p�̏I������
	DxLib_End();


	// �\�t�g�̏I��
	return 0;
}




