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

extern s32 data_02097d78[5];
void func_ov000_02162bd4(void *self);
BOOL func_ov000_02190a30(void *p, s32 a);
void func_ov000_02190a80(void *p, s32 a);
void func_0203cb78(s32 a, s32 b, s32 c);

static inline BOOL LoIsMode4(void) {
    if (data_02097d78[3] == 4) {
        return TRUE;
    }
    return data_02097d78[1] == 4 ? TRUE : FALSE;
}

void func_ov000_02162a20(void *self) {
    func_ov000_02162bd4(self);
    if (func_ov000_02190a30((u8 *)self + 0x55c, 0)) {
        func_ov000_02190a80((u8 *)self + 0x55c, 0x1000);
    }
}

}
