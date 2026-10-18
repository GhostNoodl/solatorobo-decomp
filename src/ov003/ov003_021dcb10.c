#include "types.h"

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 1;
} Ov003Unit;

typedef struct {
    u8 unk_00[0x20];
    u16 unk_20;
    u8 unk_22[2];
    u8 unk_24[0x14];
    void *unk_38;
    u8 unk_3c[0x90];
    u16 unk_cc_0 : 3;
    u16 unk_cc_3 : 1;
} Ov003Obj24;

extern void *data_ov000_021ccd64;
extern void *func_0203db40(void *p);
extern void func_ov000_02190a80(void *a, void *b);
extern void func_0203de1c(void *p);
extern void func_ov000_0219429c(void *p);
extern void func_ov000_0219433c(void *p);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);

void func_ov003_021dcb10(Ov003Obj24 *self) {
    if (self->unk_38 != NULL) {
        func_ov000_02190a80(self->unk_38, func_0203db40(self->unk_24));
    }
}

void func_ov003_021dcb3c(void) {

}

void func_ov003_021dcb40(void) {

}

void func_ov003_021dcb44(void) {

}

void func_ov003_021dcb48(void) {

}

void func_ov003_021dcb4c(void) {

}

void func_ov003_021dcb50(void) {

}

void func_ov003_021dcb54(void) {

}

void *func_ov003_021dcb58(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021dcb74(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void func_ov003_021dcb88(Ov003Obj24 *self) {
    Ov003Unit *unit;
    func_ov000_0219433c(self);
    unit = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (unit != NULL) {
        unit->unk_a2_0 = 0;
    }
    self->unk_cc_3 = 0;
}
