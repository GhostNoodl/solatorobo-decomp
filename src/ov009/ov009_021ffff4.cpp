#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern u8 data_ov009_02215dc0[];
extern void func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_01ffc9fc(Ov009Vec *out, const void *a, s32 b, s32 c);
extern void func_02012be8(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern void func_0203f2b8(void *p);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 4;
    u8 b5 : 1;
    u8 b6 : 2;
};

void func_ov009_021ffff4(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        func_02049f44(data_02097e4c, 0x6b, &self->pos, 0);
    }
    func_ov003_021d5900(self);
}

void func_ov009_02200034(Ov009Actor *self) {
    u8 *p;
    func_ov003_021d0fc0(self);
    p = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        Ov009Byte *b = (Ov009Byte *)(p + 0xa2);
        b->b0 = 0;
        b->b5 = 1;
    }
}

void func_ov009_02200070(Ov009Actor *self) {
    Ov009Vec t;
    u32 saved;
    func_ov003_021d112c(self);
    FLD(Ov009Vec, self, 0xf8) = self->pos;
    self->unk_84 = self->pos;
    FLD(u8, self, 0xf0) = 0;
    func_01ffc9fc(&t, data_ov009_02215dc0, 0x5554, 0);
    func_02012be8(&self->unk_84, &t, &self->pos);
    self->unk_b8 = self->pos;
    switch (self->kind) {
    case 0x5423:
        FLD(s32, self, 0xf4) = 0x32000;
        break;
    case 0x5424:
        FLD(s32, self, 0xf4) = 0x6000;
        break;
    }
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
