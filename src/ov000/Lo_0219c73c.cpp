#include "ov000/LoCommon.h"

typedef struct {
    u16 b0 : 11;
    u16 b11 : 1;
    u16 b12 : 4;
} Bits0219c73c;

extern "C" {
BOOL func_ov000_0218f110(void *p);
BOOL func_ov000_02191b9c(void *p);
void func_ov000_0219c8e0(void *self);

struct Obj0219c73c {
    u8 unk_00[0x3c];
    u8 *unk_3c;
    u8 unk_40[0x154];
    s16 unk_194;
    u8 unk_196[0x2ba];
    s16 unk_450;
    u8 unk_452[0x136];
    s16 unk_588;
    u8 unk_58a[0x2d6];
    s16 unk_860;
    u8 unk_862[0x13a];
    s16 *unk_99c;
    u8 unk_9a0[0x182];
    Bits0219c73c unk_b22;
    u8 unk_b24[0x7c];
    u8 *unk_ba0;
};

BOOL func_ov000_0219c73c(Obj0219c73c *self) {
    BOOL ret = TRUE;
    if (self->unk_194 >= 0 && !func_ov000_0218f110((u8 *)self + 0x194)) {
        ret = FALSE;
    }
    if (self->unk_860 >= 0 && !func_ov000_0218f110((u8 *)self + 0x860)) {
        ret = FALSE;
    }
    {
        u8 *p = self->unk_3c;
        BOOL ok = TRUE;
        if (p[0x1b] != 3 && p[0x1b] != 0) {
            ok = FALSE;
        }
        if (!ok && !func_ov000_02191b9c(p)) {
            ret = FALSE;
        }
    }
    if (self->unk_450 >= 0 && !func_ov000_0218f110((u8 *)self + 0x450)) {
        ret = FALSE;
    }
    {
        u8 *p = self->unk_ba0;
        if (p != NULL && p[0x18] != 0 && self->unk_588 >= 0 && !func_ov000_0218f110((u8 *)self + 0x588)) {
            ret = FALSE;
        }
    }
    {
        s16 *q = self->unk_99c;
        if (q != NULL && *q >= 0 && !func_ov000_0218f110(q)) {
            ret = FALSE;
        }
    }
    if (ret && self->unk_b22.b11) {
        func_ov000_0219c8e0(self);
        self->unk_b22.b11 = 0;
    }
    return ret;
}

}
