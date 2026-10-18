#include "ov014/ov014.h"

struct Ov014A {
    u8 unk_00[0xf8];
    Ov014Vec unk_f8[2];
};

struct Ov014Flags127 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
};

extern "C" {

extern u8 data_ov014_02217114[];
extern const Ov014Vec data_ov014_02216468[];
extern u8 data_ov014_022170d8[];
extern char data_ov014_022170e7[];
extern char data_ov014_022170f4[];
extern void *data_02097cdc;
extern void *data_02097e4c;

extern void func_ov000_0218e9c4(void *p);
extern void func_ov000_0218fe1c(void *p);
extern void func_ov003_021ceedc(void *p);
extern void func_ov003_021cef0c(void *p);
extern void func_ov000_0218fee4(void *p);
extern void func_ov000_0218ea20(void *p);
extern BOOL func_02035b90(void *a, s32 b);
extern void func_02036838(void *a, void *b, s32 c, s32 d);
extern void func_02049564(void *a, s32 b, s32 c);
extern void func_ov000_02187a20(void *a, s32 b);
extern void func_020359d0(void *a, s32 b, s32 c);

#pragma force_active on
Ov014Actor *func_ov014_021fa6a0(Ov014Actor *self) {
    u8 i;
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = data_ov014_02217114;
    func_ov000_0218e9c4((u8 *)self + 0x124);
    func_ov000_0218fe1c((u8 *)self + 0x25c);
    func_ov003_021ceedc((u8 *)self + 0x348);
    for (i = 0; i < 2; i++) {
        ((Ov014A *)self)->unk_f8[i] = data_ov014_02216468[i];
    }
    FLD(u8, self, 0xf0) = 0;
    FLD(s32, self, 0xf4) = 0;
    FLD(s32, self, 0x344) = 0;
    FLD(u8, self, 0x11e) = 0;
    FLD(u8, self, 0x11f) = 0;
    FLD(u16, self, 0x364) = 0x1000;
    return self;
}
#pragma force_active reset

static inline void Ov014_StopSnd(void) {
    if (func_02035b90(data_ov014_022170d8, 7)) {
        func_02036838(data_02097cdc, data_ov014_022170d8, 7, 0);
    }
}

void *func_ov014_021fa740(void *self) {
    FLD(void *, self, 0) = data_ov014_02217114;
    Ov014_StopSnd();
    func_ov003_021cef0c((u8 *)self + 0x348);
    func_ov000_0218fee4((u8 *)self + 0x25c);
    func_ov000_0218ea20((u8 *)self + 0x124);
    func_ov003_021d0edc(self);
    return self;
}

void *func_ov014_021fa7b8(void *self) {
    FLD(void *, self, 0) = data_ov014_02217114;
    Ov014_StopSnd();
    func_ov003_021cef0c((u8 *)self + 0x348);
    func_ov000_0218fee4((u8 *)self + 0x25c);
    func_ov000_0218ea20((u8 *)self + 0x124);
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

}
