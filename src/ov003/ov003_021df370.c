#include "types.h"

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 1;
} Ov003Unit;

typedef struct {
    s32 x, y, z;
} Ov003Vec3;

typedef struct {
    u8 unk_00[0xa8];
    s32 unk_a8;
    s32 unk_ac;
    s32 unk_b0;
} Ov003Model;

typedef struct {
    void *vtbl;
    u8 unk_04[0x16];
    s16 unk_1a;
    u8 unk_1c[0x4];
    u16 unk_20;
    u8 unk_22[0x16];
    Ov003Model *unk_38;
    u8 unk_3c[0x34];
    Ov003Vec3 unk_70;
    u8 unk_7c[0x8];
    Ov003Vec3 unk_84;
    u8 unk_90[0x40];
    s32 unk_d0;
} Ov003Prop;

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern char data_ov003_021f8350[];
extern void func_0203de1c(void *p);
extern void func_ov000_0219429c(void *p);
extern void func_ov000_02194758(void *p);
extern void func_02049bb4(void *mgr, s32 id);
extern s32 func_02049afc(void *mgr, s32 v);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_ov000_0218b700(Ov003Unit *u, s32 a, s32 b);

Ov003Prop *func_ov003_021df370(Ov003Prop *self) {
    self->vtbl = data_ov003_021f8350;
    if (self->unk_d0 >= 0) {
        func_02049bb4(data_02097e4c, self->unk_d0);
    }
    func_ov000_0219429c(self);
    return self;
}

Ov003Prop *func_ov003_021df3b0(Ov003Prop *self) {
    self->vtbl = data_ov003_021f8350;
    if (self->unk_d0 >= 0) {
        func_02049bb4(data_02097e4c, self->unk_d0);
    }
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov003_021df3f8(Ov003Prop *self) {
    Ov003Unit *u;
    s32 s;
    func_ov000_02194758(self);
    s = self->unk_1a;
    if (s != 0) {
        Ov003Model *m = self->unk_38;
        m->unk_a8 = s;
        m->unk_ac = s;
        m->unk_b0 = s;
    }
    self->unk_84.x = self->unk_70.x;
    self->unk_84.y = self->unk_70.y;
    self->unk_84.z = self->unk_70.z;
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_0 = 0;
        func_ov000_0218b700(u, 0x5000, 0);
    }
    self->unk_d0 = func_02049afc(data_02097e4c, 0x3f);
}
