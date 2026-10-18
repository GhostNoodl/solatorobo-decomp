#include "ov013/ov013.h"

struct Ov013Spot {
    Ov013Vec pos;
    u16 rot;
};

extern "C" {

extern void *data_0214a420;
extern void *data_ov000_021ccd68;
extern char data_ov013_0220b88d[];
extern void *func_020657b0(void *a, s32 b);
extern void func_ov000_0219763c(Ov013Actor *self);
extern void func_ov000_02195d88(Ov013Actor *self);
extern void func_ov000_02196060(Ov013Actor *self);
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern Ov013Actor *func_ov000_0218e4cc(void *mgr, u16 id);
extern BOOL func_ov003_021d98bc(void *a, const Ov013Spot *b);

void func_ov013_021fe730(Ov013Actor *self) {
    if (self->unk_40->state == 0) {
        func_ov000_02190cb0(self->unk_38, data_ov013_0220b88d, 0x2ab, 0);
        func_ov000_021915a0(self->unk_38);
    }
    func_ov000_02195d88(self);
}

}
