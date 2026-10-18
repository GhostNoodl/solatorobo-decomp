#include "ov002/ov002.h"

extern "C" {

BOOL func_ov002_021ec6a8(void) {
    return TRUE;
}

BOOL func_ov002_021ec6b0(void) {
    return TRUE;
}

BOOL func_ov002_021ec6b8(void) {
    return TRUE;
}

void func_ov002_021ec6c0(void) {
}

void func_ov002_021ec6c4(VObject *self, s32 kind) {
    s32 k = FIELD(self, 0x24, s32);
    s32 st;
    if (k != 2 && k != kind) {
        return;
    }
    st = FIELD(self, 0x8, s32);
    if (st == 3 || st == 7) {
        self->v0x2c(kind);
    }
}

void func_ov002_021ec6fc(void *node) {
    void *p = data_ov002_021f0fa0[0];
    void *prev;
    if (p == NULL) {
        data_ov002_021f0fa0[2] = node;
        data_ov002_021f0fa0[0] = node;
    } else {
        if (p != NULL) {
            s32 key = FIELD(FIELD(node, 0x20, void *), 4, s32);
            do {
                if (key < FIELD(FIELD(p, 0x20, void *), 4, s32)) {
                    break;
                }
                prev = p;
                p = FIELD(p, 0x2c, void *);
            } while (p != NULL);
        }
        if (p == NULL) {
            FIELD(node, 0x28, void *) = prev;
            FIELD(node, 0x2c, void *) = NULL;
            FIELD(prev, 0x2c, void *) = node;
            data_ov002_021f0fa0[2] = node;
        } else {
            FIELD(node, 0x28, void *) = FIELD(p, 0x28, void *);
            FIELD(node, 0x2c, void *) = p;
            FIELD(p, 0x28, void *) = node;
            if (FIELD(node, 0x28, void *) != NULL) {
                FIELD(FIELD(node, 0x28, void *), 0x2c, void *) = node;
            } else {
                data_ov002_021f0fa0[0] = node;
            }
        }
    }
    {
        s32 idx = FIELD(FIELD(node, 0x20, void *), 0, s32);
        FIELD(node, 0x30, void *) = data_ov002_021f0fac[idx];
        data_ov002_021f0fac[idx] = node;
    }
}

void func_ov002_021ec7ac(void *self) {
    FIELD(self, 0x20, s32) = 0;
    FIELD(self, 0x24, s32) = 3;
    FIELD(self, 0x28, s32) = 0;
    FIELD(self, 0x2c, s32) = 0;
    FIELD(self, 0x30, s32) = 0;
    if (FIELD(self, 0x8, s32) != 1) {
        FIELD(self, 0xc, s32) = 1;
    }
}

void func_ov002_021ec7dc(void) {
}

BOOL func_ov002_021ec7e0(void *self) {
    if (*FIELD(self, 0x20, s32 *) == 3) {
        FIELD(data_ov002_021f0fa0[1], 0x4, u32) |= 8;
    }
    return FALSE;
}

void func_ov002_021ec80c(void) {
}

void func_ov002_021ec810(void *self) {
    FIELD(self, 0x34, s32) = 0;
    FIELD(self, 0x38, s32) = 0;
    FIELD(self, 0x3c, s32) = 0;
    FIELD(self, 0x40, s32) = 0;
    FIELD(self, 0x44, s32) = 0;
    FIELD(self, 0x48, u8) = 0;
    FIELD(self, 0x49, u8) = 0x1e;
}

void func_ov002_021ec838(void *self) {
    u32 saved;
    HEAP_PUSH(saved);
    {
        void *p = FIELD(self, 0x38, void *);
        if (p != NULL) {
            if (p != NULL) {
                func_02041558(p);
                func_02041278((u8 *)p + 0x88);
                func_0203de1c(p);
            }
            FIELD(self, 0x38, void *) = NULL;
        }
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_VOBJ(FIELD(self, 0x34, VObject *));
    HEAP_POP(saved);
}

static inline BOOL func_ov002_021ec8d8_is5(void *t) {
    return FIELD(t, 8, s32) == 5 ? TRUE : FALSE;
}
static inline BOOL func_ov002_021ec8d8_flag(void *t) {
    return FIELD(t, 4, Bits32).b4 == 1 ? TRUE : FALSE;
}
BOOL func_ov002_021ec8d8(void) {
    void *t;
    int n = 0;
    for (t = data_ov002_021f0fa0[8]; t != NULL; t = FIELD(t, 0x30, void *)) {
        if (func_ov002_021ec8d8_is5(t) || func_ov002_021ec8d8_flag(t)) {
            n++;
        }
    }
    if (n >= FIELD(data_ov002_021f0d88, 0x2c, s32)) {
        return FALSE;
    }
    return TRUE;
}

BOOL func_ov002_021ec968(void *self) {
    switch (FIELD(self, 0x10, s32)) {
    case 0: {
        VObject *o = (VObject *)func_0203dd9c(0x4c);
        if (o != NULL) {
            *(VFunc **)o = data_0208b318;
            o->v0x8();
        }
        FIELD(self, 0x34, VObject *) = o;
        FIELD(o, 0x44, s32) = 2;
        FIELD(self, 0x34, VObject *)->v0x24(data_ov002_021f0d88[2], FIELD(FIELD(self, 0x20, void *), 8, void *));
        FIELD(self, 0x10, s32)++;
        break;
    }
    case 1:
        if (FIELD(self, 0x34, VObject *)->v0x2c()) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

}
