#include "ov009/ov009.h"

extern "C" {

void func_ov009_022127f8(Ov009Actor *self) {
    Ov009Vec d;
    Ov009Sub40 *st;
    switch (self->unk_40->state) {
    case 0:
        FLD(Ov009Vec, self, 0x128) = self->pos;
        FLD(Ov009Vec, self, 0x128).y -= 0x1800;
        if (FLD(Ov009Vec, self, 0x128).y < FLD(s32, self, 0x138) - 0x2000) {
            FLD(Ov009Vec, self, 0x128).y = FLD(s32, self, 0x138) - 0x2000;
        }
        self->unk_40->state++;
        self->unk_40->timer = 0;
    case 1:
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x3c || VEC_Distance(&self->pos, &FLD(Ov009Vec, self, 0x128)) < 0x19a) {
            if (self->unk_1a == 1) {
                func_ov000_02198360(self->unk_40, 1, 0);
            } else {
                FLD(Ov009Vec, self, 0x128).x = FLD(Ov009Vec, self, 0x134).x;
                FLD(Ov009Vec, self, 0x128).y = FLD(Ov009Vec, self, 0x134).y;
                FLD(Ov009Vec, self, 0x128).z = FLD(Ov009Vec, self, 0x134).z;
                self->unk_40->state++;
                self->unk_40->timer = 0;
            }
        }
        break;
    case 2:
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x78 || VEC_Distance(&self->pos, &FLD(Ov009Vec, self, 0x128)) < 0x52) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    d.x = FLD(Ov009Vec, self, 0x128).x - self->pos.x;
    d.y = FLD(Ov009Vec, self, 0x128).y - self->pos.y;
    d.z = FLD(Ov009Vec, self, 0x128).z - self->pos.z;
    VEC_MultAdd(0x7b, &d, &self->pos, &self->pos);
}


struct Ov009CamDA {
    u8 b0 : 2;
    u8 b2 : 2;
    u8 b4 : 1;
    u8 b5 : 3;
};

extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern void func_0203f920(void *mesh);
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void func_ov000_02184508(void *g);
extern void func_ov000_02184548(void *g);
extern void func_ov000_0218d46c(void *a, u16 id, s32 msg);
extern void func_ov000_0218e8ec(void *mgr, u16 id, s32 msg);
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_02199f48(void *p, Ov009Actor *a);
extern void *func_ov000_0219b71c(Ov009Vec *pos, Ov009Vec *v, s32 a, s32 b, s32 c, s32 d);
extern void func_ov003_021d6954(Ov009Actor *self, u8 a);
extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern Ov009Actor *func_ov000_0219bf90(void);

static inline void *Ov009_FindActorD68(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov009_02212978(Ov009Actor *self) {
    Ov009Vec v;
    Ov009Vec w;
    Ov009Sub40 *st;
    u16 t;
    switch (self->unk_40->state) {
    case 0: {
        Ov009Sub44 *s44;
        void *o;
        if (self->unk_1a != 0) {
            self->unk_9c = 0;
            self->unk_a0 = -0x71;
            self->unk_a4 = 0x5c;
        } else {
            self->unk_9c = 0;
            self->unk_a0 = -0x71;
            self->unk_a4 = 0;
            func_ov000_02184508(data_ov000_021ccd54);
        }
        *self->unk_50 = 0;
        s44 = self->unk_44;
        if (s44 != NULL) {
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
        }
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x483f, 0x15);
        o = Ov009_FindActorD68(FLD(u16, self, 0xf0));
        if (o != NULL) {
            func_ov000_0218d46c(o, FLD(u16, self, 0xf0), 0x15);
        }
        self->unk_40->state++;
        self->unk_40->timer = 0;
        return;
    }
    case 1:
        st = self->unk_40;
        st->timer++;
        t = st->timer;
        if (t > 0xb4) {
            func_0203f920(FLD(void *, self, 0x58));
            if (self->unk_1a == 0) {
                func_ov000_02184548(data_ov000_021ccd54);
            }
            func_ov000_0218996c(10, 0x28);
            func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
            func_02065f88(5, &self->pos)->v14(0x7800, 0x7800, 0x7800);
            self->unk_40->timer = 0x29;
            self->unk_40->state++;
            return;
        }
        if (t % 20 == 0) {
            v = self->pos;
            v.y += 0x2000;
            w.x = 0x1333;
            w.y = 0x2000;
            w.z = 0x5800;
            func_ov000_0219b71c(&v, &w, 0x666, 0x1000, 3, 0x46);
            func_ov000_0218996c(8, 8);
            func_02049a48(data_02097e4c, 0x35, -1, -1, -1);
        }
        VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
        if (self->unk_1a == 0) {
            u8 *g = (u8 *)data_ov000_021ccd54 + 0xf4;
            FLD(s32, g, 0xf4) = 0xf000;
            FLD(Ov009CamDA, g, 0xda).b2 = 1;
            FLD(u16, g, 0xf8) = 0x1800;
            FLD(Ov009CamDA, g, 0xda).b4 = 1;
            return;
        }
        if (self->unk_40->timer % 35 == 0) {
            Ov009V *e = func_02065f88(0x325, &self->pos);
            s32 a;
            e->v34(0, (u16)(self->rot[1] + 0x8000), 0);
            e->v14(0x1ccd, 0x1ccd, 0x1ccd);
            a = func_02040498(0x4000);
            e->v24(-0x3800, a - 0x1000, func_02040498(0x3000));
        }
        break;
    case 2:
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            func_ov000_02199f48(self->unk_50, func_ov000_0219bf90());
            func_ov003_021d6a3c(self, 1, 1, 1);
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
