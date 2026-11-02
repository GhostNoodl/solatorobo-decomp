#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/Model.h"
#include "Main/Res/ResArc.h"

extern "C" {
extern char data_0214b105[];
extern const char *data_0208cb7c;
extern const char *data_0208cc94;
extern const char *data_0208cc88;
extern u8 data_ov000_021c9ab6[];
void func_ov000_0215fdfc(void *self, s32 a, const void *b);

void func_ov000_021699f0(Lo021cb798 *self) {
    void *res;
    Model *m;
    switch (self->unk_9c) {
    case 0:
        self->unk_54 = 7;
        self->unk_38 = 0;
        self->unk_3c = 0x20;
        self->unk_40 = 0;
        self->unk_74 = 0x2d;
        self->unk_78 = 0xb6;
        self->unk_7c = -0x199a;
        self->unk_a8 = 0xff;
        break;
    case 1:
        self->unk_54 = 7;
        self->unk_38 = 0;
        self->unk_3c = -0x10;
        self->unk_40 = 0;
        self->unk_74 = 0x2a;
        self->unk_78 = 3;
        self->unk_7c = -0x199a;
        self->unk_a8 = 1;
        func_ov000_0215fdfc(self, 2, data_ov000_021c9ab6);
        break;
    }
    res = func_02034d88(func_02035d5c(data_0214b105), data_0208cb7c);
    m = (Model *)Heap_Alloc(sizeof(Model));
    if (m) {
        const char *nm = data_0208cb7c;
        func_02041218(&m->pltt);
        func_02041440(m, nm, 0);
    }
    self->unk_a4 = m;
    func_020417e0(m, res);
    self->unk_a4->flags |= 2;
    self->unk_a4->flags |= 0x200000;
    self->unk_a4->flags |= 0x80000;
    func_02041d9c(self->unk_a4, 0, (u16)self->unk_9c);
    if (self->unk_a8 != 0xff) {
        Model *m2;
        void *res2;
        res2 = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
        m2 = (Model *)Heap_Alloc(sizeof(Model));
        if (m2) {
            const char *nm = data_0208cc88;
            func_02041218(&m2->pltt);
            func_02041440(m2, nm, 0);
        }
        self->unk_a0 = m2;
        func_020417e0(m2, res2);
        self->unk_a0->flags |= 2;
        self->unk_a0->flags |= 0x200000;
        self->unk_a0->flags |= 0x80000;
        func_02041d9c(self->unk_a0, 0, self->unk_a8);
    }
    self->unk_28 = 2;
    self->unk_30 = 0xc000;
    self->unk_4c = 0x400;
    self->unk_0c |= 0x1a0;
}
}
