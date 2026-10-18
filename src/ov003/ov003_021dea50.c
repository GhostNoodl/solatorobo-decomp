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
    void *vtbl;
    u8 unk_04[0x14];
    s16 unk_18;
    u8 unk_1a[0x1e];
    void *unk_38;
    u8 unk_3c[0x8];
    Ov003Part44 *unk_44;
    Ov003Part48 *unk_48;
    u8 unk_4c[0x84];
    s32 unk_d0;
} Ov003Prop;

extern void *data_02097e4c;
extern char data_ov003_021f83e8[];
extern const char data_ov003_021f8510[];
extern const char data_ov003_021f8516[];
extern void func_0203de1c(void *p);
extern void func_ov000_0219429c(void *p);
extern void func_ov000_02194758(void *p);
extern void func_02049bb4(void *mgr, s32 id);
extern s32 func_02049afc(void *mgr, s32 v);
extern void func_ov000_02190cb0(void *p, const char *name, s32 a, s32 b);
extern void func_ov000_02191318(void *p, s32 v);
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
