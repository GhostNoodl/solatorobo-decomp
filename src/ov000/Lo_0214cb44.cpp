#include "ov000/LoCommon.h"

typedef struct {
    u32 b0 : 7;
    u32 alpha : 6;
    u32 rest : 19;
} LoAlpha0214cb44;

extern "C" {

extern u8 *data_02097d48;
void *NNS_G2dGetCellDataByIdx(void *a, int b);
void *NNS_G2dGetAnimSequenceByIdx(void *a, int b);
void func_02042628(void *a, void *b, void *c, int d);
s32 func_02043d48(void *p);
void func_ov000_0214d304(VObj *self, s32 a, s32 *pos, s32 d);
void func_ov000_0214d994(VObj *self);

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

void func_ov000_0214cb44(VObj *self, s32 a, s32 *pos, s32 d) {
    if (LFLD(void *, self, 0x38) != NULL) {
        s16 z;
        s32 x;
        s32 y;
        self->vfunc_64(a, pos, d);
        func_ov000_0214d304(self, a, pos, d);
        z = LFLD(s16, self, 0x68) - 0x110;
        x = (pos[0] + ((LFLD(s32, self, 0x24) - 0x80) + ((0x100 - LFLD(s32, self, 0x24)) >> 1))) << 12;
        y = pos[1] + (((LFLD(s32, self, 0x28) >> 1) - 0x60) << 12);
        LFLD(LoAlpha0214cb44, LFLD(void *, self, 0x84), 0x6c).alpha = func_02043d48(data_02097d48 + 0x8b0);
        {
            u8 *o = LFLD(u8 *, self, 0x84);
            LFLD(s32, o, 0xfc) = x;
            LFLD(s32, o, 0x100) = y;
        }
        LFLD(s32, LFLD(void *, self, 0x84), 0x150) = z;
        LoModelPlayPart(LFLD(void *, self, 0x84), 0);
        {
            s32 py = pos[1];
            s32 px = pos[0];
            LFLD(s32, self, 0x100) = LFLD(s16, self, 0x68);
            LFLD(VObj, self, 0x90).vfunc_20(((LFLD(s32, self, 0x24) - LFLD(s32, self, 0xd4)) >> 1) + (px >> 12),
                                            (py >> 12) + 2);
        }
        LFLD(VObj, self, 0x90).vfunc_90();
    }
    if (LFLD(VObj *, self, 0x200) != NULL) {
        func_ov000_0214d994(self);
        LFLD(VObj *, self, 0x200)->vfunc_90();
    }
    if (LFLD(VObj *, self, 0x8c) != NULL) {
        LFLD(VObj *, self, 0x8c)->vfunc_20();
    }
}

}
