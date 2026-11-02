#include "ov000/LoCommon.h"
#include "ov000/Actor.h"
#include "ov000/ObjLayouts.h"

typedef struct {
    u16 b0 : 1;
    u16 sel : 2;
    u16 rest : 13;
} G18_021a0268;

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} C18_021a0268;

typedef struct {
    VecFx32 pos;
    u16 rot[3];
    s32 z;
} Msg021a0268;

extern "C" {
extern u8 *data_0214a424;
extern s32 data_ov000_021ca00c[];
extern s32 data_ov000_021ca100[];
extern s32 data_ov000_021ca168[];
void func_ov000_021b05b0(u8 *self);
u8 func_0206d37c(void *save, s32 a);
Actor *ActorMgr_GetActor(void *mgr, u16 id);

void func_ov000_0218d46c(void *self, u16 id, u8 value);
BOOL func_ov000_02198360(void *s, s32 a, s32 b);
s32 func_ov000_021a09b8(u8 *self, s32 *list, s32 count);
void func_ov000_0218d7e8(void *self, u8 arg);

static inline Actor *GetObj021a0268(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline void Reset021a0268(Robo021ca458 *self) {
    self->unk_b24_5 = 0;
    self->unk_b1c = 0xffff;
    self->unk_b1e = 0xffff;
    self->unk_b24_7 = self->unk_b24_9;
}

static inline BOOL GBusy021a0268(FieldState *g) {
    return g->head != g->tail ? TRUE : FALSE;
}

static inline BOOL GIdle021a0268(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (GBusy021a0268(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline s32 FxMul021a0268(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

void func_ov000_021a0268(Robo021ca458 *self) {
    ActorSub40 *s;
    if (self->unk_b22_6 == 5) {
        func_ov000_021b05b0((u8 *)self);
        return;
    }
    if (self->unk_b24_1) {
        self->model = (Model0218fe1c *)((u8 *)self + 0x368);
        self->hit = (ActorSub48 *)((u8 *)self + 0x6c0);
        if (self->unk_b24_5 == 2) {
            self->unk_b08 = 0x15c;
        } else {
            self->unk_b08 = data_ov000_021ca00c[LFLD(G18_021a0268, data_0214a424, 0x18).sel];
        }
        if (self->unk_b22_3) {
            self->unk_b08 += 0x8f;
        }
        self->unk_b08 += func_0206d37c(data_0214a424, 3) * 4;
    } else {
        self->model = (Model0218fe1c *)&self->unk_ac;
        self->hit = (ActorSub48 *)((u8 *)self + 0x2cc);
        self->unk_b08 = 0x19a;
    }
    if (self->unk_b0c != 0x1000) {
        self->unk_b08 = FxMul021a0268(self->unk_b08, self->unk_b0c);
    }
    if (LFLD(u16, ((u8 *)self->unk_54), 0) != 0 && LFLD(s16, ((u8 *)self->unk_54), 2) != 0) {
        self->unk_b08 = FxMul021a0268(self->unk_b08, LFLD(s16, ((u8 *)self->unk_54), 2));
    }
    {
        u16 t = LFLD(u16, ((u8 *)self->unk_54), 4);
        if (t != 0) {
            if (self->unk_9ac > t) {
                self->unk_9ac -= t;
            } else {
                self->unk_9ac = 0;
            }
        }
    }
    s = ((ActorSub40 *)self->fsm);
    if (s->current != 0x1f) {
        if (s->flags & 1) {
            Actor *o = GetObj021a0268(self->unk_b1c);
            if (o != NULL) {
                Msg021a0268 m;
                m.pos = self->pos;
                m.pos.y += self->centerY;
                m.rot[0] = o->rot_x;
                m.rot[1] = o->rot_y;
                m.rot[2] = o->rot_z;
                m.z = 0;
                Actor_SendMsg((Actor *)o, self->id, 7, 1, 0x18, &m);
                func_ov000_0218d46c(o, self->id, 10);
                if (((u8 *)o->targetObj) != NULL) {
                    LFLD(C18_021a0268, ((u8 *)o->targetObj), 0x18).b0 = 0;
                }
            }
            Reset021a0268(self);
            return;
        }
        if (s->flags & 0x80000000) {
            func_ov000_02198360(s, 0x1f, 0);
        } else if (s->flags & 2) {
            func_ov000_02198360(s, 1, 1);
        } else if (s->flags & 0x80000) {
            func_ov000_02198360(s, 0x13, 1);
        } else if (s->flags & 0x40000) {
            func_ov000_02198360(s, 0x12, 1);
        }
    }
    s = ((ActorSub40 *)self->fsm);
    switch (s->current) {
    case 0x16:
        func_ov000_021a09b8((u8 *)self, data_ov000_021ca100, 0xb);
        break;
    case 3:
        if (func_ov000_021a09b8((u8 *)self, data_ov000_021ca100, 0xb)) {
            break;
        }
        if (self->unk_b24_12 != 0) {
            break;
        }
        s = ((ActorSub40 *)self->fsm);
        if (!(s->flags & 8)) {
            break;
        }
        if (!self->unk_b24_1) {
            break;
        }
        func_ov000_02198360(s, 0x16, 0);
        break;
    case 4:
        if (!self->unk_b24_17 && !self->unk_b24_18) {
            if (func_ov000_021a09b8((u8 *)self, data_ov000_021ca100, 0xb)) {
                break;
            }
        } else if (s->flags & 0x4000000) {
            func_ov000_02198360(s, 0x1a, 0);
            break;
        }
        s = ((ActorSub40 *)self->fsm);
        if ((s->flags & 0x2000000) && self->velY <= 0x19a &&
            self->pos.y - self->unk_af4 >= -0x2d000 && self->unk_b1c == 0xffff &&
            !(self->hit->unk_50 & 0x20000000)) {
            func_ov000_02198360(s, 0x19, 0);
            break;
        }
        if (s->flags & 8) {
            u32 f = self->hit->unk_50;
            if ((f & 0x20000000) && !(f & 0x400)) {
                func_ov000_02198360(s, 3, 0);
                break;
            }
            if (self->unk_b24_1 && self->unk_b24_5 == 0 &&
                self->unk_b24_12 == 0 && self->velY <= 0x19a &&
                !self->unk_b24_17 && !self->unk_b24_18) {
                func_ov000_02198360(s, 0x17, 0);
                break;
            }
        }
        if (GIdle021a0268()) {
            break;
        }
        if ((self->hit->unk_54 & 0x20000000) && !self->unk_b28_3) {
            break;
        }
        if (self->unk_b24_1) {
            if (self->unk_b22_0 != 0) {
                func_ov000_02198360(s, 0x19, 0);
            } else {
                func_ov000_02198360(s, 0x17, 0);
            }
        } else {
            func_ov000_02198360(s, 1, 0);
        }
        break;
    case 1:
        if (LFLD(u16, ((u8 *)self->hp), 0) == 0) {
            func_ov000_02198360(s, 0x14, 0);
            break;
        }
        if (s->flags & 2) {
            break;
        }
    case 2:
        if (self->hit->unk_50 & 0x20000000) {
            if (func_ov000_021a09b8((u8 *)self, data_ov000_021ca168, 0x12)) {
                break;
            }
        } else if (!self->unk_b24_17 && !self->unk_b24_18) {
            if (func_ov000_021a09b8((u8 *)self, data_ov000_021ca100, 0xb)) {
                break;
            }
        }
        s = ((ActorSub40 *)self->fsm);
        if ((u8)(s->current + 0xff) > 1) {
            break;
        }
        if (self->hit->unk_50 & 0x20000000) {
            if (s->flags & 4) {
                func_ov000_02198360(s, 2, 0);
            } else {
                func_ov000_02198360(s, 1, 0);
            }
            break;
        }
        {
            BOOL ok = TRUE;
            if (!GIdle021a0268()) {
                if (self->unk_b24_1 ||
                    ((self->hit->unk_54 & 0x20000000) && !self->unk_b28_3)) {
                    self->speed = 0;
                    self->gravity = 0x52;
                } else {
                    ok = FALSE;
                }
            }
            if (ok) {
                func_ov000_02198360(((ActorSub40 *)self->fsm), 4, 0);
            }
        }
        break;
    }
    func_ov000_0218d7e8(self, self->fsm->current);
}
}
