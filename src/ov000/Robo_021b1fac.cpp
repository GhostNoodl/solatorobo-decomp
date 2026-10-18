#include "types.h"

typedef struct {
    u8 pad_00[0x50];
    u32 unk_50;
    u8 pad_54[0x46];
    u16 unk_9a;
} Sub021b1fac;

typedef struct {
    u8 pad_00[0x10];
    u32 unk_10;
} Data021b1fac;

typedef struct {
    u8 pad_00[0x48];
    Sub021b1fac *unk_48;
    u8 pad_4c[0x24];
    s32 unk_70;
    s32 unk_74;
    u8 pad_78[0x24];
    s32 unk_9c;
    s32 unk_a0;
    u8 pad_a4[0xa80];
    u32 unk_b24_0 : 12;
    u32 unk_b24_12 : 2;
    u32 unk_b24_14 : 18;
    u8 pad_b28[0x80];
    s32 unk_ba8;
} Robo021b1fac;

extern "C" {

extern Data021b1fac *data_0214a424;
void func_ov000_021b209c(Robo021b1fac *self, BOOL a);
void func_ov000_0218dbe0(Robo021b1fac *self, s32 a);
void func_ov000_021987b8(Sub021b1fac *p, s32 a, s32 b, s32 c);

void func_ov000_021b1fac(Robo021b1fac *self, BOOL a, s32 b) {
    s32 ox;
    s32 oz;
    if (self->unk_b24_12) {
        func_ov000_021b209c(self, a);
        return;
    }
    ox = self->unk_70;
    oz = self->unk_74;
    if (a) {
        self->unk_48->unk_9a |= 0x20;
    }
    func_ov000_0218dbe0(self, 0);
    if (ox != self->unk_70 || oz != self->unk_74) {
        s32 t = self->unk_ba8 + self->unk_9c;
        self->unk_ba8 = t;
        if (t > 0x1000) {
            Data021b1fac *g = data_0214a424;
            u32 v = g->unk_10 + ((u32)t >> 12);
            if (v >= 999999) {
                g->unk_10 = 999999;
            } else {
                g->unk_10 = v;
            }
            self->unk_ba8 &= 0xfff;
        }
    }
    func_ov000_021987b8(self->unk_48, b, 0, 0);
    if (self->unk_a0 < 0 && (self->unk_48->unk_50 & 0x20000000)) {
        self->unk_a0 = 0;
    }
}

}
