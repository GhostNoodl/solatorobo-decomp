#include "ov002/ov002.h"

extern "C" {

void func_ov002_021ec0cc(void *p);

void func_ov002_021e6e40(void *self);

static inline bool isVisible021e6c0c(void *self) {
    BOOL in = FALSE;
    s32 idx = FIELD(self, 0xb8, s32);
    if (idx >= 0 && idx < FIELD(data_ov002_021f0f98[1], 0xd0, s32)) {
        in = TRUE;
    }
    return in;
}

BOOL func_ov002_021e6c0c(void *self) {
    if (FIELD(self, 0x96, s16) != 0) {
        if (FIELD(data_ov002_021f0f98[1], 0xd4, s32) < FIELD(self, 0x9c, s16) << 12 && FIELD(self, 0x9c, s16) << 12 <= FIELD(data_ov002_021f0f98[1], 0xd0, s32)) {
            BOOL has;
            char *s;
            FIELD(self, 0xb4, s32) = 0;
            FIELD(self, 0xb8, s32) = FIELD(self, 0x9e, s16) << 12;
            FIELD(self, 0xbc, s16) = 0;
            FIELD(self, 0xc0, s32) = FIELD(self, 0xb0, s32);
            FIELD(self, 0x14c, s32) = FIELD(self, 0xac, s32);
            MI_CpuFill8((u8 *)self + 0xc4, 0, 0x80);
            FIELD(self, 0x144, void *) = (u8 *)self + 0xc4;
            has = FALSE;
            s = FIELD(self, 0xac, char *);
            if (s != NULL && s[0] != 0) {
                has = TRUE;
            }
            if (!has) {
                FIELD(self, 0x148, s32) = 0xff;
            } else if (FIELD(self, 0xa8, s8) == 1) {
                FIELD(self, 0x148, s32) = 0;
            } else {
                FIELD(self, 0x148, s32) = 1;
            }
            func_ov002_021ec0cc((u8 *)self + 0x8c);
        }
    }
    if (!isVisible021e6c0c(self)) {
        func_ov002_021e6e40(self);
    }
    if (isVisible021e6c0c(self)) {
        FIELD(self, 0x148, s32) = 0xff;
    }
    FIELD(data_ov002_021f0f98[1], 0x12c, s32) = FIELD(self, 0x148, s32);
    return TRUE;
}

}
