#include "../h/GV.h"


//プレイヤーー更新処理
void updatePlayer() {



	//歩行フラグ、向き情報
	if (player.data.x % MAP_SIZE == 0 && player.data.y % MAP_SIZE == 0 && gameState == noState && player.data.attack_flag == 0) {//マスにピッタリ　＆　攻撃状態でないなら
		player.data.walking_flag = 1;//一先ず歩行フラグON
		player.data.nextWalking_flag = 1;
		keyPushManage();//なんのキーを押されたか管理
		player.collisonFlag = FALSE;
		searchObject();

		//移動できるかを判定。
		//if (playerIsAbleToGo(player.data.x, player.data.y, player.data.muki) != 1)player.data.walking_flag = 0;//移動できないなら移動フラグを0にする
		//decideActionPos();
	

	
	}

	//実際にプレイヤーが移動する
	if (player.data.walking_flag == 1 && player.data.attack_flag == 0) {//歩行フラグがONかつ攻撃フラグがＯＦＦなら
		walkingUpdatePlayer(player.data.muki);//移動変化関数（向きに応じて座標を変化させる関数）
	}
	

}


void searchObject(){//プレイヤーと同じマスに何かオブジェクトはあるか
	int i = 0;
	while (i < MYCHARA_NUM) {
		if (player.data.x == myChara[i].data.x  &&   player.data.y == myChara[i].data.y) {
			//プレイヤーと自分のキャラが同じ座標だったら
			collisonObject = myChara[i];
			player.collisonFlag = TRUE;
			return;//接触を確認したらこの関数から抜ける
		}
		else {
			player.collisonFlag = FALSE;
		}
		i++;
	}

	i = 0;
	while (i < ENEMY_NUM) {
		if (player.data.x == enemyChara[i].data.x  &&   player.data.y == enemyChara[i].data.y) {
			//プレイヤーと敵キャラが同じ座標だったら
			collisonObject = enemyChara[i];
			player.collisonFlag = TRUE;
			return;//接触を確認したらこの関数から抜ける
		}
		else {
			player.collisonFlag = FALSE;
		}
		i++;
	}

}


int searchObjectMyChara() {//プレイヤーと同じマスに何かオブジェクトはあるか
	int i = 0;
	while (i < MYCHARA_NUM) {
		if (player.data.x == myChara[i].data.x  &&   player.data.y == myChara[i].data.y) {
			//プレイヤーと自分のキャラが同じ座標だったら
			player.collisonFlag = TRUE;
			return i;//接触を確認したらこの関数から抜ける
		}
		else {
			player.collisonFlag = FALSE;
		}
		i++;
	}
	return -1;//味方のオブジェクトが見つからなかった場合
}

void decideActionPos() {//actionPosを取得する関数。actionPos....プレイヤーの前の座標

	if (player.data.muki == 0) { player.data.actionPosX = player.data.x; player.data.actionPosY = player.data.y + MAP_SIZE; }//下
	if (player.data.muki == 1) { player.data.actionPosX = player.data.x - MAP_SIZE; player.data.actionPosY = player.data.y; }//左
	if (player.data.muki == 2) { player.data.actionPosX = player.data.x + MAP_SIZE; player.data.actionPosY = player.data.y; }//右
	if (player.data.muki == 3) { player.data.actionPosX = player.data.x; player.data.actionPosY = player.data.y - MAP_SIZE; }//上
	if (player.data.muki == 4) { player.data.actionPosX = player.data.x + MAP_SIZE; player.data.actionPosY = player.data.y - MAP_SIZE; }//右上
	if (player.data.muki == 5) { player.data.actionPosX = player.data.x + MAP_SIZE; player.data.actionPosY = player.data.y + MAP_SIZE; }//右下
	if (player.data.muki == 6) { player.data.actionPosX = player.data.x - MAP_SIZE; player.data.actionPosY = player.data.y - MAP_SIZE; }//左上
	if (player.data.muki == 7) { player.data.actionPosX = player.data.x - MAP_SIZE; player.data.actionPosY = player.data.y + MAP_SIZE; }//左下
																																		//あとで戻り値ありの関数化させたほうがいいかも	

}

