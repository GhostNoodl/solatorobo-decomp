#include "ov002/ov002.h"

extern "C" {

typedef struct SprAttr021edcec {
    u32 lo : 8;
    u32 prio : 5;
    u32 pal : 8;
    u32 hi : 11;
} SprAttr021edcec;

void func_ov002_021edcec(void *self, int mode) {
    s32 x;
    s32 y;
    if (FIELD(self, 0x34, void *) == NULL || FIELD(self, 0x54, u8) == 0) {
        return;
    }
    x = FIELD(self, 0x38, s32) >> 12;
    y = FIELD(self, 0x3c, s32) >> 12;
    if (mode == 1) {
        y += 0xc0;
    }
    FIELD(FIELD(self, 0x34, void *), 0x4, SprAttr021edcec).pal = func_02043d48(data_02097d48 + 0x8b0);
    FIELD(FIELD(self, 0x34, void *), 0x4, SprAttr021edcec).prio = FIELD(self, 0x54, u8);
    FIELD(self, 0x34, VObject *)->v0x20(x, y);
    FIELD(FIELD(self, 0x34, void *), 0x70, s32) = -0x1000;
    FIELD(self, 0x34, VObject *)->v0x90();
    if (FIELD(self, 0x44, void *) == NULL) {
        return;
    }
    x = FIELD(self, 0x48, s32) >> 12;
    y = FIELD(self, 0x4c, s32) >> 12;
    if (mode == 1) {
        y += 0xc0;
    }
    FIELD(FIELD(self, 0x44, void *), 0x4, SprAttr021edcec).pal = func_02043d48(data_02097d48 + 0x8b0);
    FIELD(FIELD(self, 0x44, void *), 0x4, SprAttr021edcec).prio = FIELD(self, 0x54, u8);
    FIELD(self, 0x44, VObject *)->v0x20(x, y);
    FIELD(FIELD(self, 0x44, void *), 0x70, s32) = -0x1000;
    FIELD(self, 0x44, VObject *)->v0x90();
}

}
