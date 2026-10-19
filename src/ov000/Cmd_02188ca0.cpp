#include "ov000/CmdQueue.h"

typedef struct {
    u8 c[3];
} Id3;

typedef struct {
    u8 unk_00[0x4];
    CmdQueue *unk_04;
} Data021ccd50;

typedef struct {
    u16 flags;
} Obj02097e48;

extern "C" {
extern Data021ccd50 data_ov000_021ccd50;
extern Obj02097e48 *data_02097e48;

void func_ov000_02188ca0(Id3 *id, s32 arg) {
    data_02097e48->flags |= 2;
    CmdQueue_Push(data_ov000_021ccd50.unk_04, 9, arg);
    if (id != NULL) {
        *(Id3 *)((u8 *)data_ov000_021ccd50.unk_04 + 0xcd) = *id;
    }
}
}
