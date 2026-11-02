#include "ov009/ov009.h"

extern "C" {


void func_ov009_022117ac(Ov009ActVt_02217aac *self) {
    if (self->fsm->st == 0) {
        self->unk_fc = FLD(u8, ((u8 *)self->unk_100) + self->unk_fc * 16, 0xc);
        self->unk_fe = 0;
    }
    func_ov003_021d4fd8(self);
}

extern void *data_02097e4c;
extern Ov003Actor *func_ov000_0219bf90(void);
extern void func_0203f364(ActorSub48 *p);
extern void func_ov000_02199f48(void *p, Ov003Actor *a);
extern void ActorMgr_BroadcastKind(void *mgr, u16 id, s32 msg);
extern void func_ov000_021911c8(void *m, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void *func_02049f44(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern void *func_ov000_0219b71c(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, s32 d);
void func_ov009_022117e4(Ov009ActVt_02217aac *self) {
    VecFx32 p;
    VecFx32 v;
    VecFx32 q;
    switch (self->fsm->st) {
    case 0: {
        ActorSub44 *s44;
        ActorSub48 *s48;
        self->unk_ea_6 = 1;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        s48 = self->hit;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
        func_ov000_02199f48(self->hp, func_ov000_0219bf90());
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4802, 0x15);
        self->unk_93_4 = 0;
        self->fsm->st++;
        func_ov000_021911c8(self->model, 0x800);
    }
    case 1: {
        u16 t;
        self->fsm->timer++;
        t = self->fsm->timer;
        if (t == 0xdc) {
            EffectObj *e;
            if (self->unk_ff == 0) {
                return;
            }
            func_ov000_0218996c(0x19, 0x3c);
            func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
            func_02049f44(data_02097e4c, 0x53, &self->pos, 0);
            e = func_02065f88(5, &self->pos);
            e->AddPosXYZ(0, self->centerY + (self->centerY >> 1), 0);
            e->SetScaleXYZ((self->radius >> 1) + 0x3800, (self->radius >> 1) + 0x3800, (self->radius >> 1) + 0x3800);
            return;
        }
        if (t >= 0xfa) {
            {
                s32 b = 0;
                if (self->unk_ff != 0) {
                    b = 1;
                }
                func_ov003_021d6a3c(self, b, 1, 1);
            }
            self->fsm->timer = 0;
            self->fsm->st++;
            return;
        }
        if (t >= 0xdc) {
            return;
        }
        if (t % 0x19 != 1) {
            return;
        }
        p.x = self->pos.x;
        p.y = self->pos.y;
        p.z = self->pos.z;
        p.y += self->height;
        v.x = self->radius + (self->radius >> 1);
        v.y = self->height >> 1;
        v.z = self->radius + (self->radius >> 1);
        func_ov000_0219b71c(&p, &v, 0x800, 0xccd, 3, 0x32);
        func_ov000_0218996c(10, 0xf);
        func_02049f44(data_02097e4c, 0x35, &p, 0);
        return;
    }
    case 2: {
        ActorSub40 *st = self->fsm;
        EffectObj *e;
        s32 h;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        q.x = self->pos.x;
        q.y = self->pos.y;
        q.z = self->pos.z;
        q.x += Rand_PlusMinus(self->radius);
        q.z += Rand_PlusMinus(self->radius);
        h = self->height;
        q.y += h + Rand_PlusMinus(h >> 2);
        e = func_02065f88(0x325, &q);
        e->SetRotXYZ(0xc000, 0, 0);
        e->SetScaleAll(0xccd);
        self->fsm->timer = Rand_UpTo(0x28) + 0x3c;
        return;
    }
    }
}

}
