#include "types.h"

typedef struct {
    u8 unk_00[0x22];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
} Ov003SwPart;

typedef struct {
    u8 unk_00[0x18];
    s16 unk_18;
    s16 unk_1a;
    u8 unk_1c[0x28];
    Ov003SwPart *unk_44;
    u8 unk_48[4];
    void *unk_4c;
    u8 unk_50[0x43];
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
} Ov003SwProp;

extern s32 func_ov003_021f093c(void *p);
extern BOOL func_ov003_021f0abc(void *p, BOOL deep);
extern void func_ov000_02197dec(void *self, s32 a, s32 b);
extern void func_020627b4(void);

static inline BOOL Ov003SwPart_IsOn(Ov003SwPart *p) {
    if (p->unk_22_0 == 1 && p->unk_22_1 == 1) {
        return TRUE;
    }
    return FALSE;
}

void func_ov003_021ddd48(Ov003SwProp *self) {
    BOOL changed = FALSE;
    s32 v = -1;
    switch (self->unk_1a) {
    case 3:
        switch (func_ov003_021f093c(self->unk_4c)) {
        case 3:
        case 4:
            if (self->unk_18 == 0) {
                changed = TRUE;
                v = 1;
            }
            break;
        case 1:
        case 2:
            if (self->unk_18 != 0) {
                v = 0;
                changed = TRUE;
            }
            break;
        }
        break;
    case 2:
        if (func_ov003_021f0abc(self->unk_4c, TRUE)) {
            if (self->unk_18 == 0) {
                changed = TRUE;
                v = 1;
            }
        } else {
            if (self->unk_18 != 0) {
                changed = TRUE;
                v = 0;
            }
        }
        break;
    case 1:
        if (self->unk_93_1 != self->unk_18) {
            v = self->unk_18;
            func_ov000_02197dec(self, (u8)self->unk_18, -1);
        }
        break;
    }
    switch (v) {
    case 0: {
        Ov003SwPart *p = self->unk_44;
        if (p->unk_22_0 == 1 && p->unk_22_1 == 1) {
            p->unk_22_0 = 0;
            p->unk_22_1 = 0;
        }
        self->unk_93_1 = v;
        break;
    }
    case 1: {
        Ov003SwPart *p = self->unk_44;
        if (!Ov003SwPart_IsOn(p)) {
            p->unk_22_0 = 1;
            p->unk_22_1 = 1;
        }
        self->unk_93_1 = v;
        break;
    }
    }
    if (changed) {
        self->unk_18 = v;
        func_020627b4();
        func_ov000_02197dec(self, changed, changed);
    }
}
