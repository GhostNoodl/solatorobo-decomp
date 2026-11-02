#include "ov009/ov009.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Snd/SndMgr.h"

extern "C" {

extern Ov009Path data_ov009_02215cf4[];
extern u8 data_ov009_02216ab6[];
extern void func_ov000_0216912c(void *p, u16 id, s32 a, u16 b, u16 c, const VecFx32 *pos);

static inline void Ov009_Notify(u16 id, u16 a, u16 b, const VecFx32 *pos) {
    FieldActor *g = data_ov000_021ccd30->unk_11c;
    if (g != NULL && g->unk_60 != NULL) {
        func_ov000_0216912c(g->unk_60, id, 0, a, b, pos);
    }
}

BOOL Ov009ActVt_02216750_Draw(Ov009ActVt_02216750 *self) {
    BOOL r = Ov003Actor_Draw(self);
    if (r) {
        Ov009_Notify(self->id, self->hp[0], self->hp[1], &self->pos);
    }
    return r;
}

void Ov009ActVt_02216750_State20(Ov009ActVt_02216750 *self) {
    VecFx32 d;
    Ov009Path *path = &data_ov009_02215cf4[self->unk_1a - 1];
    u8 *anim = data_ov009_02216ab6;
    switch (self->fsm->st) {
    case 0: {
        ActorSub44 *s44;
        func_ov000_02190cb0(self->model, (char *)anim, 0x2ab, 0);
        func_ov000_021915a0(self->model);
        {
            u16 r = self->rot_y;
            s32 x = path->start.x;
            s32 y = path->start.y;
            s32 z = path->start.z;
            self->moveYaw = r;
            self->pos.x = x;
            self->pos.y = y;
            self->pos.z = z;
        }

        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->fsm->st++;
        break;
    }
    case 1:
        d.x = path->end.x - self->pos.x;
        d.y = path->end.y - self->pos.y;
        d.z = path->end.z - self->pos.z;
        VEC_MultAdd(0x7b, &d, &self->pos, &self->pos);
        if (Hit_DiffInSphere(&self->pos, &path->end, self->radius + 0x800)) {
            ActorSub44 *s44 = self->unk_44;
            s44->unk_22_0 = 1;
            s44->unk_22_1 = 1;
            self->unk_f0 = self->pos;
            self->unk_fc = self->pos;
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
}

void Ov009ActVt_02216750_StateIdle(Ov009ActVt_02216750 *self) {
    VecFx32 d;
    ActorSub40 *st = self->fsm;
    VecFx32 *t = &self->unk_fc;
    if (st->timer != 0) {
        st->timer--;
    }
    if (st->timer == 0) {
        self->fsm->timer = 0x4b;
        *t = self->unk_f0;
        t->y += Rand_PlusMinus(0xc00);
        t->x += Rand_PlusMinus(0x59a);
        t->z += Rand_PlusMinus(0x59a);
    }
    d.x = t->x - self->pos.x;
    d.y = t->y - self->pos.y;
    d.z = t->z - self->pos.z;
    VEC_MultAdd(0x31, &d, &self->pos, &self->pos);
}

extern Ov003Actor *func_ov000_02199f60(void *p);
static inline u16 Ov009_AngleTo(Ov003Actor *a, Ov003Actor *b) {
    if (a != NULL && a != b) {
        return FX_Atan2(a->pos.x - b->pos.x, a->pos.z - b->pos.z);
    }
    return b->rot_y;
}

void Ov009ActVt_02216750_StateHurt(Ov009ActVt_02216750 *self) {
    VecFx32 d;
    ActorSub40 *st;
    switch (self->fsm->st) {
    case 0: {
        Ov003Actor *p;
        self->unk_fc = self->pos;
        if (self->unk_18 == 1) {
            self->unk_fc.y -= Rand_UpTo(0x800) + 0x1000;
        } else {
            self->unk_fc.y -= Rand_UpTo(0x800) + 0x2800;
        }
        if (self->unk_fc.y < self->unk_f0.y - 0x1000) {
            self->unk_fc.y = self->unk_f0.y - 0x1000;
        }
        if (data_ov000_021ccd54->unk_ca.c[0] != 0x11) {
            p = func_ov000_02199f60(self->hp);
            if (p != NULL) {
                u16 a = Ov009_AngleTo(self, p);
                self->unk_fc.x += FX_Mul(OV009_SIN(a), 0x1000);
                self->unk_fc.z += FX_Mul(OV009_COS(a), 0x1000);
            }
        }
        if (self->unk_18 == 1) {
            func_02049f44(data_02097e4c, 0xd03, &self->pos, 0);
        }
        self->fsm->st++;
    }
    case 1:
        st = self->fsm;
        st->timer++;
        if (st->timer > 0x2d) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        d.x = self->unk_fc.x - self->pos.x;
        d.y = self->unk_fc.y - self->pos.y;
        d.z = self->unk_fc.z - self->pos.z;
        VEC_MultAdd(0x31, &d, &self->pos, &self->pos);
        break;
    }
}

}
