// NitroSDK/TwlSDK crt0 (hybrid ROM start-up code), hand-written assembly, followed by the TWL
// and NITRO module parameter blocks that the start-up code and the ROM tools read.

#pragma force_active on

void __call_static_initializers(void);
void _fp_init(void);
void func_0203d5c4(void);
extern char data_0208d940[];
extern char data_020925e0[];
extern char data_02092600[];
extern char OS_IrqHandler[];
extern char data_02fe0000[];
extern char func_02004fd4[];
extern char func_02004ffc[];
extern char main[];
void Entry(void);
void INITi_CpuClear32(void);
void INITi_InitCoprocessor(void);
void INITi_InitRegion(void);
void INITi_DoAutoload(void);
void INITi_ShelterStaticInitializer(void);
void INITi_CallStaticInitializers(void);
void MIi_UncompressBackward(void);
void AutoloadCallback(void);
void func_02004eac(void);
void OSi_ReferSymbol(void);
void INITi_IsRunOnTwl(void);
void INITi_Copy32(void);
void INITi_Fill32(void);
void data_02004f7c(void);
void func_02004f94(void);
void BuildInfo(void);

asm void Entry(void) {
    mov r12, #0x4000000
    str r12, [r12, #0x208]
    bl INITi_InitCoprocessor
    mov r0, #0
    ldr r1, =0x2ffff80
    ldr r2, =0x68
    bl INITi_CpuClear32
    mov r0, #0
    ldr r1, =0x2fffff0
    ldr r2, =0x10
    bl INITi_CpuClear32
    ldr r1, =0x2fffc40
    ldrh r2, [r1]
    cmp r2, #0
    moveq r2, #1
    streqh r2, [r1]
    ldr r1, =func_02004fd4
    ldr r2, =0x1ff8000
    add r3, r2, #0x28
@L0200484c:
    ldr r0, [r1], #4
    str r0, [r2], #4
    cmp r2, r3
    blt @L0200484c
    ldr r0, =0x2fffc28
    mov r1, #1
    strh r1, [r0]
    ldr r0, =0x2fffc24
    ldr r1, =0x2fffc26
    ldr r2, =0x1ff8000
    blx r2
    ldr r1, =0x2004f94
    ldr r2, =0x1ff8000
    add r3, r2, #0x1c
@L02004884:
    ldr r0, [r1], #4
    str r0, [r2], #4
    cmp r2, r3
    blt @L02004884
    ldr r0, =0x2fffc28
    mov r1, #4
    ldr r2, =0x1ff8000
    blx r2
    bl INITi_IsRunOnTwl
    bne @L020048d8
    ldr r1, =func_02004ffc
    ldr r2, =0x1ff8000
    add r2, r2, #0x1c
    mov r3, #0x34
@L020048bc:
    subs r3, r3, #4
    ldr r0, [r1, r3]
    str r0, [r2, r3]
    bgt @L020048bc
    mov r0, #1
    mov r1, #8
    blx r2
@L020048d8:
    bl INITi_InitRegion
    mov r0, #0x13
    msr cpsr_c, r0
    ldr r1, =data_02fe0000
    add r1, r1, #0x4000
    sub sp, r1, #0x40
    sub r1, sp, #0x40
    mov r0, #0x12
    msr cpsr_c, r0
    sub sp, r1, #4
    tst sp, #4
    subeq sp, sp, #4
    ldr r0, =0x800
    sub r1, r1, r0
    mov r0, #0x1f
    msr cpsr_fsxc, r0
    sub sp, r1, #4
    tst sp, #4
    subne sp, sp, #4
    mov r0, #0
    ldr r1, =data_02fe0000
    mov r2, #0x4000
    bl INITi_CpuClear32
    mov r1, #0
    ldr r0, =0x5000000
    mov r2, #0x400
    bl INITi_Fill32
    ldr r0, =0x7000000
    mov r2, #0x400
    bl INITi_Fill32
    bl INITi_DoAutoload
    mov r1, #0
    ldr r3, =BuildInfo
    ldr r0, [r3, #0xc]
    ldr r2, [r3, #0x10]
    subs r2, r2, r0
    blgt INITi_Fill32
    ldr r1, =data_02fe0000
    add r1, r1, #0x3fc0
    add r1, r1, #0x3c
    ldr r0, =OS_IrqHandler
    str r0, [r1]
    bl _fp_init
    bl func_0203d5c4
    bl __call_static_initializers
    bl INITi_CallStaticInitializers
    ldr r1, =0x4000006
@L02004994:
    ldrh r0, [r1]
    cmp r0, #0
    bne @L02004994
    ldr r1, =main
    ldr lr, =0xffff0000
    bx r1
}

asm void INITi_CpuClear32(void) {
    add r12, r1, r2
@L02004a04:
    cmp r1, r12
    strlt r0, [r1], #4
    blt @L02004a04
    bx lr
}

asm void INITi_InitCoprocessor(void) {
    mrc p15, 0, r0, c1, c0, 0
    tst r0, #1
    beq @L02004a54
    tst r0, #4
    beq @L02004a4c
    mov r1, #0
@L02004a2c:
    mov r2, #0
@L02004a30:
    orr r3, r1, r2
    mcr p15, 0, r3, c7, c10, 2
    add r2, r2, #0x20
    cmp r2, #0x400
    blt @L02004a30
    adds r1, r1, #0x40000000
    bne @L02004a2c
@L02004a4c:
    mov r1, #0
    mcr p15, 0, r1, c7, c10, 4
@L02004a54:
    ldr r1, =0xf9005
    bic r0, r0, r1
    ldr r1, =0x2078
    orr r0, r0, r1
    mcr p15, 0, r0, c1, c0, 0
    mov r1, #0x20
    mcr p15, 0, r1, c9, c1, 1
    ldr r1, =data_02fe0000
    orr r1, r1, #0xa
    mcr p15, 0, r1, c9, c1, 0
    mov r1, #0x50000
    orr r0, r0, r1
    mcr p15, 0, r0, c1, c0, 0
    bx lr
}

asm void INITi_InitRegion(void) {
    mov r12, lr
    ldr r0, =0x4000033
    mcr p15, 0, r0, c6, c0, 0
    ldr r0, =data_02fe0000
    orr r0, r0, #0x1b
    mcr p15, 0, r0, c6, c4, 0
    ldr r0, =0x100002f
    mcr p15, 0, r0, c6, c5, 0
    ldr r0, =0xffff001d
    mcr p15, 0, r0, c6, c6, 0
    bl INITi_IsRunOnTwl
    bne @L02004b14
    ldr r0, =0x2000031
    mcr p15, 0, r0, c6, c1, 0
    ldr r0, =0x2f80025
    mcr p15, 0, r0, c6, c2, 0
    ldr r0, =0x8000035
    mcr p15, 0, r0, c6, c3, 0
    ldr r0, =0x2ffc01b
    mcr p15, 0, r0, c6, c7, 0
    mov r0, #0x4a
    mcr p15, 0, r0, c2, c0, 1
    mov r0, #0x4a
    mcr p15, 0, r0, c2, c0, 0
    mov r0, #0xa
    mcr p15, 0, r0, c3, c0, 0
    ldr r0, =0x5101011
    mcr p15, 0, r0, c5, c0, 3
    ldr r0, =0x15111011
    mcr p15, 0, r0, c5, c0, 2
    b @L02004b5c
@L02004b14:
    ldr r0, =0x2000031
    mcr p15, 0, r0, c6, c1, 0
    ldr r0, =0x27ff017
    mcr p15, 0, r0, c6, c2, 0
    ldr r0, =0x8000035
    mcr p15, 0, r0, c6, c3, 0
    ldr r0, =0x2fff017
    mcr p15, 0, r0, c6, c7, 0
    mov r0, #0x42
    mcr p15, 0, r0, c2, c0, 1
    mov r0, #0x42
    mcr p15, 0, r0, c2, c0, 0
    mov r0, #2
    mcr p15, 0, r0, c3, c0, 0
    ldr r0, =0x5101011
    mcr p15, 0, r0, c5, c0, 3
    ldr r0, =0x15111111
    mcr p15, 0, r0, c5, c0, 2
@L02004b5c:
    mrc p15, 0, r0, c1, c0, 0
    ldr r1, =0x5005
    orr r0, r0, r1
    mcr p15, 0, r0, c1, c0, 0
    mov r1, #0
    mcr p15, 0, r1, c7, c6, 0
    mcr p15, 0, r1, c7, c5, 0
    bx r12
}

asm void INITi_DoAutoload(void) {
    stmdb sp!, {lr}
    ldr r1, =BuildInfo
    ldr r0, [r1, #0x14]
    bl MIi_UncompressBackward
    ldr r0, =BuildInfo
    ldr r12, [r0]
    ldr r3, [r0, #4]
    ldr r1, [r0, #8]
@L02004bd4:
    cmp r12, r3
    bge @L02004c64
    stmdb sp!, {r3}
    ldr r0, [r12], #4
    ldr r2, [r12], #4
    stmdb sp!, {r0}
    bl INITi_Copy32
    stmfd sp!, {r0, r1}
    ldr r0, [r12], #4
    stmdb sp!, {r12}
    bl INITi_ShelterStaticInitializer
    ldmia sp!, {r12}
    ldmia sp!, {r0}
    mov r1, #0
    ldr r2, [r12], #4
    bl INITi_Fill32
    ldmfd sp!, {r1, r2}
    mov r3, #0x1000000
    cmp r2, r3
    movge r3, #0x2000000
    cmpge r3, r2
    bgt @L02004c5c
    ldr r3, =data_02fe0000
    cmp r2, r3
    addge r3, r3, #0x4000
    cmpge r3, r2
    bgt @L02004c5c
    bic r2, r2, #0x1f
@L02004c44:
    cmp r2, r0
    bge @L02004c5c
    mcr p15, 0, r2, c7, c14, 1
    mcr p15, 0, r2, c7, c5, 1
    add r2, r2, #0x20
    b @L02004c44
@L02004c5c:
    ldmia sp!, {r3}
    b @L02004bd4
@L02004c64:
    bl INITi_IsRunOnTwl
    bne @L02004d28
    ldr r1, =0x2ffe1cc
    ldr r0, [r1]
    cmp r0, #0
    beq @L02004d28
    ldr r1, =0x2004f7c
    ldr r0, [r1, #0xc]
    bl MIi_UncompressBackward
    ldr r0, =0x2004f7c
    ldr r12, [r0]
    ldr r3, [r0, #4]
    ldr r1, [r0, #8]
@L02004c98:
    cmp r12, r3
    bge @L02004d28
    stmdb sp!, {r3}
    ldr r0, [r12], #4
    ldr r2, [r12], #4
    stmdb sp!, {r0}
    bl INITi_Copy32
    stmfd sp!, {r0, r1}
    ldr r0, [r12], #4
    stmdb sp!, {r12}
    bl INITi_ShelterStaticInitializer
    ldmia sp!, {r12}
    ldmia sp!, {r0}
    mov r1, #0
    ldr r2, [r12], #4
    bl INITi_Fill32
    ldmfd sp!, {r1, r2}
    mov r3, #0x1000000
    cmp r2, r3
    movge r3, #0x2000000
    cmpge r3, r2
    bgt @L02004d20
    ldr r3, =data_02fe0000
    cmp r2, r3
    addge r3, r3, #0x4000
    cmpge r3, r2
    bgt @L02004d20
    bic r2, r2, #0x1f
@L02004d08:
    cmp r2, r0
    bge @L02004d20
    mcr p15, 0, r2, c7, c14, 1
    mcr p15, 0, r2, c7, c5, 1
    add r2, r2, #0x20
    b @L02004d08
@L02004d20:
    ldmia sp!, {r3}
    b @L02004c98
@L02004d28:
    mov r0, #0
    mcr p15, 0, r0, c7, c10, 4
    ldr r0, =BuildInfo
    ldr r1, =0x2004f7c
    ldmia sp!, {lr}
    b AutoloadCallback
}

asm void INITi_ShelterStaticInitializer(void) {
    cmp r0, #0
    bxeq lr
    ldr r1, =data_02fe0000
    add r1, r1, #0x4000
    sub r1, r1, #0x40
    sub r1, r1, #0x40
    ldr r2, =0x800
    sub r1, r1, r2
    add r1, r1, #4
@L02004d74:
    ldr r2, [r1]
    cmp r2, #0
    addne r1, r1, #4
    bne @L02004d74
@L02004d84:
    ldr r2, [r0], #4
    str r2, [r1], #4
    cmp r2, #0
    bne @L02004d84
    bx lr
}

asm void INITi_CallStaticInitializers(void) {
    stmdb sp!, {lr}
    ldr r1, =data_02fe0000
    add r1, r1, #0x4000
    sub r1, r1, #0x40
    sub r1, r1, #0x40
    ldr r2, =0x800
    sub r1, r1, r2
    add r1, r1, #4
@L02004dc0:
    ldr r0, [r1]
    cmp r0, #0
    beq @L02004de4
    stmdb sp!, {r1}
    blx r0
    ldmia sp!, {r1}
    mov r0, #0
    str r0, [r1], #4
    b @L02004dc0
@L02004de4:
    ldmia sp!, {lr}
    bx lr
}

asm void MIi_UncompressBackward(void) {
    cmp r0, #0
    beq @L02004ea4
    stmfd sp!, {r4, r5, r6, r7, r8}
    ldmdb r0, {r1, r2}
    add r2, r0, r2
    sub r3, r0, r1, lsr #24
    bic r1, r1, #0xff000000
    sub r1, r0, r1
    mov r4, r2
@L02004e18:
    cmp r3, r1
    ble @L02004e80
    ldrb r5, [r3, #-1]!
    mov r6, #8
@L02004e28:
    subs r6, r6, #1
    blt @L02004e18
    tst r5, #0x80
    bne @L02004e48
    ldrb r0, [r3, #-1]!
    ldrb r8, [r2, #-1]
    strb r0, [r2, #-1]!
    b @L02004e74
@L02004e48:
    ldrb r12, [r3, #-1]!
    ldrb r7, [r3, #-1]!
    orr r7, r7, r12, lsl #8
    bic r7, r7, #0xf000
    add r7, r7, #2
    add r12, r12, #0x20
@L02004e60:
    ldrb r0, [r2, r7]
    ldrb r8, [r2, #-1]
    strb r0, [r2, #-1]!
    subs r12, r12, #0x10
    bge @L02004e60
@L02004e74:
    cmp r3, r1
    mov r5, r5, lsl #1
    bgt @L02004e28
@L02004e80:
    mov r0, #0
    bic r3, r1, #0x1f
@L02004e88:
    mcr p15, 0, r0, c7, c10, 4
    mcr p15, 0, r3, c7, c5, 1
    mcr p15, 0, r3, c7, c14, 1
    add r3, r3, #0x20
    cmp r3, r4
    blt @L02004e88
    ldmfd sp!, {r4, r5, r6, r7, r8}
@L02004ea4:
    bx lr
}

asm void AutoloadCallback(void) {
    bx lr
}

asm void func_02004eac(void) {
    bx lr
}

asm void OSi_ReferSymbol(void) {
    bx lr
}

asm void INITi_IsRunOnTwl(void) {
    ldr r0, =0x4004000
    ldrb r0, [r0]
    and r0, r0, #3
    cmp r0, #1
    moveq r0, #1
    movne r0, #0
    bx lr
}

asm void INITi_Copy32(void) {
    stmfd sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11}
    bics r3, r2, #0x1f
    beq @L02004ef4
    add r3, r0, r3
@L02004ee4:
    ldmia r1!, {r4, r5, r6, r7, r8, r9, r10, r11}
    stmia r0!, {r4, r5, r6, r7, r8, r9, r10, r11}
    cmp r3, r0
    bgt @L02004ee4
@L02004ef4:
    tst r2, #0x10
    ldmneia r1!, {r4, r5, r6, r7}
    stmneia r0!, {r4, r5, r6, r7}
    tst r2, #8
    ldmneia r1!, {r4, r5}
    stmneia r0!, {r4, r5}
    tst r2, #4
    ldmneia r1!, {r4}
    stmneia r0!, {r4}
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11}
    bx lr
}

asm void INITi_Fill32(void) {
    stmfd sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11}
    mov r4, r1
    mov r5, r1
    mov r6, r1
    mov r7, r1
    mov r8, r1
    mov r9, r1
    mov r10, r1
    mov r11, r1
    bics r3, r2, #0x1f
    beq @L02004f5c
    add r3, r0, r3
@L02004f50:
    stmia r0!, {r4, r5, r6, r7, r8, r9, r10, r11}
    cmp r3, r0
    bgt @L02004f50
@L02004f5c:
    tst r2, #0x10
    stmneia r0!, {r4, r5, r6, r7}
    tst r2, #8
    stmneia r0!, {r4, r5}
    tst r2, #4
    stmneia r0!, {r4}
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, r9, r10, r11}
    bx lr
}

// TWL module parameters: the LTD autoload list, its end, the LTD autoload start, the end of
// the compressed LTD static area (all in TWL-only memory, so plain numbers), then the TWL
// code magic.
asm void data_02004f7c(void) {
    dcd 0x02479424
    dcd 0x02479434
    dcd 0x02400004
    dcd 0x0242afa0
    dcd 0xdec01463
    dcd 0x6314c0de
}

// Waits until the halfword at r0 equals r1, with a short delay between reads.
asm void func_02004f94(void) {
@L02004f94:
    ldrh r2, [r0]
    cmp r1, r2
    bxeq lr
    mov r3, #0x10
@L02004fa4:
    subs r3, r3, #1
    bne @L02004fa4
    b @L02004f94
}

// NITRO module parameters: the autoload list, its end, the autoload start, the static .bss
// start and end, the compressed static end (none), the SDK version ID and the NITRO code magic.
asm void BuildInfo(void) {
    dcd data_020925e0
    dcd data_02092600
    dcd data_0208d940
    dcd data_0208d940
    dcd 0x0214b1a0
    dcd 0
    dcd 0x05047531
    dcd 0xdec00621
    dcd 0x2106c0de
}
