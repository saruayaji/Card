#include "../h/GV.h"

// ---------------------------------------- �`�揈�� ----------------------------------------

void draw() {
	// ��ʂ���������
	ClearDrawScreen();
	switch (mainState) {
	case TITLE:
		// �^�C�g���̕`��
		drawTitle();
		break;

	case GAME:
		// �Q�[����ʂ̕`��		

		drawMAP(stage00);

		for (int i = 0; i < ENEMY_NUM; i++) {
			if(player.data.y >= enemyChara[i].data.y)drawEnemy(i);//�v���C���[����ɓG������ꍇ�@�v���C���[������ɕ`�悷��
		}
		
		drawMyChara();

		for (int i = 0; i < ENEMY_NUM; i++) {
			if (player.data.y < enemyChara[i].data.y)drawEnemy(i);//�v���C���[��艺�ɓG������ꍇ�@�v���C���[�̌�ɕ`�悷��
		}

		drawPlayer();										//�v���C���[��`�悷��

		drawHeightMap();//MAP�ŏ�ʃ��C���[��t�������ĕ`��
		//drawConsole();//�Q�[��HP�o�[��A�f�o�b�N�R���\�[���̕`��
		//if (gameState == openGameMenu)drawGameMenu();
		objectCollisonDraw();
		break;

	case GAMEOVER:
		// �Q�[���I�[�o�[��ʂ̕`��
		drawGmaOver();
		break;

	case GAMECLEAR:
		// �Q�[���N���A��ʂ̕`��
		drawGameClear();
		break;

	}

	// ��ʂɕ\������
	ScreenFlip();
}

// �^�C�g���̕`��
void drawTitle() {

	DrawGraph(0, 0, backTitle, TRUE); //�摜�̕`��
									  //DrawString(260, 350, "SPACE�L�[�ŊJ�n", GetColor(255, 255, 255));
	DrawString(player.select.titleMenuPointX, player.select.titleMenuPointY, "��", GetColor(255, 255, 0));
	DrawString(300, 300, "�͂��߂�", GetColor(0, 0, 0));
	DrawString(300, 325, "������", GetColor(0, 0, 0));
	DrawString(300, 350, "�I���", GetColor(0, 0, 0));

}

// �Q�[���I�[�o�[�̕`��
void drawGmaOver() {
	DrawString(300, 150, "GAMEOVER", GetColor(255, 0, 0));
	DrawString(260, 350, "SPACE�L�[�ōė��C", GetColor(255, 255, 255));

}

// �Q�[���N���A�̕`��
void drawGameClear() {
	DrawString(300, 150, "GAMECLEAR", GetColor(0, 255, 0));
	DrawString(260, 350, "SPACE�L�[�Ń^�C�g��", GetColor(255, 255, 255));
}


//�@�v���C���[�i�I���W���j�\��
void drawPlayer() {
	switch (player.deadOrAlive) {
	case ALIVE:
		DrawBox(startXpos, startYpos, player.data.nextPosX + MAP_SIZE, player.data.nextPosY + MAP_SIZE, GetColor(255, 0, 0), FALSE);
	
	}

}


