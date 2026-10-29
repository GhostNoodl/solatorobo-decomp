#include "types.h"

typedef void (*VFunc)(void *);

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
} Ov003Part;

typedef struct {
    u8 unk_00[0x16];
    u8 unk_16_0 : 2;
    u8 unk_16_2 : 1;
} Ov003Player;

typedef struct {
    u8 unk_00[0x24];
    u8 unk_24[0x14];
    void *unk_38;
    u8 unk_3c[0x10];
    Ov003Part *unk_4c;
    u8 unk_50[0x7c];
    u16 unk_cc_0 : 7;
    u16 unk_cc_7 : 1;
    u16 unk_ce;
} Ov003Obj;

extern void func_ov000_02194758(void *self);
extern Ov003Player *func_ov000_0219bf90(void);
extern void *func_0203dd9c(u32 size);
extern Ov003Part *func_ov000_02199b00(void *p);
extern void *func_0203db40(void *p);
extern void func_ov000_02190a80(void *a, void *b);
extern void func_0203de1c(void *p);
extern void *func_ov000_0218fee4(void *p);
extern void *func_ov000_0219429c(void *p);

void *func_ov003_021ea858(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021ea874(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov003_021ea888(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021ea8a4(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov003_021ea8b8(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021ea8d4(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov003_021ea8e8(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021ea904(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov003_021ea918(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021ea934(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov003_021ea948(void *self) {
    func_ov000_0218fee4((u8 *)self + 0xd0);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021ea970(void *self) {
    func_ov000_0218fee4((u8 *)self + 0xd0);
    func_ov000_0219429c(self);
    return self;
}

void *func_ov003_021ea990(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021ea9ac(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov003_021ea9c0(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021ea9dc(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov003_021ea9f0(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021eaa0c(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov003_021eaa20(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov003_021eaa34(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov003_021eaa50(Ov003Obj *self) {
    Ov003Player *player;
    func_ov000_02194758(self);
    self->unk_ce = 0;
    player = func_ov000_0219bf90();
    if (player == NULL) {
        return;
    }
    if (!player->unk_16_2) {
        return;
    }
    if (self->unk_4c == NULL) {
        Ov003Part *part = func_0203dd9c(0x5c);
        if (part != NULL) {
            part = func_ov000_02199b00(part);
        }
        self->unk_4c = part;
    }
    self->unk_4c->unk_03 = 10;
    self->unk_4c->unk_00 = 7;
    self->unk_4c->unk_01 = 4;
    self->unk_4c->unk_02 = 0;
}

void func_ov003_021eaad8(Ov003Obj *self) {
    if (self->unk_cc_7 && self->unk_38 != NULL) {
        func_ov000_02190a80(self->unk_38, func_0203db40(self->unk_24));
    }
}
