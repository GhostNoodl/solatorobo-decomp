#include "ov002/ov002.h"

extern "C" {

void *func_ov002_021e2f04(void *self, void *unused, u8 *entries, u16 *count) {
    u16 n = *count;
    int i;
    for (i = 0; i < n; i++) {
        Bits021e2f04 *e = (Bits021e2f04 *)(entries + i * 8 + 4);
        e->nib = FIELD(self, 0x70, s32) + e->nib;
    }
    *count = n;
    return entries;
}

void func_ov002_021e2f54(void *self) {
    FIELD(self, 0x18, s32) = 0xf;
    FIELD(self, 0x1c, s32) = 0x78;
    FIELD(self, 0x30, s32) = 0;
    FIELD(self, 0x34, s32) = 0;
    FIELD(self, 0x38, u16) = 0xffff;
    FIELD(self, 0x3a, u16) = 0;
    FIELD(self, 0x3c, char *) = data_ov002_021effde;
    FIELD(self, 0x40, char *) = data_ov002_021effeb;
    FIELD(self, 0x44, u8) = 1;
    FIELD(self, 0x45, u8) = 0;
    FIELD(self, 0x48, s32) = 2;
}

}
