#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021da800(Obj021efe7c *self) {
    BOOL a = func_02035b90(data_ov002_021efdf6, 7) != 0 ? TRUE : FALSE;
    BOOL b;
    u8 *d = FIELD(((u8 *)self->board), 4, u8 *);
    b = TRUE;
    if (*FIELD(d, 4, s16 *) >= 0 && !func_ov000_0218f110(FIELD(d, 4, s16 *))) {
        b = FALSE;
    }
    if (*FIELD(d, 0xc, s16 *) >= 0 && !func_ov000_0218f110(FIELD(d, 0xc, s16 *))) {
        b = FALSE;
    }
    if (*FIELD(d, 0x14, s16 *) >= 0 && !func_ov000_0218f110(FIELD(d, 0x14, s16 *))) {
        b = FALSE;
    }
    return (a & b) ? TRUE : FALSE;
}

void func_ov002_021da894(Obj021efe7c *self) {
    func_ov002_021d95e0(self->board);
    func_ov002_021dab58(self, self->unk_0c);
    EffectMgr_SaveList(data_0214a420);
    *(s32 *)data_0214a420 = 0;
    self->unk_10 = 1;
}

BOOL func_ov002_021da8d8(Obj021efe7c *self) {
    BOOL r = TRUE;
    VObj *o;
    func_ov002_021d9728(self->board);
    o = self->unk_08;
    if (o != NULL) {
        o->vfunc_0c();
        self->unk_08->vfunc_10();
        if (self->unk_08->vfunc_18()) {
            func_ov002_021dab58(self, FIELD(((void *)self->unk_08), 8, int));
        }
    }
    if (((void *)self->unk_08) == NULL) {
        r = FALSE;
    }
    func_02065ac0(data_0214a420);
    return r;
}

}
