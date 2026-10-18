#include "ov008/ov008.h"

typedef s32 (*Ov008Cb)(...);

struct Ov008Item {
    u8 unk_00[0x2c];
    Ov008Item *next;
};

struct Ov008Flags04 {
    u32 b0 : 6;
    u32 b6 : 1;
    u32 rest : 25;
};

extern "C" {

extern void *data_02097ce0;
extern void *data_ov000_021caec8;
extern void *data_ov000_021cac60;
void *func_0203a4c0(void *p);
BOOL func_02054f10(void *a, int b);
BOOL func_0203e63c(void *p);
BOOL func_ov008_021d01b0(Ov008V *self);

}

static inline BOOL Ov008_IsState2(Ov008V *self) {
    return FLD(s32, self, 0x4) == 2;
}

static inline Ov008Item *Ov008_GetItem(Ov008V *self) {
    Ov008Item *p = FLD(Ov008Item *, self, 0x98);
    s32 i;
    if (p == NULL) {
        return NULL;
    }
    i = FLD(s8, self, 0xb1);
    while (i-- != 0) {
        p = p->next;
    }
    return p;
}

static inline BOOL Ov008_ModelDone(void *p) {
    if (FLD(void *, p, 0x6c) == NULL) {
        return TRUE;
    }
    if (func_0203e63c(FLD(void *, p, 0x6c))) {
        FLD(void *, p, 0x6c) = NULL;
    } else {
        return FLD(Ov008Flags04, p, 0x4).b6 == 0;
    }
    return TRUE;
}

static inline s32 Ov008_Height(Ov008V *self) {
    s32 a = self->v40() * FLD(s32, self, 0x20);
    s32 b = self->v34();
    return a + b + self->v38();
}

extern "C" {

s32 func_ov008_021d0014(Ov008V *self, s32 arg) {
    if (FLD(Ov008Cb, self, 0x8c) == NULL) {
        return TRUE;
    }
    return FLD(Ov008Cb, self, 0x8c)(self, arg);
}

s32 func_ov008_021d0030(Ov008V *self, s32 arg) {
    if (FLD(Ov008Cb, self, 0x88) == NULL) {
        return TRUE;
    }
    return FLD(Ov008Cb, self, 0x88)(self, arg);
}

s32 func_ov008_021d004c(Ov008V *self, s32 arg) {
    if (FLD(Ov008Cb, self, 0x84) == NULL) {
        return TRUE;
    }
    return FLD(Ov008Cb, self, 0x84)(self, arg);
}

s32 func_ov008_021d0068(Ov008V *self) {
    if (FLD(u32, self, 0xc) & 0x20000) {
        s32 r;
        FLD(s32, self, 0x20) += 2;
        r = Ov008_Height(self);
        FLD(s32, self, 0x20) -= 2;
        return r;
    }
    return Ov008_Height(self);
}

s32 func_ov008_021d011c(void) {
    return 4;
}

s32 func_ov008_021d0124(Ov008V *self) {
    return self->v30() + FLD(u8, self, 0xc0) + 0x12;
}

s32 func_ov008_021d0148(void) {
    return 0xc;
}

s32 func_ov008_021d0150(void) {
    return 0;
}

s32 func_ov008_021d0158(Ov008V *self) {
    return FLD(void *, self, 0xb8) != NULL ? 0x12 : 0;
}

s32 func_ov008_021d016c(Ov008V *self) {
    return FLD(s8, self, 0xc1) * 8;
}

BOOL func_ov008_021d0178(Ov008V *self) {
    BOOL r = func_ov008_021d01b0(self);
    if (FLD(void *, self, 0xb4) != NULL && !func_02054f10(FLD(void *, self, 0xb4), 0xffff)) {
        r = FALSE;
    }
    return r;
}

BOOL func_ov008_021d01b0(Ov008V *self) {
    BOOL r = TRUE;
    void *p;
    if (FLD(void *, self, 0x10) != NULL && !func_02054f10(FLD(void *, self, 0x10), 0xffff)) {
        r = FALSE;
    }
    p = FLD(void *, self, 0x14);
    if (p != NULL && !Ov008_ModelDone(p)) {
        r = FALSE;
    }
    p = FLD(void *, self, 0x18);
    if (p != NULL && !Ov008_ModelDone(p)) {
        r = FALSE;
    }
    return r;
}

Ov008V *func_ov008_021d0284(Ov008V *self) {
    FLD(void *, self, 0) = &data_ov000_021caec8;
    self->v2c();
    FLD(void *, self, 0) = &data_ov000_021cac60;
    self->v2c();
    return self;
}

}
