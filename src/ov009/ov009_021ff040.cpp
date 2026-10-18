#include "ov009/ov009.h"

extern "C" {

extern void *data_0214a420;
extern void *data_02097e4c;
extern u8 data_ov009_02216ab6[];
extern u8 data_ov009_02216ace[];
extern void func_02065804(void *mgr, void *p);
extern void func_02049564(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(void *p, s32 a);
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern void func_ov000_021984f4(void *a, s32 b, s32 c);
extern void func_ov000_0219864c(void *a, s32 b, s32 c);
extern void NNS_G3dGetCurrentMtx(void *p, s32 a);

void func_ov009_021ff040(Ov009Actor *self) {
    func_ov003_021d5348(self);
    if (self->unk_a0 < -0x133) {
        func_ov000_02198360(self->unk_40, 1, 0);
    }
}

void func_ov009_021ff074(Ov009Actor *self) {
    if (self->unk_40->state == 0 && self->unk_18 == 0) {
        self->unk_48->unk_30 = 0;
    }
    func_ov003_021d3a88(self);
}

void func_ov009_021ff0a0(Ov009Actor *self) {
    if (self->unk_40->state == 0 && FLD(u16, self, 0xf4) == 0x5045) {
        func_02065804(data_0214a420, FLD(void *, self, 0xf8));
        FLD(void *, self, 0xf8) = NULL;
    }
    func_ov003_021d5900(self);
}

void func_ov009_021ff0f0(Ov009Actor *self) {
    if (self->unk_40->state == 0 && FLD(u16, self, 0xf4) == 0x5045) {
        func_02065804(data_0214a420, FLD(void *, self, 0xf8));
        FLD(void *, self, 0xf8) = NULL;
    }
    func_ov003_021d6054(self);
}

void func_ov009_021ff140(Ov009Actor *self) {
    func_ov003_021d0fc0(self);
    func_02049564(data_02097e4c, 1, 1);
    func_ov000_02187a20(data_ov000_021ccd54, 0xe);
    self->unk_ea_10 = 1;
}

void func_ov009_021ff188(Ov009Actor *self) {
    BOOL go;
    Ov009Actor *target;
    switch (self->unk_40->state) {
    case 0: {
        Ov009Sub48 *s48 = self->unk_48;
        Ov009Sub44 *s44;
        s48->unk_9a_1 = 0;
        s48->unk_9a_4 = 0;
        self->unk_38->unk_c2_0 = 0;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->unk_40->state++;
    }
        break;
    case 1:
        go = FALSE;
        if (self->unk_1a == 0) {
            go = TRUE;
        } else {
            target = func_ov000_0218d240(self);
            if (target != NULL && func_01ffc198(&target->pos, &self->pos, target->unk_64 + 0x8000)) {
                go = TRUE;
            }
        }
        if (go) {
            self->unk_38->unk_c2_0 = 1;
            func_ov000_02190cb0(self->unk_38, data_ov009_02216ace, 0x1000, 0);
            self->unk_40->state++;
        }
        break;
    case 2:
        if (func_ov000_02191120(self->unk_38)) {
            Ov009Sub44 *s44 = self->unk_44;
            s44->unk_22_0 = 1;
            s44->unk_22_1 = 1;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

void func_ov009_021ff2d8(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov009_02216ab6, 0xcd, 0);
        func_ov000_021915a0(self->unk_38);
    }
    func_ov003_021d6054(self);
}

void func_ov009_021ff31c(Ov009Actor *self) {
    if (self->unk_44 != NULL) {
        func_ov000_021984f4(self->unk_44, 0, 0);
    }
}

void func_ov009_021ff33c(Ov009Actor *self) {
    if (self->unk_48 != NULL) {
        func_ov000_0219864c(self->unk_48, 0, 0);
    }
}

void func_ov009_021ff35c(void) {
}

void func_ov009_021ff360(void) {
}

void func_ov009_021ff364(void) {
}

void func_ov009_021ff368(void) {
}

void func_ov009_021ff36c(void) {
}

void func_ov009_021ff370(void) {
}

void func_ov009_021ff374(void) {
}

void func_ov009_021ff378(void) {
}

void func_ov009_021ff37c(Ov009Actor *self) {
    self->v54();
}

void func_ov009_021ff390(Ov009Actor *self) {
    self->unk_ee_5 = 1;
    self->v70();
}

void func_ov009_021ff3b0(Ov009Actor *self) {
    self->unk_ee_2 = 2;
    self->v64();
}

void func_ov009_021ff3d4(Ov009Actor *self) {
    self->unk_ee_2 = 1;
    self->v64();
}

void func_ov009_021ff3f8(Ov009Actor *self) {
    func_ov003_021d3524(self);
}

void func_ov009_021ff404(Ov009Actor *self) {
    self->v80();
}

void func_ov009_021ff418(Ov009Actor *self) {
    self->v7c();
}

Ov009Actor *func_ov009_021ff42c(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov009Actor *func_ov009_021ff448(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

void func_ov009_021ff45c(Ov009Actor *self) {
    self->v80();
}

Ov009Actor *func_ov009_021ff470(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009Actor *func_ov009_021ff484(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov009Actor *func_ov009_021ff4a0(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009Actor *func_ov009_021ff4b4(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov009Actor *func_ov009_021ff4d0(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009Actor *func_ov009_021ff4e4(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov009Actor *func_ov009_021ff500(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009Actor *func_ov009_021ff514(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov009Actor *func_ov009_021ff530(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009Actor *func_ov009_021ff544(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov009Actor *func_ov009_021ff560(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009Actor *func_ov009_021ff574(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov009Actor *func_ov009_021ff590(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009Actor *func_ov009_021ff5a4(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov009Actor *func_ov009_021ff5c0(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009Actor *func_ov009_021ff5d4(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov009Actor *func_ov009_021ff5f0(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009Actor *func_ov009_021ff604(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov009Actor *func_ov009_021ff620(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov009Actor *func_ov009_021ff634(Ov009Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

void func_ov009_021ff650(Ov009Actor *self) {
    u8 *p = FLD(u8 *, FLD(void *, self, 0x4), 0x2c);
    s32 v;
    if (p == NULL) {
        return;
    }
    if (FLD(u32, self, 0x8) & 0x10) {
        v = FLD(u8, self, 0xae);
    } else {
        v = -1;
    }
    if (v == FLD(s32, p, 0)) {
        NNS_G3dGetCurrentMtx(p + 4, 0);
    }
}

void func_ov009_021ff690(Ov009Actor *self) {
    FLD(void *, self, 0x24) = (void *)func_ov009_021ff650;
    self->unk_92 = 3;
}

void func_ov009_021ff6a8(Ov009Actor *self) {
    func_ov003_021d112c(self);
    FLD(u16, self, 0xf0) = 0;
    FLD(u16, self, 0xf4) = 0;
    switch (self->kind) {
    case 0x5421:
        FLD(u16, self, 0xf2) = 0x50;
        if (self->unk_1a == 0) {
            func_ov000_02198360(self->unk_40, 0x20, 0);
            FLD(u16, self, 0xf4) = 0xf0;
        }
        break;
    case 0x5031:
        FLD(u16, self, 0xf2) = 0x64;
        break;
    }
    {
        Ov009Vec *v = &self->unk_48->unk_68;
        s32 x = v->x;
        s32 y = v->y;
        s32 z = v->z;
        self->unk_b8.x = x;
        self->unk_b8.y = y;
        self->unk_b8.z = z;
    }
}

}
