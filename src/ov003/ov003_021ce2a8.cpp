#include "types.h"

#define V(n) virtual void v##n();

class Ov003Scene {
public:
    V(00) V(04) V(08) V(0c) V(10) V(14) V(18) V(1c) V(20) V(24) V(28) V(2c) V(30) V(34) V(38) V(3c)
    V(40) V(44) V(48) V(4c) V(50)
    virtual BOOL IsDone();
    V(58)
    virtual void Release();
};

typedef struct {
    u8 unk_00[0x14];
    u32 unk_14;
} Ov003Current;

typedef struct {
    void *vtbl;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 b7 : 1;
} Ov003FlagSet;

extern "C" {

extern void *data_02149ef8;
extern Ov003Current *data_ov000_021ccd40;
extern u32 data_ov000_021ccd38;
extern u32 data_ov003_021f78f4;
extern u32 data_ov000_021cc060;
extern void func_02016e28(char *dst, s32 c);
extern const char *func_0204c0e8(void *mgr, s32 id);
extern void func_0203de1c(void *p);

void func_ov003_021ce2a8(void *self, char *dst, u32 size, const char *arg) {
    u32 n = 0;
    const char *fmt;
    u32 max;
    func_02016e28(dst, n);
    max = size - 1;
    fmt = func_0204c0e8(data_02149ef8, 0x5c);
    while (*fmt != 0 && n < max) {
        if (*fmt == '%') {
            while (*arg != 0 && n < max) {
                *dst++ = *arg++;
                n++;
            }
            fmt++;
        } else {
            *dst++ = *fmt++;
            n++;
        }
    }
    *dst = 0;
}

bool func_ov003_021ce344(void *p) {
    BOOL r = (data_ov000_021ccd40 == p);
    return r;
}

void func_ov003_021ce36c(Ov003Current *p) {
    if (data_ov000_021ccd40 != NULL) {
        data_ov000_021ccd38 = data_ov000_021ccd40->unk_14;
    } else {
        data_ov000_021ccd38 = 0;
    }
    data_ov000_021ccd40 = p;
}

BOOL func_ov003_021ce3a0(Ov003Scene *self) {
    if (self->IsDone()) {
        if (data_ov000_021ccd40 != NULL) {
            data_ov000_021ccd38 = data_ov000_021ccd40->unk_14;
        } else {
            data_ov000_021ccd38 = 0;
        }
        data_ov000_021ccd40 = NULL;
    }
    return TRUE;
}

void func_ov003_021ce3f4(Ov003Scene *self) {
    if (self->IsDone()) {
        if (data_ov000_021ccd40 != NULL) {
            data_ov000_021ccd38 = data_ov000_021ccd40->unk_14;
        } else {
            data_ov000_021ccd38 = 0;
        }
        data_ov000_021ccd40 = NULL;
    }
}

bool func_ov003_021ce444(u32 *self, u32 mask) {
    BOOL r = (self[1] & mask) ? TRUE : FALSE;
    return r;
}

void func_ov003_021ce464(Ov003FlagSet *self) {
    self->b7 = 0;
}

void func_ov003_021ce474(Ov003FlagSet *self) {
    self->b7 = 1;
}

bool func_ov003_021ce484(Ov003FlagSet *self) {
    BOOL r = self->b6 ? TRUE : FALSE;
    return r;
}

void func_ov003_021ce4a8(Ov003FlagSet *self) {
    self->b6 = 1;
}

bool func_ov003_021ce4b8(Ov003FlagSet *self) {
    BOOL r = self->b5 ? TRUE : FALSE;
    return r;
}

void func_ov003_021ce4dc(Ov003FlagSet *self) {
    self->b5 = 1;
}

void func_ov003_021ce4ec(Ov003FlagSet *self) {
    self->b4 = 0;
}

void func_ov003_021ce4fc(Ov003FlagSet *self) {
    self->b4 = 1;
}

BOOL func_ov003_021ce50c(void) {
    return TRUE;
}

Ov003Scene *func_ov003_021ce514(Ov003Scene *self) {
    *(void **)self = &data_ov003_021f78f4;
    self->Release();
    *(void **)self = &data_ov000_021cc060;
    self->Release();
    func_0203de1c(self);
    return self;
}

Ov003Scene *func_ov003_021ce560(Ov003Scene *self) {
    *(void **)self = &data_ov003_021f78f4;
    self->Release();
    *(void **)self = &data_ov000_021cc060;
    self->Release();
    return self;
}

void *func_ov003_021ce5a4(void *self) {
    func_0203de1c(self);
    return self;
}

s32 func_ov003_021ce5b8(u32 color) {
    u32 c = color & 0xf0f0f0;
    if (c == 0xb06010) {
        return 3;
    }
    if (c == 0x80d0f0) {
        return 6;
    }
    if (c == 0xe0e000) {
        return 0x3b;
    }
    if (c == 0x606060) {
        return 4;
    }
    if (c == 0x5000) {
        return 2;
    }
    return (c == 0x400) ? 0x3d : 1;
}

}
