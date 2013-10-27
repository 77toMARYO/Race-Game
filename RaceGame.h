#ifndef _RACEGAME_H_
#define _RACEGAME_H_

#include "DxLib.h"

extern void Car1(int);
extern void Car2(int);
extern void Car3(int);
extern void Car4(int);
extern void Load();
extern void Car_select();
extern void DrawGameSelect();
extern void Ready_Timer();
extern char *KeyReturn(int);
extern void KeySwitch(int,int,int);
//extern void Draw();
extern void init();
extern int Random();
extern void DrawCar1(int);
extern void DrawCar2(int);
extern void DrawCar3(int);
extern void DrawCar4(int);
extern void Goal(int);

//main
typedef struct {
	float x;
	int y;
	int image;
}Cars;
extern Cars car[4];
extern int entry_flag[4];
extern int chara_select[4];
extern int game_select;
extern int keyinput_flag[4];
extern int ready_flag;
extern int readytime;
//cars
extern int Input[4];
extern int EdgeInput[4];
extern int *count;
extern int car1key, car2key[8], car3key;
extern float px, pv;
extern int White;



//Load
extern int soitsu, WhiteBlend, ready1, ready2, ready3, go;
extern int opening, op_start, select_red, select_blue, select_yellow, select_green;
extern int carchar[4];

//Draw
extern int box;

//goalmotion
extern int goalend_flag;



#endif