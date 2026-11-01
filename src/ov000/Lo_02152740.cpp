#include "ov000/LoCommon.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 pad : 5;
    u32 fade : 2;
    u32 rest : 23;
} Bits02152740;

typedef void (*LoCb02152740)(VObj *self);

extern "C" {
s32 FX_Div(s32 a, s32 b);

#define WB(self) LFLD(Bits02152740, self, 0xc)

struct Obj02152740 : public VObj {
    s32 unk_04;
    u8 unk_08[0x28];
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3c;
    s32 unk_40;
    s32 unk_44;
    u8 unk_48[0x4];
    s32 unk_4c;
    s32 unk_50;
    u8 unk_54[0x20];
    VObj *unk_74;
    LoCb02152740 unk_78;
};

BOOL func_ov000_02152740(Obj02152740 *self) {
    self->vfunc_54();
    switch (self->unk_04) {
    case 5:
        if (!WB(self).b1) {
            self->unk_04 = 0;
            return TRUE;
        }
        return FALSE;
    case 0:
        WB(self).b0 = 1;
        if (WB(self).b1 == 1) {
            self->unk_04 = 5;
            break;
        }
        if (self->unk_78 != NULL) {
            self->unk_78(self);
        }
        self->unk_04 = 3;
    case 3:
        if (!self->vfunc_4c()) {
            break;
        }
        self->unk_30 += 0x1000;
        self->unk_38 = FX_Div(self->unk_30, self->unk_34);
        if (self->unk_38 < 0x1000) {
            break;
        }
        if ((void *)self->unk_74 == NULL) {
            WB(self).b0 = 0;
        }
        self->unk_30 = self->unk_34;
        self->unk_38 = 0x1000;
        if (self->unk_78 != NULL) {
            self->unk_78(self);
        }
        self->unk_04 = 2;
        break;
    case 1:
        WB(self).b0 = 1;
        if (self->unk_78 != NULL) {
            self->unk_78(self);
        }
        self->unk_04 = 4;
    case 4:
        self->unk_30 -= 0x1000;
        self->unk_38 = FX_Div(self->unk_30, self->unk_34);
        if (self->unk_38 > 0) {
            break;
        }
        self->unk_30 = 0;
        self->unk_38 = 0;
        if (self->unk_78 != NULL) {
            self->unk_78(self);
        }
        self->unk_04 = 5;
        return FALSE;
    case 2:
        self->unk_30 = self->unk_34;
        self->unk_38 = 0x1000;
        {
            u32 f = WB(self).fade;
            if (f == 0) {
            } else if (f == 1) {
                self->unk_3c += 0x1000;
                self->unk_44 = FX_Div(self->unk_3c, self->unk_40);
                if (self->unk_44 >= 0x1000) {
                    self->unk_3c = self->unk_40;
                    self->unk_44 = 0x1000;
                    WB(self).fade = 2;
                }
            } else if (f == 3) {
                self->unk_3c -= 0x1000;
                self->unk_44 = FX_Div(self->unk_3c, self->unk_40);
                if (self->unk_44 <= 0) {
                    self->unk_3c = 0;
                    self->unk_44 = 0;
                    WB(self).fade = 0;
                }
            }
        }
        break;
    }
    if (self->unk_74 != NULL && !self->unk_74->vfunc_1c()) {
        LO_FREE_V(self, 0x74);
        if (self->unk_74 == NULL) {
            WB(self).b0 = 0;
        }
        if (!self->vfunc_50()) {
            WB(self).b1 = 1;
        }
    }
    self->vfunc_58();
    if (self->unk_50 != 0) {
        s32 n = self->unk_50 << 12;
        self->unk_4c += 0x666;
        if (self->unk_4c >= n + 0x7c000) {
            self->unk_4c -= n;
        }
    }
    return TRUE;
}

}

