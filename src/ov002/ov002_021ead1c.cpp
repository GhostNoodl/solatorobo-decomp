#include "ov002/ov002.h"

extern "C" {

void *Heap_AllocArray(u32 size);

void func_ov002_021eb964(void *self);

void func_ov002_021ead1c(void *self, u8 *a, s32 b, u8 c) {
    s32 hdr;
    s32 n0;
    s32 n1;
    s32 n2;
    s32 n3;
    func_ov002_021eae48(self);
    FIELD(self, 0x4, s32) = b;
    FIELD(self, 0x8, u8 *) = a;
    FIELD(self, 0xc, u8) = c;
    MI_CpuCopy8(a + 8, &hdr, 4);
    func_ov002_021eb964(self);
    MI_CpuCopy8(FIELD(self, 0x18, u8 *) + 8, &n0, 4);
    MI_CpuCopy8(FIELD(self, 0x1c, u8 *) + 8, &n1, 4);
    MI_CpuCopy8(FIELD(self, 0x20, u8 *) + 8, &n2, 4);
    MI_CpuCopy8(FIELD(self, 0x24, u8 *) + 8, &n3, 4);
    if (n0 > 0) {
        FIELD(self, 0x40, void *) = Heap_AllocArray(n0 * 0x1c);
        FIELD(self, 0x50, s32) = n0;
    }
    if (n1 > 0) {
        FIELD(self, 0x44, void *) = Heap_AllocArray(n1 * 4);
        FIELD(self, 0x54, s32) = n1;
    }
    if (n2 > 0) {
        FIELD(self, 0x48, void *) = Heap_AllocArray(n2 * 4);
        FIELD(self, 0x58, s32) = n2;
    }
    if (n3 > 0) {
        FIELD(self, 0x4c, void *) = Heap_AllocArray(n3 * 4);
        FIELD(self, 0x5c, s32) = n3;
    }
}

}
