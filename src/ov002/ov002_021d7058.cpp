#include "ov002/ov002.h"

extern "C" {

Model0218fe1c *func_ov000_0218fe1c(void *p);

BOOL func_ov000_0218ffdc(void *a, void *b, int c, int d);

BOOL func_ov000_02190cb0(void *a, void *b, s32 c, int d);

void func_ov000_021915a0(void *a);

void func_ov000_02191618(void *a);

void func_ov000_02191780(void *a);

s32 **func_ov000_02190a30(void *a, int b);

void NNSi_G3dModifyPolygonAttrMask(void *a, int b, s32 c);



extern char data_ov002_021efdd1[];

extern char data_ov002_021efdd7[];

extern Ov002SndCue data_ov002_021eeffc[];

static inline Model0218fe1c *ov002_newAnim(void) {
    Model0218fe1c *m = (Model0218fe1c *)Heap_Alloc(sizeof(Model0218fe1c));
    if (m != NULL) {
        m = func_ov000_0218fe1c(m);
    }
    return m;
}

static inline void ov002_bindPal(Model0218fe1c *anim, void *pal) {
    ResHandle *res = anim->res->mdl_handle;
    NNS_G3dBindMdlSet(NNS_G3dGetMdlSet((NNSG3dResFileHeader *)(res != NULL ? res->unk_00 : NULL)), (NNSG3dResTex *)pal);
}

void func_ov002_021d7058(Obj021efe4c *self) {
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
    func_ov000_0218ffdc(self->unk_08, self->unk_0c, 0, 1);
    func_ov000_02190cb0(self->unk_08, data_ov002_021efdd1, 0x1000, 0);
    func_ov000_021915a0(self->unk_08);
    self->unk_08->boxTest = 0;
    NNSi_G3dModifyPolygonAttrMask(self->unk_08->mdl, 1, 0x1f0000);
    ov002_bindPal(self->unk_08, pal);
    self->unk_08->visible = 1;
    self->unk_10 = ov002_newAnim();
    func_ov000_0218ffdc(self->unk_10, self->unk_14, 0, 1);
    func_ov000_02190cb0(self->unk_10, data_ov002_021efdd7, 0x1000, 0);
    func_ov000_02191618(self->unk_10);
    self->unk_10->boxTest = 0;
    ov002_bindPal(self->unk_10, pal);
    self->unk_10->visible = 1;
    func_ov000_02191780(self->unk_10);
    k = data_ov002_021eeffc;
    self->cues = k;
    {
        s32 **pp = func_ov000_02190a30(self->unk_10, 0);
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
    func_ov002_021d7238(self);
    self->visible = 1;
}

}
