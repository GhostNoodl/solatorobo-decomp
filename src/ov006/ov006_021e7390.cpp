#include "ov006/ov006.h"

typedef struct ov006_Unk021e7390 {
    u8 unk0[4];
    u64 flags;
} ov006_Unk021e7390;

typedef struct ov006_Obj021e7390 {
    u8 unk0[0x40];
    ov006_Unk021e7390 *unk40;
} ov006_Obj021e7390;

extern "C" {

#pragma force_active on
void func_ov006_021e7390(ov006_Obj021e7390 *self) {
    ov006_Unk021e7390 *p = self->unk40;
    if (p != NULL) {
        p->flags |= 2;
    }
}
#pragma force_active reset

}
