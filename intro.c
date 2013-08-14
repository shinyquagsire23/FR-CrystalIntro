#define VAR     ((u8*)0x020370B8)
#define TIMER   ((long*)0x020370BC)
#define init     ((u8*)0x020370B8)

#define Tiles     ((u16*)0x6000000)
#define OBJData		((u16*)0x6010000)
#define MapData     ((u16*)0x6003800)
#define BG1Data     ((u16*)0x6008000)
#define BG2Data     ((u16*)0x600C000)
#define second 60;

#include "include/gba_keys.h"

void notMain()
{
	TIMER[0] = TIMER[0] + 1;
	faith();
	trust();
	pixieDust();
	if(init[27] == 0)
	{
		if(TIMER[0] < 10)
		{
			initDitto();
		}
		else if(TIMER[0] < 17)
		{
			moveDitto();
		}
		else if(TIMER[0] < 22)
		{
			shiftDitto(1);
			moveDitto();
		}
		else if(TIMER[0] < 23)
		{
			playSound(49);
			moveDitto();
		}
		else if(TIMER[0] < 24)
		{
			moveDitto();
		}
		else if(TIMER[0] < 28)
		{
			shiftDitto(2);
		}
		else if(TIMER[0] < 40)
		{
			shiftDitto(1);
			moveDittoUp();
		}
		else if(TIMER[0] < 39)
		{
			//shiftDitto(0);
			moveDittoUp();
		}
		else if(TIMER[0] < 40)
		{
			moveDittoUpNum(5);
		}
		else if(TIMER[0] < 41)
		{
			moveDittoUpNum(4);
		}
		else if(TIMER[0] < 42)
		{
			moveDittoUpNum(3);
		}
		else if(TIMER[0] < 44)
		{
			shiftDitto(1);
			moveDittoUpNum(2);
		}
		else if(TIMER[0] < 46)
		{
			moveDittoUpNum(1);
		}
		else if(TIMER[0] < 50){}
		else if(TIMER[0] < 51)
		{
			moveDittoNum(1);
		}
		else if(TIMER[0] < 52)
		{
			//shiftDitto(0);
			moveDittoNum(2);
		}
		else if(TIMER[0] < 53)
		{
			moveDittoNum(3);
		}
		else if(TIMER[0] < 54)
		{
			moveDittoNum(4);
		}
		else if(TIMER[0] < 55)
		{
			moveDittoNum(6);
		}
		else if(TIMER[0] < 60)
		{
			moveDittoNum(7);
		}
		else if(TIMER[0] < 61)
		{
			playSound(50);
			shiftDitto(1);
			moveDittoNum(7);
		}
		else if(TIMER[0] < 62)
		{
			shiftDitto(1);
			moveDittoNum(7);
		}
		else if(TIMER[0] < 68)
		{
			shiftDitto(2);
		}
		else if(TIMER[0] < 73)
		{
			shiftDitto(3);
		}
		else if(TIMER[0] < 95){}
		else if(TIMER[0] < 96)
		{
			playSound(51);
			dittoMosiac(1);
		}
		else if(TIMER[0] < 110)
		{
			dittoMosiac(1);
		}
		else if(TIMER[0] < 115)
		{
			transform();
			dittoMosiac(0);
		}
		else if(TIMER[0] < 130)
		{
			transform();
			dittoMosiac(0);
		}
		else if(TIMER[0] < 165){}
		else if(TIMER[0] < 166)
		{
			playCry(252);
		}
		else if(TIMER[0] < 175)
		{
			//Sound
			loadGameFreak();
		}
		else if(TIMER[0] < 205){}
		else if(TIMER[0] < 215)
		{
			loadPresents();
		}
		else if(TIMER[0] < 290){}
		else if(TIMER[0] < 291)
		{
			fadeScreenFast();
		}
		else if(TIMER[0] < 400){}
		else if(TIMER[0] < 401)
		{
			init[27] = 1;
			TIMER[0] = 0;
			init[0] = 6;
		}
	}	
	else if(init[27] == 1)
	{
		if(TIMER[0] < 30)
		{
			flashA();	
		}
		else if(TIMER[0] < 60)
		{
			unflashA();	
		}
		else if(TIMER[0] < 61)
		{
			playSound(257);
		}
		else if(TIMER[0] < 70)
		{
			flashA();	
		}
		else if(TIMER[0] < 75)
		{
			APulseInit();
		}
		else if(TIMER[0] < 78)
		{
			APulse(1);
		}
		else if(TIMER[0] < 81)
		{
			APulse(2);
		}
		else if(TIMER[0] < 90)
		{
			APulse(3);
		}
		else if(TIMER[0] < 120)
		{	
			unflashA();
			APulse(3);	
		}
		else if(TIMER[0] < 121)
		{
			init[27] = 2;
			TIMER[0] = 0;
			init[0] = 1;
		}
	}
	else if(init[27] == 2)
	{
		if(TIMER[0] < 160)
		{
			treePan();
		}
		else if(TIMER[0] < 161)
		{
			treePan();
			fadeScreenFast();
		}
		else if(TIMER[0] < 180)
		{
			treePan();
		}
		else if(TIMER[0] < 181)
		{
			init[27] = 3;
			init[0] = 0;
			TIMER[0] = 0;
		}
	}
	else if(init[27] == 3)
	{		
		if(TIMER[0] < 10)
		{
			flashI();
		}
		else if(TIMER[0] < 15)
		{
			IPulseInit();
		}
		else if(TIMER[0] < 18)
		{
			APulse(1);
		}
		else if(TIMER[0] < 21)
		{
			APulse(2);
		}
		else if(TIMER[0] < 30)
		{
			APulse(3);
		}
		else if(TIMER[0] < 31)
		{
			blackPulse();
		}
		else if(TIMER[0] < 60)
		{
			unflashI();
		}
		else if(TIMER[0] < 80)
		{
			flashH();
		}
		else if(TIMER[0] < 85)
		{
			APulse(0);
			HPulseInit();
		}
		else if(TIMER[0] < 88)
		{
			APulse(1);
		}
		else if(TIMER[0] < 91)
		{
			APulse(2);
		}
		else if(TIMER[0] < 100)
		{
			APulse(3);
		}
		else if(TIMER[0] < 120)
		{
			unflashH();
			blackPulse();
		}
		else if(TIMER[0] < 180){}
		else if(TIMER[0] < 181)
		{
			init[27] = 4;
			init[0] = 1;
			TIMER[0] = 0;
		}
	}
	else if(init[27] == 4)
	{
		if(TIMER[0] < 90)
		{
			treePan();
		}
		else if(TIMER[0] < 91)
		{
			playSound(17);
		}
		else if(TIMER[0] < 120)
		{
			moveSuicune();
		}
		else if(TIMER[0] < 125)
		{
			shiftGrass();
		}
		else if(TIMER[0] < 130)
		{
			unshiftGrass();
		}
		else if(TIMER[0] < 135)
		{
			shiftGrass();
		}
		else if(TIMER[0] < 140)
		{
			unshiftGrass();
		}
		else if(TIMER[0] < 145)
		{
			shiftGrass();
		}
		else if(TIMER[0] < 150)
		{
			unshiftGrass();
		}
		else if(TIMER[0] < 151)
		{
			playSound(34);
		}
		else if(TIMER[0] < 180)
		{
			moveWooper();
		}
		else if(TIMER[0] < 190){}
		else if(TIMER[0] < 191)
		{
			playSound(34);
		}
		else if(TIMER[0] < 220)
		{
			movePichu();
		}
		else if(TIMER[0] < 230)
		{
			shiftPichu(1);
		}
		else if(TIMER[0] < 240)
		{
			shiftPichu(2);
		}
		else if(TIMER[0] < 270){}
		else if(TIMER[0] < 271)
		{
			fadeScreenFast();
		}
		else if(TIMER[0] < 330){}
		else if(TIMER[0] < 331)
		{
			init[27] = 5;
			init[0] = 0;
			TIMER[0] = 0;
		}
	}
	else if(init[27] == 5)
	{
		//BEST HUGS (evar!)
		if(TIMER[0] < 30)
		{
			showDuck();
		}
		else if(TIMER[0] < 31)
		{
			playSound(258);
		}
		else if(TIMER[0] < 60)
		{
			showE();
		}
		else if(TIMER[0] < 61)
		{
			playSound(257);
		}
		else if(TIMER[0] < 70){}
		else if(TIMER[0] < 90)
		{
			showS();
		}
		else if(TIMER[0] < 91)
		{
			playSound(258);
		}
		else if(TIMER[0] < 100){}
		else if(TIMER[0] < 120)
		{
			showT();
		}

		else if(TIMER[0] < 121)
		{
			playSound(259);
		}
		else if(TIMER[0] < 125){}
		else if(TIMER[0] < 135)
		{
			showH();
		}
		else if(TIMER[0] < 136)
		{
			playSound(258);
		}
		else if(TIMER[0] < 140){}
		else if(TIMER[0] < 150)
		{
			showU();
		}
		else if(TIMER[0] < 151)
		{
			playSound(257);
		}
		else if(TIMER[0] < 155){}
		else if(TIMER[0] < 165)
		{
			showG();
		}
		else if(TIMER[0] < 166)
		{
			playSound(258);
		}
		else if(TIMER[0] < 170){}
		else if(TIMER[0] < 180)
		{
			showS2();
		}
		else if(TIMER[0] < 181)
		{
			fadeScreenFast();
		}
		else if(TIMER[0] < 240){}
		else if(TIMER[0] < 241)
		{
			init[27] = 6;
			init[0] = 1;
			TIMER[0] = 0;
		}
	}
	else if(init[27] == 6)
	{
		if(TIMER[0] < 100)
		{
			treeDashing();
		}
		else if(TIMER[0] < 120)
		{
			treeDashing();
			moveSuicuneDashing();
		}
		else if(TIMER[0] < 140)
		{
			treeDashing();
			moveSuicuneDashingFaster();
		}
		else if(TIMER[0] < 160)
		{
			treeDashing();
		}
		else if(TIMER[0] < 161)
		{
			fadeScreenFast();
			treeDashing();
		}
		else if(TIMER[0] < 180)
		{
			treeDashing();
		}
		else if(TIMER[0] < 181)
		{
			init[27] = 7;
			init[0] = 0;
			TIMER[0] = 0;
		}
	}
	else if(init[27] == 7)
	{
		if(TIMER[0] < 120)
			scrollEpicBackground();
		else if(TIMER[0] < 125)
		{
			shiftUnown(0);
			scrollEpicBackground();
		}
		else if(TIMER[0] < 130)
		{
			shiftUnown(1);
			scrollEpicBackground();
		}
		else if(TIMER[0] < 135)
		{
			shiftUnown(2);
			scrollEpicBackground();
		}
		else if(TIMER[0] < 140)
		{
			shiftUnown(3);
			scrollEpicBackground();
		}
		else if(TIMER[0] < 145)
		{
			shiftUnown(4);
			scrollEpicBackground();
		}
		else if(TIMER[0] < 240){scrollEpicBackground();}
		else if(TIMER[0] < 241)
		{
			fadeScreenFast();
			scrollEpicBackground();
		}
		else if(TIMER[0] < 270){scrollEpicBackground();}
		else if(TIMER[0] < 271)
		{
			init[27] = 8;
			init[0] = 0;
			TIMER[0] = 0;
		}
	}
	else if(init[27] == 8)
	{
		if(TIMER[0] < 138)
		{
			scrollEpicBackground();
		}
		else if(TIMER[0] < 139)
		{
			scrollEpicBackground();
			fadeScreenFast();
		}
		if(TIMER[0] < 170)
		{
			scrollEpicBackground();
		}
		else if(TIMER[0] < 171)
		{
			init[27] = 9;
			init[0] = 0;
			TIMER[0] = 0;
		}
	}
	else if(init[27] == 9)
	{
		if(TIMER[0] < 60)
		{
			scrollEpicBackground();
		}
		else if(TIMER[0] < 68)
		{
			scrollEpicBackground();
			showEduck();
		}
		else if(TIMER[0] < 76)
		{
			scrollEpicBackground();
			showEe();
		}
		else if(TIMER[0] < 84)
		{
			scrollEpicBackground();
			showEs();
		}
		else if(TIMER[0] < 92)
		{
			scrollEpicBackground();
			showEt();
		}
		else if(TIMER[0] < 100)
		{
			scrollEpicBackground();
			showEh2();
		}
		else if(TIMER[0] < 108)
		{
			scrollEpicBackground();
			showEu();
		}
		else if(TIMER[0] < 116)
		{
			scrollEpicBackground();
			showEg();
		}
		else if(TIMER[0] < 124)
		{
			scrollEpicBackground();
			showEs2();
		}
		else if(TIMER[0] < 200)
		{
			scrollEpicBackground();
		}
		else if(TIMER[0] < 201)
		{
			scrollEpicBackground();
			fadeScreenWhite();
		}
		else if(TIMER[0] < 260)
		{
			scrollEpicBackground();
		}
		else if(TIMER[0] < 261)
		{
			init[27] = 10;
			init[0] = 0;
			TIMER[0] = 0;
		}
	}
	else if(init[27] == 10)
	{
		if(TIMER[0] < 20)
		{
			initCrystal();
		}
		else if(TIMER[0] < 210)
		{
			loadText();
		}
		else if(TIMER[0] < 211)
		{
			fadeScreenWhite();
		}
		else if(TIMER[0] > 240)
		{
			init[27] = 11;
			init[0] = 0;
			TIMER[0] = 0;
		}
	}
	if(keyDown(KEY_A) || keyDown(KEY_B) || keyDown(KEY_START) || keyDown(KEY_SELECT) ||init[27] == 11)
   	{
     		int (*func)(void) = (int (*)(void))0x080186A5;
     		resetVars();
		int x = func();
	}
	return;
}

#include <string.h>
#include "include/gba.h"
#include "diegologo.c"
#include "unown.c"
#include "trees.c"
#include "epicsuicune.c"
#include "crystal.c"
#include "useful.h"

