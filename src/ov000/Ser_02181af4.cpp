#include "ov000/LoCommon.h"

extern "C" {
void MI_CpuFill8(void *dst, u8 val, u32 size);

static inline void Put2(u8 *buf, s32 i, u8 *src) {
    u8 *d = &buf[i];
    d[0] = src[0];
    d[1] = src[1];
}

s32 func_ov000_02181af4(u8 *self, u8 *buf, u32 size) {
    s32 off = 0;
    u16 n;
    u8 *p;
    MI_CpuFill8(buf, off, size);
    buf[0] = LFLD(u8 *, self, 0xc) != NULL ? 1 : 0;
    n = 0;
    for (p = LFLD(u8 *, self, 0x10); p != NULL; p = LFLD(u8 *, p, 0xd4)) {
        n++;
    }
    buf[1] = n;
    if (LFLD(u8 *, self, 0xc) == NULL) {
        off += 10;
    } else {
        off += 10;
        buf[2] = LFLD(u8, LFLD(u8 *, self, 0xc), 0xc6);
        buf[3] = LFLD(u8, LFLD(u8 *, self, 0xc), 0xc7);
        buf[4] = LFLD(u16, LFLD(u8 *, self, 0xc), 0xc8);
        buf[5] = LFLD(u16, LFLD(u8 *, self, 0xc), 0xca);
        buf[6] = LFLD(u8, LFLD(u8 *, self, 0xc), 0xcc);
        buf[7] = LFLD(u8, LFLD(u8 *, self, 0xc), 0xcd);
        buf[8] = LFLD(u8, LFLD(u8 *, self, 0xc), 0xce);
        buf[9] = LFLD(u8, LFLD(u8 *, self, 0xc), 0xcf);
    }
    p = LFLD(u8 *, self, 0x10);
    if (p == NULL) {
        off += 10;
    } else {
        Put2(buf, off, p + 0xc6);
        Put2(buf, off + 2, p + 0xc4);
        (buf + off)[4] = LFLD(u16, p, 0xc8);
        (buf + off)[5] = LFLD(u16, p, 0xca);
        Put2(buf, off + 6, p + 0xcc);
        Put2(buf, off + 8, p + 0xce);
        off += 10;
    }
    return (off + 1) & ~1;
}
}
