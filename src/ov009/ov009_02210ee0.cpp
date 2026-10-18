#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd64;
extern u8 data_ov009_022179b4[];
extern u8 data_ov009_02216148[];
extern u8 data_ov009_02216058[];
extern u8 data_ov009_02216188[];
extern u8 data_ov009_02216070[];
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);
extern Ov009Actor *func_ov000_0219bf90(void);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 7;
};

void func_ov009_02210ee0(Ov009Actor *self) {
    u8 *p;
    Ov009Actor *a;
    Ov009Game54 *g;
    func_ov003_021d112c(self);
    p = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        ((Ov009Byte *)(p + 0xa2))->b0 = 0;
    }
    self->unk_93_4 = 1;
    self->unk_90 = 0xffff;
    a = func_ov000_0219bf90();
    if (a != NULL) {
        self->unk_90 = a->id;
    }
    func_ov000_02190cb0(self->unk_38, data_ov009_022179b4, 0x1000, 0);
    func_ov000_021915a0(self->unk_38);
    FLD(u8, self, 0xfc) = 0;
    FLD(u8, self, 0xfd) = 0;
    FLD(u8, self, 0xfe) = 0;
    self->unk_48->unk_60 = 0x1800;
    self->unk_44->unk_10 = 0x1800;
    FLD(u8, self, 0xff) = 0;
    FLD(void *, self, 0x100) = data_ov009_02216148;
    FLD(void *, self, 0x104) = data_ov009_02216058;
    g = data_ov000_021ccd54;
    if (FLD(u8, g, 0xca) == 0x11 && FLD(u8, g, 0xcb) == 0 && FLD(u8, g, 0xcc) == 0) {
        FLD(u8, self, 0xff) = 1;
        FLD(void *, self, 0x100) = data_ov009_02216188;
        FLD(void *, self, 0x104) = data_ov009_02216070;
    }
}

}
