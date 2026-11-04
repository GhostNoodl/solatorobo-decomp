#include "ov002/ov002.h"

extern "C" {

Model0218fe1c *Model0218fe1c_Init(void *p);

BOOL Model0218fe1c_SetRes(void *a, void *b, int c, int d);

BOOL Model0218fe1c_SetAnim(void *a, void *b, s32 c, int d);

void Model0218fe1c_SetLoop(void *a);

void Model0218fe1c_ClearLoop(void *a);

void Model0218fe1c_SetReverse(void *a);

s32 **Model0218fe1c_GetAnimCtrl(void *a, int b);

void NNSi_G3dModifyPolygonAttrMask(void *a, int b, s32 c);



extern char data_ov002_021efdd1[];

extern char data_ov002_021efdd7[];

extern Ov002SndCue data_ov002_021eeffc[];

static inline Model0218fe1c *ov002_newAnim(void) {
    Model0218fe1c *m = (Model0218fe1c *)Heap_Alloc(sizeof(Model0218fe1c));
    if (m != NULL) {
        m = Model0218fe1c_Init(m);
    }
    return m;
}

static inline void ov002_bindPal(Model0218fe1c *anim, void *pal) {
    ResHandle *res = anim->res->mdl_handle;
    NNS_G3dBindMdlSet(NNS_G3dGetMdlSet((NNSG3dResFileHeader *)(res != NULL ? res->unk_00 : NULL)), (NNSG3dResTex *)pal);
}

void Obj021efe4c_SetupBoxModels(Obj021efe4c *self) {
    void *pal;
    void *src = ((void *)self->unk_04->unk_fc);
    Ov002SndCue *k;
    s32 x;
    if (src == NULL) {
        pal = NULL;
    } else {
        pal = NNS_G3dGetTex((NNSG3dResFileHeader *)*(void **)src);
    }
    self->unk_08 = ov002_newAnim();
    Model0218fe1c_SetRes(self->unk_08, self->unk_0c, 0, 1);
    Model0218fe1c_SetAnim(self->unk_08, data_ov002_021efdd1, 0x1000, 0);
    Model0218fe1c_SetLoop(self->unk_08);
    self->unk_08->boxTest = 0;
    NNSi_G3dModifyPolygonAttrMask(self->unk_08->mdl, 1, 0x1f0000);
    ov002_bindPal(self->unk_08, pal);
    self->unk_08->visible = 1;
    self->unk_10 = ov002_newAnim();
    Model0218fe1c_SetRes(self->unk_10, self->unk_14, 0, 1);
    Model0218fe1c_SetAnim(self->unk_10, data_ov002_021efdd7, 0x1000, 0);
    Model0218fe1c_ClearLoop(self->unk_10);
    self->unk_10->boxTest = 0;
    ov002_bindPal(self->unk_10, pal);
    self->unk_10->visible = 1;
    Model0218fe1c_SetReverse(self->unk_10);
    k = data_ov002_021eeffc;
    self->cues = k;
    {
        s32 **pp = Model0218fe1c_GetAnimCtrl(self->unk_10, 0);
        x = 0;
        if (*pp != NULL) {
            x = **pp;
        }
    }
    while (k->time < (x + 0x1000) >> 12) {
        if (k->time < 0) {
            k--;
            break;
        }
        k++;
    }
    self->cue = k;
    self->unk_5d = 0;
    Obj021efe4c_UpdateBoxMesh(self);
    self->visible = 1;
}

}
