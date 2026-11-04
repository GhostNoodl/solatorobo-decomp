#include "types.h"

#pragma force_active on

// DSProtect: these check that the first instructions of a protection stub haven't been patched.
// The stubs are referenced as data so that the offset folds into the pool relocation.
extern u8 DSProt_RomCheckA_Stub[];
extern u8 DSProt_RomCheckB_Stub[];
extern u8 DSProt_EmuCheckA_Stub[];
extern u8 DSProt_EmuCheckB_Stub[];

#define CHECK_STUB(stub, bad, good)                                \
    u8 *p = (u8 *)((u32)((stub) + 0x3200) - 0x6400);              \
    if (p[0x3200 + 0] != 0x0f) return (bad);                       \
    if (p[0x3200 + 1] != 0xc0) return (bad);                       \
    if (p[0x3200 + 2] != 0x8f) return (bad);                       \
    if (p[0x3200 + 3] != 0xe1) return (bad);                       \
    if (p[0x3200 + 4] != 0x0c) return (bad);                       \
    if (p[0x3200 + 5] != 0xc0) return (bad);                       \
    if (p[0x3200 + 6] != 0x1c) return (bad);                       \
    if (p[0x3200 + 7] != 0xe0) return (bad);                       \
    if (p[0x3200 + 8] != 0x00) return (bad);                       \
    if (p[0x3200 + 9] != 0xc0) return (bad);                       \
    if (p[0x3200 + 10] != 0xa0) return (bad);                      \
    if (p[0x3200 + 11] != 0x03) return (bad);                      \
    if (p[0x3200 + 12] != 0x68) return (bad);                      \
    if (p[0x3200 + 13] != 0xc0) return (bad);                      \
    if (p[0x3200 + 14] != 0x8c) return (bad);                      \
    if (p[0x3200 + 15] != 0x12) return (bad);                      \
    return (good);

u32 DSProt_IsEmuCheckAStubIntact(void) {
    CHECK_STUB(DSProt_EmuCheckA_Stub, 0xc127, 0xb975)
}

u32 DSProt_IsEmuCheckBStubIntact(void) {
    CHECK_STUB(DSProt_EmuCheckB_Stub, 0xaa65, 0xb177)
}

u32 DSProt_IsRomCheckAStubIntact(void) {
    CHECK_STUB(DSProt_RomCheckA_Stub, 0xc127, 0xb975)
}

u32 DSProt_IsRomCheckBStubIntact(void) {
    CHECK_STUB(DSProt_RomCheckB_Stub, 0xaa65, 0xb177)
}

#pragma force_active reset
