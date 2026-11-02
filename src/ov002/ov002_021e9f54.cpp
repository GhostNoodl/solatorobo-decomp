#include "ov002/ov002.h"

extern "C" {

void *Ov002Vt_021f0674_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021f0674;
    func_ov002_021e7dac(self);
    *(VFunc **)((u8 *)self + 0x6c) = data_ov002_021f0684;
    func_ov002_021eae3c((u8 *)self + 0x6c);
    return self;
}

void *Ov002Vt_021f0694_DtorDelete(void *self) {
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021f0694_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *Ov002Vt_021f06e4_DtorDelete(void *self) {
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021f06e4_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *Ov002Vt_021f07fc_DtorDelete(void *self) {
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021f07fc_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *Ov002Vt_021f0828_DtorDelete(void *self) {
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021f0828_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *Ov002Vt_021f0854_DtorDelete(void *self) {
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021f0854_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *Ov002Vt_021f0784_DtorDelete(void *self) {
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021f0784_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    return self;
}

void *Ov002Vt_021f07ac_DtorDelete(void *self) {
    *(VFunc **)self = data_ov002_021f07ac;
    if (FIELD(self, 0x14, s32) != 0) {
        func_02035acc((u8 *)self + 0x4c, (u8 *)self + 0x6c, 0);
    }
    FIELD(data_02097ce0, 0x10, u16) = 1;
    Ov002Vt_021f0ce8_Dtor((u8 *)self + 0x8c);
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    Heap_Free(self);
    return self;
}

void *Ov002Vt_021f07ac_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021f07ac;
    if (FIELD(self, 0x14, s32) != 0) {
        func_02035acc((u8 *)self + 0x4c, (u8 *)self + 0x6c, 0);
    }
    FIELD(data_02097ce0, 0x10, u16) = 1;
    Ov002Vt_021f0ce8_Dtor((u8 *)self + 0x8c);
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    return self;
}

}
