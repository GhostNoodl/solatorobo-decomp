#include "ov000/LoCommon.h"

extern "C" {

extern void *data_02fe152c;
extern u8 data_ov000_021ccd24[];
extern void *data_02097e4c;
void *func_0205976c(void *a, s32 b);
u32 func_0205975c(void *a, s32 b);
u32 func_ov000_0214bf2c(u16 a);
BOOL func_02059544(void *a, void *b, void *c, s32 d, s32 e);
BOOL func_0205a9c8(void *p);
void func_0204c7d0(void *p);
void *func_ov000_02173610(s32 kind);
void *func_ov000_0219bf90(void *p);
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

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

BOOL func_ov000_0214be8c(void) {
    void *p = LFLD(void *, data_02fe152c, 0x4c);
    u8 *tbl = (u8 *)func_0205976c(data_02fe152c, 1);
    u32 n = func_0205975c(data_02fe152c, 1);
    u16 i;
    for (i = 0; i < n; i++) {
        u32 fl = func_ov000_0214bf2c(LFLD(u16, tbl + i * 4, 2));
        if (!(fl & 0x100) && !(fl & 0x40)) {
            if (!func_02059544(data_02fe152c, (u8 *)p + 0x30, tbl, 0x301, i)) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

}
