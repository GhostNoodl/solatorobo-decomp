#pragma pool_strings on
#pragma dont_reuse_strings off
#include "ov006/Window.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/TextWin.h"

typedef struct ov006_Unk0203a4c0 {
    s8 *unk0;
} ov006_Unk0203a4c0;

extern "C" {

extern void *data_ov006_021ec424;
extern void *data_ov006_021ec404;
extern void *data_ov006_021ec444;
extern u16 data_ov006_021eb840[];


BOOL Vram_IsTransferDone(void *a);
BOOL Model_IsReady(Model *a, int b);
BOOL ov006_ListWin_IsReadyB(ov006_ListWin *self);
BOOL ov006_ListWin_IsReadyA(ov006_ListWin *self);

void ov006_ListWin_DrawItem(ov006_ListWin *self, void *arg, void *arg2) {
    if (self->onDrawItem != NULL) {
        self->onDrawItem(arg, self, arg2);
    }
}

int ov006_ListWin_GetLineHeight(ov006_ListWin *self) {
    s8 base;
    data_02097ce0->unk_004 = self->font;
    base = ((ov006_Unk0203a4c0 *)GfxMgr_GetFont(data_02097ce0))->unk0[1];
    return base + self->vfunc_3c();
}

int func_ov006_021e399c(ov006_ListWin *self, int a, int b, int c) {
    return self->vfunc_60(a, b, c);
}

BOOL ov006_Window_OnChildDone(ov006_ListWin *self) {
    BOOL result;
    if (self->unk_90 == NULL) {
        return TRUE;
    }
    result = self->unk_90(self, UiList_GetCurrent(self));
    self->unk_90 = NULL;
    return result;
}

BOOL func_ov006_021e3a0c(ov006_ListWin *self, UiListItem *node) {
    if (self->unk_8c == NULL) {
        return TRUE;
    }
    return self->unk_8c(self, node);
}

BOOL ov006_Window_OnCursor(ov006_ListWin *self, UiListItem *node) {
    if (self->onCursor == NULL) {
        return TRUE;
    }
    return self->onCursor(self, node);
}

static inline int ov006_Window_CalcSize(ov006_ListWin *self) {
    int rows = self->rows * self->vfunc_40();
    int top = self->vfunc_34();
    return rows + top + self->vfunc_38();
}

int ov006_ListWin_CalcSize(ov006_ListWin *self) {
    if (self->flags & 0x20000) {
        int size;
        self->rows += 2;
        size = ov006_Window_CalcSize(self);
        self->rows -= 2;
        return size;
    }
    return ov006_Window_CalcSize(self);
}

int func_ov006_021e3af8(ov006_ListWin *self) {
    return self->vfunc_30() + self->unk_c0 + 0x12;
}

int func_ov006_021e3b1c(void) {
    return 0;
}

int func_ov006_021e3b24(ov006_ListWin *self) {
    return self->unk_b8 != NULL ? 0x12 : 0;
}

int func_ov006_021e3b38(ov006_ListWin *self) {
    return self->unk_c1 * 8;
}

int ov006_Window_GetLineSpacing(void) {
    return 4;
}

int ov006_Window_GetPadBottom(void) {
    return 4;
}

int ov006_Window_GetPadTop(ov006_ListWin *self) {
    return (self->title2 != NULL ? 0x10 : 0) + 10;
}

int ov006_Window_GetPadLeft(void) {
    return 0;
}

static inline BOOL ov006_TextWin_IsReady(TextWin *self) {
    if (self->unk_6c == NULL) {
        return TRUE;
    }
    if (Vram_IsTransferDone(self->unk_6c)) {
        self->unk_6c = NULL;
    } else {
        return !self->noVram;
    }
    return TRUE;
}

BOOL ov006_ListWin_IsReady(ov006_ListWin *self) {
    BOOL result = ov006_ListWin_IsReadyB(self);
    TextWin *text = self->title2;
    if (text != NULL && !ov006_TextWin_IsReady(text)) {
        result = FALSE;
    }
    return result;
}

BOOL ov006_ListWin_IsReadyB(ov006_ListWin *self) {
    BOOL result = ov006_ListWin_IsReadyA(self);
    if (self->unk_b4 != NULL && !Model_IsReady(self->unk_b4, 0xffff)) {
        result = FALSE;
    }
    return result;
}

BOOL ov006_ListWin_IsReadyA(ov006_ListWin *self) {
    BOOL result = TRUE;
    if (self->model != NULL && !Model_IsReady(self->model, 0xffff)) {
        result = FALSE;
    }
    if (self->title != NULL && !ov006_TextWin_IsReady(self->title)) {
        result = FALSE;
    }
    if (self->caption != NULL && !ov006_TextWin_IsReady(self->caption)) {
        result = FALSE;
    }
    return result;
}

static inline void ov006_ModelHolder_Dtor(ov006_ModelHolder *self) {
    self->vtbl = &data_ov006_021ec424;
    OV006_DELETE_MODEL(self->model);
}

ov006_ModelHolder *func_ov006_021e3cec(ov006_ModelHolder *self) {
    ov006_ModelHolder_Dtor(self);
    return self;
}

ov006_ModelHolder *ov006_ModelHolder_DtorDelete(ov006_ModelHolder *self) {
    ov006_ModelHolder_Dtor(self);
    Heap_Free(self);
    return self;
}

void ov006_ModelHolder_Load(ov006_ModelHolder *self, int a) {
    const char *file = "menu/net";
    const char *name = "wireless_slv";
    Model *model;
    OV006_DELETE_MODEL(self->model);
    model = (Model *)Heap_Alloc(sizeof(Model));
    if (model != NULL) {
        PlttRes_Init_02041218(&model->pltt);
        TexObj_Init(model, name, 0);
        STD_CopyString(model->name, file);
    }
    self->model = model;
    TexObj_SetRes(self->model, func_02035de0(file, name));
    self->model->flags |= 2;
    self->model->flags |= 0x80000;
    self->model->flags |= 0x400000;
    TexObj_SelectImage(self->model, a, 0);
    TexObj_SelectImage(self->model, a, 1);
    TexObj_SelectImage(self->model, a, 2);
    TexObj_SelectImage(self->model, a, 3);
    self->unk8 = a;
}

void func_ov006_021e3f0c(void) {
}

}
