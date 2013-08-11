#include "img_bins/crystal/unown.h"

#define unownBuffer     ((u16*)0x02037108)
#define numCharsinWord 11
//#define unownBuffer     ((u16*)0x03003128)

void initCrystal()
{
	if(init[0] <= 1)
	{	
		loadCrystalGFX();
		unfadeScreenWhite();
	}
}

void loadText()
{
	if(VAR[19] < 20)
		VAR[19] = VAR[19] + 1;
	else
		VAR[19] = 0;

	if(VAR[19] >= 10 && init[30] == 1 && init[28] < numCharsinWord)
	{
		init[30] = 0;
		loadNextLetter();
	}
	else if(VAR[19] < 10)
	{
		init[30] = 1;
	}
}

void loadNextLetter()
{
	for(int i = 0; i < 4; i++)
	{
		OAM_Mem[init[28]*4+i] = unownBuffer[init[28]*4+i];
	}
	init[28] = init[28] + 1;
}

void loadCrystalGFX()
{
	clearOAM();
	copyPal(&whitePal, &BG_PaletteMem[0]);
	copyPal(&whitePal, &BG_PaletteMem[16]);
	copyPal(&unownlettersPal, &OBJ_PaletteMem[0]);
	LZ77UnCompVram(&unownlettersTiles, &OBJData[0]);
	init[0] = init[0] + 1;

	//Now time to center our unown words. 
	//Each letter will be spaced by 16 pixels 
	//on the left and right sides, making the 
	//total letter's area 64 pixels.
	int c = numCharsinWord; //7 letters in CRYSTAL
	c *= 16;
	c = (240 / 2) - (c / 2) - ((numCharsinWord/2)*4);
	
	for(int i = 0; i < numCharsinWord; i++)
	{
		unownBuffer[i*4+0] = 0x40;
		unownBuffer[i*4+1] = 0x4000 + (c + (i * 16)+(i * 4));
		int l = unownWord[i];
		if(l == 0)
			l = 32;
		unownBuffer[i*4+2] = 0x0400 + ((l - 1) * 4);
	}
}
