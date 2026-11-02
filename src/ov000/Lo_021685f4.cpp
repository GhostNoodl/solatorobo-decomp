#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/Model.h"
#include "Main/Res/ResArc.h"

extern "C" {

extern const char *data_0208cc94;
extern const char *data_0208cc88;

void func_ov000_021685f4(Lo021cb894 *self) {
    void *res;
    Model *m;
    self->unk_28 = 0;
    self->unk_30 = 0xc000;
    self->unk_50 = 0;
    self->unk_54 = 0;
    self->unk_0c |= 0x2c0;
    self->unk_58 = 1;
    self->unk_74 = 0;
    self->unk_78 = 0;
    self->unk_7c = -0x2000;
    res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
    m = (Model *)Heap_Alloc(sizeof(Model));
    if (m) {
        const char *nm = data_0208cc88;
        func_02041218(&m->pltt);
        func_02041440(m, nm, 0);
    }
    self->unk_9c = (Model *)(m);
    func_020417e0(m, res);
    self->unk_9c->flags |= 2;
    self->unk_9c->flags |= 0x200000;
    self->unk_9c->flags |= 0x80000;
    func_02041d9c(self->unk_9c, 0, 0x1a);
    func_02041d9c(self->unk_9c, 0, 0x1b);
    func_02041d9c(self->unk_9c, 0, 0x1c);
}

}
