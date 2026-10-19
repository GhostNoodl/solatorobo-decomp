#include "ov000/LoCommon.h"

extern "C" {

extern u8 *data_0214a424;
extern void *data_02097e4c;
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

BOOL func_ov000_02177f40(void *self, void *msg) {
    u16 id;
    void *o;
    if (msg == NULL) {
        return FALSE;
    }
    id = LFLD(u16, msg, 6);
    o = LFLD(void *, self, 8);
    if (((u32)(id << 4) >> 16) - 1 == 1) {
        s32 c;
        u32 v;
        v = LFLD(u8, data_0214a424 + (u16)(id & 0xfff), 0x2a);
        c = LFLD(s32, msg, 0xc);
        {
            u16 *p = &LFLD(u16, LFLD(void *, o, 0x54), 0x8a);
            *p = v > 1 ? v : 1;
        }
        LFLD(s32, LFLD(void *, o, 0x54), 0x8c) = c;
        LBIT(LFLD(void *, o, 0x54), 0xc).b2 = 0;
        LBIT(LFLD(void *, o, 0x54), 0xc).b1 = 0;
        LFLD(u16, LFLD(void *, o, 0x54), 0x88) = 1;
        LBIT(LFLD(void *, o, 0x3c), 0xc).b2 = 1;
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
    }
    return TRUE;
}

}
