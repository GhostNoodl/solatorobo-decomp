#include "types.h"
#include "ov003/Actor.h"
#include "Main/Sys/FieldState.h"
#include "nitro/mi.h"

typedef struct {
    u8 unk_00[0x74];
    s32 unk_74;
    u8 unk_78[0xc];
    s32 unk_84;
} Ov003SdUnit;

typedef struct {
    u8 unk_00[0x1c];
    u16 unk_1c;
    u8 unk_1e[2];
    u8 mtx[0x24];
    VecFx32 unk_44;
} Ov003SdTgt;

typedef struct {
    u8 unk_00[0x4c];
    Ov003SdTgt *unk_4c;
} Ov003SdObj;

extern "C" {

extern void *data_ov000_021ccd64;
extern void *data_ov000_021ccd68;
extern Ov003SdUnit *Group_FindNode(void *mgr, u16 id);
extern Ov003SdObj *ActorMgr_GetActor(void *mgr, u16 id);
extern s32 FX_Div(s32 a, s32 b);
extern void NNS_G3dRenderObjSetInitFunc(void *rob, void *func);
extern void Ov003Obj_StartCapture(void *rs);
extern u16 Actor_Draw(Ov003Actor *self);
extern u16 Model021903b4_Draw(Model0218fe1c *m);
extern void Vec_RotateY(VecFx32 *out, VecFx32 *in, u16 ang);
extern void ActorMarker_Draw(void *p);

}

static inline void Ov003Sd_SetSqrtImm64(u64 param) {
    *(volatile u64 *)0x040002b8 = param;
}

static inline void Ov003Sd_SetSqrt64(u64 param) {
    *(volatile u16 *)0x040002b0 = 1;
    Ov003Sd_SetSqrtImm64(param);
}

static inline void Ov003Sd_WaitSqrt(void) {
    while (*(volatile u16 *)0x040002b0 & 0x8000) {
    }
}

static inline u32 Ov003Sd_GetSqrtResult32(void) {
    return *(volatile u32 *)0x040002b4;
}

static inline s32 Ov003Sd_Dist(s64 sq) {
    Ov003Sd_SetSqrt64((u64)(sq << 2));
    Ov003Sd_WaitSqrt();
    return (s32)(Ov003Sd_GetSqrtResult32() + 1) >> 1;
}

static inline void Ov003Sd_SetLight(Model0218fe1c *m) {
    m->color = 0x3def;
    m->color2 = 0x3def;
    m->blend = 2;
    m->blendMax = 1;
}

static inline BOOL Ov003Game_IsBusy(FieldState *g) {
    BOOL r = g->head != g->tail;
    return r;
}

static inline BOOL Ov003Game_IsIdle(FieldState *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}

static inline BOOL Ov003Game_HasEvent(FieldState *g) {
    return g->event != NULL ? TRUE : FALSE;
}

static inline BOOL Ov003_GameHasD4(void) {
    return Ov003Game_HasEvent(data_ov000_021ccd54) ? TRUE : FALSE;
}

static inline Ov003SdObj *Ov003Sd_FindObj(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

extern "C" u16 Ov003Actor_Draw(Ov003Actor *self) {
    s32 i;
    Model0218fe1c *sub;
    u8 buf[0x24];
    VecFx32 v;
    Ov003SdUnit *unit;
    u8 alpha;
    u16 r;
    MtxFx43 *mt;
    if (self->hpObj != NULL && self->hpObj->cur == 0 && !self->unk_ea_9) {
        Ov003Sd_SetLight(self->model);
        if (self->unk_d0 != NULL && self->unk_ea_3) {
            s32 j;
            for (j = 0; j < 2; j++) {
                sub = self->unk_d0->models[j];
                if (sub != NULL) {
                    Ov003Sd_SetLight(sub);
                }
            }
        }
    }
    alpha = 0x1f;
    unit = NULL;
    if (!self->unk_ea_14) {
        unit = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    }
    if (unit != NULL) {
        FieldState *g = data_ov000_021ccd54;
        s32 dx = self->pos.x - g->cam.base.eye.x;
        s32 dz = self->pos.z - g->cam.base.eye.z;
        s64 sq = (s64)dx * dx;
        s32 dist;
        s32 f;
        sq += (s64)dz * dz;
        dist = Ov003Sd_Dist(sq);
        f = 0x1000;
        if (dist > unit->unk_84) {
            if (dist >= unit->unk_74) {
                f = 0;
            } else {
                f -= FX_Div(dist - unit->unk_84, unit->unk_74 - unit->unk_84);
            }
        }
        if (f == 0) {
            alpha = 0;
        } else if (f < 0x1000) {
            alpha = (f * 31) >> 12;
        }
    }
    if (self->unk_d0 != NULL && self->unk_ea_3) {
        for (i = 0; i < 2; i++) {
            if (self->unk_d0->idx[i] != 0xff) {
                Model0218fe1c *m;
                self->model->renderUser = self->unk_d0;
                m = self->model;
                NNS_G3dRenderObjSetInitFunc(m->unk_24, (void *)Ov003Obj_StartCapture);
                m->unk_c2 |= 0x20;
                self->model->unk_c2 |= 0x100;
                break;
            }
        }
    }
    r = FALSE;
    {
        ActorSub4c *s = self->targetObj;
        if (s != NULL && s->unk_18_0) {
            MI_Copy36B(s->unk_20, buf);
            MI_Copy36B(buf, &self->model->rot);
            self->unk_93_0 = 1;
        }
    }
    if (alpha == 0x1f) {
        r = Actor_Draw(self);
    } else if (alpha != 0) {
        u8 old = self->model->alpha;
        if (old > alpha) {
            self->model->alpha = alpha;
        }
        r = Actor_Draw(self);
        self->model->alpha = old;
    }
    if (self->unk_d0 != NULL && self->unk_ea_3) {
        for (i = 0; i < 2; i++) {
            if (r && (sub = self->unk_d0->models[i]) != NULL) {
                mt = &self->unk_d0->mtx[i];
                MI_Copy36B(mt, &sub->rot);
                sub->trans.x = mt->_30;
                sub->trans.y = mt->_31;
                sub->trans.z = mt->_32;
                if (alpha == 0x1f) {
                    Model021903b4_Draw(sub);
                } else if (alpha != 0) {
                    u8 old = sub->alpha;
                    if (old > alpha) {
                        sub->alpha = alpha;
                    }
                    r = Model021903b4_Draw(sub);
                    sub->alpha = old;
                }
            } else if (self->unk_d0->unk_62[i] != 0xffff) {
                Ov003SdObj *o = Ov003Sd_FindObj(self->unk_d0->unk_62[i]);
                if (o != NULL && (sub = (Model0218fe1c *)o->unk_4c) != NULL) {
                    ((Ov003SdTgt *)sub)->unk_1c = self->id;
                    if (r) {
                        MI_Copy48B(&self->unk_d0->mtx[i], ((Ov003SdTgt *)sub)->mtx);
                    } else {
                        v.y = self->height >> 1;
                        v.x = 0xccd;
                        v.z = 0xccd;
                        Vec_RotateY(&v, &v, self->rot_y);
                        VEC_Add(&v, &self->pos, &v);
                        ((Ov003SdTgt *)sub)->unk_44 = v;
                    }
                }
            }
        }
    }
    if (r && self->unk_5c != NULL && Ov003_GameIdle() && !Ov003_GameHasD4()) {
        ActorMarker_Draw(self->unk_5c);
    }
    self->unk_ea_13 = r;
    return r;
}
