#include "ov000/LoCommon.h"
#include "nitro/fx.h"

typedef struct {
    u32 b0 : 2;
    u32 f2 : 5;
    u32 f7 : 6;
    u32 pad13 : 6;
    u32 b19 : 1;
    u32 b20 : 1;
    u32 b21 : 1;
    u32 rest : 10;
} LoMdlFlags0216df28;

#define MF(m) LFLD(LoMdlFlags0216df28, m, 0x6c)
#define M10 LFLD(u8 *, self, 0x10)
#define M14 LFLD(u8 *, self, 0x14)

extern "C" {

void *NNS_G2dGetCellDataByIdx(void *a, int b);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);
void func_02041c18(void *m, int a);
void func_ov000_0216d9dc(void *self, s32 unused, u16 *msg);

static inline void *LoModelGetPart(void *self, int idx) {
    if (idx >= LFLD(s32, self, 0x80)) {
        return NULL;
    }
    return (u8 *)LFLD(void *, self, 0x78) + idx * 0x28;
}

static inline void LoModelPlayPartF(void *model, int idx, int f) {
    void *res = LFLD(void *, model, 0x28);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = LoModelGetPart(model, idx);
    if (part != NULL && LFLD(void *, part, 0x4) != NULL) {
        anim = LFLD(void *, LFLD(void *, part, 0x4), 0x30);
    } else {
        anim = NNS_G2dGetCellDataByIdx(LFLD(void *, res, 0x4), **(u16 **)LFLD(void *, NNS_G2dGetAnimSequenceByIdx(LFLD(void *, res, 0xc), idx), 0xc));
    }
    func_02042628(model, anim, part, f);
}

static inline void LoModelPlayPart(void *model, int idx) {
    LoModelPlayPartF(model, idx, 0);
}

static inline void LoSetPos(void *m, s32 x, s32 y) {
    LFLD(s32, m, 0xfc) = x;
    LFLD(s32, m, 0x100) = y;
}

static inline void LoPlace(u8 *self, s32 x, s32 y) {
    MF(M10).b21 = 1;
    LFLD(s32, M10, 0x150) = -0x1f80;
    LoSetPos(M10, x << 12, y << 12);
}
static inline void LoPlace2(u8 *self, s32 z, s32 x, s32 y) {
    MF(M10).b21 = 1;
    LFLD(s32, M10, 0x150) = z;
    LoSetPos(M10, x << 12, y << 12);
}

void func_ov000_0216df28(u8 *self) {
    u8 *m;
    s32 st = LFLD(s32, self, 4);
    s32 s;
    if (st != 7 && st != 8 && st != 9) {
        return;
    }
    {
        s32 y;
        s32 x;
        x = (LO_FX_MUL(LFLD(s32, self, 0x30), 0x80000) >> 12) - 0x80;
        y = (LFLD(s32, self, 0x4c) - 0x60000) >> 12;
        if (LBIT(self, 0).b10 == 1) {
            LoPlace(self, x + 0xbd, y + 0x1e + (LFLD(s32, self, 0x3c) >> 12));
            LoModelPlayPart(M10, 0xf);
            MF(M10).b21 = 0;
        }
        MF(M10).f2 = 0x1e;
        LFLD(s32, M10, 0x150) = -0x2000;
        LoSetPos(M10, (x + 0xff) << 12, (y + 0x18) << 12);
        LoModelPlayPart(M10, 0xc);
        func_02041c18(M14, LFLD(s32, self, 0x20));
        LoSetPos(M14, (x + 0xf7) << 12, (y + 0x24) << 12);
        m = M14;
        LoModelPlayPart(m, 0x1f);
        if (LBIT(self, 0).b8 == 1) {
            s = LO_FX_MUL(LFLD(s32, self, 0x3c), 0x1000);
            MTX_Identity22_((MtxFx22 *)(M14 + 0x114));
            MTX_ScaleApply22((MtxFx22 *)(M14 + 0x114), (MtxFx22 *)(M14 + 0x114), s + 0x1000, s + 0x1000);
            LFLD(u16, M14, 0x154) = 0x1098;
            LoModelPlayPartF(M14, 0x1e, 1);
        } else {
            if (LBIT(self, 0).b9 == 1) {
                LFLD(u16, M14, 0x154) = 0x1098;
            }
            LoModelPlayPart(M14, 0x1e);
        }
        LFLD(u16, M14, 0x154) = 0x7fff;
        if (LFLD(s32, self, 0x28) == 0) {
            return;
        }
        LoSetPos(M14, (x + 0xc9) << 12, (y + 9) << 12);
        LoModelPlayPart(M14, 0x20);
        func_02041c18(M14, LFLD(s32, self, 0x28));
        LoSetPos(M14, (x + 0xf7) << 12, (y + 0xf) << 12);
        LoModelPlayPart(M14, 0x1f);
        if (LBIT(self, 0).b11 == 1) {
            LFLD(void *, M14, 0x15c) = (void *)func_ov000_0216d9dc;
            if (LBIT(self, 0).b12 == 1) {
                LFLD(u16, M14, 0x154) = 0x7792;
            }
            LoModelPlayPartF(M14, 0x1e, 1);
            LFLD(u16, M14, 0x154) = 0x7fff;
            LFLD(s32, M14, 0x15c) = 0;
        } else {
            LoModelPlayPart(M14, 0x1e);
        }
    }
}

}
