#pragma once

#pragma region 头文件引用

#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <vector>
#include <math.h>
//音乐系统
//#include<MMSystem.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include "resource.h"
#pragma comment(lib, "Msimg32.lib")			//图象处理的函数接口，例如：透明色的位图的绘制TransparentBlt函数
using namespace std;
#pragma endregion

#pragma region 宏定义

#define WINDOW_TITLEBARHEIGHT	32			//标题栏高度
#define WINDOW_WIDTH			896+16	//游戏窗口宽度
#define WINDOW_HEIGHT			640+32		//游戏窗口高度

#define STAGE_STARTMENU			0		//开始画面的ID
#define STAGE_1					11		//第一个游戏场景的ID
#define STAGE_2					12
#define STAGE_3					13
#define STAGE_4					14
#define STAGE_5				15
#define STAGE_9					19
#define STAGE_20				9
#define STAGE_6					16
#define STAGE_7					17
#define STAGE_8					18
#define STAGE_10					20
#define STAGE_11				21
#define STAGE_12				22
#define STAGE_13				23
#define STAGE_14				24
#define STAGE_HELP				3
#define STAGE_PAUSE				4
#define STAGE_GAMEOVER			5
#define STAGE_CHOOSE			6
#define STAGE_TASK				7
#define STAGE_PROP				8
#define STAGE_win				10





//尺寸
#define BG_BITMAP_WIDTH			240		//背景图片的位图宽度
#define BG_BITMAP_HEIGHT		160		//背景图片的位图高度
#define BG_COLUMNS				28		//背景列数
#define BG_ROWS					20		//背景行数
//#define BG2_BITMAP_WIDTH		480		//背景图片的位图宽度
//#define BG2_BITMAP_HEIGHT		320		//背景图片的位图高度
//#define BG2_COLUMNS				56		//背景列数
//#define BG2_ROWS				40		//背景行数
#define HUMAN_SIZE_X			38		//人物在屏幕上的宽度
#define HUMAN_SIZE_Y			52		
#define HUMAN_BITMAP_SIZE_X		19		//人物在位图上的宽度
#define HUMAN_BITMAP_SIZE_Y		26		
#define BLOCK_SIZE_X			32		//背景单格在屏幕上的宽度
#define BLOCK_SIZE_Y			32		//背景单格在屏幕上的高度
#define BLOCK_BITMAP_SIZE_X		16		//地图块在位图上的宽度
#define BLOCK_BITMAP_SIZE_Y		16
#define DIALOG_SIZE_X			896		//对话框背景
#define DIALOG_SIZE_Y			120
#define DIALOG_BITMAP_SIZE_X	250
#define DIALOG_BITMAP_SIZE_Y	44
#define MOSTER_SIZE_X			28		//怪物
#define MOSTER_SIZE_Y			30
#define MOSTER_BITMAP_SIZE_X	14
#define MOSTER_BITMAP_SIZE_Y	15
#define AIMOSTER_SIZE_X			32		//AI怪物
#define AIMOSTER_SIZE_Y			32
#define AIMOSTER_BITMAP_SIZE_X	16
#define AIMOSTER_BITMAP_SIZE_Y	16
#define BOSS_SIZE_X			128		//BOSS
#define BOSS_SIZE_Y		    128
#define BOSS_BITMAP_SIZE_X	64
#define BOSS_BITMAP_SIZE_Y	64

#define ATTACK_SIZE_X			32		//攻击特效
#define ATTACK_SIZE_Y			32
#define ATTACK_BITMAP_SIZE_X	22
#define ATTACK_BITMAP_SIZE_Y	22



//单位状态定义
#define UNIT_STATE_HOLD			0		//静止
#define UNIT_STATE_WALK			1		//行走
#define UNIT_STATE_ATTACK		2		//攻击

//单位方向定义
#define UNIT_DIRECT_RIGHT		1		//向右
#define UNIT_DIRECT_LEFT		3		//向左
#define UNIT_DIRECT_UP			2		//向上
#define UNIT_DIRECT_DOWN		0		//向下
#define UNIT_DIRECT_RIGHTUP		4		//右上
#define UNIT_DIRECT_LEFTUP		5		//左上
#define UNIT_DIRECT_RIGHTDOWN	6		//右下
#define UNIT_DIRECT_LEFTDOWN	7		//左下

