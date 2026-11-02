#include "ov009/ov009.h"

extern "C" {

extern BOOL func_ov000_0218cf5c(Ov009Actor *self);
extern BOOL func_ov000_0218f110(void *p);

BOOL Ov009ActVt_02217594_IsReady(Ov009ActVt_02217594 *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (self->anim.unk_00 >= 0 && !func_ov000_0218f110(&self->anim)) {
        r = FALSE;
    }
    return r;
}

extern void func_0203f364(Ov009Sub48 *p);
extern void NNSi_G3dModifyPolygonAttrMask(void *p, s32 a, s32 b);
extern void NNSi_G3dModifyMatFlag(void *p, s32 a, s32 b);
extern BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
extern void func_ov000_02190758(void *a, const void *b, s32 c);
extern Ov009Actor *func_ov000_0219bf90(void);
void Ov009ActVt_02217594_Start(Ov009ActVt_02217594 *self) {
    u32 saved;
    Ov009Sub48 *s48;
    Ov009Sub44 *s44;
    Ov009Actor *t;
    func_ov003_021d112c(self);
    func_ov000_0218ffdc(&self->model, &self->anim, 0, 1);
    self->model.unk_b4 = self->id;
    switch (self->unk_1a) {
    case 0:
    case 1: {
        s32 y = self->pos.y;
        s32 x = self->pos.x;
        s32 z = self->pos.z;
        if (self->unk_1a == 0) {
            x += 0x6000;
        } else {
            x -= 0x6000;
            self->rot[1] = 0x8000;
        }
        self->model.unk_78.x = x;
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
        break;
    }
    case 2:
        self->unk_48->unk_60 = 0x5000;
        self->unk_44->unk_10 = 0x5000;
        break;
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
    s48 = self->unk_48;
    s48->unk_9a_0 = 0;
    s48->unk_9a_3 = 0;
    func_0203f364(s48);
    s48 = self->unk_48;
    s48->unk_9a_1 = 0;
    s48->unk_9a_4 = 0;
    s48 = self->unk_48;
    s48->unk_9a_2 = 0;
    s48->unk_9a_5 = 0;
    s44 = self->unk_44;
    s44->unk_22_0 = 0;
    s44->unk_22_1 = 0;
    self->unk_44->unk_22_2 = 2;
    self->unk_90 = 0xffff;
    t = func_ov000_0219bf90();
    if (t != NULL) {
        self->unk_90 = t->id;
    }
    self->step = 0;
    self->unk_314 = 0;
}

}
