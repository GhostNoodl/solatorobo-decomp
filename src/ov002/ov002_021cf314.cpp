#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021cf314(int idx, u32 arg) {
    BOOL ok;
    u16 i;
    u32 count;
    u8 *base;
    void *tbl;
    ok = TRUE;
    count = DataRes_GetCount(data_02fe152c, idx);
    base = data_02fe152c->data + 0x10 + idx * 0x20;
    tbl = DataRes_GetTable(data_02fe152c, idx);
    for (i = 0; i < count; i++) {
        if (DataRes_ReadBitsAt_02059544(data_02fe152c, base, tbl, arg, i)) {
            ok = FALSE;
            break;
        }
    }
    return ok;
}

}
