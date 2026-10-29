#include "ov000/LoCommon.h"

typedef struct {
    u32 b0 : 2;
    u32 f2 : 5;
    u32 rest : 25;
} LoF2;

typedef struct {
    u16 id;
    u8 pad_02[0x16];
} Entry0215f334;

typedef struct {
    u32 b0 : 1;
    u32 rest : 31;
} Flags0215f334;

typedef struct {
    Flags0215f334 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    u8 pad_1c[8];
    VObj *unk_24;
    void *unk_28;
} Win0215f334;

extern "C" {

extern Entry0215f334 data_02fe0188[];
BOOL func_02054f10(void *model, u32 id);
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);
void func_ov000_0215f970(BOOL skip, s32 x, s32 y, s32 z, s32 unused, const void *oam, const void *img, u32 charBase, u32 plttBase, s32 unused2, const void *ctx0);
void func_ov000_0215f618(Win0215f334 *self, s32 *pos);

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

void func_ov000_0215f334(Win0215f334 *self) {
    s32 pos[3];
    VObj *t;
    Entry0215f334 *e;

    if (!func_02054f10(self->unk_28, 0xffff)) {
        return;
    }
    e = &data_02fe0188[self->unk_04];
    pos[0] = self->unk_08;
    pos[1] = self->unk_0c;
    pos[2] = self->unk_10;
    if (self->unk_00.b0) {
        pos[0] -= self->unk_14 >> 1;
    }
    LFLD(void *, self->unk_28, 0x158) = (void *)func_ov000_0215f970;
    LFLD(u32, self->unk_28, 0x6c) |= 0x80000;
    LFLD(u32, self->unk_28, 0x6c) |= 0x200000;
    LFLD(LoF2, self->unk_28, 0x6c).f2 = 0x1e;
    {
        s32 px = pos[0];
        s32 py = pos[1];
        u8 *o = (u8 *)self->unk_28;
        LFLD(s32, o, 0xfc) = px << 12;
        LFLD(s32, o, 0x100) = py << 12;
    }
    LFLD(s32, self->unk_28, 0x150) = pos[2] - 0x40;
    LoModelPlayPart(self->unk_28, e->id);
    LFLD(void *, self->unk_28, 0x158) = NULL;
    pos[2] -= 0x80;
    func_ov000_0215f618(self, pos);
    t = self->unk_24;
    pos[0] += (self->unk_14 - LFLD(s32, t, 0x44)) >> 1;
    pos[1] += (self->unk_18 - LFLD(s32, t, 0x48)) >> 1;
    LFLD(s32, t, 0x70) = self->unk_10;
    self->unk_24->vfunc_20(pos[0] - 1, pos[1] - 1);
    self->unk_24->vfunc_90();
}

}
