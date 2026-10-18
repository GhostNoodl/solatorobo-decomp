#include "ov010/ov010.h"

struct Ov010Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

struct Ov010PlFlags {
    u32 b0 : 12;
    u32 b12 : 2;
    u32 b14 : 18;
};

extern "C" {

extern void *data_0214a420;
extern Ov010Heap *data_02097dd0;
extern void func_02065804(void *a, s32 b);
extern void func_ov003_021da48c(void *p, s32 a);
extern void func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_ov010_02200a00(u8 *o);
extern u8 *func_ov000_0219bf90(void);
extern s32 func_ov003_021d9a80(const Ov010Vec *a, const Ov010Vec *b);

static inline void Ov010Fx_Free(u8 *s) {
    if (FLD(Ov010Flags8, s, 0).b0) {
        FLD(Ov010Flags8, s, 0).b0 = 0;
        func_02065804(data_0214a420, FLD(s32, s, 0x14));
        func_02065804(data_0214a420, FLD(s32, s, 0x18));
        func_02065804(data_0214a420, FLD(s32, s, 0x1c));
        FLD(s32, s, 0x14) = 0;
        FLD(s32, s, 0x18) = 0;
        FLD(s32, s, 0x1c) = 0;
    }
}

static inline void Ov010Beam_Reset(u8 *b) {
    if (FLD(u8, b, 0) != 0) {
        Ov010Fx_Free(b + 0x28);
        FLD(u8, b, 0) = 0;
    }
}

void func_ov010_0220166c(u8 *o) {
    u8 *n;
    if (!FLD(Ov010Flags8, o, 0).b0) {
        return;
    }
    for (n = FLD(u8 *, o, 0x10); n != NULL; n = FLD(u8 *, n, 8)) {
        func_ov010_02200a00(n + 0xc);
    }
}

void func_ov010_022016a0(u8 *o, const Ov010Vec *a, const Ov010Vec *b, u16 c) {
    if (!FLD(Ov010Flags8, o, 0).b0) {
        return;
    }
    if (FLD(u16, o, 0x2c) != 0x65) {
        return;
    }
    FLD(u16, o, 0x2c) = 0;
    FLD(Ov010Vec, o, 0x14) = *a;
    FLD(Ov010Vec, o, 0x20) = *b;
    FLD(u16, o, 8) = c;
}

void func_ov010_02201700(u8 *o) {
    if (FLD(Ov010Flags8, o, 0).b0 && FLD(u16, o, 0x2c) != 0x64 && FLD(u16, o, 0x2c) != 0x65) {
        FLD(u16, o, 0x2e) = 0;
        FLD(u16, o, 0x2c) = 0x64;
    }
}

void func_ov010_0220172c(u8 *o) {
    u8 *n;
    if (!FLD(Ov010Flags8, o, 0).b0) {
        return;
    }
    func_ov003_021da48c(o + 0x2c, 0);
    FLD(u16, o, 0x2c) = 0x65;
    for (n = FLD(u8 *, o, 0x10); n != NULL; n = FLD(u8 *, n, 8)) {
        if (FLD(u8, n, 0xc) != 0) {
            func_ov003_021da48c(n + 0x78, 0);
            func_ov000_02198360(n + 0x78, 5, 0);
            if (FLD(Ov010Flags8, n, 0x34).b0) {
                func_02065804(data_0214a420, FLD(s32, n, 0x48));
                func_02065804(data_0214a420, FLD(s32, n, 0x4c));
                func_02065804(data_0214a420, FLD(s32, n, 0x50));
                FLD(s32, n, 0x48) = 0;
                FLD(s32, n, 0x4c) = 0;
                FLD(s32, n, 0x50) = 0;
                func_ov003_021da48c(n + 0x64, 0);
                func_ov000_02198360(n + 0x64, 0, 1);
            }
        }
    }
}

BOOL func_ov010_0220180c(u8 *o) {
    BOOL r = TRUE;
    if (FLD(Ov010Flags8, o, 0).b0 && FLD(u16, o, 0x2c) != 0x65) {
        r = FALSE;
    }
    return r;
}

void func_ov010_02201830(u8 *o, const Ov010Vec *v) {
    u8 *n;
    if (!FLD(Ov010Flags8, o, 0).b0) {
        return;
    }
    FLD(Ov010Vec, o, 0x20) = *v;
    for (n = FLD(u8 *, o, 0x10); n != NULL; n = FLD(u8 *, n, 8)) {
        if (FLD(u8, n, 0xc) != 0) {
            FLD(Ov010Vec, n, 0x28) = FLD(Ov010Vec, o, 0x20);
        }
    }
}

void func_ov010_02201898(u8 *o, const Ov010Vec *v) {
    if (!FLD(Ov010Flags8, o, 0).b0) {
        return;
    }
    FLD(Ov010Vec, o, 0x14) = *v;
}

BOOL func_ov010_022018c4(u16 id, const Ov010Vec *a, const Ov010Vec *b) {
    BOOL r = FALSE;
    u8 *pl = func_ov000_0219bf90();
    if (id == FLD(u16, pl, 0xc) && FLD(Ov010PlFlags, pl, 0xb24).b12 == 0) {
        if (func_ov003_021d9a80(a, b) < 0x51000) {
            r = TRUE;
        }
    }
    return r;
}

}
