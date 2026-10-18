#include "types.h"

typedef struct {
    u8 unk_00[0x50];
    u32 flags;
} Ov003MvCtl;

typedef struct {
    u8 unk_00[0xa2];
    u8 active : 1;
    u8 unk_a2_1 : 4;
    u8 solid : 1;
    u8 moving : 1;
} Ov003Unit;

typedef struct {
    u8 unk_00[0x22];
    u16 enable : 1;
    u16 visible : 1;
} Ov003MvPart;

typedef struct {
    u8 unk_00[0xe];
    u16 id;
    u8 unk_10[8];
    s16 kind;
    s16 mode;
    u8 unk_1c[4];
    u16 unitId;
    u8 unk_22[0x1e];
    void *work;
    Ov003MvPart *part;
    Ov003MvCtl *ctl;
    u8 unk_4c[0x82];
    u8 type;
    u8 unk_cf;
    u16 wait;
} Ov003Mover;

extern void *data_ov000_021ccd64;
extern void func_ov000_02196c40(void *self);
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_02194758(void *self);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);
extern s32 func_02040498(s32 max);

void func_ov003_021e8a70(Ov003Mover *self) {
    func_ov000_02196c40(self);
    if (!(self->ctl->flags & 0x60000000)) {
        return;
    }
    func_ov000_02198360(self->work, 0x15, 0);
}

void func_ov003_021e8aa0(Ov003Mover *self) {
    func_ov000_02194758(self);
    switch (self->id) {
    case 0x405c:
    case 0x407b: {
        Ov003Unit *u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unitId);
        if (u != NULL) {
            u->solid = 1;
            u->active = 0;
            u->moving = 0;
        }
        self->type = 0;
        self->wait = self->kind;
        if (self->kind == 0) {
            self->wait = func_02040498(10) + 0x32;
        }
        break;
    }
    case 0x407c:
    case 0x407d:
        self->type = 1;
        break;
    }
    func_ov000_02198360(self->work, 1, 0);
}
