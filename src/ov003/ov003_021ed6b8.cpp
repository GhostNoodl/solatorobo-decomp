#include "types.h"

struct Ov003Vec {
    s32 x;
    s32 y;
    s32 z;
};

struct Ov003Work {
    u16 state;
    u16 timer;
};

typedef struct {
    s32 m[9];
    s32 tx, ty, tz;
} Ov003LfMtx;

typedef struct {
    Ov003Vec pos;
    u16 unk_0c;
    u16 mask;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    u16 unk_28;
    union { u8 flags; struct { u8 f_0 : 1; u8 f_1 : 1; u8 f_2 : 1; u8 f_3 : 1; } b; };
} Ov003LfQuery;

typedef struct {
    Ov003LfQuery *q;
} Ov003LfFinder;

typedef struct {
    Ov003Vec pos;
    u8 unk_0c[4];
    s32 unk_10;
} Ov003LfHit;

typedef struct {
    u8 unk_00;
    u8 type;
} Ov003LfCfg;

typedef struct {
    u8 unk_00[0x13];
    u8 kind;
} Ov003LfRide;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
} Ov003LfBits;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0x30];
    Ov003LfRide *ride;
    u8 unk_44[8];
    Ov003LfCfg *cfg;
    u8 unk_50[0x14];
    s32 unk_64;
    s32 unk_68;
    u8 unk_6c[4];
    Ov003Vec pos;
    u16 rot[3];
    u8 unk_82[0x1a];
    s32 unk_9c;
    u8 unk_a0[0x6bc];
    Ov003Vec pos2;
    u8 unk_768[0x3bc];
    Ov003LfBits bits;
} Ov003LfTgt;

typedef struct {
    Ov003Vec pos;
    u16 rot[3];
    s32 unk_14;
} Ov003LfWarp;

class Ov003LfFx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void SetScale(s32 x, s32 y, s32 z);
};

typedef struct {
    u8 unk_00[0xac];
    u8 unk_ac;
} Ov003LfGame;

struct Ov003Lift {
    void *vtbl;
    u8 unk_04[8];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[8];
    u16 kind;
    s16 mode;
    s16 height;
    u8 unk_1e[0x1a];
    void *model;
    u8 unk_3c[4];
    Ov003Work *work;
    u8 unk_44[8];
    void *unk_4c;
    u8 unk_50[8];
    void *unk_58;
    u8 unk_5c[8];
    s32 unk_64;
    s32 unk_68;
    s32 unk_6c;
    Ov003Vec pos;
    u16 rot[3];
    u8 unk_82[0xe];
    u16 unk_90;
    u8 unk_92;
    u8 unk_93_0 : 1;
    u8 state : 3;
    u8 unk_94[0x1c];
    Ov003LfCfg *cfg;
    u8 unk_b4[0x18];
    u16 unk_cc_0 : 1;
    u16 unk_ce;
};

