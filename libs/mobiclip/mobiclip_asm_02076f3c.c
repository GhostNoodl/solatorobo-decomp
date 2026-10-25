// Actimagine Mobiclip audio decoder, hand-written ARM assembly: the excitation helper
// func_02076f3c, the synthesis filter func_02077118 (reached from func_0207670c), the four pool
// words func_02077118 loads with negative pc offsets, and the 64 x 32-byte table it indexes with
// `add r5, pc, #0x178`.
// Generated with tools/asm2mw/asmblob.py main func_02076f3c:02076f3c:02077108:code
// data_02077108:02077108:02077118:data func_02077118:02077118:020772b8:code
// data_020772b8:020772b8:02077ab8:data

#pragma force_active on

void func_02076990(void);
void func_02076f3c(void);
void data_02077108(void);
void func_02077118(void);
void data_020772b8(void);

asm void func_02076f3c(void) {
    cmp r8, #0
    beq @L02076f54
    mov r12, r8
@L02076f48:
    strh r6, [r3], r10
    subs r12, r12, #1
    bne @L02076f48
@L02076f54:
    ldr r9, [r4], #4
    ldr r9, [r7, r9, lsl #2]
    strh r9, [r3], r10
    strh r6, [r3], r10
    strh r6, [r3], r10
    ldr r9, [r4], #4
    ldr r9, [r7, r9, lsl #2]
    strh r9, [r3], r10
    strh r6, [r3], r10
    strh r6, [r3], r10
    ldr r9, [r4], #4
    ldr r9, [r7, r9, lsl #2]
    strh r9, [r3], r10
    strh r6, [r3], r10
    strh r6, [r3], r10
    ldr r9, [r4], #4
    ldr r9, [r7, r9, lsl #2]
    strh r9, [r3], r10
    strh r6, [r3], r10
    strh r6, [r3], r10
    ldr r9, [r4], #4
    ldr r9, [r7, r9, lsl #2]
    strh r9, [r3], r10
    strh r6, [r3], r10
    strh r6, [r3], r10
    ldr r9, [r4], #4
    ldr r9, [r7, r9, lsl #2]
    strh r9, [r3], r10
    strh r6, [r3], r10
    strh r6, [r3], r10
    ldr r9, [r4], #4
    ldr r9, [r7, r9, lsl #2]
    strh r9, [r3], r10
    strh r6, [r3], r10
    strh r6, [r3], r10
    ldr r9, [r4], #4
    ldr r9, [r7, r9, lsl #2]
    strh r9, [r3], r10
    strh r6, [r3], r10
    strh r6, [r3], r10
    ldr r9, [r4], #4
    ldr r9, [r7, r9, lsl #2]
    strh r9, [r3], r10
    strh r6, [r3], r10
    strh r6, [r3], r10
    ldr r9, [r4], #4
    ldr r9, [r7, r9, lsl #2]
    strh r9, [r3], r10
    strh r6, [r3], r10
    strh r6, [r3], r10
    ldr r9, [r4], #4
    ldr r9, [r7, r9, lsl #2]
    strh r9, [r3], r10
    strh r6, [r3], r10
    strh r6, [r3], r10
    ldr r9, [r4], #4
    ldr r9, [r7, r9, lsl #2]
    strh r9, [r3], r10
    strh r6, [r3], r10
    strh r6, [r3], r10
    ldr r9, [r4], #4
    ldr r9, [r7, r9, lsl #2]
    strh r9, [r3], r10
    strh r6, [r3], r10
    strh r6, [r3], r10
    ldr r9, [r4], #4
    ldr r9, [r7, r9, lsl #2]
    strh r9, [r3], r10
    strh r6, [r3], r10
    strh r6, [r3], r10
    ldr r9, [r4], #4
    ldr r9, [r7, r9, lsl #2]
    strh r9, [r3], r10
    strh r6, [r3], r10
    strh r6, [r3], r10
    ldr r9, [r4], #4
    ldr r9, [r7, r9, lsl #2]
    strh r9, [r3], r10
    strh r6, [r3], r10
    strh r6, [r3], r10
    ldr r9, [r4], #4
    ldr r9, [r7, r9, lsl #2]
    strh r9, [r3], r10
    strh r6, [r3], r10
    strh r6, [r3], r10
    ldr r9, [r4], #4
    ldr r9, [r7, r9, lsl #2]
    strh r9, [r3], r10
    strh r6, [r3], r10
    strh r6, [r3], r10
    ldr r9, [r4], #4
    ldr r9, [r7, r9, lsl #2]
    strh r9, [r3], r10
    strh r6, [r3], r10
    strh r6, [r3], r10
    ldr r9, [r4], #4
    ldr r9, [r7, r9, lsl #2]
    strh r9, [r3], r10
    strh r6, [r3], r10
    strh r6, [r3], r10
    ldr r9, [r4], #4
    ldr r9, [r7, r9, lsl #2]
    strh r9, [r3], r10
    rsbs r12, r8, #3
    moveq pc, lr
@L020770f8:
    strh r6, [r3], r10
    subs r12, r12, #1
    bne @L020770f8
    mov pc, lr
}

asm void data_02077108(void) {
    dcd 0x00006e14
    dcd 0x00004000
    dcd 0xffff8000
    dcd 0x00007fff
}

asm void func_02077118(void) {
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    ldr r1, [r0, #4]
    add r2, r0, #8
    ldr r10, [r0, #0x1cc]
    ldr r0, [r0]
    bl func_02076990
    mov r3, r1
    add r4, r2, #0x40
    add r5, pc, #0x178 // data_020772b8
    mov r6, #0
    ldr r7, [r2, #0x30]
    add r7, r5, r7, lsl #5
    ldr r8, [r2, #0x20]
    bl func_02076f3c
    ldr r7, [r2, #0x34]
    add r7, r5, r7, lsl #5
    ldr r8, [r2, #0x24]
    bl func_02076f3c
    ldr r7, [r2, #0x38]
    add r7, r5, r7, lsl #5
    ldr r8, [r2, #0x28]
    bl func_02076f3c
    ldr r7, [r2, #0x3c]
    add r7, r5, r7, lsl #5
    ldr r8, [r2, #0x2c]
    bl func_02076f3c
    ldr r11, [pc, #-0x80] // data_02077108
    ldr r12, [pc, #-0x80] // data_02077108+0x4
    add r3, r2, #0x190
    ldr r9, [r2, #0x1b4]
    ldr r0, [pc, #-0x88] // data_02077108+0x8
    ldr r4, [pc, #-0x88] // data_02077108+0xc
    mov lr, #0x100
@L0207719c:
    ldrsh r5, [r1]
    ldr r6, [r2, #0x1c]
    ldr r7, [r3, #0x1c]
    mla r8, r6, r7, r12
    sub r5, r5, r8, asr #15
    mla r8, r6, r5, r12
    add r8, r7, r8, asr #15
    str r8, [r3, #0x20]
    ldr r6, [r2, #0x18]
    ldr r7, [r3, #0x18]
    mla r8, r6, r7, r12
    sub r5, r5, r8, asr #15
    mla r8, r6, r5, r12
    add r8, r7, r8, asr #15
    str r8, [r3, #0x1c]
    ldr r6, [r2, #0x14]
    ldr r7, [r3, #0x14]
    mla r8, r6, r7, r12
    sub r5, r5, r8, asr #15
    mla r8, r6, r5, r12
    add r8, r7, r8, asr #15
    str r8, [r3, #0x18]
    ldr r6, [r2, #0x10]
    ldr r7, [r3, #0x10]
    mla r8, r6, r7, r12
    sub r5, r5, r8, asr #15
    mla r8, r6, r5, r12
    add r8, r7, r8, asr #15
    str r8, [r3, #0x14]
    ldr r6, [r2, #0xc]
    ldr r7, [r3, #0xc]
    mla r8, r6, r7, r12
    sub r5, r5, r8, asr #15
    mla r8, r6, r5, r12
    add r8, r7, r8, asr #15
    str r8, [r3, #0x10]
    ldr r6, [r2, #8]
    ldr r7, [r3, #8]
    mla r8, r6, r7, r12
    sub r5, r5, r8, asr #15
    mla r8, r6, r5, r12
    add r8, r7, r8, asr #15
    str r8, [r3, #0xc]
    ldr r6, [r2, #4]
    ldr r7, [r3, #4]
    mla r8, r6, r7, r12
    sub r5, r5, r8, asr #15
    mla r8, r6, r5, r12
    add r8, r7, r8, asr #15
    str r8, [r3, #8]
    ldr r6, [r2]
    ldr r7, [r3]
    mla r8, r6, r7, r12
    sub r5, r5, r8, asr #15
    mla r8, r6, r5, r12
    add r8, r7, r8, asr #15
    str r8, [r3, #4]
    str r5, [r3]
    mla r6, r9, r11, r12
    add r9, r5, r6, asr #15
    add r8, r9, r9
    cmp r8, r0
    movlt r8, r0
    cmp r8, r4
    movgt r8, r4
    strh r8, [r1], r10
    subs lr, lr, #1
    bne @L0207719c
    str r9, [r3, #0x24]
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    bx lr
}

asm void data_020772b8(void) {
    dcd 0xffffffe4
    dcd 0xffffffec
    dcd 0xfffffff4
    dcd 0xfffffffc
    dcd 0x00000004
    dcd 0x0000000c
    dcd 0x00000014
    dcd 0x0000001c
    dcd 0xffffffc8
    dcd 0xffffffd8
    dcd 0xffffffe8
    dcd 0xfffffff8
    dcd 0x00000008
    dcd 0x00000018
    dcd 0x00000028
    dcd 0x00000038
    dcd 0xffffffac
    dcd 0xffffffc4
    dcd 0xffffffdc
    dcd 0xfffffff4
    dcd 0x0000000c
    dcd 0x00000024
    dcd 0x0000003c
    dcd 0x00000054
    dcd 0xffffff90
    dcd 0xffffffb0
    dcd 0xffffffd0
    dcd 0xfffffff0
    dcd 0x00000010
    dcd 0x00000030
    dcd 0x00000050
    dcd 0x00000070
    dcd 0xffffff74
    dcd 0xffffff9c
    dcd 0xffffffc4
    dcd 0xffffffec
    dcd 0x00000014
    dcd 0x0000003c
    dcd 0x00000064
    dcd 0x0000008c
    dcd 0xffffff58
    dcd 0xffffff88
    dcd 0xffffffb8
    dcd 0xffffffe8
    dcd 0x00000018
    dcd 0x00000048
    dcd 0x00000078
    dcd 0x000000a8
    dcd 0xffffff3c
    dcd 0xffffff74
    dcd 0xffffffac
    dcd 0xffffffe4
    dcd 0x0000001c
    dcd 0x00000054
    dcd 0x0000008c
    dcd 0x000000c4
    dcd 0xffffff20
    dcd 0xffffff60
    dcd 0xffffffa0
    dcd 0xffffffe0
    dcd 0x00000020
    dcd 0x00000060
    dcd 0x000000a0
    dcd 0x000000e0
    dcd 0xffffff04
    dcd 0xffffff4c
    dcd 0xffffff94
    dcd 0xffffffdc
    dcd 0x00000024
    dcd 0x0000006c
    dcd 0x000000b4
    dcd 0x000000fc
    dcd 0xfffffee8
    dcd 0xffffff38
    dcd 0xffffff88
    dcd 0xffffffd8
    dcd 0x00000028
    dcd 0x00000078
    dcd 0x000000c8
    dcd 0x00000118
    dcd 0xfffffecc
    dcd 0xffffff24
    dcd 0xffffff7c
    dcd 0xffffffd4
    dcd 0x0000002c
    dcd 0x00000084
    dcd 0x000000dc
    dcd 0x00000134
    dcd 0xfffffeb0
    dcd 0xffffff10
    dcd 0xffffff70
    dcd 0xffffffd0
    dcd 0x00000030
    dcd 0x00000090
    dcd 0x000000f0
    dcd 0x00000150
    dcd 0xfffffe94
    dcd 0xfffffefc
    dcd 0xffffff64
    dcd 0xffffffcc
    dcd 0x00000034
    dcd 0x0000009c
    dcd 0x00000104
    dcd 0x0000016c
    dcd 0xfffffe78
    dcd 0xfffffee8
    dcd 0xffffff58
    dcd 0xffffffc8
    dcd 0x00000038
    dcd 0x000000a8
    dcd 0x00000118
    dcd 0x00000188
    dcd 0xfffffe5c
    dcd 0xfffffed4
    dcd 0xffffff4c
    dcd 0xffffffc4
    dcd 0x0000003c
    dcd 0x000000b4
    dcd 0x0000012c
    dcd 0x000001a4
    dcd 0xfffffe40
    dcd 0xfffffec0
    dcd 0xffffff40
    dcd 0xffffffc0
    dcd 0x00000040
    dcd 0x000000c0
    dcd 0x00000140
    dcd 0x000001c0
    dcd 0xfffffe08
    dcd 0xfffffe98
    dcd 0xffffff28
    dcd 0xffffffb8
    dcd 0x00000048
    dcd 0x000000d8
    dcd 0x00000168
    dcd 0x000001f8
    dcd 0xfffffdd0
    dcd 0xfffffe70
    dcd 0xffffff10
    dcd 0xffffffb0
    dcd 0x00000050
    dcd 0x000000f0
    dcd 0x00000190
    dcd 0x00000230
    dcd 0xfffffd98
    dcd 0xfffffe48
    dcd 0xfffffef8
    dcd 0xffffffa8
    dcd 0x00000058
    dcd 0x00000108
    dcd 0x000001b8
    dcd 0x00000268
    dcd 0xfffffd60
    dcd 0xfffffe20
    dcd 0xfffffee0
    dcd 0xffffffa0
    dcd 0x00000060
    dcd 0x00000120
    dcd 0x000001e0
    dcd 0x000002a0
    dcd 0xfffffd28
    dcd 0xfffffdf8
    dcd 0xfffffec8
    dcd 0xffffff98
    dcd 0x00000068
    dcd 0x00000138
    dcd 0x00000208
    dcd 0x000002d8
    dcd 0xfffffcf0
    dcd 0xfffffdd0
    dcd 0xfffffeb0
    dcd 0xffffff90
    dcd 0x00000070
    dcd 0x00000150
    dcd 0x00000230
    dcd 0x00000310
    dcd 0xfffffcb8
    dcd 0xfffffda8
    dcd 0xfffffe98
    dcd 0xffffff88
    dcd 0x00000078
    dcd 0x00000168
    dcd 0x00000258
    dcd 0x00000348
    dcd 0xfffffc80
    dcd 0xfffffd80
    dcd 0xfffffe80
    dcd 0xffffff80
    dcd 0x00000080
    dcd 0x00000180
    dcd 0x00000280
    dcd 0x00000380
    dcd 0xfffffc10
    dcd 0xfffffd30
    dcd 0xfffffe50
    dcd 0xffffff70
    dcd 0x00000090
    dcd 0x000001b0
    dcd 0x000002d0
    dcd 0x000003f0
    dcd 0xfffffba0
    dcd 0xfffffce0
    dcd 0xfffffe20
    dcd 0xffffff60
    dcd 0x000000a0
    dcd 0x000001e0
    dcd 0x00000320
    dcd 0x00000460
    dcd 0xfffffb30
    dcd 0xfffffc90
    dcd 0xfffffdf0
    dcd 0xffffff50
    dcd 0x000000b0
    dcd 0x00000210
    dcd 0x00000370
    dcd 0x000004d0
    dcd 0xfffffac0
    dcd 0xfffffc40
    dcd 0xfffffdc0
    dcd 0xffffff40
    dcd 0x000000c0
    dcd 0x00000240
    dcd 0x000003c0
    dcd 0x00000540
    dcd 0xfffffa50
    dcd 0xfffffbf0
    dcd 0xfffffd90
    dcd 0xffffff30
    dcd 0x000000d0
    dcd 0x00000270
    dcd 0x00000410
    dcd 0x000005b0
    dcd 0xfffff9e0
    dcd 0xfffffba0
    dcd 0xfffffd60
    dcd 0xffffff20
    dcd 0x000000e0
    dcd 0x000002a0
    dcd 0x00000460
    dcd 0x00000620
    dcd 0xfffff970
    dcd 0xfffffb50
    dcd 0xfffffd30
    dcd 0xffffff10
    dcd 0x000000f0
    dcd 0x000002d0
    dcd 0x000004b0
    dcd 0x00000690
    dcd 0xfffff900
    dcd 0xfffffb00
    dcd 0xfffffd00
    dcd 0xffffff00
    dcd 0x00000100
    dcd 0x00000300
    dcd 0x00000500
    dcd 0x00000700
    dcd 0xfffff820
    dcd 0xfffffa60
    dcd 0xfffffca0
    dcd 0xfffffee0
    dcd 0x00000120
    dcd 0x00000360
    dcd 0x000005a0
    dcd 0x000007e0
    dcd 0xfffff740
    dcd 0xfffff9c0
    dcd 0xfffffc40
    dcd 0xfffffec0
    dcd 0x00000140
    dcd 0x000003c0
    dcd 0x00000640
    dcd 0x000008c0
    dcd 0xfffff660
    dcd 0xfffff920
    dcd 0xfffffbe0
    dcd 0xfffffea0
    dcd 0x00000160
    dcd 0x00000420
    dcd 0x000006e0
    dcd 0x000009a0
    dcd 0xfffff580
    dcd 0xfffff880
    dcd 0xfffffb80
    dcd 0xfffffe80
    dcd 0x00000180
    dcd 0x00000480
    dcd 0x00000780
    dcd 0x00000a80
    dcd 0xfffff4a0
    dcd 0xfffff7e0
    dcd 0xfffffb20
    dcd 0xfffffe60
    dcd 0x000001a0
    dcd 0x000004e0
    dcd 0x00000820
    dcd 0x00000b60
    dcd 0xfffff3c0
    dcd 0xfffff740
    dcd 0xfffffac0
    dcd 0xfffffe40
    dcd 0x000001c0
    dcd 0x00000540
    dcd 0x000008c0
    dcd 0x00000c40
    dcd 0xfffff2e0
    dcd 0xfffff6a0
    dcd 0xfffffa60
    dcd 0xfffffe20
    dcd 0x000001e0
    dcd 0x000005a0
    dcd 0x00000960
    dcd 0x00000d20
    dcd 0xfffff200
    dcd 0xfffff600
    dcd 0xfffffa00
    dcd 0xfffffe00
    dcd 0x00000200
    dcd 0x00000600
    dcd 0x00000a00
    dcd 0x00000e00
    dcd 0xfffff040
    dcd 0xfffff4c0
    dcd 0xfffff940
    dcd 0xfffffdc0
    dcd 0x00000240
    dcd 0x000006c0
    dcd 0x00000b40
    dcd 0x00000fc0
    dcd 0xffffee80
    dcd 0xfffff380
    dcd 0xfffff880
    dcd 0xfffffd80
    dcd 0x00000280
    dcd 0x00000780
    dcd 0x00000c80
    dcd 0x00001180
    dcd 0xffffecc0
    dcd 0xfffff240
    dcd 0xfffff7c0
    dcd 0xfffffd40
    dcd 0x000002c0
    dcd 0x00000840
    dcd 0x00000dc0
    dcd 0x00001340
    dcd 0xffffeb00
    dcd 0xfffff100
    dcd 0xfffff700
    dcd 0xfffffd00
    dcd 0x00000300
    dcd 0x00000900
    dcd 0x00000f00
    dcd 0x00001500
    dcd 0xffffe940
    dcd 0xffffefc0
    dcd 0xfffff640
    dcd 0xfffffcc0
    dcd 0x00000340
    dcd 0x000009c0
    dcd 0x00001040
    dcd 0x000016c0
    dcd 0xffffe780
    dcd 0xffffee80
    dcd 0xfffff580
    dcd 0xfffffc80
    dcd 0x00000380
    dcd 0x00000a80
    dcd 0x00001180
    dcd 0x00001880
    dcd 0xffffe5c0
    dcd 0xffffed40
    dcd 0xfffff4c0
    dcd 0xfffffc40
    dcd 0x000003c0
    dcd 0x00000b40
    dcd 0x000012c0
    dcd 0x00001a40
    dcd 0xffffe400
    dcd 0xffffec00
    dcd 0xfffff400
    dcd 0xfffffc00
    dcd 0x00000400
    dcd 0x00000c00
    dcd 0x00001400
    dcd 0x00001c00
    dcd 0xffffe081
    dcd 0xffffe981
    dcd 0xfffff280
    dcd 0xfffffb80
    dcd 0x00000480
    dcd 0x00000d80
    dcd 0x00001680
    dcd 0x00001f80
    dcd 0xffffdd01
    dcd 0xffffe701
    dcd 0xfffff100
    dcd 0xfffffb00
    dcd 0x00000500
    dcd 0x00000f00
    dcd 0x00001900
    dcd 0x00002300
    dcd 0xffffd981
    dcd 0xffffe481
    dcd 0xffffef80
    dcd 0xfffffa80
    dcd 0x00000580
    dcd 0x00001080
    dcd 0x00001b80
    dcd 0x00002680
    dcd 0xffffd601
    dcd 0xffffe201
    dcd 0xffffee00
    dcd 0xfffffa00
    dcd 0x00000600
    dcd 0x00001200
    dcd 0x00001e00
    dcd 0x00002a00
    dcd 0xffffd281
    dcd 0xffffdf81
    dcd 0xffffec80
    dcd 0xfffff980
    dcd 0x00000680
    dcd 0x00001380
    dcd 0x00002080
    dcd 0x00002d80
    dcd 0xffffcf01
    dcd 0xffffdd01
    dcd 0xffffeb00
    dcd 0xfffff900
    dcd 0x00000700
    dcd 0x00001500
    dcd 0x00002300
    dcd 0x00003100
    dcd 0xffffcb81
    dcd 0xffffda81
    dcd 0xffffe980
    dcd 0xfffff880
    dcd 0x00000780
    dcd 0x00001680
    dcd 0x00002580
    dcd 0x00003480
    dcd 0xffffc801
    dcd 0xffffd801
    dcd 0xffffe800
    dcd 0xfffff800
    dcd 0x00000800
    dcd 0x00001800
    dcd 0x00002800
    dcd 0x00003800
    dcd 0xffffc101
    dcd 0xffffd301
    dcd 0xffffe500
    dcd 0xfffff700
    dcd 0x00000900
    dcd 0x00001b00
    dcd 0x00002cff
    dcd 0x00003eff
    dcd 0xffffba01
    dcd 0xffffce01
    dcd 0xffffe200
    dcd 0xfffff600
    dcd 0x00000a00
    dcd 0x00001e00
    dcd 0x000031ff
    dcd 0x000045ff
    dcd 0xffffb301
    dcd 0xffffc901
    dcd 0xffffdf00
    dcd 0xfffff500
    dcd 0x00000b00
    dcd 0x00002100
    dcd 0x000036ff
    dcd 0x00004cff
    dcd 0xffffac01
    dcd 0xffffc401
    dcd 0xffffdc00
    dcd 0xfffff400
    dcd 0x00000c00
    dcd 0x00002400
    dcd 0x00003bff
    dcd 0x000053ff
    dcd 0xffffa501
    dcd 0xffffbf01
    dcd 0xffffd900
    dcd 0xfffff300
    dcd 0x00000d00
    dcd 0x00002700
    dcd 0x000040ff
    dcd 0x00005aff
    dcd 0xffff9e01
    dcd 0xffffba01
    dcd 0xffffd600
    dcd 0xfffff200
    dcd 0x00000e00
    dcd 0x00002a00
    dcd 0x000045ff
    dcd 0x000061ff
    dcd 0xffff9701
    dcd 0xffffb501
    dcd 0xffffd300
    dcd 0xfffff100
    dcd 0x00000f00
    dcd 0x00002d00
    dcd 0x00004aff
    dcd 0x000068ff
    dcd 0xffff9001
    dcd 0xffffb001
    dcd 0xffffd000
    dcd 0xfffff000
    dcd 0x00001000
    dcd 0x00003000
    dcd 0x00004fff
    dcd 0x00006fff
}

