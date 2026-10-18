#include "ov002/ov002.h"

extern "C" {

extern VFunc data_0208ba70[];

void func_0204c7d0(void *p);

s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);

void func_ov002_021e331c(void *self) {
    u8 *p;
    {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(FIELD(self, 0x34, VObject *));
        HEAP_POP(saved);
    }
    p = (u8 *)func_0203dd9c(0xb8);
    if (p != NULL) {
        *(VFunc **)p = data_0208ba70;
        func_0204c7d0(p);
    }
    FIELD(self, 0x34, u8 *) = p;
    FIELD(p, 0x28, s32) = 8;
    p = FIELD(self, 0x34, u8 *);
    FIELD(p, 0x24, s32) = FIELD(self, 0x3c, s32);
    FIELD(p, 0x4c, s32) = func_0204c4fc(FIELD(p, 0x28, s32), FIELD(p, 0x38, s32), FIELD(p, 0x24, s32), p + 0x44, p + 0x48, FIELD(p, 0x37, s8) != 0);
    FIELD(data_02097ce0, 0x4, s32) = FIELD(p, 0x28, s32);
    FIELD(FIELD(self, 0x34, void *), 0x4, u32) = (FIELD(FIELD(self, 0x34, void *), 0x4, u32) & ~0x1f00) | 0x1e00;
    FIELD(FIELD(self, 0x34, void *), 0x4, u32) |= 0x40;
    FIELD(self, 0x34, VObject *)->v0x14();
    FIELD(FIELD(self, 0x34, void *), 0x4, u32) |= 0x1000000;
    FIELD(FIELD(self, 0x34, void *), 0x4, u32) |= 0x400000;
    FIELD(FIELD(self, 0x34, void *), 0x4, u32) |= 0x200000;
    FIELD(FIELD(self, 0x34, void *), 0x2c, s32) = FIELD(self, 0x44, u8) ? 0 : 0xe;
    FIELD(FIELD(self, 0x34, void *), 0x4, u32) |= 0x4;
}

}
