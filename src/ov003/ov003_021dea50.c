#include "types.h"

typedef struct {
    u8 unk_00[0x10];
    s32 unk_10;
    u8 unk_14[0xe];
    u16 unk_22_0 : 2;
    u16 unk_22_2 : 2;
} Ov003Part44;

typedef struct {
    u8 unk_00[0x60];
    s32 unk_60;
} Ov003Part48;

typedef struct {
    u16 state;
    u16 timer;
} Ov003PropWk;

typedef struct {
    s32 x, y, z;
} Ov003PropVec;

typedef struct {
    void *vtbl;
    u8 unk_04[0x14];
    s16 unk_18;
    u8 unk_1a[0x1e];
    void *unk_38;
    u8 unk_3c[0x4];
    Ov003PropWk *work;
    Ov003Part44 *unk_44;
    Ov003Part48 *unk_48;
    u8 unk_4c[0x24];
    Ov003PropVec pos;
    u8 unk_7c[0x54];
    s32 unk_d0;
} Ov003Prop;

extern void *data_02097e4c;
extern char data_ov003_021f83e8[];
extern const char data_ov003_021f8510[];
extern const char data_ov003_021f8516[];
extern void func_0203de1c(void *p);
extern void *func_ov000_0219429c(void *p);
extern void func_ov000_02194758(void *p);
extern void func_02049bb4(void *mgr, s32 id);
extern s32 func_02049afc(void *mgr, s32 v);
extern BOOL func_ov000_02190cb0(void *p, const char *name, s32 a, s32 b);
extern void *func_ov000_02191318(void *p, s32 v);
extern void func_ov000_021915a0(void *p);

Ov003Prop *func_ov003_021dea50(Ov003Prop *self) {
    self->vtbl = data_ov003_021f83e8;
    if (self->unk_d0 >= 0) {
        func_02049bb4(data_02097e4c, self->unk_d0);
    }
    func_ov000_0219429c(self);
    return self;
}

Ov003Prop *func_ov003_021dea90(Ov003Prop *self) {
    self->vtbl = data_ov003_021f83e8;
    if (self->unk_d0 >= 0) {
        func_02049bb4(data_02097e4c, self->unk_d0);
    }
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov003_021dead8(Ov003Prop *self) {
    func_ov000_02194758(self);
    if (self->unk_18 >= 3) {
        func_ov000_02190cb0(self->unk_38, data_ov003_021f8510, 0x1000, 0);
        func_ov000_02191318(self->unk_38, -1);
    } else {
        func_ov000_02190cb0(self->unk_38, data_ov003_021f8516, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
    }
    self->unk_44->unk_22_2 = 2;
    self->unk_44->unk_10 = -0x3800;
    self->unk_48->unk_60 = -0x3800;
    self->unk_d0 = func_02049afc(data_02097e4c, 0x3f);
}

extern void func_ov000_0218996c(s32 a, s32 b);
extern void *func_ov000_0219b71c(Ov003PropVec *pos, Ov003PropVec *v, s32 a, s32 b, s32 c, s32 d);

void func_ov003_021deb80(Ov003Prop *self) {
    Ov003PropWk *w;
    s32 a;
    s32 b;
    Ov003PropVec p;
    Ov003PropVec sc;
    if (self->unk_18 < 3) {
        return;
    }
    w = self->work;
    w->timer++;
    if (w->timer & 0xf) {
        return;
    }
    a = -1;
    b = 100;
    switch (self->work->timer & 0x3f) {
    case 0:
        func_ov000_0218996c(8, 0xf);
        a = 1;
        break;
    case 0x10:
        break;
    case 0x20:
        func_ov000_0218996c(6, 8);
        a = 3;
        break;
    case 0x30:
        a = 3;
        b = 0x19;
        break;
    }
    p.x = self->pos.x;
    p.y = self->pos.y;
    p.z = self->pos.z;
    p.y -= 0x4000;
    sc.x = 0x5000;
    sc.y = 0x3000;
    sc.z = 0x3800;
    func_ov000_0219b71c(&p, &sc, 0x1000, 0x2800, a, b);
}
