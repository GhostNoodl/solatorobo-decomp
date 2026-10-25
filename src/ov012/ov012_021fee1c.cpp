#include "ov012/ov012.h"

extern "C" {
extern u8 data_ov012_0220abf0[];
#pragma force_active on
Ov012Actor *func_ov012_021fee1c(Ov012Actor *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = data_ov012_0220abf0;
    FLD(s32, self, 0xfc) = 0;
    FLD(s16, self, 0x100) = 0;
    FLD(u8, self, 0x102) = 0;
    FLD(u16, self, 0x104) = 0x1000;
    return self;
}
#pragma force_active reset
}

extern "C" {
extern const u8 data_ov012_0220a400[];
void func_ov012_021fee58(Ov012Actor *self) {
    Ov012Sub48 *m;
    Ov012Sub44 *n;
    func_ov003_021d112c(self);
    Ov012_ClearOwnerFlag(self);
    Ov012_VecSet(&FLD(Ov012Vec, self, 0xf0), -0x9000, 0x3000, 0);
    Ov012_VecSet(&self->pos, -0x9000, -0xa000, 0);
    self->rot[1] = 0x4000;
    n = self->unk_44;
    n->unk_22_0 = 0;
    n->unk_22_1 = 0;
    m = self->unk_48;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    m = self->unk_48;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    m = self->unk_48;
    m->unk_9a_2 = 0;
    m->unk_9a_5 = 0;
    self->unk_48->unk_30 = 0;
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov012_0220a400);
        FLD(s16, self, 0x104) = 0x1800;
    }
}
}

extern "C" {
void func_ov012_021fef64(Ov012Actor *self, Ov012Msg *msg) {
    switch (msg->type) {
    case 6:
        FLD(s16, self, 0x100) = msg->idx;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        break;
    case 0xe:
        FLD(u8, self, 0x102) = msg->idx;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        break;
    }
    func_ov003_021d1c00(self, msg);
}
}

extern "C" {
extern const Ov012Vec data_ov012_0220a4a4[];
extern const Ov012Vec data_ov012_0220a4bc[];
void func_ov012_021fefc8(Ov012Actor *self) {
    Ov012Actor *pl;
    Ov012Vec v;
    s32 a;
    if (!Ov012_GameIdle()) {
        return;
    }
    FLD(u16, self, 0x90) = 0xffff;
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        FLD(u16, self, 0x90) = pl->id;
    }
    v.x = pl->pos.x;
    v.y = pl->pos.y;
    v.z = pl->pos.z;
    VEC_Distance(&self->pos, &v);
    if (!(self->unk_30 & 0x40)) {
        return;
    }
    switch (FLD(u16, self, 0x100)) {
    case 1:
        self->unk_38->unk_c2_0 = 0;
        FLD(u32, self, 0xfc) |= 0x100000;
        break;
    case 2:
        if (FLD(u32, self, 0xfc) & 0x100000) {
            FLD(u32, self, 0xfc) ^= 0x100000;
        }
        self->unk_38->unk_c2_0 = 1;
        FLD(Ov012Vec, self, 0xf0) = data_ov012_0220a4a4[FLD(u8, self, 0x102)];
        self->pos = data_ov012_0220a4bc[FLD(u8, self, 0x102)];
        switch (FLD(u8, self, 0x102)) {
        case 0:
            a = 1;
            self->rot[1] = 0xbff4;
            break;
        case 1:
            a = 2;
            self->rot[1] = 0x4000;
            break;
        }
        func_ov000_0219bd20(0x5c02, self->kind, 0xe, 1, 4, &a);
        break;
    case 4:
        self->unk_38->unk_c2_0 = 1;
        self->unk_40->flags |= 0x4000;
        break;
    case 0x10:
        self->unk_40->flags = 0;
        self->unk_40->flags |= 0x200000;
        break;
    }
    FLD(s16, self, 0x100) = 0;
}
}
