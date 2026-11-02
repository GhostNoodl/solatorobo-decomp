#include "ov009/ov009.h"

extern "C" {

void func_ov009_022127f8(Ov009ActSpin *self) {
    VecFx32 d;
    ActorSub40 *st;
    switch (self->fsm->st) {
    case 0:
        self->unk_128 = self->pos;
        self->unk_128.y -= 0x1800;
        if (self->unk_128.y < self->unk_134.y - 0x2000) {
            self->unk_128.y = self->unk_134.y - 0x2000;
        }
        self->fsm->st++;
        self->fsm->timer = 0;
    case 1:
        st = self->fsm;
        st->timer++;
        if (st->timer > 0x3c || VEC_Distance(&self->pos, &self->unk_128) < 0x19a) {
            if (self->unk_1a == 1) {
                func_ov000_02198360(self->fsm, 1, 0);
            } else {
                self->unk_128.x = self->unk_134.x;
                self->unk_128.y = self->unk_134.y;
                self->unk_128.z = self->unk_134.z;
                self->fsm->st++;
                self->fsm->timer = 0;
            }
        }
        break;
    case 2:
        st = self->fsm;
        st->timer++;
        if (st->timer > 0x78 || VEC_Distance(&self->pos, &self->unk_128) < 0x52) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
    d.x = self->unk_128.x - self->pos.x;
    d.y = self->unk_128.y - self->pos.y;
    d.z = self->unk_128.z - self->pos.z;
    VEC_MultAdd(0x7b, &d, &self->pos, &self->pos);
}


extern void *data_02097e4c;
extern void func_0203f920(void *mesh);
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void func_ov000_02184508(void *g);
extern void func_ov000_02184548(void *g);
extern void func_ov000_0218d46c(void *a, u16 id, s32 msg);
extern void ActorMgr_BroadcastKind(void *mgr, u16 id, s32 msg);
extern Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
extern void func_ov000_02199f48(void *p, Ov003Actor *a);
extern EffectObj *func_ov000_0219b71c(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, u8 d);
extern void func_ov000_0218996c(u8 a, u8 b);
extern Ov003Actor *func_ov000_0219bf90(void);

static inline void *Ov009_FindActorD68(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void func_ov009_02212978(Ov009ActVt_02217a00 *self) {
    VecFx32 v;
    VecFx32 w;
    ActorSub40 *st;
    u16 t;
    switch (self->fsm->st) {
    case 0: {
        ActorSub44 *s44;
        void *o;
        if (self->unk_1a != 0) {
            self->speed = 0;
            self->velY = -0x71;
            self->friction = 0x5c;
        } else {
            self->speed = 0;
            self->velY = -0x71;
            self->friction = 0;
            func_ov000_02184508(data_ov000_021ccd54);
        }
        *self->hp = 0;
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
        self->fsm->st++;
        self->fsm->timer = 0;
        return;
    }
    case 1:
        st = self->fsm;
        st->timer++;
        t = st->timer;
        if (t > 0xb4) {
            func_0203f920(self->hitMesh);
            if (self->unk_1a == 0) {
                func_ov000_02184548(data_ov000_021ccd54);
            }
            func_ov000_0218996c(10, 0x28);
            func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
            func_02065f88(5, &self->pos)->SetScaleXYZ(0x7800, 0x7800, 0x7800);
            self->fsm->timer = 0x29;
            self->fsm->st++;
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
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        if (self->unk_1a == 0) {
            FieldCam *g = &data_ov000_021ccd54->cam;
            g->unk_f4 = 0xf000;
            g->unk_da_2 = 1;
            g->unk_f8 = 0x1800;
            g->unk_da_4 = 1;
            return;
        }
        if (self->fsm->timer % 35 == 0) {
            EffectObj *e = func_02065f88(0x325, &self->pos);
            s32 a;
            e->SetRotXYZ(0, (u16)(self->rot_y + 0x8000), 0);
            e->SetScaleXYZ(0x1ccd, 0x1ccd, 0x1ccd);
            a = Rand_UpTo(0x4000);
            e->AddPosXYZ(-0x3800, a - 0x1000, Rand_UpTo(0x3000));
        }
        break;
    case 2:
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            func_ov000_02199f48(self->hp, func_ov000_0219bf90());
            func_ov003_021d6a3c(self, 1, 1, 1);
            return;
        }
        if ((u8)self->fsm->timer < 0x1f) {
            func_ov003_021d6954(self, self->fsm->timer);
        }
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        break;
    }
}

}
