#include "GV.h"
#include <string>
#define DAMEGEmes 0

void drawMessage(int type) {
	if (type == DAMEGEmes) {
		DrawFormatString(str.x, str.y, Cr[1] = GetColor(255, 0, 0), "%s��%d�_���[�W��^����", enemy[3].name, player.status.ATK);

	if (str.y >= 480) { str.y = 200;}
	else { str.y+=2; }

	}
}

//�U�����b�Z�[�W�Ɣ�U�����b�Z���ƂɈ�����ς���char�𕶎��o�͂���̂͂ǂ����B�v���C���[��G�ɖ��O�ichar�j����邱�Ƃɂ͂Ȃ