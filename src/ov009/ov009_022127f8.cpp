#include "ov009/ov009.h"

extern "C" {

void func_ov009_022127f8(Ov009ActSpin *self) {
    Ov009Vec d;
    Ov009Sub40 *st;
    switch (self->unk_40->state) {
    case 0:
        self->unk_128 = self->pos;
        self->unk_128.y -= 0x1800;
        if (self->unk_128.y < self->unk_134.y - 0x2000) {
            self->unk_128.y = self->unk_134.y - 0x2000;
        }
        self->unk_40->state++;
        self->unk_40->timer = 0;
    case 1:
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x3c || VEC_Distance(&self->pos, &self->unk_128) < 0x19a) {
            if (self->unk_1a == 1) {
                func_ov000_02198360(self->unk_40, 1, 0);
            } else {
                self->unk_128.x = self->unk_134.x;
                self->unk_128.y = self->unk_134.y;
                self->unk_128.z = self->unk_134.z;
                self->unk_40->state++;
                self->unk_40->timer = 0;
            }
        }
        break;
    case 2:
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x78 || VEC_Distance(&self->pos, &self->unk_128) < 0x52) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    d.x = self->unk_128.x - self->pos.x;
    d.y = self->unk_128.y - self->pos.y;
    d.z = self->unk_128.z - self->pos.z;
    VEC_MultAdd(0x7b, &d, &self->pos, &self->pos);
}


struct Ov009CamDA {
    u8 b0 : 2;
    u8 b2 : 2;
    u8 b4 : 1;
    u8 b5 : 3;
};

extern void *data_02097e4c;
extern void func_0203f920(void *mesh);
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void func_ov000_02184508(void *g);
extern void func_ov000_02184548(void *g);
extern void func_ov000_0218d46c(void *a, u16 id, s32 msg);
extern void ActorMgr_BroadcastKind(void *mgr, u16 id, s32 msg);
extern void *ActorMgr_GetActor(void *mgr, u16 id);
extern void func_ov000_02199f48(void *p, Ov009Actor *a);
extern void *func_ov000_0219b71c(Ov009Vec *pos, Ov009Vec *v, s32 a, s32 b, s32 c, s32 d);
extern void func_ov003_021d6954(Ov009Actor *self, u8 a);
extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern Ov009Actor *func_ov000_0219bf90(void);

static inline void *Ov009_FindActorD68(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void func_ov009_02212978(Ov009ActVt_02217a00 *self) {
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
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x483f, 0x15);
        o = Ov009_FindActorD68(self->unk_f0);
        if (o != NULL) {
            func_ov000_0218d46c(o, self->unk_f0, 0x15);
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
            func_0203f920(self->unk_58);
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
            a = Rand_UpTo(0x4000);
            e->v24(-0x3800, a - 0x1000, Rand_UpTo(0x3000));
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
