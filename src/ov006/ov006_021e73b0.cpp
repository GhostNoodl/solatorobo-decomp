#include "ov006/ov006.h"

typedef struct ov006_Unk021e73b0 {
    u8 unk0[4];
    u64 flags;
    u8 unkC[7];
    u8 unk13;
} ov006_Unk021e73b0;

typedef struct ov006_Obj021e73b0 {
    u8 unk0[0x40];
    ov006_Unk021e73b0 *unk40;
} ov006_Obj021e73b0;

extern "C" {

void func_ov000_02198360(ov006_Unk021e73b0 *a, int b, int c);
void func_ov000_0218d7e8(ov006_Obj021e73b0 *a, u8 b);

void func_ov006_021e73b0(ov006_Obj021e73b0 *self) {
    ov006_Unk021e73b0 *p = self->unk40;
    if (p->flags & 2) {
        func_ov000_02198360(p, 1, 0);
    } else if (p->flags & 0x40000) {
        func_ov000_02198360(p, 0x12, 1);
    } else if (p->flags & 4) {
        func_ov000_02198360(p, 2, 0);
    }
    func_ov000_0218d7e8(self, self->unk40->unk13);
}

}
