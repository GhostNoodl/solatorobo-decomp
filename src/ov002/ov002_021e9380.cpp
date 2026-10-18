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

void *func_ov002_021e9380(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    void *p = func_0203dd9c(0x70);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0734;
        func_ov002_021e4cd8_inline2(p);
        *(VFunc **)p = data_ov002_021f070c;
        FIELD(p, 0x4c, s32) = -1;
        MIi_CpuClear32(0, (u8 *)p + 0x50, 0x10);
        FIELD(p, 0x68, s32) = -1;
        FIELD(p, 0x6c, s32) = -1;
    }
    FIELD(p, 0x18, s32) = a;
    FIELD(p, 0x1c, s32) = b;
    FIELD(p, 0x8, s32) = c;
    FIELD(p, 0x4c, s32) = d;
    FIELD(p, 0x64, s32) = e;
    FIELD(p, 0x68, s32) = e == 1 ? f : -1;
    return p;
}

extern VFunc data_ov002_021f0784[];

void *func_ov002_021e9478(s32 a, s32 b, s32 c, s32 d, u16 e, s32 mode, u8 f, u8 g) {
    void *p = func_0203dd9c(0x60);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0734;
        func_ov002_021e4cd8_inline2(p);
        *(VFunc **)p = data_ov002_021f0784;
        FIELD(p, 0x4, s32) = 6;
        FIELD(p, 0x20, s32) = -0x19a;
        FIELD(p, 0x4c, s32) = 0;
        FIELD(p, 0x50, u16) = 0;
        FIELD(p, 0x54, s32) = 0;
        FIELD(p, 0x58, s32) = 0;
        FIELD(p, 0x5c, s32) = 0;
    }
    FIELD(p, 0x18, s32) = a;
    FIELD(p, 0x1c, s32) = b;
    FIELD(p, 0x8, s32) = d;
    switch (mode) {
    case 0:
        FIELD(p, 0x4c, s32) = 0;
        break;
    case 1:
        FIELD(p, 0x4c, s32) = 1;
        break;
    case 2:
        FIELD(p, 0x4c, s32) = 2;
        FIELD(p, 0x54, u32) = f > 0x1f ? 0x1f : f;
        FIELD(p, 0x58, u32) = g > 0x1f ? 0x1f : g;
        break;
    }
    FIELD(p, 0x5c, s32) = c;
    FIELD(p, 0x50, u16) = e;
    return p;
}

void *func_02043548(void *p);

void func_02012104(void *p);

extern VFunc data_ov002_021f0854[];

extern VFunc data_ov002_021f0828[];

extern const Vec3 data_ov002_021ef0e0;

extern const Vec3 data_ov002_021ef0ec;

extern const Vec3 data_ov002_021ef0c8;

void *func_ov002_021e95c4(u8 *a, u8 *b) {
    s32 i;
    u8 *p = (u8 *)func_0203dd9c(0xcc);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0734;
        func_ov002_021e4cd8_inline2(p);
        *(VFunc **)p = data_ov002_021f0854;
        func_02043548(p + 0x50);
        FIELD(p, 0x4, s32) = 7;
        FIELD(p, 0x4c, s32) = -1;
        func_02012104(p + 0x74);
        *(VFunc **)p = data_ov002_021f0828;
        FIELD(p, 0x4, s32) = 7;
        {
            Vec3 v = data_ov002_021ef0e0;
            FIELD(p, 0x50, Vec3) = v;
        }
        {
            Vec3 v = data_ov002_021ef0ec;
            FIELD(p, 0x68, Vec3) = v;
        }
        {
            Vec3 v = data_ov002_021ef0c8;
            FIELD(p, 0x5c, Vec3) = v;
        }
        FIELD(p, 0xb8, u16) = 0xaaa;
        FIELD(p, 0xb4, s32) = 0xeff1;
        FIELD(p, 0xba, s16) = FX_SINCOS(0xaa);
        FIELD(p, 0xbc, s16) = FX_SINCOS(0xab);
        FIELD(p, 0xbe, u16) = 0x1555;
        FIELD(p, 0xc0, s32) = 0x2000;
        FIELD(p, 0xc4, s32) = 0x7d0000;
        FIELD(p, 0xc8, s32) = 0;
    }
    if (a != NULL) {
        FIELD(p, 0x48, void *) = a;
        for (i = 0; i < 8; i++) {
            if (((void **)(a + 0x28))[i] == NULL) {
                ((void **)(a + 0x28))[i] = p;
                break;
            }
        }
    }
    if (b != NULL) {
        for (i = 0; i < 8; i++) {
            if (((void **)(p + 0x28))[i] == NULL) {
                ((void **)(p + 0x28))[i] = b;
                break;
            }
        }
        FIELD(b, 0x48, void *) = p;
    }
    FIELD(p, 0x18, s32) = 0;
    FIELD(p, 0x1c, s32) = 0x7ffffffe;
    FIELD(p, 0x8, s32) = 1;
    return p;
}

void func_020128a4(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, void *out);

extern VFunc data_ov002_021f07fc[];

void *func_ov002_021e97e8(u8 *a, u8 *b) {
    s32 i;
    u8 *p = (u8 *)func_0203dd9c(0xb8);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021f0734;
        func_ov002_021e4cd8_inline2(p);
        *(VFunc **)p = data_ov002_021f0854;
        func_02043548(p + 0x50);
        FIELD(p, 0x4, s32) = 7;
        FIELD(p, 0x4c, s32) = -1;
        func_02012104(p + 0x74);
        *(VFunc **)p = data_ov002_021f07fc;
        FIELD(p, 0x4, s32) = 8;
        func_020128a4(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x20000, 0x400000, p + 0x74);
        FIELD(p, 0xb4, s32) = 0;
    }
    if (a != NULL) {
        FIELD(p, 0x48, void *) = a;
        for (i = 0; i < 8; i++) {
            if (((void **)(a + 0x28))[i] == NULL) {
                ((void **)(a + 0x28))[i] = p;
                break;
            }
        }
    }
    if (b != NULL) {
        for (i = 0; i < 8; i++) {
            if (((void **)(p + 0x28))[i] == NULL) {
                ((void **)(p + 0x28))[i] = b;
                break;
            }
        }
        FIELD(b, 0x48, void *) = p;
    }
    FIELD(p, 0x18, s32) = 0;
    FIELD(p, 0x1c, s32) = 0x7ffffffe;
    FIELD(p, 0x8, s32) = 1;
    return p;
}

}
