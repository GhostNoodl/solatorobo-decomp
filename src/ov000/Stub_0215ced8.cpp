#include "ov000/VObj.h"

struct Flag0c { u32 b0 : 1; };

static inline void Flag0c_Set(Flag0c *f) { f->b0 = 1; }

extern "C" {

void func_ov000_0215c744();

void func_ov000_0215ced8(void) {
    func_ov000_0215c744();
}

void func_ov000_0215cee4(void *self) {
    Flag0c_Set((Flag0c *)((u8 *)self + 0xc));
}

}
