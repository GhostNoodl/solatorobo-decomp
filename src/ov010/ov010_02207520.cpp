#include "ov010/ov010.h"
#include "Main/Sys/FieldState.h"
#include "ov010/ObjLayouts.h"
#include "ov000/ObjLayouts.h"

// The state-handler class: complete, so that the dispatcher reads its fields by name.
class Ov010Cls : public Ov010Obj0220ffe4 {
};
typedef void (Ov010Cls::*Ov010Fn)();
struct Ov010StEnt {
    u8 key;
    Ov010Fn fn;
};


struct Ov010Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

struct Ov010Query {
    VecFx32 pos;
    u16 rot;
    u16 kind;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    u16 unk_28;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;

    Ov010Query() {
        kind = 0;
        unk_10 = 0xffff;
        unk_12 = 0;
        unk_14 = 0;
        unk_18 = 0;
        unk_1c = 0;
        unk_20 = 0;
        unk_24 = 0;
        unk_28 = 0xffff;
        *(u8 *)((u8 *)this + 0x2a) = 0;
    }
};

struct Ov010U16x6 {
    u16 v[6];
};

extern "C" {

extern Ov010Heap *data_02097dd0;
extern void Ov010Coll_Release(void *p);

struct Obj022075bc : public Ov003Actor {
    u8 unk_f0[0x34];
    void *unk_124;
};

static inline void Ov010_FreeV(Obj022075bc *self, u32 off) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, off) != NULL) {
        VObj *p = FLD(VObj *, self, off);
        if (p != NULL) {
            p->vfunc_04();
        }
        FLD(void *, self, off) = NULL;
    }
    data_02097dd0->cur = saved;
}

extern u8 data_ov010_0220f024[];
extern void MI_CpuFill8(void *p, s32 v, s32 n);

struct Obj02207520 : public Ov003Actor {
    u8 unk_f0;
    u8 unk_f1;
    u8 unk_f2;
    u8 unk_f3;
    u16 unk_f4;
    u8 unk_f6[0x2];
    s32 unk_f8;
    s32 unk_fc;
    s32 unk_100;
    s32 unk_104;
    s32 unk_108;
    s32 unk_10c;
    s32 unk_110;
    s32 unk_114;
    s32 unk_118;
    s32 unk_11c;
    s32 unk_120;
    s32 unk_124;
    s32 unk_128;
    u8 unk_12c[0x24];
    VecFx32 unk_150;
    s32 unk_15c;
    u8 unk_160[0x10];
    u8 unk_170;
    u8 unk_171;
};

void func_ov010_02207520(Obj02207520 *self) {
    self->unk_f0 = 0;
    self->unk_f1 = 0;
    self->unk_f2 = 0;
    self->unk_f3 = 0;
    self->unk_f4 = 0;
    self->unk_f8 = 0;
    self->unk_fc = 0;
    self->unk_100 = 0;
    self->unk_104 = 0;
    self->unk_108 = 0;
    self->unk_10c = 0;
    self->unk_110 = 0;
    self->unk_114 = 0;
    self->unk_118 = 0;
    self->unk_11c = 0;
    self->unk_120 = 0;
    self->unk_124 = 0;
    self->unk_128 = -1;
    MI_CpuFill8((u8 *)self + 0x12c, 0, 0x24);
    self->unk_150 = FLD(VecFx32, data_ov010_0220f024, 0x84);
    self->unk_15c = -1;
    self->unk_170 = 0;
    self->unk_171 = 0xff;
}

void func_ov010_022075bc(Obj022075bc *self) {
    u32 saved;
    func_ov003_021cf404(0);
    func_ov003_021cf400(0);
    Ov010_FreeV(self, 0x104);
    Ov010_FreeV(self, 0x108);
    Ov010_FreeV(self, 0x10c);
    Ov010_FreeV(self, 0x110);
    Ov010_FreeV(self, 0x114);
    Ov010_FreeV(self, 0x118);
    Ov010_FreeV(self, 0x11c);
    Ov010_FreeV(self, 0x120);
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_124 != NULL) {
        Heap_Free(self->unk_124);
        self->unk_124 = NULL;
    }
    data_02097dd0->cur = saved;
    func_ov003_021d8fa8((u8 *)self + 0x160);
    Ov010Coll_Release((u8 *)self + 0x174);
    ((VObj *)((u8 *)self + 0x1b0))->vfunc_08();
    ((VObj *)((u8 *)self + 0x1dc))->vfunc_08();
    data_ov000_021ccd54->cam.unk_d8_0 = 0;
    func_ov010_02207520((Obj02207520 *)self);
    func_ov003_021cf400(0);
}

