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
