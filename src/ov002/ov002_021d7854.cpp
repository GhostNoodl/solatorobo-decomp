#include "ov002/ov002.h"

extern "C" {

void *Ov002Vt_021efe8c_Dtor(void *self) {
    Ov002Vt_021efe3c_Dtor((u8 *)self + 0x4);
    return self;
}

void *Ov002Vt_021efe8c_DtorDelete(void *self) {
    Ov002Vt_021efe3c_Dtor((u8 *)self + 0x4);
    Heap_Free(self);
    return self;
}

void func_ov002_021d788c(void *self) {
    s32 v = FIELD(self, 0x30, s32);
    if (FIELD(self, 0x24, s32 *) != NULL) {
        *FIELD(self, 0x24, s32 *) = v;
    }
    if (FIELD(self, 0x28, s32 *) != NULL) {
        *FIELD(self, 0x28, s32 *) = v;
    }
    if (FIELD(self, 0x2c, s32 *) != NULL) {
        *FIELD(self, 0x2c, s32 *) = v;
    }
    FIELD(self, 0x30, s32) = (FIELD(self, 0x30, s32) + 0x1000) % FIELD(self, 0x34, s32);
}

void *Ov002Vt_021efe5c_Dtor(void *self) {
    func_02041558((Model *)((u8 *)self + 0x74));
    func_02041278((PlttRes *)((u8 *)self + 0xfc));
    Ov002Vt_021efe3c_Dtor((u8 *)self + 0x4);
    return self;
}

void *Ov002Vt_021efe5c_DtorDelete(void *self) {
    func_02041558((Model *)((u8 *)self + 0x74));
    func_02041278((PlttRes *)((u8 *)self + 0xfc));
    Ov002Vt_021efe3c_Dtor((u8 *)self + 0x4);
    Heap_Free(self);
    return self;
}

void func_ov002_021d792c(void *self) {
    s32 v = FIELD(self, 0x30, s32);
    if (FIELD(self, 0x24, s32 *) != NULL) {
        *FIELD(self, 0x24, s32 *) = v;
    }
    if (FIELD(self, 0x28, s32 *) != NULL) {
        *FIELD(self, 0x28, s32 *) = v;
    }
    if (FIELD(self, 0x2c, s32 *) != NULL) {
        *FIELD(self, 0x2c, s32 *) = v;
    }
    FIELD(self, 0x30, s32) = (FIELD(self, 0x30, s32) + 0x1000) % FIELD(self, 0x34, s32);
    FIELD(self, 0x1d8, u32) = (u16)(FIELD(self, 0x1d8, u32) + 1);
}

}
