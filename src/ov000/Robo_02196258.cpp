#include "nitro/fx.h"
#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 1;
    u16 b7 : 1;
    u16 rest : 8;
} Bits02196258;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec02196258;

typedef struct {
    u8 unk_00[0x158];
    u32 flags[1][4];
} Save02196258;

extern "C" {
extern u8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd64;
extern Save02196258 *data_0214a424;
void func_0203f364(void *a);
void *Target_Get(void *p);
void func_ov003_021f0c60(void *self, s32 a);
void Actor_Move(void *self, s32 a);
void func_ov000_0218bed8(void *a, s32 b, void *c);
void *func_02065f88(s32 a, void *b);
void func_02062764(s32 a, s32 b);
void func_020627a0(u16 kind, u16 id);
void func_020627c8(void);
void func_ov000_02182590(u8 *p);
u16 func_0206e7ec(u32 a, u32 b);

static inline s32 FxMul02196258(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline void SetNibble02196258(s32 row, s32 idx, u32 value) {
    s32 sh = idx % 8;
    u32 *p;

    sh *= 4;
    p = &data_0214a424->flags[row][idx / 8];
    *p = (*p & ~(0xf << sh)) | ((value & 0xf) << sh);
}

static inline int GetNibble02196258(s32 row, s32 idx) {
    u32 v = data_0214a424->flags[row][idx / 8];
    return (v >> ((idx % 8) * 4)) & 0xf;
}

struct Die02196258Self {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0x7];
    u8 unk_17;
    u8 unk_18[0x34];
    u8 *unk_4c;
    u8 unk_50[0x5c];
    u8 unk_ac;
    u8 unk_ad;
};

static inline void Die02196258(VObj *obj) {
    Die02196258Self *self = (Die02196258Self *)obj;
    u8 k = LFLD(u8, self->unk_4c, 3);
    if (k != 0xa && k != 0xb) {
        func_02062764(0x3c0, 0x100);
        func_020627a0(self->unk_0e, self->unk_0c);
        {
            u8 *pl = data_ov000_021ccd54;
            pl[0xac] = 1;
            func_ov000_02182590(pl + 0xac);
        }
    }
    {
        u8 idx = self->unk_17;
        s32 row;
        if (idx != 0xff) {
            row = func_0206e7ec(self->unk_ac, self->unk_ad);
            if (row != 0xffff) {
                u8 val = 0xf;
                val |= GetNibble02196258(row, idx) & 8;
                SetNibble02196258(row, idx, val);
            }
        }
    }
    func_020627c8();
    func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
    obj->vfunc_08();
}

void func_ov000_02196258(VObj *obj) {
    ActorEx *self = (ActorEx *)obj;
    s32 zero = 0;
    u8 *t = (u8 *)Target_Get(((u8 *)self->unk_4c));
    ActorSub40 *s = self->unk_40;
    switch (s->st) {
    case 0:
        if (self->unk_44 != NULL) {
            u8 *q = self->unk_44;
            LFLD(Bits02196258, q, 0x22).b0 = 0;
            LFLD(Bits02196258, q, 0x22).b1 = 0;
        }
        if (self->unk_48 != NULL) {
            u8 *q = (u8 *)self->unk_48;
            LFLD(Bits02196258, q, 0x9a).b0 = 0;
            LFLD(Bits02196258, q, 0x9a).b3 = 0;
            func_0203f364(q);
            q = (u8 *)self->unk_48;
            LFLD(Bits02196258, q, 0x9a).b1 = 0;
            LFLD(Bits02196258, q, 0x9a).b4 = 0;
        }
        if (self->unk_58 != NULL) {
            self->unk_cc_0 = 0;
        }
        if (LFLD(u8, ((u8 *)self->unk_4c), 0) == 2) {
            self->unk_40->st = 0x14;
            return;
        }
        self->unk_cc_7 = 1;
        self->unk_40->st++;
        return;
    case 1: {
        u8 *m = ((u8 *)self->unk_4c);
        self->pos.x = LFLD(s32, m, 0x44);
        self->pos.y = LFLD(s32, m, 0x48);
        self->pos.z = LFLD(s32, m, 0x4c);
        self->unk_a4 = zero;
        self->unk_a0 = 0x185;
        if (t != NULL && LFLD(u8, m, 1) == 4) {
            self->unk_9c = 0x19a;
            self->unk_a8 = 0x57;
            self->unk_98 = self->rot_y + 0x8000;
        } else {
            self->unk_9c = zero;
            self->unk_a8 = 5;
        }
        self->unk_40->st++;
    }
    case 2: {
        ActorSub40 *s2 = self->unk_40;
        s2->timer++;
        if (s2->timer > 0xb) {
            if (t != NULL && LFLD(u8, ((u8 *)self->unk_4c), 1) == 4) {
                self->unk_40->timer = 0xc;
            } else {
                self->unk_40->timer = 0x1e;
            }
            self->unk_40->st++;
        }
        Actor_Move(self, 0);
        return;
    }
    case 3:
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            func_ov003_021f0c60(self, 0);
            Die02196258(obj);
            return;
        }
        if (t != NULL && LFLD(u8, ((u8 *)self->unk_4c), 1) == 4) {
            VecFx32 v;
            s32 k = (0xc - self->unk_40->timer) * 0xcd;
            s32 r = 0x1000 - k;
            u8 *mdl;
            v = *(VecFx32 *)(t + 0x70);
            v.y += LFLD(s32, t, 0x6c);
            v.x -= self->pos.x;
            v.y -= self->pos.y;
            v.z -= self->pos.z;
            v.x = FxMul02196258(v.x, k);
            v.y = FxMul02196258(v.y, k);
            v.z = FxMul02196258(v.z, k);
            self->unk_9c = FxMul02196258(r, self->unk_9c);
            self->unk_a0 = FxMul02196258(r, self->unk_a0);
            v.z += self->unk_9c;
            v.y += self->unk_a0;
            VEC_Add((VecFx32 *)((u8 *)self + 0x70), &v, (VecFx32 *)((u8 *)self + 0x70));
            mdl = ((u8 *)self->unk_38);
            {
                VecFx32 *sc = (VecFx32 *)(mdl + 0xa8);
                s32 x, y, z;
                y = FxMul02196258(sc->y, 0xc00);
                z = FxMul02196258(sc->z, 0xc00);
                x = FxMul02196258(sc->x, 0xc00);
                sc->x = x;
                sc->y = y;
                sc->z = z;
            }
            return;
        }
        {
            u32 a = (u8)(0x29 - (0x1e - self->unk_40->timer));
            if (a > 0x1f) {
                a = 0x1f;
            }
            LFLD(u8, ((u8 *)self->unk_38), 0xbe) = a;
        }
        return;
    case 0x14:
        func_ov003_021f0c60(self, 0);
        func_02065f88(0xc8, (u8 *)self + 0x70);
        Die02196258(obj);
        return;
    }
}

}
