// NitroSDK/TwlSDK crt0: position-independent helpers that _start copies into ITCM and runs from
// there (hand-written assembly). func_02004fd4 waits for the halfword at r1 to change while
// counting at r0; func_02004ffc sets (r0 != 0) or clears the fast-clock bit of SCFG_CLK
// (0x04004004), returns the previous bit, and then waits r1 / 4 iterations when it changed.

#pragma force_active on

void func_02004fd4(void);
void func_02004ffc(void);

asm void func_02004fd4(void) {
    ldrh r2, [r1]
    ldrh r3, [r0]
@L02004fdc:
    add r3, r3, #1
    strh r3, [r0]
    ldrh r12, [r1]
    cmp r2, r12
    beq @L02004fdc
    add r3, r3, #1
    strh r3, [r0]
    bx lr
}

asm void func_02004ffc(void) {
    cmp r0, #0
    ldr r3, =0x4004004
    ldrh r0, [r3]
    biceq r2, r0, #1
    orrne r2, r0, #1
    cmp r0, r2
    and r0, r0, #1
    bxeq lr
    strh r2, [r3]
@L02005020:
    subs r1, r1, #4
    bge @L02005020
    bx lr
}
