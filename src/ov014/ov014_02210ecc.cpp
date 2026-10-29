#include "ov014/ov014.h"

struct Ov014Wave {
    s16 kind;
    u16 wait;
    u16 count;
};

struct Ov014Vec16b {
    u16 x;
    u16 y;
    u16 z;
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
extern s32 func_02040498(s32 max);
extern void *func_ov014_02210878(Ov014Actor *self);
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
extern Ov014Actor *func_ov014_02210d9c(Ov014Actor *self);
extern Ov014Actor *func_ov014_02210a78(Ov014Actor *self);
extern Ov014Actor *func_ov014_02210c5c(Ov014Actor *self);

static inline void Ov014_TimerTick(Ov014Sub40 *s) {
    if (s->timer != 0) {
        s->timer--;
    }
}

void func_ov014_02210ecc(Ov014Actor *self) {
    self->unk_40->state = 0xffff;
}

void func_ov014_02210ee0(Ov014Actor *self) {
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

void func_ov014_022110bc(Ov014Actor *self) {
    Ov014Sub40 *s = self->unk_40;
    Ov014Wave *p = FLD(Ov014Wave *, self, 0x140);
    switch (Ov014Sub40_State(s)) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d4c, 0x19a, 0);
        func_ov000_021915a0(self->unk_38);
        func_ov000_02191318(self->unk_38, 0);
        self->unk_40->state = 20;
        FLD(u16, self, 0x14c) = p->count;
        FLD(s32, self, 0x144) = func_02040498(0xffff);
        break;
    case 20:
        if (FLD(s16, self->unk_38, 0xc4) != 1) {
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
        FLD(s16, self->unk_38, 0xc4) = 0;
        FLD(u16, self, 0x14c)--;
        if (FLD(u16, self, 0x14c) == 0) {
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

void func_ov014_022112b8(Ov014Actor *self) {
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
                v.x = FLD(s32, self, 0x118);
                v.y = FLD(s32, self, 0x11c);
                v.z = FLD(s32, self, 0x120) + 0x3000;
                e = func_02065f88(0x5e2, &v);
                e->v14(0x3000, 0x3000, 0x3000);
                FLD(s32, e, 0xc8) = 1;
            } else if (t == 100) {
                v.x = FLD(s32, self, 0x118);
                v.y = FLD(s32, self, 0x11c);
                v.z = FLD(s32, self, 0x120) + 0x3000;
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
        if (FLD(s16, self->unk_38, 0xc4) != 1) {
            return;
        }
        func_ov014_02210d9c(self);
        func_02066774(data_ov014_02217d1d, data_ov014_02217d64, 0, (Ov014Vec *)((u8 *)self + 0x118));
        func_02049f44(data_02097e4c, 0x1b, (Ov014Vec *)((u8 *)self + 0x118), 0);
        func_02049f44(data_02097e4c, 0x3e, (Ov014Vec *)((u8 *)self + 0x118), 0);
        FLD(s16, self->unk_38, 0xc4) = 0;
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
extern Ov014Actor *func_ov000_0218bf1c(void *mgr, Ov014SpawnDescB *d, Ov014Vec *pos, Ov014Vec16b *rot, u16 a);

void func_ov014_02211538(Ov014Actor *self) {
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
                v.x = FLD(s32, self, 0x118);
                v.y = FLD(s32, self, 0x11c);
                v.z = FLD(s32, self, 0x120) + 0x3000;
                func_02065f88(0x5dd, &v)->v14(0x3000, 0x3000, 0x3000);
                func_02049f44(data_02097e4c, 0x5b, &v, 0);
            }
            if (self->unk_40->timer == 0x5a) {
                Ov014Vec v;
                v.x = FLD(s32, self, 0x118);
                v.y = FLD(s32, self, 0x11c);
                v.z = FLD(s32, self, 0x120) + 0x3000;
                func_02065f88(0x5dd, &v)->v14(0x3000, 0x3000, 0x3000);
                func_02049f44(data_02097e4c, 0x5b, &v, 0);
            }
            if (self->unk_40->timer == 0x28) {
                Ov014Vec v;
                v.x = FLD(s32, self, 0x118);
                v.y = FLD(s32, self, 0x11c);
                v.z = FLD(s32, self, 0x120) + 0x3000;
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
        Ov014Vec16b rot;
        Ov014Actor *o;
        Ov014Game54 *g;
        if (FLD(s16, self->unk_38, 0xc4) != 1) {
            break;
        }
        FLD(s16, self->unk_38, 0xc4) = 0;
        p = FLD(Ov014Vec, self, 0x118);
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
        o = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, &p, &rot, 0xffff);
        FLD(void *, o, 0x60) = data_ov014_02216d30;
        o->unk_90 = self->unk_90;
        if (FLD(u8 *, o, 0x4c) != NULL) {
            FLD(u16, FLD(u8 *, o, 0x4c), 0x1c) = self->id;
        }
        FLD(Ov014Flags8, o, 0x16).b0 = 1;
        FLD(u16, self, 0xde) = o->id;
        g = data_ov000_021ccd54;
        FLD(u8, g, 0x190) |= 0x1c;
        FLD(u8, g, 0x18d) = 0x1e;
        FLD(u8, g, 0x18e) = 0x78;
        FLD(u8, g, 0x18f) = 0x78;
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
extern Ov014Actor *func_ov000_0218e640(void *mgr, u16 id);

struct Ov014WaveB {
    s16 kind;
    u16 wait;
    u16 count;
};

void func_ov014_02211980(Ov014Actor *self) {
    switch (Ov014Sub40_State(self->unk_40)) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217d4c, 0xcd, 0);
        func_ov000_02191318(self->unk_38, 0);
        func_ov000_02191618(self->unk_38);
        self->unk_40->state++;
        self->unk_40->timer = 0xa0;
        FLD(u16, self, 0x14c) = FLD(Ov014WaveB *, self, 0x140)->count;
    case 1:
        if (self->unk_40->timer != 0) {
            if (self->unk_40->timer == 0x9b) {
                Ov014Vec v;
                v.x = FLD(s32, self, 0x118);
                v.y = FLD(s32, self, 0x11c);
                v.z = FLD(s32, self, 0x120) + 0x3000;
                func_02065f88(0x5dd, &v)->v14(0x3000, 0x3000, 0x3000);
                func_02049f44(data_02097e4c, 0x5b, &v, 0);
            }
            if (self->unk_40->timer == 0x69) {
                Ov014Vec v;
                v.x = FLD(s32, self, 0x118);
                v.y = FLD(s32, self, 0x11c);
                v.z = FLD(s32, self, 0x120) + 0x3000;
                func_02065f88(0x5dd, &v)->v14(0x3000, 0x3000, 0x3000);
                func_02049f44(data_02097e4c, 0x5b, &v, 0);
            }
            if (self->unk_40->timer == 0x37) {
                Ov014Vec v;
                v.x = FLD(s32, self, 0x118);
                v.y = FLD(s32, self, 0x11c);
                v.z = FLD(s32, self, 0x120) + 0x3000;
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
            FLD(u16, self, 0x14a) = 0x46;
            FLD(u16, self, 0x148) = FLD(Ov014WaveB *, self, 0x140)->count * FLD(u16, self, 0x14a) + 0x2d;
            func_ov000_021911c8(self->unk_38, (s16)FX_Div(t, FLD(u16, self, 0x148) << 12));
            if (func_02040498(1)) {
                func_ov000_02191780(self->unk_38);
                func_ov000_02191318(self->unk_38, t);
            } else {
                func_ov000_021917f8(self->unk_38);
                func_ov000_02191318(self->unk_38, 0);
            }
            self->unk_40->state++;
            self->unk_40->timer = FLD(u16, self, 0x148);
        }
        break;
    case 2: {
        s32 i;
        Ov014Vec p;
        Ov014Vec w;
        Ov014Vec v;
        Ov014SpawnDescB desc;
        Ov014Vec16b rot;
        u16 tm = self->unk_40->timer;
        p = FLD(Ov014Vec, self, 0x118);
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
        if (tm % FLD(u16, self, 0x14a) == 0) {
            Ov014Actor *o;
            Ov014Game54 *g;
            Ov014Actor *e;
            desc.kind = 0x4839;
            desc.flags = 0x4839 & 0xf000;
            for (i = 0; i < 4; i++) {
                desc.unk_04[i] = 0;
            }
            desc.parent = -1;
            o = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, &p, &rot, 0xffff);
            FLD(void *, o, 0x60) = data_ov014_02216d78;
            o->unk_90 = self->unk_90;
            if (FLD(u8 *, o, 0x4c) != NULL) {
                FLD(u16, FLD(u8 *, o, 0x4c), 0x1c) = self->id;
            }
            FLD(Ov014Flags8, o, 0x16).b0 = 1;
            FLD(u16, self, 0xde) = o->id;
            FLD(u16, self, 0xde) = o != NULL ? o->id : 0xffff;
            g = data_ov000_021ccd54;
            FLD(u8, g, 0x190) |= 0x1c;
            FLD(u8, g, 0x18d) = 0x1e;
            FLD(u8, g, 0x18e) = 0x2d;
            FLD(u8, g, 0x18f) = 0x2d;
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
                    u16 id = FLD(u16, self, 0xde);
                    if (data_ov000_021ccd68 == NULL) {
                        a = NULL;
                    } else {
                        a = func_ov000_0218e640(data_ov000_021ccd68, id);
                    }
                }
                if (a == NULL) {
                    FLD(u16, self, 0xde) = 0xffff;
                    break;
                }
                a->pos = p;
                FLD(Ov014Vec16b, a, 0x7c) = rot;
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
