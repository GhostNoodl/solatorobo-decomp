#include "ov002/ov002.h"

extern "C" {

void *func_ov002_021e8aac(void *self) {
    *(VFunc **)self = data_ov002_021f0734;
    func_ov002_021e4d4c_inline(self);
    func_0203de1c(self);
    return self;
}

BOOL func_ov002_021e8b28(void *self) {
    return FIELD(self, 0xc, s32) >= 3;
}

void func_ov002_021e8b3c(VObject *self) {
    u32 mask;
    if (FIELD(self, 4, s32) != 4 && FIELD(self, 4, s32) != 5) {
        return;
    }
    mask = FIELD(self, 0xc, u32);
    if ((FIELD(self, 0x128, u32) & mask) && FIELD(self, 0xd0, s32) > 0) {
        func_ov002_021e8cc4(self);
    }
    for (self = FIELD(self, 0xdc, VObject *); self != NULL; self = FIELD(self, 0x24, VObject *)) {
        if ((FIELD(self, 8, u32) & mask) && FIELD(self, 0xc, s32) == 3) {
            self->v0x1c();
        }
    }
}

void func_ov002_021e8bbc(void *self, void *item) {
    void *node = FIELD(self, 0xdc, void *);
    void *prev = NULL;
    if (node == item) {
        FIELD(self, 0xdc, void *) = FIELD(item, 0x24, void *);
        return;
    }
    while (node != NULL) {
        if (node == item) {
            break;
        }
        prev = node;
        node = FIELD(node, 0x24, void *);
    }
    if (node != NULL) {
        FIELD(prev, 0x24, void *) = FIELD(node, 0x24, void *);
        FIELD(node, 0x24, void *) = NULL;
    }
}

void func_ov002_021e8c0c(void *self) {
    VObject *o = FIELD(self, 0xdc, VObject *);
    while (o != NULL) {
        VObject *next = FIELD(o, 0x24, VObject *);
        u32 saved;
        HEAP_PUSH(saved);
        if (o != NULL) {
            if (o != NULL) {
                o->v0x4();
            }
        }
        HEAP_POP(saved);
        o = next;
    }
    FIELD(self, 0xdc, void *) = NULL;
    {
        u32 saved;
        HEAP_PUSH(saved);
        {
            void *p = FIELD(self, 0x124, void *);
            if (p != NULL) {
                if (p != NULL) {
                    func_02041558(p);
                    func_02041278((u8 *)p + 0x88);
                    func_0203de1c(p);
                }
                FIELD(self, 0x124, void *) = NULL;
            }
        }
        HEAP_POP(saved);
    }
}

}
