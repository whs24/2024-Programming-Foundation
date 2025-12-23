 // PuzzleGame.cpp : 定义应用程序的入口点。
//

#include "PuzzleGame.h"
using namespace std;
#include <string.h>
#define MAX_LOADSTRING 100
#include <chrono>

//音效函数
void yinxiaotansuo(int a);
void yinxiaojingyan(int a);
void yinxiaogongji(int a);
void yinxiaoshoushang(int a);
void yinxiaokuqi(int a);


// 获取当前时间（秒）
double GetTime() {
	return clock();
	return std::chrono::duration<double>(std::chrono::system_clock::now().time_since_epoch()).count();
}


// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名
int kaishi = 0;
HBITMAP bmp_StartButton;	//开始按钮图像资源
HBITMAP bmp_HelpButton;		//帮助按钮图像资源
HBITMAP bmp_BackButton;		//back按钮图像资源
HBITMAP bmp_RestartButton;	//restart按钮图像资源
HBITMAP bmp_BacktotitleButton;		//btt按钮图像资源
HBITMAP bmp_ContinueButton;		//continue按钮图像资源
HBITMAP bmp_Player;			//玩家图像
HBITMAP bmp_NPC_MAN1;		//各位NPC图像
HBITMAP bmp_Background;		//生成的背景图像
HBITMAP bmp_Pause;		//生成的暂停图像
HBITMAP bmp_HELP1;			//生成的帮助界面图像
HBITMAP bmp_map;			//地图砖块图像
HBITMAP bmp_dialog;			//对话框背景图像
HBITMAP bmp_monster1;		//怪物1图像
HBITMAP bmp_attack;			//攻击特效图像
HBITMAP bmp_attack2;			//攻击特效图像
HBITMAP bmp_slime;		//slime图像
HBITMAP bmp_racoon;		//racoon图像
HBITMAP bmp_manu;		//manu图像
HBITMAP bmp_gameover;		//gameover图像
HBITMAP bmp_player2;		//图像
HBITMAP bmp_boy;		//图像
HBITMAP bmp_girl;		//图像
HBITMAP bmp_choose;		//图像
HBITMAP bmp_task;		//图像
HBITMAP bmp_taskbutton;		//图像
HBITMAP bmp_propbutton;		//图像
HBITMAP bmp_prop;		//图像
HBITMAP bmp_key1;		//图像
HBITMAP bmp_mayor;		//图像
HBITMAP bmp_boy1;		//图像
HBITMAP bmp_cat;		//图像
HBITMAP bmp_lock;		//图像
HBITMAP bmp_num1;		//图像
HBITMAP bmp_num2;		//图像
HBITMAP bmp_mima;		//图像
HBITMAP bmp_confirm;		//图像
HBITMAP bmp_paper;		//图像
HBITMAP bmp_boss;		//图像
HBITMAP bmp_monster;		//图像
HBITMAP bmp_victory;		//图像




int jieju = 0;
int ercigengxin1 = 0;
int ercigengxin2 = 0;
int ercigengxin3 = 0;
int migong = 0;
int migong_ = 0;
int istask = 0;
int ismima = 0;
int guanmen = 0;
int mima1 = 0;
int mima2 = 0;
int mima3 = 0;
int mima4 = 0;
int mima5 = 0;
int isprop = 0;
int aaaa = 0;
int sex;
bool die=0;
float lastAttackTime = 0.0f; // 记录上次攻击的时间
float attackInterval = 1000; // 攻击间隔时间，单位为秒

Stage* currentStage = NULL; //当前场景状态
vector<NPC*> npcs;			//NPC列表
vector<Monster*> monsters;	//怪物列表
vector<AIMonster*> aimonsters;	//怪物列表
Player* player = NULL;		//玩家
vector<Button*> buttons;	//按钮	
Attack* attack = NULL;		//攻击特效
Attack* attack2 = NULL;		//攻击特效
vector<task*>tasks;	
vector<prop*>props;



int ditu2 = 0;
int ditu3 = 0;
int ditu4 = 0;
int ditu5 = 0;
int yinxiao = 0;
int jinwu = 0;
int ditu6=0;

static int yinyueon = 0;
int mouseX = 0;
int mouseY = 0;
int stagenum = 0;
bool mouseDown = false;
bool keyUpDown = false;
bool keyDownDown = false;
bool keyLeftDown = false;
bool keyRightDown = false;
bool keyAttackDown = false;
bool keyESCDown = false;
bool keyWDown = false;
bool keySDown = false;
bool keyADown = false;
bool keyDDown = false;
bool keyFDown = false;
bool in_conversation = false;	//当前游戏处在对话状态
const wchar_t* converstaion_content = nullptr;	//当前对话的内容

//TODO 更多的全局变量

//人物属性
int healthlimit[21] = { 0,10,14,20,24,30,34,40,44,50,54,60,64,70,74,80,84,90,94,100,104 };
int explimit[21] = { 0,5,9,15,19,25,29,35,39,45,49,55,59,65,69,75,79,85,89,95,99 };
int attackdamage[21] = {0, 1,3,4,5,6,8,9,10,11,13,14,15,16,18,19,20,21,23,24,25 };
int defence[21] = { 0,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };

//帧
int PLAYER_FRAMES_HOLD[] = { 0 };
int PLAYER_FRAMES_HOLD_COUNT = sizeof(PLAYER_FRAMES_HOLD) / sizeof(int);
int AIMONSTER_FRAMES_HOLD[] = { 0 };
int AIMONSTER_FRAMES_HOLD_COUNT = sizeof(AIMONSTER_FRAMES_HOLD) / sizeof(int);
int NPC_FRAMES_HOLD[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 };
int NPC_FRAMES_HOLD_COUNT = sizeof(NPC_FRAMES_HOLD) / sizeof(int);
int FRAMES_WALK[] = {0,0,0,0,0,1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,};
int FRAMES_ATTACK1[] = { 0,0,0,0,0,1,1,1,1,1,2,2,2,2,2,3,3,3,3,3, };
int FRAMES_WALK_COUNT = sizeof(FRAMES_WALK) / sizeof(int);
int ATTACK_FRAMES[] = { 0,0,0,0,1,1,1,1,2,2,2,2 };
int ATTACK_FRAMES_COUNT = sizeof(ATTACK_FRAMES) / sizeof(int);

int BAN[] = 
{ 1,1,0,0,
1,1,1,0,
1,1,1,0,
1,1,1,0,
0,0,0,0,
1,1,1,0,
1,1,1,0,
1,1,1,0,
1,1,1,0,
1,1,1,0,
1,1,1,0,
0,0,0,0,
0,0,0,0, 
0,0,0,0, 
0,0,0,1, 
0,0,0,0, 
0,0,0,0, 
0,0,0,0, 
0,0,0,0, 
0,0,0,0, 
0,0,0,0, 
0,0,0,0, 
0,0,0,0, 
0,1,0,0, 
0,0,0,0, 
0,0,0,0,
1,0,0,0,
1,1,0,0,
0,0,0,0,
0,0,0,0,
0,0,0,1,
0,0,0,0,
0,0,0,0,
0,0,0,0,
0,0,0,1,
0,0,0,1,
0,0,0,0,
0,0,0,0,
0,0,0,0,
1,1,1,0,

};
//地图
//0空地 1草 2红花 3+7树 4/5/6/8/9/10/12/13/14土地 11蓝花 15路牌 16栅栏路牌 17栅栏 18信箱 19红花2
int map_stage1[20][28] = {
	{ 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,},
	{ 0, 0, 0, 0, 0, 0, 7, 7, 7, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,},
	{ 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,},
	{ 3, 3, 3, 3, 3, 3, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 7,},
	{ 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 5, 5, 6, 0, 0, 0, 0, 0, 3,},
	{ 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 9, 9, 9,10, 0, 0, 0, 0, 0, 7,},
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 9, 9, 9,10, 0, 0, 0, 0, 0, 0,},
	{ 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 9, 9, 9,10, 0, 0, 0, 0, 0, 0,},
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12,13,13,13,14, 0, 0, 0, 0, 0, 0,},
	{ 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,11,15, 0, 0, 0, 0,11, 0, 0, 0, 0, 0,},
	{ 3, 0, 0, 0, 0, 2, 2, 0,11,11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
	{ 7, 0, 0, 0, 2, 0, 0, 2, 0, 0,11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
	{ 3, 0, 0, 0, 2, 0, 0, 0, 0, 0,11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,},
	{ 7, 0, 0, 0, 0, 2, 0, 0,0,11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,},
	{ 3, 0, 0, 0, 0, 0, 2, 0,11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,},
	{ 7, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,},
	{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,},
	{ 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,},
	{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,},
	{ 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,},
};
//第二个关卡地图
int map_stage2[20][28] = {
	{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,},
	{ 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,},
	{ 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,},
	{ 3, 3, 3, 3, 3, 3, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 7, 7, 7, 7, 7, 7, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,},
	{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,},
	{ 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,},
};
int map_stage3[20][28] = {
{ 44, 45, 16, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 24, 25, 25, 25, 26, 17, 17, 17, 17, 17, 17, 17, 17, 16, 16 },
	{ 48,49,20,21,21,21,3,20,21,21,21,21,21,25,25,25,25,25,21,21,21,21,21,21,21,22,3,3 },
	{ 52,53,24,25,25,25,7,24,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,26,7,7 },
	{ 44,45,17,17,17,17,17,24,25,25,25,32,33,66,63,76,77,83,86,103,33,33,33,33,34,26,44,45 },
	{ 48,49,20,21,22,19,19,24,25,25,25,36,37,70,80,67,67,67,90,96,37,19,19,19,38,26,48,49 },
	{ 52,53,24,25,26,19,19,24,25,25,25,36,37,74,71,84,85,91,94,100,37,37,37,37,38,26,52,53 },
	{ 20,21,25,25,25,21,21,25,25,25,25,36,37,78,75,88,89,95,98,97,37,18,18,37,38,26,44,45 },
	{ 24,25,25,25,25,25,25,25,25,25,25,40,41,82,79,92,93,99,102,101,41,41,41,41,42,26,48,49 },
	{ 24,25,25,25,25,32,33,34,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,52,53 },
	{ 24,25,25,25,25,36,15,38,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,26,44,45 },
	{ 24,25,25,25,25,40,41,42,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,26,48,49 },
	{ 28,29,25,25,25,25,25,25,25,25,25,23,43,64,46,65,25,25,25,25,25,25,25,25,25,26,52,53 },
	{ 44,45,24,25,25,25,25,25,25,32,33,27,47,68,50,69,17,17,17,17,17,17,17,16,25,26,44,45 },
	{ 48,49,24,25,25,25,25,25,25,36,37,31,51,54,72,73,37,37,37,37,37,37,19,38,25,26,48,49 },
	{ 52,53,24,25,25,25,25,25,25,36,37,35,55,56,57,58,18,37,37,37,37,37,19,38,25,26,52,53 },
	{ 44,45,24,25,25,25,25,25,25,40,41,39,59,60,61,62,41,41,41,41,41,41,41,42,25,26,44,45 },
	{ 48,49,24,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,26,48,49 },
	{ 52,53,28,29,29,29,25,25,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,30,52,53 },
	{ 44,45,44,45,44,45,24,26,44,45,44,45,44,45,44,45,44,45,44,45,44,45,44,45,44,45,44,45 },
	{ 48,49,48,49,48,49,24,26,48,49,48,49,48,49,48,49,48,49,48,49,48,49,48,49,48,49,48,49 }
};
//128 129 130
//132 133 134  105 106
int map_stage6[20][28] = { 
	{127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127},
	{107,121,120,118,119,119,121,120,118,107,119,119,120,118,119,119,119,119,110,107,119,119,110,119,119,119,121,107},
	{107,125,124,122,123,123,125,124,122,107,123,123,124,122,123,123,123,123,114,107,123,123,114,123,123,123,125,107},
	{107,105,105,105,105,105,105,104,104,107,104,104,104,104,104,104,104,104,104,107,104,104,104,104,104,104,104,107},
	{107,104,104,104,104,104,104,104,104,107,104,104,104,104,104,104,104,104,104,107,104,104,104,104,104,104,104,107},
	{107,104,104,104,112,113,106,104,104,107,104,112,113,106,104,104,112,113,104,107,104,104,104,104,105,112,113,107},
	{107,104,104,105,116,117,104,104,104,107,104,116,117,104,104,105,116,117,104,107,104,104,104,104,105,116,117,107},
	{107,104,104,104,104,104,104,104,104,107,104,104,104,104,104,104,104,104,104,107,104,104,104,104,104,104,104,107},
	{107,104,104,104,104,104,104,104,104,111,104,104,104,104,104,104,104,104,104,111,104,104,104,104,104,104,104,107},
	{107,104,104,104,104,104,104,104,104,115,104,104,104,104,104,104,104,104,104,115,104,104,104,104,104,104,104,107},
	{107,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,107},
	{107,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,107},
	{107,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,107},
	{107,104,104,104,128,129,130,106,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,107},
	{107,104,104,105,132,133,134,104,104,104,104,104,104,104,104,104,105,128,129,129,129,129,130,104,104,104,104,107},
	{107,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,132,133,133,133,133,134,106,104,104,104,107},
	{107,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,107},
	{107,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,107},
	{111,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,111},
	{115,126,126,126,126,126,126,126,126,126,126,126,126,126,108,109,126,126,126,126,126,126,126,126,126,126,126,115} 
};
int map_stage7[20][28] = { 
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,131,136,137,138,144,138,138,139,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,135,140,141,142,143,143,143,143,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,143,143,143,143,143,143,143,143,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,143,143,146,148,149,146,143,143,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,143,143,146,152,153,146,143,143,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,143,143,143,156,157,143,143,143,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,143,143,143,143,143,143,143,143,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,143,143,108,109,143,143,143,143,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145} 
};

int map_stage8[20][28] = {
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,150,138,138,138,131,136,138,158,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,154,143,148,149,135,140,143,143,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,143,143,156,157,143,143,143,143,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,143,143,143,143,143,143,143,143,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,143,143,143,147,143,143,143,143,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,143,143,143,151,143,143,143,143,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,155,143,143,143,143,143,143,143,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,159,143,143,143,143,143,143,143,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145},
	{145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145,145} 
};
int map_stage10[20][28] = {
	{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,},
	{ 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,},
	{ 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,},
	{ 3, 3, 3, 3, 3, 3, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 7, 7, 7, 7, 7, 7, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,},
	{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,},
	{ 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,},
};
int map_stage11[20][28] = {
	{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,},
	{ 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,},
	{ 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,},
	{ 3, 3, 3, 3, 3, 3, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 7, 7, 7, 7, 7, 7, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 5, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 9, 10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 12, 13, 14, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,},
	{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,},
	{ 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,},
};
int map_stage12[20][28] = {
	{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,},
	{ 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,},
	{ 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,},
	{ 3, 3, 3, 3, 3, 3, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 7, 7, 7, 7, 7, 7, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,},
	{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,},
	{ 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,},
};
int map_stage13[20][28] = {
	{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,},
	{ 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,},
	{ 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,},
	{ 3, 3, 3, 3, 3, 3, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 7, 7, 7, 7, 7, 7, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,},
	{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,},
	{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,},
	{ 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,},
};
int map_stage5[20][28] = {
	{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,},
	{ 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,},
	{ 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,},
	{ 3, 3, 3, 3, 3, 3, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 7, 7, 7, 7, 7, 7, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,},
	{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,},
	{ 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,},
};
int map_stage4[20][28] = {
	{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,},
	{ 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,},
	{ 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3,},
	{ 3, 3, 3, 3, 3, 3, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 7, 7, 7, 7, 7, 7, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 7,},
	{ 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3,},
	{ 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,},
	{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,},
	{ 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,},
};
int map[20][28] = { 0 };	//存储当前关卡的地图


// TODO: 在此添加其它全局变量

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PUZZLEGAME, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PUZZLEGAME));

    MSG msg;

    // 主消息循环:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PUZZLEGAME));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PUZZLEGAME);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, 
       WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, // 设置窗口样式，不可改变大小，不可最大化
       CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT, nullptr, nullptr, hInstance, nullptr);
   SetMenu(hWnd, NULL);     //隐藏菜单栏
   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        // 初始化游戏窗体
        InitGame(hWnd, wParam, lParam);
        break;
    case WM_KEYDOWN:
        // 键盘按下事件
        KeyDown(hWnd, wParam, lParam);
        break;
    case WM_KEYUP:
        // 键盘松开事件
        KeyUp(hWnd, wParam, lParam);
        break;
    case WM_MOUSEMOVE:
        // 鼠标移动事件
        MouseMove(hWnd, wParam, lParam);
        break;
    case WM_LBUTTONDOWN:
        // 鼠标左键按下事件
        LButtonDown(hWnd, wParam, lParam);
        break;
    case WM_LBUTTONUP:
        // 鼠标左键松开事件
        LButtonUp(hWnd, wParam, lParam);
        break;
    case WM_TIMER:
        // 定时器事件
        if (currentStage != NULL && currentStage->timerOn) TimerUpdate(hWnd, wParam, lParam);
		/*if (currentStage != NULL && currentStage->timerOn) TimerUpdate2(hWnd, wParam, lParam);*/
        break;
    case WM_PAINT:
        // 绘图
        Paint(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
     return 0;
}

