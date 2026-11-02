#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d09dc(void) {
}

void func_ov002_021d09e0(Task021efa1c *self) {
    if (self->unk_3c != NULL) {
        self->unk_3c->vfunc_20();
    }
    if (self->unk_40 != NULL) {
        self->unk_40->vfunc_20();
    }
}

Task021ef89c *func_ov002_021d0a1c(void) {
    Task021ef89c *p = (Task021ef89c *)Heap_Alloc(0x44);
    if (p != NULL) {
        TaskBase_ctor(p);
        *(VFunc **)p = data_ov002_021ef89c;
        p->unk_3c = NULL;
        p->unk_40 = NULL;
    }
    p->vfunc_08(0x15, 0x64);
    return p;
}

BOOL func_ov002_021d0a80(void *self, void *arg) {
    u8 *obj;
    s16 *info;
    int i;
    s16 v;
    int j;
    if (arg != NULL) {
        data_ov002_021f0f84[1] = FIELD(self, 0xa8, s32);
        obj = (u8 *)func_ov000_0218084c(data_ov000_021ccd44, 0x16, 0);
        info = func_0206ee90((u16)FIELD(arg, 0x8, u32));
        if (!((Info0206ee90 *)info)->flag) {
            obj[0x68] = 0;
        } else {
            obj[0x68] = 1;
        }
        for (i = 0; i < 8; i++) {
            v = info[i + 1];
            if (v < 0) {
                break;
            }
            for (j = 0; j < 8; j++) {
                if (((s32 *)(obj + 0x3c))[j] < 0) {
                    ((s32 *)(obj + 0x3c))[j] = v;
                    break;
                }
            }
        }
        FIELD(obj, 0x60, s32) = info[9];
        func_0203c9e8(0x3f, -1);
        func_0203cc58(0xa000, 2, -1);
    }
    return TRUE;
}

void func_ov002_021d0b5c(Task021ef89c *self) {
    self->unk_04_1 = 0;
    if (self->vfunc_28() != 0) {
        return;
    }
    func_ov002_021d0b98(self);
    func_ov000_02173648(self);
}

}
