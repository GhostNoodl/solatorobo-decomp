#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern void *data_ov009_02215d0c[];
extern void func_ov000_021911c8(Ov009Sub38 *m, s32 a);
extern void func_ov000_0218ddd4(Ov009Actor *self, Ov009Vec *v, s32 a);
extern s32 func_02040498(s32 max);
extern void func_ov000_02191318(Ov009Sub38 *m, s32 a);
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d46c(Ov009Actor *a, u16 id, s32 msg);
extern void func_ov000_0218fa28(Ov009Sub38 *m, void *a, void *b, void *c, void *anim, s32 d, s32 e);
extern void func_02049564(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(void *p, s32 a);
extern void func_ov009_0220189c(Ov009Actor *self);
extern void func_ov009_02201eac(Ov009Actor *self);

void func_ov009_02200fd4(Ov009Actor *self) {
    Ov009Vec v;
    s32 a;
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c[8], 0x400, 0);
        func_ov000_021911c8(self->unk_38, FLD(s16, self, 0xf6));
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
    self->unk_48->unk_9a_5 = 1;
    a = self->unk_b0->unk_00;
    self->unk_9c = a;
    if ((FLD(u16, self, 0xf0) & 1) && !(self->unk_48->unk_50 & 0x400)) {
        self->unk_9c = a << 1;
    }
    v = self->unk_b8;
    func_ov000_0218ddd4(self, &v, self->unk_b0->unk_02);
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
    if (!(self->unk_48->unk_50 & 0x20000000)) {
        func_ov000_02198360(self->unk_40, 4, 0);
    }
}

void func_ov009_022010f0(Ov009Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        FLD(u16, self, 0xf2) = func_02040498(0xf);
        break;
    case 1:
        if (FLD(u16, self, 0xf2)++ == 0x2d) {
            func_ov000_02191318(self->unk_38, 0x10000);
        }
        break;
    }
    func_ov003_021d4b68(self);
}

}
