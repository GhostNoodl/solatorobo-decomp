#include "ov000/LoCommon.h"

extern "C" {

extern void *data_02fe152c;
extern u8 data_ov000_021ccd24[];
extern void *data_02097e4c;
void *func_0205976c(void *a, s32 b);
u32 func_0205975c(void *a, s32 b);
u32 func_ov000_0214bf2c(u16 a);
u16 func_02059544(void *a, void *b, void *c, s32 d, s32 e);
BOOL func_0205a9c8(void *p);
void func_0204c7d0(void *p);
void *func_ov000_02173610(s32 kind);
void *func_ov000_0219bf90(void);
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
} LoBits8;

typedef struct {
    u32 y : 8;
    u32 a : 8;
    u32 x : 9;
    u32 b : 7;
    u32 unk_04;
} LoOam;

static inline BOOL LoIsLoaded24(void) {
    BOOL r = TRUE;
    if (!func_0205a9c8(LFLD(void *, data_ov000_021ccd24, 8))) {
        r = FALSE;
    }
    return r;
}

void func_ov000_0215158c(void *self) {
    void *t = func_ov000_02173610(0xe);
    void *m;
    void *s;
    if (t == NULL) {
        return;
    }
    m = func_ov000_0219bf90();
    s = LFLD(void *, t, 0x50);
    switch (LFLD(s32, self, 4)) {
    case 0:
        LFLD(u32, s, 0xc) |= 0x20;
        break;
    case 3:
        LFLD(LoBits8, m, 0xb28).b3 = 1;
        break;
    case 1:
        LFLD(LoBits8, m, 0xb28).b3 = 0;
        break;
    case 2:
        break;
    case 4:
        LFLD(u32, s, 0xc) &= ~0x20;
        break;
    }
}

}
