#include "ov000/LoCommon.h"

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} NodeBits;

extern "C" {
void func_ov000_021c4460(void *self);
void func_ov000_021c4b00(void *self);
void func_ov000_0215f330(void *p);
void func_ov000_021c4c10(void *self);

void func_ov000_021c56c0(u8 *self) {
    s32 i;
    u8 *n;

    if (LFLD(s32, self, 0x4) == 2) {
        if (LBIT(self, 0xc).b1) {
            LFLD(s32, self, 0x4) = 1;
        }
        func_ov000_021c4460(self);
        func_ov000_021c4b00(self);
        LFLD(s8, self, 0xd4)++;
        if (LFLD(s8, self, 0xd4) < 20) {
            LFLD(s32, self, 0xd8) += LO_FX_MUL(0x6000 - LFLD(s32, self, 0xd8), 0x19a);
        } else if (LFLD(s8, self, 0xd4) >= 50) {
            LFLD(s8, self, 0xd4) = 0;
            LFLD(s32, self, 0xd8) = 0;
        } else {
            LFLD(s32, self, 0xd8) += LO_FX_MUL(0 - LFLD(s32, self, 0xd8), 0xcd);
        }
        func_ov000_0215f330(LFLD(void *, self, 0xf4));
        func_ov000_0215f330(LFLD(void *, self, 0xf8));
        func_ov000_0215f330(LFLD(void *, self, 0xfc));
    }
    i = 0;
    for (n = LFLD(u8 *, self, 0x94); n != NULL; n = LFLD(u8 *, n, 0x28)) {
        BOOL on = FALSE;
        switch (LFLD(u8, self, 0xdf)) {
        case 0:
            on = i >= LFLD(s32, self, 0x9c) && i <= LFLD(s32, self, 0x9c) + (LFLD(s32, self, 0x20) - 1);
            break;
        case 1:
            on = i >= LFLD(s32, self, 0x9c) && i <= LFLD(s32, self, 0x9c) + LFLD(s32, self, 0x20);
            break;
        case 2:
            on = i >= LFLD(s32, self, 0x9c) - 1 && i <= LFLD(s32, self, 0x9c) + LFLD(s32, self, 0x20) - 1;
            break;
        }
        if (on) LFLD(NodeBits, n, 0x20).b0 = 1; else LFLD(NodeBits, n, 0x20).b0 = 0;
        LFLD(NodeBits, n, 0x20).b1 = 0;
        ((VObj *)n)->vfunc_08();
        i++;
    }
    if (LFLD(u8 *, self, 0xa0) != NULL) {
        LFLD(NodeBits, LFLD(u8 *, self, 0xa0), 0x20).b1 = 1;
    }
    func_ov000_021c4c10(self);
}
}
