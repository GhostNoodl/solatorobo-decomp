#include "ov000/CmdQueue.h"

typedef struct {
    u8 pad_00[0x70];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

extern "C" {

extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
void func_02049564(void *p, s32 a, s32 b);

void func_ov000_0218781c(CmdQueue *self, s32 arg) {
    func_02049564(data_02097e4c, 1, 1);
    {
        Obj02097e48 *p = data_02097e48;
        p->unk_74 = 0x8000;
        p->unk_70 = 0;
    }
    CmdQueue_Push(self, 0x26, 1);
    CmdQueue_Push(self, 0x24, arg);
}
}
