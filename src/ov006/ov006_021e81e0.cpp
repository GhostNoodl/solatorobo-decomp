#include "ov006/SlotManager.h"

typedef struct ov006_Flags021e81e0 {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 rest : 14;
} ov006_Flags021e81e0;

typedef struct ov006_Sub021e81e0 {
    u8 unk0[0x22];
    ov006_Flags021e81e0 unk22;
} ov006_Sub021e81e0;

typedef struct ov006_Prop021e81e0 {
    u8 unk0[0x38];
    void *unk38;
    u8 unk3C[8];
    ov006_Sub021e81e0 *unk44;
    u8 unk48[0x64];
    s16 *unkAC;
    u8 unkB0[0xee];
    u8 unk19E;
    u8 unk19F;
    int unk1A0;
    u8 unk1A4[2];
    u16 unk1A6;
    u8 unk1A8[0x24];
    int unk1CC;
    u8 unk1D0[0x2e];
    s16 unk1FE;
} ov006_Prop021e81e0;

extern "C" {

extern char data_ov006_021ec4a7[];
extern void *data_02097e4c;
u32 func_ov006_021d8cb8(void);
void func_ov000_02190cb0(void *a, const void *b, int c, int d);
void func_ov000_021915a0(void *a);
void func_ov000_021911c8(void *a, s16 b);
void func_ov006_021e9c5c(ov006_Prop021e81e0 *self);
void func_ov006_021e86dc(ov006_Prop021e81e0 *self);
void func_ov006_021e8ef8(ov006_Prop021e81e0 *self);
void func_ov006_021e96cc(ov006_Prop021e81e0 *self);
s16 func_02049afc(void *a, s16 b);
void func_02049bb4(void *a);
void func_0204a094(void *a, s16 b, int c);

static inline BOOL ov006_Prop_IsOver(ov006_Prop021e81e0 *self) {
    BOOL r = FALSE;
    if (self->unk19F > data_ov006_021ec884->unk8->unkB) {
        r = TRUE;
    }
    return r;
}

void func_ov006_021e81e0(ov006_Prop021e81e0 *self) {
    if (ov006_Prop_IsOver(self) || func_ov006_021d8cb8() <= 1) {
        self->unk44->unk22.b1 = 0;
    }
    func_ov000_02190cb0(self->unk38, data_ov006_021ec4a7, 0x1000, 0);
    func_ov000_021915a0(self->unk38);
    self->unk1CC++;
    func_ov006_021e9c5c(self);
    func_ov006_021e86dc(self);
    func_ov006_021e8ef8(self);
    func_ov006_021e96cc(self);
    func_ov000_021911c8(self->unk38, (s16)(((s64)self->unkAC[0] * (self->unk1A0 + 0x333) + 0x800) >> 12));
    if (self->unk19E != data_ov006_021ec884->unk5) {
        return;
    }
    if (self->unk1FE < 0) {
        self->unk1FE = func_02049afc(data_02097e4c, self->unkAC[1]);
        return;
    }
    if (self->unk1A6 & 3) {
        func_02049bb4(data_02097e4c);
        self->unk1FE = func_02049afc(data_02097e4c, self->unkAC[1]);
    }
    func_0204a094(data_02097e4c, self->unk1FE, (self->unk1A0 - 0xe66) >> 3);
}

}
