#include "../h/GV.h"

//�ŏ��ɍs����������
void init() {

    //�ォ�珉���������s��
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


// �摜�̓ǂݍ���
void initGraphic() {

    //WG(���s�O��)
    LoadDivGraph("Pictures/WG/MUKAI.png", 16, 4, 4, 32, 48, WGplayerGraph);
    LoadDivGraph("�I�E�^�T�[�m�E�q�[��01.png", 16, 4, 4, 32, 48, WGprincessGraph);
    LoadDivGraph("monster00.png", 16, 4, 4, 32, 48, WGenemyGraph);

    //�L�����N�^�[�O���t�B�b�N
    //princess = LoadGraph("Pictures/SG/�I�^�T�[�m�q�[��02.png");
    //playerGraph = LoadGraph("Pictures/SG/KODAI MUKAI03.png");

    //�}�b�v�`�b�v�̓ǂݍ���
		//�X�e�[�W0
		LoadDivGraph("Pictures/MAP/�}�b�v�`�b�v01��.png", 64, 8, 8, 32, 32, stage00.stageGraph);




    //�w�i�̕`��
    backTitle = LoadGraph("Pictures/BackTitle/�^�C�g��.png");
    LoadDivGraph("Pictures/UI/arrow.png", 8, 4, 2, 32, 32, arrowGraph);


}
//�v���C���[�̏�����

void initOrigin() {
    player.data.x = startXpos + chPosX * MAP_SIZE;
    player.data.y = startYpos + chPosY * MAP_SIZE;
    player.data.nextPosX = startXpos + chPosX * MAP_SIZE;//�����蔻��Ɏg���ϐ��B32�������ϓ����Ȃ����݂���}�X������\��
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
//�@�I�^�T�[�m�q�[���P
    chara[index].data.x = 0;
    chara[index].data.y = 0;
    chara[index].data.muki = 3;
    chara[index].data.walking_flag = 0;
    chara[index].data.SG = LoadGraph("Pictures/SG/�I�^�T�[�m�q�[��02.png");
    LoadDivGraph("�I�E�^�T�[�m�E�q�[��01.png", 16, 4, 4, 32, 48, chara[index].data.WG);
    char name[] = "�I�^�T�[�m�q�[��";
    strcpy_s(chara[index].data.name, name);     /* �����^�z��ɕ����^�z����R�s�[ */

    //-------�X�e�[�^�X������--------------
	chara[index].status.plug = 0;		//
	chara[index].status.rearity = 10;	//���A���e�B
	chara[index].status.MS = 2;			//�ړ��ł���}�X�i�Œ�j
	chara[index].status.nowMS = 2;		//���ړ��ł���}�X
	chara[index].status.canItem = 1;	//���Ă�A�C�e���̍ő吔�i�Œ�j
	chara[index].status.nowCanItem = 1;	//�����Ă�A�C�e���̐�
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
	chara[index].status.POWER = 3;		//�r��
	chara[index].status.MAGIC = 1;		//����
    chara[index].status.ATK = 4;		//�����U����
    chara[index].status.DFE = 0;		//�����h���
	chara[index].status.INT = 1;		//���@�U����
	chara[index].status.RES = 1;		//���@�h���
	chara[index].status.SPD = 5;		//�X�s�[�h
	chara[index].status.Class = 0;		//�E
	chara[index].status.cost = 10;		//�R�X�g
	chara[index].status.range = 5;		//���F�͈�
	chara[index].status.hide = 2;		//�B�؂���
    chara[index].status.money = 100;	//��
    //---------------------------------------------------------------------------------------
	index++;
    //---------------------------------------------------------------------------------
//�AKOUDAI MUKAI
	chara[index].data.x = 0;
	chara[index].data.y = 0;
	chara[index].data.muki = 3;
	chara[index].data.walking_flag = 0;
	chara[index].data.SG = LoadGraph("Pictures/SG/KODAI MUKAI03.png");
	LoadDivGraph("MUKAI.png", 16, 4, 4, 32, 48, chara[index].data.WG);
	char name1[] = "KODAI MUKAI";
	strcpy_s(chara[index].data.name, name1);     /* �����^�z��ɕ����^�z����R�s�[ */

	//-------�X�e�[�^�X������--------------
	chara[index].status.plug = 0;		//
	chara[index].status.rearity = 5;	//���A���e�B
	chara[index].status.MS = 1;			//�ړ��ł���}�X�i�Œ�j
	chara[index].status.nowMS = 1;		//���ړ��ł���}�X
	chara[index].status.canItem = 1;	//���Ă�A�C�e���̍ő吔�i�Œ�j
	chara[index].status.nowCanItem = 1;	//�����Ă�A�C�e���̐�
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
	chara[index].status.POWER = 4;		//�r��
	chara[index].status.MAGIC = 1;		//����
	chara[index].status.ATK = 5;		//�����U����
	chara[index].status.DFE = 3;		//�����h���
	chara[index].status.INT = 1;		//���@�U����
	chara[index].status.RES = 1;		//���@�h���
	chara[index].status.SPD = 8;		//�X�s�[�h
	chara[index].status.Class = 0;		//�E
	chara[index].status.cost = 15;		//�R�X�g
	chara[index].status.range = 7;		//���F�͈�
	chara[index].status.hide = 1;		//�B�؂���
	chara[index].status.money = 100;	//��
	//---------------------------------------------------------------------------------------
	index++;
	//---------------------------------------------------------------------------------------

//�B�]���r
	chara[index].data.x = 0;
	chara[index].data.y = 0;
	chara[index].data.muki = 3;
	chara[index].data.walking_flag = 0;
	chara[index].data.SG = LoadGraph("Pictures/SG/���]���r�P.png");
	LoadDivGraph("monster00.png", 16, 4, 4, 32, 48, chara[index].data.WG);
	char name2[] = "�]���r";
	strcpy_s(chara[index].data.name, name2);     /* �����^�z��ɕ����^�z����R�s�[ */

    //-------�X�e�[�^�X������--------------
	chara[index].status.plug = 0;		//
	chara[index].status.rearity = 2;	//���A���e�B
	chara[index].status.MS = 1;			//�ړ��ł���}�X�i�Œ�j
	chara[index].status.nowMS = 1;		//���ړ��ł���}�X
	chara[index].status.canItem = 1;	//���Ă�A�C�e���̍ő吔�i�Œ�j
	chara[index].status.nowCanItem = 1;	//�����Ă�A�C�e���̐�
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
	chara[index].status.POWER = 3;		//�r��
	chara[index].status.MAGIC = 1;		//����
	chara[index].status.ATK = 2;		//�����U����
	chara[index].status.DFE = 0;		//�����h���
	chara[index].status.INT = 0;		//���@�U����
	chara[index].status.RES = 0;		//���@�h���
	chara[index].status.SPD = 3;		//�X�s�[�h
	chara[index].status.Class = 0;		//�E
	chara[index].status.cost = 5;		//�R�X�g
	chara[index].status.range = 5;		//���F�͈�
	chara[index].status.hide = 2;		//�B�؂���
	chara[index].status.money = 100;	//��
	//---------------------------------------------------------------------------------------
	//index++;
	//---------------------------------------------------------------------------------------


}



//�L�����N�^�[�̏�����
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
        myChara[i].data.nextPosX = myChara[i].data.x;//�����蔻��Ɏg���ϐ��B32�������ϓ����Ȃ����݂���}�X������\��
        myChara[i].data.nextPosY = myChara[i].data.y;
		myChara[i].data.nextWalking_flag = 0;
       

        i++;
    }

    collisonObject = myChara[1];
}

