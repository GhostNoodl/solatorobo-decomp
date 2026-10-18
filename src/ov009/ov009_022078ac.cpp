#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd64;
extern char data_ov009_022172af[];
extern void func_ov000_021903b4(void *p);
extern void func_ov000_02190a80(void *p, s32 a);
extern void func_ov000_02190e98(void *p, s32 a, s32 b, s32 c);
extern void func_ov000_0218bed8(void *mgr, s32 a, Ov009Actor *actor);

struct Ov009Bits16 {
    u16 b0 : 1;
    u16 b1 : 15;
};

BOOL func_ov009_022078ac(Ov009Actor *self) {
    BOOL r = func_ov003_021d16cc(self);
    if (r) {
        Ov009Vec p;
        p = self->pos;
        if (func_ov000_0219a2f4(&p, 0x2000, -0x5000) != -0x1000) {
            func_ov000_021903b4(&FLD(u8, self, 0x228));
        }
    }
    return r;
}

void func_ov009_02207910(Ov009Actor *self) {
    func_ov003_021d1b88(self);
    func_ov000_02190a80(&FLD(u8, self, 0x228), 0x1000);
}
extern BOOL func_01ffc584(const Ov009Vec *a, const Ov009Vec *b, s32 r, s32 h);
extern Ov009Actor *func_ov000_0219bf90(void);

void func_ov009_0220792c(Ov009Actor *self) {
    Ov009Actor *pl;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (func_ov000_0219a2f4(&self->pos, 0x1000, -0x3000) == -0x1000) {
        return;
    }
    self->unk_90 = 0xffff;
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        self->unk_90 = pl->id;
    }
    if (self->unk_1a == 0) {
        if (self->unk_40->unk_13 == 0xf) {
            return;
        }
        if (func_01ffc584(&pl->pos, &self->pos, pl->unk_64 + 0x6800, 0x6000)) {
            self->unk_40->flags |= 0x8000;
        }
    } else {
        Ov009Vec v;
        if (self->unk_40->unk_13 == 0x10) {
            return;
        }
        {
            s32 x = self->pos.x;
            s32 z = self->pos.z;
            s32 y = self->pos.y - 0x1000;
            v.x = x;
            v.z = z;
            v.y = y;
        }
        if (func_01ffc584(&pl->pos, &v, pl->unk_64 + 0x6800, 0x6000)) {
            self->unk_40->flags |= 0x10000;
        }
    }
}

}
