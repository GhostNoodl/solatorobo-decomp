#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021da800(void *self) {
    BOOL a = func_02035b90(data_ov002_021efdf6, 7) != 0 ? TRUE : FALSE;
    BOOL b;
    u8 *d = FIELD(FIELD(self, 4, u8 *), 4, u8 *);
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

void func_ov002_021da894(void *self) {
    func_ov002_021d95e0(FIELD(self, 0x4, void *));
    func_ov002_021dab58(self, FIELD(self, 0xc, s32));
    func_02065eec(data_0214a420);
    *data_0214a420 = 0;
    FIELD(self, 0x10, u8) = 1;
}

BOOL func_ov002_021da8d8(void *self) {
    BOOL r = TRUE;
    VObject *o;
    func_ov002_021d9728(FIELD(self, 4, void *));
    o = FIELD(self, 8, VObject *);
    if (o != NULL) {
        o->v0xc();
        FIELD(self, 8, VObject *)->v0x10();
        if (FIELD(self, 8, VObject *)->v0x18()) {
            func_ov002_021dab58(self, FIELD(FIELD(self, 8, void *), 8, int));
        }
    }
    if (FIELD(self, 8, void *) == NULL) {
        r = FALSE;
    }
    func_02065ac0(data_0214a420);
    return r;
}

}
