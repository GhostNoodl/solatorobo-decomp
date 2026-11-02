#include "ov002/ov002.h"
#include "Main/Gfx/TextWin.h"

extern "C" {

Task021efb24 *Ov002TaskVt_021efb24_DtorDelete(Task021efb24 *self) {
    *(VFunc **)self = data_ov002_021efb24;
    Obj021efe7c_Delete();
    TaskBase_dtor(self);
    Heap_Free(self);
    return self;
}

Task021efb24 *Ov002TaskVt_021efb24_Dtor(Task021efb24 *self) {
    *(VFunc **)self = data_ov002_021efb24;
    Obj021efe7c_Delete();
    TaskBase_dtor(self);
    return self;
}

void func_ov002_021d6a54(UiObj *self, void *arg, void *arg2) {
    UiDrawItemFn cb = self->onDrawItem;
    if (cb != NULL) {
        cb(arg, self, arg2);
    }
}

int func_ov002_021d6a78(UiObj *self) {
    s8 base;
    data_02097ce0->unk_004 = self->font;
    base = (*(s8 **)GfxMgr_GetFont(data_02097ce0))[1];
    return base + self->vfunc_3c();
}

BOOL func_ov002_021d6abc(void) {
    return FALSE;
}

int func_ov002_021d6ac4(VObj *self, int a, int b, int c) {
    return self->vfunc_60(a, b, c);
}

BOOL func_ov002_021d6ad8(UiList *self) {
    UiItemFn cb = self->unk_90;
    BOOL r;
    if (cb == NULL) {
        return TRUE;
    }
    r = cb(self, UiList_GetCurrent(self));
    self->unk_90 = NULL;
    return r;
}

BOOL func_ov002_021d6b34(UiList *self, UiListItem *item) {
    UiItemFn cb = self->unk_8c;
    if (cb == NULL) {
        return TRUE;
    }
    return cb(self, item);
}

BOOL Ov002Vt_021efca4_OnCursor(UiList *self, UiListItem *item) {
    UiItemFn cb = self->onCursor;
    if (cb == NULL) {
        return TRUE;
    }
    return cb(self, item);
}

BOOL Ov002Vt_021efca4_OnDecide(UiList *self, UiListItem *item) {
    UiItemFn cb = self->onDecide;
    if (cb == NULL) {
        return TRUE;
    }
    return cb(self, item);
}

static inline int func_ov002_021d6b88_calc(UiObj *self) {
    int a = self->vfunc_40() * self->rows;
    int b = self->vfunc_34();
    int c = self->vfunc_38();
    a += b;
    return a + c;
}

int Ov002Vt_021efca4_GetHeight(UiObj *self) {
    int r;
    if (self->flags & 0x20000) {
        self->rows += 2;
        r = func_ov002_021d6b88_calc(self);
        self->rows -= 2;
        return r;
    }
    return func_ov002_021d6b88_calc(self);
}

int func_ov002_021d6c3c(void) {
    return 0;
}

int func_ov002_021d6c44(void) {
    return 0;
}

int func_ov002_021d6c4c(void) {
    return 4;
}

int func_ov002_021d6c54(void) {
    return 3;
}

int func_ov002_021d6c5c(void) {
    return 6;
}

int func_ov002_021d6c64(UiList *self) {
    return self->vfunc_30() + self->unk_c0 + 0x12;
}

int func_ov002_021d6c88(void) {
    return 0xc;
}

int func_ov002_021d6c90(void) {
    return 0;
}

int func_ov002_021d6c98(UiList *self) {
    return self->unk_b8 != NULL ? 0x12 : 0;
}

int func_ov002_021d6cac(UiList *self) {
    return self->unk_c1 * 8;
}

int Ov002Vt_021efca4_IsLoaded(UiList *self) {
    int r = Ov002RowList_IsLoaded(self);
    if (self->unk_b4 != NULL && Model_IsReady(self->unk_b4, 0xffff) == 0) {
        r = 0;
    }
    return r;
}

static inline BOOL func_ov002_021d6cf0_check(TextWin *o) {
    if (o->unk_6c == NULL) {
        return TRUE;
    }
    if (Vram_IsTransferDone((unsigned int)o->unk_6c)) {
        o->unk_6c = NULL;
    } else {
        return !o->noVram ? TRUE : FALSE;
    }
    return TRUE;
}
BOOL Ov002RowList_IsLoaded(UiObj *self) {
    BOOL r = TRUE;
    TextWin *o;
    if (self->model != NULL && !Model_IsReady(self->model, 0xffff)) {
        r = FALSE;
    }
    o = (TextWin *)self->title;
    if (o != NULL && !func_ov002_021d6cf0_check(o)) {
        r = FALSE;
    }
    o = (TextWin *)self->caption;
    if (o != NULL && !func_ov002_021d6cf0_check(o)) {
        r = FALSE;
    }
    return r;
}

Ov002Hud *Ov002Vt_021efb14_Dtor(Ov002Hud *self) {
    *(VFunc **)self = data_ov002_021efb14;
    Ov002Hud_Release(self);
    return self;
}

void *Ov002Vt_021efb04_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021efb04;
    MsgBox_Release(self);
    return self;
}

VObj *Ov002Vt_021efca4_Dtor(VObj *self) {
    *(VFunc **)self = data_ov000_021caec8;
    self->vfunc_2c();
    *(VFunc **)self = data_ov000_021cac60;
    self->vfunc_2c();
    return self;
}

void Obj021efe4c_Init(Obj021efe4c *self) {
    self->trans.x = 0;
    self->trans.y = 0;
    self->trans.z = 0;
    self->unk_24 = 0;
    self->unk_26 = 0;
    self->unk_28 = 0;
    MTX_Identity33_(&self->rot);
    self->scale.x = 0x1000;
    self->scale.y = 0x1000;
    self->scale.z = 0x1000;
    self->visible = 0;
    self->unk_5d = 0;
    MI_CpuFill8(&self->map, 0, 4);
    self->cues = NULL;
    self->cue = NULL;
    self->unk_68 = 0;
    self->map = NULL;
    self->unk_04 = NULL;
    self->unk_08 = NULL;
    self->unk_0c = NULL;
    self->unk_10 = NULL;
    self->unk_14 = NULL;
}

static inline void func_ov002_021d6ec4_release(Model0218fe1c *obj) {
    ResHandle *res = obj->res->mdl_handle;
    NNS_G3dReleaseMdlSet(NNS_G3dGetMdlSet((NNSG3dResFileHeader *)(res != NULL ? res->unk_00 : NULL)));
}

void Obj021efe4c_Release(Obj021efe4c *self) {
    if (self->unk_08 != NULL) {
        func_ov002_021d6ec4_release(self->unk_08);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_WITH(self->unk_08, Model0218fe1c_FreeAnims);
        HEAP_POP(saved);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_WITH(self->unk_0c, ResSet_ReleaseAll);
        HEAP_POP(saved);
    }
    if (self->unk_10 != NULL) {
        func_ov002_021d6ec4_release(self->unk_10);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_WITH(self->unk_10, Model0218fe1c_FreeAnims);
        HEAP_POP(saved);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_WITH(self->unk_14, ResSet_ReleaseAll);
        HEAP_POP(saved);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_WITH(self->unk_04, ResSet_ReleaseAll);
        HEAP_POP(saved);
    }
}

}
