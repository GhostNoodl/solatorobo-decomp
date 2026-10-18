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

void func_ov008_021cff1c(Ov008V *self, s32 arg, s32 b) {
    Ov008Cb cb = FLD(Ov008Cb, self, 0x80);
    if (cb != NULL) {
        cb(arg, self, b);
    }
}

s32 func_ov008_021cff40(Ov008V *self) {
    s32 a;
    FLD(s32, data_02097ce0, 0x4) = FLD(s32, self, 0x1c);
    a = (*(s8 **)func_0203a4c0(data_02097ce0))[1];
    return a + self->v3c();
}

s32 func_ov008_021cff84(Ov008V *self, s32 a, s32 b, s32 c) {
    return self->v60(a, b, c);
}

bool func_ov008_021cff98(Ov008V *self) {
    return Ov008_IsState2(self);
}

}
