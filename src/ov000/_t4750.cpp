#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

typedef struct {
    u32 b0 : 3;
    u32 b3 : 1;
} LoCb8Bits;

extern "C" {

void *NNS_G2dGetCellDataByIdx(void *a, int b);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);
void func_02041c20(void *a, int b, int c);
void func_ov000_0216715c(void *self);
void func_ov000_021675ec(void *self);

static inline void *LoModelGetPart(void *self, int idx) {
    if (idx >= LFLD(s32, self, 0x80)) {
        return NULL;
    }
    return (u8 *)LFLD(void *, self, 0x78) + idx * 0x28;
}

static inline void LoModelPlayPart(void *model, int idx) {
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
    func_02042628(model, anim, part, 0);
}

static inline void LoPlayIf(void *m, int idx) {
    if (m != NULL) {
        LoModelPlayPart(m, idx);
    }
}

static inline void *Cb8_4750(u8 *p) {
    if (p == NULL || LFLD(void *, p, 0xcb4) == NULL) return NULL;
    return LFLD(void *, p, 0xcb8);
}
static inline void *Cb8b_4750(u8 *p) {
    void *q = NULL;
    if (p != NULL && LFLD(void *, p, 0xcb4) != NULL) q = LFLD(void *, p, 0xcb8);
    return q;
}
static inline BOOL Ready_4750(u8 *p) {
    if (p == NULL || LFLD(void *, p, 0xcb4) == NULL || LFLD(void *, p, 0xcb8) == NULL) return FALSE;
    return TRUE;
}
void func_ov000_02164750(u8 *self) {
    void *m;
    VObj *o;
    u8 *p;
    void *q;
    if (LFLD(s32, self, 0x20) != 7) {
        return;
    }
    LoPlayIf(LFLD(void *, self, 0x28), 0);
    m = LFLD(void *, self, 0x24);
    if (m != NULL) {
        LFLD(s32, m, 0x10c) = 0;
        LFLD(s32, m, 0x110) = 0;
        LoModelPlayPart(LFLD(void *, self, 0x24), 0);
        func_02041c20(LFLD(void *, self, 0x24), 1, 0);
        LoModelPlayPart(LFLD(void *, self, 0x24), 1);
        func_02041c20(LFLD(void *, self, 0x24), 1, 1);
        LoModelPlayPart(LFLD(void *, self, 0x24), 1);
    }
    LoPlayIf(LFLD(void *, self, 0x2c), 0);
    o = LFLD(VObj *, self, 0x40);
    if (o != NULL && LFLD(s32, self, 0x4c) != 0) {
        s32 y = LO_FX_MUL(FX_SinCosTable_[(((0x1000 - LFLD(s32, self, 0x4c)) << 14) >> 16) * 2], 0x80000) >> 12;
        o->vfunc_20(y + 0xcc - (LFLD(s32, o, 0x44) >> 1), 1);
        LFLD(VObj *, self, 0x40)->vfunc_90();
        LFLD(VObj *, self, 0x40)->vfunc_94();
    }
    if (LFLD(s32, self, 0x34) == 10) {
        return;
    }
    p = LFLD(u8 *, self, 0x30);
    if (p == NULL || LFLD(void *, p, 0xcb4) == NULL || (q = LFLD(void *, p, 0xcb8)) == NULL) {
        return;
    }
    if (p[1] < 2) {
        return;
    }
    if (!LFLD(LoCb8Bits, q, 0).b3) {
        func_ov000_0216715c(self);
    } else {
        func_ov000_021675ec(self);
    }
}

}