//其它定义
#define BUTTON_MANU				1000	//返回游戏按钮ID
#define BUTTON_MANU_WIDTH	    196		//返回游戏按钮宽度
#define BUTTON_MANU_HEIGHT		100		//返回游戏按钮高度

#define BUTTON_STARTGAME			1001	//开始游戏按钮ID
#define BUTTON_STARTGAME_WIDTH		212		//开始游戏按钮宽度
#define BUTTON_STARTGAME_HEIGHT		76		//开始游戏按钮高度

#define BUTTON_HELP				1002	//帮助游戏按钮ID
#define BUTTON_HELP_WIDTH		212		//帮助游戏按钮宽度
#define BUTTON_HELP_HEIGHT		76		//帮助游戏按钮高度

#define BUTTON_BACK				1003	//返回游戏按钮ID
#define BUTTON_BACK_WIDTH		212		//返回游戏按钮宽度
#define BUTTON_BACK_HEIGHT		76		//返回游戏按钮高度

#define BUTTON_CONTINUE				1004	//开始游戏按钮ID
#define BUTTON_CONTINUE_WIDTH		212		//开始游戏按钮宽度
#define BUTTON_CONTINUE_HEIGHT		76		//开始游戏按钮高度

#define BUTTON_RESTART				1005	//帮助游戏按钮ID
#define BUTTON_RESTART_WIDTH		212		//帮助游戏按钮宽度
#define BUTTON_RESTART_HEIGHT		76		//帮助游戏按钮高度

#define BUTTON_BACKTOTITLE				1006	//返回游戏按钮ID
#define BUTTON_BACKTOTITLE_WIDTH		212		//返回游戏按钮宽度
#define BUTTON_BACKTOTITLE_HEIGHT		76		//返回游戏按钮高度

#define BUTTON_RESTART2				1007	//帮助游戏按钮ID
#define BUTTON_RESTART_WIDTH		212		//帮助游戏按钮宽度
#define BUTTON_RESTART_HEIGHT		76		//帮助游戏按钮高度

#define BUTTON_BACKTOTITLE2				1008	//返回游戏按钮ID
#define BUTTON_BACKTOTITLE_WIDTH		212		//返回游戏按钮宽度
#define BUTTON_BACKTOTITLE_HEIGHT		76		//返回游戏按钮高度

#define BUTTON_BACKTOTITLE3				1050	//返回游戏按钮ID
#define BUTTON_BACKTOTITLE_WIDTH		212		//返回游戏按钮宽度
#define BUTTON_BACKTOTITLE_HEIGHT		76		//返回游戏按钮高度

#define BUTTON_BOY				1009	
#define BUTTON_BOYTOTITLE_WIDTH		212		
#define BUTTON_BOYTOTITLE_HEIGHT		76		

#define BUTTON_GIRL				1010	
#define BUTTON_BOYTOTITLE_WIDTH		212		
#define BUTTON_BOYTOTITLE_HEIGHT		76		

#define BUTTON_TASK				1011	
#define BUTTON_BOYTOTITLE_WIDTH		212		
#define BUTTON_BOYTOTITLE_HEIGHT		76		

#define BUTTON_PROP				1012	
#define BUTTON_BOYTOTITLE_WIDTH		212		
#define BUTTON_BOYTOTITLE_HEIGHT		76	


#define BUTTON_NUM1				1013	
#define BUTTON_NUM2				1015
#define BUTTON_NUM3				1016	
#define BUTTON_NUM4				1017
#define BUTTON_NUM5				1018	
#define BUTTON_NUM_WIDTH		38		
#define BUTTON_NUM_HEIGHT		38	


#define BUTTON_NUM01				1014	
#define BUTTON_NUM02				1019
#define BUTTON_NUM03				1020	
#define BUTTON_NUM04				1021
#define BUTTON_NUM05				1022	
#define BUTTON_CONFIRM				1023
#define BUTTON_BACK2				1024	



#define TIMER_GAMETIMER				1		//游戏的默认计时器ID
#define TIMER_GAMETIMER_ELAPSE		30		//默认计时器刷新间隔的毫秒数
#define UNIT_SPEED					3.0		//单位行走速度

