//#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include "DxLib.h"


#include <string>
#include <iostream>

//------------------パラメータ-----------------------

#define MAP_SIZE	32// マップチップ一つのドットサイズ

#define MAXHEIGHT 75
#define MAXWIDTH 75

#define WINDOW_W 640//幅
#define WINDOW_H 480//高さ
#define CHARA_NUM 20//全キャラの総数
#define MYCHARA_NUM 3//自軍の総数 
#define ENEMY_NUM 5//敵の数


#define ALIVE 0//生きているか
#define DEAD 1//死んでいる



#define ON 0//移動先に移動できるか
#define OFF 1//移動先に移動できるか


//------mainState-----------------
#define TITLE 0//タイトル画面
#define GAME 1//ゲームプレイ中
#define MENU 2//メニュー画面
#define GAMEOVER 3//ゲームオーバー
#define GAMECLEAR 4//ゲームクリアー

//------titleState---------------
#define titleSelect 0//[入学][再登校][退学]の３つ選ぶ状態
#define continueSelect 1//[再登校]を選び、データ選択をする状態（未定・・・・たぶん後回し）



//------actState-----------------------
#define noState 0
#define act_bgein 1
#define act_Now 2
#define act_End 3
#define move_Begin 4
#define move_Now 5
#define move_End 6

//------gameState------------------
#define openGameMenu 7
#define openItemMenu 8



#define WD 150//HPバーの幅

#define startXpos 10*32//画面内でキャラクターが描かれる座標
#define startYpos 8*32//上に同じ

#define chPosX 0		//startXposからnマス移動した位置にキャラクターを配置	//59
#define chPosY 0		//startYposからnマス移動した位置にキャラクターを配置	//13

//-------------------構造体-------------------------


struct Data {
	int x;
	int y;
	int nextPosX;
	int nextPosY;
	int muki;
	int actionPosX;			//プレイヤーの向きに１マス進んだマスのX座標(エンターや攻撃で目の前のオブジェクトにアクションを起こすときに使用)
	int actionPosY;			//プレイヤーの向きに１マス進んだマスのY座標(エンターや攻撃で目の前のオブジェクトにアクションを起こすときに使用)
	int walking_flag;		//歩けるかフラグ
	int nextWalking_flag;	//行き先の更新をしたかフラグ
	int attack_flag;		//攻撃しているかフラグ
	int turnEnd_flag;
	int effectDraw_flag;
	int img;			//歩行グラ配列を格納する変数
	int turn;
	int WG[16];
	int SG;
	char name[20] = "";


};
struct MAP {
	int Switch;
	int MapHeight;
	int MapWidth;
	int tipData[MAXHEIGHT][MAXWIDTH];
	int stageGraph[64];
};

struct Select {
	int titleMenuPointX;
	int titleMenuPointY;
	int openGameMenuPointX;
	int openGameMenuPointY;
};
struct Message {
	char mes[20];
	int x;
	int y;

};



struct Status {
	int plug;
	int rearity;
	int MS;		//moving speed
	int nowMS;
	int canItem;
	int nowCanItem;
	int HP;
	int MAXHP;
	int MP;
	int MAXMP;
	int SP;
	int MAXSP;
	int TP;
	int EXP;
	int MAXEXP;
	int level;
	int POWER;	//腕力
	int MAGIC;	//魔力
	int ATK;	//物理攻撃力
	int DFE;	//物理防御力
	int INT;	//魔法攻撃力
	int RES;	//魔法防御
	int SPD;	//スピード
	int Class;	//職
	int cost;	//コスト
	int range;	//死人範囲
	int hide;	//隠ぺい率
	int money;
};
struct State {
	int deadOrAlive;
	int actState;
};
struct Charactor {
	Data data;
	Status status;
	State state;

};

struct Origin {//すべての元
	Data data;
	Select select;
	int deadOrAlive;
	boolean collisonFlag;
};

struct Effect {
	int x;
	int y;
	int limitTime;
	int time;
	int img;    //エフェクトを格納する配列
};







//main.cppのみここを通る 
#ifdef _GLOBAL_INSTANCE_
//------------------キャラ-------------------------------

Origin player;
Charactor chara[CHARA_NUM];
Charactor myChara[MYCHARA_NUM];
Charactor enemyChara[ENEMY_NUM];
Charactor collisonObject;

