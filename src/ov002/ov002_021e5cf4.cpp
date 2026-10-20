#include "ov002/ov002.h"

extern "C" {

void NNS_G3dRenderObjSetCallBack(void *a, void *fn, int b, int c, int d);
void NNS_G3dRenderObjResetCallBack(void *a);
void func_ov002_021e4f48(void *self);

static inline void ov002_021e5b08_Scale(Vec3 *out, const Vec3 *in, s32 s) {
    out->x = FX_MUL(in->x, s);
    out->y = FX_MUL(in->y, s);
    out->z = FX_MUL(in->z, s);
}

void func_ov002_021e5b08(void *self) {
    VObject *o;
    if (FIELD(data_ov002_021f0f98[1], 0xd0, s32) <= FIELD(self, 0x18, s32)) {
        return;
    }
    switch (FIELD(data_ov002_021f0f98[1], 0xc, s32)) {
    case 1:
        o = FIELD(self, 0x1e0, VObject *);
        break;
    case 2:
        o = FIELD(self, 0x1e4, VObject *);
        break;
    default:
        o = FIELD(self, 0x1e0, VObject *);
        break;
    }
    o->v0x20();
    if (FIELD(self, 0x1f0, Bits8).b0) {
        Vec3 v;
        ov002_021e5b08_Scale(&v, &FIELD(self, 0x1b0, Vec3), 0x64000);
        v.z = 0x1000;
        NNS_G3dGlbSetBaseScale(&v);
        ov002_021e5b08_Scale(&v, &FIELD(self, 0x1a4, Vec3), 0x64000);
        v.z = FIELD(self, 0x20, s32);
        NNS_G3dGlbSetBaseTrans(&v);
        MI_Copy36B((u8 *)self + 0x1bc, data_020928b4);
        NNS_G3dGlb.fc &= ~0xa4;
    } else {
        MI_Copy36B((u8 *)self + 0x1bc, data_020928b4);
        NNS_G3dGlb.fc &= ~0xa4;
        NNS_G3dGlbSetBaseTrans((u8 *)self + 0x1a4);
        NNS_G3dGlbSetBaseScale((u8 *)self + 0x1b0);
    }
    NNS_G3dGlbFlushVP();
    data_ov002_021f0f98[0] = self;
    NNS_G3dRenderObjSetCallBack((u8 *)self + 0x68, (void *)func_ov002_021e4f48, 0, 6, 2);
    NNS_G3dDraw((u8 *)self + 0x68);
    NNS_G3dRenderObjResetCallBack((u8 *)self + 0x68);
    data_ov002_021f0f98[0] = NULL;
}


void func_ov002_021e5cf4(void) {
}

BOOL func_ov002_021e5cf8(void *self) {
    return FIELD(self, 0xc, s32) >= 3;
}

void func_ov002_021e5d0c(void *self) {
    FIELD(self, 0x4, s32) = 2;
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x4c, s32) = 0;
    FIELD(self, 0x50, s32) = 0;
    FIELD(self, 0x54, s32) = 0;
    FIELD(self, 0x58, s32) = -1;
    FIELD(self, 0x5c, s32) = -1;
    FIELD(self, 0x60, s32) = 0;
    FIELD(self, 0x64, s32) = 0;
    FIELD(self, 0x68, s32) = 0;
    FIELD(self, 0x6c, s32) = 0;
    FIELD(self, 0x70, s32) = 0;
    FIELD(self, 0x74, s32) = 0;
    FIELD(self, 0x78, s32) = 0;
    FIELD(self, 0x7c, s32) = 0;
    FIELD(self, 0x80, s32) = 0;
    FIELD(self, 0x84, s32) = 0;
    FIELD(self, 0x88, s32) = 0x1000;
    FIELD(self, 0x8c, s32) = 0;
    MI_CpuFill8((u8 *)self + 0x90, 0, 0x58);
    FIELD(self, 0xe8, s32) = 0;
}

