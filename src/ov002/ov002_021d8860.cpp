#include "ov002/ov002.h"

extern "C" {

s32 Interp_SinLerp(s32 t, s32 a, s32 b);
void func_ov002_021e398c(void *m, u8 dir);
void *func_ov002_021e3874(s32 *pos, u8 type, u8 a);

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

void func_ov002_021d8860(Obj021efe9c *self) {
    s32 t = 0xd2 - self->unk_a4;
    if (t < 0x78) {
        self->unk_9c = FX_MUL(FX_SINCOS((((t * 0x444) % 0x7fff) >> 4) * 2), 0xb5c) + 0x429;
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
        pos[0] = self->unk_54;
        pos[1] = self->unk_58;
        org[0] = self->unk_64;
        org[1] = self->unk_68;
        func_ov002_021e3b0c(out, pos, org);
        func_ov002_021e398c(m, FIELD(self, 0x52, Bits52).dir);
        v[0] = FX_MUL((FIELD(self, 0x50, Bits50).x - FIELD(self, 0x52, Bits52).x * 2) << 11, 0x28f) - 0x147;
        v[1] = 0;
        v[2] = FX_MUL((FIELD(self, 0x50, Bits50).z - FIELD(self, 0x52, Bits52).z * 2) << 11, 0x28f) - 0x147;
        MTX_MultVec33((VecFx32 *)v, (MtxFx33 *)m, (VecFx32 *)v);
        out[0] += v[0];
        out[1] = 0x266;
        out[2] += v[2];
        func_ov002_021e3874(out, self->unk_4a, FIELD(self, 0x50, Bits50).x);
        {
            void *p = func_02065f88(0x6d, (VecFx32 *)out); // out is s32[3]
            if (p != NULL) {
                FIELD(p, 0x3c, s32) = 0x800;
            }
        }
    } else if (t >= 0xb4) {
        self->unk_9c = 0;
    } else {
        self->unk_9c = Interp_SinLerp(FX_Div((t - 0x78) << 12, 0x3c000), 0xf85, 0);
    }
}

}
