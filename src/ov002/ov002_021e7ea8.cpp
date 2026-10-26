#include "ov002/ov002.h"

extern "C" {

void GXx_SetMasterBrightness_(vu16 *reg, int v);
static inline void GX_SetMasterBrightness(int b) { GXx_SetMasterBrightness_((vu16 *)0x400006c, b); }
static inline void GXS_SetMasterBrightness(int b) { GXx_SetMasterBrightness_((vu16 *)0x400106c, b); }

int func_0203ca84(int a);
void func_02043904(void *p);
void func_020656b4(void *p);
BOOL func_ov002_021e828c(void *self);
BOOL func_ov002_021e86a0(void *self);
BOOL func_ov002_021e8828(void *self);
void func_ov002_021e8c0c(void *self);

static inline void ov002_SetBright(int v) {
    GX_SetMasterBrightness(v);
    GXS_SetMasterBrightness(v);
}

static inline void G3X_EdgeMarking(BOOL e) {
    if (e) *(vu16 *)0x04000060 = (u16)((*(vu16 *)0x04000060 & ~0x3000) | 0x20);
    else *(vu16 *)0x04000060 &= ~(0x3000 | 0x20);
}
static inline void ov002_SetState(void *self, s32 st) {
    FIELD(self, 0x4, s32) = st;
    FIELD(self, 0x8, s32) = 0;
}

static inline s32 FxM7ea8(s32 a, s32 b) { return (s32)(((s64)a * b + 0x800) >> 12); }
BOOL func_ov002_021e7ea8(void *self) {
    BOOL ret = TRUE;
    u8 *gx;
    BOOL done;
    int mode;
    u8 *g;
    s32 b;
    FIELD(self, 0xc, s32) = FIELD(data_02097d48, 0xa30, Bits8).b4 ? 1 : 2;
    switch (FIELD(self, 0x4, s32)) {
    case 0: {
        b = 0;
        switch (FIELD(self, 0x130, s32)) {
        case 0:
            b = func_0203ca84(0);
            break;
        case 1:
            b = 0x10;
            break;
        case 2:
            b = -0x10;
            break;
        }
        ov002_SetBright(b);
        func_0203caf8(-1);
        FIELD(self, 0x13c, s32) = b << 12;
        FIELD(self, 0x140, s32) = 0;
        FIELD(self, 0x144, s32) = 0;
        gx = data_02097d48 + 0x8b0;
        MIi_CpuCopy32(gx, (u8 *)self + 0x14c, 0x180);
        func_02043904(gx);
        FIELD(gx, 0, Bits8).b4 = 0;
        FIELD(gx, 0, Bits8).b5 = 1;
        G3X_EdgeMarking(FALSE);
        FIELD(gx, 0xac, u16) = 0x4a52;
        FIELD(gx, 0xae, u16) = 0x1084;
        FIELD(gx, 0xb0, u16) = 0x739c;
        FIELD(gx, 0xb2, u16) = 0;
        func_02043b20(gx);
        FIELD(self, 0x148, u8) = 1;
        FIELD(data_02097d48, 0x4, s32) = 2;
        FIELD(data_0214a420, 0x10, u8) = 1;
        FIELD(data_0214a420, 0x34, u8) = 1;
        ov002_SetState(self, 1);
        break;
    }
    case 1:
        if (!func_ov002_021e828c(self)) {
            break;
        }
        ov002_SetState(self, 2);
    case 2:
        if (!func_ov002_021e86a0(self)) {
            break;
        }
        ov002_SetState(self, 3);
    case 3:
        func_ov002_021e8828(self);
        if (FIELD(self, 0x10, u8) == 0) {
            ov002_SetState(self, 4);
        }
        break;
    case 4: {
        if (FIELD(self, 0x144, s32) < 0xa000) {
            {
                s32 t_0 = FIELD(self, 0x144, s32);
                b = (FIELD(self, 0x13c, s32) + FxM7ea8(FX_Div(FIELD(self, 0x140, s32) - FIELD(self, 0x13c, s32), 0xa000), t_0)) >> 12;
                ov002_SetBright(b);
                FIELD(self, 0x144, s32) += 0x1000;
            }
        }
        if (func_ov002_021e8828(self)) {
            break;
        }
        b = 0;
        switch (FIELD(self, 0x134, s32)) {
        case 0:
            b = FIELD(self, 0x138, u16) > 0x4210 ? 0x10 : -0x10;
            break;
        case 1:
            b = 0x10;
            break;
        case 2:
            b = -0x10;
            break;
        }
        FIELD(self, 0x13c, s32) = 0;
        FIELD(self, 0x140, s32) = b << 12;
        FIELD(self, 0x144, s32) = 0;
        ov002_SetState(self, 5);
    }
    case 5: {
        done = FALSE;
        if (FIELD(self, 0x144, s32) >= 0x14000) {
            mode = FIELD(self, 0x140, s32) > 0 ? 1 : 2;
            func_0203cc58(0x1000, mode, 0);
            done = TRUE;
            func_0203cc58(0x1000, mode, 1);
        } else {
            {
                s32 t_1 = FIELD(self, 0x144, s32);
                b = (FIELD(self, 0x13c, s32) + FxM7ea8(FX_Div(FIELD(self, 0x140, s32) - FIELD(self, 0x13c, s32), 0x14000), t_1)) >> 12;
                ov002_SetBright(b);
                FIELD(self, 0x144, s32) += 0x1000;
            }
        }
        if (done) {
            func_ov002_021e8c0c(self);
            func_020656b4(data_0214a420);
            FIELD(data_0214a420, 0x10, u8) = 0;
            FIELD(data_02097d48, 0x4, s32) = 1;
            ov002_SetState(self, 6);
        }
        break;
    }
    case 6: {
        ov002_SetBright(0);
        g = data_02097d48;
        MIi_CpuCopy32((u8 *)self + 0x14c, g + 0x8b0, 0x180);
        func_02043b20(g + 0x8b0);
        FIELD(self, 0x148, u8) = 0;
        ov002_SetState(self, 7);
    }
    case 7:
        ret = FALSE;
        break;
    }
    return ret;
}

}
