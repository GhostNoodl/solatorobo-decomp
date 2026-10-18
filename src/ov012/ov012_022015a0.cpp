#include "ov012/ov012.h"

extern "C" {
void func_ov012_022015a0(Ov012Actor *self) {
    Ov012Sub48 *m;
    void *o;
    self->unk_48->unk_30 = 0x40000000;
    FLD(u16, self->unk_48, 0x9a) |= 0x12;
    func_ov003_021daa6c(FLD(void *, self, 0x108), 0);
    self->unk_40->timer = 0;
    func_ov003_021d5900(self);
    if (!(FLD(u32, self, 0x100) & 0x100000)) {
        return;
    }
    if (self->unk_40->state != 1) {
        return;
    }
    m = self->unk_48;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    if (FLD(u32, self, 0x100) & 0x100000) {
        FLD(u32, self, 0x100) ^= 0x100000;
    }
    self->unk_9c = 0x266;
    self->unk_a0 = 0x333;
    o = Ov012_FindRes(0x5000, 0x5c02);
    if (o == NULL) {
        return;
    }
    if (*FLD(u16 *, o, 0x50) != 0) {
        return;
    }
    func_ov000_02198360(self->unk_40, 4, 0);
    self->unk_40->state = 10;
}
}

extern "C" {
void func_ov012_022016a4(Ov012Actor *self) {
    func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
    self->v08();
}
}

extern "C" {
extern char data_ov012_0220ab1b[];
BOOL func_ov012_022016d8(Ov012Actor *self, s32 spd) {
    Ov012Vec v;
    switch (FLD(u8, self, 0x107)) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220ab1b, 0x111, 0);
        self->unk_9c = self->unk_b0->unk_00 * 2;
        self->unk_a0 = 0x266;
        self->unk_a4 = 0;
        self->unk_a8 = 0x52;
        FLD(u8, self, 0x107)++;
    case 1:
        v.x = self->unk_b8.x;
        v.y = self->unk_b8.y;
        v.z = self->unk_b8.z;
        func_ov000_0218d918(self, &v, 0x333);
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
            FLD(u8, self, 0x107)++;
        }
        break;
    case 2:
        if (FLD(s16, self->unk_38, 0xc4) == 2) {
            func_ov000_02191418(self->unk_38, 0x1e, 0);
        }
        v.x = self->unk_b8.x;
        v.y = self->unk_b8.y;
        v.z = self->unk_b8.z;
        func_ov000_0218ddd4(self, &v, 0);
        self->unk_48->unk_9a_5 = 1;
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (self->unk_48->unk_50 & 0x20000000) {
            func_ov000_0218996c(3, 5);
            func_02065f88(0x12f, &self->pos)->v0c(0x800);
            func_02049f44(data_02097e4c, 0x2a, &self->pos, 0);
            func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4[0], 0x111, 0);
            self->unk_9c = spd;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            FLD(u8, self, 0x107)++;
        }
        break;
    case 3:
        self->unk_48->unk_9a_5 = 0;
        v.x = self->unk_b8.x;
        v.y = self->unk_b8.y;
        v.z = self->unk_b8.z;
        v.y = self->pos.y;
        self->unk_b8 = v;
        return TRUE;
    }
    return FALSE;
}
}
