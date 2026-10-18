#include "ov002/ov002.h"

extern "C" {

void *func_0203dddc(u32 size);

void func_ov002_021e4814(void *self, u8 *src) {
    u8 *p;
    func_ov002_021e4904_inline(self);
    FIELD(self, 0x4, u8 *) = src;
    MI_CpuCopy8(src, (u8 *)self + 0x8, 4);
    p = src + 4;
    {
        u32 saved;
        HEAP_PUSH(saved);
        if (FIELD(self, 0xc, void *) != NULL) {
            func_0203de50(FIELD(self, 0xc, void *));
            FIELD(self, 0xc, void *) = NULL;
        }
        HEAP_POP(saved);
    }
    FIELD(self, 0xc, void *) = func_0203dddc(FIELD(self, 0x8, s32) << 2);
    MI_CpuCopy8(p, FIELD(self, 0xc, void *), FIELD(self, 0x8, s32) << 2);
    p += FIELD(self, 0x8, s32) * 4;
    FIELD(self, 0x10, u8 *) = p;
    FIELD(self, 0x14, u8 *) = p + (STD_GetStringLength(p) + 1);
    STD_GetStringLength(FIELD(self, 0x14, u8 *));
}

}
