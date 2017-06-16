#include "../h/GV.h"


//マイキャラクターー更新処理
void updateMyChara() {



	//歩行フラグ、向き情報
	if (myChara[player.collisonObjectkind].data.x % MAP_SIZE == 0 && myChara[player.collisonObjectkind].data.y % MAP_SIZE == 0 && gameState == openMyCharaMenu/* && player.data.attack_flag == 0*/) {//マスにピッタリ　＆　攻撃状態でないなら
		myChara[player.collisonObjectkind].data.walking_flag = 1;//一先ず歩行フラグON
		myChara[player.collisonObjectkind].data.nextWalking_flag = 1;
		myCharaKeyPushManage();//なんのキーを押されたか管理
		//player.collisonFlag = FALSE;
		//searchObject();

		//移動できるかを判定。
		if (isAbleToGo(player.collisonObjectkind, myChara[player.collisonObjectkind].data.x, myChara[player.collisonObjectkind].data.y, myChara[player.collisonObjectkind].data.muki) != 1)myChara[player.collisonObjectkind].data.walking_flag = 0;//移動できないなら移動フラグを0にする
		
		
		if (beforeZKey == 1 && keyBuffer[KEY_INPUT_Z] == 0  ) {
			if (myCharaSearchObjectMyChara() < 0) {
				PlaySound("カーソル2.wav", DX_PLAYTYPE_BACK); //test.wavのバックグラウンド演奏
				gameState = noState;
				player.mycharaFocus.state = noState;
				//初期座標を設定
				myChara[player.collisonObjectkind].data.initPosX = myChara[player.collisonObjectkind].data.x;
				myChara[player.collisonObjectkind].data.initPosY = myChara[player.collisonObjectkind].data.y;
			}
		}

	}

	//実際にプレイヤーが移動する
	if (myChara[player.collisonObjectkind].data.walking_flag == 1 && myChara[player.collisonObjectkind].data.attack_flag == 0) {//歩行フラグがONかつ攻撃フラグがＯＦＦなら
		walkingUpdateMyChara(myChara[player.collisonObjectkind].data.muki);//移動変化関数（向きに応じて座標を変化させる関数）
	}
}



