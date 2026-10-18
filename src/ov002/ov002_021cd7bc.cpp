#include "ov002/ov002.h"

extern "C" {

bool func_ov002_021cd7bc(Task50 *self) {
    BOOL r = Task50_getFlag4(self);
    return r;
}

void func_ov002_021cd7e0(Task50 *self) {
    self->unk_20 = 0x10000;
    self->unk_3c = NULL;
    self->unk_40 = NULL;
    self->unk_44 = NULL;
    self->unk_48 = 0;
    self->unk_4c = -1;
    self->unk_4d = 0;
}

void func_ov002_021cd80c(Task50 *self) {
    u32 saved;
    void *p;
    VObject *o;

    HEAP_PUSH(saved);
    p = self->unk_3c;
    if (p != NULL) {
        if (p != NULL) {
            func_02041558(p);
            func_02041278((u8 *)p + 0x88);
            func_0203de1c(p);
        }
        self->unk_3c = NULL;
    }
    HEAP_POP(saved);

    HEAP_PUSH(saved);
    o = self->unk_40;
    if (o != NULL) {
        if (o != NULL) {
            VC(o, 0x4)();
        }
        self->unk_40 = NULL;
    }
    HEAP_POP(saved);

    HEAP_PUSH(saved);
    o = self->unk_44;
    if (o != NULL) {
        if (o != NULL) {
            VC(o, 0x4)();
        }
        self->unk_44 = NULL;
    }
    HEAP_POP(saved);

    if (self->unk_4d) {
        func_02035acc(data_ov002_021ef3e4, data_ov002_021ef3ec, 2);
    }
}

void func_ov002_021cd910(void *self, int arg) {
    func_ov000_0218084c(data_ov000_021ccd44, arg, 0);
}

void func_ov002_021cd92c(Task50 *self, int kind) {
    void *msg = data_02149ef8;
    void *str = data_ov002_021ef3f8;
    switch (kind) {
    case 0:
        str = func_0204c0e8(msg, 0xdf);
        break;
    case 1:
        str = func_0204c0e8(msg, 0xe0);
        break;
    case 2:
        str = func_0204c0e8(msg, 0xc3);
        break;
    case 3:
        str = func_0204c0e8(msg, 0xe2);
        break;
    case 4:
        str = func_0204c0e8(msg, 0xe1);
        break;
    case 5:
        str = func_0204c0e8(msg, 0xde);
        break;
    }
    func_ov000_0215bb14(self->unk_44, str);
    VC(self->unk_44, 0x70)();
}

}
