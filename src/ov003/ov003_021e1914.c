#include "types.h"

typedef struct {
    s32 x, y, z;
} Ov003Vec3;

typedef struct {
    u8 unk_00[0xc];
    u8 unk_0c[0xc];
    Ov003Vec3 unk_18;
    u8 unk_24[0x1e];
    u16 unk_42;
    u8 unk_44[0x4];
} Ov003SpotDef;

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 5;
    u8 unk_a2_5 : 1;
} Ov003Unit;

typedef struct {
    u8 unk_00[0x70];
    Ov003Vec3 unk_70;
} Ov003Player;

typedef struct {
    u8 unk_00[0xac];
    u8 unk_ac;
} Ov003Game;

typedef struct {
    u8 unk_00[0xc2];
    u16 unk_c2_0 : 1;
} Ov003Model;

typedef struct {
    void *vtbl;
    u8 unk_04[0x8];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0xa];
    s16 unk_1a;
    u16 unk_1c;
    u8 unk_1e[0x2];
    u16 unk_20;
    u8 unk_22[0x16];
    Ov003Model *unk_38;
    u8 unk_3c[0x4];
    void *unk_40;
    u8 unk_44[0x2c];
    Ov003Vec3 unk_70;
    u8 unk_7c[0x8];
    Ov003Vec3 unk_84;
    u8 unk_90[0x3];
    u8 unk_93_0 : 4;
    u8 unk_93_4 : 1;
} Ov003Prop;

extern Ov003Game *data_ov000_021ccd54;
extern void *data_ov000_021ccd64;
extern Ov003SpotDef data_ov003_021f6428[];
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_ov000_0219433c(void *self);
extern void func_ov000_02194758(void *self);
extern Ov003Player *func_ov000_0219bf90(void);
extern BOOL func_01ffc2a4(Ov003Vec3 *a, Ov003Vec3 *b, void *c, void *d);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);
extern void VEC_Add(const Ov003Vec3 *a, const Ov003Vec3 *b, Ov003Vec3 *out);

void func_ov003_021e1914(Ov003Prop *self) {
    self->unk_1c = 0;
    func_ov000_02198360(self->unk_40, 1, 0);
    func_020627a0(self->unk_0e, self->unk_0c);
    func_020627dc(4);
    data_ov000_021ccd54->unk_ac = 1;
}

void func_ov003_021e195c(Ov003Prop *self) {
    Ov003SpotDef *def;
    Ov003Player *pl;
    Ov003Vec3 v;
    func_ov000_0219433c(self);
    def = &data_ov003_021f6428[self->unk_1a];
    if ((def->unk_42 >> 12) != 5) {
        return;
    }
    pl = func_ov000_0219bf90();
    if (pl == NULL) {
        return;
    }
    v.x = pl->unk_70.x;
    v.y = pl->unk_70.y;
    v.z = pl->unk_70.z;
    if (func_01ffc2a4(&v, &self->unk_70, def, def->unk_0c)) {
        self->unk_93_4 = 1;
    }
}

void func_ov003_021e19e8(Ov003Prop *self) {
    Ov003Unit *u;
    func_ov000_02194758(self);
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_5 = 1;
    }
    self->unk_84.x = self->unk_70.x;
    self->unk_84.y = self->unk_70.y;
    self->unk_84.z = self->unk_70.z;
    VEC_Add(&self->unk_70, &data_ov003_021f6428[self->unk_1a].unk_18, &self->unk_70);
    self->unk_38->unk_c2_0 = 0;
}
