#include "ov009/ov009.h"

extern "C" {

extern Ov009Obj *func_ov000_02199ba0(void *p);
extern s32 func_ov000_0219a510(Ov009Obj *self, u16 mask, const Ov009Vec *pos, s32 r, s32 a, void **list);
extern Ov009Actor *func_ov000_021985c0(void *p);
extern void func_ov003_021f0c60(Ov009Obj *self, s32 a);
extern s32 func_0203db40(void *p);
extern void func_ov000_02190a80(Ov009Sub38 *m, s32 a);
extern void *func_ov000_0219429c(void *self);

void func_ov009_02215a54(Ov009ActExVt_0221802c *self) {
    func_ov000_02198360(self->unk_40, 0x15, 0);
}

void func_ov009_02215a6c(Ov009ActExVt_0221802c *self) {
    void *list[0x20];
    s32 r = self->unk_64 + 0x333;
    u16 grp;
    s32 n;
    s32 i;
    self->unk_48->unk_44 = r;
    grp = func_ov000_02199ba0(self->unk_4c)->id & 0xf000;
    n = func_ov000_0219a510(self, ~(1 << (grp >> 12)), &self->pos, r, 0, list);
    if (n == 0) {
        return;
    }
    for (i = 0; i < n; i++) {
        Ov009Actor *a;
        if (list[i] != NULL && (a = func_ov000_021985c0(list[i])) != NULL) {
            Ov009Target *p = a->unk_4c;
            if (p == NULL || grp != (u16)(p->target & 0xf000)) {
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

void *Ov009ActExVt_0221802c_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *Ov009ActExVt_0221802c_Dtor(void *self) {
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

void *Ov009ActExVt_0221828c_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *Ov009ActExVt_0221828c_Dtor(void *self) {
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

void *Ov009ActExVt_022181f4_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov009ActExVt_022181f4_DtorDelete(void *self) {
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
