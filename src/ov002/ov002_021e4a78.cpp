#include "ov002/ov002.h"

extern "C" {

void *func_0203dddc(u32 size);

void func_ov002_021e4a78(void *self, u8 *src) {
    u8 *p;
    u16 i;
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
    FIELD(self, 0x4, u8 *) = src;
    MI_CpuCopy8(src, (u8 *)self + 0x8, 4);
    p = src + 4;
    FIELD(self, 0xc, void *) = func_0203dddc(FIELD(self, 0x8, u32) * 12);
    for (i = 0; i < FIELD(self, 0x8, u32); i++) {
        s32 len;
        u8 *s;
        MI_CpuCopy8(p, &len, 4);
        s = p + 4;
        FIELD(FIELD(self, 0xc, u8 *) + i * 12, 0x0, u16) = i;
        FIELD(FIELD(self, 0xc, u8 *) + i * 12, 0x4, u8 *) = s;
        s = s + (STD_GetStringLength(s) + 1);
        FIELD(FIELD(self, 0xc, u8 *) + i * 12, 0x8, u8 *) = s;
        STD_GetStringLength(s);
        p += len;
    }
}

}
