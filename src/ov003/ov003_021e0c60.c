#include "types.h"

typedef struct {
    u16 state;
} Ov003Work;

typedef struct {
    u8 unk_00[0x1e];
    u16 unk_1e;
    u8 unk_20[2];
    u16 flag0 : 1;
    u16 flag1 : 1;
} Ov003Part;

typedef struct {
    u8 unk_00[0xac];
    u8 unk_ac;
} Ov003Global54;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0x28];
    void *unk_38;
    u8 unk_3c[4];
    Ov003Work *work;
    Ov003Part *unk_44;
    u8 unk_48[4];
    Ov003Part *unk_4c;
    u8 unk_50[0x80];
    s16 unk_d0;
} Ov003Event;

extern char data_ov003_021f8537[];
extern Ov003Global54 *data_ov000_021ccd54;
extern BOOL func_ov000_02190cb0(void *p, const char *name, s32 a, s32 b);
extern BOOL func_ov000_02191120(void *p);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_ov000_0219433c(void *self);
extern void *func_0207011c(s32 id);
extern void func_ov000_0218f074(s16 *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern BOOL func_ov000_021946f8(void *self);
extern BOOL func_ov000_0218f110(s16 *p);
extern void func_0203de1c(void *p);
extern void *func_ov000_0219429c(void *p);

void func_ov003_021e0c60(Ov003Event *self) {
    Ov003Part *part;
    switch (self->work->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov003_021f8537, 0x1000, 0);
        part = self->unk_44;
        if (part != NULL) {
            part->flag0 = 0;
            part->flag1 = 0;
        }
        self->work->state++;
    case 1:
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        func_020627a0(self->unk_0e, self->unk_0c);
        func_020627dc(4);
        data_ov000_021ccd54->unk_ac = 1;
        self->work->state = 0x7fff;
        break;
    }
}

void *func_ov003_021e0d18(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov003_021e0d2c(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021e0d48(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov003_021e0d5c(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021e0d78(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov003_021e0d8c(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021e0da8(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov003_021e0dbc(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021e0dd8(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov003_021e0dec(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021e0e08(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov003_021e0e1c(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov003_021e0e38(Ov003Event *self) {
    func_ov000_0219433c(self);
    func_ov000_0218f074(&self->unk_d0, func_0207011c(0x4801), 1, 0, 0, 0);
    self->unk_d0 = 0;
    self->unk_4c->unk_1e = 3;
}
