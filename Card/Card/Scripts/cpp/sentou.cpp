#include "DxLib.h"
#include <stdio.h>
#define WD 300
//�֐��錾
int Damage(int x, int y);																		//�_���[�W
int HiDamage(int x, int y);																		//��_���[�W
void sentou(int HP, int MAXHP, int SP, int MAXSP, int level, int exp, int maxexp, int x);		//�퓬
void GAMEOVER();																				//�Q�[���I�[�o�[	
void win(int getexp, int getmoney, int exp, int maxexp);										//����
int revelup(int exp, int maxexp);																//���x���A�b�v
int Bonus(int revel);																			//���x���A�b�v�{�[�i�X
int zenkaihuku(int hp, int maxhp);																//�S��
int question01suu();																			
int question01ei();
int question02ei();
int question03ei();
int question04ei();
int question05ei();
int question06ei();
int question07ei();
int question08ei();
int question09ei();
int question10ei();
int question11ei();








/////////�y�_���[�W�z///////////////////////////////////////////////////////////////////////////////////////////////
int Damage(int x, int y)
{
	int dame, Cr[5];
	DrawFormatString(265, 280, Cr[1] = GetColor(255, 0, 0), "%d", x - y); // ������`�悷��
	dame = x - y;
	return dame;
}
///////�y��_���[�W�z///////////////////////////////////////////////////////////////////////////////////////////////
int HiDamage(int x, int y)
{
	int hidame, Cr[5];
	DrawFormatString(20, 350, Cr[1] = GetColor(255, 0, 0), "%d", x - y); // ������`�悷��
	hidame = x - y;
	return hidame;
}

