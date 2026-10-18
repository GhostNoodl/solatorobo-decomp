#include "ov002/ov002.h"

extern "C" {

typedef struct {
    u16 lo : 8;
    u16 rot : 2;
    u16 hi : 6;
} Rot7c54;

void func_02011488(void *m, s32 s, s32 c);

void func_ov002_021d7c54(void *self, u16 rot) {
    FIELD(self, 0x52, Rot7c54).rot = rot;
    switch (rot) {
    case 0:
        FIELD(self, 0x10, s16) = 0;
        FIELD(self, 0x12, s16) = 0;
        FIELD(self, 0x14, s16) = 0;
        func_02011340((u8 *)self + 0x18);
        break;
    case 1:
        FIELD(self, 0x10, s16) = 0;
        FIELD(self, 0x12, u16) = 0x3fff;
        FIELD(self, 0x14, s16) = 0;
        func_02011340((u8 *)self + 0x18);
        func_02011488((u8 *)self + 0x18, FX_SINCOS(0x3ff * 2), FX_SINCOS(0x3ff * 2 + 1));
        break;
    case 2:
        FIELD(self, 0x10, s16) = 0;
        FIELD(self, 0x12, u16) = 0x7fff;
        FIELD(self, 0x14, s16) = 0;
        func_02011340((u8 *)self + 0x18);
        func_02011488((u8 *)self + 0x18, FX_SINCOS(0x7ff * 2), FX_SINCOS(0x7ff * 2 + 1));
        break;
    case 3:
        FIELD(self, 0x10, s16) = 0;
        FIELD(self, 0x12, u16) = 0xbffd;
        FIELD(self, 0x14, s16) = 0;
        func_02011340((u8 *)self + 0x18);
        func_02011488((u8 *)self + 0x18, FX_SINCOS(0xbff * 2), FX_SINCOS(0xbff * 2 + 1));
        break;
    }
}

void func_ov002_021d7d5c(void *self, void *b) {
    Vec2 out;
    while (func_ov002_021e3dac((Vec2 *)((u8 *)self + 0x54), b, (u8 *)self + 0x4c, &out)) {
        if (out.x < 0) {
            FIELD(self, 0x54, s32) -= out.x;
        } else if (out.x >= FIELD(b, 0x4, Nibbles16).n2) {
            FIELD(self, 0x54, s32) = FIELD(self, 0x54, s32) - (out.x + 1 - FIELD(b, 0x4, Nibbles16).n2);
        } else if (out.y < 0) {
            FIELD(self, 0x58, s32) -= out.y;
        } else if (out.y >= FIELD(b, 0x4, Nibbles16).n3) {
            FIELD(self, 0x58, s32) = FIELD(self, 0x58, s32) - (out.y + 1 - FIELD(b, 0x4, Nibbles16).n3);
        } else if (FIELD(self, 0x54, s32) != out.x) {
            FIELD(self, 0x54, s32) = FIELD(self, 0x54, s32) > out.x ? FIELD(self, 0x54, s32) + 1 : FIELD(self, 0x54, s32) - 1;
        } else {
            FIELD(self, 0x58, s32) = FIELD(self, 0x58, s32) > out.y ? FIELD(self, 0x58, s32) + 1 : FIELD(self, 0x58, s32) - 1;
        }
    }
}

}
