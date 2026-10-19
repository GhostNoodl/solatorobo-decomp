// NitroSDK OS IRQ handlers (os_irqHandler.c, ITCM part) and the ITCM-resident ARM9 clock switch
// called by func_0201bbfc; hand-written assembly.

#pragma force_active on

extern char CP_SaveContext[];
extern char CPi_RestoreContext[];
extern char OSi_ThreadInfo[];
extern char data_02fe0020[];
extern char data_02fe01e0[];
void OS_IrqHandler(void);
void OS_IrqHandler_ThreadSwitch(void);
void func_01ff82a8(void);

asm void OS_IrqHandler(void) {
    stmdb sp!, {lr}
    mov r12, #0x4000000
    add r12, r12, #0x210
    ldr r1, [r12, #-8]
    cmp r1, #0
    ldmeqia sp!, {pc}
    ldmia r12, {r1, r2}
    ands r1, r1, r2
    ldmeqia sp!, {pc}
    mov r3, #0x80000000
@L01ff8118:
    clz r0, r1
    bics r1, r1, r3, lsr r0
    bne @L01ff8118
    mov r1, r3, lsr r0
    str r1, [r12, #4]
    rsbs r0, r0, #0x1f
    ldr r1, =data_02fe0020
    ldr r0, [r1, r0, lsl #2]
    ldr lr, =OS_IrqHandler_ThreadSwitch
    bx r0
}

asm void OS_IrqHandler_ThreadSwitch(void) {
    ldr r12, =data_02fe01e0
    mov r3, #0
    ldr r12, [r12]
    mov r2, #1
    cmp r12, #0
    beq @L01ff8198
@L01ff8160:
    str r2, [r12, #0x64]
    str r3, [r12, #0x78]
    str r3, [r12, #0x7c]
    ldr r0, [r12, #0x80]
    str r3, [r12, #0x80]
    mov r12, r0
    cmp r12, #0
    bne @L01ff8160
    ldr r12, =data_02fe01e0
    str r3, [r12]
    str r3, [r12, #4]
    ldr r12, =OSi_ThreadInfo
    mov r1, #1
    strh r1, [r12]
@L01ff8198:
    ldr r12, =OSi_ThreadInfo
    ldrh r1, [r12]
    cmp r1, #0
    ldreq pc, [sp], #4
    mov r1, #0
    strh r1, [r12]
    mov r3, #0xd2
    msr cpsr_c, r3
    add r2, r12, #8
    ldr r1, [r2]
@L01ff81c0:
    cmp r1, #0
    ldrneh r0, [r1, #0x64]
    cmpne r0, #1
    ldrne r1, [r1, #0x68]
    bne @L01ff81c0
    cmp r1, #0
    bne @L01ff81e8
@L01ff81dc:
    mov r3, #0x92
    msr cpsr_c, r3
    ldr pc, [sp], #4
@L01ff81e8:
    ldr r0, [r12, #4]
    cmp r1, r0
    beq @L01ff81dc
    ldr r3, [r12, #0xc]
    cmp r3, #0
    beq @L01ff8210
    stmfd sp!, {r0, r1, r12}
    mov lr, pc
    bx r3
    ldmfd sp!, {r0, r1, r12}
@L01ff8210:
    str r1, [r12, #4]
    mrs r2, spsr
    str r2, [r0, #0]!
    stmfd sp!, {r0, r1}
    add r0, r0, #0
    add r0, r0, #0x48
    ldr r1, =CP_SaveContext
    blx r1
    ldmfd sp!, {r0, r1}
    ldmib sp!, {r2, r3}
    stmib r0!, {r2, r3}
    ldmib sp!, {r2, r3, r12, lr}
    stmib r0, {r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr} ^
    add r0, r0, #0x34
    stmib r0!, {lr}
    mov r3, #0xd3
    msr cpsr_c, r3
    stmib r0!, {sp}
    stmdb sp!, {r1}
    add r0, r1, #0
    add r0, r0, #0x48
    ldr r1, =CPi_RestoreContext
    blx r1
    ldmia sp!, {r1}
    ldr sp, [r1, #0x44]
    mov r3, #0xd2
    msr cpsr_c, r3
    ldr r2, [r1, #0]!
    msr spsr_fc, r2
    ldr lr, [r1, #0x40]
    ldmib r1, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr} ^
    mov r0, r0
    stmda sp!, {r0, r1, r2, r3, r12, lr}
    ldmia sp!, {pc}
}

asm void func_01ff82a8(void) {
    ldr r2, =0x4004004
    ldrh r1, [r2]
    bic r1, r1, #1
    orr r1, r0, r1
    strh r1, [r2]
    cmp r0, #0
    moveq r0, #0xa
    movne r0, #0x14
@L01ff82c8:
    subs r0, r0, #4
    bhs @L01ff82c8
    bx lr
}

