#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003PjVec;

typedef struct {
    u16 x, y, z;
} Ov003PjRot;

typedef struct {
    s32 m[9];
} Ov003PjMtx33;

typedef struct {
    s32 m[9];
    Ov003PjVec t;
} Ov003PjMtx43;

typedef struct {
    s16 fx;
    s16 ox;
    s16 oy;
    s16 oz;
    s16 scale;
    u8 unk_0a[0xa];
    s16 trail;
    s16 tx;
    s16 ty;
    s16 tz;
    s16 tscale;
    u16 tint;
    s16 life;
    u8 unk_22[8];
    u16 mode : 3;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 1;
    u16 b7 : 3;
    u16 b10 : 1;
} Ov003PjCfg;

typedef struct {
    u16 dur;
    s16 speed;
    s16 accel;
    s16 homing;
    s16 next;
} Ov003PjStep;

typedef struct {
    u16 state;
} Ov003PjWork;

typedef struct {
    u8 unk_00[0x30];
    u32 unk_30;
    u8 unk_34[0x66];
    union {
        u16 flags;
        struct {
            u16 b0 : 1;
        } b;
    } f9a;
} Ov003PjAnim;

typedef struct {
    u8 unk_00[0x22];
    union {
        u16 flags;
        struct {
            u16 b0 : 1;
        } b;
    } f22;
} Ov003PjS44;

typedef struct {
    u8 unk_00[2];
    u16 b0 : 3;
} Ov003PjB0;

typedef struct {
    u8 unk_00[0xe];
    u16 unk_0e;
} Ov003PjPart;

typedef struct {
    u8 unk_00[0x78];
    Ov003PjVec pos;
    s32 rot[9];
} Ov003PjModel;

typedef struct {
    u8 unk_00[0x13];
    u8 kind;
} Ov003PjPlWork;

typedef struct {
    u8 unk_00[0x40];
    Ov003PjPlWork *work;
    u8 unk_44[0x4c];
    u16 unk_90;
    u8 unk_92[0xa8c];
    u16 unk_b1e;
} Ov003PjPlayer;

class Ov003PjFx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void SetScale(s32 x, s32 y, s32 z);
    virtual void v18();
    virtual void v1c();
    virtual void SetOffset(Ov003PjVec *v);
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void SetRot(Ov003PjRot *r);
    u8 unk_04[0x20];
    void *unk_24;
};

typedef struct {
    u8 unk_00[0xc];
    u16 id;
    u8 unk_0e[0x2a];
    Ov003PjModel *model;
    u8 unk_3c[4];
    Ov003PjWork *work;
    Ov003PjS44 *unk_44;
    Ov003PjAnim *anim;
    void *unk_4c;
    u8 unk_50[0x20];
    Ov003PjVec pos;
    Ov003PjRot rot;
    u8 unk_82[2];
    Ov003PjVec dest;
    u8 unk_90[3];
    u8 unk_93_0 : 1;
    u8 unk_94[8];
    Ov003PjVec vel;
    u8 unk_a8[8];
    Ov003PjB0 *unk_b0;
    u8 unk_b4[8];
    void *fxh;
    Ov003PjVec fxofs;
    u8 unk_cc[4];
    Ov003PjCfg *cfg;
    Ov003PjStep *steps;
    u16 unk_d8;
    u16 trailTimer;
    u16 lockTimer;
    u16 stepTimer;
    s16 step;
    u8 unk_e2[2];
    s32 speed;
    Ov003PjVec local;
} Ov003Pj;

