#include "ov008/ov008.h"
#include "Main/Gfx/GfxMgr.h"



extern "C" {

extern void *UiList_vtbl;
extern void *UiObj_vtbl;
BOOL Model_IsReady(Model *a, u32 b);
BOOL Vram_IsTransferDone(void *p);
BOOL Ov008Menu_AreModelsReady(Ov008Menu *self);

}

static inline BOOL Ov008_IsState2(Ov008Menu *self) {
    return self->state == 2;
}

static inline Ov008Item *Ov008_GetItem(Ov008Menu *self) {
    Ov008Item *p = self->topItem;
    s32 i;
    if (p == NULL) {
        return NULL;
    }
    i = self->cursor;
    while (i-- != 0) {
        p = p->next;
    }
    return p;
}

static inline BOOL Ov008_ModelDone(Ov008MenuRes *p) {
    if (p->unk_6c == NULL) {
        return TRUE;
    }
    if (Vram_IsTransferDone(p->unk_6c)) {
        p->unk_6c = NULL;
    } else {
        return p->unk_04.b6 == 0;
    }
    return TRUE;
}

static inline s32 Ov008_Height(Ov008Menu *self) {
    s32 a = self->v40() * self->rows;
    s32 b = self->v34();
    return a + b + self->v38();
}

extern "C" {

void Ov008Menu_DrawItem(Ov008Menu *self, s32 arg, s32 b) {
    Ov008Cb cb = self->onDrawItem;
    if (cb != NULL) {
        cb(arg, self, b);
    }
}

s32 Ov008Menu_GetLineHeight(Ov008Menu *self) {
    s32 a;
    gGfxMgr->unk_004 = self->font;
    a = (*(s8 **)GfxMgr_GetFont(gGfxMgr))[1];
    return a + self->v3c();
}

s32 func_ov008_021cff84(Ov008Menu *self, s32 a, s32 b, s32 c) {
    return self->v60(a, b, c);
}

bool Ov008Menu_IsShown(Ov008Menu *self) {
    return Ov008_IsState2(self);
}

s32 Ov008Menu_OnChildDone(Ov008Menu *self) {
    Ov008Cb cb = self->unk_90;
    s32 r;
    if (cb == NULL) {
        return 1;
    }
    r = cb(self, Ov008_GetItem(self));
    self->unk_90 = NULL;
    return r;
}

}
