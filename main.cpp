#include "RaceGame.h"
#include<time.h>
#include<string.h>
#include<stdlib.h>
	
int EdgeInput[4], Input[4] = {0,};
int gamepad, entry_flag[4], chara_select[4], keyinput_flag[4], ready_flag = 0;
int readytime;
static int game_select = 0;
Cars car[4];

//○入力で1を返す
int Entry_Flag()
{
	for(int i = 0; i < GetJoypadNum(); i++) {
		if( entry_flag[i] != 2 ) {
			return 0;
		}
	}
	return 1;
}

//乗り物を選ぶ
void Car_Select() {
	for(int i = 0; i < GetJoypadNum(); i++) {
		if(chara_select[i] == 0) Car1(i);
		if(chara_select[i] == 1) Car2(i);
		if(chara_select[i] == 2) Car3(i);
		if(chara_select[i] == 3) Car4(i);
	}
}

 
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
						 LPSTR lpCmdLine, int nCmdShow )
{
	ChangeWindowMode( TRUE ) ;
	SetGraphMode( 800, 600, 32 );
	// ＤＸライブラリ初期化処理
	if( DxLib_Init() == -1 ) return -1;		// エラーが起きたら直ちに終了
	
	//描画先画面を裏にする
	SetDrawScreen( DX_SCREEN_BACK );
	int White = GetColor(255, 255, 255);
	SetTransColor(255, 255, 255);

	init();
	Load();

	// キーが押されるまでループ
	while( ProcessMessage() == 0 && ScreenFlip() == 0)
	{
		//画面を初期化
		ClearDrawScreen();
		if( CheckHitKey( KEY_INPUT_ESCAPE ) == 1) break;

		int PadInput[4] = {GetJoypadInputState( DX_INPUT_PAD1 ), GetJoypadInputState( DX_INPUT_PAD2 ),
						GetJoypadInputState( DX_INPUT_PAD3 ), GetJoypadInputState( DX_INPUT_PAD4 )};
		
		for(int i = 0; i < GetJoypadNum(); i++) {
			EdgeInput[i] = PadInput[i] & ~Input[i];
			Input[i] = PadInput[i];
		}

		switch( game_select ) {
			case 0:			//game's opening
				DrawGraph( 0, 0, opening, false );
				DrawGraph( 400, 450, op_start, true );
				for(int i = 0; i < 4; i++) 
					if( EdgeInput[i] & PAD_INPUT_2 ) game_select = 1;
				break;

			case 1:			//player entry
				DrawGameSelect();
				for( int i = 0; i < GetJoypadNum(); i++) {
					if( EdgeInput[i] & PAD_INPUT_2 )
						entry_flag[i] = 1;
					
					if( (EdgeInput[i] & PAD_INPUT_RIGHT) && keyinput_flag[i] == 0 ) {
						chara_select[i]++;
						chara_select[i] %= 4;
					}
					if( (EdgeInput[i] & PAD_INPUT_LEFT) && keyinput_flag[i] == 0 ) {
						chara_select[i]--;
						if( chara_select[i] == -1)
							chara_select[i] = 3;
					}
					if( EdgeInput[i] & PAD_INPUT_9 ) {
						if(keyinput_flag[i] == 0) {
							keyinput_flag[i] = 1;
							entry_flag[i] = 2;
						} else {
							keyinput_flag[i] = 0;
							entry_flag[i] = 1;
						}
					}
				}
				if( Entry_Flag() == 1 )
					game_select = 2;
				break;
			
			case 2:
				Ready_Timer();
				if(ready_flag == 1) 
					if(readytime < 20 && readytime >= 0 ) DrawGraph( 5, 70, go, true);
				Car_Select();
				for( int i = 0; i < GetJoypadNum(); i++) {
					Goal(i);
					if( goalend_flag >= 1)
						game_select = 0;
				}
				break;

			case 3:
								
				break;
		}

	}

	// ＤＸライブラリ使用の終了処理
	DxLib_End() ;
	return 0 ;	
}

