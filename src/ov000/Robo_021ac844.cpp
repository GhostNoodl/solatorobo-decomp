#include "ov000/LoCommon.h"
#include "nitro/fx.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 3;
    u32 b5 : 2;
    u32 b7 : 2;
    u32 b9 : 1;
    u32 b10 : 2;
    u32 b12 : 2;
    u32 b14 : 3;
    u32 b17 : 1;
    u32 b18 : 3;
    u32 b21 : 1;
    u32 rest : 10;
} B24_021ac844;

typedef struct {
    u16 b0 : 3;
    u16 rest : 13;
} B22_021ac844;

typedef struct {
    u8 b0 : 5;
    u8 b5 : 2;
    u8 b7 : 1;
} B93_021ac844;

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} B8_021ac844;

typedef struct {
    VecFx32 pos;
    u16 rx;
    u16 ry;
    u16 rz;
    s32 unk;
} Pose_021ac844;

extern "C" {
extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd54;
extern void *data_02097e4c;
extern void *data_0214a424;
extern char data_ov000_021cc6cc[];
extern char data_ov000_021cc6d2[];
extern char data_ov000_021cc6d8[];
extern char data_ov000_021cc6de[];
u8 *func_ov000_0218e640(void *mgr, u16 id);
void func_ov000_02198360(void *p, s32 a, s32 b);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
void func_ov000_02190cb0(void *p, void *a, s32 b, s32 c);
void func_ov000_02191008(void *a);
void func_ov000_02191418(void *a, s32 b, s32 c);
BOOL func_ov000_02191120(void *a);
BOOL func_ov000_02191508(void *a);
void func_ov000_0218dbe0(void *self, s32 a);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
void func_ov000_0218d398(void *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
void func_ov000_0218d46c(void *o, u16 id, s32 c);
void func_02049bb4(void *mgr, s32 id);
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_0218996c(u8 a, u8 b);
u8 *func_ov000_02199f60(void *p);
void func_ov000_02199f88(void *t, void *self);
u16 func_ov000_02198da8(void *body, u16 angle);
s32 func_0206d204(void *p, s32 a);
void func_ov000_021b1fac(void *self, s32 a, s32 b);

static inline u8 *FindActor_021ac844(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline BOOL GBusy_021ac844(u8 *g) {
    return LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94) ? TRUE : FALSE;
}

static inline BOOL GIdle_021ac844(void) {
    u8 *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (GBusy_021ac844(g)) {
            return FALSE;
        }
        if (LFLD(s32, g, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline void Bump_021ac844(u8 *self) {
    if (LFLD(B24_021ac844, self, 0xb24).b1 && (LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x400)) {
        LFLD(u16, self, 0x98) = FX_Atan2(LFLD(s32, self, 0xaf0) - LFLD(s32, self, 0x70), LFLD(s32, self, 0xaf8) - LFLD(s32, self, 0x78));
        LFLD(s32, self, 0x9c) = 0x66;
        LFLD(s32, self, 0xa4) = 0;
        if (!LFLD(B24_021ac844, self, 0xb24).b17 || (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x40000000)) {
            LFLD(s32, self, 0xa0) = 0x200;
        }
        LFLD(s32, self, 0xa8) = 0x52;
        LFLD(B24_021ac844, self, 0xb24).b17 = 1;
    }
}

void func_ov000_021ac844(u8 *self) {
    BOOL upd = FALSE;
    u8 *a;
    Pose_021ac844 pose;

    switch (LFLD(u16, LFLD(u8 *, self, 0x40), 0)) {
    case 0: {
        u8 *o;
        u16 ang;
        char *anim = data_ov000_021cc6d2;
        if (LFLD(B93_021ac844, self, 0x93).b5) {
            anim = data_ov000_021cc6cc;
        }
        func_ov000_02190cb0(LFLD(void *, self, 0x38), anim, 0x800, 1);
        if (LFLD(B22_021ac844, self, 0xb22).b0 != 0) {
            if (LFLD(void *, self, 0x998) != NULL) {
                func_ov000_02191008(LFLD(void *, self, 0x998));
            }
            if (LFLD(s16, self, 0xb64) >= 0) {
                func_02049bb4(data_02097e4c, LFLD(s16, self, 0xb64));
                LFLD(s16, self, 0xb64) = -1;
            }
            if (LFLD(B22_021ac844, self, 0xb22).b0 > 1) {
                LFLD(B22_021ac844, self, 0xb22).b0 = 1;
                LFLD(u16, self, 0x7c) = 0;
                LFLD(u16, self, 0x80) = 0;
                LFLD(u16, self, 0x9a6) = 0;
                LFLD(u16, self, 0x9a8) = 0;
                LFLD(u16, self, 0x9aa) = 0;
                LFLD(u16, self, 0x9a0) = 0;
                LFLD(u16, self, 0x9a2) = 0;
                LFLD(u16, self, 0x9a4) = 0;
            }
        }
        if (!LFLD(B24_021ac844, self, 0xb24).b0) {
            LFLD(u16, LFLD(u8 *, self, 0x50), 0xa) = 0x96;
        } else {
            func_02049a48(data_02097e4c, 0x30a, -1, -1, -1);
        }
        func_ov000_0218996c(8, 0xc);
        a = FindActor_021ac844(LFLD(u16, self, 0xb1c));
        if (a != NULL) {
            pose.pos.x = LFLD(s32, self, 0x70);
            pose.pos.y = LFLD(s32, self, 0x74);
            pose.pos.z = LFLD(s32, self, 0x78);
            pose.pos.y += LFLD(s32, self, 0x6c);
            pose.rx = LFLD(u16, a, 0x7c);
            pose.ry = LFLD(u16, a, 0x7e);
            pose.rz = LFLD(u16, a, 0x80);
            pose.unk = 0;
            func_ov000_0218d398(a, LFLD(u16, self, 0xc), 7, 1, 0x18, &pose);
            func_ov000_0218d46c(a, LFLD(u16, self, 0xc), 0xa);
            if (LFLD(u8 *, a, 0x4c) != NULL) {
                LFLD(B8_021ac844, LFLD(u8 *, a, 0x4c), 0x18).b0 = 0;
            }
        }
        LFLD(u16, self, 0xb1c) = 0xffff;
        LFLD(u16, self, 0xb1e) = 0xffff;
        LFLD(B24_021ac844, self, 0xb24).b5 = 0;
        LFLD(B24_021ac844, self, 0xb24).b7 = LFLD(B24_021ac844, self, 0xb24).b9;
        LFLD(u16, self, 0x90) = 0xffff;
        LFLD(B24_021ac844, self, 0xb24).b21 = 0;
        if (LFLD(B93_021ac844, self, 0x93).b5 == 0) {
            LFLD(u16, self, 0xb36) = 0;
        } else if (LFLD(B93_021ac844, self, 0x93).b5 == 1) {
            LFLD(B93_021ac844, self, 0x93).b5 = 2;
        }
        LFLD(u16, self, 0xb20) = 0xffff;
        LFLD(B24_021ac844, self, 0xb24).b12 = 0;
        LFLD(u16, self, 0x7c) = 0;
        o = func_ov000_02199f60(LFLD(void *, self, 0x50));
        if (o == NULL || o == self) {
            ang = LFLD(u16, self, 0x7e);
        } else {
            ang = FX_Atan2(LFLD(s32, o, 0x70) - LFLD(s32, self, 0x70), LFLD(s32, o, 0x78) - LFLD(s32, self, 0x78));
        }
        LFLD(u16, self, 0x96) = ang;
        LFLD(u16, self, 0x98) = LFLD(u16, self, 0x96) + 0x8000;
        LFLD(u16, self, 0x7e) = func_01ffc128(LFLD(u16, self, 0x96), LFLD(u16, self, 0x7e), 0x8cd, 1, 0x8000);
        LFLD(s32, self, 0x9c) = 0;
        LFLD(s32, self, 0xa0) = 0;
        LFLD(s32, self, 0xa4) = 0;
        LFLD(s32, self, 0xa8) = 0;
        LFLD(u8, self, 0x92) = 0;
        LFLD(u16, LFLD(u8 *, self, 0x40), 0)++;
        if (LFLD(u32, self, 0x30) & 0x80) {
            upd = TRUE;
        }
        break;
    }
    case 1: {
        u32 m = LFLD(B93_021ac844, self, 0x93).b5;
        if (m != 0) {
            LFLD(s32, self, 0x9c) = 0x600;
            LFLD(s32, self, 0xa4) = 0xcb8;
            LFLD(s32, self, 0xa8) = 0x52;
            LFLD(s32, self, 0xa0) = 0;
            if (m == 2) {
                LFLD(B93_021ac844, self, 0x93).b5 = 1;
            }
            LFLD(u16, LFLD(u8 *, self, 0x40), 0) = 0x14;
        } else {
            func_ov000_02199f88(LFLD(void *, self, 0x50), self);
            LFLD(u16, LFLD(u8 *, self, 0x40), 0)++;
        }
        if (LFLD(s32, self, 0x74) - LFLD(s32, self, 0xb00) > 0x28cd) {
            LFLD(s32, self, 0xa0) = -0x60;
        }
        if (LFLD(B24_021ac844, self, 0xb24).b0) {
            LFLD(s32, self, 0x9c) = 0;
        }
        func_ov000_02191418(LFLD(void *, self, 0x38), 5, 0);
        if (LFLD(u32, self, 0x30) & 0x80) {
            upd = TRUE;
        }
        break;
    }
    case 2:
        if (LFLD(s32, self, 0xa0) > 0) {
            if (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x80000000) {
                LFLD(s32, self, 0xa0) = 0;
            }
        } else {
            u32 fl;
            if ((LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x40000000) || LFLD(s32, LFLD(u8 *, self, 0x48), 0x58) != 0) {
                LFLD(u16, self, 0x98) = func_ov000_02198da8(LFLD(void *, self, 0x48), LFLD(u16, self, 0x98));
                LFLD(s32, self, 0x9c) = 0x114;
                if (LFLD(s32, self, 0xa0) < -0xcd) {
                    LFLD(s32, self, 0xa0) = -0xcd;
                }
            }
            fl = LFLD(u32, LFLD(u8 *, self, 0x48), 0x50);
            if (fl & 0x20000000) {
                if (fl & 0x400) {
                    LFLD(s32, self, 0x9c) = 0;
                    LFLD(s32, self, 0xa0) = 0;
                    LFLD(s32, self, 0xa4) = 0;
                    LFLD(s32, self, 0xa8) = 0;
                    func_ov000_02198360(LFLD(void *, self, 0x40), 4, 0);
                } else if (++LFLD(u8, self, 0x92) > 2 || ((LFLD(u16, self, 0xb68) & 2) && !LFLD(B24_021ac844, self, 0xb24).b0) ||
                           !GIdle_021ac844() || LFLD(u8, self, 0x15) == 3) {
                    func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc6d8, 0x800, 1);
                    LFLD(s32, self, 0x9c) = 0;
                    LFLD(s32, self, 0xa0) = 0;
                    LFLD(s32, self, 0xa4) = 0;
                    LFLD(s32, self, 0xa8) = 0;
                    LFLD(u16, LFLD(u8 *, self, 0x40), 0) = 10;
                    LFLD(u16, LFLD(u8 *, self, 0x40), 2) = 0;
                } else {
                    BOOL stop;
                    s32 r;
                    func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc6de, 0x800, 1);
                    LFLD(s32, self, 0xa0) = -LFLD(s32, self, 0xa0) >> 1;
                    LFLD(s32, self, 0x9c) = LFLD(s32, self, 0x9c) - (LFLD(s32, self, 0x9c) >> 2);
                    stop = FALSE;
                    r = func_0206d204(data_0214a424, 0);
                    if (LFLD(u16, LFLD(u8 *, self, 0x50), 0) == 0 && r == 0) {
                        stop = TRUE;
                    }
                    if (stop) {
                        LFLD(s32, self, 0x9c) = 0;
                    }
                }
            }
        }
        LFLD(u16, self, 0x7e) = func_01ffc128(LFLD(u16, self, 0x96), LFLD(u16, self, 0x7e), 0x8cd, 1, 0x8000);
        if (!func_ov000_02191508(LFLD(void *, self, 0x38))) {
            func_ov000_0218dbe0(self, 0);
        }
        func_ov000_021987b8(LFLD(void *, self, 0x48), 1, 0, 0);
        Bump_021ac844(self);
        {
            u8 *s = LFLD(u8 *, self, 0x40);
            LFLD(u16, s, 2)++;
            if (LFLD(u16, s, 2) > 0x3c) {
                func_ov000_02198360(LFLD(void *, self, 0x40), 4, 0);
            }
        }
        break;
    case 10: {
        u8 *s = LFLD(u8 *, self, 0x40);
        if (LFLD(B24_021ac844, self, 0xb24).b0) {
            func_ov000_021987b8(LFLD(void *, self, 0x48), 0, 0, 0);
            func_ov000_02198360(LFLD(void *, self, 0x40), 0x14, 0);
        } else {
            LFLD(u16, s, 2)++;
            if (LFLD(u16, s, 2) > 0x19 || (LFLD(u16, self, 0xb68) & 2)) {
                func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc6d8, 0x800, 0);
                LFLD(u16, LFLD(u8 *, self, 0x40), 0)++;
            }
        }
        LFLD(u16, LFLD(u8 *, self, 0x48), 0x9a) |= 0x20;
        if (LFLD(u32, self, 0x30) & 0x80) {
            upd = TRUE;
        }
        break;
    }
    case 11:
        if (func_ov000_02191120(LFLD(void *, self, 0x38))) {
            if (LFLD(B93_021ac844, self, 0x93).b5) {
                func_ov000_02198360(LFLD(void *, self, 0x40), 0x1c, 0);
            } else {
                func_ov000_02198360(LFLD(void *, self, 0x40), 1, 0);
            }
        }
        LFLD(u16, LFLD(u8 *, self, 0x48), 0x9a) |= 0x20;
        if (LFLD(u32, self, 0x30) & 0x80) {
            upd = TRUE;
        }
        break;
    case 0x14:
        if (func_ov000_02191120(LFLD(void *, self, 0x38))) {
            if (LFLD(B93_021ac844, self, 0x93).b5) {
                func_ov000_02198360(LFLD(void *, self, 0x40), 0x1c, 0);
            } else {
                func_ov000_02198360(LFLD(void *, self, 0x40), 1, 0);
            }
        }
        if (!func_ov000_02191508(LFLD(void *, self, 0x38))) {
            func_ov000_021b1fac(self, 1, 1);
        }
        Bump_021ac844(self);
        LFLD(u16, self, 0x7e) = func_01ffc128(LFLD(u16, self, 0x96), LFLD(u16, self, 0x7e), 0x8cd, 1, 0x8000);
        break;
    }
    if (upd) {
        func_ov000_021987b8(LFLD(void *, self, 0x48), 1, 0, 0);
    }
}
}
