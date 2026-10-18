#include "ov012/ov012.h"

extern "C" {
void func_ov012_02206e9c(Ov012Actor *self) {
    func_ov000_02198360(self->unk_40, 0x15, 0);
}
}

extern "C" {
void func_ov012_02206eb4(Ov012Actor *self) {
    if (FLD(u32, self, 0xdc) & 0x200000) {
        if (func_020657b0(data_0214a420, FLD(void *, self, 0xe4)) != NULL) {
            return;
        }
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->v08();
    } else {
        func_ov000_0219763c(self);
    }
}
}

extern "C" {
void func_ov012_02206f18(Ov012Actor *self) {
    void *list[0x20];
    s32 r = self->unk_64 + 0x4cd;
    u16 k;
    s32 n;
    s32 i;
    if (r < 0xccd) {
        r = 0xccd;
    }
    self->unk_48->unk_44 = r;
    k = FLD(u16, func_ov000_02199ba0(FLD(void *, self, 0x4c)), 0xc) & 0xf000;
    n = func_ov000_0219a510(self, ~(1 << (k >> 12)), &self->pos, r, 0, list);
    if (n == 0) {
        return;
    }
    for (i = 0; i < n; i++) {
        if (list[i] != NULL) {
            void *o = func_ov000_021985c0(list[i]);
            if (o != NULL) {
                void *p = FLD(void *, o, 0x4c);
                if (p == NULL || k != (u16)(FLD(u16, p, 0x1c) & 0xf000)) {
                    func_ov003_021f0c60(self, 0);
                    func_ov000_02198360(self->unk_40, 0x15, 0);
                    return;
                }
            }
        }
    }
}
}

extern "C" {
extern u8 data_ov012_0220b0b8[];
#pragma force_active on
Ov012Actor *func_ov012_02207018(Ov012Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov012_0220b0b8;
    FLD(s32, self, 0xd0) = 0;
    FLD(s32, self, 0xd4) = 0;
    return self;
}
#pragma force_active reset
}

extern "C" {
extern u8 data_ov012_0220b0b8[];
void *func_ov012_02207044(void *self) {
    FLD(void *, self, 0) = data_ov012_0220b0b8;
    Ov012_FreeFx(self, 0xd4);
    func_ov000_0219429c(self);
    return self;
}
}

extern "C" {
extern u8 data_ov012_0220b0b8[];
void *func_ov012_022070b4(void *self) {
    FLD(void *, self, 0) = data_ov012_0220b0b8;
    Ov012_FreeFx(self, 0xd4);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}
}

extern "C" {
void func_ov012_0220712c(Ov012Actor *self) {
    func_ov000_02194758(self);
    FLD(s32 *, self, 0xd4) = Ov012_NewFx();
    func_ov000_02198360(self->unk_40, 0xb, 0);
}
}

extern "C" {
void func_ov012_02207164(Ov012Actor *self) {
    func_ov000_021953b4(self);
    func_ov003_021dacfc(FLD(void *, self, 0xd4));
}
}
