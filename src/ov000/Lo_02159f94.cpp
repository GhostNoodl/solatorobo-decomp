#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"

extern "C" {

void func_ov000_0215eab4(void *p);

void func_ov000_02159f94(Lo021cb5a8 *self, s32 b, s32 c) {
    u8 *n = (u8 *)Heap_Alloc(0x30);
    u8 *t;
    u8 *nx;
    s16 id;
    if (n) {
        LFLD(s32, n, 0) = 0;
        LFLD(s16, n, 4) = 0;
        LFLD(s16, n, 6) = 0;
        LFLD(u16, n, 8) = 0xffff;
        LFLD(u16, n, 0xa) = 0xffff;
        LFLD(s32, n, 0xc) = 0;
        LFLD(s32, n, 0x10) = 0;
        LFLD(s32, n, 0x14) = 0;
        LFLD(s32, n, 0x18) = 0;
        LFLD(s32, n, 0x1c) = 0;
        LFLD(s32, n, 0x20) = 0;
        LFLD(s32, n, 0x24) = 0;
        LFLD(s32, n, 0x28) = 0;
        LFLD(s32, n, 0x2c) = 0;
    }
    LFLD(s32, n, 0) = c;
    id = self->unk_9c;
    self->unk_9c = id + 1;
    LFLD(s16, n, 4) = id;
    LFLD(s16, n, 6) = b;
    t = self->unk_94;
    if (t == NULL) {
        self->unk_94 = n;
        self->unk_98 = n;
        return;
    }
    for (nx = LFLD(u8 *, t, 0x2c); nx != NULL; nx = LFLD(u8 *, nx, 0x2c)) {
        t = nx;
    }
    LFLD(u8 *, t, 0x2c) = n;
    LFLD(u8 *, n, 0x28) = t;
}

}
