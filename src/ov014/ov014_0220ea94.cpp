#include "ov014/ov014.h"

extern "C" {

extern void *data_0214a420;
extern void *data_02097e4c;
extern u8 *data_02097d48;
extern u8 data_ov014_02217aac[];
extern u8 data_ov014_02217c6c[];
extern void EffectMgr_StopLoop(void *a, void *b);
extern void func_ov000_02195d88(void *self);
extern void func_ov000_0219763c(void *self);
extern Ov003Actor *Target_Get(void *p);
extern Ov003Actor *func_ov000_0219bf90(void);
extern s32 func_ov000_0219a510(Actor *self, u16 mask, VecFx32 *pos, s32 r, s32 a, Ov003Actor **list);
extern Ov003Actor *func_ov000_021985c0(Ov003Actor *p);
extern s32 **func_ov000_02190a30(void *a, s32 b);
extern s32 func_ov000_02191318(void *a, s32 b);
extern s32 func_ov000_02191f18(void *a, void *b);
extern s32 func_ov014_0220ec18(s16 *a, u8 *b);
extern void *ActorEx_Ctor(void *self);
extern void func_ov000_02194758(void *self);
extern BOOL func_ov000_02194c08(void *self);
extern void func_02049de8(void *a, s32 b);
extern u8 Gfx3DState_NextPolyId(void *p);
extern void func_ov000_02191920(void *a, s32 b, s32 c, s32 d);
extern void func_ov000_02191618(void *p);
extern void func_ov000_02191708(void *p);

extern VecFx32 *func_ov000_0218d2e0(void *self);
extern BOOL func_ov014_0220eb14(Actor *self);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, VecFx32 *v, s32 f, s32 g, s32 h, s32 i, s32 j);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);

#define OV014Y_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014Y_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014Y_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline s32 Ov014y_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov014_0220e72c(Ov014ActEx_0220dcf4 *self) {
    switch (self->fsm->st) {
    case 0: {
        VecFx32 *p;
        {
            ActorSub4c *m = self->targetObj;
            m->unk_50 = 0x1000;
            m->unk_54 = 0x29;
            m->unk_58 = 0;
        }
        self->hit->unk_30 = 0;
        p = func_ov000_0218d2e0(self);
        if (p != NULL) {
            VecFx32 d;
            s32 r;
            s32 dx;
            s32 dz;
            d = *p;
            d.y = d.y - self->pos.y;
            {
                s64 sq;
                dx = self->pos.x - d.x;
                dz = self->pos.z - d.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                OV014Y_SQRTCNT = 1;
                OV014Y_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV014Y_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014Y_SQRT_RESULT + 1) >> 1;
            d.x = FX_Mul(r, OV014_SIN(self->rot_y));
            d.z = FX_Mul(r, OV014_COS(self->rot_y));
            VEC_Normalize(&d, &d);
            self->speed = Ov014y_FxMul64(d.x, 0x800);
            self->velY = Ov014y_FxMul64(d.y, 0x800);
            self->friction = Ov014y_FxMul64(d.z, 0x800);
        } else {
            self->speed = OV014_SIN(self->rot_y);
            self->friction = OV014_COS(self->rot_y);
            self->speed = Ov014y_FxMul64(self->speed, 0x800);
            self->velY = Ov014y_FxMul64(self->velY, 0x800);
            self->friction = Ov014y_FxMul64(self->friction, 0x800);
        }
        {
            ActorSub48 *m = self->hit;
            m->unk_50 = 0;
            m->unk_54 = 0;
            FLD(u32, m, 0x58) = 0;
        }
        EffectMgr_StopLoop(data_0214a420, self->unk_d0);
        self->unk_d0 = NULL;
        self->fsm->st++;
        break;
    }
    case 1: {
        void *a;
        VecFx32 v;
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        if (!(self->hit->unk_50 & 0xe0000000) && !func_ov014_0220eb14(self)) {
            return;
        }
        a = Target_Get(self->targetObj);
        v.x = self->pos.x - FLD(s32, self, 0x70);
        v.y = self->pos.y - FLD(s32, self, 0x74);
        v.z = self->pos.z - FLD(s32, self, 0x78);
        func_ov000_0219aae8(self, a, self->targetObj->unk_08, self->targetObj->unk_0a, 0x20, &v, 0,
                            0x4000, 0, 3, 0x1000);
        func_02049f44(data_02097e4c, 0x82, &self->pos, 0);
        self->targetObj->unk_02 = 0;
        func_ov000_02198360(self->fsm, 0x15, 0);
        break;
    }
    }
}

void func_ov014_0220ea94(Ov014ActEx_0220dcf4 *self) {
    if (self->fsm->st == 0) {
        EffectMgr_StopLoop(data_0214a420, self->unk_d0);
        self->unk_d0 = NULL;
    }
    func_ov000_02195d88(self);
}

void func_ov014_0220ead4(Ov014ActEx_0220dcf4 *self) {
    if (self->fsm->st == 0) {
        EffectMgr_StopLoop(data_0214a420, self->unk_d0);
        self->unk_d0 = NULL;
    }
    func_ov000_0219763c(self);
}

BOOL func_ov014_0220eb14(Actor *self) {
    Ov003Actor *list[0x20];
    BOOL r = FALSE;
    Ov003Actor *o;
    Ov003Actor *p;
    u16 k;
    s32 i;
    u16 mask;
    s32 rad;
    s32 n;
    o = Target_Get(self->targetObj);
    p = func_ov000_0219bf90();
    if (o == NULL || p == NULL) {
        return FALSE;
    }
    k = o->id & 0xf000;
    mask = ~(1 << (k >> 12));
    rad = self->radius;
    if (o->kind == 0x1000) {
        rad = rad + 0x4cd;
    } else if (FLD(u16, p, 0xb1e) == self->id) {
        rad >>= 1;
    }
    n = func_ov000_0219a510(self, mask, &self->pos, rad, 0, list);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            Ov003Actor *q;
            if (list[i] != NULL && (q = func_ov000_021985c0(list[i])) != NULL) {
                ActorSub4c *s = q->targetObj;
                if (s == NULL || k != (u16)(s->target & 0xf000)) {
                    r = TRUE;
                    break;
                }
            }
        }
    }
    return r;
}


// The result is kept in the parameter slot: the original reuses a's register
// for the return value.
s32 func_ov014_0220ec18(s16 *a, u8 *b) {
    s32 **q;
    s32 prev;
    if (a[0] == 5) {
        prev = 0;
        q = func_ov000_02190a30(b, 0);
        if (q != NULL && *q != NULL) {
            prev = **q;
        }
        a = (s16 *)func_ov000_02191318(b, ((u16 *)a)[1] << 12);
        if (q != NULL) {
            s32 cur = (*q != NULL) ? **q : 0;
            if (prev >= cur) {
                FLD(u32, b, 0xe4) |= 0x20000000;
            }
        }
    } else {
        a = (s16 *)func_ov000_02191f18(a, b);
    }
    return (s32)a;
}

}
