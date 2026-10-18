#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x8];
    u16 unk_08;
    u16 unk_0a;
    u16 unk_0c;
    u16 unk_0e;
} Data02fe1534;

typedef struct {
    u8 unk_00[0xc8];
    u16 unk_c8;
    u16 unk_ca;
    u16 unk_cc;
    u16 unk_ce;
} Obj02181efc;

extern "C" {

extern Data02fe1534 data_02fe1534;
s32 func_0205aa98(Obj02181efc *self, s32 a);

s32 func_ov000_02181efc(Obj02181efc *self, s32 a) {
    s32 r;
    Data02fe1534 *d = &data_02fe1534;
    d->unk_08 = self->unk_c8;
    d->unk_0a = self->unk_ca;
    d->unk_0c = self->unk_cc;
    d->unk_0e = self->unk_ce;
    r = func_0205aa98(self, a);
    self->unk_c8 = d->unk_08;
    self->unk_ca = d->unk_0a;
    self->unk_cc = d->unk_0c;
    self->unk_ce = d->unk_0e;
    return r;
}

}
