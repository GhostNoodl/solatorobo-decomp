#include "ov012/ov012.h"

extern "C" {
void func_ov012_02206374(Ov012Actor *self) {
    if (FLD(u16, func_ov000_02199ba0(FLD(void *, self, 0x4c)), 0xe) == 0x1000 && self->unk_40->state == 0 &&
        !(FLD(u32, self, 0xd0) & 0x100000)) {
        u8 b = 2;
        func_ov000_0219bd20(0x5c03, self->kind, 6, 1, 1, &b);
    }
    func_ov000_02195d88(self);
}
}

extern "C" {
void func_ov012_022063e8(Ov012Actor *self) {
    func_ov000_02198360(self->unk_40, 0x15, 0);
}
}

extern "C" {
void func_ov012_02206400(Ov012Actor *self) {
    Ov012V *e;
    if (FLD(u32, self, 0xd0) & 0x100000) {
        if (self->unk_1a != 0) {
            return;
        }
        self->unk_38->unk_c2_0 = 0;
        func_02049de8(data_02097e4c, 0x4f);
        e = func_02065f88(4, &self->pos);
        e->v0c(0xe66);
        func_020639d4(e, 0x56, 0);
        func_02065f88(0x6b, &self->pos);
        e = func_02065f88(0x57c, &self->pos);
        e->v0c(0x1b33);
        func_020639d4(e, 0x79, 0);
        func_ov000_0218996c(10, 10);
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->v08();
        self->unk_1a = 1;
    } else {
        func_ov000_0219763c(self);
    }
}
}

extern "C" {
void func_ov012_02206508(Ov012Actor *self) {
    u8 i;
    for (i = 1; i < 3; i++) {
        Ov012SpawnDesc d;
        Ov012Actor *o;
        Ov012Spawn_Init(&d, 0x4824);
        o = func_ov000_0218bf1c(data_ov000_021ccd64, &d, &self->pos, self->rot, 0xffff);
        if (o != NULL) {
            void *p;
            FLD(Ov012Flags8, o, 0x16).b0 = 1;
            FLD(u16, o, 0x18) = i;
            FLD(u16, o, 0x7e) = FLD(u16, self, 0x7e);
            o->unk_90 = self->unk_90;
            p = FLD(void *, o, 0x4c);
            if (p != NULL) {
                func_ov000_02199b88(p, func_ov000_02199ba0(FLD(void *, self, 0x4c)));
            }
        }
    }
}
}

extern "C" {
void func_ov012_022065d8(Ov012Actor *self) {
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
void func_ov012_022066d8(Ov012Actor *self) {
    func_ov000_02194758(self);
    FLD(s32, self, 0xdc) = 0;
    FLD(u8, self, 0xe0) = 0;
    FLD(s32, self, 0xd0) = 0x1000;
    FLD(s32, self, 0xd4) = 0x1000;
    FLD(s32, self, 0xd8) = 0x1000;
    self->unk_48->unk_30 = 0;
    func_ov000_02198360(self->unk_40, 0xb, 0);
}
}
