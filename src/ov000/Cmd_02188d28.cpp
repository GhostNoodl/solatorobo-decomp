#include "ov000/CmdQueue.h"

typedef struct {
    u8 unk_00[0x4];
    CmdQueue *unk_04;
} Data021ccd50;

typedef struct {
    u16 flags;
} Obj02097e48;

typedef struct {
    u8 c[3];
} Rgb3;

typedef struct {
    u8 unk_00[0x52];
    u16 unk_52;
} Data02fe1534;

extern "C" {
extern Data021ccd50 data_ov000_021ccd50;
extern Obj02097e48 *data_02097e48;
extern void *data_02fe152c;
extern Data02fe1534 data_02fe1534;
BOOL func_ov000_0219bf90(void *p);
u16 func_020594bc(void *a, int b, int c, int d);
u32 func_0205975c(void *a, int idx);
void *func_0205976c(void *a, int idx);
u16 func_02059544(void *a, void *b, void *c, u16 d, u16 e);
BOOL func_020624d8(void);

void func_ov000_02188d28(Rgb3 *rgb) {
    if (!func_ov000_0219bf90(rgb)) {
        CmdQueue_Push(data_ov000_021ccd50.unk_04, 0xb, 0);
    }
    data_02097e48->flags |= 2;
    CmdQueue_Push(data_ov000_021ccd50.unk_04, 0xa, 0);
    if (rgb != NULL) {
        *(Rgb3 *)((u8 *)data_ov000_021ccd50.unk_04 + 0xcd) = *rgb;
    }
}

BOOL func_ov000_02188dfc(void) {
    u8 *base;
    s32 n;
    u16 i;
    u16 *tbl;
    u32 count;
    if (func_020594bc(data_02fe152c, 5, 1, 2) == 1) {
        return TRUE;
    }
    if (func_020624d8()) {
        n = 0;
        base = *(u8 **)((u8 *)data_02fe152c + 0x4c);
        tbl = (u16 *)func_0205976c(data_02fe152c, 0);
        count = func_0205975c(data_02fe152c, 0);
        for (i = 0; i < count; i++) {
            if (!func_02059544(data_02fe152c, base + 0x10, tbl, 1, i)) {
                if (data_02fe1534.unk_52 != tbl[i * 2 + 1]) {
                    n++;
                }
            }
        }
        if (n == 0) {
            return TRUE;
        }
    }
    return FALSE;
}
}
