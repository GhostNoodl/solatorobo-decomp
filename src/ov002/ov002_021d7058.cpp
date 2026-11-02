#include "ov002/ov002.h"

extern "C" {

void *func_ov000_0218fe1c(void *p);

BOOL func_ov000_0218ffdc(void *a, void *b, int c, int d);

BOOL func_ov000_02190cb0(void *a, void *b, s32 c, int d);

void func_ov000_021915a0(void *a);

void func_ov000_02191618(void *a);

void func_ov000_02191780(void *a);

s32 **func_ov000_02190a30(void *a, int b);

void NNSi_G3dModifyPolygonAttrMask(void *a, int b, s32 c);



extern char data_ov002_021efdd1[];

extern char data_ov002_021efdd7[];

typedef struct Key021d7058 {
    s16 t;
    s16 a;
    s16 b;
} Key021d7058;

extern Key021d7058 data_ov002_021eeffc[];

static inline void *ov002_newAnim(void) {
    void *m = Heap_Alloc(0xe8);
    if (m != NULL) {
        m = func_ov000_0218fe1c(m);
    }
    return m;
}

static inline void ov002_bindPal(void *anim, void *pal) {
    void **res = FIELD(*(void **)anim, 0xc, void **);
    NNS_G3dBindMdlSet(NNS_G3dGetMdlSet((NNSG3dResFileHeader *)(res != NULL ? *res : NULL)), (NNSG3dResTex *)pal);
}

void func_ov002_021d7058(Obj021efe4c *self) {
    void *pal;
    void *src = FIELD(((u8 *)self->unk_04), 0xfc, void *);
    Key021d7058 *k;
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
    FIELD(((u8 *)self->unk_08), 0xc2, Bits16).b4 = 0;
    NNSi_G3dModifyPolygonAttrMask(FIELD(((u8 *)self->unk_08), 0x4, void *), 1, 0x1f0000);
    ov002_bindPal(self->unk_08, pal);
    FIELD(((u8 *)self->unk_08), 0xc2, Bits16).b0 = 1;
    self->unk_10 = ov002_newAnim();
    func_ov000_0218ffdc(self->unk_10, self->unk_14, 0, 1);
    func_ov000_02190cb0(self->unk_10, data_ov002_021efdd7, 0x1000, 0);
    func_ov000_02191618(self->unk_10);
    FIELD(((u8 *)self->unk_10), 0xc2, Bits16).b4 = 0;
    ov002_bindPal(self->unk_10, pal);
    FIELD(((u8 *)self->unk_10), 0xc2, Bits16).b0 = 1;
    func_ov000_02191780(self->unk_10);
    k = data_ov002_021eeffc;
    FIELD(self, 0x60, Key021d7058 *) = k;
    {
        s32 **pp = func_ov000_02190a30(self->unk_10, 0);
        x = 0;
        if (*pp != NULL) {
            x = **pp;
        }
    }
    while (k->t < (x + 0x1000) >> 12) {
        if (k->t < 0) {
            k--;
            break;
        }
        k++;
    }
    FIELD(self, 0x64, Key021d7058 *) = k;
    self->unk_5d = 0;
    func_ov002_021d7238(self);
    self->unk_5c = 1;
}

}
