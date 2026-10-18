#include "ov000/VObj.h"

typedef struct {
    u32 flags;
    u8 unk_04[0x3c];
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
} Obj021bd314;

typedef struct {
    u32 bit0 : 1;
    u32 bit1 : 1;
    u32 bit2 : 1;
    u32 bit3 : 1;
    u32 rest : 28;
} Flags021bd374;

typedef struct {
    Flags021bd374 flags;
    u8 unk_04[0x64];
    s32 unk_68;
    u8 unk_6c[0x18];
    s32 unk_84;
    s32 unk_88;
} Obj021bd374;


extern "C" {

s32 FX_Div(s32 a, s32 b);
extern const s16 FX_SinCosTable_[];

void func_ov000_021bd7b8(Obj021bd314 *self);

BOOL func_ov000_021bd314(Obj021bd314 *self, s32 x) {
    if (self->unk_48 == x) {
        return TRUE;
    }
    if ((u32)(self->unk_40 - 7) <= 2) {
        func_ov000_021bd7b8(self);
    }
    if (self->unk_44 == x) {
        return TRUE;
    }
    self->unk_40 = 7;
    self->unk_48 = x;
    self->flags |= 8;
    return TRUE;
}

BOOL func_ov000_021bd374(Obj021bd374 *self, s32 len) {
    s32 v;
    if (!(self->flags.bit1 == 1 ? TRUE : FALSE) || (self->flags.bit3 == 1 ? TRUE : FALSE)) {
        self->unk_84 -= 0x1000;
    } else {
        self->unk_84 += 0x1000;
    }
    v = FX_Div(self->unk_84, len);
    if (v >= 0x1000) {
        self->unk_84 = len;
        v = 0x1000;
    } else if (v <= 0) {
        self->unk_84 = 0;
        self->unk_68 = 4;
        return TRUE;
    }
    self->unk_88 = FX_SinCosTable_[((v << 14) >> 16) * 2];
    return FALSE;
}

}
