#include "ov006/ov006.h"
#include "ov006/Window.h"

extern "C" {

// The decide callback of ov006_ShowListWin's list: it stores the chosen item's id (-1: none)
// where the list's owner points.
#pragma force_active on
BOOL ov006_ListCb_StoreId2(UiList *self, UiListItem *item) {
    s32 *dst = (s32 *)self->owner;
    if (item != NULL) {
        *dst = item->id;
    } else {
        *dst = -1;
    }
    return FALSE;
}
#pragma force_active reset

}
