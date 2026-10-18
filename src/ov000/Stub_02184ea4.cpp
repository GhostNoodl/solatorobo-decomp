#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x10];
    s32 kinds[0x10];
    s32 args[0x10];
    s32 unk_90;
    s32 index;
} CmdQueue;

extern "C" {

void func_ov000_02184ea4(CmdQueue *self, s32 a) {
    self->kinds[self->index] = 0x10;
    self->args[self->index] = a << 16;
    if (++self->index >= 0x10) {
        self->index = 0;
    }
}

void func_ov000_02184ee0(CmdQueue *self, s32 a) {
    self->kinds[self->index] = 0x10;
    self->args[self->index] = (a << 16) | 1;
    if (++self->index >= 0x10) {
        self->index = 0;
    }
}

}
