#include "../h/GV.h"


//�}�C�L�����N�^�[�[�X�V����
void updateMyChara() {



	//���s�t���O�A�������
	if (myChara[player.collisonObjectkind].data.x % MAP_SIZE == 0 && myChara[player.collisonObjectkind].data.y % MAP_SIZE == 0 && gameState == openMyCharaMenu/* && player.data.attack_flag == 0*/) {//�}�X�Ƀs�b�^���@���@�U����ԂłȂ��Ȃ�
		myChara[player.collisonObjectkind].data.walking_flag = 1;//��悸���s�t���OON
		myChara[player.collisonObjectkind].data.nextWalking_flag = 1;
		myCharaKeyPushManage();//�Ȃ�̃L�[�������ꂽ���Ǘ�
		//player.collisonFlag = FALSE;
		//searchObject();

		//�ړ��ł��邩�𔻒�B
		if (isAbleToGo(player.collisonObjectkind, myChara[player.collisonObjectkind].data.x, myChara[player.collisonObjectkind].data.y, myChara[player.collisonObjectkind].data.muki) != 1)myChara[player.collisonObjectkind].data.walking_flag = 0;//�ړ��ł��Ȃ��Ȃ�ړ��t���O��0�ɂ���
		
		
		if (beforeZKey == 1 && keyBuffer[KEY_INPUT_Z] == 0  ) {
			if (myCharaSearchObjectMyChara() < 0) {
				PlaySound("�J�[�\��2.wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
				gameState = noState;
				player.mycharaFocus.state = noState;
				//�������W��ݒ�
				myChara[player.collisonObjectkind].data.initPosX = myChara[player.collisonObjectkind].data.x;
				myChara[player.collisonObjectkind].data.initPosY = myChara[player.collisonObjectkind].data.y;
			}
		}

	}

	//���ۂɃv���C���[���ړ�����
	if (myChara[player.collisonObjectkind].data.walking_flag == 1 && myChara[player.collisonObjectkind].data.attack_flag == 0) {//���s�t���O��ON���U���t���O���n�e�e�Ȃ�
		walkingUpdateMyChara(myChara[player.collisonObjectkind].data.muki);//�ړ��ω��֐��i�����ɉ����č��W��ω�������֐��j
	}
}



void myCharaKeyPushManage() {
	/*
	//�U���̊Ǘ�
	if (keyBuffer[KEY_INPUT_Z] == 1) {
	player.data.attack_flag = 1;//�U���t���O�𗧂Ă�
	player.data.walking_flag = 0;
	}
	*/



	//�ړ��̊Ǘ�
	//�\���ړ��@�@�@�u���v�u���v�u���v�u���v�̏�
	if (keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0 && keyBuffer[KEY_INPUT_V] == 0)myChara[player.collisonObjectkind].data.muki = 0;
	else if (keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0 && keyBuffer[KEY_INPUT_V] == 0)myChara[player.collisonObjectkind].data.muki = 1;  //���{�^���������ꂽ�獶�����t���O�𗧂Ă�
	else if (keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0 && keyBuffer[KEY_INPUT_V] == 0)myChara[player.collisonObjectkind].data.muki = 2;//�E�{�^���������ꂽ��E�����t���O�𗧂Ă�
	else if (keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0 && keyBuffer[KEY_INPUT_V] == 0)myChara[player.collisonObjectkind].data.muki = 3;//��{�^���������ꂽ�������t���O�𗧂Ă�
																																  //�΂߈ړ�		�u�E��v�u�E���v�u����v�u�����v�̏�
	else if (keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1 && keyBuffer[KEY_INPUT_V] == 0)myChara[player.collisonObjectkind].data.muki = 4;//�E��{�^���������ꂽ�������t���O�𗧂Ă�
	else if (keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1 && keyBuffer[KEY_INPUT_V] == 0)myChara[player.collisonObjectkind].data.muki = 5;//�E���{�^���������ꂽ�������t���O�𗧂Ă�
	else if (keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1 && keyBuffer[KEY_INPUT_V] == 0)myChara[player.collisonObjectkind].data.muki = 6;//����{�^���������ꂽ�������t���O�𗧂Ă�
	else if (keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1 && keyBuffer[KEY_INPUT_V] == 0)myChara[player.collisonObjectkind].data.muki = 7;//�����{�^���������ꂽ�������t���O�𗧂Ă�
																																									  //���̏�����]���̊Ǘ�
	//�\�������ϊ��@�@�@�u���v�u���v�u���v�u���v�̏�
	else if (keyBuffer[KEY_INPUT_V] == 1 && keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0) myChara[player.collisonObjectkind].data.muki = 0, myChara[player.collisonObjectkind].data.walking_flag = 0, myChara[player.collisonObjectkind].data.nextWalking_flag = 0;//���Ɍ���
	else if (keyBuffer[KEY_INPUT_V] == 1 && keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0) myChara[player.collisonObjectkind].data.muki = 1, myChara[player.collisonObjectkind].data.walking_flag = 0, myChara[player.collisonObjectkind].data.nextWalking_flag = 0;//���Ɍ���
	else if (keyBuffer[KEY_INPUT_V] == 1 && keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0) myChara[player.collisonObjectkind].data.muki = 2, myChara[player.collisonObjectkind].data.walking_flag = 0, myChara[player.collisonObjectkind].data.nextWalking_flag = 0;//�E�Ɍ���
	else if (keyBuffer[KEY_INPUT_V] == 1 && keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0) myChara[player.collisonObjectkind].data.muki = 3, myChara[player.collisonObjectkind].data.walking_flag = 0, myChara[player.collisonObjectkind].data.nextWalking_flag = 0;//��Ɍ���
																																																   //�΂ߌ����]��		�u�E��v�u�E���v�u����v�u�����v�̏�
	else if (keyBuffer[KEY_INPUT_V] == 1 && keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1) myChara[player.collisonObjectkind].data.muki = 4, myChara[player.collisonObjectkind].data.walking_flag = 0, myChara[player.collisonObjectkind].data.nextWalking_flag = 0;//�E��Ɍ���
	else if (keyBuffer[KEY_INPUT_V] == 1 && keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1) myChara[player.collisonObjectkind].data.muki = 5, myChara[player.collisonObjectkind].data.walking_flag = 0, myChara[player.collisonObjectkind].data.nextWalking_flag = 0;//�E���Ɍ���
	else if (keyBuffer[KEY_INPUT_V] == 1 && keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1) myChara[player.collisonObjectkind].data.muki = 6, myChara[player.collisonObjectkind].data.walking_flag = 0, myChara[player.collisonObjectkind].data.nextWalking_flag = 0;//����Ɍ���
	else if (keyBuffer[KEY_INPUT_V] == 1 && keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1) myChara[player.collisonObjectkind].data.muki = 7, myChara[player.collisonObjectkind].data.walking_flag = 0, myChara[player.collisonObjectkind].data.nextWalking_flag = 0;//�����Ɍ���
	else {
		myChara[player.collisonObjectkind].data.walking_flag = 0;//���̃{�^����������ĂȂ���������s�t���OOFF
		myChara[player.collisonObjectkind].data.nextWalking_flag = 0;
	}
}
void walkingUpdateMyChara(int muki) {
	switch (muki) {
	case 0:

		myChara[player.collisonObjectkind].data.y += 1;//�������Ȃ�ch.y���W�𑝂₷				32�̔{������Ŏ�l���̕��s���xUP
		player.data.y += 1;//�������Ȃ�ch.y���W�𑝂₷				32�̔{������Ŏ�l���̕��s���xUP
		break;
	case 1:
		myChara[player.collisonObjectkind].data.x -= 1;//�������Ȃ�ch.x���W�����炷
		player.data.x -= 1;//�������Ȃ�ch.y���W�𑝂₷				32�̔{������Ŏ�l���̕��s���xUP
		break;
	case 2:
		myChara[player.collisonObjectkind].data.x += 1; //�E�����Ȃ�ch.x���W�𑝂₷
		player.data.x += 1;//�������Ȃ�ch.y���W�𑝂₷				32�̔{������Ŏ�l���̕��s���xUP

		break;
	case 3:
		myChara[player.collisonObjectkind].data.y -= 1;//������Ȃ�ch.y���W�����炷
		player.data.y -= 1;//�������Ȃ�ch.y���W�𑝂₷				32�̔{������Ŏ�l���̕��s���xUP

		break;
	case 4:
		myChara[player.collisonObjectkind].data.y -= 1;//�E������Ȃ�ch.y���W�����炷
		myChara[player.collisonObjectkind].data.x += 1;
		player.data.y -= 1;//�������Ȃ�ch.y���W�𑝂₷				32�̔{������Ŏ�l���̕��s���xUP
		player.data.x += 1;//�������Ȃ�ch.y���W�𑝂₷				32�̔{������Ŏ�l���̕��s���xUP		
		break;
	case 5:
		myChara[player.collisonObjectkind].data.y += 1;//�E�������Ȃ�ch.y���W�����炷
		myChara[player.collisonObjectkind].data.x += 1;
		player.data.y += 1;//�������Ȃ�ch.y���W�𑝂₷				32�̔{������Ŏ�l���̕��s���xUP
		player.data.x += 1;//�������Ȃ�ch.y���W�𑝂₷				32�̔{������Ŏ�l���̕��s���xUP		
		break;
	case 6:
		myChara[player.collisonObjectkind].data.y -= 1;//��������Ȃ�ch.y���W�����炷
		myChara[player.collisonObjectkind].data.x -= 1;
		player.data.y -= 1;//�������Ȃ�ch.y���W�𑝂₷				32�̔{������Ŏ�l���̕��s���xUP
		player.data.x -= 1;//�������Ȃ�ch.y���W�𑝂₷				32�̔{������Ŏ�l���̕��s���xUP		
		break;
	case 7:
		myChara[player.collisonObjectkind].data.y += 1;//���������Ȃ�ch.y���W�����炷
		myChara[player.collisonObjectkind].data.x -= 1;
		player.data.y += 1;//�������Ȃ�ch.y���W�𑝂₷				32�̔{������Ŏ�l���̕��s���xUP
		player.data.x -= 1;//�������Ȃ�ch.y���W�𑝂₷				32�̔{������Ŏ�l���̕��s���xUP		

		break;
	}
}
int myCharaSearchObjectMyChara() {//�I�����ꂽ�}�C�L�����Ɠ����}�X�Ƀ}�C�L���������邩
	int i = 0;
	while (i < MYCHARA_NUM) {
		//�����Ώۂ��I�����ꂽ�}�C�L�����������疳�����Ď��̓z��
		if (player.collisonObjectkind == i)i++; 

		if (myChara[player.collisonObjectkind].data.x == myChara[i].data.x  &&   myChara[player.collisonObjectkind].data.y == myChara[i].data.y) {
				
			//�I�𒆂̃}�C�L�����Ƒ��̃}�C�L�������������W��������
			myChara[player.collisonObjectkind].myCharaCollisonFlag = TRUE;
			return i;//�ڐG���m�F�����炱�̊֐����甲����
		}
		else {
			myChara[player.collisonObjectkind].myCharaCollisonFlag = FALSE;
		}
		i++;
	}
	return -1;//�����̃I�u�W�F�N�g��������Ȃ������ꍇ
}
