#include "img_bins/epic/background.h"
#include "img_bins/epic/suicune.h"
#include "img_bins/epic/unown.h"

void scrollEpicBackground()
{
	if(init[0] <= 1)
	{
		loadEpicGFX();
		unfadeScreen();
		VAR[17] = 0x1FF;
		VAR[18] = 0;
	}
	VAR[17] = VAR[17] - 12;
	VAR[18] = VAR[18] + 2;
	if(VAR[18] > 0x30)
		VAR[18] = 0x30;
	changeIO(0x10,0);
	changeIO(0x12,VAR[17]);
	changeIO(0x14,VAR[18]);

	if(OAM_Mem[0] > 0x30)
		OAM_Mem[0] = OAM_Mem[0] - 1;

	
	if(init[27] == 7)
	{
		if(VAR[19] < 10)
			VAR[19] = VAR[19] + 1;
		else
			VAR[19] = 0;

		if(VAR[19] >= 5)
			LZ77UnCompVram(&epicsuicune2Tiles, &OBJData[0]);
		else
			LZ77UnCompVram(&epicsuicune1Tiles, &OBJData[0]);
	}
	else if(init[27] == 8)
	{
		if(VAR[19] < 20)
			VAR[19] = VAR[19] + 1;
		else
			VAR[19] = 0;

		if(VAR[19] >= 10)
		{
			LZ77UnCompVram(&suicunemug1Tiles, &Tiles[0xa00]);
			LZ77UnCompVram(&suicunemug1Map, &BG1Data[0]);
		}
		else
		{
			LZ77UnCompVram(&suicunemug2Tiles, &Tiles[0xa00]);
			LZ77UnCompVram(&suicunemug2Map, &BG1Data[0]);
		}
	}
}

void shiftUnown(int i)
{
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+4] = unown_fOAM[i];
	}
	if(i == 0)
		LZ77UnCompVram(&unown_f1Tiles, &OBJData[0x400]);	
	else if(i == 1)
		LZ77UnCompVram(&unown_f2Tiles, &OBJData[0x400]);
	else if(i == 2)
		LZ77UnCompVram(&unown_f3Tiles, &OBJData[0x400]);
	else if(i == 3)
		LZ77UnCompVram(&unown_f4Tiles, &OBJData[0x400]);
	else if(i == 4)
		LZ77UnCompVram(&unown_f5Tiles, &OBJData[0x400]);
}

void showEduck()
{
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+4] = sunownduckOAM[i];
	}
}

void showEe()
{
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+8] = sunownEOAM[i];
	}
}

void showEs()
{
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+12] = sunownSOAM[i];
	}
}

void showEt()
{
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+16] = sunownTOAM[i];
	}
}

void showEh2()
{
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+20] = sunownH2OAM[i];
	}
}

void showEu()
{
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+24] = sunownUOAM[i];
	}
}

void showEg()
{
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+28] = sunownGOAM[i];
	}
}

void showEs2()
{
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+32] = sunownS2OAM[i];
	}
}

void loadEpicGFX()
{
	REG_DISPCNT = 0x7160;
	WIN0H = 0xFF;
	WIN1H = 0xFFFF;
	WIN0V = 0x0C96;//0xFF;
	WIN1V = 0xFFFF;
	clearOAM();
	copyPal(&seismicPal, &BG_PaletteMem[0]);
	LZ77UnCompVram(&seismicTiles, &Tiles[0]);
	LZ77UnCompVram(&seismicMap, &MapData[0]);

	if(init[27] < 8)
	{
		copyPal(&epicsuicunePal, &OBJ_PaletteMem[0]);
		copyPal(&unown_fPal, &OBJ_PaletteMem[16]);
		LZ77UnCompVram(&epicsuicune1Tiles, &OBJData[0]);
		for(int i = 0; i < 8; i++)
		{
			OAM_Mem[i] = epicsuicuneOAM[i];
		}	
	}
	else if(init[27] == 8)
	{
		REG_DISPCNT = 0x7360;
		WIN0V = 0x2180;
		WIN0H = 0x1FD0;
		copyPal(&suicunemugPal, &BG_PaletteMem[16]);
		LZ77UnCompVram(&suicunemug1Tiles, &Tiles[0xa00]);
		LZ77UnCompVram(&suicunemug1Map, &BG1Data[0]);
	}
	else if(init[27] == 9)
	{
		copyPal(&unown_3Pal, &OBJ_PaletteMem[0]);
		copyPal(&epicsuicunePal, &OBJ_PaletteMem[16]);
		LZ77UnCompVram(&unown_duckTiles, &OBJData[0]);
		LZ77UnCompVram(&unown_eTiles, &OBJData[0x100]);
		LZ77UnCompVram(&unown_sTiles, &OBJData[0x200]);
		LZ77UnCompVram(&unown_tTiles, &OBJData[0x300]);
		LZ77UnCompVram(&unown_wTiles, &OBJData[0x400]);
		LZ77UnCompVram(&unown_uTiles, &OBJData[0x500]);
		LZ77UnCompVram(&unown_gTiles, &OBJData[0x600]);
		LZ77UnCompVram(&unown_sTiles, &OBJData[0x700]);
		LZ77UnCompVram(&epicsuicune3Tiles, &OBJData[0x800]);
		for(int i = 0; i < 8; i++)
		{
			OAM_Mem[i] = epicsuicune2OAM[i];
		}

	}

	init[0] = init[0] + 1;
}
