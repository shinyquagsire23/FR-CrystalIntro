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

void APulseInit()
{
	for(int i = 0; i < 4; i++)
	{
		OAM_Mem[i] = unownP1OAM[i];
	}
	for(int i = 0; i < 4; i++)
	{
		OAM_Mem[i+4] = unownP2OAM[i];
	}
	for(int i = 0; i < 4; i++)
	{
		OAM_Mem[i+8] = unownP3OAM[i];
	}
	for(int i = 0; i < 4; i++)
	{
		OAM_Mem[i+12] = unownP4OAM[i];
	}
}

void IPulseInit()
{
	for(int i = 0; i < 4; i++)
	{
		OAM_Mem[i] = unownIP1OAM[i];
	}
	for(int i = 0; i < 4; i++)
	{
		OAM_Mem[i+4] = unownIP2OAM[i];
	}
	for(int i = 0; i < 4; i++)
	{
		OAM_Mem[i+8] = unownIP3OAM[i];
	}
	for(int i = 0; i < 4; i++)
	{
		OAM_Mem[i+12] = unownIP4OAM[i];
	}
}

void HPulseInit()
{
	for(int i = 0; i < 4; i++)
	{
		OAM_Mem[i] = unownHP1OAM[i];
	}
	for(int i = 0; i < 4; i++)
	{
		OAM_Mem[i+4] = unownHP2OAM[i];
	}
	for(int i = 0; i < 4; i++)
	{
		OAM_Mem[i+8] = unownHP3OAM[i];
	}
	for(int i = 0; i < 4; i++)
	{
		OAM_Mem[i+12] = unownHP4OAM[i];
	}
}

void APulse(int i)
{
	if(i == 0)
	{
		LZ77UnCompVram(&unownpulse1Tiles, &OBJData[0x200]);
	}
	else if(i == 1)
	{
		LZ77UnCompVram(&unownpulse2Tiles, &OBJData[0x200]);
	}
	else if(i == 2)
	{
		LZ77UnCompVram(&unownpulse3Tiles, &OBJData[0x200]);
	}
	else if(i == 3)
	{
		LZ77UnCompVram(&unownpulse4Tiles, &OBJData[0x200]);
	}

	if(i >= 1)
		movePulseA();
}

void blackPulse()
{
	copyPal(&blackPal, &OBJ_PaletteMem[16]);
}

void movePulseA()
{
	OAM_Mem[0] = OAM_Mem[0] - 4;
	OAM_Mem[1] = OAM_Mem[1] - 4;

	OAM_Mem[4] = OAM_Mem[4] - 4;
	OAM_Mem[5] = OAM_Mem[5] + 4;

	OAM_Mem[8] = OAM_Mem[8] + 4;
	OAM_Mem[9] = OAM_Mem[9] - 4;

	OAM_Mem[12] = OAM_Mem[12] + 4;
	OAM_Mem[13] = OAM_Mem[13] + 4;

	if(OAM_Mem[0] > 0xFF)
		OAM_Mem[0] = 0xFF;
	if(OAM_Mem[4] > 0xFF)
		OAM_Mem[4] = 0xFF;
}


void loadAGFX()
{
	REG_DISPCNT = 0x7040;
	clearOAM();
	copyPal(&unown_aPal, &OBJ_PaletteMem[0]);
	copyPal(&unownpulsePal, &OBJ_PaletteMem[16]);
	copyPal(&blackPal, &BG_PaletteMem[16]);

	LZ77UnCompVram(&unown_aTiles, &OBJData[0]);
	LZ77UnCompVram(&unownpulse1Tiles, &OBJData[0x200]);

	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+20] = unownAOAM[i];
	}

	init[0] = 0;
	unfadeScreen();
}

void flashI()
{
	if(init[0] <= 1)
	{
		loadIGFX();
		playSound(56);
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
		copyPal(&unownpulsePal, &OBJ_PaletteMem[16]);
		for(int i = 0; i < 8; i++)
		{
			OAM_Mem[i+20] = unownHOAM[i];
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
		fadeScreen2(0,0x10,0);
		playSound(57);
		unfadeScreen();
	}
	//
}

void showE()
{
	clearOAM();
	if(init[0] == 1)
	{
		//unfadeScreen();
		init[0] = 0;
	}
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+4] = unownEOAM[i];
	}
}

void showS()
{
	clearOAM();
	if(init[0] == 0)
	{
		//fadeScreen2(0,0x10,0);
		init[0] = 1;
	}
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+8] = unownSOAM[i];
	}
}

void showT()
{
	clearOAM();
	if(init[0] == 1)
	{
		//fadeScreen2(0,0x10,0);
		init[0] = 0;
	}
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+12] = unownTOAM[i];
	}
}

void showH()
{
	clearOAM();
	//fadeScreen2(0,0x10,0);
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+16] = unownH2OAM[i];
	}
}

void showU()
{
	clearOAM();
	//unfadeScreen();
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+20] = unownUOAM[i];
	}
}

void showG()
{
	clearOAM();
	//unfadeScreen();
	for(int i = 0; i < 8; i++)
	{
		OAM_Mem[i+24] = unownGOAM[i];
	}
}

void showS2()
{
	clearOAM();
	//unfadeScreen();
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
	LZ77UnCompVram(&unownpulse1Tiles, &OBJData[0x200]);
	copyPal(&unown_hiPal, &OBJ_PaletteMem[0]);
	copyPal(&unownpulsePal, &OBJ_PaletteMem[16]);
	copyPal(&blackPal, &BG_PaletteMem[0]);
	copyPal(&blackPal, &BG_PaletteMem[16]);
	copyPal(&blackPal, &BG_PaletteMem[32]);

	for(int i = 0; i < 4; i++)
	{
		OAM_Mem[i+20] = unownIOAM[i];
	}

	unfadeScreen();
	init[0] = init[0] + 1;
}