extern "C" {

extern const s16 FX_SinCosTable_[];
extern void *data_02097e4c;
extern Ov003LfGame *data_ov000_021ccd54;
extern char data_ov003_021f9fd0[];
extern char data_ov003_021f9fd6[];
extern s32 func_ov000_021993fc(Ov003LfFinder *f, Ov003LfQuery *q, Ov003LfHit **out, s32 max);
extern Ov003LfTgt *func_ov000_021985c0(Ov003LfHit *h);
extern BOOL func_ov003_021f0a38(Ov003LfTgt *t, void *def);
extern BOOL func_ov000_02199d40(void *t);
extern BOOL func_01ffc584(const Ov003Vec *a, const Ov003Vec *b, s32 r, s32 h);
extern BOOL func_ov000_02190cb0(void *p, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *p);
extern void func_ov000_021911c8(void *p, s32 a);
extern void *func_ov000_02191318(void *p, s32 a);
extern void *func_02049f44(void *mgr, s32 id, Ov003Vec *pos, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov000_0218d398(Ov003LfTgt *o, u16 id, s32 a, s32 b, s32 c, void *p);
extern Ov003LfTgt *func_ov000_0219bf90(void);
extern Ov003LfFx *func_02065f88(s32 id, Ov003Vec *pos);
extern void *func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern Ov003LfTgt *func_ov000_0218d240(Ov003Lift *self);
extern void MTX_Identity43_(Ov003LfMtx *m);
extern void MTX_RotX43_(Ov003LfMtx *m, s32 s, s32 c);
extern void MTX_RotY43_(Ov003LfMtx *m, s32 s, s32 c);
extern void MTX_RotZ43_(Ov003LfMtx *m, s32 s, s32 c);
extern void MTX_Concat43(Ov003LfMtx *a, Ov003LfMtx *b, Ov003LfMtx *out);
extern void func_0203f9dc(void *o, Ov003LfMtx *m);
extern void VEC_MultAdd(s32 a, Ov003Vec *v1, Ov003Vec *v2, Ov003Vec *dst);
extern s32 VEC_Distance(const Ov003Vec *a, const Ov003Vec *b);
extern BOOL func_ov000_021b4738(void);
extern void func_020627b4(void);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_020627ec(u16 a);
extern void func_ov000_02182590(void *p);

#define OV003LF_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003LF_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

static inline void Ov003LfQuery_Init(Ov003LfQuery *q) {
    q->mask = 0;
    q->unk_10 = 0xffff;
    q->unk_12 = 0;
    q->unk_14 = 0;
    q->unk_18 = 0;
    q->unk_1c = 0;
    q->unk_20 = 0;
    q->unk_24 = 0;
    q->unk_28 = 0xffff;
    q->flags = 0;
}

static inline void Ov003Lf_SetMtx(void *o, const Ov003Vec *p, u16 rx, u16 ry, u16 rz) {
    Ov003LfMtx m;
    Ov003LfMtx t;
    BOOL set = FALSE;
    MTX_Identity43_(&m);
    if (rz != 0) {
        MTX_RotZ43_(&m, OV003LF_SIN(rz), OV003LF_COS(rz));
        set = TRUE;
    }
    if (ry != 0) {
        if (set) {
            MTX_RotY43_(&t, OV003LF_SIN(ry), OV003LF_COS(ry));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotY43_(&m, OV003LF_SIN(ry), OV003LF_COS(ry));
            set = TRUE;
        }
    }
    if (rx != 0) {
        if (set) {
            MTX_RotX43_(&t, OV003LF_SIN(rx), OV003LF_COS(rx));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotX43_(&m, OV003LF_SIN(rx), OV003LF_COS(rx));
            set = TRUE;
        }
    }
    m.tx = p->x;
    m.ty = p->y;
    m.tz = p->z;
    func_0203f9dc(o, &m);
}

static inline BOOL Ov003Lf_Flag(Ov003LfTgt *p) {
    return p->bits.b1 ? TRUE : FALSE;
}

static inline s32 Ov003Lf_RideKind(Ov003LfTgt *p) {
    return p->ride != NULL ? p->ride->kind : 0;
}

static inline void Ov003Lf_Notify(Ov003Lift *self, Ov003LfTgt *t) {
    if (func_ov000_0219bf90() != NULL && !func_ov000_021b4738()) {
        u16 id = 0;
        if (t != NULL) {
            id = t->unk_0e;
        }
        func_020627b4();
        func_020627a0(self->unk_0e, self->unk_0c);
        func_020627dc(self->kind);
        func_020627ec(id);
        {
            u8 *ac = &data_ov000_021ccd54->unk_ac;
            *ac = 1;
            func_ov000_02182590(ac);
        }
    }
}

static inline void Ov003Lf_Sound(Ov003Lift *self) {
    if (VEC_Distance(&self->pos, &func_ov000_0219bf90()->pos) <= 0x3800) {
        func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
        func_ov000_0218996c(5, 10);
    }
}

static inline void Ov003Lf_Approach(Ov003LfWarp *w, Ov003LfTgt *t, Ov003Lift *self) {
    Ov003Vec d;
    w->pos.x = t->pos.x;
    w->pos.y = t->pos.y;
    w->pos.z = t->pos.z;
    d.x = self->pos.x - w->pos.x;
    d.y = self->pos.y - w->pos.y;
    d.z = self->pos.z - w->pos.z;
    VEC_MultAdd(0xc00, &d, &w->pos, &w->pos);
    w->rot[0] = t->rot[0];
    w->rot[1] = t->rot[1];
    w->rot[2] = t->rot[2];
}

void func_ov003_021ed6b8(Ov003Lift *self) {
    switch (self->work->state) {
    case 0: {
        Ov003LfQuery q;
        Ov003LfFinder f;
        u8 flag;
        Ov003LfHit *list[0x20];
        s32 n;
        s32 res;
        Ov003LfTgt *found;
        s32 i;
        u8 cnt;
        Ov003Work *w = self->work;
        if (w->timer != 0) {
            w->timer--;
        }
        flag = FALSE;
        Ov003LfQuery_Init(&q);
        q.pos.x = self->pos.x;
        q.pos.y = self->pos.y;
        q.pos.z = self->pos.z;
        q.unk_0c = 0;
        q.unk_28 = self->unk_0c;
        {
            s32 r = self->unk_64 + 0x400;
            q.unk_18 = 0;
            q.unk_1c = r;
        }
        q.unk_20 = 0;
        q.unk_24 = 0x2800;
        q.b.f_1 = 1;
        q.b.f_2 = 1;
        q.b.f_3 = 1;
        q.mask = 0x10;
        q.unk_10 = 0xffff;
        f.q = NULL;
        n = func_ov000_021993fc(&f, &q, list, 0x20);
        res = 0;
        cnt = 0;
        found = NULL;
        for (i = 0; i < n; i++) {
            Ov003LfHit *h = list[i];
            Ov003LfTgt *o;
            if (h == NULL) {
                continue;
            }
            if (h->pos.y - h->unk_10 - self->pos.y - self->unk_68 > 0x666) {
                continue;
            }
            o = func_ov000_021985c0(h);
            if (o == NULL) {
                continue;
            }
            if (self->unk_4c != NULL && !func_ov003_021f0a38(o, self->unk_4c)) {
                continue;
            }
            if ((u16)(o->unk_0c & 0xf000) == 0x4000) {
                Ov003LfCfg *c = o->cfg;
                if (c != NULL && c->type != 2 && c->type != 6) {
                    continue;
                }
            }
            {
                Ov003LfWarp wp;
                wp.pos.x = o->pos.x;
                wp.pos.y = o->pos.y;
                wp.pos.z = o->pos.z;
                wp.rot[0] = o->rot[0];
                wp.rot[1] = o->rot[1];
                wp.rot[2] = o->rot[2];
                wp.unk_14 = 0x52;
                func_ov000_0218d398(o, self->unk_0c, 7, 1, 0x18, &wp);
            }
            if (res == 0) {
                res = 1;
                found = o;
            } else if (self->unk_90 == o->unk_0c) {
                found = o;
            }
            cnt++;
        }
        if (res == 0 && found == NULL) {
            if (self->unk_4c == NULL || !func_ov000_02199d40(self->unk_4c)) {
                Ov003LfTgt *pl = func_ov000_0219bf90();
                if (!Ov003Lf_Flag(pl) || Ov003Lf_RideKind(pl) == 1 || Ov003Lf_RideKind(pl) == 2 || pl->unk_9c == 0) {
                    Ov003Vec p;
                    p.x = pl->pos2.x;
                    p.y = pl->pos2.y;
                    p.z = pl->pos2.z;
                    p.y += 0x333;
                    if (func_01ffc584(&p, &self->pos, self->unk_64 + pl->unk_64 + 0x400, 0x999)) {
                        found = pl;
                        res = 1;
                    }
                }
            }
        }
        if (res != 0 && found != NULL) {
            if (self->unk_90 != 0xffff && self->unk_90 != found->unk_0c) {
                res = 2;
            }
            if (self->mode > 0) {
                if (self->unk_ce < cnt) {
                    if (self->work->timer == 0) {
                        flag = TRUE;
                    }
                }
                if (self->mode > cnt) {
                    res = 0;
                }
            } else if (self->work->timer == 0) {
                if (cnt != 0 && self->state != res) {
                    flag = TRUE;
                }
            }
        }
        self->unk_ce = cnt;
        if (self->state != res) {
            char *name;
            s32 frame;
            if (self->state == 1 && res == 2) {
                if (func_ov000_0219bf90() != NULL && !func_ov000_021b4738()) {
                    func_020627b4();
                    func_020627a0(self->unk_0e, self->unk_0c);
                    func_020627dc(0);
                    func_020627ec(0);
                    {
                        u8 *ac = &data_ov000_021ccd54->unk_ac;
                        *ac = 1;
                        func_ov000_02182590(ac);
                    }
                }
            }
            frame = 0x111;
            if (res != 0) {
                name = data_ov003_021f9fd6;
                if (self->work->timer != 0) {
                    frame = 0x1000;
                    self->unk_cc_0 = 0;
                }
                self->kind = 1;
                self->unk_90 = 0xffff;
                if (found != NULL) {
                    self->unk_90 = found->unk_0c;
                }
            } else {
                void *mesh = self->unk_58;
                self->unk_cc_0 = 1;
                name = data_ov003_021f9fd0;
                if (mesh != NULL) {
                    Ov003Lf_SetMtx(mesh, &self->pos, self->rot[0], self->rot[1], self->rot[2]);
                }
                self->kind = 0;
                self->unk_90 = 0xffff;
            }
            if (self->model != NULL && name != NULL) {
                func_ov000_02190cb0(self->model, name, frame, 0);
                func_ov000_021915a0(self->model);
                func_ov000_021911c8(self->model, 0x4cd);
                if (frame == 0x1000) {
                    func_ov000_02191318(self->model, -1);
                }
            }
            if (self->cfg->type == 0 || res == 0 || self->work->timer != 0) {
                self->state = res;
                Ov003Lf_Notify(self, found);
            }
            if (res != 0) {
                self->work->state++;
                self->work->timer = 0;
                if (self->cfg->type == 1) {
                    Ov003Lf_Sound(self);
                }
            }
        }
        if (!flag) {
            return;
        }
        func_02049f44(data_02097e4c, 0x18, &self->pos, 0);
        {
            Ov003Vec v;
            Ov003LfTgt *pl = func_ov000_0219bf90();
            if (pl == NULL) {
                return;
            }
            v.x = pl->pos.x;
            v.y = pl->pos.y;
            v.z = pl->pos.z;
            func_02065f88(0x44f, &v)->SetScale(0, pl->unk_68, 0);
            func_02049a48(data_02097e4c, 0x4a, -1, -1, -1);
        }
        return;
    }
    case 1: {
        Ov003Work *w;
        Ov003LfTgt *t;
        if (self->state == 2) {
            self->state = 1;
        }
        w = self->work;
        w->timer++;
        if (w->timer >= 0xf) {
            self->unk_cc_0 = 0;
            self->work->timer = 0;
            if (self->cfg->type == 1) {
                t = func_ov000_0218d240(self);
                if (t != NULL) {
                    Ov003LfWarp wp;
                    wp.pos.x = self->pos.x;
                    wp.pos.y = self->pos.y;
                    wp.pos.z = self->pos.z;
                    wp.rot[0] = t->rot[0];
                    wp.rot[1] = t->rot[1];
                    wp.rot[2] = t->rot[2];
                    wp.unk_14 = 0;
                    func_ov000_0218d398(t, self->unk_0c, 7, 1, 0x18, &wp);
                }
                if (self->state == 0) {
                    Ov003Lf_Notify(self, t);
                    self->state = 1;
                    if (self->unk_58 != NULL) {
                        Ov003Lf_Sound(self);
                    }
                }
                self->work->state--;
                return;
            }
            self->work->state--;
            return;
        }
        if (self->unk_58 != NULL) {
            Ov003Vec p;
            p.x = self->pos.x;
            p.y = self->pos.y - self->work->timer * 0xcd;
            p.z = self->pos.z;
            Ov003Lf_SetMtx(self->unk_58, &p, self->rot[0], self->rot[1], self->rot[2]);
        }
        if (self->cfg->type != 1) {
            return;
        }
        t = func_ov000_0218d240(self);
        if (t == NULL) {
            return;
        }
        {
            Ov003LfWarp wp;
            Ov003Lf_Approach(&wp, t, self);
            wp.unk_14 = 0;
            func_ov000_0218d398(t, self->unk_0c, 7, 1, 0x18, &wp);
        }
        break;
    }
    }
}

}
