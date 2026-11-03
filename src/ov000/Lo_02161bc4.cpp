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
BOOL Model0218fe1c_GetAnimCtrl(void *p, s32 a);
void Model0218fe1c_UpdateAnim(void *p, s32 a);
void GfxSys_StartFadeIn(s32 a, s32 b, s32 c);

static inline BOOL LoIsMode4(void) {
    if (data_02097d78[3] == 4) {
        return TRUE;
    }
    return data_02097d78[1] == 4 ? TRUE : FALSE;
}

struct Obj02161bc4 {
    u8 unk_00[0x70];
    s32 unk_70;
};

LoGlyph *func_ov000_02161bc4(Obj02161bc4 *self, s32 unused, LoGlyph *g, u16 *count) {
    s32 i;
    s32 n = *count;
    for (i = 0; i < n; i++) {
        g[i].w.pal = g[i].w.pal + self->unk_70;
    }
    *count = n;
    return g;
}

}
