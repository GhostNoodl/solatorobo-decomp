#include "ov000/LoCommon.h"

struct LoDE { s32 d; s32 *e; };
extern "C" {

u32 Rand_GetGlobal(void);
void func_ov000_021c216c(void *p);
void func_ov000_0216c954(void *self, u16 a, s32 b);

struct Obj0216c9b0 {
    u8 unk_00[0x10];
    void *unk_10;
};

void Obj0216c9b0_Release(Obj0216c9b0 *self) {
    u32 saved;
    void *p;
    LO_HEAP_PUSH(saved);
    p = self->unk_10;
    if (p) {
        if (p) {
            func_ov000_021c216c(p);
            Heap_Free(p);
        }
        self->unk_10 = NULL;
    }
    LO_HEAP_POP(saved);
    LO_FREE_M(self, 0xc);
    func_ov000_0216c954(self, 0, 0);
}

}
