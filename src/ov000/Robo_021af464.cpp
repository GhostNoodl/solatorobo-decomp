#include "ov000/LoCommon.h"

typedef struct {
    u16 state;
    u16 timer;
} St_021af464;

typedef struct {
    u32 b0 : 14;
    u32 kind : 2;
    u32 b16 : 11;
    u32 b27 : 1;
    u32 b28 : 4;
} B24_021af464;

typedef struct {
    s32 x, y, z;
} Vec_021af464;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 11;
} B9a_021af464;

typedef struct {
    u8 b0 : 4;
    u8 b4 : 1;
    u8 b5 : 3;
} B18_021af464;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 7;
} B19_021af464;

#define REG_SQRTCNT_021af464 (*(volatile u16 *)0x40002b0)
#define REG_SQRT_RESULT_021af464 (*(volatile u32 *)0x40002b4)
/* written without volatile: the target computes both halves before storing */
#define REG_SQRT_PARAM_021af464 (*(u64 *)0x40002b8)

extern "C" {

extern const s16 FX_SinCosTable_[];
extern u8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd6c;
extern void *data_02097e4c;
extern char data_ov000_021cc62a[];
extern char data_ov000_021cc71d[];
extern char data_ov000_021cc723[];
void func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_ov000_021911c8(void *a, s32 b);
void func_ov000_02191418(void *a, u16 delay, BOOL force);
void func_ov000_02191780(void *a);
void func_ov000_021917f8(void *a);
void func_ov000_02198360(St_021af464 *st, s32 state, s32 x);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
u8 *func_ov000_0218e640(void *mgr, u16 id);
void func_ov000_0218ddd4(void *self, const void *target, s32 turn);
void func_ov000_0218dbe0(void *self, s32 turn);
s32 func_ov000_021b288c(void *self);
void func_ov000_021899d8(void *pos, s32 a, s32 b, s32 c, s32 d, s32 e);
void func_0203f364(void *obj);
void func_02049f44(void *mgr, s32 id, void *pos, s32 a);
u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
void VEC_MultAdd(s32 a, const void *v1, const void *v2, void *out);

static inline u8 *FindActor021af464(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline s32 Dist021af464(s32 dx, s32 dz) {
    s64 sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    REG_SQRTCNT_021af464 = 1;
    REG_SQRT_PARAM_021af464 = (u64)(sq << 2);
    while (REG_SQRTCNT_021af464 & 0x8000) {
    }
    return (s32)(REG_SQRT_RESULT_021af464 + 1) >> 1;
}

static inline s32 FxMul021af464(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline BOOL GBusy021af464(u8 *g) {
    return LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94) ? TRUE : FALSE;
}

static inline BOOL GIdle021af464(void) {
    u8 *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (GBusy021af464(g)) {
            return FALSE;
        }
        if (LFLD(s32, g, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline BOOL GHasD4_021af464(void) {
    return LFLD(void *, data_ov000_021ccd54, 0xd4) != NULL ? TRUE : FALSE;
}

static inline BOOL Ev19_021af464(void) {
    u8 *e = LFLD(u8 *, data_ov000_021ccd6c, 0x14);
    if (e != NULL && LFLD(B19_021af464, e, 0x19).b0) {
        return TRUE;
    }
    return FALSE;
}

void func_ov000_021af464(u8 *self) {
    u8 *a;
    u8 *info;
    Vec_021af464 pos;
    u16 ang;
    Vec_021af464 v;
    a = FindActor021af464(LFLD(u16, self, 0x90));
    info = NULL;
    if (a != NULL) {
        info = LFLD(u8 *, a, 0x4c);
        pos = LFLD(Vec_021af464, a, 0x70);
        ang = LFLD(u16, a, 0x7e);
        {
            u16 r = ang + 0x8000;
            pos.x += FxMul021af464(FX_SinCosTable_[(r >> 4) * 2], 0x800);
            pos.z += FxMul021af464(FX_SinCosTable_[(r >> 4) * 2 + 1], 0x800);
        }
        pos.y += 0x800;
    }
    if (LFLD(u8, self, 0xb2f) == 0) {
        LFLD(u8, self, 0xb2f)++;
    }
    if (LFLD(St_021af464 *, self, 0x40)->state < 10) {
        u8 *s48 = LFLD(u8 *, self, 0x48);
        LFLD(B9a_021af464, s48, 0x9a).b3 = 0;
        func_0203f364(s48);
        LFLD(B9a_021af464, LFLD(u8 *, self, 0x48), 0x9a).b4 = 0;
    }
    switch (LFLD(St_021af464 *, self, 0x40)->state) {
    case 0:
        if (info != NULL) {
            u8 k = info[0];
            if (k == 9) {
                LFLD(B24_021af464, self, 0xb24).kind = 1;
            } else if (k == 10) {
                LFLD(B24_021af464, self, 0xb24).kind = 2;
            }
        } else {
            LFLD(B24_021af464, self, 0xb24).kind = 0;
            func_ov000_02198360(LFLD(St_021af464 *, self, 0x40), 1, 0);
            break;
        }
        func_02049f44(data_02097e4c, 7, self + 0x70, 0);
        func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc62a, 0x800, 0);
        LFLD(s32, self, 0x9c) = Dist021af464(pos.x - LFLD(s32, self, 0x70), pos.z - LFLD(s32, self, 0x78)) >> 4;
        LFLD(s32, self, 0xa0) = ((pos.y - LFLD(s32, self, 0x74)) >> 4) + 0x185;
        LFLD(s32, self, 0xa4) = 0;
        LFLD(s32, self, 0xa8) = 0x52;
        LFLD(B24_021af464, self, 0xb24).b27 = 0;
        LFLD(St_021af464 *, self, 0x40)->state++;
        break;
    case 1:
        LFLD(u16, self, 0x7e) = func_01ffc128(ang, LFLD(u16, self, 0x7e), 0x400, 1, 0x8000);
        func_ov000_0218ddd4(self, &pos, 0);
        {
            St_021af464 *st = LFLD(St_021af464 *, self, 0x40);
            st->timer++;
            if (st->timer < 0x10) {
                break;
            }
        }
        func_ov000_02190cb0(LFLD(void *, self, 0x38),
                            LFLD(B24_021af464, self, 0xb24).kind == 1 ? data_ov000_021cc71d : data_ov000_021cc723,
                            0x400, 0);
        func_ov000_021915a0(LFLD(void *, self, 0x38));
        func_ov000_021911c8(LFLD(void *, self, 0x38), 0x1400);
        func_ov000_02191418(LFLD(void *, self, 0x38), 10, 0);
        LFLD(St_021af464 *, self, 0x40)->timer = 0;
        LFLD(St_021af464 *, self, 0x40)->state++;
        break;
    case 2: {
        St_021af464 *st = LFLD(St_021af464 *, self, 0x40);
        st->timer++;
        if (st->timer >= 10) {
            LFLD(Vec_021af464, self, 0x70) = pos;
            LFLD(u16, self, 0x7e) = ang;
            LFLD(u16, self, 0x98) = ang;
            LFLD(u16, self, 0x90) = 0xffff;
            func_02049f44(data_02097e4c, 1, self + 0x70, 0);
            LFLD(St_021af464 *, self, 0x40)->state++;
        } else {
            Vec_021af464 d;
            LFLD(u16, self, 0x7e) = func_01ffc128(ang, LFLD(u16, self, 0x7e), 0x8cd, 1, 0x8000);
            LFLD(s32, self, 0x9c) = 0;
            LFLD(s32, self, 0xa0) = 0;
            LFLD(s32, self, 0xa4) = 0;
            LFLD(s32, self, 0xa8) = 0;
            d.x = pos.x - LFLD(s32, self, 0x70);
            d.y = pos.y - LFLD(s32, self, 0x74);
            d.z = pos.z - LFLD(s32, self, 0x78);
            VEC_MultAdd(0x800, &d, self + 0x70, self + 0x70);
        }
        break;
    }
    case 3: {
        s32 r = func_ov000_021b288c(self);
        if (r <= 0) {
            LFLD(B24_021af464, self, 0xb24).kind = 0;
            if (r == 0) {
                LFLD(s32, self, 0x9c) = 0x19a;
                LFLD(s32, self, 0xa0) = 0x2cd;
                LFLD(s32, self, 0xa8) = 0x52;
            } else {
                LFLD(s32, self, 0x9c) = 0;
                LFLD(s32, self, 0xa0) = 0x185;
                LFLD(s32, self, 0xa8) = 0x52;
            }
            LFLD(s32, self, 0xa4) = 0;
            LFLD(u8, self, 0xb29) |= 2;
            func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc62a, 0x800, 0);
            func_02049f44(data_02097e4c, 7, self + 0x70, 0);
            LFLD(St_021af464 *, self, 0x40)->state = 10;
        } else if (LFLD(s32, self, 0xa0) == 0) {
            func_ov000_02191418(LFLD(void *, self, 0x38), 1, 0);
        } else if (LFLD(s32, self, 0xa0) < 0) {
            func_ov000_02191780(LFLD(void *, self, 0x38));
        } else {
            func_ov000_021917f8(LFLD(void *, self, 0x38));
        }
        break;
    }
    case 10:
        LFLD(u8, self, 0xb29) |= 2;
        func_ov000_0218dbe0(self, 0);
        func_ov000_021987b8(LFLD(void *, self, 0x48), 0, 0, 0);
        if (LFLD(s32, self, 0xa0) > 0) {
            break;
        }
        if (!(LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000)) {
            break;
        }
        func_ov000_02198360(LFLD(St_021af464 *, self, 0x40), 4, 0);
        break;
    }
    if (Ev19_021af464()) {
        return;
    }
    if (info != NULL && (LFLD(B18_021af464, info, 0x18).b4 ? TRUE : FALSE)) {
        return;
    }
    if (LFLD(B24_021af464, self, 0xb24).b27) {
        return;
    }
    if (!GIdle021af464() || GHasD4_021af464()) {
        LFLD(B24_021af464, self, 0xb24).b27 = 1;
    }
    {
        v = *(Vec_021af464 *)(self + 0x70);
        v.y += LFLD(s32, self, 0x6c);
        func_ov000_021899d8(&v, 0, 0x6ccd, 1, 0x1000, 0x1000);
    }
}

}
