#include "../h/GV.h"


//�v���C���[�[�X�V����
void updatePlayer() {



	//���s�t���O�A�������
	if (player.data.x % MAP_SIZE == 0 && player.data.y % MAP_SIZE == 0 && gameState == noState && player.data.attack_flag == 0) {//�}�X�Ƀs�b�^���@���@�U����ԂłȂ��Ȃ�
		player.data.walking_flag = 1;//��悸���s�t���OON
		player.data.nextWalking_flag = 1;
		keyPushManage();//�Ȃ�̃L�[�������ꂽ���Ǘ�
		player.collisonFlag = FALSE;
		searchObject();

		//�ړ��ł��邩�𔻒�B
		//if (playerIsAbleToGo(player.data.x, player.data.y, player.data.muki) != 1)player.data.walking_flag = 0;//�ړ��ł��Ȃ��Ȃ�ړ��t���O��0�ɂ���
		//decideActionPos();
	

	
	}

	//���ۂɃv���C���[���ړ�����
	if (player.data.walking_flag == 1 && player.data.attack_flag == 0) {//���s�t���O��ON���U���t���O���n�e�e�Ȃ�
		walkingUpdatePlayer(player.data.muki);//�ړ��ω��֐��i�����ɉ����č��W��ω�������֐��j
	}
	

}


void searchObject(){//�v���C���[�Ɠ����}�X�ɉ����I�u�W�F�N�g�͂��邩
	int i = 0;
	while (i < MYCHARA_NUM) {
		if (player.data.x == myChara[i].data.x  &&   player.data.y == myChara[i].data.y) {
			//�v���C���[�Ǝ����̃L�������������W��������
			collisonObject = myChara[i];
			player.collisonFlag = TRUE;
			return;//�ڐG���m�F�����炱�̊֐����甲����
		}
		else {
			player.collisonFlag = FALSE;
		}
		i++;
	}

	i = 0;
	while (i < ENEMY_NUM) {
		if (player.data.x == enemyChara[i].data.x  &&   player.data.y == enemyChara[i].data.y) {
			//�v���C���[�ƓG�L�������������W��������
			collisonObject = enemyChara[i];
			player.collisonFlag = TRUE;
			return;//�ڐG���m�F�����炱�̊֐����甲����
		}
		else {
			player.collisonFlag = FALSE;
		}
		i++;
	}

}


int searchObjectMyChara() {//�v���C���[�Ɠ����}�X�ɉ����I�u�W�F�N�g�͂��邩
	int i = 0;
	while (i < MYCHARA_NUM) {
		if (player.data.x == myChara[i].data.x  &&   player.data.y == myChara[i].data.y) {
			//�v���C���[�Ǝ����̃L�������������W��������
			player.collisonFlag = TRUE;
			return i;//�ڐG���m�F�����炱�̊֐����甲����
		}
		else {
			player.collisonFlag = FALSE;
		}
		i++;
	}
	return -1;//�����̃I�u�W�F�N�g��������Ȃ������ꍇ
}

void decideActionPos() {//actionPos���擾����֐��BactionPos....�v���C���[�̑O�̍��W

	if (player.data.muki == 0) { player.data.actionPosX = player.data.x; player.data.actionPosY = player.data.y + MAP_SIZE; }//��
	if (player.data.muki == 1) { player.data.actionPosX = player.data.x - MAP_SIZE; player.data.actionPosY = player.data.y; }//��
	if (player.data.muki == 2) { player.data.actionPosX = player.data.x + MAP_SIZE; player.data.actionPosY = player.data.y; }//�E
	if (player.data.muki == 3) { player.data.actionPosX = player.data.x; player.data.actionPosY = player.data.y - MAP_SIZE; }//��
	if (player.data.muki == 4) { player.data.actionPosX = player.data.x + MAP_SIZE; player.data.actionPosY = player.data.y - MAP_SIZE; }//�E��
	if (player.data.muki == 5) { player.data.actionPosX = player.data.x + MAP_SIZE; player.data.actionPosY = player.data.y + MAP_SIZE; }//�E��
	if (player.data.muki == 6) { player.data.actionPosX = player.data.x - MAP_SIZE; player.data.actionPosY = player.data.y - MAP_SIZE; }//����
	if (player.data.muki == 7) { player.data.actionPosX = player.data.x - MAP_SIZE; player.data.actionPosY = player.data.y + MAP_SIZE; }//����
																																		//���ƂŖ߂�l����̊֐����������ق�����������	

}

