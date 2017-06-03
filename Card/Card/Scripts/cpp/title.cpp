#include "DxLib.h"
#include "stdio.h"
#include "sentou.h"
#include "map.h"


int GetHitKeyStateAll_2(int KeyStateBuf[]);
void char_disp(int White, int y);
void TITLE();






int GetHitKeyStateAll_2(int KeyStateBuf[]){
	char GetHitKeyStateAll_Key[256];
	GetHitKeyStateAll(GetHitKeyStateAll_Key);
	for (int i = 0; i<256; i++){
		if (GetHitKeyStateAll_Key[i] == 1) KeyStateBuf[i]++;
		else                            KeyStateBuf[i] = 0;
	}
	return 0;
}

void char_disp(int White, int y){
	SetFontSize(50);

	DrawString(200, y, "■", White);
	DrawString(260, 280, "入学", White);
	DrawString(260, 330, "登校", White);
	DrawString(260, 380, "退学", White);
}


void TITLE(){
	ChangeFont("HGS創英角ﾎﾟｯﾌﾟ体", DX_CHARSET_DEFAULT);

	int Key[256];
	int White, y = 280;                                       //色とy座標の宣言
	int title;
	title = LoadGraph("タイトル_43.jpg"); // 画像のロード
	PlayMusic("9.mp3", DX_PLAYTYPE_BACK);


	ChangeWindowMode(TRUE);//ウィンドウモード
	
	White = GetColor(0, 0, 0);                    //色の取得


	while (ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll_2(Key) == 0 && Key[KEY_INPUT_ESCAPE] == 0){
		//↑ﾒｯｾｰｼﾞ処理         ↑画面をｸﾘｱ         ↑入力状態を保存　　　　　　　↑ESCが押されていない
		DrawGraph(0, 0, title, TRUE); //画像の描画
		char_disp(White, y);         // 文字を描画

		if (Key[KEY_INPUT_DOWN] == 1 || (Key[KEY_INPUT_DOWN] % 5 == 0 && Key[KEY_INPUT_DOWN]>30)){
			// たった今押したか、30カウンター以上押しっぱなしかつ5回に一度
			PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
			y += 50;
			if (y == 430)                            // y座標が260なら(選択が一番下なら)
				y = 280;                        // 選択座標を一番上に
		}
		if (Key[KEY_INPUT_UP] == 1 || (Key[KEY_INPUT_UP] % 5 == 0 && Key[KEY_INPUT_UP] > 30)){
			// たった今押したか、30カウンター以上押しっぱなしかつ5回に一度
			PlaySound("決定3.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
			y -= 50;
			if (y == 230)                            // y座標が260なら(選択が一番下なら)
				y = 380;                        // 選択座標を一番上に
			break;
		}


		if (Key[KEY_INPUT_RETURN] == 1 && y == 280){     //『入学』をEnterしたら
			SetFontSize(20);//フォントサイズを戻してゲームに戻る
			break;
		}

		if (Key[KEY_INPUT_RETURN] == 1 && y == 330){     //『登校』をEnterしたら
			SetFontSize(30);//フォントサイズを戻してゲームに戻る
			break;
		}

		if (Key[KEY_INPUT_RETURN] == 1 && y == 380){     //『退学』をEnterしたら
			SetFontSize(30);//フォントサイズを戻してゲームに戻る
			break;
		}


		ScreenFlip();//裏画面反映
	}

}
