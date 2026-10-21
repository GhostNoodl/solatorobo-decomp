#include "ov000/LoCommon.h"

typedef struct {
    u8 pad_00[0x12];
    u16 trg;
} Pad021bb8dc;

extern "C" {
extern u8 *data_ov000_021ccd30;
extern char *data_ov000_021cc858;
extern char data_ov000_021cc894[];
extern Pad021bb8dc *data_02097dc8;
extern void *data_02097e4c;
extern const s16 FX_SinCosTable_[];
void func_0206e900(char *dst, const char *src);
void func_ov000_021bbd94(u8 *self);
BOOL func_02054f10(void *a, s32 b);
s32 FX_Div(s32 a, s32 b);
void func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
void func_ov000_02165da0(void *p);
BOOL func_ov000_02165df4(void *p);
void func_ov000_02165d78(void *p);

static inline void *Get021bb8dc(void) {
    u8 *p = LFLD(u8 *, data_ov000_021ccd30, 0x118);
    if (p == NULL) {
        return NULL;
    }
    if (LFLD(s32, p, 0x28) != 1) {
        return NULL;
    }
    return LFLD(void *, p, 0x30);
}

static inline BOOL Ready021bb8dc(u8 *self) {
    BOOL ok = TRUE;
    if (!((VObj *)(self + 4))->vfunc_2c()) {
        ok = FALSE;
    }
    return ok;
}

BOOL func_ov000_021bb8dc(u8 *self) {
    s32 t;
    void *p = Get021bb8dc();

    switch (LFLD(s32, self, 0x50)) {
    case 1: {
        char buf[0x20];
        func_0206e900(buf, data_ov000_021cc858);
        LFLD(s32, self, 0x48) = 2;
        ((VObj *)(self + 4))->vfunc_24(buf, data_ov000_021cc894);
        LFLD(s32, self, 0x50) = 2;
    }
    case 2:
        if (!Ready021bb8dc(self)) {
            break;
        }
        LFLD(s32, self, 0x50) = 4;
    case 4:
        func_ov000_021bbd94(self);
        LFLD(s32, self, 0x50) = 10;
    case 10:
        if (!func_02054f10(LFLD(void *, self, 0x58), 0xffff)) {
            break;
        }
        LFLD(s32, self, 0x50) = 6;
    case 6:
        LFLD(s32, self, 0x64) += 0x1000;
        t = FX_Div(LFLD(s32, self, 0x64), 0x1e000);
        if (t > 0x1000) {
            LFLD(s32, self, 0x50) = 11;
            LFLD(s32, self, 0x64) = 0x1e000;
            t = 0x1000;
            if (LFLD(void *, self, 0x5c) != NULL) {
                LFLD(u32, LFLD(void *, self, 0x5c), 0xc) &= ~2;
            }
        }
        LFLD(s32, self, 0x68) = FX_SinCosTable_[((t << 14) >> 16) * 2];
        break;
    case 11:
        if (data_02097dc8->trg & 2) {
            func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
            LFLD(s32, self, 0x50) = 12;
            break;
        }
        switch (LFLD(s16, self, 0x54)) {
        case 0:
            if (++LFLD(s32, self, 0x6c) > 0x3c) {
                func_ov000_02165da0(p);
                LFLD(s16, self, 0x54) = 10;
            }
            break;
        case 10:
            if (func_ov000_02165df4(p)) {
                LFLD(s32, self, 0x6c) = 0;
                LFLD(s16, self, 0x54) = 20;
            }
            break;
        case 20:
            if (++LFLD(s32, self, 0x6c) > 0x78) {
                LFLD(s32, self, 0x6c) = 0;
                LFLD(s16, self, 0x54) = 100;
            }
            break;
        case 100:
            LFLD(s32, self, 0x50) = 12;
            break;
        }
        break;
    case 12:
        func_ov000_02165d78(p);
        if (LFLD(void *, self, 0x5c) != NULL) {
            LFLD(u32, LFLD(void *, self, 0x5c), 0xc) |= 2;
        }
        LFLD(s32, self, 0x50) = 13;
    case 13:
        LFLD(s32, self, 0x64) -= 0x1000;
        t = FX_Div(LFLD(s32, self, 0x64), 0x1e000);
        if (t <= 0) {
            t = 0;
            LFLD(s32, self, 0x64) = 0;
            LFLD(s32, self, 0x50) = 17;
        }
        LFLD(s32, self, 0x68) = FX_SinCosTable_[((t << 14) >> 16) * 2];
        break;
    case 17:
        return FALSE;
    }
    if (LFLD(VObj *, self, 0x5c) != NULL) {
        LFLD(VObj *, self, 0x5c)->vfunc_1c();
    }
    LFLD(s32, self, 0x60) += 0x1000;
    if (LFLD(s32, self, 0x60) < 0) {
        LFLD(s32, self, 0x60) -= (s32)0x80000001;
    }
    return TRUE;
}
}
