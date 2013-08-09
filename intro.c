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
		else if(TIMER[0] < 140)
		{
			moveSuicune();
		}
		else if(TIMER[0] < 145)
		{
			shiftGrass();
		}
		else if(TIMER[0] < 150)
		{
			unshiftGrass();
		}
		else if(TIMER[0] < 155)
		{
			shiftGrass();
		}
		else if(TIMER[0] < 160)
		{
			unshiftGrass();
		}
		else if(TIMER[0] < 165)
		{
			shiftGrass();
		}
		else if(TIMER[0] < 170)
		{
			unshiftGrass();
		}
		else if(TIMER[0] < 200)
		{
			moveWooper();
		}
		else if(TIMER[0] < 210){}
		else if(TIMER[0] < 240)
		{
			movePichu();
		}
		else if(TIMER[0] < 250)
		{
			shiftPichu(1);
		}
		else if(TIMER[0] < 260)
		{
			shiftPichu(2);
		}
		else if(TIMER[0] < 290){}
		else if(TIMER[0] < 291)
		{
			fadeScreenFast();
		}
		else if(TIMER[0] < 300){}
		else if(TIMER[0] < 301)
		{
			init[27] = 5;
			init[0] = 0;
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

