#include "ov000/VObj.h"
#include "Main/Sys/SysState.h"
#include "Main/Gfx/Model.h"
#include "ov000/HeapScope.h"
#include "ov000/ListRow.h"

extern "C" {

extern u8 data_ov000_021cc9bc[];
extern u8 data_ov000_021cc9d3[];
extern u8 data_ov000_021cc9dc[];
void ResMgr_ReleaseArchive(void *a, void *b, s32 c);

void ListRow021cca70_Init(ListRow021cca70 *self) {
    self->width = 0xc8;
    self->height = 0x8c;
    self->arc = 0;
    self->name = 0;
    self->unk_38 = 0;
    self->unk_3c = 0;
    self->unk_40 = data_ov000_021cc9bc;
    self->unk_44 = 0;
    self->item.id = 0;
    self->item.mask = 0;
    self->item.count = 0;
    self->item.n = 0;
    self->item.unk_0a = 0;
    self->alpha = 0;
    self->scale = 0x99a;
    self->ox = 0;
    self->oy = 0;
    self->partZ = 0;
    self->unk_68 = 0;
    self->unk_6c = 0;
    self->unk_70 = 0;
    self->unk_74 = 0;
    self->unk_78 = 0;
}

void ListRow021cca70_Release(ListRow021cca70 *self) {
    HEAP_DELETE_MODEL(self->unk_38);
    HEAP_DELETE_MODEL(self->unk_3c);
    if (self->unk_68 != 0) {
        ResMgr_ReleaseArchive(self->arc, self->name, 2);
        ResMgr_ReleaseArchive(data_ov000_021cc9d3, data_ov000_021cc9dc, 2);
    }
    self->unk_6c = 0;
    self->alpha = 0;
    self->scale = 0x99a;
}

}
