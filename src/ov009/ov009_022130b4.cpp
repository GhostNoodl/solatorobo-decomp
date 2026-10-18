#include "ov009/ov009.h"

extern "C" {

struct Ov009Rot {
    u16 x;
    u16 y;
    u16 z;
};

extern void *data_ov000_021ccd68;
extern u8 data_ov009_022160ac[];
extern u8 data_ov009_022160c4[];
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0219a210(Ov009Vec *v, const void *a, u16 b);
extern Ov009Actor *func_ov000_0219be1c(u16 kind, const Ov009Vec *pos, const void *rot, u16 id, u16 parent);

static inline Ov009Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov009_022130b4(Ov009Actor *self) {
    if (func_ov000_0218d240(self) == NULL) {
        return;
    }
    switch (self->unk_40->state) {
    case 0:
    case 2:
    case 4: {
        Ov009Sub40 *st;
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4092, 6);
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x1e) {
            self->unk_40->state++;
            self->unk_40->timer = 0;
        }
        break;
    }
    case 1:
    case 3:
    case 5: {
        Ov009Vec p;
        Ov009Rot r;
        Ov009Actor *a;
        Ov009Actor *o;
        u16 s;
        p = self->pos;
        func_ov000_0219a210(&p, data_ov009_022160ac, self->rot[1]);
        a = Ov009_FindActor(FLD(u16, self, 0xf0));
        r.x = a->rot[0];
        r.y = a->rot[1];
        r.z = a->rot[2];
        r.x += (u16)func_02040498(0x200);
        s = self->unk_40->state;
        {
            s32 t = func_02040498(0x400);
            r.y += (u16)(t + (s * 0x600 + 0xee00));
        }
        func_ov000_0219a210(&p, data_ov009_022160c4, r.y);
        o = func_ov000_0219be1c(0x483f, &p, &r, self->id, self->unk_90);
        if (o != NULL) {
            o->unk_1a = 1;
        }
        if (*(volatile u16 *)&self->unk_40->state < 5) {
            self->unk_40->state++;
            return;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    }
}

}
