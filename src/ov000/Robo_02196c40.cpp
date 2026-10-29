#include "types.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u16 st;
    u16 timer;
    s32 unk_04;
    s32 unk_08;
} State02196c40;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 1;
    u16 rest : 9;
} Bits02196c40;

typedef struct {
    u8 b0 : 2;
    u8 b2 : 1;
    u8 rest : 5;
} Bits8_02196c40;

typedef struct {
    u16 mode : 3;
    u16 rest : 13;
} Mode02196c40;

class VObj02196c40 {
public:
    virtual void vfunc_00();
    virtual void vfunc_04();
    virtual void vfunc_08();
    virtual void vfunc_0c(s32 a);
};

extern "C" {
extern char data_ov000_021cc463[];
extern u8 *data_0214a424;
extern void *data_02097e4c;
extern void *data_ov000_021ccd6c;
BOOL func_ov000_02190cb0(void *a, const char *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
BOOL func_ov000_02191120(void *a);
void func_0203f324(void *a);
void func_0203f364(void *a);
BOOL func_ov000_02198360(void *s, s32 a, s32 b);
void *func_ov000_0219bf90(void);
void *func_ov000_02199ba0(void *p);
void func_ov000_02199b88(void *a, void *b);
void func_ov003_021f0c60(void *self, s32 a);
void *func_ov003_021f0868(void *pos, s32 a, s32 b);
void *func_02049f44(void *mgr, s32 id, void *pos, s32 a);
VObj02196c40 *func_02065f88(s32 id, void *pos);
u8 *func_ov000_021b68b8(void *mgr, void *pos);
void func_ov000_02197ad0(void *self, BOOL b);
void func_ov000_0218dbe0(void *self, s32 a);
void func_ov000_021987b8(void *a, BOOL b, s32 c, s32 d);

static inline s32 FxMul02196c40(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

static inline BOOL IsB2_02196c40(u8 *m) {
    return LFLD(Bits8_02196c40, m, 0x18).b2 ? TRUE : FALSE;
}

void func_ov000_02196c40(u8 *self) {
    BOOL flag = TRUE;
    LFLD(Bits02196c40, LFLD(u8 *, self, 0x48), 0x9a).b6 = 0;
    switch (LFLD(State02196c40 *, self, 0x40)->st) {
    case 0:
        if (LFLD(s32, self, 0xa8) == 0) {
            LFLD(s32, self, 0xa8) = 0x52;
        }
        LFLD(u8, self, 0x92) = 0;
        LFLD(Bits02196c40, self, 0xcc).b6 = 0;
        LFLD(State02196c40 *, self, 0x40)->st++;
        break;
    case 1: {
        u32 in = LFLD(u32, LFLD(u8 *, self, 0x48), 0x50);
        u8 *hit;
        if (LFLD(s32, self, 0xa0) > 0 && (in & 0x80000000)) {
            LFLD(s32, self, 0xa0) = -0xcd;
        }
        if (LFLD(u32, self, 0x30) & 0x80) {
            LFLD(s32, self, 0x9c) = 0;
        }
        if (in & 0x400) {
            VObj02196c40 *o;
            if (LFLD(Bits02196c40, self, 0xcc).b6) {
                break;
            }
            LFLD(Bits02196c40, self, 0xcc).b6 = 1;
            LFLD(s32, self, 0x9c) = 0;
            LFLD(u8, self, 0x92) = 3;
            func_02049f44(data_02097e4c, 0x3d, self + 0x70, 0);
            o = func_02065f88(0x2bd, self + 0x70);
            if (LFLD(s32, self, 0x64) > 0x1000) {
                o->vfunc_0c(LFLD(s32, self, 0x64));
            }
            break;
        }
        hit = func_ov000_021b68b8(data_ov000_021ccd6c, self + 0x70);
        if (hit != NULL) {
            u16 ang = LFLD(u16, hit, 0x1a);
            LFLD(s32, self, 0x9c) = FxMul02196c40(LFLD(s32, self, 0x9c), 0x59a);
            if (LFLD(s32, self, 0x9c) < 0x8f) {
                LFLD(s32, self, 0x9c) = 0x8f;
            }
            LFLD(u16, self, 0x98) = ang;
            LFLD(s32, self, 0xa8) = 0x52;
            flag = FALSE;
        }
        if (hit != NULL || (in & 0x20000000) || ((in & 0x40000000) && !IsB2_02196c40(LFLD(u8 *, self, 0x4c))) ||
            LFLD(s32, LFLD(u8 *, self, 0x48), 0x58) != 0) {
            s32 kind = 0;
            BOOL got = FALSE;
            LFLD(State02196c40 *, self, 0x40)->timer = 0;
            if (hit != NULL || LFLD(u16, LFLD(u8 *, self, 0x4c), 0x1c) != 0xffff) {
                if (LFLD(u8, LFLD(u8 *, self, 0x4c), 1) == 1) {
                    kind = LFLD(u8, LFLD(u8 *, self, 0x4c), 2);
                    got = TRUE;
                }
            }
            switch (kind) {
            case 1:
            case 2: {
                u8 *p;
                if (LFLD(u8 *, self, 0x44) != NULL) {
                    u8 *q = LFLD(u8 *, self, 0x44);
                    LFLD(Bits02196c40, q, 0x22).b0 = 0;
                    LFLD(Bits02196c40, q, 0x22).b1 = 0;
                }
                if (LFLD(u8 *, self, 0x48) != NULL) {
                    u8 *q = LFLD(u8 *, self, 0x48);
                    LFLD(Bits02196c40, q, 0x9a).b0 = 0;
                    LFLD(Bits02196c40, q, 0x9a).b3 = 0;
                    func_0203f364(q);
                    q = LFLD(u8 *, self, 0x48);
                    LFLD(Bits02196c40, q, 0x9a).b1 = 0;
                    LFLD(Bits02196c40, q, 0x9a).b4 = 0;
                }
                p = (u8 *)func_ov000_0219bf90();
                if (LFLD(u16, p, 0xc) == LFLD(u16, LFLD(u8 *, self, 0x4c), 0x1c)) {
                    u8 *g = data_0214a424;
                    u32 n = LFLD(u16, g, 0x16) + 1;
                    if (n >= 0xffff) {
                        n = 0xffff;
                    }
                    LFLD(u16, g, 0x16) = n;
                }
                if (LFLD(u8, LFLD(u8 *, self, 0x4c), 3) != 0) {
                    func_ov003_021f0c60(self, 0);
                }
                func_ov000_02198360(LFLD(void *, self, 0x40), 0x15, 0);
                break;
            }
            default:
                func_ov000_02197ad0(self, got);
                if (((in & 0x20000000) && LFLD(s32, self, 0xa0) == 0) || LFLD(u8, self, 0x92) > 3) {
                    LFLD(State02196c40 *, self, 0x40)->st++;
                    LFLD(s32, self, 0xa0) = 0;
                    LFLD(s32, self, 0xa8) = 0;
                    LFLD(s32, self, 0xa4) = 0x800;
                }
                break;
            }
        }
        if (LFLD(s32, self, 0xa0) < 0) {
            State02196c40 *st;
            func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc463, 0x1000, 0);
            func_ov000_021915a0(LFLD(void *, self, 0x38));
            st = LFLD(State02196c40 *, self, 0x40);
            st->timer++;
            if (st->timer > 0x46) {
                LFLD(State02196c40 *, self, 0x40)->timer = 0x46;
                if (!(LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x20000000)) {
                    func_ov000_02198360(LFLD(void *, self, 0x40), 0x15, 0);
                }
            }
        }
        break;
    }
    case 2: {
        State02196c40 *st;
        LFLD(Bits02196c40, LFLD(u8 *, self, 0x48), 0x9a).b5 = 1;
        st = LFLD(State02196c40 *, self, 0x40);
        st->timer++;
        if (st->timer < 6) {
            break;
        }
        LFLD(State02196c40 *, self, 0x40)->timer = 6;
        if (!func_ov000_02191120(LFLD(void *, self, 0x38)) && LFLD(s64, LFLD(State02196c40 *, self, 0x40), 4) == 0) {
            break;
        }
        LFLD(u16, LFLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
        func_ov000_02198360(LFLD(void *, self, 0x40), 1, 0);
        break;
    }
    }
    func_ov000_0218dbe0(self, 0);
    if (LFLD(u8 *, self, 0x48) != NULL) {
        u8 *other;
        BOOL saved;
        u8 *m;
        if (LFLD(Mode02196c40, LFLD(u8 *, self, 0xb0), 2).mode == 2) {
            u8 *q = LFLD(u8 *, self, 0x48);
            LFLD(Bits02196c40, q, 0x9a).b0 = 1;
            LFLD(Bits02196c40, q, 0x9a).b3 = 1;
            func_0203f324(q);
        }
        m = LFLD(u8 *, self, 0x4c);
        other = NULL;
        saved = FALSE;
        if (m != NULL && LFLD(u16, m, 0x1c) != 0xffff && LFLD(u8, m, 1) == 1) {
            s32 h = LFLD(s32, self, 0x64) + 0x4cd;
            u8 *t;
            if (h < 0xccd) {
                h = 0xccd;
            }
            LFLD(s32, LFLD(u8 *, self, 0x48), 0x44) = h;
            t = (u8 *)func_ov000_02199ba0(LFLD(u8 *, self, 0x4c));
            if (t != NULL && (other = LFLD(u8 *, t, 0x48)) != NULL && LFLD(Bits02196c40, other, 0x9a).b3) {
                LFLD(Bits02196c40, other, 0x9a).b3 = 0;
                func_0203f364(other);
                saved = TRUE;
            }
        }
        func_ov000_021987b8(LFLD(u8 *, self, 0x48), flag, 0, 0);
        if (saved) {
            LFLD(Bits02196c40, other, 0x9a).b3 = 1;
            func_0203f324(other);
        }
    }
    if (LFLD(u8 *, self, 0x4c) != NULL && LFLD(u8, LFLD(u8 *, self, 0x4c), 0) == 2) {
        void *r = func_ov003_021f0868(self + 0x70, LFLD(s32, self, 0x64), LFLD(s32, self, 0x68));
        if (r != NULL) {
            func_ov000_02199b88(LFLD(u8 *, self, 0x4c), r);
            func_ov000_02198360(LFLD(void *, self, 0x40), 0xd, 0);
        }
    }
}

}
