#include "DxLib.h"
#include "stdio.h"
#include "sentou.h"
#include "map.h"


int GetHitKeyStateAll_2(int KeyStateBuf[]);
void char_disp(int White, int y);
void TITLE();






int GetHitKeyStateAll_2(int KeyStateBuf[]){
	char GetHitKeyStateAll_Key[256];
	GetHitKeyStateAll(GetHitKeyStateAll_Key);
	for (int i = 0; i<256; i++){
		if (GetHitKeyStateAll_Key[i] == 1) KeyStateBuf[i]++;
		else                            KeyStateBuf[i] = 0;
	}
	return 0;
}

void char_disp(int White, int y){
	SetFontSize(50);

	DrawString(200, y, "��", White);
	DrawString(260, 280, "���w", White);
	DrawString(260, 330, "�o�Z", White);
	DrawString(260, 380, "�ފw", White);
}


void TITLE(){
	ChangeFont("HGS�n�p�p�߯�ߑ�", DX_CHARSET_DEFAULT);

	int Key[256];
	int White, y = 280;                                       //�F��y���W�̐錾
	int title;
	title = LoadGraph("�^�C�g��_43.jpg"); // �摜�̃��[�h
	PlayMusic("9.mp3", DX_PLAYTYPE_BACK);


	ChangeWindowMode(TRUE);//�E�B���h�E���[�h
	
	White = GetColor(0, 0, 0);                    //�F�̎擾


	while (ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll_2(Key) == 0 && Key[KEY_INPUT_ESCAPE] == 0){
		//��ү���ޏ���         ����ʂ�ر         �����͏�Ԃ�ۑ��@�@�@�@�@�@�@��ESC��������Ă��Ȃ�
		DrawGraph(0, 0, title, TRUE); //�摜�̕`��
		char_disp(White, y);         // ������`��

		if (Key[KEY_INPUT_DOWN] == 1 || (Key[KEY_INPUT_DOWN] % 5 == 0 && Key[KEY_INPUT_DOWN]>30)){
			// �����������������A30�J�E���^�[�ȏ㉟�����ςȂ�����5��Ɉ�x
			PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
			y += 50;
			if (y == 430)                            // y���W��260�Ȃ�(�I������ԉ��Ȃ�)
				y = 280;                        // �I�����W����ԏ��
		}
		if (Key[KEY_INPUT_UP] == 1 || (Key[KEY_INPUT_UP] % 5 == 0 && Key[KEY_INPUT_UP] > 30)){
			// �����������������A30�J�E���^�[�ȏ㉟�����ςȂ�����5��Ɉ�x
			PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
			y -= 50;
			if (y == 230)                            // y���W��260�Ȃ�(�I������ԉ��Ȃ�)
				y = 380;                        // �I�����W����ԏ��
			break;
		}


		if (Key[KEY_INPUT_RETURN] == 1 && y == 280){     //�w���w�x��Enter������
			SetFontSize(20);//�t�H���g�T�C�Y��߂��ăQ�[���ɖ߂�
			break;
		}

		if (Key[KEY_INPUT_RETURN] == 1 && y == 330){     //�w�o�Z�x��Enter������
			SetFontSize(30);//�t�H���g�T�C�Y��߂��ăQ�[���ɖ߂�
			break;
		}

		if (Key[KEY_INPUT_RETURN] == 1 && y == 380){     //�w�ފw�x��Enter������
			SetFontSize(30);//�t�H���g�T�C�Y��߂��ăQ�[���ɖ߂�
			break;
		}


		ScreenFlip();//����ʔ��f
	}

}
