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
u8 func_02043d48(void *p);
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

struct Obj0214cb44 : public VObj {
    u8 unk_04[0x20];
    s32 unk_24;
    s32 unk_28;
    u8 unk_2c[0xc];
    void *unk_38;
    u8 unk_3c[0x2c];
    s16 unk_68;
    u8 unk_6a[0x1a];
    void *unk_84;
    u8 unk_88[0x4];
    VObj *unk_8c;
    VObj unk_90;
    u8 unk_94[0x40];
    s32 unk_d4;
    u8 unk_d8[0x28];
    s32 unk_100;
    u8 unk_104[0xfc];
    VObj *unk_200;
};

void func_ov000_0214cb44(Obj0214cb44 *self, s32 a, s32 *pos, s32 d) {
    if (self->unk_38 != NULL) {
        s16 z;
        s32 x;
        s32 y;
        self->vfunc_64(a, pos, d);
        func_ov000_0214d304(self, a, pos, d);
        z = self->unk_68 - 0x110;
        x = (pos[0] + ((self->unk_24 - 0x80) + ((0x100 - self->unk_24) >> 1))) << 12;
        y = pos[1] + (((self->unk_28 >> 1) - 0x60) << 12);
        LFLD(LoAlpha0214cb44, self->unk_84, 0x6c).alpha = func_02043d48(data_02097d48 + 0x8b0);
        {
            u8 *o = (u8 *)self->unk_84;
            LFLD(s32, o, 0xfc) = x;
            LFLD(s32, o, 0x100) = y;
        }
        LFLD(s32, self->unk_84, 0x150) = z;
        LoModelPlayPart(self->unk_84, 0);
        {
            s32 py = pos[1];
            s32 px = pos[0];
            self->unk_100 = self->unk_68;
            self->unk_90.vfunc_20(((self->unk_24 - self->unk_d4) >> 1) + (px >> 12),
                                            (py >> 12) + 2);
        }
        self->unk_90.vfunc_90();
    }
    if (self->unk_200 != NULL) {
        func_ov000_0214d994(self);
        self->unk_200->vfunc_90();
    }
    if (self->unk_8c != NULL) {
        self->unk_8c->vfunc_20();
    }
}

}
