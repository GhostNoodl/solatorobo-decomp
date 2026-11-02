#include "ov015/ov015.h"

extern "C" {

extern u8 data_ov015_022132d0[];
u8 *func_0206ef88(u16 id);
extern Ov015Obj290 *data_ov015_0221336c;
void NNS_G3dGetCurrentMtx(void *p, s32 a);
void func_ov015_02211954(u8 *self);
void MTX_Identity33_(void *a);
extern Ov015Shared *data_ov015_02213368;
extern const char *data_ov015_02213228[];
extern const char *data_ov015_02213230[];
extern const char *data_ov015_02213208[];
void *STD_CopyString(void *dst, const void *src);
s32 func_ov000_0218f110(void *a);

void func_ov015_02211824(void) {
}

void func_ov015_02211828(Ov015Info38 *self) {
    SET_VT(self, data_ov015_022132d0);
    self->unk_04 = 0xffff;
    self->unk_08 = 0;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_28 = 0;
    self->unk_2c = 0;
    self->unk_30 = 0;
    self->unk_34 = 0;
}

void func_ov015_02211878(void *self) {
}

void *func_ov015_0221187c(void *self) {
    Heap_Free(self);
    return self;
}

void func_ov015_02211890(Ov015Info38 *self, u16 id, s32 mode) {
    u8 *info;
    s32 t;
    self->unk_04 = id;
    info = func_0206ef88(id);
    self->unk_08 = info[2] * 0x333 + 0x4cd;
    self->unk_0c = info[2] * 0x4cd + 0xccd;
    self->unk_10 = 0xa000;
    self->unk_14 = 0;
    t = info[3] * -0x99a - 0x1800;
    self->unk_18 = t;
    self->unk_1c = t >> 1;
    self->unk_20 = FLD(s16, info, 0x4) << 4;
    if (mode == 1) {
        self->unk_20 += 0x1000;
    }
    self->unk_24 = FLD(s16, info, 0x4) << 4;
    self->unk_28 = -0x1800;
    self->unk_2c = -0xc0;
    self->unk_30 = FLD(s16, info, 0x6) << 4;
}

struct Ov015Info30 {
    u8 pad[0x24];
    Ov015VecC v;
};
void func_ov015_02211954(u8 *self) {
    Ov015Obj290 *g = data_ov015_0221336c;
    s32 k;
    Ov015Info30 info;
    if (g == NULL) {
        return;
    }
    k = (FLD(u32, self, 0x8) & 0x10) ? FLD(u8, self, 0xae) : -1;
    if (k != g->unk_0c) {
        return;
    }
    NNS_G3dGetCurrentMtx(&info, 0);
    g->unk_234 = info.v;
    FLD(void *, self, 0x24) = NULL;
    FLD(u8, self, 0x92) = 0;
}

void func_ov015_022119d0(u8 *self) {
    FLD(void *, self, 0x24) = (void *)func_ov015_02211954;
    FLD(u8, self, 0x92) = 3;
}

void func_ov015_022119e8(Ov015Obj290 *self) {
    VCALL(self)->v08();
    self->unk_04 = 0;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_28c = 0x1000;
}

void func_ov015_02211a18(void) {
}

void func_ov015_02211a1c(Ov015Obj290 *self) {
    self->unk_08 = 0;
    self->unk_234.x = 0;
    self->unk_234.y = 0;
    self->unk_234.z = 0;
    self->unk_240.x = 0;
    self->unk_240.y = 0;
    self->unk_240.z = 0;
    MTX_Identity33_(&self->unk_24c);
    self->unk_270.x = 0;
    self->unk_270.y = 0;
    self->unk_270.z = 0;
    self->unk_27c.x = 0;
    self->unk_27c.y = 0;
    self->unk_27c.z = 0;
    self->unk_288 = 0;
    self->unk_28a = 0;
}

static inline void Ov015_SetPairB(u8 *l, s32 i, const void *a, const void *b) {
    STD_CopyString(l + 0x10 + i * 0x3c, a);
    STD_CopyString(l + 0x30 + i * 0x3c, b);
    l[3] |= 2 << i;
}
void func_ov015_02211a74(Ov015Obj290 *self) {
    s32 idx = data_ov015_02213368->unk_2c;
    Ov015_SetPairB((u8 *)&self->unk_14, 0, data_ov015_02213230[idx], data_ov015_02213228[idx]);
    Ov015_SetPairB((u8 *)&self->unk_14, 1, data_ov015_02213230[idx], data_ov015_02213208[idx]);
    self->unk_14.unk_00 = 0;
}

BOOL func_ov015_02211b00(Ov015Obj290 *self) {
    BOOL r = TRUE;
    if (self->unk_14.unk_00 >= 0) {
        if ((func_ov000_0218f110(&self->unk_14) & 1) == 0) r = FALSE;
    }
    return r;
}


BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_02191618(void *a);
void NNS_G3dRenderObjSetInitFunc(void *a, void *cb);
s32 func_ov000_021909a8(void *a, const void *b, const void *c);
extern u8 data_ov015_02213280[];
extern const char *data_ov015_02213210[];

BOOL func_ov015_02211b2c(Ov015Obj290 *self) {
    func_ov000_0218ffdc(&self->unk_14c, &self->unk_14, 0, 1);
    func_ov000_02190cb0(&self->unk_14c, data_ov015_02213280, 0x1000, 0);
    func_ov000_02191618(&self->unk_14c);
    self->unk_14c.unk_c2.b4 = 0;
    self->unk_14c.unk_c2.b2 = 0;
    self->unk_14c.unk_c2.b0 = 0;
    NNS_G3dRenderObjSetInitFunc(&self->unk_14c.unk_24, (void *)func_ov015_022119d0);
    self->unk_14c.unk_c2.b5 = 0;
    self->unk_14c.unk_c2.b8 = 1;
    s32 r = data_ov015_02213368->unk_2c;
    r = func_ov000_021909a8(&self->unk_14c, data_ov015_02213210[r], NULL);
    self->unk_0c = r;
    return TRUE;
}

}
