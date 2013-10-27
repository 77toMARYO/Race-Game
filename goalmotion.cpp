#include "RaceGame.h"

int ranking[4], goalend_flag, goalcount = 0;
static int goaltime = 50;

void Goal(int select) {
	DrawFormatString ( 0, 0, White, "%d", goalcount );
	 for(int i = 0; i < GetJoypadNum(); i++) {
		if( car[select].x >= 200 ) { 
			DrawString( car[select].x + 100, car[select].y, "goal", White );
		}
		if( goalcount == GetJoypadNum() - 1 ) {
			goaltime--;
			if( goaltime < 0) goalend_flag = 1;
		}
	}
}