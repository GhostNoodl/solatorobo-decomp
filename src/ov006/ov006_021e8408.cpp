#include "ov006/SlotManager.h"
#include "ov006/ov006.h"
#include "nitro/fx.h"

typedef struct ov006_State021e8408 {
    u16 state;
} ov006_State021e8408;

typedef struct ov006_Body021e8408 {
    u8 unk0[0x22];
    u16 unk22_0 : 1;
    u16 unk22_1 : 1;
    u16 unk22_2 : 14;
} ov006_Body021e8408;

typedef struct ov006_Eff021e8408 {
    u8 unk0[0x24];
    int unk24;
    u8 unk28[0x14];
    fx32 unk3C;
} ov006_Eff021e8408;

typedef struct ov006_Old021e8408 {
    u8 unk0[0x1c];
    int unk1C;
} ov006_Old021e8408;

typedef struct ov006_Prop021e8408 {
    u8 unk0[0x38];
    void *unk38;
    u8 unk3C[4];
    ov006_State021e8408 *st;
    ov006_Body021e8408 *body;
    u8 unk48[0x28];
    VecFx32 pos;
    u16 rotX;
    u16 rotY;
    u16 rotZ;
    u8 unk82[0x11a];
    u16 unk19C_0 : 2;
    u16 unk19C_2 : 4;
    u16 unk19C_6 : 10;
    u8 unk19E;
    u8 unk19F;
    s32 unk1A0;
    u8 unk1A4[0xa];
    u16 unk1AE;
    u16 unk1B0;
    u8 unk1B2[8];
    u16 unk1BA;
    u16 unk1BC;
    u8 unk1BE[0x22];
    int unk1E0;
    u8 unk1E4[0x11];
    u8 unk1F5;
} ov006_Prop021e8408;

extern "C" {

extern void *data_0214a420;
extern void *data_02097e4c;

ov006_Eff021e8408 *func_02065f88(int id, VecFx32 *pos);
ov006_Old021e8408 *func_020657b0(void *a, int b);
void func_02063a14(ov006_Old021e8408 *p);
void func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
void func_ov000_0218996c(s32 a, s32 b);
void func_ov000_02198360(void *a, s32 b, s32 c);
void func_ov000_021911c8(void *a, s32 b);
s32 func_02040528(s32 range);
u16 func_01ffc128(u16 target, u16 cur, s32 rate, u32 minStep, u16 maxStep);
void func_ov006_021e96cc(ov006_Prop021e8408 *self);

void func_ov006_021e8408(ov006_Prop021e8408 *self) {
    self->body->unk22_1 = 0;
    switch (self->st->state) {
    case 0: {
        ov006_Eff021e8408 *eff;
        self->unk1A0 >>= 1;
        self->unk19C_2 = 0;
        eff = func_02065f88(0x322, &self->pos);
        if (eff != NULL) {
            ov006_Old021e8408 *old = func_020657b0(data_0214a420, self->unk1E0);
            if (old != NULL) {
                func_02063a14(old);
                old->unk1C = 4;
            }
            self->unk1E0 = eff->unk24;
            eff->unk3C = 0x1800;
        }
        func_02049f44(data_02097e4c, 0x79, &self->pos, 0);
        if (self->unk19E == data_ov006_021ec884->unk5) {
            func_ov000_0218996c(8, (u8)(self->unk1F5 - 10));
        }
        self->st->state++;
        break;
    }
    case 1:
        if (self->unk1F5 <= 10) {
            func_ov000_02198360(self->st, 2, 0);
        }
        self->unk1A0 -= 0x28;
        if (self->unk1A0 < 0xcd) {
            self->unk1A0 = 0xcd;
        }
        if (self->unk1F5 % 25 == 0) {
            VecFx32 at;
            ov006_Eff021e8408 *eff;
            at = self->pos;
            at.x += func_02040528(0x1000);
            at.z += func_02040528(0x1000);
            eff = func_02065f88(0x325, &at);
            if (eff != NULL) {
                ((VObj *)eff)->v0C(0xc00);
                ((VObj *)eff)->v30(&self->rotX);
            }
        }
        break;
    }
    self->rotX = func_01ffc128(0, self->rotX, 0x200, 1, 0x8000);
    self->rotZ = func_01ffc128(0, self->rotZ, 0x200, 1, 0x8000);
    self->unk1AE = func_01ffc128(self->rotX, self->unk1AE, 0x466, 1, 0x8000);
    self->unk1BA = func_01ffc128(self->rotX, self->unk1BA, 0x466, 1, 0x8000);
    self->unk1B0 = func_01ffc128(self->unk1BC, self->unk1B0, 0x466, 1, 0x8000);
    self->rotY = func_01ffc128(self->unk1BC, self->rotY, 0x466, 1, 0x8000);
    func_ov006_021e96cc(self);
    func_ov000_021911c8(self->unk38, (s16)(self->unk1A0 + 0x333));
}

}
