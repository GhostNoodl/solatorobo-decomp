#include "ov002/ov002.h"

extern "C" {

void func_02049870(void *a, void *b);

s32 func_0204a2c8(void *a, void *b);

void func_02049950(void *a, s32 b, int c);

void func_02049960(void *a, void *b, u16 c);

void func_0204a2a8(void *a, int b, u16 c);

BOOL func_ov002_021ede5c(void *self) {
    BOOL busy = FALSE;
    u8 *d = FIELD(self, 0x20, u8 *);
    switch (FIELD(d, 0xc, u16)) {
    case 0:
        if (FIELD(self, 0x10, s32) == 0) {
            func_02049870(data_02097e4c, FIELD(d, 0x8, void *));
            FIELD(self, 0x10, s32)++;
        }
        if (FIELD(FIELD(self, 0x20, u8 *), 0xe, u16) != 0) {
            s32 t = func_02012ab8(FIELD(self, 0x14, s32), FIELD(FIELD(self, 0x20, u8 *), 0xe, u16) << 12);
            s32 tot;
            s32 cur;
            if (t >= 0x1000) {
                t = 0x1000;
            }
            tot = func_0204a2c8(data_02097e4c, FIELD(FIELD(self, 0x20, u8 *), 0x8, void *));
            cur = FX_MUL(tot << 12, FX_SINCOS_TABLE[((t << 14) >> 16) * 2]) >> 12;
            func_02049950(data_02097e4c, cur, 0);
            if (cur != tot) {
                busy = TRUE;
            }
        }
        break;
    case 1:
        func_02049960(data_02097e4c, FIELD(d, 0x8, void *), FIELD(d, 0xe, u16));
        break;
    case 2:
        func_0204a2a8(data_02097e4c, 100, FIELD(d, 0xe, u16));
        break;
    case 3:
        {
            u8 *g = data_02097e48;
            FIELD(g, 0x80, u16) = 0x8000;
            FIELD(g, 0x7c, u16) = 0;
        }
        break;
    }
    return busy;
}

}
