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
void func_ov000_021570f0(BOOL alt, s32 x, s32 y, s32 z, s32 unused, const void *oam, const void *img, u32 charBase, u32 plttBase, s32 unused2, const void *ctx);

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

static inline void LoSetScrPos(void *m, s32 px, s32 y) {
    LFLD(s32, m, 0xfc) = (px - 0x80) << 12;
    LFLD(s32, m, 0x100) = (y - 0x60) << 12;
}

static inline void LoDrawPart(VObj *self, s32 px, s32 y, BOOL flip, u32 f, int idx) {
    if (flip) {
        LFLD(u32, LFLD(void *, self, 0x10), 0x6c) |= 0x40000;
    } else {
        LFLD(u32, LFLD(void *, self, 0x10), 0x6c) &= ~0x40000;
    }
    LFLD(LoF2, LFLD(void *, self, 0x10), 0x6c).f2 = f;
    LoSetScrPos(LFLD(void *, self, 0x10), px, y);
    LoModelPlayPart(LFLD(void *, self, 0x10), idx);
}

void func_ov000_02156d48(VObj *self, s32 unused, s32 *pos) {
    s16 z = LFLD(s16, self, 0x68) - 0x80;
    s32 py;
    s32 c8;
    s32 h;
    s32 px;
    s32 y;
    LFLD(void *, LFLD(void *, self, 0x10), 0x158) = (void *)func_ov000_021570f0;
    LFLD(u32, LFLD(void *, self, 0x10), 0x6c) |= 0x80000;
    LFLD(u32, LFLD(void *, self, 0x10), 0x6c) |= 0x200000;
    LFLD(LoF2, LFLD(void *, self, 0x10), 0x6c).f2 = 0x1e;
    {
        s32 k;
        u8 *o;
        px = pos[0];
        py = pos[1];
        k = self->vfunc_90();
        o = LFLD(u8 *, self, 0x10);
        LFLD(s32, o, 0xfc) = px + (k << 12);
        LFLD(s32, o, 0x100) = py;
    }
    LFLD(s32, LFLD(void *, self, 0x10), 0x150) = z;
    LoModelPlayPart(LFLD(void *, self, 0x10), 6);
    LFLD(void *, LFLD(void *, self, 0x10), 0x158) = NULL;
    if (LFLD(void *, self, 0x94) == NULL) {
        return;
    }
    px = (LFLD(s32, self, 0x24) >> 1) + (pos[0] >> 12) + 4;
    if (LFLD(s8, self, 0xc2) > 0) {
        y = pos[1];
        c8 = LFLD(s32, self, 0xc8);
        LFLD(u32, LFLD(void *, self, 0x10), 0x6c) |= 0x40000;
        y = (y >> 12) - 2 - (c8 >> 12);
        LFLD(LoF2, LFLD(void *, self, 0x10), 0x6c).f2 = LFLD(u8, self, 0xc2);
        LoSetScrPos(LFLD(void *, self, 0x10), px, y);
        LoModelPlayPart(LFLD(void *, self, 0x10), 10);
    }
    if (LFLD(s8, self, 0xc3) > 0) {
        h = LFLD(s32, self, 0x28);
        py = pos[1];
        c8 = LFLD(s32, self, 0xc8);
        LFLD(u32, LFLD(void *, self, 0x10), 0x6c) &= ~0x40000;
        LFLD(LoF2, LFLD(void *, self, 0x10), 0x6c).f2 = LFLD(u8, self, 0xc3);
        LoSetScrPos(LFLD(void *, self, 0x10), px, h + (py >> 12) - 2 + (c8 >> 12));
        LoModelPlayPart(LFLD(void *, self, 0x10), 10);
    }
    if (LFLD(u32, self, 0xc) & 0x10000) {
        px = LFLD(s32, self, 0x24) + (pos[0] >> 12) - 0x10;
        LoDrawPart(self, px, pos[1] >> 12, FALSE, 0x1e, 2);
    }
}

}
