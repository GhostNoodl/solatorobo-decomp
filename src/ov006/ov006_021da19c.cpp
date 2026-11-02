#include "ov006/Tasks.h"

extern "C" {

#pragma force_active on
// The decide callback of ov006_Task021ec040_BuildShopList's list: it stores the chosen item's id where the
// list's owner points and plays a sound; with no item it returns TRUE.
BOOL ov006_ListCb_StoreIdOrCancel(UiList *self, UiListItem *item) {
    s32 *dst = (s32 *)self->owner;
    BOOL r = FALSE;
    if (item != NULL) {
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        *dst = item->id;
    } else {
        func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        r = TRUE;
    }
    return r;
}
#pragma force_active reset

}
