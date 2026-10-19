#include "ov000/LoCommon.h"
#include "nitro/fx.h"

typedef struct {
    u8 type;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03[0x15];
    u8 b0 : 5;
    u8 b5 : 1;
    u8 b6 : 2;
    u8 unk_19[3];
    u16 target;
} Tgt0219af3c;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
} PBits0219af3c;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 3;
    u32 b5 : 2;
    u32 rest : 25;
} PlBits0219af3c;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 rest : 14;
} Bits22_0219af3c;

extern "C" {
extern void *data_ov000_021ccd68;
u8 *func_ov000_0219bf90(void);
u8 *func_ov000_0218e640(void *mgr, u16 id);
BOOL func_ov000_02199cd8(Tgt0219af3c *self, u16 id);
BOOL func_01ffc198(VecFx32 *a, VecFx32 *b, s32 r);
BOOL func_ov000_021bd314(void *p, s32 x);

static inline s32 Cur0219af3c(u8 *self) {
    u8 *h = LFLD(u8 *, self, 0x40);
    return h != NULL ? h[0x13] : 0;
}

static inline u8 *FindActor0219af3c(u16 id) {
    void *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(mgr, id);
}

static inline u16 Kind0219af3c(u16 id) {
    return id & 0xf000;
}

static inline BOOL Both0219af3c(u8 *p) {
    return LFLD(Bits22_0219af3c, p, 0x22).b0 == 1 && LFLD(Bits22_0219af3c, p, 0x22).b1 == 1 ? TRUE : FALSE;
}

static inline BOOL Special0219af3c(Tgt0219af3c *t) {
    u8 type, a, b;
    BOOL r;
    type = t->type;
    b = t->unk_02;
    a = t->unk_01;
    r = FALSE;
    if (type == 0xe || type == 0xf || type == 0x13) {
        if (a == 1 || a == 2 || a == 6) {
            if (b != 1 && b != 2 && b != 4) {
                r = TRUE;
            }
        }
    }
    return r;
}

void func_ov000_0219af3c(u8 *self, u8 *p) {
    u8 *pl;
    Tgt0219af3c *tgt;
    u8 type;
    s32 r4;
    s32 act;
    LFLD(PBits0219af3c, p, 0).b1 = 0;
    r4 = 0;
    pl = func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    if (LFLD(PlBits0219af3c, pl, 0xb24).b0 || LFLD(u16, pl, 0xb1e) != 0xffff) {
        return;
    }
    if (Cur0219af3c(self) == 9) {
        return;
    }
    if (Cur0219af3c(self) == 6 || LFLD(u8 *, self, 0x44) == NULL) {
        return;
    }
    if (!Both0219af3c(LFLD(u8 *, self, 0x44)) || LFLD(u16, self, 0xc) == LFLD(u16, pl, 0xb20) ||
        (tgt = LFLD(Tgt0219af3c *, self, 0x4c)) == NULL || tgt->target == LFLD(u16, pl, 0xc)) {
        return;
    }
    type = tgt->type;
    if (LFLD(u16, pl, 0x90) != LFLD(u16, self, 0xc)) {
        if (Cur0219af3c(self) == 0xb || type == 0 || type == 2 || type == 9 || type == 0xa || type == 0xb ||
            type == 0x11 || Kind0219af3c(LFLD(u16, self, 0xc)) == 0x5000) {
            return;
        }
        if (tgt->b5) {
            return;
        }
        if (!(LFLD(PlBits0219af3c, pl, 0xb24).b1 ? TRUE : FALSE)) {
            if (type == 1) {
                return;
            }
            if (type == 0x15) {
                return;
            }
        } else if (type == 1) {
            u8 *a;
            if (LFLD(u16, pl, 0xb1c) == 0xffff) {
                return;
            }
            a = FindActor0219af3c(LFLD(u16, pl, 0xb1c));
            if (a == NULL) {
                return;
            }
            if (!func_ov000_02199cd8(tgt, LFLD(u16, a, 0xe))) {
                return;
            }
        }
        {
            VecFx32 v;
            v.x = LFLD(VecFx32, self, 0x70).x;
            v.y = LFLD(VecFx32, self, 0x70).y;
            v.z = LFLD(VecFx32, self, 0x70).z;
            if (!func_01ffc198(&LFLD(VecFx32, pl, 0x70), &v, LFLD(s32, pl, 0x64) + 0x6000)) {
                return;
            }
        }
        r4 = 1;
        if ((u8)(type + 0xfa) <= 2) {
            r4 = 0;
        } else if (!(LFLD(PlBits0219af3c, pl, 0xb24).b1 ? TRUE : FALSE)) {
            if (type == 5 || type == 4 || ((u8)(type + 0xf2) <= 1 && tgt->unk_02 == 1) || Special0219af3c(tgt)) {
                r4 = 0;
            }
        }
        func_ov000_021bd314(p, 1);
        if (LFLD(s32, p, 0x44) == 1) {
            LFLD(s32, p, 0x98) = r4;
        } else {
            LFLD(s32, p, 0x28) = r4;
        }
        LFLD(PBits0219af3c, p, 0).b1 = 1;
        return;
    }
    act = -1;
    if (LFLD(PlBits0219af3c, pl, 0xb24).b1) {
        if (LFLD(PlBits0219af3c, pl, 0xb24).b5) {
            act = 4;
        } else if (type == 4 || type == 0xc || type == 0xd || (u8)(type + 0xef) <= 3) {
            act = 4;
        } else if (type == 5 || (u8)(type + 0xf2) <= 1) {
            act = 3;
        } else if (type == 0x10) {
            act = 6;
        } else if (type != 2) {
            act = 7;
        }
    } else {
        if (type == 4 || type == 6 || type == 9 || type == 0xa || type == 0xb || type == 0x11) {
            act = 4;
        } else if (type == 5 || type == 7) {
            act = 4;
        } else if (type == 8) {
            act = 6;
        } else if (((u8)(type + 0xf2) <= 1 && tgt->unk_02 == 1) || Special0219af3c(tgt) || Kind0219af3c(LFLD(u16, self, 0xe)) == 0x5000) {
            act = 4;
        } else if (type != 2) {
            act = 7;
        }
    }
    if (act == 3 || act == 4 || act == 6) {
        LFLD(s32, p, 0x28) = r4;
    }
    if (act == -1) {
        return;
    }
    func_ov000_021bd314(p, act);
    LFLD(PBits0219af3c, p, 0).b1 = 1;
}
}
