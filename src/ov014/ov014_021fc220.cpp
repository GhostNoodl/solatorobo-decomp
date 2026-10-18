#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_0221722c[];
extern Ov014Vec data_ov014_022164a0[];
extern void func_ov003_021daab0(void *p);
extern void func_ov000_0219763c(void *self);
extern void func_ov000_02194074(void *self);
extern void func_ov003_021da940(void *p);
extern void func_ov000_02194758(void *self);
extern void func_0203f364(Ov014Sub48 *p);

void func_ov014_021fc220(Ov014Actor *self) {
    if (self->unk_40->state == 0) {
        func_ov003_021daab0(FLD(void *, self, 0xd0));
    }
    func_ov000_0219763c(self);
}

#pragma force_active on
Ov014Actor *func_ov014_021fc24c(Ov014Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov014_0221722c;
    FLD(s32, self, 0xf8) = 0;
    FLD(void *, self, 0x100) = NULL;
    FLD(s32, self, 0xf4) = 0;
    FLD(u8, self, 0xfd) = 0;
    return self;
}
#pragma force_active reset

static inline void Ov014_Free100(Ov014Actor *self) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, 0x100) != NULL) {
        void *p = FLD(void *, self, 0x100);
        if (p != NULL) {
            func_ov003_021da940(p);
            func_0203de1c(p);
        }
        FLD(void *, self, 0x100) = NULL;
    }
    data_02097dd0->cur = saved;
}

Ov014Actor *func_ov014_021fc280(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_0221722c;
    Ov014_Free100(self);
    func_ov000_0219429c(self);
    return self;
}

Ov014Actor *func_ov014_021fc2f0(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_0221722c;
    Ov014_Free100(self);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov014_021fc368(Ov014Actor *self) {
    s32 *p;
    Ov014Sub38 *m;
    func_ov000_02194758(self);
    FLD(u8, self, 0xfc) = self->unk_18;
    FLD(s32, self, 0xdc) = 0x1000;
    FLD(s32, self, 0xe0) = 0x1000;
    FLD(s32, self, 0xe4) = 0x1000;
    self->unk_48->unk_30 = 0;
    {
        Ov014Sub48 *s48 = self->unk_48;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
    }
    {
        Ov014Sub48 *s48 = self->unk_48;
        s48->unk_9a_2 = 0;
        s48->unk_9a_5 = 0;
    }
    self->unk_44->unk_1c = Ov014_FxMul(self->unk_64, 0x2800);
    p = (s32 *)func_0203dd9c(4);
    if (p != NULL) {
        *p = 0;
    }
    FLD(s32 *, self, 0x100) = p;
    m = self->unk_38;
    {
        s32 y = FLD(Ov014Vec, m, 0xa8).y;
        s32 z = FLD(Ov014Vec, m, 0xa8).z;
        FLD(Ov014Vec, self, 0xe8).x = FLD(Ov014Vec, m, 0xa8).x;
        FLD(Ov014Vec, self, 0xe8).y = y;
        FLD(Ov014Vec, self, 0xe8).z = z;
    }
    Ov014_VecCopy(&FLD(Ov014Vec, m, 0xa8), &data_ov014_022164a0[4]);
    func_ov000_02198360(self->unk_40, 1, 0);
}

}
