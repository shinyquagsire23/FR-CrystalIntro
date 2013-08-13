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
mov r0, #0x1
neg r0, r0
mov r3, r2
mov r2, r1
mov r1, #0x0
str r1, [sp,#0x0]
mov r1, #0x0
ldr r4, =0x08070589;
bx r4

.align 2
callback3_address:		.word 0x08077578+1
loc_080704D0:			.word 0x080704D0+1
sub_0800CC7A:			.word 0x0800CC7A+1
unfadescreen_trigger:		.word 0x020370B6
returnloc:			.word 0x0800053a+1
returnloc2:			.word 0x0800053a+1
returnloc3:			.word 0x0800053a+1

C_hook:
