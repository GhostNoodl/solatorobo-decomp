#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern void *data_ov009_02215d0c[];
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d46c(Ov009Actor *a, u16 id, s32 msg);
extern BOOL func_ov000_0218fa28(Ov009Sub38 *m, void *a, void *b, void *c, void *anim, s32 d, s32 e);
extern void func_02049564(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(void *p, s32 a);
extern void func_ov009_0220189c(Ov009Actor *self);
extern void func_ov009_02201eac(Ov009Actor *self);

void func_ov009_02201470(Ov009Actor *self) {
    func_ov003_021d0fc0(self);
    func_02049564(data_02097e4c, 1, 1);
    switch (self->kind) {
    case 0x5047:
        func_ov000_02187a20(data_ov000_021ccd54, 0xd);
        self->unk_1a = 0;
        break;
    case 0x503f:
    case 0x5048:
        func_ov000_02187a20(data_ov000_021ccd54, 0xe);
        self->unk_1a = 1;
        break;
    case 0x5035:
        func_ov000_02187a20(data_ov000_021ccd54, 0xf);
        self->unk_1a = 2;
        break;
    case 0x5054:
        func_ov000_02187a20(data_ov000_021ccd54, 0x10);
        self->unk_1a = 3;
        break;
    }
    self->unk_ea_10 = 1;
    FLD(s32, self, 0x108) = -1;
}

void func_ov009_02201574(Ov009Actor *self) {
    u32 *p;
    func_ov003_021d112c(self);
    p = (u32 *)func_0203dd9c(4);
    if (p != NULL) {
        *p = 0;
    }
    FLD(u32 *, self, 0x104) = p;
    FLD(u16, self, 0xf0) = 0;
    switch (self->kind) {
    case 0x503f:
    case 0x5048:
        FLD(s8, self, 0xf5) = 0;
        FLD(u16, self, 0xf2) = 0x78;
        break;
    case 0x5035:
    case 0x5047:
    case 0x5054:
        FLD(s8, self, 0xf5) = 1;
        switch (self->kind) {
        case 0x5047:
            FLD(u16, self, 0xf2) = 0x78;
            break;
        case 0x5035:
            FLD(u16, self, 0xf2) = 0x96;
            break;
        case 0x5054:
            FLD(u16, self, 0xf2) = 0x50;
            break;
        }
        self->unk_c8 = 0x16000;
        self->unk_cc = 0xc000;
        break;
    }
}

extern u8 data_ov009_02215dd8[];
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_020639d4(void *p, s32 a, s32 b);
extern void func_02049bb4(void *mgr, s32 id);
extern Ov009Actor *func_ov000_0219bf90(void);
extern BOOL func_ov003_021daa0c(void *mgr, s32 id);
extern void func_ov003_021da9ac(void *mgr, s32 id, void *obj);
extern void func_ov003_021daa6c(void *mgr, s32 id);
extern void func_ov003_021daae4(void *mgr, s32 id, const Ov009Vec *pos, s32 a, s32 b, const void *c, s32 d);
extern void func_ov003_021dacfc(void *mgr);
void func_ov009_02201678(Ov009Actor *self) {
    Ov009V *obj;
    Ov009Vec v;
    func_ov003_021d1e8c(self);
    if (FLD(u8, self, 0xf4) != 0) {
        self->unk_94_1 = 1;
        if (FLD(s8, self, 0xf5) == 1) {
            if (!func_ov003_021daa0c(FLD(void *, self, 0x104), 0xfd)) {
                if (self->unk_40->unk_13 != 0x15) {
                    obj = func_02065f88(0x322, &self->pos);
                    obj->v20(data_ov009_02215dd8);
                    obj->v0c(0xccd);
                    FLD(s32, obj, 0xc8) = -1;
                    func_020639d4(obj, 0x78, 0);
                    func_ov003_021da9ac(FLD(void *, self, 0x104), 0xfd, obj);
                }
            } else {
                func_ov003_021daae4(FLD(void *, self, 0x104), 0xfd, &self->pos, 0, 0, data_ov009_02215dd8, 0);
            }
            if (self->unk_40->unk_13 != 0xf && func_ov003_021daa0c(FLD(void *, self, 0x104), 0xfb)) {
                func_ov003_021daa6c(FLD(void *, self, 0x104), 0xfb);
                func_02049bb4(data_02097e4c, FLD(s32, self, 0x108));
                FLD(s32, self, 0x108) = -1;
            }
            if (func_ov003_021daa0c(FLD(void *, self, 0x104), 0xfa)) {
                v = func_ov000_0219bf90()->pos;
                func_ov003_021daae4(FLD(void *, self, 0x104), 0xfa, &v, 0, 0, 0, 0);
            }
        }
    } else if (FLD(s8, self, 0xf5) == 1 && func_ov003_021daa0c(FLD(void *, self, 0x104), 0xfd)) {
        func_ov003_021daa6c(FLD(void *, self, 0x104), 0xfd);
    }
    func_ov003_021dacfc(FLD(void *, self, 0x104));
}

}
