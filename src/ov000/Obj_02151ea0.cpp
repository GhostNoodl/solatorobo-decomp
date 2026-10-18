#include "types.h"

typedef struct Node {
    u8 unk_00[0x2c];
    struct Node *next;
} Node;

class Obj02151 {
public:
    virtual s32 vfunc_00();
    virtual s32 vfunc_04();
    virtual s32 vfunc_08();
    virtual s32 vfunc_0c();
    virtual s32 vfunc_10();
    virtual s32 vfunc_14();
    virtual s32 vfunc_18();
    virtual s32 vfunc_1c();
    virtual s32 vfunc_20();
    virtual s32 vfunc_24();
    virtual s32 vfunc_28();
    virtual s32 vfunc_2c();
    virtual s32 vfunc_30();
    virtual s32 vfunc_34();
    virtual s32 vfunc_38();
    virtual s32 vfunc_3c();
    virtual s32 vfunc_40();
    virtual s32 vfunc_44();
    virtual s32 vfunc_48();
    virtual s32 vfunc_4c();
    virtual s32 vfunc_50();
    virtual s32 vfunc_54();
    virtual s32 vfunc_58();
    virtual s32 vfunc_5c();

    u32 unk_04;
    u8 unk_08[0x18];
    s32 unk_20;
    s32 unk_24;
    u8 unk_28[0x58];
    void (*unk_80)(void *arg, Obj02151 *self, void *arg2);
    BOOL (*unk_84)(Obj02151 *self, void *arg);
    BOOL (*unk_88)(Obj02151 *self, void *arg);
    BOOL (*unk_8c)(Obj02151 *self, void *arg);
    BOOL (*unk_90)(Obj02151 *self, Node *node);
    u32 unk_94;
    Node *unk_98;
    u8 unk_9c[0x15];
    s8 unk_b1;
    u8 unk_b2[0xf];
    s8 unk_c1;
    u8 unk_c2[0x1a];
    u8 unk_dc;
};

static inline Node *GetCurrentNode(Obj02151 *self) {
    Node *node = self->unk_98;
    s32 n;
    if (node == NULL) {
        return NULL;
    }
    n = self->unk_b1;
    while (n-- != 0) {
        node = node->next;
    }
    return node;
}

extern "C" {

extern u8 data_ov000_021caa44[];
extern u8 data_ov000_021cc060[];

static inline BOOL IsState2(Obj02151 *self) {
    return self->unk_04 == 2 ? TRUE : FALSE;
}

Obj02151 *func_ov000_02151ea0(Obj02151 *self) {
    *(void **)self = data_ov000_021caa44;
    self->vfunc_5c();
    *(void **)self = data_ov000_021cc060;
    self->vfunc_5c();
    return self;
}

void func_ov000_02151ee4(Obj02151 *self, void *arg, void *arg2) {
    if (self->unk_80 != NULL) {
        self->unk_80(arg, self, arg2);
    }
}

bool func_ov000_02151f08(Obj02151 *self) {
    return IsState2(self);
}

BOOL func_ov000_02151f28(Obj02151 *self) {
    BOOL ret;
    if (self->unk_90 == NULL) {
        return TRUE;
    }
    ret = self->unk_90(self, GetCurrentNode(self));
    self->unk_90 = NULL;
    return ret;
}

BOOL func_ov000_02151f84(Obj02151 *self, void *arg) {
    if (self->unk_8c == NULL) {
        return TRUE;
    }
    return self->unk_8c(self, arg);
}

BOOL func_ov000_02151fa0(Obj02151 *self, void *arg) {
    if (self->unk_88 == NULL) {
        return TRUE;
    }
    return self->unk_88(self, arg);
}

BOOL func_ov000_02151fbc(Obj02151 *self, void *arg) {
    if (self->unk_84 == NULL) {
        return TRUE;
    }
    return self->unk_84(self, arg);
}

s32 func_ov000_02151fd8(Obj02151 *self) {
    return self->unk_c1 * 8;
}

s32 func_ov000_02151fe4(Obj02151 *self) {
    s32 a = self->vfunc_40() * self->unk_20;
    s32 b = self->vfunc_34();
    return a + b + self->vfunc_38();
}

s32 func_ov000_02152030(Obj02151 *self) {
    s32 a = self->vfunc_40() * self->unk_20;
    s32 b = self->vfunc_34();
    return a + b + self->vfunc_38();
}

s32 func_ov000_0215207c(void) {
    return 0;
}

s32 func_ov000_02152084(void) {
    return 0;
}

s32 func_ov000_0215208c(void) {
    return 4;
}

s32 func_ov000_02152094(void) {
    return 3;
}

s32 func_ov000_0215209c(void) {
    return 8;
}

s32 func_ov000_021520a4(Obj02151 *self) {
    return self->unk_dc + 0x12;
}

s32 func_ov000_021520b0(Obj02151 *self) {
    return (s32)(((s64)(self->unk_24 << 12) * 0xe7a + 0x800) >> 12) >> 12;
}

s32 func_ov000_021520e4(void) {
    return 0xe;
}

}
