#include "ov000/CmdQueue.h"

typedef struct {
    u16 b0 : 3;
    u16 flag : 1;
    u16 b4 : 12;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 pad_0a[0x66];
    u16 unk_70;
    u16 unk_72;
    u16 unk_74;
} Obj02097e48;

extern "C" {

extern void *data_02097e4c;
extern Obj02097e48 *data_02097e48;
void func_02049564(void *p, s32 a, s32 b);

void func_ov000_02187588(CmdQueue *self) {
    func_02049564(data_02097e4c, 1, 1);
    {
        Obj02097e48 *p = data_02097e48;
        if (p->flag) {
            p->unk_06 = 0x8000;
            p->unk_08 = 0x1e;
            p->unk_02 = 0;
        }
    }
    {
        Obj02097e48 *p = data_02097e48;
        p->unk_74 = 0x8000;
        p->unk_70 = 0;
    }
    CmdQueue_Push(self, 0x26, 2);
    CmdQueue_Push(self, 0x23, 0);
}

}
