#include "ov000/LoCommon.h"
#include "ov000/MsgEntry.h"

extern "C" {

extern u8 data_02fe1534[];
extern void *data_02fe152c;
void Obj0215eab4_Draw(void *p);
void DataRes_WriteEntry(void *a, s32 b, s32 c, u16 d, s32 e);

void func_ov000_0214dc20(MsgEntryEx *self, s32 *msg) {
    if (msg[0] != 0x25) {
        return;
    }
    switch (msg[1]) {
    case 0:
        self->vals[0] = msg[2];
        if (msg[2] != LFLD(u16, data_02fe1534, 0x46)) {
            self->unk_24 = 0xe;
            return;
        }
        DataRes_WriteEntry(data_02fe152c, 1, 0x101, self->id, 0);
        break;
    case 1:
        self->vals[1] = msg[2];
        break;
    case 2:
        self->vals[2] = msg[2];
        break;
    case 3:
        self->vals[3] = msg[2];
        break;
    }
}

}
