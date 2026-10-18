#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd64;
extern u8 data_ov009_022179b4[];
extern Ov009Actor *func_ov000_0219bf90(void);
extern void VEC_Normalize(const Ov009Vec *in, Ov009Vec *out);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern void func_ov000_0218d918(Ov009Actor *self, const Ov009Vec *v, s32 a);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 a);
extern void func_ov000_021911c8(void *m, s32 a);
extern void func_ov003_021d6954(Ov009Actor *self, u8 a);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
extern void func_ov000_0218bed8(void *mgr, s32 a, Ov009Actor *self);
static inline void Ov009_NextState(Ov009Actor *self) {
    self->unk_40->state++;
    self->unk_40->timer = 0;
}

void func_ov009_02211b6c(Ov009Actor *self) {
    Ov009Vec d;
    Ov009Sub40 *st;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_022179b4, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        Ov009_NextState(self);
        break;
    case 1: {
        Ov009Actor *t = func_ov000_0219bf90();
        s32 tx = t->pos.x;
        s32 ty = t->pos.y;
        s32 tz = t->pos.z;
        d.x = self->pos.x - tx;
        d.y = self->pos.y - ty;
        d.z = self->pos.z - tz;
        VEC_Normalize(&d, &d);
        VEC_Add(&d, &self->pos, &d);
        func_ov000_0218d918(self, &d, 0x400);
        st = self->unk_40;
        st->timer++;
        if (st->timer > 10) {
            func_ov000_021911c8(self->unk_38, 0x1800);
            self->unk_98 = self->rot[1];
            self->unk_a0 = 0;
            self->unk_a8 = 0;
            self->unk_9c = 0x7b;
            self->unk_a4 = 0x1052;
            Ov009_NextState(self);
        }
        break;
    }
    case 2:
        func_ov000_0218dbe0(self, 0);
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x3c) {
            Ov009_NextState(self);
        }
        break;
    case 3: {
        u8 h;
        u8 a;
        func_ov000_0218dbe0(self, 0);
        h = self->unk_40->timer >> 1;
        if (h > 0x1d) {
            a = 2;
        } else {
            a = 0x1f - h;
        }
        func_ov003_021d6954(self, a);
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x3c) {
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            FLD(u8, data_ov000_021ccd54, 0xac) = 1;
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->v08();
        }
        break;
    }
    }
}

}
