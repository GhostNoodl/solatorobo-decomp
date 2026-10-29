#include "ov010/ov010.h"

extern "C" {

extern u8 data_ov010_0220fd70[];
extern void func_ov003_021da48c(void *p, s32 a);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);
extern void *func_ov000_02198328(void *p);
extern void func_ov010_02200ee0(void *p);
BOOL func_ov010_022006fc(u8 *o, u16 a, u16 b, u8 c, u16 d);

void func_ov010_02200670(u8 *o, const Ov010Vec *v, u16 a, u16 b, s16 c, s16 d, u8 e, u16 g) {
    if (!FLD(Ov010Flags8, o, 0).b0) {
        return;
    }
    if (FLD(u8, o, 0x43) != 0) {
        return;
    }
    FLD(Ov010Flags8, o, 0).b1 = e;
    FLD(s16, o, 6) = c;
    FLD(u16, o, 8) = 0;
    FLD(s16, o, 0xa) = d;
    FLD(u16, o, 0xc) = g;
    FLD(u16, o, 0xe) = a;
    FLD(u16, o, 0x10) = b;
    FLD(s32, o, 0x14) = 0;
    FLD(s32, o, 0x18) = 0;
    FLD(s32, o, 0x1c) = 0;
    FLD(Ov010Vec, o, 0x24) = *v;
    func_ov003_021da48c(o + 0x30, 1);
}

BOOL func_ov010_022006fc(u8 *o, u16 a, u16 b, u8 c, u16 d) {
    FLD(u8, o, 0) = 1;
    FLD(u8, o, 1) = 0;
    FLD(u8, o, 2) = c;
    FLD(u16, o, 4) = a;
    FLD(u16, o, 6) = b;
    FLD(u16, o, 8) = d;
    FLD(u16, o, 0xa) = 0;
    FLD(u16, o, 0xc) = 0;
    FLD(u16, o, 0xe) = 0;
    FLD(u16, o, 0x10) = 0;
    FLD(u16, o, 0x12) = 0;
    FLD(s32, o, 0x14) = 0;
    FLD(s32, o, 0x18) = 0;
    FLD(Ov010Vec, o, 0x1c) = FLD(Ov010Vec, data_ov010_0220fd70, 0x20);
    func_ov003_021da48c(o + 0x6c, 0);
    FLD(u16, o, 0x6e) = 0;
    func_ov000_02198360(o + 0x6c, 5, 0);
    return TRUE;
}

extern void *data_0214a420;
extern u8 *data_ov000_021ccd54;
extern void *data_02097e4c;
extern void func_02065804(void *a, s32 b);
extern BOOL func_ov010_02200048(u8 *o, u16 a, u16 b, u8 c, u16 d);
extern BOOL func_ov010_02200c98(u8 *o);
extern void *func_0204a028(void *a, s32 b, void *c, s32 d);
extern void func_ov010_022000d8(u8 *o);

static inline BOOL Ov010Beam_IsDone(u8 *s) {
    BOOL r = TRUE;
    if (FLD(Ov010Flags8, s, 0).b0 && FLD(u8, s, 0x43) != 0) {
        r = FALSE;
    }
    return r;
}

void func_ov010_0220078c(u8 *o) {
    s32 k;
    if (FLD(u8, o, 0) == 0) {
        return;
    }
    FLD(s32, o, 0x18) = 0;
    switch (FLD(u8, o, 0x7f)) {
    case 5:
        FLD(s32, o, 0x14) = 0;
        break;
    case 0:
        if (FLD(Ov010Flags8, o, 0x28).b0) {
            FLD(Ov010Flags8, o, 0x28).b0 = 0;
            func_02065804(data_0214a420, FLD(s32, o, 0x3c));
            func_02065804(data_0214a420, FLD(s32, o, 0x40));
            func_02065804(data_0214a420, FLD(s32, o, 0x44));
            FLD(s32, o, 0x3c) = 0;
            FLD(s32, o, 0x40) = 0;
            FLD(s32, o, 0x44) = 0;
        }
        func_ov010_02200048(o + 0x28, FLD(u16, o, 4), FLD(u16, o, 6), FLD(u8, o, 2), FLD(u16, o, 8));
        func_ov000_02198360(o + 0x6c, 1, 0);
        break;
    case 1:
        if (func_ov010_02200c98(o)) {
            func_ov000_02198360(o + 0x6c, 2, 0);
        }
        break;
    case 2:
        FLD(u16, o, 0x6e)++;
        if (FLD(u16, o, 0x6e) > 10) {
            FLD(u16, o, 0x6e) = 0;
            func_ov000_02198360(o + 0x6c, 3, 0);
        }
        break;
    case 3:
        if (FLD(u16, o, 0x6c) == 0) {
            FLD(s32, o, 0x18) = 1;
            func_ov010_02200670(o + 0x28, (Ov010Vec *)(o + 0x1c), FLD(u16, o, 0x10), FLD(u16, o, 0x12), FLD(s16, o, 0xc), FLD(s16, o, 0xe), 0, FLD(u16, o, 0xa));
            if (FLD(u8, o, 1) != 0) {
                u8 *g = data_ov000_021ccd54;
                FLD(u8, g, 0x190) |= 0x1c;
                FLD(u8, g, 0x18d) = 0xf;
                FLD(u8, g, 0x18e) = 10;
                FLD(u8, g, 0x18f) = 10;
                func_0204a028(data_02097e4c, 0x5c, o + 0x1c, 5);
            }
            FLD(u16, o, 0x6c)++;
        } else if (Ov010Beam_IsDone(o + 0x28)) {
            FLD(s32, o, 0x18) = 2;
            func_ov000_02198360(o + 0x6c, 4, 0);
        }
        break;
    case 4:
        if (FLD(Ov010Flags8, o, 0x28).b0 && FLD(u8, o, 0x6b) == 1) {
            func_ov003_021da48c(o + 0x58, 2);
        }
        func_ov000_02198360(o + 0x6c, 5, 0);
        break;
    }
    k = 0;
    if (FLD(Ov010Flags8, o, 0x28).b0) {
        if (!Ov010Beam_IsDone(o + 0x28)) {
            k = FLD(s32, o, 0x48);
        }
    }
    if (k == 1) {
        FLD(s32, o, 0x18) = 2;
    }
    func_ov010_022000d8(o + 0x28);
}

extern u8 data_020928b4[];
extern u8 NNS_G3dGlb[];
extern u8 *data_02097d48;
extern void MTX_Identity33_(void *m);
extern void MI_Copy36B(void *m, void *b);
extern void NNS_G3dGlbSetBaseTrans(Ov010Vec *v);
extern void NNS_G3dGlbSetBaseScale(Ov010Vec *v);
extern void NNS_G3dGlbFlushVP(void);
extern void NNS_G3dGeBufferOP_N(s32 cmd, const void *data, s32 n);
extern void MTX_RotX33_(void *m, s32 s, s32 c);
extern void MTX_RotY33_(void *m, s32 s, s32 c);
extern u8 func_02043d48(void *p);
extern void NNS_G3dGeFlushBuffer(void);

static inline void Ov010_G3End(void) {
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
}

}
