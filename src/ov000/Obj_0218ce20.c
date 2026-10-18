#include "types.h"

typedef struct {
    u8 unk_00[0x78];
    s32 unk_78;
    s32 unk_7c;
    s32 unk_80;
    u8 unk_84[0x3a];
    u8 unk_be;
} Sub0218ce38;

typedef struct {
    u8 unk_00[0x10];
    s32 unk_10;
    u8 unk_14[0x5];
    u8 unk_19;
    u8 unk_1a;
    u8 unk_1b;
} Sub0218ce3c;

typedef struct {
    s16 unk_00;
} Sub0218ce34;

typedef struct {
    u8 unk_00[0x6c];
    s32 unk_6c;
} Sub0218ce48;

typedef struct {
    u8 unk_00[0x24];
    u8 unk_24[0x10];
    Sub0218ce34 *unk_34;
    Sub0218ce38 *unk_38;
    Sub0218ce3c *unk_3c;
    u8 unk_40[0x4];
    void *unk_44;
    Sub0218ce48 *unk_48;
    u8 unk_4c[0x24];
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    u8 unk_7c[0x17];
    u8 unk_93_0 : 1;
} Obj0218ce38;

void *func_0203db40(void *a);
void func_ov000_02190a80(void *a, void *b);
void func_ov000_02190758(Sub0218ce38 *a, void *b, s32 c);
BOOL func_ov000_021903b4(Sub0218ce38 *a);
void func_ov000_02191c24(Sub0218ce3c *a, void *b);
BOOL func_ov000_0218f110(Sub0218ce34 *a);
BOOL func_ov000_02191b9c(Sub0218ce3c *a);
void func_ov000_0219864c(void *a, s32 b, s32 c);
void func_ov000_021984f4(void *a, s32 b, s32 c);

void func_ov000_0218ce20(void) {
}

void func_ov000_0218ce24(void) {
}

void func_ov000_0218ce28(void) {
}

void func_ov000_0218ce2c(void) {
}

void func_ov000_0218ce30(void) {
}

void func_ov000_0218ce34(void) {
}

void func_ov000_0218ce38(Obj0218ce38 *self) {
    if (self->unk_38 != NULL) {
        func_ov000_02190a80(self->unk_38, func_0203db40(self->unk_24));
    }
}

void func_ov000_0218ce64(Obj0218ce38 *self) {
    if (self->unk_48 != NULL) {
        func_ov000_0219864c(self->unk_48, 0, 0);
    }
}

void func_ov000_0218ce84(Obj0218ce38 *self) {
    if (self->unk_44 != NULL) {
        func_ov000_021984f4(self->unk_44, 0, 0);
    }
}

BOOL func_ov000_0218cea4(Obj0218ce38 *self) {
    Sub0218ce38 *sub = self->unk_38;
    BOOL ret = FALSE;
    if (sub != NULL) {
        if (!self->unk_93_0) {
            sub->unk_78 = self->unk_70;
            sub->unk_7c = self->unk_74;
            sub->unk_80 = self->unk_78;
            func_ov000_02190758(self->unk_38, self->unk_7c, 0);
        }
        self->unk_93_0 = 0;
        ret = func_ov000_021903b4(self->unk_38);
    }
    if (ret && self->unk_3c != NULL) {
        if (self->unk_48 != NULL) {
            self->unk_3c->unk_10 = self->unk_74 - self->unk_48->unk_6c;
        }
        if (self->unk_38->unk_be < 0xf) {
            self->unk_3c->unk_19 = self->unk_38->unk_be;
        }
        func_ov000_02191c24(self->unk_3c, &self->unk_70);
    }
    return ret;
}

static inline BOOL IsIdle0218cf5c(Sub0218ce3c *sub) {
    BOOL ret = TRUE;
    if (sub->unk_1b != 3 && sub->unk_1b != 0) {
        ret = FALSE;
    }
    return ret;
}

BOOL func_ov000_0218cf5c(Obj0218ce38 *self) {
    BOOL ret = TRUE;
    if (self->unk_34 != NULL && self->unk_34->unk_00 >= 0) {
        if (!func_ov000_0218f110(self->unk_34)) {
            ret = FALSE;
        }
    }
    if (self->unk_3c != NULL && !IsIdle0218cf5c(self->unk_3c)) {
        if (!func_ov000_02191b9c(self->unk_3c)) {
            ret = FALSE;
        }
    }
    return ret;
}
