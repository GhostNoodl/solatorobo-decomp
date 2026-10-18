#include "ov000/VObj.h"
#include "Main/Res/StageRes.h"

typedef struct {
    u8 unk_00[4];
    u16 unk_04;
    u16 unk_06;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0a;
} Obj021c2208;

extern "C" {

u16 func_0206f788(u32 v);
u16 func_02059688(DataRes *res, SaveBlock *block, SaveEntry *entries, int packed, u32 id);
u32 func_0205975c(DataRes *res, u32 idx);
SaveEntry *func_0205976c(DataRes *res, u32 idx);

void func_ov000_021c2208(Obj021c2208 *self) {
    self->unk_04 = 0;
    self->unk_06 = 0;
    self->unk_08 = 0;
    self->unk_09 = 0;
    self->unk_0a = 0;
}

void func_ov000_021c2224(Obj021c2208 *self, u32 id) {
    s32 i;
    SaveLayout *layout;
    SaveEntry *entries;
    self->unk_04 = id;
    self->unk_06 = func_0206f788(id);
    self->unk_09 = 4;
    self->unk_08 = 0;
    for (i = 0; i < self->unk_09; i++) {
        if (self->unk_06 & (1 << i)) {
            self->unk_08++;
        }
    }
    layout = (SaveLayout *)data_02fe152c->data;
    entries = func_0205976c(data_02fe152c, 11);
    func_0205975c(data_02fe152c, 11);
    self->unk_0a = func_02059688(data_02fe152c, &layout->blocks[11], entries, 0x101, id) != 0;
}

}
