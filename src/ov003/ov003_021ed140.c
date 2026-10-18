#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003Vec3;

typedef struct {
    u16 x, y, z;
} Ov003Rot3;

typedef struct {
    u16 state;
} Ov003Work;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0xa];
    s16 unk_18;
    u8 unk_1a[0x26];
    Ov003Work *work;
    u8 unk_44[0x1c];
    void *unk_60;
    u8 unk_64[0xc];
    Ov003Vec3 pos;
    Ov003Rot3 rot;
} Ov003Obj;

typedef struct {
    u16 id;
    u16 kind;
    u16 unk_04[4];
    s16 unk_0c;
} Ov003SpawnInfo;

typedef struct {
    u8 unk_00[0x16];
    u8 unk_16_0 : 1;
    u8 unk_17[0x81];
    u16 unk_98;
    u8 unk_9a[2];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
} Ov003Spawned;

extern void *data_ov000_021ccd64;
extern Ov003Spawned *func_ov000_0218bf1c(void *mgr, Ov003SpawnInfo *info, Ov003Vec3 *pos, Ov003Rot3 *rot, u16 a);
extern void func_ov000_0218d46c(Ov003Spawned *o, u16 a, s32 b);
extern s32 func_02040498(s32 n);
extern void func_ov000_0219763c(void *self);

void func_ov003_021ed058(Ov003Obj *self) {
    if (self->work->state == 0 && self->unk_18 != 0) {
        Ov003SpawnInfo info;
        Ov003Spawned *o;
        s32 i;
        info.id = 0x5401;
        info.kind = 0x5000;
        for (i = 0; i < 4; i++) {
            info.unk_04[i] = 0;
        }
        info.unk_0c = -1;
        o = func_ov000_0218bf1c(data_ov000_021ccd64, &info, &self->pos, &self->rot, 0xffff);
        if (o != NULL) {
            o->unk_16_0 = 1;
            func_ov000_0218d46c(o, self->unk_0c, 4);
            o->unk_9c = func_02040498(0x80) + 0x19a;
            o->unk_a0 = 0x333;
            o->unk_a4 = 0;
            o->unk_a8 = 0x52;
            o->unk_98 = self->rot.y;
        }
    }
    func_ov000_0219763c(self);
}

extern u32 data_ov003_021f6c04;
extern void func_ov003_021dae58(void *self);

void func_ov003_021ed140(Ov003Obj *self) {
    func_ov003_021dae58(self);
    self->unk_60 = &data_ov003_021f6c04;
}
