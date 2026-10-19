// NitroSDK/TwlSDK crt0: position-independent helper that _start copies into ITCM and runs from
// there (hand-written assembly). func_02004ffc, the next helper, stays in the gap so that the gap
// object after it keeps a function (objdiff cannot handle a code section with no mapping symbol).

#pragma force_active on

void func_02004fd4(void);

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

