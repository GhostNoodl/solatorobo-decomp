#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x10];
    s32 kinds[0x10];
    s32 args[0x10];
    s32 unk_90;
    s32 index;
} CmdQueue;

extern "C" {

void func_ov000_02188634(CmdQueue *self, s32 a, s32 b) {
    self->kinds[self->index] = 0x29;
    self->args[self->index] = a | (b << 16);
    if (++self->index >= 0x10) {
        self->index = 0;
    }
}

}
