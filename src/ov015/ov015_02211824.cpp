#include "ov015/ov015.h"

extern "C" {

extern u8 data_ov015_022132d0[];
u8 *func_0206ef88(u16 id);
extern u8 *data_ov015_0221336c;
void func_0202a4c8(void *p, s32 a);
void func_ov015_02211954(u8 *self);
void func_02011340(void *a);
extern Ov015Shared *data_ov015_02213368;
extern const char *data_ov015_02213228[];
extern const char *data_ov015_02213230[];
extern const char *data_ov015_02213208[];
void func_0201e520(void *dst, const void *src);
s32 func_ov000_0218f110(void *a);

void func_ov015_02211824(void) {
}

void func_ov015_02211828(u8 *self) {
    SET_VT(self, data_ov015_022132d0);
    FLD(u16, self, 0x4) = 0xffff;
    FLD(s32, self, 0x8) = 0;
    FLD(s32, self, 0xc) = 0;
    FLD(s32, self, 0x10) = 0;
    FLD(s32, self, 0x14) = 0;
    FLD(s32, self, 0x18) = 0;
    FLD(s32, self, 0x1c) = 0;
    FLD(s32, self, 0x20) = 0;
    FLD(s32, self, 0x24) = 0;
    FLD(s32, self, 0x28) = 0;
    FLD(s32, self, 0x2c) = 0;
    FLD(s32, self, 0x30) = 0;
    FLD(s32, self, 0x34) = 0;
}

void func_ov015_02211878(void *self) {
}

void *func_ov015_0221187c(void *self) {
    func_0203de1c(self);
    return self;
}

void func_ov015_02211890(u8 *self, u16 id, s32 mode) {
    u8 *info;
    s32 t;
    FLD(u16, self, 0x4) = id;
    info = func_0206ef88(id);
    FLD(s32, self, 0x8) = info[2] * 0x333 + 0x4cd;
    FLD(s32, self, 0xc) = info[2] * 0x4cd + 0xccd;
    FLD(s32, self, 0x10) = 0xa000;
    FLD(s32, self, 0x14) = 0;
    t = info[3] * -0x99a - 0x1800;
    FLD(s32, self, 0x18) = t;
    FLD(s32, self, 0x1c) = t >> 1;
    FLD(s32, self, 0x20) = FLD(s16, info, 0x4) << 4;
    if (mode == 1) {
        FLD(s32, self, 0x20) += 0x1000;
    }
    FLD(s32, self, 0x24) = FLD(s16, info, 0x4) << 4;
    FLD(s32, self, 0x28) = -0x1800;
    FLD(s32, self, 0x2c) = -0xc0;
    FLD(s32, self, 0x30) = FLD(s16, info, 0x6) << 4;
}

struct Ov015Info30 {
    u8 pad[0x24];
    Ov015VecC v;
};
void func_ov015_02211954(u8 *self) {
    u8 *g = data_ov015_0221336c;
    s32 k;
    Ov015Info30 info;
    if (g == NULL) {
        return;
    }
    k = (FLD(u32, self, 0x8) & 0x10) ? FLD(u8, self, 0xae) : -1;
    if (k != FLD(s32, g, 0xc)) {
        return;
    }
    func_0202a4c8(&info, 0);
    *(Ov015VecC *)(g + 0x234) = info.v;
    FLD(void *, self, 0x24) = NULL;
    FLD(u8, self, 0x92) = 0;
}

void func_ov015_022119d0(u8 *self) {
    FLD(void *, self, 0x24) = (void *)func_ov015_02211954;
    FLD(u8, self, 0x92) = 3;
}

void func_ov015_022119e8(u8 *self) {
    VCALL(self)->v08();
    FLD(s32, self, 0x4) = 0;
    FLD(s32, self, 0xc) = 0;
    FLD(s32, self, 0x10) = 0;
    FLD(s32, self, 0x28c) = 0x1000;
}

void func_ov015_02211a18(void) {
}

void func_ov015_02211a1c(u8 *self) {
    FLD(s32, self, 0x8) = 0;
    FLD(s32, self, 0x234) = 0;
    FLD(s32, self, 0x238) = 0;
    FLD(s32, self, 0x23c) = 0;
    FLD(s32, self, 0x240) = 0;
    FLD(s32, self, 0x244) = 0;
    FLD(s32, self, 0x248) = 0;
    func_02011340(self + 0x24c);
    FLD(s32, self, 0x270) = 0;
    FLD(s32, self, 0x274) = 0;
    FLD(s32, self, 0x278) = 0;
    FLD(s32, self, 0x27c) = 0;
    FLD(s32, self, 0x280) = 0;
    FLD(s32, self, 0x284) = 0;
    FLD(u16, self, 0x288) = 0;
    FLD(u16, self, 0x28a) = 0;
}

static inline void Ov015_SetPairB(u8 *l, s32 i, const void *a, const void *b) {
    func_0201e520(l + 0x10 + i * 0x3c, a);
    func_0201e520(l + 0x30 + i * 0x3c, b);
    l[3] |= 2 << i;
}
void func_ov015_02211a74(u8 *self) {
    s32 idx = data_ov015_02213368->unk_2c;
    Ov015_SetPairB(self + 0x14, 0, data_ov015_02213230[idx], data_ov015_02213228[idx]);
    Ov015_SetPairB(self + 0x14, 1, data_ov015_02213230[idx], data_ov015_02213208[idx]);
    FLD(s16, self, 0x14) = 0;
}

BOOL func_ov015_02211b00(u8 *self) {
    BOOL r = TRUE;
    if (FLD(s16, self, 0x14) >= 0) {
        if ((func_ov000_0218f110(self + 0x14) & 1) == 0) r = FALSE;
    }
    return r;
}

}
