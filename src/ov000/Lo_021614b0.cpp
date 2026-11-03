#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

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
void func_ov000_02161798(void *self, s32 a, s32 b, s32 c);
void func_ov000_02161994(void *self, s32 a, s32 b, s32 c);
BOOL Model0218fe1c_GetAnimCtrl(void *p, s32 a);
void Model0218fe1c_UpdateAnim(void *p, s32 a);
void GfxSys_StartFadeIn(s32 a, s32 b, s32 c);

static inline BOOL LoIsMode4(void) {
    if (data_02097d78[3] == 4) {
        return TRUE;
    }
    return data_02097d78[1] == 4 ? TRUE : FALSE;
}

void Lo021cacd8_DrawBody(Lo021cacd8 *self, s32 a, s32 b, s32 c) {
    if (a == 0) {
        return;
    }
    self->vfunc_64(a, b, c);
    func_ov000_02161798(self, a, b, c);
    func_ov000_02161994(self, a, b, c);
    self->flags |= 0x200;
}

}
