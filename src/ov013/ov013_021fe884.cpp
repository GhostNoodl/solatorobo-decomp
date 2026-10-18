#include "ov013/ov013.h"

struct Ov013Spot {
    Ov013Vec pos;
    u16 rot;
};

extern "C" {

extern void *data_0214a420;
extern void *data_ov000_021ccd68;
extern char data_ov013_0220b88d[];
extern void *func_020657b0(void *a, s32 b);
extern void func_ov000_0219763c(Ov013Actor *self);
extern void func_ov000_02195d88(Ov013Actor *self);
extern void func_ov000_02196060(Ov013Actor *self);
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern Ov013Actor *func_ov000_0218e4cc(void *mgr, u16 id);
extern BOOL func_ov003_021d98bc(void *a, const Ov013Spot *b);

void func_ov013_021fe884(Ov013Actor *self) {
    if (self->unk_40->state == 0) {
        void *p = func_020657b0(data_0214a420, FLD(s32, self, 0xd0));
        if (p != NULL) {
            FLD(s32, p, 0x1c) = 4;
            FLD(s32, self, 0xd0) = -1;
        }
    }
    func_ov000_0219763c(self);
}

void func_ov013_021fe8d0(Ov013Actor *self) {
    if (self->unk_38 != NULL) {
        func_ov000_02190a80(self->unk_38, func_0203db40((u8 *)self + 0x24));
    }
}

void func_ov013_021fe8fc(void) {
}

void func_ov013_021fe900(void) {
}

void func_ov013_021fe904(void) {
}

void func_ov013_021fe908(void) {
}

void func_ov013_021fe90c(void) {
}

void func_ov013_021fe910(void) {
}

Ov013Actor *func_ov013_021fe914(Ov013Actor *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

Ov013Actor *func_ov013_021fe930(Ov013Actor *self) {
    func_ov000_0219429c(self);
    return self;
}

void func_ov013_021fe944(void) {
}

}
