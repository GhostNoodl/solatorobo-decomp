#include "ov000/LoCommon.h"

extern "C" {

extern const s16 FX_SinCosTable_[];
extern u8 *data_ov000_021ccd54;
void func_02011820(void *m);
void func_02011994(void *m, s32 s, s32 c);
void func_020627fc(s32 a);
void func_ov000_02182590(void *p);
void func_ov000_02188140(void *p, s32 a, s32 b, s32 c);

void func_ov000_0216d9dc(void *self, s32 unused, u16 *msg) {
    u16 type = msg[0];
    void *p = LFLD(void *, msg, 8);
    u16 ang;
    if (type != 0x1e) {
        return;
    }
    ang = LFLD(u16, p, 0x44);
    func_02011820(self);
    func_02011994(self, FX_SinCosTable_[(ang >> 4) * 2], FX_SinCosTable_[(ang >> 4) * 2 + 1]);
}

void func_ov000_0216da2c(void *self, s32 a, s32 b, s32 c) {
    LFLD(s32, self, 8) = a;
    LFLD(s32, self, 0x24) = b;
    LFLD(s32, self, 0x28) = c;
    switch (a) {
    case 1:
        LFLD(s32, self, 0x20) = 0;
        LFLD(s32, self, 0x1c) = 0;
        if (b == 0) {
            LFLD(s32, self, 0x24) = 0x7fffffff;
        }
        break;
    case 2:
        LFLD(s32, self, 0x20) = b;
        LFLD(s32, self, 0x1c) = b;
        break;
    }
    LBIT(self, 0).b7 = 0;
}

void func_ov000_0216da78(void *self) {
    s32 v = LFLD(s32, self, 0x1c);
    LBIT(self, 0).b9 = 1;
    LBIT(self, 0).b16 = 0;
    LBIT(self, 0).b5 = 1;
    LBIT(self, 0).b8 = 1;
    LFLD(s32, self, 0x20) = v;
    if (LBIT(self, 0).b6 == 1) {
        u8 *d;
        func_020627fc(4);
        d = data_ov000_021ccd54;
        d[0xac] = 1;
        func_ov000_02182590(d + 0xac);
        func_ov000_02188140(data_ov000_021ccd54, 0xffff, 0, 0);
    }
}

}
