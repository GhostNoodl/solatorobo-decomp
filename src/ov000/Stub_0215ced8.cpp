#include "ov000/ObjLayouts.h"

extern "C" {

void func_ov000_0215c744(VObj *self, u32 flags, u16 id);

void func_ov000_0215ced8(VObj *self, u32 flags, u16 id) {
    func_ov000_0215c744(self, flags, id);
}

void func_ov000_0215cee4(Lo021cad50 *self) {
    self->busy = 1;
}

}