extern s32 func_ov000_02199128(s32 *out, Ov010Query *q, void **list, s32 max);

extern s32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);
extern BOOL Ov003Vec_Equal(VecFx32 *a, VecFx32 *b);
extern void Ov003Vec_MultAdd(VecFx32 *a, VecFx32 *b, VecFx32 *c, s32 d, s32 e);

static inline s32 Ov010_Clamp(s32 v, s32 lo, s32 hi) {
    if (v > hi) {
        return hi;
    }
    if (v < lo) {
        return lo;
    }
    return v;
}

struct Obj02207828 : public Ov003Actor {
    u8 unk_f0[0x3];
    u8 unk_f3;
    u8 unk_f4[0x5c];
    VecFx32 unk_150;
    u8 unk_15c[0xa0];
    u8 unk_1fc;
    u8 unk_1fd[0x3];
    s32 unk_200;
};

static inline void Ov010_Move(Obj02207828 *self) {
    Ov003Vec_MultAdd(&self->pos, &self->unk_150, &self->pos, self->speed, self->velY);
    func_ov003_021da2c8(self, self->speed, self->velY, self->friction, self->gravity);
}

void func_ov010_02207828(Obj02207828 *self) {
    VecFx32 t;
    t.x = self->unk_b8.x;
    t.y = self->unk_b8.y;
    t.z = self->unk_b8.z;
    if (VEC_Distance(&t, &self->pos) >= 0x3000) {
        self->speed += 0x180;
        self->speed = Ov010_Clamp(self->speed, 0, 0xd00);
        Ov010_Move(self);
        return;
    } else {
        BOOL slow = TRUE;
        if (self->speed >= 0x40) {
            slow = FALSE;
        }
        if (Ov003Vec_Equal(&self->pos, &t) || slow) {
            self->speed = 0;
            return;
        }
        self->friction = 0xf00;
        if (self->speed >= 0x400) {
            self->speed = 0x400;
        }
    }
    Ov010_Move(self);
}

static inline void Ov010Query_Set(Ov010Query *q, const VecFx32 *pos, u16 rot, u16 kind, s32 r) {
    q->pos.x = pos->x;
    q->pos.y = pos->y;
    q->pos.z = pos->z;
    q->rot = rot;
    q->kind = kind;
    q->unk_10 = 0xffff;
    q->unk_18 = 0;
    q->unk_1c = r;
    q->b2 = 0;
}

BOOL func_ov010_0220794c(Actor *self) {
    void *list[0x20];
    Ov010Query q;
    s32 out;
    BOOL found = FALSE;
    s32 n;
    s32 i;
    Ov010Query_Set(&q, &self->pos, self->rot_y, 0x10, 0x5000);
    out = 0;
    n = func_ov000_02199128(&out, &q, list, 0x20);
    for (i = 0; i < n; i++) {
        void *a = list[i];
        if (a != NULL) {
            u8 st;
            if (FLD(void *, a, 0x40) != NULL) {
                st = FLD(u8, FLD(void *, a, 0x40), 0x13);
            } else {
                st = 0;
            }
            if (st == 0xb && FLD(u16, a, 0x90) == self->id) {
                found = TRUE;
            }
        }
    }
    return found;
}

extern u8 data_ov010_02210154[];
extern u8 data_ov010_0220ffe4[];
extern char data_ov010_0220ff84[];
extern char data_ov010_0220ff91[];
extern char data_ov010_0220ffa1[];
extern char data_ov010_0220ffae[];
extern void *func_ov010_0220d79c(void *p);
extern void *Ov003Vt_021f7d10_Ctor(void *p);
extern void *Ov003Vt_021f7cd8_Ctor(void *p);
extern void func_ov010_02207520(Obj02207520 *self);
extern void Ov010ActVt_02210154_Start(void *self);
extern BOOL func_ov010_0220441c(void *self, void *msg);

