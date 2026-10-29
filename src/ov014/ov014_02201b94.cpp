#include "ov014/ov014.h"

extern "C" {

extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern Ov014Actor *func_ov000_0218e6d0(void *mgr, u16 a, u16 b);
extern void func_ov000_0219bd20(s32 a, u16 b, s32 c, s32 d, s32 e, u8 *f);
extern void func_ov003_021daa6c(void *p, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void *func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern Ov014Actor *func_02065f88(s32 id, Ov014Vec *pos);

void func_ov014_02201a28(Ov014Actor *self) {
    if (self->unk_40->state == 0) {
        Ov014Game54 *g = data_ov000_021ccd54;
        u8 c;
        Ov014Actor *a;
        Ov014Actor *e;
        FLD(u8, g, 0x190) |= 0x1c;
        FLD(u8, g, 0x18d) = 0xf;
        FLD(u8, g, 0x18e) = 0xf;
        FLD(u8, g, 0x18f) = 0xf;
        c = FLD(s16, self, 0xf0) + 3;
        func_ov000_0219bd20(0x5c0e, self->kind, 6, 1, 1, &c);
        if (data_ov000_021ccd68 == NULL) {
            a = NULL;
        } else {
            a = func_ov000_0218e6d0(data_ov000_021ccd68, 0x4000, 0x483c);
        }
        if (a != NULL) {
            FLD(u16, a, 0x1a) = 1;
        }
        func_ov003_021daa6c(FLD(void *, self, 0x100), 0xff);
        func_ov003_021daa6c(FLD(void *, self, 0x100), 0xfe);
        func_ov000_0218996c(0x19, 0x3c);
        func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
        func_02049f44(data_02097e4c, 0x79, &self->pos, 0);
        func_02065f88(0x322, &self->pos)->v0c(0x1400);
        e = func_02065f88(0x68, &self->pos);
        e->v0c(0x1800);
        e->v34(0x4000, 0, 0);
    }
    func_ov003_021d6054(self);
}

extern u8 data_ov014_02217430[];
extern void func_ov003_021ceedc(void *p);
extern void *func_ov003_021cef0c(void *p);
extern void *func_ov003_021da940(void *p);
extern void *func_ov003_021d7f0c(void *p);
extern void *func_ov003_021d7fc0(void *p);
extern void *func_ov000_0218e9c4(void *p);
extern void *func_ov000_0218fe1c(void *p);
extern void *func_ov000_0218fee4(void *p);
extern void *func_ov000_0218ea20(void *p);
extern BOOL func_ov000_0218cf5c(Ov014Actor *self);
extern BOOL func_ov000_0218f110(void *p);
extern BOOL func_ov003_021d8820(void *p);
extern void func_ov003_021d883c(void *p, Ov014Vec *a, Ov014Vec *b, s32 c);
extern BOOL func_ov000_021903b4(void *p);
extern void func_ov003_021d3008(Ov014Actor *self);
extern BOOL func_ov003_021d1c00(Ov014Actor *self, Ov014Msg *msg);

#pragma force_active on
Ov014Actor *func_ov014_02201b94(Ov014Actor *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = data_ov014_02217430;
    func_ov003_021d7f0c((u8 *)self + 0x100);
    func_ov003_021ceedc((u8 *)self + 0x134);
    func_ov000_0218e9c4((u8 *)self + 0x150);
    func_ov000_0218fe1c((u8 *)self + 0x288);
    FLD(s32, self, 0xf4) = 0x40;
    FLD(u8, self, 0xf8) = 0xff;
    FLD(void *, self, 0xfc) = NULL;
    FLD(s32, self, 0x130) = 0;
    FLD(u8, self, 0xf9) = 0;
    FLD(u8, self, 0x12e) = 0;
    FLD(s16, self, 0x12c) = 0x1000;
    return self;
}
#pragma force_active reset

static inline void Ov014_FreeFC(Ov014Actor *self) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, 0xfc) != NULL) {
        void *p = FLD(void *, self, 0xfc);
        if (p != NULL) {
            func_ov003_021da940(p);
            func_0203de1c(p);
        }
        FLD(void *, self, 0xfc) = NULL;
    }
    data_02097dd0->cur = saved;
}

Ov014Actor *func_ov014_02201c04(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217430;
    Ov014_FreeFC(self);
    ((Ov014V *)((u8 *)self + 0x100))->v08();
    func_ov000_0218fee4((u8 *)self + 0x288);
    func_ov000_0218ea20((u8 *)self + 0x150);
    func_ov003_021cef0c((u8 *)self + 0x134);
    func_ov003_021d7fc0((u8 *)self + 0x100);
    func_ov003_021d0edc(self);
    return self;
}

Ov014Actor *func_ov014_02201ca4(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217430;
    Ov014_FreeFC(self);
    ((Ov014V *)((u8 *)self + 0x100))->v08();
    func_ov000_0218fee4((u8 *)self + 0x288);
    func_ov000_0218ea20((u8 *)self + 0x150);
    func_ov003_021cef0c((u8 *)self + 0x134);
    func_ov003_021d7fc0((u8 *)self + 0x100);
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

extern char data_ov014_022173ce[];
extern char data_ov014_022173d9[];

void func_ov014_02201d4c(Ov014Actor *self) {
    func_ov003_021d0fc0(self);
    {
        const char *a = data_ov014_022173ce;
        const char *b = data_ov014_022173d9;
        if (a) {
            STD_CopyString((char *)self + 0x160, a);
            STD_CopyString((char *)self + 0x180, b);
            FLD(u8, self, 0x153) |= 2;
            STD_CopyString((char *)self + 0x19c, a);
            STD_CopyString((char *)self + 0x1bc, b);
            FLD(u8, self, 0x153) |= 4;
        }
    }
    FLD(u16, self, 0x150) = 0;
    FLD(u16, self, 0xea) |= 0x4000;
}

}
