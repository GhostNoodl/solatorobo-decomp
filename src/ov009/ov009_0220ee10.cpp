#include "ov009/ov009.h"

extern "C" {

void func_ov009_0220ee10(Ov009Actor *self) {
    Ov009Sub40 *st = self->unk_40;
    Ov009Vec d;
    switch (st->state) {
    case 0:
        FLD(Ov009Vec, self, 0xfc) = self->pos;
        FLD(Ov009Vec, self, 0xfc).x += 0x2000;
        FLD(Ov009Vec, self, 0xfc).y -= 0x1000;
        st->state++;
        self->unk_40->timer = 0;
        return;
    case 1:
        st->timer++;
        if (st->timer > 0x28 || VEC_Distance(&self->pos, &FLD(Ov009Vec, self, 0xfc)) < 0x52) {
            func_ov000_02198360(self->unk_40, 1, 0);
            FLD(Ov009Vec, self, 0xfc).x = self->pos.x;
            FLD(Ov009Vec, self, 0xfc).y = self->pos.y;
            FLD(Ov009Vec, self, 0xfc).z = self->pos.z;
        }
        d.x = FLD(Ov009Vec, self, 0xfc).x - self->pos.x;
        d.y = FLD(Ov009Vec, self, 0xfc).y - self->pos.y;
        d.z = FLD(Ov009Vec, self, 0xfc).z - self->pos.z;
        VEC_MultAdd(0xf6, &d, &self->pos, &self->pos);
        break;
    }
}

extern void *data_02097e4c;
extern void func_ov000_0219b71c(Ov009Vec *pos, Ov009Vec *v, s32 a, s32 b, s32 c, s32 d);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);
extern void func_ov003_021d6954(Ov009Actor *self, u8 a);
void func_ov009_0220ef1c(Ov009Actor *self) {
    Ov009Vec v;
    Ov009Vec d;
    Ov009Sub40 *st;
    u16 t;
    switch (self->unk_40->state) {
    case 0: {
        Ov009Sub44 *s44;
        *self->unk_50 = 0;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->unk_ea_6 = 1;
        FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
        {
            s32 z = func_02040528(0x29);
            s32 x = func_02040528(0x29);
            self->unk_a0 = -0x71;
            self->unk_a4 = z;
            self->unk_9c = x;
        }
        self->unk_40->state++;
        break;
    }
    case 1:
        d.x = 0x185 - self->unk_9c;
        d.y = -0x8f - self->unk_a0;
        d.z = -self->unk_a4;
        VEC_MultAdd(0x66, &d, (Ov009Vec *)&self->unk_9c, (Ov009Vec *)&self->unk_9c);
        VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
        st = self->unk_40;
        st->timer++;
        t = st->timer;
        VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
        if (t > 0x78) {
            func_ov000_0218996c(10, 0x28);
            func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
            func_02065f88(5, &self->pos)->v14(0x6000, 0x6000, 0x6000);
            self->unk_40->timer = 0x29;
            self->unk_40->state++;
            return;
        }
        if ((t & 0xf) == 0) {
            s32 a = -1;
            s32 b = 100;
            u32 r = self->unk_40->timer & 0x3f;
            if (r == 0 || r == 0x20) {
                a = 3;
                b = 100;
            }
            v.x = 0x3000;
            v.y = 0x2800;
            v.z = 0x1800;
            func_ov000_0219b71c(&self->pos, &v, 0xc00, 0x1400, a, b);
            func_ov000_0218996c(6, 10);
        }
        break;
    case 2:
        if ((u8)self->unk_40->timer < 0x1f) {
            func_ov003_021d6954(self, self->unk_40->timer);
        }
        VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            func_ov003_021d6a3c(self, 1, 1, 1);
        }
        break;
    }
}

}
