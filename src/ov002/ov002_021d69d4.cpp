#include "ov002/ov002.h"

extern "C" {

Task021efb24 *Ov002TaskVt_021efb24_DtorDelete(Task021efb24 *self) {
    *(VFunc **)self = data_ov002_021efb24;
    func_ov002_021da39c();
    TaskBase_dtor(self);
    Heap_Free(self);
    return self;
}

Task021efb24 *Ov002TaskVt_021efb24_Dtor(Task021efb24 *self) {
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

int func_ov002_021d6a78(VObj *self) {
    s8 base;
    data_02097ce0->unk_004 = FIELD(self, 0x1c, s32);
    base = (*(s8 **)GfxMgr_GetFont(data_02097ce0))[1];
    return base + self->vfunc_3c();
}

BOOL func_ov002_021d6abc(void) {
    return FALSE;
}

int func_ov002_021d6ac4(VObj *self, int a, int b, int c) {
    return self->vfunc_60(a, b, c);
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

static inline int func_ov002_021d6b88_calc(VObj *self) {
    int a = self->vfunc_40() * FIELD(self, 0x20, s32);
    int b = self->vfunc_34();
    int c = self->vfunc_38();
    a += b;
    return a + c;
}

int func_ov002_021d6b88(VObj *self) {
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

int func_ov002_021d6c64(VObj *self) {
    return self->vfunc_30() + FIELD(self, 0xc0, u8) + 0x12;
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
    if (func_0203e63c((unsigned int)FIELD(o, 0x6c, void *))) {
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

Ov002Hud *Ov002Vt_021efb14_Dtor(Ov002Hud *self) {
    *(VFunc **)self = data_ov002_021efb14;
    func_ov002_021e1d28(self);
    return self;
}

void *Ov002Vt_021efb04_Dtor(void *self) {
    *(VFunc **)self = data_ov002_021efb04;
    func_ov000_02163254(self);
    return self;
}

VObj *Ov002Vt_021efca4_Dtor(VObj *self) {
    *(VFunc **)self = data_ov000_021caec8;
    self->vfunc_2c();
    *(VFunc **)self = data_ov000_021cac60;
    self->vfunc_2c();
    return self;
}

void func_ov002_021d6e48(Obj021efe4c *self) {
    self->unk_18 = 0;
    self->unk_1c = 0;
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_26 = 0;
    self->unk_28 = 0;
    MTX_Identity33_((MtxFx33 *)((u8 *)self + 0x2c));
    self->unk_50 = 0x1000;
    self->unk_54 = 0x1000;
    self->unk_58 = 0x1000;
    self->unk_5c = 0;
    self->unk_5d = 0;
    MI_CpuFill8((u8 *)self + 0x6c, 0, 4);
    self->unk_60 = 0;
    self->unk_64 = 0;
    self->unk_68 = 0;
    self->map = NULL;
    self->unk_04 = NULL;
    self->unk_08 = NULL;
    self->unk_0c = NULL;
    self->unk_10 = NULL;
    self->unk_14 = NULL;
}

static inline void func_ov002_021d6ec4_release(void *obj) {
    void **res = FIELD(*(void **)obj, 0xc, void **);
    NNS_G3dReleaseMdlSet(NNS_G3dGetMdlSet((NNSG3dResFileHeader *)(res != NULL ? *res : NULL)));
}

void func_ov002_021d6ec4(Obj021efe4c *self) {
    if (self->unk_08 != NULL) {
        func_ov002_021d6ec4_release(self->unk_08);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_WITH(FIELD(self, 0x8, void *), func_ov000_0218fee4);
        HEAP_POP(saved);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_WITH(FIELD(self, 0xc, void *), func_ov000_0218ea20);
        HEAP_POP(saved);
    }
    if (self->unk_10 != NULL) {
        func_ov002_021d6ec4_release(self->unk_10);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_WITH(FIELD(self, 0x10, void *), func_ov000_0218fee4);
        HEAP_POP(saved);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_WITH(FIELD(self, 0x14, void *), func_ov000_0218ea20);
        HEAP_POP(saved);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_WITH(FIELD(self, 0x4, void *), func_ov000_0218ea20);
        HEAP_POP(saved);
    }
}

}
