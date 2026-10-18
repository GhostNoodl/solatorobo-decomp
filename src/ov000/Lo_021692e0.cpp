#include "ov000/LoCommon.h"

extern "C" {

extern u8 *data_ov000_021ccd54;
extern s32 data_02097d78[5];
BOOL func_02054f10(void *a, s32 b);
extern void *data_0208cc94;
extern void *data_0208cc88;
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_ov000_0215fdfc(void *self, s32 a, const void *b);
extern u8 data_ov000_021c9ab0[];
extern s32 data_ov000_021c9bb4[];

typedef struct {
    s32 a;
    u8 **list;
} LoPair;

typedef struct {
    s32 a;
    s32 b;
} LoIdx2;

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

void func_ov000_021692e0(void *self) {
    void *res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
    u8 *m = (u8 *)func_0203dd9c(0x160);
    if (m) {
        void *nm = data_0208cc88;
        func_02041218(m + 0x88);
        func_02041440(m, nm, 0);
    }
    LFLD(void *, self, 0x9c) = m;
    func_020417e0(m, res);
    LFLD(u32, LFLD(void *, self, 0x9c), 0x6c) |= 2;
    LFLD(u32, LFLD(void *, self, 0x9c), 0x6c) |= 0x200000;
    LFLD(u32, LFLD(void *, self, 0x9c), 0x6c) |= 0x80000;
    func_02041d9c(LFLD(void *, self, 0x9c), 0, 1);
    LFLD(s32, self, 0x30) = 0xc000;
    LFLD(s32, self, 0x50) = 0x30;
    LFLD(s32, self, 0x54) = 3;
    LFLD(s32, self, 0x28) = 0;
    LFLD(u32, self, 0xc) |= 0x360;
    LFLD(s32, self, 0x74) = 0;
    LFLD(s32, self, 0x78) = 0;
    LFLD(s32, self, 0x7c) = 0xffffe333;
    func_ov000_0215fdfc(self, 2, data_ov000_021c9ab0);
}

BOOL func_ov000_021693e0(void *self) {
    if (!LoGIdle() || !LoD78Idle()) {
        LBIT(self, 0xc).b1 = 1;
    }
    switch (LFLD(s32, self, 4)) {
    case 6:
        if (!LBIT(self, 0xc).b1 ? TRUE : FALSE) {
            LFLD(s32, self, 4) = 0;
            return TRUE;
        }
        return FALSE;
    case 1:
        if (!func_02054f10(LFLD(void *, self, 0x9c), 0xffff)) {
            return FALSE;
        }
        LBIT(self, 0xc).b3 = 1;
        break;
    }
    return TRUE;
}

}
