#include "ov002/ov002.h"

extern "C" {

s32 func_0201e950(const void *a, const void *b, u32 n);

void *func_ov002_021e92b0(s32 a, s32 b, s32 c, s32 d, s32 e);

typedef struct Hdr021ebcf8 {
    s32 count;
    s32 stride;
} Hdr021ebcf8;

typedef struct Rec021ebcf8 {
    s32 a;
    s32 b;
    s32 pad8;
    s32 c;
    s16 d;
    s8 e;
    s8 f;
    s32 g;
} Rec021ebcf8;

static inline void ov002_addPair(u8 *list, u8 *a, u8 *b, s32 kind) {
    u8 *n;
    for (n = FIELD(list, 0x4, u8 *); n != NULL; n = FIELD(n, 0x4c, u8 *)) {
        if (func_0201e950(n, a, STD_GetStringLength(n)) == 0 && func_0201e950(n + 0x20, b, STD_GetStringLength(n)) == 0 && FIELD(n, 0x40, s32) == kind) {
            break;
        }
    }
    if (n == NULL) {
        n = (u8 *)func_0203dd9c(0x50);
        MI_CpuFill8(n, 0, 0x20);
        MI_CpuFill8(n + 0x20, 0, 0x20);
        FIELD(n, 0x44, u8) = 0;
        FIELD(n, 0x48, s32) = 0;
        FIELD(n, 0x4c, u8 *) = NULL;
        STD_CopyLString(n, a, 0x20);
        STD_CopyLString(n + 0x20, b, 0x20);
        FIELD(n, 0x40, s32) = kind;
        FIELD(n, 0x4c, u8 *) = FIELD(list, 0x4, u8 *);
        FIELD(list, 0x4, u8 *) = n;
    }
}

void func_ov002_021ebcf8(void *self, int a1, s32 data, s32 out) {
    Hdr021ebcf8 hdr;
    Rec021ebcf8 rec;
    s32 n;
    s32 stride;
    u8 *src;
    s32 i;
    u8 *o;
    u8 *s1;
    u8 *s2;
    u8 *s3;
    MI_CpuCopy8((u8 *)data + 8, &hdr, 8);
    n = hdr.count;
    stride = hdr.stride;
    src = (u8 *)data + 0x10;
    for (i = 0; i < n; i++) {
        MI_CpuCopy8(src, &rec, 0x18);
        o = (u8 *)func_ov002_021e92b0(rec.a, rec.b, 1, rec.e, rec.g);
        FIELD(o, 0x4, s32) = a1;
        FIELD(o, 0x84, s32) = rec.f;
        FIELD(o, 0x58, s32) = rec.c;
        FIELD(o, 0x5c, s32) = rec.d;
        s1 = FIELD(src, 0x18, s8) ? src + 0x18 : NULL;
        s2 = FIELD(src, 0x30, s8) ? src + 0x30 : NULL;
        s3 = FIELD(src, 0x48, s8) ? src + 0x48 : NULL;
        FIELD(o, 0x4c, u8 *) = s1;
        FIELD(o, 0x50, u8 *) = s2;
        FIELD(o, 0x54, u8 *) = s3;
        if (FIELD(self, 0x60, u8 *) != NULL && s1 != NULL && s2 != NULL) {
            ov002_addPair(FIELD(self, 0x60, u8 *), s1, s2, 6);
        }
        ((u8 **)out)[i] = o;
        src += stride;
    }
}

}
