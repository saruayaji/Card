#include "../h/GV.h"


//�����ۂɍ��W�������ɉ����ĕω�������
void walkingUpdatePlayer(int muki) {
	switch (muki) {
	case 0:

		player.data.y+=4;//�������Ȃ�ch.y���W�𑝂₷				32�̔{������Ŏ�l���̕��s���xUP
		break;
	case 1:
		player.data.x-= 4;//�������Ȃ�ch.x���W�����炷
		break;
	case 2:
		player.data.x+= 4; //�E�����Ȃ�ch.x���W�𑝂₷
		break;
	case 3:
		player.data.y-= 4;//������Ȃ�ch.y���W�����炷
		break;
	case 4:
		player.data.y-= 4;//�E������Ȃ�ch.y���W�����炷
		player.data.x+= 4;
		break;
	case 5:
		player.data.y+= 4;//�E�������Ȃ�ch.y���W�����炷
		player.data.x+= 4;
		break;
	case 6:
		player.data.y-= 4;//��������Ȃ�ch.y���W�����炷
		player.data.x-= 4;
		break;
	case 7:
		player.data.y+= 4;//���������Ȃ�ch.y���W�����炷
		player.data.x-= 4;
		break;
	}
}