//----------------- MAP-------------------------------
MAP stage00;		//ステージ00にステージ00の幅と高さを入れて宣言

int floorNow;			//ステージのフロア　とりま普通にintで
//-----------------WG(歩行グラフィック)画像---------------------------------

int WGplayerGraph[16];
int WGprincessGraph[16];
int WGenemyGraph[16];
//-------------------名前---------------------------------------------------------


//------------------入力・色など---------------------------------------------
char beforeSpaceKey;				//前のタイミングのSPACEキーの状態を格納
char beforeUpKey;				//前のタイミングのSPACEキーの状態を格納
char beforeDownKey;				//前のタイミングのSPACEキーの状態を格納
char beforeRightKey;				//前のタイミングのSPACEキーの状態を格納
char beforeLeftKey;				//前のタイミングのSPACEキーの状態を格納

char keyBuffer[265];				//キーボードの状態を格納
int Cr[10];
Message str;
//-------------------その他　背景----------------------------------------------------------------

int backTitle;
Effect arrow;
int arrowGraph[8];
//-----------------SG　グラフィック（立ち絵）---------------------------

int playerGraph;
int princess;


//------------------マップチップ画像---------------------------------------

int StageGraph00[64];


//------------------状態-----------------------------------------------------------

int mainState;
int titleState;
int gameState;
//----------------エフェクト---------------------------------------------------------

Effect normalAttack;


//----------------ターン管理----------------------------------------------------------

int turn_Now;



//-----------------関数プロトタイプ宣言--------------------------------------------

//■初期化
extern void init();					//初期化処理↓
extern void initGraphic();				//画像読み込み
extern void initOrigin();				//プレイヤーの初期化
extern void initCharactor();			//全キャラの初期化
extern void initMyChara();				//プレイヤの初期化
extern void initEnemy();				//敵の初期化
extern void initMAP();					//マップの初期化
extern void initTitleMenu();			//タイトルメニューのselectの初期化
extern void initOpenGameMenu();		//ゲームメニューのselectの初期化

//■入力
extern void input();					//入力処理

//■更新
extern void updateTitle();				//タイトル画面の更新処理
extern void update();					//更新処理↓
extern void updatePlayer();			//プレイヤー更新処理
extern void searchObject();
extern void decideActionPos();		//actionPosの更新処理
extern void keyPushManage();		//入力可能時になんのキーを押したか判定をひとまとめに
extern void getPlayerActState();
extern void walkingUpdatePlayer(int);//移動の更新処理
extern void attackUpdatePlayer(int, int, int);//攻撃の更新処理
extern int playerIsAbleToGo(int, int, int);				//入力先に移動できるか

extern void updateEnemy();		//敵更新処理
extern void decideAction();
extern int decideDirection(int, int, int, int, int);
extern int moveroot(int, int, int, int,int);
extern void walkingUpdateEnemy(int, int);		//敵の移動処理
extern void attackUpdateEnemy(int, int, int, int);//攻撃の更新処理
extern int EnemyIsAbleToGo(int, int, int, int);				//入力先に移動できるか
extern void updateTurn();
extern void updateGameMenu();			//ゲームメニュー画面の更新
								//void updateMAP();				//ＭＡＰ更新処理

//■描画
extern void draw();					//描画処理↓
extern void drawTitle();				//タイトル描写
extern void drawGmaOver();				//ゲームオーバー描写
extern void drawGameClear();			//ゲームクリア描写
extern void drawPlayer();				//プレイヤー描写
extern void drawMyChara();
extern void drawEnemy(int);				//敵描写
extern void drawMAP(MAP);					//ＭＡＰ描写
extern void objectCollisonDraw();//オリジンとオブジェクトが接触した際に描画される
extern void drawHeightMap();			//ＭＡＰの高レイヤーのグラフィックの描写
extern void drawGameMenu();				//ゲーム画面のメニューを表示
extern void drawConsole();				//ゲーム画面のＨＰバーやテストの座標表記
extern void drawMessage(int);
extern int mapdata00(int i, int j);
extern int mapdata01(int i, int j);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//main.cpp以外ではココを通る////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#else


//キャラ
extern Origin player;
extern Charactor chara[CHARA_NUM];
extern Charactor myChara[MYCHARA_NUM];
extern Charactor enemyChara[ENEMY_NUM];
extern Charactor collisonObject;

