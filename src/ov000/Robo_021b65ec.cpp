#include "ov000/Actor.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 r, g, b;
} Rgb021b65ec;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 2;
    u16 b4 : 12;
} ItemBits021b65ec;

typedef struct {
    VecFx32 pos;
    u8 unk_0c[8];
    s16 hx, hy, hz;
    u16 rot;
    ItemBits021b65ec bits;
    u8 unk_1e[2];
    Rgb021b65ec col;
    u8 unk_23;
} Item021b65ec;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 3;
    u32 b5 : 2;
    u32 b7 : 2;
    u32 b9 : 1;
    u32 b10 : 22;
} B24_021b65ec;

typedef struct {
    s16 x, y, z;
} Rot021b65ec;

extern "C" {

extern ActorMgr *data_ov000_021ccd68;
extern void *data_02fe152c;
u8 *func_ov000_0219bf90(void);
Actor *func_ov000_0218e640(ActorMgr *mgr, u16 id);
void func_ov000_021b13cc(u8 *pl, s32 a);
void func_ov000_021b12c0(u8 *pl, s32 a);
u16 func_020594bc(void *a, s32 b, s32 c, s32 d);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);

static inline Actor *FindActor021b65ec(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline void PlSetPos021b65ec(u8 *pl, const VecFx32 *pos, s16 rx, s16 ry, s16 rz) {
    LFLD(VecFx32, pl, 0x75c) = *pos;
    LFLD(s16, pl, 0x76c) = rx;
    LFLD(s16, pl, 0x76e) = ry;
    LFLD(s16, pl, 0x770) = rz;
}

static inline void PlSetCol021b65ec(u8 *pl, u8 r, u8 g, u8 b) {
    LFLD(u8, pl, 0x772) = r;
    LFLD(u8, pl, 0x773) = g;
    LFLD(u8, pl, 0x774) = b;
}

static inline Rgb021b65ec *PlCol021b65ec(u8 *pl) {
    return &LFLD(Rgb021b65ec, pl, 0x772);
}

static inline BOOL SameCol021b65ec(const Rgb021b65ec *a, const Rgb021b65ec *b) {
    BOOL r = FALSE;
    if (a->r == b->r && a->g == b->g && a->b == b->b) {
        r = TRUE;
    }
    return r;
}

void func_ov000_021b65ec(u8 *self) {
    u8 *g;
    u8 *pl;
    Item021b65ec *item;
    // DECL-END
    pl = func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    item = &LFLD(Item021b65ec *, self, 0x18)[LFLD(u8, self, 0xb)];
    g = (u8 *)data_ov000_021ccd54;
    if (item->bits.b1 && LFLD(B24_021b65ec, pl, 0xb24).b5) {
        Actor *a = FindActor021b65ec(LFLD(u16, pl, 0xb1c));
        if (a != NULL && LFLD(u8 *, a, 0x4c) != NULL) {
            LFLD(u16, LFLD(u8 *, a, 0x4c), 0x1c) = 0xffff;
        }
        LFLD(u16, pl, 0xb1c) = 0xffff;
        LFLD(u16, pl, 0xb1e) = 0xffff;
        LFLD(B24_021b65ec, pl, 0xb24).b5 = 0;
        LFLD(B24_021b65ec, pl, 0xb24).b7 = LFLD(B24_021b65ec, pl, 0xb24).b9;
    }
    switch (item->bits.b2) {
    case 1:
        if (!LFLD(B24_021b65ec, pl, 0xb24).b1) {
            return;
        }
        func_ov000_021b13cc(pl, 0);
        { typedef struct { u8 c[3]; } C3; LFLD(C3, pl, 0x772) = LFLD(C3, g, 0xd0); }
        {
            VecFx32 v;
            v.x = item->hx << 4;
            v.y = item->hy << 4;
            v.z = item->hz << 4;
            VEC_Add(&v, &item->pos, &v);
            PlSetPos021b65ec(pl, &v, 0, item->rot, 0);
        }
        break;
    case 2: {
        Rgb021b65ec c;
        if (LFLD(B24_021b65ec, pl, 0xb24).b1 ? TRUE : FALSE) {
            return;
        }
        c.r = item->col.r;
        c.g = item->col.g;
        c.b = item->col.b;
        if (c.r == 0xff) {
            c.r = LFLD(u8, g, 0xd0);
        }
        if (c.g == 0xff) {
            c.g = LFLD(u8, g, 0xd1);
        }
        if (c.b == 0xff) {
            c.b = LFLD(u8, g, 0xd2);
        }
        if (!SameCol021b65ec(&c, PlCol021b65ec(pl))) {
            return;
        }
        func_ov000_021b12c0(pl, 0);
        break;
    }
    case 3: {
        Rgb021b65ec c;
        if (func_020594bc(data_02fe152c, 5, 1, 0) != 1) {
            return;
        }
        if (LFLD(B24_021b65ec, pl, 0xb24).b1 ? TRUE : FALSE) {
            return;
        }
        func_ov000_021b12c0(pl, 0);
        ((u8 *)&c)[0] = ((u8 *)&item->col)[0];
        if (((u8 *)&c)[0] == 0xff) {
            ((u8 *)&c)[0] = LFLD(u8, g, 0xd0);
        }
        ((u8 *)&c)[1] = ((u8 *)&item->col)[1];
        if (((u8 *)&c)[1] == 0xff) {
            ((u8 *)&c)[1] = LFLD(u8, g, 0xd1);
        }
        ((u8 *)&c)[2] = ((u8 *)&item->col)[2];
        if (((u8 *)&c)[2] == 0xff) {
            ((u8 *)&c)[2] = LFLD(u8, g, 0xd2);
        }
        LFLD(Rgb021b65ec, pl, 0x772) = c;
        break;
    }
    }
}

}
