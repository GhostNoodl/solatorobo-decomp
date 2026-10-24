#include "ov000/LoCommon.h"

extern "C" {
void func_ov000_02181f54(u8 *self, u16 id, u16 a, u16 b, u16 c, u16 d);
void func_ov000_02182190(u8 *self, u16 id, u16 a, u16 b, u16 c, u16 d, u16 e);

static inline void Get2(u8 *buf, s32 i, u8 *dst) {
    u8 *s = &buf[i];
    dst[0] = s[0];
    dst[1] = s[1];
}

static inline void Get2r(u8 *buf, s32 i, u8 *dst) {
    u8 *s = &buf[i];
    dst[1] = s[1];
    dst[0] = s[0];
}

static inline void Get2b(const u8 *s, u8 *dst) {
    dst[0] = s[0];
    dst[1] = s[1];
}
static inline void Get2v(const u8 *s, u8 *dst) {
    u8 a = s[0];
    u8 b = s[1];
    dst[1] = b;
    dst[0] = a;
}

s32 func_ov000_02181c4c(u8 *self, u8 *buf) {
    u16 id;
    u16 sub;
    u16 d;
    u16 c;
    s32 off = 0;
    u32 zero;
    u8 n = buf[1];
    zero = 0;
    if (buf[0] != zero) {
        u16 a_0;
        u16 b_0;
        Get2b(buf + 2, (u8 *)&id);
        a_0 = buf[4];
        b_0 = buf[5];
        Get2v(buf + 6, (u8 *)&c);
        off += 10;
        Get2v(buf + 8, (u8 *)&d);
        func_ov000_02181f54(self, id, a_0, b_0, c, d);
    } else {
        off += 10;
    }
    if (n > zero) {
        u16 a_1;
        u16 b_1;
        Get2(buf, off, (u8 *)&id);
        Get2(buf, off + 2, (u8 *)&sub);
        a_1 = (buf + off)[4];
        b_1 = (buf + off)[5];
        Get2(buf, off + 6, (u8 *)&c);
        Get2(buf, off + 8, (u8 *)&d);
        off += 10;
        func_ov000_02182190(self, id, sub, a_1, b_1, c, d);
    } else {
        off += 10;
    }
    return (off + 1) & ~1;
}
}