void func_ov002_021e5d88(void *self) {
    if (FIELD(self, 0x64, void *) != NULL) {
        func_0203df0c(FIELD(self, 0x64, void *));
        FIELD(self, 0x64, void *) = NULL;
    }
    if (FIELD(self, 0x68, void *) != NULL) {
        func_0203df0c(FIELD(self, 0x68, void *));
        FIELD(self, 0x68, void *) = NULL;
    }
    if (FIELD(self, 0x6c, void *) != NULL) {
        func_0203df0c(FIELD(self, 0x6c, void *));
        FIELD(self, 0x6c, void *) = NULL;
    }
    if (FIELD(self, 0x70, void *) != NULL) {
        func_0203df0c(FIELD(self, 0x70, void *));
        FIELD(self, 0x70, void *) = NULL;
    }
    if (FIELD(self, 0x74, void *) != NULL) {
        func_0203df0c(FIELD(self, 0x74, void *));
        FIELD(self, 0x74, void *) = NULL;
    }
    if (FIELD(self, 0x14, s32) != 0) {
        if (FIELD(self, 0x4c, void *) != NULL) {
            func_02035acc(FIELD(self, 0x4c, void *), FIELD(self, 0x50, void *), 6);
        } else {
            func_02036838(data_02097cdc, FIELD(self, 0x50, void *), 6, 0);
        }
    }
}

BOOL func_ov002_021e5e3c(void) {
    return TRUE;
}

BOOL func_ov002_021e5e44(void *self) {
    BOOL r = FALSE;
    switch (FIELD(self, 0x10, s32)) {
    case 0:
        if (FIELD(self, 0x4c, void *) != NULL) {
            func_020359fc(FIELD(self, 0x4c, void *), FIELD(self, 0x50, void *), 6, 0);
        } else {
            func_020359d0(FIELD(self, 0x50, void *), 6, 0);
        }
        FIELD(self, 0x14, s32) = 1;
        FIELD(self, 0x10, s32)++;
        break;
    case 1:
        if (FIELD(self, 0x4c, void *) != NULL) {
            if (func_02035bd4(FIELD(self, 0x4c, void *), FIELD(self, 0x50, void *), 6) == 0) {
                break;
            }
            {
                void *t = func_02035f30(FIELD(self, 0x4c, void *), FIELD(self, 0x50, void *), 6);
                FIELD(self, 0x60, void *) = func_02034ff8(t, FIELD(self, 0x50, void *));
            }
        } else {
            if (func_02035b90(FIELD(self, 0x50, void *), 6) == 0) {
                break;
            }
            FIELD(self, 0x60, void *) = func_02035d2c(FIELD(self, 0x50, void *));
        }
    case 10:
        FIELD(self, 0x10, s32) = -1;
        r = TRUE;
        break;
    }
    return r;
}

BOOL func_ov002_021e5f2c(void) {
    return TRUE;
}

BOOL func_ov002_021e5f34(void *self) {
    Bits8 *fl = &FIELD(self, 0xe8, Bits8);
    s32 lim = FIELD(data_ov002_021f0f98[1], 0xd0, s32);
    if (fl->b2) {
        return FALSE;
    }
    if (!fl->b0 || lim <= FIELD(self, 0x18, s32)) {
        return TRUE;
    }
    if (!fl->b1) {
        BOOL t = FALSE;
        if (FIELD(self, 0x8c, s32) >= 0 && FIELD(self, 0x7c, s32) > FIELD(self, 0x8c, s32)) {
            t = TRUE;
        }
        if (t) {
            FIELD(self, 0xe8, Bits8).b1 = 1;
        }
    }
    func_ov002_021e63f0(self);
    if (!FIELD(self, 0xe8, Bits8).b1) {
        FIELD(self, 0x7c, s32) += FIELD(data_ov002_021f0f98[1], 0xd8, s32);
    }
    return TRUE;
}

}
