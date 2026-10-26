#include "ov006/Tasks.h"
#include "nitro/fx.h"

typedef struct ov006_Unk02097e40 {
    u8 unk0[0x32];
    u16 unk32;
} ov006_Unk02097e40;

extern "C" {

extern ov006_Unk02097e40 *data_02097e40;

void func_ov006_021dabcc(ov006_Slot *self, void *buf);
void func_ov006_021e4a80(ov006_Unk021ec888 *self, u16 a, int b, const void *src, u32 size);
void func_ov000_02162a20(ov006_Actor58 *self);
void func_ov000_02162a58(ov006_Actor58 *self);
void func_ov006_021e0af4(ov006_Unk68 *self);
void func_ov006_021e0b80(ov006_Unk68 *self);
void func_ov006_021e10d0(ov006_Unk021e139c *self);
void func_ov006_021e1180(ov006_Unk021e139c *self);
void func_ov006_021e463c(ov006_Unk021ec888 *self);
void func_ov006_021cd580(int a, int b, int c);
void func_ov006_021d2ff0(ov006_TaskD1F *self);
void func_ov006_021d30d4(ov006_TaskD1F *self);
void func_ov006_021d3224(ov006_TaskD1F *self);
void func_ov006_021db258(void);
u16 func_ov006_021e60e8(int type, u16 mask);
void func_ov006_021e5e00(ov006_Unk021ec888 *self);

void func_ov006_021d2b9c(ov006_TaskD1F *self) {
    u16 trg;
    if (self->base.state != 0) {
        return;
    }
    trg = data_02097dc8->unk12;
    if (trg & 2) {
        if (self->unk48) {
            if (self->base.unkC == 0) {
                func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
            }
            self->base.state = 5;
            self->base.subState = 0;
        } else {
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
        }
        return;
    }
    if (!(trg & 1)) {
        return;
    }
    func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
    self->base.state = 1;
    self->base.subState = 0;
}

static inline void ov006_Actor58_SetPos(ov006_Actor58 *self, s32 x, s32 y, s32 z) {
    self->pos.x = x;
    self->pos.y = y;
    self->pos.z = z;
}

static inline void ov006_Actor58_SetRot(ov006_Actor58 *self, s16 x, s16 y, s16 z) {
    self->rot.x = x;
    self->rot.y = y;
    self->rot.z = z;
}

void func_ov006_021d2c84(ov006_TaskD1F *self) {
    u8 buf[0x18];
    int i;
    if (self->base.unk8 == 0xd) {
        if (self->base.unkC != 0) {
            func_ov006_021db060(data_ov006_021ec884, data_ov006_021ec884->unk5)->unkC = self->unk4A;
            func_ov006_021dabcc(func_ov006_021db060(data_ov006_021ec884, data_ov006_021ec884->unk5), buf);
            func_ov006_021e4a80(data_ov006_021ec888, self->unk49, 1, buf, 0x18);
        } else {
            func_ov006_021db060(data_ov006_021ec884, data_ov006_021ec884->unk5)->unkC = self->unk4A;
        }
    }
    VCALL(self->unk54, 1C);
    func_ov000_02162a20(self->unk58);
    {
        ov006_Actor58 *a = self->unk58;
        // x is read through a const view, so it is not merged with the earlier read of a->pos.
        ov006_Actor58_SetPos(a, ((const ov006_Actor58 *)a)->pos.x, FX_Mul(FX_SinCosTable_[((u16)(self->unk44 << 8) >> 4) * 2], 0x4cd), a->pos.z);
    }
    ov006_Actor58_SetRot(self->unk58, 0, self->unk44 * 0x90, 0);
    self->unk44 = (u16)(self->unk44 + 1);
    if (self->unk58->unk6B8 / 10 == 1) {
        self->unk44 = 0;
    }
    VCALL(self->unk5C, 1C);
    VCALL(self->unk60, 1C);
    VCALL(self->unk64, 1C);
    func_ov006_021e0af4(self->unk68);
    for (i = 0; i < 4; i++) {
        func_ov006_021e10d0(self->gauges[i]);
    }
}

}
