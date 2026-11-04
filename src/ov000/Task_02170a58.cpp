#include "ov000/MessageQueue.h"
#include "ov000/ObjLayouts.h"
#include "ov000/LoTimer.h"
#include "ov000/LoTicker.h"
#include "ov000/SceneCmd.h"
#include "ov000/HeapScope.h"
#include "Main/Gfx/SlideWin.h"
#include "ov000/Obj0216c954.h"
#include "ov000/Obj0216ad04.h"

extern "C" {

extern u8 ResHandle_vtbl[];
extern u8 Ov000Vt_021cac0c_vtbl[];
extern u8 Lo021cb798_vtbl[];
extern u8 Lo021cb7ec_vtbl[];
extern u8 Lo021cb744_vtbl[];
extern u8 Lo021cb6f0_vtbl[];
extern u8 Lo021cb840_vtbl[];
extern u8 Lo021cb894_vtbl[];
void *Heap_Alloc(u32 size);
void Lo0216b474_Init(Lo0216b474 *p);
void __cxa_vec_ctor(void *arr, int n, u32 size, void (*ctor)(void *), void (*dtor)(void *));
void Bss021ccd74_LoadModels(void);
BOOL MsgRes_BindGlobal(void);
BOOL MissionCard_Update(void *p);
BOOL SceneCondCard_Update(void *p);
BOOL MissionInfo_Update(void *p);
BOOL TextWinTitle_Update(void *p);
BOOL PlaceNameCard_Update(void *p);
BOOL Obj021bb2b0_Update(void *p);
BOOL ImageCard_Update(void *p);
void SceneStage_RunCur(SceneStage *self);
void Lo0216b474_Update(Lo0216b474 *p);
void Obj021bbc68_Release(void *p);
void TextBox_Release(void *p);
void ImageCard_Dtor(void *p);
void PlaceNameCard_Dtor(void *p);
void Obj021b8ecc_Release(void *p);
void Obj021bacf4_Release(void *p);
void Obj021bb810_Release(void *p);

static inline VObj *NewObj2(u32 size, void *vt) {
    VObj *p = (VObj *)Heap_Alloc(size);
    if (p != NULL) {
        *(void **)p = Ov000Vt_021cac0c_vtbl;
        p->vfunc_14();
        *(void **)p = vt;
        p->vfunc_14();
    }
    return p;
}

void ListBuffer021cb940_Update(ListBuffer021cb940 *self) {
    MessageQueue021cb980 *c = (MessageQueue021cb980 *)self->unk_0c; // the owner queue
    switch (self->state) {
    case 0:
        self->state = 1;
    case 1: {
        Lo021cb798 *p;
        Obj0216ad04 *q;
        Lo0216b474 *r;
        LoTicker *tk;
        if (c->flag0) {
            break;
        }
        p = (Lo021cb798 *)Heap_Alloc(sizeof(Lo021cb798));
        if (p != NULL) {
            *(void **)p = Ov000Vt_021cac0c_vtbl;
            p->vfunc_14();
            *(void **)p = Lo021cb798_vtbl;
            p->vfunc_14();
            p->unk_9c = 0;
        }
        self->unk_58 = p;
        p = (Lo021cb798 *)Heap_Alloc(sizeof(Lo021cb798));
        if (p != NULL) {
            *(void **)p = Ov000Vt_021cac0c_vtbl;
            p->vfunc_14();
            *(void **)p = Lo021cb798_vtbl;
            p->vfunc_14();
            p->unk_9c = 1;
        }
        self->unk_5c = p;
        self->unk_60 = (Lo021cb7ec *)NewObj2(sizeof(Lo021cb7ec), Lo021cb7ec_vtbl);
        r = (Lo0216b474 *)Heap_Alloc(sizeof(Lo0216b474));
        if (r != NULL) {
            Lo0216b474_Init(r);
        }
        self->unk_68 = r;
        self->unk_64 = (Lo021cb744 *)NewObj2(sizeof(Lo021cb744), Lo021cb744_vtbl);
        self->unk_6c = (Lo021cb6f0 *)NewObj2(sizeof(Lo021cb6f0), Lo021cb6f0_vtbl);
        self->unk_70 = (Lo021cb840 *)NewObj2(sizeof(Lo021cb840), Lo021cb840_vtbl);
        self->unk_74 = (Lo021cb894 *)NewObj2(sizeof(Lo021cb894), Lo021cb894_vtbl);
        q = (Obj0216ad04 *)Heap_Alloc(sizeof(Obj0216ad04));
        if (q != NULL) {
            Obj0216ad04_Init(q);
        }
        self->unk_78 = q;
        tk = (LoTicker *)Heap_Alloc(sizeof(LoTicker));
        if (tk != NULL) {
            __cxa_vec_ctor(tk->res, 10, sizeof(LoTextHolder), (void (*)(void *))LoTextHolder_Init, (void (*)(void *))LoTextHolder_Dtor);
            LoTicker_Init(tk);
        }
        self->ticker = tk;
        Bss021ccd74_LoadModels();
        self->state = 2;
    }
    case 2:
        if (!MsgRes_BindGlobal()) {
            return;
        }
        LoTicker_InitTexts(self->ticker);
        self->unk_20 |= 2;
        self->state = 3;
        break;
    case 4:
        if (self->dialog == NULL && !self->win->unk_vf8c()) {
            HEAP_DELETE(SlideWin *, self->win, p->unk_vf04());
            self->state = 3;
        }
    case 10:
        if (self->unk_3c != NULL && !MissionCard_Update(self->unk_3c)) {
            HEAP_DELETE_FN(self->unk_3c, Obj021b8ecc_Release);
            if (self->state == 10) {
                self->state = 3;
            }
        }
    case 11:
        if (self->dialog != NULL && !self->dialog->vfunc_1c()) {
            HEAP_DELETE(Lo021cb0b8 *, self->dialog, p->vfunc_04());
            if (self->win != NULL) {
                self->win->OnSkip();
            }
            SceneStage_RunCur(&SceneCmd_Get()->stage);
            if (self->state == 11) {
                self->state = 3;
            }
        }
        break;
    case 8:
        if (self->unk_40 != NULL && !SceneCondCard_Update(self->unk_40)) {
            HEAP_DELETE_FN(self->unk_40, Obj021bacf4_Release);
            self->state = 3;
        }
        break;
    case 9:
        if (self->unk_44 != NULL && !MissionInfo_Update(self->unk_44)) {
            HEAP_DELETE(u8 *, (u8 *)self->unk_44, Obj021bbc68_Release(p); *(void **)(p + 4) = ResHandle_vtbl; ((VObj *)(p + 4))->vfunc_0c(); Heap_Free(p));
            self->state = 3;
        }
        break;
    case 5:
        if (!TextWinTitle_Update(self->unk_2c)) {
            HEAP_DELETE_FN(self->unk_2c, TextBox_Release);
            self->state = 3;
        }
        break;
    case 6:
        if (!self->unk_30->vfunc_1c()) {
            HEAP_DELETE(VObj *, self->unk_30, p->vfunc_04());
            self->state = 3;
        }
        break;
    case 7:
        if (!PlaceNameCard_Update(self->unk_38)) {
            HEAP_DELETE_FN(self->unk_38, PlaceNameCard_Dtor);
            self->state = 3;
        }
        break;
    }
    if (self->unk_4c != NULL && !Obj021bb2b0_Update(self->unk_4c)) {
        HEAP_DELETE_FN(self->unk_4c, Obj021bb810_Release);
    }
    if (self->unk_34 != NULL && !ImageCard_Update(self->unk_34)) {
        HEAP_DELETE_FN(self->unk_34, ImageCard_Dtor);
    }
    if (self->unk_50 != NULL && !Obj0216c954_Update(self->unk_50)) {
        HEAP_DELETE(Obj0216c954 *, self->unk_50, Obj0216c9b0_Release(p); Heap_Free(p));
    }
    if (self->unk_54 != NULL && !LoTimer_Update(self->unk_54)) {
        HEAP_DELETE(LoTimer *, self->unk_54, LoTimer_FreeModels(p); Heap_Free(p));
    }
    if (self->unk_58 != NULL) {
        self->unk_58->vfunc_0c();
    }
    if (self->unk_5c != NULL) {
        self->unk_5c->vfunc_0c();
    }
    if (self->unk_60 != NULL) {
        self->unk_60->vfunc_0c();
    }
    if (self->unk_64 != NULL) {
        self->unk_64->vfunc_0c();
    }
    if (self->unk_68 != NULL) {
        Lo0216b474_Update(self->unk_68);
    }
    if (self->unk_78 != NULL) {
        Obj0216ad04_Update(self->unk_78);
    }
    if (self->unk_6c != NULL) {
        self->unk_6c->vfunc_0c();
    }
    if (self->unk_70 != NULL) {
        self->unk_70->vfunc_0c();
    }
    if (self->unk_74 != NULL) {
        self->unk_74->vfunc_0c();
    }
    if (self->ticker != NULL) {
        LoTicker_Update(self->ticker);
    }
}

void LoTextHolder_Init(LoTextHolder *self) {
    self->count = 0;
    self->text = NULL;
    self->win = NULL;
}

}