// 初始化游戏窗体函数
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	//加载图像资源
	bmp_Background = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BACKGROUND));
	bmp_Pause = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_PAUSE));
	bmp_HELP1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HELP1));
	bmp_StartButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_STARTBUTTON));
	bmp_HelpButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HELPBUTTON));
	bmp_BackButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BACKBUTTON));
	bmp_RestartButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_RESTARTBUTTON));
	bmp_ContinueButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CONTINUEBUTTON));
	bmp_BacktotitleButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BACKTOTITLEBUTTON));
	bmp_Player = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_PLAYER));
	bmp_NPC_MAN1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NPC_MAN1));
	bmp_map = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_MAP));
	bmp_dialog = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_DIALOG));
	bmp_monster1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_MONSTER1));
	bmp_HelpButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HELPBUTTON));
	bmp_slime = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_SLIME));
	bmp_racoon = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_RACOON));
	bmp_attack = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_ATTACK));
	bmp_attack2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_ATTACK2));
	bmp_manu = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_MANU));
	bmp_gameover = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_GAMEOVER));
	bmp_player2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_PLAYER2));
	bmp_boy = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BOY));
	bmp_girl = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_GIRL));
	bmp_choose = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CHOOSE));
	bmp_task = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_TASK));
	bmp_taskbutton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_TASKBUTTON));
	bmp_propbutton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_PROPBUTTON));
	bmp_prop = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_PROP));
	bmp_key1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_KEY1));
	bmp_mayor = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_MAYOR));
	bmp_boy1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BOY1));
	bmp_cat = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CAT));
	bmp_lock = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_LOCK));
	bmp_num1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NUM1));
	bmp_num2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NUM2));
	bmp_mima = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_MIMA));
	bmp_confirm = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CONFIRM));
	bmp_paper = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_PAPER));
	bmp_boss = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BOSS));
	bmp_monster = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_MONSTER));
	bmp_victory= LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_VICTORY));


	
	task* task1 = new task();
	task1->taskID = 1;
	task1->limit = 3;
	task1->value = 0;
	task1->visible = 0;
	task1->statement=(L"杀死游荡的怪物");
	task1->finish = false;
	tasks.push_back(task1);


	

	prop* prop1 = new prop();
	prop1->propID = 1;
	prop1->num = 1;
	prop1->img = bmp_key1;
	prop1->visible = 0;
	prop1->statement = (L"应该能打开某个地方");
	prop1->name = (L"一把神奇的钥匙");
	props.push_back(prop1);

	prop* prop2 = new prop();
	prop2->propID = 2;
	prop2->num = 1;
	prop2->img = bmp_paper;
	prop2->visible = 0;
	prop2->statement = (L"上面写着：十天干：“甲、乙、丙、丁、戊、己、庚、辛、壬、癸”");
	prop2->name = (L"纸片1");
	props.push_back(prop2);


	prop* prop3 = new prop();
	prop3->propID = 3;
	prop3->num = 1;
	prop3->img = bmp_paper;
	prop3->visible = 0;
	prop3->statement = (L"上面写着：十二地支：“子、丑、寅、卯、辰、巳、午、未、申、酉、戌、亥”");
	prop3->name = (L"纸片2");
	props.push_back(prop3);


	prop* prop4 = new prop();
	prop4->propID = 4;
	prop4->num = 1;
	prop4->img = bmp_paper;
	prop4->visible = 0;
	prop4->statement = (L"上面写着：上天无用，唯我下地，引诱臭猫");
	prop4->name = (L"纸片3");
	props.push_back(prop4);
	
	//添加按钮
	Button* startButton = CreateButton(BUTTON_STARTGAME, bmp_StartButton, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT,
		(WINDOW_WIDTH - BUTTON_STARTGAME_WIDTH) / 2, (WINDOW_WIDTH - BUTTON_STARTGAME_HEIGHT) / 2);
	buttons.push_back(startButton);
	
	Button* helpButton = CreateButton(BUTTON_HELP, bmp_HelpButton, BUTTON_HELP_WIDTH, BUTTON_HELP_HEIGHT,
		(WINDOW_WIDTH - BUTTON_HELP_WIDTH) / 2, (WINDOW_WIDTH + 1.2 * BUTTON_HELP_HEIGHT) / 2);
	buttons.push_back(helpButton);

	Button* backButton = CreateButton(BUTTON_BACK, bmp_BackButton, BUTTON_BACK_WIDTH, BUTTON_BACK_HEIGHT,
		(WINDOW_WIDTH - 1.2*BUTTON_HELP_WIDTH) +30,  BUTTON_HELP_HEIGHT/4);
	buttons.push_back(backButton);
	Button* continueButton = CreateButton(BUTTON_CONTINUE, bmp_ContinueButton, BUTTON_CONTINUE_WIDTH, BUTTON_CONTINUE_HEIGHT,
		(WINDOW_WIDTH - BUTTON_STARTGAME_WIDTH) / 2, (WINDOW_WIDTH - 6.5*BUTTON_STARTGAME_HEIGHT) / 2);
	buttons.push_back(continueButton);

	Button* restartButton = CreateButton(BUTTON_RESTART, bmp_RestartButton, BUTTON_RESTART_WIDTH, BUTTON_RESTART_HEIGHT,
		(WINDOW_WIDTH - BUTTON_STARTGAME_WIDTH) / 2, (WINDOW_WIDTH - 3*BUTTON_STARTGAME_HEIGHT) / 2);
	buttons.push_back(restartButton);

	Button* backtotitleButton = CreateButton(BUTTON_BACKTOTITLE, bmp_BacktotitleButton, BUTTON_BACKTOTITLE_WIDTH, BUTTON_BACKTOTITLE_HEIGHT,
		(WINDOW_WIDTH - BUTTON_HELP_WIDTH) / 2, (WINDOW_WIDTH +0.5 * BUTTON_HELP_HEIGHT) / 2);
	buttons.push_back(backtotitleButton);
	Button* backtotitleButton3 = CreateButton(BUTTON_BACKTOTITLE3, bmp_BacktotitleButton, BUTTON_BACKTOTITLE_WIDTH, BUTTON_BACKTOTITLE_HEIGHT,
		(WINDOW_WIDTH - BUTTON_HELP_WIDTH) / 2, (0.5 * BUTTON_HELP_HEIGHT) );
	buttons.push_back(backtotitleButton3);

	Button* restartButton2 = CreateButton(BUTTON_RESTART2, bmp_RestartButton, BUTTON_RESTART_WIDTH, BUTTON_RESTART_HEIGHT,
		(WINDOW_WIDTH -3* BUTTON_STARTGAME_WIDTH) / 2, (WINDOW_WIDTH + 0.5 * BUTTON_HELP_HEIGHT) / 2);
	buttons.push_back(restartButton2);

	Button* backtotitleButton2 = CreateButton(BUTTON_BACKTOTITLE2, bmp_BacktotitleButton, BUTTON_BACKTOTITLE_WIDTH, BUTTON_BACKTOTITLE_HEIGHT,
		(WINDOW_WIDTH + BUTTON_HELP_WIDTH) / 2, (WINDOW_WIDTH + 0.5 * BUTTON_HELP_HEIGHT) / 2);
	buttons.push_back(backtotitleButton2);

	Button* boy = CreateButton(BUTTON_BOY, bmp_boy, BUTTON_RESTART_WIDTH, BUTTON_RESTART_HEIGHT,
		(WINDOW_WIDTH - 3 * BUTTON_STARTGAME_WIDTH) / 2+20, (WINDOW_WIDTH + 0.5 * BUTTON_HELP_HEIGHT) / 2);
	buttons.push_back(boy);

	Button* girl = CreateButton(BUTTON_GIRL, bmp_girl, BUTTON_BACKTOTITLE_WIDTH, BUTTON_BACKTOTITLE_HEIGHT,
		(WINDOW_WIDTH + BUTTON_HELP_WIDTH) / 2-70, (WINDOW_WIDTH + 0.5 * BUTTON_HELP_HEIGHT) / 2);
	buttons.push_back(girl);

	Button* taskbutton = CreateButton(BUTTON_TASK, bmp_taskbutton, BUTTON_RESTART_WIDTH, BUTTON_RESTART_HEIGHT,
		(WINDOW_WIDTH - 2.9 * BUTTON_STARTGAME_WIDTH) / 2 + 20, (WINDOW_WIDTH - 11 * BUTTON_HELP_HEIGHT) / 2);
	buttons.push_back(taskbutton);

	Button* propbutton = CreateButton(BUTTON_PROP, bmp_propbutton, BUTTON_BACKTOTITLE_WIDTH, BUTTON_BACKTOTITLE_HEIGHT,
		(WINDOW_WIDTH + 1.5*BUTTON_HELP_WIDTH) / 2 - 70, (WINDOW_WIDTH - 11 * BUTTON_HELP_HEIGHT) / 2);
	buttons.push_back(propbutton);

	Button* manuButton = CreateButton(BUTTON_MANU, bmp_manu, BUTTON_MANU_WIDTH, BUTTON_MANU_HEIGHT,
		2,2);
	buttons.push_back(manuButton);

	Button* num1 = CreateButton(BUTTON_NUM1, bmp_num1, BUTTON_NUM_WIDTH, BUTTON_NUM_HEIGHT,
		150,180);
	buttons.push_back(num1);
	Button* num2 = CreateButton(BUTTON_NUM2, bmp_num1, BUTTON_NUM_WIDTH, BUTTON_NUM_HEIGHT,
		300, 180);
	buttons.push_back(num2);
	Button* num3 = CreateButton(BUTTON_NUM3, bmp_num1, BUTTON_NUM_WIDTH, BUTTON_NUM_HEIGHT,
		450,180);
	buttons.push_back(num3);
	Button* num4 = CreateButton(BUTTON_NUM4, bmp_num1, BUTTON_NUM_WIDTH, BUTTON_NUM_HEIGHT,
		600,180);
	buttons.push_back(num4);
	Button* num5 = CreateButton(BUTTON_NUM5, bmp_num1, BUTTON_NUM_WIDTH, BUTTON_NUM_HEIGHT,
		750,180);
	buttons.push_back(num5);

	Button* num01 = CreateButton(BUTTON_NUM01, bmp_num2, BUTTON_NUM_WIDTH, BUTTON_NUM_HEIGHT,
		150, 500);
	buttons.push_back(num01);
	Button* num02 = CreateButton(BUTTON_NUM02, bmp_num2, BUTTON_NUM_WIDTH, BUTTON_NUM_HEIGHT,
		300,500);
	buttons.push_back(num02);
	Button* num03 = CreateButton(BUTTON_NUM03, bmp_num2, BUTTON_NUM_WIDTH, BUTTON_NUM_HEIGHT,
		450,500);
	buttons.push_back(num03);
	Button* num04 = CreateButton(BUTTON_NUM04, bmp_num2, BUTTON_NUM_WIDTH, BUTTON_NUM_HEIGHT,
		600,500);
	buttons.push_back(num04);
	Button* num05 = CreateButton(BUTTON_NUM05, bmp_num2, BUTTON_NUM_WIDTH, BUTTON_NUM_HEIGHT,
		750,500);
	buttons.push_back(num05);
	Button* backButton2 = CreateButton(BUTTON_BACK2, bmp_BackButton, BUTTON_BACK_WIDTH, BUTTON_BACK_HEIGHT,
		(WINDOW_WIDTH - 1.2 * BUTTON_HELP_WIDTH), BUTTON_HELP_HEIGHT / 4);
	buttons.push_back(backButton2);
	Button* confirmbutton = CreateButton(BUTTON_CONFIRM, bmp_confirm, BUTTON_RESTART_WIDTH, BUTTON_RESTART_HEIGHT,
		(WINDOW_WIDTH - 2.9 * BUTTON_STARTGAME_WIDTH) / 2 + 20+160, (WINDOW_WIDTH - 11 * BUTTON_HELP_HEIGHT) / 2);
	buttons.push_back(confirmbutton);

	attack = CreateAttack();
	attack2 = CreateAttack2();


	//初始化开始场景
	InitStage(hWnd, STAGE_STARTMENU);

	//初始化主计时器
	SetTimer(hWnd, TIMER_GAMETIMER, TIMER_GAMETIMER_ELAPSE, NULL);
	SetTimer(hWnd, TIMER_GAMETIMER2, TIMER_GAMETIMER2_ELAPSE, NULL);
}

// 键盘按下事件处理函数
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case 'K':
		keyAttackDown = true;
		attack->visible = true;
		break;
	case 'F':
		keyFDown = true;
		if (stagenum>11||stagenum==11) {
			if (istask == 0&&isprop==0) {
				istask = 1;
				InitStage(hWnd, STAGE_TASK);
			}
			else {
				InitStage(hWnd, stagenum);
				istask = 0;
				isprop = 0;
			}
			}
		break;
	case VK_UP:
		keyUpDown = true;
		break;
	case VK_DOWN:
		keyDownDown = true;
		break;
	case VK_LEFT:
		keyLeftDown = true;
		break;
	case VK_RIGHT:
		keyRightDown = true;
		break;
	case VK_ESCAPE:
		keyESCDown = true;
		break;
	case 'W':
		keyWDown = true;
		break;
	case 'S':
		keySDown = true;
		break;
	case 'A':
		keyADown = true;
		break;
	case 'D':
		keyDDown = true;
		break;
	case VK_SPACE:
		if (currentStage->stageID == STAGE_win)
		{
			jieju++;
			InvalidateRect(hWnd, NULL, FALSE);

		}
		break;
	default:
		break;
	}
}

// 键盘松开事件处理函数
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// TODO
	switch (wParam)
	{
	case 'K':
		keyAttackDown = false;
		break;
	case 'F':
		keyFDown = false;
		break;
	case VK_UP:
		keyUpDown = false;
		break;
	case VK_DOWN:
		keyDownDown = false;
		break;
	case VK_LEFT:
		keyLeftDown = false;
		break;
	case VK_RIGHT:
		keyRightDown = false;
		break;
	case VK_ESCAPE:
		keyESCDown = false;
		break;
	case 'W':
		keyWDown = false;
		break;
	case 'S':
		keySDown = false;
		break;
	case 'A':
		keyADown = false;
		break;
	case 'D':
		keyDDown = false;
		break;
	case VK_SPACE:
		HandleConversationEvents(hWnd);
		break;
	default:
		break;
	}
}

// 鼠标移动事件处理函数
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
}

// 鼠标左键按下事件处理函数
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseDown = true;

	for (int i = 0; i < buttons.size(); i++)
	{
		Button* button = buttons[i];
		if (button->visible)
		{
			if (button->x <= mouseX
				&& button->x + button->width >= mouseX
				&& button->y <= mouseY
				&& button->y + button->height >= mouseY)
			{
				switch (button->buttonID) {
				case BUTTON_STARTGAME:
				{
					//TODO：判断进入哪个关卡
					yinyueon = 0;
					if (player != NULL)player = NULL;
					npcs.clear();
					InitStage(hWnd, STAGE_CHOOSE);
					yinyueon = 0;
					if (player != NULL)player = NULL;
					npcs.clear();
					aimonsters.clear();
					jieju = 0;
					ercigengxin1 = 0;
					ercigengxin2 = 0;
					ercigengxin3 = 0;
					migong = 0;
					migong_ = 0;
					istask = 0;
					ismima = 0;
					guanmen = 0;
					mima1 = 0;
					mima2 = 0;
					mima3 = 0;
					mima4 = 0;
					mima5 = 0;
					isprop = 0;
					aaaa = 0;

					die = 0;
					lastAttackTime = 0.0f; // 记录上次攻击的时间
					attackInterval = 1000; // 攻击间隔时间，单位为秒
					ditu2 = 0;
					ditu3 = 0;
					ditu4 = 0;
					ditu5 = 0;
					yinxiao = 0;
					jinwu = 0;
					ditu6 = 0;
					props[0]->visible = false;
					props[1]->visible = false;
					props[2]->visible = false;
					props[3]->visible = false;
					tasks[0]->value = 0;
					tasks[0]->finish = 0;
					tasks[0]->visible = 0;
					yinyueon = 0;
					mouseX = 0;
					mouseY = 0;
					stagenum = 0;
				}
				break;
				case BUTTON_BOY:
				{
					sex = 1;
					//TODO：判断进入哪个关卡
					if (player != NULL)player = NULL;
					npcs.clear();
					InitStage(hWnd, STAGE_1);
				}
				break;
				case BUTTON_GIRL:
				{
					sex = 0;
					//TODO：判断进入哪个关卡
					if (player != NULL)player = NULL;
					npcs.clear();
					InitStage(hWnd, STAGE_1);
				}
				break;
				case BUTTON_HELP:
				{
					//TODO：判断进入哪个关卡
					InitStage(hWnd, STAGE_HELP);
					kaishi = 1;
				}
				break;
				case BUTTON_BACK:
				{
					//TODO：判断进入哪个关卡
					InitStage(hWnd, STAGE_STARTMENU);
					kaishi = 1;
					InvalidateRect(hWnd, NULL, FALSE);

				}
				break;
				case BUTTON_RESTART:
				{
					//TODO：判断进入哪个关卡
					yinyueon = 0;
					if (player != NULL)player = NULL;
					npcs.clear();
					aimonsters.clear();
					 jieju = 0;
					 ercigengxin1 = 0;
					 ercigengxin2 = 0;
					 ercigengxin3 = 0;
					 migong = 0;
					 migong_ = 0;
					 istask = 0;
					 ismima = 0;
					 guanmen = 0;
					 mima1 = 0;
					 mima2 = 0;
					 mima3 = 0;
					mima4 = 0;
					 mima5 = 0;
				 isprop = 0;
					 aaaa = 0;
					
					 die = 0;
					 lastAttackTime = 0.0f; // 记录上次攻击的时间
					attackInterval = 1000; // 攻击间隔时间，单位为秒
					 ditu2 = 0;
					 ditu3 = 0;
					 ditu4 = 0;
					 ditu5 = 0;
					 yinxiao = 0;
					 jinwu = 0;
					 ditu6 = 0;

					 yinyueon = 0;
					 mouseX = 0;
					 mouseY = 0;
				    stagenum = 0;
					props[0]->visible = false;
					props[1]->visible = false;
					props[2]->visible = false;
					props[3]->visible = false;
					tasks[0]->value = 0;
					tasks[0]->finish = 0;
					tasks[0]->visible = 0;
					//TODO 更多的全局变量
					InitStage(hWnd, STAGE_1);
				}
				break;

				case BUTTON_RESTART2:
				{
					
					yinyueon = 0;
					InitStage(hWnd, stagenum);
					PlaySound(NULL, NULL, SND_PURGE);
					PlaySound(MAKEINTRESOURCE(IDR_MAIN), NULL, SND_RESOURCE | SND_ASYNC | SND_LOOP);
					player->health = player->healthlimit;
					player->alive=1;


				}
				break;
				case BUTTON_CONTINUE:
				{
					//TODO：判断进入哪个关卡
					InitStage(hWnd, stagenum);
				}
				break;
				case BUTTON_BACKTOTITLE:
				{
					//TODO：判断进入哪个关卡
					if (player != NULL)player = NULL;
					npcs.clear();
					aimonsters.clear();
					yinyueon = 0;
					if (player != NULL)player = NULL;
					npcs.clear();
					aimonsters.clear();
					jieju = 0;
					ercigengxin1 = 0;
					ercigengxin2 = 0;
					ercigengxin3 = 0;
					migong = 0;
					migong_ = 0;
					istask = 0;
					ismima = 0;
					guanmen = 0;
					mima1 = 0;
					mima2 = 0;
					mima3 = 0;
					mima4 = 0;
					mima5 = 0;
					isprop = 0;
					aaaa = 0;

					die = 0;
					lastAttackTime = 0.0f; // 记录上次攻击的时间
					attackInterval = 1000; // 攻击间隔时间，单位为秒
					ditu2 = 0;
					ditu3 = 0;
					ditu4 = 0;
					ditu5 = 0;
					yinxiao = 0;
					jinwu = 0;
					ditu6 = 0;

					yinyueon = 0;
					mouseX = 0;
					mouseY = 0;
					stagenum = 0;
					props[0]->visible = false;
					props[1]->visible = false;
					props[2]->visible = false;
					props[3]->visible = false;
					tasks[0]->value = 0;
					tasks[0]->finish = 0;
					tasks[0]->visible = 0;
					InitStage(hWnd, STAGE_STARTMENU);
				}
				break;
				case BUTTON_BACKTOTITLE3:
				{
					//TODO：判断进入哪个关卡
					if (player != NULL)player = NULL;
					npcs.clear();
					aimonsters.clear();
					yinyueon = 0;
					if (player != NULL)player = NULL;
					npcs.clear();
					aimonsters.clear();
					jieju = 0;
					ercigengxin1 = 0;
					ercigengxin2 = 0;
					ercigengxin3 = 0;
					migong = 0;
					migong_ = 0;
					istask = 0;
					ismima = 0;
					guanmen = 0;
					mima1 = 0;
					mima2 = 0;
					mima3 = 0;
					mima4 = 0;
					mima5 = 0;
					isprop = 0;
					aaaa = 0;

					die = 0;
					lastAttackTime = 0.0f; // 记录上次攻击的时间
					attackInterval = 1000; // 攻击间隔时间，单位为秒
					ditu2 = 0;
					ditu3 = 0;
					ditu4 = 0;
					ditu5 = 0;
					yinxiao = 0;
					jinwu = 0;
					ditu6 = 0;

					yinyueon = 0;
					mouseX = 0;
					mouseY = 0;
					stagenum = 0;
					props[0]->visible = false;
					props[1]->visible = false;
					props[2]->visible = false;
					props[3]->visible = false;
					tasks[0]->value=0;
					tasks[0]->finish = 0;
					tasks[0]->visible = 0;
					InitStage(hWnd, STAGE_STARTMENU);
				}
				break;
				case BUTTON_BACKTOTITLE2:
				{
					//TODO：判断进入哪个关卡
					if (player != NULL)player = NULL;
					npcs.clear();
					aimonsters.clear();
					InitStage(hWnd, STAGE_STARTMENU);
				}
				break;
				case BUTTON_TASK:
				{
					//TODO：判断进入哪个关卡
					istask = 1;
					isprop = 0;
					InitStage(hWnd, STAGE_TASK);
				}
				break;
				case BUTTON_PROP:
				{
					//TODO：判断进入哪个关卡
					istask = 0;
					isprop = 1;
					InitStage(hWnd, STAGE_PROP);
				}
				break;
				case BUTTON_NUM1:
				{
					//TODO：判断进入哪个关卡
					if (mima1 < 9)mima1++;
					InvalidateRect(hWnd, NULL, FALSE);
				}
				break;
				case BUTTON_NUM2:
				{
					//TODO：判断进入哪个关卡
					if (mima2 < 9)mima2++;
					InvalidateRect(hWnd, NULL, FALSE);
				}
				break;
				case BUTTON_NUM3:
				{
					//TODO：判断进入哪个关卡
					if (mima3 < 9)mima3++;
					InvalidateRect(hWnd, NULL, FALSE);
				}
				break;
				case BUTTON_NUM4:
				{
					//TODO：判断进入哪个关卡
					if (mima4 < 9)mima4++;
					InvalidateRect(hWnd, NULL, FALSE);
				}
				break;
				case BUTTON_NUM5:
				{
					//TODO：判断进入哪个关卡
					if (mima5 < 9)mima5++;
					InvalidateRect(hWnd, NULL, FALSE);
				}
				break;
				case BUTTON_NUM01:
				{
					//TODO：判断进入哪个关卡
					if (mima1 > 0)mima1--;
					InvalidateRect(hWnd, NULL, FALSE);
				}
				break;
				case BUTTON_NUM02:
				{
					//TODO：判断进入哪个关卡
					if (mima2 > 0)mima2--;
					InvalidateRect(hWnd, NULL, FALSE);
				}
				break;
				case BUTTON_NUM03:
				{
					//TODO：判断进入哪个关卡
					if (mima3 > 0)mima3--;
					InvalidateRect(hWnd, NULL, FALSE);
				}
				break;
				case BUTTON_NUM04:
				{
					//TODO：判断进入哪个关卡
					if (mima4 > 0)mima4--;
					InvalidateRect(hWnd, NULL, FALSE);
				}
				break;
				case BUTTON_NUM05:
				{
					//TODO：判断进入哪个关卡
					if (mima5 > 0)mima5--;
					InvalidateRect(hWnd, NULL, FALSE);
				}
				break;
				case BUTTON_BACK2:
				{
					//TODO：判断进入哪个关卡
					InitStage(hWnd, STAGE_6);
					ismima = 0;
					player->y -= 50;
				}
				break;
				case BUTTON_CONFIRM:
				{
					//TODO：判断进入哪个关卡
					if (mima1 == 3 && mima2 == 1 && mima3 == 0 && mima4 == 2 && mima5 == 4) {
						InitStage(hWnd, STAGE_6);ismima = 0;guanmen = 0;
						for (int j = 0; j < npcs.size(); j++) {
							if (npcs[j]->npcID == NPC_MAYOR_ID) {
								npcs[j]->task_complete = true;
							}
						}
					}
				}
				break;
				}

			}

		}
	}

}

// 鼠标左键松开事件处理函数
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseDown = false;
}

