#include "types.h"

typedef struct {
    u16 state;
} Ov003Work;

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02[0x1a];
    u16 unk_1c;
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
    u8 unk_00[0x30];
    u32 unk_30;
} Ov003Part48;

typedef struct {
    u8 unk_00[6];
    u16 unk_06;
    u8 unk_08[0xe];
    u16 unk_16;
    u8 unk_18[0x1e];
} Ov003TableEntry;

typedef struct {
    u8 unk_00[0x24];
    Ov003TableEntry *entries;
} Ov003Table;

typedef struct {
    u8 unk_00[0x34];
} Ov003Table34;

typedef struct {
    u16 unk_00;
    u16 unk_02;
} Ov003Work2;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x0a];
    s16 unk_18;
    u8 unk_1a[0x76];
    u16 unk_90;
} Ov003Spawned;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[8];
    s16 unk_18;
    s16 unk_1a;
    u16 unk_1c;
    u16 unk_1e;
    u16 unk_20;
    u8 unk_22[0x16];
    void *unk_38;
    void *unk_3c;
    Ov003Work *work;
    Ov003Part *unk_44;
    Ov003Part48 *unk_48;
    Ov003Part *unk_4c;
    u8 unk_50[0x20];
    u8 unk_70[0xc];
    u8 unk_7c[0x14];
    u16 unk_90;
    u8 unk_92[0x3a];
    u16 unk_cc_0 : 3;
    u16 unk_cc_3 : 1;
    u16 unk_cc_4 : 1;
    u16 unk_ce;
    s16 unk_d0;
    u8 unk_d2[0x136];
    union {
        u16 unk_208;
        Ov003Table *table;
    };
    u16 unk_20c;
    u16 unk_20e[5];
} Ov003Event;

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 1;
} Ov003Unit;

typedef struct {
    u8 unk_00[0x15];
    u8 unk_15;
    u8 unk_16[0xb12];
    u8 unk_b28_0 : 2;
    u8 unk_b28_2 : 1;
} Ov003Player;

extern void *data_ov000_021ccd64;
extern char data_ov003_021f8564[];
extern char data_ov003_021f8569[];
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_ov000_02196060(void *self);
extern void func_ov000_02194758(void *self);
extern void func_ov000_02197d80(void *self);
extern Ov003Spawned *func_ov000_02199ba0(Ov003Part *p);
extern Ov003Spawned *func_ov000_0219be1c(s32 id, void *pos, void *rot, u16 a, u16 b);
extern BOOL func_020621c4(void);
extern void func_ov000_0219bebc(Ov003Spawned *p, s32 v);
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern s32 func_ov003_021f093c(Ov003Part *p);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern s32 func_0205b1fc(void);
extern Ov003Player *func_ov000_0219bf90(void);
extern Ov003Table34 data_ov003_021f62f0[];
extern Ov003Table *data_ov003_021f5fac[];
extern void func_ov000_0219b808(u16 id, void *pos, Ov003Table34 *entry, s32 a, s32 b);
extern void func_ov000_02193e5c(s16 *p);
extern void func_ov003_021d0a2c(s16 *p);

static inline BOOL Ov003Event_SetMode(Ov003Event *self, s16 mode) {
    if (self->unk_18 != mode) {
        self->unk_18 = mode;
        return TRUE;
    }
    return FALSE;
}

