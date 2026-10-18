#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd64;
extern char data_ov009_022172af[];
extern char data_ov009_022172b5[];
extern void func_ov000_0218ffdc(Ov009Sub38 *m, void *res, s32 a, s32 b);
extern void func_ov000_02190758(Ov009Sub38 *m, u16 *rot, s32 a);
extern void func_ov000_021903b4(Ov009Sub38 *m);
extern void func_ov000_02190e98(void *p, s32 a, s32 b, s32 c);
extern void func_ov000_0218bed8(void *mgr, s32 a, Ov009Actor *actor);

struct Ov009Bits16 {
    u16 b0 : 1;
    u16 b1 : 15;
};

void func_ov009_02207aa0(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        self->unk_38->unk_c2_0 = 0;
        ((Ov009Bits16 *)&FLD(u8, self, 0x2ea))->b0 = 0;
        self->unk_40->state++;
    }
}

void func_ov009_02207ae4(Ov009Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_022172af, 0x1000, 1);
        self->unk_38->unk_c2_0 = 1;
        func_ov000_02190e98(&FLD(u8, self, 0x228), 0, 0x1000, 1);
        ((Ov009Bits16 *)&FLD(u8, self, 0x2ea))->b0 = 1;
        self->unk_40->state++;
        break;
    case 1:
        if (func_ov000_02191120(self->unk_38)) {
            self->unk_38->unk_c2_0 = 0;
            ((Ov009Bits16 *)&FLD(u8, self, 0x2ea))->b0 = 0;
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->v08();
        }
        break;
    }
}

void func_ov009_02207bd4(Ov009Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_022172b5, 0x1000, 1);
        self->unk_38->unk_c2_0 = 1;
        func_ov000_02190e98(&FLD(u8, self, 0x228), 1, 0x1000, 1);
        ((Ov009Bits16 *)&FLD(u8, self, 0x2ea))->b0 = 1;
        self->unk_40->state++;
        break;
    case 1:
        if (func_ov000_02191120(self->unk_38)) {
            self->unk_38->unk_c2_0 = 0;
            ((Ov009Bits16 *)&FLD(u8, self, 0x2ea))->b0 = 0;
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->v08();
        }
        break;
    }
}

BOOL func_ov009_02207cc4(void) {
    return FALSE;
}

}