// 定时器事件处理函数
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{

	UpdatePlayer(hWnd);
	UpdateNPCs(hWnd);
	UpdateMonsters(hWnd);
	//Updateboss(hWnd);
	UpdateMaps(hWnd);
	PAUSE(hWnd);
	GAMEOVER(hWnd);
	UpdateAIMonsters(hWnd);
	UpdateAttack(hWnd);
	updateplayer(hWnd);
	Updateditu(hWnd);
	//TASK(hWnd);
	//刷新显示
	InvalidateRect(hWnd, NULL, FALSE);
}
//void TimerUpdate2(HWND hWnd, WPARAM wParam, LPARAM lParam)
//{
//
//	updateyinxiao(hWnd);
//	InvalidateRect(hWnd, NULL, FALSE);
//}
void updateyinxiao(HWND hWnd) {
	if(yinxiao==1)yinxiao = 0;
	if (jinwu == 1)jinwu = 0;
}
//更新玩家状态
void UpdatePlayer(HWND hWnd) {
	//如果键盘按下，设置状态为WALK
	if (keyLeftDown || keyUpDown || keyRightDown || keyDownDown||keyADown || keyWDown || keyDDown || keySDown) {
		player->state = UNIT_STATE_WALK;
		player->frame_sequence = FRAMES_WALK;
		player->frame_count = FRAMES_WALK_COUNT;
		if (keyLeftDown&&keyUpDown) {
			player->direction = UNIT_DIRECT_LEFTUP;
		}
		else if (keyRightDown&&keyUpDown) {
			player->direction = UNIT_DIRECT_RIGHTUP;
		}
		else if (keyRightDown&&keyDownDown) {
			player->direction = UNIT_DIRECT_RIGHTDOWN;
		}
		else if (keyLeftDown && keyDownDown) {
			player->direction = UNIT_DIRECT_LEFTDOWN;
		}
		else if (keyLeftDown) {
			player->direction = UNIT_DIRECT_LEFT;
		}
		else if (keyUpDown) {
			player->direction = UNIT_DIRECT_UP;
		}
		else if (keyRightDown) {
			player->direction = UNIT_DIRECT_RIGHT;
		}
		else if (keyDownDown) {
			player->direction = UNIT_DIRECT_DOWN;
		}
		else if (keyADown) {
			player->direction = UNIT_DIRECT_LEFT;
		}
		else if (keyWDown) {
			player->direction = UNIT_DIRECT_UP;
		}
		else if (keyDDown) {
			player->direction = UNIT_DIRECT_RIGHT;
		}
		else if (keySDown) {
			player->direction = UNIT_DIRECT_DOWN;
		}
		if (keyADown && keyWDown) {
			player->direction = UNIT_DIRECT_LEFTUP;
		}
		else if (keyDDown && keyWDown) {
			player->direction = UNIT_DIRECT_RIGHTUP;
		}
		else if (keyDDown && keySDown) {
			player->direction = UNIT_DIRECT_RIGHTDOWN;
		}
		else if (keyADown && keySDown) {
			player->direction = UNIT_DIRECT_LEFTDOWN;
		}
		player->frame_row = player->direction;
	}
	else {
		player->state = UNIT_STATE_HOLD;
		player->frame_sequence = PLAYER_FRAMES_HOLD;
		player->frame_count = PLAYER_FRAMES_HOLD_COUNT;
	}
	//更新位置
	if (player->state == UNIT_STATE_WALK) {
		switch (player->direction) {
		case UNIT_DIRECT_LEFT:
			if ((BAN[map[int(player->y + 3 * player->vy) / BLOCK_SIZE_Y][int((player->x - 2*player->vx) / BLOCK_SIZE_Y)]] == 1)&&(BAN[map[player->y / BLOCK_SIZE_Y][int((player->x - 2*player->vx) / BLOCK_SIZE_Y)]] == 1)) {

				int flag = 0;
				for (int i = 0; i < npcs.size(); i++) {
					NPC* npc = npcs[i];
					if (npc->visible == 1) {
						if ((((player->x - player->vx <= npc->x && npc->x <= player->x - player->vx + HUMAN_SIZE_X) || (npc->x <= player->x - player->vx && player->x - player->vx <= npc->x + HUMAN_SIZE_X)) &&
							((player->y <= npc->y && npc->y <= player->y + HUMAN_SIZE_Y) || (npc->y <= player->y && player->y <= npc->y + HUMAN_SIZE_X)))) {
							flag = 1;
						}

					}
				}
				if (flag == 0) {
					int flag2 = 0;
					for (int j = 0; j < aimonsters.size(); j++) {
						AIMonster* aimonster = aimonsters[j];
						if (aimonster->visible == 1) {
							if ((((player->x - player->vx <= aimonster->x && aimonster->x <= player->x - player->vx + 0.8 * AIMOSTER_SIZE_X) || (aimonster->x <= player->x - player->vx && player->x - player->vx <= aimonster->x + 0.8 * AIMOSTER_SIZE_X)) &&
								((player->y <= aimonster->y && aimonster->y <= player->y + 0.8 * AIMOSTER_SIZE_Y) || (aimonster->y <= player->y && player->y <= aimonster->y + 0.8 * AIMOSTER_SIZE_X)))) {
								flag2 = 1;
							}
						}


					}
					if (flag2 == 0) {
						player->x -= player->vx;
					}
				}
			}
			break;
		case UNIT_DIRECT_UP:
			if (BAN[map[int((player->y - player->vy) / BLOCK_SIZE_Y)][(player->x / BLOCK_SIZE_Y)]] == 1) {
				int flag = 0;
				for (int i = 0; i < npcs.size(); i++) {
					NPC* npc = npcs[i];
					if (npc->visible == 1) {
						if ((((player->x <= npc->x && npc->x <= player->x + HUMAN_SIZE_X) || (npc->x <= player->x && player->x <= npc->x + HUMAN_SIZE_X)) &&
							((player->y - player->vy <= npc->y && npc->y <= player->y - player->vy + HUMAN_SIZE_Y) || (npc->y <= player->y - player->vy && player->y - player->vy <= npc->y + HUMAN_SIZE_X)))) {
							flag = 1;
						}

					}
					
				}
				if (flag == 0) {
					int flag2 = 0;
					for (int j = 0; j < aimonsters.size(); j++) {
						AIMonster* aimonster = aimonsters[j];
						if (aimonster->visible == 1) {
							if ((((player->x <= aimonster->x && aimonster->x <= player->x + 0.8 * AIMOSTER_SIZE_X) || (aimonster->x <= player->x && player->x <= aimonster->x + 0.8 * AIMOSTER_SIZE_X)) &&
								((player->y - player->vy <= aimonster->y && aimonster->y <= player->y - player->vy + 0.8 * AIMOSTER_SIZE_Y) || (aimonster->y <= player->y - player->vy && player->y - player->vy <= aimonster->y + 0.8 * AIMOSTER_SIZE_X)))) {
								flag2 = 1;
							}
						}

					}if (flag2 == 0) {
						player->y -= player->vy;
					}
				}
			}
			break;
		case UNIT_DIRECT_RIGHT:
			if ((BAN[map[int(player->y +3*player->vy)/ BLOCK_SIZE_Y][int((player->x + 2*player->vx) / BLOCK_SIZE_Y)]] == 1)&& (BAN[map[int(player->y   ) / BLOCK_SIZE_Y][int((player->x + 2*player->vx) / BLOCK_SIZE_Y)]] == 1)) {

				int flag = 0;
				for (int i = 0; i < npcs.size(); i++) {
					NPC* npc = npcs[i];
					if (npc->visible == 1) {
						if ((((player->x + player->vx <= npc->x && npc->x <= player->x + player->vx + HUMAN_SIZE_X) || (npc->x <= player->x + player->vx && player->x + player->vx <= npc->x + HUMAN_SIZE_X)) &&
							((player->y <= npc->y && npc->y <= player->y + HUMAN_SIZE_Y) || (npc->y <= player->y && player->y <= npc->y + HUMAN_SIZE_X)))) {
							flag = 1;
						}

					}
				}
				if (flag == 0) {
					int flag2 = 0;
					for (int j = 0; j < aimonsters.size(); j++) {
						AIMonster* aimonster = aimonsters[j];
						if (aimonster->visible == 1) {
							if ((((player->x + player->vx <= aimonster->x && aimonster->x <= player->x + player->vx + 0.8 * AIMOSTER_SIZE_X) || (aimonster->x <= player->x + player->vx && player->x + player->vx <= aimonster->x + 0.8 * AIMOSTER_SIZE_X)) &&
								((player->y <= aimonster->y && aimonster->y <= player->y + 0.8 * AIMOSTER_SIZE_Y) || (aimonster->y <= player->y && player->y <= aimonster->y + 0.8 * AIMOSTER_SIZE_X)))) {
								flag2 = 1;
							}
						}

					}if (flag2 == 0) {
						player->x += player->vx;
					}
				}
			}
			break;
		case UNIT_DIRECT_DOWN:
			if (int((player->y + 4*player->vy) / BLOCK_SIZE_Y) <= 19) {
				if (BAN[map[int((player->y + 4*player->vy) / BLOCK_SIZE_Y)][(player->x / BLOCK_SIZE_Y)]] == 1) {
					int flag = 0;
					for (int i = 0; i < npcs.size(); i++) {
						NPC* npc = npcs[i];
						if (npc->visible == 1) {
							if ((((player->x <= npc->x && npc->x <= player->x + HUMAN_SIZE_X) || (npc->x <= player->x && player->x <= npc->x + HUMAN_SIZE_X)) &&
								((player->y + player->vy <= npc->y && npc->y <= player->y + player->vy + HUMAN_SIZE_Y) || (npc->y <= player->y + player->vy && player->y + player->vy <= npc->y + HUMAN_SIZE_X)))) {
								flag = 1;
							}

						}
					}
					if (flag == 0) {
						int flag2 = 0;
						for (int j = 0; j < aimonsters.size(); j++) {
							AIMonster* aimonster = aimonsters[j];
							if (aimonster->visible == 1) {
								if ((((player->x <= aimonster->x && aimonster->x <= player->x + 0.8 * AIMOSTER_SIZE_X) || (aimonster->x <= player->x && player->x <= aimonster->x + 0.8 * AIMOSTER_SIZE_X)) &&
									((player->y + player->vy <= aimonster->y && aimonster->y <= player->y + player->vy + 0.8 * AIMOSTER_SIZE_Y) || (aimonster->y <= player->y + player->vy && player->y + player->vy <= aimonster->y + 0.8 * AIMOSTER_SIZE_X)))) {
									flag2 = 1;
								}
							}

						}if (flag2 == 0) {
							player->y += player->vy;
						}
					}
				}
			}
			break;
		case UNIT_DIRECT_LEFTUP:
			if (BAN[map[int((player->y - player->vy) / BLOCK_SIZE_Y)][int((player->x - player->vx) / BLOCK_SIZE_Y)]] == 1) {
				int flag = 0;
				for (int i = 0; i < npcs.size(); i++) {
					NPC* npc = npcs[i];
					if (npc->visible == 1) {
						if ((((player->x - player->vx <= npc->x && npc->x <= player->x - player->vx + HUMAN_SIZE_X) || (npc->x <= player->x - player->vx && player->x - player->vx <= npc->x + HUMAN_SIZE_X)) &&
							((player->y - player->vy <= npc->y && npc->y <= player->y - player->vy + HUMAN_SIZE_Y) || (npc->y <= player->y - player->vy && player->y - player->vy <= npc->y + HUMAN_SIZE_X)))) {
							flag = 1;
						}

					}
				
				}if (flag == 0) {
					int flag2 = 0;
					for (int j = 0; j < aimonsters.size(); j++) {
						AIMonster* aimonster = aimonsters[j];
						if (aimonster->visible == 1) {
							if ((((player->x - player->vx <= aimonster->x && aimonster->x <= player->x - player->vx + 0.8 * AIMOSTER_SIZE_X) || (aimonster->x <= player->x - player->vx && player->x - player->vx <= aimonster->x + 0.8 * AIMOSTER_SIZE_X)) &&
								((player->y - player->vy <= aimonster->y && aimonster->y <= player->y - player->vy + 0.8 * AIMOSTER_SIZE_Y) || (aimonster->y <= player->y - player->vy && player->y - player->vy <= aimonster->y + 0.8 * AIMOSTER_SIZE_X)))) {
								flag2 = 1;
							}
						}

					}if (flag2 == 0) {
						player->x -= player->vx;
						player->y -= player->vy;
					}
				}
			}
			break;
		case UNIT_DIRECT_LEFTDOWN:
			if (int((player->y + player->vy) / BLOCK_SIZE_Y) <= 19) {
				if (BAN[map[int((player->y + 4*player->vy) / BLOCK_SIZE_Y)][int((player->x - player->vx) / BLOCK_SIZE_Y)]] == 1) {
					int flag = 0;
					for (int i = 0; i < npcs.size(); i++) {
						NPC* npc = npcs[i];
						if (npc->visible == 1) {
							if ((((player->x - player->vx <= npc->x && npc->x <= player->x - player->vx + HUMAN_SIZE_X) || (npc->x <= player->x - player->vx && player->x - player->vx <= npc->x + HUMAN_SIZE_X)) &&
								((player->y + player->vy <= npc->y && npc->y <= player->y + player->vy + HUMAN_SIZE_Y) || (npc->y <= player->y + player->vy && player->y + player->vy <= npc->y + HUMAN_SIZE_X)))) {
								flag = 1;
							}

						}
					}if (flag == 0) {
						int flag2 = 0;
						for (int j = 0; j < aimonsters.size(); j++) {
							AIMonster* aimonster = aimonsters[j];
							if (aimonster->visible == 1) {
								if ((((player->x - player->vx <= aimonster->x && aimonster->x <= player->x - player->vx + 0.8 * AIMOSTER_SIZE_X) || (aimonster->x <= player->x - player->vx && player->x - player->vx <= aimonster->x + 0.8 * AIMOSTER_SIZE_X)) &&
									((player->y + player->vy <= aimonster->y && aimonster->y <= player->y + player->vy + 0.8 * AIMOSTER_SIZE_Y) || (aimonster->y <= player->y + player->vy && player->y + player->vy <= aimonster->y + 0.8 * AIMOSTER_SIZE_X)))) {
									flag2 = 1;
								}
							}

						}if (flag2 == 0) {
							player->x -= player->vx;
							player->y += player->vy;
						}
					}
				}
			}
			break;
		case UNIT_DIRECT_RIGHTUP:
			if (BAN[map[int((player->y - player->vy) / BLOCK_SIZE_Y)][int((player->x + player->vx) / BLOCK_SIZE_Y)]] == 1) {
				int flag = 0;
				for (int i = 0; i < npcs.size(); i++) {
					NPC* npc = npcs[i];
					if (npc->visible == 1) {
					if ((((player->x + player->vx <= npc->x && npc->x <= player->x + player->vx + HUMAN_SIZE_X) || (npc->x <= player->x + player->vx && player->x + player->vx <= npc->x + HUMAN_SIZE_X)) &&
						((player->y - player->vy <= npc->y && npc->y <= player->y - player->vy + HUMAN_SIZE_Y) || (npc->y <= player->y - player->vy && player->y - player->vy <= npc->y + HUMAN_SIZE_X)))) {
						flag = 1;
					}

					}
				}if (flag == 0) {
					int flag2 = 0;
					for (int j = 0; j < aimonsters.size(); j++) {
						AIMonster* aimonster = aimonsters[j];
						if (aimonster->visible == 1) {
							if ((((player->x + player->vx <= aimonster->x && aimonster->x <= player->x + player->vx + 0.8 * AIMOSTER_SIZE_X) || (aimonster->x <= player->x + player->vx && player->x + player->vx <= aimonster->x + 0.8 * AIMOSTER_SIZE_X)) &&
								((player->y - player->vy <= aimonster->y && aimonster->y <= player->y - player->vy + 0.8 * AIMOSTER_SIZE_Y) || (aimonster->y <= player->y - player->vy && player->y - player->vy <= aimonster->y + 0.8 * AIMOSTER_SIZE_X)))) {
								flag2 = 1;
							}
						}

					}if (flag2 == 0) {
						player->x += player->vx;
						player->y -= player->vy;
					}
				}
			}
		
				break;
		case UNIT_DIRECT_RIGHTDOWN:
			if (int((player->y + player->vy) / BLOCK_SIZE_Y) <= 19) {
				if (BAN[map[int((player->y + 4*player->vy) / BLOCK_SIZE_Y)][int((player->x + player->vx) / BLOCK_SIZE_Y)]] == 1) {
					int flag = 0;
					for (int i = 0; i < npcs.size(); i++) {
						NPC* npc = npcs[i];
						if (npc->visible == 1) {
						if ((((player->x + player->vx <= npc->x && npc->x <= player->x + player->vx + HUMAN_SIZE_X) || (npc->x <= player->x + player->vx && player->x + player->vx <= npc->x + HUMAN_SIZE_X)) &&
							((player->y + player->vy <= npc->y && npc->y <= player->y + player->vy + HUMAN_SIZE_Y) || (npc->y <= player->y + player->vy && player->y + player->vy <= npc->y + HUMAN_SIZE_X)))) {
							flag = 1;
						}

					}
					}if (flag == 0) {
						int flag2 = 0;
						for (int j = 0; j < aimonsters.size(); j++) {
							AIMonster* aimonster = aimonsters[j];
							if (aimonster->visible == 1) {
								if ((((player->x + player->vx <= aimonster->x && aimonster->x <= player->x + player->vx + 0.8 * AIMOSTER_SIZE_X) || (aimonster->x <= player->x + player->vx && player->x + player->vx <= aimonster->x + 0.8 * AIMOSTER_SIZE_X)) &&
									((player->y + player->vy <= aimonster->y && aimonster->y <= player->y + player->vy + 0.8 * AIMOSTER_SIZE_Y) || (aimonster->y <= player->y + player->vy && player->y + player->vy <= aimonster->y + 0.8 * AIMOSTER_SIZE_X)))) {
									flag2 = 1;
								}
							}

						}if (flag2 == 0) {
							player->x += player->vx;
							player->y += player->vy;
						}
					}
				}
			}
			break;
		default:
			break;
			};
			}
	
	
	//动画运行到下一帧
	player->frame_id++;
	player->frame_id = player->frame_id % player->frame_count;
	player->frame_column = player->frame_sequence[player->frame_id];
}


//更新AI怪兽状态
void UpdateAIMonsters(HWND hWnd) {
	for (int i = 0; i < aimonsters.size(); i++) {
		AIMonster* aimonster = aimonsters[i];
		attack2 = aimonster->attack2;
		if (aimonster->visible == 1) {
			if ((( aimonster->x <= player->x + 5 * HUMAN_SIZE_X)  && (player->x <= aimonster->x + 5 * HUMAN_SIZE_X) && (aimonster->y <= player->y + 5 * HUMAN_SIZE_Y) && (player->y <= aimonster->y + 5 * HUMAN_SIZE_Y))&&!(((player->x + 0.8 * HUMAN_SIZE_X >= aimonster->x) && (player->y + 0.8 * HUMAN_SIZE_Y >= aimonster->y)) && ((aimonster->x >= (player->x - 0.8 * HUMAN_SIZE_X)) && (aimonster->y >= (player->y - 0.8 * HUMAN_SIZE_Y))))) {
				aimonster->state = UNIT_STATE_WALK;
				aimonster->frame_sequence = FRAMES_WALK;
				aimonster->frame_count = FRAMES_WALK_COUNT;
				int dx = abs(player->x - aimonster->x) + 1;
				int dy = abs(player->y - aimonster->y);
				float rate = dy / dx;
				if (((player->x < aimonster->x && player->y < aimonster->y) && (0.6 < rate < 1))) {
					aimonster->direction = UNIT_DIRECT_LEFTUP;
					aimonster->frame_row = 3;
				}
				else if (((player->x > aimonster->x && player->y < aimonster->y) && (0.6 < rate < 1))) {
					aimonster->direction = UNIT_DIRECT_RIGHTUP;
					aimonster->frame_row = 1;
				}
				else if (((player->x > aimonster->x && player->y > aimonster->y) && (0.6 < rate < 1.7))) {
					aimonster->direction = UNIT_DIRECT_RIGHTDOWN;
					aimonster->frame_row = 0;
				}
				else if (((player->x < aimonster->x && player->y > aimonster->y) && (0.6 < rate < 1.7))) {
					aimonster->direction = UNIT_DIRECT_LEFTDOWN;
					aimonster->frame_row = 0;
				}
				else if (((player->x <= aimonster->x && player->y <= aimonster->y) && (rate < 0.6)) || ((player->x <= aimonster->x && player->y >= aimonster->y) && (rate < 0.6))) {
					aimonster->direction = UNIT_DIRECT_LEFT;
					aimonster->frame_row = aimonster->direction;
				}
				else if ((((player->x <= aimonster->x && player->y <= aimonster->y) && (rate > 1)) || ((player->x >= aimonster->x && player->y <= aimonster->y) && (rate > 1)))) {
					aimonster->direction = UNIT_DIRECT_UP;
					aimonster->frame_row = aimonster->direction;
				}
				else if (((player->x >= aimonster->x && player->y <= aimonster->y) && (rate < 0.6)) || ((player->x >= aimonster->x && player->y >= aimonster->y) && (rate < 0.6))) {
					aimonster->direction = UNIT_DIRECT_RIGHT;
					aimonster->frame_row = aimonster->direction;
				}
				else if ((((player->x >= aimonster->x && player->y >= aimonster->y) && (rate > 1.7)) || ((player->x <= aimonster->x && player->y >= aimonster->y) && (rate > 1.7)))) {
					aimonster->direction = UNIT_DIRECT_DOWN;
					aimonster->frame_row = aimonster->direction;
				}

			}
			else if (((player->x + HUMAN_SIZE_X >= 0.8 *aimonster->x) && (player->y + 0.8 * HUMAN_SIZE_Y >= aimonster->y)) && ((aimonster->x >= (player->x - 0.8 * HUMAN_SIZE_X))&& (aimonster->y >= (player->y - 0.5 * HUMAN_SIZE_Y))) ) {
				aimonster->state = UNIT_STATE_HOLD;
				aimonster->frame_sequence = AIMONSTER_FRAMES_HOLD;
				aimonster->frame_count = AIMONSTER_FRAMES_HOLD_COUNT;
				// 检查是否达到攻击间隔时间
				if (GetTime() - aimonster->lastAttackTime >= aimonster->attackInterval) {
					aimonster->lastAttackTime = GetTime(); // 更新上次攻击时间

					// 触发攻击
					
					TriggerAttack(player, aimonster, aimonster->attack2);
				}
				

			}

			else {
				aimonster->state = UNIT_STATE_WALK;
				aimonster->frame_sequence = FRAMES_WALK;
				aimonster->frame_count = FRAMES_WALK_COUNT;
				if (rand() % 20 == 0) {
					if (rand() % 3 == 0) {	//转身
						aimonster->state = UNIT_STATE_HOLD;
						aimonster->frame_sequence = AIMONSTER_FRAMES_HOLD;
						aimonster->frame_count = AIMONSTER_FRAMES_HOLD_COUNT;
					}
					else {					//移动
						aimonster->frame_column = rand() % 4;
						switch (aimonster->frame_column)
						{
						case 0:		//down
							if (int((aimonster->y + aimonster->vy) / BLOCK_SIZE_Y) <= 19) {
								if (BAN[map[int((aimonster->y + aimonster->vy) / BLOCK_SIZE_Y)][int(aimonster->x / BLOCK_SIZE_Y)]] == 1) {
									aimonster->direction = UNIT_DIRECT_DOWN;
									aimonster->frame_row = aimonster->direction;
									aimonster->y += aimonster->vy;
								}
							}
							break;
						case 1:		//right
							if (BAN[map[int(aimonster->y / BLOCK_SIZE_Y)][int((aimonster->x + aimonster->vx) / BLOCK_SIZE_Y)]] == 1) {
								aimonster->x += aimonster->vx;
								aimonster->direction = UNIT_DIRECT_RIGHT;
								aimonster->frame_row = aimonster->direction;
							}
							break;
						case 2:		//left
							if (BAN[map[int(aimonster->y / BLOCK_SIZE_Y)][int((aimonster->x - aimonster->vx) / BLOCK_SIZE_Y)]] == 1) {
								aimonster->x -= aimonster->vx;
								aimonster->direction = UNIT_DIRECT_LEFT;
								aimonster->frame_row = aimonster->direction;
							}
							break;
						case 3:		//up
							if (BAN[map[int((aimonster->y - aimonster->vy) / BLOCK_SIZE_Y)][int(aimonster->x / BLOCK_SIZE_Y)]] == 1) {
								aimonster->y -= aimonster->vy;
								aimonster->direction = UNIT_DIRECT_UP;
								aimonster->frame_row = aimonster->direction;
							}
							break;
						default:
							break;
						}
						aimonster->frame_id++;
						aimonster->frame_id = aimonster->frame_id % aimonster->frame_count;
						aimonster->frame_column = aimonster->frame_sequence[aimonster->frame_id];
					}
				}
			}
			if (aimonster->attack2 != NULL && aimonster->attack2->visible) {
				//动画运行到下一帧
				aimonster->attack2->frame_id++;
				//char ooo[123];
				//_itoa_s(attack2->frame_id, ooo, 10);
				//OutputDebugStringA(ooo);
				//OutputDebugStringA("\n");
				aimonster->attack2->frame_id = aimonster->attack2->frame_id % aimonster->attack2->frame_count;
				aimonster->attack2->frame_column = aimonster->attack2->frame_sequence[aimonster->attack2->frame_id];
				if (aimonster->attack2->frame_id == 0) {
					aimonster->attack2->visible = false;
				}
			}
			//更新位置
			if (aimonster->state == UNIT_STATE_WALK) {
				switch (aimonster->direction) {
				case UNIT_DIRECT_LEFT:
					if (BAN[map[int(aimonster->y  / BLOCK_SIZE_Y)][int((aimonster->x - aimonster->vx) / BLOCK_SIZE_Y)]] == 1) {
						aimonster->x -= aimonster->vx;
					}
					break;
				case UNIT_DIRECT_UP:
					if (BAN[map[int((aimonster->y - aimonster->vy) / BLOCK_SIZE_Y)][int(aimonster->x  / BLOCK_SIZE_Y)]] == 1) {
						aimonster->y -= aimonster->vy;
					}
					break;
				case UNIT_DIRECT_RIGHT:
					if (BAN[map[int(aimonster->y / BLOCK_SIZE_Y)][int((aimonster->x + aimonster->vx) / BLOCK_SIZE_Y)]] == 1) {
						aimonster->x += aimonster->vx;
					}
					break;
				case UNIT_DIRECT_DOWN:
					if (int((player->y + player->vy) / BLOCK_SIZE_Y) <= 19) {
						if (BAN[map[int((aimonster->y + aimonster->vy) / BLOCK_SIZE_Y)][int(aimonster->x / BLOCK_SIZE_Y)]] == 1) {
							aimonster->y += aimonster->vy;
						}
					}
					break;
				case UNIT_DIRECT_LEFTUP:
					if (BAN[map[int((aimonster->y - aimonster->vy) / BLOCK_SIZE_Y)][int((aimonster->x - aimonster->vx) / BLOCK_SIZE_Y)]] == 1) {
						aimonster->x -= aimonster->vx;
						aimonster->y -= aimonster->vy;
					}
					break;
				case UNIT_DIRECT_LEFTDOWN:
					if (int((player->y + player->vy) / BLOCK_SIZE_Y) <= 19) {
						if (BAN[map[int((aimonster->y + aimonster->vy) / BLOCK_SIZE_Y)][int((aimonster->x - aimonster->vx) / BLOCK_SIZE_Y)]] == 1) {
							aimonster->x -= aimonster->vx;
							aimonster->y += aimonster->vy;
						}
					}
					break;
				case UNIT_DIRECT_RIGHTUP:
					if (BAN[map[int((aimonster->y - aimonster->vy) / BLOCK_SIZE_Y)][int((aimonster->x + aimonster->vx) / BLOCK_SIZE_Y)]] == 1) {
						aimonster->x += aimonster->vx;
						aimonster->y -= aimonster->vy;
					}
					break;
				case UNIT_DIRECT_RIGHTDOWN:
					if (int((player->y + player->vy) / BLOCK_SIZE_Y) <= 19) {
						if (BAN[map[int((aimonster->y + aimonster->vy) / BLOCK_SIZE_Y)][int((aimonster->x + aimonster->vx) / BLOCK_SIZE_Y)]] == 1) {
							aimonster->x += aimonster->vx;
							aimonster->y += aimonster->vy;
						}
					}
					break;
				default:
					break;
				};
			}


			//动画运行到下一帧
			aimonster->frame_id++;
			aimonster->frame_id = aimonster->frame_id % aimonster->frame_count;
			aimonster->frame_column = aimonster->frame_sequence[aimonster->frame_id];

		}
	}
}
//更新NPC状态

