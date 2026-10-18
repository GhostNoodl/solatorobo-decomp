#include "ov009/ov009.h"

extern "C" {

extern void *func_ov000_02199ba0(void *p);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 a);
extern s32 func_ov000_0219a510(Ov009Actor *self, u16 mask, const Ov009Vec *pos, s32 r, s32 b, void **out);
extern Ov009Actor *func_ov000_021985c0(void *p);
extern void func_ov003_021f0c60(Ov009Actor *self, s32 a);
extern void func_ov000_02196060(Ov009Actor *self);

void func_ov009_022141e0(Ov009Actor *self) {
    void *list[32];
    s32 n;
    s32 r;
    u16 grp;
    s32 i;
    if (func_ov000_02199ba0(FLD(void *, self, 0x4c)) == NULL) {
        return;
    }
    if (self->unk_40->state == 1) {
        func_ov000_0218dbe0(self, 0);
        if (self->unk_48 != NULL) {
            func_ov000_021987b8(self->unk_48, 0, 0, 0);
            if (self->unk_48->unk_50 & 0x20000000) {
                func_ov000_02198360(self->unk_40, 0x15, 0);
            }
        }
        r = self->unk_64 + 0x4cd;
        if (r < 0xccd) {
            r = 0xccd;
        }
        self->unk_48->unk_44 = r;
        grp = FLD(u16, func_ov000_02199ba0(FLD(void *, self, 0x4c)), 0xc) & 0xf000;
        n = func_ov000_0219a510(self, ~(1 << (grp >> 12)), &self->pos, r, 0, list);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                Ov009Actor *a;
                if (list[i] != NULL && (a = func_ov000_021985c0(list[i])) != NULL) {
                    u8 *p = FLD(u8 *, a, 0x4c);
                    if (p == NULL || grp != (u16)(FLD(u16, p, 0x1c) & 0xf000)) {
                        func_ov003_021f0c60(self, 0);
                        func_ov000_02198360(self->unk_40, 0x15, 0);
                        return;
                    }
                }
            }
        }
    } else {
        func_ov000_02196060(self);
    }
}

}
