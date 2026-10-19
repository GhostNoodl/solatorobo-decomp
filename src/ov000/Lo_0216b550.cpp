#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

extern "C" {

extern u8 *data_ov000_021ccd54;
extern s32 data_02097d78[5];
extern void *data_0208cc94;
extern void *data_0208cc88;
BOOL func_02054f10(void *a, s32 b);
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
s32 FX_Div(s32 a, s32 b);

typedef struct {
    u32 b0 : 2;
    u32 alpha : 5;
    u32 rest : 25;
} LoMdlFlags0216b550;

static inline BOOL LoGBusy(u8 *g) {
    return LFLD(s32, g, 0x90) != LFLD(s32, g, 0x94) ? TRUE : FALSE;
}

static inline BOOL LoGIdle(void) {
    u8 *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (LoGBusy(g)) {
            return FALSE;
        }
        if (LFLD(s32, g, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline BOOL LoD78Idle(void) {
    return (data_02097d78[3] == 0 && data_02097d78[0] == 0) ? TRUE : FALSE;
}

void func_ov000_0216b550(u8 *self) {
    if (!LoGIdle() || !LoD78Idle()) {
        LBIT(self, 0).b1 = 0;
    }
    switch (LFLD(s32, self, 4)) {
    case 2:
        LFLD(s32, self, 4) = 4;
        break;
    case 3:
        LO_FREE_M(self, 8);
        LFLD(s32, self, 4) = 4;
        break;
    case 4:
        if (!LBIT(self, 0).b1) {
            return;
        }
        LBIT(self, 0).b0 = 1;
        LFLD(s32, self, 4) = 5;
        break;
    case 5: {
        void *res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
        u8 *m = (u8 *)func_0203dd9c(0x160);
        if (m) {
            void *nm = data_0208cc88;
            func_02041218(m + 0x88);
            func_02041440(m, nm, 0);
        }
        LFLD(void *, self, 8) = m;
        func_020417e0(m, res);
        LFLD(u32, LFLD(void *, self, 8), 0x6c) |= 2;
        func_02041d9c(LFLD(void *, self, 8), 0, 0x22);
        func_02041d9c(LFLD(void *, self, 8), 0, 0x23);
        LFLD(u32, LFLD(void *, self, 8), 0x6c) |= 0x80000;
        LFLD(u32, LFLD(void *, self, 8), 0x6c) |= 0x200000;
        LFLD(LoMdlFlags0216b550, LFLD(void *, self, 8), 0x6c).alpha = 0x1e;
        LFLD(s32, self, 4) = 6;
        break;
    }
    case 6:
        if (!func_02054f10(LFLD(void *, self, 8), 0xffff)) {
            return;
        }
        LFLD(s32, self, 0x14) = 0;
        LFLD(s32, self, 0x18) = 0x1000;
        LFLD(s32, self, 4) = 8;
        break;
    case 7:
        if (!LBIT(self, 0).b2) {
            LBIT(self, 0).b1 = 0;
        }
        LBIT(self, 0).b2 = 0;
    case 8:
        if (!LBIT(self, 0).b1) {
            LBIT(self, 0).b0 = 0;
            LFLD(s32, self, 4) = 8;
        }
        if (LFLD(s32, self, 4) == 7) {
            return;
        }
        if (LBIT(self, 0).b0) {
            LFLD(s32, self, 0x14)++;
            LFLD(s32, self, 0x18) = FX_Div(LFLD(s32, self, 0x14) << 12, 0xc000);
            if (LFLD(s32, self, 0x18) >= 0x1000) {
                LFLD(s32, self, 0x18) = 0x1000;
                LFLD(s32, self, 4) = 7;
            }
        } else {
            LFLD(s32, self, 0x14)--;
            LFLD(s32, self, 0x18) = FX_Div(LFLD(s32, self, 0x14) << 12, 0xc000);
            if (LFLD(s32, self, 0x18) <= 0) {
                LFLD(s32, self, 0x18) = 0;
                LFLD(s32, self, 4) = 3;
            }
        }
        LFLD(s32, self, 0x18) = 0x1000 - FX_SinCosTable_[((LFLD(s32, self, 0x18) << 14) >> 16) * 2];
        break;
    }
}

}
