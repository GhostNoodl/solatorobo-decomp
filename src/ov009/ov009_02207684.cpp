#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_0221729c[];
extern char data_ov009_022172a7[];
extern BOOL func_ov000_0218cf5c(Ov009Actor *self);
extern BOOL func_ov000_0218f110(void *p);

static inline void Ov009Names_Set(Ov009Names *n, const char *a, const char *b) {
    STD_CopyString(n->unk_10, a);
    STD_CopyString(n->unk_30, b);
    n->unk_03_1 = 1;
    STD_CopyString(n->unk_4c, a);
    STD_CopyString(n->unk_6c, b);
    n->unk_03_2 = 1;
    n->unk_00 = 0;
}

BOOL Ov009ActVt_02217844_IsReady(Ov009ActVt_02217844 *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (self->anim.unk_00 >= 0 && !func_ov000_0218f110(&self->anim)) {
        r = FALSE;
    }
    return r;
}

extern void func_0203f2b8(void *p);
extern void NNSi_G3dModifyPolygonAttrMask(void *p, s32 a, s32 b);
extern void NNSi_G3dModifyMatFlag(void *p, s32 a, s32 b);
extern BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
extern void func_ov000_02190758(void *a, const void *b, s32 c);
void Ov009ActVt_02217844_Start(Ov009ActVt_02217844 *self) {
    u32 saved;
    func_ov003_021d112c(self);
    func_ov000_0218ffdc(&self->model, &self->anim, 0, 1);
    self->model.unk_b4 = self->id;
    if (self->unk_1a == 0) {
        self->model.unk_78 = self->pos;
        self->model.scale.x = 0xccd;
        self->model.scale.y = 0xccd;
        self->model.scale.z = 0xccd;
    } else {
        s32 y = self->pos.y;
        s32 x = self->pos.x;
        s32 z = self->pos.z;
        self->model.unk_78.x = x + 0x6000;
        self->model.unk_78.y = y - 0x800;
        self->model.unk_78.z = z;
        self->model.scale.x = 0x99a;
        self->model.scale.y = 0x99a;
        self->model.scale.z = 0x99a;
        {
            Ov009Vec *s = &self->unk_38->scale;
            s->x = 0xccd;
            s->y = 0xccd;
            s->z = 0xccd;
        }
    }
    func_ov000_02190758(&self->model, self->rot, 0);
    NNSi_G3dModifyPolygonAttrMask(self->model.unk_04, 1, 0x3f000000);
    NNSi_G3dModifyMatFlag(self->model.unk_04, 1, 0x40);
    NNSi_G3dModifyMatFlag(self->model.unk_04, 1, 0x80);
    NNSi_G3dModifyMatFlag(self->model.unk_04, 1, 0x200);
    NNSi_G3dModifyMatFlag(self->model.unk_04, 1, 0x400);
    self->model.unk_c2 |= 0x80;
    NNSi_G3dModifyPolygonAttrMask(self->model.unk_04, 1, 0x1f0000);
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_3c != NULL) {
        if (self->unk_3c != NULL) {
            self->unk_3c->v04();
        }
        self->unk_3c = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_48 != NULL) {
        Ov009Sub48 *p = self->unk_48;
        if (p != NULL) {
            func_0203f2b8(p);
            func_0203de1c(p);
        }
        self->unk_48 = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_44 != NULL) {
        func_0203de1c(self->unk_44);
        self->unk_44 = NULL;
    }
    data_02097dd0->cur = saved;
}

}
