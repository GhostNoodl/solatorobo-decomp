#include "ov008/ov008.h"
#include "Main/Gfx/GfxMgr.h"



extern "C" {

extern void *UiList_vtbl;
extern void *UiObj_vtbl;
BOOL Model_IsReady(Model *a, u32 b);
BOOL Vram_IsTransferDone(void *p);
BOOL func_ov008_021d01b0(Ov008Menu *self);

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

s32 func_ov008_021d0014(Ov008Menu *self, s32 arg) {
    if (self->unk_8c == NULL) {
        return TRUE;
    }
    return self->unk_8c(self, arg);
}

s32 Ov008Menu_OnCursor(Ov008Menu *self, s32 arg) {
    if (self->onCursor == NULL) {
        return TRUE;
    }
    return self->onCursor(self, arg);
}

s32 Ov008Menu_OnDecide(Ov008Menu *self, s32 arg) {
    if (self->onDecide == NULL) {
        return TRUE;
    }
    return self->onDecide(self, arg);
}

s32 Ov008Menu_GetHeight(Ov008Menu *self) {
    if (self->flags & 0x20000) {
        s32 r;
        self->rows += 2;
        r = Ov008_Height(self);
        self->rows -= 2;
        return r;
    }
    return Ov008_Height(self);
}

s32 Ov008Menu_GetLineSpacing(void) {
    return 4;
}

s32 func_ov008_021d0124(Ov008Menu *self) {
    return self->v30() + self->unk_c0 + 0x12;
}

s32 Ov008Menu_GetPadLeft(void) {
    return 0xc;
}

s32 func_ov008_021d0150(void) {
    return 0;
}

s32 func_ov008_021d0158(Ov008Menu *self) {
    return self->unk_b8 != NULL ? 0x12 : 0;
}

s32 func_ov008_021d016c(Ov008Menu *self) {
    return self->unk_c1 * 8;
}

BOOL Ov008Menu_IsLoaded(Ov008Menu *self) {
    BOOL r = func_ov008_021d01b0(self);
    if (self->unk_b4 != NULL && !Model_IsReady(self->unk_b4, 0xffff)) {
        r = FALSE;
    }
    return r;
}

BOOL func_ov008_021d01b0(Ov008Menu *self) {
    BOOL r = TRUE;
    Ov008MenuRes *p;
    if (self->unk_10 != NULL && !Model_IsReady(self->unk_10, 0xffff)) {
        r = FALSE;
    }
    p = self->unk_14;
    if (p != NULL && !Ov008_ModelDone(p)) {
        r = FALSE;
    }
    p = self->unk_18;
    if (p != NULL && !Ov008_ModelDone(p)) {
        r = FALSE;
    }
    return r;
}

Ov008V *Ov008Menu_Dtor(Ov008Menu *self) {
    OV008_SET_VT(self, &UiList_vtbl);
    self->v2c();
    OV008_SET_VT(self, &UiObj_vtbl);
    self->v2c();
    return self;
}

}
