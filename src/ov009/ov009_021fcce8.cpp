#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern void *data_ov000_021ccd30;
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_02049564(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(void *p, s32 a);
extern void func_ov000_0216912c(void *p, u16 id, s32 a, u16 b, u16 c, const Ov009Vec *pos);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 4;
    u8 b5 : 1;
    u8 b6 : 2;
};

void func_ov009_021fcce8(Ov009Actor *self) {
    u8 *p;
    func_ov003_021d0fc0(self);
    func_02049564(data_02097e4c, 1, 1);
    if (self->kind != 0x5038 && self->kind != 0x5044) {
        return;
    }
    func_ov000_02187a20(data_ov000_021ccd54, 0xd);
    self->unk_18 = 1;
    p = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        ((Ov009Byte *)(p + 0xa2))->b5 = 1;
    }
    if (self->kind != 0x5044) {
        return;
    }
    self->pos.y += 0x1000;
    if (FLD(u8, data_ov000_021ccd54, 0xca) == 0x11) {
        self->pos.y += 0x1000;
    }
}

void func_ov009_021fcda8(Ov009Actor *self) {
    Ov009Sub48 *s48;
    func_ov003_021d112c(self);
    FLD(Ov009Vec, self, 0xf0) = self->pos;
    FLD(Ov009Vec, self, 0xfc) = self->pos;
    if (FLD(u8, data_ov000_021ccd54, 0xca) != 0x11) {
        s48 = self->unk_48;
        s48->unk_9a_1 = 0;
        s48->unk_9a_4 = 0;
    }
    s48 = self->unk_48;
    s48->unk_9a_2 = 0;
    s48->unk_9a_5 = 0;
    if (self->kind != 0x5012) {
        self->unk_44->unk_1c += 0x800;
        self->unk_44->unk_10 = -0x1000;
        self->unk_48->unk_60 = -0x1000;
    }
    self->unk_ea_6 = 1;
    if (self->unk_1a != 0) {
        self->unk_40->flags |= 0x100000000ULL;
    }
}

}
