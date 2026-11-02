#include "ov002/ov002.h"

extern "C" {



void Obj021efe7c_Release(Obj021efe7c *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 8, VObj *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 4, VObj *));
    HEAP_POP(saved);
    ResMgr_ReleaseByName(data_02097cdc, data_ov002_021efdf6, 7, 0);
    if (self->unk_10) {
        EffectMgr_RestoreList(data_0214a420);
        if (data_ov000_021ccd54 != NULL) {
            *(u8 **)data_0214a420 = (u8 *)data_ov000_021ccd54 + 8;
        }
    }
}

}
