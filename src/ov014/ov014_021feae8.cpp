#include "ov014/ov014.h"

extern "C" {

extern const u8 data_ov014_022173c8[];
extern void *data_ov014_02216500[];
void func_ov000_02191690(void *a);
void func_ov000_02191318(void *a, s32 b);
s32 func_ov000_0219a510(void *self, u16 mask, Ov014Vec *p, s32 r, s32 a, void **out);
Ov014Actor *func_ov000_021985c0(void *p);
void *func_ov000_0218d2e0(void *a);
void func_ov000_0218d46c(void *o, u16 id, s32 c);

#pragma force_active on
void func_ov014_021feae8(Ov014Actor *self) {
    switch (FLD(s16, self, 0xf0)) {
    case 0: {
        Ov014Vec p;
        void *ids[32];
        s32 n;
        s32 i;
        if (self->unk_40->state == 0) {
            func_ov000_02190cb0(self->unk_38, data_ov014_022173c8, 0x89, 0);
            if (FLD(u32, self, 0xf4) & 0x40) {
                func_ov000_02191690(self->unk_38);
                func_ov000_02191318(self->unk_38, 0);
            } else {
                func_ov000_021915a0(self->unk_38);
            }
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_40->state++;
        }
        p.x = FLD(s32, self->unk_48, 0x68);
        p.y = FLD(s32, self->unk_48, 0x6c);
        p.z = FLD(s32, self->unk_48, 0x70);
        n = func_ov000_0219a510(self, 0xffdf, &p, FLD(s32, self->unk_48, 0x38), 0, ids);
        if (n == 0) {
            return;
        }
        for (i = 0; i < n; i++) {
            if (ids[i] != NULL) {
                Ov014Actor *a = func_ov000_021985c0(ids[i]);
                if (a != NULL) {
                    u16 id = a->id;
                    if ((u16)(FLD(u16, FLD(void *, a, 0x4c), 0x1c) & 0xf000) != 0x5000) {
                        if (func_ov000_0218d2e0(a) != NULL) {
                            return;
                        }
                        func_ov000_0218d46c(a, id, 0x15);
                        return;
                    } else {
                        func_ov000_0218d46c(a, id, 0x15);
                        return;
                    }
                }
            }
        }
        break;
    }
    case 1:
        if (self->unk_40->state == 0) {
            func_ov000_02190cb0(self->unk_38, data_ov014_02216500[3], 0x89, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_40->state++;
        }
        break;
    }
}
#pragma force_active reset
}