#define TIMER_GAMETIMER2				2		//游戏的默认计时器ID
#define TIMER_GAMETIMER2_ELAPSE		1000		//默认计时器刷新间隔的毫秒数

#define NPC_MAN1_ID				2001		//每个NPC的ID号
#define NPC_MAYOR_ID			2002
#define NPC_BOY_ID			2003
#define NPC_CAT_ID			2004
#define NPC_LOCK_ID			2005


#define MONSTER_CAT_ID			3001

#define AIMONSTER_SLIME_ID			4001
#define AIMONSTER_RACOON_ID			4002
#define AIMONSTER_MONSTER_ID			4003




///

#pragma endregion


#pragma region 结构体声明

// 场景结构体
struct Stage
{
	int stageID;		//场景编号
	HBITMAP bg;			//背景图片
	int timeCountDown;	//游戏时间倒计时
	bool timerOn;		//计时器是否运行（游戏是否被暂停）

};


// 按钮结构体
struct Button
{
	int buttonID;	//按钮编号
	bool visible;	//按钮是否可见
	HBITMAP img;	//图片
	int x;			//坐标x
	int y;			//坐标y
	int width;		//宽度
	int height;		//高度
};

struct task
{
	int taskID;	//按钮编号
	bool finish;	//按钮是否可见
	bool visible;
	int limit;
	int value;
	const wchar_t* statement;
};

struct prop
{
	int propID;	//按钮编号	
	bool visible;
	HBITMAP img;	//图片
	int num;
	const wchar_t* name;
	const wchar_t* statement;
};

// NPC结构体
struct NPC
{
	int npcID;				//NPC编号
	HBITMAP img;			//图片
	bool visible;			//该NPC是否可见
	bool task_complete;		//该npc的任务是否完成。决定了与npc对话时他会说什么，以及其它行为

	int frame_row;			//当前显示的是图像的第几行
	int frame_column;		//当前显示的是图像的第几列

	int* frame_sequence;	//当前的帧序列
	int frame_count;		//帧序列的长度
	int frame_id;			//当前显示的是帧序列的第几帧

	int state;		//单位状态
	int direction;	//单位方向

	int flag;
	int flag2;
	int x;			//坐标x
	int y;			//坐标y
	double vx;		//速度x
	double vy;		//速度y
	int health;		//生命值

	vector<const wchar_t*> conversations_before;	//任务完成前NPC的台词
	vector<const wchar_t*> conversations_after;		//任务完成后NPC的台词
	int next_conversation1_id;				//NPC下一次要说第几句台词1
	int next_conversation2_id;				//NPC下一次要说第几句台词2

};

// 玩家结构体
struct Player
{
	HBITMAP img;	//图片

	int frame_row;			//当前显示的是图像的第几行
	int frame_column;		//当前显示的是图像的第几列

	int* frame_sequence;	//当前的帧序列
	int frame_count;		//帧序列的长度
	int frame_id;			//当前显示的是帧序列的第几帧

	int state;		//单位状态
	int direction;	//单位方向

	int x;			//坐标x
	int y;			//坐标y
	double vx;		//速度x
	double vy;		//速度y
	int health;		//生命值
	int healthlimit;//生命值上限
	int attack;     //攻击力
	int defence;     //defence
	int rank;		//等级
	int exp;		//经验值
	int explimit;		//经验值limit
	bool alive;		//是否活着
};
// 怪物结构体
struct Monster
{
	int monsterID;			//怪物编号
	HBITMAP img;			//图片
	bool visible;			//是否可见
	bool task_complete;		//任务是否完成

	int frame_row;			//当前显示的是图像的第几行
	int frame_column;		//当前显示的是图像的第几列

	int* frame_sequence;	//当前的帧序列
	int frame_count;		//帧序列的长度
	int frame_id;			//当前显示的是帧序列的第几帧

	int state;		//单位状态
	int direction;	//单位方向

	int x;			//坐标x
	int y;			//坐标y
	double vx;		//速度x
	double vy;		//速度y
	int health;		//生命值
	bool alive;		//是否活着
	int exp;

	vector<const wchar_t*> conversations_before;	//任务完成前的台词
	vector<const wchar_t*> conversations_after;		//任务完成后的台词
	int next_conversation_id;						//下一次要说第几句台词
};
struct Attack
{
	HBITMAP img;	//图片

