#include "../h/GV.h"

//�@�Q�[�����j���[�̍X�V����
void  updateMyCharaMenu() {
	/*
	//Z�L�[�������ꂽ�烁�j���[�J��
	if (player.collisonFlag && beforeZKey == 1 && keyBuffer[KEY_INPUT_Z] == 0) {
		int collisonObjectkind = searchObjectMyChara();
		if (collisonObjectkind != -1) {
			gameState = openMyCharaMenu;
			player.mycharaFocus.state = SELECT;
			PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
		}
	}

*/


		switch (player.mycharaFocus.state)
		{
		case noState://-----------------------���j���[���J�����ǂ���
		
			if (player.collisonFlag && beforeZKey == 1 && keyBuffer[KEY_INPUT_Z] == 0) {
				int collisonObjectkind = searchObjectMyChara();
				if (collisonObjectkind != -1) {
					gameState = openMyCharaMenu;
					player.mycharaFocus.state = SELECT;
					PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
				}
			}
		break;

		case SELECT://-----------------------���ڑI�����------------------------------------------

			if (keyBuffer[KEY_INPUT_DOWN] == 0 && beforeDownKey == 1) {
				PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
				if (player.select.openMyCharaMenuPointY == 190) {
					player.select.openMyCharaMenuPointY = 50;
					player.mycharaFocus.selectIndex = 0;
				}
				else {
					player.select.openMyCharaMenuPointY += 20;
					player.mycharaFocus.selectIndex += 1;
				}
			}

			if (keyBuffer[KEY_INPUT_UP] == 0 && beforeUpKey == 1) {
				PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
				if (player.select.openMyCharaMenuPointY == 50) {
					player.select.openMyCharaMenuPointY = 190;
					player.mycharaFocus.selectIndex = 7;
				}
				else {
					player.select.openMyCharaMenuPointY -= 20;
					player.mycharaFocus.selectIndex -= 1;
				}
			}
			//�b����������߂�
			if (beforeCKey == 1 && keyBuffer[KEY_INPUT_C] == 0) {
				gameState = noState;
				player.mycharaFocus.state = noState;
				PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
				initMyCharaMenu();//���j���[�Z���N�g�|�C���g�̍��W������
			}
			
			//Z����������
			if (beforeZKey == 1 && keyBuffer[KEY_INPUT_Z] == 0) {
				if (player.mycharaFocus.selectIndex == 0){
					PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
					player.mycharaFocus.state = MOVE;
				}
				if (player.mycharaFocus.selectIndex == 1) {
					PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
					player.mycharaFocus.state = SKILL;
				}
				if (player.mycharaFocus.selectIndex == 2) {
					PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
					player.mycharaFocus.state = STATE;
				}
				if (player.mycharaFocus.selectIndex == 3) {
					PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
					player.mycharaFocus.state = MAPATK;
				}
				if (player.mycharaFocus.selectIndex == 4) {
					PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
					player.mycharaFocus.state = ITEM;
				}
				if (player.mycharaFocus.selectIndex == 5) {
					PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
					player.mycharaFocus.state = EQU;
				}
				if (player.mycharaFocus.selectIndex == 6) {
					//PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
					//player.mycharaFocus.state = SKILL;
				}
				if (player.mycharaFocus.selectIndex == 7) {
					PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
					player.mycharaFocus.state = WARMING;
				}
			}
			break;
		case MOVE:

			//�b����������߂�
			if (beforeCKey == 1 && keyBuffer[KEY_INPUT_C] == 0) {
				player.mycharaFocus.state = SELECT;
				PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
				initMyCharaMenu();//���j���[�Z���N�g�|�C���g�̍��W������
			}
			break;
		case SKILL:

			//�b����������߂�
			if (beforeCKey == 1 && keyBuffer[KEY_INPUT_C] == 0) {
				player.mycharaFocus.state = SELECT;
				PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
				//initMyCharaMenu();//���j���[�Z���N�g�|�C���g�̍��W������
			}
			break;
		case STATE:
			
			//�b����������߂�
			if (beforeCKey == 1 && keyBuffer[KEY_INPUT_C] == 0) {
				player.mycharaFocus.state = SELECT;
				PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
				//initMyCharaMenu();//���j���[�Z���N�g�|�C���g�̍��W������
			}
			break;
		case MAPATK:

			//�b����������߂�
			if (beforeCKey == 1 && keyBuffer[KEY_INPUT_C] == 0) {
				player.mycharaFocus.state = SELECT;
				PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
				//initMyCharaMenu();//���j���[�Z���N�g�|�C���g�̍��W������
			}
			break;
		case ITEM:

			//�b����������߂�
			if (beforeCKey == 1 && keyBuffer[KEY_INPUT_C] == 0) {
				player.mycharaFocus.state = SELECT;
				PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
				//initMyCharaMenu();//���j���[�Z���N�g�|�C���g�̍��W������
			}
			break;
		case EQU:

			//�b����������߂�
			if (beforeCKey == 1 && keyBuffer[KEY_INPUT_C] == 0) {
				player.mycharaFocus.state = SELECT;
				PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
				//initMyCharaMenu();//���j���[�Z���N�g�|�C���g�̍��W������
			}
			break;
		case WARMING:

			//�b����������߂�
			if (beforeCKey == 1 && keyBuffer[KEY_INPUT_C] == 0) {
				player.mycharaFocus.state = SELECT;
				PlaySound("����3.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
				//initMyCharaMenu();//���j���[�Z���N�g�|�C���g�̍��W������
			}
			break;
			/*
		default:
			player.mycharaFocus.mycharaFocusflag = SELECT;
			*/
		}
	}

