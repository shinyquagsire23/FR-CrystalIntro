#include "img_bins/trees/trees.h"
#include "img_bins/trees/suicune.h"
#include "img_bins/trees/pichu.h"
#include "img_bins/trees/wooper.h"

void treePan()
{
	if(init[0] == 1)
	{
		loadTreeGFX();
	}	
	VAR[17] = VAR[17] + 1;
	if(VAR[19] == 0)
	{
		VAR[18] = VAR[18] + 1;
		VAR[19] = 1;
	}
	else
		VAR[19] = 0;
	changeIO(0x10,VAR[18]);
	changeIO(0x14,VAR[18]);
	changeIO(0x18,VAR[17]);
}

void treeDashing()
{
	if(init[0] == 1)
	{
		loadTreeGFX();
		playSong(277);
		changeIO(0x10,0x1FF);
		changeIO(0x14,0x1FF);
		changeIO(0x18,0x1FF);
		OAM_Mem[1] = 0xC060;
	}	
	VAR[17] = VAR[17] - 12;
	if(VAR[19] == 0)
	{
		VAR[18] = VAR[18] - 12;
		VAR[19] = 1;
	}
	else
		VAR[19] = 0;

	if(VAR[17] == 0 || VAR[17] > 0x1FF)
		VAR[17] = 0x1FF;

	if(VAR[18] == 0 || VAR[18] > 0x1FF)
		VAR[18] = 0x1FF;
	changeIO(0x10,VAR[18]);
	changeIO(0x14,VAR[18]);
	changeIO(0x18,VAR[17]);
	animateSuicune();
}

void moveSuicuneDashing()
{
	doFastAnimTimer();
	if(OAM_Mem[1] > 0xC000)
	{
		OAM_Mem[1] = OAM_Mem[1] - 4;
	}
	else
	{
		OAM_Mem[1] = 0xC1FF;
	}

	animateSuicune();
}

void moveSuicuneDashingFaster()
{
	doFastAnimTimer();
	if(OAM_Mem[1] > 0xC000)
	{
		OAM_Mem[1] = OAM_Mem[1] - 8;
	}
	else
	{
		OAM_Mem[1] = 0xC1FF;
	}

	animateSuicune();
}

void moveSuicune()
{
	doFastAnimTimer();
	if(OAM_Mem[1] > 0xC000)
	{
		OAM_Mem[1] = OAM_Mem[1] - 16;
	}
	else
	{
		OAM_Mem[1] = 0xC1FF;
	}

	animateSuicune();
}

void animateSuicune()
{
	if(VAR[19] == 1 && VAR[22] >= 2)
	{
		VAR[22] = 0;
		VAR[20] = VAR[20] + 1;
		if(VAR[20] > 3)
			VAR[20] = 0;
	}
	else
	{
		VAR[22] = VAR[22] + 1;
	}

	if(VAR[20] == 0)
	{
		LZ77UnCompVram(&suicune1Tiles, &OBJData[0x200]);
	}
	else if(VAR[20] == 1)
	{
		LZ77UnCompVram(&suicune4Tiles, &OBJData[0x200]);
	}
	else if(VAR[20] == 2)
	{
		LZ77UnCompVram(&suicune3Tiles, &OBJData[0x200]);
	}
	else if(VAR[20] == 3)
	{
		LZ77UnCompVram(&suicune2Tiles, &OBJData[0x200]);
	}
}

void doFastAnimTimer()
{
	TIMER[1] = TIMER[1] + 1;
	if(TIMER[1] > 22)
		TIMER[1] = 0;
}

void moveWooper()
{
	BG1CNT = 0x1001; //Move this background back in priority so that their heads don't get stuck in the grass
	if(OAM_Mem[4+0] > 0x42)
	{
		OAM_Mem[4+0] = OAM_Mem[4+0] - 8;
	}
	else
	{
		OAM_Mem[4+0] = 0x42;
	}
}

void movePichu()
{
	if(OAM_Mem[8+0] > 0x40)
	{
		OAM_Mem[8+0] = OAM_Mem[8+0] - 8;
	}
	else
	{
		OAM_Mem[8+0] = 0x40;
	}
}

void shiftPichu(int stage)
{
	if(stage == 0)
		LZ77UnCompVram(&pichu1Tiles, &OBJData[0x800]);
	else if(stage == 1)
		LZ77UnCompVram(&pichu2Tiles, &OBJData[0x800]);
	else
		LZ77UnCompVram(&pichu3Tiles, &OBJData[0x800]);
}

void shiftGrass()
{
	LZ77UnCompVram(&grass2Map, &BG1Data[0]);
	LZ77UnCompVram(&grass2Tiles, &Tiles[0x1000]);
}

void unshiftGrass()
{
	LZ77UnCompVram(&grassMap, &BG1Data[0]);
	LZ77UnCompVram(&grassTiles, &Tiles[0x1000]);
}

void loadTreeGFX()
{
	REG_DISPCNT = 0x7760;
	BG1CNT = 0x1000;
	BG2CNT = 0x1800;
	BG1VOFF = 0x0;
	WIN0H = 0xFF;
	WIN1H = 0xFFFF;
	WIN0V = 0x0C96;//0xFF;
	WIN1V = 0xFFFF;
	WININ = 0x1F1F;
	WINOUT = 0x0;
	BLDMOD = 0x1F40;
	clearOAM();
	copyPal(&trees_bg0_nightPal, &BG_PaletteMem[0]);
	copyPal(&bushNightPal, &BG_PaletteMem[16]);
	copyPal(&suicunePal, &OBJ_PaletteMem[0]);
	copyPal(&wooperPal, &OBJ_PaletteMem[16]);
	copyPal(&pichuPal, &OBJ_PaletteMem[32]);
	LZ77UnCompVram(&trees_bg0_nightTiles, &Tiles[0]);
	LZ77UnCompVram(&trees_bg0_nightMap, &MapData[0]);
	LZ77UnCompVram(&grassTiles, &Tiles[0x1000]);

	LZ77UnCompVram(&grassMap, &BG1Data[0]);
	LZ77UnCompVram(&bushNightTiles, &Tiles[0xa00]);
	LZ77UnCompVram(&bushNightMap, &BG2Data[0]);
	LZ77UnCompVram(&suicune1Tiles, &OBJData[0x200]);
	LZ77UnCompVram(&wooperTiles, &OBJData[0x400]);
	LZ77UnCompVram(&pichu1Tiles, &OBJData[0x800]);

	if(VAR[16] == 1)
	{
		copyPal(&wooper2Pal, &OBJ_PaletteMem[16]);
	}

	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i] = suicuneOAM[i];
	}
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+4] = wooperOAM[i];
	}
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+8] = pichuOAM[i];
	}
	
	init[0] = 0;
	unfadeScreen();
}
