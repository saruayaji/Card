#include "GV.h"


void attackUpdatePlayer(int x, int y, int muki) {//���b�ԍU���X�V���������Ă��邩�i�A�j���[�V������SE�ɍ��킹��time��ς���j
	normalAttack.time++;
	if (normalAttack.time == 1) {

		for (int i = 0; i < ENEMY_NUM; i++) {
			if (player.data.actionPosX == enemy[i].data.x && player.data.actionPosY == enemy[i].data.y && enemy[i].state.deadOrAlive == ALIVE) {//�O�iactionPos�j�ɓG������Ȃ�
				if (player.status.ATK <= enemy[i].status.DFE) { enemy[i].status.HP -= 0; }//�v���C���[�̍U���� �� �G�̖h��́@�̏ꍇ�@�^�_����0�ƂȂ�B
				
				else enemy[i].status.HP -= player.status.ATK - enemy[i].status.DFE;//����ȊO�iATK>DFE�̏ꍇ�j�^�_���@���@��ATK - �GDFE�@
				if (enemy[i].status.HP <= 0) {//�G��|������
					player.status.EXP += enemy[i].status.EXP;
					enemy[i].state.deadOrAlive = DEAD;
				}
			}
		}


	}

	if (normalAttack.time == 32) {
		player.data.attack_flag = 0, normalAttack.time = 0;
		player.state.actState = act_End;//normalAttack.time(�U�����[�V��������)���I�������v���C���[�̍U�����I���iact_End�j�Ƃ���
		player.data.turn++;//�v���C���[�̃^�[���I���
	}
	else {
		player.data.walking_flag = 0;
		player.state.actState = act_Now;//normalAttack.time(�U�����[�V��������)���I����Ă��Ȃ�������v���C���[�̍U���r���iact_Now�j�Ƃ���
	}

}