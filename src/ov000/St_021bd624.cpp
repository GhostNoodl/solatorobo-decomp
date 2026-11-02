#include "ov000/LoCommon.h"
#include "nitro/mi.h"

typedef void (*StFn021bd624)(void *self);

typedef struct {
    StFn021bd624 enter;
    StFn021bd624 update;
} St021bd624;

extern "C" {

extern St021bd624 data_ov000_021cc934[];
extern St021bd624 data_ov000_021cc938[];
BOOL func_ov000_021bd8ac(void *self);
BOOL func_0203e688(void);
BOOL func_02054f10(void *p, u16 a);

static inline s32 Norm021bd624(s32 k) {
    if (k >= 12 && k < 16) {
        k = 11;
    }
    return k;
}

struct Obj021bd624 {
    u8 unk_00[0x40];
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
    u8 unk_4c[0x14];
    StFn021bd624 unk_60;
    StFn021bd624 unk_64;
    s32 unk_68;
};

void func_ov000_021bd624(Obj021bd624 *self) {
    switch (self->unk_40) {
    case 7:
        if (!func_ov000_021bd8ac(self)) {
            break;
        }
        self->unk_40 = 8;
    case 8: {
        s32 i;
        BOOL ok;
        s32 k = Norm021bd624(self->unk_48);
        ok = FALSE;
        if (k == 11) {
            if (func_0203e688()) {
                ok = TRUE;
            }
        } else {
            for (i = 0; i < 8; i++) {
                if (((void **)((u8 *)self + 8))[i] != NULL && !func_02054f10(((void **)((u8 *)self + 8))[i], 0xffff)) {
                    break;
                }
            }
            if (i == 8) {
                ok = TRUE;
            }
        }
        if (!ok) {
            break;
        }
        self->unk_40 = 9;
    }
    case 9: {
        s32 n;
        s32 k;
        if (self->unk_68 != 4) {
            break;
        }
        LBIT(self, 0).b3 = 0;
        self->unk_68 = 5;
        if (self->unk_60 != NULL) {
            self->unk_60(self);
        }
        MI_CpuFill8((u8 *)self + 0x68, 0, 0x24);
        self->unk_68 = 1;
        n = Norm021bd624(self->unk_48);
        self->unk_44 = self->unk_48;
        self->unk_48 = -1;
        self->unk_60 = data_ov000_021cc934[n].enter;
        self->unk_64 = data_ov000_021cc938[n].enter;
        if (self->unk_60 != NULL) {
            self->unk_60(self);
        }
        self->unk_40 = 10;
    }
    }
    if (self->unk_60 != NULL) {
        self->unk_60(self);
    }
}

}
