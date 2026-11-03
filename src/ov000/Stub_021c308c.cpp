#include "Main/Res/StageRes.h"
#include "ov000/ListRow.h"

typedef struct {
    u8 pad_00[4];
    char *unk_04;
    char *unk_08;
} Info021c308c;

extern "C" {

Info021c308c *func_0206eed0(u32 id);
u16 func_0206f788(u32 v);
u16 DataRes_ReadBitsById_02059688(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, u32 id);
u32 DataRes_GetCount(DataRes *res, u32 idx);
SaveEntry *DataRes_GetTable(DataRes *res, u32 idx);

void func_ov000_021c308c(ListRow021cca70 *self, u32 id) {
    Info021c308c *info = func_0206eed0(id);
    ListRowItem *sub;
    s32 i;
    SaveLayout *layout;
    SaveEntry *entries;
    self->arc = info->unk_04;
    self->name = info->unk_08;
    sub = &self->item;
    sub->id = id;
    sub->mask = func_0206f788(id);
    sub->n = 4;
    sub->count = 0;
    for (i = 0; i < sub->n; i++) {
        if (sub->mask & (1 << i)) {
            sub->count++;
        }
    }
    layout = (SaveLayout *)gDataRes->data;
    entries = DataRes_GetTable(gDataRes, 11);
    DataRes_GetCount(gDataRes, 11);
    sub->unk_0a = DataRes_ReadBitsById_02059688(gDataRes, &layout->blocks[11], entries, 0x101, id) != 0;
}

}
