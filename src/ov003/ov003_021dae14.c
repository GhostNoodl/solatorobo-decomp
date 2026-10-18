#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003Vec;

typedef struct {
    u8 unk_00[0x70];
    Ov003Vec unk_70;
    u16 unk_7c;
    u16 unk_7e;
    u32 unk_80;
    Ov003Vec unk_84;
} Ov003Obj7e;

extern void func_02012d78(Ov003Vec *src, Ov003Vec *dst);
extern void func_ov000_0219433c(void *self);
extern void func_01ffc9fc(Ov003Vec *src, Ov003Vec *dst, u16 angle);
extern void func_02012be8(Ov003Vec *a, Ov003Vec *b, Ov003Vec *dst);
extern void func_0203de1c(void *p);
extern void func_ov000_0219429c(void *p);

void *func_ov003_021dae14(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov003_021dae28(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021dae44(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void func_ov003_021dae58(Ov003Obj7e *self) {
    Ov003Vec v;
    func_ov000_0219433c(self);
    v.x = 0;
    v.y = 0;
    v.z = 0x1000;
    func_01ffc9fc(&v, &v, self->unk_7e);
    func_02012be8(&v, &self->unk_70, &v);
    self->unk_84.x = v.x;
    self->unk_84.y = v.y;
    self->unk_84.z = v.z;
}
