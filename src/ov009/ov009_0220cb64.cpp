#include "ov009/ov009.h"

extern "C" {

extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_0218d918(Ov009Actor *self, const Ov009Vec *v, s32 a);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 a);

void func_ov009_0220cb64(Ov009Actor *self) {
    Ov009Vec v;
    if (self->unk_40->state == 0) {
        u8 n = FLD(u8, self->unk_38, 0xbe);
        if (n < 0x1f) {
            n = n + 1;
            if (n >= 0x1f) {
                Ov009Sub44 *s44 = self->unk_44;
                s44->unk_22_0 = 1;
                s44->unk_22_1 = 1;
                n = 0x1f;
                func_ov000_02198360(self->unk_40, 1, 0);
            }
            FLD(u8, self->unk_38, 0xbe) = n;
        }
    }
    v = func_ov000_0219bf90()->pos;
    func_ov000_0218d918(self, &v, 0x1000);
    self->unk_98 = self->rot[1];
    func_ov000_0218dbe0(self, 0);
}

}
