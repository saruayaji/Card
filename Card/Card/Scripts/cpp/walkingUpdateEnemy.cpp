#include "../h/GV.h"

void walkingUpdateEnemy(int i, int muki) {
	/*�������ɑ������ړ��Ǘ�*/
	if (enemyChara[i].data.walking_flag == 1) {//���s�t���O��ON�Ȃ�
		switch (muki) {
		case 0:
			enemyChara[i].data.y++;//�������Ȃ�ch.y���W�𑝂₷
			break;
		case 1:
			enemyChara[i].data.x--;//�������Ȃ�ch.x���W�����炷
			break;
		case 2:
			enemyChara[i].data.x++; //�E�����Ȃ�ch.x���W�𑝂₷
			break;
		case 3:
			enemyChara[i].data.y--;//������Ȃ�ch.y���W�����炷
			break;
		case 4:
			enemyChara[i].data.y--;//�E������Ȃ�ch.y���W�����炷
			enemyChara[i].data.x++;
			break;
		case 5:
			enemyChara[i].data.y++;//�E�������Ȃ�ch.y���W�����炷
			enemyChara[i].data.x++;
			break;
		case 6:
			enemyChara[i].data.y--;//��������Ȃ�ch.y���W�����炷
			enemyChara[i].data.x--;
			break;
		case 7:
			enemyChara[i].data.y++;//���������Ȃ�ch.y���W�����炷
			enemyChara[i].data.x--;
			break;
		}
	}



}