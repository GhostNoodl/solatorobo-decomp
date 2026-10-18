#include "ov009/ov009.h"

extern "C" {

extern void func_ov000_02194758(Ov009Actor *self);
extern void func_0203f364(Ov009Sub48 *p);
extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);
extern void func_ov000_0219433c(Ov009Actor *self);
extern void *func_ov000_02199ba0(void *p);

void func_ov009_02214fe4(Ov009Actor *self) {
    Ov009Sub48 *s48;
    func_ov000_02194758(self);
    s48 = self->unk_48;
    s48->unk_9a_0 = 0;
    s48->unk_9a_3 = 0;
    func_0203f364(s48);
}

void func_ov009_02215014(Ov009Actor *self) {
    func_ov000_0218d988(self, func_ov000_0219bf90(), 0x7b);
    func_ov000_02198360(self->unk_40, 1, 0);
}

void func_ov009_02215044(Ov009Actor *self) {
    func_ov000_0219433c(self);
    self->rot[0] = 0xd548;
    FLD(s32, self, 0xd0) = 0;
}

void func_ov009_02215068(Ov009Actor *self) {
    Ov009Sub48 *s48;
    u8 *p;
    func_ov000_02194758(self);
    s48 = self->unk_48;
    s48->unk_9a_0 = 0;
    s48->unk_9a_3 = 0;
    func_0203f364(s48);
    p = (u8 *)func_ov000_02199ba0(FLD(void *, self, 0x4c));
    if (p != NULL && FLD(s16, p, 0x1c) == 0) {
        self->unk_48->unk_30 = 0;
    }
    func_ov000_02198360(self->unk_40, 0xb, 0);
}

}
