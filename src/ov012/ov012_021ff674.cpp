#include "ov012/ov012.h"

extern "C" {
extern const Ov012Vec data_ov012_0220a4bc[];
void func_ov012_021ff674(Ov012Actor *self) {
    s32 off = 0;
    Ov012Sub40 *s;
    u8 side = FLD(u8, self, 0x102);
    switch (side) {
    case 0:
        off = -0x1000;
        break;
    case 1:
        off = 0x1000;
        break;
    }
    s = self->unk_40;
    switch (*(volatile u16 *)&s->state) {
    case 0:
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x480b, 0x15);
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4[0], 0x400, 0);
        self->unk_b8.y = self->pos.y;
        self->unk_b8.z = self->pos.z;
        self->unk_b8.x = self->pos.x - off;
        self->unk_40->state++;
        break;
    case 1:
        if (!(FLD(u32, self, 0xfc) & 0x100000)) {
            Ov012Vec v;
            s32 a;
            func_ov000_0218d918(self, (void *)&data_ov012_0220a4bc[side], 0x19a);
            if (!func_ov000_02191120(self->unk_38)) {
                return;
            }
            v.x = self->unk_b8.x;
            v.y = self->unk_b8.y;
            v.z = self->unk_b8.z;
            func_ov000_0218ddd4(self, &v, 0);
            if (VEC_Distance(&self->pos, &self->unk_b8) > 0x800) {
                return;
            }
            switch (FLD(u8, self, 0x102)) {
            case 0:
                a = 4;
                break;
            case 1:
                a = 8;
                break;
            }
            func_ov000_0219bd20(0x5c02, self->kind, 0xe, 1, 4, &a);
            self->unk_40->state++;
        } else {
            s->state++;
        }
        break;
    case 2:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a3c4[1], 0x89, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->state++;
        break;
    case 3:
        if (FLD(u32, self, 0xfc) & 0x100000) {
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->v08();
        }
        break;
    }
}
}

extern "C" {
extern const Ov012Vec data_ov012_0220a4d4[];
void func_ov012_021ff8b4(Ov012Actor *self, s32 idx) {
    Ov012SpawnDesc d;
    Ov012Vec v;
    Ov012Vec dir;
    u16 r[3];
    Ov012Actor *o;
    Ov012Spawn_Init(&d, 0x480b);
    v.x = 0x99a;
    v.y = 0x1000;
    v.z = 0x2000;
    func_01ffc9fc(&v, &v, self->rot[1]);
    VEC_Add(&self->pos, &v, &v);
    dir = data_ov012_0220a4d4[idx - 1];
    if (FLD(s32, self, 0xf0) >= 0) {
        dir.x = -dir.x;
    }
    dir.x = dir.x - v.x;
    dir.y = dir.y - v.y;
    dir.z = dir.z - v.z;
    VEC_Normalize(&dir, &dir);
    r[0] = 0;
    r[1] = 0;
    r[2] = 0;
    r[0] = FX_AsinIdx(-dir.y);
    r[1] = FX_Atan2(dir.x, dir.z);
    o = func_ov000_0218bf1c(data_ov000_021ccd64, &d, &v, r, 0xffff);
    if (o == NULL) {
        return;
    }
    FLD(u16, o, 0x18) = 6;
    func_ov000_0219bebc(o, FLD(s16, self, 0x104));
    FLD(Ov012Flags8, o, 0x16).b0 = 1;
    if (FLD(void *, o, 0x4c) != NULL) {
        FLD(u16, FLD(void *, o, 0x4c), 0x1c) = self->id;
    }
}
}

extern "C" {
extern u8 data_ov012_0220ab44[];
#pragma force_active on
Ov012Actor *func_ov012_021ffa68(Ov012Actor *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = data_ov012_0220ab44;
    FLD(s32, self, 0x100) = 0;
    FLD(s16, self, 0x104) = 0;
    FLD(u8, self, 0x106) = 0;
    FLD(u8, self, 0x107) = 0;
    FLD(s32, self, 0xfc) = 0;
    FLD(s32, self, 0x108) = 0;
    return self;
}
#pragma force_active reset
}

extern "C" {
extern u8 data_ov012_0220ab44[];
void *func_ov012_021ffaa8(void *self) {
    FLD(void *, self, 0) = data_ov012_0220ab44;
    Ov012_FreeFx(self, 0x108);
    func_ov003_021d0edc(self);
    return self;
}
}

extern "C" {
extern u8 data_ov012_0220ab44[];
void *func_ov012_021ffb18(void *self) {
    FLD(void *, self, 0) = data_ov012_0220ab44;
    Ov012_FreeFx(self, 0x108);
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}
}

extern "C" {
void func_ov012_021ffb90(Ov012Actor *self) {
    func_ov003_021d0fc0(self);
}
}

extern "C" {
BOOL func_ov012_021ffb9c(Ov012Actor *self) {
    return func_ov000_0218cf5c(self);
}
}

extern "C" {
extern const u8 data_ov012_0220a3f0[];
void func_ov012_021ffba8(Ov012Actor *self) {
    Ov012Sub48 *m;
    Ov012Sub44 *n;
    func_ov003_021d112c(self);
    FLD(s32 *, self, 0x108) = Ov012_NewFx();
    Ov012_ClearOwnerFlag(self);
    self->unk_ea_6 = 1;
    Ov012_VecSet(&FLD(Ov012Vec, self, 0xf0), 0x9000, 0x3000, 0);
    Ov012_VecSet(&self->pos, 0x9000, -0xa000, 0);
    self->rot[1] = 0xbff4;
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
        func_ov003_021d6bac(self, data_ov012_0220a3f0);
    }
}
}

extern "C" {
void func_ov012_021ffcd0(Ov012Actor *self, Ov012Msg *msg) {
    switch (msg->type) {
    case 6:
        FLD(s16, self, 0x104) = msg->idx;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        break;
    case 0xe:
        FLD(u8, self, 0x106) = msg->idx;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        break;
    }
    func_ov003_021d1c00(self, msg);
}
}