void Updateditu(HWND hWnd) {
	if (currentStage->stageID == STAGE_4)
	{
		int flag = 0;
		for (int i = 0; i < aimonsters.size(); i++) {
			AIMonster* aimonster = aimonsters[i];
			if (aimonster->visible == 1)flag = 1;
		}
		if (flag == 0) { ercigengxin1 = 1; InitStage(hWnd, STAGE_4);  }


	}
	if (currentStage->stageID == STAGE_5)
	{
		int flag = 0;
		for (int i = 0; i < aimonsters.size(); i++) {
			AIMonster* aimonster = aimonsters[i];
			if (aimonster->visible == 1)flag = 1;
		}
		if (flag == 0) { ercigengxin2 = 1; InitStage(hWnd, STAGE_5); }


	}
	if (currentStage->stageID == STAGE_9)
	{
		int flag = 0;
		for (int i = 0; i < aimonsters.size(); i++) {
			AIMonster* aimonster = aimonsters[i];
			if (aimonster->visible == 1)flag = 1;
		}
		if (flag == 0) { ercigengxin3 = 1; InitStage(hWnd, STAGE_9); }


	}
}
	
void UpdateNPCs(HWND hWnd) {

	//顺次更新每个npc
	for (int i = 0; i < npcs.size(); i++) {
		//动画运行到下一帧
		npcs[i]->frame_id++;
		npcs[i]->frame_id = npcs[i]->frame_id % npcs[i]->frame_count;
		npcs[i]->frame_column = npcs[i]->frame_sequence[npcs[i]->frame_id];
	}
}
void UpdateMonsters(HWND hWnd)
{
	//顺次更新每个怪物
	for (int i = 0; i < monsters.size(); i++) {
		//动画运行到下一帧
		monsters[i]->frame_id++;
		monsters[i]->frame_id = monsters[i]->frame_id % monsters[i]->frame_count;
		monsters[i]->frame_column = monsters[i]->frame_sequence[monsters[i]->frame_id];
	}
}
//void Updateboss(HWND hWnd)
//{
//	//顺次更新每个怪物
//	   boss->state = UNIT_STATE_ATTACK;
//	   boss->frame_sequence = FRAMES_WALK;
//	    boss->frame_count = FRAMES_WALK_COUNT;
//		monsters[i]->frame_id++;
//		monsters[i]->frame_id = monsters[i]->frame_id % monsters[i]->frame_count;
//		monsters[i]->frame_column = monsters[i]->frame_sequence[monsters[i]->frame_id];
//	}
//}
// 地图切换逻辑
void UpdateMaps(HWND hWnd)
{

	//走到地图边界，切换到map2
	if (currentStage->stageID == STAGE_1 && player->y <= 15 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0 && ditu2)
	{
		player->y = 672 - (player->y + 1.1 * HUMAN_SIZE_Y);

		InitStage(hWnd, STAGE_2);


	}
	if (currentStage->stageID == STAGE_1 && player->y <= 15 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0 && !ditu2)
	{
		player->y = 35;
		yinxiao = 1;
		yinxiaotansuo(yinxiao);

	}
	if (currentStage->stageID == STAGE_1 && player->x >= 890 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0 && !ditu3)
	{

		player->x = 870;
		yinxiao = 1;
		yinxiaotansuo(yinxiao);

	}
	if (currentStage->stageID == STAGE_1 && player->x >= 890 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0 && ditu3)
	{

		player->x = 32;
		InitStage(hWnd, STAGE_3);

	}

	if (currentStage->stageID == STAGE_2 && player->y >= 615 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)
	{

		InitStage(hWnd, STAGE_1);
		player->y = 672 - (player->y + 0.7 * HUMAN_SIZE_Y);

	}
	if (currentStage->stageID == STAGE_3 && player->y <= 15 && (map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 24 || map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 25 || map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 26) && !ditu4)
	{
		player->y = 35;
		yinxiao = 1;
		yinxiaotansuo(yinxiao);

	}
	if (currentStage->stageID == STAGE_3 && player->y <= 15 && (map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 24 || map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 25 || map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 26) && ditu4)
	{
		player->x = 450;
		player->y = 672 - (player->y + 0.1 * HUMAN_SIZE_Y)-100;
		InitStage(hWnd, STAGE_4);

	}

	if (currentStage->stageID == STAGE_3 && player->y >= 600 && (map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 24 || map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 26) && !ditu5)
	{
		player->y = 580;
		yinxiao = 1;
		yinxiaotansuo(yinxiao);

	}
	if (currentStage->stageID == STAGE_3 && player->y >= 620 && (map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 24 || map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 26) && ditu5)
	{
		player->x = 450;
		player->y = 672 - (player->y + 1.1 * HUMAN_SIZE_Y)+50;
		migong = 1;
		migong_ = migong;
		InitStage(hWnd, STAGE_10);


	}
	if (currentStage->stageID == STAGE_3 && player->x <= 15 && (map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 24 || map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 20 || map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 28))
	{

		player->x = 65;
		yinxiao = 1;
		yinxiaotansuo(yinxiao);

	}
	if (currentStage->stageID == STAGE_3 && player->y <= 230 && (map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 93))
	{

		player->y = 610;
		player->x = 480;

		InitStage(hWnd, STAGE_6);

	}
	if (currentStage->stageID == STAGE_3 && player->y <= 500 && (map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 59)&&ditu6)
	{


		player->y = 420;
		player->x = 420;
		jinwu = 1;
		yinxiaokuqi(jinwu);
		InitStage(hWnd, STAGE_7);

	}
	if (currentStage->stageID == STAGE_3 && player->y <= 500 && (map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 59) && !ditu6)
	{

		player->y = 520;
		yinxiao = 1;
		yinxiaotansuo(yinxiao);

	}
	if (currentStage->stageID == STAGE_6 && player->y >= 620 && (map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 108 || map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 109)&&!guanmen)
	{

		player->y = 250;
		player->x = 530;


		InitStage(hWnd, STAGE_3);

	}
	if (currentStage->stageID == STAGE_6 && player->y >= 620 && (map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 108 || map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 109) && guanmen)
	{

		
		ismima = 1;
		InitStage(hWnd, STAGE_20);

	}
	if (currentStage->stageID == STAGE_7 && player->y >= 430 && (map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 108 || map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 109))
	{

		player->y = 510;
		player->x = 400;


		InitStage(hWnd, STAGE_3);

	}
	if (currentStage->stageID == STAGE_7 && player->y <= 430 && (map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 139))
	{

		player->y += 40;



		InitStage(hWnd, STAGE_8);

	}
	if (currentStage->stageID == STAGE_8 && player->y <= 430 && (map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 158))
	{

		player->y += 40;



		InitStage(hWnd, STAGE_7);

	}
	//迷宫逻辑
	if (currentStage->stageID == STAGE_10 && player->y <= 15 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)//上
	{
		player->y = 602;
		player->x = 230;
		InitStage(hWnd, STAGE_3);
		aaaa = 1;
		migong = 0;
		migong_ = migong;

	}
	if (currentStage->stageID == STAGE_10 && player->x >= 890 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)//右
	{
		player->x = 32;
		InitStage(hWnd, STAGE_12);
		migong_ = migong;


	}
	if (currentStage->stageID == STAGE_10 && player->y >= 615 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)//下
	{
		player->y = 672 - (player->y + 0.7 * HUMAN_SIZE_Y);
		InitStage(hWnd, STAGE_13);
		if (migong > 1)		migong--;
		migong_ = migong;



	}
	if (currentStage->stageID == STAGE_10 && player->x <= 15 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)//左
	{
		player->x = 880;
		InitStage(hWnd, STAGE_11);
		migong++;
		migong_ = migong;

	}
	if (currentStage->stageID == STAGE_11 && player->y <= 15 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)
	{
		player->y = 672 - (player->y + 1.1 * HUMAN_SIZE_Y);
		InitStage(hWnd, STAGE_13);
		migong_ = migong;


	}
	if (currentStage->stageID == STAGE_11 && player->x >= 890 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)
	{
		player->x = 32;
		InitStage(hWnd, STAGE_10);
		if (migong > 1)		migong--;

		migong_ = migong;


	}
	if (currentStage->stageID == STAGE_11 && player->y >= 615 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)
	{
		player->y = 672 - (player->y + 0.7 * HUMAN_SIZE_Y);
		InitStage(hWnd, STAGE_12);
		migong++;
		migong_ = migong;

	}
	if (currentStage->stageID == STAGE_11 && player->x <= 15 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)
	{
		player->y = 602;
		player->x = 230;
		InitStage(hWnd, STAGE_3);
		aaaa = 1;
		migong = 0;
		migong_ = migong;

	}
	if (currentStage->stageID == STAGE_12 && player->y <= 15 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)//上
	{
		player->y = 672 - (player->y + 1.1 * HUMAN_SIZE_Y);
		InitStage(hWnd, STAGE_11);
		if (migong > 1)		migong--;

		migong_ = migong;


	}
	if (currentStage->stageID == STAGE_12 && player->x >= 890 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)//右
	{
		player->x = 32;
		InitStage(hWnd, STAGE_13);
		migong++;
		migong_ = migong;

	}
	if (currentStage->stageID == STAGE_12 && player->y >= 615 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)//下
	{
		player->y = 602;
		player->x = 230;
		InitStage(hWnd, STAGE_3);
		migong = 0;
		aaaa = 1;
		migong_ = migong;

	}
	if (currentStage->stageID == STAGE_12 && player->x <= 15 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)//左
	{
		player->x = 880;
		InitStage(hWnd, STAGE_10);
		migong_ = migong;

	}
	if (currentStage->stageID == STAGE_13 && player->y <= 15 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)//上
	{
		player->y = 672 - (player->y + 1.1 * HUMAN_SIZE_Y);
		InitStage(hWnd, STAGE_10);
		migong_ = migong;


	}
	if (currentStage->stageID == STAGE_13 && player->x >= 890 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)//右
	{
		player->y = 602;
		player->x = 230;
		InitStage(hWnd, STAGE_3);
		migong = 0;
		migong_ = migong;
		aaaa = 1;



	}
	if (currentStage->stageID == STAGE_13 && player->y >= 615 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)//下
	{
		player->y = 672 - (player->y + 0.7 * HUMAN_SIZE_Y);

		InitStage(hWnd, STAGE_11);
		migong++;
		migong_ = migong;

	}
	if (currentStage->stageID == STAGE_13 && player->x <= 15 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)//左
	{
		player->x = 880;
		InitStage(hWnd, STAGE_12);
		if (migong > 1)		migong--;

		migong_ = migong;

	}
	if (currentStage->stageID == STAGE_14 && player->y <= 15 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)//上
	{
		player->y = 602;
		player->x = 230;
		InitStage(hWnd, STAGE_3);
		migong = 0;
		migong_ = migong;
	

	}
	if (currentStage->stageID == STAGE_14 && player->x >= 890 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)//右
	{
		player->y = 602;
		player->x = 230;
		InitStage(hWnd, STAGE_3);
		migong = 0;
		migong_ = migong;



	}
	if (currentStage->stageID == STAGE_14 && player->y >= 615 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)//下
	{
		player->y = 602;
		player->x = 230;
		InitStage(hWnd, STAGE_3);
		migong = 0;
		migong_ = migong;

	}
	if (currentStage->stageID == STAGE_14 && player->x <= 15 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)//左
	{
		player->y = 602;
		player->x = 230;
		InitStage(hWnd, STAGE_3);
		migong = 0;
		migong_ = migong;

	}
	if (currentStage->stageID == STAGE_4 && player->y <= 15 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0 )
	{
		player->y = 672 - (player->y + 1.1 * HUMAN_SIZE_Y)-50;

		InitStage(hWnd, STAGE_5);


	}
	if (currentStage->stageID == STAGE_5 && player->y <= 15 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0 )
	{
		player->y = 672 - (player->y + 1.1 * HUMAN_SIZE_Y)-50;

		InitStage(hWnd, STAGE_9);


	}
	if (currentStage->stageID == STAGE_9 && player->y <= 15 && map[player->y / BLOCK_SIZE_Y][player->x / BLOCK_SIZE_Y] == 0)
	{
		

		InitStage(hWnd, STAGE_win);


	}
}

//
//处理各种交互事件

//游戏暂停
void PAUSE(HWND hWnd) 
{
	if (keyESCDown) {
		InitStage(hWnd, STAGE_PAUSE);
	}
}
//void TASK(HWND hWnd)
//	if (keyFDown) {
//		if (istask==0) {
//			InitStage(hWnd, STAGE_TASK);
//		}
	//	else InitStage(hWnd, stagenum);
//	}
//}
//游戏失败
void GAMEOVER(HWND hWnd)
{
	if (player->alive==0) {
	//	die = 0;
		InitStage(hWnd, STAGE_GAMEOVER);
		
	}
}
//更新人物属性
void updateplayer(HWND hWnd){
	player->explimit = explimit[player->rank];
	player->healthlimit = healthlimit[player->rank];
	player->attack = attackdamage[player->rank];
	player->defence = defence[player->rank];

}


//攻击判定
void UpdateAttack(HWND hWnd)
{
	if (attack->visible) {
		//动画运行到下一帧
		attack->frame_id++;
		attack->frame_id = attack->frame_id % attack->frame_count;
		attack->frame_column = attack->frame_sequence[attack->frame_id];
		if (!keyAttackDown && attack->frame_id == 0)
			attack->visible = false;
	}

	if (player != NULL) {
		switch (player->direction)
		{
		case UNIT_DIRECT_RIGHT:
			attack->x = player->x + HUMAN_SIZE_X / 2 + ATTACK_SIZE_X / 2;
			attack->y = player->y;
			break;
		case UNIT_DIRECT_LEFT:
			attack->x = player->x - HUMAN_SIZE_X / 2 - ATTACK_SIZE_X / 2;
			attack->y = player->y;
			break;
		case UNIT_DIRECT_UP:
			attack->x = player->x;
			attack->y = player->y - HUMAN_SIZE_Y / 2 - ATTACK_BITMAP_SIZE_Y / 2;
			break;
		case UNIT_DIRECT_DOWN:
			attack->x = player->x;
			attack->y = player->y + HUMAN_SIZE_Y / 2 + ATTACK_SIZE_Y / 2;
			break;
		case UNIT_DIRECT_RIGHTUP:
			attack->x = player->x + HUMAN_SIZE_X / 2 + ATTACK_SIZE_X / 2;
			attack->y = player->y - HUMAN_SIZE_Y / 2 - ATTACK_BITMAP_SIZE_Y / 2;
			break;
		case UNIT_DIRECT_LEFTUP:
			attack->x = player->x - HUMAN_SIZE_X / 2 - ATTACK_SIZE_X / 2;
			attack->y = player->y - HUMAN_SIZE_Y / 2 - ATTACK_BITMAP_SIZE_Y / 2;
			break;
		case UNIT_DIRECT_LEFTDOWN:
			attack->x = player->x - HUMAN_SIZE_X / 2 - ATTACK_SIZE_X / 2;
			attack->y = player->y + HUMAN_SIZE_Y / 2 + ATTACK_SIZE_Y / 2;
			break;
		case UNIT_DIRECT_RIGHTDOWN:
			attack->x = player->x + HUMAN_SIZE_X / 2 + ATTACK_SIZE_X / 2;
			attack->y = player->y + HUMAN_SIZE_Y / 2 + ATTACK_SIZE_Y / 2;
			break;
		default:
			break;
		}
	}

	//怪物碰撞检测
	if (attack->visible  && attack->frame_id == 1) {
		for (int i = 0; i < monsters.size(); i++) {
			Monster* monster = monsters[i];
			if (monster->visible &&
				((attack->x <= monster->x && monster->x <= attack->x + ATTACK_SIZE_X) || (monster->x <= attack->x && attack->x <= monster->x + ATTACK_SIZE_X)) &&
				((attack->y <= monster->y && monster->y <= attack->y + ATTACK_SIZE_Y) || (monster->y <= attack->y && attack->y <= monster->y + ATTACK_SIZE_Y))) {
				monster->health -= player->attack;
				yinxiaogongji(yinxiao);
				if (monster->health <= 0) {
					monster->alive = false;
					monster->visible = false;

					player->exp += 2;
					 yinxiaojingyan(yinxiao);
					if (player->exp >= player->explimit) {
						player->exp %= player->explimit;
						player->rank++;
					}
					if (tasks[0]->value < 2) {
						tasks[0]->value++;
					}
					else if (tasks[0]->value == 2) {
						tasks[0]->value++;
						for (int j = 0; j < npcs.size(); j++) {
							if (npcs[j]->npcID == NPC_MAN1_ID) {
								npcs[j]->task_complete = true;
							}
						}
					}
					/*switch (monster->monsterID)
					{
					case MONSTER_CAT_ID:
						for (int j = 0; j < npcs.size(); j++) {
							if (npcs[j]->npcID == NPC_MAN1_ID) {
								npcs[j]->task_complete = true;
							}
						}
						break;
					default:
						break;
					}*/
				}
			}
		}
	}
	//AI怪物检测
	if (attack->visible && attack->frame_id == 1) {
	for (int i = 0; i < aimonsters.size(); i++) {
		AIMonster* monster = aimonsters[i];
		if (monster->visible &&
			((attack->x <= monster->x && monster->x <= attack->x + ATTACK_SIZE_X) || (monster->x <= attack->x && attack->x <= monster->x + ATTACK_SIZE_X)) &&
			((attack->y <= monster->y && monster->y <= attack->y + ATTACK_SIZE_Y) || (monster->y <= attack->y && attack->y <= monster->y + ATTACK_SIZE_Y))) {
			monster->health -= player->attack;
			yinxiaogongji(yinxiao);
			if (monster->health <= 0) {
				monster->alive = false;
				monster->visible = false;
				monster->attack2->visible = false;
				player->exp += monster->exp;
				yinxiaojingyan(yinxiao);
				if (tasks[0]->value < 2) {
					tasks[0]->value++;

				}
				else if (tasks[0]->value == 2) {
					tasks[0]->value++;
					for (int j = 0; j < npcs.size(); j++) {
						if (npcs[j]->npcID == NPC_MAN1_ID) {
							npcs[j]->task_complete = true;
						}
					}
				}
				if (player->exp >= player->explimit) {
					player->exp %= player->explimit;
					player->rank++;
				}
				
				
			}
		}
	}
}
	}
