#include "ov006/ov006.h"

typedef struct ov006_Unk021d88f8 {
    u8 unk0[6];
    u16 unk6;
} ov006_Unk021d88f8;

typedef struct ov006_Ctx021d88f8 {
    u8 unk0[8];
    int *unk8;
} ov006_Ctx021d88f8;

extern "C" {

#pragma force_active on
int func_ov006_021d88f8(ov006_Ctx021d88f8 *ctx, ov006_Unk021d88f8 *item) {
    int *dst = ctx->unk8;
    if (item != NULL) {
        *dst = item->unk6;
    } else {
        *dst = -1;
    }
    return 0;
}
#pragma force_active reset

}
