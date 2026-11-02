#include "ov014/ov014.h"

struct Ov014Wave {
    s16 kind;
    u16 wait;
    u16 count;
};

struct Ov014SpawnDescB {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov014SpawnB_Init(Ov014SpawnDescB *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

extern "C" {

extern u8 data_ov014_02217d3a[];
extern u8 data_ov014_02217d40[];
extern u8 data_ov014_02217d46[];
extern void func_ov000_021911c8(void *a, s32 b);
extern Ov014Actor *func_ov000_0219bf90(void);
extern u16 FX_Atan2(s32 x, s32 z);
extern u8 data_ov014_02217d4c[];
extern void *func_ov000_02191318(void *a, s32 b);
extern s32 Rand_UpTo(s32 max);
extern void *func_ov014_02210878(Ov014Act_0220f9d0 *self);
extern void *data_02097e4c;
extern u8 data_ov014_02217d1d[];
extern u8 data_ov014_02217d52[];
extern u8 data_ov014_02217d5e[];
extern u8 data_ov014_02217d64[];
extern void func_ov000_02191618(void *a);
extern s32 **func_ov000_02190a30(void *a, s32 b);
extern Ov014Actor *func_02065f88(s32 id, Ov014Vec *pos);
extern Ov014V *func_02066774(const void *a, const void *b, s32 c, Ov014Vec *pos);
extern void *func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern Ov014Actor *func_ov014_02210d9c(Ov014Act_0220f9d0 *self);
extern Ov014Actor *func_ov014_02210a78(Ov014Act_0220f9d0 *self);
extern Ov014Actor *func_ov014_02210c5c(Ov014Act_0220f9d0 *self);

static inline void Ov014_TimerTick(Ov014Sub40 *s) {
    if (s->timer != 0) {
        s->timer--;
    }
}

void func_ov014_02210ecc(Ov014Act_0220f9d0 *self) {
    self->unk_40->state = 0xffff;
}

void func_ov014_02210ee0(Ov014Act_0220f9d0 *self) {
    switch (self->unk_40->state) {
    case 0: {
        Ov014Sub44 *n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        FLD(Ov014Flags, self->unk_44, 0x22).b4 = 1;
        self->unk_40->state = 40;
        break;
    }
    case 10:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d3a, 0xcd, 0);
        func_ov000_021911c8(self->unk_38, 0x1000);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state = 40;
        break;
    case 20:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d40, 0xcd, 0);
        func_ov000_021911c8(self->unk_38, 0x1000);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state = 40;
        break;
    case 30:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d46, 0xcd, 0);
        func_ov000_021911c8(self->unk_38, 0x1000);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state = 40;
        break;
    case 40:
        if (func_ov000_02191120(self->unk_38)) {
            Ov014Actor *a = func_ov000_0219bf90();
            u16 ang;
            if (a == NULL || a == self) {
                ang = self->rot[1];
            } else {
                ang = FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
            }
            if (ang < 0x71c || ang > 0xf8e3) {
                self->unk_40->state = 10;
            } else if (ang < 0x3fff) {
                self->unk_40->state = 20;
            } else {
                self->unk_40->state = 30;
            }
        }
        break;
    }
}

void func_ov014_022110bc(Ov014Act_0220f9d0 *self) {
    Ov014Sub40 *s = self->unk_40;
    Ov014Wave *p = ((Ov014Wave *)self->unk_140);
    switch (Ov014Sub40_State(s)) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d4c, 0x19a, 0);
        func_ov000_021915a0(self->unk_38);
        func_ov000_02191318(self->unk_38, 0);
        self->unk_40->state = 20;
        self->unk_14c = p->count;
        self->unk_144 = Rand_UpTo(0xffff);
        break;
    case 20:
        if (self->unk_38->unk_c4 != 1) {
            return;
        }
        switch (p->kind) {
        case 0:
            func_ov014_02210878(self);
            break;
        case 1:
            func_ov014_02210a78(self);
            break;
        case 2:
            func_ov014_02210c5c(self);
            break;
        default:
            func_ov014_02210878(self);
            break;
        }
        self->unk_38->unk_c4 = 0;
        self->unk_14c--;
        if (self->unk_14c == 0) {
            self->unk_40->state = 30;
            self->unk_40->timer = 30;
        } else {
            self->unk_40->state++;
            self->unk_40->timer = p->wait;
        }
        break;
    case 21:
        if (Ov014Sub40_Timer(s) != 0) {
            Ov014_TimerTick(s);
            return;
        }
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d4c, 0x19a, 0);
        func_ov000_021915a0(self->unk_38);
        if (p->wait <= 35) {
            func_ov000_02191318(self->unk_38, 0x24000);
        } else {
            func_ov000_02191318(self->unk_38, 0);
        }
        self->unk_40->state--;
        break;
    case 30:
        if (Ov014Sub40_Timer(s) == 0) {
            s->state = 0xffff;
        } else {
            Ov014_TimerTick(s);
        }
        break;
    default:
        s->state = 0xffff;
        break;
    }
}

