#include "ov000/LoCommon.h"
#include "ov000/ActorMgr.h"
#include "ov000/MessageQueue.h"
#include "Main/Res/StageFlags.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/GfxMgr.h"

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} Bit0_0219d9fc;

#define SIN_0219d9fc(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define COS_0219d9fc(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

extern "C" {
extern MessageQueue021cb980 *data_ov000_021ccd30;
extern u8 data_ov000_021ca320[];
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
void func_ov000_02191ec4(void *a, s32 b, u32 c);
int func_02043d9c(void *p);
void func_ov000_02190758(void *model, void *rot, s32 a);
BOOL func_ov000_021903b4(void *model);
void NNS_G3dRenderObjSetInitFunc(void *obj, void *fn);
void func_ov003_021ce9ac(void *p);
void func_ov000_021b4130(Robo021ca458 *self, BOOL a);
void func_ov000_021bd7a0(void *p);
void func_ov000_02191c24(void *shadow, void *pos);
void func_ov000_02167fac(Lo021cb6f0 *self, s32 a, s32 b);

static inline Actor *FindActor_0219d9fc(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline BOOL IsBusy_0219d9fc(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL IsIdle_0219d9fc(FieldState *g) {
    if (g != NULL) {
        if (IsBusy_0219d9fc(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline u8 Begin_0219d9fc(void) {
    u8 a = LFLD(u8, data_02097d48, 0x8b3);
    func_02043d9c(data_02097d48->unk_8b0);
    return a;
}

static inline BOOL HasD4_0219d9fc(FieldState *g) {
    return ((s32)g->event) != 0;
}

static inline BOOL HasD4B_0219d9fc(FieldState *g) {
    return HasD4_0219d9fc(g) ? TRUE : FALSE;
}

static inline BOOL PadB9_0219d9fc(void) {
    return data_0214a424->bits18.flag9 ? TRUE : FALSE;
}

struct RgbEq_0219d9fcSelf {
    u8 unk_00[0x772];
    u8 unk_772;
    u8 unk_773;
    u8 unk_774;
};

static inline BOOL RgbEq_0219d9fc(FieldState *g, RgbEq_0219d9fcSelf *self) {
    BOOL e = FALSE;
    if (g->unk_ca.c[0] == self->unk_772 && g->unk_ca.c[1] == self->unk_773 && g->unk_ca.c[2] == self->unk_774) {
        e = TRUE;
    }
    return e;
}

static inline void Flash_0219d9fc(Model0218fe1c *m, u16 a, u16 b, s32 n) {
    if (n != 0) {
        m->color = a;
        m->color2 = b;
        m->blend = n + 1;
        m->blendMax = n;
    }
}

BOOL Robo021ca458_Draw(Robo021ca458 *self) {
    u32 fl;
    Model0218fe1c *m;
    u8 v;
    s32 n;
    Actor *a;
    u8 lvl;
    u16 ca;
    u16 cb;
    s32 h;

    if (self->unk_b28_3) {
        return FALSE;
    }
    func_ov000_02191ec4(self->unk_3c, 1, self->hit->unk_54);
    m = self->model;
    v = m->bright;
    if (self->hit->unk_54 & 0x80000) {
        if (self->unk_b24_20_f) {
            if (v > 5) {
                m->bright = v - 3;
            }
        } else {
            m->bright = 5;
            self->unk_b24_20_f = 1;
        }
    } else {
        if (self->unk_b24_20_f) {
            if (v < 0x1f) {
                m->bright = v + 1;
            }
        } else {
            m->bright = 0x1f;
            self->unk_b24_20_f = 1;
        }
    }

    lvl = 0x1f;
    {
        u16 w = self->hpObj->unk_0a;
        n = 0;
        if (w != 0) {
            if (self->model->blend == 0) {
                u16 k;
                n = 1;
                cb = ca = 0x53ff;
                if (w > 0x3c) {
                    k = w & 0xf;
                } else {
                    k = w & 7;
                    if (w <= 0x1e) {
                        k = w & 3;
                    }
                }
                lvl = 0x1e;
                if (k != 0) {
                    lvl = 0x14;
                }
            }
        } else if (self->unk_b24_0) {
            cb = ca = 0x3def;
            lvl = 0x1e;
            n = 1;
        } else if (self->unk_b22_3 && IsIdle_0219d9fc(data_ov000_021ccd54)) {
            if (!(data_ov000_021ccd68->frame & 0x3f)) {
                ca = 0x63fc;
                cb = 0x5ad4;
                n = 0x40;
            }
        } else if (self->unk_b2c_6) {
            if (self->fsm->current == 0x16) {
                cb = ca = 0x729c;
                n = 1;
            }
        } else if (self->unk_b2c_3_f) {
            cb = ca = 0x7e90;
            n = 1;
        }
    }
    if (n != 0) {
        Model0218fe1c *fm = self->model;
        fm->color = ca;
        fm->color2 = cb;
        fm->blend = n + 1;
        fm->blendMax = n;
    }
    self->model->alpha = lvl;
    if (self->unk_b24_1) {
        if (self->unk_b22_0 && self->unk_998 != NULL) {
            Flash_0219d9fc((Model0218fe1c *)self->unk_998, ca, cb, n);
            LFLD(u8, self->unk_998, 0xbe) = lvl;
        }
    } else if (self->unk_b24_21) {
        if (n != 0) {
            self->mdl2.color = ca;
            self->mdl2.color2 = cb;
            self->mdl2.blend = n + 1;
            self->mdl2.blendMax = n;
        }
        self->mdl2.alpha = lvl;
    }

    {
    s32 res = 0;
    s32 off = self->radius;
    u8 alpha = Begin_0219d9fc();
    if (self->unk_b24_2) {
        self->mdl1.trans = self->unk_75c;
        func_ov000_02190758(&self->mdl1, (u8 *)self + 0x76c, 1);
        self->mdl1.alpha = 0x1f;
        self->mdl1.polyId = alpha;
        if (func_ov000_021903b4(&self->mdl1)) {
            res = 1;
        }
        self->mdl0.trans = self->pos;
        func_ov000_02190758(&self->mdl0, (u8 *)self + 0x7c, 1);
        self->mdl0.polyId = alpha;
        func_ov000_021903b4(&self->mdl0);
        h = self->hit0.check.y;
    } else {
    if (self->unk_b24_1) {
        VecFx32 p;
        if ((u32)(self->unk_b24_5 - 1) <= 1) {
            s32 f = self->unk_b24_7;
            if (f == 1) {
                self->unk_ae4 |= 2;
            } else if (f == 0) {
                self->unk_ae4_0 = 1;
            } else {
                self->unk_ae4 |= 2;
                self->unk_ae4_0 = 1;
            }
        }
        if (self->unk_b22_0) {
            self->unk_ae4 |= 4;
        }
        if (self->unk_ae4 != 0) {
            self->mdl1.renderUser = (u8 *)self + 0xa50;
            NNS_G3dRenderObjSetInitFunc((u8 *)self + 0x38c, (void *)func_ov003_021ce9ac);
            self->mdl1.unk_c2 |= 0x20;
        }
        p = self->unk_75c;
        if (self->unk_b24_12) {
            a = FindActor_0219d9fc(self->unk_b20);
            ActorSub4c *s;
            if (a != NULL && (s = a->targetObj) != NULL) {
                s16 *e = (s16 *)(data_ov000_021ca320 + s->unk_06 * 0x18);
                VecFx32 o;
                o.x = e[1];
                o.y = e[2];
                o.z = e[3];
                VEC_Add(&p, &o, &p);
            }
        }
        self->mdl1.trans = p;
        func_ov000_02190758(&self->mdl1, (u8 *)self + 0x76c, 1);
        self->mdl1.polyId = alpha;
        if (func_ov000_021903b4(&self->mdl1)) {
            res = 1;
        }
        h = self->hit1.check.y;
        if (!self->unk_b22_3) {
            off = off * 2 - (off >> 2);
        } else {
            off <<= 1;
        }
        if (self->unk_b24_5) {
            func_ov000_021b4130(self, res != 0 ? TRUE : FALSE);
        }
    } else {
        if (!PadB9_0219d9fc() && RgbEq_0219d9fc(data_ov000_021ccd54, (RgbEq_0219d9fcSelf *)self)) {
            self->mdl1.trans = self->unk_75c;
            func_ov000_02190758(&self->mdl1, (u8 *)self + 0x76c, 1);
            self->mdl1.alpha = 0x1f;
            self->mdl1.polyId = alpha;
            if (self->unk_b22_0) {
                self->unk_ae4 |= 4;
                self->mdl1.renderUser = (u8 *)self + 0xa50;
                NNS_G3dRenderObjSetInitFunc((u8 *)self + 0x38c, (void *)func_ov003_021ce9ac);
                self->mdl1.unk_c2 |= 0x20;
            }
            if (func_ov000_021903b4(&self->mdl1)) {
                res = 1;
            }
        } else {
            res = -1;
        }
        if (self->unk_b24_21) {
            LFLD(Bit0_0219d9fc, self, 0xa4c).b0 = 1;
            self->mdl0.renderUser = (u8 *)self + 0x9b8;
            NNS_G3dRenderObjSetInitFunc((u8 *)self + 0xd0, (void *)func_ov003_021ce9ac);
            self->mdl0.unk_c2 |= 0x20;
        }
        if (!self->unk_93_0) {
            self->mdl0.trans = self->pos;
            func_ov000_02190758(&self->mdl0, (u8 *)self + 0x7c, 1);
        }
        self->mdl0.polyId = alpha;
        if (func_ov000_021903b4(&self->mdl0) && self->unk_b24_21) {
            self->mdl2.trans = self->unk_9dc;
            MI_Copy36B((u8 *)self + 0x9b8, (u8 *)self + 0x7fc);
            self->mdl2.polyId = alpha;
            func_ov000_021903b4(&self->mdl2);
        }
        h = self->hit0.check.y;
        if (self->unk_b24_5) {
            Actor *a = FindActor_0219d9fc(self->unk_b1c);
            if (a != NULL) {
                ActorSub4c *s = a->targetObj;
                s32 q[3];
                s->target = self->id;
                q[0] = self->pos.x;
                q[1] = self->pos.y;
                q[2] = self->pos.z;
                q[1] += self->centerY;
                s->dest = *(VecFx32 *)q;
            }
        }
    }
    {
        FieldState *g = data_ov000_021ccd54;
        if (IsIdle_0219d9fc(g) && !HasD4B_0219d9fc(g)) {
            func_ov000_021bd7a0(self->unk_5c);
            func_ov000_021bd7a0(self->unk_9b0);
            func_ov000_021bd7a0(self->unk_9b4);
        }
    }
    }
    fl = self->hit->unk_54;
    if ((fl & 0xf0f0f0) != 0xe0e000 && (fl & 0x20000) != 0x20000) {
        self->unk_3c->unk_14 = off;
        self->unk_3c->unk_10 = self->pos.y - h;
        self->unk_3c->unk_1a = alpha;
        if (self->unk_93_0 && !self->unk_b24_1) {
            VecFx32 w;
            w.x = self->mdl0.trans.x;
            w.y = self->mdl0.trans.y;
            w.z = self->mdl0.trans.z;
            func_ov000_02191c24(self->unk_3c, &w);
        } else {
            func_ov000_02191c24(self->unk_3c, &self->pos);
        }
    }
    if (self->unk_b22_0 && self->unk_998 != NULL && res >= 0 && self->mdl1.visible) {
        if (res != 0) {
            BOOL set;
            u16 rz;
            u16 ry;
            u16 rx;
            MtxFx33 mm;
            MtxFx33 mt;
            LFLD(VecFx32, self->unk_998, 0x78) = self->unk_ad4;
            ry = self->unk_9a8;
            rz = self->unk_9aa;
            rx = self->unk_9a6;
            set = FALSE;
            MTX_Identity33_(&mm);
            if (ry != 0) {
                MTX_RotY33_(&mm, SIN_0219d9fc(ry), COS_0219d9fc(ry));
                set = TRUE;
            }
            if (rx != 0) {
                if (set) {
                    MTX_RotX33_(&mt, SIN_0219d9fc(rx), COS_0219d9fc(rx));
                    MTX_Concat33(&mt, &mm, &mm);
                } else {
                    MTX_RotX33_(&mm, SIN_0219d9fc(rx), COS_0219d9fc(rx));
                    set = TRUE;
                }
            }
            if (rz != 0) {
                if (set) {
                    MTX_RotZ33_(&mt, SIN_0219d9fc(rz), COS_0219d9fc(rz));
                    MTX_Concat33(&mt, &mm, &mm);
                } else {
                    MTX_RotZ33_(&mm, SIN_0219d9fc(rz), COS_0219d9fc(rz));
                }
            }
            MTX_Concat33(&mm, (const MtxFx33 *)((u8 *)self + 0xab0), &mm);
            MI_Copy36B(&mm, ((u8 *)self->unk_998) + 0x84);
            LFLD(u8, self->unk_998, 0xc1) = alpha;
            func_ov000_021903b4(self->unk_998);
        }
        if (self->unk_9ac < self->unk_9ae) {
            if (self->unk_b24_1) {
                ListBuffer021cb940 *o = data_ov000_021ccd30->unk_11c;
                if (o != NULL && o->unk_6c != NULL) {
                    func_ov000_02167fac(o->unk_6c, self->unk_9ac, self->unk_9ae);
                }
            }
        }
    }
    }
    return TRUE;
}
}
