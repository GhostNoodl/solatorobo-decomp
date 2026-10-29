#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003Vec;

typedef struct {
    u16 state;
    u16 timer;
} Ov003EmTask;

typedef struct {
    u8 unk_00[0x26];
    s16 speed;
    s16 range;
    u16 unk_2a_0 : 4;
    u16 stopEffect : 1;
} Ov003EmDefA;

typedef struct {
    u8 unk_00[0x40];
    Ov003EmTask *task;
    u8 unk_44[0x20];
    s32 speed;
    s32 range;
    s32 halfRange;
    u8 unk_70[0x4c];
    void *effect;
    u8 unk_c0[0x10];
    Ov003EmDefA *def;
    u8 unk_d4[4];
    u16 unk_d8;
    u16 unk_da;
    u16 unk_dc;
    u16 unk_de;
    u16 unk_e0;
} Ov003EmA;

typedef struct {
    u8 unk_00[4];
    u16 duration;
    u8 unk_06[2];
    Ov003Vec offset;
    s16 sound;
    u8 unk_16[0x32];
} Ov003EmDefB;

typedef struct {
    u8 unk_00[0x7c];
    s32 alpha;
} Ov003EmFx;

typedef struct {
    u8 unk_00[0x18];
    s16 kind;
    s16 mode;
    u8 unk_1c[0x24];
    Ov003EmTask *task;
    u8 unk_44[0x1c];
    Ov003EmDefB *custom;
    u8 unk_64[0xc];
    Ov003Vec pos;
    u8 unk_7c[8];
    Ov003Vec offset;
    u8 unk_90[0x40];
    Ov003EmDefB *def;
    void *handles[2];
    Ov003Vec vecs[2];
} Ov003EmB;

extern void *data_0214a420;
extern void *data_02097e4c;
extern Ov003EmDefB data_ov003_021f49ec[];
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_0219763c(void *self);
extern void func_ov000_02195d88(void *self);
extern void func_ov000_02194758(void *self);
extern void func_02065804(void *mgr, void *handle);
extern Ov003EmFx *func_020657b0(void *mgr, void *handle);
extern void func_02063a14(Ov003EmFx *fx);
extern s32 FX_Div(s32 a, s32 b);
extern void *func_02049f44(void *mgr, s32 id, Ov003Vec *pos, s32 a);
extern void func_ov003_021dc3fc(Ov003EmB *self, s32 a, s32 b);
extern BOOL func_ov003_021dc840(Ov003EmB *self);

void func_ov003_021dc0c8(Ov003EmA *self) {
    self->unk_d8 = 0;
    self->unk_da = 0;
    self->unk_de = 0;
    self->unk_e0 = 0;
    self->unk_dc = 0;
}

void func_ov003_021dc0e4(Ov003EmA *self) {
    func_ov000_02198360(self->task, 0x15, 0);
}

void func_ov003_021dc0fc(Ov003EmA *self) {
    if (self->task->state == 0) {
        s32 v = self->def->speed;
        if (v >= 0) {
            self->speed = v << 4;
        }
        v = self->def->range;
        if (v >= 0) {
            self->range = v << 4;
            self->halfRange = (v << 4) >> 1;
        }
    }
    func_ov000_0219763c(self);
}

void func_ov003_021dc148(Ov003EmA *self) {
    if (self->task->state == 0) {
        if (self->def->stopEffect && self->effect != NULL) {
            func_02065804(data_0214a420, self->effect);
            self->effect = NULL;
        }
        self->unk_d8 = 0;
    }
    func_ov000_02195d88(self);
}

void func_ov003_021dc1a8(Ov003EmB *self) {
    Ov003EmDefB *def;
    u8 i;
    func_ov000_02194758(self);
    def = self->custom;
    if (def == NULL) {
        def = &data_ov003_021f49ec[self->kind];
    }
    self->def = def;
    for (i = 0; i < 2; i++) {
        self->vecs[i].x = 0;
        self->vecs[i].y = 0;
        self->vecs[i].z = 0;
        self->handles[i] = NULL;
    }
    def = self->def;
    self->offset.x = def->offset.x;
    self->offset.y = def->offset.y;
    self->offset.z = def->offset.z;
    if (def->sound >= 0) {
        func_02049f44(data_02097e4c, 0x5c, &self->pos, 0);
        func_02049f44(data_02097e4c, self->def->sound, &self->pos, 0);
    }
    func_ov000_02198360(self->task, 0xb, 0);
}

void func_ov003_021dc27c(Ov003EmB *self) {
    u8 i;
    Ov003EmTask *t;
    u16 st = self->task->state;
    switch (st) {
    case 0:
        func_ov003_021dc3fc(self, 1, st);
        func_ov003_021dc3fc(self, 0, st);
        if (self->task->timer >= 3) {
            func_ov003_021dc840(self);
        }
        t = self->task;
        t->timer++;
        if (t->timer >= self->def->duration || self->mode == 1) {
            self->task->timer = 0;
            self->task->state++;
        }
        break;
    case 1:
        func_ov003_021dc3fc(self, 1, st);
        func_ov003_021dc3fc(self, 0, st);
        if (self->vecs[1].x == 0 && self->vecs[1].y == 0) {
            for (i = 0; i < 2; i++) {
                Ov003EmFx *fx = func_020657b0(data_0214a420, self->handles[i]);
                if (fx != NULL) {
                    fx->alpha = FX_Div(0, 0x1f000);
                    func_02063a14(fx);
                }
            }
            func_ov000_02198360(self->task, 0x15, 0);
        }
        break;
    }
}

void func_ov003_021dc3b8(Ov003EmB *self) {
    if (self->task->state == 0) {
        func_02065804(data_0214a420, self->handles[1]);
        func_02065804(data_0214a420, self->handles[0]);
    }
    func_ov000_0219763c(self);
}
