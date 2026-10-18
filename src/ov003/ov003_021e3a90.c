#include "types.h"

typedef struct {
    u8 unk_00;
    u8 unk_01;
} Ov003PropB0;

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03[0x1b];
    s16 unk_1e;
} Ov003Prop4c;

typedef struct {
    u8 unk_00[0x22];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
    u16 unk_22_2 : 2;
    u16 unk_22_4 : 1;
} Ov003Prop44;

typedef struct {
    u16 state;
    u16 timer;
} Ov003PropWk;

typedef struct {
    u8 unk_00[0x18];
    s16 unk_18;
    s16 unk_1a;
    s16 unk_1c;
    s16 unk_1e;
    u8 unk_20[0x18];
    void *model;
    u8 unk_3c[4];
    Ov003PropWk *work;
    Ov003Prop44 *unk_44;
    u8 unk_48[4];
    Ov003Prop4c *unk_4c;
    u8 unk_50[0x20];
    s32 pos[3];
    u16 unk_7c;
    u16 unk_7e;
    u8 unk_80[0x18];
    u16 unk_98;
    u8 unk_9a[2];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[4];
    Ov003PropB0 *unk_b0;
    u8 unk_b4[0x18];
    u16 unk_cc_0 : 1;
} Ov003Prop;

extern void *data_02097e4c;
extern char data_ov003_021f8564[];
extern char data_ov003_021f856e[];
extern char data_ov003_021f8574[];
extern char data_ov003_021f857c[];
extern char data_ov003_021f8581[];
extern void func_ov000_02194758(void *self);
extern void *data_ov000_021ccd64;
extern char data_ov003_021f8587[];
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_0218bed8(void *mgr, s32 a, void *self);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_021911c8(void *model, s32 v);
extern u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
extern void func_ov000_021975b4(void *self);
extern void func_ov000_02190cb0(void *model, const void *name, s32 a, s32 b);
extern void func_02049f44(void *mgr, s32 id, void *pos, s32 a);
extern void func_0204a028(void *mgr, s32 id, void *pos, s32 a);

void func_ov003_021e3890(Ov003Prop *self) {
    s16 a;
    s16 b;
    func_ov000_02194758(self);
    a = self->unk_18;
    b = self->unk_1a;
    if (a != 0 && a < b) {
        switch (self->unk_b0->unk_01) {
        case 1:
            func_ov000_02190cb0(self->model, data_ov003_021f857c, 0x1000, 0);
            break;
        case 2:
            func_ov000_02190cb0(self->model, data_ov003_021f857c, 0x1000, 0);
            break;
        }
    }
}

void func_ov003_021e3900(Ov003Prop *self) {
    s16 n;
    s16 lim;
    func_ov000_021975b4(self);
    n = self->unk_18 + 1;
    lim = self->unk_1a;
    self->unk_18 = n;
    switch (self->unk_b0->unk_01) {
    case 1:
        if (n >= lim) {
            if (self->model != NULL) {
                func_ov000_02190cb0(self->model, data_ov003_021f8564, 0x1000, 0);
            }
            self->unk_cc_0 = 0;
        } else if (self->model != NULL) {
            func_ov000_02190cb0(self->model, data_ov003_021f857c, 0x1000, 0);
        }
        break;
    case 2:
        if (n >= lim) {
            Ov003Prop44 *p;
            if (self->model != NULL) {
                func_ov000_02190cb0(self->model, data_ov003_021f8564, 0x1000, 0);
            }
            self->unk_4c->unk_02 = 5;
            p = self->unk_44;
            if (p != NULL) {
                p->unk_22_0 = 0;
                p->unk_22_1 = 0;
            }
        } else if (self->model != NULL) {
            func_ov000_02190cb0(self->model, data_ov003_021f857c, 0x1000, 0);
        }
        break;
    case 4:
        if (self->model != NULL) {
            func_ov000_02190cb0(self->model, data_ov003_021f856e, 0x1000, 0);
        }
        break;
    case 5:
        if (self->unk_4c != NULL) {
            self->unk_4c->unk_1e = self->unk_1c;
        }
        func_02049f44(data_02097e4c, 0x73, self->pos, 0);
        break;
    case 6:
        func_0204a028(data_02097e4c, 8, self->pos, -5);
        break;
    }
}

void func_ov003_021e3a90(Ov003Prop *self) {
    func_ov000_02194758(self);
    if (self->unk_18 >= self->unk_1a) {
        self->unk_4c->unk_00 = 0x10;
        if (self->unk_1e == 0) {
            self->unk_7e += 0x8000;
        }
    }
    self->unk_98 = self->unk_7e;
}

void func_ov003_021e3ad4(Ov003Prop *self) {
    Ov003PropWk *w = self->work;
    switch (w->state) {
    case 0:
        if (self->unk_18 >= self->unk_1a) {
            func_ov000_02190cb0(self->model, data_ov003_021f8581, 0x1000, 0);
        } else {
            func_ov000_02190cb0(self->model, data_ov003_021f8574, 0x1000, 0);
        }
        func_ov000_021915a0(self->model);
        func_ov000_021911c8(self->model, 0xccd);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        if (self->unk_18 >= self->unk_1a) {
            self->work->state = 10;
        } else {
            self->work->state++;
        }
        break;
    case 10:
        w->timer++;
        if (w->timer > 0x5a) {
            Ov003Prop44 *p = self->unk_44;
            p->unk_22_0 = 1;
            p->unk_22_1 = 1;
            self->unk_44->unk_22_4 = 0;
            self->unk_4c->unk_00 = 0x10;
            self->work->state++;
        }
        if (self->work->timer > 0x2d) {
            self->unk_7e = func_01ffc128(self->unk_98, self->unk_7e, 0x100, 1, 0x8000);
            self->unk_7c = func_01ffc128(0, self->unk_7c, 0x400, 1, 0x8000);
        }
        break;
    case 11:
        self->unk_7e = func_01ffc128(self->unk_98, self->unk_7e, 0x100, 1, 0x8000);
        break;
    }
}