void myCharaKeyPushManage() {
	/*
	//攻撃の管理
	if (keyBuffer[KEY_INPUT_Z] == 1) {
	player.data.attack_flag = 1;//攻撃フラグを立てる
	player.data.walking_flag = 0;
	}
	*/



	//移動の管理
	//十字移動　　　「↓」「←」「→」「↑」の順
	if (keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0 && keyBuffer[KEY_INPUT_V] == 0)myChara[player.collisonObjectkind].data.muki = 0;
	else if (keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0 && keyBuffer[KEY_INPUT_V] == 0)myChara[player.collisonObjectkind].data.muki = 1;  //左ボタンが押されたら左向きフラグを立てる
	else if (keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0 && keyBuffer[KEY_INPUT_V] == 0)myChara[player.collisonObjectkind].data.muki = 2;//右ボタンが押されたら右向きフラグを立てる
	else if (keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0 && keyBuffer[KEY_INPUT_V] == 0)myChara[player.collisonObjectkind].data.muki = 3;//上ボタンが押されたら上向きフラグを立てる
																																  //斜め移動		「右上」「右下」「左上」「左下」の順
	else if (keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1 && keyBuffer[KEY_INPUT_V] == 0)myChara[player.collisonObjectkind].data.muki = 4;//右上ボタンが押されたら上向きフラグを立てる
	else if (keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1 && keyBuffer[KEY_INPUT_V] == 0)myChara[player.collisonObjectkind].data.muki = 5;//右下ボタンが押されたら上向きフラグを立てる
	else if (keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1 && keyBuffer[KEY_INPUT_V] == 0)myChara[player.collisonObjectkind].data.muki = 6;//左上ボタンが押されたら上向きフラグを立てる
	else if (keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1 && keyBuffer[KEY_INPUT_V] == 0)myChara[player.collisonObjectkind].data.muki = 7;//左下ボタンが押されたら上向きフラグを立てる
																																									  //その場向き転換の管理
	//十字向き変換　　　「↓」「←」「→」「↑」の順
	else if (keyBuffer[KEY_INPUT_V] == 1 && keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0) myChara[player.collisonObjectkind].data.muki = 0, myChara[player.collisonObjectkind].data.walking_flag = 0, myChara[player.collisonObjectkind].data.nextWalking_flag = 0;//下に向く
	else if (keyBuffer[KEY_INPUT_V] == 1 && keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0) myChara[player.collisonObjectkind].data.muki = 1, myChara[player.collisonObjectkind].data.walking_flag = 0, myChara[player.collisonObjectkind].data.nextWalking_flag = 0;//左に向く
	else if (keyBuffer[KEY_INPUT_V] == 1 && keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0) myChara[player.collisonObjectkind].data.muki = 2, myChara[player.collisonObjectkind].data.walking_flag = 0, myChara[player.collisonObjectkind].data.nextWalking_flag = 0;//右に向く
	else if (keyBuffer[KEY_INPUT_V] == 1 && keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0) myChara[player.collisonObjectkind].data.muki = 3, myChara[player.collisonObjectkind].data.walking_flag = 0, myChara[player.collisonObjectkind].data.nextWalking_flag = 0;//上に向く
																																																   //斜め向き転換		「右上」「右下」「左上」「左下」の順
	else if (keyBuffer[KEY_INPUT_V] == 1 && keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1) myChara[player.collisonObjectkind].data.muki = 4, myChara[player.collisonObjectkind].data.walking_flag = 0, myChara[player.collisonObjectkind].data.nextWalking_flag = 0;//右上に向く
	else if (keyBuffer[KEY_INPUT_V] == 1 && keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1) myChara[player.collisonObjectkind].data.muki = 5, myChara[player.collisonObjectkind].data.walking_flag = 0, myChara[player.collisonObjectkind].data.nextWalking_flag = 0;//右下に向く
	else if (keyBuffer[KEY_INPUT_V] == 1 && keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1) myChara[player.collisonObjectkind].data.muki = 6, myChara[player.collisonObjectkind].data.walking_flag = 0, myChara[player.collisonObjectkind].data.nextWalking_flag = 0;//左上に向く
	else if (keyBuffer[KEY_INPUT_V] == 1 && keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1) myChara[player.collisonObjectkind].data.muki = 7, myChara[player.collisonObjectkind].data.walking_flag = 0, myChara[player.collisonObjectkind].data.nextWalking_flag = 0;//左下に向く
	else {
		myChara[player.collisonObjectkind].data.walking_flag = 0;//何のボタンも押されてなかったら歩行フラグOFF
		myChara[player.collisonObjectkind].data.nextWalking_flag = 0;
	}
}
void walkingUpdateMyChara(int muki) {
	switch (muki) {
	case 0:

		myChara[player.collisonObjectkind].data.y += 1;//下向きならch.y座標を増やす				32の倍数代入で主人公の歩行速度UP
		player.data.y += 1;//下向きならch.y座標を増やす				32の倍数代入で主人公の歩行速度UP
		break;
	case 1:
		myChara[player.collisonObjectkind].data.x -= 1;//左向きならch.x座標を減らす
		player.data.x -= 1;//下向きならch.y座標を増やす				32の倍数代入で主人公の歩行速度UP
		break;
	case 2:
		myChara[player.collisonObjectkind].data.x += 1; //右向きならch.x座標を増やす
		player.data.x += 1;//下向きならch.y座標を増やす				32の倍数代入で主人公の歩行速度UP

		break;
	case 3:
		myChara[player.collisonObjectkind].data.y -= 1;//上向きならch.y座標を減らす
		player.data.y -= 1;//下向きならch.y座標を増やす				32の倍数代入で主人公の歩行速度UP

		break;
	case 4:
		myChara[player.collisonObjectkind].data.y -= 1;//右上向きならch.y座標を減らす
		myChara[player.collisonObjectkind].data.x += 1;
		player.data.y -= 1;//下向きならch.y座標を増やす				32の倍数代入で主人公の歩行速度UP
		player.data.x += 1;//下向きならch.y座標を増やす				32の倍数代入で主人公の歩行速度UP		
		break;
	case 5:
		myChara[player.collisonObjectkind].data.y += 1;//右下向きならch.y座標を減らす
		myChara[player.collisonObjectkind].data.x += 1;
		player.data.y += 1;//下向きならch.y座標を増やす				32の倍数代入で主人公の歩行速度UP
		player.data.x += 1;//下向きならch.y座標を増やす				32の倍数代入で主人公の歩行速度UP		
		break;
	case 6:
		myChara[player.collisonObjectkind].data.y -= 1;//左上向きならch.y座標を減らす
		myChara[player.collisonObjectkind].data.x -= 1;
		player.data.y -= 1;//下向きならch.y座標を増やす				32の倍数代入で主人公の歩行速度UP
		player.data.x -= 1;//下向きならch.y座標を増やす				32の倍数代入で主人公の歩行速度UP		
		break;
	case 7:
		myChara[player.collisonObjectkind].data.y += 1;//左下向きならch.y座標を減らす
		myChara[player.collisonObjectkind].data.x -= 1;
		player.data.y += 1;//下向きならch.y座標を増やす				32の倍数代入で主人公の歩行速度UP
		player.data.x -= 1;//下向きならch.y座標を増やす				32の倍数代入で主人公の歩行速度UP		

		break;
	}
}
int myCharaSearchObjectMyChara() {//選択されたマイキャラと同じマスにマイキャラがいるか
	int i = 0;
	while (i < MYCHARA_NUM) {
		//検索対象が選択されたマイキャラだったら無視して次の奴へ
		if (player.collisonObjectkind == i)i++; 

		if (myChara[player.collisonObjectkind].data.x == myChara[i].data.x  &&   myChara[player.collisonObjectkind].data.y == myChara[i].data.y) {
				
			//選択中のマイキャラと他のマイキャラが同じ座標だったら
			myChara[player.collisonObjectkind].myCharaCollisonFlag = TRUE;
			return i;//接触を確認したらこの関数から抜ける
		}
		else {
			myChara[player.collisonObjectkind].myCharaCollisonFlag = FALSE;
		}
		i++;
	}
	return -1;//味方のオブジェクトが見つからなかった場合
}
