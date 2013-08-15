#
# Equivalent makefile for the earlier build procedure.
#

PATH   := $(DEVKITARM)/bin:$(PATH)

intro.bin : intro.c
	arm-none-eabi-gcc -mthumb -mthumb-interwork -g -c -w -std=c99 -o intro.out intro.c
	arm-none-eabi-ld -o intro.o -T linker.lsc intro.out
	arm-none-eabi-objcopy -O binary intro.o intro.bin
	rm intro.o
	rm intro.out
