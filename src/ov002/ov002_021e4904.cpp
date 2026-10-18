#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e4904(void *self) {
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, s32) = 0;
    {
        u32 saved;
        HEAP_PUSH(saved);
        if (FIELD(self, 0xc, void *) != NULL) {
            func_0203de50(FIELD(self, 0xc, void *));
            FIELD(self, 0xc, void *) = NULL;
        }
        HEAP_POP(saved);
    }
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x14, s32) = 0;
}

u32 func_ov002_021e4960(void *self, s32 val) {
    u32 n = FIELD(self, 0x8, u32);
    s32 *arr;
    u32 i;
    if (n == 0 || (arr = FIELD(self, 0xc, s32 *)) == NULL) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        if (arr[i] > val) {
            return i;
        }
    }
    return i;
}

void func_ov002_021e49a0(void *self) {
    *(VFunc **)self = data_ov002_021f00ec;
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, s32) = 0;
    FIELD(self, 0xc, s32) = 0;
}

void *func_ov002_021e49c0(void *self) {
    *(VFunc **)self = data_ov002_021f00ec;
    {
        u32 saved;
        HEAP_PUSH(saved);
        if (FIELD(self, 0xc, void *) != NULL) {
            func_0203de50(FIELD(self, 0xc, void *));
            FIELD(self, 0xc, void *) = NULL;
        }
        HEAP_POP(saved);
    }
    return self;
}

void *func_ov002_021e4a18(void *self) {
    *(VFunc **)self = data_ov002_021f00ec;
    {
        u32 saved;
        HEAP_PUSH(saved);
        if (FIELD(self, 0xc, void *) != NULL) {
            func_0203de50(FIELD(self, 0xc, void *));
            FIELD(self, 0xc, void *) = NULL;
        }
        HEAP_POP(saved);
    }
    func_0203de1c(self);
    return self;
}

}
