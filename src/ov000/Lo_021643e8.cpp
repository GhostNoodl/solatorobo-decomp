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

extern s32 gFadeState[5];
BOOL Model0218fe1c_GetAnimCtrl(void *p, s32 a);
void Model0218fe1c_UpdateAnim(void *p, s32 a);
void GfxSys_StartFadeIn(s32 a, s32 b, s32 c);

static inline BOOL LoIsMode4(void) {
    if (gFadeState[3] == 4) {
        return TRUE;
    }
    return gFadeState[1] == 4 ? TRUE : FALSE;
}

struct Obj021643e8 {
    u8 unk_00[0x20];
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    s32 unk_30;
    s32 unk_34;
    u8 unk_38[0x8];
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
    s32 unk_50;
};

void func_ov000_021643e8(Obj021643e8 *self) {
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_28 = 0;
    self->unk_2c = 0;
    self->unk_30 = 0;
    self->unk_34 = 4;
    self->unk_40 = 0;
    self->unk_44 = 4;
    self->unk_48 = 0;
    self->unk_4c = 0;
    self->unk_50 = 0;
}

}
