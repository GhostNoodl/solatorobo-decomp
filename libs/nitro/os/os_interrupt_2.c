#include "nitro/os.h"

#define REG_IME (*(vu16 *)0x04000208)
#define REG_IE  (*(vu32 *)0x04000210)
#define REG_IF  (*(vu32 *)0x04000214)

OSIrqMask OS_SetIrqMask(OSIrqMask mask) {
    u16 ime = REG_IME;
    OSIrqMask prev;
    u16 dummy;

    REG_IME = 0;
    prev = REG_IE;
    REG_IE = mask;
    dummy = REG_IME;
    REG_IME = ime;
    return prev;
}

OSIrqMask OS_EnableIrqMask(OSIrqMask mask) {
    u16 ime = REG_IME;
    OSIrqMask prev;
    u16 dummy;

    REG_IME = 0;
    prev = REG_IE;
    REG_IE = prev | mask;
    dummy = REG_IME;
    REG_IME = ime;
    return prev;
}

OSIrqMask OS_DisableIrqMask(OSIrqMask mask) {
    u16 ime = REG_IME;
    OSIrqMask prev;
    u16 dummy;

    REG_IME = 0;
    prev = REG_IE;
    REG_IE = prev & ~mask;
    dummy = REG_IME;
    REG_IME = ime;
    return prev;
}

OSIrqMask OS_ResetRequestIrqMask(OSIrqMask mask) {
    u16 ime = REG_IME;
    OSIrqMask prev;
    u16 dummy;

    REG_IME = 0;
    prev = REG_IF;
    REG_IF = mask;
    dummy = REG_IME;
    REG_IME = ime;
    return prev;
}
