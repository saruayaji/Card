#include "../h/GV.h"

//���i�߂邩�ǂ������������B
int isAbleToGo(int index, int x, int y, int muki) {//�i�߂邩�𔻒肷��

	if (stage00.Switch == ON) {			//���X�e�[�W�O�O�ɂ�����
		switch (muki) {
		case 0:

			for (int i = 0; i < ENEMY_NUM; i++) {//�v���C���[�̈ړ���ɓG��������
				if ((myChara[index].data.x == enemyChara[i].data.x) && (myChara[index].data.y + MAP_SIZE == enemyChara[i].data.y) && (enemyChara[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (stage00.tipData[y / MAP_SIZE + 1][x / MAP_SIZE] == 1 || stage00.tipData[y / MAP_SIZE + 1][x / MAP_SIZE] == 39) {
				if (myChara[index].data.nextWalking_flag == 1) {//nextPoint����x�����X�V
					myChara[index].data.nextPosY += MAP_SIZE;
					myChara[index].data.nextWalking_flag = 0;
				}
				return 1;//�������悪�P�܂��͂R�X�Ői�߂�Ȃ�P��Ԃ�
			}
			break;

		case 1:

			for (int i = 0; i < ENEMY_NUM; i++) {//�v���C���[�̈ړ���ɓG��������
				if ((myChara[index].data.x - MAP_SIZE == enemyChara[i].data.x) && (myChara[index].data.y == enemyChara[i].data.y) && (enemyChara[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (x / MAP_SIZE - 1 < 0)return 0;
			if (stage00.tipData[y / MAP_SIZE][x / MAP_SIZE - 1] == 1 || stage00.tipData[y / MAP_SIZE][x / MAP_SIZE - 1] == 39) {
				if (myChara[index].data.nextWalking_flag == 1) {//nextPoint����x�����X�V
					myChara[index].data.nextPosX -= MAP_SIZE;
					myChara[index].data.nextWalking_flag = 0;
				}

				return 1;//�������悪�P�܂��͂R�X�Ői�߂�Ȃ�P��Ԃ�
			}
			break;

		case 2:

			for (int i = 0; i < ENEMY_NUM; i++) {//�v���C���[�̈ړ���ɓG��������
				if ((myChara[index].data.x + MAP_SIZE == enemyChara[i].data.x) && (myChara[index].data.y == enemyChara[i].data.y) && (enemyChara[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (stage00.tipData[y / MAP_SIZE][x / MAP_SIZE + 1] == 1 || stage00.tipData[y / MAP_SIZE][x / MAP_SIZE + 1] == 39) {
				if (myChara[index].data.nextWalking_flag == 1) {//nextPoint����x�����X�V
					myChara[index].data.nextPosX += MAP_SIZE;
					myChara[index].data.nextWalking_flag = 0;
				}
				return 1;//�������悪�P�܂��͂R�X�Ői�߂�Ȃ�P��Ԃ�
			}
			break;
		case 3:

			for (int i = 0; i < ENEMY_NUM; i++) {//�v���C���[�̈ړ���ɓG��������
				if ((myChara[index].data.x == enemyChara[i].data.x) && (myChara[index].data.y - MAP_SIZE == enemyChara[i].data.y) && (enemyChara[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (stage00.tipData[y / MAP_SIZE - 1][x / MAP_SIZE] == 1 || stage00.tipData[y / MAP_SIZE - 1][x / MAP_SIZE] == 39) {
				if (myChara[index].data.nextWalking_flag == 1) {//nextPoint����x�����X�V
					myChara[index].data.nextPosY -= MAP_SIZE;
					myChara[index].data.nextWalking_flag = 0;
				}
				return 1;//�������悪�P�܂��͂R�X�Ői�߂�Ȃ�P��Ԃ�
			}
			break;
		case 4:

			for (int i = 0; i < ENEMY_NUM; i++) {//�v���C���[�̈ړ���i���̍��E�j�ɓG��������
				if (((myChara[index].data.x + MAP_SIZE == enemyChara[i].data.x) && (myChara[index].data.y - MAP_SIZE == enemyChara[i].data.y) && (enemyChara[i].state.deadOrAlive == ALIVE))
					|| ((myChara[index].data.x + MAP_SIZE == enemyChara[i].data.x) && (myChara[index].data.y == enemyChara[i].data.y))
					|| ((myChara[index].data.x == enemyChara[i].data.x) && (myChara[index].data.y - MAP_SIZE == enemyChara[i].data.y))) return 0;
			}
			if (stage00.tipData[y / MAP_SIZE - 1][x / MAP_SIZE + 1] == 1 || stage00.tipData[y / MAP_SIZE - 1][x / MAP_SIZE + 1] == 39) {
				if (myChara[index].data.nextWalking_flag == 1) {//nextPoint����x�����X�V
					myChara[index].data.nextPosX += MAP_SIZE;
					myChara[index].data.nextPosY -= MAP_SIZE;
					myChara[index].data.nextWalking_flag = 0;
				}
				return 1;//�������悪�P�܂��͂R�X�Ői�߂�Ȃ�P��Ԃ�
			}
			break;

		case 5:

			for (int i = 0; i < ENEMY_NUM; i++) {//�v���C���[�̈ړ���i���̍��E�j�ɓG��������
				if (((myChara[index].data.x + MAP_SIZE == enemyChara[i].data.x) && (myChara[index].data.y + MAP_SIZE == enemyChara[i].data.y) && (enemyChara[i].state.deadOrAlive == ALIVE))
					|| ((myChara[index].data.x + MAP_SIZE == enemyChara[i].data.x) && (myChara[index].data.y == enemyChara[i].data.y))
					|| ((myChara[index].data.x == enemyChara[i].data.x) && (myChara[index].data.y + MAP_SIZE == enemyChara[i].data.y))) return 0;
			}
			if (stage00.tipData[y / MAP_SIZE + 1][x / MAP_SIZE + 1] == 1 || stage00.tipData[y / MAP_SIZE + 1][x / MAP_SIZE + 1] == 39) {
				if (myChara[index].data.nextWalking_flag == 1) {//nextPoint����x�����X�V
					myChara[index].data.nextPosX += MAP_SIZE;
					myChara[index].data.nextPosY += MAP_SIZE;
					myChara[index].data.nextWalking_flag = 0;
				}
				return 1;//�������悪�P�܂��͂R�X�Ői�߂�Ȃ�P��Ԃ�
			}
			break;
		case 6:

			for (int i = 0; i < ENEMY_NUM; i++) {//�v���C���[�̈ړ���i���̍��E�j�ɓG��������
				if (((myChara[index].data.x - MAP_SIZE == enemyChara[i].data.x) && (myChara[index].data.y - MAP_SIZE == enemyChara[i].data.y) && (enemyChara[i].state.deadOrAlive == ALIVE))
					|| ((myChara[index].data.x - MAP_SIZE == enemyChara[i].data.x) && (myChara[index].data.y == enemyChara[i].data.y))
					|| ((myChara[index].data.x == enemyChara[i].data.x) && (myChara[index].data.y - MAP_SIZE == enemyChara[i].data.y))) return 0;
			}
			if (stage00.tipData[y / MAP_SIZE - 1][x / MAP_SIZE - 1] == 1 || stage00.tipData[y / MAP_SIZE - 1][x / MAP_SIZE - 1] == 39) {
				if (myChara[index].data.nextWalking_flag == 1) {//nextPoint����x�����X�V
					myChara[index].data.nextPosX -= MAP_SIZE;
					myChara[index].data.nextPosY -= MAP_SIZE;
					myChara[index].data.nextWalking_flag = 0;
				}
				return 1;//�������悪�P�܂��͂R�X�Ői�߂�Ȃ�P��Ԃ�
			}
			break;
		case 7:

			for (int i = 0; i < ENEMY_NUM; i++) {//�v���C���[�̈ړ���i���̍��E�j�ɓG��������
				if (((myChara[index].data.x - MAP_SIZE == enemyChara[i].data.x) && (myChara[index].data.y + MAP_SIZE == enemyChara[i].data.y) && (enemyChara[i].state.deadOrAlive == ALIVE))
					|| ((myChara[index].data.x - MAP_SIZE == enemyChara[i].data.x) && (myChara[index].data.y == enemyChara[i].data.y))
					|| ((myChara[index].data.x == enemyChara[i].data.x) && (myChara[index].data.y + MAP_SIZE == enemyChara[i].data.y))) return 0;
			}
			if (stage00.tipData[y / MAP_SIZE + 1][x / MAP_SIZE - 1] == 1 || stage00.tipData[y / MAP_SIZE + 1][x / MAP_SIZE - 1] == 39) {
				if (myChara[index].data.nextWalking_flag == 1) {//nextPoint����x�����X�V
					myChara[index].data.nextPosX -= MAP_SIZE;
					myChara[index].data.nextPosY += MAP_SIZE;
					myChara[index].data.nextWalking_flag = 0;
				}
				return 1;//�������悪�P�܂��͂R�X�Ői�߂�Ȃ�P��Ԃ�
			}
			break;

		}
		return 0;//�i�߂Ȃ��ꍇ0��Ԃ�

	}

	else
		DrawString(300, 150, "stage00���n�m�ɂȂ��ĂȂ����[", GetColor(255, 0, 0));
	return 0;
	//���̃X�e�[�W�ɕς�����Ƃ������̂ŏ�Ɠ����悤��stage00�����ς��Ĕ���



}