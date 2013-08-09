#define TITLE     ((u8*)0x020370B7)
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
	if(init[27] == 0)
	{
		if(TIMER[0] < 211)
		{
			quagStrut();
		}
		else if(TIMER[0] < 263)
		{	
			quagWalkDown();
		}	
		else if	(TIMER[0] < 303)
		{
			quagShout();
		}
		else if(TIMER[0] < 343)
		{
			quagSparkle();
		}
		else if(TIMER[0] < 344)
		{
			fadeScreen();
			fadeSong();
		}
		else if(TIMER[0] < 500){}
		else if(TIMER[0] < 530)
		{
			init[27] = 1;
			TIMER[0] = 0;
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
		else if(TIMER[0] < 90)
		{
			flashA();	
		}
		else if(TIMER[0] < 120)
		{	
			unflashA();	
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
		if(TIMER[0] < 30)
		{
			flashI();
		}
		else if(TIMER[0] < 60)
		{
			unflashI();
		}
		else if(TIMER[0] < 90)
		{
			flashH();
		}
		else if(TIMER[0] < 120)
		{
			unflashH();
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
		else if(TIMER[0] < 180)
		{
			moveWooper();
		}
		else if(TIMER[0] < 190){}
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
		//un3Test();
		if(TIMER[0] < 30)
		{
			showDuck();
		}
		else if(TIMER[0] < 60)
		{
			showE();
		}
		else if(TIMER[0] < 90)
		{
			showS();
		}
		else if(TIMER[0] < 120)
		{
			showT();
		}

		else if(TIMER[0] < 135)
		{
			showH();
		}
		else if(TIMER[0] < 150)
		{
			showU();
		}
		else if(TIMER[0] < 165)
		{
			showG();
		}
		else if(TIMER[0] < 180)
		{
			showS2();
		}
		else if(TIMER[0] < 180){}
		else if(TIMER[0] < 181)
		{
			init[27] = 6;
			init[0] = 1;
			TIMER[0] = 0;
		}
	}
	if(keyDown(KEY_A))
	{
		int (*func)(void) = (int (*)(void))0x0800CC7B;
		resetVars();
		int x = func();
	}
	return;
}

#include <string.h>
#include "include/gba.h"
#include "companylogo.c"
#include "unown.c"
#include "trees.c"
#include "useful.h"

