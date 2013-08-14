.text
.global callback

.thumb
.thumb_func
.align 2

call_fadescreen:
mov r3, r2
mov r2, r1
cmp r0, #0x1
beq setwhite
mov r1, #0x0
returnfade:
mov r0, #0x1
neg r0, r0
str r1, [sp,#0x0]
mov r1, #0x0
ldr r4, fadescreen;
bx r4

setwhite:
ldrh r1, white
b returnfade

.align 2
fadescreen:			.word 0x080A1AD4+1
white:				.byte 0xFF 
				.byte 0xFF