//�G�̏�����
void initEnemy() {
    int i = 0;
    while (i < ENEMY_NUM) {
		enemyChara[i] = chara[2];

        enemyChara[i].data.x = GetRand(17) * MAP_SIZE;
        enemyChara[i].data.y = GetRand(17) * MAP_SIZE;
		if (stage00.tipData[enemyChara[i].data.y / MAP_SIZE][enemyChara[i].data.x / MAP_SIZE] != 1)continue;
        enemyChara[i].state.deadOrAlive = ALIVE;
        enemyChara[i].data.muki = GetRand(3);
        enemyChara[i].data.nextPosX = enemyChara[i].data.x;//�����蔻��Ɏg���ϐ��B32�������ϓ����Ȃ����݂���}�X������\��
        enemyChara[i].data.nextPosY = enemyChara[i].data.y;
        enemyChara[i].data.nextWalking_flag = 0;



        i++;
    }

}

//�}�C�L�����P�̂�nowMS��������
void initMS(int index) {

		myChara[index].status.nowMS = myChara[index].status.MS;		//���ړ��ł���}�X

}

//MAP�̏�����
void initMAP() {
    stage00.Switch = ON;

    //�X�e�[�W�O�O�̃}�b�v�f�[�^00�imap.cpp�j������B
    for (int i = 0; i < MAXHEIGHT; i++) {//map�f�[�^�ǂݍ���
        for (int j = 0; j < MAXWIDTH; j++) {
            stage00.tipData[i][j] = mapdata00(i, j);
        }
    }
    
    floorNow = 1;
}

//�^�C�g�����j���[��select�̍��W�̏�����
void initTitleMenu() {

    player.select.titleMenuPointX = 280;//�^�C�g�����j���[��slect�̏������W
    player.select.titleMenuPointY = 300;//�^�C�g�����j���[��slect�̏������W

}

//�Q�[�����j���[��select�̍��W�̏�����
void initOpenGameMenu() {
    player.select.openGameMenuPointX = 13;//�Q�[�����j���[��slect�̏������W
    player.select.openGameMenuPointY = 45;

}

void initMyCharaMenu() {
	player.select.openMyCharaMenuPointX = 500;//�Q�[�����j���[��slect�̏������W
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
	//���I�Ɏc��ړ��\�}�X��ω�
	collisonObject.status.nowMS = myChara[player.collisonObjectkind].status.nowMS;
}

void initAllMyCharaNowMS() {
	for (int i = 0; i < MYCHARA_NUM; i++) {
		myChara[i].status.nowMS = myChara[i].status.MS;
	}
}

