#include "ov002/ov002.h"

extern "C" {

void func_ov002_021ec0cc(void *self) {
    u8 *p;
    if (FIELD(self, 0x8, s16) >= FIELD(self, 0xa, s16)) {
        return;
    }
    p = FIELD(self, 0xc, u8 *) + (FIELD(self, 0x18, s16) + FIELD(self, 0x1a, s16));
    FIELD(self, 0xc, u8 *) = p;
    MI_CpuCopy8(p, (u8 *)self + 0x10, 0xe);
    p += FIELD(self, 0x18, s16);
    FIELD(self, 0x20, u8 *) = p;
    FIELD(self, 0x24, u8 *) = p + (STD_GetStringLength(p) + 1);
    FIELD(self, 0x8, s16)++;
}

void *func_ov002_021ec13c(void *self) {
    *(VFunc **)self = data_ov002_021f0cf8;
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, u16) = 0;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, u16) = 0;
    FIELD(self, 0x14, s32) = 0;
    return self;
}

void *func_ov002_021ec164(void *self) {
    *(VFunc **)self = data_ov002_021f0cf8;
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, u16) = 0;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, u16) = 0;
    FIELD(self, 0x14, s32) = 0;
    return self;
}

void *func_ov002_021ec18c(void *self) {
    *(VFunc **)self = data_ov002_021f0cf8;
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, u16) = 0;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, u16) = 0;
    FIELD(self, 0x14, s32) = 0;
    func_0203de1c(self);
    return self;
}

void func_ov002_021ec1c4(void *self) {
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, u16) = 0;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, u16) = 0;
    FIELD(self, 0x14, s32) = 0;
}

void func_ov002_021ec1e0(void *self, void *src) {
    s16 n;
    s16 rec[8];
    u8 *p = *(u8 **)src;
    u8 *q;
    int i = 0;
    FIELD(self, 0x4, void *) = src;
    FIELD(self, 0x8, s16) = 0;
    FIELD(self, 0xc, u32) = 0;
    FIELD(self, 0x10, s16) = 0;
    FIELD(self, 0x14, u8 *) = NULL;
    MI_CpuCopy8(p, &n, 2);
    FIELD(self, 0x10, s16) = n;
    if (FIELD(self, 0x10, s16) == 0) {
        return;
    }
    for (q = p + 2; i < FIELD(self, 0x10, s16); i++, q += 0x10) {
        MI_CpuCopy8(q, rec, 0x10);
        if (rec[1] == 6 || rec[1] == 8) {
            FIELD(self, 0xc, u32) |= 1 << (rec[2] / 256);
        }
    }
    FIELD(self, 0x14, u8 *) = p + 2;
    FIELD(self, 0x8, s16) = 1;
}

void func_ov002_021ec2ac(void *self) {
    if (FIELD(self, 0x8, s16) >= FIELD(self, 0x10, s16)) {
        FIELD(self, 0x14, s32) = 0;
    } else {
        FIELD(self, 0x14, s32) += 0x10;
        FIELD(self, 0x8, s16)++;
    }
}

}
