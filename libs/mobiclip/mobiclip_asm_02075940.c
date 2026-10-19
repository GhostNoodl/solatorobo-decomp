// Actimagine Mobiclip video decoder, hand-written ARM assembly (deblocking filters; func_02075a78
// and func_02075c74 are only reached by relative branches, so dsd's analysis did not find them).

#pragma force_active on

void func_02075940(void);
void func_02075a78(void);
void func_02075b6c(void);
void func_02075c74(void);

asm void func_02075940(void) {
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    ldr lr, [r0, #0x10]
    ldr r12, [r0, #0x14]
    ldr r1, [r0, #4]
    ldr r11, [r0]
    ldr r3, [r0, #0xc]
    ldr r2, [r11], #4
    ldr r10, [r0, #8]
    str r3, [sp, #-4]!
    str r2, [r1], #4
    sub r10, r10, #8
@L0207596c:
    str r10, [sp, #-4]!
    ldrb r2, [r11], #1
    ldrb r3, [r11], #1
    ldrb r4, [r11], #1
    ldrb r5, [r11], #1
    ldrb r6, [r11], #1
    ldrb r7, [r11], #1
    ldrb r8, [r11], #1
    and r9, lr, #0xff
    subs r10, r5, r6
    rsblt r10, r10, #0
    cmp r10, r9
    bge @L02075a14
    subs r10, r4, r5
    rsblt r10, r10, #0
    cmp r10, lr, lsr #8
    bge @L02075a14
    subs r10, r7, r6
    rsblt r10, r10, #0
    cmp r10, lr, lsr #8
    bge @L02075a14
    add r10, r5, r6
    add r10, r10, #1
    subs r9, r3, r5
    sub r5, r4, r7
    add r5, r5, #4
    mov r5, r5, asr #3
    rsblt r9, r9, #0
    cmp r9, lr, lsr #8
    addlt r4, r3, r10, asr #1
    addlt r4, r4, #1
    movlt r4, r4, asr #1
    subs r9, r8, r6
    rsblt r9, r9, #0
    cmp r9, lr, lsr #8
    addlt r7, r8, r10, asr #1
    addlt r7, r7, #1
    movlt r7, r7, asr #1
    rsb r6, r5, r10, asr #1
    ldrb r6, [r12, r6]
    add r5, r5, r10, asr #1
    ldrb r5, [r12, r5]
@L02075a14:
    ldrb r9, [r11], #1
    orr r2, r2, r3, lsl #8
    orr r2, r2, r4, lsl #16
    orr r2, r2, r5, lsl #24
    orr r6, r6, r7, lsl #8
    orr r6, r6, r8, lsl #16
    orr r6, r6, r9, lsl #24
    stmia r1!, {r2, r6}
    ldr r10, [sp], #4
    subs r10, r10, #8
    bne @L0207596c
    ldr r3, [sp], #4
    ldr r2, [r11], #4
    ldr r10, [r0, #8]
    add r11, r11, #0x100
    str r2, [r1], #0x104
    sub r11, r11, r10
    sub r1, r1, r10
    subs r3, r3, #1
    ldrne r2, [r11], #4
    strne r3, [sp, #-4]!
    subne r10, r10, #8
    strne r2, [r1], #4
    bne @L0207596c
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, pc}
}

asm void func_02075a78(void) {
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    ldr r1, [r0, #8]
    ldr r2, [r0, #0xc]
    ldr r3, [r0, #0x10]
    ldr r4, [r0, #0x14]
    ldr r0, [r0, #4]
    mov r5, r1
    add r0, r0, #0x800
    subs r2, r2, #8
@L02075a9c:
    ldrb r7, [r0, #-0x100]
    ldrb r8, [r0]
    ldrb r6, [r0, #-0x200]
    ldrb r9, [r0, #0x100]
    and lr, r3, #0xff
    subs r10, r7, r8
    rsblt r10, r10, #0
    cmp r10, lr
    bge @L02075b48
    subs r10, r6, r7
    rsblt r10, r10, #0
    cmp r10, r3, lsr #8
    bge @L02075b48
    subs r10, r8, r9
    rsblt r10, r10, #0
    cmp r10, r3, lsr #8
    bge @L02075b48
    ldrb r12, [r0, #-0x300]
    ldrb lr, [r0, #0x200]
    sub r6, r6, r9
    add r9, r7, r8
    add r6, r6, #4
    add r9, r9, #1
    mov r9, r9, asr #1
    adds r10, r9, r6, asr #3
    subs r11, r9, r6, asr #3
    ldrb r10, [r4, r10]
    ldrb r11, [r4, r11]
    add r9, r9, #1
    subs r7, r12, r7
    rsblt r7, r7, #0
    cmp r7, r3, lsr #8
    addlt r12, r12, r9
    movlt r12, r12, asr #1
    strltb r12, [r0, #-0x200]
    subs r8, lr, r8
    rsblt r8, r8, #0
    cmp r8, r3, lsr #8
    addlt lr, lr, r9
    movlt lr, lr, asr #1
    strltb lr, [r0, #0x100]
    strb r10, [r0, #-0x100]
    strb r11, [r0]
@L02075b48:
    add r0, r0, #1
    subs r5, r5, #1
    bne @L02075a9c
    add r0, r0, #0x800
    sub r0, r0, r1
    mov r5, r1
    subs r2, r2, #8
    bne @L02075a9c
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, pc}
}

asm void func_02075b6c(void) {
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    ldr lr, [r0, #0x10]
    ldr r12, [r0, #0x14]
    ldr r1, [r0, #4]
    ldr r11, [r0]
    ldr r3, [r0, #0xc]
    ldr r2, [r11], #4
    ldr r10, [r0, #8]
    str r3, [sp, #-4]!
    str r2, [r1], #4
    sub r10, r10, #8
@L02075b98:
    str r10, [sp, #-4]!
    ldrb r2, [r11], #1
    ldrb r3, [r11], #1
    ldrb r4, [r11], #1
    ldrb r5, [r11], #1
    ldrb r6, [r11], #1
    ldrb r7, [r11], #1
    ldrb r8, [r11], #1
    and r9, lr, #0xff
    subs r10, r5, r6
    rsblt r10, r10, #0
    cmp r10, r9
    bge @L02075c10
    subs r10, r4, r5
    rsblt r10, r10, #0
    cmp r10, lr, lsr #8
    bge @L02075c10
    subs r10, r7, r6
    rsblt r10, r10, #0
    cmp r10, lr, lsr #8
    bge @L02075c10
    add r10, r5, r6
    add r10, r10, #1
    sub r9, r4, r7
    add r9, r9, #4
    mov r9, r9, asr #3
    add r5, r9, r10, asr #1
    ldrb r5, [r12, r5]
    rsb r6, r9, r10, asr #1
    ldrb r6, [r12, r6]
@L02075c10:
    ldrb r9, [r11], #1
    orr r2, r2, r3, lsl #8
    orr r2, r2, r4, lsl #16
    orr r2, r2, r5, lsl #24
    orr r6, r6, r7, lsl #8
    orr r6, r6, r8, lsl #16
    orr r6, r6, r9, lsl #24
    stmia r1!, {r2, r6}
    ldr r10, [sp], #4
    subs r10, r10, #8
    bne @L02075b98
    ldr r3, [sp], #4
    ldr r2, [r11], #4
    ldr r10, [r0, #8]
    add r11, r11, #0x100
    str r2, [r1], #0x104
    sub r11, r11, r10
    sub r1, r1, r10
    subs r3, r3, #1
    ldrne r2, [r11], #4
    strne r3, [sp, #-4]!
    subne r10, r10, #8
    strne r2, [r1], #4
    bne @L02075b98
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, pc}
}

asm void func_02075c74(void) {
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    ldr r1, [r0, #8]
    ldr r2, [r0, #0xc]
    ldr r3, [r0, #0x10]
    ldr r4, [r0, #0x14]
    ldr r0, [r0, #4]
    mov r5, r1
    add r0, r0, #0x800
    subs r2, r2, #8
@L02075c98:
    ldrb r7, [r0, #-0x100]
    ldrb r8, [r0]
    ldrb r6, [r0, #-0x200]
    ldrb r9, [r0, #0x100]
    and lr, r3, #0xff
    subs r10, r7, r8
    rsblt r10, r10, #0
    cmp r10, lr
    bge @L02075d28
    subs r10, r6, r7
    rsblt r10, r10, #0
    cmp r10, r3, lsr #8
    bge @L02075d28
    subs r10, r8, r9
    rsblt r10, r10, #0
    cmp r10, r3, lsr #8
    bge @L02075d28
    sub r6, r6, r9
    add r9, r7, r8
    add r6, r6, #4
    add r9, r9, #1
    mov r9, r9, asr #1
    adds r10, r9, r6, asr #3
    ldrb r10, [r4, r10]
    subs r11, r9, r6, asr #3
    ldrb r11, [r4, r11]
    subs r5, r5, #1
    strb r10, [r0, #-0x100]
    strb r11, [r0], #1
    bne @L02075c98
    add r0, r0, #0x800
    sub r0, r0, r1
    mov r5, r1
    subs r2, r2, #8
    bne @L02075c98
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, pc}
@L02075d28:
    add r0, r0, #1
    subs r5, r5, #1
    bne @L02075c98
    add r0, r0, #0x800
    sub r0, r0, r1
    mov r5, r1
    subs r2, r2, #8
    bne @L02075c98
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, pc}
}