extern "C" {

extern const s16 FX_SinCosTable_[];
extern Ov003PjStep data_ov003_021f49ba[];
extern Ov003PjVec data_02092a50;
extern Ov003PjPlayer *func_ov000_0219bf90(void);
extern Ov003PjPart *func_ov000_02199ba0(void *def);
extern Ov003PjVec *func_ov000_0218d2e0(Ov003Pj *self);
extern BOOL func_ov003_021dbd80(Ov003Pj *self);
extern Ov003PjFx *func_02065f88(s32 id, Ov003PjVec *pos);
extern void func_01ffc9fc(Ov003PjVec *dst, Ov003PjVec *src, u16 ry);
extern void func_0203f324(Ov003PjAnim *a);
extern void func_ov000_021987b8(Ov003PjAnim *a, s32 b, s32 c, s32 d);
extern void VEC_Normalize(Ov003PjVec *a, Ov003PjVec *b);
extern void VEC_Add(Ov003PjVec *a, Ov003PjVec *b, Ov003PjVec *dst);
extern void VEC_MultAdd(s32 a, Ov003PjVec *v1, Ov003PjVec *v2, Ov003PjVec *dst);
extern void VEC_MultSubtract(s32 a, Ov003PjVec *v1, Ov003PjVec *v2, Ov003PjVec *dst);
extern Ov003PjMtx43 *NNS_G3dGlbGetInvV(void);
extern void MTX_Identity33_(Ov003PjMtx33 *m);
extern void MTX_RotX33_(Ov003PjMtx33 *m, s32 s, s32 c);
extern void MTX_RotY33_(Ov003PjMtx33 *m, s32 s, s32 c);
extern void MTX_RotZ33_(Ov003PjMtx33 *m, s32 s, s32 c);
extern void MTX_Concat33(Ov003PjMtx33 *a, Ov003PjMtx33 *b, Ov003PjMtx33 *out);
extern void MTX_MultVec33(Ov003PjVec *v, Ov003PjMtx33 *m, Ov003PjVec *out);
extern void MTX_Identity43_(Ov003PjMtx43 *m);
extern void MTX_RotX43_(Ov003PjMtx43 *m, s32 s, s32 c);
extern void MTX_RotY43_(Ov003PjMtx43 *m, s32 s, s32 c);
extern void MTX_RotZ43_(Ov003PjMtx43 *m, s32 s, s32 c);
extern void MTX_Concat43(Ov003PjMtx43 *a, Ov003PjMtx43 *b, Ov003PjMtx43 *out);
extern void MI_Copy36B(const void *src, void *dst);

#define OV003PJ_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003PJ_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])
#define OV003PJ_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

static inline u8 Ov003Pj_Kind(Ov003PjPlayer *pl) {
    if (pl->work != NULL) {
        return pl->work->kind;
    }
    return 0;
}

static inline s32 Ov003Pj_Sqrt(s64 v) {
    *(vu16 *)0x40002b0 = 1;
    *(volatile s64 *)0x40002b8 = v;
    while (*(vu16 *)0x40002b0 & 0x8000) {
    }
    return *(volatile s32 *)0x40002b4;
}

static inline void Ov003Pj_Show(Ov003PjAnim *a) {
    a->f9a.b.b0 = 1;
    a->f9a.flags |= 8;
    func_0203f324(a);
}

static inline void Ov003Pj_SetMtx(Ov003PjModel *o, Ov003PjMtx43 *m) {
    MI_Copy36B(m, o->rot);
    o->pos = m->t;
}

void func_ov003_021db244(Ov003Pj *self) {
    Ov003PjMtx33 m33;
    Ov003PjVec d2;
    Ov003PjVec o;
    Ov003PjVec v;
    Ov003PjVec d;
    Ov003PjMtx43 m;
    Ov003PjMtx33 t33;
    Ov003PjMtx43 t;
    Ov003PjCfg *cfg;
    Ov003PjStep *ent;
    BOOL changed;
    s32 spd;
    Ov003PjPlayer *pl;
    Ov003PjPart *part;
    u16 mode;
    Ov003PjVec *tgt;
    pl = func_ov000_0219bf90();
    part = func_ov000_02199ba0(self->unk_4c);
    switch (self->work->state) {
    case 0: {
        cfg = self->cfg;
        self->unk_d8 = 0;
        self->trailTimer = 0;
        self->stepTimer = 0;
        self->step = 0;
        self->lockTimer = 0;
        self->vel.x = 0;
        self->vel.y = 0;
        self->vel.z = 0;
        mode = cfg->mode;
        tgt = func_ov000_0218d2e0(self);
        if (part->unk_0e == 0x1000 && !self->cfg->b5) {
            s32 a;
            mode = 2;
            self->steps = data_ov003_021f49ba;
            if (tgt == NULL) {
                mode = 1;
            }
            a = self->cfg->life;
            if (a < 0) {
                a = -a;
            }
            if (a > 0x96) {
                self->unk_d8 = a - 0x96;
            }
        }
        switch (mode) {
        case 1:
            self->vel.x = OV003PJ_MUL(self->steps->speed, OV003PJ_SIN(self->rot.y));
            {
                s32 z = OV003PJ_MUL(self->steps->speed, OV003PJ_COS(self->rot.y));
                self->vel.y = 0;
                self->vel.z = z;
            }
            break;
        case 2: {
            s32 h;
            s32 dx;
            s32 dz;
            s64 sq;
            if (tgt != NULL) {
                d2 = *tgt;
            } else {
                d2 = self->dest;
            }
            d2.y -= self->pos.y;
            dz = self->pos.z - d2.z;
            dx = self->pos.x - d2.x;
            sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            h = (Ov003Pj_Sqrt(sq << 2) + 1) >> 1;
            d2.x = OV003PJ_MUL(h, OV003PJ_SIN(self->rot.y));
            d2.z = OV003PJ_MUL(h, OV003PJ_COS(self->rot.y));
            VEC_Normalize(&d2, &d2);
            {
                s32 s = self->steps->speed;
                self->vel.x = OV003PJ_MUL(d2.x, s);
                self->vel.y = OV003PJ_MUL(d2.y, s);
                self->vel.z = OV003PJ_MUL(d2.z, s);
            }
            break;
        }
        default: {
            BOOL set;
            u16 ry;
            u16 rz;
            u16 rx;
            ry = self->rot.y;
            rz = self->rot.z;
            rx = self->rot.x;
            set = FALSE;
            MTX_Identity33_(&m33);
            if (ry != 0) {
                MTX_RotY33_(&m33, OV003PJ_SIN(ry), OV003PJ_COS(ry));
                set = TRUE;
            }
            if (rx != 0) {
                if (set) {
                    MTX_RotX33_(&t33, OV003PJ_SIN(rx), OV003PJ_COS(rx));
                    MTX_Concat33(&t33, &m33, &m33);
                } else {
                    MTX_RotX33_(&m33, OV003PJ_SIN(rx), OV003PJ_COS(rx));
                    set = TRUE;
                }
            }
            if (rz != 0) {
                if (set) {
                    MTX_RotZ33_(&t33, OV003PJ_SIN(rz), OV003PJ_COS(rz));
                    MTX_Concat33(&t33, &m33, &m33);
                } else {
                    MTX_RotZ33_(&m33, OV003PJ_SIN(rz), OV003PJ_COS(rz));
                    set = TRUE;
                }
            }
            {
                s32 sp = self->steps->speed;
                self->vel.x = 0;
                self->vel.y = 0;
                self->vel.z = sp;
            }
            MTX_MultVec33(&self->vel, &m33, &self->vel);
            break;
        }
        }
        self->speed = self->steps->speed;
        if (self->cfg->fx != -1 && self->fxh == NULL) {
            Ov003PjFx *e = func_02065f88(self->cfg->fx, &self->pos);
            s32 s = self->cfg->scale << 4;
            e->SetScale(s, s, s);
            e->SetRot(&self->rot);
            self->fxh = e->unk_24;
            o.x = self->cfg->ox << 4;
            o.y = self->cfg->oy << 4;
            o.z = self->cfg->oz << 4;
            if (mode == 1 || mode == 2) {
                func_01ffc9fc(&self->fxofs, &o, self->rot.y);
            } else {
                MTX_MultVec33(&o, &m33, &self->fxofs);
            }
        }
        if (self->anim != NULL) {
            Ov003Pj_Show(self->anim);
            self->anim->f9a.flags |= 0x12;
            if ((self->cfg->b7 & 2) && tgt == NULL) {
                self->anim->unk_30 = 0xe0000000;
            }
        }
        {
            Ov003PjS44 *q = self->unk_44;
            if (q != NULL) {
                q->f22.b.b0 = 1;
                q->f22.flags |= 2;
            }
        }
        self->work->state++;
    }
    case 1: {
        if (func_ov003_021dbd80(self)) {
            return;
        }
        cfg = self->cfg;
        if (cfg->trail != -1) {
            self->trailTimer++;
            if (self->trailTimer > cfg->tint) {
                Ov003PjFx *e;
                s32 s;
                self->trailTimer = 0;
                e = func_02065f88(cfg->trail, &self->pos);
                cfg = self->cfg;
                v.x = cfg->tx << 4;
                v.y = cfg->ty << 4;
                v.z = cfg->tz << 4;
                func_01ffc9fc(&v, &v, self->rot.y);
                e->SetOffset(&v);
                s = self->cfg->tscale << 4;
                e->SetScale(s, s, s);
                e->SetRot(&self->rot);
            }
        }
        ent = &self->steps[self->step];
        changed = FALSE;
        if (ent->dur != 0 && ent->next >= 0) {
            self->stepTimer++;
            if (self->stepTimer >= ent->dur) {
                self->stepTimer = 0;
                changed = TRUE;
                {
                    s16 n = ent->next;
                    ent = &self->steps[n];
                    self->step = n;
                }
            }
        }
        if (ent->accel != 0) {
            changed = TRUE;
            self->speed += OV003PJ_MUL(ent->accel, ent->speed - self->speed);
        }
        spd = self->speed;
        if (self->cfg->b3) {
            if (pl != NULL && (pl->unk_b1e == self->id || (Ov003Pj_Kind(pl) == 0x18 && pl->unk_90 == self->id))) {
                self->lockTimer++;
                if (self->lockTimer >= 0x5a) {
                    self->lockTimer = 0x5a;
                } else {
                    spd = (s32)(((s64)spd * 0xcd + 0x800) >> 12);
                    changed = TRUE;
                }
            } else {
                self->lockTimer = 0;
            }
        }
        if (changed) {
            VEC_Normalize(&self->vel, &self->vel);
            self->vel.x = OV003PJ_MUL(self->vel.x, spd);
            self->vel.y = OV003PJ_MUL(self->vel.y, spd);
            self->vel.z = OV003PJ_MUL(self->vel.z, spd);
        }
        if (ent->homing != 0) {
            tgt = func_ov000_0218d2e0(self);
            if (tgt != NULL) {
                d = *tgt;
            } else {
                d = self->dest;
            }
            d.x -= self->pos.x;
            d.y -= self->pos.y;
            d.z -= self->pos.z;
            VEC_Normalize(&d, &d);
            VEC_MultSubtract(spd, &d, &self->vel, &d);
            VEC_MultAdd(ent->homing, &d, &self->vel, &self->vel);
        }
        if (self->cfg->b10) {
            Ov003PjMtx43 *iv;
            s32 x;
            s32 y;
            s32 z;
            VEC_Add(&self->local, &self->vel, &self->local);
            iv = NNS_G3dGlbGetInvV();
            y = self->local.y;
            x = self->local.x;
            z = self->local.z;
            self->pos.x = (s32)(((s64)x * iv->m[0] + (s64)y * iv->m[3] + (s64)z * iv->m[6]) >> 12);
            self->pos.y = (s32)(((s64)x * iv->m[1] + (s64)y * iv->m[4] + (s64)z * iv->m[7]) >> 12);
            self->pos.z = (s32)(((s64)x * iv->m[2] + (s64)y * iv->m[5] + (s64)z * iv->m[8]) >> 12);
            VEC_Add(&self->pos, &data_02092a50, &self->pos);
            {
                BOOL set;
                u16 rz;
                u16 ry;
                u16 rx;
                rz = self->rot.z;
                ry = self->rot.y;
                rx = self->rot.x;
                set = FALSE;
                MTX_Identity43_(&m);
                if (rz != 0) {
                    MTX_RotZ43_(&m, OV003PJ_SIN(rz), OV003PJ_COS(rz));
                    set = TRUE;
                }
                if (ry != 0) {
                    if (set) {
                        MTX_RotY43_(&t, OV003PJ_SIN(ry), OV003PJ_COS(ry));
                        MTX_Concat43(&t, &m, &m);
                    } else {
                        MTX_RotY43_(&m, OV003PJ_SIN(ry), OV003PJ_COS(ry));
                        set = TRUE;
                    }
                }
                if (rx != 0) {
                    if (set) {
                        MTX_RotX43_(&t, OV003PJ_SIN(rx), OV003PJ_COS(rx));
                        MTX_Concat43(&t, &m, &m);
                    } else {
                        MTX_RotX43_(&m, OV003PJ_SIN(rx), OV003PJ_COS(rx));
                        set = TRUE;
                    }
                }
            }
            MTX_Concat43(&m, NNS_G3dGlbGetInvV(), &m);
            m.t = self->pos;
            Ov003Pj_SetMtx(self->model, &m);
            self->unk_93_0 = 1;
        } else {
            VEC_Add(&self->pos, &self->vel, &self->pos);
        }
        if (self->anim == NULL) {
            return;
        }
        if (!(self->unk_b0->b0 & 2)) {
            Ov003Pj_Show(self->anim);
        }
        func_ov000_021987b8(self->anim, 0, 0, 0);
        break;
    }
    }
}

}