extern char data_ov003_021f8537[];
extern Ov003Global54 *data_ov000_021ccd54;
extern void func_ov000_02190cb0(void *p, const char *name, s32 a, s32 b);
extern BOOL func_ov000_02191120(void *p);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_ov000_0219433c(void *self);
extern void *func_0207011c(s32 id);
extern void func_ov000_0218f074(s16 *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern BOOL func_ov000_021946f8(void *self);
extern BOOL func_ov000_0218f110(s16 *p);
extern void func_0203de1c(void *p);
extern void func_ov000_0219429c(void *p);

BOOL func_ov003_021e0e8c(Ov003Event *self) {
    BOOL r = func_ov000_021946f8(self);
    if (self->unk_d0 >= 0) {
        if (!func_ov000_0218f110(&self->unk_d0)) {
            r = FALSE;
        }
    }
    return r;
}

void func_ov003_021e0ec0(Ov003Event *self) {
    Ov003Spawned *p;
    Ov003Part *part;
    u16 a = 0xffff;
    u16 b;
    u16 v;
    self->unk_208 = a;
    p = func_ov000_02199ba0(self->unk_4c);
    b = a;
    if (p != NULL) {
        a = p->unk_0c;
        b = p->unk_90;
    }
    p = func_ov000_0219be1c(0x4801, self->unk_70, self->unk_7c, a, b);
    if (p != NULL) {
        s16 type = 2;
        if (self->unk_0e == 0x4058) {
            type = 3;
        }
        p->unk_18 = type;
        self->unk_208 = p->unk_0c;
        if (func_020621c4() && (self->unk_4c->unk_1c >> 12) == 5) {
            func_ov000_0219bebc(p, 0x1800);
        }
    }
    part = self->unk_4c;
    if (part->unk_1e <= 1) {
        part->unk_01 = 1;
        v = 0;
    } else {
        v = part->unk_1e - 1;
    }
    self->unk_4c->unk_1e = v;
    func_ov000_02198360(self->work, 9, 0);
}

void func_ov003_021e0fa8(Ov003Event *self) {
    if (self->work->state == 0) {
        if (self->unk_0e == 0x4058) {
            if (self->unk_90 != 0xffff) {
                self->unk_48->unk_30 = 0;
            }
        }
        self->unk_4c->unk_01 = 1;
    }
    func_ov000_02196060(self);
}

void func_ov003_021e1000(Ov003Event *self) {
    Ov003Unit *unit;
    func_ov000_0219433c(self);
    unit = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (unit != NULL) {
        unit->unk_a2_0 = 0;
    }
}

void func_ov003_021e1034(Ov003Event *self) {
    func_ov000_02194758(self);
    func_ov000_02197d80(self);
    if (self->unk_1a == 0) {
        self->unk_18 = 2;
        return;
    }
    switch (self->unk_18) {
    case 2:
        if (self->unk_38 != NULL) {
            func_ov000_02190cb0(self->unk_38, data_ov003_021f8564, 0x1000, 0);
        }
        break;
    case 0:
    case 1:
    case 3:
        if (self->unk_38 != NULL) {
            func_ov000_02190cb0(self->unk_38, data_ov003_021f8569, 0x1000, 0);
        }
        break;
    }
}

void func_ov003_021e10c4(Ov003Event *self) {
    BOOL changed = FALSE;
    Ov003Player *player;
    switch (self->unk_1a) {
    case 3:
        switch (func_ov003_021f093c(self->unk_4c)) {
        case 3:
        case 4:
            changed = Ov003Event_SetMode(self, 2);
            break;
        case 1:
        case 2:
            changed = Ov003Event_SetMode(self, 0);
            break;
        }
        break;
    case 5:
        switch (func_ov003_021f093c(self->unk_4c)) {
        case 3:
        case 4:
            changed = Ov003Event_SetMode(self, 0);
            break;
        case 1:
        case 2:
            changed = Ov003Event_SetMode(self, 2);
            break;
        }
        break;
    }
    if (!changed) {
        return;
    }
    func_ov000_02197dec(self, self->unk_18, self->unk_18);
    if (func_0205b1fc() != 1) {
        return;
    }
    player = func_ov000_0219bf90();
    if (player == NULL) {
        return;
    }
    if (player->unk_b28_0 != 0) {
        return;
    }
    player->unk_15 = 3;
    player->unk_b28_0 = 0;
    player->unk_b28_2 = 1;
}

void func_ov003_021e11c4(Ov003Event *self) {
    if (self->unk_18 == 0) {
        return;
    }
    func_ov000_0219b808(self->unk_0c, self->unk_70, &data_ov003_021f62f0[(s16)self->unk_1c], 0, 0);
}
