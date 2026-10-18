#include "ov002/ov002.h"

extern "C" {

typedef struct Ent021e5140 {
    s32 kind;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    u8 e;
    u8 f;
    s32 g;
} Ent021e5140;

typedef struct Self021e5140 {
    u8 pad[0xc0];
    Ent021e5140 ents[8];
} Self021e5140;

static inline void setv021e5140(void *self, s32 v) {
    FIELD(self, 0x4c, s32) = v >> 12;
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x20, s32) = v;
}

void func_ov002_021e5140(void *self) {
    s32 i;
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x20, s32) = -0xa66;
    FIELD(self, 0x4c, s32) = FIELD(self, 0x20, s32) >> 12;
    FIELD(self, 0x50, s32) = 0;
    FIELD(self, 0x54, s32) = 0;
    FIELD(self, 0x58, s32) = 0;
    FIELD(self, 0x5c, s32) = 0;
    FIELD(self, 0x60, s32) = 0;
    FIELD(self, 0x64, s32) = 0;
    FIELD(self, 0xbc, s32) = 0;
    for (i = 0; i < 8; i++) {
        u8 *e = (u8 *)self + i * 0x1c;
        FIELD(e, 0xc0, s32) = 0;
        FIELD(e, 0xc4, s32) = 0;
        FIELD(e, 0xc8, s32) = 0;
        FIELD(e, 0xcc, s32) = 0;
        FIELD(e, 0xd0, s32) = 0;
        FIELD(e, 0xd4, u8) = 0;
        FIELD(e, 0xd5, u8) = 0;
        FIELD(e, 0xd8, s32) = 0;
    }
    FIELD(self, 0x1a0, s32) = 0;
    FIELD(self, 0x1a4, s32) = 0;
    FIELD(self, 0x1a8, s32) = 0;
    FIELD(self, 0x1ac, s32) = 0;
    FIELD(self, 0x1b0, s32) = 0x1000;
    FIELD(self, 0x1b4, s32) = 0x1000;
    FIELD(self, 0x1b8, s32) = 0x1000;
    MTX_Identity33_((u8 *)self + 0x1bc);
    FIELD(self, 0x1e0, s32) = 0;
    FIELD(self, 0x1e4, s32) = 0;
    FIELD(self, 0x1e8, s32) = 0;
    FIELD(self, 0x1ec, s32) = 0;
    FIELD(self, 0x1f0, u8) = 0;
}

void func_ov002_021e51f8(void *self) {
    s32 i;
    if (FIELD(self, 0x10, s32) >= 0x28) {
        if (FIELD(self, 0x5c, void **) != NULL) {
            func_0203f0b4(*FIELD(self, 0x5c, void **));
        }
        for (i = 0; i < FIELD(self, 0x1a0, s32); i++) {
            u8 *e = (u8 *)self + 0xc0 + i * 0x1c;
            if (FIELD(e, 0x10, void **) != NULL) {
                func_0203f0b4(*FIELD(e, 0x10, void **));
            } else if (FIELD(e, 0x15, u8)) {
                func_0203f0b4(*FIELD(e, 0x18, void **));
            }
        }
    }
    if (FIELD(self, 0x14, void *) != NULL) {
        if (FIELD(self, 0x50, void *) != NULL) {
            func_02035acc(FIELD(self, 0x50, void *), FIELD(self, 0x54, void *), 4);
        } else {
            func_02036838(data_02097cdc, FIELD(self, 0x54, void *), 4, 0);
        }
    }
    for (i = 0; i < FIELD(self, 0x1a0, s32); i++) {
        u8 *e = (u8 *)self + 0xc0 + i * 0x1c;
        if (FIELD(e, 0x14, u8)) {
            if (FIELD(e, 0x4, void *) != NULL) {
                if (FIELD(e, 0x15, u8)) {
                    func_02035acc(FIELD(e, 0x4, void *), FIELD(e, 0x8, void *), 4);
                } else {
                    func_02035acc(FIELD(e, 0x4, void *), FIELD(e, 0x8, void *), 5);
                }
            } else {
                func_02036838(data_02097cdc, FIELD(e, 0x8, void *), 5, 0);
            }
        }
    }
}

}
