#include "ov014/ov014.h"

extern "C" {

extern void *data_02097e4c;
extern void func_ov003_021daab0(void *p);
extern void func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern BOOL func_ov003_021d8820(void *p);
extern void func_ov003_021d87d0(void *p, s32 a);
extern void *data_ov014_02216500[];
extern void func_0203f324(Ov014Sub48 *p);
extern void func_ov000_0218dbe0(Ov014Actor *self, s32 a);
extern Ov014Actor *func_ov000_0218d240(Ov014Actor *self);
extern void func_ov000_0218d988(Ov014Actor *self, Ov014Actor *target, s32 a);

void func_ov014_022027d0(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0: {
        Ov014Sub44 *n;
        Ov014Sub48 *m;
        func_ov000_02190cb0(self->unk_38, data_ov014_02216500[3], 0x89, 0);
        func_ov000_021915a0(self->unk_38);
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        switch (FLD(s16, self, 0xf0)) {
        case 0:
            self->unk_48->unk_60 = -0x800;
            break;
        case 1:
            self->unk_48->unk_60 = -0x4cd;
            break;
        }
        m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        func_0203f324(m);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
    }
    case 1: {
        u32 f = FLD(u32, self, 0xf4);
        if (!(f & 1) && f != 0) {
            s32 off = 0;
            switch (FLD(s16, self, 0xf0)) {
            case 0:
                off = 0x1000;
                break;
            case 1:
                off = 0x800;
                break;
            }
            if (self->pos.y < off + (self->unk_64 + 0x4719a)) {
                self->unk_a0 = 0x333;
                func_ov000_0218dbe0(self, 0);
            } else {
                Ov014Sub44 *n = self->unk_44;
                n->unk_22_0 = 1;
                n->unk_22_1 = 1;
                FLD(u32, self, 0xf4) = 1;
            }
        }
        break;
    }
    }
    func_ov000_0218d988(self, func_ov000_0218d240(self), 0xcd);
}

void func_ov014_02202964(Ov014Actor *self) {
    if (self->unk_40->state == 0) {
        self->unk_48->unk_30 = 0;
    }
    func_ov003_021d3a88(self);
}

void func_ov014_02202988(Ov014Actor *self) {
    func_ov003_021daab0(FLD(void *, self, 0xfc));
    self->unk_48->unk_30 = 0x40000000;
    if (self->unk_40->state == 0) {
        func_02049f44(data_02097e4c, 0x67, &self->pos, 0);
        self->unk_48->unk_60 = 0;
        if (!func_ov003_021d8820((u8 *)self + 0x100)) {
            func_ov003_021d87d0((u8 *)self + 0x100, 1);
        }
    }
    func_ov003_021d5900(self);
    if (self->unk_40->state == 0 && FLD(u16, self, 0xe8) == 0) {
        self->unk_9c = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_a0 = 0x29;
    }
}

}
