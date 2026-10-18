#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e4b80(void *self) {
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, s32) = 0;
    {
        u32 saved;
        HEAP_PUSH(saved);
        if (FIELD(self, 0xc, void *) != NULL) {
            func_0203de50(FIELD(self, 0xc, void *));
            FIELD(self, 0xc, void *) = NULL;
        }
        HEAP_POP(saved);
    }
}

s32 func_ov002_021e4bd0(void *self, u32 idx) {
    if (idx >= FIELD(self, 0x8, u32) || FIELD(self, 0xc, u8 *) == NULL) {
        return 0;
    }
    return FIELD(FIELD(self, 0xc, u8 *) + idx * 0xc, 0x4, s32);
}

s32 func_ov002_021e4c00(void *self, u32 idx) {
    if (idx >= FIELD(self, 0x8, u32) || FIELD(self, 0xc, u8 *) == NULL) {
        return 0;
    }
    return FIELD(FIELD(self, 0xc, u8 *) + idx * 0xc, 0x8, s32);
}

u32 func_ov002_021e4c30(int which) {
    u32 r = 0;
    switch (which) {
    case 0:
        r = data_02097dd0[5] / 3600;
        break;
    case 1:
        r = FIELD(data_0214a424, 0xa, u16);
        break;
    case 2:
        r = FIELD(data_0214a424, 0xc, u32);
        break;
    case 3:
        r = FIELD(data_0214a424, 0x61c, u16);
        break;
    case 4:
        r = FIELD(data_0214a424, 0x10, u32);
        break;
    case 5:
        r = FIELD(data_0214a424, 0x14, u16);
        break;
    case 6:
        r = FIELD(data_0214a424, 0x16, u16);
        break;
    }
    return r;
}

void func_ov002_021e4cd8(void *self) {
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
    func_02016cd8(0, (u8 *)self + 0x28, 0x20);
    FIELD(self, 0x48, s32) = 0;
    ctx = (u8 *)data_ov002_021f0f98[1];
    if (FIELD(ctx, 0xe0, void *) == NULL) {
        FIELD(ctx, 0xdc, void *) = self;
    } else {
        FIELD(FIELD(ctx, 0xe0, void *), 0x24, void *) = self;
    }
    FIELD(ctx, 0xe0, void *) = self;
}

void func_ov002_021e4d4c(void *self) {
    int i;
    u8 *owner = FIELD(self, 0x48, u8 *);
    if (owner != NULL) {
        for (i = 0; i < 8; i++) {
            if (((void **)(owner + 0x28))[i] == self) {
                ((void **)(owner + 0x28))[i] = NULL;
                break;
            }
        }
        FIELD(self, 0x48, void *) = NULL;
    }
    for (i = 0; i < 8; i++) {
        void *child = ((void **)((u8 *)self + 0x28))[i];
        if (child != NULL) {
            FIELD(child, 0x48, void *) = NULL;
        }
    }
}

void func_ov002_021e4dac(void *self, void *item) {
    int i;
    for (i = 0; i < 8; i++) {
        if (((void **)((u8 *)self + 0x28))[i] == NULL) {
            ((void **)((u8 *)self + 0x28))[i] = item;
            return;
        }
    }
}

}