void keyPushManage() {
	/*
	//攻撃の管理
	if (keyBuffer[KEY_INPUT_Z] == 1) {
		player.data.attack_flag = 1;//攻撃フラグを立てる
		player.data.walking_flag = 0;
	}
	*/
	


	

	//移動の管理
	//十字移動　　　「↓」「←」「→」「↑」の順
	if (keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0 && keyBuffer[KEY_INPUT_C] == 0)player.data.muki = 0;
	else if (keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0 && keyBuffer[KEY_INPUT_C] == 0)player.data.muki = 1;  //左ボタンが押されたら左向きフラグを立てる
	else if (keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0 && keyBuffer[KEY_INPUT_C] == 0)player.data.muki = 2;//右ボタンが押されたら右向きフラグを立てる
	else if (keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0 && keyBuffer[KEY_INPUT_C] == 0)player.data.muki = 3;//上ボタンが押されたら上向きフラグを立てる
																																  //斜め移動		「右上」「右下」「左上」「左下」の順
	else if (keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1 && keyBuffer[KEY_INPUT_C] == 0)player.data.muki = 4;//右上ボタンが押されたら上向きフラグを立てる
	else if (keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1 && keyBuffer[KEY_INPUT_C] == 0)player.data.muki = 5;//右下ボタンが押されたら上向きフラグを立てる
	else if (keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1 && keyBuffer[KEY_INPUT_C] == 0)player.data.muki = 6;//左上ボタンが押されたら上向きフラグを立てる
	else if (keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1 && keyBuffer[KEY_INPUT_C] == 0)player.data.muki = 7;//左下ボタンが押されたら上向きフラグを立てる
																																									  //その場向き転換の管理
																																									  //十字向き変換　　　「↓」「←」「→」「↑」の順
	else if (keyBuffer[KEY_INPUT_C] == 1 && keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0) player.data.muki = 0, player.data.walking_flag = 0, player.data.nextWalking_flag = 0;//下に向く
	else if (keyBuffer[KEY_INPUT_C] == 1 && keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0) player.data.muki = 1, player.data.walking_flag = 0, player.data.nextWalking_flag = 0;//左に向く
	else if (keyBuffer[KEY_INPUT_C] == 1 && keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0) player.data.muki = 2, player.data.walking_flag = 0, player.data.nextWalking_flag = 0;//右に向く
	else if (keyBuffer[KEY_INPUT_C] == 1 && keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 0) player.data.muki = 3, player.data.walking_flag = 0, player.data.nextWalking_flag = 0;//上に向く
																																																   //斜め向き転換		「右上」「右下」「左上」「左下」の順
	else if (keyBuffer[KEY_INPUT_C] == 1 && keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1) player.data.muki = 4, player.data.walking_flag = 0, player.data.nextWalking_flag = 0;//右上に向く
	else if (keyBuffer[KEY_INPUT_C] == 1 && keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_RIGHT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1) player.data.muki = 5, player.data.walking_flag = 0, player.data.nextWalking_flag = 0;//右下に向く
	else if (keyBuffer[KEY_INPUT_C] == 1 && keyBuffer[KEY_INPUT_UP] == 1 && keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1) player.data.muki = 6, player.data.walking_flag = 0, player.data.nextWalking_flag = 0;//左上に向く
	else if (keyBuffer[KEY_INPUT_C] == 1 && keyBuffer[KEY_INPUT_DOWN] == 1 && keyBuffer[KEY_INPUT_LEFT] == 1 && keyBuffer[KEY_INPUT_LSHIFT] == 1) player.data.muki = 7, player.data.walking_flag = 0, player.data.nextWalking_flag = 0;//左下に向く
	else {
		player.data.walking_flag = 0;//何のボタンも押されてなかったら歩行フラグOFF
		player.data.nextWalking_flag = 0;
	}
}

void getPlayerActState() {//プレイヤーが何もしていない。移動中　などというステートを取得する関数
	/*
	if (player.data.walking_flag == 0 && player.data.attack_flag == 0)player.state.actState = noState;//プレイヤーの入力待ちの状態（noState）
	if (player.data.walking_flag == 1 && player.data.attack_flag == 0) {
		if (player.data.x % MAP_SIZE != 0 || player.data.y % MAP_SIZE != 0)player.state.actState = move_Now;//プレイヤーの座標がピッタリでなかった場合移動している最中(move_Now)の状態
	}
	*/
}


