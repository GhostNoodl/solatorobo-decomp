#include "ov000/LoCommon.h"
#include "ov000/ActorMgr.h"
#include "ov000/MessageQueue.h"
#include "Main/Res/StageFlags.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"

class Robo021a0d4cCls;
typedef void (Robo021a0d4cCls::*Robo021a0d4cPmf)();

typedef struct {
    s32 key;
    Robo021a0d4cPmf fn;
} Robo021a0d4cEntry;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
} Bd_021a0d4c;

typedef struct {
    u8 b0 : 4;
    u8 hi : 4;
} Bq_021a0d4c;

extern "C" {
extern Robo021a0d4cEntry data_ov000_021ca458[];
extern MessageQueue021cb980 *data_ov000_021ccd30;
extern void *data_ov000_021ccd64;
extern u8 *data_ov000_021ccd6c;
extern u8 *data_02149f0c;
void func_ov000_021b06dc(u8 *self);
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
void func_ov000_0216adc0(void *p, s32 a, u16 b);
void func_ov000_021b3d78(u8 *self);
void Obj0218c208_AddPoint(void *a, void *pos, u16 ang);
void func_ov000_0219a088(void *p);
void func_ov000_0219a0b0(void *p, u8 *self);
void func_ov000_0216b508(void *p, s32 a, BOOL b);
BOOL func_ov000_021bd314(void *p, s32 a);
void func_ov000_021bd624(void *p);
void func_ov000_021b1110(u8 *self, s32 a);
void func_ov000_021697dc(void *p, u16 a, u16 b);
void func_ov000_0216a438(void *p, u16 a, s32 b, BOOL c);

static inline Actor *GetObj021a0d4c(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline void Reset021a0d4c(Robo021ca458 *self) {
    self->unk_b24_5 = 0;
    self->unk_b1c = 0xffff;
    self->unk_b1e = 0xffff;
    self->unk_b24_7 = self->unk_b24_9;
}

static inline u8 *Target021a0d4c(Robo021ca458 *self) {
    u8 *o = (u8 *)GetObj021a0d4c(self->unk_b1c);
    u8 *p = NULL;
    if (o != NULL) {
        p = LFLD(u8 *, o, 0x4c);
    }
    if (p == NULL || LFLD(u16, p, 0x1c) != self->id) {
        Reset021a0d4c(self);
        return NULL;
    }
    return o;
}

static inline void Gauge021a0d4c(u16 v) {
    ListBuffer021cb940 *g = data_ov000_021ccd30->unk_11c;
    if (g != NULL && g->unk_78 != NULL) {
        func_ov000_0216adc0(g->unk_78, 1, v);
    }
}

static inline BOOL GBusy021a0d4c(FieldState *g) {
    return g->head != g->tail ? TRUE : FALSE;
}

static inline BOOL GIdle021a0d4c(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (GBusy021a0d4c(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline BOOL RgbEq021a0d4c(u8 *a, u8 *b) {
    BOOL r = FALSE;
    if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2]) {
        r = TRUE;
    }
    return r;
}

static inline BOOL NotB1_021a0d4c(Robo021ca458 *self) {
    return !self->unk_b24_1 ? TRUE : FALSE;
}

static inline BOOL G9_021a0d4c(void) {
    return data_0214a424->bits18.flag9 ? TRUE : FALSE;
}

static inline BOOL Ready021a0d4c(FieldState *g) {
    if (GBusy021a0d4c(g)) return FALSE;
    if (g->state != 3) return FALSE;
    return TRUE;
}
static inline BOOL IdleG021a0d4c(FieldState *g) {
    if (g != NULL) {
        return Ready021a0d4c(g);
    }
    return TRUE;
}
static inline BOOL Ok021a0d4c(Robo021ca458 *self) {
    FieldState *g = data_ov000_021ccd54;
    BOOL r = IdleG021a0d4c(g);
    if (r) {
        r = !self->unk_b29_1;
    }
    if (r) {
        r = self->unk_b28 == 0;
    }
    if (r) {
        r = self->unk_b2e == 0;
    }
    if (r) {
        r = !self->unk_b24_0;
    }
    if (r) {
        r = !self->unk_b29_3;
    }
    if (r) {
        r = !NotB1_021a0d4c(self);
        if (!r) {
            BOOL t = G9_021a0d4c();
            r = !t;
            if (!t) {
                r = RgbEq021a0d4c((u8 *)g + 0xca, (u8 *)self + 0x772);
            }
            if (r) {
                r = self->unk_b24_14 == 0;
            }
        }
    }
    return r;
}

static inline void Bar021a0d4c(u16 a, u16 b) {
    ListBuffer021cb940 *g = data_ov000_021ccd30->unk_11c;
    if (g != NULL && g->unk_58 != NULL) {
        func_ov000_021697dc(g->unk_58, a, b);
        LFLD(u32, g->unk_58, 0xc) |= 0x80;
    }
}

static inline void Mark021a0d4c(u16 a, s32 b, BOOL c) {
    ListBuffer021cb940 *g = data_ov000_021ccd30->unk_11c;
    if (g != NULL && g->unk_64 != NULL) {
        func_ov000_0216a438(g->unk_64, a, b, c);
    }
}

void func_ov000_021a0d4c(Robo021ca458 *self) {

    s32 k;
    s32 i;

    if (self->unk_b22_6 == 5) {
        func_ov000_021b06dc((u8 *)self);
        return;
    }
    self->unk_b29 = 0;
    if (self->unk_b2e != 0) {
        self->unk_b2e--;
    }
    k = self->fsm->current;
    for (i = 0; i < 0x1d; i++) {
        if (k == *(s32 *)((u8 *)data_ov000_021ca458 + i * 12)) {
            (((Robo021a0d4cCls *)self)->*data_ov000_021ca458[i].fn)();
            break;
        }
    }
    if (!self->unk_b24_1) {
        self->model = (Model0218fe1c *)&self->mdl0;
        self->hit = (ActorSub48 *)((u8 *)self + 0x2cc);
    } else {
        self->model = (Model0218fe1c *)((u8 *)self + 0x368);
        self->unk_75c.x = self->pos.x;
        self->unk_75c.y = self->pos.y;
        self->unk_75c.z = self->pos.z;
        self->unk_76c = self->rot_x;
        self->unk_76e = self->rot_y;
        self->unk_770 = self->rot_z;
        self->hit = (ActorSub48 *)((u8 *)self + 0x6c0);
    }
    if (self->hit->unk_9a_8) {
        u32 f = self->hit->unk_50;
        if ((f & 0x20000000) && !(f & 0x40400) && !(f & 0x40000000)) {
            self->unk_af0.x = self->pos.x;
            self->unk_af0.y = self->pos.y;
            self->unk_af0.z = self->pos.z;
        }
        if (self->hit->unk_54 & 0x20000000) {
            ActorSub48 *p = self->hit;
            self->unk_afc.x = p->check.x;
            self->unk_afc.y = p->check.y;
            self->unk_afc.z = p->check.z;
        }
    }
    if (self->unk_b24_5 != 0 && !self->unk_b22_3) {
        u8 *o = Target021a0d4c(self);
        if (o != NULL) {
            ActorSub4c *p = (ActorSub4c *)LFLD(u8 *, o, 0x4c);
            u16 v = 0;
            if (p != NULL) {
                v = p->unk_1e;
            }
            if (v != 0) {
                Gauge021a0d4c(v);
                if (self->unk_b32 == 0) {
                    self->unk_b32++;
                }
            }
        }
    }
    if (self->unk_b24_12 == 3) {
        Actor *o = GetObj021a0d4c(self->unk_b20);
        ActorSub4c *p = NULL;
        if (o != NULL) {
            p = o->targetObj;
        }
        if (p != NULL) {
            Gauge021a0d4c(p->unk_1e);
            if (self->unk_b32 == 0) {
                self->unk_b32++;
            }
        }
    }
    func_ov000_021b3d78((u8 *)self);
    Obj0218c208_AddPoint(data_ov000_021ccd64, &self->pos, self->rot_y);
    if (self->unk_b24_2 != 1) {
        u8 *c = data_ov000_021ccd6c;
        LFLD(s32, c, 0x24) = self->pos.x;
        LFLD(s32, c, 0x28) = self->pos.y;
        LFLD(s32, c, 0x2c) = self->pos.z;
    }
    {
        u8 *c = data_02149f0c;
        LFLD(s32, c, 0) = self->pos.x;
        LFLD(s32, c, 4) = self->pos.y;
        LFLD(s32, c, 8) = self->pos.z;
    }
    if (self->hpObj->unk_0a != 0) {
        self->hpObj->unk_0a--;
    }
    func_ov000_0219a088(self->unk_54);
    {
        s32 a = 0;
        s32 b = 0;
        u8 *q = self->unk_ba4;
        if (q != NULL && self->unk_b24_1 && !self->unk_b24_0) {
            b = LFLD(Bq_021a0d4c, q, 4).hi;
            if (b != 0) {
                b = b * 10;
                a = 0x2d0;
            }
        }
        self->unk_aea = a;
        self->unk_aec = b;
    }
    func_ov000_0219a0b0((u8 *)self + 0xae8, (u8 *)self);
    LFLD(Bd_021a0d4c, self->unk_9b4, 0).b1 = 0;
    if (self->unk_b22_0 != 0 && Ok021a0d4c(self)) {
        if (self->unk_b24_1) {
            BOOL f = data_0214a424->bits18.flag10 ? TRUE : FALSE;
            ListBuffer021cb940 *g = data_ov000_021ccd30->unk_11c;
            if (g != NULL) {
                func_ov000_0216b508(g->unk_68, 1, f);
            }
        }
        if (self->unk_b22_0 == 3 || self->unk_b22_0 == 4) {
            func_ov000_021bd314(self->unk_9b4, 8);
            LFLD(Bd_021a0d4c, self->unk_9b4, 0).b1 = 1;
        } else {
            FieldCam *q = &data_ov000_021ccd54->cam;
            if (q != NULL && q->unk_d6 - 1 == q->unk_d4) {
                func_ov000_021bd314(self->unk_9b4, 9);
                LFLD(Bd_021a0d4c, self->unk_9b4, 0).b1 = 1;
            }
        }
    }
    func_ov000_021bd624(self->unk_9b4);
    func_ov000_021b1110((u8 *)self, 0);
    if (self->unk_b32 != 0) {
        u16 m;
        self->unk_b32--;
        m = self->hpObj->max;
        if (self->unk_b34 < m) {
            self->unk_b34 += (u16)(m / 32);
            if (self->unk_b34 < m) {
                m = self->unk_b34;
                if (self->unk_b32 == 0) {
                    self->unk_b32++;
                }
            } else {
                self->unk_b34 = m;
            }
        }
        if (GIdle021a0d4c() || self->unk_b34 < m) {
            Bar021a0d4c(self->hpObj->cur, m);
            if (data_0214a424->bits18.mode == 1 && !self->unk_b22_4) {
                BOOL on;
                if (!self->unk_b22_3 && self->unk_b22_9 == 0 &&
                    self->unk_b24_1 && self->unk_93_4 &&
                    !self->unk_b29_3 && self->unk_b22_0 == 0 &&
                    self->unk_b24_12 == 0 && self->fsm->current != 0x11 &&
                    !(self->fsm->current == 0xb && self->unk_b24_26)) {
                    on = TRUE;
                } else {
                    on = FALSE;
                }
                Mark021a0d4c(data_0214a424->unk_026, 0x2d0, on);
            }
        }
    }
    if (self->unk_b22_0 != 0 && (self->hit->unk_50 & 0x20000000)) {
        self->unk_9ac += 0x80;
        if (self->unk_9ac > self->unk_9ae) {
            self->unk_9ac = self->unk_9ae;
        }
    }
    self->fsm->flags = 0;
}
}
