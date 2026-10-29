#include "ov013/ov013.h"

extern "C" {

extern void *data_0214a420;
extern void *data_ov013_0220b738[];
extern Ov013Vec data_ov013_0220aed0;
extern void *func_020657b0(void *a, s32 b);
extern void func_ov000_0219763c(Ov013Actor *self);
extern void *func_ov000_02194074(Ov013Actor *self);
extern void func_ov000_02194758(void *self);
extern Ov013Actor *func_ov000_0219bf90(void);

void func_ov013_021fdb18(Ov013Actor *self) {
    s32 i;
    if (self->unk_40->state == 0) {
        for (i = 0; i < 2; i++) {
            void *p = func_020657b0(data_0214a420, FLD(s32, (u8 *)self + i * 4, 0xd0));
            if (p != NULL) {
                FLD(s32, p, 0x1c) = 4;
            }
        }
    }
    func_ov000_0219763c(self);
}

Ov013Actor *func_ov013_021fdb70(Ov013Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov013_0220b738;
    FLD(u16, self, 0xce) = 0;
    FLD(s32, self, 0xd0) = -1;
    FLD(u8, self, 0xd4) = 0;
    return self;
}

static inline void Ov013_SetSpd(Ov013Actor *self, Ov013Vec v) {
    Ov013_VecCopy(&FLD(Ov013Vec, self->unk_48, 0x5c), &v);
    Ov013_VecCopy(&FLD(Ov013Vec, self->unk_44, 0xc), &v);
}

void func_ov013_021fdba4(Ov013Actor *self) {
    Ov013Actor *p;
    func_ov000_02194758(self);
    func_ov000_02198360(self->unk_40, 0x20, 0);
    self->unk_90 = 0xffff;
    p = func_ov000_0219bf90();
    if (p != NULL) {
        self->unk_90 = p->id;
    }
    Ov013_SetSpd(self, data_ov013_0220aed0);
    FLD(u16, self, 0xce) = 0x140;
}

}
