#include "ov000/VObj.h"
#include "ov000/CmdQueue.h"

extern "C" {

void func_ov000_02181f54(void *p, s32 a, s32 b, s32 c, u16 d, u16 e);

void func_ov000_021836d0(CmdQueue *self, s32 a, s32 b, s32 c, u16 d, u16 e) {
    CmdQueue_Push(self, 6, 0);
    func_ov000_02181f54((u8 *)self + 0xac, a, b, c, d, e);
}

}