void func_ov014_022112b8(Ov014Act_0220f9d0 *self) {
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d4c, 0xcd, 0);
        func_ov000_02191318(self->unk_38, 0);
        func_ov000_02191618(self->unk_38);
        self->unk_40->state++;
        self->unk_40->timer = 0xcd;
    case 1: {
        Ov014Vec v;
        u16 t = self->unk_40->timer;
        if (t != 0) {
            if (t == 200) {
                Ov014Actor *e;
                v.x = self->unk_118.x;
                v.y = self->unk_118.y;
                v.z = self->unk_118.z + 0x3000;
                e = func_02065f88(0x5e2, &v);
                e->v14(0x3000, 0x3000, 0x3000);
                e->unk_c8 = 1;
            } else if (t == 100) {
                v.x = self->unk_118.x;
                v.y = self->unk_118.y;
                v.z = self->unk_118.z + 0x3000;
                func_02066774(data_ov014_02217d1d, data_ov014_02217d52, 0, &v)->v14(0x3000, 0x3000, 0x3000);
                func_02049f44(data_02097e4c, 0x5b, (Ov014Vec *)((u8 *)self + 0x118), 0);
                func_02049f44(data_02097e4c, 0x50, (Ov014Vec *)((u8 *)self + 0x118), 0);
            }
            Ov014_TimerTick(self->unk_40);
        } else {
            func_ov000_02190cb0(self->unk_38, data_ov014_02217d5e, 0x1000, 0);
            func_ov000_02191318(self->unk_38, 0);
            func_ov000_02191618(self->unk_38);
            self->unk_40->state++;
        }
        break;
    }
    case 2:
        if (self->unk_38->unk_c4 != 1) {
            return;
        }
        func_ov014_02210d9c(self);
        func_02066774(data_ov014_02217d1d, data_ov014_02217d64, 0, (Ov014Vec *)((u8 *)self + 0x118));
        func_02049f44(data_02097e4c, 0x1b, (Ov014Vec *)((u8 *)self + 0x118), 0);
        func_02049f44(data_02097e4c, 0x3e, (Ov014Vec *)((u8 *)self + 0x118), 0);
        self->unk_38->unk_c4 = 0;
        self->unk_40->state++;
        break;
    case 3: {
        s32 t = 0;
        s32 **q = func_ov000_02190a30(self->unk_38, 0);
        if (*q != NULL) {
            t = **q;
        }
        if (t >= 0x3c000) {
            self->unk_40->state = 0xffff;
        }
        break;
    }
    }
}


extern u8 data_ov014_02217d70[];
extern u8 data_ov014_02216d30[];
extern void *data_ov000_021ccd64;
extern void MTX_MultVec43(const Ov014Vec *in, const void *m, Ov014Vec *out);
extern s32 VEC_Mag(const Ov014Vec *v);
extern Ov014Actor *Group_SpawnActor(void *mgr, Ov014SpawnDescB *d, Ov014Vec *pos, Ov014Rot16 *rot, u16 a);

