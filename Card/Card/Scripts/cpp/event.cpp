#include "DxLib.h"

void kaiwa00(int haikei,int ota,int serihu);

void kaiwa00(int haikei, int ota, int serihu){
PlayMusic("7.mp3", DX_PLAYTYPE_BACK); //test.wavÌobNOEh
	DrawGraph(0, 0, haikei, TRUE); // ¶næð`æ·é

	DrawGraph(420, 40, ota, TRUE); // ¶næð`æ·é
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);

	DrawGraph(30, 320, serihu, TRUE); // ¶næð`æ·é
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0);

	ScreenFlip();// æÊð\æÊÉ½f
	WaitKey();

}