#include "ov000/Actor.h"
#include "ov000/LoCommon.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 10;
    u32 mode : 2;
    u32 b14 : 2;
    u32 b16 : 1;
    u32 rest : 15;
} B24_0219e998;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 rest : 13;
} B2c_0219e998;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 rest : 12;
} B22_0219e998;

typedef struct {
    u8 b0 : 5;
    u8 f5 : 2;
    u8 b7 : 1;
} B93_0219e998;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 3;
    u8 b4 : 1;
    u8 rest : 3;
} B29_0219e998;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
} Bd_0219e998;

typedef struct {
    u16 b0 : 5;
    u16 b5 : 1;
    u16 rest : 10;
} B9a_0219e998;

extern "C" {

void func_ov000_021bd300(void *p);
VObj *func_02065f88(s32 id, void *pos);
BOOL func_ov000_0218d494(Actor *self, ActorMsg *msg);

static inline void MinB32_0219e998(u8 *self, u16 n) {
    if (LFLD(u16, self, 0xb32) < n) {
        LFLD(u16, self, 0xb32) = n;
    }
}

// g is a local; as a trailing parameter it gets the target's registers.
BOOL func_ov000_0219e998(Actor *self, ActorMsg *msg, u8 *g) {
    u8 *s = (u8 *)self;
    BOOL callBase;
    BOOL ok;
    if (!self->vfunc_14()) {
        u8 t = msg->type;
        if (t == 9 || t == 0xb || (u8)(t + 0xf9) <= 1) {
            self->msg_flags |= 1 << t;
            msg->type = 0;
            return TRUE;
        }
        return FALSE;
    }
    ok = TRUE;
    callBase = ok;
    switch (msg->type) {
    case 9:
        callBase = FALSE;
        if (!LFLD(B29_0219e998, s, 0xb29).b0 && LFLD(u16, LFLD(u8 *, s, 0x50), 0xa) == 0) {
            g = (u8 *)data_ov000_021ccd54;
            if (g != NULL) {
                ok = LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94) ? TRUE : FALSE;
                if (ok) {
                    ok = FALSE;
                } else {
                    if (LFLD(s32, g, 0) != 3) ok = FALSE; else ok = TRUE;
                }
            }
        if (ok) {
            u16 dmg;
            u16 hp;
            s32 bit;
            u8 kind;
            u8 *p50 = LFLD(u8 *, s, 0x50);
            LFLD(u16, p50, 4) = msg->id;
            dmg = *(u16 *)msg->data;
            if (LFLD(u8, LFLD(u8 *, s, 0x40), 0x13) == 0x16 && !(LFLD(u32, LFLD(u8 *, s, 0x48), 0x50) & 0x20000000)) {
                dmg += dmg / 2;
            }
            if (LFLD(B93_0219e998, s, 0x93).f5 != 0 && dmg > 1) {
                dmg = dmg / 2;
            }
            p50 = LFLD(u8 *, s, 0x50);
            if (dmg >= LFLD(u16, p50, 0)) {
                LFLD(u16, p50, 0) = 0;
            } else {
                LFLD(u16, p50, 0) -= dmg;
            }
            bit = 0;
            hp = LFLD(u16, p50, 0);
            kind = msg->data[2];
            MinB32_0219e998(s, 0x5a);
            if (hp != 0) {
                u32 mode = LFLD(B24_0219e998, s, 0xb24).mode;
                if ((mode == 0 || mode == 3) && !LFLD(B2c_0219e998, s, 0xb2c).b0 && !LFLD(B2c_0219e998, s, 0xb2c).b1 &&
                    !LFLD(B2c_0219e998, s, 0xb2c).b2 && (!LFLD(B22_0219e998, s, 0xb22).b3 || kind == 0x50)) {
                    switch (kind) {
                    case 0x10:
                    case 0x11:
                        bit = 0x12;
                        if (!(LFLD(u32, LFLD(u8 *, s, 0x48), 0x50) & 0x20000000) || mode == 3) {
                            MinB32_0219e998(s, 0x96);
                            bit = 0x13;
                            kind = 0x20;
                        }
                        break;
                    case 0x20:
                    case 0x21:
                    case 0x30:
                    case 0x31:
                    case 0x50:
                        bit = 0x13;
                        MinB32_0219e998(s, 0x96);
                        break;
                    }
                }
            } else if (LFLD(B24_0219e998, s, 0xb24).mode - 1 <= 1) {
                LFLD(u16, LFLD(u8 *, s, 0x50), 0) = 1;
            } else {
                LFLD(B24_0219e998, s, 0xb24).b0 = 1;
                LFLD(B93_0219e998, s, 0x93).f5 = 0;
                MinB32_0219e998(s, 0x96);
                LFLD(u16, s, 0x90) = 0xffff;
                LFLD(Bd_0219e998, LFLD(u8 *, s, 0x5c), 0).b1 = 0;
                bit = 0x13;
                kind = 0x20;
                func_ov000_021bd300(LFLD(void *, s, 0x5c));
                LFLD(Bd_0219e998, LFLD(u8 *, s, 0x9b0), 0).b1 = 0;
                func_ov000_021bd300(LFLD(void *, s, 0x9b0));
            }
            p50 = LFLD(u8 *, s, 0x50);
            LFLD(u16, p50, 6) = dmg;
            LFLD(u8, p50, 8) = kind;
            LFLD(u8, p50, 9) = kind;
            if (bit != 0) {
                ((ActorSub40 *)self->unk_40)->flags |= (u64)1 << bit;
            }
            if (msg->data[2] != 1) {
                LFLD(u16, LFLD(u8 *, s, 0x50), 0xa) = 0x5a;
            } else {
                LFLD(u16, LFLD(u8 *, s, 0x50), 0xa) = 10;
            }
            {
                u8 *m = LFLD(u8 *, s, 0x38);
                LFLD(u16, m, 0xb6) = 0x14bf;
                LFLD(u16, m, 0xb8) = 0x739f;
                LFLD(u16, m, 0xba) = 0xb;
                LFLD(u16, m, 0xbc) = 0xa;
            }
            LFLD(u8, s, 0xb2a) |= 2;
            if ((msg->id >> 12) == 4) {
                LFLD(u8, s, 0xb2a) |= 0x10;
            }
        }
        }
        break;
    case 10: {
        u8 *p;
        VObj *e;
        callBase = FALSE;
        LFLD(u16, LFLD(u8 *, s, 0x50), 4) = msg->id;
        p = LFLD(u8 *, s, 0x50);
        LFLD(u16, p, 0) += *(u16 *)msg->data;
        if (LFLD(u16, p, 0) > LFLD(u16, p, 2)) {
            LFLD(u16, p, 0) = LFLD(u16, p, 2);
        }
        {
            u8 *m = LFLD(u8 *, s, 0x38);
            LFLD(u16, m, 0xb6) = 0x73ea;
            LFLD(u16, m, 0xb8) = 0x7ffc;
            LFLD(u16, m, 0xba) = 0xb;
            LFLD(u16, m, 0xbc) = 0xa;
        }
        e = func_02065f88(0xcb, s + 0x70);
        LFLD(s32, s, 0xb44) = LFLD(s32, e, 0x24);
        e->vfunc_14(0x99a, 0x1000, 0x99a);
        MinB32_0219e998(s, 0x5a);
        break;
    }
    case 11:
        callBase = FALSE;
        switch (msg->data[0]) {
        case 1: {
            u16 a = *(u16 *)(msg->data + 4);
            u8 *p = LFLD(u8 *, s, 0x54);
            LFLD(s16, p, 2) = *(s16 *)(msg->data + 2);
            LFLD(u16, p, 0) = a;
            break;
        }
        case 2:
            LFLD(u16, LFLD(u8 *, s, 0x54), 4) = *(u16 *)(msg->data + 4);
            break;
        }
        break;
    case 12:
        callBase = FALSE;
        if (msg->data[0] == 2) {
            LFLD(u16, LFLD(u8 *, s, 0x54), 4) = 0;
        }
        break;
    case 7: {
        s32 v;
        callBase = FALSE;
        LFLD(B29_0219e998, s, 0xb29).b4 = 1;
        LFLD(s32, s, 0x70) = *(s32 *)(msg->data + 0);
        LFLD(s32, s, 0x74) = *(s32 *)(msg->data + 4);
        LFLD(s32, s, 0x78) = *(s32 *)(msg->data + 8);
        LFLD(u16, s, 0x7c) = *(u16 *)(msg->data + 0xc);
        LFLD(u16, s, 0x7e) = *(u16 *)(msg->data + 0xe);
        LFLD(u16, s, 0x80) = *(u16 *)(msg->data + 0x10);
        v = *(s32 *)(msg->data + 0x14);
        if (v > 0) {
            LFLD(s32, s, 0xa8) = v;
        } else if (v == 0) {
            if (LFLD(B24_0219e998, s, 0xb24).b1) {
                if ((LFLD(u16, data_ov000_021ccd68, 0xa) & 0x3f) >= 0x2a) {
                    LFLD(s32, s, 0xa0) -= LFLD(s32, s, 0xa0) >> 2;
                } else {
                    LFLD(s32, s, 0xa0) -= LFLD(s32, s, 0xa0) >> 3;
                }
            } else if ((LFLD(u16, data_ov000_021ccd68, 0xa) & 0x3f) >= 0x2a) {
                if (LFLD(s32, s, 0xa0) < 0) {
                    LFLD(s32, s, 0xa0) -= LFLD(s32, s, 0xa0) >> 1;
                }
            } else {
                if (LFLD(s32, s, 0xa0) < 0) {
                    LFLD(s32, s, 0xa0) -= LFLD(s32, s, 0xa0) >> 2;
                }
            }
            LFLD(s32, s, 0xa8) = 0x52;
            LFLD(B9a_0219e998, LFLD(u8 *, s, 0x48), 0x9a).b5 = 0;
            LFLD(B24_0219e998, s, 0xb24).b16 = 0;
        }
        break;
    }
    }
    if (callBase && func_ov000_0218d494(self, msg)) {
        return TRUE;
    }
    self->msg_flags |= 1 << msg->type;
    msg->type = 0;
    return TRUE;
}
}
