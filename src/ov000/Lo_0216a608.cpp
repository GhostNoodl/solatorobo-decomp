#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/Model.h"
#include "Main/Res/ResArc.h"

extern "C" {

extern char data_0214b105[];
extern const char *data_0208cb7c;
extern const char *data_0208cc94;
extern const char *data_0208cc88;
void func_ov000_0215fdfc(ObjBase021cac0c_021cb6f0 *self, s32 a, const void *b);
extern u8 data_ov000_021c9b04[];
extern u8 data_ov000_021c9b0a[];

void func_ov000_0216a608(Lo021cb744 *self) {
    void *res = func_02034d88(func_02035d5c(data_0214b105), data_0208cb7c);
    Model *m = (Model *)Heap_Alloc(sizeof(Model));
    if (m) {
        const char *nm = data_0208cb7c;
        func_02041218(&m->pltt);
        func_02041440(m, nm, 0);
    }
    self->unk_9c = m;
    func_020417e0(m, res);
    self->unk_9c->flags |= 2;
    self->unk_9c->flags |= 0x200000;
    self->unk_9c->flags |= 0x80000;
    func_02041d9c(self->unk_9c, 0, 2);
    {
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
    func_02041d9c(self->unk_a0, 0, 0x21);
    }
    self->unk_28 = 2;
    self->unk_30 = 0xc000;
    self->unk_0c |= 0x1a0;
    self->unk_50 = 0x30;
    self->unk_54 = 6;
    self->unk_58 = 1;
    self->unk_38 = 0;
    self->unk_3c = 0x20;
    self->unk_40 = 0;
    self->unk_74 = 0x2d;
    self->unk_78 = 0xae;
    self->unk_7c = 0xffffe666;
    func_ov000_0215fdfc(self, 1, data_ov000_021c9b04);
    func_ov000_0215fdfc(self, 2, data_ov000_021c9b0a);
}

}
