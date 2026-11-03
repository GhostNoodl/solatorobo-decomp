#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021cf314(int idx, u32 arg) {
    BOOL ok;
    u16 i;
    u32 count;
    u8 *base;
    void *tbl;
    ok = TRUE;
    count = DataRes_GetCount(gDataRes, idx);
    base = gDataRes->data + 0x10 + idx * 0x20;
    tbl = DataRes_GetTable(gDataRes, idx);
    for (i = 0; i < count; i++) {
        if (DataRes_ReadBitsAt_02059544(gDataRes, base, tbl, arg, i)) {
            ok = FALSE;
            break;
        }
    }
    return ok;
}

}
