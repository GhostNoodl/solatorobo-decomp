#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_02217dc0[];
extern char data_ov014_02217d8e[];
extern char data_ov014_02217d95[];
extern void *func_ov000_0218e9c4(void *p);
extern void *func_ov000_0218fe1c(void *p);
extern void *func_ov000_0218fee4(void *p);
extern void *func_ov000_0218ea20(void *p);
extern void MIi_CpuClearFast(s32 v, void *p, u32 n);
extern BOOL func_ov000_0218cf5c(Ov014Actor *self);
extern BOOL func_ov000_0218f110(void *p);
extern s32 func_ov003_021d1c00(Ov014Actor *self, Ov014Msg *msg);

#pragma force_active on
Ov014Actor *Ov014Act_0221267c_Ctor(Ov014Act_0221267c *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = data_ov014_02217dc0;
    func_ov000_0218e9c4((u8 *)self + 0xf0);
    func_ov000_0218fe1c((u8 *)self + 0x228);
    self->unk_310 = 0;
    self->unk_312 = 0;
    MIi_CpuClearFast(0, (u8 *)self + 0x314, 0x34);
    self->unk_34c = 0;
    self->unk_348 = 0;
    self->unk_350 = 0;
    self->unk_354 = 0;
    return self;
}
#pragma force_active reset

Ov014Act_0221267c *Ov014Act_0221267c_Dtor(Ov014Act_0221267c *self) {
    func_ov000_0218fee4((u8 *)self + 0x228);
    func_ov000_0218ea20((u8 *)self + 0xf0);
    func_ov003_021d0edc(self);
    return self;
}

Ov014Act_0221267c *Ov014Act_0221267c_DtorDelete(Ov014Act_0221267c *self) {
    func_ov000_0218fee4((u8 *)self + 0x228);
    func_ov000_0218ea20((u8 *)self + 0xf0);
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

static inline void Ov014Names_Set(u8 *n, const char *a, const char *b) {
    STD_CopyString((char *)n + 0x10, a);
    STD_CopyString((char *)n + 0x30, b);
    FLD(Ov014Flags8, n, 3).b1 = 1;
}

void Ov014Act_0221267c_Init(Ov014Act_0221267c *self) {
    func_ov003_021d0fc0(self);
    {
        const char *b = data_ov014_02217d8e;
        u8 *n = (u8 *)self + 0xf0;
        if (b) {
            Ov014Names_Set(n, data_ov014_02217d95, b);
        }
        FLD(u16, n, 0) = 0;
    }
}

}
