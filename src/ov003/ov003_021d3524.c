#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003V3;

typedef struct {
    u16 state;
    u16 timer;
} Ov003Wk;

typedef struct {
    u8 unk_00[0x50];
    u32 flags;
    u8 unk_54[0x46];
    u16 unk_9a_0 : 4;
    u16 unk_9a_4 : 1;
    u16 unk_9a_5 : 1;
} Ov003Ct;

typedef struct {
    u16 unk_00;
} Ov003S50;

typedef struct {
    u8 unk_00[0x1c];
    u16 unk_1c;
} Ov003S4c;

typedef struct {
    s16 unk_00;
    s16 unk_02;
} Ov003SB0;

typedef struct {
    u8 unk_00[0x38];
    void *model;
    u8 unk_3c[4];
    Ov003Wk *work;
    u8 unk_44[4];
    Ov003Ct *ctl;
    Ov003S4c *unk_4c;
    Ov003S50 *unk_50;
    u8 unk_54[0x2a];
    u16 unk_7e;
    u8 unk_80[0x18];
    u16 unk_98;
    u8 unk_9a[2];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[4];
    Ov003SB0 *unk_b0;
    u16 unk_b4;
    u16 unk_b6;
    Ov003V3 unk_b8;
    u8 unk_c4[0x2a];
    u16 unk_ee_0 : 1;
} Ov003Unk;

extern char data_ov003_021f7a60[];
extern char data_ov003_021f7a66[];
extern char data_ov003_021f7a6c[];
extern char data_ov003_021f7a72[];
extern BOOL func_ov000_02190cb0(void *model, const void *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_021911c8(void *model, s32 v);
extern s32 func_02040528(s32 max);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_0218ddd4(void *self, Ov003V3 *v, s32 a);
extern void func_ov000_021987b8(Ov003Ct *ctl, s32 a, s32 b, s32 c);

void func_ov003_021d3524(Ov003Unk *self) {
    if (self->work->state == 0) {
        const char *name = data_ov003_021f7a60;
        if (self->unk_ee_0) {
            name = data_ov003_021f7a66;
        }
        func_ov000_02190cb0(self->model, name, 0x2ab, 0);
        func_ov000_021915a0(self->model);
        func_ov000_021911c8(self->model, (s16)(func_02040528(0x19a) + 0x1000));
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->work->state++;
    }
    if (self->ctl != NULL && self->ctl->unk_9a_4) {
        self->ctl->unk_9a_5 = 1;
        if (!(self->ctl->flags & 0x20000000)) {
            func_ov000_02198360(self->work, 4, 0);
        }
    }
}

void func_ov003_021d3600(Ov003Unk *self) {
    Ov003SB0 *p;
    Ov003V3 v;
    if (self->work->state == 0) {
        const char *name = data_ov003_021f7a6c;
        if (self->unk_ee_0) {
            name = data_ov003_021f7a72;
        }
        func_ov000_02190cb0(self->model, name, 0x2ab, 0);
        func_ov000_021915a0(self->model);
        self->work->state++;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
    }
    self->ctl->unk_9a_5 = 1;
    p = self->unk_b0;
    self->unk_9c = p->unk_00;
    v.x = self->unk_b8.x;
    v.y = self->unk_b8.y;
    v.z = self->unk_b8.z;
    func_ov000_0218ddd4(self, &v, p->unk_02);
    func_ov000_021987b8(self->ctl, 1, 0, 0);
    if (!(self->ctl->flags & 0x20000000)) {
        func_ov000_02198360(self->work, 4, 0);
    }
}
