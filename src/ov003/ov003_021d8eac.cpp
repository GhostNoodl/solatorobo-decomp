#include "types.h"

class Ov003Timer {
public:
    virtual void v00();
    virtual void v04();
    virtual void Release();
    u8 active : 1;
    u8 running : 1;
    u8 loop : 1;
    s16 duration;
    void *target;
    u8 unk_0c[4];
    u32 unk_10;
    u32 unk_14;
};

typedef struct {
    u8 active : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u32 unk_0c;
} Ov003Flag;

extern "C" {

extern void func_ov000_02198360(void *p, s32 a, s32 b);

void func_ov003_021d8eac(Ov003Timer *self, void *target, s16 duration, bool loop) {
    if (!self->active) {
        return;
    }
    self->running = 1;
    self->loop = loop;
    self->target = target;
    self->duration = duration;
    self->unk_10 = 0;
    self->unk_14 = 0;
    func_ov000_02198360(self->unk_0c, 0, 1);
}

BOOL func_ov003_021d8efc(Ov003Timer *self) {
    if (self->active && !self->running) {
        return TRUE;
    }
    return FALSE;
}

void func_ov003_021d8f24(Ov003Flag *self) {
    self->active = 0;
}

void func_ov003_021d8f34(Ov003Flag *self) {
    if (self->active) {
        self->active = 0;
    }
}

#pragma force_active on
BOOL func_ov003_021d8f4c(Ov003Flag *self) {
    self->active = 1;
    self->b1 = 0;
    self->b2 = 0;
    self->b3 = 0;
    self->b4 = 0;
    self->b5 = 0;
    self->b6 = 0;
    self->unk_04 = 0;
    self->unk_06 = 0;
    self->unk_08 = 0;
    self->unk_0c = 0;
    return TRUE;
}
#pragma force_active reset

void func_ov003_021d8fa8(Ov003Flag *self) {
    if (self->active) {
        self->active = 0;
    }
}

}
