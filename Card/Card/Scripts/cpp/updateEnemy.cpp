
#include "GV.h"

//�G�̍X�V����
void updateEnemy() {


	int i = 0;
	while (i < ENEMY_NUM) {//�G�̐l���J��Ԃ�

		if (enemy[i].data.x % MAP_SIZE == 0 && enemy[i].data.y % MAP_SIZE == 0) {//���W��32�Ŋ���؂ꂽ����͉\(�}�X�Ƃ��ĊǗ����Ă��邽��)
			enemy[i].data.walking_flag = 1;//��悸���s�t���OON
			enemy[i].data.nextWalking_flag = 1;


			if (EnemyIsAbleToGo(enemy[i].data.x, enemy[i].data.y, enemy[i].data.muki, i) == 0)continue;//enemy[i].data.walking_flag = 0;//�ړ����悤�Ƃ����s�悪�ǂ̂Ƃ��Ăї������擾����
			else if (EnemyIsAbleToGo(enemy[i].data.x, enemy[i].data.y, enemy[i].data.muki, i) == 2) continue;//�ړ����悤�Ƃ����s�悪�v���C���[�̈ړ����悤���}�X�̂Ƃ��Ăї������擾����

		}
		walkingUpdateEnemy(i, enemy[i].data.muki);

		i++;
	}

}

void decideAction() {
	int i = 0;
	while (i < ENEMY_NUM) {//�G�̐l���J��Ԃ�
		if (enemy[i].data.x % MAP_SIZE == 0 && enemy[i].data.y % MAP_SIZE == 0 && enemy[i].state.deadOrAlive == ALIVE) {//���W��32�Ŋ���؂ꂽ����͉\(�}�X�Ƃ��ĊǗ����Ă��邽��)
			int muki = enemy[i].data.muki;//�G�̌�����ۑ����Ă���
			enemy[i].data.walking_flag = 1;//��悸���s�t���OON
			enemy[i].data.nextWalking_flag = 1;

			enemy[i].data.muki = moveroot(enemy[i].data.x, enemy[i].data.y, player.data.nextPosX, player.data.nextPosY,enemy[i].data.muki);//moveroot���g���Ĉړ����U�����𔻒�

			if (enemy[i].data.muki / 10 == 1) {//moveroot��10�`19�̏ꍇ�A�U���t���O�𗧂Ă�
				enemy[i].data.walking_flag = 0;
				enemy[i].data.attack_flag = 1;
				

			}
			else { //����ȊO�͈ړ��t���O�𗧂Ă�
				enemy[i].data.walking_flag = 1;
				enemy[i].data.attack_flag = 0;
			}
			enemy[i].data.muki %= 10;//2���ɂȂ���muki�����������̏��ɖ߂�
			if (enemy[i].data.walking_flag == 1) {
				if (EnemyIsAbleToGo(enemy[i].data.x, enemy[i].data.y, enemy[i].data.muki, i) == 0)enemy[i].data.walking_flag = 0;//�ړ����悤�Ƃ����s�悪�ǂ̂Ƃ��Ăї������擾����
				else if (EnemyIsAbleToGo(enemy[i].data.x, enemy[i].data.y, enemy[i].data.muki, i) == 2) enemy[i].data.attack_flag = 1;//�ړ����悤�Ƃ����s�悪�v���C���[�̈ړ����悤���}�X�̂Ƃ��Ăї������擾����
			}



			/*
			if (enemy[i].data.muki == 10) {
			enemy[i].data.walking_flag = 0;
			enemy[i].data.attack_flag = 1;

			}
			else {
			enemy[i].data.walking_flag = 1;
			enemy[i].data.attack_flag = 0;
			}

			if (enemy[i].data.walking_flag == 1) {
			if (EnemyIsAbleToGo(enemy[i].data.x, enemy[i].data.y, enemy[i].data.muki, i) == 0)enemy[i].data.walking_flag = 0;//�ړ����悤�Ƃ����s�悪�ǂ̂Ƃ��Ăї������擾����
			else if (EnemyIsAbleToGo(enemy[i].data.x, enemy[i].data.y, enemy[i].data.muki, i) == 2) enemy[i].data.attack_flag = 1;//�ړ����悤�Ƃ����s�悪�v���C���[�̈ړ����悤���}�X�̂Ƃ��Ăї������擾����
			}
			
			*/
		}
		i++;
	}

}

