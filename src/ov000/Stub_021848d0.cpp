#include "ov000/VObj.h"

typedef struct {
    u8 unk_00[0x10];
    s32 kinds[0x10];
    s32 args[0x10];
    s32 unk_90;
    s32 index;
    u8 unk_98[0x32];
    u8 unk_ca;
} CmdQueue;

extern "C" {

void *func_ov000_0219bf90(void);

void func_ov000_021848d0(CmdQueue *self) {
    if (func_ov000_0219bf90() == NULL || self->unk_ca == 0xfe) {
        return;
    }
    self->kinds[self->index] = 0xd;
    self->args[self->index] = 0;
    if (++self->index >= 0x10) {
        self->index = 0;
    }
}

}
