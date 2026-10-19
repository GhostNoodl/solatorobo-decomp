#include "types.h"

typedef struct {
    u8 unk_00[0xa8];
    s32 scaleX;
    s32 scaleY;
    s32 scaleZ;
} Ov003Model;

typedef struct {
    u8 unk_00[0xe];
    u16 kind;
    u8 unk_10[8];
    s16 scaleX;
    s16 scaleY;
    s16 scaleZ;
    u8 unk_1e[0x1a];
    Ov003Model *model;
    u8 unk_3c[0x74];
    s16 unk_b0;
} Ov003Prop;

extern u32 data_ov003_021fa648;
extern void func_ov000_021b4c60(void *self);
extern void func_0206fef8(u16 kind);
extern void __cxa_vec_cleanup(void *arr, int count, int size, void *dtor);
extern void func_ov000_0218fee4(void *p);
extern void func_ov000_0218ea20(void *p);
extern void func_ov000_0218c928(void *p);
extern void func_ov000_021b4adc(void *self);
extern void func_ov000_0218f074(s16 *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern BOOL func_ov000_0218cf5c(void *self);
extern BOOL func_ov000_0218f110(s16 *p);
extern void func_0203de1c(void *p);
extern void func_ov000_0219429c(void *p);
extern void func_ov000_021b4b0c(void *p);

void func_ov003_021f34b0(Ov003Prop *self) {
    s32 x;
    s32 y;
    s32 z;
    Ov003Model *model;
    func_ov000_021b4c60(self);
    func_0206fef8(self->kind);
    model = self->model;
    x = model->scaleX;
    y = model->scaleY;
    if (self->scaleX != 0) {
        x = self->scaleX << 4;
    }
    z = model->scaleZ;
    if (self->scaleY != 0) {
        y = self->scaleY << 4;
    }
    if (self->scaleZ != 0) {
        z = self->scaleZ << 4;
    }
    model->scaleX = x;
    model->scaleY = y;
    model->scaleZ = z;
}

void func_ov003_021f3508(void) {

}

void *func_ov003_021f350c(void *self) {
    func_ov000_0218c928(self);
    return self;
}

void *func_ov003_021f3520(void *self) {
    func_ov000_0218c928(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021f353c(void *self) {
    func_ov000_0218c928(self);
    return self;
}

void *func_ov003_021f3550(void *self) {
    func_ov000_0218c928(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021f356c(void *self) {
    __cxa_vec_cleanup((u8 *)self + 0xa70, 6, 0xe8, func_ov000_0218fee4);
    __cxa_vec_cleanup((u8 *)self + 0xb0, 8, 0x138, func_ov000_0218ea20);
    func_ov000_0218c928(self);
    return self;
}

void *func_ov003_021f35b4(void *self) {
    __cxa_vec_cleanup((u8 *)self + 0xa70, 6, 0xe8, func_ov000_0218fee4);
    __cxa_vec_cleanup((u8 *)self + 0xb0, 8, 0x138, func_ov000_0218ea20);
    func_ov000_0218c928(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021f3604(void *self) {
    func_ov000_0218c928(self);
    return self;
}

void *func_ov003_021f3618(void *self) {
    func_ov000_0218c928(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021f3634(void *self) {
    func_ov000_0218c928(self);
    return self;
}

void *func_ov003_021f3648(void *self) {
    func_ov000_0218c928(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021f3664(void *self) {
    func_ov000_0218c928(self);
    return self;
}

void *func_ov003_021f3678(void *self) {
    func_ov000_0218c928(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021f3694(void *self) {
    func_ov000_0218c928(self);
    return self;
}

void *func_ov003_021f36a8(void *self) {
    func_ov000_0218c928(self);
    func_0203de1c(self);
    return self;
}

void func_ov003_021f36c4(Ov003Prop *self) {
    func_ov000_021b4adc(self);
    if (self->kind == 0x6a01) {
        return;
    }
    func_ov000_0218f074(&self->unk_b0, &data_ov003_021fa648, 1, 1, 0, 0);
    self->unk_b0 = 0;
}
