#include "ov000/LoCommon.h"
#include "ov000/CmdQueue.h"

typedef struct {
    s32 x;
    s32 y;
} Pos02166be8;

typedef struct {
    u32 b0 : 3;
    u32 b3 : 1;
} Bits02166be8;

extern "C" {

extern u8 *data_ov000_021ccd6c;
extern u8 data_ov000_021c9a9c[];
extern CmdQueue *data_ov000_021ccd54;
extern u8 data_02097d78[];
void *func_ov000_0219bf90(void);
void func_ov000_021658e8(void *self);
u8 *func_ov000_02165f94(void *self);
void *func_ov000_02165e2c(void *self, void *area);
void func_ov000_02164c50(void *self, void *tgt);
void func_ov000_02166180(void *self);
s32 FX_Div(s32 a, s32 b);

static inline BOOL CmdQueue_Has02166be8(CmdQueue *q, s32 kind) {
    s32 i;
    for (i = q->unk_90; i != q->index;) {
        if (q->kinds[i] == kind) {
            return TRUE;
        }
        if (++i >= 0x10) {
            i = 0;
        }
    }
    return FALSE;
}

static inline BOOL IsMode0_02166be8(void) {
    if (LFLD(s32, data_02097d78, 0xc) == 0 && LFLD(s32, data_02097d78, 0) == 0) {
        return TRUE;
    }
    return FALSE;
}

static inline BOOL IsMode1_02166be8(void) {
    if (LFLD(s32, data_02097d78, 0xc) == 1) {
        return TRUE;
    }
    return LFLD(s32, data_02097d78, 0) == 1 ? TRUE : FALSE;
}

static inline s32 FxMulS64_02166be8(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline BOOL Skip02166be8(void) {
    BOOL skip = FALSE;
    if (func_ov000_0219bf90() == NULL) {
        skip = TRUE;
    }
    if (CmdQueue_Has02166be8(data_ov000_021ccd54, 9) || CmdQueue_Has02166be8(data_ov000_021ccd54, 10)) {
        skip = TRUE;
    }
    return skip;
}

void func_ov000_02166be8(u8 *self) {
    u8 *area;
    u8 *rgb;
    s32 k;
    s32 sq;
    u8 *tgt;
    u8 *w;
    s32 dx;
    s32 dz;
    s32 ox;
    u8 *ctx = data_ov000_021ccd6c;
    u8 *e;
    tgt = LFLD(u8 *, ctx, 0xc);
    Pos02166be8 c = LFLD(Pos02166be8, data_ov000_021c9a9c, 0x28);
    k = 0x1000;
    switch (LFLD(s32, self, 0x34)) {
    case 4:
        func_ov000_021658e8(self);
        if (Skip02166be8()) {
            return;
        }
        if (tgt == NULL) {
            return;
        }
        func_ov000_02164c50(self, tgt);
        LFLD(s32, self, 0x34) = 8;
        return;
    case 3:
        tgt = NULL;
    case 8:
        if (tgt == NULL || LFLD(u16, LFLD(u8 *, self, 0x30), 4) != LFLD(u16, tgt, 8)) {
            LFLD(s32, self, 0x38) -= 0x1000;
        } else {
            LFLD(s32, self, 0x38) += 0x1000;
        }
        LFLD(s32, self, 0x3c) = FX_Div(LFLD(s32, self, 0x38), k);
        if (LFLD(s32, self, 0x3c) < 0) {
            LFLD(s32, self, 0x38) = 0;
            LFLD(s32, self, 0x3c) = 0;
            LFLD(s32, self, 0x34) = 4;
            return;
        }
        if (LFLD(s32, self, 0x3c) > 0x1000) {
            LFLD(s32, self, 0x38) = k;
            LFLD(s32, self, 0x3c) = k;
            LFLD(s32, self, 0x34) = 7;
        }
        return;
    case 7: {
        rgb = func_ov000_02165f94(self);
        w = LFLD(u8 *, self, 0x30);
        k = 0x19a;
        if (LFLD(void *, w, 0xcb8) == NULL || !LFLD(Bits02166be8, LFLD(void *, w, 0xcb8), 0).b3) {
            if (tgt == NULL || LFLD(u16, w, 4) != LFLD(u16, tgt, 8)) {
                LFLD(s32, self, 0x34) = 3;
                return;
            }
        } else {
            if (Skip02166be8() || tgt == NULL || LFLD(u16, LFLD(u8 *, self, 0x30), 4) != LFLD(u16, tgt, 8)) {
                LFLD(s32, self, 0x34) = 4;
                return;
            }
        }
        LFLD(s32, w, 0xcc4) += 0x1000;
        LFLD(s32, w, 0xcc8) = FX_Div(LFLD(s32, w, 0xcc4), 0x20000);
        if (LFLD(s32, w, 0xcc8) >= 0x1000) {
            LFLD(s32, w, 0xcc4) = 0;
            LFLD(s32, w, 0xcc8) = 0x1000;
        }
        LFLD(s32, w, 0xcd4) += 0x1000;
        LFLD(s32, w, 0xcd8) = FX_Div(LFLD(s32, w, 0xcd4), 0x40000);
        if (LFLD(s32, w, 0xcd8) >= 0x1000) {
            LFLD(s32, w, 0xcd4) = 0;
            LFLD(s32, w, 0xcd8) = 0x1000;
        }
        LFLD(s32, w, 0xccc) += 0x1000;
        LFLD(s32, w, 0xcd0) = FX_Div(LFLD(s32, w, 0xccc), 0x40000);
        if (LFLD(s32, w, 0xcd0) >= 0x1000) {
            LFLD(s32, w, 0xccc) = 0;
            LFLD(s32, w, 0xcd0) = 0x1000;
        }
        if (IsMode0_02166be8() || IsMode1_02166be8()) {
            u8 idx = rgb[2];
            u8 *w2 = LFLD(u8 *, self, 0x30);
            area = idx >= w2[8] ? NULL : LFLD(u8 *, w2, 0xc84) + idx * 0x1c;
            if (area != LFLD(u8 *, w, 0xcb8)) {
                LFLD(s32, w, 0xcc4) = 0;
                LFLD(s32, w, 0xcc8) = 0;
                if (LFLD(void *, w, 0xcdc) == NULL) {
                    LFLD(s32, w, 0xccc) = 0;
                    LFLD(s32, w, 0xcd0) = 0;
                }
            }
            LFLD(u8 *, w, 0xcb8) = area;
            if (area == NULL) {
                return;
            }
            e = (u8 *)func_ov000_02165e2c(self, area);
            if (e != LFLD(u8 *, w, 0xcb4)) {
                if (e == NULL || LFLD(u8 *, w, 0xcb4) == NULL) {
                    if (!CmdQueue_Has02166be8(data_ov000_021ccd54, 0x14)) {
                        k = 0x1000;
                    }
                }
                LFLD(u8 *, w, 0xcb4) = e;
                LFLD(s32, w, 0xcc4) = 0;
                LFLD(s32, w, 0xcc8) = 0;
                LFLD(s32, w, 0xccc) = 0;
                LFLD(s32, w, 0xcd0) = 0;
            }
            w[0] = 0;
        }
        e = LFLD(u8 *, w, 0xcb4);
        if (e == NULL) {
            return;
        }
        dz = ((LFLD(s32, e, 0x10) - c.y) << 12) - LFLD(s32, w, 0xcc0);
        ox = LFLD(s32, w, 0xcbc);
        dx = ((LFLD(s32, e, 0xc) - c.x) << 12) - ox;
        { s64 t = (s64)dx * dx; t += (s64)dz * dz; sq = (s32)((t + 0x800) >> 12); }
        if (sq < 0x100) {
            k = 0x1000;
        }
        LFLD(s32, w, 0xcbc) = ox + FxMulS64_02166be8(k, dx);
        LFLD(s32, w, 0xcc0) += FxMulS64_02166be8(k, dz);
        func_ov000_02166180(self);
        break;
    }
    case 10:
        break;
    }
}

}
