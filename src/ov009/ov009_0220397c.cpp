#include "ov009/ov009.h"

extern "C" {

extern void *data_ov009_02215d0c[];
extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_02049564(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(Ov009Game54 *g, s32 a);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 4;
    u8 b5 : 1;
    u8 b6 : 2;
};

void func_ov009_0220397c(Ov009Names *self, void *res) {
    char *a = func_0207011c(res);
    char *b = func_020701d4(res);
    u8 *c = func_02070558(res);
    char *s;
    char *t;
    STD_CopyString(self->unk_10, a);
    STD_CopyString(self->unk_30, b);
    self->unk_03_1 = 1;
    s = (char *)data_ov009_02215d0c[11];
    STD_CopyString(self->unk_4c, s);
    STD_CopyString(self->unk_6c, (char *)data_ov009_02215d0c[13]);
    self->unk_03_2 = 1;
    t = FLD(char *, c, 0x28);
    if (t != NULL) {
        STD_CopyString(self->unk_c4, s);
        STD_CopyString(self->unk_e4, t);
        self->unk_03_4 = 1;
    }
    self->unk_00 = 0;
}

extern u8 data_ov009_02215d64[];
extern void func_ov003_021d6bac(Ov009Actor *self, const void *a);

void func_ov009_02203a3c(Ov009Actor *self) {
    u8 *p;
    if (self->kind == 0x5053) {
        FLD(void *, self, 0xd8) = (void *)func_ov009_0220397c;
    }
    func_ov003_021d0fc0(self);
    p = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        Ov009Byte *bb = (Ov009Byte *)(p + 0xa2);
        bb->b0 = 0;
        bb->b5 = 1;
    }
    func_02049564(data_02097e4c, 1, 1);
    switch (self->kind) {
    case 0x502e:
    case 0x5033:
    case 0x504c:
        func_ov000_02187a20(data_ov000_021ccd54, 0xd);
        self->unk_1a = 0;
        break;
    case 0x5053:
        func_ov000_02187a20(data_ov000_021ccd54, 0x10);
        self->unk_1a = 1;
        break;
    case 0x5059:
        func_ov000_02187a20(data_ov000_021ccd54, 0xd);
        self->unk_1a = 0;
        func_ov003_021d6bac(self, data_ov009_02215d64);
        break;
    }
    self->unk_c8 = 0x1e000;
    self->unk_cc = 0xc000;
    FLD(s32, self, 0xf0) = 0;
}

}
