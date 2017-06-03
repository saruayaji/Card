//#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include "DxLib.h"


#include <string>
#include <iostream>

//------------------�p�����[�^-----------------------

#define MAP_SIZE	32// �}�b�v�`�b�v��̃h�b�g�T�C�Y

#define MAXHEIGHT 75
#define MAXWIDTH 75

#define WINDOW_W 640//��
#define WINDOW_H 480//����
#define CHARA_NUM 20//�S�L�����̑���
#define MYCHARA_NUM 3//���R�̑��� 
#define ENEMY_NUM 5//�G�̐�


#define ALIVE 0//�����Ă��邩
#define DEAD 1//����ł���



#define ON 0//�ړ���Ɉړ��ł��邩
#define OFF 1//�ړ���Ɉړ��ł��邩


//------mainState-----------------
#define TITLE 0//�^�C�g�����
#define GAME 1//�Q�[���v���C��
#define MENU 2//���j���[���
#define GAMEOVER 3//�Q�[���I�[�o�[
#define GAMECLEAR 4//�Q�[���N���A�[

//------titleState---------------
#define titleSelect 0//[���w][�ēo�Z][�ފw]�̂R�I�ԏ��
#define continueSelect 1//[�ēo�Z]��I�сA�f�[�^�I���������ԁi����E�E�E�E���Ԃ��񂵁j



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



#define WD 150//HP�o�[�̕�

#define startXpos 10*32//��ʓ��ŃL�����N�^�[���`�������W
#define startYpos 8*32//��ɓ���

#define chPosX 0		//startXpos����n�}�X�ړ������ʒu�ɃL�����N�^�[��z�u	//59
#define chPosY 0		//startYpos����n�}�X�ړ������ʒu�ɃL�����N�^�[��z�u	//13

//-------------------�\����-------------------------