void keyPushManage() {
	/*
	//�U���̊Ǘ�
	if (keyBuffer[KEY_INPUT_Z] == 1) {
		player.data.attack_flag = 1;//�U���t���O�𗧂Ă�
		player.data.walking_flag = 0;
	}
	*/
	


	

	//�ړ��̊Ǘ�
	//�\���ړ��@�@�@�u���v�u���v�u���v�u���v�̏�
	if (keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0 && keyBuffer[KEY_INPUT_C] == 0)player.data.muki = 0;
	else if (keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0 && keyBuffer[KEY_INPUT_C] == 0)player.data.muki = 1;  //���{�^���������ꂽ�獶�����t���O�𗧂Ă�
	else if (keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0 && keyBuffer[KEY_INPUT_C] == 0)player.data.muki = 2;//�E�{�^���������ꂽ��E�����t���O�𗧂Ă�
	else if (keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0 && keyBuffer[KEY_INPUT_C] == 0)player.data.muki = 3;//��{�^���������ꂽ�������t���O�𗧂Ă�
																																  //�΂߈ړ�		�u�E��v�u�E���v�u����v�u�����v�̏�
	else if (keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1 && keyBuffer[KEY_INPUT_C] == 0)player.data.muki = 4;//�E��{�^���������ꂽ�������t���O�𗧂Ă�
	else if (keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1 && keyBuffer[KEY_INPUT_C] == 0)player.data.muki = 5;//�E���{�^���������ꂽ�������t���O�𗧂Ă�
	else if (keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1 && keyBuffer[KEY_INPUT_C] == 0)player.data.muki = 6;//����{�^���������ꂽ�������t���O�𗧂Ă�
	else if (keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1 && keyBuffer[KEY_INPUT_C] == 0)player.data.muki = 7;//�����{�^���������ꂽ�������t���O�𗧂Ă�
																																									  //���̏�����]���̊Ǘ�
																																									  //�\�������ϊ��@�@�@�u���v�u���v�u���v�u���v�̏�
	else if (keyBuffer[KEY_INPUT_C] == 1 && keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0) player.data.muki = 0, player.data.walking_flag = 0, player.data.nextWalking_flag = 0;//���Ɍ���
	else if (keyBuffer[KEY_INPUT_C] == 1 && keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0) player.data.muki = 1, player.data.walking_flag = 0, player.data.nextWalking_flag = 0;//���Ɍ���
	else if (keyBuffer[KEY_INPUT_C] == 1 && keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0) player.data.muki = 2, player.data.walking_flag = 0, player.data.nextWalking_flag = 0;//�E�Ɍ���
	else if (keyBuffer[KEY_INPUT_C] == 1 && keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0) player.data.muki = 3, player.data.walking_flag = 0, player.data.nextWalking_flag = 0;//��Ɍ���
																																																   //�΂ߌ����]��		�u�E��v�u�E���v�u����v�u�����v�̏�
	else if (keyBuffer[KEY_INPUT_C] == 1 && keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1) player.data.muki = 4, player.data.walking_flag = 0, player.data.nextWalking_flag = 0;//�E��Ɍ���
	else if (keyBuffer[KEY_INPUT_C] == 1 && keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1) player.data.muki = 5, player.data.walking_flag = 0, player.data.nextWalking_flag = 0;//�E���Ɍ���
	else if (keyBuffer[KEY_INPUT_C] == 1 && keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1) player.data.muki = 6, player.data.walking_flag = 0, player.data.nextWalking_flag = 0;//����Ɍ���
	else if (keyBuffer[KEY_INPUT_C] == 1 && keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1) player.data.muki = 7, player.data.walking_flag = 0, player.data.nextWalking_flag = 0;//�����Ɍ���
	else {
		player.data.walking_flag = 0;//���̃{�^����������ĂȂ���������s�t���OOFF
		player.data.nextWalking_flag = 0;
	}
}

void getPlayerActState() {//�v���C���[���������Ă��Ȃ��B�ړ����@�ȂǂƂ����X�e�[�g���擾����֐�
	/*
	if (player.data.walking_flag == 0 && player.data.attack_flag == 0)player.state.actState = noState;//�v���C���[�̓��͑҂��̏�ԁinoState�j
	if (player.data.walking_flag == 1 && player.data.attack_flag == 0) {
		if (player.data.x % MAP_SIZE != 0 || player.data.y % MAP_SIZE != 0)player.state.actState = move_Now;//�v���C���[�̍��W���s�b�^���łȂ������ꍇ�ړ����Ă���Œ�(move_Now)�̏��
	}
	*/
}


