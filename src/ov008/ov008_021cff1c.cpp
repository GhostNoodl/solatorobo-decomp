#include "ov008/ov008.h"



extern "C" {

extern Ov008Ce0 *data_02097ce0;
extern void *data_ov000_021caec8;
extern void *data_ov000_021cac60;
void *func_0203a4c0(void *p);
BOOL func_02054f10(void *a, int b);
BOOL func_0203e63c(void *p);
BOOL func_ov008_021d01b0(Ov008Menu *self);

}

static inline BOOL Ov008_IsState2(Ov008Menu *self) {
    return self->unk_04 == 2;
}

static inline Ov008Item *Ov008_GetItem(Ov008Menu *self) {
    Ov008Item *p = self->unk_98;
    s32 i;
    if (p == NULL) {
        return NULL;
    }
    i = self->unk_b1;
    while (i-- != 0) {
        p = p->next;
    }
    return p;
}

static inline BOOL Ov008_ModelDone(Ov008MenuRes *p) {
    if (p->unk_6c == NULL) {
        return TRUE;
    }
    if (func_0203e63c(p->unk_6c)) {
        p->unk_6c = NULL;
    } else {
        return p->unk_04.b6 == 0;
    }
    return TRUE;
}

static inline s32 Ov008_Height(Ov008Menu *self) {
    s32 a = self->v40() * self->unk_20;
    s32 b = self->v34();
    return a + b + self->v38();
}

extern "C" {

void func_ov008_021cff1c(Ov008Menu *self, s32 arg, s32 b) {
    Ov008Cb cb = self->unk_80;
    if (cb != NULL) {
        cb(arg, self, b);
    }
}

s32 func_ov008_021cff40(Ov008Menu *self) {
    s32 a;
    data_02097ce0->unk_04 = self->unk_1c;
    a = (*(s8 **)func_0203a4c0(data_02097ce0))[1];
    return a + self->v3c();
}

s32 func_ov008_021cff84(Ov008Menu *self, s32 a, s32 b, s32 c) {
    return self->v60(a, b, c);
}

bool func_ov008_021cff98(Ov008Menu *self) {
    return Ov008_IsState2(self);
}

s32 func_ov008_021cffb8(Ov008Menu *self) {
    Ov008Cb cb = self->unk_90;
    s32 r;
    if (cb == NULL) {
        return 1;
    }
    r = cb(self, Ov008_GetItem(self));
    self->unk_90 = NULL;
    return r;
}

}