struct Data {
	int x;
	int y;
	int nextPosX;
	int nextPosY;
	int muki;
	int actionPosX;			//�v���C���[�̌����ɂP�}�X�i�񂾃}�X��X���W(�G���^�[��U���Ŗڂ̑O�̃I�u�W�F�N�g�ɃA�N�V�������N�����Ƃ��Ɏg�p)
	int actionPosY;			//�v���C���[�̌����ɂP�}�X�i�񂾃}�X��Y���W(�G���^�[��U���Ŗڂ̑O�̃I�u�W�F�N�g�ɃA�N�V�������N�����Ƃ��Ɏg�p)
	int walking_flag;		//�����邩�t���O
	int nextWalking_flag;	//�s����̍X�V���������t���O
	int attack_flag;		//�U�����Ă��邩�t���O
	int turnEnd_flag;
	int effectDraw_flag;
	int img;			//���s�O���z����i�[����ϐ�
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
	int POWER;	//�r��
	int MAGIC;	//����
	int ATK;	//�����U����
	int DFE;	//�����h���
	int INT;	//���@�U����
	int RES;	//���@�h��
	int SPD;	//�X�s�[�h
	int Class;	//�E
	int cost;	//�R�X�g
	int range;	//���l�͈�
	int hide;	//�B�؂���
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

struct Origin {//���ׂĂ̌�
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
	int img;    //�G�t�F�N�g���i�[����z��
};







//main.cpp�݂̂�����ʂ� 
#ifdef _GLOBAL_INSTANCE_
//------------------�L����-------------------------------

Origin player;
Charactor chara[CHARA_NUM];
Charactor myChara[MYCHARA_NUM];
Charactor enemyChara[ENEMY_NUM];
Charactor collisonObject;

//----------------- MAP-------------------------------
MAP stage00;		//�X�e�[�W00�ɃX�e�[�W00�̕��ƍ��������Đ錾

int floorNow;			//�X�e�[�W�̃t���A�@�Ƃ�ܕ��ʂ�int��
//-----------------WG(���s�O���t�B�b�N)�摜---------------------------------

int WGplayerGraph[16];
int WGprincessGraph[16];
int WGenemyGraph[16];
//-------------------���O---------------------------------------------------------


//------------------���́E�F�Ȃ�---------------------------------------------
char beforeSpaceKey;				//�O�̃^�C�~���O��SPACE�L�[�̏�Ԃ��i�[
char beforeUpKey;				//�O�̃^�C�~���O��SPACE�L�[�̏�Ԃ��i�[
char beforeDownKey;				//�O�̃^�C�~���O��SPACE�L�[�̏�Ԃ��i�[
char beforeRightKey;				//�O�̃^�C�~���O��SPACE�L�[�̏�Ԃ��i�[
char beforeLeftKey;				//�O�̃^�C�~���O��SPACE�L�[�̏�Ԃ��i�[

char keyBuffer[265];				//�L�[�{�[�h�̏�Ԃ��i�[
int Cr[10];
Message str;
//-------------------���̑��@�w�i----------------------------------------------------------------

int backTitle;
Effect arrow;
int arrowGraph[8];
//-----------------SG�@�O���t�B�b�N�i�����G�j---------------------------

int playerGraph;
int princess;


//------------------�}�b�v�`�b�v�摜---------------------------------------

int StageGraph00[64];


//------------------���-----------------------------------------------------------

int mainState;
int titleState;
int gameState;
//----------------�G�t�F�N�g---------------------------------------------------------

Effect normalAttack;


//----------------�^�[���Ǘ�----------------------------------------------------------

int turn_Now;



//-----------------�֐��v���g�^�C�v�錾--------------------------------------------

//��������
extern void init();					//������������
extern void initGraphic();				//�摜�ǂݍ���
extern void initOrigin();				//�v���C���[�̏�����
extern void initCharactor();			//�S�L�����̏�����
extern void initMyChara();				//�v���C���̏�����
extern void initEnemy();				//�G�̏�����
extern void initMAP();					//�}�b�v�̏�����
extern void initTitleMenu();			//�^�C�g�����j���[��select�̏�����
extern void initOpenGameMenu();		//�Q�[�����j���[��select�̏�����

//������
extern void input();					//���͏���

//���X�V
extern void updateTitle();				//�^�C�g����ʂ̍X�V����
extern void update();					//�X�V������
extern void updatePlayer();			//�v���C���[�X�V����
extern void searchObject();
extern void decideActionPos();		//actionPos�̍X�V����
extern void keyPushManage();		//���͉\���ɂȂ�̃L�[����������������ЂƂ܂Ƃ߂�
extern void getPlayerActState();
extern void walkingUpdatePlayer(int);//�ړ��̍X�V����
extern void attackUpdatePlayer(int, int, int);//�U���̍X�V����
extern int playerIsAbleToGo(int, int, int);				//���͐�Ɉړ��ł��邩

extern void updateEnemy();		//�G�X�V����
extern void decideAction();
extern int decideDirection(int, int, int, int, int);
extern int moveroot(int, int, int, int,int);
extern void walkingUpdateEnemy(int, int);		//�G�̈ړ�����
extern void attackUpdateEnemy(int, int, int, int);//�U���̍X�V����
extern int EnemyIsAbleToGo(int, int, int, int);				//���͐�Ɉړ��ł��邩
extern void updateTurn();
extern void updateGameMenu();			//�Q�[�����j���[��ʂ̍X�V
								//void updateMAP();				//�l�`�o�X�V����

//���`��
extern void draw();					//�`�揈����
extern void drawTitle();				//�^�C�g���`��
extern void drawGmaOver();				//�Q�[���I�[�o�[�`��
extern void drawGameClear();			//�Q�[���N���A�`��
extern void drawPlayer();				//�v���C���[�`��
extern void drawMyChara();
extern void drawEnemy(int);				//�G�`��
extern void drawMAP(MAP);					//�l�`�o�`��
extern void objectCollisonDraw();//�I���W���ƃI�u�W�F�N�g���ڐG�����ۂɕ`�悳���
extern void drawHeightMap();			//�l�`�o�̍����C���[�̃O���t�B�b�N�̕`��
extern void drawGameMenu();				//�Q�[����ʂ̃��j���[��\��
extern void drawConsole();				//�Q�[����ʂ̂g�o�o�[��e�X�g�̍��W�\�L
extern void drawMessage(int);
extern int mapdata00(int i, int j);
extern int mapdata01(int i, int j);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//main.cpp�ȊO�ł̓R�R��ʂ�////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#else


//�L����
extern Origin player;
extern Charactor chara[CHARA_NUM];
extern Charactor myChara[MYCHARA_NUM];
extern Charactor enemyChara[ENEMY_NUM];
extern Charactor collisonObject;

//----------------- MAP-------------------------------
					extern MAP stage00;		//�X�e�[�W00�ɃX�e�[�W00�̕��ƍ��������Đ錾
					extern int floorNow;			//�X�e�[�W�̃t���A�@�Ƃ�ܕ��ʂ�int��
//-----------------WG(���s�O���t�B�b�N)�摜---------------------------------

