#include "ov002/ov002.h"

extern "C" {

static inline void func_ov002_021e4cd8_inline2(void *self) {
    u8 *ctx;
    FIELD(self, 0x4, s32) = -1;
    FIELD(self, 0x8, s32) = 1;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x14, s32) = 0;
    FIELD(self, 0x18, s32) = 0;
    FIELD(self, 0x1c, s32) = 0;
    FIELD(self, 0x20, s32) = -0x29;
    FIELD(self, 0x24, s32) = 0;
    MIi_CpuClear32(0, (u8 *)self + 0x28, 0x20);
    FIELD(self, 0x48, s32) = 0;
    ctx = (u8 *)data_ov002_021f0f98[1];
    if (FIELD(ctx, 0xe0, void *) == NULL) {
        FIELD(ctx, 0xdc, void *) = self;
    } else {
        FIELD(FIELD(ctx, 0xe0, void *), 0x24, void *) = self;
    }
    FIELD(ctx, 0xe0, void *) = self;
}

extern VFunc data_ov002_021f06bc[];

void func_ov002_021ec13c(void *p);

void func_ov002_021ec1c4(void *p);

void *func_ov002_021e9bd8(void *a, void *b) {
    void *p = func_0203dd9c(0xac);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0734;
        func_ov002_021e4cd8_inline2(p);
        *(VFunc **)p = data_ov002_021f06bc;
        func_ov002_021ec13c((u8 *)p + 0x94);
        FIELD(p, 0x4, s32) = 4;
        func_02016e28((u8 *)p + 0x4c, 0, 0x20);
        func_02016e28((u8 *)p + 0x6c, 0, 0x20);
        FIELD(p, 0x8c, s32) = 0;
        FIELD(p, 0x90, s32) = 0;
        func_ov002_021ec1c4((u8 *)p + 0x94);
    }
    func_0201e5a0((u8 *)p + 0x4c, a, 0x20);
    func_0201e5a0((u8 *)p + 0x6c, b, 0x20);
    return p;
}

}
