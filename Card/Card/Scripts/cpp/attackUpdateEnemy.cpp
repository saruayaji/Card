#include "GV.h"


void attackUpdateEnemy(int x, int y, int muki, int i) {//�U���̍X�V����
	if (player.data.x % MAP_SIZE == 0 && player.data.y % MAP_SIZE == 0 && enemy[i].state.deadOrAlive == ALIVE) {//���W��32�Ŋ���؂ꂽ����͉\(�}�X�Ƃ��ĊǗ����Ă��邽��)
		player.status.HP -= 10;
	}


}
