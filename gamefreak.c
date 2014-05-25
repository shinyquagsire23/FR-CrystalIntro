#include "img_bins/ditto/ditto.h"
#include "img_bins/ditto/laz.h"

void initDitto()
{
	if(init[0] == 0)
	{
		loadDittoGFX();
		unfadeScreen();
	}	
	
}

void moveDitto()
{
	OAM_Mem[0] = OAM_Mem[0] + 8;
	if(OAM_Mem[0] > 0xFF && OAM_Mem[0] >> 8 != 0x10)
		OAM_Mem[0] = 0x1000;
}

void moveDittoUp()
{
	OAM_Mem[0] = OAM_Mem[0] - 6;
	if(OAM_Mem[0] > 0xFF && OAM_Mem[0] >> 8 != 0x10)
		OAM_Mem[0] = 0x10FF;
}

void moveDittoNum(int i)
{
	OAM_Mem[0] = OAM_Mem[0] + i;
	if(OAM_Mem[0] > 0xFF && OAM_Mem[0] >> 8 != 0x10)
		OAM_Mem[0] = 0x1000;
}

void moveDittoUpNum(int i)
{
	OAM_Mem[0] = OAM_Mem[0] - i;
	if(OAM_Mem[0] > 0xFF && OAM_Mem[0] >> 8 != 0x10)
		OAM_Mem[0] = 0x10FF;
}

void dittoMosiac(int i)
{
	if(i == 1)
	{
		VAR[1] = VAR[1] + 0x11;
		if(VAR[1] > 0x99)
			VAR[1] = 0x99;
	}
	else
	{
		VAR[1] = VAR[1] - 0x11;
		if(VAR[1] > 0x99)
			VAR[1] = 0x0;
	}
	int e = VAR[1] << 8;
	changeIO(0x4C, e);
}

void shiftDitto(int i)
{
	if(i == 0)
	{
		LZ77UnCompVram(&ditto1Tiles, &OBJData[0]);
	}
	else if(i == 1)
	{
		LZ77UnCompVram(&ditto2Tiles, &OBJData[0]);
	}
	else if(i == 2)
	{
		LZ77UnCompVram(&ditto3Tiles, &OBJData[0]);
	}
	else if(i == 3)
	{
		LZ77UnCompVram(&ditto4Tiles, &OBJData[0]);
	}
}

void transform()
{
	OAM_Mem[2] = 0x1400;
	LZ77UnCompVram(&rocketTiles, &OBJData[0]);
}

void loadGameFreak()
{
	REG_DISPCNT = 0x7140;
}

void loadPresents()
{
	WIN0V = 0xFF;
}

void loadDittoGFX()
{
	REG_DISPCNT = 0x7040;
	BG0CNT = 0x0702;
	WIN0H = 0xFF;
	WIN1H = 0xFFFF;
	WIN0V = 0x6F; //0xFF
	WIN1V = 0xFFFF;
	WININ = 0x1F1F;
	WINOUT = 0x0;
	BLDMOD = 0x1F40;
	copyPal(&dittoPal, &OBJ_PaletteMem[0]);
	copyPal(&rocketPal, &OBJ_PaletteMem[16]);
	copyPal(&lazPal, &BG_PaletteMem[0]);
	LZ77UnCompVram(&ditto1Tiles, &OBJData[0]);
	LZ77UnCompVram(&lazTiles, &Tiles[0]);

	LZ77UnCompVram(&lazMap, &MapData[0]);
	if(keyDown(KEY_R))
	{
		VAR[16] = 1;
		copyPal(&dittoSparklePal, &OBJ_PaletteMem[0]);
		//copyPal(&quagsirePal, &OBJ_PaletteMem[16]);
	}

	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i] = dittoOAM[i];
	}

	init[0] = 1;
}
