#include "ov000/LoCommon.h"
#include "ov000/ModelViewer.h"

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
void ModelViewer_UpdateModel(ModelViewer *self);
BOOL Model0218fe1c_GetAnimCtrl(void *p, s32 a);
void Model0218fe1c_UpdateAnim(void *p, s32 a);
void GfxSys_StartFadeIn(s32 a, s32 b, s32 c);

static inline BOOL LoIsMode4(void) {
    if (gFadeState[3] == 4) {
        return TRUE;
    }
    return gFadeState[1] == 4 ? TRUE : FALSE;
}

void ModelViewer_Update(ModelViewer *self) {
    ModelViewer_UpdateModel(self);
    if (Model0218fe1c_GetAnimCtrl(&self->model, 0)) {
        Model0218fe1c_UpdateAnim(&self->model, 0x1000);
    }
}

}
