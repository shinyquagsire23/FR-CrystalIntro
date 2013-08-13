void faith()
{

}

void trust()
{

}

void pixieDust()
{
	int (*func)(void) = (int (*)(void))0x080a1a1d;
	func();
}

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
	int (*func)(void) = (int (*)(void))0x089E0025;
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
	int (*func)(void) = (int (*)(void))0x080A3241;
	int x = func();
}

void copyPal(void *source, void *dest)
{
	__asm("mov r2, #0x8");
	SystemCall(0xC);
	//int (*func)(void) = (int (*)(void))0x080087BD;
	//func();
}

void copyMem(void *source, void *dest, void *size)
{
	__asm("mov r2, #0x8");
	SystemCall(0xC);
}

void playSong(int *songNum)
{
	int (*func)(void) = (int (*)(void))0x082E0131;
	int x = func();
}

void playCry(int *pkmnNum, int *fx)
{
	int (*func)(void) = (int (*)(void))0x080A3275;
	int x = func();
}

void playSound(int *fxNum)
{
	int (*func)(void) = (int (*)(void))0x080A37A5;
	int x = func();
}

void changeIO(int *a, int *b)
{
	int (*func)(void) = (int (*)(void))0x080010B5;
	int i = func();
}

void clearOAM()
{
	int (*func)(void) = (int (*)(void))0x08006975;
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

