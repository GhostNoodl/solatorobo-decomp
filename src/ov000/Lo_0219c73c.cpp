#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
BOOL func_ov000_0218f110(void *p);
BOOL func_ov000_02191b9c(void *p);
void func_ov000_0219c8e0(void *self);

BOOL Robo021ca458_IsReady(Robo021ca458 *self) {
    BOOL ret = TRUE;
    if (self->res0.unk_00 >= 0 && !func_ov000_0218f110((u8 *)self + 0x194)) {
        ret = FALSE;
    }
    if (self->res3.unk_00 >= 0 && !func_ov000_0218f110((u8 *)self + 0x860)) {
        ret = FALSE;
    }
    {
        u8 *p = (u8 *)self->unk_3c;
        BOOL ok = TRUE;
        if (p[0x1b] != 3 && p[0x1b] != 0) {
            ok = FALSE;
        }
        if (!ok && !func_ov000_02191b9c(p)) {
            ret = FALSE;
        }
    }
    if (self->res1.unk_00 >= 0 && !func_ov000_0218f110((u8 *)self + 0x450)) {
        ret = FALSE;
    }
    {
        u8 *p = self->unk_ba0;
        if (p != NULL && p[0x18] != 0 && self->res2.unk_00 >= 0 && !func_ov000_0218f110((u8 *)self + 0x588)) {
            ret = FALSE;
        }
    }
    {
        s16 *q = ((s16 *)self->unk_99c);
        if (q != NULL && *q >= 0 && !func_ov000_0218f110(q)) {
            ret = FALSE;
        }
    }
    if (ret && self->unk_b22_11) {
        func_ov000_0219c8e0(self);
        self->unk_b22_11 = 0;
    }
    return ret;
}

}
