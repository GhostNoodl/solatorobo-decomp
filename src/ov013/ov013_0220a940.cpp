#include "ov013/ov013.h"

extern "C" {

extern void *data_ov013_0220beb4;
extern char data_ov013_0220b3f8[];
extern char data_ov013_0220b404[];
extern void func_ov000_0218dbe0(Ov013Actor *self, s32 a);
extern void func_ov000_02194074(void *self);
extern void func_ov000_02194758(void *self);
extern Ov013Actor *func_ov000_0219bf90(void);
extern Ov013V *func_02065f88(s32 id, Ov013Vec *pos);

void func_ov013_0220a940(Ov013Actor *self) {
    Ov013Sub38 *s;
    Ov013Sub40 *q;
    u8 v;
    func_ov000_0218dbe0(self, 0);
    s = self->unk_38;
    v = FLD(u8, s, 0xbe);
    if (v > 1) {
        v -= 2;
    } else if (v != 0) {
        v -= 1;
    }
    FLD(u8, s, 0xbe) = v;
    q = self->unk_40;
    q->timer++;
    if (q->timer > 0xf) {
        func_ov000_02198360(self->unk_40, 0x15, 0);
    }
}

#pragma force_active on
Ov013Actor *func_ov013_0220a9a8(Ov013Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = &data_ov013_0220beb4;
    FLD(u16, self, 0xce) = 0;
    FLD(s32, self, 0xd0) = 0;
    FLD(s32, self, 0xd4) = 0;
    return self;
}
#pragma force_active reset

void func_ov013_0220a9d8(Ov013Actor *self) {
    Ov013Actor *pl;
    Ov013V *fx;
    func_ov000_02194758(self);
    func_ov000_02198360(self->unk_40, 1, 0);
    FLD(u16, self, 0xce) = 600;
    self->unk_48->unk_38 = 0x1b33;
    FLD(s32, self, 0xd0) = 0x1000;
    self->unk_90 = 0xffff;
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        self->unk_90 = pl->id;
    }
    fx = func_02065f88(0x38c, &self->pos);
    if (fx == NULL) {
        return;
    }
    fx->v10(data_ov013_0220b3f8);
    fx->v20(data_ov013_0220b404);
    FLD(s32, self, 0xbc) = FLD(s32, fx, 0x24);
}

}
