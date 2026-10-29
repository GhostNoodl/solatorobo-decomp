#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov009_02215d0c[];
extern void *data_ov009_0221707c;
extern u8 data_ov009_02216bb4[];
extern u8 data_ov009_02216bba[];
extern void func_02049564(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(void *p, s32 a);
extern void func_ov003_021d452c(Ov009Actor *self);
extern s32 func_ov003_021d1e30(s32 a);
extern void *func_ov003_021da940(void *p);
extern void *func_0204a028(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void *func_ov000_02191318(Ov009Sub38 *m, s32 a);
void func_ov009_02205d94(Ov009Names *self, void *res);

struct Ov009Rot {
    s16 x;
    s16 y;
    s16 z;
};

void func_ov009_02205d14(Ov009Actor *self) {
    if (self->unk_40->state == 0 && FLD(u8, self, 0xf2) == 0) {
        self->unk_64 >>= 1;
    }
    func_ov003_021d6054(self);
}

void func_ov009_02205d40(Ov009Actor *self) {
    func_ov003_021d0fc0(self);
    func_02049564(data_02097e4c, 1, 1);
    func_ov000_02187a20(data_ov000_021ccd54, 0xe);
}

void func_ov009_02205d78(Ov009Actor *self) {
    if (self->unk_1a != 0) {
        self->unk_cc = 0xc000;
    }
    func_ov003_021d1e8c(self);
}

void func_ov009_02205d94(Ov009Names *self, void *res) {
    char *a = func_0207011c(res);
    char *b = func_020701d4(res);
    u8 *c = func_02070558(res);
    char *s;
    char *t;
    STD_CopyString(self->unk_10, a);
    STD_CopyString(self->unk_30, b);
    self->unk_03_1 = 1;
    s = (char *)data_ov009_02215d0c[15];
    STD_CopyString(self->unk_4c, s);
    STD_CopyString(self->unk_6c, (char *)data_ov009_02215d0c[14]);
    self->unk_03_2 = 1;
    t = FLD(char *, c, 0x28);
    if (t != NULL) {
        STD_CopyString(self->unk_c4, s);
        STD_CopyString(self->unk_e4, t);
        self->unk_03_4 = 1;
    }
    self->unk_00 = 0;
}

void func_ov009_02205e54(Ov009Actor *self) {
    if (self->kind == 0x5051) {
        FLD(void *, self, 0xd8) = (void *)func_ov009_02205d94;
    }
    func_ov003_021d0fc0(self);
    func_02049564(data_02097e4c, 1, 1);
    switch (self->kind) {
    case 0x5014:
    case 0x501e:
    case 0x5028:
    case 0x502c:
    case 0x5034:
    case 0x5043:
        func_ov000_02187a20(data_ov000_021ccd54, 0xd);
        break;
    case 0x5019:
    case 0x501a:
    case 0x5020:
    case 0x502b:
    case 0x5051:
    case 0x5052:
    case 0x505a:
    case 0x505b:
        func_ov000_02187a20(data_ov000_021ccd54, 0xe);
        break;
    }
    self->unk_ea_10 = 1;
    self->unk_ea_14 = 1;
}

void func_ov009_02205ff0(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        self->unk_64 >>= 1;
    }
    func_ov003_021d6054(self);
}

void func_ov009_02206014(Ov009Actor *self) {
    func_ov003_021d0fc0(self);
    func_02049564(data_02097e4c, 1, 1);
    func_ov000_02187a20(data_ov000_021ccd54, 0xd);
    self->unk_b8 = self->pos;
    self->unk_ea_10 = 1;
    FLD(u16, self, 0xf0) = 0;
    FLD(u16, self, 0xf2) = 0;
    FLD(u16, self, 0xf4) = 0;
}

}
