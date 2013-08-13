
void unfadeScreen()
{
	fadeScreen2(0,0x10,0);
}

void fadeScreen()
{
	fadeScreen2(4,0,0x10);
}

void fadeScreen2(int white, int r2, int r3)
{
	int (*func)(void) = (int (*)(void))0x08790025;
	func();
}

void fadeScreenFast()
{
	fadeScreen2(0,0,0x10);
}

void unfadeScreenWhite()
{
	fadeScreen2(1,0x10,0);
}

void fadeScreenWhite()
{
	fadeScreen2(1,0,0x10);
}

void fadeSong()
{
	__asm("mov r0, #0x4");
	int (*func)(void) = (int (*)(void))0x0806b155;
	int x = func();
}

void copyPal(void *source, void *dest)
{
	__asm("mov r2, #0x8");
	SystemCall(0xC);
}

void copyMem(void *source, void *dest, void *size)
{
	__asm("mov r2, #0x8");
	SystemCall(0xC);
}

void playSong(int *songNum)
{
	int (*func)(void) = (int (*)(void))0x081DD0F5;
	int x = func();
}

void playCry(int *pkmnNum, int *fx)
{
	int (*func)(void) = (int (*)(void))0x08071dF1;
	int x = func();
}

void playSound(int *fxNum)
{
	int (*func)(void) = (int (*)(void))0x080722CD;
	int x = func();
}

void changeIO(int *a, int *b)
{
	int (*func)(void) = (int (*)(void))0x08000A39;
	int i = func();
}

void clearOAM()
{
	int (*func)(void) = (int (*)(void))0x08006B11;
	int i = func();
}

void resetVars()
{
	TIMER[0] = 0;
	TIMER[1] = 0;
	for(int i = 0; i < 90; i++)
	{
		VAR[i] = 0;
	}
}

