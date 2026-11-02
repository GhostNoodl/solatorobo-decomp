#include "ov000/LoCommon.h"
#include "ov000/SceneRes.h"
#include "ov000/ObjLayouts.h"
#include "ov000/MsgEntry.h"
#include "ov000/HeapScope.h"

extern "C" {

void func_ov000_02150cb0(Lo021ca9c4 *self) {
    self->text[0].unk_vf08();
    self->text[1].unk_vf08();
    self->text[2].unk_vf08();
    self->text[3].unk_vf08();
    self->text[4].unk_vf08();
    self->text[5].unk_vf08();
    HEAP_DELETE(MsgEntryEx *, self->unk_54, func_ov000_02153fd8(p); Heap_Free(p));
    HEAP_DELETE_VOBJ(self->unk_58);
    HEAP_DELETE_VOBJ(self->unk_4c);
    HEAP_DELETE_VOBJ(self->unk_50);
    HEAP_DELETE_MODEL(self->unk_48);
    HEAP_DELETE_MODEL(self->unk_44);
    HEAP_DELETE_VOBJ(self->unk_3c);
    if (self->unk_42 == 0xffff) {
        LO_FREE_V(&data_ov000_021ccd24, 8);
    }
}

}
