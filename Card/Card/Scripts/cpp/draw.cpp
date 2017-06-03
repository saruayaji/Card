#include "../h/GV.h"

// ---------------------------------------- 描画処理 ----------------------------------------

void draw() {
	// 画面を消去する
	ClearDrawScreen();
	switch (mainState) {
	case TITLE:
		// タイトルの描画
		drawTitle();
		break;

	case GAME:
		// ゲーム画面の描画		

		drawMAP(stage00);

		for (int i = 0; i < ENEMY_NUM; i++) {
			if(player.data.y >= enemyChara[i].data.y)drawEnemy(i);//プレイヤーより上に敵がいる場合　プレイヤーよりも先に描画する
		}
		
		drawMyChara();

		for (int i = 0; i < ENEMY_NUM; i++) {
			if (player.data.y < enemyChara[i].data.y)drawEnemy(i);//プレイヤーより下に敵がいる場合　プレイヤーの後に描画する
		}

		drawPlayer();										//プレイヤーを描画する

		drawHeightMap();//MAP最上位レイヤーを付け足して描画
		//drawConsole();//ゲームHPバーや、デバックコンソールの描画
		//if (gameState == openGameMenu)drawGameMenu();
		objectCollisonDraw();
		break;

	case GAMEOVER:
		// ゲームオーバー画面の描画
		drawGmaOver();
		break;

	case GAMECLEAR:
		// ゲームクリア画面の描画
		drawGameClear();
		break;

	}

	// 画面に表示する
	ScreenFlip();
}

// タイトルの描画
void drawTitle() {

	DrawGraph(0, 0, backTitle, TRUE); //画像の描画
									  //DrawString(260, 350, "SPACEキーで開始", GetColor(255, 255, 255));
	DrawString(player.select.titleMenuPointX, player.select.titleMenuPointY, "■", GetColor(255, 255, 0));
	DrawString(300, 300, "はじめる", GetColor(0, 0, 0));
	DrawString(300, 325, "続ける", GetColor(0, 0, 0));
	DrawString(300, 350, "終わる", GetColor(0, 0, 0));

}

// ゲームオーバーの描画
void drawGmaOver() {
	DrawString(300, 150, "GAMEOVER", GetColor(255, 0, 0));
	DrawString(260, 350, "SPACEキーで再履修", GetColor(255, 255, 255));

}

// ゲームクリアの描画
void drawGameClear() {
	DrawString(300, 150, "GAMECLEAR", GetColor(0, 255, 0));
	DrawString(260, 350, "SPACEキーでタイトル", GetColor(255, 255, 255));
}


//　プレイヤー（オリジン）表示
void drawPlayer() {
	switch (player.deadOrAlive) {
	case ALIVE:
		DrawBox(startXpos, startYpos, player.data.nextPosX + MAP_SIZE, player.data.nextPosY + MAP_SIZE, GetColor(255, 0, 0), FALSE);
	
	}

}


