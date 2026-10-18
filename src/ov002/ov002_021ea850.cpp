#include "ov002/ov002.h"

extern "C" {

void *func_ov002_021ea850(void *self) {
    int i;
    *(VFunc **)self = data_ov002_021f070c;
    for (i = 0; i < 4; i++) {
        VObject *o = func_020657b0(data_0214a420, ((void **)((u8 *)self + 0x50))[i]);
        u32 saved;
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->v0x4();
            }
        }
        HEAP_POP(saved);
    }
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    func_0203de1c(self);
    return self;
}

void *func_ov002_021ea938(void *self) {
    int i;
    *(VFunc **)self = data_ov002_021f070c;
    for (i = 0; i < 4; i++) {
        VObject *o = func_020657b0(data_0214a420, ((void **)((u8 *)self + 0x50))[i]);
        u32 saved;
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->v0x4();
            }
        }
        HEAP_POP(saved);
    }
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *func_ov002_021eaa18(void *self) {
    *(VFunc **)self = data_ov002_021f075c;
    func_ov002_021e5d88(self);
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    func_0203de1c(self);
    return self;
}

void func_ov002_021eaaa4(void) {
}

void *func_ov002_021eaaa8(void *self) {
    *(VFunc **)self = data_ov002_021f075c;
    func_ov002_021e5d88(self);
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *func_ov002_021eab2c(void *self) {
    *(VFunc **)self = data_ov002_021f07d4;
    func_ov002_021e51f8(self);
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    func_0203de1c(self);
    return self;
}

void *func_ov002_021eabb8(void *self) {
    *(VFunc **)self = data_ov002_021f07d4;
    func_ov002_021e51f8(self);
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *func_ov002_021eac3c(void *self) {
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *func_ov002_021eaca8(void *self) {
    *(VFunc **)self = data_ov002_021f0684;
    func_ov002_021eae3c(self);
    func_0203de1c(self);
    return self;
}

void func_ov002_021eacd0(void *self) {
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, s32) = 0;
    MIi_CpuClear32(0, (u8 *)self + 0x10, 0x30);
    FIELD(self, 0x40, s32) = 0;
    FIELD(self, 0x44, s32) = 0;
    FIELD(self, 0x48, s32) = 0;
    FIELD(self, 0x4c, s32) = 0;
    FIELD(self, 0x50, s32) = 0;
    FIELD(self, 0x54, s32) = 0;
    FIELD(self, 0x58, s32) = 0;
    FIELD(self, 0x5c, s32) = 0;
    FIELD(self, 0x60, s32) = 0;
}

}
