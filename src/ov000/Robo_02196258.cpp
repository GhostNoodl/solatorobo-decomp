#include "nitro/fx.h"
#include "ov000/VObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u16 st;
    u16 timer;
} State02196258;

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
void *func_ov000_02199ba0(void *p);
void func_ov003_021f0c60(void *self, s32 a);
void func_ov000_0218dbe0(void *self, s32 a);
void func_ov000_0218bed8(void *a, s32 b, void *c);
void func_02065f88(s32 a, void *b);
void func_02062764(s32 a, s32 b);
void func_020627a0(u16 kind, u16 id);
void func_020627c8(void);
void func_ov000_02182590(u8 *p);
s32 func_0206e7ec(u32 a, u32 b);

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

static inline void Die02196258(VObj *obj) {
    u8 *self = (u8 *)obj;
    u8 k = LFLD(u8, LFLD(u8 *, self, 0x4c), 3);
    if (k != 0xa && k != 0xb) {
        func_02062764(0x3c0, 0x100);
        func_020627a0(LFLD(u16, self, 0xe), LFLD(u16, self, 0xc));
        {
            u8 *pl = data_ov000_021ccd54;
            pl[0xac] = 1;
            func_ov000_02182590(pl + 0xac);
        }
    }
    {
        u8 idx = LFLD(u8, self, 0x17);
        s32 row;
        if (idx != 0xff) {
            row = func_0206e7ec(LFLD(u8, self, 0xac), LFLD(u8, self, 0xad));
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
    u8 *self = (u8 *)obj;
    s32 zero = 0;
    u8 *t = (u8 *)func_ov000_02199ba0(LFLD(u8 *, self, 0x4c));
    State02196258 *s = LFLD(State02196258 *, self, 0x40);
    switch (s->st) {
    case 0:
        if (LFLD(u8 *, self, 0x44) != NULL) {
            u8 *q = LFLD(u8 *, self, 0x44);
            LFLD(Bits02196258, q, 0x22).b0 = 0;
            LFLD(Bits02196258, q, 0x22).b1 = 0;
        }
        if (LFLD(u8 *, self, 0x48) != NULL) {
            u8 *q = LFLD(u8 *, self, 0x48);
            LFLD(Bits02196258, q, 0x9a).b0 = 0;
            LFLD(Bits02196258, q, 0x9a).b3 = 0;
            func_0203f364(q);
            q = LFLD(u8 *, self, 0x48);
            LFLD(Bits02196258, q, 0x9a).b1 = 0;
            LFLD(Bits02196258, q, 0x9a).b4 = 0;
        }
        if (LFLD(void *, self, 0x58) != NULL) {
            LFLD(Bits02196258, self, 0xcc).b0 = 0;
        }
        if (LFLD(u8, LFLD(u8 *, self, 0x4c), 0) == 2) {
            LFLD(State02196258 *, self, 0x40)->st = 0x14;
            return;
        }
        LFLD(Bits02196258, self, 0xcc).b7 = 1;
        LFLD(State02196258 *, self, 0x40)->st++;
        return;
    case 1: {
        u8 *m = LFLD(u8 *, self, 0x4c);
        LFLD(s32, self, 0x70) = LFLD(s32, m, 0x44);
        LFLD(s32, self, 0x74) = LFLD(s32, m, 0x48);
        LFLD(s32, self, 0x78) = LFLD(s32, m, 0x4c);
        LFLD(s32, self, 0xa4) = zero;
        LFLD(s32, self, 0xa0) = 0x185;
        if (t != NULL && LFLD(u8, m, 1) == 4) {
            LFLD(s32, self, 0x9c) = 0x19a;
            LFLD(s32, self, 0xa8) = 0x57;
            LFLD(u16, self, 0x98) = LFLD(u16, self, 0x7e) + 0x8000;
        } else {
            LFLD(s32, self, 0x9c) = zero;
            LFLD(s32, self, 0xa8) = 5;
        }
        LFLD(State02196258 *, self, 0x40)->st++;
    }
    case 2: {
        State02196258 *s2 = LFLD(State02196258 *, self, 0x40);
        s2->timer++;
        if (s2->timer > 0xb) {
            if (t != NULL && LFLD(u8, LFLD(u8 *, self, 0x4c), 1) == 4) {
                LFLD(State02196258 *, self, 0x40)->timer = 0xc;
            } else {
                LFLD(State02196258 *, self, 0x40)->timer = 0x1e;
            }
            LFLD(State02196258 *, self, 0x40)->st++;
        }
        func_ov000_0218dbe0(self, 0);
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
        if (t != NULL && LFLD(u8, LFLD(u8 *, self, 0x4c), 1) == 4) {
            VecFx32 v;
            s32 k = (0xc - LFLD(State02196258 *, self, 0x40)->timer) * 0xcd;
            s32 r = 0x1000 - k;
            u8 *mdl;
            v = *(VecFx32 *)(t + 0x70);
            v.y += LFLD(s32, t, 0x6c);
            v.x -= LFLD(s32, self, 0x70);
            v.y -= LFLD(s32, self, 0x74);
            v.z -= LFLD(s32, self, 0x78);
            v.x = FxMul02196258(v.x, k);
            v.y = FxMul02196258(v.y, k);
            v.z = FxMul02196258(v.z, k);
            LFLD(s32, self, 0x9c) = FxMul02196258(r, LFLD(s32, self, 0x9c));
            LFLD(s32, self, 0xa0) = FxMul02196258(r, LFLD(s32, self, 0xa0));
            v.z += LFLD(s32, self, 0x9c);
            v.y += LFLD(s32, self, 0xa0);
            VEC_Add((VecFx32 *)(self + 0x70), &v, (VecFx32 *)(self + 0x70));
            mdl = LFLD(u8 *, self, 0x38);
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
            u32 a = (u8)(0x29 - (0x1e - LFLD(State02196258 *, self, 0x40)->timer));
            if (a > 0x1f) {
                a = 0x1f;
            }
            LFLD(u8, LFLD(u8 *, self, 0x38), 0xbe) = a;
        }
        return;
    case 0x14:
        func_ov003_021f0c60(self, 0);
        func_02065f88(0xc8, self + 0x70);
        Die02196258(obj);
        return;
    }
}

}