//////////�y�퓬�z/////////////////////////////////////////////////////////////////////////////////////		
void sentou(int HP, int MAXHP, int SP, int MAXSP, int revel, int exp, int maxexp, int x)
{
	int menu, nyuuryoku;
	menu = LoadGraph("���j���[00.png");
	nyuuryoku = LoadGraph("���͗�.png");
	int Cr[5];

	DrawGraph(0, 0, menu, TRUE); // �摜��`�悷��
	DrawGraph(260, 450, nyuuryoku, TRUE); // �摜��`�悷��
	DrawBox(172, 335, 172 + WD, 350, GetColor(0, 255, 0), FALSE);//				HP
	DrawBox(172, 335, 172 + WD*HP / MAXHP, 350, GetColor(0, 255, 0), TRUE);//	HP
	DrawBox(172, 370, 172 + WD, 385, GetColor(0, 0, 255), FALSE);//				SP
	DrawBox(172, 370, 172 + WD*SP / MAXSP, 385, GetColor(0, 0, 255), TRUE);//	SP
	DrawBox(172, 405, 172 + WD, 420, GetColor(0, 255, 255), FALSE);//			EXP
	DrawBox(172, 405, 172 + WD*exp / maxexp, 420, GetColor(0, 200, 200), TRUE);//EXP
	DrawFormatString(180, 315, Cr[1] = GetColor(255, 0, 0), "HP%d/%d					level%d ", HP, MAXHP, revel);
	DrawFormatString(180, 353, Cr[1] = GetColor(255, 0, 0), "SP%d/%d ", SP, MAXSP);
	DrawFormatString(180, 386, Cr[1] = GetColor(255, 0, 0), "EXP  %d/%d ", exp, maxexp);
	DrawFormatString(265, 100, Cr[1] = GetColor(0, 0, 255), "HP%d ", x); // ������`�悷��
	ScreenFlip();//����ʂ�\��ʂɔ��f
	WaitKey();
	ScreenFlip();//����ʂ�\��ʂɔ��f



}
////////�y�Q�[���I�[�o�[�z///////////////////////////////////////////////////////////////////////////////////////////////
void GAMEOVER()
{
	int GAMEOVER, Cr;
	PlayMusic("die.mid", DX_PLAYTYPE_BACK); //test.wav�̃o�b�N�O���E���h���t
	SetTransColor(0, 0, 0);
	GAMEOVER = LoadGraph("GMAE OVER.png");
	SetTransColor(255, 255, 25);
	DrawGraph(0, 0, GAMEOVER, TRUE); // �摜��`�悷��
	DrawFormatString(330, 450, Cr = GetColor(255, 0, 0), "�͐s����.......�B");
	ScreenFlip();//����ʂ�\��ʂɔ��f
	WaitTimer(10000);
	WaitKey();


}
/////////�y�����z//////////////////////////////////////////////////////////////////////////////////////////////
void win(int getexp, int getmoney, int exp, int maxexp)
{
	int win, Cr;
	PlayMusic("�C�x���g�@�퓬�I��.mp3", DX_PLAYTYPE_BACK);
	win = LoadGraph("�����i.png");
	DrawGraph(150, 100, win, TRUE);
	DrawBox(172, 405, 172 + WD, 420, GetColor(0, 255, 255), FALSE);//���[�^�[�̘g��`��
	DrawBox(172, 405, 172 + WD*(exp + getexp) / maxexp, 420, GetColor(0, 200, 200), TRUE);//���[�^�[�̒��g��`��
	DrawFormatString(160, 115, Cr = GetColor(255, 0, 0), "EXP+%d money+%d", getexp, getmoney);
	DrawFormatString(200, 405, Cr = GetColor(255, 0, 0), "+%d", getexp);
	ScreenFlip();
	WaitTimer(4000);
	WaitKey();
}
////////�y���x���A�b�v�z////////////////////////////////////////////////////////////////////////////////////////////
int revelup(int exp, int maxexp)
{
	int x = 0, Cr;
	x = maxexp - exp;
	PlayMusic("���t���b�V��1 (1).wav", DX_PLAYTYPE_BACK);
	DrawFormatString(20, 350, Cr = GetColor(255, 0, 0), "LEVEL�@UP�I�I");
	return x;
}
////////�y�X�L���U��z///////////////////////////////////////////////////////////////////////////////////////////////
int Bonus(int level)
{
	int win, SP, Cr, ans;
	if (level<50)
	{
		win = LoadGraph("���x���A�b�v���j���[.png");
		SP = LoadGraph("�X�L���|�C���g.png");
		DrawGraph(150, 100, win, TRUE);
		DrawGraph(0, 225, SP, TRUE);
		DrawFormatString(160, 115, Cr = GetColor(255, 0, 0), "");

		ans = KeyInputNumber(320, 460, 4, 1, FALSE);
		while (CheckHitKey(KEY_INPUT_RETURN) == 0)
		{
			// ���b�Z�[�W����
			if (ProcessMessage() == -1)
			{
				break;    // �G���[�����������烋�[�v�𔲂���
			}
		}
		if (ans == 1)
			return ans;
		if (ans == 2)
			return ans;
		if (ans == 3)
			return ans;
		if (ans == 4)
			return ans;
	}
	return 0;
}
//////////�y�S�񕜁z///////////////////////////////////////////////////////////////////////////////////////////
int zenkaihuku(int hp, int maxhp)
{
	int x;
	x = maxhp - hp;
	return x;
}

