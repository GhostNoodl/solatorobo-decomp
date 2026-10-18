#include "ov000/LoCommon.h"
#include "nitro/fx.h"

extern "C" {

extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
void func_02043d20(void *obj, int a);
void NNS_G3dGeBufferOP_N(int cmd, const void *data, int count);

static inline void G3_Vec021601c4(int cmd, int x, int y, int z) {
    int v[3];
    v[0] = x;
    v[1] = y;
    v[2] = z;
    NNS_G3dGeBufferOP_N(cmd, v, 3);
}

static inline BOOL IsB3_021601c4(void *self) {
    return LBIT(self, 0xc).b3 ? TRUE : FALSE;
}

static inline void VecAdd021601c4(const VecFx32 *a, const VecFx32 *b, VecFx32 *o) {
    o->x = a->x + b->x;
    o->y = a->y + b->y;
    o->z = a->z + b->z;
}

void func_ov000_021601c4(VObj *self) {
    VecFx32 pos;
    s32 sn;
    s32 sy;
    s32 sx;
    s32 kind;
    if (!IsB3_021601c4(self)) {
        return;
    }
    func_02043d20(data_02097d48 + 0x8b0, 0);
    G3_Vec021601c4(0x1b, 0x1000, 0x1000, 0x1000);
    sn = FX_SinCosTable_[((LFLD(s32, self, 0x34) << 14) >> 16) * 2];
    pos.x = LFLD(s32, self, 0x74) << 12;
    pos.y = LFLD(s32, self, 0x78) << 12;
    pos.z = 0;
    sx = 0x1000;
    sy = 0x1000;
    kind = LFLD(s32, self, 0x28);
    if (kind == 0) {
        sy = sn;
        if (sn == 0) {
            return;
        }
    }
    if (kind == 1 || kind == 3) {
        sx = sn;
    }
    if (kind == 2 || kind == 3) {
        VecFx32 d;
        d.x = LO_FX_MUL(0x1000 - sn, LFLD(s32, self, 0x38) << 12);
        d.y = LO_FX_MUL(0x1000 - sn, LFLD(s32, self, 0x3c) << 12);
        d.z = 0;
        VecAdd021601c4(&pos, &d, &pos);
    }
    if (LBIT(self, 0xc).b9) {
        pos.x -= (LFLD(s32, self, 0x50) >> 1) << 12;
    }
    pos.z = LFLD(s32, self, 0x7c);
    self->vfunc_3c(sn, &pos, sx, sy);
}

}
