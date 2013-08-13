.text
.global callback

.thumb
.thumb_func
.align 2

main:
push {r0-r7, lr}
bl main_func
returnmain:
bl call_back3
bl sub_080704D0
pop {r0-r7}
ldr r0, returnloc
bx r0

call_back3:
ldr r4, callback3_address
bx r4

sub_080704D0:
ldr r4, loc_080704D0
bx r4

main_func:
push {lr}
bl C_hook
b returnmain

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
callback3_address:		.word 0x08077578+1
loc_080704D0:			.word 0x080704D0+1
sub_0800CC7A:			.word 0x0800CC7A+1
returnloc:			.word 0x0800053a+1
fadescreen:			.word 0x08070588+1
white:				.hword 0xFF7F

C_hook:
