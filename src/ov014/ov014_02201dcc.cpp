#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_02217430[];
extern void func_ov003_021ceedc(void *p);
extern void func_ov003_021cef0c(void *p);
extern void func_ov003_021da940(void *p);
extern void func_ov003_021d7f0c(void *p);
extern void func_ov003_021d7fc0(void *p);
extern void func_ov000_0218e9c4(void *p);
extern void func_ov000_0218fe1c(void *p);
extern void func_ov000_0218fee4(void *p);
extern void func_ov000_0218ea20(void *p);
extern BOOL func_ov000_0218cf5c(Ov014Actor *self);
extern BOOL func_ov000_0218f110(void *p);
extern BOOL func_ov003_021d8820(void *p);
extern void func_ov003_021d883c(void *p, Ov014Vec *a, Ov014Vec *b, s32 c);
extern BOOL func_ov000_021903b4(void *p);
extern void func_ov003_021d3008(Ov014Actor *self);
extern void func_ov003_021d1c00(Ov014Actor *self, Ov014Msg *msg);
extern void *data_ov000_021ccd64;
extern u8 data_ov014_02216500[];
extern u8 data_ov014_02216534[];
extern u8 data_ov014_0221653c[];
extern u8 data_ov014_02216544[];
extern u8 data_ov014_02216554[];
extern void func_ov003_021d112c(Ov014Actor *self);
extern void func_ov003_021d8198(void *p);
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_0203f364(Ov014Sub48 *p);
extern void func_ov003_021cf1f0(void *p, s32 a, s32 b, const void *c);
extern void func_ov000_0218ffdc(void *anim, void *res, s32 a, s32 b);
extern BOOL func_020621c4(void);
extern void func_ov003_021d6bac(Ov014Actor *self, const void *a);

BOOL func_ov014_02201dcc(Ov014Actor *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (FLD(s16, self, 0x150) >= 0) {
        r = (r & func_ov000_0218f110((u8 *)self + 0x150)) ? TRUE : FALSE;
    }
    return r;
}

BOOL func_ov014_02201e08(Ov014Actor *self) {
    s32 f;
    BOOL r;
    Ov014Vec saved = self->pos;
    if (!func_ov003_021d8820((u8 *)self + 0x100)) {
        func_ov003_021d883c((u8 *)self + 0x100, &self->pos, &self->pos, 0x200);
    }
    r = func_ov003_021d16cc(self);
    f = FLD(s32, self, 0xf4);
    if ((f & 0x40) || (f & 0x1000)) {
        FLD(Ov014Vec, self, 0x300) = self->pos;
        r = func_ov000_021903b4((u8 *)self + 0x288);
    }
    self->pos = saved;
    return r;
}

void func_ov014_02201ea4(Ov014Actor *self) {
    func_ov003_021d3008(self);
    ((Ov014V *)((u8 *)self + 0x100))->v0c();
}

void func_ov014_02201ec4(Ov014Actor *self) {
    func_ov003_021d1b88(self);
    func_ov000_02190a80((u8 *)self + 0x288, func_0203db40((u8 *)self + 0x24));
}

void func_ov014_02201ee8(Ov014Actor *self, Ov014Msg *msg) {
    if (msg->type == 6) {
        FLD(u8, self, 0xf8) = msg->idx;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
    }
    func_ov003_021d1c00(self, msg);
}

void func_ov014_02201f24(Ov014Actor *self) {
    u8 *u;
    func_ov003_021d112c(self);
    FLD(s16, self, 0xf0) = (u8)self->unk_18;
    FLD(s32 *, self, 0xfc) = Ov014_NewFx();
    func_ov003_021d8198((u8 *)self + 0x100);
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        FLD(Ov014Flags8, u, 0xa2).b0 = 0;
    }
    FLD(u8, self->unk_38, 0xbe) = 0;
    self->unk_ea_6 = 1;
    {
        Ov014Sub48 *m = self->unk_48;
        m->unk_9a_0 = 0;
        m->unk_9a_3 = 0;
        func_0203f364(m);
    }
    switch (FLD(s16, self, 0xf0)) {
    case 0:
        func_ov003_021cf1f0((u8 *)self + 0x134, 0, 1, data_ov014_02216534);
        break;
    case 1:
        func_ov003_021cf1f0((u8 *)self + 0x134, 1, 1, data_ov014_0221653c);
        break;
    case 2:
        func_ov003_021cf1f0((u8 *)self + 0x134, 2, 1, data_ov014_02216544);
        break;
    }
    func_ov000_0218ffdc((u8 *)self + 0x288, (u8 *)self + 0x150, 0, 1);
    FLD(Ov014Flags, self, 0x34a).b0 = 1;
    FLD(s32, self, 0x330) = FLD(s32, data_ov014_02216500, 0x130);
    FLD(s32, self, 0x334) = FLD(s32, data_ov014_02216500, 0x134);
    FLD(s32, self, 0x338) = FLD(s32, data_ov014_02216500, 0x138);
    switch (FLD(s16, self, 0xf0)) {
    case 0:
        self->unk_48->unk_60 = -0x800;
        break;
    case 1: {
        Ov014Sub44 *n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->unk_48->unk_60 = -0x4cd;
        break;
    }
    case 2:
        FLD(u8, self, 0x12e) = func_02040498(5);
        break;
    }
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov014_02216554);
        FLD(u16, self, 0x12c) = 0x1800;
    }
}

}
