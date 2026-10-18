#include "ov002/ov002.h"

extern "C" {

void func_ov002_021ecfd8(void *self) {
    FIELD(self, 0x4c, s32) = 0;
}

void func_ov002_021ecfe4(void *self) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_WITH(FIELD(self, 0x4c, void *), func_ov000_0214b724);
    HEAP_POP(saved);
}

BOOL func_ov002_021ed03c(void) {
    return TRUE;
}

BOOL func_ov002_021ed044(void *self) {
    switch (FIELD(self, 0x10, s32)) {
    case 0: {
        void *p = func_0203dd9c(0x3c);
        if (p != NULL) {
            p = func_ov000_0214b6d8(p);
        }
        FIELD(self, 0x4c, void *) = p;
        func_ov000_0214b88c(p, data_ov002_021f0d88[3]);
        FIELD(self, 0x10, s32)++;
        break;
    }
    case 1:
        func_ov000_0214b810(FIELD(self, 0x4c, void *));
        if (func_ov000_0214b8d8(FIELD(self, 0x4c, void *))) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL func_ov002_021ed0c0(void *self) {
    if (FIELD(self, 0x10, s32) != 0) {
        return FALSE;
    }
    FIELD(self, 0x24, s32) = FIELD(FIELD(self, 0x20, void *), 0xc, u16);
    FIELD(self, 0x49, u8) = 0x1f;
    return TRUE;
}

static inline BOOL func_ov002_021ed0ec_is3(void *self) {
    return FIELD(self, 8, s32) == 3 ? TRUE : FALSE;
}
void func_ov002_021ed0ec(void *self) {
    if (FIELD(self, 0x4c, void *) == NULL || FIELD(self, 0x48, u8) == 0) {
        return;
    }
    {
        Vec3 b = data_ov002_021ef124;
        Vec3 a;
        a.x = FIELD(self, 0x3c, s32);
        a.y = FIELD(self, 0x40, s32);
        a.z = FIELD(self, 0x44, s32);
        a.x = (a.x & ~0xfff) + 0x80000;
        a.y = (a.y & ~0xfff) + 0x60000;
        if (func_ov002_021ed0ec_is3(self)) {
            a.z = -0x2000;
        } else {
            a.z = -0x1ccd;
        }
        func_ov000_0214b1a0(&a, &b, FIELD(self, 0x48, u8), func_ov000_0214b8ec(FIELD(self, 0x4c, void *)));
    }
}

void func_ov002_021ed1ac(void *self) {
    FIELD(self, 0x34, s32) = 0;
    FIELD(self, 0x44, s32) = 0;
    FIELD(self, 0x38, s32) = 0;
    FIELD(self, 0x3c, s32) = 0;
    FIELD(self, 0x40, s32) = 0;
    FIELD(self, 0x48, s32) = 0;
    FIELD(self, 0x4c, s32) = 0;
    FIELD(self, 0x50, s32) = 0;
    FIELD(self, 0x54, u8) = 0x1f;
}

void func_ov002_021ed1dc(void *self) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x34, VObject *));
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x44, VObject *));
    HEAP_POP(saved);
}

}
