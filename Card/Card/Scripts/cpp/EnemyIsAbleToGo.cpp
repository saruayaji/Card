#include "GV.h"

//���G���i�߂邩�ǂ������������B
int EnemyIsAbleToGo(int x, int y, int muki, int This) {//�i�߂邩�𔻒肷��

	if (stage00.Switch == ON) {			//���X�e�[�W�O�O�ɂ�����
		switch (muki) {
		case 0:
			for (int i = 0; i < ENEMY_NUM; i++) {//�s����ɑ��̃����X�^�[��������i�܂Ȃ�
				if ((x == enemy[i].data.nextPosX) && (y + MAP_SIZE == enemy[i].data.nextPosY) && (enemy[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (stage00.tipData[y / MAP_SIZE + 1][x / MAP_SIZE] == 1 || stage00.tipData[y / MAP_SIZE + 1][x / MAP_SIZE] == 39) {
				if (x == player.data.nextPosX && y + MAP_SIZE == player.data.nextPosY)return 0;//�v���C���[�̍s�����Ƃ��Ă���}�X�Ɉړ��͂ł��Ȃ�
				if (enemy[This].data.nextWalking_flag == 1) {//�G�l�~�[��nextPos����x�����X�V
					enemy[This].data.nextPosY += MAP_SIZE;
					enemy[This].data.nextWalking_flag = 0;
				}
				return 1;//�������悪�P�܂��͂R�X�Ői�߂�Ȃ�P��Ԃ�
			}
			break;
		case 1:
			for (int i = 0; i < ENEMY_NUM; i++) {//�s����ɑ��̃����X�^�[��������i�܂Ȃ�
				if ((x - MAP_SIZE == enemy[i].data.nextPosX) && (y == enemy[i].data.nextPosY) && (enemy[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (x / MAP_SIZE - 1 < 0)return 0;
			if (stage00.tipData[y / MAP_SIZE][x / MAP_SIZE - 1] == 1 || stage00.tipData[y / MAP_SIZE][x / MAP_SIZE - 1] == 39) {
				if (x - MAP_SIZE == player.data.nextPosX && y == player.data.nextPosY)return 0;//�v���C���[�̍s�����Ƃ��Ă���}�X�Ɉړ��͂ł��Ȃ�
				if (enemy[This].data.nextWalking_flag == 1) {//�G�l�~�[��nextPos����x�����X�V
					enemy[This].data.nextPosX -= MAP_SIZE;
					enemy[This].data.nextWalking_flag = 0;
				}
				return 1;//�������悪�P�܂��͂R�X�Ői�߂�Ȃ�P��Ԃ�
			}
			break;
		case 2:
			for (int i = 0; i < ENEMY_NUM; i++) {//�s����ɑ��̃����X�^�[��������i�܂Ȃ�
				if ((x + MAP_SIZE == enemy[i].data.nextPosX) && (y == enemy[i].data.nextPosY) && (enemy[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (stage00.tipData[y / MAP_SIZE][x / MAP_SIZE + 1] == 1 || stage00.tipData[y / MAP_SIZE][x / MAP_SIZE + 1] == 39) {
				if (x + MAP_SIZE == player.data.nextPosX && y == player.data.nextPosY)return 0;//�v���C���[�̍s�����Ƃ��Ă���}�X�Ɉړ��͂ł��Ȃ�
				if (enemy[This].data.nextWalking_flag == 1) {//�G�l�~�[��nextPos����x�����X�V
					enemy[This].data.nextPosX += MAP_SIZE;
					enemy[This].data.nextWalking_flag = 0;
				}
				return 1;//�������悪�P�܂��͂R�X�Ői�߂�Ȃ�P��Ԃ�
			}
			break;
		case 3:
			for (int i = 0; i < ENEMY_NUM; i++) {//�s����ɑ��̃����X�^�[��������i�܂Ȃ�
				if ((x == enemy[i].data.nextPosX) && (y - MAP_SIZE == enemy[i].data.nextPosY) && (enemy[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (stage00.tipData[y / MAP_SIZE - 1][x / MAP_SIZE] == 1) {
				if (x == player.data.nextPosX && y - MAP_SIZE == player.data.nextPosY)return 0;//�v���C���[�̍s�����Ƃ��Ă���}�X�Ɉړ��͂ł��Ȃ�
				if (enemy[This].data.nextWalking_flag == 1) {//�G�l�~�[��nextPos����x�����X�V
					enemy[This].data.nextPosY -= MAP_SIZE;
					enemy[This].data.nextWalking_flag = 0;
				}
				return 1;//�������悪�P�܂��͂R�X�Ői�߂�Ȃ�P��Ԃ�
			}
			break;

		case 4:
			for (int i = 0; i < ENEMY_NUM; i++) {//�s����ƍs����̍��E�ɑ��̃����X�^�[��������i�܂Ȃ�
				if ((((x + MAP_SIZE == enemy[i].data.nextPosX) && (y - MAP_SIZE == enemy[i].data.nextPosY))
					|| ((x + MAP_SIZE == enemy[i].data.nextPosX) && (y == enemy[i].data.nextPosY))
					|| ((x == enemy[i].data.nextPosX) && (y - MAP_SIZE == enemy[i].data.nextPosY))) && (enemy[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (stage00.tipData[y / MAP_SIZE - 1][x / MAP_SIZE + 1] == 1) {
				if ((x + MAP_SIZE == player.data.nextPosX && y - MAP_SIZE == player.data.nextPosY)//�v���C���[�̍s�����Ƃ��Ă���}�X�i���̍��E�j�Ɉړ��͂ł��Ȃ�
					|| (x + MAP_SIZE == player.data.nextPosX && y == player.data.nextPosY)
					|| (x == player.data.nextPosX) && (y - MAP_SIZE == player.data.nextPosY))return 0;
				if (enemy[This].data.nextWalking_flag == 1) {//�G�l�~�[��nextPos����x�����X�V
					enemy[This].data.nextPosX += MAP_SIZE;
					enemy[This].data.nextPosY -= MAP_SIZE;
					enemy[This].data.nextWalking_flag = 0;
				}
				return 1;//�������悪�P�܂��͂R�X�Ői�߂�Ȃ�P��Ԃ�
			}
			break;
		case 5:
			for (int i = 0; i < ENEMY_NUM; i++) {//�s����ƍs����̍��E�ɑ��̃����X�^�[��������i�܂Ȃ�
				if ((((x + MAP_SIZE == enemy[i].data.nextPosX) && (y + MAP_SIZE == enemy[i].data.nextPosY))
					|| ((x + MAP_SIZE == enemy[i].data.nextPosX) && (y == enemy[i].data.nextPosY))
					|| ((x == enemy[i].data.nextPosX) && (y + MAP_SIZE == enemy[i].data.nextPosY))) && (enemy[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (stage00.tipData[y / MAP_SIZE + 1][x / MAP_SIZE + 1] == 1) {
				if ((x + MAP_SIZE == player.data.nextPosX && y + MAP_SIZE == player.data.nextPosY)//�v���C���[�̍s�����Ƃ��Ă���}�X�i���̍��E�j�Ɉړ��͂ł��Ȃ�
					|| (x + MAP_SIZE == player.data.nextPosX && y == player.data.nextPosY)
					|| (x == player.data.nextPosX) && (y + MAP_SIZE == player.data.nextPosY))return 0;
				if (enemy[This].data.nextWalking_flag == 1) {//�G�l�~�[��nextPos����x�����X�V
					enemy[This].data.nextPosX += MAP_SIZE;
					enemy[This].data.nextPosY += MAP_SIZE;
					enemy[This].data.nextWalking_flag = 0;
				}
				return 1;//�������悪�P�܂��͂R�X�Ői�߂�Ȃ�P��Ԃ�
			}
			break;
		case 6:
			for (int i = 0; i < ENEMY_NUM; i++) {//�s����ƍs����̍��E�ɑ��̃����X�^�[��������i�܂Ȃ�
				if ((((x - MAP_SIZE == enemy[i].data.nextPosX) && (y - MAP_SIZE == enemy[i].data.nextPosY))
					|| ((x - MAP_SIZE == enemy[i].data.nextPosX) && (y == enemy[i].data.nextPosY))
					|| ((x == enemy[i].data.nextPosX) && (y - MAP_SIZE == enemy[i].data.nextPosY))) && (enemy[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (stage00.tipData[y / MAP_SIZE - 1][x / MAP_SIZE - 1] == 1) {
				if ((x - MAP_SIZE == player.data.nextPosX && y - MAP_SIZE == player.data.nextPosY)//�v���C���[�̍s�����Ƃ��Ă���}�X�i���̍��E�j�Ɉړ��͂ł��Ȃ�
					|| (x - MAP_SIZE == player.data.nextPosX && y == player.data.nextPosY)
					|| (x == player.data.nextPosX) && (y - MAP_SIZE == player.data.nextPosY))return 0;
				if (enemy[This].data.nextWalking_flag == 1) {//�G�l�~�[��nextPos����x�����X�V
					enemy[This].data.nextPosX -= MAP_SIZE;
					enemy[This].data.nextPosY -= MAP_SIZE;
					enemy[This].data.nextWalking_flag = 0;
				}
				return 1;//�������悪�P�܂��͂R�X�Ői�߂�Ȃ�P��Ԃ�
			}
			break;
		case 7:
			for (int i = 0; i < ENEMY_NUM; i++) {//�s����ƍs����̍��E�ɑ��̃����X�^�[��������i�܂Ȃ�
				if ((((x - MAP_SIZE == enemy[i].data.nextPosX) && (y + MAP_SIZE == enemy[i].data.nextPosY))
					|| ((x - MAP_SIZE == enemy[i].data.nextPosX) && (y == enemy[i].data.nextPosY))
					|| ((x == enemy[i].data.nextPosX) && (y + MAP_SIZE == enemy[i].data.nextPosY))) && (enemy[i].state.deadOrAlive == ALIVE))return 0;
			}
			if (stage00.tipData[y / MAP_SIZE + 1][x / MAP_SIZE - 1] == 1) {
				if ((x - MAP_SIZE == player.data.nextPosX && y + MAP_SIZE == player.data.nextPosY)//�v���C���[�̍s�����Ƃ��Ă���}�X�i���̍��E�j�Ɉړ��͂ł��Ȃ�
					|| (x - MAP_SIZE == player.data.nextPosX && y == player.data.nextPosY)
					|| (x == player.data.nextPosX) && (y + MAP_SIZE == player.data.nextPosY))return 0;
				if (enemy[This].data.nextWalking_flag == 1) {//�G�l�~�[��nextPos����x�����X�V
					enemy[This].data.nextPosX -= MAP_SIZE;
					enemy[This].data.nextPosY += MAP_SIZE;
					enemy[This].data.nextWalking_flag = 0;
				}
				return 1;//�������悪�P�܂��͂R�X�Ői�߂�Ȃ�P��Ԃ�
			}
		}
		return 0;//�i�߂Ȃ��ꍇ0��Ԃ�

	}

	else
		DrawString(300, 150, "stage00���n�m�ɂȂ��ĂȂ����[", GetColor(255, 0, 0));
	return 0;
	//���̃X�e�[�W�ɕς�����Ƃ������̂ŏ�Ɠ����悤��stage00�����ς��Ĕ���



}