#include "ov002/ov002.h"

extern "C" {

s32 func_02049130(s32 t, s32 a, s32 b);
void func_ov002_021e398c(void *m, u8 dir);
void func_ov002_021e3874(s32 *pos, u8 type, u8 a);
void *func_02065f88(s32 id, s32 *pos);

typedef struct {
    u16 lo : 8;
    u16 x : 4;
    u16 z : 4;
} Bits50;

typedef struct {
    u16 x : 4;
    u16 z : 4;
    u16 dir : 2;
    u16 hi : 6;
} Bits52;

void func_ov002_021d8860(void *self) {
    s32 t = 0xd2 - FIELD(self, 0xa4, s32);
    if (t < 0x78) {
        FIELD(self, 0x9c, s32) = FX_MUL(FX_SINCOS((((t * 0x444) % 0x7fff) >> 4) * 2), 0xb5c) + 0x429;
        if (t % 30 == 0) {
            func_02049a48(data_02097e4c, 0x44, -1, -1, -1);
        }
    } else if (t == 0x78) {
        s32 org[2];
        s32 pos[2];
        s32 out[3];
        u8 m[0x24];
        s32 v[3];
        func_02049a48(data_02097e4c, 0x5c, -1, -1, -1);
        pos[0] = FIELD(self, 0x54, s32);
        pos[1] = FIELD(self, 0x58, s32);
        org[0] = FIELD(self, 0x64, s32);
        org[1] = FIELD(self, 0x68, s32);
        func_ov002_021e3b0c(out, pos, org);
        func_ov002_021e398c(m, FIELD(self, 0x52, Bits52).dir);
        v[0] = FX_MUL((FIELD(self, 0x50, Bits50).x - FIELD(self, 0x52, Bits52).x * 2) << 11, 0x28f) - 0x147;
        v[1] = 0;
        v[2] = FX_MUL((FIELD(self, 0x50, Bits50).z - FIELD(self, 0x52, Bits52).z * 2) << 11, 0x28f) - 0x147;
        MTX_MultVec33(v, m, v);
        out[0] += v[0];
        out[1] = 0x266;
        out[2] += v[2];
        func_ov002_021e3874(out, FIELD(self, 0x4a, u8), FIELD(self, 0x50, Bits50).x);
        {
            void *p = func_02065f88(0x6d, out);
            if (p != NULL) {
                FIELD(p, 0x3c, s32) = 0x800;
            }
        }
    } else if (t >= 0xb4) {
        FIELD(self, 0x9c, s32) = 0;
    } else {
        FIELD(self, 0x9c, s32) = func_02049130(FX_Div((t - 0x78) << 12, 0x3c000), 0xf85, 0);
    }
}

}
