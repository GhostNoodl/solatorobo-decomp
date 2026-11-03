#include "ov000/LoCommon.h"
#include "Main/Res/StageVars.h"
#include "ov000/MsgEntry.h"

extern "C" {

extern void *gDataRes;
void Obj0215eab4_Draw(void *p);
void DataRes_WriteEntry(void *a, s32 b, s32 c, u16 d, s32 e);

void func_ov000_0214dc20(MsgEntryEx *self, s32 *msg) {
    if (msg[0] != 0x25) {
        return;
    }
    switch (msg[1]) {
    case 0:
        self->vals[0] = msg[2];
        if (msg[2] != data_02fe1534.unk_46) {
            self->unk_24 = 0xe;
            return;
        }
        DataRes_WriteEntry(gDataRes, 1, 0x101, self->id, 0);
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
