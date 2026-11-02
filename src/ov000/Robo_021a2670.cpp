#include "ov000/LoCommon.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"

typedef struct {
    u16 state;
    u16 timer;
} St021a2670;

typedef struct {
    u16 b0 : 6;
    u16 b6 : 1;
    u16 rest : 9;
} Ba4_021a2670;

extern "C" {
extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd30;
extern void *data_02097e4c;
extern void *data_ov000_021ca030[];
extern void *data_ov000_021ca040[];
extern void *const data_ov000_021ca080[];
extern u8 data_ov000_021cc62a[];
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021b1fac(void *self, BOOL a, s32 b);
void func_ov000_021b1dd8(void *self, s32 a, s32 b, s32 c, s32 d, s32 e);
BOOL func_ov000_02198360(void *st, s32 a, s32 b);
Actor *ActorMgr_GetActor(void *mgr, u16 id);
void func_ov000_02168e18(void *a, s32 b, s32 c, VecFx32 *v);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
void *func_02049f44(void *a, s32 b, void *c, s32 d);
u16 FX_Atan2(s32 x, s32 z);

static inline Actor *GetObj021a2670(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline BOOL Jump021a2670(Robo021ca458 *self) {
    BOOL go = FALSE;
    if (self->unk_b24_1 && (self->hit->unk_54 & 0x400)) {
        self->moveYaw = FX_Atan2(self->unk_af0.x - self->pos.x, self->unk_af0.z - self->pos.z);
        self->speed = 0x66;
        self->friction = 0;
        if (!self->unk_b24_17 || (self->hit->unk_50 & 0x40000000)) {
            self->velY = 0x200;
        }
        self->gravity = 0x52;
        self->unk_b24_17 = 1;
        go = TRUE;
    }
    return go;
}

static inline void PlaySe021a2670(s32 id, void *pos) {
    if (id >= 0) {
        func_02049f44(data_02097e4c, id, pos, 0);
    }
}

void func_ov000_021a2670(Robo021ca458 *self) {
    u16 thr = 0;
    s32 kind;
    void *anm;
    switch (((St021a2670 *)self->fsm)->state) {
    case 0: {
        self->unk_b24_16 = 0;
        self->unk_b24_17 = 0;
        self->unk_b2c_6 = 0;
        self->friction = 0xc00;
        if (self->speed > 0x252) {
            self->speed = 0x252;
        }
        self->unk_b36 = 0;
        func_ov000_021b1fac(self, TRUE, 1);
        if (Jump021a2670(self)) {
            func_ov000_02198360(self->fsm, 4, 0);
            return;
        }
        if (self->unk_b24_1) {
            thr = 6;
        }
        {
            St021a2670 *st = (St021a2670 *)self->fsm;
            st->timer++;
            if (st->timer <= thr) {
                return;
            }
        }
        if (0) {
            return;
        }
        if ((self->unk_b1c >> 12) == 5) {
            Actor *o = GetObj021a2670(self->unk_b1c);
            u8 *p = NULL;
            if (o != NULL) {
                p = ((u8 *)o->targetObj);
            }
            if (p != NULL) {
                u8 k = p[0];
                if (k == 0xf || k == 0x11) {
                    self->unk_b24_22 = 1;
                }
            }
        }
        ((St021a2670 *)self->fsm)->timer = 0;
        if (self->unk_b24_1 && self->unk_b24_12 == 0 &&
            self->unk_ba4 != NULL && LFLD(Ba4_021a2670, self->unk_ba4, 6).b6 &&
            self->unk_b38 >= thr) {
            func_ov000_02190cb0(self->model, data_ov000_021ca030[self->unk_b24_5], 0x19a, 1);
            self->speed = 0;
            self->friction = 0;
            ((St021a2670 *)self->fsm)->state++;
            self->unk_b38 = 1;
            return;
        }
        ((St021a2670 *)self->fsm)->state = 10;
        return;
    }
    case 1: {
        St021a2670 *st = (St021a2670 *)self->fsm;
        u16 t;
        st->timer++;
        t = st->timer;
        if (self->unk_b38 < t) {
            if (t < 0x1e) {
                ((St021a2670 *)self->fsm)->state = 10;
                return;
            }
            func_ov000_02190cb0(self->model, data_ov000_021ca040[self->unk_b24_5], 0x800, 0);
            self->unk_b2c_6 = 1;
            func_ov000_02198360(self->fsm, 0x16, 0);
            self->unk_b48 = 0;
            return;
        }
        if (t >= 10) {
            if ((t & 0x1f) == 10) {
                EffectObj *e = func_02065f88(0x646, &self->pos);
                self->unk_b48 = e->id;
                self->unk_b5e = 0;
                self->unk_b4c = 0;
                self->unk_b54 = 0;
                self->unk_b50 = self->centerY;
                self->unk_b58 = 0;
                self->unk_b5a = 0;
                self->unk_b5c = 0;
            }
            {
                u8 *g = data_ov000_021ccd30;
                VecFx32 v;
                v.x = 0;
                v.y = 0;
                v.z = 0;
                if (t > 0x1e) {
                    t = 0x1e;
                }
                g = LFLD(u8 *, g, 0x11c);
                if (g != NULL && LFLD(u8 *, g, 0x70) != NULL) {
                    func_ov000_02168e18(LFLD(u8 *, g, 0x70), t, 0x1e, &v);
                }
            }
        }
        self->hit->unk_9a |= 0x20;
        func_ov000_021987b8(self->hit, 1, 0, 0);
        if (self->hit->unk_50 & 0x20000000) {
            return;
        }
        func_ov000_02198360(self->fsm, 4, 0);
        return;
    }
    case 10: {
        s32 snd;
        s32 lock;
        anm = data_ov000_021cc62a;
        self->unk_b2a_3 = 1;
        if (self->unk_b24_1) {
            lock = self->unk_b24_5;
            anm = data_ov000_021ca080[lock];
            self->gravity = 0x52;
            self->velY = 0x53f;
            kind = self->unk_b1c >> 12;
            if (kind != 5) {
                switch (lock) {
                case 1:
                    self->velY = 0x4cd;
                    break;
                case 2:
                    self->velY = 0x200;
                    break;
                }
            }
            ((St021a2670 *)self->fsm)->timer = 9;
            snd = 7;
        } else {
            if (self->hit->unk_50 & 0x400) {
                self->velY = 0x31f;
                snd = 0x3c;
            } else {
                self->velY = 0x53f;
                snd = 9;
            }
            self->gravity = 0x50;
            ((St021a2670 *)self->fsm)->timer = 0xf;
        }
        func_ov000_02190cb0(self->model, anm, 0x800, 0);
        PlaySe021a2670(snd, &self->pos);
        if (!self->unk_93_4) {
            s32 se = 0x300;
            if (LFLD(u16, data_ov000_021ccd68, 0xa) & 1) {
                se = 0x304;
            }
            PlaySe021a2670(se, &self->pos);
        }
        ((St021a2670 *)self->fsm)->state++;
    }
    case 11:
        if (!self->unk_b24_16 && !self->unk_b24_17) {
            func_ov000_021b1dd8(self, self->unk_b08 + (self->unk_b08 >> 1), 0x200, 0xf00, 0x466, 1);
        } else {
            func_ov000_021b1fac(self, FALSE, 0);
        }
        if (Jump021a2670(self)) {
            func_ov000_02198360(self->fsm, 4, 0);
            return;
        }
        if (self->unk_b24_12 == 0) {
            if ((self->hit->unk_50 & 0x40000000) || ((s32)self->hit->unk_58) != 0) {
                self->speed = 0;
                self->unk_b24_16 = 1;
            }
        }
        {
            St021a2670 *st = (St021a2670 *)self->fsm;
            if (st->timer != 0) {
                st->timer--;
            }
            if (st->timer == 0) {
                func_ov000_02198360(self->fsm, 4, 0);
            }
        }
        break;
    }
}
}
