#include "ov000/LoCommon.h"

extern "C" {

typedef struct {
    s32 v[3];
} Lo3W;

typedef struct {
    u32 lo : 12;
    u32 pal : 4;
    u32 hi : 16;
} LoGlyphW;

typedef struct {
    u32 unk_00;
    LoGlyphW w;
} LoGlyph;

extern u8 data_02097d78[];
void func_ov000_02161798(void *self, s32 a, s32 b, s32 c);
void func_ov000_02161994(void *self, s32 a, s32 b, s32 c);
void func_ov000_02162bd4(void *self);
BOOL func_ov000_02190a30(void *p, s32 a);
void func_ov000_02190a80(void *p, s32 a);
void func_0203cb78(s32 a, s32 b, s32 c);

static inline BOOL LoIsMode4(void) {
    if (LFLD(s32, data_02097d78, 0xc) == 4) {
        return TRUE;
    }
    return LFLD(s32, data_02097d78, 4) == 4 ? TRUE : FALSE;
}

void func_ov000_021643e8(void *self) {
    LFLD(s32, self, 0x20) = 0;
    LFLD(s32, self, 0x24) = 0;
    LFLD(s32, self, 0x28) = 0;
    LFLD(s32, self, 0x2c) = 0;
    LFLD(s32, self, 0x30) = 0;
    LFLD(s32, self, 0x34) = 4;
    LFLD(s32, self, 0x40) = 0;
    LFLD(s32, self, 0x44) = 4;
    LFLD(s32, self, 0x48) = 0;
    LFLD(s32, self, 0x4c) = 0;
    LFLD(s32, self, 0x50) = 0;
}

}
