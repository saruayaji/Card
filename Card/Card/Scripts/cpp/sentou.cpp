#include "DxLib.h"
#include <stdio.h>
#define WD 300
//関数宣言
int Damage(int x, int y);																		//ダメージ
int HiDamage(int x, int y);																		//被ダメージ
void sentou(int HP, int MAXHP, int SP, int MAXSP, int level, int exp, int maxexp, int x);		//戦闘
void GAMEOVER();																				//ゲームオーバー	
void win(int getexp, int getmoney, int exp, int maxexp);										//勝利
int revelup(int exp, int maxexp);																//レベルアップ
int Bonus(int revel);																			//レベルアップボーナス
int zenkaihuku(int hp, int maxhp);																//全回復
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








/////////【ダメージ】///////////////////////////////////////////////////////////////////////////////////////////////
int Damage(int x, int y)
{
	int dame, Cr[5];
	DrawFormatString(265, 280, Cr[1] = GetColor(255, 0, 0), "%d", x - y); // 文字を描画する
	dame = x - y;
	return dame;
}
///////【被ダメージ】///////////////////////////////////////////////////////////////////////////////////////////////
int HiDamage(int x, int y)
{
	int hidame, Cr[5];
	DrawFormatString(20, 350, Cr[1] = GetColor(255, 0, 0), "%d", x - y); // 文字を描画する
	hidame = x - y;
	return hidame;
}

//////////【戦闘】/////////////////////////////////////////////////////////////////////////////////////		
void sentou(int HP, int MAXHP, int SP, int MAXSP, int revel, int exp, int maxexp, int x)
{
	int menu, nyuuryoku;
	menu = LoadGraph("メニュー00.png");
	nyuuryoku = LoadGraph("入力欄.png");
	int Cr[5];

	DrawGraph(0, 0, menu, TRUE); // 画像を描画する
	DrawGraph(260, 450, nyuuryoku, TRUE); // 画像を描画する
	DrawBox(172, 335, 172 + WD, 350, GetColor(0, 255, 0), FALSE);//				HP
	DrawBox(172, 335, 172 + WD*HP / MAXHP, 350, GetColor(0, 255, 0), TRUE);//	HP
	DrawBox(172, 370, 172 + WD, 385, GetColor(0, 0, 255), FALSE);//				SP
	DrawBox(172, 370, 172 + WD*SP / MAXSP, 385, GetColor(0, 0, 255), TRUE);//	SP
	DrawBox(172, 405, 172 + WD, 420, GetColor(0, 255, 255), FALSE);//			EXP
	DrawBox(172, 405, 172 + WD*exp / maxexp, 420, GetColor(0, 200, 200), TRUE);//EXP
	DrawFormatString(180, 315, Cr[1] = GetColor(255, 0, 0), "HP%d/%d					level%d ", HP, MAXHP, revel);
	DrawFormatString(180, 353, Cr[1] = GetColor(255, 0, 0), "SP%d/%d ", SP, MAXSP);
	DrawFormatString(180, 386, Cr[1] = GetColor(255, 0, 0), "EXP  %d/%d ", exp, maxexp);
	DrawFormatString(265, 100, Cr[1] = GetColor(0, 0, 255), "HP%d ", x); // 文字を描画する
	ScreenFlip();//裏画面を表画面に反映
	WaitKey();
	ScreenFlip();//裏画面を表画面に反映



}
////////【ゲームオーバー】///////////////////////////////////////////////////////////////////////////////////////////////
void GAMEOVER()
{
	int GAMEOVER, Cr;
	PlayMusic("die.mid", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
	SetTransColor(0, 0, 0);
	GAMEOVER = LoadGraph("GMAE OVER.png");
	SetTransColor(255, 255, 25);
	DrawGraph(0, 0, GAMEOVER, TRUE); // 画像を描画する
	DrawFormatString(330, 450, Cr = GetColor(255, 0, 0), "力尽きた.......。");
	ScreenFlip();//裏画面を表画面に反映
	WaitTimer(10000);
	WaitKey();


}
/////////【勝利】//////////////////////////////////////////////////////////////////////////////////////////////
void win(int getexp, int getmoney, int exp, int maxexp)
{
	int win, Cr;
	PlayMusic("イベント　戦闘終了.mp3", DX_PLAYTYPE_BACK);
	win = LoadGraph("勝利品.png");
	DrawGraph(150, 100, win, TRUE);
	DrawBox(172, 405, 172 + WD, 420, GetColor(0, 255, 255), FALSE);//メーターの枠を描画
	DrawBox(172, 405, 172 + WD*(exp + getexp) / maxexp, 420, GetColor(0, 200, 200), TRUE);//メーターの中身を描画
	DrawFormatString(160, 115, Cr = GetColor(255, 0, 0), "EXP+%d money+%d", getexp, getmoney);
	DrawFormatString(200, 405, Cr = GetColor(255, 0, 0), "+%d", getexp);
	ScreenFlip();
	WaitTimer(4000);
	WaitKey();
}
////////【レベルアップ】////////////////////////////////////////////////////////////////////////////////////////////
int revelup(int exp, int maxexp)
{
	int x = 0, Cr;
	x = maxexp - exp;
	PlayMusic("★フラッシュ1 (1).wav", DX_PLAYTYPE_BACK);
	DrawFormatString(20, 350, Cr = GetColor(255, 0, 0), "LEVEL　UP！！");
	return x;
}
////////【スキル振り】///////////////////////////////////////////////////////////////////////////////////////////////
int Bonus(int level)
{
	int win, SP, Cr, ans;
	if (level<50)
	{
		win = LoadGraph("レベルアップメニュー.png");
		SP = LoadGraph("スキルポイント.png");
		DrawGraph(150, 100, win, TRUE);
		DrawGraph(0, 225, SP, TRUE);
		DrawFormatString(160, 115, Cr = GetColor(255, 0, 0), "");

		ans = KeyInputNumber(320, 460, 4, 1, FALSE);
		while (CheckHitKey(KEY_INPUT_RETURN) == 0)
		{
			// メッセージ処理
			if (ProcessMessage() == -1)
			{
				break;    // エラーが発生したらループを抜ける
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
//////////【全回復】///////////////////////////////////////////////////////////////////////////////////////////
int zenkaihuku(int hp, int maxhp)
{
	int x;
	x = maxhp - hp;
	return x;
}

////////【数学01】/////////////////////////////////////////////////////////////////////////////////////
int question01suu()
{
	int ans;
	int puestion[10];
	puestion[1] = LoadGraph("▲数学問題1.jpg");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion[1], TRUE); // 画像を描画する
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//裏画面を表画面に反映
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// メッセージ処理
		if (ProcessMessage() == -1)
		{
			break;    // エラーが発生したらループを抜ける
		}
	}
	if (ans == 2)
		return 1;
	else
		return 0;
}
///////【英語01】////////////////////////////////////////////////////////////////////////////////
int question01ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("▲英語問題1.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // 画像を描画する
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//裏画面を表画面に反映
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// メッセージ処理
		if (ProcessMessage() == -1)
		{
			break;    // エラーが発生したらループを抜ける
		}
	}
	if (ans == 3)
		return 1;
	else
		return 0;
}
///////【英語02】///////////////////////////////////////////////////
int question02ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("▲英語問題2.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // 画像を描画する
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//裏画面を表画面に反映
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// メッセージ処理
		if (ProcessMessage() == -1)
		{
			break;    // エラーが発生したらループを抜ける
		}
	}
	if (ans == 1)
		return 1;
	else
		return 0;
}
/////////【英語03】////////////////////////////////////////////////////////////
int question03ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("▲英語問題3（1）.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // 画像を描画する
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//裏画面を表画面に反映
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// メッセージ処理
		if (ProcessMessage() == -1)
		{
			break;    // エラーが発生したらループを抜ける
		}
	}
	if (ans == 1)
		return 1;
	else
		return 0;
}
/////////【英語04】////////////////////////////////////////////////////////
int question04ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("▲英語問題4（4）.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // 画像を描画する
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//裏画面を表画面に反映
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// メッセージ処理
		if (ProcessMessage() == -1)
		{
			break;    // エラーが発生したらループを抜ける
		}
	}
	if (ans == 4)
		return 1;
	else
		return 0;
}

