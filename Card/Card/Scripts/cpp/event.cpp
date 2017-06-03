#include "DxLib.h"

void kaiwa00(int haikei,int ota,int serihu);

void kaiwa00(int haikei, int ota, int serihu){
PlayMusic("7.mp3", DX_PLAYTYPE_BACK); //test.wav‚ÌƒoƒbƒNƒOƒ‰ƒEƒ“ƒh‰‰
	DrawGraph(0, 0, haikei, TRUE); // •¶Œn‰æ‘œ‚ð•`‰æ‚·‚é

	DrawGraph(420, 40, ota, TRUE); // •¶Œn‰æ‘œ‚ð•`‰æ‚·‚é
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);

	DrawGraph(30, 320, serihu, TRUE); // •¶Œn‰æ‘œ‚ð•`‰æ‚·‚é
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0);

	ScreenFlip();//— ‰æ–Ê‚ð•\‰æ–Ê‚É”½‰f
	WaitKey();

}