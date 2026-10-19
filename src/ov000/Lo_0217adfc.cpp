#include "ov000/LoCommon.h"

typedef struct {
    u8 pad[0xa8];
    VObj *objs[4];
} Arr0217adfc;

extern "C" {
void func_ov000_0214b724(void *p);

void func_ov000_0217adfc(u8 *self) {
    s32 i;
    LO_FREE_V(self, 0x60);
    LO_FREE_V(self, 0x5c);
    LO_FREE_V(self, 0x64);
    {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (LFLD(void *, self, 0x6c) != NULL) {
            void *p = LFLD(void *, self, 0x6c);
            if (p != NULL) {
                func_ov000_0214b724(p);
                func_0203de1c(p);
            }
            LFLD(void *, self, 0x6c) = NULL;
        }
        LO_HEAP_POP(saved);
    }
    LO_FREE_V(self, 0x74);
    LO_FREE_V(self, 0x78);
    LO_FREE_V(self, 0x7c);
    LO_FREE_V(self, 0x80);
    LO_FREE_V(self, 0x84);
    LO_FREE_V(self, 0x88);
    LO_FREE_V(self, 0x8c);
    LO_FREE_V(self, 0x90);
    LO_FREE_V(self, 0x94);
    LO_FREE_V(self, 0x98);
    LO_FREE_V(self, 0x9c);
    LFLD(u8, self, 0x71) = 0;
    LO_FREE_M(self, 0xa0);
    for (i = 0; i < 4; i++) {
        u32 saved;
        LO_HEAP_PUSH(saved);
        if (((Arr0217adfc *)self)->objs[i] != NULL) {
            VObj *p_ = ((Arr0217adfc *)self)->objs[i];
            if (p_ != NULL) {
                p_->vfunc_04();
            }
            ((Arr0217adfc *)self)->objs[(u32)i] = NULL;
        }
        LO_HEAP_POP(saved);
    }
    LO_FREE_V(self, 0x3c);
}
}
