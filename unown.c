#include "img_bins/unown/unown.h"

void flashA()
{
	if(init[0] >= 5)
	{
		loadAGFX();
	}
}

void unflashA()
{
	if(init[0] == 0)
	{
		init[0] = 6;
		fadeScreenFast();
	}
}

void loadAGFX()
{
	LZ77UnCompVram(&unown_aTiles, &OBJData[0]);
	copyPal(&unown_aPal, &OBJ_PaletteMem[0]);
	copyPal(&blackPal, &BG_PaletteMem[16]);
	copyPal(&blackPal, &OBJ_PaletteMem[16]);

	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i] = unownAOAM[i];
	}

	init[0] = 0;
	unfadeScreen();
}

void flashI()
{
	if(init[0] <= 1)
	{
		loadIGFX();
		playSong(56);
	}
}

void unflashI()
{
	if(init[0] == 2)
	{
		init[0] = 1;
		fadeScreenFast();
	}
}

void flashH()
{
	if(init[0] == 1)
	{
		clearOAM();
		for(int i = 0; i < 8; i++)
		{
			OAM_Mem[i+4] = unownHOAM[i];
		}
		unfadeScreen();
		playSound(55);
		init[0] = 0;
	}
}

void unflashH()
{
	if(init[0] == 0)
	{
		init[0] = 1;
		fadeScreenFast();
	}
}

void showDuck()
{
	if(init[0] == 0)
	{
		loadHugsGFX();
		unfadeScreen();
		playSound(57);
	}
	//unfadeScreen();
}

void showE()
{
	clearOAM();
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+4] = unownEOAM[i];
	}
}

void showS()
{
	clearOAM();
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+8] = unownSOAM[i];
	}
}

void showT()
{
	clearOAM();
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+12] = unownTOAM[i];
	}
}

void showH()
{
	clearOAM();
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+16] = unownH2OAM[i];
	}
}

void showU()
{
	clearOAM();
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+20] = unownUOAM[i];
	}
}

void showG()
{
	clearOAM();
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+24] = unownGOAM[i];
	}
}

void showS2()
{
	clearOAM();
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+28] = unownS2OAM[i];
	}
}

void loadHugsGFX()
{
	clearOAM();
	REG_DISPCNT = 0x1040;

	copyPal(&unown_3Pal, &OBJ_PaletteMem[0]);
	copyPal(&unown_hiPal, &OBJ_PaletteMem[16]);
	copyPal(&blackPal, &BG_PaletteMem[0]);
	copyPal(&blackPal, &BG_PaletteMem[16]);
	copyPal(&blackPal, &BG_PaletteMem[32]);

	LZ77UnCompVram(&unown_duckTiles, &OBJData[0]);
	LZ77UnCompVram(&unown_eTiles, &OBJData[0x100]);
	LZ77UnCompVram(&unown_sTiles, &OBJData[0x200]);
	LZ77UnCompVram(&unown_tTiles, &OBJData[0x300]);
	LZ77UnCompVram(&unown_wTiles, &OBJData[0x400]);
	LZ77UnCompVram(&unown_uTiles, &OBJData[0x500]);
	LZ77UnCompVram(&unown_gTiles, &OBJData[0x600]);
	LZ77UnCompVram(&unown_sTiles, &OBJData[0x700]);

	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i] = unownduckOAM[i];
	}

	init[0] = init[0] + 1;
}

void loadIGFX()
{
	clearOAM();
	REG_DISPCNT = 0x1040;
	LZ77UnCompVram(&unown_iTiles, &OBJData[0]);
	LZ77UnCompVram(&unown_hTiles, &OBJData[0x100]);
	copyPal(&unown_hiPal, &OBJ_PaletteMem[0]);
	copyPal(&blackPal, &BG_PaletteMem[0]);
	copyPal(&blackPal, &BG_PaletteMem[16]);
	copyPal(&blackPal, &BG_PaletteMem[32]);

	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i] = unownIOAM[i];
	}

	unfadeScreen();
	init[0] = init[0] + 1;
}
