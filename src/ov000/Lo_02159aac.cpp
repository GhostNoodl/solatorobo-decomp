#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

extern "C" {

extern void *data_0208cb84;
extern void *data_0208cc8c;
extern void *data_0208cb74;
extern void *data_0208cca0;
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_02041c5c(void *m, void *fn);
void func_02041c20(void *m, s32 a, void *b);
void *STD_CopyString(void *dst, void *src);
void func_ov000_02153c48(void *node, void *a, s32 b, s32 c, s32 d);
void func_ov000_0215a088(void *self);
void *func_ov000_02159998(void *self, u16 *msg, void *arr, u16 *cnt);

typedef s32 (*VFn9aac)(void *);


#define LO_MODEL_NEW(out, NAME, ARC)                 \
    do {                                             \
        u8 *m_ = (u8 *)Heap_Alloc(0x160);         \
        if (m_) {                                    \
            void *arc_;                              \
            void *name_;                             \
            name_ = NAME;                            \
            arc_ = ARC;                              \
            func_02041218((struct PlttRes *)(m_ + 0x88));                \
            func_02041440(m_, name_, 0);             \
            STD_CopyString(m_ + 0x2c, arc_);          \
        }                                            \
        out = m_;                                    \
    } while (0)

static inline BOOL LoadModel9aac(Lo021cb5a8 *self) {
    if (self->model) {
        return TRUE;
    }
    if (LBIT(self, 0xc).b6 ? TRUE : FALSE) {
        LO_MODEL_NEW((u8 *)self->model, data_0208cb84, data_0208cc8c);
    } else {
        LO_MODEL_NEW((u8 *)self->model, data_0208cb74, data_0208cca0);
    }
    {
        void *a = func_02035d5c((u8 *)self->model + 0x2c);
        void *b = func_02034d88(a, (u8 *)self->model + 0x4c);
        func_020417e0((u8 *)self->model, b);
    }
    LFLD(u32, self->model, 0x6c) |= 2;
    func_02041d9c((u8 *)self->model, 0, 7);
    return TRUE;
}

void func_ov000_02159aac(Lo021cb5a8 *self) {
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
        func_ov000_02153c48(n, ((void *)self->font), 1, 0, 0);
        w = LFLD(s32, ((u8 *)n->label), 0x44);
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
        w2 = LFLD(s32, ((u8 *)n->label), 0x44) + 0x14;
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
        func_02041d9c(self->model, 0, 8);
        func_02041d9c(self->model, 0, 2);
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
    LBIT(self, 0xc).b0 = 1;
}

}
