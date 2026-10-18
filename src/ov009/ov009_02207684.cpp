#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_0221729c[];
extern char data_ov009_022172a7[];
extern BOOL func_ov000_0218cf5c(Ov009Actor *self);
extern BOOL func_ov000_0218f110(void *p);

static inline void Ov009Names_Set(Ov009Names *n, const char *a, const char *b) {
    func_0201e520(n->unk_10, a);
    func_0201e520(n->unk_30, b);
    n->unk_03_1 = 1;
    func_0201e520(n->unk_4c, a);
    func_0201e520(n->unk_6c, b);
    n->unk_03_2 = 1;
    n->unk_00 = 0;
}

BOOL func_ov009_02207684(Ov009Actor *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (FLD(s16, self, 0xf0) >= 0 && !func_ov000_0218f110(&FLD(u8, self, 0xf0))) {
        r = FALSE;
    }
    return r;
}

extern void func_0203f2b8(void *p);
extern void func_0202a624(void *p, s32 a, s32 b);
extern void func_0202a57c(void *p, s32 a, s32 b);
extern void func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
extern void func_ov000_02190758(void *a, const void *b, s32 c);
void func_ov009_022076b8(Ov009Actor *self) {
    u32 saved;
    func_ov003_021d112c(self);
    func_ov000_0218ffdc(&FLD(u8, self, 0x228), &FLD(u8, self, 0xf0), 0, 1);
    FLD(u16, self, 0x2dc) = self->id;
    if (self->unk_1a == 0) {
        FLD(Ov009Vec, self, 0x2a0) = self->pos;
        FLD(s32, self, 0x2d0) = 0xccd;
        FLD(s32, self, 0x2d4) = 0xccd;
        FLD(s32, self, 0x2d8) = 0xccd;
    } else {
        s32 y = self->pos.y;
        s32 x = self->pos.x;
        s32 z = self->pos.z;
        FLD(s32, self, 0x2a0) = x + 0x6000;
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
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_48 != NULL) {
        Ov009Sub48 *p = self->unk_48;
        if (p != NULL) {
            func_0203f2b8(p);
            func_0203de1c(p);
        }
        self->unk_48 = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_44 != NULL) {
        func_0203de1c(self->unk_44);
        self->unk_44 = NULL;
    }
    data_02097dd0->cur = saved;
}

}
