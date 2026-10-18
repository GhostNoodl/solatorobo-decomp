#include "ov013/ov013.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern u8 data_ov013_0220b03a[];
extern u8 data_ov013_0220b064[];
extern u8 data_ov013_0220b108[];
extern u8 data_ov013_0220b218[];
extern BOOL func_ov003_021d984c(void *p, void *tbl);
extern void func_ov003_021d95e8(void *p, void *tbl, s32 n);
extern void func_ov003_021d969c(void *p, s32 a);
extern Ov013Actor *func_ov000_0218e6d0(void *mgr, u16 a, u16 b);

void func_ov013_02202c88(Ov013Actor *self) {
    void *tbl = NULL;
    s32 n = 0;
    switch (FLD(u8, self, 0x15d)) {
    case 1:
        tbl = data_ov013_0220b03a;
        n = 7;
        break;
    case 2:
        tbl = data_ov013_0220b064;
        n = 7;
        break;
    }
    if (!func_ov003_021d984c((u8 *)self + 0x14c, tbl)) {
        func_ov003_021d95e8((u8 *)self + 0x14c, tbl, n);
    }
}

void func_ov013_02202cec(Ov013Actor *self) {
    void *tbl = NULL;
    s32 n = 0;
    switch (FLD(u8, self, 0x15d)) {
    case 1:
        tbl = data_ov013_0220b218;
        n = 0x14;
        break;
    case 2:
        tbl = data_ov013_0220b108;
        n = 0xc;
        break;
    }
    if (!func_ov003_021d984c((u8 *)self + 0x14c, tbl)) {
        func_ov003_021d95e8((u8 *)self + 0x14c, tbl, n);
    }
}

void func_ov013_02202d50(Ov013Actor *self) {
    BOOL f = FALSE;
    Ov013Actor *a;
    if (data_ov000_021ccd68 == NULL) {
        a = NULL;
    } else {
        a = func_ov000_0218e6d0(data_ov000_021ccd68, 0x4000, 0x483e);
    }
    if (a != NULL) {
        u8 k;
        if (a->unk_40 != NULL) {
            k = a->unk_40->unk_13;
        } else {
            k = 0;
        }
        if (k == 9) {
            f = TRUE;
        }
    }
    if (!f) {
        func_ov003_021d969c((u8 *)self + 0x14c, 0);
    } else {
        func_ov003_021d969c((u8 *)self + 0x14c, 1);
    }
}

}
