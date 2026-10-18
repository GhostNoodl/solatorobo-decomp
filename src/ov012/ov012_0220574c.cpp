#include "ov012/ov012.h"

extern "C" {

BOOL func_ov012_0220574c(Ov012Actor *self) {
    BOOL r;
    if (!(FLD(u32, self, 0xd0) & 0x100000)) {
        FLD(s32, self, 0x288) = self->pos.x;
        FLD(s32, self, 0x28c) = self->pos.y;
        FLD(s32, self, 0x290) = self->pos.z;
        func_ov000_02190758((u8 *)self + 0x210, self->rot, 0);
        r = func_ov000_021903b4((u8 *)self + 0x210);
        if (r && self->unk_3c != NULL && self->unk_48 != NULL) {
            Ov012Sub48 *m = self->unk_48;
            u8 v;
            FLD(s32, self->unk_3c, 0x10) = self->pos.y - FLD(s32, m, 0x6c);
            v = 1;
            if (m->unk_54 & 0x10000) {
                v = 3;
            }
            {
                Ov012Nib *n = &FLD(Ov012Nib, self->unk_3c, 0x18);
                n->hi = n->lo;
                n->lo = v;
            }
            func_ov000_02191c24(self->unk_3c, &self->pos);
        }
    } else {
        r = func_ov000_02194c08(self);
    }
    return r;
}

void func_ov012_02205818(Ov012Actor *self) {
    if (self->unk_38 != NULL) {
        func_ov000_02190a80(self->unk_38, func_0203db40((u8 *)self + 0x24));
    }
    if (!(FLD(u32, self, 0xd0) & 0x100000)) {
        func_ov000_02190a80((u8 *)self + 0x210, func_0203db40((u8 *)self + 0x24));
    }
}
}

extern "C" {
extern const u8 data_ov012_0220b0a7[];
void func_ov012_02205864(Ov012Actor *self) {
    func_ov000_02194758(self);
    FLD(u32, self, 0xd0) = 0;
    FLD(u8, self, 0x2f8) = 1;
    FLD(u8, self, 0xd4) = self->unk_18;
    if (FLD(u8, self, 0xd4)) {
        Ov012Sub48 *m;
        Ov012Sub44 *n;
        FLD(u32, self, 0xd0) = 0x100000;
        self->unk_38->unk_c2_0 = 1;
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        m = self->unk_48;
        m->unk_9a_0 = 0;
        m->unk_9a_3 = 0;
        func_0203f364(m);
        m = self->unk_48;
        m->unk_9a_2 = 0;
        m->unk_9a_5 = 0;
    } else {
        self->unk_38->unk_c2_0 = 0;
        func_ov000_0218ffdc((u8 *)self + 0x210, (u8 *)self + 0xd8, 0, 1);
        FLD(s32, self, 0x2b8) = 0x2800;
        FLD(s32, self, 0x2bc) = 0x2800;
        FLD(s32, self, 0x2c0) = 0x2800;
        FLD(Ov012Flags, self, 0x2d2).b0 = 1;
        func_ov000_02190758((u8 *)self + 0x210, self->rot, 0);
        func_ov000_02190cb0((u8 *)self + 0x210, data_ov012_0220b0a7, 0x1000, 0);
        func_ov000_021915a0((u8 *)self + 0x210);
    }
    func_ov000_02198360(self->unk_40, 0xb, 0);
}
}