void func_ov014_02211538(Ov014Act_0220f9d0 *self) {
    switch (Ov014Sub40_State(self->unk_40)) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d4c, 0xcd, 0);
        func_ov000_02191318(self->unk_38, 0);
        func_ov000_02191618(self->unk_38);
        self->unk_40->state++;
        self->unk_40->timer = 0x91;
    case 1:
        if (self->unk_40->timer != 0) {
            if (self->unk_40->timer == 0x8c) {
                Ov014Vec v;
                v.x = self->unk_118.x;
                v.y = self->unk_118.y;
                v.z = self->unk_118.z + 0x3000;
                func_02065f88(0x5dd, &v)->v14(0x3000, 0x3000, 0x3000);
                func_02049f44(data_02097e4c, 0x5b, &v, 0);
            }
            if (self->unk_40->timer == 0x5a) {
                Ov014Vec v;
                v.x = self->unk_118.x;
                v.y = self->unk_118.y;
                v.z = self->unk_118.z + 0x3000;
                func_02065f88(0x5dd, &v)->v14(0x3000, 0x3000, 0x3000);
                func_02049f44(data_02097e4c, 0x5b, &v, 0);
            }
            if (self->unk_40->timer == 0x28) {
                Ov014Vec v;
                v.x = self->unk_118.x;
                v.y = self->unk_118.y;
                v.z = self->unk_118.z + 0x3000;
                func_02065f88(0x196, &v)->v14(0x2ccd, 0x2ccd, 0x2ccd);
                func_02049f44(data_02097e4c, 0x44, &v, 0);
            }
            {
                Ov014Sub40 *s = self->unk_40;
                if (s->timer != 0) {
                    s->timer--;
                }
            }
            break;
        }
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d70, 0xcd, 0);
        func_ov000_02191318(self->unk_38, 0);
        func_ov000_02191618(self->unk_38);
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 2: {
        Ov014Vec p;
        Ov014Vec w;
        Ov014Vec v;
        Ov014SpawnDescB desc;
        Ov014Rot16 rot;
        Ov014Actor *o;
        Ov014Game54 *g;
        if (self->unk_38->unk_c4 != 1) {
            break;
        }
        self->unk_38->unk_c4 = 0;
        p = self->unk_118;
        p.y -= 0x800;
        v.x = 0;
        v.y = 0;
        v.z = 0x1000;
        MTX_MultVec43(&v, (u8 *)self + 0xf4, &v);
        w.x = v.x;
        w.y = 0;
        w.z = v.z;
        VEC_Mag(&w);
        rot.x = 0xf00;
        rot.y = FX_Atan2(w.x, w.z);
        rot.z = 0;
        Ov014SpawnB_Init(&desc, 0x4838);
        o = Group_SpawnActor(data_ov000_021ccd64, &desc, &p, &rot, 0xffff);
        o->unk_60 = data_ov014_02216d30;
        o->unk_90 = self->unk_90;
        if (o->unk_4c != NULL) {
            o->unk_4c->target = self->id;
        }
        o->flags_0 = 1;
        self->target_id = o->id;
        g = data_ov000_021ccd54;
        g->unk_190 |= 0x1c;
        g->unk_18d = 0x1e;
        g->unk_18e = 0x78;
        g->unk_18f = 0x78;
        self->unk_40->state++;
        self->unk_40->timer = 0xa0;
        break;
    }
    case 3: {
        Ov014Sub40 *s = self->unk_40;
        if (Ov014Sub40_Timer(s) == 0) {
            s->state++;
            break;
        }
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer > 0x28 && s->timer % 40 == 0) {
            func_02049f44(data_02097e4c, 0x5c, &self->pos, 0);
        }
        break;
    }
    case 4:
        self->unk_40->state = 0xffff;
        break;
    }
}

extern u8 data_ov014_02217d76[];
extern u8 data_ov014_02216d78[];
extern void *data_ov000_021ccd68;
extern s32 FX_Div(s32 a, s32 b);
extern void func_ov000_02191780(void *a);
extern void func_ov000_021917f8(void *a);
extern Ov014Actor *ActorMgr_GetActor(void *mgr, u16 id);

struct Ov014WaveB {
    s16 kind;
    u16 wait;
    u16 count;
};

