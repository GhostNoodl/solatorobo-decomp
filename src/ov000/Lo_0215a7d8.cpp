#include "ov000/LoCommon.h"

typedef struct {
    u32 b0 : 2;
    u32 f2 : 5;
    u32 rest : 25;
} LoF2;

extern "C" {

void *NNS_G2dGetCellDataByIdx(void *a, int b);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);
void func_ov000_0215a8c8(void);

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

void func_ov000_0215a7d8(void *self, s32 unused, s32 *pos) {
    s16 z = LFLD(s16, self, 0x68) - 0x100;
    LFLD(void *, LFLD(void *, self, 0x10), 0x158) = (void *)func_ov000_0215a8c8;
    LFLD(u32, LFLD(void *, self, 0x10), 0x6c) |= 0x80000;
    LFLD(u32, LFLD(void *, self, 0x10), 0x6c) |= 0x200000;
    LFLD(LoF2, LFLD(void *, self, 0x10), 0x6c).f2 = 0x1e;
    {
        s32 px = pos[0];
        s32 py = pos[1];
        u8 *o = LFLD(u8 *, self, 0x10);
        LFLD(s32, o, 0xfc) = px;
        LFLD(s32, o, 0x100) = py;
    }
    LFLD(s32, LFLD(void *, self, 0x10), 0x150) = z;
    LoModelPlayPart(LFLD(void *, self, 0x10), 8);
    LFLD(void *, LFLD(void *, self, 0x10), 0x158) = NULL;
}

}
