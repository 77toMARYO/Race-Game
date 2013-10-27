#include"RaceGame.h"

int soitsu;
int carchar[4];
int opening, op_start, ending, WhiteBlend;
int ready3, ready2, ready1, go;
int select_red, select_blue, select_yellow, select_green;
void Load()
{
	soitsu = LoadGraph("data/image/EDGE1.bmp");
	opening = LoadGraph("data/image/opening.bmp");
	select_red = LoadGraph("data/image/select_red.png");
	select_blue = LoadGraph("data/image/select_blue.png");
	select_yellow = LoadGraph("data/image/select_yellow.png");
	select_green = LoadGraph("data/iamge/select_green.png");
	op_start = LoadGraph("data/image/op_start.png");
	WhiteBlend = LoadGraph("data/image/White.bmp");
	ready3 = LoadGraph("data/image/3.png");
	ready2 = LoadGraph("data/image/2.png");
	ready1 = LoadGraph("data/image/1.png");
	go = LoadGraph("data/image/go!.png");
	carchar[0] = LoadGraph("data/iamge/carchar0.bmp");
	carchar[1] = LoadGraph("data/iamge/carchar1.bmp");
	carchar[2] = LoadGraph("data/iamge/carchar2.bmp");
	carchar[3] = LoadGraph("data/iamge/carchar3.bmp");
}

