#include "ov009/ov009.h"

extern "C" {

extern void *func_ov000_02199ba0(void *p);
extern s32 func_ov000_0219a510(Ov009Actor *self, u16 mask, const Ov009Vec *pos, s32 r, s32 a, void **list);
extern Ov009Actor *func_ov000_021985c0(void *p);
extern void func_ov003_021f0c60(Ov009Actor *self, s32 a);
extern s32 func_0203db40(void *p);
extern void func_ov000_02190a80(Ov009Sub38 *m, s32 a);
extern void *func_ov000_0219429c(void *self);

void func_ov009_02215a54(Ov009Actor *self) {
    func_ov000_02198360(self->unk_40, 0x15, 0);
}

void func_ov009_02215a6c(Ov009Actor *self) {
    void *list[0x20];
    s32 r = self->unk_64 + 0x333;
    u16 grp;
    s32 n;
    s32 i;
    FLD(s32, self->unk_48, 0x44) = r;
    grp = FLD(u16, func_ov000_02199ba0(FLD(void *, self, 0x4c)), 0xc) & 0xf000;
    n = func_ov000_0219a510(self, ~(1 << (grp >> 12)), &self->pos, r, 0, list);
    if (n == 0) {
        return;
    }
    for (i = 0; i < n; i++) {
        Ov009Actor *a;
        if (list[i] != NULL && (a = func_ov000_021985c0(list[i])) != NULL) {
            u8 *p = FLD(u8 *, a, 0x4c);
            if (p == NULL || grp != (u16)(FLD(u16, p, 0x1c) & 0xf000)) {
                func_ov003_021f0c60(self, 0);
                func_ov000_02198360(self->unk_40, 0x15, 0);
                return;
            }
        }
    }
}

void func_ov009_02215b5c(Ov009Actor *self) {
    if (self->unk_38 != NULL) {
        func_ov000_02190a80(self->unk_38, func_0203db40(&FLD(u8, self, 0x24)));
    }
}

void func_ov009_02215b88(void) {
}

void func_ov009_02215b8c(void) {
}

void func_ov009_02215b90(void) {
}

void func_ov009_02215b94(void) {
}

void func_ov009_02215b98(void) {
}

void func_ov009_02215b9c(void) {
}

void func_ov009_02215ba0(void) {
}

void *func_ov009_02215ba4(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov009_02215bc0(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov009_02215bd4(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov009_02215bf0(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov009_02215c04(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov009_02215c20(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov009_02215c34(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov009_02215c50(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov009_02215c64(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov009_02215c78(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov009_02215c94(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov009_02215ca8(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

}
