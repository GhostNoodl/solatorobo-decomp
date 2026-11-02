#include "types.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ActorParts.h"
#include "ov003/ActEx.h"
#include "ov003/ActorApi.h"

typedef struct {
    VecFx32 pos;
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
} Ov003BrQuery;

typedef struct {
    Ov003BrQuery *q;
} Ov003BrFinder;

typedef struct {
    VecFx32 pos;
    u8 unk_0c[4];
    s32 unk_10;
} Ov003BrHit;

typedef struct {
    VecFx32 pos;
    u16 rot[3];
    s32 unk_14;
} Ov003BrWarp;

extern "C" {

extern const s16 FX_SinCosTable_[];
extern char data_ov003_021f9fd6[];
extern s32 func_ov000_021993fc(Ov003BrFinder *f, Ov003BrQuery *q, Ov003BrHit **out, s32 max);
extern Actor *func_ov000_021985c0(Ov003BrHit *h);
extern BOOL func_ov003_021f0a38(Actor *t, void *def);
extern BOOL func_ov000_02190cb0(void *p, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *p);
extern void func_ov000_021911c8(void *p, s32 a);
extern void func_ov000_0218996c(u8 a, u8 b);
extern void Actor_SendMsg(Actor *o, u16 id, s32 a, s32 b, s32 c, void *p);
extern Actor *func_ov000_0219bf90(void);
extern void HitMesh_SetMtx(void *o, MtxFx43 *m);
extern BOOL func_ov000_021b4738(void);
extern void func_020627b4(void);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_020627ec(u16 a);
extern void func_ov000_02182590(void *p);

#define OV003BR_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003BR_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

static inline void Ov003BrQuery_Init(Ov003BrQuery *q) {
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

static inline void Ov003Br_SetMtx(void *o, s32 x, s32 y, s32 z, u16 rx, u16 ry, u16 rz) {
    MtxFx43 m;
    MtxFx43 t;
    BOOL set = FALSE;
    MTX_Identity43_(&m);
    if (rz != 0) {
        MTX_RotZ43_(&m, OV003BR_SIN(rz), OV003BR_COS(rz));
        set = TRUE;
    }
    if (ry != 0) {
        if (set) {
            MTX_RotY43_(&t, OV003BR_SIN(ry), OV003BR_COS(ry));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotY43_(&m, OV003BR_SIN(ry), OV003BR_COS(ry));
            set = TRUE;
        }
    }
    if (rx != 0) {
        if (set) {
            MTX_RotX43_(&t, OV003BR_SIN(rx), OV003BR_COS(rx));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotX43_(&m, OV003BR_SIN(rx), OV003BR_COS(rx));
            set = TRUE;
        }
    }
    m._30 = x;
    m._31 = y;
    m._32 = z;
    HitMesh_SetMtx(o, &m);
}

static inline void Ov003Br_Approach(Ov003BrWarp *w, Actor *t, Ov003Bridge *self) {
    VecFx32 d;
    w->pos.x = t->pos.x;
    w->pos.y = t->pos.y;
    w->pos.z = t->pos.z;
    w->pos.y += self->unk_1c << 4;
    d.x = self->pos.x - w->pos.x;
    d.y = self->pos.y - w->pos.y;
    d.z = self->pos.z - w->pos.z;
    VEC_MultAdd(0x59a, &d, &w->pos, &w->pos);
    w->rot[0] = t->rot_x;
    w->rot[1] = t->rot_y;
    w->rot[2] = t->rot_z;
}

void func_ov003_021eeecc(Ov003Bridge *self) {
    switch (self->fsm->st) {
    case 0: {
        Ov003BrHit *list[0x20];
        Ov003BrQuery q;
        VecFx32 v;
        Ov003BrFinder f;
        u8 b;
        s32 n;
        Actor *found = NULL;
        s32 i;
        Actor *pl;
        Ov003BrQuery_Init(&q);
        q.pos.x = self->pos.x;
        q.pos.y = self->pos.y;
        q.pos.z = self->pos.z;
        q.unk_0c = 0;
        q.unk_28 = self->id;
        q.unk_1c = self->radius + 0x400;
        q.unk_18 = 0;
        q.unk_20 = 0;
        q.unk_24 = 0x2800;
        q.b.f_1 = 1;
        q.b.f_2 = 1;
        q.b.f_3 = 1;
        q.mask = 0x10;
        q.unk_10 = 0xffff;
        f.q = NULL;
        n = func_ov000_021993fc(&f, &q, list, 0x20);
        for (i = 0; i < n; i++) {
            Ov003BrHit *h = list[i];
            if (h != NULL && h->pos.y - h->unk_10 - self->pos.y - self->height <= 0x666) {
                Actor *o = func_ov000_021985c0(h);
                if (o != NULL && self->targetObj != NULL && func_ov003_021f0a38(o, self->targetObj)) {
                    found = o;
                    break;
                }
            }
        }
        if (found == NULL) {
            return;
        }
        self->target = found->id;
        if (self->model != NULL) {
            func_ov000_02190cb0(self->model, data_ov003_021f9fd6, 0x111, 0);
            func_ov000_021915a0(self->model);
            func_ov000_021911c8(self->model, 0x4cd);
        }
        func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
        func_ov000_0218996c(5, 10);
        b = 0;
        Actor_SendMsg(found, self->id, 0xd, 1, 1, &b);
        pl = func_ov000_0219bf90();
        if (pl != NULL) {
            v.x = pl->pos.x;
            v.y = pl->pos.y;
            v.z = pl->pos.z;
            func_02065f88(0x44f, &v)->AddPosXYZ(0, pl->height, 0);
            func_02049a48(data_02097e4c, 0x4a, -1, -1, -1);
        }
        self->fsm->st++;
        self->fsm->timer = 0;
        break;
    }
    case 1: {
        ActorSub40 *w = self->fsm;
        Actor *t;
        w->timer++;
        if (w->timer >= 0xf) {
            self->unk_cc_0 = 0;
            self->fsm->timer = 0;
            t = Actor_GetTarget(self);
            if (t != NULL) {
                Ov003BrWarp wp;
                s16 mode;
                wp.pos.x = self->pos.x;
                wp.pos.y = self->pos.y;
                wp.pos.z = self->pos.z;
                wp.pos.y = self->pos.y + (self->unk_1c << 4);
                wp.rot[0] = t->rot_x;
                wp.rot[1] = t->rot_y;
                wp.rot[2] = t->rot_z;
                wp.unk_14 = 0;
                Actor_SendMsg(t, self->id, 7, 1, 0x18, &wp);
                func_ov000_02197d80(self);
                mode = 1;
                if (self->unk_18 == 0) {
                    if (self->unk_1a == 0) {
                        if (t->unk_1a != 0) {
                            mode = 2;
                        }
                    } else if (t->unk_1a == 0) {
                        mode = 3;
                    } else {
                        mode = 4;
                    }
                } else if (self->unk_1a == 0) {
                    if (t->unk_1a == 0) {
                        mode = 5;
                    } else {
                        mode = 6;
                    }
                } else {
                    mode = 6;
                    if (t->unk_1a != 0) {
                        mode = 5;
                    }
                }
                self->unk_18 = mode;
                func_ov000_02197dec(self, mode, -1);
            }
            self->unk_93_1 = 1;
            if (self->hitMesh != NULL) {
                func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
                func_ov000_0218996c(5, 10);
            }
            self->fsm->st = 10;
            return;
        }
        if (self->hitMesh != NULL) {
            VecFx32 p;
            p.x = self->pos.x;
            p.y = self->pos.y - self->fsm->timer * 0xcd;
            p.z = self->pos.z;
            Ov003Br_SetMtx(self->hitMesh, p.x, p.y, p.z, self->rot_x, self->rot_y, self->rot_z);

        }
        t = Actor_GetTarget(self);
        if (t != NULL) {
            Ov003BrWarp wp;
            Ov003Br_Approach(&wp, t, self);
            wp.unk_14 = 0;
            Actor_SendMsg(t, self->id, 7, 1, 0x18, &wp);
        }
        break;
    }
    case 10:
        if (func_ov000_0219bf90() != NULL && !func_ov000_021b4738()) {
            u16 id = 0;
            Actor *t = Actor_GetTarget(self);
            if (t != NULL) {
                id = t->kind;
            }
            func_020627b4();
            func_020627a0(self->kind, self->id);
            func_020627dc(1);
            func_020627ec(id);
            {
                u8 *ac = &data_ov000_021ccd54->stageFlags;
                *ac = 1;
                func_ov000_02182590(ac);
            }
        }
        self->fsm->st++;
        break;
    }
}

}