//----------------- MAP-------------------------------
					extern MAP stage00;		//ステージ00にステージ00の幅と高さを入れて宣言
					extern int floorNow;			//ステージのフロア　とりま普通にintで
//-----------------WG(歩行グラフィック)画像---------------------------------

					extern int WGplayerGraph[16];
					extern int WGprincessGraph[16];
					extern int WGenemyGraph[16];

//-----------------名前-------------------------------


//------------------入力・色など---------------------------------------------
					extern char beforeSpaceKey;				//前のタイミングのSPACEキーの状態を格納
					extern char beforeUpKey;				//前のタイミングのSPACEキーの状態を格納
					extern char beforeDownKey;				//前のタイミングのSPACEキーの状態を格納
					extern char beforeRightKey;				//前のタイミングのSPACEキーの状態を格納
					extern char beforeLeftKey;				//前のタイミングのSPACEキーの状態を格納

					extern char keyBuffer[265];				//キーボードの状態を格納
					extern int Cr[10];
					extern Message str;
//-------------------その他　背景----------------------------------------------------------------

					extern int backTitle;
					extern int arrowGraph[8];
					extern Effect arrow;
//-----------------キャラグラフィック（立ち絵）---------------------------

					extern int playerGraph;
					extern int princess;


//------------------マップチップ画像---------------------------------------

					extern int StageGraph00[64];


//------------------状態-----------------------------------------------------------

					extern int mainState;
					extern int titleState;
					extern int gameState;

//----------------ターン管理----------------------------------------------------------

					extern int turn_Now;
//----------------エフェクト---------------------------------------------------------

					extern Effect normalAttack;


//-----------------関数プロトタイプ宣言--------------------------------------------

//■初期化
					extern void init();					//初期化処理↓
					extern void initGraphic();				//画像読み込み
					extern void initOrigin();				//プレイヤーの初期化
					extern void initCharactor();			//全キャラの初期化
					extern void initMyChara();				//自分の手札のの初期化
					extern void initEnemy();				//敵の初期化
					extern void initMAP();					//マップの初期化
					extern void initTitleMenu();			//タイトルメニューのselectの初期化
					extern void initOpenGameMenu();		//ゲームメニューのselectの初期化

//■入力
					extern void input();					//入力処理
//■更新
					extern void updateTitle();				//タイトル画面の更新処理
					extern void update();					//更新処理↓
					extern void updatePlayer();			//プレイヤー更新処理
					extern void decideActionPos();		//actionPosの更新処理
					extern void searchObject();
					extern void keyPushManage();		//入力可能時になんのキーを押したか判定をひとまとめに
					extern void getPlayerActState();
					extern void walkingUpdatePlayer(int);//移動の更新処理
					extern void attackUpdatePlayer(int, int, int);//攻撃の更新処理
					extern int playerIsAbleToGo(int, int, int);				//入力先に移動できるか

					extern void updateEnemy();		//敵更新処理
					extern void decideAction();
					extern int decideDirection(int, int, int, int, int);
					extern int moveroot(int, int, int, int, int);
					extern void walkingUpdateEnemy(int, int);		//敵の移動処理
					extern void attackUpdateEnemy(int, int, int, int);//攻撃の更新処理
					extern int EnemyIsAbleToGo(int, int, int, int);				//入力先に移動できるか
					extern void updateTurn();
					extern void updateGameMenu();			//ゲームメニュー画面の更新
															//void updateMAP();				//ＭＡＰ更新処理

//■描画
					extern void draw();					//描画処理↓
					extern void drawTitle();				//タイトル描写
					extern void drawGmaOver();				//ゲームオーバー描写
					extern void drawGameClear();			//ゲームクリア描写
					extern void drawPlayer();				//プレイヤー描写
					extern void drawMyChara();
					extern void drawEnemy(int);				//敵描写
					extern void drawMAP(MAP);					//ＭＡＰ描写
					extern void objectCollisonDraw();//オリジンとオブジェクトが接触した際に描画される
					extern void drawHeightMap();			//ＭＡＰの高レイヤーのグラフィックの描写
					extern void drawGameMenu();				//ゲーム画面のメニューを表示
					extern void drawConsole();				//ゲーム画面のＨＰバーやテストの座標表記
					extern void drawMessage(int);
					extern int mapdata00(int i, int j);
					extern int mapdata01(int i, int j);




#endif // _GLOBAL_INSTANCE_ 



