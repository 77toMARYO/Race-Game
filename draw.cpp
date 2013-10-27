#include"RaceGame.h"

void DrawGameSelect()
{
	DrawFormatString( 0, 20, White, "%d", GetJoypadNum() );
	DrawFormatString( 100, 20, White, "%d", entry_flag[0]);
	DrawFormatString( 120, 20, White, "%d", entry_flag[1]);
	DrawFormatString( 160, 20, White, "%d", keyinput_flag[0]);
	if(entry_flag[0] == 1 || entry_flag[0] == 2) {
		DrawGraph( 25, 100, select_red, true);
		DrawFormatString( 0, 30, White, "%d", chara_select[0] );
	}
	if(entry_flag[1] == 1 || entry_flag[1] == 2) {
		DrawGraph( 25+390+20, 100, select_blue, true);
		DrawFormatString( 450, 30, White, "%d", chara_select[1] );
	}
	if(entry_flag[2] == 1 || entry_flag[2] == 2) {
		DrawGraph( 25, 100+250+20, select_yellow, true);
		DrawFormatString( 0, 30 + 250, White, "%d", chara_select[2] );
	}
	if(entry_flag[3] == 1 || entry_flag[3] == 2) {
		DrawGraph( 25+390+20, 100+250+20, select_green, true);
		DrawFormatString( 450, 30 + 250, White, "%d", chara_select[3] );
	}

}

void DrawCar1(int select)
{
	DrawBox(car[select].x, car[select].y, car[select].x+32-1, car[select].y+32-1, GetColor(255, 0, 0), TRUE);
	DrawFormatString( 0, car[select].y, White, "%s", KeyReturn(car1key) ); 

} 

void DrawCar2(int select)
{
	DrawBox(car[select].x, car[select].y, car[select].x+32-1, car[select].y+32-1, GetColor(255, 0, 0), TRUE);
	for(int i = 0; i < 8; i++) 
		DrawFormatString( i * 16, car[select].y, White, "%s", KeyReturn(car2key[i]) ); 
	
}


void DrawCar3(int select)
{
	DrawBox(car[select].x, car[select].y, car[select].x+32-1, car[select].y+32-1, GetColor(255, 0, 0), TRUE);
	DrawFormatString( 0, car[select].y, White, "%s", KeyReturn(car3key) );
	
}

void DrawCar4(int select)
{
	DrawBox(car[select].x, car[select].y, car[select].x+32-1, car[select].y+32-1, GetColor(255, 0, 0), TRUE);
	DrawLine(car[select].x + 32, car[select].y + 32 - 1, car[select].x + 32 + px, car[select].y + 32 - 1, GetColor( 255, 255, 255 ));
	DrawFormatString( 0, car[select].y, White, "%.1f", car[select].x );
	DrawFormatString( 48, car[select].y, White, "%.1f", px);
	DrawFormatString( 96, car[select].y, White, "%.0f", pv);
}


void Ready_Timer() {
	readytime--;
	if(readytime < 200 && readytime >= 150) DrawGraph( 240, 70, ready3, true );
	if(readytime < 140 && readytime >= 90) DrawGraph( 240, 70, ready2, true );
	if(readytime < 80 && readytime >= 30) DrawGraph( 240, 70, ready1, true );	
	if(readytime == 20) ready_flag = 1;
}