#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern void *data_ov000_021ccd68;
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern void func_ov000_0219b71c(Ov009Vec *pos, Ov009Vec *v, s32 a, s32 b, s32 c, s32 d);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void func_02049bb4(void *mgr, s32 id);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_ov003_021d6954(Ov009Actor *self, u8 a);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
extern void func_ov000_0218bed8(void *mgr, s32 a, Ov009Actor *actor);
void func_ov009_0220f5fc(Ov009Actor *self) {
    Ov009Vec v;
    Ov009Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0:
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x482d, 0x15);
        self->unk_9c = 0;
        self->unk_a4 = 0;
        self->unk_a0 = -0x71;
        self->unk_40->state++;
        self->unk_40->timer = 0;
        break;
    case 1:
        st->timer++;
        if (st->timer > 0xb4) {
            func_ov000_0218996c(0x14, 0x3c);
            func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
            func_02049bb4(data_02097e4c, FLD(s32, self, 0x10c));
            func_02065f88(5, &self->pos)->v0c(0x7000);
            self->unk_40->timer = 0x29;
            self->unk_40->state++;
            return;
        }
        if ((st->timer & 0xf) == 0) {
            s32 a = -1;
            s32 b = 100;
            switch (self->unk_40->timer & 0x3f) {
            case 0:
                a = 3;
                break;
            case 0x10:
                a = 3;
                b = 0x19;
                break;
            case 0x20:
                break;
            case 0x30:
                a = 3;
                b = 0x32;
                break;
            }
            v.x = 0x3000;
            v.y = 0x2800;
            v.z = 0x1800;
            func_ov000_0219b71c(&self->pos, &v, 0xc00, 0x1400, a, b);
            func_ov000_0218996c(6, 10);
        }
        VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
        break;
    case 2:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            FLD(u8, data_ov000_021ccd54, 0xac) = 1;
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->v08();
            return;
        }
        if ((u8)self->unk_40->timer < 0x1f) {
            func_ov003_021d6954(self, self->unk_40->timer);
        }
        VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
        break;
    }
}

}