// 自キャラの表示
void drawMyChara() {
	int i = 0;
	while (i < MYCHARA_NUM) {
		switch (myChara[i].state.deadOrAlive) {
		case ALIVE:

			int myCharaXpos = myChara[i].data.x - player.data.x, myCharaYpos = myChara[i].data.y - player.data.y;			//主人公の座標とモンスターの座標の差

			if (myChara[i].data.muki == 4 || myChara[i].data.muki == 5)myChara[i].data.img = myChara[i].data.WG[myChara[i].data.x % MAP_SIZE / 8 + 2 * 4];//主人公が斜め移動（右上、右下）のときの画像セット
			else if (myChara[i].data.muki == 6 || myChara[i].data.muki == 7)myChara[i].data.img = myChara[i].data.WG[myChara[i].data.x % MAP_SIZE / 8 + 1 * 4];//主人公が斜め移動（左上、左下）のときの画像セット
			else myChara[i].data.img = myChara[i].data.WG[(myChara[i].data.x % MAP_SIZE + myChara[i].data.y % MAP_SIZE) / 8 + myChara[i].data.muki * 4];//主人公の向きを考慮した十字移動の主人公の画像のセット。

			DrawGraph(startXpos + myCharaXpos, startYpos + myCharaYpos - 18, myChara[i].data.img, TRUE);//主人公の描画
																		//case DEAD:
		
			i++;
		}
	}
	if (myChara[i].data.attack_flag == 1) {//攻撃状態なら
		if (normalAttack.time == 1)
			PlaySound("雄叫び (2).wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏


	}
}
// 　敵の表示
void drawEnemy(int i) {

		switch (enemyChara[i].state.deadOrAlive) {
		case ALIVE:
			int enemyXpos = enemyChara[i].data.x - player.data.x, enemyYpos = enemyChara[i].data.y - player.data.y;			//主人公の座標とモンスターの座標の差

			if      (enemyChara[i].data.muki == 4 || enemyChara[i].data.muki == 5)enemyChara[i].data.img = enemyChara[i].data.WG[enemyChara[i].data.x % MAP_SIZE / 8 + 2 * 4];//主人公の向きを考慮した主人公の画像のセット。
			else if (enemyChara[i].data.muki == 6 || enemyChara[i].data.muki == 7)enemyChara[i].data.img = enemyChara[i].data.WG[enemyChara[i].data.x % MAP_SIZE / 8 + 1 * 4];//主人公の向きを考慮した主人公の画像のセット。
			else     enemyChara[i].data.img = enemyChara[i].data.WG[(enemyChara[i].data.x % MAP_SIZE + enemyChara[i].data.y % MAP_SIZE) / 8 + enemyChara[i].data.muki * 4];//モンスターの向きを考慮したモンスターの画像のセット。
			
			DrawGraph(startXpos + enemyXpos, startYpos + enemyYpos - 18, enemyChara[i].data.img, TRUE);//モンスターの描画

																								  //case DEAD:
																								  //★
		}	
}



void objectCollisonDraw() {//プレイヤーがオブジェクトに接触した際に表示されるUI　（ステータスなどを表示）
	if (player.collisonFlag == TRUE) {
		
		
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 50);//////////////////////////////////やや透明
		DrawBox(5, 300, 635, 475, GetColor(0, 0, 255), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 130);/////////////////////////////////結構透明
		//HPバーの表示
		DrawBox(200, 340, 200 + WD, 350, GetColor(0, 255, 0), FALSE);//メーターの枠を描画                                      
		DrawBox(200, 340, 200 + WD* collisonObject.status.HP / collisonObject.status.MAXHP, 350, GetColor(0, 255, 0), TRUE);//メーターの中身を描画
		//SPバーの表示
		DrawBox(200, 380, 200 + WD, 390, GetColor(0, 150, 150), FALSE);//メーターの枠を描画                                      
		DrawBox(200, 380, 200 + WD* collisonObject.status.MP / collisonObject.status.MAXMP, 390, GetColor(0, 150, 150), TRUE);//メーターの中身を描画
		//MPバーの表示
		DrawBox(200, 360, 200 + WD, 370, GetColor(255, 255, 0), FALSE);//メーターの枠を描画                                      
		DrawBox(200, 360, 200 + WD* collisonObject.status.SP / collisonObject.status.MAXSP, 370, GetColor(255, 255, 0), TRUE);//メーターの中身を描画
		
		

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);///////////////////////////////透明度０


		DrawGraph(5, 300, collisonObject.data.SG, TRUE);//立ち絵の表示

		
		DrawFormatString(200, 320, Cr[1] = GetColor(255, 255, 255), "%s",collisonObject.data.name);//名前の表示

		SetFontSize(10);//文字サイズ


		DrawFormatString(355, 340, Cr[1] = GetColor(0, 255, 0), "HP %d / %d", collisonObject.status.HP, collisonObject.status.MAXHP);//HP数値
		DrawFormatString(355, 360, Cr[1] = GetColor(255, 255, 0), "SP %d / %d", collisonObject.status.SP, collisonObject.status.MAXSP);//SP数値
		DrawFormatString(355, 380, Cr[1] = GetColor(255, 255, 255), "MP %d / %d", collisonObject.status.MP, collisonObject.status.MAXMP);//MP数値
		
		DrawFormatString(200, 400, Cr[1] = GetColor(255, 255, 255), "ATK  %d", collisonObject.status.ATK);//ATK数値
		DrawFormatString(200, 415, Cr[1] = GetColor(255, 255, 255), "DFE  %d", collisonObject.status.DFE);//DFE数値
		DrawFormatString(200, 430, Cr[1] = GetColor(255, 255, 255), "INT  %d", collisonObject.status.INT);//INT数値
		DrawFormatString(200, 445, Cr[1] = GetColor(255, 255, 255), "RES  %d", collisonObject.status.RES);//RES数値
		DrawFormatString(200, 460, Cr[1] = GetColor(255, 255, 255), "SPD  %d", collisonObject.status.SPD);//SPD数値
		DrawFormatString(450, 340, Cr[1] = GetColor(255, 255, 255), "レベル  %d", collisonObject.status.level);//レベル数値
		DrawFormatString(450, 355, Cr[1] = GetColor(255, 255, 255), "レア度  %d", collisonObject.status.rearity);//レベル数値	
		DrawFormatString(450, 370, Cr[1] = GetColor(255, 255, 255), "職  %d", collisonObject.status.Class);//レベル数値
		DrawFormatString(450, 385, Cr[1] = GetColor(255, 255, 255), "視認範囲  %d", collisonObject.status.range);//レベル数値
		DrawFormatString(450, 400, Cr[1] = GetColor(255, 255, 255), "隠ぺい率  %d", collisonObject.status.hide);//レベル数値
		DrawFormatString(450, 415, Cr[1] = GetColor(255, 255, 255), "移動マス  %d", collisonObject.status.MS);//レベル数値
		DrawFormatString(450, 460, Cr[1] = GetColor(255, 255, 255), "コスト  %d", collisonObject.status.cost);//レベル数値

		SetFontSize(20);

	}


}
