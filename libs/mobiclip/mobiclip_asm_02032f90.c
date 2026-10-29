// Actimagine Mobiclip video decoder, hand-written ARM assembly (YUV to RGB555 conversion of two
// rows at a time through the lookup table at the end of the context).

#pragma force_active on

void func_02032f90(void *conv);

asm void func_02032f90(void *conv) {
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    ldr r8, [r0, #0xc]
    ldr r9, [r0, #0x10]
    ldr r10, [r0, #0x14]
    ldr r3, [r0, #0x18]
    mov r4, #0x100
    rsb r5, r9, r4, lsl #0x1
    sub r6, r4, r9, lsr #0x1
    sub r7, r8, r9
    mov r7, r7, lsl #0x1
    stmfd sp!, {r5, r6, r7, r8, r9, r10}
    ldr r1, [r0, #0x4]
    ldr r2, [r0, #0x8]
    ldr r0, [r0]
    add r3, r3, #0x100
    add lr, r2, r8
@L02032fd0:
    str r10, [sp, #-4]!
    ldr r10, [sp, #0x14]
@L02032fd8:
    ldrb r5, [r1], #0x80
    ldrb r6, [r1], #-0x7f
    ldrb r4, [r0], #0x1
    sub r5, r5, #0x80
    sub r6, r6, #0x80
    add r7, r3, r6
    sub r6, r5, r6
    add r6, r6, r3
    sub r5, r6, r5, lsl #0x1
    ldrb r8, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #0xff
    add r8, r11, r8, lsl #0x5
    add r8, r8, r12, lsl #0xa
    orr r8, r8, #0x8000
    sub r4, r4, #0x4
    ldrb r9, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #0x1
    add r8, r8, r9, lsl #0x15
    add r8, r8, r11, lsl #0x10
    add r8, r8, r12, lsl #0x1a
    orr r8, r8, #0x80000000
    str r8, [r2], #0x4
    sub r4, r4, #0x4
    ldrb r8, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #-0xff
    add r8, r11, r8, lsl #0x5
    add r8, r8, r12, lsl #0xa
    orr r8, r8, #0x8000
    ldrb r9, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    add r8, r8, r9, lsl #0x15
    add r8, r8, r11, lsl #0x10
    add r8, r8, r12, lsl #0x1a
    orr r8, r8, #0x80000000
    str r8, [lr], #0x4
    ldrb r5, [r1], #0x80
    ldrb r6, [r1], #-0x7f
    ldrb r4, [r0], #0x1
    sub r5, r5, #0x80
    sub r6, r6, #0x80
    add r7, r3, r6
    sub r6, r5, r6
    add r6, r6, r3
    sub r5, r6, r5, lsl #0x1
    ldrb r8, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #0xff
    add r8, r11, r8, lsl #0x5
    add r8, r8, r12, lsl #0xa
    orr r8, r8, #0x8000
    sub r4, r4, #0x4
    ldrb r9, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #0x1
    add r8, r8, r9, lsl #0x15
    add r8, r8, r11, lsl #0x10
    add r8, r8, r12, lsl #0x1a
    orr r8, r8, #0x80000000
    str r8, [r2], #0x4
    sub r4, r4, #0x4
    ldrb r8, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #-0xff
    add r8, r11, r8, lsl #0x5
    add r8, r8, r12, lsl #0xa
    orr r8, r8, #0x8000
    ldrb r9, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    add r8, r8, r9, lsl #0x15
    add r8, r8, r11, lsl #0x10
    add r8, r8, r12, lsl #0x1a
    orr r8, r8, #0x80000000
    str r8, [lr], #0x4
    ldrb r5, [r1], #0x80
    ldrb r6, [r1], #-0x7f
    ldrb r4, [r0], #0x1
    sub r5, r5, #0x80
    sub r6, r6, #0x80
    add r7, r3, r6
    sub r6, r5, r6
    add r6, r6, r3
    sub r5, r6, r5, lsl #0x1
    ldrb r8, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #0xff
    add r8, r11, r8, lsl #0x5
    add r8, r8, r12, lsl #0xa
    orr r8, r8, #0x8000
    sub r4, r4, #0x4
    ldrb r9, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #0x1
    add r8, r8, r9, lsl #0x15
    add r8, r8, r11, lsl #0x10
    add r8, r8, r12, lsl #0x1a
    orr r8, r8, #0x80000000
    str r8, [r2], #0x4
    sub r4, r4, #0x4
    ldrb r8, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #-0xff
    add r8, r11, r8, lsl #0x5
    add r8, r8, r12, lsl #0xa
    orr r8, r8, #0x8000
    ldrb r9, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    add r8, r8, r9, lsl #0x15
    add r8, r8, r11, lsl #0x10
    add r8, r8, r12, lsl #0x1a
    orr r8, r8, #0x80000000
    str r8, [lr], #0x4
    ldrb r5, [r1], #0x80
    ldrb r6, [r1], #-0x7f
    ldrb r4, [r0], #0x1
    sub r5, r5, #0x80
    sub r6, r6, #0x80
    add r7, r3, r6
    sub r6, r5, r6
    add r6, r6, r3
    sub r5, r6, r5, lsl #0x1
    ldrb r8, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #0xff
    add r8, r11, r8, lsl #0x5
    add r8, r8, r12, lsl #0xa
    orr r8, r8, #0x8000
    sub r4, r4, #0x4
    ldrb r9, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #0x1
    add r8, r8, r9, lsl #0x15
    add r8, r8, r11, lsl #0x10
    add r8, r8, r12, lsl #0x1a
    orr r8, r8, #0x80000000
    str r8, [r2], #0x4
    sub r4, r4, #0x4
    ldrb r8, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #-0xff
    add r8, r11, r8, lsl #0x5
    add r8, r8, r12, lsl #0xa
    orr r8, r8, #0x8000
    ldrb r9, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    add r8, r8, r9, lsl #0x15
    add r8, r8, r11, lsl #0x10
    add r8, r8, r12, lsl #0x1a
    orr r8, r8, #0x80000000
    str r8, [lr], #0x4
    ldrb r5, [r1], #0x80
    ldrb r6, [r1], #-0x7f
    ldrb r4, [r0], #0x1
    sub r5, r5, #0x80
    sub r6, r6, #0x80
    add r7, r3, r6
    sub r6, r5, r6
    add r6, r6, r3
    sub r5, r6, r5, lsl #0x1
    ldrb r8, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #0xff
    add r8, r11, r8, lsl #0x5
    add r8, r8, r12, lsl #0xa
    orr r8, r8, #0x8000
    sub r4, r4, #0x4
    ldrb r9, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #0x1
    add r8, r8, r9, lsl #0x15
    add r8, r8, r11, lsl #0x10
    add r8, r8, r12, lsl #0x1a
    orr r8, r8, #0x80000000
    str r8, [r2], #0x4
    sub r4, r4, #0x4
    ldrb r8, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #-0xff
    add r8, r11, r8, lsl #0x5
    add r8, r8, r12, lsl #0xa
    orr r8, r8, #0x8000
    ldrb r9, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    add r8, r8, r9, lsl #0x15
    add r8, r8, r11, lsl #0x10
    add r8, r8, r12, lsl #0x1a
    orr r8, r8, #0x80000000
    str r8, [lr], #0x4
    ldrb r5, [r1], #0x80
    ldrb r6, [r1], #-0x7f
    ldrb r4, [r0], #0x1
    sub r5, r5, #0x80
    sub r6, r6, #0x80
    add r7, r3, r6
    sub r6, r5, r6
    add r6, r6, r3
    sub r5, r6, r5, lsl #0x1
    ldrb r8, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #0xff
    add r8, r11, r8, lsl #0x5
    add r8, r8, r12, lsl #0xa
    orr r8, r8, #0x8000
    sub r4, r4, #0x4
    ldrb r9, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #0x1
    add r8, r8, r9, lsl #0x15
    add r8, r8, r11, lsl #0x10
    add r8, r8, r12, lsl #0x1a
    orr r8, r8, #0x80000000
    str r8, [r2], #0x4
    sub r4, r4, #0x4
    ldrb r8, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #-0xff
    add r8, r11, r8, lsl #0x5
    add r8, r8, r12, lsl #0xa
    orr r8, r8, #0x8000
    ldrb r9, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    add r8, r8, r9, lsl #0x15
    add r8, r8, r11, lsl #0x10
    add r8, r8, r12, lsl #0x1a
    orr r8, r8, #0x80000000
    str r8, [lr], #0x4
    ldrb r5, [r1], #0x80
    ldrb r6, [r1], #-0x7f
    ldrb r4, [r0], #0x1
    sub r5, r5, #0x80
    sub r6, r6, #0x80
    add r7, r3, r6
    sub r6, r5, r6
    add r6, r6, r3
    sub r5, r6, r5, lsl #0x1
    ldrb r8, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #0xff
    add r8, r11, r8, lsl #0x5
    add r8, r8, r12, lsl #0xa
    orr r8, r8, #0x8000
    sub r4, r4, #0x4
    ldrb r9, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #0x1
    add r8, r8, r9, lsl #0x15
    add r8, r8, r11, lsl #0x10
    add r8, r8, r12, lsl #0x1a
    orr r8, r8, #0x80000000
    str r8, [r2], #0x4
    sub r4, r4, #0x4
    ldrb r8, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #-0xff
    add r8, r11, r8, lsl #0x5
    add r8, r8, r12, lsl #0xa
    orr r8, r8, #0x8000
    ldrb r9, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    add r8, r8, r9, lsl #0x15
    add r8, r8, r11, lsl #0x10
    add r8, r8, r12, lsl #0x1a
    orr r8, r8, #0x80000000
    str r8, [lr], #0x4
    ldrb r5, [r1], #0x80
    ldrb r6, [r1], #-0x7f
    ldrb r4, [r0], #0x1
    sub r5, r5, #0x80
    sub r6, r6, #0x80
    add r7, r3, r6
    sub r6, r5, r6
    add r6, r6, r3
    sub r5, r6, r5, lsl #0x1
    ldrb r8, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #0xff
    add r8, r11, r8, lsl #0x5
    add r8, r8, r12, lsl #0xa
    orr r8, r8, #0x8000
    sub r4, r4, #0x4
    ldrb r9, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #0x1
    add r8, r8, r9, lsl #0x15
    add r8, r8, r11, lsl #0x10
    add r8, r8, r12, lsl #0x1a
    orr r8, r8, #0x80000000
    str r8, [r2], #0x4
    sub r4, r4, #0x4
    ldrb r8, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    ldrb r4, [r0], #-0xff
    add r8, r11, r8, lsl #0x5
    add r8, r8, r12, lsl #0xa
    orr r8, r8, #0x8000
    ldrb r9, [r7, r4]
    ldrb r11, [r6, r4]
    ldrb r12, [r5, r4]
    add r8, r8, r9, lsl #0x15
    add r8, r8, r11, lsl #0x10
    add r8, r8, r12, lsl #0x1a
    orr r8, r8, #0x80000000
    str r8, [lr], #0x4
    subs r10, r10, #0x10
    bgt @L02032fd8
    ldr r10, [sp], #4
    ldr r5, [sp]
    ldr r6, [sp, #0x4]
    ldr r7, [sp, #0x8]
    add r0, r0, r5
    add r1, r1, r6
    add r2, r2, r7
    add lr, lr, r7
    subs r10, r10, #0x2
    bgt @L02032fd0
    add sp, sp, #0x18
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, pc}
}
