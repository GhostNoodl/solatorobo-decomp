#include "ov002/ov002.h"

extern "C" {

extern VFunc data_ov002_021f06bc[];

void func_ov002_021ec164(void *p);

void *func_ov002_021ea670(void *self) {
    s16 *p;
    s32 t;
    *(VFunc **)self = data_ov002_021f06bc;
    if (FIELD(self, 0x14, void *) != NULL) {
        func_02035acc((u8 *)self + 0x4c, (u8 *)self + 0x6c, 0);
    }
    for (p = FIELD(self, 0xa8, s16 *); p != NULL; p = FIELD(self, 0xa8, s16 *)) {
        t = p[1];
        if (t == 1 || t == 3 || t == 7 || t == 10) {
            func_0204aaec(data_02097e48, p);
        }
        func_ov002_021ec2ac((u8 *)self + 0x94);
    }
    func_ov002_021ec164((u8 *)self + 0x94);
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    func_0203de1c(self);
    return self;
}

void *func_ov002_021ea764(void *self) {
    s16 *p;
    s32 t;
    *(VFunc **)self = data_ov002_021f06bc;
    if (FIELD(self, 0x14, void *) != NULL) {
        func_02035acc((u8 *)self + 0x4c, (u8 *)self + 0x6c, 0);
    }
    for (p = FIELD(self, 0xa8, s16 *); p != NULL; p = FIELD(self, 0xa8, s16 *)) {
        t = p[1];
        if (t == 1 || t == 3 || t == 7 || t == 10) {
            func_0204aaec(data_02097e48, p);
        }
        func_ov002_021ec2ac((u8 *)self + 0x94);
    }
    func_ov002_021ec164((u8 *)self + 0x94);
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    return self;
}

}
