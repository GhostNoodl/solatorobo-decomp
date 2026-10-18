#include "ov006/Tasks.h"

extern "C" {

extern void *data_02149ef8;

u16 func_ov006_021e60e8(int type, u16 mask);
void func_ov006_021e4a80(ov006_Unk021ec888 *self, u16 a, int b, const void *src, u32 size);
void func_ov006_021db258(void);
void func_ov006_021d1b8c(ov006_TaskD0C *self);
void *func_0204c0e8(void *a, int id);
void func_ov000_0215bb14(void *a, const void *b);

void func_ov006_021d1490(ov006_TaskD0C *self) {
    u16 trg = data_02097dc8->unk12;
    if (self->unk3C) {
        return;
    }
    if (trg & 2) {
        if (self->unkC == 2 && func_ov006_021e60e8(1, 1)) {
            return;
        }
        self->unk3C = 0x32;
        return;
    }
    if (!(trg & 1)) {
        return;
    }
    if (self->unkC != 1) {
        return;
    }
    if (self->unk40 < 2) {
        return;
    }
    if (data_ov006_021ec884->numActive >= 2) {
        self->unk3C = 5;
        return;
    }
    func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
}

void func_ov006_021d1570(ov006_TaskD0C *self) {
    if (self->unk8 == 9 || self->unk8 == 0xd) {
        if (data_ov006_021ec888->unk8 != 9) {
            u8 n;
            func_ov006_021e4a80(data_ov006_021ec888, self->unk101, 1, &self->unk102, 0x18);
            func_ov006_021db258();
            n = data_ov006_021ec884->numActive;
            if (self->unk40 != n) {
                func_ov006_021d1b8c(self);
                if (self->unkC == 1) {
                    void *res = data_02149ef8;
                    if (self->unk40 <= 1 && n >= 2) {
                        func_ov000_0215bb14(self->unk120, func_0204c0e8(res, 0x137));
                        VCALL(self->unk120, 70);
                    } else if (self->unk40 >= 2 && n <= 1) {
                        func_ov000_0215bb14(self->unk120, func_0204c0e8(res, 0x138));
                        VCALL(self->unk120, 70);
                    }
                }
                self->unk40 = n;
            }
        }
    }
    VCALL(self->unk11C, 1C);
    VCALL(self->unk120, 1C);
    VCALL(self->unk124, 1C);
}

}
