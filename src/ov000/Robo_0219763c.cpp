#include "nitro/fx.h"
#include "ov000/VObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u16 st;
    u16 timer;
} State0219763c;

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
} Bits0219763c;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec0219763c;

typedef struct {
    u8 unk_00[0x158];
    u32 flags[1][4];
} Save0219763c;

typedef struct {
    s16 snd;
    s16 fx0;
    s16 scale0;
    s16 fx1;
    s16 scale1;
    u8 a;
    u8 b;
} Ent0219763c;

extern "C" {
extern u8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd64;
extern Save0219763c *data_0214a424;
extern Ent0219763c data_ov000_021c9ecc[];
extern void *data_02097e4c;
void func_0203f364(void *a);
void func_ov000_0218bed8(void *a, s32 b, void *c);
VObj *func_02065f88(s32 a, void *b);
void func_020627a0(u16 kind, u16 id);
void func_020627dc(u16 sfx);
void func_020627c8(void);
void func_ov000_02182590(u8 *p);
u16 func_0206e7ec(u32 a, u32 b);
void *func_ov000_0219bf90(void);
BOOL func_ov000_021b4738(void);
void MIi_CpuClear32(u32 data, void *dst, u32 size);
void *func_02049f44(void *mgr, s32 id, void *pos, s32 a);
void func_ov000_0218996c(u8 a, u8 b);
u8 *func_020704b4(u16 id);
void func_ov000_0219b400(u16 *ids, u8 *rates, s32 n, void *pos, void *rot, u8 check);
void func_ov000_02198c8c(void *p, u16 id);

static inline void SetNibble0219763c(s32 row, s32 idx, u32 value) {
    s32 sh = idx % 8;
    u32 *p;

    sh *= 4;
    p = &data_0214a424->flags[row][idx / 8];
    *p = (*p & ~(0xf << sh)) | ((value & 0xf) << sh);
}

static inline int GetNibble0219763c(s32 row, s32 idx) {
    u32 v = data_0214a424->flags[row][idx / 8];
    return (v >> ((idx % 8) * 4)) & 0xf;
}

static inline void Die0219763c(VObj *obj) {
    u8 *self = (u8 *)obj;
    {
        u8 idx = LFLD(u8, self, 0x17);
        s32 row;
        if (idx != 0xff) {
            row = func_0206e7ec(LFLD(u8, self, 0xac), LFLD(u8, self, 0xad));
            if (row != 0xffff) {
                u8 val = 0xf;
                val |= GetNibble0219763c(row, idx) & 8;
                SetNibble0219763c(row, idx, val);
            }
        }
    }
    if (func_ov000_0219bf90() != NULL && !func_ov000_021b4738()) {
        func_020627a0(LFLD(u16, self, 0xe), LFLD(u16, self, 0xc));
        func_020627dc(0x63);
        {
            u8 *pl = data_ov000_021ccd54;
            pl[0xac] = 1;
            func_ov000_02182590(pl + 0xac);
        }
    }
    func_020627c8();
    func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
    obj->vfunc_08();
}

static inline void Spawn0219763c(u8 *self, s16 id, const s16 *scale, Vec0219763c *p) {
    VObj *fx = func_02065f88(id, p);
    s32 s = *scale << 4;
    if (s == 0) {
        s = LFLD(s32, self, 0x64) + (LFLD(s32, self, 0x64) >> 3);
    }
    fx->vfunc_0c(s);
    if (!LFLD(Bits0219763c, self, 0xcc).b5) {
        MIi_CpuClear32(-1, (u8 *)fx + 0x84, 0x40);
    }
}

void func_ov000_0219763c(VObj *obj) {
    u8 *self = (u8 *)obj;
    s32 zero = 0;
    State0219763c *s = LFLD(State0219763c *, self, 0x40);
    switch (s->st) {
    case 0: {
        u8 *t = LFLD(u8 *, self, 0x4c);
        Ent0219763c *e = (Ent0219763c *)zero;
        Vec0219763c p;
        if (t != NULL) {
            if (t[2] != 1 && t[2] != 2) {
                Die0219763c(obj);
                return;
            }
            {
                u16 id = LFLD(u16, t, 6);
                if (id >= 0x14) {
                    id = 0;
                }
                e = &data_ov000_021c9ecc[id];
            }
        }
        p = *(Vec0219763c *)(self + 0x70);
        p.y += LFLD(s32, self, 0x6c) + (LFLD(s32, self, 0x6c) >> 1);
        if (e != NULL) {
            if (e->fx0 != -1) {
                Spawn0219763c(self, e->fx0, &e->scale0, &p);
            }
            if (e->fx1 != -1) {
                Spawn0219763c(self, e->fx1, &e->scale1, &p);
            }
            if (e->snd >= 0 && LFLD(Bits0219763c, self, 0xcc).b5) {
                func_02049f44(data_02097e4c, e->snd, self + 0x70, 0);
            }
            if (e->a != 0 && e->b != 0) {
                func_ov000_0218996c(e->a, e->b);
            }
        }
        {
            u8 *r = func_020704b4(LFLD(u16, self, 0xe));
            func_ov000_0219b400((u16 *)(r + 0x20), r + 0x24, 2, &p, self + 0x7c, zero);
        }
        if (LFLD(u8 *, self, 0x44) != NULL) {
            u8 *q = LFLD(u8 *, self, 0x44);
            LFLD(Bits0219763c, q, 0x22).b0 = 0;
            LFLD(Bits0219763c, q, 0x22).b1 = 0;
        }
        if (LFLD(u8 *, self, 0x48) != NULL) {
            u8 *q;
            func_ov000_02198c8c(LFLD(u8 *, self, 0x48), 0xffff);
            q = LFLD(u8 *, self, 0x48);
            LFLD(Bits0219763c, q, 0x9a).b0 = 0;
            LFLD(Bits0219763c, q, 0x9a).b3 = 0;
            func_0203f364(q);
            q = LFLD(u8 *, self, 0x48);
            LFLD(Bits0219763c, q, 0x9a).b1 = 0;
            LFLD(Bits0219763c, q, 0x9a).b4 = 0;
        }
        if (LFLD(void *, self, 0x58) != NULL) {
            LFLD(Bits0219763c, self, 0xcc).b0 = 0;
        }
        LFLD(State0219763c *, self, 0x40)->st++;
        return;
    }
    case 1:
        s->timer++;
        if (s->timer > 5) {
            Die0219763c(obj);
            return;
        }
        if (LFLD(u8 *, self, 0x38) != NULL) {
            LFLD(u8, LFLD(u8 *, self, 0x38), 0xbe) = 0x1f - (LFLD(State0219763c *, self, 0x40)->timer << 2);
        }
        return;
    }
}

}