// ���L�����̕\��
void drawMyChara() {
	int i = 0;
	while (i < MYCHARA_NUM) {
		switch (myChara[i].state.deadOrAlive) {
		case ALIVE:

			int myCharaXpos = myChara[i].data.x - player.data.x, myCharaYpos = myChara[i].data.y - player.data.y;			//��l���̍��W�ƃ����X�^�[�̍��W�̍�

			if (myChara[i].data.muki == 4 || myChara[i].data.muki == 5)myChara[i].data.img = myChara[i].data.WG[myChara[i].data.x % MAP_SIZE / 8 + 2 * 4];//��l�����΂߈ړ��i�E��A�E���j�̂Ƃ��̉摜�Z�b�g
			else if (myChara[i].data.muki == 6 || myChara[i].data.muki == 7)myChara[i].data.img = myChara[i].data.WG[myChara[i].data.x % MAP_SIZE / 8 + 1 * 4];//��l�����΂߈ړ��i����A�����j�̂Ƃ��̉摜�Z�b�g
			else myChara[i].data.img = myChara[i].data.WG[(myChara[i].data.x % MAP_SIZE + myChara[i].data.y % MAP_SIZE) / 8 + myChara[i].data.muki * 4];//��l���̌������l�������\���ړ��̎�l���̉摜�̃Z�b�g�B

			DrawGraph(startXpos + myCharaXpos, startYpos + myCharaYpos - 18, myChara[i].data.img, TRUE);//��l���̕`��
																		//case DEAD:
		
			i++;
		}
	}
	if (myChara[i].data.attack_flag == 1) {//�U����ԂȂ�
		if (normalAttack.time == 1)
			PlaySound("�Y���� (2).wav", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t


	}
}
// �@�G�̕\��
void drawEnemy(int i) {

		switch (enemyChara[i].state.deadOrAlive) {
		case ALIVE:
			int enemyXpos = enemyChara[i].data.x - player.data.x, enemyYpos = enemyChara[i].data.y - player.data.y;			//��l���̍��W�ƃ����X�^�[�̍��W�̍�

			if      (enemyChara[i].data.muki == 4 || enemyChara[i].data.muki == 5)enemyChara[i].data.img = enemyChara[i].data.WG[enemyChara[i].data.x % MAP_SIZE / 8 + 2 * 4];//��l���̌������l��������l���̉摜�̃Z�b�g�B
			else if (enemyChara[i].data.muki == 6 || enemyChara[i].data.muki == 7)enemyChara[i].data.img = enemyChara[i].data.WG[enemyChara[i].data.x % MAP_SIZE / 8 + 1 * 4];//��l���̌������l��������l���̉摜�̃Z�b�g�B
			else     enemyChara[i].data.img = enemyChara[i].data.WG[(enemyChara[i].data.x % MAP_SIZE + enemyChara[i].data.y % MAP_SIZE) / 8 + enemyChara[i].data.muki * 4];//�����X�^�[�̌������l�����������X�^�[�̉摜�̃Z�b�g�B
			
			DrawGraph(startXpos + enemyXpos, startYpos + enemyYpos - 18, enemyChara[i].data.img, TRUE);//�����X�^�[�̕`��

																								  //case DEAD:
																								  //��
		}	
}



void objectCollisonDraw() {//�v���C���[���I�u�W�F�N�g�ɐڐG�����ۂɕ\�������UI�@�i�X�e�[�^�X�Ȃǂ�\���j
	if (player.collisonFlag == TRUE) {
		
		
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 50);//////////////////////////////////��ⓧ��
		DrawBox(5, 300, 635, 475, GetColor(0, 0, 255), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 130);/////////////////////////////////���\����
		//HP�o�[�̕\��
		DrawBox(200, 340, 200 + WD, 350, GetColor(0, 255, 0), FALSE);//���[�^�[�̘g��`��                                      
		DrawBox(200, 340, 200 + WD* collisonObject.status.HP / collisonObject.status.MAXHP, 350, GetColor(0, 255, 0), TRUE);//���[�^�[�̒��g��`��
		//SP�o�[�̕\��
		DrawBox(200, 380, 200 + WD, 390, GetColor(0, 150, 150), FALSE);//���[�^�[�̘g��`��                                      
		DrawBox(200, 380, 200 + WD* collisonObject.status.MP / collisonObject.status.MAXMP, 390, GetColor(0, 150, 150), TRUE);//���[�^�[�̒��g��`��
		//MP�o�[�̕\��
		DrawBox(200, 360, 200 + WD, 370, GetColor(255, 255, 0), FALSE);//���[�^�[�̘g��`��                                      
		DrawBox(200, 360, 200 + WD* collisonObject.status.SP / collisonObject.status.MAXSP, 370, GetColor(255, 255, 0), TRUE);//���[�^�[�̒��g��`��
		
		

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);///////////////////////////////�����x�O


		DrawGraph(5, 300, collisonObject.data.SG, TRUE);//�����G�̕\��

		
		DrawFormatString(200, 320, Cr[1] = GetColor(255, 255, 255), "%s",collisonObject.data.name);//���O�̕\��

		SetFontSize(10);//�����T�C�Y


		DrawFormatString(355, 340, Cr[1] = GetColor(0, 255, 0), "HP %d / %d", collisonObject.status.HP, collisonObject.status.MAXHP);//HP���l
		DrawFormatString(355, 360, Cr[1] = GetColor(255, 255, 0), "SP %d / %d", collisonObject.status.SP, collisonObject.status.MAXSP);//SP���l
		DrawFormatString(355, 380, Cr[1] = GetColor(255, 255, 255), "MP %d / %d", collisonObject.status.MP, collisonObject.status.MAXMP);//MP���l
		
		DrawFormatString(200, 400, Cr[1] = GetColor(255, 255, 255), "ATK  %d", collisonObject.status.ATK);//ATK���l
		DrawFormatString(200, 415, Cr[1] = GetColor(255, 255, 255), "DFE  %d", collisonObject.status.DFE);//DFE���l
		DrawFormatString(200, 430, Cr[1] = GetColor(255, 255, 255), "INT  %d", collisonObject.status.INT);//INT���l
		DrawFormatString(200, 445, Cr[1] = GetColor(255, 255, 255), "RES  %d", collisonObject.status.RES);//RES���l
		DrawFormatString(200, 460, Cr[1] = GetColor(255, 255, 255), "SPD  %d", collisonObject.status.SPD);//SPD���l
		DrawFormatString(450, 340, Cr[1] = GetColor(255, 255, 255), "���x��  %d", collisonObject.status.level);//���x�����l
		DrawFormatString(450, 355, Cr[1] = GetColor(255, 255, 255), "���A�x  %d", collisonObject.status.rearity);//���x�����l	
		DrawFormatString(450, 370, Cr[1] = GetColor(255, 255, 255), "�E  %d", collisonObject.status.Class);//���x�����l
		DrawFormatString(450, 385, Cr[1] = GetColor(255, 255, 255), "���F�͈�  %d", collisonObject.status.range);//���x�����l
		DrawFormatString(450, 400, Cr[1] = GetColor(255, 255, 255), "�B�؂���  %d", collisonObject.status.hide);//���x�����l
		DrawFormatString(450, 415, Cr[1] = GetColor(255, 255, 255), "�ړ��}�X  %d", collisonObject.status.MS);//���x�����l
		DrawFormatString(450, 460, Cr[1] = GetColor(255, 255, 255), "�R�X�g  %d", collisonObject.status.cost);//���x�����l

		SetFontSize(20);

	}


}
