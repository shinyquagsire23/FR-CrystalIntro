

void unfadeScreen()
{
	//__asm("mov r0, #0x0");
	//__asm("mov r1, #0x0");
	//int (*func)(void) = (int (*)(void))0x0807A819;
	//int x = func();
	fadeScreen2(0,0x10,0);
}

void fadeScreen()
{
	__asm("mov r0, #0x1");
	__asm("mov r1, #0x4");
	int (*func)(void) = (int (*)(void))0x0807A819;
	int x = func();
}

void fadeScreen2(int nub, int r2, int r3)
{
	int (*func)(void) = (int (*)(void))0x08790025;
	func();
}

void fadeScreenFast()
{
	__asm("mov r0, #0x1");
	__asm("mov r1, #0x0");
	int (*func)(void) = (int (*)(void))0x0807A819;
	int x = func();
}

void unfadeScreenWhite()
{
	__asm("mov r0, #0x2");
	__asm("mov r1, #0x0");
	int (*func)(void) = (int (*)(void))0x0807A819;
	int x = func();
}

void fadeScreenWhite()
{
	__asm("mov r0, #0x3");
	__asm("mov r1, #0x0");
	int (*func)(void) = (int (*)(void))0x0807A819;
	int x = func();
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

void drawText(int *foo, int *font, int *x, int *y, int *bar, int *baz, long *str)
{
	//__asm("str r4, [SP,#0xBC]");
	//__asm("str r5, [SP,#0xBC+4]");
	//__asm("str r6, [SP,#0xBC+8]");
	int (*func)(void) = (int (*)(void))0x0812E51D;
	int i = func();
}

void changeIO(int *a, int *b)
{
	int (*func)(void) = (int (*)(void))0x08000A39;
	int i = func();
}

void something2(int *a, int *b, int *c)
{
	int (*func)(void) = (int (*)(void))0x08001B91;
	int i = func();
}

void something(int *a, int *b, int *c)
{
	int (*func)(void) = (int (*)(void))0x080F6F1D;
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
