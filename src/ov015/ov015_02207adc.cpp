#include "ov015/ov015.h"

extern "C" {

extern u8 data_ov015_02212d23[];
extern u8 data_ov015_02212d29[];
void func_ov015_02208474(u8 *self);
void func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void NNS_G3dRenderObjSetInitFunc(void *a, void *cb);
void func_ov000_02190e98(void *a, s32 b, s32 c, s32 d);
void func_ov000_021911c8(void *a, s32 b);
s32 func_ov000_021909a8(void *a, const void *b, const void *c);

struct Ov015Nib {
    u8 lo : 4;
    u8 hi : 4;
};
struct Ov015Anim8 {
    u8 anim[0xa8];
    s32 a;
    s32 b;
    s32 c;
    u8 pad[0x34];
};
struct Ov015Anim8Host {
    u8 pad[0x358];
    Ov015Anim8 e[8];
};
BOOL func_ov015_02207adc(u8 *self) {
    s32 i;
    func_ov000_0218ffdc(self + 0x138, self, 0, 1);
    func_ov000_02190cb0(self + 0x138, data_ov015_02212d23, 0x1000, 0);
    func_ov000_021915a0(self + 0x138);
    NNS_G3dRenderObjSetInitFunc(self + 0x15c, (void *)func_ov015_02208474);
    FLD(Ov015AnimFlags, self, 0x1fa).b5 = 0;
    FLD(Ov015AnimFlags, self, 0x1fa).b8 = 1;
    FLD(u8, self, 0xd04) = func_ov000_021909a8(self + 0x138, self + 0x6c, data_ov015_02212d29);
    for (i = 0; i < 8; i++) {
        Ov015Anim8Host *h = (Ov015Anim8Host *)self;
        func_ov000_0218ffdc(h->e[i].anim, self + 0x220, 0, 1);
        func_ov000_02190e98(h->e[i].anim, 0, 0x1000, 0);
        func_ov000_021915a0(h->e[i].anim);
        func_ov000_021911c8(h->e[i].anim, 0);
        h->e[i].a = 0x1333;
        h->e[i].b = 0x1333;
        h->e[i].c = 0x1c00;
    }
    func_ov000_0218ffdc(self + 0xbd0, self + 0xa98, 0, 1);
    FLD(Ov015Nib, self, 0xcd0).hi = FLD(Ov015Nib, self, 0xcd0).lo;
    FLD(Ov015Nib, self, 0xcd0).lo = 3;
    FLD(s32, self, 0xccc) = 0x2000;
    FLD(u16, self, 0xd38) = 0x32;
    return TRUE;
}

}
