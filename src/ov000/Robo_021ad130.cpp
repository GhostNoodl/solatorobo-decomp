#include "ov000/LoCommon.h"
#include "Main/Res/StageCmd.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"

typedef struct {
    u16 state;
    u16 timer;
} St021ad130;

typedef struct {
    s32 w[3];
} Ids021ad130;

typedef struct {
    u16 v[3];
} Ids16_021ad130;

extern "C" {
extern u8 data_ov000_021cc6de[];
extern u8 data_ov000_021cc5e3[];
extern u8 data_ov000_021cc618[];
extern void *data_02097e4c;
extern const u8 data_ov000_021c9fe8[3];
extern const u8 data_ov000_021c9feb[3];
extern const u8 data_ov000_021c9fee[3];
extern const Ids16_021ad130 data_ov000_021c9ff2;
const u8 data_ov000_021c9fee[3] = {0x11, 0, 0};
const u8 data_ov000_021c9feb[3] = {0x11, 0, 2};
const u8 data_ov000_021c9fe8[3] = {0x11, 0, 0};
const Ids16_021ad130 data_ov000_021c9ff2 = {{0x127, 0x310, 0}};
extern Ids021ad130 data_ov000_021ca018;
BOOL Model0218fe1c_SetAnim(void *a, void *b, s32 c, s32 d);
u8 func_0206d204(void *p, s32 a);
void NNSi_G3dModifyPolygonAttrMask(void *mdl, s32 on, u32 mask);
u8 *Spawn_ScatterEffect(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, s32 d);
s32 Rand_UpTo(s32 max);
void *SndMgr_PlayAt(void *a, s32 b, void *c, s32 d);
void *SndMgr_PlayAtPitch(void *a, s32 b, void *c, s32 d);
void func_ov000_0218996c(s32 a, s32 b);
void func_02062410(void);
void func_ov000_02182590(void *p);
BOOL func_0205b29c(u16 *ids);
void func_ov000_02186dbc(void *g);
void func_ov000_021899d8(void *pos, s32 a, s32 b, s32 c, s32 d, s32 e);
BOOL Model0218fe1c_IsAnimDone(void *a);
BOOL History_SetState(void *st, s32 a, s32 b);
void Body_Update(void *a, s32 b, s32 c, s32 d);

static inline void Fx021ad130(Robo021ca458 *self) {
    VecFx32 v;
    v = *(VecFx32 *)((u8 *)self + 0x70);
    v.y += self->height;
    func_ov000_021899d8(&v, 0, 0x8ccd, 1, 0x1000, 0x1000);
}

static inline BOOL QHas021ad130(const s32 *w) {
    FieldState *q = data_ov000_021ccd54;
    s32 i;
    for (i = q->head; i != q->tail;) {
        const s32 *p = w;
        while (*p != 0) {
            if (*p++ == ((s32 *)((u8 *)q + 0x10))[i]) {
                return TRUE;
            }
        }
        if (++i >= 0x10) {
            i = 0;
        }
    }
    return FALSE;
}

static inline void Spawn021ad130(Robo021ca458 *self, s32 id, s32 scale) {
    EffectObj *e = Effect_SpawnId(id, &self->pos);
    if (e != NULL) {
        e->SetScaleAll(scale);
        e->speed = 0xb33;
        if (self->unk_b22_6 == 5) {
            e->AddPosXYZ(0, 0x1800, 0);
            e->SetScaleAll(0x3000);
        }
    }
}

void func_ov000_021ad130(Robo021ca458 *self) {
    switch (((St021ad130 *)self->fsm)->state) {
    case 0: {
        s32 r;
        Model0218fe1c_SetAnim(self->model, data_ov000_021cc6de, 0x400, 0);
        r = func_0206d204(data_0214a424, 1);
        if (r != 0) {
            u8 *p;
            ((St021ad130 *)self->fsm)->state = 10;
            p = ((u8 *)self->hp);
            LFLD(u16, p, 0) = (s32)(r * LFLD(u16, p, 2)) / 100;
            Effect_SpawnId(0xcb, &self->pos)->SetScaleXYZ(0x99a, 0x1800, 0x99a);
            break;
        }
        if (self->unk_b24_1) {
            ((St021ad130 *)self->fsm)->timer = 0;
        } else {
            ((St021ad130 *)self->fsm)->timer = 0xd2;
        }
        if (self->unk_b32 < 0xa0) {
            self->unk_b32 = 0xa0;
        }
        {
            Model0218fe1c *m = self->model;
            m->cull = 2;
            NNSi_G3dModifyPolygonAttrMask(m->mdl, 0, 0xc0);
        }
    next:
        ((St021ad130 *)self->fsm)->state++;
        break;
    }
    case 1: {
        if (self->unk_b24_1) {
            u16 t = ((St021ad130 *)self->fsm)->timer;
            if (t <= 0xfa) {
                if (t % 25 == 0) {
                    s32 a = -1;
                    s32 b = 0;
                    VecFx32 pos;
                    VecFx32 ext;
                    u8 *hit;
                    switch (t % 100) {
                    case 0:
                        a = 0x322;
                        b = 100;
                        break;
                    case 0x32:
                        a = 6;
                        b = 0x4b;
                        break;
                    }
                    pos = *(VecFx32 *)((u8 *)self + 0x70);
                    pos.y += self->centerY;
                    ext.x = self->radius;
                    ext.y = self->height >> 2;
                    ext.z = self->radius;
                    hit = Spawn_ScatterEffect(&pos, &ext, 0x400, 0x666, a, b);
                    if (hit != NULL) {
                        s32 k = LFLD(s32, hit, 0x20);
                        if (k != 4) {
                            if (k == 0x322) {
                                SndMgr_PlayAt(data_02097e4c, Rand_UpTo(2) + 0x78, (u8 *)self + 0x70, 0);
                            }
                        } else {
                            SndMgr_PlayAtPitch(data_02097e4c, 0x35, (u8 *)self + 0x70, 8);
                        }
                    }
                }
            } else if (t == 0x118) {
                EffectObj *e = Effect_SpawnId(5, &self->pos);
                if (e != NULL) {
                    e->SetScaleAll(0x2800);
                    e->speed = 0x800;
                    if (self->unk_b22_6 == 5) {
                        e->AddPosXYZ(0, 0x1800, 0);
                        e->SetScaleAll(0x3000);
                    }
                }
                e = Effect_SpawnId(0x66, &self->pos);
                if (e != NULL) {
                    e->SetScaleAll(0x28cd);
                    e->speed = 0xb33;
                    if (self->unk_b22_6 == 5) {
                        e->AddPosXYZ(0, 0x1800, 0);
                        e->SetScaleAll(0x3000);
                    }
                }
                SndMgr_PlayAtPitch(data_02097e4c, 0x56, (u8 *)self + 0x70, -5);
                func_ov000_0218996c(0x14, 0x3c);
                self->model->visible = 0;
                self->unk_3c->unk_19 = 0;
            }
        }
        if (((St021ad130 *)self->fsm)->timer == 300) {
            func_02062410();
            {
                FieldState *g = data_ov000_021ccd54;
                g->stageFlags = 1;
                func_ov000_02182590((u8 *)g + 0xac);
            }
            {
                Ids021ad130 ids = data_ov000_021ca018;
                Ids16_021ad130 ids16 = data_ov000_021c9ff2;
                if (!QHas021ad130(ids.w) && !func_0205b29c(ids16.v)) {
                    func_ov000_02186dbc(data_ov000_021ccd54);
                }
            }
            ((St021ad130 *)self->fsm)->state++;
        }
        if (((St021ad130 *)self->fsm)->timer <= 0x11d) {
            Fx021ad130(self);
        }
        ((St021ad130 *)self->fsm)->timer++;
        break;
    }
    case 10:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            St021ad130 *st = (St021ad130 *)self->fsm;
            st->timer++;
            if (st->timer > 0x3c) {
                EffectObj *e = Effect_SpawnId(0xc9, &self->pos);
                s32 sc = 0x4800;
                self->unk_b44 = e->id;
                if (self->unk_b22_6 == 5) {
                    sc = 0x8000;
                }
                e->SetScaleAll(sc);
                self->unk_44->unk_22_1 = 0;
                ((St021ad130 *)self->fsm)->timer = 0;
                goto next;
            }
        }
        break;
    case 11: {
        St021ad130 *st = (St021ad130 *)self->fsm;
        st->timer++;
        if (st->timer > 0x14) {
            u8 *anm;
            Effect_SpawnId(0x190, &self->pos);
            anm = data_ov000_021cc5e3;
            if (!self->unk_b24_1 && (self->hit->unk_50 & 0x400)) {
                anm = data_ov000_021cc618;
            }
            Model0218fe1c_SetAnim(self->model, anm, 0x400, 0);
            self->hpObj->unk_0a = 0xf0;
            self->unk_b24_0 = 0;
            ((St021ad130 *)self->fsm)->timer = 0;
            ((St021ad130 *)self->fsm)->state++;
        }
        Fx021ad130(self);
        self->unk_44->unk_22_1 = 0;
        break;
    }
    case 12: {
        St021ad130 *st = (St021ad130 *)self->fsm;
        st->timer++;
        if (st->timer > 0x2d) {
            History_SetState(self->fsm, 1, 0);
        }
        if (((St021ad130 *)self->fsm)->timer < 10) {
            Fx021ad130(self);
        }
        break;
    }
    }
    if (self->unk_b22_6 == 5) {
        return;
    }
    self->hit->unk_9a |= 0x20;
    if (!(self->msg_flags & 0x80) && self->hpObj->cur == 0) {
        return;
    }
    Body_Update(self->hit, 0, 0, 0);
}
}