static inline void Ov010_02204204_Body(Ov010ObjBase0220ffe4_0221009c *self) {
    func_ov003_021d0c1c(self);
    *(void * *)self = data_ov010_02210154;
    func_ov003_021d8f24((u8 *)self + 0x160);
    func_ov010_0220d79c((u8 *)self + 0x174);
    Ov003Vt_021f7d10_Ctor((u8 *)self + 0x1b0);
    Ov003Vt_021f7cd8_Ctor((u8 *)self + 0x1dc);
    func_ov003_021cf340(data_ov010_0220ff84);
    func_ov003_021cf3fc(1);
    func_ov003_021cf39c(2, data_ov010_0220ff91);
    func_ov003_021cf39c(0, data_ov010_0220ffa1);
    func_ov003_021cf39c(1, data_ov010_0220ffae);
    func_ov010_02207520((Obj02207520 *)self);
}

u16 func_ov010_02207a44(s32 i) {
    Ov010U16x6 t = FLD(Ov010U16x6, data_ov010_0220f024, 0xb4);
    if (i < 6) {
        return t.v[i];
    }
    return t.v[5] + (u16)((i - 5) * 0x5a);
}

void *Ov010ActVt_0220ffe4_Ctor(Obj02207828 *self) {
    Ov010_02204204_Body((Ov010ObjBase0220ffe4_0221009c *)self);
    self->unk_1fc = 0;
    self->unk_200 = 0;
    *(void * *)self = data_ov010_0220ffe4;
    return self;
}

void Ov010ActVt_0220ffe4_Start(Obj02207828 *self) {
    Ov010ActVt_02210154_Start(self);
    self->unk_f3 = self->unk_18 == 3;
}

void func_ov010_02207b90(Obj02207828 *self, void *msg) {
    if (msg != NULL && FLD(u8, msg, 5) == 2) {
        self->unk_1fc = 0;
    }
    func_ov010_0220441c(self, msg);
}

extern const Ov010StEnt data_ov010_0220f188[];
extern const Ov010Blk12 data_ov010_0220f0b4;
extern Robo021ca458 *func_ov000_0219bf90(void);
extern void VEC_MultAdd(s32 a, const VecFx32 *b, const VecFx32 *c, VecFx32 *out);
extern void func_ov010_0220d858(void *p);


void func_ov010_02207bb4(Ov010Cls *self) {
    u32 i;
    Robo021ca458 *pl;
    s16 *p;
    u8 key;
    if (self->unk_1fc != 0) {
        return;
    }
    key = self->fsm->current;
    for (i = 0; i < 6; i++) {
        if (key == data_ov010_0220f188[i].key && *(s32 *)&data_ov010_0220f188[i].fn != 0) {
            (self->*data_ov010_0220f188[i].fn)();
            break;
        }
    }
    func_ov003_021d3008(self);
    if (func_ov003_021cf408()) {
        self->mode = func_ov003_021cf408();
    }
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        Ov010_VecCopy(&pl->unk_b90, &self->pos);
        pl->unk_b9c = 0x800;
    }
    p = self->unk_124;
    if (p != NULL) {
        VecFx32 v;
        *(Ov010Blk12 *)&v = data_ov010_0220f0b4;
        func_ov003_021d9980(&v, p[0], &v);
        VEC_MultAdd(p[1], &v, &self->pos, &self->pos);
        p[1] = Ov010_FxMul(p[1], p[2]);
    }
    func_ov010_0220d858((u8 *)self + 0x174);
    ((VObj *)((u8 *)self + 0x1b0))->vfunc_0c();
    ((VObj *)((u8 *)self + 0x1dc))->vfunc_0c();
    if (self->unk_118 != NULL) {
        self->unk_118->vfunc_0c();
    }
}

