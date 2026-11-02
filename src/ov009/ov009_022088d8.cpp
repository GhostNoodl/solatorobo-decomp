#include "ov009/ov009.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Snd/SndMgr.h"

extern "C" {

extern Ov009Path data_ov009_02215fd0[];
extern Ov003Actor *func_ov000_0219bf90(void);
extern BOOL Hit_DiffInCylinder(VecFx32 *a, VecFx32 *b, fx32 r, fx32 h);
extern BOOL func_ov000_0219aae8(Actor *self, Actor *src, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);

static inline BOOL Ov009Game_IsPaused(FieldState *g) {
    return g->event != 0;
}

void func_ov009_022088d8(Ov003Actor *self) {
    ActorSub40 *st;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (Ov009Game_IsPaused(data_ov000_021ccd54)) {
        return;
    }
    st = self->fsm;
    if (st->current == 1 && st->timer >= 0x2d) {
        Ov003Actor *a = func_ov000_0219bf90();
        VecFx32 v = self->unk_84;
        v.y -= 0x3000;
        s32 r = data_ov009_02215fd0[self->unk_1a].start.x;
        if (Hit_DiffInCylinder(&a->pos, &v, r + a->radius, 0x5000)) {
            self->fsm->flags = 0;
            func_ov000_02198360(self->fsm, 0xf, 0);
        }
    }
    if (self->fsm->current == 0xf) {
        func_ov000_0219aae8(self, self, 0x78, self->targetObj->unk_0a & 0xff, 2, 0, 0, 0x3000, 0x1b33, 0x64, 0x1000);
    }
    if (self->model->anim_state == 1) {
        func_0204a028(data_02097e4c, 9, &self->pos, -3);
    }
}

extern void *data_ov009_02215ee4[];

void func_ov009_02208a84(Ov003Actor *self) {
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, (char *)data_ov009_02215ee4[0], 0x111, 0);
        func_ov000_021915a0(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    case 1: {
        ActorSub40 *st = self->fsm;
        st->timer++;
        if (st->timer > 0x2d) {
            self->fsm->timer = 0x2d;
        }
        break;
    }
    }
}

static inline s32 Ov009_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline s32 Ov009_DistXZ(const VecFx32 *a, const VecFx32 *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov009_Sqrt64(sq);
}

// The path table is in .rodata. Declared const, its loads carry no alias edge to the stores
// through self, so the scheduler can issue p->end.y above the rot store (case 5) and the two
// p->end.x reads in case 3 are one load across the unk_9c store (round qpC).
extern const Ov009Path data_ov009_02215fbc[];
extern char data_ov009_022172c7[];
extern void func_ov000_021911c8(Model0218fe1c *m, s16 a);
extern s16 *func_ov000_02191318(Model0218fe1c *m, s32 a);
extern void func_ov000_02191780(Model0218fe1c *m);

void func_ov009_02208b24(Ov003Actor *self) {
    VecFx32 v;
    VecFx32 v3;
    VecFx32 d;
    const Ov009Path *p = &data_ov009_02215fbc[self->unk_1a];
    u16 state = self->fsm->st;
    switch (state) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov009_022172c7, 0x111, 0);
        func_ov000_02191318(self->model, 0x3c000);
        func_ov000_021911c8(self->model, 0x1800);
        func_ov000_02191780(self->model);
        self->speed = 0;
        self->friction = 0;
        self->gravity = 0;
        self->velY = 0x52;
        self->fsm->timer = 0;
        self->fsm->st++;
    case 1:
        if (func_ov000_02191120(self->model)) {
            func_ov000_02190cb0(self->model, (char *)data_ov009_02215ee4[1], 0x2ab, 0);
            func_ov000_021915a0(self->model);
            func_ov000_021911c8(self->model, 0xccd);
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    case 2: {
        ActorSub40 *s = self->fsm;
        s->timer++;
        if (s->timer >= 0x2d) {
            func_ov000_021911c8(self->model, 0x1400);
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    }
    case 3: {
        s32 ang;
        v = self->unk_84;
        v.z -= 0x5000;
        self->unk_b8 = v;
        ang = FX_Atan2(Ov009_DistXZ(&self->pos, &v), v.y - self->pos.y);
        self->speed = FX_Mul(p->end.x, OV009_SIN(ang));
        self->velY = FX_Mul(p->end.x, OV009_COS(ang));
        self->moveYaw = self->rot_y;
        self->fsm->st++;
    }
    case 4:
        if (VEC_Distance(&self->pos, &self->unk_b8) <= 0x800) {
            self->velY = 0;
            self->unk_18 = 1;
            self->fsm->st++;
        }
        break;
    case 5:
        if (self->unk_18 == 2) {
            GroupNode *o = Group_FindNode(data_ov000_021ccd64, self->unk_20);
            if (o != NULL) {
                s32 off;
                self->rot_y = o->rot.y;
                v = o->pos;
                off = p->end.y;
                self->unk_b8 = v;
                v.y += off;
                self->pos = v;
            }
            self->fsm->st++;
        }
        break;
    case 6: {
        ActorSub40 *s = self->fsm;
        u16 t;
        s->timer++;
        t = s->timer;
        if (t == 0x96) {
            func_ov000_02190cb0(self->model, data_ov009_022172c7, 0x1000, 0);
        }
        if (t > 0x96) {
            v = self->unk_b8;
            OV009_BLKCPY(&v3, &v);
            v3.y -= 0x800;
            d.x = v3.x - self->pos.x;
            d.y = v3.y - self->pos.y;
            d.z = v3.z - self->pos.z;
            VEC_MultAdd(0x66, &d, &self->pos, &self->pos);
            if (VEC_Distance(&self->pos, &self->unk_b8) <= 0x19a) {
                self->pos = v;
                self->speed = 0;
                self->velY = 0;
                self->friction = 0;
                self->gravity = 0;
                func_ov000_02198360(self->fsm, 1, 0);
            }
            if (func_ov000_02191120(self->model)) {
                func_ov000_02190cb0(self->model, (char *)data_ov009_02215ee4[0], 0x89, 0);
                func_ov000_021915a0(self->model);
            }
        }
        break;
    }
    }
    if (state < 6) {
        Actor_Move(self, 0);
    }
}

}
