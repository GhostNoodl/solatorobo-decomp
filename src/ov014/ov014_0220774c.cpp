#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_022177a0[];
extern void func_ov000_02194074(void *self);
extern void func_ov000_02194758(void *self);
extern void *data_ov000_021ccd64;
extern void *data_0214a420;
extern void func_ov003_021daa6c(void *p, s32 a);
extern void *func_ov003_021daa3c(void *p, u8 id);
extern Ov014V *func_020657b0(void *a, void *b);
extern void func_ov000_0219bd20(s32 a, u16 b, s32 c, s32 d, s32 e, u8 *f);
extern void func_ov000_0218bed8(void *a, s32 b, void *c);

void func_ov014_022075f4(Ov014Actor *self) {
    // volatile read keeps the state reload in case 1 (no CSE with the switch value)
    switch (*(volatile u16 *)&self->unk_40->state) {
    case 0:
        func_ov003_021daa6c(FLD(void *, self, 0xdc), 0xfe);
        self->unk_40->state++;
        break;
    case 1:
        if (FLD(s32, self, 0xd4) > 0) {
            Ov014V *o;
            FLD(s32, self, 0xd4) += -0x266;
            if (FLD(s32, self, 0xd4) <= 0) {
                FLD(s32, self, 0xd4) = 0;
            }
            o = func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0xdc), 0xff));
            if (o != NULL) {
                o->v14(FLD(s32, self, 0xd4), FLD(s32, self, 0xd4), FLD(s32, self, 0xd4));
            }
        } else {
            self->unk_40->state++;
        }
        break;
    case 2: {
        u8 c;
        func_ov003_021daa6c(FLD(void *, self, 0xdc), 0xff);
        c = 10;
        func_ov000_0219bd20(0x5c0e, self->kind, 6, 1, 1, &c);
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->v08();
        self->unk_40->state++;
        break;
    }
    }
}

#pragma force_active on
Ov014Actor *func_ov014_0220774c(Ov014Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov014_022177a0;
    FLD(s32, self, 0xd0) = 0;
    FLD(void *, self, 0xd8) = NULL;
    return self;
}
#pragma force_active reset

Ov014Actor *func_ov014_02207778(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_022177a0;
    Ov014_FreeFx(self, 0xd8);
    func_ov000_0219429c(self);
    return self;
}

Ov014Actor *func_ov014_022077e8(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_022177a0;
    Ov014_FreeFx(self, 0xd8);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov014_02207860(Ov014Actor *self) {
    func_ov000_02194758(self);
    FLD(s32 *, self, 0xd8) = Ov014_NewFx();
    FLD(s32, self, 0xd4) = 0;
    func_ov000_02198360(self->unk_40, 0xb, 0);
}

void func_ov014_0220789c(Ov014Actor *self) {
    func_ov000_021953b4(self);
    func_ov003_021dacfc(FLD(void *, self, 0xd8));
}

}
