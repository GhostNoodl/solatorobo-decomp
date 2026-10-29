#include "ov000/LoCommon.h"
#include "ov000/Actor.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 3;
    u32 f5 : 2;
    u32 f7 : 2;
    u32 b9 : 1;
    u32 b10 : 2;
    u32 mode : 2;
    u32 b14 : 3;
    u32 b17 : 1;
    u32 b18 : 1;
    u32 rest : 13;
} B24_021a0268;

typedef struct {
    u16 lo : 3;
    u16 b3 : 1;
    u16 b4 : 2;
    u16 kind : 3;
    u16 rest : 7;
} B22_021a0268;

typedef struct {
    u8 b0 : 3;
    u8 b3 : 1;
    u8 rest : 4;
} B28_021a0268;

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
    s32 x, y, z;
} Vec021a0268;

typedef struct {
    Vec021a0268 pos;
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
u8 *func_ov000_0218e640(void *mgr, u16 id);

void func_ov000_0218d46c(void *self, u16 id, u8 value);
BOOL func_ov000_02198360(void *s, s32 a, s32 b);
s32 func_ov000_021a09b8(u8 *self, s32 *list, s32 count);
void func_ov000_0218d7e8(void *self, u8 arg);

static inline u8 *GetObj021a0268(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline void Reset021a0268(u8 *self) {
    LFLD(B24_021a0268, self, 0xb24).f5 = 0;
    LFLD(u16, self, 0xb1c) = 0xffff;
    LFLD(u16, self, 0xb1e) = 0xffff;
    LFLD(B24_021a0268, self, 0xb24).f7 = LFLD(B24_021a0268, self, 0xb24).b9;
}

static inline BOOL GBusy021a0268(u8 *g) {
    return LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94) ? TRUE : FALSE;
}

static inline BOOL GIdle021a0268(void) {
    u8 *g = (u8 *)data_ov000_021ccd54;
    if (g != NULL) {
        if (GBusy021a0268(g)) {
            return FALSE;
        }
        if (LFLD(s32, g, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline s32 FxMul021a0268(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

void func_ov000_021a0268(u8 *self) {
    ActorSub40 *s;
    if (LFLD(B22_021a0268, self, 0xb22).kind == 5) {
        func_ov000_021b05b0(self);
        return;
    }
    if (LFLD(B24_021a0268, self, 0xb24).b1) {
        LFLD(void *, self, 0x38) = self + 0x368;
        LFLD(void *, self, 0x48) = self + 0x6c0;
        if (LFLD(B24_021a0268, self, 0xb24).f5 == 2) {
            LFLD(s32, self, 0xb08) = 0x15c;
        } else {
            LFLD(s32, self, 0xb08) = data_ov000_021ca00c[LFLD(G18_021a0268, data_0214a424, 0x18).sel];
        }
        if (LFLD(B22_021a0268, self, 0xb22).b3) {
            LFLD(s32, self, 0xb08) += 0x8f;
        }
        LFLD(s32, self, 0xb08) += func_0206d37c(data_0214a424, 3) * 4;
    } else {
        LFLD(void *, self, 0x38) = self + 0xac;
        LFLD(void *, self, 0x48) = self + 0x2cc;
        LFLD(s32, self, 0xb08) = 0x19a;
    }
    if (LFLD(s32, self, 0xb0c) != 0x1000) {
        LFLD(s32, self, 0xb08) = FxMul021a0268(LFLD(s32, self, 0xb08), LFLD(s32, self, 0xb0c));
    }
    if (LFLD(u16, LFLD(u8 *, self, 0x54), 0) != 0 && LFLD(s16, LFLD(u8 *, self, 0x54), 2) != 0) {
        LFLD(s32, self, 0xb08) = FxMul021a0268(LFLD(s32, self, 0xb08), LFLD(s16, LFLD(u8 *, self, 0x54), 2));
    }
    {
        u16 t = LFLD(u16, LFLD(u8 *, self, 0x54), 4);
        if (t != 0) {
            if (LFLD(u16, self, 0x9ac) > t) {
                LFLD(u16, self, 0x9ac) -= t;
            } else {
                LFLD(u16, self, 0x9ac) = 0;
            }
        }
    }
    s = LFLD(ActorSub40 *, self, 0x40);
    if (s->unk_13 != 0x1f) {
        if (s->flags & 1) {
            u8 *o = GetObj021a0268(LFLD(u16, self, 0xb1c));
            if (o != NULL) {
                Msg021a0268 m;
                m.pos = LFLD(Vec021a0268, self, 0x70);
                m.pos.y += LFLD(s32, self, 0x6c);
                m.rot[0] = LFLD(u16, o, 0x7c);
                m.rot[1] = LFLD(u16, o, 0x7e);
                m.rot[2] = LFLD(u16, o, 0x80);
                m.z = 0;
                func_ov000_0218d398((Actor *)o, LFLD(u16, self, 0xc), 7, 1, 0x18, &m);
                func_ov000_0218d46c(o, LFLD(u16, self, 0xc), 10);
                if (LFLD(u8 *, o, 0x4c) != NULL) {
                    LFLD(C18_021a0268, LFLD(u8 *, o, 0x4c), 0x18).b0 = 0;
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
    s = LFLD(ActorSub40 *, self, 0x40);
    switch (s->unk_13) {
    case 0x16:
        func_ov000_021a09b8(self, data_ov000_021ca100, 0xb);
        break;
    case 3:
        if (func_ov000_021a09b8(self, data_ov000_021ca100, 0xb)) {
            break;
        }
        if (LFLD(B24_021a0268, self, 0xb24).mode != 0) {
            break;
        }
        s = LFLD(ActorSub40 *, self, 0x40);
        if (!(s->flags & 8)) {
            break;
        }
        if (!LFLD(B24_021a0268, self, 0xb24).b1) {
            break;
        }
        func_ov000_02198360(s, 0x16, 0);
        break;
    case 4:
        if (!LFLD(B24_021a0268, self, 0xb24).b17 && !LFLD(B24_021a0268, self, 0xb24).b18) {
            if (func_ov000_021a09b8(self, data_ov000_021ca100, 0xb)) {
                break;
            }
        } else if (s->flags & 0x4000000) {
            func_ov000_02198360(s, 0x1a, 0);
            break;
        }
        s = LFLD(ActorSub40 *, self, 0x40);
        if ((s->flags & 0x2000000) && LFLD(s32, self, 0xa0) <= 0x19a &&
            LFLD(s32, self, 0x74) - LFLD(s32, self, 0xaf4) >= -0x2d000 && LFLD(u16, self, 0xb1c) == 0xffff &&
            !(LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000)) {
            func_ov000_02198360(s, 0x19, 0);
            break;
        }
        if (s->flags & 8) {
            u32 f = LFLD(u32, LFLD(u8 *, self, 0x48), 0x50);
            if ((f & 0x20000000) && !(f & 0x400)) {
                func_ov000_02198360(s, 3, 0);
                break;
            }
            if (LFLD(B24_021a0268, self, 0xb24).b1 && LFLD(B24_021a0268, self, 0xb24).f5 == 0 &&
                LFLD(B24_021a0268, self, 0xb24).mode == 0 && LFLD(s32, self, 0xa0) <= 0x19a &&
                !LFLD(B24_021a0268, self, 0xb24).b17 && !LFLD(B24_021a0268, self, 0xb24).b18) {
                func_ov000_02198360(s, 0x17, 0);
                break;
            }
        }
        if (GIdle021a0268()) {
            break;
        }
        if ((LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x20000000) && !LFLD(B28_021a0268, self, 0xb28).b3) {
            break;
        }
        if (LFLD(B24_021a0268, self, 0xb24).b1) {
            if (LFLD(B22_021a0268, self, 0xb22).lo != 0) {
                func_ov000_02198360(s, 0x19, 0);
            } else {
                func_ov000_02198360(s, 0x17, 0);
            }
        } else {
            func_ov000_02198360(s, 1, 0);
        }
        break;
    case 1:
        if (LFLD(u16, LFLD(u8 *, self, 0x50), 0) == 0) {
            func_ov000_02198360(s, 0x14, 0);
            break;
        }
        if (s->flags & 2) {
            break;
        }
    case 2:
        if (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000) {
            if (func_ov000_021a09b8(self, data_ov000_021ca168, 0x12)) {
                break;
            }
        } else if (!LFLD(B24_021a0268, self, 0xb24).b17 && !LFLD(B24_021a0268, self, 0xb24).b18) {
            if (func_ov000_021a09b8(self, data_ov000_021ca100, 0xb)) {
                break;
            }
        }
        s = LFLD(ActorSub40 *, self, 0x40);
        if ((u8)(s->unk_13 + 0xff) > 1) {
            break;
        }
        if (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000) {
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
                if (LFLD(B24_021a0268, self, 0xb24).b1 ||
                    ((LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x20000000) && !LFLD(B28_021a0268, self, 0xb28).b3)) {
                    LFLD(s32, self, 0x9c) = 0;
                    LFLD(s32, self, 0xa8) = 0x52;
                } else {
                    ok = FALSE;
                }
            }
            if (ok) {
                func_ov000_02198360(LFLD(void *, self, 0x40), 4, 0);
            }
        }
        break;
    }
    func_ov000_0218d7e8(self, LFLD(ActorSub40 *, self, 0x40)->unk_13);
}
}
