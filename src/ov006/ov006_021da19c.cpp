#include "ov006/Tasks.h"

typedef struct ov006_Item021da19c {
    u8 unk0[6];
    u16 unk6;
} ov006_Item021da19c;

typedef struct ov006_Ctx021da19c {
    u8 unk0[8];
    int *unk8;
} ov006_Ctx021da19c;

extern "C" {

#pragma force_active on
BOOL func_ov006_021da19c(ov006_Ctx021da19c *ctx, ov006_Item021da19c *item) {
    int *dst = ctx->unk8;
    BOOL r = FALSE;
    if (item != NULL) {
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        *dst = item->unk6;
    } else {
        func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        r = TRUE;
    }
    return r;
}
#pragma force_active reset

}
