#include "ov000/LoCommon.h"

#define REG_SQRTCNT (*(volatile u16 *)0x40002b0)
#define REG_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define REG_SQRT_PARAM (*(volatile u64 *)0x40002b8)

typedef struct {
    u8 b0 : 1;
    u8 rest : 7;
} B8_02194c08;

typedef struct {
    u16 b0 : 12;
    u16 b12 : 2;
    u16 b14 : 2;
} Info12_02194c08;

typedef struct {
    s32 m[12];
} Mtx_02194c08;

extern "C" {
extern u8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd64;
u8 *func_ov000_02199ba0(void *p);
u8 *func_ov000_0218bd5c(void *mgr, u16 id);
u8 *func_0206fef8(u16 id);
void func_ov000_02190758(void *a, void *b, s32 c);
BOOL func_ov000_021903b4(void *a);
void func_ov000_02191c24(void *a, void *b);
void func_ov000_02191ec4(void *a, s32 b, u32 c);
void func_ov000_021bd7a0(void *p);
void MI_Copy48B(const void *src, void *dst);
void MI_Copy36B(const void *src, void *dst);
s32 FX_Div(s32 a, s32 b);

static inline BOOL GBusy02194c08(u8 *g) {
    return LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94) ? TRUE : FALSE;
}

static inline BOOL GIdle02194c08(void) {
    u8 *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (GBusy02194c08(g)) {
            return FALSE;
        }
        if (LFLD(s32, g, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline BOOL GD4_02194c08(void) {
    return LFLD(void *, data_ov000_021ccd54, 0xd4) != NULL ? TRUE : FALSE;
}

static inline BOOL GHasD4_02194c08(void) {
    return GD4_02194c08() ? TRUE : FALSE;
}

static inline s32 Fade02194c08(s32 dist, u8 *cam) {
    s32 r = 0x1000;
    if (dist > LFLD(s32, cam, 0x84)) {
        if (dist >= LFLD(s32, cam, 0x74)) {
            r = 0;
        } else {
            r -= FX_Div(dist - LFLD(s32, cam, 0x84), LFLD(s32, cam, 0x74) - LFLD(s32, cam, 0x84));
        }
    }
    return r;
}

struct Obj02194c08 {
    u8 unk_00[0xe];
    u16 unk_0e;
    u8 unk_10[0x10];
    u16 unk_20;
    u8 unk_22[0x16];
    u8 *unk_38;
    u8 *unk_3c;
    u8 *unk_40;
    u8 unk_44[0x4];
    u8 *unk_48;
    u8 *unk_4c;
    u8 unk_50[0xc];
    u8 *unk_5c;
    u8 unk_60[0x10];
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    u8 unk_7c[0x17];
    B8_02194c08 unk_93;
};

BOOL func_ov000_02194c08(Obj02194c08 *self) {
    BOOL ret;
    u8 *p;
    u8 *q;
    if (!GIdle02194c08() && self->unk_4c != NULL && *self->unk_4c == 2) {
        return FALSE;
    }
    p = NULL;
    q = p;
    ret = TRUE;
    if (self->unk_38 != NULL) {
        u8 alpha;
        u8 *cam;
        if (self->unk_4c != NULL) {
            p = func_ov000_02199ba0(self->unk_4c);
        }
        if (p == NULL) {
            p = (u8 *)self;
        }
        if (p != NULL) {
            q = LFLD(u8 *, p, 0x48);
        }
        if (q != NULL) {
            u8 *s = self->unk_38;
            if (LFLD(u32, q, 0x54) & 0x80000) {
                LFLD(u8, s, 0xbf) = 5;
            } else {
                LFLD(u8, s, 0xbf) = 0x1f;
            }
        }
        if (self->unk_4c != NULL && LFLD(B8_02194c08, self->unk_4c, 0x18).b0) {
            Mtx_02194c08 m;
            u8 *s;
            MI_Copy48B(self->unk_4c + 0x20, &m);
            s = self->unk_38;
            MI_Copy36B(&m, s + 0x84);
            LFLD(s32, s, 0x78) = m.m[9];
            LFLD(s32, s, 0x7c) = m.m[10];
            LFLD(s32, s, 0x80) = m.m[11];
            self->unk_93.b0 = 1;
        }
        if (!self->unk_93.b0) {
            u8 *s = self->unk_38;
            LFLD(s32, s, 0x78) = self->unk_70;
            LFLD(s32, s, 0x7c) = self->unk_74;
            LFLD(s32, s, 0x80) = self->unk_78;
            func_ov000_02190758(self->unk_38, (u8 *)self + 0x7c, 0);
        }
        self->unk_93.b0 = 0;
        alpha = 0x1f;
        cam = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
        if (cam != NULL) {
            s32 dist;
            s32 r;
            u8 *g = data_ov000_021ccd54;
            u8 *s = self->unk_38;
            s32 dx = LFLD(s32, g, 0xf8) - LFLD(s32, s, 0x78);
            s32 dz = LFLD(s32, g, 0x100) - LFLD(s32, s, 0x80);
            {
                s64 sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                REG_SQRTCNT = 1;
                REG_SQRT_PARAM = (u64)(sq << 2);
            }
            while (REG_SQRTCNT & 0x8000) {
            }
            dist = (s32)(REG_SQRT_RESULT + 1) >> 1;
            r = Fade02194c08(dist, cam);
            if (r == 0) {
                alpha = 0;
            } else if (r < 0x1000) {
                alpha = (r * 31) >> 12;
            }
        }
        if (alpha == 0x1f) {
            ret = func_ov000_021903b4(self->unk_38);
        } else if (alpha != 0) {
            u8 old = LFLD(u8, self->unk_38, 0xbe);
            if (old > alpha) {
                LFLD(u8, self->unk_38, 0xbe) = alpha;
            }
            ret = func_ov000_021903b4(self->unk_38);
            LFLD(u8, self->unk_38, 0xbe) = old;
        }
    }
    if (ret && self->unk_3c != NULL) {
        u8 *info = func_0206fef8(self->unk_0e);
        u8 *o = self->unk_48;
        u8 *t = func_ov000_02199ba0(self->unk_4c);
        if (t != NULL) {
            if (LFLD(u8, self->unk_40, 0x13) == 9) {
                o = LFLD(u8 *, t, 0x48);
            }
        } else if (LFLD(Info12_02194c08, info, 0x12).b12 == 2) {
            o = NULL;
        }
        if (o != NULL) {
            s32 m;
            LFLD(s32, self->unk_3c, 0x10) = self->unk_74 - LFLD(s32, o, 0x6c);
            m = 1;
            switch (LFLD(Info12_02194c08, info, 0x12).b14) {
            case 0:
                m = 1;
                break;
            case 1:
                m = 0;
                break;
            case 2:
                m = 3;
                break;
            case 3:
                m = 2;
                break;
            }
            func_ov000_02191ec4(self->unk_3c, m, LFLD(u32, o, 0x54));
            func_ov000_02191c24(self->unk_3c, (u8 *)self + 0x70);
        }
    }
    if (ret && self->unk_5c != NULL) {
        if (GIdle02194c08() && !GHasD4_02194c08()) {
            func_ov000_021bd7a0(self->unk_5c);
        }
    }
    return ret;
}
}
