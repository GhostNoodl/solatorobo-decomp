#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov009_02215d0c[];
extern void func_ov003_021daab0(void *p);
extern void func_02049bb4(void *mgr, s32 id);
extern void NNSi_G3dModifyPolygonAttrMask(void *p, s32 a, s32 b);
extern void func_ov003_021d3d28(Ov009Actor *self);
extern void func_ov000_02191618(Ov009Sub38 *m);
extern void func_ov003_021d4fd8(Ov009Actor *self);
extern void *data_ov009_02216e78;
extern char data_ov009_02216b98[];
extern void *data_02097cdc;
extern void MIi_CpuClear32(u32 v, void *dst, u32 size);
extern BOOL func_02035b90(const char *name, s32 a);
extern void func_02036838(void *mgr, const char *name, s32 a, s32 b);
extern BOOL func_ov000_0218cf5c(Ov009Actor *self);
extern void func_ov000_0219864c(void *a, s32 b, s32 c);
extern void func_0203f8d8(void *p);
extern void *func_ov000_0219bf90(void);

static inline void Ov009_StopEffect(Ov009Actor *self) {
    Ov009Sub38 *m;
    FLD(u8, self, 0xf4) = 0;
    func_ov003_021daab0(FLD(void *, self, 0x104));
    func_02049bb4(data_02097e4c, FLD(s32, self, 0x108));
    FLD(s32, self, 0x108) = -1;
    m = self->unk_38;
    m->unk_c2_9 = 3;
    NNSi_G3dModifyPolygonAttrMask(m->unk_04, 1, 0xc0);
}

void func_ov009_0220244c(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        FLD(u8, self, 0xf4) = 1;
    }
    func_ov003_021d3600(self);
}

void func_ov009_0220246c(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        Ov009_StopEffect(self);
    }
    func_ov003_021d5900(self);
    if (self->unk_40->unk_13 == 4) {
        FLD(u16, self, 0xf0) |= 0x800;
    }
}

void func_ov009_022024f8(Ov009Actor *self) {
    func_ov003_021d3d28(self);
    if (self->unk_40->state < 1) {
        return;
    }
    if (!(FLD(u16, self, 0xf0) & 0x800)) {
        return;
    }
    func_ov000_02190cb0(self->unk_38, data_ov009_02215d0c[5], 0x1000, 0);
    FLD(u8, self, 0xf4) = 0;
    func_ov000_02191618(self->unk_38);
    if (self->unk_40->state == 2) {
        FLD(u16, self, 0xf0) = 0;
    }
}

void func_ov009_02202560(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        Ov009_StopEffect(self);
        self->unk_64 >>= 2;
    }
    func_ov003_021d6054(self);
}

void func_ov009_022025e0(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        Ov009_StopEffect(self);
    }
    func_ov003_021d4fd8(self);
}

void func_ov009_02202654(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        Ov009_StopEffect(self);
    }
    func_ov003_021d5348(self);
}

void func_ov009_022026c8(Ov009Names *self, void *res) {
    char *a = func_0207011c(res);
    char *b = func_020701d4(res);
    u8 *c = func_02070558(res);
    char *s;
    char *t;
    func_0201e520(self->unk_10, a);
    func_0201e520(self->unk_30, b);
    self->unk_03_1 = 1;
    s = (char *)data_ov009_02215d0c[1];
    func_0201e520(self->unk_4c, s);
    func_0201e520(self->unk_6c, (char *)data_ov009_02215d0c[2]);
    self->unk_03_2 = 1;
    t = FLD(char *, c, 0x28);
    if (t != NULL) {
        func_0201e520(self->unk_c4, s);
        func_0201e520(self->unk_e4, t);
        self->unk_03_4 = 1;
    }
    self->unk_00 = 0;
}

#pragma force_active on
Ov009Actor *func_ov009_02202788(Ov009Actor *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = &data_ov009_02216e78;
    MIi_CpuClear32(0, &FLD(u8, self, 0xf8), 0x34);
    return self;
}
#pragma force_active reset

Ov009Actor *func_ov009_022027b8(Ov009Actor *self) {
    FLD(void *, self, 0) = &data_ov009_02216e78;
    if (self->kind == 0x5055 && func_02035b90(data_ov009_02216b98, 7)) {
        func_02036838(data_02097cdc, data_ov009_02216b98, 7, 0);
    }
    func_ov003_021d0edc(self);
    return self;
}

Ov009Actor *func_ov009_0220282c(Ov009Actor *self) {
    FLD(void *, self, 0) = &data_ov009_02216e78;
    if (self->kind == 0x5055 && func_02035b90(data_ov009_02216b98, 7)) {
        func_02036838(data_02097cdc, data_ov009_02216b98, 7, 0);
    }
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

}
