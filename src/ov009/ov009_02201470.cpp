#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern void *data_ov009_02215d0c[];
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d46c(Ov009Actor *a, u16 id, s32 msg);
extern void func_ov000_0218fa28(Ov009Sub38 *m, void *a, void *b, void *c, void *anim, s32 d, s32 e);
extern void func_02049564(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(void *p, s32 a);
extern void func_ov009_0220189c(Ov009Actor *self);
extern void func_ov009_02201eac(Ov009Actor *self);

void func_ov009_02201470(Ov009Actor *self) {
    func_ov003_021d0fc0(self);
    func_02049564(data_02097e4c, 1, 1);
    switch (self->kind) {
    case 0x5047:
        func_ov000_02187a20(data_ov000_021ccd54, 0xd);
        self->unk_1a = 0;
        break;
    case 0x503f:
    case 0x5048:
        func_ov000_02187a20(data_ov000_021ccd54, 0xe);
        self->unk_1a = 1;
        break;
    case 0x5035:
        func_ov000_02187a20(data_ov000_021ccd54, 0xf);
        self->unk_1a = 2;
        break;
    case 0x5054:
        func_ov000_02187a20(data_ov000_021ccd54, 0x10);
        self->unk_1a = 3;
        break;
    }
    self->unk_ea_10 = 1;
    FLD(s32, self, 0x108) = -1;
}

void func_ov009_02201574(Ov009Actor *self) {
    u32 *p;
    func_ov003_021d112c(self);
    p = (u32 *)func_0203dd9c(4);
    if (p != NULL) {
        *p = 0;
    }
    FLD(u32 *, self, 0x104) = p;
    FLD(u16, self, 0xf0) = 0;
    switch (self->kind) {
    case 0x503f:
    case 0x5048:
        FLD(s8, self, 0xf5) = 0;
        FLD(u16, self, 0xf2) = 0x78;
        break;
    case 0x5035:
    case 0x5047:
    case 0x5054:
        FLD(s8, self, 0xf5) = 1;
        switch (self->kind) {
        case 0x5047:
            FLD(u16, self, 0xf2) = 0x78;
            break;
        case 0x5035:
            FLD(u16, self, 0xf2) = 0x96;
            break;
        case 0x5054:
            FLD(u16, self, 0xf2) = 0x50;
            break;
        }
        self->unk_c8 = 0x16000;
        self->unk_cc = 0xc000;
        break;
    }
}

}
