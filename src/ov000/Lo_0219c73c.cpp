#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"


extern "C" {
BOOL ResSet_UpdateLoad(void *p);
BOOL Shadow_UpdateLoad(void *p);
void func_ov000_0219c8e0(Robo021ca458 *self);

BOOL Robo021ca458_IsReady(Robo021ca458 *self) {
    BOOL ret = TRUE;
    if (self->res0.unk_00 >= 0 && !ResSet_UpdateLoad(&self->res0)) {
        ret = FALSE;
    }
    if (self->res3.unk_00 >= 0 && !ResSet_UpdateLoad(&self->res3)) {
        ret = FALSE;
    }
    {
        u8 *p = (u8 *)self->unk_3c;
        BOOL ok = TRUE;
        if (p[0x1b] != 3 && p[0x1b] != 0) {
            ok = FALSE;
        }
        if (!ok && !Shadow_UpdateLoad(p)) {
            ret = FALSE;
        }
    }
    if (self->res1.unk_00 >= 0 && !ResSet_UpdateLoad(&self->res1)) {
        ret = FALSE;
    }
    {
        u8 *p = self->unk_ba0;
        if (p != NULL && p[0x18] != 0 && self->res2.unk_00 >= 0 && !ResSet_UpdateLoad(&self->res2)) {
            ret = FALSE;
        }
    }
    {
        s16 *q = ((s16 *)self->unk_99c);
        if (q != NULL && *q >= 0 && !ResSet_UpdateLoad(q)) {
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