extern void *data_02097e4c;
extern const VecFx32 data_ov010_0220f0fc;
extern BOOL func_ov000_02190cb0(void *a, const char *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
extern VObj *func_02065f88(s32 id, VecFx32 *pos);
extern u16 FX_Atan2(s32 y, s32 x);

void func_ov010_02207d2c(Obj02207828 *self) {
    self->model->visible = 1;
    switch (self->unk_18) {
    case 0: {
        ActorSub40 *st = self->fsm;
        switch (st->st) {
        case 0:
            func_ov000_02190cb0(self->model, FLD(const char *, data_ov010_0220f024, 0x2c), 0x1000, 0);
            func_ov000_021915a0(self->model);
            Ov010_VecSet(&self->pos, 0x19a, 0x1b3b, -0x3a77);
            self->rot_x = FLD(u16, data_ov010_0220f024, 0x50);
            self->rot_y = FLD(u16, data_ov010_0220f024, 0x52);
            self->rot_z = FLD(u16, data_ov010_0220f024, 0x54);
            self->pos.y += 0x5000;
            self->speed = 0xcd;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            func_02049f44(data_02097e4c, 0x51, &self->pos, 0);
            self->fsm->st = 1;
            return;
        case 1:
            if (self->speed >= 0x20) {
                const VecFx32 *t = &data_ov010_0220f0fc;
                if (self->friction == 0) {
                    if (VEC_Distance(t, &self->pos) < 0x333) {
                        self->friction = 0xe66;
                    }
                }
                func_ov003_021d9dbc(&self->pos, t, &self->pos, self->speed, self->velY);
                func_ov003_021da2c8(self, self->speed, self->velY, self->friction, self->gravity);
                self->moveYaw = FX_Atan2(t->x - self->pos.x, t->z - self->pos.z);
                return;
            }
            func_02065f88(0x12f, &self->pos)->vfunc_0c(0xe66);
            self->fsm->st = 2;
            return;
        case 2:
            st->timer++;
            if (self->fsm->timer <= 0x5a) {
                return;
            }
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            func_ov003_021d64f0(self);
            return;
        }
        return;
    }
    case 1:
        Ov010_VecSet(&self->pos, 0x19a, 0x1b3b, -0x3a77);
        self->rot_x = FLD(u16, data_ov010_0220f024, 0x50);
        self->rot_y = FLD(u16, data_ov010_0220f024, 0x52);
        self->rot_z = FLD(u16, data_ov010_0220f024, 0x54);
        func_ov003_021d64f0(self);
        return;
    case 2:
        Ov010_VecSet(&self->pos, 0x1da2, -0xb42d, 0x266f);
        self->rot_x = 0;
        self->rot_y = 0x7fff;
        self->rot_z = 0;
        func_ov003_021d64f0(self);
        return;
    case 3:
        Ov010_VecSet(&self->pos, 0x1da2, -0xb42d, 0x266f);
        self->rot_x = 0;
        self->rot_y = 0x7fff;
        self->rot_z = 0;
        func_ov003_021d64f0(self);
        return;
    }
}

extern void VEC_Normalize(const VecFx32 *src, VecFx32 *dst);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);

static inline void Ov010_VecSub(const VecFx32 *a, const VecFx32 *b, VecFx32 *o) {
    o->x = a->x - b->x;
    o->y = a->y - b->y;
    o->z = a->z - b->z;
}

void func_ov010_02208018(Obj02207828 *self) {
    if (self->fsm->st == 0) {
        Ov010_VecSet(&self->pos, 0x1da2, -0xb42d, 0x266f);
        self->rot_x = 0;
        self->rot_y = 0x7fff;
        self->rot_z = 0;
        self->pos.y += 0x8000;
        Ov010_VecSet(&self->unk_b8, 0x1da2, -0xb42d, 0x266f);
        Ov010_VecSub(&self->unk_b8, &self->pos, &self->unk_150);
        VEC_Normalize(&self->unk_150, &self->unk_150);
        self->moveYaw = FX_Atan2(self->unk_150.x, self->unk_150.z);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
        self->fsm->st++;
        return;
    }
    func_ov010_02207828(self);
    if (self->speed == 0) {
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
        func_ov000_02198360(self->fsm, 1, 0);
    }
}

