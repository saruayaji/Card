#include "../h/GV.h"


//�Q�[�����̃��j���[��ʂȂ�
void drawMyCharaMenu() {

	//���j���[���̘g��`��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawBox(500, 40, 638, 240, Cr[0] = GetColor(0, 80, 150), TRUE);
	DrawBox(500, 40, 639, 240, Cr[1] = GetColor(255, 255, 250), FALSE);
	//DrawBox(400, 300, 630, 470, Cr[0] = GetColor(0, 80, 150), TRUE);
	//DrawBox(400, 300, 630, 470, Cr[1] = GetColor(255, 255, 250), FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	/*
	//������\��
	DrawFormatString(210, 40, Cr[1] = GetColor(255, 0, 0), "SP%d/%d ", player.status.SP, player.status.MAXSP);
	DrawFormatString(110, 442, Cr[1] = GetColor(255, 0, 0), "EXP  %d/%d ", player.status.EXP, player.status.MAXEXP);
	DrawFormatString(20, 310, Cr[1] = GetColor(0, 255, 0), "ATK%d DFE%d", player.status.ATK, player.status.DFE);
	*/
	//select������			
	DrawString(player.select.openMyCharaMenuPointX, player.select.openMyCharaMenuPointY, "��", Cr[0] = (0, 0, 0));
	DrawString(520, 50, "�ړ�", Cr[0] = (0, 0, 0));
	DrawString(520, 70, "�X�L��", Cr[0] = (0, 0, 0));
	DrawString(520, 90, "�X�e�[�g", Cr[0] = (0, 0, 0));
	DrawString(520, 110, "�}�b�v�U��", Cr[0] = (0, 0, 0));
	DrawString(520, 130, "�A�C�e��", Cr[0] = (0, 0, 0));
	DrawString(520, 150, "����", Cr[0] = (0, 0, 0));
	DrawString(520, 170, "�H", Cr[0] = (0, 0, 0));
	DrawString(520, 190, "�x��", Cr[0] = (0, 0, 0));


}


