#include "ov000/VObj.h"
#include "ov000/CmdQueue.h"

static inline void CmdQueue_Push2(CmdQueue *q, s32 kind, s32 lo, u16 hi) {
    q->kinds[q->index] = kind;
    q->args[q->index] = lo | (hi << 16);
    if (++q->index >= 0x10) {
        q->index = 0;
    }
}

extern "C" {

void func_ov000_02188140(CmdQueue *self, s32 a, s32 b, s32 c) {
    u16 v;
    if (a == 0) {
        a = 1;
    }
    v = (b & 0xff) | ((c & 0xf) << 8);
    CmdQueue_Push2(self, 0x27, a, v);
}

}
