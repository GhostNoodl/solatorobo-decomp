#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e61b4(void *self) {
    char name[0x10];
    void *anm;
    FIELD(self, 0x4, s32) = 3;
    MI_CpuFill8(name, 0, sizeof(name));
    if (FIELD(self, 0x54, void *) != NULL) {
        STD_CopyLString(name, FIELD(self, 0x54, void *), sizeof(name));
    } else {
        STD_CopyLString(name, FIELD(self, 0x50, void *), sizeof(name));
    }
    anm = NNS_G3dGetAnmByName(*FIELD(self, 0x60, void **), name);
    FIELD(self, 0x64, void *) = func_0203de84(0x100, 4);
    FIELD(FIELD(self, 0x64, void *), 0x8, void *) = anm;
    FIELD(FIELD(self, 0x64, void *), 0x0, s32) = 0;
    FIELD(FIELD(self, 0x64, void *), 0x4, s32) = 0x1000;
    FIELD(FIELD(self, 0x64, void *), 0xc, void *) = (void *)NNS_G3dFuncAnmJntNsBcaDefault;
    FIELD(FIELD(self, 0x64, void *), 0x10, s32) = 0;
    FIELD(FIELD(self, 0x64, void *), 0x14, s32) = 0;
    FIELD(FIELD(self, 0x64, void *), 0x18, u8) = 0x7f;
    FIELD(FIELD(self, 0x64, void *), 0x19, u8) = 0;
    func_ov002_021e63f0(self);
    func_ov002_021e6290(self);
}

void func_ov002_021e6290(void *self) {
    void *m;
    s32 cur;
    s32 lim;
    s32 t;
    if (FIELD(self, 0x64, void *) != NULL) {
        m = FIELD(self, 0x64, void *);
    } else if (FIELD(self, 0x68, void *) != NULL) {
        m = FIELD(self, 0x68, void *);
    } else if (FIELD(self, 0x6c, void *) != NULL) {
        m = FIELD(self, 0x6c, void *);
    }
    t = FIELD(self, 0x1c, s32);
    lim = (FIELD(FIELD(m, 8, void *), 4, u16) << 12) - 0x1000;
    FIELD(self, 0x80, s32) = lim;
    cur = FIELD(data_ov002_021f0f98[1], 0xd0, s32);
    if (t < 0) {
        FIELD(self, 0x8c, s32) = -1;
    } else if (FIELD(self, 0x78, s32) == 0) {
        FIELD(self, 0x8c, s32) = t - FIELD(self, 0x18, s32);
    } else if (FIELD(self, 0x78, s32) == 1) {
        FIELD(self, 0x8c, s32) = ((s32)_s32_div_f(t - FIELD(self, 0x18, s32), lim) + 1) * lim;
    }
    {
        FIELD(self, 0x7c, s32) = cur > FIELD(self, 0x18, s32) ? cur - FIELD(self, 0x18, s32) : 0;
    }
    FIELD(self, 0xe8, Bits8).b0 = 1;
}

void func_ov002_021e6360(void *self) {
    u8 *o = FIELD(self, 0x48, u8 *);
    if (FIELD(self, 4, s32) == 2) {
        if (FIELD(self, 0x64, void *) != NULL) {
            NNS_G3dRenderObjRemoveAnmObj(o + 0x68, FIELD(self, 0x64, void *));
        }
        if (FIELD(self, 0x68, void *) != NULL) {
            NNS_G3dRenderObjRemoveAnmObj(o + 0x68, FIELD(self, 0x68, void *));
        }
        if (FIELD(self, 0x6c, void *) != NULL) {
            NNS_G3dRenderObjRemoveAnmObj(o + 0x68, FIELD(self, 0x6c, void *));
        }
        if (FIELD(self, 0x70, void *) != NULL) {
            NNS_G3dRenderObjRemoveAnmObj(o + 0x68, FIELD(self, 0x70, void *));
        }
        if (FIELD(self, 0x74, void *) != NULL) {
            NNS_G3dRenderObjRemoveAnmObj(o + 0x68, FIELD(self, 0x74, void *));
        }
    } else {
        FIELD(self, 0xe8, Bits8).b2 = 1;
    }
}

}