	int frame_row;			//当前显示的是图像的第几行
	int frame_column;		//当前显示的是图像的第几列

	int* frame_sequence;	//当前的帧序列
	int frame_count;		//帧序列的长度
	int frame_id;			//当前显示的是帧序列的第几帧
	bool visible;			//当前是否可见
	int attack;

	int x;			//坐标x
	int y;			//坐标y
};
struct AIMonster
{
	int AImonsterID;			//怪物编号
	HBITMAP img;			//图片
	bool visible;			//是否可见
	bool task_complete;		//任务是否完成

	int frame_row;			//当前显示的是图像的第几行
	int frame_column;		//当前显示的是图像的第几列

	int* frame_sequence;	//当前的帧序列
	int frame_count;		//帧序列的长度
	int frame_id;			//当前显示的是帧序列的第几帧

	int state;		//单位状态
	int direction;	//单位方向

	int x;			//坐标x
	int y;			//坐标y
	double vx;		//速度x
	double vy;		//速度y
	int health;		//生命值
	int attack;		//值
	bool alive;		//是否活着
	int exp;
	Attack* attack2;
	vector<const wchar_t*> conversations_before;	//任务完成前的台词
	vector<const wchar_t*> conversations_after;		//任务完成后的台词
	int next_conversation_id;						//下一次要说第几句台词

	float lastAttackTime = 0.0f; // 记录上次攻击的时间
	float attackInterval = 1000; // 攻击间隔时间，单位为秒

};

struct boss
{
	HBITMAP img;			//图片
	bool visible;			//是否可见
	bool task_complete;		//任务是否完成

	int frame_row;			//当前显示的是图像的第几行
	int frame_column;		//当前显示的是图像的第几列

	int* frame_sequence;	//当前的帧序列
	int frame_count;		//帧序列的长度
	int frame_id;			//当前显示的是帧序列的第几帧

	int state;		//单位状态
	

	int x;			//坐标x
	int y;			//坐标y
	int health;		//生命值
	bool alive;		//是否活着
	Attack* attack2;
	vector<const wchar_t*> conversations_before;	//任务完成前的台词
	vector<const wchar_t*> conversations_after;		//任务完成后的台词
	int next_conversation_id;						//下一次要说第几句台词

	float lastAttackTime = 0.0f; // 记录上次攻击的时间
	float attackInterval = 1000; // 攻击间隔时间，单位为秒

};



//TODO: 添加游戏需要的更多种数据（地物、砖块等）


#pragma endregion


#pragma region 事件处理函数声明


// 初始化游戏窗体函数
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 键盘按下事件处理函数
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 键盘松开事件处理函数
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 鼠标移动事件处理函数
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 鼠标左键按下事件处理函数
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 鼠标左键松开事件处理函数
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 定时器事件处理函数
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);

void TimerUpdate2(HWND hWnd, WPARAM wParam, LPARAM lParam);
#pragma endregion


#pragma region 其它游戏状态处理函数声明

// 添加按钮函数
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y);

// 添加单位函数
Player* CreatePlayer(int x, int y);
NPC* CreateNPC(int x, int y, int npc_id);
Monster* CreateMonster(int x, int y, int monster_id);
Attack* CreateAttack();
Attack* CreateAttack2();


// 初始化场景函数
void InitStage(HWND hWnd, int stageID);


//行为和交互函数：update***在定时器事件中以固定频率调用；handle***在发生键盘/鼠标事件时触发
void UpdatePlayer(HWND hWnd);
void UpdateNPCs(HWND hWnd);
void UpdateMonsters(HWND hWnd);
void UpdateMaps(HWND hWnd);
void PAUSE(HWND hWnd);
//void TASK(HWND hWnd);
void GAMEOVER(HWND hWnd);
void UpdateAIMonsters(HWND hWnd);
void UpdateAttack(HWND hWnd);
void TriggerAttack(Player* player, AIMonster* aimonster, Attack* attack2);
void Updateditu(HWND hWnd);

void HandleConversationEvents(HWND hWnd);

//TODO: 添加游戏需要的更多函数
void updateplayer(HWND hWnd);

#pragma endregion 

void updateyinxiao(HWND hWnd);

#pragma region 绘图函数声明

// 绘图函数
void Paint(HWND hWnd);

#pragma endregion