void func_ov014_02211980(Ov014Act_0220f9d0 *self) {
    switch (Ov014Sub40_State(self->unk_40)) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d4c, 0xcd, 0);
        func_ov000_02191318(self->unk_38, 0);
        func_ov000_02191618(self->unk_38);
        self->unk_40->state++;
        self->unk_40->timer = 0xa0;
        self->unk_14c = ((Ov014WaveB *)self->unk_140)->count;
    case 1:
        if (self->unk_40->timer != 0) {
            if (self->unk_40->timer == 0x9b) {
                Ov014Vec v;
                v.x = self->unk_118.x;
                v.y = self->unk_118.y;
                v.z = self->unk_118.z + 0x3000;
                func_02065f88(0x5dd, &v)->v14(0x3000, 0x3000, 0x3000);
                func_02049f44(data_02097e4c, 0x5b, &v, 0);
            }
            if (self->unk_40->timer == 0x69) {
                Ov014Vec v;
                v.x = self->unk_118.x;
                v.y = self->unk_118.y;
                v.z = self->unk_118.z + 0x3000;
                func_02065f88(0x5dd, &v)->v14(0x3000, 0x3000, 0x3000);
                func_02049f44(data_02097e4c, 0x5b, &v, 0);
            }
            if (self->unk_40->timer == 0x37) {
                Ov014Vec v;
                v.x = self->unk_118.x;
                v.y = self->unk_118.y;
                v.z = self->unk_118.z + 0x3000;
                func_02065f88(0x196, &v)->v0c(0x2ccd);
                func_02049f44(data_02097e4c, 0x44, &v, 0);
            }
            {
                Ov014Sub40 *s = self->unk_40;
                if (s->timer != 0) {
                    s->timer--;
                }
            }
            break;
        }
        {
            s32 **q;
            s32 t;
            func_ov000_02190cb0(self->unk_38, data_ov014_02217d76, 0xcd, 0);
            func_ov000_02191618(self->unk_38);
            q = func_ov000_02190a30(self->unk_38, 0);
            if (*q != NULL) {
                **q = (FLD(u16, FLD(u8 *, *q, 8), 4) << 12) - 1;
            }
            t = 0;
            q = func_ov000_02190a30(self->unk_38, 0);
            if (*q != NULL) {
                t = **q;
            }
            self->unk_14a = 0x46;
            self->unk_148 = ((Ov014WaveB *)self->unk_140)->count * self->unk_14a + 0x2d;
            func_ov000_021911c8(self->unk_38, (s16)FX_Div(t, self->unk_148 << 12));
            if (Rand_UpTo(1)) {
                func_ov000_02191780(self->unk_38);
                func_ov000_02191318(self->unk_38, t);
            } else {
                func_ov000_021917f8(self->unk_38);
                func_ov000_02191318(self->unk_38, 0);
            }
            self->unk_40->state++;
            self->unk_40->timer = self->unk_148;
        }
        break;
    case 2: {
        s32 i;
        Ov014Vec p;
        Ov014Vec w;
        Ov014Vec v;
        Ov014SpawnDescB desc;
        Ov014Rot16 rot;
        u16 tm = self->unk_40->timer;
        p = self->unk_118;
        p.y -= 0x800;
        v.x = 0;
        v.y = 0;
        v.z = 0x1000;
        MTX_MultVec43(&v, (u8 *)self + 0xf4, &v);
        w.x = v.x;
        w.y = 0;
        w.z = v.z;
        VEC_Mag(&w);
        rot.x = 0xf00;
        rot.y = FX_Atan2(w.x, w.z);
        rot.z = 0;
        if (tm % self->unk_14a == 0) {
            Ov014Actor *o;
            Ov014Game54 *g;
            Ov014Actor *e;
            desc.kind = 0x4839;
            desc.flags = 0x4839 & 0xf000;
            for (i = 0; i < 4; i++) {
                desc.unk_04[i] = 0;
            }
            desc.parent = -1;
            o = Group_SpawnActor(data_ov000_021ccd64, &desc, &p, &rot, 0xffff);
            o->unk_60 = data_ov014_02216d78;
            o->unk_90 = self->unk_90;
            if (o->unk_4c != NULL) {
                o->unk_4c->target = self->id;
            }
            o->flags_0 = 1;
            self->target_id = o->id;
            self->target_id = o != NULL ? o->id : 0xffff;
            g = data_ov000_021ccd54;
            g->unk_190 |= 0x1c;
            g->unk_18d = 0x1e;
            g->unk_18e = 0x2d;
            g->unk_18f = 0x2d;
            e = func_02065f88(0x579, &p);
            e->v0c(0x24cd);
            FLD(s32, e, 0x50) = -0x64000;
            func_02049f44(data_02097e4c, 0x1b, &p, 0);
        }
        {
            Ov014Sub40 *s = self->unk_40;
            Ov014Actor *a;
            if (s->timer != 0) {
                s->timer--;
            }
            if (s->timer > 10) {
                {
                    u16 id = self->target_id;
                    if (data_ov000_021ccd68 == NULL) {
                        a = NULL;
                    } else {
                        a = ActorMgr_GetActor(data_ov000_021ccd68, id);
                    }
                }
                if (a == NULL) {
                    self->target_id = 0xffff;
                    break;
                }
                a->pos = p;
                FLD(Ov014Rot16, a, 0x7c) = rot;
                break;
            }
            self->unk_40->state++;
            self->unk_40->timer = 0;
        }
        break;
    }
    case 3: {
        Ov014Sub40 *s = self->unk_40;
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            self->unk_40->state = 0xffff;
        }
        break;
    }
    }
}

}
