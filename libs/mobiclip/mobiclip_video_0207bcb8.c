// Actimagine Mobiclip video decoder, hand-written ARM assembly. func_0203465c (mobiclip_mem.cpp)
// copies these 0x659c bytes to fast memory (or runs them in place) and the player calls the
// start as its decode function, so the code is position-independent: no absolute addresses,
// every table is reached with `add/sub rX, pc, #imm` and most dispatch goes through tables of
// offsets from the table's own address (`ldr rT, [rB, rI, lsl #2]; add pc, rT, rB`).
// The jump-table words are commented with the label they lead to; pc-relative operands stay
// numeric (the MWCC assembler has no label arithmetic), commented with the label they resolve to.
// The code/data split comes from a flow analysis, not from any symbol information.
// Generated with tools/asm2mw/asmblob.py main data_0207bcb8:0207bcb8:02082254:code; its --labels
// output is the .D_/.L_ labels in symbols.txt that give the delinked target the same $d/$a layout.

#pragma force_active on

void data_0207bcb8(void);

asm void data_0207bcb8(void) {
    b @L0207d3a8
    dcd 0x00000100
    dcd 0x0000009e
@L0207bcc4:
    dcd 0x000049e8 // @L020806ac - @L0207bcc4
    dcd 0x00004a94 // @L02080758 - @L0207bcc4
    dcd 0x00004c20 // @L020808e4 - @L0207bcc4
    dcd 0x00004d60 // @L02080a24 - @L0207bcc4
    dcd 0x00004f74 // @L02080c38 - @L0207bcc4
    dcd 0x000050b4 // @L02080d78 - @L0207bcc4
    dcd 0x000052b8 // @L02080f7c - @L0207bcc4
    dcd 0x000053e8 // @L020810ac - @L0207bcc4
    dcd 0x00004a04 // @L020806c8 - @L0207bcc4
    dcd 0x00004aec // @L020807b0 - @L0207bcc4
    dcd 0x00004c64 // @L02080928 - @L0207bcc4
    dcd 0x00004ddc // @L02080aa0 - @L0207bcc4
    dcd 0x00004fb8 // @L02080c7c - @L0207bcc4
    dcd 0x0000512c // @L02080df0 - @L0207bcc4
    dcd 0x000052f8 // @L02080fbc - @L0207bcc4
    dcd 0x00005444 // @L02081108 - @L0207bcc4
@L0207bd04:
    dcd 0x00005540 // @L02081204 - @L0207bcc4
    dcd 0x000055c4 // @L02081288 - @L0207bcc4
    dcd 0x000056cc // @L02081390 - @L0207bcc4
    dcd 0x000057a8 // @L0208146c - @L0207bcc4
    dcd 0x000058f8 // @L020815bc - @L0207bcc4
    dcd 0x000059cc // @L02081690 - @L0207bcc4
    dcd 0x00005b0c // @L020817d0 - @L0207bcc4
    dcd 0x00005bd8 // @L0208189c - @L0207bcc4
    dcd 0x0000555c // @L02081220 - @L0207bcc4
    dcd 0x00005604 // @L020812c8 - @L0207bcc4
    dcd 0x00005700 // @L020813c4 - @L0207bcc4
    dcd 0x000057fc // @L020814c0 - @L0207bcc4
    dcd 0x00005928 // @L020815ec - @L0207bcc4
    dcd 0x00005a1c // @L020816e0 - @L0207bcc4
    dcd 0x00005b3c // @L02081800 - @L0207bcc4
    dcd 0x00005c1c // @L020818e0 - @L0207bcc4
@L0207bd44:
    stmfd sp!, {r4, r5, r6, r11, r12, lr}
    bl @L0207dd30
    mov r5, r6
    bl @L0207dd30
    add r9, r0, #0x3bc
    ldmia r9, {r7, r8}
    add r5, r5, r7
    add r6, r6, r8
@L0207bd64:
    stmia r4, {r5, r6}
    add r7, r5, r11, lsl #1
    and r7, r7, #7
    and r8, r6, #1
    add r7, r7, r8, lsl #3
    stmfd sp!, {r0, r1, r2, r3}
    ldr r2, [sp, #0x14]
    ldr r1, [r0, #0xc]
    add r0, r0, r2
    ldr r0, [r0, #0xc]
    mov r8, r6, asr #1
    add r0, r0, r11
    add r0, r0, r8, lsl #8
    add r0, r0, r5, asr #1
    add r1, r1, r11
    ldr r2, [sp, #0x18]
    sub r3, pc, #0xe8 // @L0207bcc4
    add lr, pc, #4 // @L0207bdb4
    ldr r8, [r3, r7, lsl #2]
    add pc, r8, r3
@L0207bdb4:
    ldr r0, [sp]
    ldr r2, [sp, #0x14]
    ldr r1, [r0, #0x24]
    add r0, r0, r2
    ldr r0, [r0, #0x24]
    mov r8, r6, asr #2
    add r0, r0, r11, lsr #1
    add r0, r0, r8, lsl #8
    add r0, r0, r5, asr #2
    add r1, r1, r11, lsr #1
    ldr r2, [sp, #0x18]
    mov r2, r2, lsr #1
    sub r3, pc, #0xe8 // @L0207bd04
    add r5, r5, r11, lsl #1
    mov r5, r5, asr #1
    and r5, r5, #7
    mov r8, r6, asr #1
    and r8, r8, #1
    add r5, r5, r8, lsl #3
    add lr, pc, #8 // @L0207be10
    mov r6, r0
    ldr r8, [r3, r5, lsl #2]
    add pc, r8, r3
@L0207be10:
    ldr r2, [sp, #0x18]
    mov r2, r2, lsr #1
    add r0, r6, #0x80
    sub r1, r1, r2, lsl #8
    add r1, r1, #0x80
    sub r3, pc, #0x128 // @L0207bd04
    add lr, pc, #4 // @L0207be34
    ldr r8, [r3, r5, lsl #2]
    add pc, r8, r3
@L0207be34:
    ldmfd sp!, {r0, r1, r2, r3, r4, r5, r6, r11, r12, pc}
@L0207be38:
    dcd 0x01010101
    dcd 0x01010101
    dcd 0x08080808
    dcd 0x09090909
    dcd 0x02020304
    dcd 0x06050707
    dcd 0x00000000
    dcd 0x00000000
@L0207be58:
    dcd 0x00000034 // @L0207be8c - @L0207be58
    dcd 0x0000005c // @L0207beb4 - @L0207be58
    dcd 0x00000074 // @L0207becc - @L0207be58
    dcd 0x0000008c // @L0207bee4 - @L0207be58
    dcd 0x000000a4 // @L0207befc - @L0207be58
    dcd 0x000000bc // @L0207bf14 - @L0207be58
    dcd 0x00001764 // @L0207d5bc - @L0207be58
    dcd 0x00001828 // @L0207d680 - @L0207be58
    dcd 0x000000d4 // @L0207bf2c - @L0207be58
    dcd 0x000000f0 // @L0207bf48 - @L0207be58
@L0207be80:
    dcd 0x05040202
    dcd 0x04050505
    dcd 0x00000303
@L0207be8c:
    str lr, [sp, #-4]!
    mov r5, #4
    mov r6, #0x10
    add lr, pc, #0xc // @L0207beac
    stmfd sp!, {r4, r5, r6, r11, r12, lr}
    add r9, r0, #0x3bc
    ldmia r9, {r5, r6}
    b @L0207bd64
@L0207beac:
    bl @L0207d758
    ldr pc, [sp], #4
@L0207beb4:
    str lr, [sp, #-4]!
    mov r5, #4
    mov r6, #0x10
    bl @L0207bd44
    bl @L0207d758
    ldr pc, [sp], #4
@L0207becc:
    str lr, [sp, #-4]!
    mov r5, #8
    mov r6, #0x10
    bl @L0207bd44
    bl @L0207d758
    ldr pc, [sp], #4
@L0207bee4:
    str lr, [sp, #-4]!
    mov r5, #0xc
    mov r6, #0x10
    bl @L0207bd44
    bl @L0207d758
    ldr pc, [sp], #4
@L0207befc:
    str lr, [sp, #-4]!
    mov r5, #0x10
    mov r6, #0x10
    bl @L0207bd44
    bl @L0207d758
    ldr pc, [sp], #4
@L0207bf14:
    str lr, [sp, #-4]!
    mov r5, #0x14
    mov r6, #0x10
    bl @L0207bd44
    bl @L0207d758
    ldr pc, [sp], #4
@L0207bf2c:
    str lr, [sp, #-4]!
    bl @L0207c740
    add r11, r11, #0x800
    bl @L0207c740
    sub r11, r11, #0x800
    bl @L0207d758
    ldr pc, [sp], #4
@L0207bf48:
    str lr, [sp, #-4]!
    bl @L0207c1bc
    add r11, r11, #8
    bl @L0207c1bc
    sub r11, r11, #8
    bl @L0207d758
    ldr pc, [sp], #4
@L0207bf64:
    mov r6, r3, lsr #0x1b
    sub r5, pc, #0x138 // @L0207be38
    ldrb r5, [r5, r6]
    sub r6, pc, #0xf8 // @L0207be80
    ldrb r6, [r6, r5]
    mov r3, r3, lsl r6
    subs r2, r2, r6
    mov r8, lr
    bllt @L0207dd1c
    sub r6, pc, #0x138 // @L0207be58
    ldr r5, [r6, r5, lsl #2]
    mov lr, r8
    add pc, r5, r6
@L0207bf98:
    dcd 0x00005a58 // @L020819f0 - @L0207bf98
    dcd 0x00005aac // @L02081a44 - @L0207bf98
    dcd 0x00005b64 // @L02081afc - @L0207bf98
    dcd 0x00005c00 // @L02081b98 - @L0207bf98
    dcd 0x00005ce0 // @L02081c78 - @L0207bf98
    dcd 0x00005d64 // @L02081cfc - @L0207bf98
    dcd 0x00005e24 // @L02081dbc - @L0207bf98
    dcd 0x00005ea0 // @L02081e38 - @L0207bf98
    dcd 0x00005a6c // @L02081a04 - @L0207bf98
    dcd 0x00005adc // @L02081a74 - @L0207bf98
    dcd 0x00005b8c // @L02081b24 - @L0207bf98
    dcd 0x00005c3c // @L02081bd4 - @L0207bf98
    dcd 0x00005d00 // @L02081c98 - @L0207bf98
    dcd 0x00005d98 // @L02081d30 - @L0207bf98
    dcd 0x00005e44 // @L02081ddc - @L0207bf98
    dcd 0x00005ed0 // @L02081e68 - @L0207bf98
@L0207bfd8:
    stmfd sp!, {r4, r5, r6, r11, r12, lr}
    bl @L0207dd30
    mov r5, r6
    bl @L0207dd30
    add r9, r0, #0x3bc
    ldmia r9, {r7, r8}
    add r5, r5, r7
    add r6, r6, r8
@L0207bff8:
    stmia r4, {r5, r6}
    add r7, r5, r11, lsl #1
    and r7, r7, #7
    and r8, r6, #1
    add r7, r7, r8, lsl #3
    stmfd sp!, {r0, r1, r2, r3}
    ldr r2, [sp, #0x14]
    ldr r1, [r0, #0xc]
    add r0, r0, r2
    ldr r0, [r0, #0xc]
    mov r8, r6, asr #1
    add r0, r0, r11
    add r0, r0, r8, lsl #8
    add r0, r0, r5, asr #1
    add r1, r1, r11
    ldr r2, [sp, #0x18]
    sub r3, pc, #0x33c // @L0207bd04
    add lr, pc, #4 // @L0207c048
    ldr r8, [r3, r7, lsl #2]
    add pc, r8, r3
@L0207c048:
    ldr r0, [sp]
    ldr r2, [sp, #0x14]
    ldr r1, [r0, #0x24]
    add r0, r0, r2
    ldr r0, [r0, #0x24]
    mov r8, r6, asr #2
    add r0, r0, r11, lsr #1
    add r0, r0, r8, lsl #8
    add r0, r0, r5, asr #2
    add r1, r1, r11, lsr #1
    ldr r2, [sp, #0x18]
    mov r2, r2, lsr #1
    sub r3, pc, #0xe8 // @L0207bf98
    add r5, r5, r11, lsl #1
    mov r5, r5, asr #1
    and r5, r5, #7
    mov r8, r6, asr #1
    and r8, r8, #1
    add r5, r5, r8, lsl #3
    add lr, pc, #8 // @L0207c0a4
    mov r6, r0
    ldr r8, [r3, r5, lsl #2]
    add pc, r8, r3
@L0207c0a4:
    ldr r2, [sp, #0x18]
    mov r2, r2, lsr #1
    add r0, r6, #0x80
    sub r1, r1, r2, lsl #8
    add r1, r1, #0x80
    sub r3, pc, #0x128 // @L0207bf98
    add lr, pc, #4 // @L0207c0c8
    ldr r8, [r3, r5, lsl #2]
    add pc, r8, r3
@L0207c0c8:
    ldmfd sp!, {r0, r1, r2, r3, r4, r5, r6, r11, r12, pc}
@L0207c0cc:
    dcd 0x00000000
    dcd 0x04050909
    dcd 0x08030202
    dcd 0x01010101
@L0207c0dc:
    dcd 0x00000034 // @L0207c110 - @L0207c0dc
    dcd 0x0000004c // @L0207c128 - @L0207c0dc
    dcd 0x00000060 // @L0207c13c - @L0207c0dc
    dcd 0x00000074 // @L0207c150 - @L0207c0dc
    dcd 0x00000088 // @L0207c164 - @L0207c0dc
    dcd 0x0000009c // @L0207c178 - @L0207c0dc
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x000000b0
    dcd 0x000000c8
@L0207c104:
    dcd 0x04030202
    dcd 0x00000404
    dcd 0x00000304
@L0207c110:
    mov r5, #4
    mov r6, #0x10
    stmfd sp!, {r4, r5, r6, r11, r12, lr}
    add r9, r0, #0x3bc
    ldmia r9, {r5, r6}
    b @L0207bff8
@L0207c128:
    str lr, [sp, #-4]!
    mov r5, #4
    mov r6, #0x10
    bl @L0207bfd8
    ldr pc, [sp], #4
@L0207c13c:
    str lr, [sp, #-4]!
    mov r5, #8
    mov r6, #0x10
    bl @L0207bfd8
    ldr pc, [sp], #4
@L0207c150:
    str lr, [sp, #-4]!
    mov r5, #0xc
    mov r6, #0x10
    bl @L0207bfd8
    ldr pc, [sp], #4
@L0207c164:
    str lr, [sp, #-4]!
    mov r5, #0x10
    mov r6, #0x10
    bl @L0207bfd8
    ldr pc, [sp], #4
@L0207c178:
    str lr, [sp, #-4]!
    mov r5, #0x14
    mov r6, #0x10
    bl @L0207bfd8
    ldr pc, [sp], #4
@L0207c18c:
    str lr, [sp, #-4]!
    bl @L0207ca94
    add r11, r11, #0x800
    bl @L0207ca94
    sub r11, r11, #0x800
    ldr pc, [sp], #4
@L0207c1a4:
    str lr, [sp, #-4]!
    bl @L0207c3f4
    add r11, r11, #4
    bl @L0207c3f4
    sub r11, r11, #4
    ldr pc, [sp], #4
@L0207c1bc:
    mov r6, r3, lsr #0x1c
    sub r5, pc, #0xfc // @L0207c0cc
    ldrb r5, [r5, r6]
    sub r6, pc, #0xcc // @L0207c104
    ldrb r6, [r6, r5]
    mov r3, r3, lsl r6
    subs r2, r2, r6
    mov r8, lr
    bllt @L0207dd1c
    sub r6, pc, #0x10c // @L0207c0dc
    ldr r5, [r6, r5, lsl #2]
    mov lr, r8
    add pc, r5, r6
@L0207c1f0:
    dcd 0x00005cfc // @L02081eec - @L0207c1f0
    dcd 0x00005d6c // @L02081f5c - @L0207c1f0
    dcd 0x00005e30 // @L02082020 - @L0207c1f0
    dcd 0x00005eb8 // @L020820a8 - @L0207c1f0
    dcd 0x00005d18 // @L02081f08 - @L0207c1f0
    dcd 0x00005da0 // @L02081f90 - @L0207c1f0
    dcd 0x00005e54 // @L02082044 - @L0207c1f0
    dcd 0x00005ef0 // @L020820e0 - @L0207c1f0
@L0207c210:
    stmfd sp!, {r4, r5, r6, r11, r12, lr}
    bl @L0207dd30
    mov r5, r6
    bl @L0207dd30
    add r9, r0, #0x3bc
    ldmia r9, {r7, r8}
    add r5, r5, r7
    add r6, r6, r8
@L0207c230:
    stmia r4, {r5, r6}
    add r7, r5, r11, lsl #1
    and r7, r7, #7
    and r8, r6, #1
    add r7, r7, r8, lsl #3
    stmfd sp!, {r0, r1, r2, r3}
    ldr r2, [sp, #0x14]
    ldr r1, [r0, #0xc]
    add r0, r0, r2
    ldr r0, [r0, #0xc]
    mov r8, r6, asr #1
    add r0, r0, r11
    add r0, r0, r8, lsl #8
    add r0, r0, r5, asr #1
    add r1, r1, r11
    ldr r2, [sp, #0x18]
    sub r3, pc, #0x2e0 // @L0207bf98
    add lr, pc, #4 // @L0207c280
    ldr r8, [r3, r7, lsl #2]
    add pc, r8, r3
@L0207c280:
    ldr r0, [sp]
    ldr r2, [sp, #0x14]
    ldr r1, [r0, #0x24]
    add r0, r0, r2
    ldr r0, [r0, #0x24]
    mov r8, r6, asr #2
    add r0, r0, r11, lsr #1
    add r0, r0, r8, lsl #8
    add r0, r0, r5, asr #2
    add r1, r1, r11, lsr #1
    ldr r2, [sp, #0x18]
    mov r2, r2, lsr #1
    sub r3, pc, #0xc8 // @L0207c1f0
    add r5, r5, r11, lsl #1
    mov r5, r5, asr #1
    and r5, r5, #3
    mov r8, r6, asr #1
    and r8, r8, #1
    add r5, r5, r8, lsl #2
    add lr, pc, #8 // @L0207c2dc
    mov r6, r0
    ldr r8, [r3, r5, lsl #2]
    add pc, r8, r3
@L0207c2dc:
    ldr r2, [sp, #0x18]
    mov r2, r2, lsr #1
    add r0, r6, #0x80
    sub r1, r1, r2, lsl #8
    add r1, r1, #0x80
    sub r3, pc, #0x108 // @L0207c1f0
    add lr, pc, #4 // @L0207c300
    ldr r8, [r3, r5, lsl #2]
    add pc, r8, r3
@L0207c300:
    ldmfd sp!, {r0, r1, r2, r3, r4, r5, r6, r11, r12, pc}
@L0207c304:
    dcd 0x05090303
    dcd 0x00000000
    dcd 0x02020804
    dcd 0x01010101
@L0207c314:
    dcd 0x00000034 // @L0207c348 - @L0207c314
    dcd 0x0000004c // @L0207c360 - @L0207c314
    dcd 0x00000060 // @L0207c374 - @L0207c314
    dcd 0x00000074 // @L0207c388 - @L0207c314
    dcd 0x00000088 // @L0207c39c - @L0207c314
    dcd 0x0000009c // @L0207c3b0 - @L0207c314
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x000000b0
    dcd 0x000000c8
@L0207c33c:
    dcd 0x03030202
    dcd 0x00000404
    dcd 0x00000404
@L0207c348:
    mov r5, #4
    mov r6, #0x10
    stmfd sp!, {r4, r5, r6, r11, r12, lr}
    add r9, r0, #0x3bc
    ldmia r9, {r5, r6}
    b @L0207c230
@L0207c360:
    str lr, [sp, #-4]!
    mov r5, #4
    mov r6, #0x10
    bl @L0207c210
    ldr pc, [sp], #4
@L0207c374:
    str lr, [sp, #-4]!
    mov r5, #8
    mov r6, #0x10
    bl @L0207c210
    ldr pc, [sp], #4
@L0207c388:
    str lr, [sp, #-4]!
    mov r5, #0xc
    mov r6, #0x10
    bl @L0207c210
    ldr pc, [sp], #4
@L0207c39c:
    str lr, [sp, #-4]!
    mov r5, #0x10
    mov r6, #0x10
    bl @L0207c210
    ldr pc, [sp], #4
@L0207c3b0:
    str lr, [sp, #-4]!
    mov r5, #0x14
    mov r6, #0x10
    bl @L0207c210
    ldr pc, [sp], #4
@L0207c3c4:
    str lr, [sp, #-4]!
    bl @L0207cdf4
    add r11, r11, #0x800
    bl @L0207cdf4
    sub r11, r11, #0x800
    ldr pc, [sp], #4
@L0207c3dc:
    str lr, [sp, #-4]!
    bl @L0207c61c
    add r11, r11, #2
    bl @L0207c61c
    sub r11, r11, #2
    ldr pc, [sp], #4
@L0207c3f4:
    mov r6, r3, lsr #0x1c
    sub r5, pc, #0xfc // @L0207c304
    ldrb r5, [r5, r6]
    sub r6, pc, #0xcc // @L0207c33c
    ldrb r6, [r6, r5]
    mov r3, r3, lsl r6
    subs r2, r2, r6
    mov r8, lr
    bllt @L0207dd1c
    sub r6, pc, #0x10c // @L0207c314
    ldr r5, [r6, r5, lsl #2]
    mov lr, r8
    add pc, r5, r6
@L0207c428:
    dcd 0x00005d58 // @L02082180 - @L0207c428
    dcd 0x00005da8 // @L020821d0 - @L0207c428
    dcd 0x00005d6c // @L02082194 - @L0207c428
    dcd 0x00005dcc // @L020821f4 - @L0207c428
@L0207c438:
    stmfd sp!, {r4, r5, r6, r11, r12, lr}
    bl @L0207dd30
    mov r5, r6
    bl @L0207dd30
    add r9, r0, #0x3bc
    ldmia r9, {r7, r8}
    add r5, r5, r7
    add r6, r6, r8
@L0207c458:
    stmia r4, {r5, r6}
    add r7, r5, r11, lsl #1
    and r7, r7, #3
    and r8, r6, #1
    add r7, r7, r8, lsl #2
    stmfd sp!, {r0, r1, r2, r3}
    ldr r2, [sp, #0x14]
    ldr r1, [r0, #0xc]
    add r0, r0, r2
    ldr r0, [r0, #0xc]
    mov r8, r6, asr #1
    add r0, r0, r11
    add r0, r0, r8, lsl #8
    add r0, r0, r5, asr #1
    add r1, r1, r11
    ldr r2, [sp, #0x18]
    sub r3, pc, #0x2b0 // @L0207c1f0
    add lr, pc, #4 // @L0207c4a8
    ldr r8, [r3, r7, lsl #2]
    add pc, r8, r3
@L0207c4a8:
    ldr r0, [sp]
    ldr r2, [sp, #0x14]
    ldr r1, [r0, #0x24]
    add r0, r0, r2
    ldr r0, [r0, #0x24]
    mov r8, r6, asr #2
    add r0, r0, r11, lsr #1
    add r0, r0, r8, lsl #8
    add r0, r0, r5, asr #2
    add r1, r1, r11, lsr #1
    ldr r2, [sp, #0x18]
    mov r2, r2, lsr #1
    sub r3, pc, #0xb8 // @L0207c428
    add r5, r5, r11, lsl #1
    mov r5, r5, asr #1
    and r5, r5, #1
    mov r8, r6, asr #1
    and r8, r8, #1
    add r5, r5, r8, lsl #1
    add lr, pc, #8 // @L0207c504
    mov r6, r0
    ldr r8, [r3, r5, lsl #2]
    add pc, r8, r3
@L0207c504:
    ldr r2, [sp, #0x18]
    mov r2, r2, lsr #1
    add r0, r6, #0x80
    sub r1, r1, r2, lsl #8
    add r1, r1, #0x80
    sub r3, pc, #0xf8 // @L0207c428
    add lr, pc, #4 // @L0207c528
    ldr r8, [r3, r5, lsl #2]
    add pc, r8, r3
@L0207c528:
    ldmfd sp!, {r0, r1, r2, r3, r4, r5, r6, r11, r12, pc}
@L0207c52c:
    dcd 0x01010101
    dcd 0x01010101
    dcd 0x01010101
    dcd 0x01010101
    dcd 0x03030303
    dcd 0x05080404
    dcd 0x02020202
    dcd 0x00000000
@L0207c54c:
    dcd 0x0000003c // @L0207c588 - @L0207c54c
    dcd 0x00000054 // @L0207c5a0 - @L0207c54c
    dcd 0x00000068 // @L0207c5b4 - @L0207c54c
    dcd 0x0000007c // @L0207c5c8 - @L0207c54c
    dcd 0x00000090 // @L0207c5dc - @L0207c54c
    dcd 0x000000a4 // @L0207c5f0 - @L0207c54c
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x000000b8
    dcd 0x00000000
@L0207c574:
    dcd 0x03030103
    dcd 0x00000504
    dcd 0x00000005
    dcd 0x00000000
    dcd 0x00000000
@L0207c588:
    mov r5, #4
    mov r6, #0x10
    stmfd sp!, {r4, r5, r6, r11, r12, lr}
    add r9, r0, #0x3bc
    ldmia r9, {r5, r6}
    b @L0207c458
@L0207c5a0:
    str lr, [sp, #-4]!
    mov r5, #4
    mov r6, #0x10
    bl @L0207c438
    ldr pc, [sp], #4
@L0207c5b4:
    str lr, [sp, #-4]!
    mov r5, #8
    mov r6, #0x10
    bl @L0207c438
    ldr pc, [sp], #4
@L0207c5c8:
    str lr, [sp, #-4]!
    mov r5, #0xc
    mov r6, #0x10
    bl @L0207c438
    ldr pc, [sp], #4
@L0207c5dc:
    str lr, [sp, #-4]!
    mov r5, #0x10
    mov r6, #0x10
    bl @L0207c438
    ldr pc, [sp], #4
@L0207c5f0:
    str lr, [sp, #-4]!
    mov r5, #0x14
    mov r6, #0x10
    bl @L0207c438
    ldr pc, [sp], #4
@L0207c604:
    str lr, [sp, #-4]!
    bl @L0207d16c
    add r11, r11, #0x800
    bl @L0207d16c
    sub r11, r11, #0x800
    ldr pc, [sp], #4
@L0207c61c:
    mov r6, r3, lsr #0x1b
    sub r5, pc, #0xfc // @L0207c52c
    ldrb r5, [r5, r6]
    sub r6, pc, #0xbc // @L0207c574
    ldrb r6, [r6, r5]
    mov r3, r3, lsl r6
    subs r2, r2, r6
    mov r8, lr
    bllt @L0207dd1c
    sub r6, pc, #0xfc // @L0207c54c
    ldr r5, [r6, r5, lsl #2]
    mov lr, r8
    add pc, r5, r6
@L0207c650:
    dcd 0x00000000
    dcd 0x08080405
    dcd 0x09030202
    dcd 0x01010101
@L0207c660:
    dcd 0x00000034 // @L0207c694 - @L0207c660
    dcd 0x0000004c // @L0207c6ac - @L0207c660
    dcd 0x00000060 // @L0207c6c0 - @L0207c660
    dcd 0x00000074 // @L0207c6d4 - @L0207c660
    dcd 0x00000088 // @L0207c6e8 - @L0207c660
    dcd 0x0000009c // @L0207c6fc - @L0207c660
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x000000b0
    dcd 0x000000c8
@L0207c688:
    dcd 0x04030202
    dcd 0x00000404
    dcd 0x00000403
@L0207c694:
    mov r5, #4
    mov r6, #8
    stmfd sp!, {r4, r5, r6, r11, r12, lr}
    add r9, r0, #0x3bc
    ldmia r9, {r5, r6}
    b @L0207bd64
@L0207c6ac:
    str lr, [sp, #-4]!
    mov r5, #4
    mov r6, #8
    bl @L0207bd44
    ldr pc, [sp], #4
@L0207c6c0:
    str lr, [sp, #-4]!
    mov r5, #8
    mov r6, #8
    bl @L0207bd44
    ldr pc, [sp], #4
@L0207c6d4:
    str lr, [sp, #-4]!
    mov r5, #0xc
    mov r6, #8
    bl @L0207bd44
    ldr pc, [sp], #4
@L0207c6e8:
    str lr, [sp, #-4]!
    mov r5, #0x10
    mov r6, #8
    bl @L0207bd44
    ldr pc, [sp], #4
@L0207c6fc:
    str lr, [sp, #-4]!
    mov r5, #0x14
    mov r6, #8
    bl @L0207bd44
    ldr pc, [sp], #4
@L0207c710:
    str lr, [sp, #-4]!
    bl @L0207c864
    add r11, r11, #0x400
    bl @L0207c864
    sub r11, r11, #0x400
    ldr pc, [sp], #4
@L0207c728:
    str lr, [sp, #-4]!
    bl @L0207ca94
    add r11, r11, #8
    bl @L0207ca94
    sub r11, r11, #8
    ldr pc, [sp], #4
@L0207c740:
    mov r6, r3, lsr #0x1c
    sub r5, pc, #0xfc // @L0207c650
    ldrb r5, [r5, r6]
    sub r6, pc, #0xcc // @L0207c688
    ldrb r6, [r6, r5]
    mov r3, r3, lsl r6
    subs r2, r2, r6
    mov r8, lr
    bllt @L0207dd1c
    sub r6, pc, #0x10c // @L0207c660
    ldr r5, [r6, r5, lsl #2]
    mov lr, r8
    add pc, r5, r6
@L0207c774:
    dcd 0x00000000
    dcd 0x04080303
    dcd 0x09050202
    dcd 0x01010101
@L0207c784:
    dcd 0x00000034 // @L0207c7b8 - @L0207c784
    dcd 0x0000004c // @L0207c7d0 - @L0207c784
    dcd 0x00000060 // @L0207c7e4 - @L0207c784
    dcd 0x00000074 // @L0207c7f8 - @L0207c784
    dcd 0x00000088 // @L0207c80c - @L0207c784
    dcd 0x0000009c // @L0207c820 - @L0207c784
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x000000b0
    dcd 0x000000c8
@L0207c7ac:
    dcd 0x03030202
    dcd 0x00000404
    dcd 0x00000404
@L0207c7b8:
    mov r5, #4
    mov r6, #4
    stmfd sp!, {r4, r5, r6, r11, r12, lr}
    add r9, r0, #0x3bc
    ldmia r9, {r5, r6}
    b @L0207bd64
@L0207c7d0:
    str lr, [sp, #-4]!
    mov r5, #4
    mov r6, #4
    bl @L0207bd44
    ldr pc, [sp], #4
@L0207c7e4:
    str lr, [sp, #-4]!
    mov r5, #8
    mov r6, #4
    bl @L0207bd44
    ldr pc, [sp], #4
@L0207c7f8:
    str lr, [sp, #-4]!
    mov r5, #0xc
    mov r6, #4
    bl @L0207bd44
    ldr pc, [sp], #4
@L0207c80c:
    str lr, [sp, #-4]!
    mov r5, #0x10
    mov r6, #4
    bl @L0207bd44
    ldr pc, [sp], #4
@L0207c820:
    str lr, [sp, #-4]!
    mov r5, #0x14
    mov r6, #4
    bl @L0207bd44
    ldr pc, [sp], #4
@L0207c834:
    str lr, [sp, #-4]!
    bl @L0207c970
    add r11, r11, #0x200
    bl @L0207c970
    sub r11, r11, #0x200
    ldr pc, [sp], #4
@L0207c84c:
    str lr, [sp, #-4]!
    bl @L0207cbb8
    add r11, r11, #8
    bl @L0207cbb8
    sub r11, r11, #8
    ldr pc, [sp], #4
@L0207c864:
    mov r6, r3, lsr #0x1c
    sub r5, pc, #0xfc // @L0207c774
    ldrb r5, [r5, r6]
    sub r6, pc, #0xcc // @L0207c7ac
    ldrb r6, [r6, r5]
    mov r3, r3, lsl r6
    subs r2, r2, r6
    mov r8, lr
    bllt @L0207dd1c
    sub r6, pc, #0x10c // @L0207c784
    ldr r5, [r6, r5, lsl #2]
    mov lr, r8
    add pc, r5, r6
@L0207c898:
    dcd 0x01010101
    dcd 0x01010101
    dcd 0x02020409
    dcd 0x03050000
@L0207c8a8:
    dcd 0x00000034 // @L0207c8dc - @L0207c8a8
    dcd 0x0000004c // @L0207c8f4 - @L0207c8a8
    dcd 0x00000060 // @L0207c908 - @L0207c8a8
    dcd 0x00000074 // @L0207c91c - @L0207c8a8
    dcd 0x00000088 // @L0207c930 - @L0207c8a8
    dcd 0x0000009c // @L0207c944 - @L0207c8a8
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x000000b0
@L0207c8d0:
    dcd 0x04030103
    dcd 0x00000404
    dcd 0x00000400
@L0207c8dc:
    mov r5, #4
    mov r6, #2
    stmfd sp!, {r4, r5, r6, r11, r12, lr}
    add r9, r0, #0x3bc
    ldmia r9, {r5, r6}
    b @L0207bd64
@L0207c8f4:
    str lr, [sp, #-4]!
    mov r5, #4
    mov r6, #2
    bl @L0207bd44
    ldr pc, [sp], #4
@L0207c908:
    str lr, [sp, #-4]!
    mov r5, #8
    mov r6, #2
    bl @L0207bd44
    ldr pc, [sp], #4
@L0207c91c:
    str lr, [sp, #-4]!
    mov r5, #0xc
    mov r6, #2
    bl @L0207bd44
    ldr pc, [sp], #4
@L0207c930:
    str lr, [sp, #-4]!
    mov r5, #0x10
    mov r6, #2
    bl @L0207bd44
    ldr pc, [sp], #4
@L0207c944:
    str lr, [sp, #-4]!
    mov r5, #0x14
    mov r6, #2
    bl @L0207bd44
    ldr pc, [sp], #4
@L0207c958:
    str lr, [sp, #-4]!
    bl @L0207ccc4
    add r11, r11, #8
    bl @L0207ccc4
    sub r11, r11, #8
    ldr pc, [sp], #4
@L0207c970:
    mov r6, r3, lsr #0x1c
    sub r5, pc, #0xe4 // @L0207c898
    ldrb r5, [r5, r6]
    sub r6, pc, #0xb4 // @L0207c8d0
    ldrb r6, [r6, r5]
    mov r3, r3, lsl r6
    subs r2, r2, r6
    mov r8, lr
    bllt @L0207dd1c
    sub r6, pc, #0xf4 // @L0207c8a8
    ldr r5, [r6, r5, lsl #2]
    mov lr, r8
    add pc, r5, r6
@L0207c9a4:
    dcd 0x00000000
    dcd 0x09050303
    dcd 0x02020804
    dcd 0x01010101
@L0207c9b4:
    dcd 0x00000034 // @L0207c9e8 - @L0207c9b4
    dcd 0x0000004c // @L0207ca00 - @L0207c9b4
    dcd 0x00000060 // @L0207ca14 - @L0207c9b4
    dcd 0x00000074 // @L0207ca28 - @L0207c9b4
    dcd 0x00000088 // @L0207ca3c - @L0207c9b4
    dcd 0x0000009c // @L0207ca50 - @L0207c9b4
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x000000b0
    dcd 0x000000c8
@L0207c9dc:
    dcd 0x03030202
    dcd 0x00000404
    dcd 0x00000404
@L0207c9e8:
    mov r5, #4
    mov r6, #8
    stmfd sp!, {r4, r5, r6, r11, r12, lr}
    add r9, r0, #0x3bc
    ldmia r9, {r5, r6}
    b @L0207bff8
@L0207ca00:
    str lr, [sp, #-4]!
    mov r5, #4
    mov r6, #8
    bl @L0207bfd8
    ldr pc, [sp], #4
@L0207ca14:
    str lr, [sp, #-4]!
    mov r5, #8
    mov r6, #8
    bl @L0207bfd8
    ldr pc, [sp], #4
@L0207ca28:
    str lr, [sp, #-4]!
    mov r5, #0xc
    mov r6, #8
    bl @L0207bfd8
    ldr pc, [sp], #4
@L0207ca3c:
    str lr, [sp, #-4]!
    mov r5, #0x10
    mov r6, #8
    bl @L0207bfd8
    ldr pc, [sp], #4
@L0207ca50:
    str lr, [sp, #-4]!
    mov r5, #0x14
    mov r6, #8
    bl @L0207bfd8
    ldr pc, [sp], #4
@L0207ca64:
    str lr, [sp, #-4]!
    bl @L0207cbb8
    add r11, r11, #0x400
    bl @L0207cbb8
    sub r11, r11, #0x400
    ldr pc, [sp], #4
@L0207ca7c:
    str lr, [sp, #-4]!
    bl @L0207cdf4
    add r11, r11, #4
    bl @L0207cdf4
    sub r11, r11, #4
    ldr pc, [sp], #4
@L0207ca94:
    mov r6, r3, lsr #0x1c
    sub r5, pc, #0xfc // @L0207c9a4
    ldrb r5, [r5, r6]
    sub r6, pc, #0xcc // @L0207c9dc
    ldrb r6, [r6, r5]
    mov r3, r3, lsl r6
    subs r2, r2, r6
    mov r8, lr
    bllt @L0207dd1c
    sub r6, pc, #0x10c // @L0207c9b4
    ldr r5, [r6, r5, lsl #2]
    mov lr, r8
    add pc, r5, r6
@L0207cac8:
    dcd 0x02020202
    dcd 0x03030908
    dcd 0x00000405
    dcd 0x01010101
@L0207cad8:
    dcd 0x00000034 // @L0207cb0c - @L0207cad8
    dcd 0x0000004c // @L0207cb24 - @L0207cad8
    dcd 0x00000060 // @L0207cb38 - @L0207cad8
    dcd 0x00000074 // @L0207cb4c - @L0207cad8
    dcd 0x00000088 // @L0207cb60 - @L0207cad8
    dcd 0x0000009c // @L0207cb74 - @L0207cad8
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x000000b0
    dcd 0x000000c8
@L0207cb00:
    dcd 0x03020203
    dcd 0x00000404
    dcd 0x00000404
@L0207cb0c:
    mov r5, #4
    mov r6, #4
    stmfd sp!, {r4, r5, r6, r11, r12, lr}
    add r9, r0, #0x3bc
    ldmia r9, {r5, r6}
    b @L0207bff8
@L0207cb24:
    str lr, [sp, #-4]!
    mov r5, #4
    mov r6, #4
    bl @L0207bfd8
    ldr pc, [sp], #4
@L0207cb38:
    str lr, [sp, #-4]!
    mov r5, #8
    mov r6, #4
    bl @L0207bfd8
    ldr pc, [sp], #4
@L0207cb4c:
    str lr, [sp, #-4]!
    mov r5, #0xc
    mov r6, #4
    bl @L0207bfd8
    ldr pc, [sp], #4
@L0207cb60:
    str lr, [sp, #-4]!
    mov r5, #0x10
    mov r6, #4
    bl @L0207bfd8
    ldr pc, [sp], #4
@L0207cb74:
    str lr, [sp, #-4]!
    mov r5, #0x14
    mov r6, #4
    bl @L0207bfd8
    ldr pc, [sp], #4
@L0207cb88:
    str lr, [sp, #-4]!
    bl @L0207ccc4
    add r11, r11, #0x200
    bl @L0207ccc4
    sub r11, r11, #0x200
    ldr pc, [sp], #4
@L0207cba0:
    str lr, [sp, #-4]!
    bl @L0207cf34
    add r11, r11, #4
    bl @L0207cf34
    sub r11, r11, #4
    ldr pc, [sp], #4
@L0207cbb8:
    mov r6, r3, lsr #0x1c
    sub r5, pc, #0xfc // @L0207cac8
    ldrb r5, [r5, r6]
    sub r6, pc, #0xcc // @L0207cb00
    ldrb r6, [r6, r5]
    mov r3, r3, lsl r6
    subs r2, r2, r6
    mov r8, lr
    bllt @L0207dd1c
    sub r6, pc, #0x10c // @L0207cad8
    ldr r5, [r6, r5, lsl #2]
    mov lr, r8
    add pc, r5, r6
@L0207cbec:
    dcd 0x02020202
    dcd 0x05090404
    dcd 0x00000303
    dcd 0x01010101
@L0207cbfc:
    dcd 0x00000034 // @L0207cc30 - @L0207cbfc
    dcd 0x0000004c // @L0207cc48 - @L0207cbfc
    dcd 0x00000060 // @L0207cc5c - @L0207cbfc
    dcd 0x00000074 // @L0207cc70 - @L0207cbfc
    dcd 0x00000088 // @L0207cc84 - @L0207cbfc
    dcd 0x0000009c // @L0207cc98 - @L0207cbfc
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x000000b0
@L0207cc24:
    dcd 0x03020203
    dcd 0x00000403
    dcd 0x00000400
@L0207cc30:
    mov r5, #4
    mov r6, #2
    stmfd sp!, {r4, r5, r6, r11, r12, lr}
    add r9, r0, #0x3bc
    ldmia r9, {r5, r6}
    b @L0207bff8
@L0207cc48:
    str lr, [sp, #-4]!
    mov r5, #4
    mov r6, #2
    bl @L0207bfd8
    ldr pc, [sp], #4
@L0207cc5c:
    str lr, [sp, #-4]!
    mov r5, #8
    mov r6, #2
    bl @L0207bfd8
    ldr pc, [sp], #4
@L0207cc70:
    str lr, [sp, #-4]!
    mov r5, #0xc
    mov r6, #2
    bl @L0207bfd8
    ldr pc, [sp], #4
@L0207cc84:
    str lr, [sp, #-4]!
    mov r5, #0x10
    mov r6, #2
    bl @L0207bfd8
    ldr pc, [sp], #4
@L0207cc98:
    str lr, [sp, #-4]!
    mov r5, #0x14
    mov r6, #2
    bl @L0207bfd8
    ldr pc, [sp], #4
@L0207ccac:
    str lr, [sp, #-4]!
    bl @L0207d04c
    add r11, r11, #4
    bl @L0207d04c
    sub r11, r11, #4
    ldr pc, [sp], #4
@L0207ccc4:
    mov r6, r3, lsr #0x1c
    sub r5, pc, #0xe4 // @L0207cbec
    ldrb r5, [r5, r6]
    sub r6, pc, #0xb4 // @L0207cc24
    ldrb r6, [r6, r5]
    mov r3, r3, lsl r6
    subs r2, r2, r6
    mov r8, lr
    bllt @L0207dd1c
    sub r6, pc, #0xf4 // @L0207cbfc
    ldr r5, [r6, r5, lsl #2]
    mov lr, r8
    add pc, r5, r6
@L0207ccf8:
    dcd 0x00000000
    dcd 0x05090303
    dcd 0x02020408
    dcd 0x01010101
@L0207cd08:
    dcd 0x00000040 // @L0207cd48 - @L0207cd08
    dcd 0x00000058 // @L0207cd60 - @L0207cd08
    dcd 0x0000006c // @L0207cd74 - @L0207cd08
    dcd 0x00000080 // @L0207cd88 - @L0207cd08
    dcd 0x00000094 // @L0207cd9c - @L0207cd08
    dcd 0x000000a8 // @L0207cdb0 - @L0207cd08
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x000000bc
    dcd 0x000000d4
@L0207cd30:
    dcd 0x03030202
    dcd 0x00000404
    dcd 0x00000404
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x00000000
@L0207cd48:
    mov r5, #4
    mov r6, #8
    stmfd sp!, {r4, r5, r6, r11, r12, lr}
    add r9, r0, #0x3bc
    ldmia r9, {r5, r6}
    b @L0207c230
@L0207cd60:
    str lr, [sp, #-4]!
    mov r5, #4
    mov r6, #8
    bl @L0207c210
    ldr pc, [sp], #4
@L0207cd74:
    str lr, [sp, #-4]!
    mov r5, #8
    mov r6, #8
    bl @L0207c210
    ldr pc, [sp], #4
@L0207cd88:
    str lr, [sp, #-4]!
    mov r5, #0xc
    mov r6, #8
    bl @L0207c210
    ldr pc, [sp], #4
@L0207cd9c:
    str lr, [sp, #-4]!
    mov r5, #0x10
    mov r6, #8
    bl @L0207c210
    ldr pc, [sp], #4
@L0207cdb0:
    str lr, [sp, #-4]!
    mov r5, #0x14
    mov r6, #8
    bl @L0207c210
    ldr pc, [sp], #4
@L0207cdc4:
    str lr, [sp, #-4]!
    bl @L0207cf34
    add r11, r11, #0x400
    bl @L0207cf34
    sub r11, r11, #0x400
    ldr pc, [sp], #4
@L0207cddc:
    str lr, [sp, #-4]!
    bl @L0207d16c
    add r11, r11, #2
    bl @L0207d16c
    sub r11, r11, #2
    ldr pc, [sp], #4
@L0207cdf4:
    mov r6, r3, lsr #0x1c
    sub r5, pc, #0x108 // @L0207ccf8
    ldrb r5, [r5, r6]
    sub r6, pc, #0xd8 // @L0207cd30
    ldrb r6, [r6, r5]
    mov r3, r3, lsl r6
    subs r2, r2, r6
    mov r8, lr
    bllt @L0207dd1c
    sub r6, pc, #0x118 // @L0207cd08
    ldr r5, [r6, r5, lsl #2]
    mov lr, r8
    add pc, r5, r6
@L0207ce28:
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x04040404
    dcd 0x03030303
    dcd 0x05050908
    dcd 0x02020202
    dcd 0x01010101
    dcd 0x01010101
@L0207ce48:
    dcd 0x00000040 // @L0207ce88 - @L0207ce48
    dcd 0x00000058 // @L0207cea0 - @L0207ce48
    dcd 0x0000006c // @L0207ceb4 - @L0207ce48
    dcd 0x00000080 // @L0207cec8 - @L0207ce48
    dcd 0x00000094 // @L0207cedc - @L0207ce48
    dcd 0x000000a8 // @L0207cef0 - @L0207ce48
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x000000bc
    dcd 0x000000d4
@L0207ce70:
    dcd 0x03030202
    dcd 0x00000403
    dcd 0x00000505
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x00000000
@L0207ce88:
    mov r5, #4
    mov r6, #4
    stmfd sp!, {r4, r5, r6, r11, r12, lr}
    add r9, r0, #0x3bc
    ldmia r9, {r5, r6}
    b @L0207c230
@L0207cea0:
    str lr, [sp, #-4]!
    mov r5, #4
    mov r6, #4
    bl @L0207c210
    ldr pc, [sp], #4
@L0207ceb4:
    str lr, [sp, #-4]!
    mov r5, #8
    mov r6, #4
    bl @L0207c210
    ldr pc, [sp], #4
@L0207cec8:
    str lr, [sp, #-4]!
    mov r5, #0xc
    mov r6, #4
    bl @L0207c210
    ldr pc, [sp], #4
@L0207cedc:
    str lr, [sp, #-4]!
    mov r5, #0x10
    mov r6, #4
    bl @L0207c210
    ldr pc, [sp], #4
@L0207cef0:
    str lr, [sp, #-4]!
    mov r5, #0x14
    mov r6, #4
    bl @L0207c210
    ldr pc, [sp], #4
@L0207cf04:
    str lr, [sp, #-4]!
    bl @L0207d04c
    add r11, r11, #0x200
    bl @L0207d04c
    sub r11, r11, #0x200
    ldr pc, [sp], #4
@L0207cf1c:
    str lr, [sp, #-4]!
    bl @L0207d27c
    add r11, r11, #2
    bl @L0207d27c
    sub r11, r11, #2
    ldr pc, [sp], #4
@L0207cf34:
    mov r6, r3, lsr #0x1b
    sub r5, pc, #0x118 // @L0207ce28
    ldrb r5, [r5, r6]
    sub r6, pc, #0xd8 // @L0207ce70
    ldrb r6, [r6, r5]
    mov r3, r3, lsl r6
    subs r2, r2, r6
    mov r8, lr
    bllt @L0207dd1c
    sub r6, pc, #0x118 // @L0207ce48
    ldr r5, [r6, r5, lsl #2]
    mov lr, r8
    add pc, r5, r6
@L0207cf68:
    dcd 0x00000000
    dcd 0x05090404
    dcd 0x02020303
    dcd 0x01010101
@L0207cf78:
    dcd 0x00000040 // @L0207cfb8 - @L0207cf78
    dcd 0x00000058 // @L0207cfd0 - @L0207cf78
    dcd 0x0000006c // @L0207cfe4 - @L0207cf78
    dcd 0x00000080 // @L0207cff8 - @L0207cf78
    dcd 0x00000094 // @L0207d00c - @L0207cf78
    dcd 0x000000a8 // @L0207d020 - @L0207cf78
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x000000bc
@L0207cfa0:
    dcd 0x03030202
    dcd 0x00000403
    dcd 0x00000400
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x00000000
@L0207cfb8:
    mov r5, #4
    mov r6, #2
    stmfd sp!, {r4, r5, r6, r11, r12, lr}
    add r9, r0, #0x3bc
    ldmia r9, {r5, r6}
    b @L0207c230
@L0207cfd0:
    str lr, [sp, #-4]!
    mov r5, #4
    mov r6, #2
    bl @L0207c210
    ldr pc, [sp], #4
@L0207cfe4:
    str lr, [sp, #-4]!
    mov r5, #8
    mov r6, #2
    bl @L0207c210
    ldr pc, [sp], #4
@L0207cff8:
    str lr, [sp, #-4]!
    mov r5, #0xc
    mov r6, #2
    bl @L0207c210
    ldr pc, [sp], #4
@L0207d00c:
    str lr, [sp, #-4]!
    mov r5, #0x10
    mov r6, #2
    bl @L0207c210
    ldr pc, [sp], #4
@L0207d020:
    str lr, [sp, #-4]!
    mov r5, #0x14
    mov r6, #2
    bl @L0207c210
    ldr pc, [sp], #4
@L0207d034:
    str lr, [sp, #-4]!
    bl @L0207d374
    add r11, r11, #2
    bl @L0207d374
    sub r11, r11, #2
    ldr pc, [sp], #4
@L0207d04c:
    mov r6, r3, lsr #0x1c
    sub r5, pc, #0xf0 // @L0207cf68
    ldrb r5, [r5, r6]
    sub r6, pc, #0xc0 // @L0207cfa0
    ldrb r6, [r6, r5]
    mov r3, r3, lsl r6
    subs r2, r2, r6
    mov r8, lr
    bllt @L0207dd1c
    sub r6, pc, #0x100 // @L0207cf78
    ldr r5, [r6, r5, lsl #2]
    mov lr, r8
    add pc, r5, r6
@L0207d080:
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x02020202
    dcd 0x02020202
    dcd 0x03030303
    dcd 0x05080404
    dcd 0x01010101
    dcd 0x01010101
@L0207d0a0:
    dcd 0x00000038 // @L0207d0d8 - @L0207d0a0
    dcd 0x00000050 // @L0207d0f0 - @L0207d0a0
    dcd 0x00000064 // @L0207d104 - @L0207d0a0
    dcd 0x00000078 // @L0207d118 - @L0207d0a0
    dcd 0x0000008c // @L0207d12c - @L0207d0a0
    dcd 0x000000a0 // @L0207d140 - @L0207d0a0
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x000000b4
    dcd 0x00000000
@L0207d0c8:
    dcd 0x03020202
    dcd 0x00000504
    dcd 0x00000005
    dcd 0x00000000
@L0207d0d8:
    mov r5, #4
    mov r6, #8
    stmfd sp!, {r4, r5, r6, r11, r12, lr}
    add r9, r0, #0x3bc
    ldmia r9, {r5, r6}
    b @L0207c458
@L0207d0f0:
    str lr, [sp, #-4]!
    mov r5, #4
    mov r6, #8
    bl @L0207c438
    ldr pc, [sp], #4
@L0207d104:
    str lr, [sp, #-4]!
    mov r5, #8
    mov r6, #8
    bl @L0207c438
    ldr pc, [sp], #4
@L0207d118:
    str lr, [sp, #-4]!
    mov r5, #0xc
    mov r6, #8
    bl @L0207c438
    ldr pc, [sp], #4
@L0207d12c:
    str lr, [sp, #-4]!
    mov r5, #0x10
    mov r6, #8
    bl @L0207c438
    ldr pc, [sp], #4
@L0207d140:
    str lr, [sp, #-4]!
    mov r5, #0x14
    mov r6, #8
    bl @L0207c438
    ldr pc, [sp], #4
@L0207d154:
    str lr, [sp, #-4]!
    bl @L0207d27c
    add r11, r11, #0x400
    bl @L0207d27c
    sub r11, r11, #0x400
    ldr pc, [sp], #4
@L0207d16c:
    mov r6, r3, lsr #0x1b
    sub r5, pc, #0xf8 // @L0207d080
    ldrb r5, [r5, r6]
    sub r6, pc, #0xb8 // @L0207d0c8
    ldrb r6, [r6, r5]
    mov r3, r3, lsl r6
    subs r2, r2, r6
    mov r8, lr
    bllt @L0207dd1c
    sub r6, pc, #0xf8 // @L0207d0a0
    ldr r5, [r6, r5, lsl #2]
    mov lr, r8
    add pc, r5, r6
@L0207d1a0:
    dcd 0x00000000
    dcd 0x05080404
    dcd 0x02020303
    dcd 0x01010101
@L0207d1b0:
    dcd 0x00000038 // @L0207d1e8 - @L0207d1b0
    dcd 0x00000050 // @L0207d200 - @L0207d1b0
    dcd 0x00000064 // @L0207d214 - @L0207d1b0
    dcd 0x00000078 // @L0207d228 - @L0207d1b0
    dcd 0x0000008c // @L0207d23c - @L0207d1b0
    dcd 0x000000a0 // @L0207d250 - @L0207d1b0
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x000000b4
    dcd 0x00000000
@L0207d1d8:
    dcd 0x03030202
    dcd 0x00000403
    dcd 0x00000004
    dcd 0x00000000
@L0207d1e8:
    mov r5, #4
    mov r6, #4
    stmfd sp!, {r4, r5, r6, r11, r12, lr}
    add r9, r0, #0x3bc
    ldmia r9, {r5, r6}
    b @L0207c458
@L0207d200:
    str lr, [sp, #-4]!
    mov r5, #4
    mov r6, #4
    bl @L0207c438
    ldr pc, [sp], #4
@L0207d214:
    str lr, [sp, #-4]!
    mov r5, #8
    mov r6, #4
    bl @L0207c438
    ldr pc, [sp], #4
@L0207d228:
    str lr, [sp, #-4]!
    mov r5, #0xc
    mov r6, #4
    bl @L0207c438
    ldr pc, [sp], #4
@L0207d23c:
    str lr, [sp, #-4]!
    mov r5, #0x10
    mov r6, #4
    bl @L0207c438
    ldr pc, [sp], #4
@L0207d250:
    str lr, [sp, #-4]!
    mov r5, #0x14
    mov r6, #4
    bl @L0207c438
    ldr pc, [sp], #4
@L0207d264:
    str lr, [sp, #-4]!
    bl @L0207d374
    add r11, r11, #0x200
    bl @L0207d374
    sub r11, r11, #0x200
    ldr pc, [sp], #4
@L0207d27c:
    mov r6, r3, lsr #0x1c
    sub r5, pc, #0xe8 // @L0207d1a0
    ldrb r5, [r5, r6]
    sub r6, pc, #0xb8 // @L0207d1d8
    ldrb r6, [r6, r5]
    mov r3, r3, lsl r6
    subs r2, r2, r6
    mov r8, lr
    bllt @L0207dd1c
    sub r6, pc, #0xf8 // @L0207d1b0
    ldr r5, [r6, r5, lsl #2]
    mov lr, r8
    add pc, r5, r6
@L0207d2b0:
    dcd 0x01010405
    dcd 0x02030000
@L0207d2b8:
    dcd 0x00000040 // @L0207d2f8 - @L0207d2b8
    dcd 0x00000058 // @L0207d310 - @L0207d2b8
    dcd 0x0000006c // @L0207d324 - @L0207d2b8
    dcd 0x00000080 // @L0207d338 - @L0207d2b8
    dcd 0x00000094 // @L0207d34c - @L0207d2b8
    dcd 0x000000a8 // @L0207d360 - @L0207d2b8
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x00000000
@L0207d2e0:
    dcd 0x03030202
    dcd 0x00000303
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x00000000
    dcd 0x00000000
@L0207d2f8:
    mov r5, #4
    mov r6, #2
    stmfd sp!, {r4, r5, r6, r11, r12, lr}
    add r9, r0, #0x3bc
    ldmia r9, {r5, r6}
    b @L0207c458
@L0207d310:
    str lr, [sp, #-4]!
    mov r5, #4
    mov r6, #2
    bl @L0207c438
    ldr pc, [sp], #4
@L0207d324:
    str lr, [sp, #-4]!
    mov r5, #8
    mov r6, #2
    bl @L0207c438
    ldr pc, [sp], #4
@L0207d338:
    str lr, [sp, #-4]!
    mov r5, #0xc
    mov r6, #2
    bl @L0207c438
    ldr pc, [sp], #4
@L0207d34c:
    str lr, [sp, #-4]!
    mov r5, #0x10
    mov r6, #2
    bl @L0207c438
    ldr pc, [sp], #4
@L0207d360:
    str lr, [sp, #-4]!
    mov r5, #0x14
    mov r6, #2
    bl @L0207c438
    ldr pc, [sp], #4
@L0207d374:
    mov r6, r3, lsr #0x1d
    sub r5, pc, #0xd0 // @L0207d2b0
    ldrb r5, [r5, r6]
    sub r6, pc, #0xa8 // @L0207d2e0
    ldrb r6, [r6, r5]
    mov r3, r3, lsl r6
    subs r2, r2, r6
    mov r8, lr
    bllt @L0207dd1c
    sub r6, pc, #0xe8 // @L0207d2b8
    ldr r5, [r6, r5, lsl #2]
    mov lr, r8
    add pc, r5, r6
@L0207d3a8:
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    ldr r1, [r0]
    mov r2, #0
    ldrh r3, [r1], #2
    mov r3, r3, lsl #0x10
    adds r3, r3, r3
    bhs @L0207d4d4
    subs r2, r2, #1
    bllt @L0207dd1c
    bl @L0207dd30
    cmp r6, #0
    ldrne r4, [r0, #0x3b4]
    addne r4, r4, r6
    blne @L0208060c
    ldr r11, [r0, #0x3c]
    str r11, [r0, #0x3b8]
    add r4, r0, #0x3c4
    mov r5, #0
    mov r6, #0
    ldr r12, [r0, #4]
    add r12, r12, #0x20
@L0207d3fc:
    stmia r4!, {r5, r6}
    subs r12, r12, #0x10
    bne @L0207d3fc
    mov r11, #0
    ldr r12, [r0, #8]
@L0207d410:
    str r12, [sp, #-4]!
    add r4, r0, #0x3c4
    ldr r12, [r0, #4]
@L0207d41c:
    ldmia r4, {r5, r6, r7, r8, r9, r10}
    add r4, r4, #8
    cmp r5, r7
    movgt lr, r5
    movgt r5, r7
    movgt r7, lr
    cmp r7, r9
    movgt lr, r7
    movgt r7, r9
    movgt r9, lr
    cmp r5, r7
    movgt lr, r5
    movgt r5, r7
    movgt r7, lr
    cmp r6, r8
    movgt lr, r6
    movgt r6, r8
    movgt r8, lr
    cmp r8, r10
    movgt lr, r8
    movgt r8, r10
    movgt r10, lr
    cmp r6, r8
    movgt lr, r6
    movgt r6, r8
    movgt r8, lr
    add lr, r0, #0x3bc
    stmia lr, {r7, r8}
    mov r7, #0
    mov r8, #0
    stmia r4, {r7, r8}
    bl @L0207bf64
    add r11, r11, #0x10
    subs r12, r12, #0x10
    bne @L0207d41c
    ldr r12, [sp], #4
    ldr r10, [r0, #4]
    add r11, r11, #0x1000
    sub r11, r11, r10
    subs r12, r12, #0x10
    bne @L0207d410
    ldr r2, [r0]
    sub r0, r1, r2
    sub r0, r0, #2
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    bx lr
@L0207d4d4:
    adds r3, r3, r3
    movhs r11, #1
    movlo r11, #0
    str r11, [r0, #0x48]
    adds r3, r3, r3
    ldrlo r11, [r0, #0x3c]
    ldrhs r11, [r0, #0x40]
    str r11, [r0, #0x3b8]
    subs r2, r2, #3
    bllt @L0207dd1c
    mov r4, r3, lsr #0x1a
    mov r3, r3, lsl #6
    subs r2, r2, #6
    bllt @L0207dd1c
    ldr r5, [r0, #0x3b4]
    cmp r5, r4
    blne @L0208060c
    mov r11, #0
    ldr r12, [r0, #8]
@L0207d520:
    str r12, [sp, #-4]!
    ldr r12, [r0, #4]
@L0207d528:
    adds r3, r3, r3
    addhs r4, pc, #0x14c // @L0207d680
    addlo r4, pc, #0x84 // @L0207d5bc
    subs r2, r2, #1
    bllt @L0207dd1c
    add lr, pc, #0 // @L0207d544
    bx r4
@L0207d544:
    add r11, r11, #0x10
    subs r12, r12, #0x10
    bne @L0207d528
    ldr r12, [sp], #4
    ldr r10, [r0, #4]
    add r11, r11, #0x1000
    sub r11, r11, r10
    subs r12, r12, #0x10
    bne @L0207d520
    ldr r2, [r0]
    sub r0, r1, r2
    sub r0, r0, #2
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, r12, lr}
    bx lr
@L0207d57c:
    dcd 0x0f3f1f00
    dcd 0x01020408
    dcd 0x0d1b0e0b
    dcd 0x170c0703
    dcd 0x051e0a1d
    dcd 0x3b372f10
    dcd 0x093e3d13
    dcd 0x1a15061c
    dcd 0x14121133
    dcd 0x353c2018
    dcd 0x303a1619
    dcd 0x34273231
    dcd 0x38392d2b
    dcd 0x212e3623
    dcd 0x2c242225
    dcd 0x2629282a
@L0207d5bc:
    stmfd sp!, {r4, r12, lr}
    bl @L0207dcec
    sub r4, pc, #0x50 // @L0207d57c
    ldrb r4, [r4, r6]
    mov r12, r3, lsr #0x1d
    mov r3, r3, lsl #3
    subs r2, r2, #3
    bllt @L0207dd1c
    ldr r10, [r0, #0xc]
    add r11, r11, r10
    cmp r12, #2
    moveq r12, #9
    bleq @L0207dd70
    str r4, [sp, #-4]!
    tst r4, #1
    add lr, pc, #0xc // @L0207d60c
    bne @L0207dac0
    add r5, pc, #0x2c8 // @L0207d8d0
    ldr r6, [r5, r12, lsl #2]
    add pc, r6, r5
@L0207d60c:
    add r11, r11, #8
    ldr r4, [sp]
    tst r4, #2
    add lr, pc, #0xc // @L0207d62c
    bne @L0207dac0
    add r5, pc, #0x2a8 // @L0207d8d0
    ldr r6, [r5, r12, lsl #2]
    add pc, r6, r5
@L0207d62c:
    add r11, r11, #0x800
    sub r11, r11, #8
    ldr r4, [sp]
    tst r4, #4
    add lr, pc, #0xc // @L0207d650
    bne @L0207dac0
    add r5, pc, #0x284 // @L0207d8d0
    ldr r6, [r5, r12, lsl #2]
    add pc, r6, r5
@L0207d650:
    add r11, r11, #8
    ldr r4, [sp]
    tst r4, #8
    add lr, pc, #0xc // @L0207d670
    bne @L0207dac0
    add r5, pc, #0x264 // @L0207d8d0
    ldr r6, [r5, r12, lsl #2]
    add pc, r6, r5
@L0207d670:
    sub r11, r11, #0x800
    sub r11, r11, #8
    sub r11, r11, r10
    b @L0207d848
@L0207d680:
    stmfd sp!, {r4, r12, lr}
    bl @L0207dcec
    sub r4, pc, #0x114 // @L0207d57c
    ldrb r4, [r4, r6]
    ldr r10, [r0, #0xc]
    add r11, r11, r10
    str r4, [sp, #-4]!
    add r5, r0, #0x55
    tst r4, #1
    add lr, pc, #4 // @L0207d6b0
    beq @L0207d7d8
    bne @L0207d920
@L0207d6b0:
    add r11, r11, #8
    add r5, r0, #0x57
    ldr r4, [sp]
    tst r4, #2
    add lr, pc, #4 // @L0207d6cc
    beq @L0207d7d8
    bne @L0207d920
@L0207d6cc:
    add r11, r11, #0x800
    sub r11, r11, #8
    add r5, r0, #0x65
    ldr r4, [sp]
    tst r4, #4
    add lr, pc, #4 // @L0207d6ec
    beq @L0207d7d8
    bne @L0207d920
@L0207d6ec:
    add r11, r11, #8
    add r5, r0, #0x67
    ldr r4, [sp]
    tst r4, #8
    add lr, pc, #4 // @L0207d708
    beq @L0207d7d8
    bne @L0207d920
@L0207d708:
    sub r11, r11, #0x800
    sub r11, r11, #8
    sub r11, r11, r10
    b @L0207d848
@L0207d718:
    dcd 0x01040f00
    dcd 0x030c0208
    dcd 0x070d0a05
    dcd 0x091f0b0e
    dcd 0x1e3f1006
    dcd 0x1c1b1d17
    dcd 0x121a1813
    dcd 0x20151411
    dcd 0x3719162f
    dcd 0x3c3b3e3d
    dcd 0x24213533
    dcd 0x2c232822
    dcd 0x252d2730
    dcd 0x2a2e2b3a
    dcd 0x32383431
    dcd 0x36392629
@L0207d758:
    stmfd sp!, {r4, r12, lr}
    bl @L0207dcec
    sub r12, pc, #0x50 // @L0207d718
    ldrb r12, [r12, r6]
    ldr r10, [r0, #0xc]
    add r11, r11, r10
    tst r12, #1
    blne @L0207dae4
    add r11, r11, #8
    tst r12, #2
    blne @L0207dae4
    add r11, r11, #0x800
    sub r11, r11, #8
    tst r12, #4
    blne @L0207dae4
    add r11, r11, #8
    tst r12, #8
    blne @L0207dae4
    sub r11, r11, #0x800
    sub r11, r11, #8
    sub r11, r11, r10
    ldr r10, [r0, #0x24]
    add r11, r10, r11, lsr #1
    tst r12, #0x10
    blne @L0207dae4
    add r10, r10, #0x80
    add r11, r11, #0x80
    tst r12, #0x20
    blne @L0207dae4
    sub r11, r11, r10
    mov r11, r11, lsl #1
    ldmfd sp!, {r4, r12, pc}
@L0207d7d8:
    ldrb r12, [r5, #-8]
    ldrb r6, [r5, #-1]
    cmp r12, r6
    movgt r12, r6
    cmp r12, #9
    moveq r12, #3
    mov r6, r3, lsr #0x1c
    cmp r6, r12
    addge r6, r6, #1
    cmp r6, #9
    movlt r12, r6
    movlt r7, #4
    movge r7, #1
    strb r12, [r5]
    strb r12, [r5, #1]
    strb r12, [r5, #8]
    strb r12, [r5, #9]
    add r6, pc, #0xac // @L0207d8d0
    ldr r12, [r6, r12, lsl #2]
    add r6, r6, r12
    mov r3, r3, lsl r7
    subs r2, r2, r7
    mov r8, r10
    mov r12, lr
    bllt @L0207dd1c
    mov r10, r8
    mov lr, r12
    mov pc, r6
@L0207d848:
    mov r12, r3, lsr #0x1d
    mov r3, r3, lsl #3
    subs r2, r2, #3
    bllt @L0207dd1c
    ldr r10, [r0, #0x24]
    add r11, r10, r11, lsr #1
    cmp r12, #2
    bne @L0207d884
    mov r12, #9
    bl @L0207e280
    add r10, r10, #0x80
    add r11, r11, #0x80
    bl @L0207e280
    sub r10, r10, #0x80
    sub r11, r11, #0x80
@L0207d884:
    ldr r4, [sp]
    tst r4, #0x10
    add lr, pc, #0xc // @L0207d8a0
    bne @L0207dac0
    add r5, pc, #0x34 // @L0207d8d0
    ldr r6, [r5, r12, lsl #2]
    add pc, r6, r5
@L0207d8a0:
    add r10, r10, #0x80
    add r11, r11, #0x80
    ldr r4, [sp], #4
    tst r4, #0x20
    add lr, pc, #0xc // @L0207d8c4
    bne @L0207dac0
    add r5, pc, #0x10 // @L0207d8d0
    ldr r6, [r5, r12, lsl #2]
    add pc, r6, r5
@L0207d8c4:
    sub r11, r11, r10
    mov r11, r11, lsl #1
    ldmfd sp!, {r4, r12, pc}
@L0207d8d0:
    dcd 0x0000089c // @L0207e16c - @L0207d8d0
    dcd 0x000008e8 // @L0207e1b8 - @L0207d8d0
    dcd 0x000009b0 // @L0207e280 - @L0207d8d0
    dcd 0x00000e2c // @L0207e6fc - @L0207d8d0
    dcd 0x00000e50 // @L0207e720 - @L0207d8d0
    dcd 0x00000ff4 // @L0207e8c4 - @L0207d8d0
    dcd 0x0000124c // @L0207eb1c - @L0207d8d0
    dcd 0x000015a0 // @L0207ee70 - @L0207d8d0
    dcd 0x000017d8 // @L0207f0a8 - @L0207d8d0
    dcd 0x0000049c // @L0207dd6c - @L0207d8d0
    dcd 0x00001b18 // @L0207f3e8 - @L0207d8d0
    dcd 0x00001b34 // @L0207f404 - @L0207d8d0
    dcd 0x00001b7c // @L0207f44c - @L0207d8d0
    dcd 0x00001de0 // @L0207f6b0 - @L0207d8d0
    dcd 0x00001e04 // @L0207f6d4 - @L0207d8d0
    dcd 0x00001ea4 // @L0207f774 - @L0207d8d0
    dcd 0x00001fa8 // @L0207f878 - @L0207d8d0
    dcd 0x000020b0 // @L0207f980 - @L0207d8d0
    dcd 0x00002198 // @L0207fa68 - @L0207d8d0
    dcd 0x0000049c // @L0207dd6c - @L0207d8d0
@L0207d920:
    tst r3, #0x80000000
    beq @L0207d9ec
    add r3, r3, r3
    sub r2, r2, #1
    ldrb r12, [r5, #-8]
    ldrb r6, [r5, #-1]
    cmp r12, r6
    movgt r12, r6
    cmp r12, #9
    moveq r12, #3
    mov r6, r3, lsr #0x1c
    cmp r6, r12
    addge r6, r6, #1
    cmp r6, #9
    movlt r12, r6
    movlt r7, #4
    movge r7, #1
    mov r3, r3, lsl r7
    subs r2, r2, r7
    mov r7, lr
    mov r8, r10
    bllt @L0207dd1c
    mov lr, r7
    mov r10, r8
    strb r12, [r5]
    strb r12, [r5, #1]
    strb r12, [r5, #8]
    strb r12, [r5, #9]
    b @L0207dad0
@L0207d994:
    ldrb r12, [r5, #-8]
    ldrb r6, [r5, #-1]
    cmp r12, r6
    movgt r12, r6
    cmp r12, #9
    moveq r12, #3
    mov r6, r3, lsr #0x1c
    cmp r6, r12
    addge r6, r6, #1
    cmp r6, #9
    movlt r12, r6
    movlt r7, #4
    movge r7, #1
    strb r12, [r5]
    add r12, r12, #0xa
    mov r3, r3, lsl r7
    subs r2, r2, r7
    mov r8, r10
    mov r6, lr
    bllt @L0207dd1c
    mov r10, r8
    mov pc, r6
@L0207d9ec:
    stmfd sp!, {r5, lr}
    mov r8, r10
    bl @L0207dcec
    add r4, pc, #0xac // @L0207daac
    ldrb r4, [r4, r6]
    mov r10, r8
    str r4, [sp, #-4]!
    bl @L0207d994
    tst r4, #1
    add lr, pc, #0xc // @L0207da24
    bne @L0207dc88
    sub r6, pc, #0x150 // @L0207d8d0
    ldr r7, [r6, r12, lsl #2]
    add pc, r6, r7
@L0207da24:
    add r11, r11, #4
    ldmia sp, {r4, r5}
    add r5, r5, #1
    bl @L0207d994
    tst r4, #2
    add lr, pc, #0xc // @L0207da4c
    bne @L0207dc88
    sub r6, pc, #0x178 // @L0207d8d0
    ldr r7, [r6, r12, lsl #2]
    add pc, r6, r7
@L0207da4c:
    add r11, r11, #0x400
    sub r11, r11, #4
    ldmia sp, {r4, r5}
    add r5, r5, #8
    bl @L0207d994
    tst r4, #4
    add lr, pc, #0xc // @L0207da78
    bne @L0207dc88
    sub r6, pc, #0x1a4 // @L0207d8d0
    ldr r7, [r6, r12, lsl #2]
    add pc, r6, r7
@L0207da78:
    add r11, r11, #4
    ldmfd sp!, {r4, r5}
    add r5, r5, #9
    bl @L0207d994
    tst r4, #8
    add lr, pc, #0xc // @L0207daa0
    bne @L0207dc88
    sub r6, pc, #0x1cc // @L0207d8d0
    ldr r7, [r6, r12, lsl #2]
    add pc, r6, r7
@L0207daa0:
    sub r11, r11, #0x400
    sub r11, r11, #4
    ldr pc, [sp], #4
@L0207daac:
    dcd 0x02000f00
    dcd 0x0c080401
    dcd 0x0e0d0b03
    dcd 0x09050a07
    dcd 0x00000006
@L0207dac0:
    tst r3, #0x80000000
    beq @L0207dbe0
    add r3, r3, r3
    sub r2, r2, #1
@L0207dad0:
    stmfd sp!, {r10, r11, r12, lr}
    add lr, pc, #0x1c // @L0207daf8
    sub r5, pc, #0x210 // @L0207d8d0
    ldr r12, [r5, r12, lsl #2]
    add pc, r12, r5
@L0207dae4:
    tst r3, #0x80000000
    beq @L0207db8c
    add r3, r3, r3
    sub r2, r2, #1
    stmfd sp!, {r10, r11, r12, lr}
@L0207daf8:
    mov r4, #0
    mov r5, #0
    mov r6, #0
    mov r7, #0
    mov r8, #0
    mov r9, #0
    mov r10, #0
    mov r11, #0
    add r12, r0, #0x1b4
    stmia r12!, {r4, r5, r6, r7, r8, r9, r10, r11}
    stmia r12!, {r4, r5, r6, r7, r8, r9, r10, r11}
    stmia r12!, {r4, r5, r6, r7, r8, r9, r10, r11}
    stmia r12!, {r4, r5, r6, r7, r8, r9, r10, r11}
    stmia r12!, {r4, r5, r6, r7, r8, r9, r10, r11}
    stmia r12!, {r4, r5, r6, r7, r8, r9, r10, r11}
    stmia r12!, {r4, r5, r6, r7, r8, r9, r10, r11}
    stmia r12!, {r4, r5, r6, r7, r8, r9, r10, r11}
    add r12, r0, #0x74
    bl @L0207fc54
    sub r12, r12, r0
    add r4, pc, #0x38 // @L0207db88
    add r4, r4, #0x2600
    cmp r12, #0x78
    movle pc, r4
    add r4, pc, #8 // @L0207db68
    add r4, r4, #0x2500
    cmp r12, #0x80
    movle pc, r4
@L0207db68:
    add r4, pc, #0x4c // @L0207dbbc
    add r4, r4, #0x2300
    cmp r12, #0x9c
    movle pc, r4
    b @L0207fcc4
@L0207db7c:
    dcd 0x08010400
    dcd 0x05030c02
    dcd 0x0d070f0a
@L0207db88:
    dcd 0x06090b0e
@L0207db8c:
    stmfd sp!, {r12, lr}
    mov r8, r10
    bl @L0207dcec
    mov r10, r8
    sub r12, pc, #0x28 // @L0207db7c
    ldrb r12, [r12, r6]
    tst r12, #1
    blne @L0207dc9c
    add r11, r11, #4
    tst r12, #2
    blne @L0207dc9c
    add r11, r11, #0x400
@L0207dbbc:
    sub r11, r11, #4
    tst r12, #4
    blne @L0207dc9c
    add r11, r11, #4
    tst r12, #8
    blne @L0207dc9c
    sub r11, r11, #0x400
    sub r11, r11, #4
    ldmfd sp!, {r12, pc}
@L0207dbe0:
    stmfd sp!, {r12, lr}
    add r12, r12, #0xa
    mov r8, r10
    bl @L0207dcec
    sub r4, pc, #0x14c // @L0207daac
    ldrb r4, [r4, r6]
    mov r10, r8
    str r4, [sp, #-4]!
    tst r4, #1
    add lr, pc, #0xc // @L0207dc18
    bne @L0207dc88
    sub r6, pc, #0x344 // @L0207d8d0
    ldr r7, [r6, r12, lsl #2]
    add pc, r6, r7
@L0207dc18:
    add r11, r11, #4
    ldr r4, [sp]
    tst r4, #2
    add lr, pc, #0xc // @L0207dc38
    bne @L0207dc88
    sub r6, pc, #0x364 // @L0207d8d0
    ldr r7, [r6, r12, lsl #2]
    add pc, r6, r7
@L0207dc38:
    add r11, r11, #0x400
    sub r11, r11, #4
    ldr r4, [sp]
    tst r4, #4
    add lr, pc, #0xc // @L0207dc5c
    bne @L0207dc88
    sub r6, pc, #0x388 // @L0207d8d0
    ldr r7, [r6, r12, lsl #2]
    add pc, r6, r7
@L0207dc5c:
    add r11, r11, #4
    ldr r4, [sp], #4
    tst r4, #8
    add lr, pc, #0xc // @L0207dc7c
    bne @L0207dc88
    sub r6, pc, #0x3a8 // @L0207d8d0
    ldr r7, [r6, r12, lsl #2]
    add pc, r6, r7
@L0207dc7c:
    sub r11, r11, #0x400
    sub r11, r11, #4
    ldmfd sp!, {r12, pc}
@L0207dc88:
    stmfd sp!, {r10, r11, r12, lr}
    add lr, pc, #0xc // @L0207dca0
    sub r6, pc, #0x3c8 // @L0207d8d0
    ldr r7, [r6, r12, lsl #2]
    add pc, r6, r7
@L0207dc9c:
    stmfd sp!, {r10, r11, r12, lr}
@L0207dca0:
    mov r4, #0
    mov r5, #0
    mov r6, #0
    mov r7, #0
    mov r8, #0
    mov r9, #0
    mov r10, #0
    mov r11, #0
    add r12, r0, #0x1b4
    stmia r12!, {r4, r5, r6, r7, r8, r9, r10, r11}
    stmia r12!, {r4, r5, r6, r7, r8, r9, r10, r11}
    add r12, r0, #0x174
    bl @L0207fc54
    sub r12, r12, r0
    add r4, pc, #0x28 // @L0207dd08
    add r4, r4, #0x2600
    cmp r12, #0x178
    movle pc, r4
    b @L02080234
@L0207dcec:
    clz r10, r3
    mov r3, r3, lsl r10
    add r3, r3, r3
    rsb r9, r10, #0x20
    mov r6, r3, lsr r9
    mov r9, #1
    add r6, r6, r9, lsl r10
@L0207dd08:
    sub r6, r6, #1
    mov r3, r3, lsl r10
    sub r2, r2, r10, lsl #1
    subs r2, r2, #1
    movge pc, lr
@L0207dd1c:
    ldrh r10, [r1], #2
    add r2, r2, #0x10
    rsb r9, r2, #0x10
    orr r3, r3, r10, lsl r9
    mov pc, lr
@L0207dd30:
    clz r10, r3
    mov r3, r3, lsl r10
    add r3, r3, r3
    rsb r9, r10, #0x20
    mov r6, r3, lsr r9
    mov r9, #1
    add r6, r6, r9, lsl r10
    tst r6, #1
    rsbne r6, r6, #1
    mov r6, r6, asr #1
    mov r3, r3, lsl r10
    sub r2, r2, r10, lsl #1
    subs r2, r2, #1
    movge pc, lr
    b @L0207dd1c
@L0207dd6c:
    mov pc, lr
@L0207dd70:
    stmfd sp!, {r4, r10, r12, lr}
    bl @L0207dd30
    stmfd sp!, {r0, r1, r2, r3}
    sub lr, r11, #0x100
    ldmia lr, {r0, r1, r2, r3}
    add lr, r11, #0xf00
    ldrb r4, [lr, #-1]
    mov r10, r3, lsr #0x18
    add r5, r4, r10
    add r5, r5, #1
    mov r5, r5, asr #1
    add r5, r5, r6, lsl #1
    sub r6, r5, r4
    add r6, r6, #1
    mov r4, r4, lsl #3
    sub sp, sp, #0x80
    mov lr, sp
    add r4, r4, r6, asr #1
    mov r8, #0xff
    and r7, r8, r0
    sub r8, r4, r7, lsl #3
    add r8, r8, #1
    mov r7, r7, lsl #6
    add r4, r4, r6, asr #1
    mov r12, #0xff
    and r9, r12, r0, lsr #8
    sub r12, r4, r9, lsl #3
    add r12, r12, #1
    mov r9, r9, lsl #6
    stmia lr!, {r7, r8, r9, r12}
    add r4, r4, r6, asr #1
    mov r8, #0xff
    and r7, r8, r0, lsr #16
    sub r8, r4, r7, lsl #3
    add r8, r8, #1
    mov r7, r7, lsl #6
    add r4, r4, r6, asr #1
    mov r12, #0xff
    and r9, r12, r0, lsr #24
    sub r12, r4, r9, lsl #3
    add r12, r12, #1
    mov r9, r9, lsl #6
    stmia lr!, {r7, r8, r9, r12}
    add r4, r4, r6, asr #1
    mov r8, #0xff
    and r7, r8, r1
    sub r8, r4, r7, lsl #3
    add r8, r8, #1
    mov r7, r7, lsl #6
    add r4, r4, r6, asr #1
    mov r12, #0xff
    and r9, r12, r1, lsr #8
    sub r12, r4, r9, lsl #3
    add r12, r12, #1
    mov r9, r9, lsl #6
    stmia lr!, {r7, r8, r9, r12}
    add r4, r4, r6, asr #1
    mov r8, #0xff
    and r7, r8, r1, lsr #16
    sub r8, r4, r7, lsl #3
    add r8, r8, #1
    mov r7, r7, lsl #6
    add r4, r4, r6, asr #1
    mov r12, #0xff
    and r9, r12, r1, lsr #24
    sub r12, r4, r9, lsl #3
    add r12, r12, #1
    mov r9, r9, lsl #6
    stmia lr!, {r7, r8, r9, r12}
    add r4, r4, r6, asr #1
    mov r8, #0xff
    and r7, r8, r2
    sub r8, r4, r7, lsl #3
    add r8, r8, #1
    mov r7, r7, lsl #6
    add r4, r4, r6, asr #1
    mov r12, #0xff
    and r9, r12, r2, lsr #8
    sub r12, r4, r9, lsl #3
    add r12, r12, #1
    mov r9, r9, lsl #6
    stmia lr!, {r7, r8, r9, r12}
    add r4, r4, r6, asr #1
    mov r8, #0xff
    and r7, r8, r2, lsr #16
    sub r8, r4, r7, lsl #3
    add r8, r8, #1
    mov r7, r7, lsl #6
    add r4, r4, r6, asr #1
    mov r12, #0xff
    and r9, r12, r2, lsr #24
    sub r12, r4, r9, lsl #3
    add r12, r12, #1
    mov r9, r9, lsl #6
    stmia lr!, {r7, r8, r9, r12}
    add r4, r4, r6, asr #1
    mov r8, #0xff
    and r7, r8, r3
    sub r8, r4, r7, lsl #3
    add r8, r8, #1
    mov r7, r7, lsl #6
    add r4, r4, r6, asr #1
    mov r12, #0xff
    and r9, r12, r3, lsr #8
    sub r12, r4, r9, lsl #3
    add r12, r12, #1
    mov r9, r9, lsl #6
    stmia lr!, {r7, r8, r9, r12}
    add r4, r4, r6, asr #1
    mov r8, #0xff
    and r7, r8, r3, lsr #16
    sub r8, r4, r7, lsl #3
    add r8, r8, #1
    mov r7, r7, lsl #6
    add r4, r4, r6, asr #1
    mov r12, #0xff
    and r9, r12, r3, lsr #24
    sub r12, r4, r9, lsl #3
    add r12, r12, #1
    mov r9, r9, lsl #6
    stmia lr!, {r7, r8, r9, r12}
    sub r9, r5, r10
    add r9, r9, #1
    mov r10, r10, lsl #3
    mov lr, #0x10
@L0207df64:
    add r10, r10, r9, asr #1
    ldrb r8, [r11, #-1]
    sub r7, r10, r8, lsl #3
    add r7, r7, #1
    mov r8, r8, lsl #6
    add r12, sp, #0
    ldmia r12, {r0, r1, r2, r3, r4, r5, r6, r12}
    add r0, r0, r1, asr #1
    add r2, r2, r3, asr #1
    add r4, r4, r5, asr #1
    add r6, r6, r12, asr #1
    str r0, [sp]
    str r2, [sp, #8]
    str r4, [sp, #0x10]
    str r6, [sp, #0x18]
    add r8, r8, r7, asr #1
    add r5, r0, r8
    add r5, r5, #0x40
    mov r5, r5, asr #7
    add r8, r8, r7, asr #1
    add r12, r2, r8
    add r12, r12, #0x40
    mov r12, r12, asr #7
    orr r5, r5, r12, lsl #8
    add r8, r8, r7, asr #1
    add r12, r4, r8
    add r12, r12, #0x40
    mov r12, r12, asr #7
    orr r5, r5, r12, lsl #16
    add r8, r8, r7, asr #1
    add r12, r6, r8
    add r12, r12, #0x40
    mov r12, r12, asr #7
    orr r5, r5, r12, lsl #24
    str r5, [r11], #4
    add r12, sp, #0x20
    ldmia r12, {r0, r1, r2, r3, r4, r5, r6, r12}
    add r0, r0, r1, asr #1
    add r2, r2, r3, asr #1
    add r4, r4, r5, asr #1
    add r6, r6, r12, asr #1
    str r0, [sp, #0x20]
    str r2, [sp, #0x28]
    str r4, [sp, #0x30]
    str r6, [sp, #0x38]
    add r8, r8, r7, asr #1
    add r5, r0, r8
    add r5, r5, #0x40
    mov r5, r5, asr #7
    add r8, r8, r7, asr #1
    add r12, r2, r8
    add r12, r12, #0x40
    mov r12, r12, asr #7
    orr r5, r5, r12, lsl #8
    add r8, r8, r7, asr #1
    add r12, r4, r8
    add r12, r12, #0x40
    mov r12, r12, asr #7
    orr r5, r5, r12, lsl #16
    add r8, r8, r7, asr #1
    add r12, r6, r8
    add r12, r12, #0x40
    mov r12, r12, asr #7
    orr r5, r5, r12, lsl #24
    str r5, [r11], #4
    add r12, sp, #0x40
    ldmia r12, {r0, r1, r2, r3, r4, r5, r6, r12}
    add r0, r0, r1, asr #1
    add r2, r2, r3, asr #1
    add r4, r4, r5, asr #1
    add r6, r6, r12, asr #1
    str r0, [sp, #0x40]
    str r2, [sp, #0x48]
    str r4, [sp, #0x50]
    str r6, [sp, #0x58]
    add r8, r8, r7, asr #1
    add r5, r0, r8
    add r5, r5, #0x40
    mov r5, r5, asr #7
    add r8, r8, r7, asr #1
    add r12, r2, r8
    add r12, r12, #0x40
    mov r12, r12, asr #7
    orr r5, r5, r12, lsl #8
    add r8, r8, r7, asr #1
    add r12, r4, r8
    add r12, r12, #0x40
    mov r12, r12, asr #7
    orr r5, r5, r12, lsl #16
    add r8, r8, r7, asr #1
    add r12, r6, r8
    add r12, r12, #0x40
    mov r12, r12, asr #7
    orr r5, r5, r12, lsl #24
    str r5, [r11], #4
    add r12, sp, #0x60
    ldmia r12, {r0, r1, r2, r3, r4, r5, r6, r12}
    add r0, r0, r1, asr #1
    add r2, r2, r3, asr #1
    add r4, r4, r5, asr #1
    add r6, r6, r12, asr #1
    str r0, [sp, #0x60]
    str r2, [sp, #0x68]
    str r4, [sp, #0x70]
    str r6, [sp, #0x78]
    add r8, r8, r7, asr #1
    add r5, r0, r8
    add r5, r5, #0x40
    mov r5, r5, asr #7
    add r8, r8, r7, asr #1
    add r12, r2, r8
    add r12, r12, #0x40
    mov r12, r12, asr #7
    orr r5, r5, r12, lsl #8
    add r8, r8, r7, asr #1
    add r12, r4, r8
    add r12, r12, #0x40
    mov r12, r12, asr #7
    orr r5, r5, r12, lsl #16
    add r8, r8, r7, asr #1
    add r12, r6, r8
    add r12, r12, #0x40
    mov r12, r12, asr #7
    orr r5, r5, r12, lsl #24
    str r5, [r11], #0xf4
    subs lr, lr, #1
    bne @L0207df64
    add sp, sp, #0x80
    sub r11, r11, #0x1000
    ldmfd sp!, {r0, r1, r2, r3, r4, r10, r12, pc}
@L0207e16c:
    sub r7, r11, #0x100
    ldmia r7, {r4, r5}
    add r7, r7, #0x100
    stmia r7, {r4, r5}
    add r7, r7, #0x100
    stmia r7, {r4, r5}
    add r7, r7, #0x100
    stmia r7, {r4, r5}
    add r7, r7, #0x100
    stmia r7, {r4, r5}
    add r7, r7, #0x100
    stmia r7, {r4, r5}
    add r7, r7, #0x100
    stmia r7, {r4, r5}
    add r7, r7, #0x100
    stmia r7, {r4, r5}
    add r7, r7, #0x100
    stmia r7, {r4, r5}
    mov pc, lr
@L0207e1b8:
    ldrb r6, [r11, #-1]
    orr r6, r6, r6, lsl #8
    orr r6, r6, r6, lsl #16
    mov r7, r6
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    ldrb r6, [r11, #-1]
    orr r6, r6, r6, lsl #8
    orr r6, r6, r6, lsl #16
    mov r7, r6
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    ldrb r6, [r11, #-1]
    orr r6, r6, r6, lsl #8
    orr r6, r6, r6, lsl #16
    mov r7, r6
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    ldrb r6, [r11, #-1]
    orr r6, r6, r6, lsl #8
    orr r6, r6, r6, lsl #16
    mov r7, r6
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    ldrb r6, [r11, #-1]
    orr r6, r6, r6, lsl #8
    orr r6, r6, r6, lsl #16
    mov r7, r6
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    ldrb r6, [r11, #-1]
    orr r6, r6, r6, lsl #8
    orr r6, r6, r6, lsl #16
    mov r7, r6
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    ldrb r6, [r11, #-1]
    orr r6, r6, r6, lsl #8
    orr r6, r6, r6, lsl #16
    mov r7, r6
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    ldrb r6, [r11, #-1]
    orr r6, r6, r6, lsl #8
    orr r6, r6, r6, lsl #16
    mov r7, r6
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    sub r11, r11, #0x800
    mov pc, lr
@L0207e280:
    stmfd sp!, {r4, r10, r12, lr}
    bl @L0207dd30
    stmfd sp!, {r0, r1, r2, r3}
    sub lr, r11, #0x100
    ldmia lr, {r0, r1}
    add lr, r11, #0x700
    ldrb r4, [lr, #-1]
    mov r10, r1, lsr #0x18
    add r5, r4, r10
    add r5, r5, #1
    mov r5, r5, asr #1
    add r5, r5, r6, lsl #1
    sub r6, r5, r4
    mov r4, r4, lsl #3
    sub sp, sp, #0x40
    mov lr, sp
    mov r2, #0xff
    add r4, r4, r6
    and r7, r2, r0
    sub r8, r4, r7, lsl #3
    mov r7, r7, lsl #6
    add r4, r4, r6
    and r9, r2, r0, lsr #8
    sub r12, r4, r9, lsl #3
    mov r9, r9, lsl #6
    stmia lr!, {r7, r8, r9, r12}
    add r4, r4, r6
    and r7, r2, r0, lsr #16
    sub r8, r4, r7, lsl #3
    mov r7, r7, lsl #6
    add r4, r4, r6
    and r9, r2, r0, lsr #24
    sub r12, r4, r9, lsl #3
    mov r9, r9, lsl #6
    stmia lr!, {r7, r8, r9, r12}
    add r4, r4, r6
    and r7, r2, r1
    sub r8, r4, r7, lsl #3
    mov r7, r7, lsl #6
    add r4, r4, r6
    and r9, r2, r1, lsr #8
    sub r12, r4, r9, lsl #3
    mov r9, r9, lsl #6
    stmia lr!, {r7, r8, r9, r12}
    add r4, r4, r6
    and r7, r2, r1, lsr #16
    sub r8, r4, r7, lsl #3
    mov r7, r7, lsl #6
    add r4, r4, r6
    and r9, r2, r1, lsr #24
    sub r12, r4, r9, lsl #3
    mov r9, r9, lsl #6
    stmia lr!, {r7, r8, r9, r12}
    sub r9, r5, r10
    mov r10, r10, lsl #3
    mov lr, #8
@L0207e360:
    add r10, r10, r9
    ldrb r8, [r11, #-1]
    sub r7, r10, r8, lsl #3
    mov r8, r8, lsl #6
    add r12, sp, #0
    ldmia r12, {r0, r1, r2, r3, r4, r5, r6, r12}
    add r0, r0, r1
    add r2, r2, r3
    add r4, r4, r5
    add r6, r6, r12
    str r0, [sp]
    str r2, [sp, #8]
    str r4, [sp, #0x10]
    str r6, [sp, #0x18]
    add r8, r8, r7
    add r5, r0, r8
    add r5, r5, #0x40
    mov r5, r5, asr #7
    add r8, r8, r7
    add r12, r2, r8
    add r12, r12, #0x40
    mov r12, r12, asr #7
    orr r5, r5, r12, lsl #8
    add r8, r8, r7
    add r12, r4, r8
    add r12, r12, #0x40
    mov r12, r12, asr #7
    orr r5, r5, r12, lsl #16
    add r8, r8, r7
    add r12, r6, r8
    add r12, r12, #0x40
    mov r12, r12, asr #7
    orr r5, r5, r12, lsl #24
    str r5, [r11], #4
    add r12, sp, #0x20
    ldmia r12, {r0, r1, r2, r3, r4, r5, r6, r12}
    add r0, r0, r1
    add r2, r2, r3
    add r4, r4, r5
    add r6, r6, r12
    str r0, [sp, #0x20]
    str r2, [sp, #0x28]
    str r4, [sp, #0x30]
    str r6, [sp, #0x38]
    add r8, r8, r7
    add r5, r0, r8
    add r5, r5, #0x40
    mov r5, r5, asr #7
    add r8, r8, r7
    add r12, r2, r8
    add r12, r12, #0x40
    mov r12, r12, asr #7
    orr r5, r5, r12, lsl #8
    add r8, r8, r7
    add r12, r4, r8
    add r12, r12, #0x40
    mov r12, r12, asr #7
    orr r5, r5, r12, lsl #16
    add r8, r8, r7
    add r12, r6, r8
    add r12, r12, #0x40
    mov r12, r12, asr #7
    orr r5, r5, r12, lsl #24
    str r5, [r11], #0xfc
    subs lr, lr, #1
    bne @L0207e360
    add sp, sp, #0x40
    sub r11, r11, #0x800
    ldmfd sp!, {r0, r1, r2, r3, r4, r10, r12, pc}
@L0207e474:
    mov r6, #0
    sub r7, r11, #0x100
    ldmia r7, {r4, r5}
    add r6, r6, r4, lsr #24
    mov r4, r4, lsl #8
    add r6, r6, r4, lsr #24
    mov r4, r4, lsl #8
    add r6, r6, r4, lsr #24
    mov r4, r4, lsl #8
    add r6, r6, r4, lsr #24
    add r6, r6, r5, lsr #24
    mov r5, r5, lsl #8
    add r6, r6, r5, lsr #24
    mov r5, r5, lsl #8
    add r6, r6, r5, lsr #24
    mov r5, r5, lsl #8
    add r6, r6, r5, lsr #24
    sub r11, r11, #1
    ldrb r4, [r11], #0x100
    add r6, r6, r4
    ldrb r4, [r11], #0x100
    add r6, r6, r4
    ldrb r4, [r11], #0x100
    add r6, r6, r4
    ldrb r4, [r11], #0x100
    add r6, r6, r4
    ldrb r4, [r11], #0x100
    add r6, r6, r4
    ldrb r4, [r11], #0x100
    add r6, r6, r4
    ldrb r4, [r11], #0x100
    add r6, r6, r4
    ldrb r4, [r11], #1
    add r6, r6, r4
    add r6, r6, #8
    mov r6, r6, asr #4
    orr r6, r6, r6, lsl #8
    orr r6, r6, r6, lsl #16
    mov r7, r6
    sub r11, r11, #0x700
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    sub r11, r11, #0x700
    mov pc, lr
@L0207e558:
    mov r6, #0
    sub r11, r11, #1
    ldrb r4, [r11], #0x100
    add r6, r6, r4
    ldrb r4, [r11], #0x100
    add r6, r6, r4
    ldrb r4, [r11], #0x100
    add r6, r6, r4
    ldrb r4, [r11], #0x100
    add r6, r6, r4
    ldrb r4, [r11], #0x100
    add r6, r6, r4
    ldrb r4, [r11], #0x100
    add r6, r6, r4
    ldrb r4, [r11], #0x100
    add r6, r6, r4
    ldrb r4, [r11], #1
    add r6, r6, r4
    add r6, r6, #4
    mov r6, r6, asr #3
    orr r6, r6, r6, lsl #8
    orr r6, r6, r6, lsl #16
    mov r7, r6
    sub r11, r11, #0x700
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    sub r11, r11, #0x700
    mov pc, lr
@L0207e5fc:
    mov r6, #0
    sub r7, r11, #0x100
    ldmia r7, {r4, r5}
    add r6, r6, r4, lsr #24
    mov r4, r4, lsl #8
    add r6, r6, r4, lsr #24
    mov r4, r4, lsl #8
    add r6, r6, r4, lsr #24
    mov r4, r4, lsl #8
    add r6, r6, r4, lsr #24
    add r6, r6, r5, lsr #24
    mov r5, r5, lsl #8
    add r6, r6, r5, lsr #24
    mov r5, r5, lsl #8
    add r6, r6, r5, lsr #24
    mov r5, r5, lsl #8
    add r6, r6, r5, lsr #24
    add r6, r6, #4
    mov r6, r6, asr #3
    orr r6, r6, r6, lsl #8
    orr r6, r6, r6, lsl #16
    mov r7, r6
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    sub r11, r11, #0x700
    mov pc, lr
@L0207e698:
    mov r6, #0x80
    orr r6, r6, r6, lsl #8
    orr r6, r6, r6, lsl #16
    mov r7, r6
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    add r11, r11, #0x100
    stmia r11, {r6, r7}
    sub r11, r11, #0x700
    mov pc, lr
@L0207e6ec:
    dcd 0xffffffac // @L0207e698 - @L0207e6ec
    dcd 0xffffff10 // @L0207e5fc - @L0207e6ec
    dcd 0xfffffe6c // @L0207e558 - @L0207e6ec
    dcd 0xfffffd88 // @L0207e474 - @L0207e6ec
@L0207e6fc:
    sub r5, pc, #0x18 // @L0207e6ec
    mov r8, #0
    sub r6, r11, r10
    movs r7, r6, lsl #0x18
    addne r8, r8, #8
    cmp r6, #0x100
    addge r8, r8, #4
    ldr r6, [r5, r8]
    add pc, r5, r6
@L0207e720:
    stmfd sp!, {r3, r12, lr}
    ldrb r3, [r11, #-1]!
    ldrb r12, [r11, #0x100]!
    ldrb r9, [r11, #0x100]!
    ldrb r6, [r11, #0x100]!
    add r8, r3, r12
    add r3, r9, r3
    add r3, r3, r12, lsl #1
    add r3, r3, #2
    mov lr, r3, asr #2
    add r3, r12, r9
    add r12, r6, r12
    add r8, r8, #1
    mov r8, r8, asr #1
    add r12, r12, r9, lsl #1
    add r3, r3, #1
    mov r3, r3, asr #1
    add r12, r12, #2
    orr r8, r8, lr, lsl #8
    orr r8, r8, r3, lsl #16
    mov r12, r12, asr #2
    orr r8, r8, r12, lsl #24
    sub lr, r11, #0x300
    str r8, [lr, #1]
    add r8, r9, r6
    add r8, r8, #1
    mov lr, r8, asr #1
    ldrb r8, [r11, #0x100]!
    orr r3, r3, r12, lsl #8
    orr r3, r3, lr, lsl #16
    add r9, r8, r9
    add r9, r9, r6, lsl #1
    add r9, r9, #2
    mov r4, r9, asr #2
    add r9, r6, r8
    add r9, r9, #1
    mov r5, r9, asr #1
    ldrb r9, [r11, #0x100]!
    orr r3, r3, r4, lsl #24
    sub r7, r11, #0x400
    str r3, [r7, #1]
    add r6, r9, r6
    add r6, r6, r8, lsl #1
    add r6, r6, #2
    orr r7, lr, r4, lsl #8
    mov r6, r6, asr #2
    orr r7, r7, r5, lsl #16
    add r3, r8, r9
    add r3, r3, #1
    orr r7, r7, r6, lsl #24
    sub r12, r11, #0x500
    str r7, [r12, #5]
    mov r12, r3, asr #1
    ldrb r3, [r11, #0x100]!
    orr lr, r5, r6, lsl #8
    orr lr, lr, r12, lsl #16
    add r8, r3, r8
    add r8, r8, r9, lsl #1
    add r8, r8, #2
    mov r8, r8, asr #2
    add r4, r9, r3
    add r4, r4, #1
    orr lr, lr, r8, lsl #24
    sub r5, r11, #0x400
    str r7, [r5, #1]
    str lr, [r5, #-0xfb]
    mov r5, r4, asr #1
    ldrb r4, [r11, #0x100]
    orr r8, r12, r8, lsl #8
    orr r8, r8, r5, lsl #16
    add r9, r4, r9
    add r9, r9, r3, lsl #1
    add r12, r3, r4
    add r9, r9, #2
    mov r9, r9, asr #2
    orr r8, r8, r9, lsl #24
    add r3, r4, r3
    add r3, r3, r4, lsl #1
    add r12, r12, #1
    mov r12, r12, asr #1
    add r3, r3, #2
    orr r9, r5, r9, lsl #8
    orr r9, r9, r12, lsl #16
    mov r3, r3, asr #2
    orr r9, r9, r3, lsl #24
    sub r7, r11, #0x200
    str r8, [r7, #-0x1fb]
    str r9, [r7, #-0xfb]
    str lr, [r7, #-0xff]
    str r8, [r7, #1]
    orr r8, r12, r3, lsl #8
    str r9, [r11, #-0xff]
    orr r9, r4, r4, lsl #8
    orr r8, r8, r4, lsl #16
    orr r8, r8, r4, lsl #24
    orr r9, r9, r4, lsl #16
    orr r9, r9, r4, lsl #24
    str r8, [r11, #-0x1fb]
    str r9, [r11, #-0xfb]
    add r11, r11, #1
    stmia r11, {r8, r9}
    str r9, [r11, #0x100]
    str r9, [r11, #0x104]
    sub r11, r11, #0x600
    ldmfd sp!, {r3, r12, pc}
@L0207e8c4:
    stmfd sp!, {r0, r1, r2, r3, r10, r12, lr}
    sub r0, r11, #0x100
    ldmia r0, {r3, r12}
    add r0, r0, #0x100
    ldrb r1, [r0, #-1]
    ldrb r2, [r0, #-0x101]
    add r4, r1, r2
    add r4, r4, #1
    mov lr, r4, asr #1
    and r7, r3, #0xff
    add r4, r7, r1
    add r4, r4, r2, lsl #1
    add r4, r4, #2
    mov r5, r4, asr #2
    mov r4, r3, lsl #0x10
    mov r4, r4, lsr #0x18
    add r6, r2, r4
    mov r8, r3, lsl #8
    add r6, r6, r7, lsl #1
    mov r9, r8, lsr #0x18
    add r7, r7, r9
    add r7, r7, r4, lsl #1
    add r6, r6, #2
    mov r3, r3, lsr #0x18
    add r4, r4, r3
    mov r6, r6, asr #2
    add r7, r7, #2
    orr r8, lr, r5, lsl #8
    orr r8, r8, r6, lsl #16
    mov r7, r7, asr #2
    add r4, r4, r9, lsl #1
    add r4, r4, #2
    orr r11, r8, r7, lsl #24
    mov r8, r4, asr #2
    and r4, r12, #0xff
    mov r10, r12, lsl #0x10
    mov r10, r10, lsr #0x18
    add r9, r9, r4
    add r9, r9, r3, lsl #1
    mov r12, r12, lsl #8
    add r12, r4, r12, lsr #24
    add r3, r3, r10
    add r3, r3, r4, lsl #1
    add r9, r9, #2
    mov r9, r9, asr #2
    add r3, r3, #2
    add r12, r12, r10, lsl #1
    add r12, r12, #2
    mov r3, r3, asr #2
    orr r4, r8, r9, lsl #8
    orr r3, r4, r3, lsl #16
    mov r12, r12, asr #2
    orr r12, r3, r12, lsl #24
    stmia r0, {r11, r12}
    ldrb r12, [r0, #0xff]
    add r2, r2, r12
    add r2, r2, r1, lsl #1
    add r3, r12, r1
    add r3, r3, #1
    add r2, r2, #2
    mov r2, r2, asr #2
    mov r3, r3, asr #1
    orr r4, r3, r2, lsl #8
    orr r4, r4, lr, lsl #16
    orr lr, r6, r7, lsl #8
    orr lr, lr, r8, lsl #16
    orr lr, lr, r9, lsl #24
    orr r4, r4, r5, lsl #24
    add r0, r0, #0x100
    stmia r0, {r4, lr}
    ldrb lr, [r0, #0xff]
    add r1, r1, lr
    add r1, r1, r12, lsl #1
    add r5, lr, r12
    add r5, r5, #1
    add r1, r1, #2
    mov r1, r1, asr #2
    mov r5, r5, asr #1
    orr r6, r5, r1, lsl #8
    orr r3, r6, r3, lsl #16
    orr r2, r3, r2, lsl #24
    add r6, r0, #0x100
    stmia r6, {r2, r11}
    ldrb r3, [r0, #0x1ff]
    add r12, r12, r3
    add r12, r12, lr, lsl #1
    add r6, r3, lr
    add r6, r6, #1
    add r12, r12, #2
    mov r12, r12, asr #2
    mov r6, r6, asr #1
    orr r7, r6, r12, lsl #8
    orr r5, r7, r5, lsl #16
    orr r1, r5, r1, lsl #24
    add r0, r0, #0x200
    stmia r0, {r1, r4}
    ldrb r4, [r0, #0xff]
    str r2, [r0, #0x104]
    add lr, lr, r4
    add lr, lr, r3, lsl #1
    add r5, r4, r3
    add r5, r5, #1
    add lr, lr, #2
    mov lr, lr, asr #2
    mov r5, r5, asr #1
    orr r7, r5, lr, lsl #8
    orr r6, r7, r6, lsl #16
    orr r12, r6, r12, lsl #24
    str r12, [r0, #0x100]!
    ldrb r2, [r0, #0xff]
    str r1, [r0, #0x104]
    add r3, r3, r2
    add r3, r3, r4, lsl #1
    add r6, r2, r4
    add r6, r6, #1
    add r3, r3, #2
    mov r3, r3, asr #2
    mov r6, r6, asr #1
    orr r7, r6, r3, lsl #8
    orr r5, r7, r5, lsl #16
    orr lr, r5, lr, lsl #24
    str lr, [r0, #0x100]!
    ldrb r1, [r0, #0xff]
    str r12, [r0, #0x104]
    add r4, r4, r1
    add r4, r4, r2, lsl #1
    add r5, r1, r2
    add r5, r5, #1
    add r4, r4, #2
    mov r4, r4, asr #2
    mov r5, r5, asr #1
    orr r7, r5, r4, lsl #8
    orr r6, r7, r6, lsl #16
    orr r3, r6, r3, lsl #24
    str r3, [r0, #0x100]
    ldrb r12, [r0, #0x1ff]
    add r3, r12, r1
    add r2, r2, r12
    add r1, r2, r1, lsl #1
    add r1, r1, #2
    add r3, r3, #1
    mov r3, r3, asr #1
    mov r1, r1, asr #2
    orr r1, r3, r1, lsl #8
    orr r1, r1, r5, lsl #16
    orr r1, r1, r4, lsl #24
    add r2, r0, #0x200
    stmia r2, {r1, lr}
    sub r11, r0, #0x500
    ldmfd sp!, {r0, r1, r2, r3, r10, r12, pc}
@L0207eb1c:
    stmfd sp!, {r0, r1, r2, r3, r10, r12, lr}
    sub r0, r11, #0x100
    ldmia r0, {r2, r7}
    ldrb r3, [r0, #-1]
    and r9, r2, #0xff
    sub sp, sp, #0x34
    add r1, r3, r9
    add r1, r1, #1
    str r3, [sp, #0x30]
    mov r3, r1, asr #1
    mov r1, r2, lsl #0x10
    mov r10, r1, lsr #0x18
    add r1, r9, r10
    add r1, r1, #1
    str r3, [sp, #0x2c]
    mov r3, r1, asr #1
    mov r1, r2, lsl #8
    str r3, [sp, #0x28]
    mov r1, r1, lsr #0x18
    add r3, r10, r1
    add r3, r3, #1
    mov lr, r3, asr #1
    mov r2, r2, lsr #0x18
    add r3, r1, r2
    add r3, r3, #1
    mov r4, r3, asr #1
    ldr r3, [sp, #0x2c]
    ldr r11, [sp, #0x28]
    orr r3, r3, r11, lsl #8
    orr r3, r3, lr, lsl #16
    orr r3, r3, r4, lsl #24
    str r3, [r0, #0x100]!
    and r3, r7, #0xff
    add r12, r2, r3
    add r12, r12, #1
    mov r5, r12, asr #1
    mov r12, r7, lsl #0x10
    mov r12, r12, lsr #0x18
    add r6, r3, r12
    add r6, r6, #1
    mov r8, r6, asr #1
    mov r6, r7, lsl #8
    mov r6, r6, lsr #0x18
    str r8, [sp, #0x24]
    add r8, r12, r6
    add r8, r8, #1
    mov r11, r8, asr #1
    add r8, sp, #0x1c
    mov r7, r7, lsr #0x18
    stmia r8, {r7, r11}
    ldr r8, [sp, #0x24]
    add r7, r6, r7
    add r7, r7, #1
    orr r8, r5, r8, lsl #8
    orr r8, r8, r11, lsl #16
    mov r7, r7, asr #1
    orr r7, r8, r7, lsl #24
    str r7, [r0, #4]
    ldrb r7, [r0, #-1]
    ldr r8, [sp, #0x30]
    str r7, [sp, #0x18]
    add r7, r7, r9
    add r7, r7, r8, lsl #1
    add r8, r8, r10
    add r8, r8, r9, lsl #1
    add r9, r9, r1
    add r9, r9, r10, lsl #1
    add r10, r10, r2
    add r10, r10, r1, lsl #1
    add r1, r1, r3
    add r8, r8, #2
    add r7, r7, #2
    mov r7, r7, asr #2
    mov r8, r8, asr #2
    add r1, r1, r2, lsl #1
    add r9, r9, #2
    mov r9, r9, asr #2
    add r2, r2, r12
    orr r11, r7, r8, lsl #8
    add r10, r10, #2
    mov r10, r10, asr #2
    orr r11, r11, r9, lsl #16
    add r2, r2, r3, lsl #1
    add r2, r2, #2
    orr r11, r11, r10, lsl #24
    str r11, [r0, #0x100]!
    mov r2, r2, asr #2
    str r2, [sp, #0x14]
    add r2, r3, r6
    add r2, r2, r12, lsl #1
    add r2, r2, #2
    mov r2, r2, asr #2
    str r2, [sp, #0x10]
    ldr r2, [sp, #0x1c]
    add r1, r1, #2
    add r2, r12, r2
    add r2, r2, r6, lsl #1
    add r2, r2, #2
    mov r3, r2, asr #2
    ldr r2, [sp, #0x14]
    mov r1, r1, asr #2
    orr r12, r1, r2, lsl #8
    ldr r2, [sp, #0x10]
    orr r6, r10, r1, lsl #8
    orr r2, r12, r2, lsl #16
    orr r2, r2, r3, lsl #24
    str r2, [r0, #4]
    ldrb r2, [r0, #-1]
    ldr r3, [sp, #0x30]
    str r2, [sp, #0xc]
    add r2, r2, r3
    ldr r3, [sp, #0x18]
    add r2, r2, r3, lsl #1
    add r2, r2, #2
    mov r2, r2, asr #2
    ldr r3, [sp, #0x2c]
    str r2, [sp, #8]
    orr r2, r2, r3, lsl #8
    ldr r3, [sp, #0x28]
    orr r2, r2, r3, lsl #16
    orr r2, r2, lr, lsl #24
    str r2, [r0, #0x100]!
    ldr r3, [sp, #0x24]
    orr r2, r4, r5, lsl #8
    ldr r11, [sp, #0x20]
    orr r2, r2, r3, lsl #16
    orr r2, r2, r11, lsl #24
    str r2, [r0, #4]
    ldrb r3, [r0, #-1]
    ldr r2, [sp, #0x18]
    add r12, r3, r2
    ldr r2, [sp, #0xc]
    add r2, r12, r2, lsl #1
    add r2, r2, #2
    mov r12, r2, asr #2
    orr r2, r12, r7, lsl #8
    orr r2, r2, r8, lsl #16
    orr r2, r2, r9, lsl #24
    str r2, [r0, #0x100]!
    ldr r2, [sp, #0x14]
    orr r6, r6, r2, lsl #16
    ldr r2, [sp, #0x10]
    orr r2, r6, r2, lsl #24
    str r2, [r0, #4]
    ldrb r6, [r0, #-1]
    ldr r2, [sp, #0xc]
    ldr r11, [sp, #8]
    add r2, r6, r2
    add r2, r2, r3, lsl #1
    add r2, r2, #2
    mov r2, r2, asr #2
    str r2, [sp, #4]
    orr r2, r2, r11, lsl #8
    ldr r11, [sp, #0x2c]
    orr r2, r2, r11, lsl #16
    ldr r11, [sp, #0x28]
    orr r2, r2, r11, lsl #24
    str r2, [r0, #0x100]!
    orr r2, lr, r4, lsl #8
    ldr r11, [sp, #0x24]
    orr r2, r2, r5, lsl #16
    orr r2, r2, r11, lsl #24
    str r2, [r0, #4]
    ldrb r11, [r0, #-1]
    add r2, r11, r3
    add r2, r2, r6, lsl #1
    add r2, r2, #2
    mov r2, r2, asr #2
    str r2, [sp]
    orr r2, r2, r12, lsl #8
    orr r2, r2, r7, lsl #16
    orr r2, r2, r8, lsl #24
    str r2, [r0, #0x100]!
    orr r2, r9, r10, lsl #8
    orr r3, r2, r1, lsl #16
    ldr r2, [sp, #0x14]
    orr r2, r3, r2, lsl #24
    str r2, [r0, #4]
    ldrb r2, [r0, #-1]
    add r3, r2, r6
    add r3, r3, r11, lsl #1
    add r3, r3, #2
    ldr r6, [sp, #4]
    mov r3, r3, asr #2
    orr r3, r3, r6, lsl #8
    ldr r6, [sp, #8]
    orr r3, r3, r6, lsl #16
    ldr r6, [sp, #0x2c]
    orr r3, r3, r6, lsl #24
    str r3, [r0, #0x100]!
    ldr r3, [sp, #0x28]
    orr r3, r3, lr, lsl #8
    orr r3, r3, r4, lsl #16
    orr r3, r3, r5, lsl #24
    str r3, [r0, #4]
    ldrb r3, [r0, #-1]
    add r3, r3, r11
    add r2, r3, r2, lsl #1
    add r2, r2, #2
    mov r2, r2, asr #2
    ldr r3, [sp]
    orr r2, r2, r3, lsl #8
    orr r2, r2, r12, lsl #16
    orr r2, r2, r7, lsl #24
    add r0, r0, #0x100
    str r2, [r0]
    orr r2, r8, r9, lsl #8
    orr r2, r2, r10, lsl #16
    orr r1, r2, r1, lsl #24
    str r1, [r0, #4]
    add sp, sp, #0x34
    sub r11, r0, #0x700
    ldmfd sp!, {r0, r1, r2, r3, r10, r12, pc}
@L0207ee70:
    stmfd sp!, {r0, r1, r2, r3, r10, r12, lr}
    sub sp, sp, #4
    ldr r6, [r11, #-0x100]
    ldrb r5, [r11, #-1]
    ldrb r4, [r11, #-0x101]
    and r3, r6, #0xff
    mov r2, r6, lsl #0x10
    mov r12, r2, lsr #0x18
    add r2, r4, r12
    add r1, r5, r3
    add r2, r2, r3, lsl #1
    mov lr, r6, lsl #8
    mov lr, lr, lsr #0x18
    add r3, r3, lr
    add r3, r3, r12, lsl #1
    mov r6, r6, lsr #0x18
    add r1, r1, r4, lsl #1
    add r1, r1, #2
    add r12, r12, r6
    add r2, r2, #2
    mov r2, r2, asr #2
    add r12, r12, lr, lsl #1
    mov r1, r1, asr #2
    add r3, r3, #2
    mov r3, r3, asr #2
    orr r8, r1, r2, lsl #8
    add r12, r12, #2
    mov r12, r12, asr #2
    orr r8, r8, r3, lsl #16
    orr r8, r8, r12, lsl #24
    str r8, [sp]
    str r8, [r11]
    sub r7, r11, #0x100
    ldr r7, [r7, #4]
    orr r0, r3, r12, lsl #8
    and r8, r7, #0xff
    mov r9, r7, lsl #0x10
    mov r9, r9, lsr #0x18
    add lr, lr, r8
    add lr, lr, r6, lsl #1
    mov r10, r7, lsl #8
    mov r10, r10, lsr #0x18
    add r6, r6, r9
    add r6, r6, r8, lsl #1
    add r8, r8, r10
    add r7, r9, r7, lsr #24
    add lr, lr, #2
    mov lr, lr, asr #2
    add r7, r7, r10, lsl #1
    add r8, r8, r9, lsl #1
    add r6, r6, #2
    mov r6, r6, asr #2
    add r8, r8, #2
    mov r8, r8, asr #2
    orr r9, lr, r6, lsl #8
    add r7, r7, #2
    mov r7, r7, asr #2
    orr r9, r9, r8, lsl #16
    orr r7, r9, r7, lsl #24
    str r7, [r11, #4]
    ldrb r7, [r11, #0xff]
    orr r10, r12, lr, lsl #8
    orr r10, r10, r6, lsl #16
    add r4, r7, r4
    add r4, r4, r5, lsl #1
    add r4, r4, #2
    mov r4, r4, asr #2
    orr r9, r4, r1, lsl #8
    orr r9, r9, r2, lsl #16
    orr r8, r10, r8, lsl #24
    str r8, [r11, #0x104]
    orr r9, r9, r3, lsl #24
    str r9, [r11, #0x100]!
    ldrb r8, [r11, #0xff]
    orr r0, r0, lr, lsl #16
    orr r6, r0, r6, lsl #24
    add r5, r8, r5
    add r5, r5, r7, lsl #1
    add r5, r5, #2
    mov r5, r5, asr #2
    orr r10, r5, r4, lsl #8
    orr r10, r10, r1, lsl #16
    orr r10, r10, r2, lsl #24
    str r6, [r11, #0x104]
    str r10, [r11, #0x100]!
    ldrb r6, [r11, #0xff]
    orr r2, r2, r3, lsl #8
    orr r2, r2, r12, lsl #16
    add r7, r6, r7
    add r7, r7, r8, lsl #1
    add r7, r7, #2
    mov r7, r7, asr #2
    orr r0, r7, r5, lsl #8
    orr r0, r0, r4, lsl #16
    orr r1, r0, r1, lsl #24
    orr r2, r2, lr, lsl #24
    add r11, r11, #0x100
    stmia r11, {r1, r2}
    ldrb r2, [r11, #0xff]
    add r3, r2, r8
    add r3, r3, r6, lsl #1
    add r3, r3, #2
    mov r3, r3, asr #2
    orr r12, r3, r7, lsl #8
    orr r12, r12, r5, lsl #16
    orr r12, r12, r4, lsl #24
    str r12, [r11, #0x100]!
    ldr r8, [sp]
    str r8, [r11, #4]
    ldrb r12, [r11, #0xff]
    add lr, r12, r6
    add lr, lr, r2, lsl #1
    add lr, lr, #2
    mov lr, lr, asr #2
    orr r4, lr, r3, lsl #8
    orr r4, r4, r7, lsl #16
    orr r4, r4, r5, lsl #24
    add r11, r11, #0x100
    stmia r11, {r4, r9}
    ldrb r4, [r11, #0xff]
    add r11, r11, #0x100
    add r2, r4, r2
    add r2, r2, r12, lsl #1
    add r2, r2, #2
    mov r2, r2, asr #2
    orr r5, r2, lr, lsl #8
    orr r5, r5, r3, lsl #16
    orr r5, r5, r7, lsl #24
    stmia r11, {r5, r10}
    ldrb r5, [r11, #0xff]
    add r12, r5, r12
    add r12, r12, r4, lsl #1
    add r12, r12, #2
    mov r12, r12, asr #2
    orr r2, r12, r2, lsl #8
    orr r2, r2, lr, lsl #16
    orr r2, r2, r3, lsl #24
    str r2, [r11, #0x100]
    str r1, [r11, #0x104]
    sub r11, r11, #0x600
    add sp, sp, #4
    ldmfd sp!, {r0, r1, r2, r3, r10, r12, pc}
@L0207f0a8:
    stmfd sp!, {r0, r1, r2, r3, r10, r12, lr}
    mov r0, r11
    ldr r2, [r0, #-0x100]
    sub sp, sp, #0x30
    mov r1, r2, lsl #0x10
    mov r11, r1, lsr #0x18
    and r10, r2, #0xff
    add r1, r10, r11
    add r1, r1, #1
    mov r12, r1, asr #1
    mov r1, r2, lsl #8
    mov r1, r1, lsr #0x18
    add lr, r11, r1
    add lr, lr, #1
    str r10, [sp, #0x2c]
    mov r10, lr, asr #1
    mov r2, r2, lsr #0x18
    add lr, r1, r2
    add lr, lr, #1
    str r11, [sp, #0x28]
    mov r11, lr, asr #1
    sub r9, r0, #0x100
    str r11, [sp, #0x20]
    str r10, [sp, #0x24]
    ldr r4, [r9, #4]
    and r3, r4, #0xff
    add lr, r2, r3
    ldr r10, [sp, #0x24]
    add lr, lr, #1
    mov r5, lr, asr #1
    orr r12, r12, r10, lsl #8
    orr r12, r12, r11, lsl #16
    orr r12, r12, r5, lsl #24
    str r5, [sp, #0x1c]
    str r12, [r0]
    mov r12, r4, lsl #0x10
    mov r12, r12, lsr #0x18
    add lr, r3, r12
    add lr, lr, #1
    mov r8, lr, asr #1
    mov lr, r4, lsl #8
    mov lr, lr, lsr #0x18
    add r5, r12, lr
    add r5, r5, #1
    mov r6, r5, asr #1
    mov r4, r4, lsr #0x18
    str r8, [sp, #0x18]
    ldr r8, [r9, #8]
    add r5, lr, r4
    add r5, r5, #1
    mov r7, r5, asr #1
    and r5, r8, #0xff
    ldr r10, [sp, #0x18]
    add r9, r4, r5
    add r9, r9, #1
    orr r10, r10, r6, lsl #8
    orr r10, r10, r7, lsl #16
    mov r9, r9, asr #1
    orr r10, r10, r9, lsl #24
    str r10, [r0, #4]
    ldr r10, [sp, #0x2c]
    ldr r11, [sp, #0x28]
    add r10, r10, r1
    add r10, r10, r11, lsl #1
    add r10, r10, #2
    mov r10, r10, asr #2
    str r10, [sp, #0x14]
    add r10, r11, r2
    add r10, r10, r1, lsl #1
    add r1, r1, r3
    add r1, r1, r2, lsl #1
    add r1, r1, #2
    add r10, r10, #2
    mov r10, r10, asr #2
    mov r1, r1, asr #2
    add r11, sp, #0xc
    stmia r11, {r1, r10}
    add r1, r2, r12
    add r10, sp, #0x10
    ldmia r10, {r2, r10}
    add r1, r1, r3, lsl #1
    orr r2, r10, r2, lsl #8
    ldr r10, [sp, #0xc]
    add r1, r1, #2
    mov r1, r1, asr #2
    orr r2, r2, r10, lsl #16
    orr r2, r2, r1, lsl #24
    str r2, [r0, #0x100]!
    add r2, r3, lr
    add r3, r12, r4
    add r2, r2, r12, lsl #1
    add r3, r3, lr, lsl #1
    add r12, lr, r5
    add r12, r12, r4, lsl #1
    add r12, r12, #2
    mov lr, r12, asr #2
    mov r12, r8, lsl #0x10
    mov r12, r12, lsr #0x18
    add r4, r4, r12
    add r3, r3, #2
    add r2, r2, #2
    mov r2, r2, asr #2
    mov r3, r3, asr #2
    add r4, r4, r5, lsl #1
    add r4, r4, #2
    orr r10, r2, r3, lsl #8
    orr r10, r10, lr, lsl #16
    mov r4, r4, asr #2
    orr r10, r10, r4, lsl #24
    str r10, [r0, #4]
    ldr r10, [sp, #0x24]
    ldr r11, [sp, #0x20]
    orr r10, r10, r11, lsl #8
    ldr r11, [sp, #0x1c]
    orr r10, r10, r11, lsl #16
    ldr r11, [sp, #0x18]
    orr r10, r10, r11, lsl #24
    str r10, [r0, #0x100]!
    add r10, r5, r12
    add r10, r10, #1
    mov r11, r10, asr #1
    orr r10, r6, r7, lsl #8
    orr r10, r10, r9, lsl #16
    orr r10, r10, r11, lsl #24
    str r11, [sp, #8]
    str r10, [r0, #4]
    ldr r10, [sp, #0x10]
    ldr r11, [sp, #0xc]
    orr r10, r10, r11, lsl #8
    orr r10, r10, r1, lsl #16
    orr r10, r10, r2, lsl #24
    str r10, [r0, #0x100]!
    mov r10, r8, lsl #8
    mov r10, r10, lsr #0x18
    add r5, r5, r10
    add r5, r5, r12, lsl #1
    add r5, r5, #2
    mov r11, r5, asr #2
    orr r5, r3, lr, lsl #8
    orr r5, r5, r4, lsl #16
    orr r5, r5, r11, lsl #24
    str r11, [sp, #4]
    str r5, [r0, #4]
    add r11, sp, #0x1c
    ldmia r11, {r5, r11}
    orr r5, r11, r5, lsl #8
    ldr r11, [sp, #0x18]
    orr r5, r5, r11, lsl #16
    orr r5, r5, r6, lsl #24
    str r5, [r0, #0x100]!
    add r5, r12, r10
    add r5, r5, #1
    mov r11, r5, asr #1
    str r11, [sp]
    ldr r11, [sp, #8]
    orr r5, r7, r9, lsl #8
    orr r5, r5, r11, lsl #16
    ldr r11, [sp]
    orr r5, r5, r11, lsl #24
    str r5, [r0, #4]
    ldr r11, [sp, #0xc]
    orr r5, r11, r1, lsl #8
    orr r5, r5, r2, lsl #16
    orr r5, r5, r3, lsl #24
    str r5, [r0, #0x100]!
    mov r5, r8, lsr #0x18
    add r12, r12, r5
    ldr r11, [sp, #4]
    add r12, r12, r10, lsl #1
    orr r8, lr, r4, lsl #8
    orr r8, r8, r11, lsl #16
    add r12, r12, #2
    mov r12, r12, asr #2
    orr r8, r8, r12, lsl #24
    str r8, [r0, #4]
    add r11, sp, #0x18
    ldmia r11, {r8, r11}
    orr r1, r1, r2, lsl #8
    orr r8, r11, r8, lsl #8
    orr r6, r8, r6, lsl #16
    orr r6, r6, r7, lsl #24
    str r6, [r0, #0x100]!
    ldr r11, [sp, #8]
    add r6, r10, r5
    orr r7, r9, r11, lsl #8
    ldr r11, [sp]
    add r6, r6, #1
    orr r1, r1, r3, lsl #16
    orr r1, r1, lr, lsl #24
    mov r6, r6, asr #1
    orr r7, r7, r11, lsl #16
    orr r6, r7, r6, lsl #24
    str r1, [r0, #0x100]
    str r6, [r0, #4]
    sub r11, r0, #0x700
    ldrb r1, [r11, #0xc]
    ldr r11, [sp, #4]
    add r1, r10, r1
    add r1, r1, r5, lsl #1
    add r1, r1, #2
    mov r1, r1, asr #2
    orr r2, r4, r11, lsl #8
    orr r2, r2, r12, lsl #16
    orr r1, r2, r1, lsl #24
    str r1, [r0, #0x104]
    add sp, sp, #0x30
    sub r11, r0, #0x600
    ldmfd sp!, {r0, r1, r2, r3, r10, r12, pc}
@L0207f3e8:
    ldr r4, [r11, #-0x100]
    str r4, [r11], #0x100
    str r4, [r11], #0x100
    str r4, [r11], #0x100
    str r4, [r11], #0x100
    sub r11, r11, #0x400
    mov pc, lr
@L0207f404:
    ldrb r6, [r11, #-1]
    orr r6, r6, r6, lsl #8
    orr r6, r6, r6, lsl #16
    str r6, [r11], #0x100
    ldrb r6, [r11, #-1]
    orr r6, r6, r6, lsl #8
    orr r6, r6, r6, lsl #16
    str r6, [r11], #0x100
    ldrb r6, [r11, #-1]
    orr r6, r6, r6, lsl #8
    orr r6, r6, r6, lsl #16
    str r6, [r11], #0x100
    ldrb r6, [r11, #-1]
    orr r6, r6, r6, lsl #8
    orr r6, r6, r6, lsl #16
    str r6, [r11], #0x100
    sub r11, r11, #0x400
    mov pc, lr
@L0207f44c:
    stmfd sp!, {r10, lr}
    bl @L0207dd30
    stmfd sp!, {r0, r1, r2, r3}
    ldr r0, [r11, #-0x100]
    add lr, r11, #0x300
    ldrb r4, [lr, #-1]
    mov r10, r0, lsr #0x18
    add r5, r4, r10
    add r5, r5, #1
    mov r5, r5, asr #1
    add r5, r5, r6, lsl #1
    sub r6, r5, r4
    mov r4, r4, lsl #2
    sub sp, sp, #0x20
    mov lr, sp
    mov r2, #0xff
    add r4, r4, r6
    and r7, r2, r0
    sub r8, r4, r7, lsl #2
    mov r7, r7, lsl #4
    add r4, r4, r6
    and r9, r2, r0, lsr #8
    sub r12, r4, r9, lsl #2
    mov r9, r9, lsl #4
    stmia lr!, {r7, r8, r9, r12}
    add r4, r4, r6
    and r7, r2, r0, lsr #16
    sub r8, r4, r7, lsl #2
    mov r7, r7, lsl #4
    add r4, r4, r6
    and r9, r2, r0, lsr #24
    sub r12, r4, r9, lsl #2
    mov r9, r9, lsl #4
    stmia lr!, {r7, r8, r9, r12}
    sub r9, r5, r10
    mov r10, r10, lsl #2
    mov lr, #4
@L0207f4e0:
    add r10, r10, r9
    ldrb r8, [r11, #-1]
    sub r7, r10, r8, lsl #2
    mov r8, r8, lsl #4
    ldmia sp, {r0, r1, r2, r3, r4, r5, r6, r12}
    add r0, r0, r1
    add r2, r2, r3
    add r4, r4, r5
    add r6, r6, r12
    str r0, [sp]
    str r2, [sp, #8]
    str r4, [sp, #0x10]
    str r6, [sp, #0x18]
    add r8, r8, r7
    add r5, r0, r8
    add r5, r5, #0x10
    mov r5, r5, asr #5
    add r8, r8, r7
    add r12, r2, r8
    add r12, r12, #0x10
    mov r12, r12, asr #5
    orr r5, r5, r12, lsl #8
    add r8, r8, r7
    add r12, r4, r8
    add r12, r12, #0x10
    mov r12, r12, asr #5
    orr r5, r5, r12, lsl #16
    add r8, r8, r7
    add r12, r6, r8
    add r12, r12, #0x10
    mov r12, r12, asr #5
    orr r5, r5, r12, lsl #24
    str r5, [r11], #0x100
    subs lr, lr, #1
    bne @L0207f4e0
    add sp, sp, #0x20
    sub r11, r11, #0x400
    ldmfd sp!, {r0, r1, r2, r3, r10, pc}
@L0207f578:
    mov r6, #0
    ldr r4, [r11, #-0x100]
    add r6, r6, r4, lsr #24
    mov r4, r4, lsl #8
    add r6, r6, r4, lsr #24
    mov r4, r4, lsl #8
    add r6, r6, r4, lsr #24
    mov r4, r4, lsl #8
    add r6, r6, r4, lsr #24
    sub r11, r11, #1
    ldrb r4, [r11], #0x100
    add r6, r6, r4
    ldrb r4, [r11], #0x100
    add r6, r6, r4
    ldrb r4, [r11], #0x100
    add r6, r6, r4
    ldrb r4, [r11], #1
    add r6, r6, r4
    add r6, r6, #4
    mov r6, r6, asr #3
    orr r6, r6, r6, lsl #8
    orr r6, r6, r6, lsl #16
    str r6, [r11], #-0x100
    str r6, [r11], #-0x100
    str r6, [r11], #-0x100
    str r6, [r11]
    mov pc, lr
@L0207f5e4:
    mov r6, #0
    sub r11, r11, #1
    ldrb r4, [r11], #0x100
    add r6, r6, r4
    ldrb r4, [r11], #0x100
    add r6, r6, r4
    ldrb r4, [r11], #0x100
    add r6, r6, r4
    ldrb r4, [r11], #1
    add r6, r6, r4
    add r6, r6, #2
    mov r6, r6, asr #2
    orr r6, r6, r6, lsl #8
    orr r6, r6, r6, lsl #16
    str r6, [r11], #-0x100
    str r6, [r11], #-0x100
    str r6, [r11], #-0x100
    str r6, [r11]
    mov pc, lr
@L0207f630:
    mov r6, #0
    ldr r4, [r11, #-0x100]
    add r6, r6, r4, lsr #24
    mov r4, r4, lsl #8
    add r6, r6, r4, lsr #24
    mov r4, r4, lsl #8
    add r6, r6, r4, lsr #24
    mov r4, r4, lsl #8
    add r6, r6, r4, lsr #24
    add r6, r6, #2
    mov r6, r6, asr #2
    orr r6, r6, r6, lsl #8
    orr r6, r6, r6, lsl #16
    str r6, [r11], #0x100
    str r6, [r11], #0x100
    str r6, [r11], #0x100
    str r6, [r11], #0x100
    sub r11, r11, #0x400
    mov pc, lr
@L0207f67c:
    mov r6, #0x80
    orr r6, r6, r6, lsl #8
    orr r6, r6, r6, lsl #16
    str r6, [r11], #0x100
    str r6, [r11], #0x100
    str r6, [r11], #0x100
    str r6, [r11], #0x100
    sub r11, r11, #0x400
    mov pc, lr
@L0207f6a0:
    dcd 0xffffffdc // @L0207f67c - @L0207f6a0
    dcd 0xffffff90 // @L0207f630 - @L0207f6a0
    dcd 0xffffff44 // @L0207f5e4 - @L0207f6a0
    dcd 0xfffffed8 // @L0207f578 - @L0207f6a0
@L0207f6b0:
    sub r5, pc, #0x18 // @L0207f6a0
    mov r8, #0
    sub r6, r11, r10
    movs r7, r6, lsl #0x18
    addne r8, r8, #8
    cmp r6, #0x100
    addge r8, r8, #4
    ldr r6, [r5, r8]
    add pc, r5, r6
@L0207f6d4:
    ldrb r5, [r11, #-1]
    ldrb r6, [r11, #0xff]
    add r4, r5, r6
    add r4, r4, #1
    mov r4, r4, asr #1
    ldrb r7, [r11, #0x1ff]!
    add r5, r5, r6, lsl #1
    add r5, r5, r7
    add r5, r5, #2
    mov r5, r5, asr #2
    orr r4, r4, r5, lsl #8
    add r5, r6, r7
    add r5, r5, #1
    mov r5, r5, asr #1
    orr r4, r4, r5, lsl #16
    ldrb r8, [r11, #0x100]!
    add r6, r6, r7, lsl #1
    add r6, r6, r8
    add r6, r6, #2
    mov r6, r6, asr #2
    orr r4, r4, r6, lsl #24
    orr r5, r5, r6, lsl #8
    add r6, r7, r8
    add r6, r6, #1
    mov r6, r6, asr #1
    orr r5, r5, r6, lsl #16
    add r7, r7, r8, lsl #1
    add r7, r7, r8
    add r7, r7, #2
    mov r7, r7, asr #2
    orr r5, r5, r7, lsl #24
    orr r6, r6, r7, lsl #8
    orr r8, r8, r8, lsl #8
    orr r6, r6, r8, lsl #16
    orr r8, r8, r8, lsl #16
    str r8, [r11, #1]!
    str r6, [r11, #-0x100]!
    str r5, [r11, #-0x100]!
    str r4, [r11, #-0x100]!
    mov pc, lr
@L0207f774:
    stmfd sp!, {r12, lr}
    ldrb r8, [r11, #-0x101]
    ldrb r7, [r11, #-1]
    ldr r9, [r11, #-0x100]
    add r12, r8, r7
    add r12, r12, #1
    mov lr, r12, asr #1
    and r12, r9, #0xff
    mov r5, r9, lsl #0x10
    mov r5, r5, lsr #0x18
    add r6, r8, r12, lsl #1
    add r4, r7, r8, lsl #1
    add r4, r4, r12
    add r12, r12, r5, lsl #1
    mov r9, r9, lsl #8
    add r9, r12, r9, lsr #24
    add r4, r4, #2
    add r6, r6, r5
    add r6, r6, #2
    mov r4, r4, asr #2
    orr r12, lr, r4, lsl #8
    mov r6, r6, asr #2
    add r9, r9, #2
    mov r9, r9, asr #2
    orr r12, r12, r6, lsl #16
    orr r9, r12, r9, lsl #24
    str r9, [r11]
    ldrb r9, [r11, #0xff]
    add r8, r8, r7, lsl #1
    add r8, r8, r9
    add r12, r7, r9
    add r12, r12, #1
    add r8, r8, #2
    mov r8, r8, asr #2
    mov r12, r12, asr #1
    orr r5, r12, r8, lsl #8
    orr lr, r5, lr, lsl #16
    orr lr, lr, r4, lsl #24
    str lr, [r11, #0x100]!
    ldrb lr, [r11, #0xff]
    add r7, r7, r9, lsl #1
    add r7, r7, lr
    add r4, r9, lr
    add r4, r4, #1
    add r7, r7, #2
    mov r7, r7, asr #2
    mov r4, r4, asr #1
    orr r5, r4, r7, lsl #8
    orr r12, r5, r12, lsl #16
    orr r8, r12, r8, lsl #24
    str r8, [r11, #0x100]!
    ldrb r8, [r11, #0xff]
    add r9, r9, lr, lsl #1
    add r12, lr, r8
    add r8, r9, r8
    add r8, r8, #2
    add r12, r12, #1
    mov r12, r12, asr #1
    mov r8, r8, asr #2
    orr r8, r12, r8, lsl #8
    orr r8, r8, r4, lsl #16
    orr r7, r8, r7, lsl #24
    str r7, [r11, #0x100]
    sub r11, r11, #0x200
    ldmfd sp!, {r12, pc}
@L0207f878:
    stmfd sp!, {r1, r2, r3, r12, lr}
    ldr lr, [r11, #-0x100]
    ldrb r3, [r11, #-0x101]
    and r1, lr, #0xff
    mov r7, lr, lsr #0x18
    add r2, r3, r1
    add r2, r2, #1
    mov r4, r2, asr #1
    mov r2, lr, lsl #0x10
    mov r2, r2, lsr #0x18
    add r12, r1, r2
    add r12, r12, #1
    mov r5, r12, asr #1
    mov r12, lr, lsl #8
    mov r12, r12, lsr #0x18
    add r6, r2, r12
    add r6, r6, #1
    add lr, r12, r7
    add lr, lr, #1
    mov r6, r6, asr #1
    orr r8, r4, r5, lsl #8
    orr r8, r8, r6, lsl #16
    mov lr, lr, asr #1
    orr lr, r8, lr, lsl #24
    str lr, [r11]
    ldrb lr, [r11, #-1]
    add r9, r3, r1, lsl #1
    add r9, r9, r2
    add r8, lr, r3, lsl #1
    add r8, r8, r1
    add r1, r1, r2, lsl #1
    add r2, r2, r12, lsl #1
    add r1, r1, r12
    add r8, r8, #2
    add r9, r9, #2
    mov r9, r9, asr #2
    mov r8, r8, asr #2
    add r1, r1, #2
    add r2, r2, r7
    add r2, r2, #2
    mov r1, r1, asr #2
    orr r12, r8, r9, lsl #8
    orr r12, r12, r1, lsl #16
    mov r2, r2, asr #2
    orr r2, r12, r2, lsl #24
    str r2, [r11, #0x100]!
    ldrb r2, [r11, #-1]
    add r3, r3, lr, lsl #1
    add r3, r3, r2
    add r3, r3, #2
    mov r3, r3, asr #2
    orr r3, r3, r4, lsl #8
    orr r3, r3, r5, lsl #16
    orr r3, r3, r6, lsl #24
    str r3, [r11, #0x100]!
    ldrb r3, [r11, #-1]
    add r2, lr, r2, lsl #1
    add r2, r2, r3
    add r2, r2, #2
    mov r2, r2, asr #2
    orr r2, r2, r8, lsl #8
    orr r2, r2, r9, lsl #16
    orr r1, r2, r1, lsl #24
    str r1, [r11, #0x100]
    sub r11, r11, #0x200
    ldmfd sp!, {r1, r2, r3, r12, pc}
@L0207f980:
    stmfd sp!, {r12, lr}
    ldr r7, [r11, #-0x100]
    ldrb r12, [r11, #-0x101]
    and lr, r7, #0xff
    ldrb r9, [r11, #-1]
    mov r4, r7, lsl #0x10
    mov r4, r4, lsr #0x18
    add r5, r12, lr, lsl #1
    add r8, r9, r12, lsl #1
    add r8, r8, lr
    mov r6, r7, lsl #8
    mov r6, r6, lsr #0x18
    add lr, lr, r4, lsl #1
    add r5, r5, r4
    add r4, r4, r6, lsl #1
    add r7, r4, r7, lsr #24
    add r5, r5, #2
    add lr, lr, r6
    add r8, r8, #2
    mov r8, r8, asr #2
    add lr, lr, #2
    mov r5, r5, asr #2
    orr r4, r8, r5, lsl #8
    mov lr, lr, asr #2
    add r7, r7, #2
    mov r7, r7, asr #2
    orr r4, r4, lr, lsl #16
    orr r7, r4, r7, lsl #24
    str r7, [r11]
    ldrb r7, [r11, #0xff]
    add r4, r7, r9, lsl #1
    add r12, r4, r12
    add r12, r12, #2
    mov r12, r12, asr #2
    orr r4, r12, r8, lsl #8
    orr r4, r4, r5, lsl #16
    orr lr, r4, lr, lsl #24
    str lr, [r11, #0x100]!
    ldrb lr, [r11, #0xff]
    add r4, lr, r7, lsl #1
    add r9, r4, r9
    add r9, r9, #2
    mov r9, r9, asr #2
    orr r4, r9, r12, lsl #8
    orr r4, r4, r8, lsl #16
    orr r4, r4, r5, lsl #24
    str r4, [r11, #0x100]!
    ldrb r4, [r11, #0xff]
    add lr, r4, lr, lsl #1
    add r7, lr, r7
    add r7, r7, #2
    mov r7, r7, asr #2
    orr r7, r7, r9, lsl #8
    orr r7, r7, r12, lsl #16
    orr r7, r7, r8, lsl #24
    str r7, [r11, #0x100]
    sub r11, r11, #0x200
    ldmfd sp!, {r12, pc}
@L0207fa68:
    stmfd sp!, {r2, r3, r10, lr}
    ldr r9, [r11, #-0x100]
    sub r2, r11, #0x100
    mov r3, r9, lsl #0x10
    mov r6, r3, lsr #0x18
    and r7, r9, #0xff
    add r3, r7, r6
    add r3, r3, #1
    mov r8, r3, asr #1
    mov r3, r9, lsl #8
    mov r12, r3, lsr #0x18
    add r3, r6, r12
    mov r9, r9, lsr #0x18
    add r3, r3, #1
    mov lr, r3, asr #1
    add r3, r12, r9
    add r3, r3, #1
    mov r4, r3, asr #1
    ldr r3, [r2, #4]
    add r7, r7, r6, lsl #1
    and r2, r3, #0xff
    add r5, r9, r2
    add r6, r6, r12, lsl #1
    add r7, r7, r12
    orr r8, r8, lr, lsl #8
    add r5, r5, #1
    mov r5, r5, asr #1
    orr r8, r8, r4, lsl #16
    orr r8, r8, r5, lsl #24
    add r12, r12, r9, lsl #1
    str r8, [r11]
    add r7, r7, #2
    mov r8, r7, asr #2
    add r12, r12, r2
    add r12, r12, #2
    add r6, r6, r9
    mov r7, r12, asr #2
    mov r12, r3, lsl #0x10
    mov r12, r12, lsr #0x18
    add r6, r6, #2
    add r9, r9, r2, lsl #1
    add r9, r9, r12
    mov r6, r6, asr #2
    orr r8, r8, r6, lsl #8
    add r9, r9, #2
    mov r9, r9, asr #2
    orr r8, r8, r7, lsl #16
    orr r8, r8, r9, lsl #24
    str r8, [r11, #0x100]!
    add r8, r2, r12
    add r2, r2, r12, lsl #1
    mov r3, r3, lsl #8
    add r2, r2, r3, lsr #24
    add r8, r8, #1
    orr lr, lr, r4, lsl #8
    orr lr, lr, r5, lsl #16
    mov r8, r8, asr #1
    add r2, r2, #2
    orr r3, r6, r7, lsl #8
    orr r9, r3, r9, lsl #16
    mov r2, r2, asr #2
    orr lr, lr, r8, lsl #24
    str lr, [r11, #0x100]!
    orr r9, r9, r2, lsl #24
    str r9, [r11, #0x100]
    sub r11, r11, #0x200
    ldmfd sp!, {r2, r3, r10, pc}
@L0207fb74:
    movs r3, r3, lsl #8
    bhs @L0207fbc8
    subs r2, r2, #8
    bllt @L0207dd1c
    mov r4, r3, lsr #0x14
    add r4, r11, r4, lsl #1
    ldrh r4, [r4]
    add r7, r11, #0x2000
    ldrb r7, [r7, r4, lsr #9]
    and r5, r4, #0xf
    mov r4, r4, lsr #4
    and r6, r4, #0x1f
    add r6, r6, r7
    mov r4, r4, lsr #5
    movs r3, r3, lsl r5
    rsbhs r6, r6, #0
    subs r2, r2, r5
    bllt @L0207dd1c
    and r5, r4, #0x3f
    mov r4, r4, lsr #6
    b @L0207fc9c
@L0207fbc8:
    adds r3, r3, r3
    bhs @L0207fc20
    subs r2, r2, #9
    bllt @L0207dd1c
    mov r4, r3, lsr #0x14
    add r4, r11, r4, lsl #1
    ldrh r4, [r4]
    and r5, r4, #0xf
    mov r4, r4, lsr #4
    and r6, r4, #0x1f
    mov r4, r4, lsr #5
    and r8, r4, #0x3f
    mov r4, r4, lsr #6
    add r7, r11, #0x2080
    add r7, r7, r6
    ldrb r7, [r7, r4, lsl #6]
    movs r3, r3, lsl r5
    rsbhs r6, r6, #0
    subs r2, r2, r5
    bllt @L0207dd1c
    add r5, r8, r7
    b @L0207fc9c
@L0207fc20:
    subs r2, r2, #9
    bllt @L0207dd1c
    mov r4, r3, lsr #0x1f
    mov r3, r3, lsl #1
    mov r5, r3, lsr #0x1a
    mov r3, r3, lsl #6
    subs r2, r2, #7
    bllt @L0207dd1c
    mov r6, r3, asr #0x14
    mov r3, r3, lsl #0xc
    subs r2, r2, #0xc
    bllt @L0207dd1c
    b @L0207fc9c
@L0207fc54:
    str lr, [sp, #-4]!
    ldr r11, [r0, #0x3b8]
@L0207fc5c:
    mov r4, r3, lsr #0x19
    cmp r4, #3
    beq @L0207fb74
    mov r4, r3, lsr #0x14
    add r4, r11, r4, lsl #1
    ldrh r4, [r4]
    and r5, r4, #0xf
    mov r4, r4, lsr #4
    and r6, r4, #0x1f
    mov r4, r4, lsr #5
    movs r3, r3, lsl r5
    rsbhs r6, r6, #0
    subs r2, r2, r5
    bllt @L0207dd1c
    and r5, r4, #0x3f
    mov r4, r4, lsr #6
@L0207fc9c:
    add r12, r12, r5, lsl #2
    ldr r8, [r12], #4
    and r5, r8, #0xff
    mov r7, r8, lsr #8
    smulbb r7, r6, r7
    add r8, r0, #0x1b4
    str r7, [r8, r5, lsl #2]
    tst r4, #1
    beq @L0207fc5c
    ldr pc, [sp], #4
@L0207fcc4:
    stmfd sp!, {r0, r1, r2, r3}
    add lr, r0, #0x1b4
    add r11, lr, #0x100
    ldmia lr!, {r0, r1, r2, r3, r4, r5, r6, r7}
    add r0, r0, #0x20
    mov r12, #8
@L0207fcdc:
    add r8, r0, r4
    sub r9, r0, r4
    add r0, r2, r6, asr #1
    rsb r4, r6, r2, asr #1
    add r2, r9, r4
    sub r4, r9, r4
    sub r6, r8, r0
    add r0, r8, r0
    add r8, r1, r7
    sub r8, r8, r3
    sub r8, r8, r3, asr #1
    sub r9, r7, r1
    add r9, r9, r5
    add r9, r9, r5, asr #1
    add r7, r7, r7, asr #1
    sub r7, r5, r7
    sub r7, r7, r3
    add r3, r3, r5
    add r3, r3, r1
    add r3, r3, r1, asr #1
    add r1, r7, r3, asr #2
    sub r7, r3, r7, asr #2
    add r3, r8, r9, asr #2
    rsb r5, r9, r8, asr #2
    add r0, r0, r7
    sub r7, r0, r7, lsl #1
    add r8, r2, r5
    sub r9, r2, r5
    add r2, r4, r3
    sub r5, r4, r3
    add r3, r6, r1
    sub r4, r6, r1
    mov r1, r8
    mov r6, r9
    str r7, [r11, #0xe0]
    str r6, [r11, #0xc0]
    str r5, [r11, #0xa0]
    str r4, [r11, #0x80]
    str r3, [r11, #0x60]
    str r2, [r11, #0x40]
    str r1, [r11, #0x20]
    str r0, [r11], #4
    subs r12, r12, #1
    ldmneia lr!, {r0, r1, r2, r3, r4, r5, r6, r7}
    bne @L0207fcdc
    sub r11, r11, #0x20
    ldr lr, [sp, #0x14]
    mov r12, #8
    ldr r8, [r11, #-0x270]
@L0207fda0:
    ldmia r11!, {r0, r1, r2, r3, r4, r5, r6, r7}
    add r9, r0, r4
    sub r10, r0, r4
    add r0, r2, r6, asr #1
    rsb r4, r6, r2, asr #1
    add r2, r10, r4
    sub r4, r10, r4
    sub r6, r9, r0
    add r0, r9, r0
    add r9, r1, r7
    sub r9, r9, r3
    sub r9, r9, r3, asr #1
    sub r10, r7, r1
    add r10, r10, r5
    add r10, r10, r5, asr #1
    add r7, r7, r7, asr #1
    sub r7, r5, r7
    sub r7, r7, r3
    add r3, r3, r5
    add r3, r3, r1
    add r3, r3, r1, asr #1
    add r1, r7, r3, asr #2
    sub r7, r3, r7, asr #2
    add r3, r9, r10, asr #2
    rsb r5, r10, r9, asr #2
    add r0, r0, r7
    sub r7, r0, r7, lsl #1
    add r9, r2, r5
    sub r10, r2, r5
    add r2, r4, r3
    sub r5, r4, r3
    add r3, r6, r1
    sub r4, r6, r1
    mov r1, r9
    mov r6, r10
    ldrb r9, [lr]
    ldrb r10, [lr, #1]
    add r9, r9, r0, asr #6
    ldrb r9, [r8, r9]
    ldrb r0, [lr, #2]
    add r10, r10, r1, asr #6
    ldrb r10, [r8, r10]
    strb r9, [lr]
    ldrb r1, [lr, #3]
    add r0, r0, r2, asr #6
    ldrb r0, [r8, r0]
    strb r10, [lr, #1]
    ldrb r2, [lr, #4]
    add r1, r1, r3, asr #6
    ldrb r1, [r8, r1]
    strb r0, [lr, #2]
    ldrb r3, [lr, #5]
    add r2, r2, r4, asr #6
    ldrb r2, [r8, r2]
    strb r1, [lr, #3]
    ldrb r4, [lr, #6]
    add r3, r3, r5, asr #6
    ldrb r3, [r8, r3]
    strb r2, [lr, #4]
    ldrb r5, [lr, #7]
    add r4, r4, r6, asr #6
    ldrb r4, [r8, r4]
    strb r3, [lr, #5]
    add r5, r5, r7, asr #6
    ldrb r5, [r8, r5]
    strb r4, [lr, #6]
    subs r12, r12, #1
    strb r5, [lr, #7]
    add lr, lr, #0x100
    bne @L0207fda0
    ldmfd sp!, {r0, r1, r2, r3, r10, r11, r12, pc}
@L0207febc:
    stmfd sp!, {r0, r1, r2, r3}
    add lr, r0, #0x1b4
    add r11, lr, #0x100
    ldmia lr!, {r0, r1, r2, r3}
    add r0, r0, #0x20
    mov r12, #4
@L0207fed4:
    add lr, lr, #0x10
    sub r4, r0, r2, asr #1
    sub r6, r0, r2
    add r9, r0, r2, asr #1
    add r0, r0, r2
    sub r8, r1, r3
    sub r8, r8, r3, asr #1
    add r7, r3, r1
    add r7, r7, r1, asr #1
    rsb r2, r3, #0
    add r5, r1, r8, asr #2
    rsb r3, r1, #0
    add r3, r8, r3, asr #2
    add r1, r2, r7, asr #2
    sub r7, r7, r2, asr #2
    add r0, r0, r7
    sub r7, r0, r7, lsl #1
    add r8, r9, r5
    sub r9, r9, r5
    add r2, r4, r3
    sub r5, r4, r3
    add r3, r6, r1
    sub r4, r6, r1
    mov r1, r8
    mov r6, r9
    str r7, [r11, #0x70]
    str r6, [r11, #0x60]
    str r5, [r11, #0x50]
    str r4, [r11, #0x40]
    str r3, [r11, #0x30]
    str r2, [r11, #0x20]
    str r1, [r11, #0x10]
    str r0, [r11], #4
    subs r12, r12, #1
    ldmneia lr!, {r0, r1, r2, r3}
    bne @L0207fed4
    sub r11, r11, #0x10
    ldr lr, [sp, #0x14]
    mov r12, #8
    ldr r8, [r11, #-0x270]
@L0207ff74:
    ldmia r11!, {r0, r1, r2, r3}
    sub r4, r0, r2, asr #1
    sub r6, r0, r2
    add r10, r0, r2, asr #1
    add r0, r0, r2
    sub r9, r1, r3
    sub r9, r9, r3, asr #1
    add r7, r3, r1
    add r7, r7, r1, asr #1
    rsb r2, r3, #0
    add r5, r1, r9, asr #2
    rsb r3, r1, #0
    add r3, r9, r3, asr #2
    add r1, r2, r7, asr #2
    sub r7, r7, r2, asr #2
    add r0, r0, r7
    sub r7, r0, r7, lsl #1
    add r9, r10, r5
    sub r10, r10, r5
    add r2, r4, r3
    sub r5, r4, r3
    add r3, r6, r1
    sub r4, r6, r1
    mov r1, r9
    mov r6, r10
    ldrb r9, [lr]
    ldrb r10, [lr, #1]
    add r9, r9, r0, asr #6
    ldrb r9, [r8, r9]
    ldrb r0, [lr, #2]
    add r10, r10, r1, asr #6
    ldrb r10, [r8, r10]
    strb r9, [lr]
    ldrb r1, [lr, #3]
    add r0, r0, r2, asr #6
    ldrb r0, [r8, r0]
    strb r10, [lr, #1]
    ldrb r2, [lr, #4]
    add r1, r1, r3, asr #6
    ldrb r1, [r8, r1]
    strb r0, [lr, #2]
    ldrb r3, [lr, #5]
    add r2, r2, r4, asr #6
    ldrb r2, [r8, r2]
    strb r1, [lr, #3]
    ldrb r4, [lr, #6]
    add r3, r3, r5, asr #6
    ldrb r3, [r8, r3]
    strb r2, [lr, #4]
    ldrb r5, [lr, #7]
    add r4, r4, r6, asr #6
    ldrb r4, [r8, r4]
    strb r3, [lr, #5]
    add r5, r5, r7, asr #6
    ldrb r5, [r8, r5]
    strb r4, [lr, #6]
    subs r12, r12, #1
    strb r5, [lr, #7]
    add lr, lr, #0x100
    bne @L0207ff74
    ldmfd sp!, {r0, r1, r2, r3, r10, r11, r12, pc}
@L02080068:
    stmfd sp!, {r0, r1, r2, r3}
    add lr, r0, #0x1b4
    ldmia lr, {r8, r9}
    ldr r10, [lr, #0x20]
    add r8, r8, #0x20
    add r7, r9, r9, asr #1
    mov r11, r7, asr #2
    rsb r3, r9, #0
    add r3, r9, r3, asr #2
    add r5, r9, r9, asr #2
    add r0, r8, r7
    sub r7, r8, r7
    add r1, r8, r5
    sub r6, r8, r5
    add r2, r8, r3
    sub r5, r8, r3
    add r3, r8, r11
    sub r4, r8, r11
    stmia lr, {r0, r1, r2, r3, r4, r5, r6, r7}
    add r7, r10, r10, asr #1
    mov r1, r7, asr #2
    rsb r3, r10, #0
    add r3, r10, r3, asr #2
    add r5, r10, r10, asr #2
    ldr r11, [sp, #0x14]
    mov r12, #8
    ldr r8, [lr, #-0x170]
@L020800d4:
    ldr r0, [lr], #4
    ldrb r9, [r11]
    ldrb r10, [r11, #1]
    add r2, r0, r7
    add r9, r9, r2, asr #6
    ldrb r9, [r8, r9]
    ldrb r4, [r11, #2]
    add r2, r0, r5
    add r10, r10, r2, asr #6
    ldrb r10, [r8, r10]
    strb r9, [r11]
    ldrb r6, [r11, #3]
    add r2, r0, r3
    add r4, r4, r2, asr #6
    ldrb r4, [r8, r4]
    strb r10, [r11, #1]
    ldrb r9, [r11, #4]
    add r2, r0, r1
    add r6, r6, r2, asr #6
    ldrb r6, [r8, r6]
    strb r4, [r11, #2]
    ldrb r10, [r11, #5]
    sub r2, r0, r1
    add r9, r9, r2, asr #6
    ldrb r9, [r8, r9]
    strb r6, [r11, #3]
    ldrb r4, [r11, #6]
    sub r2, r0, r3
    add r10, r10, r2, asr #6
    ldrb r10, [r8, r10]
    strb r9, [r11, #4]
    ldrb r6, [r11, #7]
    sub r2, r0, r5
    add r4, r4, r2, asr #6
    ldrb r4, [r8, r4]
    strb r10, [r11, #5]
    sub r2, r0, r7
    add r6, r6, r2, asr #6
    ldrb r6, [r8, r6]
    strb r4, [r11, #6]
    subs r12, r12, #1
    strb r6, [r11, #7]
    add r11, r11, #0x100
    bne @L020800d4
    ldmfd sp!, {r0, r1, r2, r3, r10, r11, r12, pc}
@L02080188:
    stmfd sp!, {r0, r1, r2, r3}
    add lr, r0, #0x1b4
    ldr r9, [lr]
    add r9, r9, #0x20
    mov r9, r9, asr #6
    ldr lr, [sp, #0x14]
    mov r12, #8
    ldr r8, [r0, #0x44]
@L020801a8:
    ldrb r0, [lr]
    ldrb r1, [lr, #1]
    ldrb r2, [lr, #2]
    ldrb r3, [lr, #3]
    ldrb r4, [lr, #4]
    ldrb r5, [lr, #5]
    ldrb r6, [lr, #6]
    ldrb r7, [lr, #7]
    add r0, r0, r9
    add r1, r1, r9
    add r2, r2, r9
    add r3, r3, r9
    add r4, r4, r9
    add r5, r5, r9
    add r6, r6, r9
    add r7, r7, r9
    ldrb r0, [r8, r0]
    ldrb r1, [r8, r1]
    ldrb r2, [r8, r2]
    ldrb r3, [r8, r3]
    ldrb r4, [r8, r4]
    ldrb r5, [r8, r5]
    ldrb r6, [r8, r6]
    ldrb r7, [r8, r7]
    strb r7, [lr, #7]
    strb r6, [lr, #6]
    strb r5, [lr, #5]
    strb r4, [lr, #4]
    strb r3, [lr, #3]
    strb r2, [lr, #2]
    strb r1, [lr, #1]
    strb r0, [lr], #0x100
    subs r12, r12, #1
    bne @L020801a8
    ldmfd sp!, {r0, r1, r2, r3, r10, r11, r12, pc}
@L02080234:
    stmfd sp!, {r0, r1, r2, r3}
    add lr, r0, #0x1b4
    add r11, lr, #0x40
    ldmia lr!, {r0, r1, r2, r3}
    add r0, r0, #0x20
    mov r12, #4
@L0208024c:
    add r0, r0, r2
    sub r2, r0, r2, lsl #1
    rsb r8, r3, r1, asr #1
    add r9, r1, r3, asr #1
    sub r3, r0, r9
    add r0, r0, r9
    add r1, r2, r8
    sub r2, r2, r8
    str r3, [r11, #0x30]
    str r2, [r11, #0x20]
    str r1, [r11, #0x10]
    str r0, [r11], #4
    subs r12, r12, #1
    ldmneia lr!, {r0, r1, r2, r3}
    bne @L0208024c
    sub r11, r11, #0x10
    ldr lr, [sp, #0x14]
    mov r12, #4
    ldr r8, [r11, #-0x1b0]
@L02080298:
    ldmia r11!, {r0, r1, r2, r3}
    add r0, r0, r2
    sub r2, r0, r2, lsl #1
    rsb r9, r3, r1, asr #1
    add r10, r1, r3, asr #1
    sub r3, r0, r10
    add r0, r0, r10
    add r1, r2, r9
    sub r2, r2, r9
    ldrb r4, [lr]
    ldrb r5, [lr, #1]
    ldrb r6, [lr, #2]
    ldrb r7, [lr, #3]
    add r4, r4, r0, asr #6
    add r5, r5, r1, asr #6
    add r6, r6, r2, asr #6
    add r7, r7, r3, asr #6
    ldrb r4, [r8, r4]
    ldrb r5, [r8, r5]
    ldrb r6, [r8, r6]
    ldrb r7, [r8, r7]
    strb r7, [lr, #3]
    strb r6, [lr, #2]
    strb r5, [lr, #1]
    strb r4, [lr], #0x100
    subs r12, r12, #1
    bne @L02080298
    ldmfd sp!, {r0, r1, r2, r3, r10, r11, r12, pc}
@L02080308:
    add lr, r0, #0x1b4
    ldr r9, [lr]
    add r9, r9, #0x20
    mov r9, r9, asr #6
    ldr lr, [sp, #4]
    mov r12, #4
    ldr r8, [r0, #0x44]
@L02080324:
    ldrb r4, [lr]
    ldrb r5, [lr, #1]
    ldrb r6, [lr, #2]
    ldrb r7, [lr, #3]
    add r4, r4, r9
    add r5, r5, r9
    add r6, r6, r9
    add r7, r7, r9
    ldrb r4, [r8, r4]
    ldrb r5, [r8, r5]
    ldrb r6, [r8, r6]
    ldrb r7, [r8, r7]
    strb r7, [lr, #3]
    strb r6, [lr, #2]
    strb r5, [lr, #1]
    strb r4, [lr], #0x100
    subs r12, r12, #1
    bne @L02080324
    ldmfd sp!, {r10, r11, r12, pc}
@L02080370:
    dcd 0x19131314
    dcd 0x18131912
    dcd 0x12141318
    dcd 0x13141220
    dcd 0x13181813
    dcd 0x19121913
    dcd 0x19121912
    dcd 0x13181813
    dcd 0x13181813
    dcd 0x14122012
    dcd 0x18122012
    dcd 0x18131318
    dcd 0x12191218
    dcd 0x18131219
    dcd 0x20121318
    dcd 0x12181812
    dcd 0x1c151516
    dcd 0x1a151c13
    dcd 0x1316151a
    dcd 0x15161323
    dcd 0x151a1a15
    dcd 0x1c131c15
    dcd 0x1c131c13
    dcd 0x151a1a15
    dcd 0x151a1a15
    dcd 0x16132313
    dcd 0x1a132313
    dcd 0x1a15151a
    dcd 0x131c131a
    dcd 0x1a15131c
    dcd 0x2313151a
    dcd 0x131a1a13
    dcd 0x2118181a
    dcd 0x1f182117
    dcd 0x171a181f
    dcd 0x181a172a
    dcd 0x181f1f18
    dcd 0x21172118
    dcd 0x21172117
    dcd 0x181f1f18
    dcd 0x181f1f18
    dcd 0x1a172a17
    dcd 0x1f172a17
    dcd 0x1f18181f
    dcd 0x1721171f
    dcd 0x1f181721
    dcd 0x2a17181f
    dcd 0x171f1f17
    dcd 0x231a1a1c
    dcd 0x211a2319
    dcd 0x191c1a21
    dcd 0x1a1c192d
    dcd 0x1a21211a
    dcd 0x2319231a
    dcd 0x23192319
    dcd 0x1a21211a
    dcd 0x1a21211a
    dcd 0x1c192d19
    dcd 0x21192d19
    dcd 0x211a1a21
    dcd 0x19231921
    dcd 0x211a1923
    dcd 0x2d191a21
    dcd 0x19212119
    dcd 0x281e1e20
    dcd 0x261e281c
    dcd 0x1c201e26
    dcd 0x1e201c33
    dcd 0x1e26261e
    dcd 0x281c281e
    dcd 0x281c281c
    dcd 0x1e26261e
    dcd 0x1e26261e
    dcd 0x201c331c
    dcd 0x261c331c
    dcd 0x261e1e26
    dcd 0x1c281c26
    dcd 0x261e1c28
    dcd 0x331c1e26
    dcd 0x1c26261c
    dcd 0x2e222224
    dcd 0x2b222e20
    dcd 0x2024222b
    dcd 0x2224203a
    dcd 0x222b2b22
    dcd 0x2e202e22
    dcd 0x2e202e20
    dcd 0x222b2b22
    dcd 0x222b2b22
    dcd 0x24203a20
    dcd 0x2b203a20
    dcd 0x2b22222b
    dcd 0x202e202b
    dcd 0x2b22202e
    dcd 0x3a20222b
    dcd 0x202b2b20
@L020804f0:
    dcd 0x10080100
    dcd 0x0a030209
    dcd 0x19201811
    dcd 0x05040b12
    dcd 0x211a130c
    dcd 0x22293028
    dcd 0x060d141b
    dcd 0x1c150e07
    dcd 0x38312a23
    dcd 0x242b3239
    dcd 0x170f161d
    dcd 0x332c251e
    dcd 0x2d343b3a
    dcd 0x2e271f26
    dcd 0x363d3c35
    dcd 0x3f3e372f
@L02080530:
    dcd 0x0a0d0d0a
    dcd 0x0d0d0a10
    dcd 0x0a100d0d
    dcd 0x100d0d10
    dcd 0x0b0e0e0b
    dcd 0x0e0e0b12
    dcd 0x0b120e0e
    dcd 0x120e0e12
    dcd 0x0d10100d
    dcd 0x10100d14
    dcd 0x0d141010
    dcd 0x14101014
    dcd 0x0e12120e
    dcd 0x12120e17
    dcd 0x0e171212
    dcd 0x17121217
    dcd 0x10141410
    dcd 0x14141019
    dcd 0x10191414
    dcd 0x19141419
    dcd 0x12171712
    dcd 0x1717121d
    dcd 0x121d1717
    dcd 0x1d17171d
@L02080590:
    dcd 0x02010400
    dcd 0x090c0805
    dcd 0x0a070306
    dcd 0x0f0b0e0d
@L020805a0:
    dcd 0x00000000
    dcd 0x01010000
    dcd 0x01010101
    dcd 0x02020202
    dcd 0x03030202
    dcd 0x03030303
    dcd 0x04040404
    dcd 0x05050404
    dcd 0x05050505
    dcd 0x06060606
    dcd 0x07070606
    dcd 0x07070707
    dcd 0x08080808
    dcd 0x01000808
    dcd 0x05040302
    dcd 0x03020100
    dcd 0x01000504
    dcd 0x05040302
    dcd 0x03020100
    dcd 0x01000504
    dcd 0x05040302
    dcd 0x03020100
    dcd 0x01000504
    dcd 0x05040302
    dcd 0x03020100
    dcd 0x01000504
    dcd 0x05040302
@L0208060c:
    str r4, [r0, #0x3b4]
    sub r5, pc, #0x78 // @L020805a0
    ldrb r6, [r5, r4]
    add r6, r6, #8
    sub r5, pc, #0x4e // @L020805d6
    ldrb r5, [r5, r4]
    sub r4, pc, #0xfc // @L02080530
    add r4, r4, r5, lsl #4
    sub r7, pc, #0xa4 // @L02080590
    add r8, r0, #0x174
    mov r9, #0x10
@L02080638:
    ldrb r10, [r4], #1
    ldrb r11, [r7], #1
    orr r11, r11, r10, lsl r6
    str r11, [r8], #4
    subs r9, r9, #1
    bne @L02080638
    sub r6, r6, #2
    sub r4, pc, #0x2ec // @L02080370
    add r4, r4, r5, lsl #6
    sub r7, pc, #0x174 // @L020804f0
    add r8, r0, #0x74
    mov r9, #0x40
@L02080668:
    ldrb r10, [r4], #1
    ldrb r11, [r7], #1
    orr r11, r11, r10, lsl r6
    str r11, [r8], #4
    subs r9, r9, #1
    bne @L02080668
    add r4, r0, #0x4c
    mov r5, #9
    strb r5, [r4, #1]
    strb r5, [r4, #2]
    strb r5, [r4, #3]
    strb r5, [r4, #4]
    strb r5, [r4, #8]
    strb r5, [r4, #0x10]
    strb r5, [r4, #0x18]
    strb r5, [r4, #0x20]
    mov pc, lr
@L020806ac:
    ldmia r0, {r3, r4, r7, r8}
    add r0, r0, #0x100
    stmia r1, {r3, r4, r7, r8}
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L020806ac
    mov pc, lr
@L020806c8:
    stmfd sp!, {r5, r6}
    ldr r12, [pc, #0xb6c] // @L02081240
    ldmia r0, {r3, r4, r5, r6}
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
@L020806e8:
    ldmia r0, {r7, r8, r9, r10}
    add r0, r0, #0x100
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    and r9, r12, r9, lsr #1
    and r10, r12, r10, lsr #1
    add r3, r3, r7
    add r4, r4, r8
    add r5, r5, r9
    add r6, r6, r10
    stmia r1, {r3, r4, r5, r6}
    add r1, r1, #0x100
    ldmia r0, {r3, r4, r5, r6}
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
    add r7, r7, r3
    add r8, r8, r4
    add r9, r9, r5
    add r10, r10, r6
    stmia r1, {r7, r8, r9, r10}
    add r1, r1, #0x100
    subs r2, r2, #2
    bne @L020806e8
    ldmfd sp!, {r5, r6}
    mov pc, lr
@L02080758:
    ldr r12, [pc, #0xae0] // @L02081240
@L0208075c:
    ldmia r0, {r3, r4, r7, r8}
    ldrb r9, [r0, #0x10]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    and r9, r12, r9, lsr #1
    add r3, r3, r3, lsr #8
    add r3, r3, r4, lsl #24
    add r4, r4, r4, lsr #8
    add r4, r4, r7, lsl #24
    add r7, r7, r7, lsr #8
    add r7, r7, r8, lsl #24
    add r8, r8, r8, lsr #8
    add r8, r8, r9, lsl #24
    stmia r1, {r3, r4, r7, r8}
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L0208075c
    mov pc, lr
@L020807b0:
    stmfd sp!, {r5, r6, lr}
    ldr r12, [pc, #0xa84] // @L02081240
    ldmia r0, {r3, r4, r5, r6}
    ldrb lr, [r0, #0x10]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
    and lr, r12, lr, lsr #1
    add r3, r3, r3, lsr #8
    add r3, r3, r4, lsl #24
    add r4, r4, r4, lsr #8
    add r4, r4, r5, lsl #24
    add r5, r5, r5, lsr #8
    add r5, r5, r6, lsl #24
    add r6, r6, r6, lsr #8
    add r6, r6, lr, lsl #24
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
@L02080808:
    ldmia r0, {r7, r8, r9, r10}
    ldrb lr, [r0, #0x10]
    add r0, r0, #0x100
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    and r9, r12, r9, lsr #1
    and r10, r12, r10, lsr #1
    and lr, r12, lr, lsr #1
    add r7, r7, r7, lsr #8
    add r7, r7, r8, lsl #24
    add r8, r8, r8, lsr #8
    add r8, r8, r9, lsl #24
    add r9, r9, r9, lsr #8
    add r9, r9, r10, lsl #24
    add r10, r10, r10, lsr #8
    add r10, r10, lr, lsl #24
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    and r9, r12, r9, lsr #1
    and r10, r12, r10, lsr #1
    add r3, r3, r7
    add r4, r4, r8
    add r5, r5, r9
    add r6, r6, r10
    stmia r1, {r3, r4, r5, r6}
    add r1, r1, #0x100
    ldmia r0, {r3, r4, r5, r6}
    ldrb lr, [r0, #0x10]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
    and lr, r12, lr, lsr #1
    add r3, r3, r3, lsr #8
    add r3, r3, r4, lsl #24
    add r4, r4, r4, lsr #8
    add r4, r4, r5, lsl #24
    add r5, r5, r5, lsr #8
    add r5, r5, r6, lsl #24
    add r6, r6, r6, lsr #8
    add r6, r6, lr, lsl #24
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
    add r7, r7, r3
    add r8, r8, r4
    add r9, r9, r5
    add r10, r10, r6
    stmia r1, {r7, r8, r9, r10}
    add r1, r1, #0x100
    subs r2, r2, #2
    bne @L02080808
    ldmfd sp!, {r5, r6, pc}
@L020808e4:
    sub r0, r0, #1
@L020808e8:
    ldmia r0, {r3, r4, r7, r8}
    ldrb r9, [r0, #0x10]
    add r0, r0, #0x100
    mov r3, r3, lsr #8
    add r3, r3, r4, lsl #24
    mov r4, r4, lsr #8
    add r4, r4, r7, lsl #24
    mov r7, r7, lsr #8
    add r7, r7, r8, lsl #24
    mov r8, r8, lsr #8
    add r8, r8, r9, lsl #24
    stmia r1, {r3, r4, r7, r8}
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L020808e8
    mov pc, lr
@L02080928:
    stmfd sp!, {r5, r6, lr}
    sub r0, r0, #1
    ldr r12, [pc, #0x908] // @L02081240
    ldmia r0, {r3, r4, r5, r6}
    ldrb lr, [r0, #0x10]
    add r0, r0, #0x100
    mov r3, r3, lsr #8
    add r3, r3, r4, lsl #24
    mov r4, r4, lsr #8
    add r4, r4, r5, lsl #24
    mov r5, r5, lsr #8
    add r5, r5, r6, lsl #24
    mov r6, r6, lsr #8
    add r6, r6, lr, lsl #24
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
@L02080970:
    ldmia r0, {r7, r8, r9, r10}
    ldrb lr, [r0, #0x10]
    add r0, r0, #0x100
    mov r7, r7, lsr #8
    add r7, r7, r8, lsl #24
    mov r8, r8, lsr #8
    add r8, r8, r9, lsl #24
    mov r9, r9, lsr #8
    add r9, r9, r10, lsl #24
    mov r10, r10, lsr #8
    add r10, r10, lr, lsl #24
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    and r9, r12, r9, lsr #1
    and r10, r12, r10, lsr #1
    add r3, r3, r7
    add r4, r4, r8
    add r5, r5, r9
    add r6, r6, r10
    stmia r1, {r3, r4, r5, r6}
    add r1, r1, #0x100
    ldmia r0, {r3, r4, r5, r6}
    ldrb lr, [r0, #0x10]
    add r0, r0, #0x100
    mov r3, r3, lsr #8
    add r3, r3, r4, lsl #24
    mov r4, r4, lsr #8
    add r4, r4, r5, lsl #24
    mov r5, r5, lsr #8
    add r5, r5, r6, lsl #24
    mov r6, r6, lsr #8
    add r6, r6, lr, lsl #24
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
    add r7, r7, r3
    add r8, r8, r4
    add r9, r9, r5
    add r10, r10, r6
    stmia r1, {r7, r8, r9, r10}
    add r1, r1, #0x100
    subs r2, r2, #2
    bne @L02080970
    ldmfd sp!, {r5, r6, pc}
@L02080a24:
    ldr r12, [pc, #0x814] // @L02081240
    sub r0, r0, #1
@L02080a2c:
    ldmia r0, {r3, r4, r7, r8}
    ldrh r9, [r0, #0x10]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    and r9, r12, r9, lsr #1
    mov r10, r3, lsr #0x10
    add r10, r10, r4, lsl #16
    add r10, r10, r3, lsr #8
    add r3, r10, r4, lsl #24
    mov r10, r4, lsr #0x10
    add r10, r10, r7, lsl #16
    add r10, r10, r4, lsr #8
    add r4, r10, r7, lsl #24
    mov r10, r7, lsr #0x10
    add r10, r10, r8, lsl #16
    add r10, r10, r7, lsr #8
    add r7, r10, r8, lsl #24
    mov r10, r8, lsr #0x10
    add r10, r10, r9, lsl #16
    add r10, r10, r8, lsr #8
    add r8, r10, r9, lsl #24
    stmia r1, {r3, r4, r7, r8}
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L02080a2c
    mov pc, lr
@L02080aa0:
    stmfd sp!, {r5, r6, r11, lr}
    ldr r12, [pc, #0x794] // @L02081240
    sub r0, r0, #1
    ldmia r0, {r3, r4, r5, r6}
    ldrh lr, [r0, #0x10]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
    and lr, r12, lr, lsr #1
    mov r11, r3, lsr #0x10
    add r11, r11, r4, lsl #16
    add r11, r11, r3, lsr #8
    add r3, r11, r4, lsl #24
    mov r11, r4, lsr #0x10
    add r11, r11, r5, lsl #16
    add r11, r11, r4, lsr #8
    add r4, r11, r5, lsl #24
    mov r11, r5, lsr #0x10
    add r11, r11, r6, lsl #16
    add r11, r11, r5, lsr #8
    add r5, r11, r6, lsl #24
    mov r11, r6, lsr #0x10
    add r11, r11, lr, lsl #16
    add r11, r11, r6, lsr #8
    add r6, r11, lr, lsl #24
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
@L02080b1c:
    ldmia r0, {r7, r8, r9, r10}
    ldrh lr, [r0, #0x10]
    add r0, r0, #0x100
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    and r9, r12, r9, lsr #1
    and r10, r12, r10, lsr #1
    and lr, r12, lr, lsr #1
    mov r11, r7, lsr #0x10
    add r11, r11, r8, lsl #16
    add r11, r11, r7, lsr #8
    add r7, r11, r8, lsl #24
    mov r11, r8, lsr #0x10
    add r11, r11, r9, lsl #16
    add r11, r11, r8, lsr #8
    add r8, r11, r9, lsl #24
    mov r11, r9, lsr #0x10
    add r11, r11, r10, lsl #16
    add r11, r11, r9, lsr #8
    add r9, r11, r10, lsl #24
    mov r11, r10, lsr #0x10
    add r11, r11, lr, lsl #16
    add r11, r11, r10, lsr #8
    add r10, r11, lr, lsl #24
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    and r9, r12, r9, lsr #1
    and r10, r12, r10, lsr #1
    add r3, r3, r7
    add r4, r4, r8
    add r5, r5, r9
    add r6, r6, r10
    stmia r1, {r3, r4, r5, r6}
    add r1, r1, #0x100
    ldmia r0, {r3, r4, r5, r6}
    ldrh lr, [r0, #0x10]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
    and lr, r12, lr, lsr #1
    mov r11, r3, lsr #0x10
    add r11, r11, r4, lsl #16
    add r11, r11, r3, lsr #8
    add r3, r11, r4, lsl #24
    mov r11, r4, lsr #0x10
    add r11, r11, r5, lsl #16
    add r11, r11, r4, lsr #8
    add r4, r11, r5, lsl #24
    mov r11, r5, lsr #0x10
    add r11, r11, r6, lsl #16
    add r11, r11, r5, lsr #8
    add r5, r11, r6, lsl #24
    mov r11, r6, lsr #0x10
    add r11, r11, lr, lsl #16
    add r11, r11, r6, lsr #8
    add r6, r11, lr, lsl #24
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
    add r7, r7, r3
    add r8, r8, r4
    add r9, r9, r5
    add r10, r10, r6
    stmia r1, {r7, r8, r9, r10}
    add r1, r1, #0x100
    subs r2, r2, #2
    bne @L02080b1c
    ldmfd sp!, {r5, r6, r11, pc}
@L02080c38:
    add r0, r0, #2
@L02080c3c:
    ldrh r3, [r0, #-2]
    ldmia r0, {r4, r7, r8}
    ldrh r9, [r0, #0xc]
    add r0, r0, #0x100
    add r3, r3, r4, lsl #16
    mov r4, r4, lsr #0x10
    add r4, r4, r7, lsl #16
    mov r7, r7, lsr #0x10
    add r7, r7, r8, lsl #16
    mov r8, r8, lsr #0x10
    add r8, r8, r9, lsl #16
    stmia r1, {r3, r4, r7, r8}
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L02080c3c
    mov pc, lr
@L02080c7c:
    stmfd sp!, {r5, r6, lr}
    ldr r12, [pc, #0x5b8] // @L02081240
    add r0, r0, #2
    ldrh r3, [r0, #-2]
    ldmia r0, {r4, r5, r6}
    ldrh lr, [r0, #0xc]
    add r0, r0, #0x100
    add r3, r3, r4, lsl #16
    mov r4, r4, lsr #0x10
    add r4, r4, r5, lsl #16
    mov r5, r5, lsr #0x10
    add r5, r5, r6, lsl #16
    mov r6, r6, lsr #0x10
    add r6, r6, lr, lsl #16
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
@L02080cc4:
    ldrh r7, [r0, #-2]
    ldmia r0, {r8, r9, r10}
    ldrh lr, [r0, #0xc]
    add r0, r0, #0x100
    add r7, r7, r8, lsl #16
    mov r8, r8, lsr #0x10
    add r8, r8, r9, lsl #16
    mov r9, r9, lsr #0x10
    add r9, r9, r10, lsl #16
    mov r10, r10, lsr #0x10
    add r10, r10, lr, lsl #16
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    and r9, r12, r9, lsr #1
    and r10, r12, r10, lsr #1
    add r3, r3, r7
    add r4, r4, r8
    add r5, r5, r9
    add r6, r6, r10
    stmia r1, {r3, r4, r5, r6}
    add r1, r1, #0x100
    ldrh r3, [r0, #-2]
    ldmia r0, {r4, r5, r6}
    ldrh lr, [r0, #0xc]
    add r0, r0, #0x100
    add r3, r3, r4, lsl #16
    mov r4, r4, lsr #0x10
    add r4, r4, r5, lsl #16
    mov r5, r5, lsr #0x10
    add r5, r5, r6, lsl #16
    mov r6, r6, lsr #0x10
    add r6, r6, lr, lsl #16
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
    add r7, r7, r3
    add r8, r8, r4
    add r9, r9, r5
    add r10, r10, r6
    stmia r1, {r7, r8, r9, r10}
    add r1, r1, #0x100
    subs r2, r2, #2
    bne @L02080cc4
    ldmfd sp!, {r5, r6, pc}
@L02080d78:
    ldr r12, [pc, #0x4c0] // @L02081240
    add r0, r0, #2
@L02080d80:
    ldrh r3, [r0, #-2]
    ldmia r0, {r4, r7, r8, r9}
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    and r9, r12, r9, lsr #1
    add r10, r3, r4, lsl #16
    add r10, r10, r3, lsr #8
    add r3, r10, r4, lsl #8
    mov r4, r4, lsr #0x10
    add r10, r4, r7, lsl #16
    add r10, r10, r4, lsr #8
    add r4, r10, r7, lsl #8
    mov r7, r7, lsr #0x10
    add r10, r7, r8, lsl #16
    add r10, r10, r7, lsr #8
    add r7, r10, r8, lsl #8
    mov r8, r8, lsr #0x10
    add r10, r8, r9, lsl #16
    add r10, r10, r8, lsr #8
    add r8, r10, r9, lsl #8
    stmia r1, {r3, r4, r7, r8}
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L02080d80
    mov pc, lr
@L02080df0:
    stmfd sp!, {r5, r6, r11, lr}
    ldr r12, [pc, #0x444] // @L02081240
    add r0, r0, #2
    ldrh r3, [r0, #-2]
    ldmia r0, {r4, r5, r6, lr}
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
    and lr, r12, lr, lsr #1
    add r11, r3, r4, lsl #16
    add r11, r11, r3, lsr #8
    add r3, r11, r4, lsl #8
    mov r4, r4, lsr #0x10
    add r11, r4, r5, lsl #16
    add r11, r11, r4, lsr #8
    add r4, r11, r5, lsl #8
    mov r5, r5, lsr #0x10
    add r11, r5, r6, lsl #16
    add r11, r11, r5, lsr #8
    add r5, r11, r6, lsl #8
    mov r6, r6, lsr #0x10
    add r11, r6, lr, lsl #16
    add r11, r11, r6, lsr #8
    add r6, r11, lr, lsl #8
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
@L02080e68:
    ldrh r7, [r0, #-2]
    ldmia r0, {r8, r9, r10, lr}
    add r0, r0, #0x100
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    and r9, r12, r9, lsr #1
    and r10, r12, r10, lsr #1
    and lr, r12, lr, lsr #1
    add r11, r7, r8, lsl #16
    add r11, r11, r7, lsr #8
    add r7, r11, r8, lsl #8
    mov r8, r8, lsr #0x10
    add r11, r8, r9, lsl #16
    add r11, r11, r8, lsr #8
    add r8, r11, r9, lsl #8
    mov r9, r9, lsr #0x10
    add r11, r9, r10, lsl #16
    add r11, r11, r9, lsr #8
    add r9, r11, r10, lsl #8
    mov r10, r10, lsr #0x10
    add r11, r10, lr, lsl #16
    add r11, r11, r10, lsr #8
    add r10, r11, lr, lsl #8
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    and r9, r12, r9, lsr #1
    and r10, r12, r10, lsr #1
    add r3, r3, r7
    add r4, r4, r8
    add r5, r5, r9
    add r6, r6, r10
    stmia r1, {r3, r4, r5, r6}
    add r1, r1, #0x100
    ldrh r3, [r0, #-2]
    ldmia r0, {r4, r5, r6, lr}
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
    and lr, r12, lr, lsr #1
    add r11, r3, r4, lsl #16
    add r11, r11, r3, lsr #8
    add r3, r11, r4, lsl #8
    mov r4, r4, lsr #0x10
    add r11, r4, r5, lsl #16
    add r11, r11, r4, lsr #8
    add r4, r11, r5, lsl #8
    mov r5, r5, lsr #0x10
    add r11, r5, r6, lsl #16
    add r11, r11, r5, lsr #8
    add r5, r11, r6, lsl #8
    mov r6, r6, lsr #0x10
    add r11, r6, lr, lsl #16
    add r11, r11, r6, lsr #8
    add r6, r11, lr, lsl #8
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
    add r7, r7, r3
    add r8, r8, r4
    add r9, r9, r5
    add r10, r10, r6
    stmia r1, {r7, r8, r9, r10}
    add r1, r1, #0x100
    subs r2, r2, #2
    bne @L02080e68
    ldmfd sp!, {r5, r6, r11, pc}
@L02080f7c:
    add r0, r0, #1
@L02080f80:
    ldrb r3, [r0, #-1]
    ldmia r0, {r4, r7, r8, r9}
    add r0, r0, #0x100
    add r3, r3, r4, lsl #8
    mov r4, r4, lsr #0x18
    add r4, r4, r7, lsl #8
    mov r7, r7, lsr #0x18
    add r7, r7, r8, lsl #8
    mov r8, r8, lsr #0x18
    add r8, r8, r9, lsl #8
    stmia r1, {r3, r4, r7, r8}
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L02080f80
    mov pc, lr
@L02080fbc:
    stmfd sp!, {r5, r6, lr}
    ldr r12, [pc, #0x278] // @L02081240
    add r0, r0, #1
    ldrb r3, [r0, #-1]
    ldmia r0, {r4, r5, r6, lr}
    add r0, r0, #0x100
    add r3, r3, r4, lsl #8
    mov r4, r4, lsr #0x18
    add r4, r4, r5, lsl #8
    mov r5, r5, lsr #0x18
    add r5, r5, r6, lsl #8
    mov r6, r6, lsr #0x18
    add r6, r6, lr, lsl #8
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
@L02081000:
    ldrb r7, [r0, #-1]
    ldmia r0, {r8, r9, r10, lr}
    add r0, r0, #0x100
    add r7, r7, r8, lsl #8
    mov r8, r8, lsr #0x18
    add r8, r8, r9, lsl #8
    mov r9, r9, lsr #0x18
    add r9, r9, r10, lsl #8
    mov r10, r10, lsr #0x18
    add r10, r10, lr, lsl #8
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    and r9, r12, r9, lsr #1
    and r10, r12, r10, lsr #1
    add r3, r3, r7
    add r4, r4, r8
    add r5, r5, r9
    add r6, r6, r10
    stmia r1, {r3, r4, r5, r6}
    add r1, r1, #0x100
    ldrb r3, [r0, #-1]
    ldmia r0, {r4, r5, r6, lr}
    add r0, r0, #0x100
    add r3, r3, r4, lsl #8
    mov r4, r4, lsr #0x18
    add r4, r4, r5, lsl #8
    mov r5, r5, lsr #0x18
    add r5, r5, r6, lsl #8
    mov r6, r6, lsr #0x18
    add r6, r6, lr, lsl #8
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
    add r7, r7, r3
    add r8, r8, r4
    add r9, r9, r5
    add r10, r10, r6
    stmia r1, {r7, r8, r9, r10}
    add r1, r1, #0x100
    subs r2, r2, #2
    bne @L02081000
    ldmfd sp!, {r5, r6, pc}
@L020810ac:
    ldr r12, [pc, #0x18c] // @L02081240
    add r0, r0, #1
@L020810b4:
    ldrb r3, [r0, #-1]
    ldmia r0, {r4, r7, r8, r9}
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    and r9, r12, r9, lsr #1
    add r3, r3, r4, lsl #8
    add r3, r3, r4
    add r4, r7, r4, lsr #24
    add r4, r4, r7, lsl #8
    add r7, r8, r7, lsr #24
    add r7, r7, r8, lsl #8
    add r8, r9, r8, lsr #24
    add r8, r8, r9, lsl #8
    stmia r1, {r3, r4, r7, r8}
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L020810b4
    mov pc, lr
@L02081108:
    stmfd sp!, {r5, r6, lr}
    ldr r12, [pc, #0x12c] // @L02081240
    add r0, r0, #1
    ldrb r3, [r0, #-1]
    ldmia r0, {r4, r5, r6, lr}
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
    and lr, r12, lr, lsr #1
    add r3, r3, r4, lsl #8
    add r3, r3, r4
    add r4, r5, r4, lsr #24
    add r4, r4, r5, lsl #8
    add r5, r6, r5, lsr #24
    add r5, r5, r6, lsl #8
    add r6, lr, r6, lsr #24
    add r6, r6, lr, lsl #8
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
@L02081164:
    ldrb r7, [r0, #-1]
    ldmia r0, {r8, r9, r10, lr}
    add r0, r0, #0x100
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    and r9, r12, r9, lsr #1
    and r10, r12, r10, lsr #1
    and lr, r12, lr, lsr #1
    add r7, r7, r8, lsl #8
    add r7, r7, r8
    add r8, r9, r8, lsr #24
    add r8, r8, r9, lsl #8
    add r9, r10, r9, lsr #24
    add r9, r9, r10, lsl #8
    add r10, lr, r10, lsr #24
    add r10, r10, lr, lsl #8
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    and r9, r12, r9, lsr #1
    and r10, r12, r10, lsr #1
    add r3, r3, r7
    add r4, r4, r8
    add r5, r5, r9
    add r6, r6, r10
    stmia r1, {r3, r4, r5, r6}
    add r1, r1, #0x100
    ldrb r3, [r0, #-1]
    ldmia r0, {r4, r5, r6, lr}
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
    and lr, r12, lr, lsr #1
    add r3, r3, r4, lsl #8
    add r3, r3, r4
    add r4, r5, r4, lsr #24
    add r4, r4, r5, lsl #8
    add r5, r6, r5, lsr #24
    add r5, r5, r6, lsl #8
@L02081204:
    add r6, lr, r6, lsr #24
    add r6, r6, lr, lsl #8
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r5, r12, r5, lsr #1
    and r6, r12, r6, lsr #1
    add r7, r7, r3
@L02081220:
    add r8, r8, r4
    add r9, r9, r5
    add r10, r10, r6
    stmia r1, {r7, r8, r9, r10}
    add r1, r1, #0x100
    subs r2, r2, #2
    bne @L02081164
    ldmfd sp!, {r5, r6, pc}
@L02081240:
    dcd 0x7f7f7f7f
@L02081244:
    ldmia r0, {r3, r4}
    add r0, r0, #0x100
    stmia r1, {r3, r4}
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L02081244
    mov pc, lr
@L02081260:
    ldr r12, [pc, #0x784] // @L020819ec
    ldmia r0, {r3, r4}
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
@L02081274:
    ldmia r0, {r7, r8}
    add r0, r0, #0x100
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    add r3, r3, r7
@L02081288:
    add r4, r4, r8
    stmia r1, {r3, r4}
    add r1, r1, #0x100
    subs r2, r2, #1
    moveq pc, lr
    ldmia r0, {r3, r4}
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    add r7, r7, r3
    add r8, r8, r4
    stmia r1, {r7, r8}
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L02081274
    mov pc, lr
@L020812c8:
    ldr r12, [pc, #0x71c] // @L020819ec
@L020812cc:
    ldmia r0, {r3, r4}
    ldrb r9, [r0, #8]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r9, r12, r9, lsr #1
    add r3, r3, r3, lsr #8
    add r3, r3, r4, lsl #24
    add r4, r4, r4, lsr #8
    add r4, r4, r9, lsl #24
    stmia r1, {r3, r4}
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L020812cc
    mov pc, lr
@L02081308:
    ldr r12, [pc, #0x6dc] // @L020819ec
    ldmia r0, {r3, r4}
    ldrb r9, [r0, #8]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r9, r12, r9, lsr #1
    add r3, r3, r3, lsr #8
    add r3, r3, r4, lsl #24
    add r4, r4, r4, lsr #8
    add r4, r4, r9, lsl #24
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
@L0208133c:
    ldmia r0, {r7, r8}
    ldrb r9, [r0, #8]
    add r0, r0, #0x100
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    and r9, r12, r9, lsr #1
    add r7, r7, r7, lsr #8
    add r7, r7, r8, lsl #24
    add r8, r8, r8, lsr #8
    add r8, r8, r9, lsl #24
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    add r3, r3, r7
    add r4, r4, r8
    stmia r1, {r3, r4}
    add r1, r1, #0x100
    subs r2, r2, #1
    moveq pc, lr
    ldmia r0, {r3, r4}
    ldrb r9, [r0, #8]
    add r0, r0, #0x100
@L02081390:
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r9, r12, r9, lsr #1
    add r3, r3, r3, lsr #8
    add r3, r3, r4, lsl #24
    add r4, r4, r4, lsr #8
    add r4, r4, r9, lsl #24
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    add r7, r7, r3
    add r8, r8, r4
    stmia r1, {r7, r8}
    add r1, r1, #0x100
@L020813c4:
    subs r2, r2, #1
    bne @L0208133c
    mov pc, lr
@L020813d0:
    sub r0, r0, #1
@L020813d4:
    ldmia r0, {r3, r4}
    ldrb r9, [r0, #8]
    add r0, r0, #0x100
    mov r3, r3, lsr #8
    add r3, r3, r4, lsl #24
    mov r4, r4, lsr #8
    add r4, r4, r9, lsl #24
    stmia r1, {r3, r4}
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L020813d4
    mov pc, lr
@L02081404:
    sub r0, r0, #1
    ldr r12, [pc, #0x5dc] // @L020819ec
    ldmia r0, {r3, r4}
    ldrb r9, [r0, #8]
    add r0, r0, #0x100
    mov r3, r3, lsr #8
    add r3, r3, r4, lsl #24
    mov r4, r4, lsr #8
    add r4, r4, r9, lsl #24
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
@L02081430:
    ldmia r0, {r7, r8}
    ldrb r9, [r0, #8]
    add r0, r0, #0x100
    mov r7, r7, lsr #8
    add r7, r7, r8, lsl #24
    mov r8, r8, lsr #8
    add r8, r8, r9, lsl #24
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    add r3, r3, r7
    add r4, r4, r8
    stmia r1, {r3, r4}
    add r1, r1, #0x100
    subs r2, r2, #1
    moveq pc, lr
@L0208146c:
    ldmia r0, {r3, r4}
    ldrb r9, [r0, #8]
    add r0, r0, #0x100
    mov r3, r3, lsr #8
    add r3, r3, r4, lsl #24
    mov r4, r4, lsr #8
    add r4, r4, r9, lsl #24
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    add r7, r7, r3
    add r8, r8, r4
    stmia r1, {r7, r8}
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L02081430
    mov pc, lr
@L020814ac:
    ldr r12, [pc, #0x538] // @L020819ec
    sub r0, r0, #1
@L020814b4:
    ldmia r0, {r3, r4}
    ldrh r9, [r0, #8]
    add r0, r0, #0x100
@L020814c0:
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r9, r12, r9, lsr #1
    mov r10, r3, lsr #0x10
    add r10, r10, r4, lsl #16
    add r10, r10, r3, lsr #8
    add r3, r10, r4, lsl #24
    mov r10, r4, lsr #0x10
    add r10, r10, r9, lsl #16
    add r10, r10, r4, lsr #8
    add r4, r10, r9, lsl #24
    stmia r1, {r3, r4}
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L020814b4
    mov pc, lr
@L02081500:
    ldr r12, [pc, #0x4e4] // @L020819ec
    sub r0, r0, #1
    ldmia r0, {r3, r4}
    ldrh r9, [r0, #8]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r9, r12, r9, lsr #1
    mov r10, r3, lsr #0x10
    add r10, r10, r4, lsl #16
    add r10, r10, r3, lsr #8
    add r3, r10, r4, lsl #24
    mov r10, r4, lsr #0x10
    add r10, r10, r9, lsl #16
    add r10, r10, r4, lsr #8
    add r4, r10, r9, lsl #24
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
@L02081548:
    ldmia r0, {r7, r8}
    ldrh r9, [r0, #8]
    add r0, r0, #0x100
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    and r9, r12, r9, lsr #1
    mov r10, r7, lsr #0x10
    add r10, r10, r8, lsl #16
    add r10, r10, r7, lsr #8
    add r7, r10, r8, lsl #24
    mov r10, r8, lsr #0x10
    add r10, r10, r9, lsl #16
    add r10, r10, r8, lsr #8
    add r8, r10, r9, lsl #24
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    add r3, r3, r7
    add r4, r4, r8
    stmia r1, {r3, r4}
    add r1, r1, #0x100
    subs r2, r2, #1
    moveq pc, lr
    ldmia r0, {r3, r4}
    ldrh r9, [r0, #8]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r9, r12, r9, lsr #1
    mov r10, r3, lsr #0x10
@L020815bc:
    add r10, r10, r4, lsl #16
    add r10, r10, r3, lsr #8
    add r3, r10, r4, lsl #24
    mov r10, r4, lsr #0x10
    add r10, r10, r9, lsl #16
    add r10, r10, r4, lsr #8
    add r4, r10, r9, lsl #24
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    add r7, r7, r3
    add r8, r8, r4
    stmia r1, {r7, r8}
@L020815ec:
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L02081548
    mov pc, lr
@L020815fc:
    ldrh r3, [r0], #2
    ldr r4, [r0], #4
    ldrh r9, [r0], #-6
    add r0, r0, #0x100
    add r3, r3, r4, lsl #16
    mov r4, r4, lsr #0x10
    add r4, r4, r9, lsl #16
    stmia r1, {r3, r4}
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L020815fc
    mov pc, lr
@L0208162c:
    ldr r12, [pc, #0x3b8] // @L020819ec
    ldrh r3, [r0], #2
    ldr r4, [r0], #4
    ldrh r9, [r0], #-6
    add r0, r0, #0x100
    add r3, r3, r4, lsl #16
    mov r4, r4, lsr #0x10
    add r4, r4, r9, lsl #16
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
@L02081654:
    ldrh r7, [r0], #2
    ldr r8, [r0], #4
    ldrh r9, [r0], #-6
    add r0, r0, #0x100
    add r7, r7, r8, lsl #16
    mov r8, r8, lsr #0x10
    add r8, r8, r9, lsl #16
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    add r3, r3, r7
    add r4, r4, r8
    stmia r1, {r3, r4}
    add r1, r1, #0x100
    subs r2, r2, #1
    moveq pc, lr
@L02081690:
    ldrh r3, [r0], #2
    ldr r4, [r0], #4
    ldrh r9, [r0], #-6
    add r0, r0, #0x100
    add r3, r3, r4, lsl #16
    mov r4, r4, lsr #0x10
    add r4, r4, r9, lsl #16
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    add r7, r7, r3
    add r8, r8, r4
    stmia r1, {r7, r8}
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L02081654
    mov pc, lr
@L020816d0:
    ldr r12, [pc, #0x314] // @L020819ec
    add r0, r0, #2
@L020816d8:
    ldrh r3, [r0, #-2]
    ldmia r0, {r4, r9}
@L020816e0:
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r9, r12, r9, lsr #1
    add r10, r3, r4, lsl #16
    add r10, r10, r3, lsr #8
    add r3, r10, r4, lsl #8
    mov r4, r4, lsr #0x10
    add r10, r4, r9, lsl #16
    add r10, r10, r4, lsr #8
    add r4, r10, r9, lsl #8
    stmia r1, {r3, r4}
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L020816d8
    mov pc, lr
@L02081720:
    ldr r12, [pc, #0x2c4] // @L020819ec
    add r0, r0, #2
    ldrh r3, [r0, #-2]
    ldmia r0, {r4, r9}
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r9, r12, r9, lsr #1
    add r10, r3, r4, lsl #16
    add r10, r10, r3, lsr #8
    add r3, r10, r4, lsl #8
    mov r4, r4, lsr #0x10
    add r10, r4, r9, lsl #16
    add r10, r10, r4, lsr #8
    add r4, r10, r9, lsl #8
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
@L02081764:
    ldrh r7, [r0, #-2]
    ldmia r0, {r8, r9}
    add r0, r0, #0x100
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    and r9, r12, r9, lsr #1
    add r10, r7, r8, lsl #16
    add r10, r10, r7, lsr #8
    add r7, r10, r8, lsl #8
    mov r8, r8, lsr #0x10
    add r10, r8, r9, lsl #16
    add r10, r10, r8, lsr #8
    add r8, r10, r9, lsl #8
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    add r3, r3, r7
    add r4, r4, r8
    stmia r1, {r3, r4}
    add r1, r1, #0x100
    subs r2, r2, #1
    moveq pc, lr
    ldrh r3, [r0, #-2]
    ldmia r0, {r4, r9}
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r9, r12, r9, lsr #1
@L020817d0:
    add r10, r3, r4, lsl #16
    add r10, r10, r3, lsr #8
    add r3, r10, r4, lsl #8
    mov r4, r4, lsr #0x10
    add r10, r4, r9, lsl #16
    add r10, r10, r4, lsr #8
    add r4, r10, r9, lsl #8
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    add r7, r7, r3
    add r8, r8, r4
    stmia r1, {r7, r8}
@L02081800:
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L02081764
    mov pc, lr
@L02081810:
    add r0, r0, #1
@L02081814:
    ldrb r3, [r0, #-1]
    ldmia r0, {r4, r9}
    add r0, r0, #0x100
    add r3, r3, r4, lsl #8
    mov r4, r4, lsr #0x18
    add r4, r4, r9, lsl #8
    stmia r1, {r3, r4}
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L02081814
    mov pc, lr
@L02081840:
    ldr r12, [pc, #0x1a4] // @L020819ec
    add r0, r0, #1
    ldrb r3, [r0, #-1]
    ldmia r0, {r4, r9}
    add r0, r0, #0x100
    add r3, r3, r4, lsl #8
    mov r4, r4, lsr #0x18
    add r4, r4, r9, lsl #8
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
@L02081868:
    ldrb r7, [r0, #-1]
    ldmia r0, {r8, r9}
    add r0, r0, #0x100
    add r7, r7, r8, lsl #8
    mov r8, r8, lsr #0x18
    add r8, r8, r9, lsl #8
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    add r3, r3, r7
    add r4, r4, r8
    stmia r1, {r3, r4}
    add r1, r1, #0x100
    subs r2, r2, #1
@L0208189c:
    moveq pc, lr
    ldrb r3, [r0, #-1]
    ldmia r0, {r4, r9}
    add r0, r0, #0x100
    add r3, r3, r4, lsl #8
    mov r4, r4, lsr #0x18
    add r4, r4, r9, lsl #8
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    add r7, r7, r3
    add r8, r8, r4
    stmia r1, {r7, r8}
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L02081868
    mov pc, lr
@L020818dc:
    ldr r12, [pc, #0x108] // @L020819ec
@L020818e0:
    add r0, r0, #1
@L020818e4:
    ldrb r3, [r0, #-1]
    ldmia r0, {r4, r9}
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r9, r12, r9, lsr #1
    add r3, r3, r4, lsl #8
    add r3, r3, r4
    add r4, r9, r4, lsr #24
    add r4, r4, r9, lsl #8
    stmia r1, {r3, r4}
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L020818e4
    mov pc, lr
@L02081920:
    ldr r12, [pc, #0xc4] // @L020819ec
    add r0, r0, #1
    ldrb r3, [r0, #-1]
    ldmia r0, {r4, r9}
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r9, r12, r9, lsr #1
    add r3, r3, r4, lsl #8
    add r3, r3, r4
    add r4, r9, r4, lsr #24
    add r4, r4, r9, lsl #8
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
@L02081958:
    ldrb r7, [r0, #-1]
    ldmia r0, {r8, r9}
    add r0, r0, #0x100
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    and r9, r12, r9, lsr #1
    add r7, r7, r8, lsl #8
    add r7, r7, r8
    add r8, r9, r8, lsr #24
    add r8, r8, r9, lsl #8
    and r7, r12, r7, lsr #1
    and r8, r12, r8, lsr #1
    add r3, r3, r7
    add r4, r4, r8
    stmia r1, {r3, r4}
    add r1, r1, #0x100
    subs r2, r2, #1
    moveq pc, lr
    ldrb r3, [r0, #-1]
    ldmia r0, {r4, r9}
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    and r9, r12, r9, lsr #1
    add r3, r3, r4, lsl #8
    add r3, r3, r4
    add r4, r9, r4, lsr #24
    add r4, r4, r9, lsl #8
    and r3, r12, r3, lsr #1
    and r4, r12, r4, lsr #1
    add r7, r7, r3
    add r8, r8, r4
    stmia r1, {r7, r8}
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L02081958
    mov pc, lr
@L020819ec:
    dcd 0x7f7f7f7f
@L020819f0:
    ldr r3, [r0], #0x100
    str r3, [r1], #0x100
    subs r2, r2, #1
    bne @L020819f0
    mov pc, lr
@L02081a04:
    ldr r12, [pc, #0x4dc] // @L02081ee8
    ldr r3, [r0], #0x100
    and r3, r12, r3, lsr #1
@L02081a10:
    ldr r7, [r0], #0x100
    and r7, r12, r7, lsr #1
    add r3, r3, r7
    str r3, [r1], #0x100
    subs r2, r2, #1
    moveq pc, lr
    ldr r3, [r0], #0x100
    and r3, r12, r3, lsr #1
    add r7, r7, r3
    str r7, [r1], #0x100
    subs r2, r2, #1
    bne @L02081a10
    mov pc, lr
@L02081a44:
    ldr r12, [pc, #0x49c] // @L02081ee8
@L02081a48:
    ldr r3, [r0]
    ldrb r9, [r0, #4]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r9, r12, r9, lsr #1
    add r3, r3, r3, lsr #8
    add r3, r3, r9, lsl #24
    str r3, [r1], #0x100
    subs r2, r2, #1
    bne @L02081a48
    mov pc, lr
@L02081a74:
    ldr r12, [pc, #0x46c] // @L02081ee8
    ldr r3, [r0]
    ldrb r9, [r0, #4]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r9, r12, r9, lsr #1
    add r3, r3, r3, lsr #8
    add r3, r3, r9, lsl #24
    and r3, r12, r3, lsr #1
@L02081a98:
    ldr r7, [r0]
    ldrb r9, [r0, #4]
    add r0, r0, #0x100
    and r7, r12, r7, lsr #1
    and r9, r12, r9, lsr #1
    add r7, r7, r7, lsr #8
    add r7, r7, r9, lsl #24
    and r7, r12, r7, lsr #1
    add r3, r3, r7
    str r3, [r1], #0x100
    subs r2, r2, #1
    moveq pc, lr
    ldr r3, [r0]
    ldrb r9, [r0, #4]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r9, r12, r9, lsr #1
    add r3, r3, r3, lsr #8
    add r3, r3, r9, lsl #24
    and r3, r12, r3, lsr #1
    add r7, r7, r3
    str r7, [r1], #0x100
    subs r2, r2, #1
    bne @L02081a98
    mov pc, lr
@L02081afc:
    sub r0, r0, #1
@L02081b00:
    ldr r3, [r0]
    ldrb r9, [r0, #4]
    add r0, r0, #0x100
    mov r3, r3, lsr #8
    add r3, r3, r9, lsl #24
    str r3, [r1], #0x100
    subs r2, r2, #1
    bne @L02081b00
    mov pc, lr
@L02081b24:
    sub r0, r0, #1
    ldr r12, [pc, #0x3b8] // @L02081ee8
    ldr r3, [r0]
    ldrb r9, [r0, #4]
    add r0, r0, #0x100
    mov r3, r3, lsr #8
    add r3, r3, r9, lsl #24
    and r3, r12, r3, lsr #1
@L02081b44:
    ldr r7, [r0]
    ldrb r9, [r0, #4]
    add r0, r0, #0x100
    mov r7, r7, lsr #8
    add r7, r7, r9, lsl #24
    and r7, r12, r7, lsr #1
    add r3, r3, r7
    str r3, [r1], #0x100
    subs r2, r2, #1
    moveq pc, lr
    ldr r3, [r0]
    ldrb r9, [r0, #4]
    add r0, r0, #0x100
    mov r3, r3, lsr #8
    add r3, r3, r9, lsl #24
    and r3, r12, r3, lsr #1
    add r7, r7, r3
    str r7, [r1], #0x100
    subs r2, r2, #1
    bne @L02081b44
    mov pc, lr
@L02081b98:
    ldr r12, [pc, #0x348] // @L02081ee8
    sub r0, r0, #1
@L02081ba0:
    ldr r3, [r0]
    ldrh r9, [r0, #4]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r9, r12, r9, lsr #1
    mov r10, r3, lsr #0x10
    add r10, r10, r9, lsl #16
    add r10, r10, r3, lsr #8
    add r3, r10, r9, lsl #24
    str r3, [r1], #0x100
    subs r2, r2, #1
    bne @L02081ba0
    mov pc, lr
@L02081bd4:
    ldr r12, [pc, #0x30c] // @L02081ee8
    sub r0, r0, #1
    ldr r3, [r0]
    ldrh r9, [r0, #4]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r9, r12, r9, lsr #1
    mov r10, r3, lsr #0x10
    add r10, r10, r9, lsl #16
    add r10, r10, r3, lsr #8
    add r3, r10, r9, lsl #24
    and r3, r12, r3, lsr #1
@L02081c04:
    ldr r7, [r0]
    ldrh r9, [r0, #4]
    add r0, r0, #0x100
    and r7, r12, r7, lsr #1
    and r9, r12, r9, lsr #1
    mov r10, r7, lsr #0x10
    add r10, r10, r9, lsl #16
    add r10, r10, r7, lsr #8
    add r7, r10, r9, lsl #24
    and r7, r12, r7, lsr #1
    add r3, r3, r7
    str r3, [r1], #0x100
    subs r2, r2, #1
    moveq pc, lr
    ldr r3, [r0]
    ldrh r9, [r0, #4]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r9, r12, r9, lsr #1
    mov r10, r3, lsr #0x10
    add r10, r10, r9, lsl #16
    add r10, r10, r3, lsr #8
    add r3, r10, r9, lsl #24
    and r3, r12, r3, lsr #1
    add r7, r7, r3
    str r7, [r1], #0x100
    subs r2, r2, #1
    bne @L02081c04
    mov pc, lr
@L02081c78:
    ldrh r3, [r0], #2
    ldrh r9, [r0], #-2
    add r0, r0, #0x100
    add r3, r3, r9, lsl #16
    str r3, [r1], #0x100
    subs r2, r2, #1
    bne @L02081c78
    mov pc, lr
@L02081c98:
    ldr r12, [pc, #0x248] // @L02081ee8
    ldrh r3, [r0], #2
    ldrh r9, [r0], #-2
    add r0, r0, #0x100
    add r3, r3, r9, lsl #16
    and r3, r12, r3, lsr #1
@L02081cb0:
    ldrh r7, [r0], #2
    ldrh r9, [r0], #-2
    add r0, r0, #0x100
    add r7, r7, r9, lsl #16
    and r7, r12, r7, lsr #1
    add r3, r3, r7
    str r3, [r1], #0x100
    subs r2, r2, #1
    moveq pc, lr
    ldrh r3, [r0], #2
    ldrh r9, [r0], #-2
    add r0, r0, #0x100
    add r3, r3, r9, lsl #16
    and r3, r12, r3, lsr #1
    add r7, r7, r3
    str r7, [r1], #0x100
    subs r2, r2, #1
    bne @L02081cb0
    mov pc, lr
@L02081cfc:
    ldr r12, [pc, #0x1e4] // @L02081ee8
    add r0, r0, #2
@L02081d04:
    ldrh r3, [r0, #-2]
    ldr r9, [r0], #0x100
    and r3, r12, r3, lsr #1
    and r9, r12, r9, lsr #1
    add r10, r3, r9, lsl #16
    add r10, r10, r3, lsr #8
    add r3, r10, r9, lsl #8
    str r3, [r1], #0x100
    subs r2, r2, #1
    bne @L02081d04
    mov pc, lr
@L02081d30:
    ldr r12, [pc, #0x1b0] // @L02081ee8
    add r0, r0, #2
    ldrh r3, [r0, #-2]
    ldr r9, [r0], #0x100
    and r3, r12, r3, lsr #1
    and r9, r12, r9, lsr #1
    add r10, r3, r9, lsl #16
    add r10, r10, r3, lsr #8
    add r3, r10, r9, lsl #8
    and r3, r12, r3, lsr #1
@L02081d58:
    ldrh r7, [r0, #-2]
    ldr r9, [r0], #0x100
    and r7, r12, r7, lsr #1
    and r9, r12, r9, lsr #1
    add r10, r7, r9, lsl #16
    add r10, r10, r7, lsr #8
    add r7, r10, r9, lsl #8
    and r7, r12, r7, lsr #1
    add r3, r3, r7
    str r3, [r1], #0x100
    subs r2, r2, #1
    moveq pc, lr
    ldrh r3, [r0, #-2]
    ldr r9, [r0], #0x100
    and r3, r12, r3, lsr #1
    and r9, r12, r9, lsr #1
    add r10, r3, r9, lsl #16
    add r10, r10, r3, lsr #8
    add r3, r10, r9, lsl #8
    and r3, r12, r3, lsr #1
    add r7, r7, r3
    str r7, [r1], #0x100
    subs r2, r2, #1
    bne @L02081d58
    mov pc, lr
@L02081dbc:
    add r0, r0, #1
@L02081dc0:
    ldrb r3, [r0, #-1]
    ldr r9, [r0], #0x100
    add r3, r3, r9, lsl #8
    str r3, [r1], #0x100
    subs r2, r2, #1
    bne @L02081dc0
    mov pc, lr
@L02081ddc:
    ldr r12, [pc, #0x104] // @L02081ee8
    add r0, r0, #1
    ldrb r3, [r0, #-1]
    ldr r9, [r0], #0x100
    add r3, r3, r9, lsl #8
    and r3, r12, r3, lsr #1
@L02081df4:
    ldrb r7, [r0, #-1]
    ldr r9, [r0], #0x100
    add r7, r7, r9, lsl #8
    and r7, r12, r7, lsr #1
    add r3, r3, r7
    str r3, [r1], #0x100
    subs r2, r2, #1
    moveq pc, lr
    ldrb r3, [r0, #-1]
    ldr r9, [r0], #0x100
    add r3, r3, r9, lsl #8
    and r3, r12, r3, lsr #1
    add r7, r7, r3
    str r7, [r1], #0x100
    subs r2, r2, #1
    bne @L02081df4
    mov pc, lr
@L02081e38:
    ldr r12, [pc, #0xa8] // @L02081ee8
    add r0, r0, #1
@L02081e40:
    ldrb r3, [r0, #-1]
    ldr r9, [r0], #0x100
    and r3, r12, r3, lsr #1
    and r9, r12, r9, lsr #1
    add r3, r3, r9, lsl #8
    add r3, r3, r9
    str r3, [r1], #0x100
    subs r2, r2, #1
    bne @L02081e40
    mov pc, lr
@L02081e68:
    ldr r12, [pc, #0x78] // @L02081ee8
    add r0, r0, #1
    ldrb r3, [r0, #-1]
    ldr r9, [r0], #0x100
    and r3, r12, r3, lsr #1
    and r9, r12, r9, lsr #1
    add r3, r3, r9, lsl #8
    add r3, r3, r9
    and r3, r12, r3, lsr #1
@L02081e8c:
    ldrb r7, [r0, #-1]
    ldr r9, [r0], #0x100
    and r7, r12, r7, lsr #1
    and r9, r12, r9, lsr #1
    add r7, r7, r9, lsl #8
    add r7, r7, r9
    and r7, r12, r7, lsr #1
    add r3, r3, r7
    str r3, [r1], #0x100
    subs r2, r2, #1
    moveq pc, lr
    ldrb r3, [r0, #-1]
    ldr r9, [r0], #0x100
    and r3, r12, r3, lsr #1
    and r9, r12, r9, lsr #1
    add r3, r3, r9, lsl #8
    add r3, r3, r9
    and r3, r12, r3, lsr #1
    add r7, r7, r3
    str r7, [r1], #0x100
    subs r2, r2, #1
    bne @L02081e8c
    mov pc, lr
@L02081ee8:
    dcd 0x7f7f7f7f
@L02081eec:
    ldrh r3, [r0]
    add r0, r0, #0x100
    strh r3, [r1]
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L02081eec
    mov pc, lr
@L02081f08:
    ldr r12, [pc, #0x26c] // @L0208217c
    ldrh r3, [r0]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
@L02081f18:
    ldrh r7, [r0]
    add r0, r0, #0x100
    and r7, r12, r7, lsr #1
    add r3, r3, r7
    strh r3, [r1]
    add r1, r1, #0x100
    subs r2, r2, #1
    moveq pc, lr
    ldrh r3, [r0]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    add r7, r7, r3
    strh r7, [r1]
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L02081f18
    mov pc, lr
@L02081f5c:
    ldr r12, [pc, #0x218] // @L0208217c
@L02081f60:
    ldrh r3, [r0]
    ldrb r9, [r0, #2]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r9, r12, r9, lsr #1
    add r3, r3, r3, lsr #8
    add r3, r3, r9, lsl #8
    strh r3, [r1]
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L02081f60
    mov pc, lr
@L02081f90:
    ldr r12, [pc, #0x1e4] // @L0208217c
    ldrh r3, [r0]
    ldrb r9, [r0, #2]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r9, r12, r9, lsr #1
    add r3, r3, r3, lsr #8
    add r3, r3, r9, lsl #8
    and r3, r12, r3, lsr #1
@L02081fb4:
    ldrh r7, [r0]
    ldrb r9, [r0, #2]
    add r0, r0, #0x100
    and r7, r12, r7, lsr #1
    and r9, r12, r9, lsr #1
    add r7, r7, r7, lsr #8
    add r7, r7, r9, lsl #8
    and r7, r12, r7, lsr #1
    add r3, r3, r7
    strh r3, [r1]
    add r1, r1, #0x100
    subs r2, r2, #1
    moveq pc, lr
    ldrh r3, [r0]
    ldrb r9, [r0, #2]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r9, r12, r9, lsr #1
    add r3, r3, r3, lsr #8
    add r3, r3, r9, lsl #8
    and r3, r12, r3, lsr #1
    add r7, r7, r3
    strh r7, [r1]
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L02081fb4
    mov pc, lr
@L02082020:
    add r0, r0, #1
@L02082024:
    ldrb r3, [r0, #-1]
    ldrb r9, [r0], #0x100
    add r3, r3, r9, lsl #8
    strh r3, [r1]
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L02082024
    mov pc, lr
@L02082044:
    add r0, r0, #1
    ldr r12, [pc, #0x12c] // @L0208217c
    ldrb r3, [r0, #-1]
    ldrb r9, [r0], #0x100
    add r3, r3, r9, lsl #8
    and r3, r12, r3, lsr #1
@L0208205c:
    ldrb r7, [r0, #-1]
    ldrb r9, [r0], #0x100
    add r7, r7, r9, lsl #8
    and r7, r12, r7, lsr #1
    add r3, r3, r7
    strh r3, [r1]
    add r1, r1, #0x100
    subs r2, r2, #1
    moveq pc, lr
    ldrb r3, [r0, #-1]
    ldrb r9, [r0], #0x100
    add r3, r3, r9, lsl #8
    and r3, r12, r3, lsr #1
    add r7, r7, r3
    strh r7, [r1]
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L0208205c
    mov pc, lr
@L020820a8:
    ldr r12, [pc, #0xcc] // @L0208217c
@L020820ac:
    ldrb r3, [r0]
    ldrh r9, [r0, #1]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r9, r12, r9, lsr #1
    mov r10, r9, lsl #0x18
    add r10, r3, r10, lsr #16
    add r3, r10, r9
    strh r3, [r1]
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L020820ac
    mov pc, lr
@L020820e0:
    ldr r12, [pc, #0x94] // @L0208217c
    ldrb r3, [r0]
    ldrh r9, [r0, #1]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r9, r12, r9, lsr #1
    mov r10, r9, lsl #0x18
    add r10, r3, r10, lsr #16
    add r3, r10, r9
    and r3, r12, r3, lsr #1
@L02082108:
    ldrb r7, [r0]
    ldrh r9, [r0, #1]
    add r0, r0, #0x100
    and r7, r12, r7, lsr #1
    and r9, r12, r9, lsr #1
    mov r10, r9, lsl #0x18
    add r10, r7, r10, lsr #16
    add r7, r10, r9
    and r7, r12, r7, lsr #1
    add r3, r3, r7
    strh r3, [r1]
    add r1, r1, #0x100
    subs r2, r2, #1
    moveq pc, lr
    ldrb r3, [r0]
    ldrh r9, [r0, #1]
    add r0, r0, #0x100
    and r3, r12, r3, lsr #1
    and r9, r12, r9, lsr #1
    mov r10, r9, lsl #0x18
    add r10, r3, r10, lsr #16
    add r3, r10, r9
    and r3, r12, r3, lsr #1
    add r7, r7, r3
    strh r7, [r1]
    add r1, r1, #0x100
    subs r2, r2, #1
    bne @L02082108
    mov pc, lr
@L0208217c:
    dcd 0x7f7f7f7f
@L02082180:
    ldrb r3, [r0], #0x100
    strb r3, [r1], #0x100
    subs r2, r2, #1
    bne @L02082180
    mov pc, lr
@L02082194:
    ldrb r3, [r0], #0x100
    mov r3, r3, lsr #1
@L0208219c:
    ldrb r7, [r0], #0x100
    mov r7, r7, lsr #1
    add r3, r3, r7
    strb r3, [r1], #0x100
    subs r2, r2, #1
    moveq pc, lr
    ldrb r3, [r0], #0x100
    mov r3, r3, lsr #1
    add r7, r7, r3
    strb r7, [r1], #0x100
    subs r2, r2, #1
    bne @L0208219c
    mov pc, lr
@L020821d0:
    add r0, r0, #1
@L020821d4:
    ldrb r3, [r0, #-1]
    ldrb r9, [r0], #0x100
    mov r3, r3, lsr #1
    add r3, r3, r9, lsr #1
    strb r3, [r1], #0x100
    subs r2, r2, #1
    bne @L020821d4
    mov pc, lr
@L020821f4:
    ldrb r3, [r0], #1
    ldrb r9, [r0], #0x100
    mov r3, r3, lsr #1
    add r3, r3, r9, lsr #1
    mov r3, r3, lsr #1
@L02082208:
    ldrb r7, [r0, #-1]
    ldrb r9, [r0], #0x100
    mov r7, r7, lsr #1
    add r7, r7, r9, lsr #1
    mov r7, r7, lsr #1
    add r3, r3, r7
    strb r3, [r1], #0x100
    subs r2, r2, #1
    moveq pc, lr
    ldrb r3, [r0, #-1]
    ldrb r9, [r0], #0x100
    mov r3, r3, lsr #1
    add r3, r3, r9, lsr #1
    mov r3, r3, lsr #1
    add r7, r7, r3
    strb r7, [r1], #0x100
    subs r2, r2, #1
    bne @L02082208
    mov pc, lr
}

