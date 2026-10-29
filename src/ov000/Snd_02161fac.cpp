#include "types.h"

typedef struct {
    s16 unk_00;
    u8 pad02[0x136];
} Track02161fac;

typedef struct {
    void *vtbl;
    u8 state;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07[0x20];
    u8 unk_27[0x18];
    u8 unk_3f[0x20];
    u8 unk_5f[0x18];
    u8 unk_77;
    Track02161fac a[2];
    Track02161fac b[2];
} Obj02161fac;

extern "C" {

void func_ov000_0218ec60(Track02161fac *t, void *a, void *b, s32 c, s32 d);
void func_ov000_0218edf0(Track02161fac *t, void *a, void *b, s32 c, s32 d);
BOOL func_ov000_0218f110(Track02161fac *t);
BOOL func_0203e688(void);

void func_ov000_02161fac(Obj02161fac *self) {
    u8 idx;
    switch (self->state) {
    case 0:
        idx = (self->unk_05 & 1) ^ 1;
        func_ov000_0218ec60(&self->a[idx], self->unk_07, self->unk_27, 1, 0);
        func_ov000_0218edf0(&self->a[idx], self->unk_3f, self->unk_5f, 1, 0);
        if (self->unk_77 != 0) {
            func_ov000_0218edf0(&self->b[idx], self->unk_07, self->unk_27, 1, 0);
        } else {
            func_ov000_0218edf0(&self->b[idx], NULL, NULL, 1, 0);
            self->b[idx].unk_00 = 0;
        }
        self->unk_06 = 0;
        self->state = 10;
        break;
    case 10:
        idx = (self->unk_05 & 1) ^ 1;
        func_ov000_0218f110(&self->a[idx]);
        func_ov000_0218f110(&self->b[idx]);
        if (self->a[idx].unk_00 < 0 && self->b[idx].unk_00 < 0) {
            if (func_0203e688()) {
                if (self->unk_06 != 0) {
                    self->state = 0;
                } else {
                    self->state = 20;
                }
            }
        }
        break;
    case 20:
        if (self->unk_06 != 0) {
            self->state = 0;
        }
        break;
    }
}

}
