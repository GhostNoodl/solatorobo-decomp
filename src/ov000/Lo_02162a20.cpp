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

extern s32 data_02097d78[5];
void func_ov000_02162bd4(ModelViewer *self);
BOOL Model0218fe1c_GetAnimCtrl(void *p, s32 a);
void Model0218fe1c_UpdateAnim(void *p, s32 a);
void func_0203cb78(s32 a, s32 b, s32 c);

static inline BOOL LoIsMode4(void) {
    if (data_02097d78[3] == 4) {
        return TRUE;
    }
    return data_02097d78[1] == 4 ? TRUE : FALSE;
}

void ModelViewer_Update(ModelViewer *self) {
    func_ov000_02162bd4(self);
    if (Model0218fe1c_GetAnimCtrl(&self->model, 0)) {
        Model0218fe1c_UpdateAnim(&self->model, 0x1000);
    }
}

}