int decideDirection(int enemyX, int enemyY, int playerX, int playerY, int enemymuki,int i) {//�G�iNPC�j������������ύX�B�v���C���[�̕����������i�g�����킩��Ȃ����ꉞ�j
	int enemyToPlayerX = playerX - enemyX;//�G����v���C���[�܂ł�X�̋���
	int enemyToPlayerY = playerY - enemyY;//�G����v���C���[�܂ł�Y�̋���

	int returndata = 0;
	if (enemyToPlayerX >= MAP_SIZE && enemyToPlayerY >= MAP_SIZE)returndata += 5;  // + +   �E���Ɉړ�
	else if (enemyToPlayerX >= MAP_SIZE && enemyToPlayerY <= -MAP_SIZE)returndata += 4; // + -   �E��Ɉړ�
	else if (enemyToPlayerX <= -MAP_SIZE && enemyToPlayerY >= MAP_SIZE)returndata += 7; // - +   �����Ɉړ�
	else if (enemyToPlayerX <= -MAP_SIZE && enemyToPlayerY <= -MAP_SIZE)returndata += 6;// - -   ����Ɉړ�
	else if (enemyToPlayerX >= MAP_SIZE)returndata += 2;// +    �E�Ɉړ�
	else if (enemyToPlayerX <= -MAP_SIZE)returndata += 1;// +    ���Ɉړ�
	else if (enemyToPlayerY >= MAP_SIZE)returndata += 0;// +    ���Ɉړ�
	else if (enemyToPlayerY <= -MAP_SIZE)returndata += 3;// +    ��Ɉړ�
	
	return returndata;
}

int moveroot(int enemyX, int enemyY, int playerX, int playerY,int enemymuki) {//�U�����ړ�����G�ƃv���C���[�̍��W�����Ŕ��f����
	int enemyToPlayerX = playerX - enemyX;//�G����v���C���[�܂ł�X�̋���
	int enemyToPlayerY = playerY - enemyY;//�G����v���C���[�܂ł�Y�̋���

	int returndata = 0;

	if ((abs(enemyToPlayerX) <= MAP_SIZE) && (abs(enemyToPlayerY) <= MAP_SIZE))returndata+=10; //�אڂ����ꍇ�U���ŕԂ� 10++

	if		(enemyToPlayerX >= MAP_SIZE && enemyToPlayerY >= MAP_SIZE)returndata+=5;  // + +   �E���Ɉړ�
	else if (enemyToPlayerX >= MAP_SIZE && enemyToPlayerY <= -MAP_SIZE)returndata += 4; // + -   �E��Ɉړ�
	else if (enemyToPlayerX <= -MAP_SIZE && enemyToPlayerY >= MAP_SIZE)returndata += 7; // - +   �����Ɉړ�
	else if (enemyToPlayerX <= -MAP_SIZE && enemyToPlayerY <= -MAP_SIZE)returndata += 6;// - -   ����Ɉړ�
	else if (enemyToPlayerX >= MAP_SIZE)returndata += 2;// +    �E�Ɉړ�
	else if (enemyToPlayerX <= -MAP_SIZE)returndata += 1;// +    ���Ɉړ�
	else if (enemyToPlayerY >= MAP_SIZE)returndata += 0;// +    ���Ɉړ�
	else if (enemyToPlayerY <= -MAP_SIZE)returndata += 3;// +    ��Ɉړ�
	
	return returndata;

}