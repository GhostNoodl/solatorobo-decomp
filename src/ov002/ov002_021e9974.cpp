#include "ov002/ov002.h"

extern "C" {

static inline void func_ov002_021e4cd8_inline4(void *self) {
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
void *func_ov002_021e9974(s32 a, s32 b, s16 c, void *d) {
    void *p = func_0203dd9c(0x54);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0734;
        func_ov002_021e4cd8_inline4(p);
        *(VFunc **)p = data_ov002_021f06e4;
        FIELD(p, 4, s32) = 10;
        FIELD(p, 0x4c, s16) = 0;
        FIELD(p, 0x50, void *) = NULL;
    }
    FIELD(p, 0x18, s32) = a;
    FIELD(p, 0x1c, s32) = b;
    FIELD(p, 0x8, s32) = 2;
    FIELD(p, 0x4c, s16) = c;
    FIELD(p, 0x50, void *) = d;
    return p;
}

static inline void func_ov002_021e4cd8_inline3(void *self) {
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
void *func_ov002_021e9a50(void *a, void *b) {
    void *p = func_0203dd9c(0x160);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0734;
        func_ov002_021e4cd8_inline3(p);
        *(VFunc **)p = data_ov002_021f07ac;
        func_ov002_021ebedc((u8 *)p + 0x8c);
        func_ov002_021e6a14(p);
    }
    STD_CopyLString((u8 *)p + 0x4c, a, 0x20);
    STD_CopyLString((u8 *)p + 0x6c, b, 0x20);
    return p;
}

static inline void func_ov002_021e4cd8_inline(void *self) {
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
void *func_ov002_021e9b28(void *arg) {
    void *p = func_0203dd9c(0x4c);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0734;
        func_ov002_021e4cd8_inline(p);
        *(VFunc **)p = data_ov002_021f0694;
        FIELD(p, 4, s32) = 9;
    }
    FIELD(p, 0x1c, void *) = arg;
    return p;
}

}