/////////【英語05】////////////////////////////////////////////////////////
int question05ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("▲英語問題5（2）.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // 画像を描画する
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//裏画面を表画面に反映
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// メッセージ処理
		if (ProcessMessage() == -1)
		{
			break;    // エラーが発生したらループを抜ける
		}
	}
	if (ans == 2)
		return 1;
	else
		return 0;
}
/////////【英語06】////////////////////////////////////////////////////////
int question06ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("▲英語問題6（3）.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // 画像を描画する
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//裏画面を表画面に反映
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// メッセージ処理
		if (ProcessMessage() == -1)
		{
			break;    // エラーが発生したらループを抜ける
		}
	}
	if (ans == 3)
		return 1;
	else
		return 0;
}
/////////【英語07】////////////////////////////////////////////////////////
int question07ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("▲英語問題7（4）.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // 画像を描画する
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//裏画面を表画面に反映
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// メッセージ処理
		if (ProcessMessage() == -1)
		{
			break;    // エラーが発生したらループを抜ける
		}
	}
	if (ans == 4)
		return 1;
	else
		return 0;
}
/////////【英語08】////////////////////////////////////////////////////////
int question08ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("▲英語問題8（3）.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // 画像を描画する
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//裏画面を表画面に反映
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// メッセージ処理
		if (ProcessMessage() == -1)
		{
			break;    // エラーが発生したらループを抜ける
		}
	}
	if (ans == 3)
		return 1;
	else
		return 0;
}
/////////【英語09】////////////////////////////////////////////////////////
int question09ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("▲英語問題9（3）.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // 画像を描画する
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//裏画面を表画面に反映
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// メッセージ処理
		if (ProcessMessage() == -1)
		{
			break;    // エラーが発生したらループを抜ける
		}
	}
	if (ans == 3)
		return 1;
	else
		return 0;
}
/////////【英語10】////////////////////////////////////////////////////////
int question10ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("▲英語問題10（4）.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // 画像を描画する
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//裏画面を表画面に反映
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// メッセージ処理
		if (ProcessMessage() == -1)
		{
			break;    // エラーが発生したらループを抜ける
		}
	}
	if (ans == 4)
		return 1;
	else
		return 0;
}
/////////【英語11】////////////////////////////////////////////////////////
int question11ei()
{
	int ans;
	int puestion;
	puestion = LoadGraph("▲英語問題11（1）.png");
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawGraph(0, 25, puestion, TRUE); // 画像を描画する
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	ScreenFlip();//裏画面を表画面に反映
	ans = KeyInputNumber(320, 460, 4, 1, FALSE);
	while (CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// メッセージ処理
		if (ProcessMessage() == -1)
		{
			break;    // エラーが発生したらループを抜ける
		}
	}
	if (ans == 1)
		return 1;
	else
		return 0;
}