#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

void func_0203df0c(void *p);
BOOL func_ov000_02152a58(void *self);
BOOL func_02054f10(void *p, s32 a);
BOOL func_0203e63c(void *p);
void func_ov000_0215429c(void *self);
void func_ov000_0215f0ec(void *p, s32 a);

static inline BOOL LoSubReady(void *p) {
    if (LFLD(void *, p, 0x6c) == NULL) {
        return TRUE;
    }
    if (func_0203e63c(LFLD(void *, p, 0x6c))) {
        LFLD(void *, p, 0x6c) = NULL;
    } else {
        return LBIT(p, 4).b6 == 0 ? TRUE : FALSE;
    }
    return TRUE;
}

void func_ov000_02157c28(LoBase021cb2a8_021cb4a8 *self) {
    s32 v;
    self->unk_64 = (self->unk_0c & 0x4000000) ? 0 : 0xc;
    self->unk_24 = 0x100 - self->unk_64 * 2;
    func_ov000_0215429c(self);
    v = self->unk_24;
    self->unk_2c = 1;
    self->unk_58 = v + 0x10;
    self->unk_5c = 0;
    self->unk_60 = 0;
    LFLD(s32, self->unk_ac, 0x10) = (v - 0x10) << 12;
}

struct Obj02157c90 {
    u8 unk_00[0xd4];
    void *unk_d4;
};

void func_ov000_02157c90(Obj02157c90 *self, s32 a) {
    void *p = func_0203dd9c(0x2c);
    if (p != NULL) {
        LFLD(s32, p, 0x0) = 0;
        LFLD(s32, p, 0x4) = 0;
        LFLD(s32, p, 0x8) = 0;
        LFLD(s32, p, 0xc) = 0;
        LFLD(s32, p, 0x10) = 0;
        LFLD(s32, p, 0x14) = 0x80;
        LFLD(s32, p, 0x18) = 6;
        LFLD(s32, p, 0x24) = 0;
        LFLD(s32, p, 0x28) = 0;
    }
    self->unk_d4 = p;
    if (LBIT(self, 0xc).b6 ? TRUE : FALSE) {
        LFLD(u32, self->unk_d4, 0) |= 0x10;
    }
    func_ov000_0215f0ec(self->unk_d4, a);
    LFLD(s32, self->unk_d4, 0x14) = LFLD(s32, LFLD(void *, self->unk_d4, 0x24), 0x44) + 0x10;
}

}