////////�y���w01�z/////////////////////////////////////////////////////////////////////////////////////
int question01suu()
{
	int ans;
	int puestion[10];
	puestion[1] = LoadGraph("�����w���1.jpg");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion[1], TRUE); // �摜��`�悷��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//����ʂ�\��ʂɔ��f
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// ���b�Z�[�W����
		if (ProcessMessage() == -1)
		{
			break;    // �G���[�����������烋�[�v�𔲂���
		}
	}
	if (ans == 2)
		return 1;
	else
		return 0;
}
///////�y�p��01�z////////////////////////////////////////////////////////////////////////////////
int question01ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("���p����1.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // �摜��`�悷��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//����ʂ�\��ʂɔ��f
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// ���b�Z�[�W����
		if (ProcessMessage() == -1)
		{
			break;    // �G���[�����������烋�[�v�𔲂���
		}
	}
	if (ans == 3)
		return 1;
	else
		return 0;
}
///////�y�p��02�z///////////////////////////////////////////////////
int question02ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("���p����2.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // �摜��`�悷��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//����ʂ�\��ʂɔ��f
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// ���b�Z�[�W����
		if (ProcessMessage() == -1)
		{
			break;    // �G���[�����������烋�[�v�𔲂���
		}
	}
	if (ans == 1)
		return 1;
	else
		return 0;
}
/////////�y�p��03�z////////////////////////////////////////////////////////////
int question03ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("���p����3�i1�j.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // �摜��`�悷��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//����ʂ�\��ʂɔ��f
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// ���b�Z�[�W����
		if (ProcessMessage() == -1)
		{
			break;    // �G���[�����������烋�[�v�𔲂���
		}
	}
	if (ans == 1)
		return 1;
	else
		return 0;
}
/////////�y�p��04�z////////////////////////////////////////////////////////
int question04ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("���p����4�i4�j.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // �摜��`�悷��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//����ʂ�\��ʂɔ��f
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// ���b�Z�[�W����
		if (ProcessMessage() == -1)
		{
			break;    // �G���[�����������烋�[�v�𔲂���
		}
	}
	if (ans == 4)
		return 1;
	else
		return 0;
}

/////////�y�p��05�z////////////////////////////////////////////////////////
int question05ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("���p����5�i2�j.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // �摜��`�悷��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//����ʂ�\��ʂɔ��f
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// ���b�Z�[�W����
		if (ProcessMessage() == -1)
		{
			break;    // �G���[�����������烋�[�v�𔲂���
		}
	}
	if (ans == 2)
		return 1;
	else
		return 0;
}
/////////�y�p��06�z////////////////////////////////////////////////////////
int question06ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("���p����6�i3�j.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // �摜��`�悷��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//����ʂ�\��ʂɔ��f
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// ���b�Z�[�W����
		if (ProcessMessage() == -1)
		{
			break;    // �G���[�����������烋�[�v�𔲂���
		}
	}
	if (ans == 3)
		return 1;
	else
		return 0;
}
/////////�y�p��07�z////////////////////////////////////////////////////////
int question07ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("���p����7�i4�j.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // �摜��`�悷��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//����ʂ�\��ʂɔ��f
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// ���b�Z�[�W����
		if (ProcessMessage() == -1)
		{
			break;    // �G���[�����������烋�[�v�𔲂���
		}
	}
	if (ans == 4)
		return 1;
	else
		return 0;
}
/////////�y�p��08�z////////////////////////////////////////////////////////
int question08ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("���p����8�i3�j.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // �摜��`�悷��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//����ʂ�\��ʂɔ��f
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// ���b�Z�[�W����
		if (ProcessMessage() == -1)
		{
			break;    // �G���[�����������烋�[�v�𔲂���
		}
	}
	if (ans == 3)
		return 1;
	else
		return 0;
}
/////////�y�p��09�z////////////////////////////////////////////////////////
int question09ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("���p����9�i3�j.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // �摜��`�悷��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//����ʂ�\��ʂɔ��f
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// ���b�Z�[�W����
		if (ProcessMessage() == -1)
		{
			break;    // �G���[�����������烋�[�v�𔲂���
		}
	}
	if (ans == 3)
		return 1;
	else
		return 0;
}
/////////�y�p��10�z////////////////////////////////////////////////////////
int question10ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("���p����10�i4�j.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // �摜��`�悷��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//����ʂ�\��ʂɔ��f
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// ���b�Z�[�W����
		if (ProcessMessage() == -1)
		{
			break;    // �G���[�����������烋�[�v�𔲂���
		}
	}
	if (ans == 4)
		return 1;
	else
		return 0;
}
/////////�y�p��11�z////////////////////////////////////////////////////////
int question11ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("���p����11�i1�j.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // �摜��`�悷��
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//����ʂ�\��ʂɔ��f
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// ���b�Z�[�W����
		if (ProcessMessage() == -1)
		{
			break;    // �G���[�����������烋�[�v�𔲂���
		}
	}
	if (ans == 1)
		return 1;
	else
		return 0;
}