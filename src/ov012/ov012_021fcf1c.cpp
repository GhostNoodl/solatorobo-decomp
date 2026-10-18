#include "ov012/ov012.h"

extern "C" {
void func_ov012_021fd708(Ov012Actor *self);
void func_ov012_021fdfa0(Ov012Actor *self);
void func_ov012_021fcf1c(Ov012Actor *self) {
    switch (FLD(s16, self, 0xf0)) {
    case 0:
        func_ov012_021fd708(self);
        break;
    case 1:
        func_ov012_021fdfa0(self);
        break;
    }
}
}

extern "C" {
extern char data_ov012_0220ab21[];
extern const Ov012Vec data_ov012_0220a414;
void func_ov012_021fcf48(Ov012Actor *self) {
    Ov012Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220ab21, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        func_02049f44(data_02097e4c, 0xe, &self->pos, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1: {
        u8 i;
        for (i = 0; i < 4; i++) {
            Ov012SpawnDesc d;
            Ov012Actor *o;
            Ov012Spawn_Init(&d, 0xffff);
            Ov012Spawn_Set(&d, 0x480f);
            o = func_ov000_02192b24(&d);
            if (o != NULL) {
                Ov012Vec t;
                VEC_Add(&self->pos, &data_ov012_0220a414, &t);
                o->pos = t;
                o->rot[0] = self->rot[0];
                o->rot[1] = self->rot[1];
                o->rot[2] = self->rot[2];
                FLD(u16, o, 0x18) = i;
                o->unk_90 = self->unk_90;
                o->v04();
                FLD(Ov012Flags8, o, 0x16).b0 = 1;
                func_ov000_0219bebc(o, FLD(s16, self, 0x170));
                if (FLD(void *, o, 0x4c) != NULL) {
                    FLD(u16, FLD(void *, o, 0x4c), 0x1c) = self->id;
                }
            }
        }
        func_02049f44(data_02097e4c, 0x501, &self->pos, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    }
    case 2:
        s->timer = 0;
        func_ov000_02198360(self->unk_40, 1, 0);
        FLD(u8, self, 0x110) = 0;
        FLD(u32, self, 0x10c) |= 1;
        break;
    }
}
}

extern "C" {
void func_ov012_021fd148(Ov012Actor *self) {
    Ov012Sub40 *s = self->unk_40;
    switch (s->state) {
    case 0:
        s->timer = 0;
        self->unk_40->state++;
        break;
    case 1:
        s->timer++;
        if (s->timer > 5) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}
}