//怪物自动攻击
void TriggerAttack(Player* player, AIMonster* aimonster,Attack* attack2) {
	// 假设攻击2的触发条件与攻击1相同
	attack2->visible = true;

	

	// 设置攻击2的位置
	//switch (aimonster->direction) {
	//case UNIT_DIRECT_RIGHT:
	attack2->x = player->x;//+ HUMAN_SIZE_X / 2 + ATTACK_SIZE_X / 2;
		attack2->y = player->y;
	//	break;
	//case UNIT_DIRECT_LEFT:
		//attack2->x = aimonster->x - HUMAN_SIZE_X / 2 - ATTACK_SIZE_X / 2;
		//attack2->y = aimonster->y;
		//break;
	//case UNIT_DIRECT_UP:
		//attack2->x = aimonster->x;
	//	attack2->y = aimonster->y - HUMAN_SIZE_Y / 2 - ATTACK_BITMAP_SIZE_Y / 2;
		//break;
//	case UNIT_DIRECT_DOWN:
	//	attack2->x = aimonster->x;
	//	attack2->y = aimonster->y + HUMAN_SIZE_Y / 2 + ATTACK_SIZE_Y / 2;
	//	break;
//	default:
	//	break;
	//}

	// 碰撞检测
	if (attack2->visible ) {
		if (((attack2->x <= player->x && player->x <= attack2->x + ATTACK_SIZE_X) ||(player->x <= attack2->x && attack2->x <= player->x + ATTACK_SIZE_X))&&((attack2->y <= player->y && player->y <= attack2->y + ATTACK_SIZE_Y) ||(player->y <= attack2->y && attack2->y <= player->y + ATTACK_SIZE_Y))) {
					player->health -= (attack2->attack)/(1+ (float)player->defence);
					yinxiaoshoushang(yinxiao);
					if (player->health <= 0) {
						player->alive = false;
						die = 1;
					}
		}
	}
}

//抬起空格时触发，开启对话
void HandleConversationEvents(HWND hWnd) 
{
	//当前已经开启对话，再按一次空格关闭
	
	if (yinxiao)yinxiao = 0;
	if (jinwu)jinwu = 0;
	if (migong_)migong_ = 0;
	if (aaaa)aaaa = 0;
	int shuohua = 0;
	int flag = 0;
	//player与npc做碰撞检测，判断与哪个npc对话
	for (int i = 0; i < npcs.size(); i++) {
		NPC* npc = npcs[i];
		if (npc->visible) {
			flag = 1;
			if (((player->x <= npc->x && npc->x <= player->x + 1.1 * HUMAN_SIZE_X) || (npc->x <= player->x && player->x <= npc->x + 1.1 * HUMAN_SIZE_X)) &&
				((player->y <= npc->y && npc->y <= player->y + 1.1 * HUMAN_SIZE_Y) || (npc->y <= player->y && player->y <= npc->y + 1.1 * HUMAN_SIZE_X))) {
				in_conversation = true;
				shuohua = 1;
				if (!npc->task_complete) {
					converstaion_content = npc->conversations_before[npc->next_conversation1_id];

					if (npc->npcID == 2004) {
						npc->visible = 0;
						for (int j = 0; j < npcs.size(); j++) {
							NPC* npc = npcs[j];
							if (npc->npcID == 2003) {
								npc->task_complete = 1;
							}
						}
					}


					if (npc->next_conversation1_id < npc->conversations_before.size() - 1) {
						npc->next_conversation1_id++;
						if (npc->next_conversation1_id == npc->conversations_before.size() - 2) {
							if (npc->npcID == 2001) {
								tasks[0]->visible = 1;
								ditu2 = 1;
							}
							if (npc->npcID == 2002) {
								guanmen = 1;
							}
							if (npc->npcID == 2003) {
								ditu5 = 1;
							}
							if (npc->npcID == 2005) {
								props[0]->visible = false;
								props[1]->visible = true;
								props[2]->visible = true;
								props[3]->visible = true;
							}

						}

					}	//npc的这句话已经说完，下次该说下一句话了；如果已经说到最后一句话了，则一直重复
					else {
						npc->flag++;
						if (npc->flag % 2 == 0) {}
						else in_conversation = false;
					}

				}
				else {
					converstaion_content = npc->conversations_after[npc->next_conversation2_id];
					if (npc->next_conversation2_id < (npc->conversations_after.size() - 1)) {
						if (npc->next_conversation2_id == 1) {
							if (npc->npcID == 2001) {
								
							tasks[0]->finish = true;

							}
							


						}
						if (npc->next_conversation2_id == 3) {
							if (npc->npcID == 2001) {
								props[0]->visible = true;
							}
						}
						npc->next_conversation2_id++;
						if (npc->next_conversation2_id == npc->conversations_after.size() - 2) {

							if (npc->npcID == 2001) {
								ditu3 = 1;
								

							}
							if (npc->npcID == 2002) {
								ditu6 = 1;
							}
							if (npc->npcID == 2003) {
								ditu4 = 1;
							}
						}
					}//npc的这句话已经说完，下次该说下一句话了；如果已经说到最后一句话了，则一直重复
					else {
						npc->flag2++;
						if (npc->flag2 % 2 == 0) {}
						else in_conversation = false;
					}
				}
				break;
			}
			else {
				if ((npc->next_conversation1_id == npc->conversations_before.size() - 1) && in_conversation) {
					npc->flag++;
					in_conversation = false;
				}
				else if ((npc->next_conversation2_id == npc->conversations_after.size() - 1) && in_conversation) {
					npc->flag2++;
					in_conversation = false;
				}
				else {
					in_conversation = false;
					
					
				}
			}
		}


		
	}
	if(flag==0)in_conversation = false;
	//if(shuohua==0)in_conversation = false;
}


//TODO: 添加游戏需要的更多函数

// 添加按钮函数
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y)
{
	Button* button = new Button();
	button->buttonID = buttonID;
	button->img = img;
	button->width = width;
	button->height = height;
	button->x = x;
	button->y = y;

	button->visible = false;
	return button;
}


// 添加主角函数
Player* CreatePlayer(int x, int y)
{
	Player* player = new Player();
	if (sex == 1) { player->img = bmp_player2; }
	else player->img = bmp_Player;
	player->x = x;
	player->y = y;
	player->direction = UNIT_DIRECT_RIGHT;
	player->vx = 5;
	player->vy = 5;
	player->health = 10;
	player->healthlimit = 10;
	player->exp = 0;
	player->explimit = 5;
	player->rank = 1;
	player->attack = 1;
	player->defence = 0;
	player->alive = 1;




	player->state = UNIT_STATE_HOLD;
	player->frame_row = player->direction;
	player->frame_column = 0;
	player->frame_sequence = PLAYER_FRAMES_HOLD;
	player->frame_count = PLAYER_FRAMES_HOLD_COUNT;
	player->frame_id = 0;

	return player;
}
// 添加AImonster函数
AIMonster* CreateAIMonster(int x, int y,int aimonster_id)
{
	AIMonster* aimonster = new AIMonster();
	aimonster->img = bmp_slime;
	aimonster->x = x;
	aimonster->y = y;
	aimonster->direction = UNIT_DIRECT_RIGHT;
	aimonster->vx = 1;
	aimonster->alive = 1;
	aimonster->vy = 1;
	aimonster->attack2 = new Attack;
	aimonster->attack2->frame_id = 0;
	aimonster->attack2->frame_sequence = ATTACK_FRAMES;
	aimonster->attack2->frame_count = ATTACK_FRAMES_COUNT;
	aimonster->attack2->frame_row = 0;
	aimonster->attack2->frame_column = 0;
	aimonster->attack2->img = bmp_attack2;
	aimonster->state = UNIT_STATE_HOLD;
	aimonster->frame_row = aimonster->direction;
	aimonster->frame_column = 0;
	aimonster->frame_sequence = AIMONSTER_FRAMES_HOLD;
	aimonster->frame_count = AIMONSTER_FRAMES_HOLD_COUNT;
	aimonster->frame_id = 0;
	switch (aimonster_id)
	{
	case AIMONSTER_SLIME_ID:
	{
		aimonster->img = bmp_slime;
		aimonster->health = 3;
		aimonster->exp = 2;
		aimonster->attack2->attack = 1;
		break;
	

	}
	case AIMONSTER_RACOON_ID:
	{
		aimonster->img = bmp_racoon;
		aimonster->vx = 2;
		aimonster->vy = 2;
		aimonster->health = 5;
		aimonster->attack2->attack = 1;
		aimonster->exp = 5;

		break;
		
	}
	case AIMONSTER_MONSTER_ID:
	{
		aimonster->img = bmp_monster;
		aimonster->vx = 3;
		aimonster->vy = 3;
		aimonster->health = 1;
		aimonster->attack2->attack = 10;
		aimonster->exp = 10;

		break;

	}
	default:
		break;
	}

	return aimonster;
}
// 添加NPC函数
NPC* CreateNPC(int x, int y, int npc_id)
{
	NPC* npc = new NPC();
	npc->npcID = npc_id;
	npc->visible = true;
	npc->task_complete = false;
	npc->x = x;
	npc->y = y;
	npc->direction = UNIT_DIRECT_DOWN;
	npc->vx = 0;
	npc->vy = 0;
	npc->flag = 1;
	npc->flag2 = 1;
	npc->state = UNIT_STATE_HOLD;
	npc->frame_row = npc->direction;
	npc->frame_column = 0;
	npc->frame_sequence = NPC_FRAMES_HOLD;
	npc->frame_count = NPC_FRAMES_HOLD_COUNT;
	npc->frame_id = 0;
	npc->next_conversation1_id = 0;
	npc->next_conversation2_id = 0;
	//根据不同NPC初始化不同的图像和对话
	switch (npc_id)
	{
	case NPC_MAN1_ID: {
		npc->img = bmp_NPC_MAN1;
		npc->conversations_before.push_back(L"你好！欢迎来到这个世界");
		npc->conversations_before.push_back(L"什么？你问我你是怎么来到这个世界的");
		npc->conversations_before.push_back(L"那不重要");
		npc->conversations_before.push_back(L"不过你天赋异禀，拥有杀死怪物的能力");
		npc->conversations_before.push_back(L"你问我怎么看出来的？");
		npc->conversations_before.push_back(L"哥们，你画面左上角都画着属性栏了...");
		npc->conversations_before.push_back(L"不相信？按K使用攻击试试");
		npc->conversations_before.push_back(L"信了吧~");
		npc->conversations_before.push_back(L"沿着这里向上走有一片草坪，那里有三只怪物，你可以帮我杀掉他们吗？");
		npc->conversations_before.push_back(L"我不会亏待你的！");
		npc->conversations_before.push_back(L"对了，你可以按F键查看任务进度哦");
		npc->conversations_before.push_back(L"期待你回来！");
		npc->conversations_after.push_back(L"可以嘛");
		npc->conversations_after.push_back(L"这么轻松就打败他们了");
		npc->conversations_after.push_back(L"不愧是你");
		npc->conversations_after.push_back(L"给你这把神奇的钥匙");
		npc->conversations_after.push_back(L"你可以按F键打开任务栏，然后点击右上角的PROP按钮进入道具背包，你就能看到它了");
		npc->conversations_after.push_back(L"你问它有什么用处？");
		npc->conversations_after.push_back(L"我也不知道，它是我在巡林的时候捡到的");
		npc->conversations_after.push_back(L"对了，我们的小镇就在右面，去小镇找镇长聊聊吧");
		npc->conversations_after.push_back(L"他会告诉你接下来该干什么的");




		break;
	}
	case NPC_MAYOR_ID: {
		npc->img = bmp_mayor;
		npc->conversations_before.push_back(L"你好！");
		npc->conversations_before.push_back(L"听说你是来自什么清北大学的高材生");
		npc->conversations_before.push_back(L"想必你一定是德智体美劳全面发展的“三好学生”吧！");
		npc->conversations_before.push_back(L"我们镇子近期遇到了很多困难");
		npc->conversations_before.push_back(L"而我相信，以你的这些品质，一定能够帮助我们一一化解");
		npc->conversations_before.push_back(L"届时，我将会送你回你的世界");
		npc->conversations_before.push_back(L"首先是第一关，对你的智的考察");
		npc->conversations_before.push_back(L"让我先来测一测你的智商，看看你到底是不是真材实料！");
		npc->conversations_before.push_back(L"这里的门被动了手脚");
		npc->conversations_before.push_back(L"进来不需要密码，而出去则需要密码");
		npc->conversations_before.push_back(L"以你的聪明才智，能否从这个密室逃脱呢？");
		npc->conversations_after.push_back(L"什么！？你竟然破解出来了，不应该啊...");
		npc->conversations_after.push_back(L"我记着我把带有谜底的纸条放到了带锁的书柜里");
		npc->conversations_after.push_back(L"难道你会撬锁？");
		npc->conversations_after.push_back(L"或者你其实是暴力枚举的！");
		npc->conversations_after.push_back(L"......");
		npc->conversations_after.push_back(L"绝对是！否则不应该啊。。。");
		npc->conversations_after.push_back(L"总之，恭喜你通过了第一关");
		npc->conversations_after.push_back(L"但是，后面的考验可就没那么简单了");
		npc->conversations_after.push_back(L"我们的的镇子被魔法诅咒了，人们的东西丢失，魔物也不时入侵");
		npc->conversations_after.push_back(L"但我相信凭你的“德”");
		npc->conversations_after.push_back(L"一定能用主体光辉照亮世界！！");
		npc->conversations_after.push_back(L"咳咳");
		npc->conversations_after.push_back(L"总之，你去镇子上转转吧，看看有没有需要帮助的人");










		break;
	}
	case NPC_BOY_ID: {
		npc->img = bmp_boy1;
		npc->conversations_before.push_back(L"呜呜呜呜呜呜呜呜呜呜呜");
		npc->conversations_before.push_back(L"我的...呜呜..猫猫");
		npc->conversations_before.push_back(L"呜呜呜，跑，呜呜呜呜呜呜");
		npc->conversations_before.push_back(L"南边..呜呜呜...森林....呜呜呜呜呜..不见");
		npc->conversations_before.push_back(L"呜呜呜呜呜...找....呜呜呜呜呜");
		npc->conversations_after.push_back(L"呜呜呜......！！！");
		npc->conversations_after.push_back(L"！！！！！！！！");
		npc->conversations_after.push_back(L"我的猫猫呜呜呜");
		npc->conversations_after.push_back(L"你回来了呜呜呜");
		npc->conversations_after.push_back(L"谢谢你，我尝试去追猫猫，却发现我迷路了，怎么走都会走回来");
		npc->conversations_after.push_back(L"哦对，你就是那个大学生吧，镇长嘱托我跟你说");
		npc->conversations_after.push_back(L"最后一关的考验是对你的体能的考验");
		npc->conversations_after.push_back(L"这考验可不简单");
		npc->conversations_after.push_back(L"不是你用**拳就能轻松通过的");
		npc->conversations_after.push_back(L"镇子的北边入口被一群魔物包围了");
		npc->conversations_after.push_back(L"他们已经困扰许久，我们也快撑不住了");
		npc->conversations_after.push_back(L"沿着镇子北上，怪物的难度会不断加强");
		npc->conversations_after.push_back(L"他们有的速度快，攻击高，有的血量厚");
		npc->conversations_after.push_back(L"但是没关系，你的能力随着打怪会不断加强");
		npc->conversations_after.push_back(L"而且击败有的怪物会回复你的血量");
		npc->conversations_after.push_back(L"不必担心！");
		npc->conversations_after.push_back(L"那么抓紧时间去击败他们吧");
		npc->conversations_after.push_back(L"我们等着你的好消息！");



		break;
	}
	case NPC_CAT_ID: {
		npc->img = bmp_cat;
		npc->conversations_before.push_back(L"喵喵喵");





		break;
	}
	case NPC_LOCK_ID: {
		npc->img = bmp_lock;
		npc->conversations_before.push_back(L"这个书柜上了锁");
		npc->conversations_before.push_back(L"使用【神秘的钥匙】打开了书柜");
		npc->conversations_before.push_back(L"获得了【纸片1】【纸片2】【纸片3】");







		break;
	}
	default:
		break;
	}

	return npc;
}

Monster* CreateMonster(int x, int y, int monster_id)
{
	Monster* monster = new Monster();
	monster->monsterID = monster_id;
	monster->visible = true;
	monster->alive = true;
	monster->task_complete = false;
	monster->x = x;
	monster->y = y;
	monster->direction = UNIT_DIRECT_DOWN;
	monster->vx = 0;
	monster->vy = 0;
	monster->state = UNIT_STATE_HOLD;
	monster->frame_row = monster->direction;
	monster->frame_column = 0;
	monster->frame_sequence = NPC_FRAMES_HOLD;
	monster->frame_count = NPC_FRAMES_HOLD_COUNT;
	monster->frame_id = 0;
	monster->next_conversation_id = 0;
	//根据不同ID初始化不同的图像和对话
	switch (monster_id)
	{
	case MONSTER_CAT_ID:
	{
		monster->img = bmp_monster1;
		monster->conversations_before.push_back(L"喵喵喵。");
		break;
	}
	default:
		break;
	}

	return monster;
}
Attack* CreateAttack()
{
	Attack* attack = new Attack();
	attack->img = bmp_attack;
	attack->visible = false;

	attack->frame_row = 0;
	attack->frame_column = 0;
	attack->frame_sequence = ATTACK_FRAMES;
	attack->frame_count = ATTACK_FRAMES_COUNT;
	attack->frame_id = 0;

	return attack;
}
Attack* CreateAttack2()
{
	Attack* attack2 = new Attack();
	attack2->img = bmp_attack2;
	attack2->visible = false;

	attack2->frame_row = 0;
	attack2->frame_column = 0;
	attack2->frame_sequence = ATTACK_FRAMES;
	attack2->frame_count = ATTACK_FRAMES_COUNT;
	attack2->frame_id = 0;

	return attack2;
}

