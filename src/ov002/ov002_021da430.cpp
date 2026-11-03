#include "ov002/ov002.h"

extern "C" {



void Obj021efe7c_Release(Obj021efe7c *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->unk_08);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(self->board);
    HEAP_POP(saved);
    ResMgr_ReleaseByName(gResMgr, data_ov002_021efdf6, 7, 0);
    if (self->unk_10) {
        EffectMgr_RestoreList(gEffectMgr);
        if (gSceneCmd != NULL) {
            *(u8 **)gEffectMgr = (u8 *)gSceneCmd + 8;
        }
    }
}

}
