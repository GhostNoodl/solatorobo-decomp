#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

typedef struct {
    u32 b0 : 2;
    u32 f2 : 5;
    u32 f7 : 6;
    u32 pad13 : 6;
    u32 b19 : 1;
    u32 b20 : 1;
    u32 b21 : 1;
    u32 rest : 10;
} LoMdlFlags0214e3b4;


extern "C" {

void *NNS_G2dGetCellDataByIdx(void *a, int b);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);
void func_02041c18(void *model, void *arg);

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

static inline void LoSetPos0214e3b4(void *m, s32 x, s32 y) {
    LFLD(s32, m, 0xfc) = x << 12;
    LFLD(s32, m, 0x100) = y << 12;
}

void func_ov000_0214e3b4(Lo021caac8 *self, void *arg, s32 x, s32 y, u8 depth, u8 flip) {
    if ((void *)self->unk_b4 == NULL) {
        return;
    }
    if (flip) {
        LFLD(LoMdlFlags0214e3b4, self->model, 0x6c).b19 = 1;
        LFLD(s32, self->model, 0x150) = self->posZ - 0x110;
        LFLD(LoMdlFlags0214e3b4, self->model, 0x6c).b20 = 1;
        LFLD(LoMdlFlags0214e3b4, self->unk_b4, 0x6c).b19 = 1;
        LFLD(s32, self->unk_b4, 0x150) = self->posZ - 0x110;
        LFLD(LoMdlFlags0214e3b4, self->unk_b4, 0x6c).b20 = 1;
    } else {
        LFLD(LoMdlFlags0214e3b4, self->model, 0x6c).b19 = 1;
        LFLD(s32, self->model, 0x150) = self->posZ - 0x80;
        LFLD(LoMdlFlags0214e3b4, self->model, 0x6c).b20 = 0;
        LFLD(LoMdlFlags0214e3b4, self->unk_b4, 0x6c).b19 = 1;
        LFLD(s32, self->unk_b4, 0x150) = self->posZ - 0x80;
        LFLD(LoMdlFlags0214e3b4, self->unk_b4, 0x6c).b20 = 0;
    }
    x += self->vfunc_94() - 0x80;
    LoSetPos0214e3b4(self->model, x, y - 0x59);
    LoModelPlayPart(self->model, 13);
    LoModelPlayPart(self->model, 12);
    LFLD(LoMdlFlags0214e3b4, self->model, 0x6c).b20 = 0;
    LFLD(LoMdlFlags0214e3b4, self->unk_b4, 0x6c).f7 = depth;
    LFLD(LoMdlFlags0214e3b4, self->unk_b4, 0x6c).f2 = 30;
    LFLD(LoMdlFlags0214e3b4, self->unk_b4, 0x6c).b21 = 1;
    if (self->flags & 0x800000) {
        LoSetPos0214e3b4(self->unk_b4, x - 2, y - 0x5d);
        LoModelPlayPart(self->unk_b4, 7);
        x += 10;
    }
    LoSetPos0214e3b4(self->unk_b4, x - 2, y - 0x5e);
    func_02041c18(self->unk_b4, LFLD(void *, arg, 0xc));
    LoModelPlayPart(self->unk_b4, 6);
}

}
