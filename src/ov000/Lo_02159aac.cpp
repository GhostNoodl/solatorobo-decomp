#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"
#include "Main/Res/ResArc.h"

extern "C" {

extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;
void func_02041c5c(void *m, void *fn);
void func_02041c20(void *m, s32 a, void *b);
void Obj02153c48_CreateText(void *node, void *a, s32 b, s32 c, s32 d);
void func_ov000_0215a088(void *self);
void *func_ov000_02159998(void *self, u16 *msg, void *arr, u16 *cnt);

typedef s32 (*VFn9aac)(void *);


static inline BOOL LoadModel9aac(Lo021cb5a8 *self) {
    if (self->model) {
        return TRUE;
    }
    if (self->flag6 ? TRUE : FALSE) {
        MODEL_NEW(self->model, data_0208cb84, data_0208cc8c);
    } else {
        MODEL_NEW(self->model, data_0208cb74, data_0208cca0);
    }
    {
        ResList *a = ResMgr_GetArcList(self->model->name);
        void *b = ResList_FindType2(a, self->model->unk_04c);
        TexObj_SetRes(self->model, b);
    }
    self->model->flags |= 2;
    TexObj_SelectImage(self->model, 0, 7);
    return TRUE;
}

void Lo021cb5a8_Setup(Lo021cb5a8 *self) {
    s32 w2;
    UiListItem *n;
    s32 maxw;
    s32 x;
    s32 y;
    s32 lim;
    s32 w;
    u32 fl;

    maxw = 0;
    self->rows = 1;
    for (n = self->items; n != NULL; n = (UiListItem *)((u8 *)n->next)) {
        Obj02153c48_CreateText(n, ((void *)self->font), 1, 0, 0);
        w = LFLD(s32, n->label, 0x44);
        if (w > maxw) {
            maxw = w;
        }
    }
    if (self->unk_d4 == -1) {
        self->unk_d4 = maxw + 0x14;
    }
    fl = self->flags;
    if (fl & 0x4000000) {
        if (!(fl & 0x8000000)) {
            self->width = -1;
        } else {
            self->width = self->unk_d4 + ((VObj *)self)->vfunc_30() * 2 - 8;
        }
    }
    if (self->width != -1) {
        lim = self->width - ((VObj *)self)->vfunc_30() * 2;
    } else {
        self->width = ((VObj *)self)->vfunc_30() * 2 - 8;
        lim = 9999;
    }
    y = 0;
    x = 0;
    for (n = self->items; n != NULL; n = (UiListItem *)((u8 *)n->next)) {
        w2 = LFLD(s32, n->label, 0x44) + 0x14;
        if (x != 0 && x + w2 > lim) {
            x = 0;
            y += ((VObj *)self)->vfunc_40();
            self->rows++;
        } else if (lim == 9999) {
            self->width += w2;
        }
        n->unk_14 = x;
        n->unk_18 = y;
        x += w2;
    }
    {
        s32 a = self->rows * ((VObj *)self)->vfunc_40();
        s32 b = ((VObj *)self)->vfunc_34();
        self->height = a + b + ((VObj *)self)->vfunc_38();
    }
    if (LoadModel9aac(self)) {
        TexObj_SelectImage(self->model, 0, 8);
        TexObj_SelectImage(self->model, 0, 2);
        func_02041c5c(self->model, (void *)func_ov000_02159998);
        func_02041c20(self->model, 8, self);
        func_02041c20(self->model, 2, self);
    }
    func_ov000_0215a088(self);
    fl = self->flags;
    if (fl & 0x10000000) {
        self->posX = 2;
    } else if (fl & 0x20000000) {
        self->posX = 0xfd - self->width;
    }
    fl = self->flags;
    if (fl & 0x40000000) {
        self->posY = 2;
    } else if (fl & 0x80000000) {
        self->posY = 0xbd - self->height;
    }
    self->busy = 1;
}

}