extern void func_ov000_021911c8(void *a, s32 b);
extern BOOL func_ov000_02191120(void *a);
extern const VecFx32 data_ov010_0220f108;
extern VecFx32 data_ov010_0220f114;
extern VecFx32 data_ov010_0220f120;
extern void Actor_Move(void *self, s32 a);

struct Ov010Rot3 {
    s16 v[3];
};

void func_ov010_0220813c(Obj02207828 *self) {
    switch (self->fsm->st) {
    case 0:
        self->fsm->st = 10;
        return;
    case 10:
        func_ov000_02190cb0(self->model, FLD(const char *, data_ov010_0220f024, 0x8), 0x266, 0);
        func_ov000_021911c8(self->model, 0x1800);
        self->fsm->st = 0xb;
    case 0xb:
        if (func_ov000_02191120(self->model)) {
            self->fsm->st = 0x14;
        }
        return;
    case 0x14: {
        FieldState *g;
        func_ov000_02190cb0(self->model, FLD(const char *, data_ov010_0220f024, 0xc), 0x266, 0);
        func_ov000_021911c8(self->model, 0x1000);
        func_ov000_021915a0(self->model);
        self->moveYaw = self->rot_y;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        g = data_ov000_021ccd54;
        g->cam.base.flags |= 0x1c;
        g->cam.base.shakeTime = 0xf;
        g->cam.base.shakeLen = 0x28;
        g->cam.base.shakeCur = 0x28;
        func_ov010_0220ea84(self, 0, self->moveYaw)->vfunc_0c(0x2000);
        func_02049f44(data_02097e4c, 0x32, &self->pos, 0);
        self->fsm->st = 0x15;
    }
    case 0x15:
        if (VEC_Distance(&self->pos, &data_ov010_0220f108) <= 0x14000) {
            self->speed += 0x333;
            self->speed = Ov010_Clamp(self->speed, 0, 0x1000);
            Actor_Move(self, 0x1000);
        }
        self->fsm->timer++;
        if (self->fsm->timer <= 0x5a) {
            return;
        }
        self->fsm->timer = 0;
        self->fsm->st = 0x1e;
        Ov010_VecSet(&self->pos, 0x19a, 0x1b3b, -0x3a77);
        return;
    case 0x1e:
        func_02065f88(0x389, &data_ov010_0220f114)->vfunc_0c(0x2000);
        func_02065f88(0x322, &data_ov010_0220f114)->vfunc_0c(0x1800);
        func_02065f88(0x389, &data_ov010_0220f120)->vfunc_0c(0x2000);
        func_02065f88(0x322, &data_ov010_0220f114)->vfunc_0c(0x1800);
        func_02049f44(data_02097e4c, 0x79, &self->pos, 0);
        self->fsm->st = 0x1f;
        self->fsm->timer = 0x28;
        return;
    case 0x1f: {
        ActorSub40 *st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            self->fsm->st = 0x28;
        }
        return;
    }
    case 0x28: {
        Ov010Rot3 r;
        void *o;
        r = FLD(Ov010Rot3, data_ov010_0220f024, 0x5c);
        o = func_ov003_021da32c(0x5816);
        Ov010_VecSet(&FLD(VecFx32, o, 0x70), 0x2ee1, -0xc000, -0x2000);
        FLD(u16, o, 0x7c) = r.v[0];
        FLD(u16, o, 0x7e) = r.v[1];
        FLD(u16, o, 0x80) = r.v[2];
        o = func_ov003_021da32c(0x5816);
        Ov010_VecSet(&FLD(VecFx32, o, 0x70), -0x2571, -0xc000, -0x2000);
        FLD(u16, o, 0x7c) = r.v[0];
        FLD(u16, o, 0x7e) = r.v[1];
        FLD(u16, o, 0x80) = r.v[2];
        func_02065f88(0x579, &data_ov010_0220f114)->vfunc_0c(0x2000);
        func_02065f88(0x579, &data_ov010_0220f120)->vfunc_0c(0x2000);
        func_02049f44(data_02097e4c, 0x5c, &self->pos, 0);
        self->fsm->st = 0x64;
        return;
    }
    case 0x64:
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
        self->fsm->st = 0x65;
        self->unk_1fc = 1;
        return;
    case 0x65:
        return;
    }
}

}
