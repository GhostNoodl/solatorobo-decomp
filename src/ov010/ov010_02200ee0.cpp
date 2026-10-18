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

void func_ov010_02200ee0(u8 *o) {
    u8 *next;
    u8 *n;
    if (!FLD(Ov010Flags8, o, 0).b0) {
        return;
    }
    for (n = FLD(u8 *, o, 0x10); n != NULL; n = next) {
        u32 saved;
        next = FLD(u8 *, n, 8);
        Ov010Beam_Reset(n + 0xc);
        saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (n != NULL) {
            if (n != NULL) {
                Ov010Beam_Reset(n + 0xc);
                Ov010Fx_Free(n + 0x34);
                func_0203de1c(n);
            }
        }
        data_02097dd0->cur = saved;
    }
    FLD(u8 *, o, 0x10) = NULL;
    FLD(Ov010Flags8, o, 0).b0 = 0;
}

}
