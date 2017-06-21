#include "../h/GV.h"

//最初に行う初期処理
void init() {

    //上から初期処理を行う
    initGraphic();
    initMAP();
    initOrigin();
    initCharactor();
    initMyChara();
    initEnemy();
    initTitleMenu();
    initOpenGameMenu();
	initMyCharaMenu();
	initTitleMenu();
    mainState = TITLE;
    titleState = titleSelect;
    gameState = noState;
    turn_Now = 1;
}


// 画像の読み込み
void initGraphic() {

    //WG(歩行グラ)
    LoadDivGraph("Pictures/WG/MUKAI.png", 16, 4, 4, 32, 48, WGplayerGraph);
    LoadDivGraph("オ・タサーノ・ヒーメ01.png", 16, 4, 4, 32, 48, WGprincessGraph);
    LoadDivGraph("monster00.png", 16, 4, 4, 32, 48, WGenemyGraph);

    //キャラクターグラフィック
    //princess = LoadGraph("Pictures/SG/オタサーノヒーメ02.png");
    //playerGraph = LoadGraph("Pictures/SG/KODAI MUKAI03.png");

    //マップチップの読み込み
		//ステージ0
		LoadDivGraph("Pictures/MAP/マップチップ01改.png", 64, 8, 8, 32, 32, stage00.stageGraph);




    //背景の描写
    backTitle = LoadGraph("Pictures/BackTitle/タイトル.png");
    LoadDivGraph("Pictures/UI/arrow.png", 8, 4, 2, 32, 32, arrowGraph);


}
//プレイヤーの初期化

void initOrigin() {
    player.data.x = startXpos + chPosX * MAP_SIZE;
    player.data.y = startYpos + chPosY * MAP_SIZE;
    player.data.nextPosX = startXpos + chPosX * MAP_SIZE;//あたり判定に使う変数。32ずつしか変動しない現在いるマスだけを表す
    player.data.nextPosY = startYpos + chPosY * MAP_SIZE;
    player.data.turn = 0;
    player.data.muki = 3;
    player.data.walking_flag = 0;


    player.deadOrAlive = ALIVE;
	player.collisonFlag = FALSE;
	player.mycharaFocus.mycharaFocusflag = FALSE;
	player.mycharaFocus.state = noState;

}

