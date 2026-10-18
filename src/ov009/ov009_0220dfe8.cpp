#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd64;
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_ov000_0218b700(u8 *p, s32 a, s32 b);
extern void func_0203f2b8(void *p);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 7;
};

void func_ov009_0220dfe8(Ov009Actor *self) {
    u32 saved;
    u8 *p;
    func_ov003_021d112c(self);
    FLD(Ov009Vec, self, 0xf0) = self->pos;
    self->pos.y -= 0x1e000;
    self->pos.x += 0x1e000;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_48 != NULL) {
        Ov009Sub48 *s = self->unk_48;
        if (s != NULL) {
            func_0203f2b8(s);
            func_0203de1c(s);
        }
        self->unk_48 = NULL;
    }
    data_02097dd0->cur = saved;
    p = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        ((Ov009Byte *)(p + 0xa2))->b0 = 0;
        func_ov000_0218b700(p, 0x3000, 0);
    }
    FLD(Ov009Vec, self, 0xfc) = FLD(Ov009Vec, self, 0xf0);
    FLD(u8, self, 0x108) = 0;
    FLD(u8, self, 0x109) = func_02040498(2);
    self->unk_ea_6 = 1;
}

}
