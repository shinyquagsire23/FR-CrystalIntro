#include "img_bins/quagsire/logo.h"
#include "img_bins/quagsire/quagsire.h"
#include "img_bins/quagsire/sparkle.h"
#include <string.h>
#include "include/gba.h"

void quagStrut();
void quagWalkDown();
void quagShout();
void quagSparkle();
void initSprites();
void changeQuagsireGFX();
void doAnimTimer();
void moveQuagsireLeft();
void moveQuagsireDown();

void quagStrut()
{
	doAnimTimer();
	if(init[0] == 0)
	{
		initGFX();
	}
	moveQuagsireLeft();
}

void quagWalkDown()
{
	doAnimTimer();
	if(init[0] == 1)
	{
		changeQuagsireGFX();
	}
	moveQuagsireLeft();
	moveQuagsireDown();
}

void quagShout()
{
	doAnimTimer();
	if(init[0] < 4)
	{
		changeQuagsireGFXShout();
	}

	if(TIMER[1] < 22)
	{
		OAM_Mem[2] = 32;
		if(init[0] == 3)
		{
			playCry(195,0);
			init[0] = 4;
		}
	}
	else
	{
		OAM_Mem[2] = 0;
	}
}

void quagSparkle()
{
	if(VAR[16] == 1)
	{
		init[0] = 5;
		TIMER[1] = 0x0;
		return;
	}
	if(init[0] == 4)
	{
		TIMER[1] = 0x0;
		init[0] = 5;
		playSound(0x5F);
	}
	doAnimTimer();
	if(TIMER[1] == 0x3)
		setSparkle2();
	if(TIMER[1] == 0xe)
		setSparkle1();
	if(TIMER[1] == 0x16)
		setSparkle2();
	if(TIMER[1] == 0x1e)
		setSparkle3();
	if(TIMER[1] == 0x26)
		setSparkle4();
}

void doAnimTimer()
{
	TIMER[1] = TIMER[1] + 1;
	if(TIMER[1] > 45)
		TIMER[1] = 0;
}

void initGFX()
{
	//Copy our palettes first
	//TIMER[0] = 630;
	REG_DISPCNT = 0x1140;
	BG0CNT = 0x0702;
	copyPal(&logoPal, &BG_PaletteMem[16]);
	copyPal(&quagPal, &OBJ_PaletteMem[0]);
	copyPal(&sparklePal, &OBJ_PaletteMem[16]);
	LZ77UnCompVram(&logoTiles, &Tiles[0]);
	LZ77UnCompVram(&logoTileData, &MapData[0]);
	LZ77UnCompVram(&walk1Tiles, &OBJData[0]);
	LZ77UnCompVram(&walk2Tiles, &OBJData[0x200]);
	
	if(keyDown(KEY_R))
	{
		VAR[16] = 1;
		copyPal(&quagNormalPal, &OBJ_PaletteMem[0]);
		copyPal(&logobluePal, &BG_PaletteMem[16]);
		LZ77UnCompVram(&logoblueTiles, &Tiles[0]);
	}

	initSprites();
	init[0] = 1;
	playSong(315);
	unfadeScreen();
	drawText(1,2,8,1,0x0200002c,0,0x08415d93);
}

void initSprites()
{
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i] = quagOAM[i];
	}
}

void changeQuagsireGFX()
{
	LZ77UnCompVram(&turn1Tiles, &OBJData[0]);
	LZ77UnCompVram(&turn2Tiles, &OBJData[0x200]);
	init[0] = 2;
}

void changeQuagsireGFXShout()
{
	LZ77UnCompVram(&turn2Tiles, &OBJData[0]);
	LZ77UnCompVram(&shoutTiles, &OBJData[0x200]);
	init[0] = 3;
}

void setSparkle1()
{
	LZ77UnCompVram(&sparkle1Tiles, &OBJData[0x100]);
}

void setSparkle2()
{
	LZ77UnCompVram(&sparkle2Tiles, &OBJData[0x100]);
}

void setSparkle3()
{
	LZ77UnCompVram(&sparkle3Tiles, &OBJData[0x100]);
}

void setSparkle4()
{
	LZ77UnCompVram(&sparkle4Tiles, &OBJData[0x100]);
}

void moveQuagsireLeft()
{
	if(VAR[1] == 2)
	{
		OAM_Mem[1] = OAM_Mem[1] - 2;
		VAR[1] = 0;
	}
	else
		VAR[1] = VAR[1]++;
	if(TIMER[1] < 22)
	{
		OAM_Mem[2] = 32;
	}
	else
	{
		OAM_Mem[2] = 0;
	}
}

void moveQuagsireDown()
{
	if(VAR[1] == 2)
	{
		OAM_Mem[0] = OAM_Mem[0] + 1;
		VAR[1] = 0;
	}
	else
		VAR[1] = VAR[1]++;
}
