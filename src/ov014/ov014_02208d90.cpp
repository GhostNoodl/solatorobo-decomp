#include "ov014/ov014.h"

extern "C" {

void func_ov014_02208d90(Ov014Actor *self) {
    FLD(u32, self, 0xd0) |= 0x1000;
    func_ov000_02198360(self->unk_40, 0x15, 0);
}
extern void *data_ov000_021ccd64;
extern void *data_02097e4c;
extern void *data_0214a420;
extern void func_ov000_02198c8c(void *p, s32 a);
extern void func_0203f364(Ov014Sub48 *p);
extern Ov014Actor *func_02065f88(s32 id, Ov014Vec *pos);
extern void *func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern void func_ov000_0218bed8(void *a, s32 b, void *c);
extern Ov014V *func_020657b0(void *a, void *b);
extern void func_ov003_021da9ac(void *p, u8 id, void *obj);
extern BOOL func_ov003_021daa0c(void *p, u8 id);
extern void *func_ov003_021daa3c(void *p, u8 id);
extern void func_ov000_0218996c(s32 a, s32 b);

void func_ov014_02208db4(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0: {
        Ov014Actor *a;
        if (self->unk_44 != NULL) {
            Ov014Sub44 *n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
        }
        if (self->unk_48 != NULL) {
            Ov014Sub48 *m;
            func_ov000_02198c8c(self->unk_48, 0xffff);
            m = self->unk_48;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
            m = self->unk_48;
            m->unk_9a_1 = 0;
            m->unk_9a_4 = 0;
        }
        self->unk_38->unk_c2_0 = 0;
        a = func_02065f88(0x69, &self->pos);
        a->v0c(0x40);
        func_ov003_021da9ac(FLD(void *, self, 0xd8), 0xff, a);
        a = func_02065f88(5, &self->pos);
        a->v0c(0x40);
        func_ov003_021da9ac(FLD(void *, self, 0xd8), 0xfe, a);
        func_ov000_0218996c(0xf, 0xf);
        func_02049f44(data_02097e4c, 0x7f, &self->pos, 0);
        func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
        self->unk_40->state++;
        break;
    }
    case 1: {
        Ov014V *o;
        o = func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0xd8), 0xff));
        if (o != NULL) {
            o->v0c(FLD(s32, o, 0x40) + 0x148);
        }
        o = func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0xd8), 0xfe));
        if (o != NULL) {
            o->v0c(FLD(s32, o, 0x40) + 0xcd);
        }
        if (!func_ov003_021daa0c(FLD(void *, self, 0xd8), 0xff)) {
            self->unk_40->state++;
        }
        break;
    }
    case 2:
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->v08();
        break;
    }
}

}
