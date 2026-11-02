#include "ov000/MessageQueue.h"
#include "ov000/ObjLayouts.h"
#include "ov000/LoTimer.h"
#include "ov000/LoTicker.h"
#include "ov000/SceneCmd.h"
#include "ov000/HeapScope.h"
#include "Main/Gfx/SlideWin.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

extern u8 data_0208b318[];
extern u8 data_ov000_021cac0c[];
extern u8 data_ov000_021cb798[];
extern u8 data_ov000_021cb7ec[];
extern u8 data_ov000_021cb744[];
extern u8 data_ov000_021cb6f0[];
extern u8 data_ov000_021cb840[];
extern u8 data_ov000_021cb894[];
void *Heap_Alloc(u32 size);
void func_ov000_0216b474(Lo0216b474 *p);
void func_ov000_0216ad04(void *p);
void __cxa_vec_ctor(void *arr, int n, u32 size, void (*ctor)(void *), void (*dtor)(void *));
void func_ov000_021bce90(void);
BOOL func_0204c120(void);
BOOL func_ov000_021b9010(void *p);
BOOL func_ov000_021ba92c(void *p);
BOOL func_ov000_021bb8dc(void *p);
BOOL func_0204fd60(void *p);
BOOL func_ov000_021b8994(void *p);
BOOL func_ov000_021bb33c(void *p);
BOOL func_ov000_021b8284(void *p);
BOOL func_ov000_0216ca70(void *p);
void func_ov000_02182524(SceneStage *self);
void func_ov000_0216b550(Lo0216b474 *p);
void func_ov000_0216adf8(void *p);
void Obj021bbc68_Release(void *p);
void func_020507d8(void *p);
void Obj0216c9b0_Release(void *p);
void func_ov000_021b8800(void *p);
void func_ov000_021b88d8(void *p);
void Obj021b8ecc_Release(void *p);
void Obj021bacf4_Release(void *p);
void func_ov000_021bb840(void *p);

typedef struct {
    u32 b0 : 1;
} Bit0;


static inline VObj *NewObj2(u32 size, void *vt) {
    VObj *p = (VObj *)Heap_Alloc(size);
    if (p != NULL) {
        *(void **)p = data_ov000_021cac0c;
        p->vfunc_14();
        *(void **)p = vt;
        p->vfunc_14();
    }
    return p;
}

void func_ov000_02170a58(ListBuffer021cb940 *self) {
    u8 *c = (u8 *)self->unk_0c;
    switch (self->state) {
    case 0:
        self->state = 1;
    case 1: {
        Lo021cb798 *p;
        u8 *q;
        Lo0216b474 *r;
        LoTicker *tk;
        if (LFLD(Bit0, c, 0x114).b0) {
            break;
        }
        p = (Lo021cb798 *)Heap_Alloc(sizeof(Lo021cb798));
        if (p != NULL) {
            *(void **)p = data_ov000_021cac0c;
            p->vfunc_14();
            *(void **)p = data_ov000_021cb798;
            p->vfunc_14();
            p->unk_9c = 0;
        }
        self->unk_58 = p;
        p = (Lo021cb798 *)Heap_Alloc(sizeof(Lo021cb798));
        if (p != NULL) {
            *(void **)p = data_ov000_021cac0c;
            p->vfunc_14();
            *(void **)p = data_ov000_021cb798;
            p->vfunc_14();
            p->unk_9c = 1;
        }
        self->unk_5c = p;
        self->unk_60 = (Lo021cb7ec *)NewObj2(sizeof(Lo021cb7ec), data_ov000_021cb7ec);
        r = (Lo0216b474 *)Heap_Alloc(sizeof(Lo0216b474));
        if (r != NULL) {
            func_ov000_0216b474(r);
        }
        self->unk_68 = r;
        self->unk_64 = (Lo021cb744 *)NewObj2(sizeof(Lo021cb744), data_ov000_021cb744);
        self->unk_6c = (Lo021cb6f0 *)NewObj2(sizeof(Lo021cb6f0), data_ov000_021cb6f0);
        self->unk_70 = (Lo021cb840 *)NewObj2(sizeof(Lo021cb840), data_ov000_021cb840);
        self->unk_74 = (Lo021cb894 *)NewObj2(sizeof(Lo021cb894), data_ov000_021cb894);
        q = (u8 *)Heap_Alloc(0x20);
        if (q != NULL) {
            func_ov000_0216ad04(q);
        }
        self->unk_78 = q;
        tk = (LoTicker *)Heap_Alloc(sizeof(LoTicker));
        if (tk != NULL) {
            __cxa_vec_ctor(tk->res, 10, sizeof(LoTextHolder), (void (*)(void *))func_ov000_0217125c, (void (*)(void *))func_ov000_0217006c);
            func_ov000_0216bf30(tk);
        }
        self->ticker = tk;
        func_ov000_021bce90();
        self->state = 2;
    }
    case 2:
        if (!func_0204c120()) {
            return;
        }
        func_ov000_0216bbec(self->ticker);
        self->unk_20 |= 2;
        self->state = 3;
        break;
    case 4:
        if (self->dialog == NULL && !self->win->unk_vf8c()) {
            HEAP_DELETE(SlideWin *, self->win, p->unk_vf04());
            self->state = 3;
        }
    case 10:
        if (self->unk_3c != NULL && !func_ov000_021b9010(self->unk_3c)) {
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
            func_ov000_02182524(&SceneCmd_Get()->stage);
            if (self->state == 11) {
                self->state = 3;
            }
        }
        break;
    case 8:
        if (self->unk_40 != NULL && !func_ov000_021ba92c(self->unk_40)) {
            HEAP_DELETE_FN(self->unk_40, Obj021bacf4_Release);
            self->state = 3;
        }
        break;
    case 9:
        if (self->unk_44 != NULL && !func_ov000_021bb8dc(self->unk_44)) {
            HEAP_DELETE(u8 *, (u8 *)self->unk_44, Obj021bbc68_Release(p); *(void **)(p + 4) = data_0208b318; ((VObj *)(p + 4))->vfunc_0c(); Heap_Free(p));
            self->state = 3;
        }
        break;
    case 5:
        if (!func_0204fd60(self->unk_2c)) {
            HEAP_DELETE_FN(self->unk_2c, func_020507d8);
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
        if (!func_ov000_021b8994(self->unk_38)) {
            HEAP_DELETE_FN(self->unk_38, func_ov000_021b88d8);
            self->state = 3;
        }
        break;
    }
    if (self->unk_4c != NULL && !func_ov000_021bb33c(self->unk_4c)) {
        HEAP_DELETE_FN(self->unk_4c, func_ov000_021bb840);
    }
    if (self->unk_34 != NULL && !func_ov000_021b8284(self->unk_34)) {
        HEAP_DELETE_FN(self->unk_34, func_ov000_021b8800);
    }
    if (self->unk_50 != NULL && !func_ov000_0216ca70(self->unk_50)) {
        HEAP_DELETE_FN(self->unk_50, Obj0216c9b0_Release);
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
        func_ov000_0216b550(self->unk_68);
    }
    if (self->unk_78 != NULL) {
        func_ov000_0216adf8(self->unk_78);
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
        func_ov000_0216be58(self->ticker);
    }
}

void func_ov000_0217125c(LoTextHolder *self) {
    self->count = 0;
    self->text = NULL;
    self->win = NULL;
}

}
