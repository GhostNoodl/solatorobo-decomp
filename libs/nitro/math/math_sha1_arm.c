// MATHi_SHA1ProcessBlock: the TwlSDK's hand-written ARM SHA-1 block function. The four round
// constants sit just before it and are loaded pc-relatively, so they are emitted as their own
// force-active asm block (listed as data in symbols.txt).

#pragma force_active on

void MATHi_SHA1K(void);
void MATHi_SHA1ProcessBlock(void);

asm void MATHi_SHA1K(void) {
    dcd 0x5a827999
    dcd 0x6ed9eba1
    dcd 0x8f1bbcdc
    dcd 0xca62c1d6
}

asm void MATHi_SHA1ProcessBlock(void) {
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    mov r11, r0
    sub sp, sp, #0x40
    mov r12, sp
    mvn r3, #0xff00
    add r8, r11, #0x14
    mov r1, r12
    ldmia r8!, {r4, r5, r6, r7}
    mov r9, #0x10
@L020160c0:
    eor r2, r4, r4, ror #16
    and r2, r3, r2, lsr #8
    eor r4, r2, r4, ror #8
    eor r2, r5, r5, ror #16
    and r2, r3, r2, lsr #8
    eor r5, r2, r5, ror #8
    eor r2, r6, r6, ror #16
    and r2, r3, r2, lsr #8
    eor r6, r2, r6, ror #8
    eor r2, r7, r7, ror #16
    and r2, r3, r2, lsr #8
    eor r7, r2, r7, ror #8
    stmia r1!, {r4, r5, r6, r7}
    subs r9, r9, #4
    ldmneia r8!, {r4, r5, r6, r7}
    bne @L020160c0
    ldmia r11, {r4, r5, r6, r7, r8}
    ldr r12, [pc, #-0x80]
    mov r9, #0
@L0201610c:
    and r10, r5, r6
    mvn lr, r5
    and lr, lr, r7
    orr r10, r10, lr
    add r10, r10, r12
    and lr, r9, #0xf
    ldr lr, [sp, lr, lsl #2]
    add r10, r10, r8
    add r10, r10, lr
    add r10, r10, r4, ror #27
    mov r8, r7
    mov r7, r6
    mov r6, r5, ror #2
    mov r5, r4
    mov r4, r10
    add r9, r9, #1
    cmp r9, #0x10
    bne @L0201610c
@L02016154:
    and r10, r5, r6
    mvn lr, r5
    and lr, lr, r7
    orr r10, r10, lr
    add r10, r10, r12
    sub r2, r9, #0x10
    and r2, r2, #0xf
    sub lr, r9, #0xe
    and lr, lr, #0xf
    ldr r3, [sp, r2, lsl #2]
    ldr r1, [sp, lr, lsl #2]
    sub lr, r9, #8
    eor r3, r3, r1
    and lr, lr, #0xf
    ldr r1, [sp, lr, lsl #2]
    sub r2, r9, #3
    eor r3, r3, r1
    and r2, r2, #0xf
    ldr r1, [sp, r2, lsl #2]
    and r2, r9, #0xf
    eor r3, r3, r1
    mov r3, r3, ror #0x1f
    str r3, [sp, r2, lsl #2]
    and lr, r9, #0xf
    ldr lr, [sp, lr, lsl #2]
    add r10, r10, r8
    add r10, r10, lr
    add r10, r10, r4, ror #27
    mov r8, r7
    mov r7, r6
    mov r6, r5, ror #2
    mov r5, r4
    mov r4, r10
    add r9, r9, #1
    cmp r9, #0x14
    bne @L02016154
    ldr r12, [pc, #-0x15c]
@L020161e8:
    eor r10, r5, r6
    eor r10, r10, r7
    add r10, r10, r12
    sub r2, r9, #0x10
    and r2, r2, #0xf
    sub lr, r9, #0xe
    and lr, lr, #0xf
    ldr r3, [sp, r2, lsl #2]
    ldr r1, [sp, lr, lsl #2]
    sub lr, r9, #8
    eor r3, r3, r1
    and lr, lr, #0xf
    ldr r1, [sp, lr, lsl #2]
    sub r2, r9, #3
    eor r3, r3, r1
    and r2, r2, #0xf
    ldr r1, [sp, r2, lsl #2]
    and r2, r9, #0xf
    eor r3, r3, r1
    mov r3, r3, ror #0x1f
    str r3, [sp, r2, lsl #2]
    and lr, r9, #0xf
    ldr lr, [sp, lr, lsl #2]
    add r10, r10, r8
    add r10, r10, lr
    add r10, r10, r4, ror #27
    mov r8, r7
    mov r7, r6
    mov r6, r5, ror #2
    mov r5, r4
    mov r4, r10
    add r9, r9, #1
    cmp r9, #0x28
    bne @L020161e8
    ldr r12, [pc, #-0x1e4]
@L02016274:
    and r10, r5, r6
    and lr, r5, r7
    orr r10, r10, lr
    and lr, r6, r7
    orr r10, r10, lr
    add r10, r10, r12
    sub r2, r9, #0x10
    and r2, r2, #0xf
    sub lr, r9, #0xe
    and lr, lr, #0xf
    ldr r3, [sp, r2, lsl #2]
    ldr r1, [sp, lr, lsl #2]
    sub lr, r9, #8
    eor r3, r3, r1
    and lr, lr, #0xf
    ldr r1, [sp, lr, lsl #2]
    sub r2, r9, #3
    eor r3, r3, r1
    and r2, r2, #0xf
    ldr r1, [sp, r2, lsl #2]
    and r2, r9, #0xf
    eor r3, r3, r1
    mov r3, r3, ror #0x1f
    str r3, [sp, r2, lsl #2]
    and lr, r9, #0xf
    ldr lr, [sp, lr, lsl #2]
    add r10, r10, r8
    add r10, r10, lr
    add r10, r10, r4, ror #27
    mov r8, r7
    mov r7, r6
    mov r6, r5, ror #2
    mov r5, r4
    mov r4, r10
    add r9, r9, #1
    cmp r9, #0x3c
    bne @L02016274
    ldr r12, [pc, #-0x278]
@L0201630c:
    eor r10, r5, r6
    eor r10, r10, r7
    add r10, r10, r12
    sub r2, r9, #0x10
    and r2, r2, #0xf
    sub lr, r9, #0xe
    and lr, lr, #0xf
    ldr r3, [sp, r2, lsl #2]
    ldr r1, [sp, lr, lsl #2]
    sub lr, r9, #8
    eor r3, r3, r1
    and lr, lr, #0xf
    ldr r1, [sp, lr, lsl #2]
    sub r2, r9, #3
    eor r3, r3, r1
    and r2, r2, #0xf
    ldr r1, [sp, r2, lsl #2]
    and r2, r9, #0xf
    eor r3, r3, r1
    mov r3, r3, ror #0x1f
    str r3, [sp, r2, lsl #2]
    and lr, r9, #0xf
    ldr lr, [sp, lr, lsl #2]
    add r10, r10, r8
    add r10, r10, lr
    add r10, r10, r4, ror #27
    mov r8, r7
    mov r7, r6
    mov r6, r5, ror #2
    mov r5, r4
    mov r4, r10
    add r9, r9, #1
    cmp r9, #0x50
    bne @L0201630c
    ldmia r11, {r1, r2, r3, r9, r10}
    add r1, r1, r4
    add r2, r2, r5
    add r3, r3, r6
    add r9, r9, r7
    add r10, r10, r8
    stmia r11, {r1, r2, r3, r9, r10}
    add sp, sp, #0x40
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, pc}
}

