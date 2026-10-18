#include "ov002/ov002.h"

extern "C" {

Task50 *func_ov002_021d69d4(Task50 *self) {
    *(VFunc **)self = data_ov002_021efb24;
    func_ov002_021da39c();
    TaskBase_dtor(self);
    func_0203de1c(self);
    return self;
}

Task50 *func_ov002_021d6a18(Task50 *self) {
    *(VFunc **)self = data_ov002_021efb24;
    func_ov002_021da39c();
    TaskBase_dtor(self);
    return self;
}

void func_ov002_021d6a54(void *self, void *arg, int a) {
    MenuCallback3 cb = FIELD(self, 0x80, MenuCallback3);
    if (cb != NULL) {
        cb(arg, self, a);
    }
}

int func_ov002_021d6a78(VObject *self) {
    s8 base;
    FIELD(data_02097ce0, 0x4, s32) = FIELD(self, 0x1c, s32);
    base = (*func_0203a4c0(data_02097ce0))[1];
    return base + self->v0x3c();
}

BOOL func_ov002_021d6abc(void) {
    return FALSE;
}

int func_ov002_021d6ac4(VObject *self, int a, int b, int c) {
    return self->v0x60(a, b, c);
}

int func_ov002_021d6ad8(void *self) {
    MenuCallback cb = FIELD(self, 0x90, MenuCallback);
    void *node;
    int r;
    if (cb == NULL) {
        return 1;
    }
    node = FIELD(self, 0x98, void *);
    if (node == NULL) {
        node = NULL;
    } else {
        int n = FIELD(self, 0xb1, s8);
        while (n-- != 0) {
            node = FIELD(node, 0x2c, void *);
        }
    }
    r = cb(self, node);
    FIELD(self, 0x90, MenuCallback) = NULL;
    return r;
}

int func_ov002_021d6b34(void *self, void *arg) {
    MenuCallback cb = FIELD(self, 0x8c, MenuCallback);
    if (cb == NULL) {
        return 1;
    }
    return cb(self, arg);
}

int func_ov002_021d6b50(void *self, void *arg) {
    MenuCallback cb = FIELD(self, 0x88, MenuCallback);
    if (cb == NULL) {
        return 1;
    }
    return cb(self, arg);
}

int func_ov002_021d6b6c(void *self, void *arg) {
    MenuCallback cb = FIELD(self, 0x84, MenuCallback);
    if (cb == NULL) {
        return 1;
    }
    return cb(self, arg);
}

static inline int func_ov002_021d6b88_calc(VObject *self) {
    int a = self->v0x40() * FIELD(self, 0x20, s32);
    int b = self->v0x34();
    int c = self->v0x38();
    a += b;
    return a + c;
}

int func_ov002_021d6b88(VObject *self) {
    int r;
    if (FIELD(self, 0xc, u32) & 0x20000) {
        FIELD(self, 0x20, s32) += 2;
        r = func_ov002_021d6b88_calc(self);
        FIELD(self, 0x20, s32) -= 2;
        return r;
    }
    return func_ov002_021d6b88_calc(self);
}

int func_ov002_021d6c3c(void) {
    return 0;
}

int func_ov002_021d6c44(void) {
    return 0;
}

int func_ov002_021d6c4c(void) {
    return 4;
}

int func_ov002_021d6c54(void) {
    return 3;
}

int func_ov002_021d6c5c(void) {
    return 6;
}

int func_ov002_021d6c64(VObject *self) {
    return self->v0x30() + FIELD(self, 0xc0, u8) + 0x12;
}

int func_ov002_021d6c88(void) {
    return 0xc;
}

int func_ov002_021d6c90(void) {
    return 0;
}

int func_ov002_021d6c98(void *self) {
    return FIELD(self, 0xb8, void *) != NULL ? 0x12 : 0;
}

int func_ov002_021d6cac(void *self) {
    return FIELD(self, 0xc1, s8) * 8;
}

int func_ov002_021d6cb8(void *self) {
    int r = func_ov002_021d6cf0(self);
    if (FIELD(self, 0xb4, void *) != NULL && func_02054f10(FIELD(self, 0xb4, void *), 0xffff) == 0) {
        r = 0;
    }
    return r;
}

static inline BOOL func_ov002_021d6cf0_check(void *o) {
    if (FIELD(o, 0x6c, void *) == NULL) {
        return TRUE;
    }
    if (func_0203e63c(FIELD(o, 0x6c, void *))) {
        FIELD(o, 0x6c, void *) = NULL;
    } else {
        return !FIELD(o, 4, Bits32).b6 ? TRUE : FALSE;
    }
    return TRUE;
}
BOOL func_ov002_021d6cf0(void *self) {
    BOOL r = TRUE;
    void *o;
    if (FIELD(self, 0x10, void *) != NULL && !func_02054f10(FIELD(self, 0x10, void *), 0xffff)) {
        r = FALSE;
    }
    o = FIELD(self, 0x14, void *);
    if (o != NULL && !func_ov002_021d6cf0_check(o)) {
        r = FALSE;
    }
    o = FIELD(self, 0x18, void *);
    if (o != NULL && !func_ov002_021d6cf0_check(o)) {
        r = FALSE;
    }
    return r;
}

void *func_ov002_021d6dc4(void *self) {
    *(VFunc **)self = data_ov002_021efb14;
    func_ov002_021e1d28(self);
    return self;
}

void *func_ov002_021d6de4(void *self) {
    *(VFunc **)self = data_ov002_021efb04;
    func_ov000_02163254(self);
    return self;
}

VObject *func_ov002_021d6e04(VObject *self) {
    *(VFunc **)self = data_ov000_021caec8;
    self->v0x2c();
    *(VFunc **)self = data_ov000_021cac60;
    self->v0x2c();
    return self;
}

void func_ov002_021d6e48(void *self) {
    FIELD(self, 0x18, s32) = 0;
    FIELD(self, 0x1c, s32) = 0;
    FIELD(self, 0x20, s32) = 0;
    FIELD(self, 0x24, s16) = 0;
    FIELD(self, 0x26, s16) = 0;
    FIELD(self, 0x28, s16) = 0;
    MTX_Identity33_((u8 *)self + 0x2c);
    FIELD(self, 0x50, s32) = 0x1000;
    FIELD(self, 0x54, s32) = 0x1000;
    FIELD(self, 0x58, s32) = 0x1000;
    FIELD(self, 0x5c, u8) = 0;
    FIELD(self, 0x5d, u8) = 0;
    func_02016e28((u8 *)self + 0x6c, 0, 4);
    FIELD(self, 0x60, s32) = 0;
    FIELD(self, 0x64, s32) = 0;
    FIELD(self, 0x68, s16) = 0;
    FIELD(self, 0x6c, s32) = 0;
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, s32) = 0;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x14, s32) = 0;
}

static inline void func_ov002_021d6ec4_release(void *obj) {
    void **res = FIELD(*(void **)obj, 0xc, void **);
    NNS_G3dReleaseMdlSet(NNS_G3dGetMdlSet(res != NULL ? *res : NULL));
}

void func_ov002_021d6ec4(void *self) {
    if (FIELD(self, 0x8, void *) != NULL) {
        func_ov002_021d6ec4_release(FIELD(self, 0x8, void *));
    }
    {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_WITH(FIELD(self, 0x8, void *), func_ov000_0218fee4);
        HEAP_POP(saved);
    }
    {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_WITH(FIELD(self, 0xc, void *), func_ov000_0218ea20);
        HEAP_POP(saved);
    }
    if (FIELD(self, 0x10, void *) != NULL) {
        func_ov002_021d6ec4_release(FIELD(self, 0x10, void *));
    }
    {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_WITH(FIELD(self, 0x10, void *), func_ov000_0218fee4);
        HEAP_POP(saved);
    }
    {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_WITH(FIELD(self, 0x14, void *), func_ov000_0218ea20);
        HEAP_POP(saved);
    }
    {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_WITH(FIELD(self, 0x4, void *), func_ov000_0218ea20);
        HEAP_POP(saved);
    }
}

}
