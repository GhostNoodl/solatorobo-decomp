#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_02217dc0[];
extern char data_ov014_02217d8e[];
extern char data_ov014_02217d95[];
extern void func_ov000_0218e9c4(void *p);
extern void func_ov000_0218fe1c(void *p);
extern void func_ov000_0218fee4(void *p);
extern void func_ov000_0218ea20(void *p);
extern void MIi_CpuClearFast(s32 v, void *p, u32 n);
extern BOOL func_ov000_0218cf5c(Ov014Actor *self);
extern BOOL func_ov000_0218f110(void *p);
extern s32 func_ov003_021d1c00(Ov014Actor *self, Ov014Msg *msg);

BOOL func_ov014_02212780(Ov014Actor *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (FLD(s16, self, 0xf0) >= 0) {
        r = (r & func_ov000_0218f110((u8 *)self + 0xf0)) ? TRUE : FALSE;
    }
    return r;
}

BOOL func_ov014_022127b8(Ov014Actor *self) {
    return func_ov003_021d16cc(self);
}

}