// 初始化游戏场景函数
void InitStage(HWND hWnd, int stageID)
{
	// 初始化场景实例

	if (currentStage != NULL) delete currentStage;
	currentStage = new Stage();
	currentStage->stageID = stageID;

	if (stageID == STAGE_STARTMENU) {
			PlaySound(MAKEINTRESOURCE(IDR_START), NULL, SND_RESOURCE | SND_ASYNC | SND_LOOP);
		currentStage->bg = bmp_Background;
		currentStage->timerOn = false;
		stagenum = stageID;
		//显示开始界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_STARTGAME&&kaishi)
				button->visible = true;
			else if(button->buttonID == BUTTON_HELP)
				button->visible = true;
			else button->visible = false;
		}
	}
	if (stageID == STAGE_CHOOSE) {
		currentStage->bg = bmp_choose;
		currentStage->timerOn = false;
		stagenum = stageID;
		//显示开始界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_BOY)
				button->visible = true;
			else if (button->buttonID == BUTTON_GIRL)
				button->visible = true;
			else button->visible = false;
		}
	}
	else if (stageID == STAGE_HELP) {
		currentStage->bg = bmp_HELP1;
		currentStage->timerOn = false;
		//显示帮助界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_BACK)
				button->visible = true;
			else button->visible = false;
		}
	}
	else if (stageID == STAGE_PAUSE) {
		currentStage->bg = bmp_Pause;
		currentStage->timerOn = false;
		//显示暂停界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID ==  BUTTON_CONTINUE)
				button->visible = true;
			else if (button->buttonID == BUTTON_RESTART)
				button->visible = true;
			else if (button->buttonID == BUTTON_BACKTOTITLE)
				button->visible = true;
			else button->visible = false;
		}
	}
	else if (stageID == STAGE_TASK) {
		currentStage->bg = bmp_task;
		currentStage->timerOn = false;
		//显示任务界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_TASK)
				button->visible = true;
			else if (button->buttonID == BUTTON_PROP)
				button->visible = true;
			else button->visible = false;
		}
		
	}
	else if (stageID == STAGE_PROP) {
		currentStage->bg = bmp_prop;
		currentStage->timerOn = false;
		//显示任务界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_TASK)
				button->visible = true;
			else if (button->buttonID == BUTTON_PROP)
				button->visible = true;
			else button->visible = false;
		}

	}
	else if (stageID == STAGE_GAMEOVER) {
		PlaySound(MAKEINTRESOURCE(IDR_DIE), NULL, SND_RESOURCE | SND_ASYNC | SND_LOOP);
		die = 0;
		currentStage->bg = bmp_gameover;
		currentStage->timerOn = false;
		
		//显示失败界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_RESTART2)
				button->visible = true;
			else if (button->buttonID == BUTTON_BACKTOTITLE2)
				button->visible = true;
			else button->visible = false;
		}
	}
	else if (stageID == STAGE_win) {
		PlaySound(MAKEINTRESOURCE(IDR_WIN), NULL, SND_RESOURCE | SND_ASYNC | SND_LOOP);
		currentStage->bg = bmp_victory;
		currentStage->timerOn = false;
		stagenum = stageID;
		jieju++;
		//显示失败界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_BACKTOTITLE3)
				button->visible = true;
			else button->visible = false;
		}
	}
	//TODO：添加多个游戏场景
	else if (stageID == STAGE_1)
	{
		currentStage->bg = bmp_Background;
		currentStage->timerOn = true;
		stagenum = stageID;
		if (yinyueon == 0) {
			PlaySound(NULL, NULL, SND_RESOURCE | SND_ASYNC | SND_LOOP);
			PlaySound(MAKEINTRESOURCE(IDR_MAIN), NULL, SND_RESOURCE | SND_ASYNC | SND_LOOP);
			yinyueon++;
		}
		//音乐系统调试
		//int ret = mciSendString(L"open m/1.wav", NULL, 0, NULL);
		//int ret3 = mciSendString(L"open m/0.wav", NULL, 0, NULL);
		//wchar_t text[256];
		//mciGetErrorString(ret, text, sizeof(text));
		//int ret2 = mciSendString(L"play m/1.wav", NULL, 0, 0); 
		//int ret4 = mciSendString(L"play m/0.wav", NULL, 0, 0);

		memcpy(map, map_stage1, sizeof(map));	//初始化地图
		//显示游戏界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			if (buttons[i]->buttonID == BUTTON_MANU) //TODO：加载游戏界面需要的按钮
				buttons[i]->visible = true;
			else
				buttons[i]->visible = false;
		}
		if (player == NULL)
			player = CreatePlayer(200, 200);					//第一次调用：初始化player
		if (npcs.size() == 0) {
			npcs.push_back(CreateNPC(625, 200, NPC_MAN1_ID));	//第一次调用：初始化NPC
		}
		//NPC的可见性
		for (int i = 0; i < npcs.size(); i++)
		{
			NPC* npc = npcs[i];
			if (true) //TODO：加载游戏界面需要的按钮
				npc->visible = true;
			else
				npc->visible = false;
		}
		//Monster的可见性
		for (int i = 0; i < monsters.size(); i++)
		{
			Monster* monster = monsters[i];
			if (false) //TODO：加载游戏界面需要的按钮
				monster->visible = true;
			else
				monster->visible = false;
		}
		//AIMonster的可见性
		for (int i = 0; i < aimonsters.size(); i++)
		{
			AIMonster* aimonster = aimonsters[i];
			if (false) //TODO：加载游戏界面需要的按钮
				aimonster->visible = true;
			else
				aimonster->visible = false;

		}
	}
	else if (stageID == STAGE_2)
	{
		currentStage->bg = bmp_Background;
		currentStage->timerOn = true;
		stagenum = stageID;
		memcpy(map, map_stage2, sizeof(map));
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (buttons[i]->buttonID == BUTTON_MANU)
				button->visible = true;
			else
				button->visible = false;
		}
		if (player == NULL)
			player = CreatePlayer(200, 200);
		if (monsters.size() == 0) {
			monsters.push_back(CreateMonster(495, 205, MONSTER_CAT_ID));//初始化Monster
		}
		if (aimonsters.size() == 0) {
			aimonsters.push_back(CreateAIMonster(295, 205, AIMONSTER_SLIME_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(395, 205, AIMONSTER_SLIME_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(495, 205, AIMONSTER_SLIME_ID));//初始化AIMonster
			
		}
		//NPC的可见性
		for (int i = 0; i < npcs.size(); i++)
		{
			NPC* npc = npcs[i];
			if (false) //TODO：加载游戏界面需要的按钮
				npc->visible = true;
			else
				npc->visible = false;
		}
		//Monster的可见性
		for (int i = 0; i < monsters.size(); i++)
		{
			Monster* monster = monsters[i];
			if (0) //TODO：加载游戏界面需要的按钮
				monster->visible = true;
			else
				monster->visible = false;
		}
		//AIMonster的可见性
		for (int i = 0; i < aimonsters.size(); i++)
		{
			AIMonster* aimonster = aimonsters[i];
			if (aimonster->alive) //TODO：加载游戏界面需要的按钮
				aimonster->visible = true;
			else
				aimonster->visible = false;
		}
	}
	else if (stageID == STAGE_4)
	{
		currentStage->bg = bmp_Background;
		currentStage->timerOn = true;
		stagenum = stageID;
		if (!ercigengxin1) memcpy(map, map_stage4, sizeof(map));
		else if (ercigengxin1) memcpy(map, map_stage5, sizeof(map));
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (buttons[i]->buttonID == BUTTON_MANU)
				button->visible = true;
			else
				button->visible = false;
		}
		if (player == NULL)player = CreatePlayer(200, 200);
		aimonsters.clear();
		if (!ercigengxin1) {
			aimonsters.push_back(CreateAIMonster(295, 205, AIMONSTER_RACOON_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(395, 205, AIMONSTER_RACOON_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(495, 205, AIMONSTER_RACOON_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(115, 205, AIMONSTER_RACOON_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(395, 505, AIMONSTER_RACOON_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(595, 305, AIMONSTER_RACOON_ID));//初始化AIMonster
			
		}
		//NPC的可见性
		for (int i = 0; i < npcs.size(); i++)
		{
			NPC* npc = npcs[i];
			if (false) //TODO：加载游戏界面需要的按钮
				npc->visible = true;
			else
				npc->visible = false;
		}
		//Monster的可见性
		for (int i = 0; i < monsters.size(); i++)
		{
			Monster* monster = monsters[i];
			if (0) //TODO：加载游戏界面需要的按钮
				monster->visible = true;
			else
				monster->visible = false;
		}
		//AIMonster的可见性
		for (int i = 0; i < aimonsters.size(); i++)
		{
			AIMonster* aimonster = aimonsters[i];
			if (aimonster->alive) //TODO：加载游戏界面需要的按钮
				aimonster->visible = true;
			else
				aimonster->visible = false;
		}
		}
	else if (stageID == STAGE_5)
	{
		currentStage->bg = bmp_Background;
		currentStage->timerOn = true;
		stagenum = stageID;
		if (!ercigengxin2) memcpy(map, map_stage4, sizeof(map));
		if (ercigengxin2) memcpy(map, map_stage5, sizeof(map));
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (buttons[i]->buttonID == BUTTON_MANU)
				button->visible = true;
			else
				button->visible = false;
		}
		if (player == NULL)player = CreatePlayer(200, 200);
		aimonsters.clear();
		if (!ercigengxin2) {
			aimonsters.push_back(CreateAIMonster(295, 205, AIMONSTER_MONSTER_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(395, 205, AIMONSTER_MONSTER_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(495, 205, AIMONSTER_MONSTER_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(115, 205, AIMONSTER_MONSTER_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(395, 505, AIMONSTER_MONSTER_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(595, 305, AIMONSTER_MONSTER_ID));//初始化AIMonster

		}
		//NPC的可见性
		for (int i = 0; i < npcs.size(); i++)
		{
			NPC* npc = npcs[i];
			if (false) //TODO：加载游戏界面需要的按钮
				npc->visible = true;
			else
				npc->visible = false;
		}
		//Monster的可见性
		for (int i = 0; i < monsters.size(); i++)
		{
			Monster* monster = monsters[i];
			if (0) //TODO：加载游戏界面需要的按钮
				monster->visible = true;
			else
				monster->visible = false;
		}
		//AIMonster的可见性
		for (int i = 0; i < aimonsters.size(); i++)
		{
			AIMonster* aimonster = aimonsters[i];
			if (aimonster->alive) //TODO：加载游戏界面需要的按钮
				aimonster->visible = true;
			else
				aimonster->visible = false;
		}
		}
	else if (stageID == STAGE_9)
	{
		currentStage->bg = bmp_Background;
		currentStage->timerOn = true;
		stagenum = stageID;
		if (!ercigengxin3)memcpy(map, map_stage4, sizeof(map));
		else memcpy(map, map_stage5, sizeof(map));
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (buttons[i]->buttonID == BUTTON_MANU)
				button->visible = true;
			else
				button->visible = false;
		}
		if (player == NULL)player = CreatePlayer(200, 200);
		aimonsters.clear();
		if (!ercigengxin3) {
			aimonsters.push_back(CreateAIMonster(295, 205, AIMONSTER_MONSTER_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(395, 205, AIMONSTER_MONSTER_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(495, 205, AIMONSTER_MONSTER_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(115, 205, AIMONSTER_MONSTER_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(395, 505, AIMONSTER_MONSTER_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(595, 305, AIMONSTER_SLIME_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(293, 205, AIMONSTER_SLIME_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(324, 205, AIMONSTER_SLIME_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(425, 205, AIMONSTER_RACOON_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(146, 205, AIMONSTER_RACOON_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(345, 505, AIMONSTER_RACOON_ID));//初始化AIMonster
			aimonsters.push_back(CreateAIMonster(532, 305, AIMONSTER_RACOON_ID));//初始化AIMonster

		}
		//NPC的可见性
		for (int i = 0; i < npcs.size(); i++)
		{
			NPC* npc = npcs[i];
			if (false) //TODO：加载游戏界面需要的按钮
				npc->visible = true;
			else
				npc->visible = false;
		}
		//Monster的可见性
		for (int i = 0; i < monsters.size(); i++)
		{
			Monster* monster = monsters[i];
			if (0) //TODO：加载游戏界面需要的按钮
				monster->visible = true;
			else
				monster->visible = false;
		}
		//AIMonster的可见性
		for (int i = 0; i < aimonsters.size(); i++)
		{
			AIMonster* aimonster = aimonsters[i];
			if (aimonster->alive) //TODO：加载游戏界面需要的按钮
				aimonster->visible = true;
			else
				aimonster->visible = false;
		}
		}
	else if (stageID == STAGE_3)
	{
		currentStage->bg = bmp_Background;
		currentStage->timerOn = true;
		stagenum = stageID;
		memcpy(map, map_stage3, sizeof(map));
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (buttons[i]->buttonID == BUTTON_MANU)
				button->visible = true;
			else
				button->visible = false;
		}
		if (player == NULL)
			player = CreatePlayer(200, 200);
		if (monsters.size() == 0) {
			//monsters.push_back(CreateMonster(495, 205, MONSTER_CAT_ID));//初始化Monster
		}
		if (aimonsters.size() == 0) {
			//aimonsters.push_back(CreateAIMonster(295, 205, AIMONSTER_SLIME_ID));//初始化AIMonster
			//aimonsters.push_back(CreateAIMonster(395, 205, AIMONSTER_RACOON_ID));//初始化AIMonster

		}
		//NPC的可见性
		for (int i = 0; i < npcs.size(); i++)
		{
			NPC* npc = npcs[i];
			if (false) //TODO：加载游戏界面需要的按钮
				npc->visible = true;
			else
				npc->visible = false;
		}
		////Monster的可见性
		//for (int i = 0; i < monsters.size(); i++)
		//{
		//	Monster* monster = monsters[i];
		//	if (monster->alive) //TODO：加载游戏界面需要的按钮
		//		monster->visible = true;
		//	else
		//		monster->visible = false;
		//}
		////AIMonster的可见性
		//for (int i = 0; i < aimonsters.size(); i++)
		//{
		//	AIMonster* aimonster = aimonsters[i];
		//	if (aimonster->alive) //TODO：加载游戏界面需要的按钮
		//		aimonster->visible = true;
		//	else
		//		aimonster->visible = false;
		//}
		}
	else if (stageID == STAGE_6)
	{
		currentStage->bg = bmp_Background;
		currentStage->timerOn = true;
		stagenum = stageID;
		memcpy(map, map_stage6, sizeof(map));
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (buttons[i]->buttonID == BUTTON_MANU)
				button->visible = true;
			else
				button->visible = false;
		}
		if (player == NULL)
			player = CreatePlayer(200, 200);
		if (monsters.size() == 0) {
			//monsters.push_back(CreateMonster(495, 205, MONSTER_CAT_ID));//初始化Monster
		}
		if (aimonsters.size() == 0) {
			//aimonsters.push_back(CreateAIMonster(295, 205, AIMONSTER_SLIME_ID));//初始化AIMonster
			//aimonsters.push_back(CreateAIMonster(395, 205, AIMONSTER_RACOON_ID));//初始化AIMonster

		}
		//NPC的可见性
		int yesorno = 0;
		for (int i = 0; i < npcs.size(); i++)
		{
			NPC* npc = npcs[i];
			if (npc->npcID==2002 ) //TODO：加载游戏界面需要的按钮
				yesorno++;
		}
		if (yesorno == 0) {
			npcs.push_back(CreateNPC(460, 230, NPC_MAYOR_ID));	//第一次调用：初始化NPC
			npcs.push_back(CreateNPC(850, 75, NPC_LOCK_ID));	//第一次调用：初始化NPC

		}
		for (int i = 0; i < npcs.size(); i++)
		{
			NPC* npc = npcs[i];
			if (npc->npcID==2002|| npc->npcID == 2005) //TODO：加载游戏界面需要的按钮
				npc->visible = true;
			else
				npc->visible = false;
		}
		////Monster的可见性
		//for (int i = 0; i < monsters.size(); i++)
		//{
		//	Monster* monster = monsters[i];
		//	if (monster->alive) //TODO：加载游戏界面需要的按钮
		//		monster->visible = true;
		//	else
		//		monster->visible = false;
		//}
		////AIMonster的可见性
		//for (int i = 0; i < aimonsters.size(); i++)
		//{
		//	AIMonster* aimonster = aimonsters[i];
		//	if (aimonster->alive) //TODO：加载游戏界面需要的按钮
		//		aimonster->visible = true;
		//	else
		//		aimonster->visible = false;
		//}
		}
	else if (stageID == STAGE_7)
	{
		currentStage->bg = bmp_Background;
		currentStage->timerOn = true;
		stagenum = stageID;
		memcpy(map, map_stage7, sizeof(map));
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (buttons[i]->buttonID == BUTTON_MANU)
				button->visible = true;
			else
				button->visible = false;
		}
		if (player == NULL)
			player = CreatePlayer(200, 200);
		if (monsters.size() == 0) {
			//monsters.push_back(CreateMonster(495, 205, MONSTER_CAT_ID));//初始化Monster
		}
		if (aimonsters.size() == 0) {
			//aimonsters.push_back(CreateAIMonster(295, 205, AIMONSTER_SLIME_ID));//初始化AIMonster
			//aimonsters.push_back(CreateAIMonster(395, 205, AIMONSTER_RACOON_ID));//初始化AIMonster

		}
		//NPC的可见性

		

		for (int i = 0; i < npcs.size(); i++)
		{
			NPC* npc = npcs[i];
			if (0) //TODO：加载游戏界面需要的按钮
				npc->visible = true;
			else
				npc->visible = false;
		}
		////Monster的可见性
		//for (int i = 0; i < monsters.size(); i++)
		//{
		//	Monster* monster = monsters[i];
		//	if (monster->alive) //TODO：加载游戏界面需要的按钮
		//		monster->visible = true;
		//	else
		//		monster->visible = false;
		//}
		////AIMonster的可见性
		//for (int i = 0; i < aimonsters.size(); i++)
		//{
		//	AIMonster* aimonster = aimonsters[i];
		//	if (aimonster->alive) //TODO：加载游戏界面需要的按钮
		//		aimonster->visible = true;
		//	else
		//		aimonster->visible = false;
		//}
		}
	else if (stageID == STAGE_8)
	{
		currentStage->bg = bmp_Background;
		currentStage->timerOn = true;
		stagenum = stageID;
		memcpy(map, map_stage8, sizeof(map));
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (buttons[i]->buttonID == BUTTON_MANU)
				button->visible = true;
			else
				button->visible = false;
		}
		if (player == NULL)
			player = CreatePlayer(200, 200);
		if (monsters.size() == 0) {
			//monsters.push_back(CreateMonster(495, 205, MONSTER_CAT_ID));//初始化Monster
		}
		if (aimonsters.size() == 0) {
			//aimonsters.push_back(CreateAIMonster(295, 205, AIMONSTER_SLIME_ID));//初始化AIMonster
			//aimonsters.push_back(CreateAIMonster(395, 205, AIMONSTER_RACOON_ID));//初始化AIMonster

		}
		//NPC的可见性
		int yesorno = 0;
		for (int i = 0; i < npcs.size(); i++)
		{
			NPC* npc = npcs[i];
			if (npc->npcID == 2003) {
				yesorno++;
			}
		}
		if (yesorno == 0) {
			npcs.push_back(CreateNPC(400, 400, NPC_BOY_ID));	//第一次调用：初始化NPC
		}

		for (int i = 0; i < npcs.size(); i++)
		{
			NPC* npc = npcs[i];
			if (npc->npcID==2003) //TODO：加载游戏界面需要的按钮
				npc->visible = true;
			else
				npc->visible = false;
		}
		////Monster的可见性
		//for (int i = 0; i < monsters.size(); i++)
		//{
		//	Monster* monster = monsters[i];
		//	if (monster->alive) //TODO：加载游戏界面需要的按钮
		//		monster->visible = true;
		//	else
		//		monster->visible = false;
		//}
		////AIMonster的可见性
		//for (int i = 0; i < aimonsters.size(); i++)
		//{
		//	AIMonster* aimonster = aimonsters[i];
		//	if (aimonster->alive) //TODO：加载游戏界面需要的按钮
		//		aimonster->visible = true;
		//	else
		//		aimonster->visible = false;
		//}
		}
	else if (stageID == STAGE_10)
	{
		currentStage->bg = bmp_Background;
		currentStage->timerOn = true;
		stagenum = stageID;
		memcpy(map, map_stage10, sizeof(map));
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (buttons[i]->buttonID == BUTTON_MANU)
				button->visible = true;
			else
				button->visible = false;
		}
	}
	else if (stageID == STAGE_11)
	{
		currentStage->bg = bmp_Background;
		currentStage->timerOn = true;
		stagenum = stageID;
		memcpy(map, map_stage10, sizeof(map));
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (buttons[i]->buttonID == BUTTON_MANU)
				button->visible = true;
			else
				button->visible = false;
		}
	}
	else if (stageID == STAGE_12)
	{
		currentStage->bg = bmp_Background;
		currentStage->timerOn = true;
		stagenum = stageID;
		memcpy(map, map_stage10, sizeof(map));
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (buttons[i]->buttonID == BUTTON_MANU)
				button->visible = true;
			else
				button->visible = false;
		}
		}
	else if (stageID == STAGE_13)
	{
		currentStage->bg = bmp_Background;
		currentStage->timerOn = true;
		stagenum = stageID;
		memcpy(map, map_stage10, sizeof(map));
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (buttons[i]->buttonID == BUTTON_MANU)
				button->visible = true;
			else
				button->visible = false;
		}
		}
	else if (stageID == STAGE_14)
	{
		currentStage->bg = bmp_Background;
		currentStage->timerOn = true;
		stagenum = stageID;
		memcpy(map, map_stage11, sizeof(map));
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (buttons[i]->buttonID == BUTTON_MANU)
				button->visible = true;
			else
				button->visible = false;
		}
		int yesorno = 0;
		for (int i = 0; i < npcs.size(); i++)
		{
			NPC* npc = npcs[i];
			if (npc->npcID == 2004) //TODO：加载游戏界面需要的按钮
				yesorno++;
		}
		if (yesorno == 0) {
			npcs.push_back(CreateNPC(450, 320, NPC_CAT_ID));	//第一次调用：初始化NPC
		}
		for (int i = 0; i < npcs.size(); i++)
		{
			NPC* npc = npcs[i];
			if (npc->npcID == 2004) //TODO：加载游戏界面需要的按钮
				npc->visible = true;
			else
				npc->visible = false;
		}
		}
	else if (stageID == STAGE_20)
	{
		currentStage->bg = bmp_mima;
		currentStage->timerOn = false;
		//显示任务界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID >= 1013&&button->buttonID!=1050) button->visible = true;
			else button->visible = false;



		}
	}
	
	//刷新显示
	InvalidateRect(hWnd, NULL, FALSE);
}





// 绘图函数
void Paint(HWND hWnd)
{

	PAINTSTRUCT ps;
	HDC hdc_window = BeginPaint(hWnd, &ps);

	HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
	HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);
	HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH hBrush1 = CreateSolidBrush(RGB(0, 255, 0));
	//初始化缓存
	HBITMAP	blankBmp = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(hdc_memBuffer, blankBmp);


	// 按场景分类绘制内容到缓存
	if (currentStage->stageID == STAGE_STARTMENU) {
		// 绘制背景到缓存
		SelectObject(hdc_loadBmp, currentStage->bg);
		TransparentBlt(
			hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT,
			hdc_loadBmp, 0, 0, BG_BITMAP_WIDTH, BG_BITMAP_HEIGHT,
			RGB(255, 255, 255));

	}
	else if (currentStage->stageID == STAGE_HELP) {
		// 绘制背景到缓存
		SelectObject(hdc_loadBmp, currentStage->bg);
		TransparentBlt(
			hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT,
			hdc_loadBmp, 0, 0, BG_BITMAP_WIDTH, BG_BITMAP_HEIGHT,
			RGB(255, 255, 255));
		HFONT hFont = CreateFontW(
			25, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
			L"SimSun");		//创建字体
		SelectObject(hdc_memBuffer, hFont);
		SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
		SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
		SetBkMode(hdc_memBuffer, TRANSPARENT);
		RECT rect;
		rect.left = 150;
		rect.top = 235;
		rect.right = WINDOW_WIDTH - 10;
		rect.bottom = WINDOW_HEIGHT - 50;
		DrawTextW(hdc_memBuffer, L"你是清北大学的一位高材生\n这天，你在电脑桌前疯狂地赶ddl\n你睡眼惺忪，最终还是昏睡过去\n你当你再次睁开眼时\n你已经仿佛被降维打击一般，来到了一个像素的世界\n借助你强大的头脑，你发现\n这个世界的物理规律不同于现实世界\n你需要按“WASD”或者“↑↓←→”进行移动\n按下空格才能和周围的事物交互,按ESC甚至能使时间暂停\nOS：“这真的不是游戏的世界吗，太老套了”\n看到远处有一个人正在东张西望，你打算上前一问究竟", -1, &rect, DT_WORDBREAK);
		DeleteObject(hFont);


	}
	else if (currentStage->stageID == STAGE_PAUSE) {
		// 绘制背景到缓存
		SelectObject(hdc_loadBmp, currentStage->bg);
		TransparentBlt(
			hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT,
			hdc_loadBmp, 0, 0, BG_BITMAP_WIDTH, BG_BITMAP_HEIGHT,
			RGB(255, 255, 255));

	}
	else if (currentStage->stageID == STAGE_GAMEOVER) {
		// 绘制背景到缓存
		SelectObject(hdc_loadBmp, currentStage->bg);
		TransparentBlt(
			hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT,
			hdc_loadBmp, 0, 0, BG_BITMAP_WIDTH, BG_BITMAP_HEIGHT,
			RGB(255, 255, 255));

	}
	else if (currentStage->stageID == STAGE_win) {
		// 绘制背景到缓存
		SelectObject(hdc_loadBmp, currentStage->bg);
		TransparentBlt(
			hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT,
			hdc_loadBmp, 0, 0, BG_BITMAP_WIDTH, BG_BITMAP_HEIGHT,
			RGB(255, 255, 255));

	}
	else if (currentStage->stageID == STAGE_CHOOSE) {
		// 绘制背景到缓存
		SelectObject(hdc_loadBmp, currentStage->bg);
		TransparentBlt(
			hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT,
			hdc_loadBmp, 0, 0, BG_BITMAP_WIDTH, BG_BITMAP_HEIGHT,
			RGB(255, 255, 255));

	}
	else if (currentStage->stageID == STAGE_TASK) {
		// 绘制背景到缓存
		SelectObject(hdc_loadBmp, currentStage->bg);
		TransparentBlt(
			hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT,
			hdc_loadBmp, 0, 0, BG_BITMAP_WIDTH, BG_BITMAP_HEIGHT,
			RGB(255, 255, 255));

	}
	else if (currentStage->stageID == STAGE_20) {
		// 绘制背景到缓存
		SelectObject(hdc_loadBmp, currentStage->bg);
		TransparentBlt(
			hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT,
			hdc_loadBmp, 0, 0, BG_BITMAP_WIDTH, BG_BITMAP_HEIGHT,
			RGB(255, 255, 255));

	}
	else if (currentStage->stageID == STAGE_PROP) {
		// 绘制背景到缓存
		SelectObject(hdc_loadBmp, currentStage->bg);
		TransparentBlt(
			hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT,
			hdc_loadBmp, 0, 0, BG_BITMAP_WIDTH, BG_BITMAP_HEIGHT,
			RGB(255, 255, 255));

	}
	else if (currentStage->stageID >= STAGE_1 ) //TODO：添加多个游戏场景
	{
		//绘制地图
		SelectObject(hdc_loadBmp, bmp_map);
		for (int i = 0; i < sizeof(map) / sizeof(map[0]); i++) {
			for (int j = 0; j < sizeof(map[0]) / sizeof(map[0][0]); j++) {
				TransparentBlt(
					hdc_memBuffer,
					j * BLOCK_SIZE_X, i * BLOCK_SIZE_Y,							// 界面上起始绘制点
					BLOCK_SIZE_X, BLOCK_SIZE_Y,									// 界面上绘制宽度高度
					hdc_loadBmp,
					(map[i][j] % 4) * BLOCK_BITMAP_SIZE_X,						// 位图上起始绘制点
					(map[i][j] / 4) * BLOCK_BITMAP_SIZE_Y,
					BLOCK_BITMAP_SIZE_X, BLOCK_BITMAP_SIZE_Y,					// 位图上绘制宽度高度
					RGB(255, 255, 255));										// 位图上的哪个颜色会被视为背景
			}
		}

		// 绘制玩家
		SelectObject(hdc_loadBmp, player->img);
		TransparentBlt(
			hdc_memBuffer,
			player->x - 0.5 * HUMAN_SIZE_X, player->y - 0.5 * HUMAN_SIZE_Y,			// 界面上起始绘制点
			HUMAN_SIZE_X, HUMAN_SIZE_Y,											// 界面上绘制宽度高度
			hdc_loadBmp,
			HUMAN_BITMAP_SIZE_X * player->frame_column, HUMAN_BITMAP_SIZE_Y * player->frame_row,	// 位图上起始绘制点
			HUMAN_BITMAP_SIZE_X, HUMAN_BITMAP_SIZE_Y,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		//绘制npc
		for (int i = 0; i < npcs.size(); i++) {
			if (npcs[i]->visible) {
				SelectObject(hdc_loadBmp, npcs[i]->img);
				TransparentBlt(
					hdc_memBuffer,
					npcs[i]->x - 0.5 * HUMAN_SIZE_X, npcs[i]->y - 0.5 * HUMAN_SIZE_Y,			// 界面上起始绘制点
					HUMAN_SIZE_X, HUMAN_SIZE_Y,											// 界面上绘制宽度高度
					hdc_loadBmp,
					HUMAN_BITMAP_SIZE_X * npcs[i]->frame_column, HUMAN_BITMAP_SIZE_Y * npcs[i]->frame_row,	// 位图上起始绘制点
					HUMAN_BITMAP_SIZE_X, HUMAN_BITMAP_SIZE_Y,											// 位图上绘制宽度高度
					RGB(255, 255, 255)
				);
			}
		}
		//绘制怪物
		for (int i = 0; i < monsters.size(); i++) {
			if (monsters[i]->visible) {
				SelectObject(hdc_loadBmp, monsters[i]->img);
				TransparentBlt(
					hdc_memBuffer,
					monsters[i]->x - 0.5 * MOSTER_SIZE_X, monsters[i]->y - 0.5 * MOSTER_SIZE_Y,		// 界面上起始绘制点
					MOSTER_SIZE_X, MOSTER_SIZE_Y,											// 界面上绘制宽度高度
					hdc_loadBmp,
					MOSTER_BITMAP_SIZE_X * monsters[i]->frame_column, MOSTER_BITMAP_SIZE_Y * monsters[i]->frame_row,	// 位图上起始绘制点
					MOSTER_BITMAP_SIZE_X, MOSTER_BITMAP_SIZE_Y,											// 位图上绘制宽度高度
					RGB(255, 255, 255)
				);
			}
		}
		
		
		//绘制AI怪物
		for (int i = 0; i < aimonsters.size(); i++) {
			if (aimonsters[i]->visible) {
				SelectObject(hdc_loadBmp, aimonsters[i]->img);
				TransparentBlt(
					hdc_memBuffer,
					aimonsters[i]->x - 0.5 * MOSTER_SIZE_X, aimonsters[i]->y - 0.5 * AIMOSTER_SIZE_Y,		// 界面上起始绘制点
					AIMOSTER_SIZE_X, AIMOSTER_SIZE_Y,											// 界面上绘制宽度高度
					hdc_loadBmp,
					AIMOSTER_BITMAP_SIZE_X * aimonsters[i]->frame_column, AIMOSTER_BITMAP_SIZE_Y * aimonsters[i]->frame_row,	// 位图上起始绘制点
					AIMOSTER_BITMAP_SIZE_X, AIMOSTER_BITMAP_SIZE_Y,											// 位图上绘制宽度高度
					RGB(255, 255, 255)
				);
			}
			if (aimonsters[i]->attack2 == NULL)continue;
			if (aimonsters[i]->attack2->visible) {
				SelectObject(hdc_loadBmp, aimonsters[i]->attack2->img);
				TransparentBlt(
					hdc_memBuffer,
					aimonsters[i]->attack2->x - 0.5 * ATTACK_SIZE_X, aimonsters[i]->attack2->y - 0.5 * ATTACK_SIZE_Y,		// 界面上起始绘制点
					ATTACK_SIZE_X, ATTACK_SIZE_Y,											// 界面上绘制宽度高度
					hdc_loadBmp,
					ATTACK_BITMAP_SIZE_X * aimonsters[i]->attack2->frame_column, ATTACK_BITMAP_SIZE_Y * aimonsters[i]->attack2->frame_row,	// 位图上起始绘制点
					ATTACK_BITMAP_SIZE_X, ATTACK_BITMAP_SIZE_Y,												// 位图上绘制宽度高度
					RGB(255, 255, 255)
				);
			}
		}
		if (attack->visible) {
			SelectObject(hdc_loadBmp, attack->img);
			TransparentBlt(
				hdc_memBuffer,
				attack->x - 0.5 * ATTACK_SIZE_X, attack->y - 0.5 * ATTACK_SIZE_Y,		// 界面上起始绘制点
				ATTACK_SIZE_X, ATTACK_SIZE_Y,											// 界面上绘制宽度高度
				hdc_loadBmp,
				ATTACK_BITMAP_SIZE_X * attack->frame_column, ATTACK_BITMAP_SIZE_Y * attack->frame_row,	// 位图上起始绘制点
				ATTACK_BITMAP_SIZE_X, ATTACK_BITMAP_SIZE_Y,												// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		//如果正处在对话状态：绘制对话框
		if (in_conversation) {
			SelectObject(hdc_loadBmp, bmp_dialog);
			TransparentBlt(
				hdc_memBuffer,
				0, WINDOW_HEIGHT - DIALOG_SIZE_Y - 38, WINDOW_WIDTH - 16, DIALOG_SIZE_Y,					// 界面上绘制位置
				hdc_loadBmp,
				0, 0, DIALOG_BITMAP_SIZE_X, DIALOG_BITMAP_SIZE_Y,	// 位图上绘制位置
				RGB(255, 255, 255)
			);
			//绘制文字
			HFONT hFont = CreateFontW(
				20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
				OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
				L"SimSun");		//创建字体
			SelectObject(hdc_memBuffer, hFont);
			SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
			SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
			RECT rect;
			rect.left = 50;
			rect.top = WINDOW_HEIGHT - DIALOG_SIZE_Y - 18;
			rect.right = WINDOW_WIDTH - 110;
			rect.bottom = WINDOW_HEIGHT - 50;
			DrawTextW(hdc_memBuffer, converstaion_content, -1, &rect, DT_WORDBREAK);

			HFONT hFont0 = CreateFontW(
				20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
				OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
				L"SimSun");		//创建字体
			SelectObject(hdc_memBuffer, hFont0);
			SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
			SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
			RECT rect0;
			rect0.left = 500;
			rect0.top = WINDOW_HEIGHT - DIALOG_SIZE_Y - 18 + 64;
			rect0.right = WINDOW_WIDTH - 10;
			rect0.bottom = WINDOW_HEIGHT - 50;
			DrawTextW(hdc_memBuffer, L"（按下空格继续对话或关闭对话栏）", -1, &rect0, DT_WORDBREAK);
			DeleteObject(hFont);
			DeleteObject(hFont0);

		}
		if (yinxiao) {
			SelectObject(hdc_loadBmp, bmp_dialog);
			TransparentBlt(
				hdc_memBuffer,
				0, WINDOW_HEIGHT - DIALOG_SIZE_Y - 38, WINDOW_WIDTH - 16, DIALOG_SIZE_Y,					// 界面上绘制位置
				hdc_loadBmp,
				0, 0, DIALOG_BITMAP_SIZE_X, DIALOG_BITMAP_SIZE_Y,	// 位图上绘制位置
				RGB(255, 255, 255)
			);
			//绘制文字
			HFONT hFont = CreateFontW(
				20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
				OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
				L"SimSun");		//创建字体
			SelectObject(hdc_memBuffer, hFont);
			SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
			SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
			RECT rect;
			rect.left = 50;
			rect.top = WINDOW_HEIGHT - DIALOG_SIZE_Y - 18;
			rect.right = WINDOW_WIDTH - 110;
			rect.bottom = WINDOW_HEIGHT - 50;
			DrawTextW(hdc_memBuffer, L"前面的区域以后再来探索吧~", -1, &rect, DT_WORDBREAK);

			HFONT hFont0 = CreateFontW(
				20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
				OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
				L"SimSun");		//创建字体
			SelectObject(hdc_memBuffer, hFont0);
			SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
			SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
			RECT rect0;
			rect0.left = 500;
			rect0.top = WINDOW_HEIGHT - DIALOG_SIZE_Y - 18+64;
			rect0.right = WINDOW_WIDTH - 10;
			rect0.bottom = WINDOW_HEIGHT - 50;
			DrawTextW(hdc_memBuffer, L"（按下空格继续对话或关闭对话栏）", -1, &rect0, DT_WORDBREAK);
			DeleteObject(hFont);
			DeleteObject(hFont0);
			
		}
		if (jinwu) {
			SelectObject(hdc_loadBmp, bmp_dialog);
			TransparentBlt(
				hdc_memBuffer,
				0, WINDOW_HEIGHT - DIALOG_SIZE_Y - 38, WINDOW_WIDTH - 16, DIALOG_SIZE_Y,					// 界面上绘制位置
				hdc_loadBmp,
				0, 0, DIALOG_BITMAP_SIZE_X, DIALOG_BITMAP_SIZE_Y,	// 位图上绘制位置
				RGB(255, 255, 255)
			);
			//绘制文字
			HFONT hFont = CreateFontW(
				20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
				OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
				L"SimSun");		//创建字体
			SelectObject(hdc_memBuffer, hFont);
			SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
			SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
			RECT rect;
			rect.left = 50;
			rect.top = WINDOW_HEIGHT - DIALOG_SIZE_Y - 18;
			rect.right = WINDOW_WIDTH - 110;
			rect.bottom = WINDOW_HEIGHT - 50;
			DrawTextW(hdc_memBuffer, L"呜呜呜呜呜呜呜呜呜呜呜~\n楼上好像传来了哭声\n去看看吧", -1, &rect, DT_WORDBREAK);

			HFONT hFont0 = CreateFontW(
				20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
				OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
				L"SimSun");		//创建字体
			SelectObject(hdc_memBuffer, hFont0);
			SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
			SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
			RECT rect0;
			rect0.left = 500;
			rect0.top = WINDOW_HEIGHT - DIALOG_SIZE_Y - 18 + 64;
			rect0.right = WINDOW_WIDTH - 10;
			rect0.bottom = WINDOW_HEIGHT - 50;
			DrawTextW(hdc_memBuffer, L"（按下空格继续对话或关闭对话栏）", -1, &rect0, DT_WORDBREAK);

			DeleteObject(hFont);
			DeleteObject(hFont0);
		}
		
		if (migong_) {
			SelectObject(hdc_loadBmp, bmp_dialog);
			TransparentBlt(
				hdc_memBuffer,
				0, WINDOW_HEIGHT - DIALOG_SIZE_Y - 38, WINDOW_WIDTH - 16, DIALOG_SIZE_Y,					// 界面上绘制位置
				hdc_loadBmp,
				0, 0, DIALOG_BITMAP_SIZE_X, DIALOG_BITMAP_SIZE_Y,	// 位图上绘制位置
				RGB(255, 255, 255)
			);
			//绘制文字
			HFONT hFont = CreateFontW(
				20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
				OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
				L"SimSun");		//创建字体
			SelectObject(hdc_memBuffer, hFont);
			SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
			SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
			RECT rect;
			rect.left = 50;
			rect.top = WINDOW_HEIGHT - DIALOG_SIZE_Y - 18;
			rect.right = WINDOW_WIDTH - 110;
			rect.bottom = WINDOW_HEIGHT - 50;
			switch (migong) {
			case 1:
				DrawTextW(hdc_memBuffer, L"这么一大片森林，它到底跑哪里去了呢", -1, &rect, DT_WORDBREAK);
				break;
			case 2:
				DrawTextW(hdc_memBuffer, L"奇怪？", -1, &rect, DT_WORDBREAK);
				break;
			case 3:
				DrawTextW(hdc_memBuffer, L"奇怪？？", -1, &rect, DT_WORDBREAK);
				break;
			case 4:
				DrawTextW(hdc_memBuffer, L"奇怪？？？", -1, &rect, DT_WORDBREAK);
				break;
			case 5:
				DrawTextW(hdc_memBuffer, L"奇怪？？？？", -1, &rect, DT_WORDBREAK);
				break;
			case 6:
				DrawTextW(hdc_memBuffer, L"奇怪？？？？？", -1, &rect, DT_WORDBREAK);
				break;
			case 7:
				DrawTextW(hdc_memBuffer, L"终于走出这破鬼打墙的地方了", -1, &rect, DT_WORDBREAK);
				InitStage(hWnd, STAGE_14);
				break;
			default:
				break;
			}
			

			HFONT hFont0 = CreateFontW(
				20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
				OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
				L"SimSun");		//创建字体
			SelectObject(hdc_memBuffer, hFont0);
			SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
			SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
			RECT rect0;
			rect0.left = 500;
			rect0.top = WINDOW_HEIGHT - DIALOG_SIZE_Y - 18 + 64;
			rect0.right = WINDOW_WIDTH - 10;
			rect0.bottom = WINDOW_HEIGHT - 50;
			DrawTextW(hdc_memBuffer, L"（按下空格继续对话或关闭对话栏）", -1, &rect0, DT_WORDBREAK);

			DeleteObject(hFont);
			DeleteObject(hFont0);
		}
		if (aaaa) {
			SelectObject(hdc_loadBmp, bmp_dialog);
			TransparentBlt(
				hdc_memBuffer,
				0, WINDOW_HEIGHT - DIALOG_SIZE_Y - 38, WINDOW_WIDTH - 16, DIALOG_SIZE_Y,					// 界面上绘制位置
				hdc_loadBmp,
				0, 0, DIALOG_BITMAP_SIZE_X, DIALOG_BITMAP_SIZE_Y,	// 位图上绘制位置
				RGB(255, 255, 255)
			);
			//绘制文字
			HFONT hFont = CreateFontW(
				20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
				OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
				L"SimSun");		//创建字体
			SelectObject(hdc_memBuffer, hFont);
			SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
			SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
			RECT rect;
			rect.left = 50;
			rect.top = WINDOW_HEIGHT - DIALOG_SIZE_Y - 18;
			rect.right = WINDOW_WIDTH - 110;
			rect.bottom = WINDOW_HEIGHT - 50;
		
				DrawTextW(hdc_memBuffer, L"???????????", -1, &rect, DT_WORDBREAK);
			
			


			HFONT hFont0 = CreateFontW(
				20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
				OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
				L"SimSun");		//创建字体
			SelectObject(hdc_memBuffer, hFont0);
			SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
			SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
			RECT rect0;
			rect0.left = 500;
			rect0.top = WINDOW_HEIGHT - DIALOG_SIZE_Y - 18 + 64;
			rect0.right = WINDOW_WIDTH - 10;
			rect0.bottom = WINDOW_HEIGHT - 50;
			DrawTextW(hdc_memBuffer, L"（按下空格继续对话或关闭对话栏）", -1, &rect0, DT_WORDBREAK);

			DeleteObject(hFont);
			DeleteObject(hFont0);
		}
	}

	// 绘制按钮到缓存
	for (int i = 0; i < buttons.size(); i++)
	{
		Button* button = buttons[i];
		if (button->visible)
		{
			SelectObject(hdc_loadBmp, button->img);
			TransparentBlt(
				hdc_memBuffer, button->x, button->y,
				button->width, button->height,
				hdc_loadBmp, 0, 0, button->width, button->height,
				RGB(255, 255, 255)
			);
		}
	}
	if (jieju) {
		SelectObject(hdc_loadBmp, bmp_dialog);
		TransparentBlt(
			hdc_memBuffer,
			0, WINDOW_HEIGHT - DIALOG_SIZE_Y - 38, WINDOW_WIDTH - 16, DIALOG_SIZE_Y,					// 界面上绘制位置
			hdc_loadBmp,
			0, 0, DIALOG_BITMAP_SIZE_X, DIALOG_BITMAP_SIZE_Y,	// 位图上绘制位置
			RGB(255, 255, 255)
		);
		//绘制文字
		HFONT hFont = CreateFontW(
			20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
			L"SimSun");		//创建字体
		SelectObject(hdc_memBuffer, hFont);
		SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
		SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
		RECT rect;
		rect.left = 50;
		rect.top = WINDOW_HEIGHT - DIALOG_SIZE_Y - 18;
		rect.right = WINDOW_WIDTH - 110;
		rect.bottom = WINDOW_HEIGHT - 50;
		if (jieju == 1)DrawTextW(hdc_memBuffer, L"当我还想着把打败怪物的消息去告诉镇长时", -1, &rect, DT_WORDBREAK);
		else if (jieju == 2)DrawTextW(hdc_memBuffer, L"我的眼前突然变得模糊....", -1, &rect, DT_WORDBREAK);
		else if (jieju == 3)DrawTextW(hdc_memBuffer, L"又逐渐变得熟悉", -1, &rect, DT_WORDBREAK);
		else if (jieju == 4)DrawTextW(hdc_memBuffer, L"我又回到了自己朝夕相处的书桌前", -1, &rect, DT_WORDBREAK);
		else if (jieju == 5)DrawTextW(hdc_memBuffer, L"刚刚的一切就仿佛一场幻梦", -1, &rect, DT_WORDBREAK);
		else if (jieju == 6)DrawTextW(hdc_memBuffer, L"什么镇长、孩童、怪物.....", -1, &rect, DT_WORDBREAK);
		else if (jieju == 7)DrawTextW(hdc_memBuffer, L"如今,一切都好像一个玩笑，如尘烟般散去了", -1, &rect, DT_WORDBREAK);
		else if (jieju == 8)DrawTextW(hdc_memBuffer, L"我又要回到既定的生活轨迹了", -1, &rect, DT_WORDBREAK);
		else if (jieju == 9)DrawTextW(hdc_memBuffer, L"日复一日地劳作，陷在DDL的怪圈中", -1, &rect, DT_WORDBREAK);
		else if (jieju == 10)DrawTextW(hdc_memBuffer, L"我们常常标榜自己勇于上进", -1, &rect, DT_WORDBREAK);
		else if (jieju == 11)DrawTextW(hdc_memBuffer, L"为了成就、成绩、名誉、荣誉，牺牲了一切向着所谓的方向前进", -1, &rect, DT_WORDBREAK);
		else if (jieju == 12)DrawTextW(hdc_memBuffer, L"就算在一场幻梦中，也放不下对“三好学生”的执念", -1, &rect, DT_WORDBREAK);
		else if (jieju == 13)DrawTextW(hdc_memBuffer, L"可难道世间万物均有标准？", -1, &rect, DT_WORDBREAK);
		else if (jieju == 14)DrawTextW(hdc_memBuffer, L"一切就有一个圆满的结局？", -1, &rect, DT_WORDBREAK);
		else if (jieju == 15)DrawTextW(hdc_memBuffer, L"自己总能成为那个头号玩家吗？", -1, &rect, DT_WORDBREAK);
		else if (jieju == 16)DrawTextW(hdc_memBuffer, L"曾经的我没有答案", -1, &rect, DT_WORDBREAK);
		else if (jieju == 17)DrawTextW(hdc_memBuffer, L"可在这一场梦后", -1, &rect, DT_WORDBREAK);
		else if (jieju == 18)DrawTextW(hdc_memBuffer, L"我想", -1, &rect, DT_WORDBREAK);
		else if (jieju == 19)DrawTextW(hdc_memBuffer, L"解开一个个小谜题、为孩子找回它的猫咪，为村子赶走怪物", -1, &rect, DT_WORDBREAK);
		else if (jieju == 20)DrawTextW(hdc_memBuffer, L"这些又怎是冷冰冰的成绩、荣誉", -1, &rect, DT_WORDBREAK);
		else if (jieju == 21)DrawTextW(hdc_memBuffer, L"所谓的“三好学生”，并不在于有多么优秀", -1, &rect, DT_WORDBREAK);
		else if (jieju == 22)DrawTextW(hdc_memBuffer, L"而是心中总怀着希望、善良与正义", -1, &rect, DT_WORDBREAK);
		else if (jieju == 23)DrawTextW(hdc_memBuffer, L"故事的结局并不唯一", -1, &rect, DT_WORDBREAK);
		else if (jieju == 24)DrawTextW(hdc_memBuffer, L"人生亦是如此", -1, &rect, DT_WORDBREAK);
		else if (jieju == 25)DrawTextW(hdc_memBuffer, L"我们没必要为了所谓的正确的路而朝思暮想", -1, &rect, DT_WORDBREAK);
		else if (jieju == 26)DrawTextW(hdc_memBuffer, L"也不必成为那个你应该成为的人", -1, &rect, DT_WORDBREAK);
		else if (jieju == 27)DrawTextW(hdc_memBuffer, L"循着心中的轨迹", -1, &rect, DT_WORDBREAK);
		else if (jieju == 28)DrawTextW(hdc_memBuffer, L"做自己想做的事", -1, &rect, DT_WORDBREAK);
		else if (jieju == 29)DrawTextW(hdc_memBuffer, L"成为自己的“三好学生”", -1, &rect, DT_WORDBREAK);
		else if (jieju == 30)DrawTextW(hdc_memBuffer, L"这就足够了", -1, &rect, DT_WORDBREAK);
		else if (jieju == 31)DrawTextW(hdc_memBuffer, L"语尽于此", -1, &rect, DT_WORDBREAK);
		else if (jieju == 32)DrawTextW(hdc_memBuffer, L"我想各位也有了自己的答案", -1, &rect, DT_WORDBREAK);
		else if (jieju == 33)DrawTextW(hdc_memBuffer, L"你我本为陌路人", -1, &rect, DT_WORDBREAK);
		else if (jieju == 34)DrawTextW(hdc_memBuffer, L"因此游戏而相聚", -1, &rect, DT_WORDBREAK);
		else if (jieju == 35)DrawTextW(hdc_memBuffer, L"但不必停留", -1, &rect, DT_WORDBREAK);
		else if (jieju == 36)DrawTextW(hdc_memBuffer, L"前路漫漫", -1, &rect, DT_WORDBREAK);
		else if (jieju == 37)DrawTextW(hdc_memBuffer, L"祝诸君", -1, &rect, DT_WORDBREAK);
		else if (jieju == 38)DrawTextW(hdc_memBuffer, L"且行且歌，抵于心之彼岸", -1, &rect, DT_WORDBREAK);
		else if (jieju == 39)DrawTextW(hdc_memBuffer, L"......", -1, &rect, DT_WORDBREAK);
		else if (jieju == 40)DrawTextW(hdc_memBuffer, L"画外音：（顺祝各位程设全部4.0！！！！！）", -1, &rect, DT_WORDBREAK);






		HFONT hFont0 = CreateFontW(
			20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
			L"SimSun");		//创建字体
		SelectObject(hdc_memBuffer, hFont0);
		SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
		SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
		RECT rect0;
		rect0.left = 500;
		rect0.top = WINDOW_HEIGHT - DIALOG_SIZE_Y - 18 + 64;
		rect0.right = WINDOW_WIDTH - 10;
		rect0.bottom = WINDOW_HEIGHT - 50;
		DrawTextW(hdc_memBuffer, L"（按下空格继续对话或关闭对话栏）", -1, &rect0, DT_WORDBREAK);

		DeleteObject(hFont);
		DeleteObject(hFont0);
	}
	//绘制任务
	if (istask) {
		for (int i = 0; i < tasks.size(); i++) {
			if (tasks[i]->visible&& !tasks[i]->finish) {

				HFONT hFont = CreateFontW(
					25, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
					OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
					L"SimSun");		//创建字体
				SelectObject(hdc_memBuffer, hFont);
				SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
				SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
				SetBkMode(hdc_memBuffer, TRANSPARENT);
				RECT rect;
				rect.left = 170;
				rect.top = 210;
				rect.right = WINDOW_WIDTH - 110;
				rect.bottom = WINDOW_HEIGHT - 50;
				DrawTextW(hdc_memBuffer, tasks[i]->statement, -1, &rect, DT_WORDBREAK);
				
				HFONT hFont11 = CreateFontW(
					24, 13, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
					OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
					L"SimSun");		//创建字体
				SelectObject(hdc_memBuffer, hFont);
				SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
				SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
				SetBkMode(hdc_memBuffer, TRANSPARENT);
				RECT rect11;
				rect.left = 700;
				rect.top = 215;
				rect.right = 800;
				rect.bottom = 240;
				TCHAR buffer[256];
				wsprintf(buffer, L"%d / %d", tasks[i]->value,tasks[i]->limit);
				DrawTextW(hdc_memBuffer,buffer, -1, &rect, DT_WORDBREAK);

				RECT rect1;
				rect.left = 642;//54
				rect.top = 248;
				rect.right = 642 + (825-642)*((float)tasks[i]->value/tasks[i]->limit);//188
				rect.bottom = 273;//12
				FillRect(hdc_memBuffer, &rect, hBrush1);
				if (false) {
					RECT rect2;
					rect2.left = 642;//54
					rect2.top = 390;
					rect2.right = 825;//(player->exp / (float)player->explimit);//188
					rect2.bottom = 415;//12
					FillRect(hdc_memBuffer, &rect2, hBrush1);

					RECT rect3;
					rect2.left = 642;//54
					rect2.top = 546;
					rect2.right = 825;//(player->exp / (float)player->explimit);//188
					rect2.bottom = 571;//12
					FillRect(hdc_memBuffer, &rect2, hBrush1);


				}
				DeleteObject(hFont);
				DeleteObject(hFont11);
			}


		}
	}
	//绘制prop
	if (isprop) {
		for (int i = 0; i < 1; i++) {
			if (props[i]->visible ) {

				HFONT hFont = CreateFontW(
					25, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
					OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
					L"SimSun");		//创建字体
				SelectObject(hdc_memBuffer, hFont);
				SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
				SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
				SetBkMode(hdc_memBuffer, TRANSPARENT);
				RECT rect;
				rect.left = 170;
				rect.top = 145;
				rect.right = WINDOW_WIDTH - 110;
				rect.bottom = WINDOW_HEIGHT - 50;
				DrawTextW(hdc_memBuffer, props[i]->name, -1, &rect, DT_WORDBREAK);

				HFONT hFont2 = CreateFontW(
					20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
					OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
					L"SimSun");		//创建字体
				SelectObject(hdc_memBuffer, hFont2);
				SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
				SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
				SetBkMode(hdc_memBuffer, TRANSPARENT);
				RECT rect2;
				rect2.left = 445;
				rect2.top = 145;
				rect2.right = WINDOW_WIDTH - 110;
				rect2.bottom = WINDOW_HEIGHT - 50;
				DrawTextW(hdc_memBuffer, props[i]->statement, -1, &rect2, DT_WORDBREAK);

				HFONT hFont11 = CreateFontW(
					24, 13, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
					OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
					L"SimSun");		//创建字体
				SelectObject(hdc_memBuffer, hFont);
				SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
				SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
				SetBkMode(hdc_memBuffer, TRANSPARENT);
				RECT rect11;
				rect.left = 735;
				rect.top = 145;
				rect.right = 800;
				rect.bottom = 240;
				TCHAR buffer[256];
				wsprintf(buffer, L"×%d", props[i]->num);
				DrawTextW(hdc_memBuffer, buffer, -1, &rect, DT_WORDBREAK);

				HDC hdcMem = CreateCompatibleDC(hdc_memBuffer); // 创建一个与hdc_memBuffer兼容的内存设备上下文
				HBITMAP hOldBitmap = (HBITMAP)SelectObject(hdcMem, props[i]->img); // 将hBitmap选入hdcMem

				// 定义要绘制图片的位置和大小
				int x = 373; // 目标位置的x坐标
				int y = 123; // 目标位置的y坐标
				int nWidth = 60; // 图片的宽度，如果设置为0，则使用图片的实际宽度
				int nHeight = 60; // 图片的高度，如果设置为0，则使用图片的实际高度

				// 使用BitBlt函数将图片绘制到hdc_memBuffer中
				BitBlt(hdc_memBuffer, x, y, nWidth, nHeight, hdcMem, 0, 0, SRCCOPY);

				// 清理资源
				SelectObject(hdcMem, hOldBitmap); // 将原来的HBITMAP选回hdcMem
				DeleteDC(hdcMem); // 删除内存设备上下文
				DeleteObject(hFont);
				DeleteObject(hFont11);
				DeleteObject(hFont2);
				
			}


		}
		for (int i = 1; i < 2; i++) {
			if (props[i]->visible) {

				HFONT hFont = CreateFontW(
					25, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
					OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
					L"SimSun");		//创建字体
				SelectObject(hdc_memBuffer, hFont);
				SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
				SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
				SetBkMode(hdc_memBuffer, TRANSPARENT);
				RECT rect;
				rect.left = 170;
				rect.top = 145;
				rect.right = WINDOW_WIDTH - 110;
				rect.bottom = WINDOW_HEIGHT - 50;
				DrawTextW(hdc_memBuffer, props[i]->name, -1, &rect, DT_WORDBREAK);

				HFONT hFont2 = CreateFontW(
					20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
					OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
					L"SimSun");		//创建字体
				SelectObject(hdc_memBuffer, hFont2);
				SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
				SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
				SetBkMode(hdc_memBuffer, TRANSPARENT);
				RECT rect2;
				rect2.left = 445;
				rect2.top = 120;
				rect2.right = WINDOW_WIDTH - 170;
				rect2.bottom = WINDOW_HEIGHT - 50;
				DrawTextW(hdc_memBuffer, props[i]->statement, -1, &rect2, DT_WORDBREAK);

				HFONT hFont11 = CreateFontW(
					24, 13, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
					OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
					L"SimSun");		//创建字体
				SelectObject(hdc_memBuffer, hFont);
				SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
				SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
				SetBkMode(hdc_memBuffer, TRANSPARENT);
				RECT rect11;
				rect.left = 735;
				rect.top = 145;
				rect.right = 800;
				rect.bottom = 240;
				TCHAR buffer[256];
				wsprintf(buffer, L"×%d", props[i]->num);
				DrawTextW(hdc_memBuffer, buffer, -1, &rect, DT_WORDBREAK);

				HDC hdcMem = CreateCompatibleDC(hdc_memBuffer); // 创建一个与hdc_memBuffer兼容的内存设备上下文
				HBITMAP hOldBitmap = (HBITMAP)SelectObject(hdcMem, props[i]->img); // 将hBitmap选入hdcMem

				// 定义要绘制图片的位置和大小
				int x = 373; // 目标位置的x坐标
				int y = 123; // 目标位置的y坐标
				int nWidth = 60; // 图片的宽度，如果设置为0，则使用图片的实际宽度
				int nHeight = 60; // 图片的高度，如果设置为0，则使用图片的实际高度

				// 使用BitBlt函数将图片绘制到hdc_memBuffer中
				BitBlt(hdc_memBuffer, x, y, nWidth, nHeight, hdcMem, 0, 0, SRCCOPY);

				// 清理资源
				SelectObject(hdcMem, hOldBitmap); // 将原来的HBITMAP选回hdcMem
				DeleteDC(hdcMem); // 删除内存设备上下文
				DeleteObject(hFont);
				DeleteObject(hFont11);
				DeleteObject(hFont2);
			}


		}
			if (props[2]->visible) {

				HFONT hFont = CreateFontW(
					25, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
					OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
					L"SimSun");		//创建字体
				SelectObject(hdc_memBuffer, hFont);
				SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
				SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
				SetBkMode(hdc_memBuffer, TRANSPARENT);
				RECT rect;
				rect.left = 170;
				rect.top = 210;
				rect.right = WINDOW_WIDTH - 110;
				rect.bottom = WINDOW_HEIGHT - 50;
				DrawTextW(hdc_memBuffer, props[2]->name, -1, &rect, DT_WORDBREAK);

				HFONT hFont2 = CreateFontW(
					20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
					OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
					L"SimSun");		//创建字体
				SelectObject(hdc_memBuffer, hFont2);
				SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
				SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
				SetBkMode(hdc_memBuffer, TRANSPARENT);
				RECT rect2;
				rect2.left = 445;
				rect2.top = 190;
				rect2.right = WINDOW_WIDTH - 170;
				rect2.bottom = WINDOW_HEIGHT - 50;
				DrawTextW(hdc_memBuffer, props[2]->statement, -1, &rect2, DT_WORDBREAK);

				HFONT hFont11 = CreateFontW(
					24, 13, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
					OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
					L"SimSun");		//创建字体
				SelectObject(hdc_memBuffer, hFont);
				SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
				SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
				SetBkMode(hdc_memBuffer, TRANSPARENT);
				RECT rect11;
				rect.left = 735;
				rect.top = 208;
				rect.right = 800;
				rect.bottom = 240;
				TCHAR buffer[256];
				wsprintf(buffer, L"×%d", props[2]->num);
				DrawTextW(hdc_memBuffer, buffer, -1, &rect, DT_WORDBREAK);

				HDC hdcMem = CreateCompatibleDC(hdc_memBuffer); // 创建一个与hdc_memBuffer兼容的内存设备上下文
				HBITMAP hOldBitmap = (HBITMAP)SelectObject(hdcMem, props[2]->img); // 将hBitmap选入hdcMem

				// 定义要绘制图片的位置和大小
				int x = 373; // 目标位置的x坐标
				int y = 190; // 目标位置的y坐标
				int nWidth = 60; // 图片的宽度，如果设置为0，则使用图片的实际宽度
				int nHeight = 60; // 图片的高度，如果设置为0，则使用图片的实际高度

				// 使用BitBlt函数将图片绘制到hdc_memBuffer中
				BitBlt(hdc_memBuffer, x, y, nWidth, nHeight, hdcMem, 0, 0, SRCCOPY);

				// 清理资源
				SelectObject(hdcMem, hOldBitmap); // 将原来的HBITMAP选回hdcMem
				DeleteDC(hdcMem); // 删除内存设备上下文
				DeleteObject(hFont);
				DeleteObject(hFont11);
				DeleteObject(hFont2);
			


		}
			
				if (props[3]->visible) {

					HFONT hFont = CreateFontW(
						25, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
						OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
						L"SimSun");		//创建字体
					SelectObject(hdc_memBuffer, hFont);
					SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
					SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
					SetBkMode(hdc_memBuffer, TRANSPARENT);
					RECT rect;
					rect.left = 170;
					rect.top = 280;
					rect.right = WINDOW_WIDTH - 110;
					rect.bottom = WINDOW_HEIGHT - 50;
					DrawTextW(hdc_memBuffer, props[3]->name, -1, &rect, DT_WORDBREAK);

					HFONT hFont2 = CreateFontW(
						20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
						OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
						L"SimSun");		//创建字体
					SelectObject(hdc_memBuffer, hFont2);
					SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
					SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
					SetBkMode(hdc_memBuffer, TRANSPARENT);
					RECT rect2;
					rect2.left = 445;
					rect2.top = 265;
					rect2.right = WINDOW_WIDTH - 170;
					rect2.bottom = WINDOW_HEIGHT - 50;
					DrawTextW(hdc_memBuffer, props[3]->statement, -1, &rect2, DT_WORDBREAK);

					HFONT hFont11 = CreateFontW(
						24, 13, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
						OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
						L"SimSun");		//创建字体
					SelectObject(hdc_memBuffer, hFont);
					SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
					SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
					SetBkMode(hdc_memBuffer, TRANSPARENT);
					RECT rect11;
					rect.left = 735;
					rect.top = 285;
					rect.right = 800;
					rect.bottom = 240;
					TCHAR buffer[256];
					wsprintf(buffer, L"×%d", props[3]->num);
					DrawTextW(hdc_memBuffer, buffer, -1, &rect, DT_WORDBREAK);

					HDC hdcMem = CreateCompatibleDC(hdc_memBuffer); // 创建一个与hdc_memBuffer兼容的内存设备上下文
					HBITMAP hOldBitmap = (HBITMAP)SelectObject(hdcMem, props[3]->img); // 将hBitmap选入hdcMem

					// 定义要绘制图片的位置和大小
					int x = 373; // 目标位置的x坐标
					int y = 258; // 目标位置的y坐标
					int nWidth = 60; // 图片的宽度，如果设置为0，则使用图片的实际宽度
					int nHeight = 60; // 图片的高度，如果设置为0，则使用图片的实际高度

					// 使用BitBlt函数将图片绘制到hdc_memBuffer中
					BitBlt(hdc_memBuffer, x, y, nWidth, nHeight, hdcMem, 0, 0, SRCCOPY);

					// 清理资源
					SelectObject(hdcMem, hOldBitmap); // 将原来的HBITMAP选回hdcMem
					DeleteDC(hdcMem); // 删除内存设备上下文
					DeleteObject(hFont);
					DeleteObject(hFont11);
					DeleteObject(hFont2);
				}


			
	}
	if (ismima) {

				HFONT hFont11 = CreateFontW(
					160, 75, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
					OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
					L"SimSun");		//创建字体
				SelectObject(hdc_memBuffer, hFont11);
				SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
				SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
				SetBkMode(hdc_memBuffer, TRANSPARENT);
				RECT rect11;
				rect11.left = 130;
				rect11.top = 270;
				rect11.right = 900;
				rect11.bottom = 800;
				TCHAR buffer[256];
				wsprintf(buffer, L"%d %d %d %d %d",mima1,mima2,mima3,mima4,mima5);
				DrawTextW(hdc_memBuffer, buffer, -1, &rect11, DT_WORDBREAK);
		
				DeleteObject(hFont11);
			
				}
			


	//绘制rank
	if (currentStage->stageID >= STAGE_1 ) {
		HFONT hFont = CreateFontW(
			24, 13, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
			L"SimSun");		//创建字体
		SelectObject(hdc_memBuffer, hFont);
		SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
		SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
		SetBkMode(hdc_memBuffer, TRANSPARENT);
		RECT rect;
		rect.left = 50;
		rect.top = 13;
		rect.right = 300;
		rect.bottom = 200;
		TCHAR buffer[256];
		wsprintf(buffer, L"%d", player->rank);
		DrawTextW(hdc_memBuffer, buffer, -1, &rect, DT_WORDBREAK);
		DeleteObject(hFont);
		
	}
	//绘制attack
	if (currentStage->stageID >= STAGE_1 ) {
		HFONT hFont = CreateFontW(
			24, 13, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
			L"SimSun");		//创建字体
		SelectObject(hdc_memBuffer, hFont);
		SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
		SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
		SetBkMode(hdc_memBuffer, TRANSPARENT);
		RECT rect;
		rect.left = 110;
		rect.top = 13;
		rect.right = 300;
		rect.bottom = 200;
		TCHAR buffer[256];
		wsprintf(buffer, L"%d", player->attack);
		DrawTextW(hdc_memBuffer, buffer, -1, &rect, DT_WORDBREAK);
		DeleteObject(hFont);
		
	}
	//绘制defence
	if (currentStage->stageID >= STAGE_1 ) {
		HFONT hFont = CreateFontW(
			24, 13, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS,
			L"SimSun");		//创建字体
		SelectObject(hdc_memBuffer, hFont);
		SetTextColor(hdc_memBuffer, RGB(0, 0, 0));	// 设置颜色:黑色字体白色背景
		SetBkColor(hdc_memBuffer, RGB(255, 255, 255));
		SetBkMode(hdc_memBuffer, TRANSPARENT);
		RECT rect;
		rect.left = 170;
		rect.top = 13;
		rect.right = 300;
		rect.bottom = 200;
		TCHAR buffer[256];
		wsprintf(buffer, L"%d", player->defence);
		DrawTextW(hdc_memBuffer, buffer, -1, &rect, DT_WORDBREAK);
		DeleteObject(hFont);
		
	}
	if (currentStage->stageID >= STAGE_1 ) {
		 // 获取整个屏幕的设备上下文
		RECT rect;
		rect.left = 54;//54
		rect.top = 50;
		rect.right = 54+(188-54)*(player->health/(float)player->healthlimit);//188
		rect.bottom = 62;//12
		FillRect(hdc_memBuffer, &rect, hBrush);

		RECT rect2;
		rect2.left = 54;//54
		rect2.top = 74;
		rect2.right =54 + (188 - 54) * (player->exp /(float) player->explimit);//188
		rect2.bottom = 86;//12
		FillRect(hdc_memBuffer, &rect2, hBrush1);
		
	}
	// 最后将所有的信息绘制到屏幕上
	BitBlt(hdc_window, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_memBuffer, 0, 0, SRCCOPY);

	// 回收资源所占的内存（非常重要）
	
	DeleteObject(blankBmp);
	DeleteDC(hdc_memBuffer);
	DeleteDC(hdc_loadBmp);
	DeleteObject(hBrush); // 删除画刷
	DeleteObject(hBrush1); // 删除画刷



	// 结束绘制
	EndPaint(hWnd, &ps);
}
void yinxiaotansuo(int a){
	//PlaySound(L"m/3.mp3", nullptr, SND_FILENAME | SND_ASYNC );
	mciSendString(L"close m/3.mp3", NULL, 0, NULL);
	mciSendString(L"open m/3.mp3", NULL, 0, NULL);
	mciSendString(L"play m/3.mp3", NULL, 0, 0); 
		
}
void yinxiaojingyan(int a) {
	//PlaySound(L"m/3.mp3", nullptr, SND_FILENAME | SND_ASYNC );
	mciSendString(L"close m/4.mp3", NULL, 0, NULL);
	mciSendString(L"open m/4.mp3", NULL, 0, NULL);
	mciSendString(L"play m/4.mp3", NULL, 0, 0);

}
void yinxiaogongji(int a) {
	//PlaySound(L"m/3.mp3", nullptr, SND_FILENAME | SND_ASYNC );
	mciSendString(L"close m/5.mp3", NULL, 0, NULL);
	mciSendString(L"open m/5.mp3", NULL, 0, NULL);
	mciSendString(L"play m/5.mp3", NULL, 0, 0);

}
void yinxiaoshoushang(int a) {
	//PlaySound(L"m/3.mp3", nullptr, SND_FILENAME | SND_ASYNC );
	mciSendString(L"close m/6.mp3", NULL, 0, NULL);
	mciSendString(L"open m/6.mp3", NULL, 0, NULL);
	mciSendString(L"play m/6.mp3", NULL, 0, 0);

}
void yinxiaokuqi(int a) {
	//PlaySound(L"m/3.mp3", nullptr, SND_FILENAME | SND_ASYNC );
	mciSendString(L"close m/7.mp3", NULL, 0, NULL);
	mciSendString(L"open m/7.mp3", NULL, 0, NULL);
	mciSendString(L"play m/7.mp3", NULL, 0, 0);

}