void initCharactor() {
    //---------------------------------------------------------------------------------
	int index = 0;
//①オタサーノヒーメ姫
    chara[index].data.x = 0;
    chara[index].data.y = 0;
    chara[index].data.muki = 3;
    chara[index].data.walking_flag = 0;
    chara[index].data.SG = LoadGraph("Pictures/SG/オタサーノヒーメ02.png");
    LoadDivGraph("オ・タサーノ・ヒーメ01.png", 16, 4, 4, 32, 48, chara[index].data.WG);
    char name[] = "オタサーノヒーメ";
    strcpy_s(chara[index].data.name, name);     /* 文字型配列に文字型配列をコピー */

    //-------ステータス初期化--------------
	chara[index].status.plug = 0;		//
	chara[index].status.rearity = 10;	//レアリティ
	chara[index].status.MS = 2;			//移動できるマス（固定）
	chara[index].status.nowMS = 2;		//今移動できるマス
	chara[index].status.canItem = 1;	//持てるアイテムの最大数（固定）
	chara[index].status.nowCanItem = 1;	//今持てるアイテムの数
	chara[index].status.HP = 60;		//HP
    chara[index].status.MAXHP = 60;		//MAXHP
    chara[index].status.MP = 150;		//MP
    chara[index].status.MAXMP = 150;	//MAXMP
    chara[index].status.SP = 20;		//SP
    chara[index].status.MAXSP = 20;		//MAXSP
    chara[index].status.TP = 3;			//TP
    chara[index].status.EXP = 0;		//EXP
    chara[index].status.MAXEXP = 100;	//MAXEXP
    chara[index].status.level = 1;		//LV
	chara[index].status.POWER = 3;		//腕力
	chara[index].status.MAGIC = 1;		//魔力
    chara[index].status.ATK = 4;		//物理攻撃力
    chara[index].status.DFE = 0;		//物理防御力
	chara[index].status.INT = 1;		//魔法攻撃力
	chara[index].status.RES = 1;		//魔法防御力
	chara[index].status.SPD = 5;		//スピード
	chara[index].status.Class = 0;		//職
	chara[index].status.cost = 10;		//コスト
	chara[index].status.range = 5;		//視認範囲
	chara[index].status.hide = 2;		//隠ぺい率
    chara[index].status.money = 100;	//金
    //---------------------------------------------------------------------------------------
	index++;
    //---------------------------------------------------------------------------------
//②KOUDAI MUKAI
	chara[index].data.x = 0;
	chara[index].data.y = 0;
	chara[index].data.muki = 3;
	chara[index].data.walking_flag = 0;
	chara[index].data.SG = LoadGraph("Pictures/SG/KODAI MUKAI03.png");
	LoadDivGraph("MUKAI.png", 16, 4, 4, 32, 48, chara[index].data.WG);
	char name1[] = "KODAI MUKAI";
	strcpy_s(chara[index].data.name, name1);     /* 文字型配列に文字型配列をコピー */

	//-------ステータス初期化--------------
	chara[index].status.plug = 0;		//
	chara[index].status.rearity = 5;	//レアリティ
	chara[index].status.MS = 1;			//移動できるマス（固定）
	chara[index].status.nowMS = 1;		//今移動できるマス
	chara[index].status.canItem = 1;	//持てるアイテムの最大数（固定）
	chara[index].status.nowCanItem = 1;	//今持てるアイテムの数
	chara[index].status.HP = 80;		//HP
	chara[index].status.MAXHP = 80;		//MAXHP
	chara[index].status.MP = 20;		//MP
	chara[index].status.MAXMP = 20;	//MAXMP
	chara[index].status.SP = 40;		//SP
	chara[index].status.MAXSP = 40;		//MAXSP
	chara[index].status.TP = 3;			//TP
	chara[index].status.EXP = 0;		//EXP
	chara[index].status.MAXEXP = 100;	//MAXEXP
	chara[index].status.level = 1;		//LV
	chara[index].status.POWER = 4;		//腕力
	chara[index].status.MAGIC = 1;		//魔力
	chara[index].status.ATK = 5;		//物理攻撃力
	chara[index].status.DFE = 3;		//物理防御力
	chara[index].status.INT = 1;		//魔法攻撃力
	chara[index].status.RES = 1;		//魔法防御力
	chara[index].status.SPD = 8;		//スピード
	chara[index].status.Class = 0;		//職
	chara[index].status.cost = 15;		//コスト
	chara[index].status.range = 7;		//視認範囲
	chara[index].status.hide = 1;		//隠ぺい率
	chara[index].status.money = 100;	//金
	//---------------------------------------------------------------------------------------
	index++;
	//---------------------------------------------------------------------------------------

//③ゾンビ
	chara[index].data.x = 0;
	chara[index].data.y = 0;
	chara[index].data.muki = 3;
	chara[index].data.walking_flag = 0;
	chara[index].data.SG = LoadGraph("Pictures/SG/★ゾンビ１.png");
	LoadDivGraph("monster00.png", 16, 4, 4, 32, 48, chara[index].data.WG);
	char name2[] = "ゾンビ";
	strcpy_s(chara[index].data.name, name2);     /* 文字型配列に文字型配列をコピー */

    //-------ステータス初期化--------------
	chara[index].status.plug = 0;		//
	chara[index].status.rearity = 2;	//レアリティ
	chara[index].status.MS = 1;			//移動できるマス（固定）
	chara[index].status.nowMS = 1;		//今移動できるマス
	chara[index].status.canItem = 1;	//持てるアイテムの最大数（固定）
	chara[index].status.nowCanItem = 1;	//今持てるアイテムの数
	chara[index].status.HP = 30;		//HP
	chara[index].status.MAXHP = 30;		//MAXHP
	chara[index].status.MP = 1;		//MP
	chara[index].status.MAXMP = 1;	//MAXMP
	chara[index].status.SP = 20;		//SP
	chara[index].status.MAXSP = 20;		//MAXSP
	chara[index].status.TP = 3;			//TP
	chara[index].status.EXP = 0;		//EXP
	chara[index].status.MAXEXP = 40;	//MAXEXP
	chara[index].status.level = 1;		//LV
	chara[index].status.POWER = 3;		//腕力
	chara[index].status.MAGIC = 1;		//魔力
	chara[index].status.ATK = 2;		//物理攻撃力
	chara[index].status.DFE = 0;		//物理防御力
	chara[index].status.INT = 0;		//魔法攻撃力
	chara[index].status.RES = 0;		//魔法防御力
	chara[index].status.SPD = 3;		//スピード
	chara[index].status.Class = 0;		//職
	chara[index].status.cost = 5;		//コスト
	chara[index].status.range = 5;		//視認範囲
	chara[index].status.hide = 2;		//隠ぺい率
	chara[index].status.money = 100;	//金
	//---------------------------------------------------------------------------------------
	//index++;
	//---------------------------------------------------------------------------------------


}



