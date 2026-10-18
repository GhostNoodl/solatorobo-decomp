#include "ov009/ov009.h"

extern "C" {

extern BOOL func_ov000_0218cf5c(Ov009Actor *self);
extern BOOL func_ov000_0218f110(void *p);

BOOL func_ov009_02208fac(Ov009Actor *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (FLD(s16, self, 0xf0) >= 0 && !func_ov000_0218f110(&FLD(u8, self, 0xf0))) {
        r = FALSE;
    }
    return r;
}

extern void func_0203f364(Ov009Sub48 *p);
extern void func_0202a624(void *p, s32 a, s32 b);
extern void func_0202a57c(void *p, s32 a, s32 b);
extern void func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
extern void func_ov000_02190758(void *a, const void *b, s32 c);
extern Ov009Actor *func_ov000_0219bf90(void);
void func_ov009_02208fe0(Ov009Actor *self) {
    u32 saved;
    Ov009Sub48 *s48;
    Ov009Sub44 *s44;
    Ov009Actor *t;
    func_ov003_021d112c(self);
    func_ov000_0218ffdc(&FLD(u8, self, 0x228), &FLD(u8, self, 0xf0), 0, 1);
    FLD(u16, self, 0x2dc) = self->id;
    switch (self->unk_1a) {
    case 0:
    case 1: {
        s32 y = self->pos.y;
        s32 x = self->pos.x;
        s32 z = self->pos.z;
        if (self->unk_1a == 0) {
            x += 0x6000;
        } else {
            x -= 0x6000;
            self->rot[1] = 0x8000;
        }
        FLD(s32, self, 0x2a0) = x;
        FLD(s32, self, 0x2a4) = y - 0x800;
        FLD(s32, self, 0x2a8) = z;
        FLD(s32, self, 0x2d0) = 0x99a;
        FLD(s32, self, 0x2d4) = 0x99a;
        FLD(s32, self, 0x2d8) = 0x99a;
        {
            Ov009Vec *s = &FLD(Ov009Vec, self->unk_38, 0xa8);
            s->x = 0xccd;
            s->y = 0xccd;
            s->z = 0xccd;
        }
        break;
    }
    case 2:
        self->unk_48->unk_60 = 0x5000;
        self->unk_44->unk_10 = 0x5000;
        break;
    }
    func_ov000_02190758(&FLD(u8, self, 0x228), self->rot, 0);
    func_0202a624(FLD(void *, self, 0x22c), 1, 0x3f000000);
    func_0202a57c(FLD(void *, self, 0x22c), 1, 0x40);
    func_0202a57c(FLD(void *, self, 0x22c), 1, 0x80);
    func_0202a57c(FLD(void *, self, 0x22c), 1, 0x200);
    func_0202a57c(FLD(void *, self, 0x22c), 1, 0x400);
    FLD(u16, self, 0x2ea) |= 0x80;
    func_0202a624(FLD(void *, self, 0x22c), 1, 0x1f0000);
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_3c != NULL) {
        if (self->unk_3c != NULL) {
            self->unk_3c->v04();
        }
        self->unk_3c = NULL;
    }
    data_02097dd0->cur = saved;
    s48 = self->unk_48;
    s48->unk_9a_0 = 0;
    s48->unk_9a_3 = 0;
    func_0203f364(s48);
    s48 = self->unk_48;
    s48->unk_9a_1 = 0;
    s48->unk_9a_4 = 0;
    s48 = self->unk_48;
    s48->unk_9a_2 = 0;
    s48->unk_9a_5 = 0;
    s44 = self->unk_44;
    s44->unk_22_0 = 0;
    s44->unk_22_1 = 0;
    self->unk_44->unk_22_2 = 2;
    self->unk_90 = 0xffff;
    t = func_ov000_0219bf90();
    if (t != NULL) {
        self->unk_90 = t->id;
    }
    FLD(u16, self, 0x310) = 0;
    FLD(s32, self, 0x314) = 0;
}

}
