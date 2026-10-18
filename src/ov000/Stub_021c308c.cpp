#include "Main/Res/StageRes.h"

typedef struct {
    u8 unk_00[4];
    u16 unk_04;
    u16 unk_06;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0a;
} Sub021c308c;

typedef struct {
    u8 pad_00[4];
    s32 unk_04;
    s32 unk_08;
} Info021c308c;

typedef struct {
    u8 pad_00[0x30];
    s32 unk_30;
    s32 unk_34;
    u8 pad_38[0x10];
    Sub021c308c unk_48;
} Obj021c308c;

extern "C" {

Info021c308c *func_0206eed0(u32 id);
u16 func_0206f788(u32 v);
u16 func_02059688(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, u32 id);
u32 func_0205975c(DataRes *res, u32 idx);
SaveEntry *func_0205976c(DataRes *res, u32 idx);

void func_ov000_021c308c(Obj021c308c *self, u32 id) {
    Info021c308c *info = func_0206eed0(id);
    Sub021c308c *sub;
    s32 i;
    SaveLayout *layout;
    SaveEntry *entries;
    self->unk_30 = info->unk_04;
    self->unk_34 = info->unk_08;
    sub = &self->unk_48;
    sub->unk_04 = id;
    sub->unk_06 = func_0206f788(id);
    sub->unk_09 = 4;
    sub->unk_08 = 0;
    for (i = 0; i < sub->unk_09; i++) {
        if (sub->unk_06 & (1 << i)) {
            sub->unk_08++;
        }
    }
    layout = (SaveLayout *)data_02fe152c->data;
    entries = func_0205976c(data_02fe152c, 11);
    func_0205975c(data_02fe152c, 11);
    sub->unk_0a = func_02059688(data_02fe152c, &layout->blocks[11], entries, 0x101, id) != 0;
}

}