//キャラクターの初期化
void initMyChara() {
    
		myChara[0] = chara[0];
		myChara[1] = chara[1];
		myChara[2] = chara[1];
   
    int i = 0;
    while (i < MYCHARA_NUM) {

        myChara[i].data.x = GetRand(17) * MAP_SIZE;
        myChara[i].data.y = GetRand(17) * MAP_SIZE;
		if (stage00.tipData[myChara[i].data.y / MAP_SIZE][myChara[i].data.x / MAP_SIZE] != 1)continue;
		myChara[i].state.deadOrAlive = ALIVE;
		myChara[i].data.muki = GetRand(3);
        myChara[i].data.nextPosX = myChara[i].data.x;//あたり判定に使う変数。32ずつしか変動しない現在いるマスだけを表す
        myChara[i].data.nextPosY = myChara[i].data.y;
		myChara[i].data.nextWalking_flag = 0;
       

        i++;
    }

    collisonObject = myChara[1];
}

//敵の初期化
void initEnemy() {
    int i = 0;
    while (i < ENEMY_NUM) {
		enemyChara[i] = chara[2];

        enemyChara[i].data.x = GetRand(17) * MAP_SIZE;
        enemyChara[i].data.y = GetRand(17) * MAP_SIZE;
		if (stage00.tipData[enemyChara[i].data.y / MAP_SIZE][enemyChara[i].data.x / MAP_SIZE] != 1)continue;
        enemyChara[i].state.deadOrAlive = ALIVE;
        enemyChara[i].data.muki = GetRand(3);
        enemyChara[i].data.nextPosX = enemyChara[i].data.x;//あたり判定に使う変数。32ずつしか変動しない現在いるマスだけを表す
        enemyChara[i].data.nextPosY = enemyChara[i].data.y;
        enemyChara[i].data.nextWalking_flag = 0;



        i++;
    }

}

//マイキャラ単体のnowMSを初期化
void initMS(int index) {

		myChara[index].status.nowMS = myChara[index].status.MS;		//今移動できるマス

}

//MAPの初期化
void initMAP() {
    stage00.Switch = ON;

    //ステージ００のマップデータ00（map.cpp）を入れる。
    for (int i = 0; i < MAXHEIGHT; i++) {//mapデータ読み込み
        for (int j = 0; j < MAXWIDTH; j++) {
            stage00.tipData[i][j] = mapdata00(i, j);
        }
    }
    
    floorNow = 1;
}

//タイトルメニューのselectの座標の初期化
void initTitleMenu() {

    player.select.titleMenuPointX = 280;//タイトルメニューのslectの初期座標
    player.select.titleMenuPointY = 300;//タイトルメニューのslectの初期座標

}

//ゲームメニューのselectの座標の初期化
void initOpenGameMenu() {
    player.select.openGameMenuPointX = 13;//ゲームメニューのslectの初期座標
    player.select.openGameMenuPointY = 45;

}

void initMyCharaMenu() {
	player.select.openMyCharaMenuPointX = 500;//ゲームメニューのslectの初期座標
	player.select.openMyCharaMenuPointY = 50;
	player.mycharaFocus.selectIndex = 0;
}


void initGetMyCharaMoveData() {
	myChara[player.collisonObjectkind].data.initPosX = myChara[player.collisonObjectkind].data.x;
	myChara[player.collisonObjectkind].data.initPosY = myChara[player.collisonObjectkind].data.y;
	myChara[player.collisonObjectkind].data.initmuki = myChara[player.collisonObjectkind].data.muki;
	myChara[player.collisonObjectkind].status.initMS = myChara[player.collisonObjectkind].status.nowMS;
	player.data.initPosX = player.data.x;
	player.data.initPosY = player.data.y;


}

void initSetMyCharaMoveData() {
	myChara[player.collisonObjectkind].data.x = myChara[player.collisonObjectkind].data.initPosX;
	myChara[player.collisonObjectkind].data.y = myChara[player.collisonObjectkind].data.initPosY;
	myChara[player.collisonObjectkind].data.nextPosX = myChara[player.collisonObjectkind].data.initPosX;
	myChara[player.collisonObjectkind].data.nextPosY = myChara[player.collisonObjectkind].data.initPosY;

	myChara[player.collisonObjectkind].data.muki = myChara[player.collisonObjectkind].data.initmuki;
	myChara[player.collisonObjectkind].status.nowMS = myChara[player.collisonObjectkind].status.initMS;
	player.data.x = player.data.initPosX;
	player.data.y = player.data.initPosY;
	//動的に残り移動可能マスを変化
	collisonObject.status.nowMS = myChara[player.collisonObjectkind].status.nowMS;
}

void initAllMyCharaNowMS() {
	for (int i = 0; i < MYCHARA_NUM; i++) {
		myChara[i].status.nowMS = myChara[i].status.MS;
	}
}

