#include "ov000/LoCommon.h"

typedef struct {
    u32 cnt : 16;
    u32 rest : 16;
} Cnt021b8994;

extern "C" {
extern int data_02097d78[];
extern u16 *data_02097dc8;
extern u8 *data_ov000_021ccd54;
extern u8 data_0208b318[];
extern char data_ov000_021cc885[];
void func_0206e900(char *dst, const char *src);
BOOL func_ov000_02184498(void *g);
void func_0203c9e8(s32 a, s32 b);
void func_0203cc58(s32 a, s32 b, s32 c);
void func_0203ca24(s32 a, s32 b, s32 c);
void func_0203cb78(s32 a, s32 b, s32 c);
s32 func_0203ca74(s32 ch);
s32 func_0203ca84(s32 ch);
void func_02042eac(s32 ch, s32 planes);
void func_02042ebc(s32 ch, s32 duration, s32 start, s32 end);
BOOL func_02042ef8(s32 ch);
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);

static inline BOOL StOk021b8994(u8 *g) {
    s32 st = LFLD(s32, g, 0x98);
    if (st == 0x14 || (u32)(st - 0x16) <= 1) {
        return TRUE;
    }
    return FALSE;
}

static inline BOOL Fade2_021b8994(void) {
    if (data_02097d78[3] == 2) {
        return TRUE;
    }
    return data_02097d78[2] == 2 ? TRUE : FALSE;
}

static inline BOOL FadeIdle021b8994(void) {
    BOOL r;
    if (data_02097d78[3] == 0 && data_02097d78[0] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

BOOL func_ov000_021b8994(u8 *self) {
    switch (LFLD(s32, self, 0x28)) {
    case 1: {
        char buf[0x20];
        VObj *p = (VObj *)func_0203dd9c(0x4c);
        if (p != NULL) {
            *(void **)p = data_0208b318;
            p->vfunc_08();
        }
        LFLD(VObj *, self, 0x24) = p;
        func_0206e900(buf, data_ov000_021cc885);
        LFLD(s32, LFLD(VObj *, self, 0x24), 0x44) = 2;
        LFLD(VObj *, self, 0x24)->vfunc_24(buf, self + 4);
        LFLD(s32, self, 0x28) = 2;
        break;
    }
    case 2:
        if (!LFLD(VObj *, self, 0x24)->vfunc_2c()) {
            break;
        }
        LFLD(s32, self, 0x28) = 4;
    case 3:
        if (!func_ov000_02184498(data_ov000_021ccd54)) {
            break;
        }
        func_0203c9e8(0x21, 0);
        func_0203cc58(0x1e000, 1, 2);
        func_0203ca24(0, 8, 2);
        LFLD(s32, self, 0x28) = 4;
        break;
    case 4: {
        u8 *p;
        if (!StOk021b8994(data_ov000_021ccd54)) {
            break;
        }
        if (!func_ov000_02184498(data_ov000_021ccd54)) {
            break;
        }
        p = (u8 *)func_0203dd9c(0x160);
        if (p != NULL) {
            func_02041218(p + 0x88);
            func_02041440(p, self + 4, 0);
        }
        LFLD(u8 *, self, 0x30) = p;
        func_020417e0(LFLD(u8 *, self, 0x30), (void *)LFLD(VObj *, self, 0x24)->vfunc_10());
        func_02041d9c(LFLD(u8 *, self, 0x30), 1, 0xffff);
        func_0203cb78(0, 1, 0);
        func_0203cc58(0, 1, 2);
        LFLD(s32, self, 0x28) = 6;
        break;
    }
    case 6:
        func_0203cb78(0x3c000, 1, 2);
        func_0203ca24(0x10, 8, 2);
        LFLD(s32, self, 0x28) = 7;
        break;
    case 7:
        if (func_0203ca74(2) <= 0x1e000) {
            break;
        }
        func_0203c9e8(0x10, 0);
        func_0203cb78(0x1e000, 1, 0);
        LFLD(s32, self, 0x28) = 9;
        break;
    case 9:
        if (!Fade2_021b8994()) {
            break;
        }
        if (FadeIdle021b8994()) {
            LFLD(s32, self, 0x28) = 0xc;
        }
        break;
    case 12:
        LFLD(Cnt021b8994, self, 0).cnt++;
        if (LFLD(Cnt021b8994, self, 0).cnt <= 0x78 && !(data_02097dc8[9] & 3)) {
            break;
        }
        LFLD(s32, self, 0x28) = 0xd;
        break;
    case 13: {
        s32 v = func_0203ca84(2);
        func_0203cb78(0x3c000, 1, 2);
        func_0203ca24(v, 0, 2);
        func_02042eac(1, 1);
        func_02042ebc(1, 0x1e, 0x10, 0);
        LFLD(u32, LFLD(u8 *, self, 0x30), 0x6c) |= 0x80000;
        LFLD(s32, self, 0x28) = 0xe;
        break;
    }
    case 14: {
        BOOL ok;
        if (func_02042ef8(1)) {
            break;
        }
        ok = TRUE;
        if (data_02097d78[3] != 0 || data_02097d78[2] != 0) {
            ok = FALSE;
        }
        if (!ok) {
            break;
        }
        LO_FREE_M(self, 0x30);
        LFLD(s32, self, 0x28) = 0x11;
        break;
    }
    case 17:
        return FALSE;
    }
    return TRUE;
}
}
