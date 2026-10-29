#include "ov009/ov009.h"

extern "C" {

extern const Ov009Vec data_ov009_02215f74[];
extern Ov009Vec data_ov009_02215f78[];
extern Ov009Vec data_ov009_02215f7c[];
extern u8 data_ov009_02215efc[];
extern void func_01ffc9fc(Ov009Vec *out, const void *a, s32 b);
extern void func_0203f364(Ov009Sub48 *p);

static inline void Ov009_SetPos(Ov009Actor *self, s32 x, s32 y, s32 z) {
    self->pos.x = x;
    self->pos.y = y;
    self->pos.z = z;
}

void func_ov009_0220b70c(Ov009Actor *self) {
    Ov009Sub48 *s48;
    func_ov003_021d112c(self);
    if (self->unk_1a != 0) {
        Ov009_SetPos(self, data_ov009_02215f74[self->unk_1a - 1].x, data_ov009_02215f74[self->unk_1a - 1].y, data_ov009_02215f74[self->unk_1a - 1].z);
    }
    switch (self->kind) {
    case 0x5808:
    case 0x580a:
        FLD(u8, self, 0xf7) = 0;
        break;
    case 0x5809:
    case 0x580b: {
        Ov009Sub48 *p;
        FLD(u8, self, 0xf7) = 1;
        func_01ffc9fc(&FLD(Ov009Vec, self, 0xfc), data_ov009_02215efc, (u16)(func_02040528(0x3c) * 0xb6));
        self->pos = FLD(Ov009Vec, self, 0xfc);
        FLD(u16, self, 0xf2) = self->kind == 0x5809 ? 0x78 : 0xa0;
        p = self->unk_48;
        FLD(s32, self, 0xf8) = p->unk_38 << 1;
        p->unk_30 = 0;
        self->unk_93_4 = 1;
        break;
    }
    }
    switch (self->kind) {
    case 0x580b:
        FLD(u8, self, 0xf6) = 0x96;
        FLD(u16, self, 0xf4) = 0x64;
        break;
    case 0x5809:
        FLD(u8, self, 0xf6) = 0xaa;
        FLD(u16, self, 0xf4) = 0x96;
        break;
    }
    FLD(u16, self, 0xf0) = 0;
    s48 = self->unk_48;
    s48->unk_9a_0 = 0;
    s48->unk_9a_3 = 0;
    func_0203f364(s48);
    FLD(u8, self->unk_38, 0xbe) = 0;
    self->unk_ea_14 = 1;
}


extern u8 data_ov009_02215f38[];
extern void *data_02097e4c;
extern Ov009Actor *func_ov000_0219bf90(void);
extern s32 func_ov000_0219a2f4(Ov009Vec *pos, s32 a, s32 b);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern void func_ov000_0218d9e8(Ov009Actor *self, Ov009Vec *v, s32 a);
extern void *func_02049f44(void *a, s32 b, Ov009Vec *c, s32 d);

static inline BOOL Ov009Game_IsPausedB(Ov009Game54 *g) {
    return g->unk_d4 != 0;
}

void func_ov009_0220b8a0(Ov009Actor *self) {
    Ov009Actor *pl;
    Ov009Vec d;
    Ov009Vec v;
    u8 k;
    self->unk_90 = 0xffff;
    {
        pl = func_ov000_0219bf90();
        if (pl != NULL) {
            self->unk_90 = pl->id;
        }
    }
    k = self->unk_40->unk_13;
    if (FLD(u8, self, 0xf7) == 0) {
        func_ov003_021d1e8c(self);
        if (k == 1 || k == 0x20 || k == 2 || k == 0xf || (u8)(k + 0xee) <= 1) {
            func_ov000_021987b8(self->unk_48, 1, 0, 0);
            v = self->pos;
            func_ov000_0219a2f4(&v, self->pos.y + 0x1800, -0xa000);
            self->pos.y += Ov009_FxMul(*(volatile s32 *)&v.y + 0x1800 - self->pos.y, 0x19a);
            v.y += 0x1800;
            VEC_Distance(&self->pos, &v);
        }
    }
    if (FLD(u8, self, 0xf7) == 1) {
        if (!Ov009_GameIdle()) {
            return;
        }
        if (Ov009Game_IsPausedB(data_ov000_021ccd54)) {
            return;
        }
        if (k == 1) {
            if (FLD(u16, self, 0xf0) == 0) {
                FLD(u16, self, 0xf0) = 4;
                self->unk_40->flags |= 0x8000;
            } else if (FLD(u16, self, 0xf0) & 1) {
                self->unk_b6++;
                if (self->unk_b6 > FLD(u16, self, 0xf4)) {
                    FLD(u16, self, 0xf0) = 0;
                    self->unk_b6 = 0;
                }
            }
        } else if (k != 0xf && k != 0x11) {
            func_01ffc9fc(&d, data_ov009_02215f38, self->rot[1]);
            VEC_Add(&self->pos, &d, &d);
            func_ov000_0218d9e8(self, &d, 0x29);
        }
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (self->pos.y <= -0x2000) {
            func_ov000_02198360(self->unk_40, 0x11, 0);
        }
    }
    if ((self->unk_30 & 0x200) && *self->unk_50 != 0) {
        func_02049f44(data_02097e4c, 0x40, &self->pos, 0);
    }
    if (self->pos.y <= -0x8000) {
        self->unk_40->flags |= 0x200000;
    }
}

}