					extern int WGplayerGraph[16];
					extern int WGprincessGraph[16];
					extern int WGenemyGraph[16];

//-----------------���O-------------------------------


//------------------���́E�F�Ȃ�---------------------------------------------
					extern char beforeSpaceKey;				//�O�̃^�C�~���O��SPACE�L�[�̏�Ԃ��i�[
					extern char beforeUpKey;				//�O�̃^�C�~���O��SPACE�L�[�̏�Ԃ��i�[
					extern char beforeDownKey;				//�O�̃^�C�~���O��SPACE�L�[�̏�Ԃ��i�[
					extern char beforeRightKey;				//�O�̃^�C�~���O��SPACE�L�[�̏�Ԃ��i�[
					extern char beforeLeftKey;				//�O�̃^�C�~���O��SPACE�L�[�̏�Ԃ��i�[

					extern char keyBuffer[265];				//�L�[�{�[�h�̏�Ԃ��i�[
					extern int Cr[10];
					extern Message str;
//-------------------���̑��@�w�i----------------------------------------------------------------

					extern int backTitle;
					extern int arrowGraph[8];
					extern Effect arrow;
//-----------------�L�����O���t�B�b�N�i�����G�j---------------------------

					extern int playerGraph;
					extern int princess;


//------------------�}�b�v�`�b�v�摜---------------------------------------

					extern int StageGraph00[64];


//------------------���-----------------------------------------------------------

					extern int mainState;
					extern int titleState;
					extern int gameState;

//----------------�^�[���Ǘ�----------------------------------------------------------

					extern int turn_Now;
//----------------�G�t�F�N�g---------------------------------------------------------

					extern Effect normalAttack;


//-----------------�֐��v���g�^�C�v�錾--------------------------------------------

//��������
					extern void init();					//������������
					extern void initGraphic();				//�摜�ǂݍ���
					extern void initOrigin();				//�v���C���[�̏�����
					extern void initCharactor();			//�S�L�����̏�����
					extern void initMyChara();				//�����̎�D�̂̏�����
					extern void initEnemy();				//�G�̏�����
					extern void initMAP();					//�}�b�v�̏�����
					extern void initTitleMenu();			//�^�C�g�����j���[��select�̏�����
					extern void initOpenGameMenu();		//�Q�[�����j���[��select�̏�����

//������
					extern void input();					//���͏���
//���X�V
					extern void updateTitle();				//�^�C�g����ʂ̍X�V����
					extern void update();					//�X�V������
					extern void updatePlayer();			//�v���C���[�X�V����
					extern void decideActionPos();		//actionPos�̍X�V����
					extern void searchObject();
					extern void keyPushManage();		//���͉\���ɂȂ�̃L�[����������������ЂƂ܂Ƃ߂�
					extern void getPlayerActState();
					extern void walkingUpdatePlayer(int);//�ړ��̍X�V����
					extern void attackUpdatePlayer(int, int, int);//�U���̍X�V����
					extern int playerIsAbleToGo(int, int, int);				//���͐�Ɉړ��ł��邩

					extern void updateEnemy();		//�G�X�V����
					extern void decideAction();
					extern int decideDirection(int, int, int, int, int);
					extern int moveroot(int, int, int, int, int);
					extern void walkingUpdateEnemy(int, int);		//�G�̈ړ�����
					extern void attackUpdateEnemy(int, int, int, int);//�U���̍X�V����
					extern int EnemyIsAbleToGo(int, int, int, int);				//���͐�Ɉړ��ł��邩
					extern void updateTurn();
					extern void updateGameMenu();			//�Q�[�����j���[��ʂ̍X�V
															//void updateMAP();				//�l�`�o�X�V����

//���`��
					extern void draw();					//�`�揈����
					extern void drawTitle();				//�^�C�g���`��
					extern void drawGmaOver();				//�Q�[���I�[�o�[�`��
					extern void drawGameClear();			//�Q�[���N���A�`��
					extern void drawPlayer();				//�v���C���[�`��
					extern void drawMyChara();
					extern void drawEnemy(int);				//�G�`��
					extern void drawMAP(MAP);					//�l�`�o�`��
					extern void objectCollisonDraw();//�I���W���ƃI�u�W�F�N�g���ڐG�����ۂɕ`�悳���
					extern void drawHeightMap();			//�l�`�o�̍����C���[�̃O���t�B�b�N�̕`��
					extern void drawGameMenu();				//�Q�[����ʂ̃��j���[��\��
					extern void drawConsole();				//�Q�[����ʂ̂g�o�o�[��e�X�g�̍��W�\�L
					extern void drawMessage(int);
					extern int mapdata00(int i, int j);
					extern int mapdata01(int i, int j);




#endif // _GLOBAL_INSTANCE_ 



