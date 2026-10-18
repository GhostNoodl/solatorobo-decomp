#include "ov006/ov006.h"

typedef struct ov006_Win021d86a0 {
    void *vtbl;
    int state;
    void *owner;
    u32 flags;
    u8 unk10[0x58];
    s16 unk68;
    u8 unk6A[0x1a];
    void *unk84;
    u8 unk88[0x150];
    u16 unk1D8;
    u8 unk1DA[2];
    int unk1DC;
    u16 unk1E0;
} ov006_Win021d86a0;

typedef struct ov006_Task021d86a0 {
    u8 unk0[0x34];
    ov006_Win021d86a0 *unk34;
    u8 unk38[4];
} ov006_Task021d86a0;

extern "C" {

ov006_Win021d86a0 *func_ov006_021db8c4(ov006_Win021d86a0 *self);
int func_ov006_021d88f8(void *a, void *b);

void func_ov006_021d86a0(ov006_Task021d86a0 *self, u16 a, int b) {
    ov006_Win021d86a0 *w;
    OV006_DELETE_OBJECT(self->unk34);
    w = (ov006_Win021d86a0 *)func_0203dd9c(0x1e8);
    if (w != NULL) {
        w = func_ov006_021db8c4(w);
    }
    self->unk34 = w;
    self->unk34->unk1D8 = a;
    self->unk34->unk1DC = b;
    self->unk34->unk1E0 = 0;
    self->unk34->flags |= 0x4000000;
    self->unk34->unk84 = (void *)func_ov006_021d88f8;
    self->unk34->owner = self->unk38;
    VCALL(self->unk34, 08);
    self->unk34->unk68 = -0x1666;
    self->unk34->flags &= ~2;
}

}
