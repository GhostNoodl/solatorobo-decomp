#pragma pool_strings on
#pragma dont_reuse_strings off
#include "types.h"
#include "ov003/GmObj.h"

// ---- merged from ov003_021e0e8c.c
namespace m_021e0e8c {
extern "C" {

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
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_ov000_02196060(void *self);
extern void func_ov000_02194758(void *self);
extern void func_ov000_02197d80(void *self);
extern Ov003Spawned *func_ov000_02199ba0(Ov003Part *p);
extern Ov003Spawned *func_ov000_0219be1c(s32 id, void *pos, void *rot, u16 a, u16 b);
extern BOOL func_020621c4(void);
extern void func_ov000_0219bebc(Ov003Spawned *p, s32 v);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern s32 func_ov003_021f093c(Ov003Part *p);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern s32 func_0205b1fc(void);
extern Ov003Player *func_ov000_0219bf90(void);
extern Ov003Table34 data_ov003_021f62f0[];
extern Ov003Table *data_ov003_021f5fac[];
extern void func_ov000_0219b808(u16 id, void *pos, Ov003Table34 *entry, s32 a, s32 b);
extern void func_ov000_02193e5c(void *res, s32 id);
extern void func_ov003_021d0a2c(void *res, u16 id);

static inline BOOL Ov003Event_SetMode(Ov003Event *self, s16 mode) {
    if (self->unk_18 != mode) {
        self->unk_18 = mode;
        return TRUE;
    }
    return FALSE;
}

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
            func_ov000_02190cb0(self->unk_38, "op02", 0x1000, 0);
        }
        break;
    case 0:
    case 1:
    case 3:
        if (self->unk_38 != NULL) {
            func_ov000_02190cb0(self->unk_38, "op00", 0x1000, 0);
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

void func_ov003_021e1204(Ov003Event *self) {
    Ov003TableEntry *e;
    Ov003Unit *unit;
    func_ov000_0219433c(self);
    self->table = data_ov003_021f5fac[(u16)self->unk_1a];
    e = &self->table->entries[self->unk_18];
    if (e->unk_06 == 0) {
        u16 id = e->unk_16;
        u16 kind = (u16)(id >> 12);
        if (kind == 4) {
            func_ov000_02193e5c(&self->unk_d0, id);
        } else if (kind == 5) {
            func_ov003_021d0a2c(&self->unk_d0, id);
        }
    }
    unit = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (unit != NULL) {
        unit->unk_a2_0 = 0;
    }
    self->unk_cc_3 = 0;
    self->unk_cc_4 = 0;
}
}
}  // namespace m_021e0e8c

// ---- merged from ov003_021e12b0.cpp
namespace m_021e12b0 {

struct Ov003EvBase {
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void Release();
};

extern "C" {

typedef struct {
    u16 state;
    u16 timer;
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
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
    u8 unk_98[0x14];
    u8 unk_ac;
} Ov003Global54;

typedef struct {
    u8 unk_00[0x30];
    u32 unk_30;
} Ov003Part48;

typedef struct {
    u8 group;
    u8 max;
    u8 mode;
    s8 next;
    u16 wait;
    u16 unk_06;
    u16 delays[7];
    u16 unk_16;
    u16 ids[7];
    s16 args[8];
} Ov003TableEntry;

typedef struct {
    s32 x, y, z;
} Ov003EvVec;

typedef struct {
    Ov003EvVec min;
    Ov003EvVec max;
    Ov003EvVec ofs;
    Ov003TableEntry *entries;
} Ov003Table;

typedef struct {
    u16 id;
    u16 kind;
    u16 unk_04[4];
    s16 unk_0c;
    u8 unk_0e[2];
} Ov003SpawnInfo;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[8];
    u8 unk_16_0 : 1;
} Ov003EvUnit;

typedef struct {
    u8 unk_00[0x16];
    u16 unk_16;
} Ov003EvGroup;

typedef struct {
    u8 unk_00[0x70];
    Ov003EvVec pos;
} Ov003EvPlayer;

typedef struct {
    u8 b0 : 4;
    u8 b4 : 1;
} Ov003EvBits;

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
    void (**vtbl)(void *);
    u8 unk_04[8];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[8];
    s16 unk_18;
    s16 unk_1a;
    s16 unk_1c;
    s16 unk_1e;
    u16 unk_20;
    u8 unk_22[0x16];
    void *unk_38;
    void *unk_3c;
    Ov003Work *work;
    Ov003Part *unk_44;
    Ov003Part48 *unk_48;
    Ov003Part *unk_4c;
    u8 unk_50[0x20];
    Ov003EvVec unk_70;
    u8 unk_7c[0x14];
    u16 unk_90;
    u8 unk_92;
    Ov003EvBits unk_93;
    u8 unk_94[0x38];
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
    u8 unk_16[0x5a];
    Ov003EvVec pos;
    u8 unk_7c[0xaac];
    u8 unk_b28_0 : 2;
    u8 unk_b28_2 : 1;
} Ov003Player;

extern void *data_ov000_021ccd64;
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_ov000_02196060(void *self);
extern void func_ov000_02194758(void *self);
extern void func_ov000_02197d80(void *self);
extern Ov003Spawned *func_ov000_02199ba0(Ov003Part *p);
extern Ov003Spawned *func_ov000_0219be1c(s32 id, void *pos, void *rot, u16 a, u16 b);
extern BOOL func_020621c4(void);
extern void func_ov000_0219bebc(Ov003Spawned *p, s32 v);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
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

BOOL func_ov003_021e12b0(Ov003Event *self) {
    BOOL r = func_ov000_021946f8(self);
    if (self->unk_d0 >= 0) {
        if (!func_ov000_0218f110(&self->unk_d0)) {
            r = FALSE;
        }
    }
    return r;
}

void func_ov003_021e12e4(Ov003Event *self) {
    int i;
    func_ov000_02194758(self);
    self->unk_20c = 0;
    for (i = 0; i < 5; i++) {
        self->unk_20e[i] = 0xffff;
    }
    ((Ov003Work2 *)self->work)->unk_02 = self->table->entries[self->unk_18].unk_06;
}

extern void *data_ov000_021ccd68;
extern Ov003EvUnit *func_ov000_0218e640(void *mgr, u16 id);
extern Ov003EvGroup *func_ov000_0218e4cc(void *mgr, u16 key);
extern BOOL func_01ffc2a4(Ov003EvVec *a, Ov003EvVec *b, Ov003EvVec *min, Ov003EvVec *max);
extern Ov003EvUnit *func_ov000_0218bf1c(void *mgr, Ov003SpawnInfo *info, Ov003EvVec *pos, void *rot, u16 a);
extern void func_ov000_0218bed8(void *mgr, s32 a, void *obj);
extern void VEC_Add(const Ov003EvVec *a, const Ov003EvVec *b, Ov003EvVec *ab);

static inline Ov003EvUnit *Ov003Ev_GetUnit(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline BOOL Ov003Ev_IsBusy(Ov003Global54 *g) {
    return g->unk_90 != g->unk_94;
}

static inline BOOL Ov003Ev_IsIdle(Ov003Global54 *g) {
    if (Ov003Ev_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003Ev_GameIdle(void) {
    Ov003Global54 *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Ev_IsIdle(g);
    }
    return TRUE;
}

static inline void Ov003Ev_CheckNext(Ov003Event *self, Ov003TableEntry *e) {
    if (!self->unk_93.b4 && e->next >= 0) {
        if ((self->table->entries[e->next].unk_16 >> 12) == 5 && self->unk_1e == 0) {
            self->unk_93.b4 = 1;
        }
    }
}

void func_ov003_021e1340(Ov003Event *self) {
    Ov003TableEntry *e;
    u16 cnt;
    s32 i;
    s32 alive;
    if (self->unk_1c != 0) {
        return;
    }
    e = &self->table->entries[self->unk_18];
    self->unk_93.b4 = 0;
    cnt = 0;
    for (i = 0; i < 5; i++) {
        if (self->unk_20e[i] != 0xffff) {
            Ov003EvUnit *u = Ov003Ev_GetUnit(self->unk_20e[i]);
            if (u != NULL) {
                u16 k;
                cnt++;
                k = u->unk_0c & 0xf000;
                if (k == 0x5000) {
                    if (Ov003Ev_GameIdle()) {
                        if (self->unk_1e == 0) {
                            self->unk_93.b4 = 1;
                        }
                    }
                }
            } else {
                self->unk_20e[i] = 0xffff;
            }
        }
    }
    alive = cnt;
    if (e->group != 0) {
        Ov003EvGroup *g = func_ov000_0218e4cc(data_ov000_021ccd68, (u16)(e->group << 12));
        if (g != NULL) {
            alive = g->unk_16;
        }
    }
    switch (self->work->state) {
    case 0: {
        Ov003Player *pl = func_ov000_0219bf90();
        if (!func_01ffc2a4(&pl->pos, &self->unk_70, &self->table->min, &self->table->max)) {
            return;
        }
    }
        self->work->state = 10;
    case 10: {
        Ov003Work *w;
        if (e->max != 0 && alive >= e->max) {
            return;
        }
        if (!Ov003Ev_GameIdle() && self->work->timer != 0) {
            return;
        }
        if (((&e->unk_16)[self->unk_20c] >> 12) == 5 && self->unk_1e == 0) {
            self->unk_93.b4 = 1;
        }
        w = self->work;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer != 0) {
            return;
        }
        {
            Ov003SpawnInfo info;
            Ov003EvVec pos;
            Ov003EvUnit *u;
            s32 j;
            info.id = (&e->unk_16)[self->unk_20c];
            info.kind = info.id & 0xf000;
            for (j = 0; j < 4; j++) {
                info.unk_04[j] = 0;
            }
            info.unk_0c = -1;
            info.unk_04[1] = e->args[self->unk_20c];
            VEC_Add(&self->unk_70, &self->table->ofs, &pos);
            u = func_ov000_0218bf1c(data_ov000_021ccd64, &info, &pos, self->unk_7c, 0xffff);
            if (u == NULL) {
                return;
            }
            u->unk_16_0 = 1;
            for (j = 0; j < 5; j++) {
                if (self->unk_20e[j] == 0xffff) {
                    self->unk_20e[j] = u->unk_0c;
                    break;
                }
            }
            self->unk_20c++;
            if (self->unk_20c >= 8 || (&e->unk_16)[self->unk_20c] == 0xffff) {
                self->work->state++;
                return;
            }
            self->work->timer = (&e->unk_06)[self->unk_20c];
        }
        return;
    }
    case 11: {
        BOOL ok;
        Ov003Ev_CheckNext(self, e);
        ok = FALSE;
        switch (e->mode) {
        case 0:
        case 3:
            ok = TRUE;
            break;
        case 1:
            if (cnt == 0) {
                ok = TRUE;
            }
            break;
        }
        if (!ok) {
            return;
        }
        self->work->timer = e->wait;
        self->work->state++;
        return;
    }
    case 12: {
        Ov003Work *w;
        s32 nx;
        Ov003Ev_CheckNext(self, e);
        w = self->work;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer != 0) {
            return;
        }
        self->unk_20c = 0;
        nx = e->next;
        if (nx == -2) {
            self->work->state = 0x15;
            nx = 0xf;
        } else if (nx == -1) {
            self->work->state = 0x14;
            nx = 0xf;
        } else if (e->mode == 3) {
            self->work->state = 0;
        } else {
            self->work->state = 10;
        }
        self->unk_18 = nx;
        func_ov000_02197dec(self, nx, -1);
        return;
    }
    case 0x14:
        if (cnt != 0) {
            return;
        }
    case 0x15:
        func_ov000_02197dec(self, 0xf, 1);
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        ((Ov003EvBase *)self)->Release();
        return;
    }
}
}
}  // namespace m_021e12b0

// ---- merged from ov003_021e1914.cpp
namespace m_021e1914 {

extern "C" {

typedef struct {
    s32 x, y, z;
} Ov003Vec3;

typedef struct {
    u8 unk_00[0xc];
    u8 unk_0c[0xc];
    Ov003Vec3 unk_18;
    Ov003Vec3 unk_24;
    Ov003Vec3 unk_30;
    s32 speed;
    u16 unk_40;
    u16 unk_42;
    s16 unk_44;
    u8 unk_46[2];
} Ov003SpotDef;

typedef struct {
    u16 state;
    u16 timer;
} Ov003SpotWork;

typedef struct {
    u16 id;
    u16 kind;
    u16 unk_04[4];
    s16 unk_0c;
    u8 unk_0e[2];
} Ov003SpawnInfo;

typedef struct {
    u16 x, y, z;
} Ov003Rot3;

typedef struct {
    u8 unk_00[0x13];
    u8 unk_13;
} Ov003SpotSub;

struct Ov003SpotUnitBase {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void Activate();
};

typedef struct {
    void *vtbl;
    u8 unk_04[8];
    u16 unk_0c;
    u8 unk_0e[8];
    u8 unk_16_0 : 1;
    u8 unk_17[0x29];
    Ov003SpotSub *unk_40;
    u8 unk_44[0x2c];
    Ov003Vec3 pos;
    Ov003Rot3 rot;
} Ov003SpotUnit;

typedef struct {
    Ov003Vec3 pos;
    u16 rx;
    u16 ry;
    u16 rz;
    s32 unk_14;
} Ov003SpotMsg;

struct Ov003SpotBase {
    virtual void v00();
    virtual void v01();
    virtual void Release();
};

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
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
    u8 unk_98[0x14];
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
    Ov003SpotWork *unk_40;
    u8 unk_44[0x14];
    void *unk_58;
    u8 unk_5c[8];
    s32 unk_64;
    u8 unk_68[8];
    Ov003Vec3 unk_70;
    u8 unk_7c[0x8];
    Ov003Vec3 unk_84;
    u8 unk_90[0x3];
    u8 unk_93_0 : 4;
    u8 unk_93_4 : 1;
    u8 unk_94[8];
    Ov003Vec3 vel;
    u8 unk_a8[0x26];
    u16 unk_ce;
} Ov003Prop;

extern Ov003Game *data_ov000_021ccd54;
extern void *data_ov000_021ccd64;
extern const Ov003SpotDef data_ov003_021f6428[];
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_ov000_0219433c(void *self);
extern void func_ov000_02194758(void *self);
extern Ov003Player *func_ov000_0219bf90(void);
extern BOOL func_01ffc2a4(Ov003Vec3 *a, Ov003Vec3 *b, const void *c, const void *d);
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
    const Ov003SpotDef *def;
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

extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern void VEC_Normalize(const Ov003Vec3 *a, Ov003Vec3 *out);
extern Ov003SpotUnit *func_ov000_0218bf1c(void *mgr, Ov003SpawnInfo *info, Ov003Vec3 *pos, Ov003Rot3 *rot, u16 a);
extern Ov003SpotUnit *func_ov000_0218e640(void *mgr, u16 id);
extern BOOL func_01ffc198(Ov003Vec3 *a, Ov003Vec3 *b, s32 r);
extern void *func_02049f44(void *mgr, s32 id, Ov003Vec3 *pos, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov000_0218d398(Ov003SpotUnit *u, u16 id, u8 type, BOOL notify, u32 size, const void *data);
extern void func_ov000_0218d46c(Ov003SpotUnit *u, u16 id, s32 m);
extern void func_0203f920(void *p);
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_0218bed8(void *mgr, s32 a, void *obj);

static inline BOOL Ov003Spot_IsBusy(Ov003Game *g) {
    return g->unk_90 != g->unk_94;
}

static inline BOOL Ov003Spot_IsIdle(Ov003Game *g) {
    if (Ov003Spot_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003Spot_GameIdle(void) {
    Ov003Game *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Spot_IsIdle(g);
    }
    return TRUE;
}

static inline Ov003SpotUnit *Ov003Spot_GetUnit(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline BOOL Ov003Spot_IsLocked(Ov003SpotUnit *u) {
    if (u->unk_40 != NULL) {
        return u->unk_40->unk_13;
    }
    return FALSE;
}

void func_ov003_021e1a68(Ov003Prop *self) {
    const Ov003SpotDef *def;
    Ov003Vec3 v;
    if (!Ov003Spot_GameIdle()) {
        return;
    }
    def = &data_ov003_021f6428[self->unk_1a];
    switch (self->unk_40->state) {
    case 0: {
        Ov003Player *pl = func_ov000_0219bf90();
        if (pl == NULL) {
            return;
        }
        v.x = pl->unk_70.x;
        v.y = pl->unk_70.y;
        v.z = pl->unk_70.z;
        if (func_01ffc2a4(&v, &self->unk_84, def, def->unk_0c)) {
            Ov003SpawnInfo info;
            Ov003Vec3 pos;
            Ov003Rot3 rot;
            Ov003SpotUnit *u;
            s32 i;
            u16 k;
            self->unk_38->unk_c2_0 = 1;
            k = def->unk_42;
            if ((k >> 12) == 5) {
                self->unk_93_4 = 1;
            }
            info.id = k;
            info.kind = k & 0xf000;
            for (i = 0; i < 4; i++) {
                info.unk_04[i] = 0;
            }
            info.unk_0c = -1;
            info.unk_04[1] = def->unk_44;
            pos.x = self->unk_70.x;
            pos.y = self->unk_70.y;
            pos.z = self->unk_70.z;
            rot.x = 0;
            rot.y = def->unk_40;
            rot.z = 0;
            u = func_ov000_0218bf1c(data_ov000_021ccd64, &info, &pos, &rot, 0xffff);
            if (u == NULL) {
                return;
            }
            u->unk_16_0 = 1;
            ((Ov003SpotUnitBase *)u)->Activate();
            self->unk_ce = u->unk_0c;
            VEC_Add(&self->unk_84, &def->unk_24, &v);
            self->vel.x = v.x - self->unk_70.x;
            self->vel.y = v.y - self->unk_70.y;
            self->vel.z = v.z - self->unk_70.z;
            VEC_Normalize(&self->vel, &self->vel);
            {
                s32 spd = def->speed;
                self->vel.x = (s32)(((s64)self->vel.x * spd + 0x800) >> 12);
                self->vel.y = (s32)(((s64)self->vel.y * spd + 0x800) >> 12);
                self->vel.z = (s32)(((s64)self->vel.z * spd + 0x800) >> 12);
            }
            self->unk_40->state++;
        } else {
            self->unk_93_4 = 0;
        }
        return;
    }
    case 1: {
        Ov003SpotUnit *u;
        Ov003SpotMsg msg;
        VEC_Add(&self->unk_84, &def->unk_24, &v);
        if (func_01ffc198(&self->unk_70, &v, def->speed + 0x19a + self->unk_64)) {
            func_02049f44(data_02097e4c, 0x47, &self->unk_70, 0);
            func_ov000_0218996c(6, 0xc);
            self->unk_40->state++;
        }
        VEC_Add(&self->unk_70, &self->vel, &self->unk_70);
        u = Ov003Spot_GetUnit(self->unk_ce);
        if (u == NULL) {
            return;
        }
        if (Ov003Spot_IsLocked(u)) {
            return;
        }
        msg.pos.x = u->pos.x;
        msg.pos.y = u->pos.y;
        msg.pos.z = u->pos.z;
        msg.pos.x = self->unk_70.x;
        msg.pos.y = self->unk_70.y;
        msg.pos.z = self->unk_70.z;
        msg.rx = u->rot.x;
        msg.ry = u->rot.y;
        msg.rz = u->rot.z;
        msg.unk_14 = 0;
        func_ov000_0218d398(u, self->unk_0c, 7, 1, sizeof(msg), &msg);
        return;
    }
    case 2: {
        Ov003SpotWork *w = self->unk_40;
        Ov003SpotUnit *u;
        w->timer++;
        if (w->timer <= 0x3c) {
            return;
        }
        u = Ov003Spot_GetUnit(self->unk_ce);
        if (u != NULL && !Ov003Spot_IsLocked(u)) {
            func_ov000_0218d46c(u, self->unk_0c, 4);
        }
        if (self->unk_58 != NULL) {
            func_0203f920(self->unk_58);
        }
        func_ov000_02190cb0(self->unk_38, "act00", 0x19a, 0);
        func_02049f44(data_02097e4c, 0xe, &self->unk_70, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        return;
    }
    case 3: {
        Ov003SpotWork *w = self->unk_40;
        w->timer++;
        if (w->timer <= 0x3c) {
            return;
        }
        VEC_Add(&self->unk_84, &def->unk_30, &v);
        self->vel.x = v.x - self->unk_70.x;
        self->vel.y = v.y - self->unk_70.y;
        self->vel.z = v.z - self->unk_70.z;
        VEC_Normalize(&self->vel, &self->vel);
        {
            s32 spd = def->speed;
            self->vel.x = (s32)(((s64)self->vel.x * spd + 0x800) >> 12);
            self->vel.y = (s32)(((s64)self->vel.y * spd + 0x800) >> 12);
            self->vel.z = (s32)(((s64)self->vel.z * spd + 0x800) >> 12);
        }
        func_ov000_02190cb0(self->unk_38, "nut00", 0x111, 0);
        func_02049f44(data_02097e4c, 0xf, &self->unk_70, 0);
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        return;
    }
    case 4:
        VEC_Add(&self->unk_84, &def->unk_30, &v);
        if (func_01ffc198(&self->unk_70, &v, def->speed + 0x19a + self->unk_64)) {
            ((Ov003SpotBase *)self)->Release();
            return;
        }
        VEC_Add(&self->unk_70, &self->vel, &self->unk_70);
        break;
    }
}

}
}  // namespace m_021e1914

// ---- merged from ov003_021e2148.c
namespace m_021e2148 {
extern "C" {

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02_0 : 3;
    u16 unk_02_3 : 1;
} Ov003PropDef;

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 5;
    u8 unk_a2_5 : 1;
} Ov003Unit;

typedef struct {
    u8 unk_00[0xe];
    u16 unk_0e;
    u8 unk_10[0x10];
    u16 unk_20;
    u8 unk_22[0x8e];
    Ov003PropDef *unk_b0;
    u8 unk_b4[0x1c];
    s16 unk_d0;
    u8 unk_d2;
    u8 unk_d3;
    u8 unk_d4[0x84];
    char unk_158[0x20];
    char unk_178[0x20];
} Ov003Prop;

extern BOOL func_ov000_021946f8(void *self);
extern void *data_ov000_021ccd64;
extern void func_ov000_0219433c(void *self);
extern char *func_0207011c(u16 id);
extern char *func_02039674(char *p);
extern void STD_CopyString(char *dst, const char *src);
extern void STD_ConcatenateString(char *dst, const char *s);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);

void func_ov003_021e2090(Ov003Prop *self) {
    Ov003PropDef *def;
    Ov003Unit *u;
    func_ov000_0219433c(self);
    def = self->unk_b0;
    if (def->unk_02_3 && def->unk_01 == 1) {
        char buf[0x18];
        char *name = func_0207011c(self->unk_0e);
        STD_CopyString(buf, func_02039674(name));
        STD_ConcatenateString(buf, "e");
        STD_CopyString(self->unk_158, name);
        STD_CopyString(self->unk_178, buf);
        self->unk_d3 |= 8;
        self->unk_d0 = 0;
    }
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_5 = 1;
    }
}

extern BOOL func_ov000_0218f110(s16 *p);

BOOL func_ov003_021e2148(Ov003Prop *self) {
    BOOL r = func_ov000_021946f8(self);
    Ov003PropDef *def = self->unk_b0;
    if (def->unk_02_3 && def->unk_01 == 1 && self->unk_d0 >= 0) {
        if (!func_ov000_0218f110(&self->unk_d0)) {
            r = FALSE;
        }
    }
    return r;
}

typedef struct {
    s32 x, y, z;
} Ov003LtVec;

typedef struct {
    s32 m[9];
    Ov003LtVec t;
} Ov003LtMtx;

typedef struct {
    Ov003LtVec ofs;
    s32 speed;
    const char *name;
    const char *name1;
    const char *name2;
    const char *name3;
    u8 shape;
    u8 sfx;
    s16 fx0;
    s16 fx0arg;
    s16 fx1;
    s16 fx1arg;
    u8 unk_2a[2];
} Ov003LtDef;

typedef struct {
    s16 v[6];
} Ov003LtShape;

typedef struct {
    s32 box[6];
    u16 rot[3];
    u16 kind;
    s32 unk_20;
    Ov003LtVec ofs;
    s32 unk_30;
} Ov003LtHit;

typedef struct {
    u16 state;
    u16 timer;
} Ov003LtWork;

typedef struct {
    u8 unk_00[0x10];
    s16 unk_10;
} Ov003LtInfo;

typedef struct {
    u8 unk_00[0x84];
    u32 *unk_84;
} Ov003LtOwner;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 3;
} Ov003LtBits;

typedef struct {
    u8 unk_00[0x15];
    u8 unk_15;
    u8 unk_16[0xb12];
    u8 unk_b28_0 : 2;
    u8 unk_b28_2 : 1;
} Ov003LtPlayer;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[8];
    s16 unk_18;
    s16 unk_1a;
    s16 unk_1c;
    u8 unk_1e[0x16];
    Ov003LtOwner *unk_34;
    void *model;
    u8 unk_3c[4];
    Ov003LtWork *work;
    u8 unk_44[8];
    void *unk_4c;
    u8 unk_50[8];
    void *unk_58;
    u8 unk_5c[8];
    s32 unk_64;
    u8 unk_68[8];
    Ov003LtVec pos;
    u16 rot_x;
    u16 rot_y;
    u16 rot_z;
    u8 unk_82[2];
    Ov003LtVec prev;
    u8 unk_90[3];
    Ov003LtBits unk_93;
    u8 unk_94[8];
    Ov003LtVec vel;
    u8 unk_a8[8];
    Ov003PropDef *unk_b0;
    u8 unk_b4[0xa0];
    u32 *unk_154;
} Ov003Lt;

extern const s16 FX_SinCosTable_[];
extern const Ov003LtDef data_ov003_021f67c0[];
extern void func_ov000_02194758(void *self);
extern void VEC_Add(const Ov003LtVec *a, const Ov003LtVec *b, Ov003LtVec *out);
extern void MTX_Identity43_(Ov003LtMtx *m);
extern void MTX_RotX43_(Ov003LtMtx *m, s32 s, s32 c);
extern void MTX_RotY43_(Ov003LtMtx *m, s32 s, s32 c);
extern void MTX_RotZ43_(Ov003LtMtx *m, s32 s, s32 c);
extern void MTX_Concat43(Ov003LtMtx *a, Ov003LtMtx *b, Ov003LtMtx *out);
extern void func_0203f9dc(void *obj, Ov003LtMtx *m);
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);

#define OV003LT_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003LT_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

void func_ov003_021e219c(Ov003Lt *self) {
    const Ov003LtDef *def;
    void *obj;
    func_ov000_02194758(self);
    self->prev.x = self->pos.x;
    self->prev.y = self->pos.y;
    self->prev.z = self->pos.z;
    def = &data_ov003_021f67c0[self->unk_1a];
    if (self->unk_18 != 0) {
        VEC_Add(&self->pos, &def->ofs, &self->pos);
    }
    obj = self->unk_58;
    if (obj != NULL) {
        Ov003LtMtx t;
        Ov003LtMtx m;
        u16 rx;
        u16 ry;
        u16 rz;
        BOOL set = FALSE;
        rz = self->rot_z;
        ry = self->rot_y;
        rx = self->rot_x;
        MTX_Identity43_(&m);
        if (rz != 0) {
            MTX_RotZ43_(&m, OV003LT_SIN(rz), OV003LT_COS(rz));
            set = TRUE;
        }
        if (ry != 0) {
            if (set) {
                MTX_RotY43_(&t, OV003LT_SIN(ry), OV003LT_COS(ry));
                MTX_Concat43(&t, &m, &m);
            } else {
                MTX_RotY43_(&m, OV003LT_SIN(ry), OV003LT_COS(ry));
                set = TRUE;
            }
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX43_(&t, OV003LT_SIN(rx), OV003LT_COS(rx));
                MTX_Concat43(&t, &m, &m);
            } else {
                MTX_RotX43_(&m, OV003LT_SIN(rx), OV003LT_COS(rx));
                set = TRUE;
            }
        }
        m.t.x = self->pos.x;
        m.t.y = self->pos.y;
        m.t.z = self->pos.z;
        func_0203f9dc(obj, &m);
    }
    func_ov000_02190cb0(self->model, def->name, 0x1000, 0);
    func_ov000_021915a0(self->model);
}

extern Ov003LtShape data_ov003_021f5c70[];
extern void *data_02097e4c;
extern void VEC_Normalize(const Ov003LtVec *a, Ov003LtVec *out);
extern void func_0203f990(void *obj, u32 a);
extern void func_0203f9b8(void *obj, s32 a);
extern Ov003LtInfo *func_0206fef8(u16 id);
extern void func_ov000_0219b808(u16 id, void *pos, Ov003LtHit *entry, s32 a, s32 b);
extern BOOL func_ov000_02191120(void *model);
extern s32 func_ov003_021f093c(void *p);
extern void func_020627b4(void);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern s32 func_0205b1fc(void);
extern Ov003LtPlayer *func_ov000_0219bf90(void);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void *func_0204a028(void *mgr, s32 id, void *pos, s32 a);
extern BOOL func_01ffc198(Ov003LtVec *a, Ov003LtVec *b, s32 r);

void func_ov003_021e2360(Ov003Lt *self) {
    const Ov003LtDef *def = &data_ov003_021f67c0[self->unk_1a];
    Ov003LtVec v;
    Ov003LtHit hit;
    Ov003LtMtx t;
    Ov003LtMtx m;
    switch (self->work->state) {
    case 0: {
        s32 r = 3;
        if (self->unk_1c != 0) {
            r = func_ov003_021f093c(self->unk_4c);
        }
        if (r == 3 || r == 4) {
            Ov003PropDef *pd;
            s16 n;
            self->unk_93.b1 = 1;
            func_ov000_02190cb0(self->model, def->name1, 0x1000, 0);
            n = (s16)(self->unk_18 + 1) & 1;
            self->unk_18 = n;
            func_020627b4();
            func_ov000_02197dec(self, n, 1);
            if (func_0205b1fc() == 1) {
                Ov003LtPlayer *pl = func_ov000_0219bf90();
                if (pl != NULL && pl->unk_b28_0 == 0) {
                    pl->unk_15 = 3;
                    pl->unk_b28_0 = 0;
                    pl->unk_b28_2 = 1;
                }
            }
            pd = self->unk_b0;
            if (pd->unk_02_3 && pd->unk_01 == 1) {
                Ov003LtInfo *info = func_0206fef8(self->unk_0e);
                func_0203f990(self->unk_58, self->unk_154 != NULL ? *self->unk_154 : 0);
                func_0203f9b8(self->unk_58, info->unk_10);
            }
            self->vel.x = 0;
            self->vel.y = 0;
            self->vel.z = 0;
            self->work->timer = 0;
            self->work->state++;
        }
        break;
    }
    case 1:
        if (!func_ov000_02191120(self->model)) {
            break;
        }
        func_ov000_02190cb0(self->model, def->name2, 0x1000, 0);
        func_ov000_021915a0(self->model);
        v.x = self->prev.x;
        v.y = self->prev.y;
        v.z = self->prev.z;
        if (self->unk_18 != 0) {
            VEC_Add(&v, &def->ofs, &v);
        }
        self->vel.x = v.x - self->pos.x;
        self->vel.y = v.y - self->pos.y;
        self->vel.z = v.z - self->pos.z;
        VEC_Normalize(&self->vel, &self->vel);
        {
            s32 spd = def->speed;
            self->vel.x = (s32)(((s64)self->vel.x * spd + 0x800) >> 12);
            self->vel.y = (s32)(((s64)self->vel.y * spd + 0x800) >> 12);
            self->vel.z = (s32)(((s64)self->vel.z * spd + 0x800) >> 12);
        }
        if (def->sfx != 0) {
            func_ov000_0218996c(5, 0xf);
        }
        if (def->fx0 >= 0) {
            func_0204a028(data_02097e4c, def->fx0, &self->pos, def->fx0arg);
        }
        self->work->state++;
    case 2: {
        void *obj;
        if (self->unk_1a == 14) {
            Ov003LtWork *ww = self->work;
            if (ww->timer != 0) {
                ww->timer--;
            }
            if (ww->timer == 0) {
                self->work->timer = 0x3c;
                func_0204a028(data_02097e4c, 0x27, &self->pos, -8);
            }
        }
        v.x = self->prev.x;
        v.y = self->prev.y;
        v.z = self->prev.z;
        if (self->unk_18 != 0) {
            VEC_Add(&v, &def->ofs, &v);
        }
        if (func_01ffc198(&self->pos, &v, def->speed + 0x19a + self->unk_64)) {
            if (self->unk_1c != 0) {
                self->unk_93.b1 = 0;
            }
            if (def->sfx != 0) {
                func_ov000_0218996c(5, 0xf);
            }
            if (def->fx1 >= 0) {
                func_0204a028(data_02097e4c, def->fx1, &self->pos, def->fx1arg);
            }
            self->vel.x = v.x - self->pos.x;
            self->vel.y = v.y - self->pos.y;
            self->vel.z = v.z - self->pos.z;
            func_ov000_02190cb0(self->model, def->name3, 0x1000, 0);
            self->work->state++;
        }
        VEC_Add(&self->pos, &self->vel, &self->pos);
        obj = self->unk_58;
        if (obj != NULL) {
            u16 rx;
            u16 ry;
            u16 rz;
            BOOL set = FALSE;
            rz = self->rot_z;
            ry = self->rot_y;
            rx = self->rot_x;
            MTX_Identity43_(&m);
            if (rz != 0) {
                MTX_RotZ43_(&m, OV003LT_SIN(rz), OV003LT_COS(rz));
                set = TRUE;
            }
            if (ry != 0) {
                if (set) {
                    MTX_RotY43_(&t, OV003LT_SIN(ry), OV003LT_COS(ry));
                    MTX_Concat43(&t, &m, &m);
                } else {
                    MTX_RotY43_(&m, OV003LT_SIN(ry), OV003LT_COS(ry));
                    set = TRUE;
                }
            }
            if (rx != 0) {
                if (set) {
                    MTX_RotX43_(&t, OV003LT_SIN(rx), OV003LT_COS(rx));
                    MTX_Concat43(&t, &m, &m);
                } else {
                    MTX_RotX43_(&m, OV003LT_SIN(rx), OV003LT_COS(rx));
                    set = TRUE;
                }
            }
            m.t.x = self->pos.x;
            m.t.y = self->pos.y;
            m.t.z = self->pos.z;
            func_0203f9dc(obj, &m);
        }
        break;
    }
    case 3:
        self->vel.x = 0;
        self->vel.y = 0;
        self->vel.z = 0;
        self->work->state++;
    case 4:
        if (func_ov000_02191120(self->model)) {
            Ov003PropDef *pd;
            if (self->unk_1c != 0) {
                self->work->state = 0;
            } else {
                self->work->state = 0xffff;
            }
            pd = self->unk_b0;
            if (pd->unk_02_3 && pd->unk_01 == 1) {
                Ov003LtInfo *info = func_0206fef8(self->unk_0e);
                u32 *p = self->unk_34->unk_84;
                func_0203f990(self->unk_58, p != NULL ? *p : 0);
                func_0203f9b8(self->unk_58, info->unk_10);
            }
        }
        break;
    }
    if (self->work->state != 0 && self->work->state != 0xffff) {
        Ov003LtShape *sh = &data_ov003_021f5c70[def->shape];
        hit.box[0] = sh->v[0] << 4;
        hit.box[1] = sh->v[1] << 4;
        hit.box[2] = sh->v[2] << 4;
        hit.box[3] = sh->v[3] << 4;
        hit.box[4] = sh->v[4] << 4;
        hit.box[5] = sh->v[5] << 4;
        hit.rot[0] = self->rot_x;
        hit.rot[1] = self->rot_y;
        hit.rot[2] = self->rot_z;
        hit.kind = 0x32;
        hit.unk_20 = 0x20040000;
        hit.ofs.x = self->vel.x;
        hit.ofs.y = self->vel.y;
        hit.ofs.z = self->vel.z;
        hit.unk_30 = -1;
        func_ov000_0219b808(self->unk_0c, &self->pos, &hit, 0, 0);
    }
}
}
}  // namespace m_021e2148
#undef OV003LT_SIN
#undef OV003LT_COS

// ---- merged from ov003_021e2afc.c
namespace m_021e2afc {
extern "C" {

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02_0 : 3;
    u16 unk_02_3 : 1;
} Ov003PropDef;

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 5;
    u8 unk_a2_5 : 1;
} Ov003Unit;

typedef struct {
    u8 unk_00[0xe];
    u16 unk_0e;
    u8 unk_10[0x10];
    u16 unk_20;
    u8 unk_22[0x8e];
    Ov003PropDef *unk_b0;
    u8 unk_b4[0x1c];
    s16 unk_d0;
    u8 unk_d2;
    u8 unk_d3;
    u8 unk_d4[0x84];
    char unk_158[0x20];
    char unk_178[0x20];
} Ov003Prop;

extern BOOL func_ov000_021946f8(void *self);
extern void *data_ov000_021ccd64;
extern void func_ov000_0219433c(void *self);
extern char *func_0207011c(u16 id);
extern char *func_02039674(char *p);
extern void STD_CopyString(char *dst, const char *src);
extern void STD_ConcatenateString(char *dst, const char *s);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);

void func_ov003_021e2a44(Ov003Prop *self) {
    Ov003PropDef *def;
    Ov003Unit *u;
    func_ov000_0219433c(self);
    def = self->unk_b0;
    if (def->unk_02_3 && def->unk_01 == 1) {
        char buf[0x18];
        char *name = func_0207011c(self->unk_0e);
        STD_CopyString(buf, func_02039674(name));
        STD_ConcatenateString(buf, "e");
        STD_CopyString(self->unk_158, name);
        STD_CopyString(self->unk_178, buf);
        self->unk_d3 |= 8;
        self->unk_d0 = 0;
    }
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_5 = 1;
    }
}

extern BOOL func_ov000_0218f110(s16 *p);

BOOL func_ov003_021e2afc(Ov003Prop *self) {
    BOOL r = func_ov000_021946f8(self);
    Ov003PropDef *def = self->unk_b0;
    if (def->unk_02_3 && def->unk_01 == 1 && self->unk_d0 >= 0) {
        if (!func_ov000_0218f110(&self->unk_d0)) {
            r = FALSE;
        }
    }
    return r;
}
}
}  // namespace m_021e2afc

// ---- merged from ov003_021e2b50.c
namespace m_021e2b50 {
extern "C" {

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02_0 : 3;
    u16 unk_02_3 : 1;
} Ov003PropDef;

typedef struct {
    s32 x, y, z;
} Ov003LtVec;

typedef struct {
    s32 m[9];
    Ov003LtVec t;
} Ov003LtMtx;

typedef struct {
    Ov003LtVec ofs;
    s32 speed;
    const char *name;
    const char *name1;
    const char *name2;
    const char *name3;
    u8 shape;
    u8 sfx;
    s16 fx0;
    s16 fx0arg;
    s16 fx1;
    s16 fx1arg;
    u8 unk_2a[2];
} Ov003LtDef;

typedef struct {
    s16 v[6];
} Ov003LtShape;

typedef struct {
    s32 box[6];
    u16 rot[3];
    u16 kind;
    s32 unk_20;
    Ov003LtVec ofs;
    s32 unk_30;
} Ov003LtHit;

typedef struct {
    u16 state;
    u16 timer;
} Ov003LtWork;

typedef struct {
    u8 unk_00[0x84];
    u32 *unk_84;
} Ov003LtOwner;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[6];
    u8 unk_16;
    u8 unk_17[0x59];
    Ov003LtVec pos;
} Ov003LtUnit;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x74e];
    Ov003LtVec pos;
} Ov003LtPlayer;

typedef struct {
    u8 unk_00[0x1f0];
    u16 unk_1f0;
} Ov003LtField;

typedef struct {
    u8 unk_00[0x10];
    s16 unk_10;
} Ov003LtInfo;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[8];
    s16 unk_18;
    s16 unk_1a;
    u8 unk_1c[0x18];
    Ov003LtOwner *unk_34;
    void *model;
    u8 unk_3c[4];
    Ov003LtWork *work;
    u8 unk_44[0x14];
    void *unk_58;
    u8 unk_5c[8];
    s32 unk_64;
    u8 unk_68[8];
    Ov003LtVec pos;
    u16 rot[3];
    u8 unk_82[2];
    Ov003LtVec prev;
    u8 unk_90[0xc];
    Ov003LtVec vel;
    u8 unk_a8[8];
    Ov003PropDef *unk_b0;
    u8 unk_b4[0xa0];
    u32 *unk_154;
} Ov003Lt;

extern const s16 FX_SinCosTable_[];
extern const Ov003LtDef data_ov003_021f67c0[];
extern Ov003LtShape data_ov003_021f5c70[];
extern void func_ov000_02194758(void *self);
extern void VEC_Add(const Ov003LtVec *a, const Ov003LtVec *b, Ov003LtVec *out);
extern void VEC_Normalize(const Ov003LtVec *a, Ov003LtVec *out);
extern void MTX_Identity43_(Ov003LtMtx *m);
extern void MTX_RotX43_(Ov003LtMtx *m, s32 s, s32 c);
extern void MTX_RotY43_(Ov003LtMtx *m, s32 s, s32 c);
extern void MTX_RotZ43_(Ov003LtMtx *m, s32 s, s32 c);
extern void MTX_Concat43(Ov003LtMtx *a, Ov003LtMtx *b, Ov003LtMtx *out);
extern void func_0203f9dc(void *obj, Ov003LtMtx *m);
extern void func_0203f8d8(void *obj);
extern void func_0203f990(void *obj, u32 a);
extern void func_0203f9b8(void *obj, s32 a);
extern Ov003LtInfo *func_0206fef8(u16 id);
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern s32 func_ov000_0219b808(u16 id, void *pos, Ov003LtHit *entry, u16 *ids, s32 max);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern BOOL func_ov000_02191120(void *model);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void *func_0204a028(void *mgr, s32 id, void *pos, s32 a);
extern BOOL func_01ffc198(Ov003LtVec *a, Ov003LtVec *b, s32 r);
extern void *data_02097e4c;
extern Ov003LtField *data_ov000_021ccd6c;
extern void *data_ov000_021ccd68;
extern Ov003LtUnit *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_021b6b4c(Ov003LtField *f, u16 id, Ov003LtVec *v);
extern Ov003LtPlayer *func_ov000_0219bf90(void);

#define OV003LT_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003LT_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

void func_ov003_021e2b50(Ov003Lt *self) {
    const Ov003LtDef *def;
    u16 rx;
    u16 ry;
    u16 rz;
    BOOL set;
    void *obj;
    func_ov000_02194758(self);
    self->prev.x = self->pos.x;
    self->prev.y = self->pos.y;
    self->prev.z = self->pos.z;
    def = &data_ov003_021f67c0[self->unk_1a];
    func_ov000_02190cb0(self->model, def->name, 0x1000, 0);
    func_ov000_021915a0(self->model);
    if (self->unk_18 != 0) {
        Ov003PropDef *pd;
        Ov003LtShape *sh;
        Ov003LtHit hit;
        if (self->unk_18 == 1) {
            VEC_Add(&self->pos, &def->ofs, &self->pos);
        } else {
            self->pos.x = self->pos.x - def->ofs.x;
            self->pos.y = self->pos.y - def->ofs.y;
            self->pos.z = self->pos.z - def->ofs.z;
        }
        func_ov000_02190cb0(self->model, def->name2, 0x1000, 0);
        func_ov000_021915a0(self->model);
        self->vel.x = self->prev.x - self->pos.x;
        self->vel.y = self->prev.y - self->pos.y;
        self->vel.z = self->prev.z - self->pos.z;
        VEC_Normalize(&self->vel, &self->vel);
        {
            s32 spd = def->speed;
            self->vel.x = (s32)(((s64)self->vel.x * spd + 0x800) >> 12);
            self->vel.y = (s32)(((s64)self->vel.y * spd + 0x800) >> 12);
            self->vel.z = (s32)(((s64)self->vel.z * spd + 0x800) >> 12);
        }
        pd = self->unk_b0;
        if (pd->unk_02_3 && pd->unk_01 == 1) {
            Ov003LtInfo *info = func_0206fef8(self->unk_0e);
            u32 v = 0;
            if (self->unk_154 != NULL) {
                v = *self->unk_154;
            }
            func_0203f990(self->unk_58, v);
            func_0203f9b8(self->unk_58, info->unk_10);
        }
        sh = &data_ov003_021f5c70[def->shape];
        hit.box[0] = sh->v[0] << 4;
        hit.box[1] = sh->v[1] << 4;
        hit.box[2] = sh->v[2] << 4;
        hit.box[3] = sh->v[3] << 4;
        hit.box[4] = sh->v[4] << 4;
        hit.box[5] = sh->v[5] << 4;
        hit.rot[0] = self->rot[0];
        hit.rot[1] = self->rot[1];
        hit.rot[2] = self->rot[2];
        hit.kind = 0x12;
        hit.unk_20 = 0;
        hit.ofs.x = self->pos.x - self->prev.x;
        hit.ofs.y = self->pos.y - self->prev.y;
        hit.ofs.z = self->pos.z - self->prev.z;
        hit.unk_30 = -1;
        func_ov000_0219b808(self->unk_0c, &self->prev, &hit, NULL, 0);
        func_ov000_02198360(self->work, 1, 0);
        self->work->state = 10;
    }
    obj = self->unk_58;
    if (obj != NULL) {
        Ov003LtMtx t;
        Ov003LtMtx m;
        set = FALSE;
        rz = self->rot[2];
        ry = self->rot[1];
        rx = self->rot[0];
        MTX_Identity43_(&m);
        if (rz != 0) {
            MTX_RotZ43_(&m, OV003LT_SIN(rz), OV003LT_COS(rz));
            set = TRUE;
        }
        if (ry != 0) {
            if (set) {
                MTX_RotY43_(&t, OV003LT_SIN(ry), OV003LT_COS(ry));
                MTX_Concat43(&t, &m, &m);
            } else {
                MTX_RotY43_(&m, OV003LT_SIN(ry), OV003LT_COS(ry));
                set = TRUE;
            }
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX43_(&t, OV003LT_SIN(rx), OV003LT_COS(rx));
                MTX_Concat43(&t, &m, &m);
            } else {
                MTX_RotX43_(&m, OV003LT_SIN(rx), OV003LT_COS(rx));
                set = TRUE;
            }
        }
        m.t.x = self->pos.x;
        m.t.y = self->pos.y;
        m.t.z = self->pos.z;
        func_0203f9dc(obj, &m);
        func_0203f8d8(self->unk_58);
    }
}

#define OV003LT_MTX(obj, MM, TT)                                                   \
    {                                                                            \
        u16 rx;                                                                  \
        u16 ry;                                                                  \
        u16 rz;                                                                  \
        BOOL set = FALSE;                                                        \
        rz = self->rot[2];                                                       \
        ry = self->rot[1];                                                       \
        rx = self->rot[0];                                                       \
        MTX_Identity43_(&MM);                                                     \
        if (rz != 0) {                                                           \
            MTX_RotZ43_(&MM, OV003LT_SIN(rz), OV003LT_COS(rz));                   \
            set = TRUE;                                                          \
        }                                                                        \
        if (ry != 0) {                                                           \
            if (set) {                                                           \
                MTX_RotY43_(&TT, OV003LT_SIN(ry), OV003LT_COS(ry));               \
                MTX_Concat43(&TT, &MM, &MM);                                        \
            } else {                                                             \
                MTX_RotY43_(&MM, OV003LT_SIN(ry), OV003LT_COS(ry));               \
                set = TRUE;                                                      \
            }                                                                    \
        }                                                                        \
        if (rx != 0) {                                                           \
            if (set) {                                                           \
                MTX_RotX43_(&TT, OV003LT_SIN(rx), OV003LT_COS(rx));               \
                MTX_Concat43(&TT, &MM, &MM);                                        \
            } else {                                                             \
                MTX_RotX43_(&MM, OV003LT_SIN(rx), OV003LT_COS(rx));               \
                set = TRUE;                                                      \
            }                                                                    \
        }                                                                        \
        MM.t.x = self->pos.x;                                                     \
        MM.t.y = self->pos.y;                                                     \
        MM.t.z = self->pos.z;                                                     \
        func_0203f9dc(obj, &MM);                                                  \
    }

#define OV003LT_HIT(hit)                                                         \
    {                                                                            \
        const Ov003LtShape *sh = &data_ov003_021f5c70[def->shape];               \
        hit.box[0] = sh->v[0] << 4;                                              \
        hit.box[1] = sh->v[1] << 4;                                              \
        hit.box[2] = sh->v[2] << 4;                                              \
        hit.box[3] = sh->v[3] << 4;                                              \
        hit.box[4] = sh->v[4] << 4;                                              \
        hit.box[5] = sh->v[5] << 4;                                              \
        hit.rot[0] = self->rot[0];                                               \
        hit.rot[1] = self->rot[1];                                               \
        hit.rot[2] = self->rot[2];                                               \
        hit.kind = 0x12;                                                         \
        hit.unk_20 = 0x20040000;                                                 \
        hit.ofs.x = self->vel.x;                                                 \
        hit.ofs.y = self->vel.y;                                                 \
        hit.ofs.z = self->vel.z;                                                 \
        hit.unk_30 = -1;                                                         \
    }

static inline Ov003LtUnit *Ov003Lt_GetUnit(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov003_021e2f54(Ov003Lt *self) {
    const Ov003LtDef *def = &data_ov003_021f67c0[self->unk_1a];
    Ov003LtVec v;
    Ov003LtHit hitB;
    u16 ids[0x20];
    Ov003LtVec d;
    Ov003LtHit hitA;
    Ov003LtMtx tB;
    Ov003LtMtx mB;
    Ov003LtMtx tA;
    Ov003LtMtx mA;
    switch (self->work->state) {
    case 0: {
        Ov003PropDef *pd;
        if (self->unk_18 == 0) {
            return;
        }
        func_ov000_02190cb0(self->model, def->name1, 0x1000, 0);
        func_ov000_02197dec(self, self->unk_18, -1);
        pd = self->unk_b0;
        if (pd->unk_02_3 && pd->unk_01 == 1) {
            Ov003LtInfo *info = func_0206fef8(self->unk_0e);
            u32 x = 0;
            if (self->unk_154 != NULL) {
                x = *self->unk_154;
            }
            func_0203f990(self->unk_58, x);
            func_0203f9b8(self->unk_58, info->unk_10);
        }
        self->work->timer = 0;
        self->work->state++;
        return;
    }
    case 1:
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        func_ov000_02190cb0(self->model, def->name2, 0x1000, 0);
        func_ov000_021915a0(self->model);
        if (self->unk_18 == 1) {
            VEC_Add(&self->pos, &def->ofs, &v);
        } else {
            v.x = self->pos.x - def->ofs.x;
            v.y = self->pos.y - def->ofs.y;
            v.z = self->pos.z - def->ofs.z;
        }
        self->vel.x = v.x - self->pos.x;
        self->vel.y = v.y - self->pos.y;
        self->vel.z = v.z - self->pos.z;
        VEC_Normalize(&self->vel, &self->vel);
        {
            s32 spd = def->speed;
            self->vel.x = (s32)(((s64)self->vel.x * spd + 0x800) >> 12);
            self->vel.y = (s32)(((s64)self->vel.y * spd + 0x800) >> 12);
            self->vel.z = (s32)(((s64)self->vel.z * spd + 0x800) >> 12);
        }
        if (def->sfx != 0) {
            func_ov000_0218996c(5, 0xf);
        }
        if (def->fx0 >= 0) {
            func_0204a028(data_02097e4c, def->fx0, &self->pos, def->fx0arg);
        }
        self->work->state++;
        return;
    case 2: {
        void *obj;
        Ov003LtPlayer *pl;
        u16 plId;
        s32 i;
        s32 n;
        VEC_Add(&self->pos, &self->vel, &self->pos);
        obj = self->unk_58;
        if (obj != NULL) {
            OV003LT_MTX(obj, mB, tB);
        }
        OV003LT_HIT(hitB);
        n = func_ov000_0219b808(self->unk_0c, &self->pos, &hitB, ids, 0x20);
        if (n == 0) {
            return;
        }
        data_ov000_021ccd6c->unk_1f0 = self->unk_0e;
        pl = func_ov000_0219bf90();
        if (n > sizeof(ids) / sizeof(ids[0])) {
            n = 0x20;
        }
        plId = pl->unk_0c;
        for (i = 0; i < n; i++) {
            Ov003LtUnit *u = Ov003Lt_GetUnit(ids[i]);
            if (u != NULL && u->unk_0e != 0x4cc1) {
                u16 id = u->unk_0c;
                if (id == plId) {
                    d.x = pl->pos.x;
                    d.y = pl->pos.y;
                    d.z = pl->pos.z;
                } else {
                    d.x = u->pos.x;
                    d.y = u->pos.y;
                    d.z = u->pos.z;
                    u->unk_16 |= 2;
                }
                d.x -= self->pos.x;
                d.y -= self->pos.y;
                d.z -= self->pos.z;
                func_ov000_021b6b4c(data_ov000_021ccd6c, id, &d);
            }
        }
        return;
    }
    case 10: {
        void *obj;
        if (func_01ffc198(&self->pos, &self->prev, def->speed + 0x19a + self->unk_64)) {
            if (def->sfx != 0) {
                func_ov000_0218996c(5, 0xf);
            }
            if (def->fx1 >= 0) {
                func_0204a028(data_02097e4c, def->fx1, &self->pos, def->fx1arg);
            }
            self->vel.x = self->prev.x - self->pos.x;
            self->vel.y = self->prev.y - self->pos.y;
            self->vel.z = self->prev.z - self->pos.z;
            func_ov000_02190cb0(self->model, def->name3, 0x1000, 0);
            self->work->state++;
        }
        VEC_Add(&self->pos, &self->vel, &self->pos);
        obj = self->unk_58;
        if (obj != NULL) {
            OV003LT_MTX(obj, mA, tA);
        }
        OV003LT_HIT(hitA);
        func_ov000_0219b808(self->unk_0c, &self->pos, &hitA, NULL, 0);
        return;
    }
    case 11:
        if (func_ov000_02191120(self->model)) {
            Ov003PropDef *pd;
            self->work->state = 0;
            self->unk_18 = 0;
            func_ov000_02197dec(self, 0, -1);
            pd = self->unk_b0;
            if (pd->unk_02_3 && pd->unk_01 == 1) {
                Ov003LtInfo *info = func_0206fef8(self->unk_0e);
                u32 *p = self->unk_34->unk_84;
                u32 x = 0;
                if (p != NULL) {
                    x = *p;
                }
                func_0203f990(self->unk_58, x);
                func_0203f9b8(self->unk_58, info->unk_10);
            }
        }
        return;
    }
}

}
}  // namespace m_021e2b50
#undef OV003LT_SIN
#undef OV003LT_COS
#undef OV003LT_MTX
#undef OV003LT_HIT

// ---- merged from ov003_021e3a90.c
namespace m_021e3a90 {
extern "C" {

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
extern void func_ov000_02194758(void *self);
extern void *data_ov000_021ccd64;
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_0218bed8(void *mgr, s32 a, void *self);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_021911c8(void *model, s32 v);
extern u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
extern void func_ov000_021975b4(void *self);
extern BOOL func_ov000_02190cb0(void *model, const void *name, s32 a, s32 b);
extern void *func_02049f44(void *mgr, s32 id, void *pos, s32 a);
extern void *func_0204a028(void *mgr, s32 id, void *pos, s32 a);

void func_ov003_021e3890(Ov003Prop *self) {
    s16 a;
    s16 b;
    func_ov000_02194758(self);
    a = self->unk_18;
    b = self->unk_1a;
    if (a != 0 && a < b) {
        switch (self->unk_b0->unk_01) {
        case 1:
            func_ov000_02190cb0(self->model, "op01", 0x1000, 0);
            break;
        case 2:
            func_ov000_02190cb0(self->model, "op01", 0x1000, 0);
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
                func_ov000_02190cb0(self->model, "op02", 0x1000, 0);
            }
            self->unk_cc_0 = 0;
        } else if (self->model != NULL) {
            func_ov000_02190cb0(self->model, "op01", 0x1000, 0);
        }
        break;
    case 2:
        if (n >= lim) {
            Ov003Prop44 *p;
            if (self->model != NULL) {
                func_ov000_02190cb0(self->model, "op02", 0x1000, 0);
            }
            self->unk_4c->unk_02 = 5;
            p = self->unk_44;
            if (p != NULL) {
                p->unk_22_0 = 0;
                p->unk_22_1 = 0;
            }
        } else if (self->model != NULL) {
            func_ov000_02190cb0(self->model, "op01", 0x1000, 0);
        }
        break;
    case 4:
        if (self->model != NULL) {
            func_ov000_02190cb0(self->model, "act00", 0x1000, 0);
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
            func_ov000_02190cb0(self->model, "fly00", 0x1000, 0);
        } else {
            func_ov000_02190cb0(self->model, "nut00", 0x1000, 0);
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

}
}  // namespace m_021e3a90

// ---- merged from ov003_021e3d34.cpp
namespace m_021e3d34 {

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
    u8 unk_00[0xc];
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    u8 unk_18[0xa];
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
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u8 unk_06[4];
    u16 unk_0a;
    u16 unk_0c;
    u16 unk_0e;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
} Ov003Prop50;

typedef struct {
    u8 unk_00[0xb24];
    u32 unk_b24_0 : 12;
    u32 unk_b24_12 : 2;
    u8 unk_b28[6];
    u8 unk_b2e;
} Ov003Plr;

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
    Ov003Prop50 *unk_50;
    u8 unk_54[0x1c];
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

class Ov003PropV {
public:
    virtual void v00();
    virtual void v04();
    virtual void Destroy();
};

extern "C" {

extern void *data_02097e4c;
extern void func_ov000_02194758(void *self);
extern void *data_ov000_021ccd64;
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_0218bed8(void *mgr, s32 a, void *self);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_021911c8(void *model, s32 v);
extern u16 func_01ffc128(u16 target, u16 cur, s32 step, s32 a, s32 b);
extern void func_ov000_021975b4(void *self);
extern BOOL func_ov000_02190cb0(void *model, const void *name, s32 a, s32 b);
extern void *func_02049f44(void *mgr, s32 id, void *pos, s32 a);
extern void *func_0204a028(void *mgr, s32 id, void *pos, s32 a);

extern void *data_ov000_021ccd68;
extern void *func_ov000_02191318(void *m, s32 a);
extern void func_ov000_02191690(void *model);
extern BOOL func_ov000_02191120(void *model);
extern void *func_ov000_02190a30(void *m, s32 a);
extern BOOL func_ov000_0218fd84(void *a);
extern void func_ov000_0218e8ec(void *mgr, s32 a, s32 b);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void *func_0203dd9c(u32 size);
extern Ov003Plr *func_ov000_0219bf90(void);

void func_ov003_021e3c80(Ov003Prop *self) {
    s16 n;
    func_ov000_021975b4(self);
    if (self->unk_18 >= self->unk_1a) {
        return;
    }
    n = self->unk_18 + 1;
    self->unk_18 = n;
    if (self->unk_1a <= n) {
        Ov003Prop44 *p;
        func_ov000_02190cb0(self->model, "fly00", 0x2ab, 0);
        func_ov000_021915a0(self->model);
        p = self->unk_44;
        p->unk_22_0 = 0;
        p->unk_22_1 = 0;
        self->unk_98 = self->unk_7e + 0x8000;
        self->unk_1e = 1;
        func_ov000_02197dec(self, self->unk_18, -1);
    } else {
        func_ov000_02190cb0(self->model, "joy00", 0x1000, 0);
    }
}

void func_ov003_021e3d34(Ov003Prop *self) {
    if (self->unk_1c == 0) {
        Ov003Prop44 *p = self->unk_44;
        p->unk_22_0 = 0;
        p->unk_22_1 = 0;
        func_ov000_02198360(self->work, 1, 0);
        self->unk_98 = self->unk_7e + 0x8000;
        return;
    }
    switch (self->work->state) {
    case 0: {
        Ov003Prop44 *p = self->unk_44;
        p->unk_22_0 = 0;
        p->unk_22_1 = 0;
        self->unk_a0 = 0;
        self->work->state++;
        break;
    }
    case 1: {
        Ov003PropWk *w;
        s32 v = self->unk_a0;
        v += (0x466 - v) >> 7;
        self->unk_a0 = v;
        self->pos[1] += v;
        self->unk_7c = func_01ffc128(0, self->unk_7c, 0x400, 1, 0x8000);
        w = self->work;
        w->timer++;
        if (w->timer > 0xb4) {
            func_ov000_02197dec(self, 0xf, -1);
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            ((Ov003PropV *)self)->Destroy();
        }
        break;
    }
    }
}

void func_ov003_021e3e78(Ov003Prop *self) {
    s16 n;
    s16 lim;
    Ov003Prop50 *q;
    func_ov000_02194758(self);
    n = self->unk_18;
    lim = self->unk_1a;
    if (n > lim) {
        n = lim;
    }
    func_ov000_02190cb0(self->model, "nut00", 0x1000, 0);
    if (n >= lim) {
        Ov003Prop44 *p;
        func_ov000_02198360(self->work, 1, 0);
        self->work->state = 0xffff;
        func_ov000_02191318(self->model, -1);
        p = self->unk_44;
        p->unk_22_0 = 0;
        p->unk_22_1 = 0;
        self->unk_cc_0 = 0;
    } else {
        func_ov000_02191690(self->model);
    }
    self->unk_44->unk_22_2 = 2;
    q = (Ov003Prop50 *)func_0203dd9c(sizeof(Ov003Prop50));
    if (q != NULL) {
        q->unk_00 = 100;
        q->unk_02 = 100;
        q->unk_04 = 0xffff;
        q->unk_0a = 0;
        q->unk_0e = 0;
        q->unk_0c = 0;
        q->unk_10 = 0;
        q->unk_14 = 0;
        q->unk_18 = 0;
    }
    self->unk_50 = q;
}

void func_ov003_021e3f78(Ov003Prop *self) {
    switch (self->work->state) {
    case 0: {
        s16 n;
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        n = self->unk_18;
        if (n >= self->unk_1a) {
            Ov003Plr *p = func_ov000_0219bf90();
            Ov003Prop44 *s;
            if (p == NULL || p->unk_b24_12 != 0) {
                self->unk_18 = n - 1;
                return;
            }
            if (p->unk_b2e < 1) {
                p->unk_b2e = 1;
            }
            func_ov000_02197dec(self, self->unk_18, 5);
            func_ov000_02190cb0(self->model, "nut00", 0x1000, 0);
            s = self->unk_44;
            s->unk_22_0 = 0;
            s->unk_22_1 = 0;
            func_ov000_0218e8ec(data_ov000_021ccd68, 0x540b, 0x15);
            self->work->state++;
        } else {
            func_ov000_02190cb0(self->model, "nut00", 0x1000, 0);
            func_ov000_02191690(self->model);
            self->work->state = 0xff;
        }
        break;
    }
    case 1: {
        void *a = func_ov000_02190a30(self->model, 0);
        if (a == NULL) {
            return;
        }
        if (!func_ov000_0218fd84(a)) {
            return;
        }
        self->unk_cc_0 = 0;
        self->work->state = 0xff;
        break;
    }
    }
}

void func_ov003_021e40d4(Ov003Prop *self) {
    Ov003Plr *p = func_ov000_0219bf90();
    u16 x;
    s16 n;
    s16 lim;
    if (p == NULL) {
        return;
    }
    if (p->unk_b24_12 != 0) {
        return;
    }
    x = self->unk_50->unk_04;
    if (x == 0xffff || (x >> 12) != 5) {
        func_ov000_02198360(self->work, 1, 0);
        return;
    }
    n = self->unk_18 + 1;
    lim = self->unk_1a;
    if (n >= lim) {
        n = lim;
        if (p->unk_b2e < 0x78) {
            p->unk_b2e = 0x78;
        }
    }
    self->unk_18 = n;
    func_ov000_02190cb0(self->model, "act00", 0x1000, 0);
    func_02049f44(data_02097e4c, 0x6a, self->pos, 0);
    func_ov000_0218996c(8, 0xf);
    func_ov000_02198360(self->work, 1, 0);
}

void func_ov003_021e41bc(Ov003Prop *self) {
    Ov003Prop44 *p;
    func_ov000_02194758(self);
    p = self->unk_44;
    p->unk_0c = 0;
    p->unk_10 = -0x1800;
    p->unk_14 = 0x3000;
}

typedef struct {
    u8 unk_00[0x16];
    u8 unk_16_0 : 1;
} Ov003Spawned;

extern Ov003Spawned *func_ov000_0218bf1c(void *mgr, Ov003SpawnInfo *info, Ov003Vec3 *pos, void *rot, u16 a);
extern void *func_ov000_0219b71c(Ov003Vec3 *pos, Ov003Vec3 *v, s32 a, s32 b, s32 c, s32 d);
extern s32 func_02040498(s32 max);

void func_ov003_021e41e8(Ov003Obj *self) {
    switch (self->work->state) {
    case 0: {
        Ov003Sub44 *s;
        func_ov000_02190cb0(self->model, "dmg00", 0x333, 0);
        func_ov000_021911c8(self->model, 0x800);
        func_02049f44(data_02097e4c, 0x41, &self->pos, 0);
        s16 n;
        s16 lim;
        lim = self->unk_1a;
        n = self->unk_18 + 1;
        self->unk_18 = n;
        if (n >= lim) {
            self->unk_cc_0 = 0;
            s = self->unk_44;
            s->unk_22_0 = 0;
            s->unk_22_1 = 0;
            self->work->state = 10;
            return;
        }
        self->work->timer = 0;
        self->work->state++;
        return;
    }
    case 1: {
        Ov003Work *w = self->work;
        w->timer++;
        if (w->timer <= 10) {
            return;
        }
        func_ov000_02198360(self->work, 1, 0);
        func_ov000_02190cb0(self->model, "nut00", 0x111, 0);
        return;
    }
    case 10:
        if (func_ov000_02191120(self->model)) {
            if (self->kind == 0) {
                Ov003SpawnInfo info;
                Ov003Vec3 p;
                Ov003Spawned *o;
                s32 id;
                s32 i;
                id = 0x5810;
                if (self->unk_0e == 0x4056) {
                    id++;
                }
                info.id = id;
                info.kind = id & 0xf000;
                for (i = 0; i < 4; i++) {
                    info.unk_04[i] = 0;
                }
                info.unk_0c = -1;
                p.x = self->unk_44->pos.x;
                p.y = self->unk_44->pos.y;
                p.z = self->unk_44->pos.z;
                o = func_ov000_0218bf1c(data_ov000_021ccd64, &info, &p, self->unk_7c, 0xffff);
                if (o != NULL) {
                    o->unk_16_0 = 1;
                }
            }
            self->unk_64 = 0x1000;
            func_ov000_02198360(self->work, 0x15, 0);
            return;
        }
        if ((self->work->timer & 0xf) == 0) {
            Ov003Vec3 sc;
            Ov003Vec3 p;
            sc.x = 0x3000;
            sc.y = 0x2000;
            sc.z = 0x3000;
            p.x = self->unk_44->pos.x;
            p.y = self->unk_44->pos.y;
            p.z = self->unk_44->pos.z;
            func_ov000_0219b71c(&p, &sc, 0x99a, 0x1000, 0x38b, 0x32);
            func_ov000_0218996c(5, 10);
            func_02049f44(data_02097e4c, 0x3b, &self->pos, 0);
            if (func_02040498(1)) {
                func_02049f44(data_02097e4c, 0x3c, &self->pos, 0);
            } else {
                func_02049f44(data_02097e4c, 0x3d, &self->pos, 0);
            }
        }
        self->work->timer++;
        return;
    }
}

}
}  // namespace m_021e3d34

// ---- merged from ov003_021e44dc.cpp
namespace m_021e44dc {

typedef struct {
    u8 unk_00[0x16];
    u8 unk_16_0 : 1;
} Ov003Spawned;

typedef struct {
    s32 m[9];
    s32 tx, ty, tz;
} Ov003BigMtx;

typedef struct {
    u8 unk_00[0x98];
} Ov003BigRObj;

typedef struct {
    u8 unk_00[0x84];
    void **unk_84;
} Ov003BigRes;

typedef struct {
    u16 unk_00;
    u16 ang;
    Ov003Vec3 v;
} Ov003BigEnt;

typedef struct {
    void *unk_00;
    void *mdl;
    u8 unk_08[0xac];
    u16 unk_b4;
    u8 unk_b6[0xc];
    u16 unk_c2_0 : 7;
    u16 unk_c2_7 : 1;
} Ov003BigMdl;

typedef struct {
    void *vtbl;
    u8 unk_04[0x8];
    u16 unk_0c;
    u8 unk_0e[0xa];
    s16 unk_18;
    s16 unk_1a;
    u8 unk_1c[0x18];
    Ov003BigRes *unk_34;
    u8 unk_38[0x38];
    Ov003Vec3 pos;
    u16 rot[3];
    u8 unk_82[0xe];
    u8 unk_90[3];
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
    u8 unk_94[0x38];
    u16 unk_cc_0 : 1;
    u8 unk_ce[2];
    s16 res;
    u8 unk_d2[0x136];
    s16 res2;
    u8 unk_20a;
    u8 unk_20b;
    u8 unk_20c[0x84];
    u8 unk_290[0x20];
    u8 unk_2b0[0x90];
    Ov003BigMdl sub;
    u8 unk_404[0x24];
    Ov003Vec3 unk_428[4];
    s32 unk_458[4];
    u8 unk_468[4];
    u8 unk_46c[0x260];
    Ov003BigRObj obj1[4];
    Ov003BigRObj obj2[3];
    Ov003Vec3 unk_af4[3];
    u8 unk_b18;
} Ov003Big;

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021911c8(void *model, s32 a);
extern BOOL func_ov000_02191120(void *model);
extern void *func_02049f44(void *mgr, s32 id, Ov003Vec3 *pos, s32 a);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern Ov003Spawned *func_ov000_0218bf1c(void *mgr, Ov003SpawnInfo *info, Ov003Vec3 *pos, void *rot, u16 a);
extern void *func_ov000_0219b71c(Ov003Vec3 *pos, Ov003Vec3 *v, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_0218996c(s32 a, s32 b);
extern s32 func_02040498(s32 max);
extern void func_ov000_0219433c(void *self);
extern void func_ov000_0218f074(s16 *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern void STD_CopyString(void *dst, const void *src);
extern BOOL func_ov000_021946f8(void *self);
extern BOOL func_ov000_0218f110(s16 *res);

void func_ov003_021e44dc(Ov003Big *self) {
    func_ov000_0219433c(self);
    const char *name = "gm/g1plt01";
    const char *ext;
    func_ov000_0218f074(&self->res, (char *)name, 1, 0, 0, 1);
    ext = "g1plt01e";
    self->res = 0;
    STD_CopyString(self->unk_290, name);
    STD_CopyString(self->unk_2b0, ext);
    self->res2 = 0;
    self->unk_20b |= 8;
    self->unk_93_1 = self->unk_18;
    self->unk_b18 = 0;
    if (self->unk_93_1 != 0) {
        self->unk_b18 = self->unk_93_1 - 1;
    }
}
BOOL func_ov003_021e4588(Ov003Big *self) {
    BOOL r = func_ov000_021946f8(self);
    if (self->res >= 0 && !func_ov000_0218f110(&self->res)) {
        r = FALSE;
    }
    if (self->res2 >= 0 && !func_ov000_0218f110(&self->res2)) {
        r = FALSE;
    }
    return r;
}


extern const s16 FX_SinCosTable_[];
extern const Ov003BigEnt data_ov003_021f5bf0[];
extern void func_ov000_02194758(void *self);
extern BOOL func_ov000_0218ffdc(Ov003BigMdl *m, s16 *res, s32 a, s32 b);
extern void func_ov000_02190758(Ov003BigMdl *m, u16 *rot, s32 a);
extern void NNSi_G3dModifyMatFlag(void *mdl, s32 on, u32 flag);
extern void NNSi_G3dModifyPolygonAttrMask(void *mdl, s32 on, u32 mask);
extern void func_01ffc9fc(Ov003Vec3 *dst, const Ov003Vec3 *src, u16 angle);
extern void VEC_Add(Ov003Vec3 *a, Ov003Vec3 *b, Ov003Vec3 *dst);
extern void func_0203f990(Ov003BigRObj *o, void *res);
extern void MTX_Identity43_(Ov003BigMtx *m);
extern void MTX_RotX43_(Ov003BigMtx *m, s32 s, s32 c);
extern void MTX_RotY43_(Ov003BigMtx *m, s32 s, s32 c);
extern void MTX_RotZ43_(Ov003BigMtx *m, s32 s, s32 c);
extern void MTX_Concat43(Ov003BigMtx *a, Ov003BigMtx *b, Ov003BigMtx *out);
extern void func_0203f9dc(Ov003BigRObj *o, Ov003BigMtx *m);
extern void func_0203f8d8(Ov003BigRObj *o);
extern void func_0203f920(Ov003BigRObj *o);
extern void func_ov003_021e51f8(Ov003Big *self, u32 a);

#define OV003BIG_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003BIG_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

static inline void Ov003Big_SetMtx(Ov003BigRObj *o, Ov003Vec3 *v, u16 rx, u16 ry, u16 rz) {
    Ov003BigMtx m;
    Ov003BigMtx t;
    BOOL set = FALSE;
    MTX_Identity43_(&m);
    if (rz != 0) {
        MTX_RotZ43_(&m, OV003BIG_SIN(rz), OV003BIG_COS(rz));
        set = TRUE;
    }
    if (ry != 0) {
        if (set) {
            MTX_RotY43_(&t, OV003BIG_SIN(ry), OV003BIG_COS(ry));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotY43_(&m, OV003BIG_SIN(ry), OV003BIG_COS(ry));
            set = TRUE;
        }
    }
    if (rx != 0) {
        if (set) {
            MTX_RotX43_(&t, OV003BIG_SIN(rx), OV003BIG_COS(rx));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotX43_(&m, OV003BIG_SIN(rx), OV003BIG_COS(rx));
            set = TRUE;
        }
    }
    m.tx = v->x;
    m.ty = v->y;
    m.tz = v->z;
    func_0203f9dc(o, &m);
}

static inline void *Ov003Big_Res(Ov003BigRes *r) {
    return r->unk_84 != NULL ? *r->unk_84 : NULL;
}

void func_ov003_021e45dc(Ov003Big *self) {
    s32 i;
    func_ov000_02194758(self);
    self->unk_cc_0 = 0;
    func_ov000_0218ffdc(&self->sub, &self->res, 0, 1);
    self->sub.unk_b4 = self->unk_0c;
    func_ov000_02190758(&self->sub, self->rot, 0);
    NNSi_G3dModifyMatFlag(self->sub.mdl, 1, 0x40);
    NNSi_G3dModifyMatFlag(self->sub.mdl, 1, 0x80);
    NNSi_G3dModifyMatFlag(self->sub.mdl, 1, 0x200);
    NNSi_G3dModifyMatFlag(self->sub.mdl, 1, 0x400);
    self->sub.unk_c2_7 = 1;
    NNSi_G3dModifyPolygonAttrMask(self->sub.mdl, 1, 0x1f0000);
    for (i = 0; i < 4; i++) {
        const Ov003BigEnt *e = &data_ov003_021f5bf0[i];
        Ov003Vec3 v;
        u16 ry;
        u16 rz;
        u16 rx;
        void *r;
        func_01ffc9fc(&v, &e->v, self->rot[1]);
        VEC_Add(&v, &self->pos, &v);
        ry = self->rot[1] + e->ang;
        r = Ov003Big_Res(self->unk_34);
        rz = self->rot[2];
        rx = self->rot[0];
        func_0203f990(&self->obj1[i], r);
        Ov003Big_SetMtx(&self->obj1[i], &v, rx, ry, rz);
        if (self->unk_1a == 0 || i <= 1) {
            func_0203f8d8(&self->obj1[i]);
        } else {
            func_0203f920(&self->obj1[i]);
        }
        if (i != 0) {
            ry += 0x8000;
            func_0203f990(&self->obj2[i - 1], Ov003Big_Res(self->unk_34));
            Ov003Big_SetMtx(&self->obj2[i - 1], &v, rx, ry, rz);
            func_0203f920(&self->obj2[i - 1]);
            v.x += (s32)(((s64)OV003BIG_SIN(ry) * 0x400 + 0x800) >> 12);
            v.z += (s32)(((s64)OV003BIG_COS(ry) * 0x400 + 0x800) >> 12);
            self->unk_af4[i - 1].x = v.x;
            self->unk_af4[i - 1].y = v.y;
            self->unk_af4[i - 1].z = v.z;
        }
    }
    {
        u32 a = 0;
        if (self->unk_93_1) {
            a = 0xffff;
        }
        func_ov003_021e51f8(self, a);
    }
}

}
}  // namespace m_021e44dc
#undef OV003BIG_SIN
#undef OV003BIG_COS

// ---- merged from ov003_021e4a94.cpp
namespace m_021e4a94 {

typedef struct {
    u8 unk_00[0x16];
    u8 unk_16_0 : 1;
} Ov003Spawned;

typedef struct {
    void *vtbl;
    u8 unk_04[0x14];
    s16 unk_18;
    u8 unk_1a[0x76];
    u8 unk_90[3];
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
    u8 unk_94[0x3c];
    s16 res;
    u8 unk_d2[0x136];
    s16 res2;
    u8 unk_20a;
    u8 unk_20b;
    u8 unk_20c[0x84];
    u8 unk_290[0x20];
    u8 unk_2b0[0x90];
    Ov003Model sub;
    u8 unk_404[0x24];
    Ov003Vec3 unk_428[4];
    s32 unk_458[4];
    u8 unk_468[4];
    u8 unk_46c[0x6ac];
    u8 unk_b18;
} Ov003Big;

extern "C" {

extern BOOL func_ov000_02194c08(void *self);
extern BOOL func_ov000_021903b4(Ov003Model *m);

BOOL func_ov003_021e4a94(Ov003Big *self) {
    BOOL r = func_ov000_02194c08(self);
    s32 i;
    for (i = 0; i < 4; i++) {
        u8 a = self->unk_468[i];
        if (a != 0) {
            self->sub.unk_be = a;
            Ov003Model_SetScale(&self->sub, self->unk_458[i]);
            self->sub.pos.x = self->unk_428[i].x;
            self->sub.pos.y = self->unk_428[i].y;
            self->sub.pos.z = self->unk_428[i].z;
            if (func_ov000_021903b4(&self->sub)) {
                r = TRUE;
            }
        }
    }
    return r;
}

}
}  // namespace m_021e4a94

// ---- merged from ov003_021e4b18.cpp
namespace m_021e4b18 {

typedef struct {
    s32 m[9];
    s32 tx, ty, tz;
} Ov003BigMtx;

typedef struct {
    u8 unk_00[0x98];
} Ov003BigRObj;

typedef struct {
    u8 unk_00[0x84];
    void **unk_84;
} Ov003BigRes;

typedef struct {
    u16 unk_00;
    u16 ang;
    Ov003Vec3 v;
} Ov003BigEnt;

typedef struct {
    void *unk_00;
    void *mdl;
    u8 unk_08[0xac];
    u16 unk_b4;
    u8 unk_b6[0xc];
    u16 unk_c2_0 : 7;
    u16 unk_c2_7 : 1;
} Ov003BigMdl;

typedef struct {
    void *vtbl;
    u8 unk_04[0x8];
    u16 unk_0c;
    u8 unk_0e[0xa];
    s16 unk_18;
    s16 unk_1a;
    u8 unk_1c[0x18];
    Ov003BigRes *unk_34;
    void *model;
    u8 unk_3c[4];
    Ov003Work *work;
    u8 unk_44[0x20];
    s32 unk_64;
    s32 unk_68;
    u8 unk_6c[4];
    Ov003Vec3 pos;
    u16 rot[3];
    u8 unk_82[0xe];
    u16 unk_90;
    u8 unk_92;
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
    u8 unk_94[0x38];
    u16 unk_cc_0 : 1;
    u8 unk_ce[2];
    s16 res;
    u8 unk_d2[0x136];
    s16 res2;
    u8 unk_20a;
    u8 unk_20b;
    u8 unk_20c[0x84];
    u8 unk_290[0x20];
    u8 unk_2b0[0x90];
    Ov003BigMdl sub;
    u8 unk_404[0x24];
    Ov003Vec3 unk_428[4];
    s32 unk_458[4];
    u8 unk_468[4];
    Ov003BigRObj obj0[4];
    Ov003BigRObj obj1[4];
    Ov003BigRObj obj2[3];
    Ov003Vec3 unk_af4[3];
    u8 unk_b18;
} Ov003Big;

typedef struct {
    s16 unk_00;
    u16 ang;
    Ov003Vec3 v;
} Ov003BigEnt2;

typedef struct {
    Ov003Vec3 pos;
    u16 unk_0c;
    u16 mask;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    u16 unk_28;
    union { u8 flags; struct { u8 f_0 : 1; u8 f_1 : 1; u8 f_2 : 1; u8 f_3 : 1; } b; };
} Ov003BigQuery;

typedef struct {
    Ov003BigQuery *q;
} Ov003BigFinder;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0x60];
    Ov003Vec3 pos;
    u16 rot[3];
} Ov003BigTgt;

typedef struct {
    Ov003Vec3 pos;
    u8 unk_0c[4];
    s32 unk_10;
} Ov003BigHit;

typedef struct {
    Ov003Vec3 pos;
    u16 rot[3];
    s32 unk_14;
} Ov003BigWarp;

extern "C" {

extern const s16 FX_SinCosTable_[];
extern const Ov003BigEnt2 data_ov003_021f6230[][4];
extern void func_01ffc9fc(Ov003Vec3 *dst, const Ov003Vec3 *src, u16 angle);
extern void VEC_Add(Ov003Vec3 *a, Ov003Vec3 *b, Ov003Vec3 *dst);
extern void func_0203f990(Ov003BigRObj *o, void *res);
extern void MTX_Identity43_(Ov003BigMtx *m);
extern void MTX_RotX43_(Ov003BigMtx *m, s32 s, s32 c);
extern void MTX_RotY43_(Ov003BigMtx *m, s32 s, s32 c);
extern void MTX_RotZ43_(Ov003BigMtx *m, s32 s, s32 c);
extern void MTX_Concat43(Ov003BigMtx *a, Ov003BigMtx *b, Ov003BigMtx *out);
extern void func_0203f9dc(Ov003BigRObj *o, Ov003BigMtx *m);
extern void func_0203f9b8(Ov003BigRObj *o, s32 a);
extern void func_0203f8d8(Ov003BigRObj *o);
extern void func_0203f920(Ov003BigRObj *o);
extern s32 func_ov000_0219a2f4(Ov003Vec3 *pos, s32 a, s32 b);
extern void *data_02097e4c;
extern s32 func_ov000_021993fc(Ov003BigFinder *f, Ov003BigQuery *q, Ov003BigHit **out, s32 max);
extern Ov003BigTgt *func_ov000_021985c0(Ov003BigHit *h);
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void *func_0204a028(void *mgr, s32 id, Ov003Vec3 *pos, s32 a);
extern void func_ov000_0218d398(Ov003BigTgt *o, u16 id, s32 a, s32 b, s32 c, void *p);
extern Ov003BigTgt *func_ov000_0218d240(Ov003Big *self);
extern void VEC_MultAdd(s32 a, Ov003Vec3 *v1, Ov003Vec3 *v2, Ov003Vec3 *dst);
extern u16 func_01ffc128(u16 cur, u16 tgt, s32 step, s32 a, s32 b);
void func_ov003_021e51f8(Ov003Big *self, u32 t);

static inline void Ov003BigQuery_Init(Ov003BigQuery *q) {
    q->mask = 0;
    q->unk_10 = 0xffff;
    q->unk_12 = 0;
    q->unk_14 = 0;
    q->unk_18 = 0;
    q->unk_1c = 0;
    q->unk_20 = 0;
    q->unk_24 = 0;
    q->unk_28 = 0xffff;
    q->flags = 0;
}

static inline void Ov003Big_Sub(Ov003Vec3 *d, Ov003Vec3 *a, Ov003Vec3 *b) {
    d->x = a->x - b->x;
    d->y = a->y - b->y;
    d->z = a->z - b->z;
}

#define OV003BIG_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003BIG_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

static inline void Ov003Big_SetMtx(Ov003BigRObj *o, Ov003Vec3 *v, u16 rx, u16 ry, u16 rz) {
    Ov003BigMtx m;
    Ov003BigMtx t;
    BOOL set = FALSE;
    MTX_Identity43_(&m);
    if (rz != 0) {
        MTX_RotZ43_(&m, OV003BIG_SIN(rz), OV003BIG_COS(rz));
        set = TRUE;
    }
    if (ry != 0) {
        if (set) {
            MTX_RotY43_(&t, OV003BIG_SIN(ry), OV003BIG_COS(ry));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotY43_(&m, OV003BIG_SIN(ry), OV003BIG_COS(ry));
            set = TRUE;
        }
    }
    if (rx != 0) {
        if (set) {
            MTX_RotX43_(&t, OV003BIG_SIN(rx), OV003BIG_COS(rx));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotX43_(&m, OV003BIG_SIN(rx), OV003BIG_COS(rx));
            set = TRUE;
        }
    }
    m.tx = v->x;
    m.ty = v->y;
    m.tz = v->z;
    func_0203f9dc(o, &m);
    func_0203f9b8(o, 0x119a);
    func_0203f8d8(o);
}

static inline void *Ov003Big_Res(Ov003BigRes *r) {
    return r->unk_84 != NULL ? *r->unk_84 : NULL;
}

static inline void Ov003Big_Approach(Ov003BigWarp *w, Ov003BigTgt *o, Ov003Big *self) {
    Ov003Vec3 d;
    w->pos.x = o->pos.x;
    w->pos.y = o->pos.y;
    w->pos.z = o->pos.z;
    Ov003Big_Sub(&d, &w->pos, &self->pos);
    VEC_MultAdd(0xc00, &d, &self->pos, &w->pos);
    w->rot[0] = o->rot[0];
    w->rot[1] = o->rot[1];
    w->rot[2] = o->rot[2];
    w->rot[1] = func_01ffc128(self->rot[1], w->rot[1], 0x400, 1, 0x8000);
}

void func_ov003_021e4b18(Ov003Big *self) {
    Ov003BigTgt *found = NULL;
    switch (self->work->state) {
    case 0:
        self->unk_90 = 0xffff;
        self->work->state++;
        break;
    case 1: {
        Ov003BigHit *list[0x20];
        Ov003BigQuery q;
        Ov003BigWarp w;
        Ov003BigFinder f;
        u8 b;
        s32 n;
        u8 kind;
        s32 i;
        Ov003BigQuery_Init(&q);
        q.pos.x = self->pos.x;
        q.pos.y = self->pos.y;
        q.pos.z = self->pos.z;
        q.unk_0c = 0;
        q.unk_28 = self->unk_0c;
        q.unk_1c = self->unk_64 + 0x400;
        q.unk_18 = 0;
        q.unk_20 = 0;
        q.unk_24 = 0x2800;
        q.b.f_1 = 1;
        q.b.f_2 = 1;
        q.b.f_3 = 1;
        q.mask = 0x10;
        q.unk_10 = 0xffff;
        f.q = NULL;
        n = func_ov000_021993fc(&f, &q, list, 0x20);
        kind = 0;
        for (i = 0; i < n; i++) {
            Ov003BigHit *h = list[i];
            if (h != NULL && h->pos.y - h->unk_10 - self->pos.y - self->unk_68 <= 0x666) {
                Ov003BigTgt *o = func_ov000_021985c0(h);
                if (o != NULL) {
                    u8 k = 0;
                    if (o->unk_0e == 0x404b) {
                        k = 1;
                    } else if (o->unk_0e == 0x404c) {
                        k = 2;
                    } else if (o->unk_0e == 0x404d) {
                        k = 3;
                    }
                    if (k != 0) {
                        if (self->unk_90 == o->unk_0c) {
                            kind = k;
                            found = o;
                            break;
                        }
                        if (k == self->unk_93_1) {
                            kind = k;
                            found = o;
                        } else if (kind == 0 && found == NULL) {
                            kind = k;
                            found = o;
                        }
                    }
                }
            }
        }
        if (self->unk_93_1 != kind) {
            if (kind != 0 && self->unk_93_1 == 0) {
                func_ov000_02190cb0(self->model, "on00", 0x1000, 0);
                func_0204a028(data_02097e4c, 0xd, &self->pos, -0xf);
                self->unk_90 = found->unk_0c;
                self->unk_93_1 = kind;
                self->unk_18 = kind;
                b = 0;
                func_ov000_0218d398(found, self->unk_0c, 0xd, 1, 1, &b);
                self->unk_b18 = self->unk_93_1 - 1;
                self->work->state = 10;
            } else {
                func_ov000_02190cb0(self->model, "off00", 0x1000, 0);
                func_0204a028(data_02097e4c, 0xd, &self->pos, -0xf);
                self->unk_18 = 0;
                self->unk_93_1 = 0;
                self->unk_90 = 0xffff;
                for (i = 0; i < 3; i++) {
                    func_0203f920(&self->obj2[i]);
                }
                for (i = 0; i < 4; i++) {
                    if (self->unk_1a == 0 || i <= 1) {
                        func_0203f8d8(&self->obj1[i]);
                    }
                }
                self->work->state = 20;
            }
        }
        if (self->unk_93_1 != 0 && found != NULL) {
            self->unk_90 = found->unk_0c;
            w.unk_14 = 0;
            Ov003Big_Approach(&w, found, self);
            func_ov000_0218d398(found, self->unk_0c, 7, 1, 0x18, &w);
            func_0203f920(&self->obj2[self->unk_b18]);
            if (func_ov000_0219a2f4(&self->unk_af4[self->unk_b18], 0x1000, -0x5000) == -0x1000) {
                func_0203f8d8(&self->obj2[self->unk_b18]);
            }
        }
        break;
    }
    case 10: {
        Ov003BigWarp w;
        Ov003BigTgt *o = func_ov000_0218d240(self);
        Ov003Work *wk;
        if (o == NULL) {
            self->work->state = 0;
            break;
        }
        w.unk_14 = 0;
        wk = self->work;
        wk->timer++;
        if (wk->timer < 6) {
            Ov003Big_Approach(&w, o, self);
        } else {
            w.pos.x = self->pos.x;
            w.pos.y = self->pos.y;
            w.pos.z = self->pos.z;
            w.pos.y -= 0x800;
            w.rot[0] = self->rot[0];
            w.rot[1] = self->rot[1];
            w.rot[2] = self->rot[2];
            self->work->state++;
            self->work->timer = 0;
        }
        func_ov000_0218d398(o, self->unk_0c, 7, 1, 0x18, &w);
        break;
    }
    case 11: {
        Ov003Work *wk = self->work;
        wk->timer++;
        if (wk->timer > 0x24) {
            Ov003BigTgt *o = func_ov000_0218d240(self);
            if (o != NULL) {
                u8 b = 1;
                func_ov000_0218d398(o, self->unk_0c, 0xd, 1, 1, &b);
            }
            self->work->timer = 0xffff;
            self->work->state = 1;
        }
        func_ov003_021e51f8(self, self->work->timer);
        break;
    }
    case 20:
        self->work->timer = 0x24;
        self->work->state++;
    case 21: {
        Ov003Work *wk = self->work;
        if (wk->timer != 0) {
            wk->timer--;
        }
        if (wk->timer == 0) {
            self->work->state = 0;
        }
        func_ov003_021e51f8(self, self->work->timer);
        break;
    }
    }
}

void func_ov003_021e51f8(Ov003Big *self, u32 t) {
    Ov003Vec3 v;
    if (t == 0) {
        s32 i;
        for (i = 0; i < 4; i++) {
            self->unk_428[i].x = self->pos.x;
            self->unk_428[i].y = self->pos.y;
            self->unk_428[i].z = self->pos.z;
            self->unk_458[i] = 0;
            self->unk_468[i] = 0;
            func_0203f920(&self->obj0[i]);
        }
        for (i = 0; i < 3; i++) {
            func_0203f920(&self->obj2[i]);
        }
        for (i = 0; i < 4; i++) {
            if (self->unk_1a == 0 || i <= 1) {
                func_0203f8d8(&self->obj1[i]);
            }
        }
    } else if (t == 0xffff) {
        s32 i;
        func_0203f920(&self->obj1[0]);
        func_0203f920(&self->obj1[self->unk_b18 + 1]);
        func_0203f920(&self->obj2[self->unk_b18]);
        if (func_ov000_0219a2f4(&self->unk_af4[self->unk_b18], 0x1000, -0x5000) == -0x1000) {
            func_0203f8d8(&self->obj2[self->unk_b18]);
        }
        for (i = 0; i < 4; i++) {
            const Ov003BigEnt2 *e = &data_ov003_021f6230[self->unk_b18][i];
            if (e->unk_00 >= 0) {
                u16 rz;
                u16 rx;
                u16 ry;
                void *r;
                func_01ffc9fc(&v, &e->v, self->rot[1]);
                VEC_Add(&v, &self->pos, &v);
                self->unk_428[i].x = v.x;
                self->unk_428[i].y = v.y;
                self->unk_428[i].z = v.z;
                self->unk_458[i] = 0x1000;
                self->unk_468[i] = 0x1f;
                rz = self->rot[2];
                ry = self->rot[1] + e->ang;
                rx = self->rot[0];
                { Ov003BigRes *q = (Ov003BigRes *)&self->res; if (e->unk_00 != 0) q = (Ov003BigRes *)&self->res2; r = Ov003Big_Res(q); }
                func_0203f990(&self->obj0[i], r);
                Ov003Big_SetMtx(&self->obj0[i], &v, rx, ry, rz);
            } else {
                self->unk_468[i] = 0;
            }
        }
    } else {
        if (t <= 12 && data_ov003_021f6230[self->unk_b18][0].unk_00 >= 0) {
            func_01ffc9fc(&v, &data_ov003_021f6230[self->unk_b18][0].v, self->rot[1]);
            VEC_Add(&v, &self->pos, &self->unk_428[0]);
            self->unk_458[0] = (s32)(t << 12) / 12;
            self->unk_468[0] = (s32)(t * 31) / 12;
        }
        if (t >= 6 && t <= 18 && data_ov003_021f6230[self->unk_b18][1].unk_00 >= 0) {
            func_01ffc9fc(&v, &data_ov003_021f6230[self->unk_b18][1].v, self->rot[1]);
            VEC_Add(&v, &self->pos, &self->unk_428[1]);
            self->unk_458[1] = (s32)((t - 6) << 12) / 12;
            self->unk_468[1] = (s32)((t - 6) * 31) / 12;
        }
        if (t >= 12 && t <= 24 && data_ov003_021f6230[self->unk_b18][2].unk_00 >= 0) {
            func_01ffc9fc(&v, &data_ov003_021f6230[self->unk_b18][2].v, self->rot[1]);
            VEC_Add(&v, &self->pos, &self->unk_428[2]);
            self->unk_458[2] = (s32)((t - 12) << 12) / 12;
            self->unk_468[2] = (s32)((t - 12) * 31) / 12;
        }
        if (t >= 18 && t <= 30 && data_ov003_021f6230[self->unk_b18][3].unk_00 >= 0) {
            func_01ffc9fc(&v, &data_ov003_021f6230[self->unk_b18][3].v, self->rot[1]);
            VEC_Add(&v, &self->pos, &self->unk_428[3]);
            self->unk_458[3] = (s32)((t - 18) << 12) / 12;
            self->unk_468[3] = (s32)((t - 18) * 31) / 12;
        }
    }
}

}
}  // namespace m_021e4b18
#undef OV003BIG_SIN
#undef OV003BIG_COS

// ---- merged from ov003_021e57b8.cpp
namespace m_021e57b8 {

typedef struct {
    s32 x, y, z;
} Ov003Vec3;

typedef struct {
    u16 state;
    u16 timer;
    u8 unk_04[0xf];
    u8 kind;
} Ov003Work;

typedef struct {
    u8 unk_00[0x50];
    u32 flags;
    u32 unk_54;
    u8 unk_58[0x42];
    u16 unk_9a;
} Ov003Ctl;

typedef struct {
    void *cur;
    u32 unk_04;
    void *alt;
} Ov003HeapCtx;

typedef struct {
    u8 unk_00[0x2c];
    u32 unk_2c;
} Ov003ColState;

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 1;
} Ov003Unit;

typedef struct {
    void *unk_00;
} Ov003ModelRes;

typedef struct {
    u8 unk_00[0xc];
    Ov003ModelRes *unk_0c;
} Ov003ModelHdr;

typedef struct {
    Ov003ModelHdr *unk_00;
    u8 unk_04[0xa4];
    s32 unk_a8;
    s32 unk_ac;
    s32 unk_b0;
    u8 unk_b4[0xe];
    u16 unk_c2_0 : 1;
} Ov003Model;

typedef struct {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
    u8 unk_98[0x32];
    u8 unk_ca;
    u8 unk_cb[9];
    void *unk_d4;
} Ov003Game54;

typedef struct {
    void *vtbl;
    u8 unk_04[0xa];
    u16 unk_0e;
    u8 unk_10[0x8];
    s16 unk_18;
    u8 unk_1a[2];
    s16 kind;
    s16 unk_1e;
    u16 unk_20;
    u8 unk_22[0x16];
    Ov003Model *model;
    u8 unk_3c[4];
    Ov003Work *work;
    void *unk_44;
    Ov003Ctl *ctl;
    u8 unk_4c[0x10];
    void *unk_5c;
    void *unk_60;
    u8 unk_64[0xc];
    Ov003Vec3 pos;
    u8 unk_7c[0x8];
    s32 unk_84;
    s32 unk_88;
    s32 unk_8c;
    u8 unk_90[3];
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
    u8 unk_94[0x8];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x20];
    u16 unk_cc_0 : 3;
    u16 unk_cc_3 : 1;
    u16 unk_ce;
    s16 res;
    u8 unk_d2;
    u8 unk_d3;
    Ov003Vec3 unk_d4;
    u8 unk_e0[0xec];
    void **unk_1cc;
    u8 unk_1d0[0x20];
    u8 unk_1f0[0x18];
    void *unk_208;
    u8 unk_20c;
    u8 unk_20d[3];
    s32 unk_210;
} Ov003Obj;

extern "C" {

extern Ov003ColState data_02fe0f14;
extern Ov003HeapCtx *data_02097dd0;
extern char data_ov003_021f8768[];
extern void func_ov000_02194758(void *self);
extern s32 func_ov000_0219a2f4(Ov003Vec3 *pos, s32 a, s32 b);
extern void func_ov000_02197ee0(void *self, s16 *res, s32 a, s32 b, s32 c);
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_0218ddd4(void *self, Ov003Vec3 *v, s32 a);
extern void func_ov000_021987b8(Ov003Ctl *ctl, s32 a, s32 b, s32 c);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern void *func_ov000_0214b598(void *p);
extern void func_0203de1c(void *p);
extern void *func_ov000_0218ea20(void *p);
extern void *func_ov000_0219429c(void *self);
extern Ov003Game54 *data_ov000_021ccd54;
extern void *const data_ov003_021f4c64[2];
extern void func_ov000_0219433c(void *self);
extern void *func_0207011c(u16 id);
extern void STD_CopyString(void *dst, const void *src);
extern void STD_ConcatenateString(void *dst, const char *s);
extern void *func_02039674(void *p);
extern BOOL OS_IsRunOnTwl(void);
extern void *func_0203dd9c(u32 size);
extern void *func_ov000_0214b570(void *p);
extern void func_ov000_0214b5e8(void *p, void *t);
extern BOOL func_ov000_021946f8(void *self);
extern BOOL func_ov000_0218f110(s16 *res);
extern s32 func_ov000_0214b6d0(void *p);
extern BOOL func_ov000_0214b640(void *p);
extern void func_ov000_0214b5bc(void *p);
extern BOOL func_ov000_02194c08(void *self);
extern void func_ov000_021bd7a0(void *p);
extern void *data_ov000_021ccd64;
extern void *NNS_G3dGetTex(void *p);
extern void *func_ov000_0214b670(void *p);
extern void *func_020394cc(void *a, void *b);
extern void *NNS_G3dGetMdlSet(void *p);
extern BOOL NNS_G3dBindMdlSet(void *a, void *b);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);
extern s32 func_02040528(s32 max);

static inline BOOL Ov003Game_IsBusy(Ov003Game54 *g) {
    return g->unk_90 != g->unk_94;
}

static inline BOOL Ov003Game_IsIdle(Ov003Game54 *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    Ov003Game54 *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}

static inline BOOL Ov003Game_HasD4(Ov003Game54 *g) {
    return g->unk_d4 != NULL ? TRUE : FALSE;
}

static inline BOOL Ov003_GameHasD4(void) {
    return Ov003Game_HasD4(data_ov000_021ccd54) ? TRUE : FALSE;
}

void func_ov003_021e57b8(Ov003Obj *self) {
    func_ov000_02194758(self);
    if (func_ov000_0219a2f4(&self->pos, 0x1000, -0xa000) == -0x1000) {
        return;
    }
    self->ctl->unk_54 |= data_02fe0f14.unk_2c;
}

void func_ov003_021e5804(Ov003Obj *self) {
    if (self->work->kind == 9) {
        return;
    }
    func_ov000_02197ee0(self, &self->res, 0x2cd, 0x333, 0x8800);
}

void func_ov003_021e5838(Ov003Obj *self) {
    Ov003Vec3 v;
    if (self->work->state == 0) {
        func_ov000_02190cb0(self->model, "run00", 0x2ab, 0);
        func_ov000_021915a0(self->model);
        self->work->state++;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
    }
    self->ctl->unk_9a |= 0x20;
    self->unk_9c = 0x2cd;
    v.x = self->unk_d4.x;
    v.y = self->unk_d4.y;
    v.z = self->unk_d4.z;
    func_ov000_0218ddd4(self, &v, 0x333);
    func_ov000_021987b8(self->ctl, 1, 0, 0);
    if (self->ctl->flags & 0x20000000) {
        return;
    }
    func_ov000_02198360(self->work, 4, 0);
}

Ov003Obj *func_ov003_021e5920(Ov003Obj *self) {
    void *old;
    void *p;
    self->vtbl = data_ov003_021f8768;
    old = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->alt;
    p = self->unk_208;
    if (p != NULL) {
        if (p != NULL) {
            func_ov000_0214b598(p);
            func_0203de1c(p);
        }
        self->unk_208 = NULL;
    }
    data_02097dd0->cur = old;
    func_ov000_0218ea20(&self->res);
    func_ov000_0219429c(self);
    return self;
}

Ov003Obj *func_ov003_021e5998(Ov003Obj *self) {
    void *old;
    void *p;
    self->vtbl = data_ov003_021f8768;
    old = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->alt;
    p = self->unk_208;
    if (p != NULL) {
        if (p != NULL) {
            func_ov000_0214b598(p);
            func_0203de1c(p);
        }
        self->unk_208 = NULL;
    }
    data_02097dd0->cur = old;
    func_ov000_0218ea20(&self->res);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov003_021e5a18(Ov003Obj *self) {
    u8 buf[0x20];
    func_ov000_0219433c(self);
    if (self->kind != 0) {
        u16 id = self->unk_0e;
        void *r;
        void *t;
        if (self->kind == 3) {
            id = 0x4053;
        }
        STD_CopyString(buf, func_0207011c(id));
        STD_ConcatenateString(buf, "c");
        r = func_02039674(buf);
        STD_CopyString(self->unk_1d0, buf);
        STD_CopyString(self->unk_1f0, r);
        t = NULL;
        self->res = 0;
        self->unk_d3 |= 0x20;
        if (OS_IsRunOnTwl()) {
            if ((u16)(s16)(self->kind - 1) <= 1) {
                if (id == 0x4053) {
                    t = data_ov003_021f4c64[1];
                } else if (id == 0x4054) {
                    t = data_ov003_021f4c64[0];
                }
                if (t != NULL) {
                    void *p = func_0203dd9c(0x1c);
                    if (p != NULL) {
                        p = func_ov000_0214b570(p);
                    }
                    self->unk_208 = p;
                    func_ov000_0214b5e8(p, t);
                }
            }
        }
    }
    self->unk_210 = 0;
    self->unk_20c = 0;
}

BOOL func_ov003_021e5b34(Ov003Obj *self) {
    BOOL r = func_ov000_021946f8(self);
    if (self->kind != 0 && self->unk_20c == 0) {
        if (self->res >= 0 && !func_ov000_0218f110(&self->res)) {
            r = FALSE;
        }
        if (self->unk_208 != NULL) {
            if (func_ov000_0214b6d0(self->unk_208) == 2) {
                r = FALSE;
                self->unk_20c = 1;
            }
            if (r && !func_ov000_0214b640(self->unk_208)) {
                func_ov000_0214b5bc(self->unk_208);
                r = FALSE;
            }
        }
    }
    return r;
}

void func_ov003_021e5bc4(Ov003Obj *self) {
    Ov003Unit *u;
    func_ov000_02194758(self);
    if (self->kind != 0 && self->unk_20c == 0) {
        void *h;
        if (self->unk_1cc == NULL) {
            h = NULL;
        } else {
            h = NNS_G3dGetTex(*self->unk_1cc);
        }
        if (h != NULL) {
            if (self->kind != 3) {
                if (self->unk_208 != NULL) {
                    void *x = func_ov000_0214b670(self->unk_208);
                    if (x != NULL) {
                        func_020394cc(*self->unk_1cc, x);
                    }
                }
            } else if (self->unk_60 != NULL) {
                func_020394cc(*self->unk_1cc, self->unk_60);
            }
            NNS_G3dBindMdlSet(NNS_G3dGetMdlSet(self->model->unk_00->unk_0c != NULL ? self->model->unk_00->unk_0c->unk_00 : NULL), h);
        }
    }
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_0 = 0;
    }
    self->unk_cc_3 = 0;
    if (self->unk_1e != 0) {
        s32 x;
        s32 y;
        s32 z;
        if (self->unk_44 != NULL) {
            void *old = data_02097dd0->cur;
            data_02097dd0->cur = data_02097dd0->alt;
            if (self->unk_44 != NULL) {
                func_0203de1c(self->unk_44);
                self->unk_44 = NULL;
            }
            data_02097dd0->cur = old;
        }
        if (self->unk_1e == 2) {
            y = func_02040528(0x4000) - 0x2000;
            x = func_02040528(0x9000);
            z = -0x32000;
            self->unk_84 = x;
            self->unk_88 = y;
            self->unk_8c = z;
        } else {
            y = func_02040528(0x2000) - 0x4000;
            x = func_02040528(0x6000);
            z = -0x14000;
            self->unk_84 = x;
            self->unk_88 = y;
            self->unk_8c = z;
        }
    } else if (self->unk_18 <= 0) {
        self->model->unk_c2_0 = 0;
    } else {
        func_ov000_02198360(self->work, 6, 0);
        self->unk_93_1 = (u8)self->unk_18;
    }
    if (self->unk_0e == 0x406a && data_ov000_021ccd54->unk_ca == 0x10) {
        Ov003Model *m = self->model;
        m->unk_a8 = 0x1800;
        m->unk_ac = 0x1800;
        m->unk_b0 = 0x1800;
    }
}

BOOL func_ov003_021e5dd0(Ov003Obj *self) {
    BOOL r = func_ov000_02194c08(self);
    if (self->unk_5c != NULL && Ov003_GameIdle() && !Ov003_GameHasD4()) {
        func_ov000_021bd7a0(self->unk_5c);
    }
    return r;
}

}
}  // namespace m_021e57b8

// ---- merged from ov003_021e5e70.cpp
namespace m_021e5e70 {

class Ov003Bar {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();

    u8 unk_04[8];
    u32 flags;
    u8 unk_10[0xc];
    s32 unk_1c;
    u8 unk_20[0x28];
    u16 unk_48;
    u8 unk_4a[0xa];
    s32 unk_54;
    u8 unk_58[0x10];
    s16 unk_68;
};

typedef struct {
    s32 m[9];
} Ov003BarMtx;

typedef struct {
    u8 unk_00[0x16];
    u16 unk_16;
} Ov003BarSnd;

typedef struct {
    u8 unk_00[0x48];
    struct {
        u8 unk_00[4];
        void *unk_04;
    } *unk_48;
} Ov003BarHdr;

extern "C" {

extern int data_02097d78[];
extern void *data_ov000_021cac60[];
extern void *data_ov000_021cad50[];
extern void *data_02149ef8;
extern void *data_ov000_021ccd68;
extern Ov003Game54 *data_ov000_021ccd54;
extern Ov003Vec3 data_02092a50;
extern void *func_0203dd9c(u32 size);
extern const char *func_0204c0e8(void *mgr, s32 id);
extern void func_ov000_0215c1bc(void *a, s32 b, const char *c);
extern void func_ov000_02188140(void *p, s32 a, s32 b, s32 c);
extern Ov003BarSnd *func_ov000_0218e4cc(void *mgr, u16 id);
extern BOOL func_ov000_0218fb64(Ov003Anim *self, void *obj, void *tex, void *file, s32 index, s16 blend, u8 force);
extern Ov003BarMtx *NNS_G3dGlbGetInvV(void);
extern void VEC_Add(Ov003Vec3 *a, Ov003Vec3 *b, Ov003Vec3 *dst);

static inline BOOL Ov003Bar_FadeIdle(void) {
    if (data_02097d78[3] == 0 && data_02097d78[0] == 0) {
        return TRUE;
    }
    return FALSE;
}

static inline void Ov003Bar_Init(Ov003Bar *b) {
    b->flags |= 8;
    b->unk_48 = 0x14a5;
    b->unk_54 = 0x1c;
}

void func_ov003_021e5e70(Ov003Obj *self) {
    if (self->unk_20c != 0) {
        Ov003Bar *b;
        if (!Ov003Bar_FadeIdle()) {
            return;
        }
        if (self->unk_210 == 0) {
            b = (Ov003Bar *)func_0203dd9c(0xe8);
            if (b != NULL) {
                *(void ***)b = data_ov000_021cac60;
                b->v28();
                *(void ***)b = data_ov000_021cad50;
                b->v28();
            }
            self->unk_210 = (s32)b;
            b->flags |= 0x10000;
            Ov003Bar_Init((Ov003Bar *)self->unk_210);
            ((Ov003Bar *)self->unk_210)->flags |= 0x20000;
            ((Ov003Bar *)self->unk_210)->unk_1c = 4;
            ((Ov003Bar *)self->unk_210)->v08();
            func_ov000_0215c1bc((Ov003Bar *)self->unk_210, 0x8000, func_0204c0e8(data_02149ef8, 0x76));
            ((Ov003Bar *)self->unk_210)->unk_68 = -0x299a;
            ((Ov003Bar *)self->unk_210)->v70();
            func_ov000_02188140(data_ov000_021ccd54, 0xffff, 0, 0);
        } else {
            ((Ov003Bar *)self->unk_210)->v1c();
            ((Ov003Bar *)self->unk_210)->v20();
        }
        return;
    }
    switch (self->work->state) {
    case 0:
        if (self->unk_1e == 0) {
            Ov003BarSnd *s;
            Ov003Sub44 *p;
            if (self->unk_44 == NULL) {
                return;
            }
            s = func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000);
            if (s == NULL) {
                return;
            }
            p = self->unk_44;
            if (s->unk_16 != 0) {
                p->unk_22_0 = 0;
                p->unk_22_1 = 0;
                return;
            }
            p->unk_22_0 = 1;
            p->unk_22_1 = 1;
            return;
        }
        if (self->unk_1e == 2) {
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0x8cd;
        } else {
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0x59a;
        }
        self->work->state = 10;
    case 10: {
        s32 z = self->unk_8c;
        Ov003BarMtx *m;
        s32 x;
        s32 y;
        if (z < 0x2800) {
        if (z > -0x1800) {
            self->model->unk_be = ((0x2800 - z) * 31) / 0x4000;
            Ov003Model_ResetAnim(self->model);
        } else if (z < -0xf000) {
            self->model->unk_be = ((z + 0x14000) * 31) / 0x5000;
            Ov003Model_ResetAnim(self->model);
        } else {
            Ov003Model *md = self->model;
            if (md->unk_10 != NULL) {
                func_ov000_0218fb64(md->unk_10, md->unk_24, *(void **)(md->unk_04 + 4), ((Ov003BarHdr *)md->unk_00)->unk_48->unk_04, 0, 0x1000, 0);
            }
        }
        VEC_Add((Ov003Vec3 *)&self->unk_84, (Ov003Vec3 *)&self->unk_9c, (Ov003Vec3 *)&self->unk_84);
        m = NNS_G3dGlbGetInvV();
        y = self->unk_88;
        x = self->unk_84;
        z = self->unk_8c;
        self->pos.x = (s32)(((s64)x * m->m[0] + (s64)y * m->m[3] + (s64)z * m->m[6]) >> 12);
        self->pos.y = (s32)(((s64)x * m->m[1] + (s64)y * m->m[4] + (s64)z * m->m[7]) >> 12);
        self->pos.z = (s32)(((s64)x * m->m[2] + (s64)y * m->m[5] + (s64)z * m->m[8]) >> 12);
        VEC_Add(&self->pos, &data_02092a50, &self->pos);
        } else {
            Ov003Obj_Destroy(self);
        }
        break;
    }
    }
}

}
}  // namespace m_021e5e70

// ---- merged from ov003_021e6274.cpp
namespace m_021e6274 {

typedef struct {
    s32 x, y, z;
} Ov003Vec3;

extern "C" void NNS_G3dRenderObjRemoveAnmObj(void *a, void *b);

typedef struct {
    u16 state;
    u16 timer;
    u8 unk_04[0xf];
    u8 kind;
} Ov003Work;

typedef struct {
    u8 unk_00[0x50];
    u32 flags;
    u32 unk_54;
    u8 unk_58[0x42];
    u16 unk_9a;
} Ov003Ctl;

typedef struct {
    void *cur;
    u32 unk_04;
    void *alt;
} Ov003HeapCtx;

typedef struct {
    u8 unk_00[0x2c];
    u32 unk_2c;
} Ov003ColState;

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 1;
    u8 unk_a2_1 : 4;
    u8 unk_a2_5 : 1;
    u8 unk_a2_6 : 1;
} Ov003Unit;

typedef struct {
    void *unk_00;
} Ov003ModelRes;

typedef struct {
    u8 unk_00[0xc];
    Ov003ModelRes *unk_0c;
} Ov003ModelHdr;

typedef struct {
    void *unk_00;
    u8 unk_04[0x104];
    u8 unk_108;
    u8 unk_109[7];
    u8 unk_110;
    u8 unk_111_0 : 1;
    u8 unk_111_1 : 1;
} Ov003Anim;

typedef struct {
    u8 unk_00[0x22];
    u16 unk_22_0 : 1;
    u16 unk_22_1 : 1;
} Ov003Sub44;

typedef struct {
    u8 unk_00[0x18];
    u8 unk_18_0 : 5;
    u8 unk_18_5 : 1;
    u8 unk_19[3];
    u16 unk_1c;
} Ov003Part;

typedef struct {
    Ov003Vec3 pos;
    s32 unk_0c;
} Ov003PathPt;

typedef struct {
    Ov003ModelHdr *unk_00;
    u8 unk_04[0xc];
    Ov003Anim *unk_10;
    u8 unk_14[0x10];
    u8 unk_24[0x84];
    s32 unk_a8;
    s32 unk_ac;
    s32 unk_b0;
    u8 unk_b4[0xa];
    u8 unk_be;
    u8 unk_bf[3];
    u16 unk_c2_0 : 1;
} Ov003Model;

typedef struct {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
    u8 unk_98[0x14];
    u8 unk_ac;
    u8 unk_ad[0x1d];
    u8 unk_ca;
    u8 unk_cb[9];
    void *unk_d4;
} Ov003Game54;

typedef struct Ov003Obj {
    void *vtbl;
    u8 unk_04[0x8];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0x8];
    s16 unk_18;
    s16 unk_1a;
    s16 kind;
    s16 unk_1e;
    u16 unk_20;
    u8 unk_22[0x16];
    Ov003Model *model;
    u8 unk_3c[4];
    Ov003Work *work;
    Ov003Sub44 *unk_44;
    Ov003Ctl *ctl;
    Ov003Part *unk_4c;
    u8 unk_50[0xc];
    void *unk_5c;
    void *unk_60;
    u8 unk_64[0xc];
    Ov003Vec3 pos;
    u8 unk_7c[0x8];
    s32 unk_84;
    s32 unk_88;
    s32 unk_8c;
    u8 unk_90[3];
    u8 unk_93_0 : 1;
    u8 unk_93_1 : 3;
    u8 unk_94[0x8];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x20];
    u16 unk_cc_0 : 3;
    u16 unk_cc_3 : 1;
    s16 unk_ce;
    s16 res;
    u8 unk_d2;
    u8 unk_d3;
    Ov003Vec3 unk_d4;
    u8 unk_e0[0xec];
    void **unk_1cc;
    u8 unk_1d0[0x20];
    u8 unk_1f0[0x18];
    void *unk_208;
    u8 unk_20c;
    u8 unk_20d[3];
    s32 unk_210;
} Ov003Obj;

class Ov003ObjV {
public:
    virtual void v00();
    virtual void v04();
    virtual void Destroy();
};

static inline void Ov003Obj_Destroy(Ov003Obj *self) {
    ((Ov003ObjV *)self)->Destroy();
}

static inline void Ov003Model_ResetAnim(Ov003Model *m) {
    Ov003Anim *a = m->unk_10;
    if (a != NULL) {
        NNS_G3dRenderObjRemoveAnmObj(m->unk_24, a->unk_00);
        a->unk_108 = 0;
        a->unk_110 = 0xff;
        a->unk_111_0 = 0;
        a->unk_111_1 = 0;
    }
}

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern Ov003Game54 *data_ov000_021ccd54;
extern Ov003PathPt *const data_ov003_021f85c0[];
extern Ov003Part *func_ov000_02199ba0(Ov003Part *p);
extern void func_ov000_02197dec(void *self, s32 a, s16 b);
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_02190e98(void *model, s32 a, s32 b, s32 c);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_02191618(void *model);
extern void *func_ov000_02191318(void *model, s32 a);
extern BOOL func_ov000_02191120(void *model);
extern void *func_0204a028(void *mgr, s32 id, Ov003Vec3 *pos, s32 a);
extern void func_ov000_0218d398(void *p, u16 a, s32 b, s32 c, s32 d, s32 e);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_020627ec(s32 a);
extern s32 func_02040498(s32 max);
extern void func_ov000_0218bed8(void *mgr, s32 a, void *obj);
extern void func_ov000_02194758(void *self);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);
extern BOOL func_ov000_02194c08(void *self);
extern void func_ov000_02191008(void *p);

static inline void Ov003Model_SetScale(Ov003Model *m, s32 s) {
    m->unk_a8 = s;
    m->unk_ac = s;
    m->unk_b0 = s;
}

static inline void Ov003Model_SetScale3(Ov003Model *m, s32 x, s32 y, s32 z) {
    m->unk_a8 = x;
    m->unk_ac = y;
    m->unk_b0 = z;
}

static inline void Ov003Sub44_Clear(Ov003Sub44 *s) {
    if (s != NULL) {
        s->unk_22_0 = 0;
        s->unk_22_1 = 0;
    }
}

static inline s32 Bit6274(Ov003Obj *o, u32 i) { return o->unk_1a & (1 << i); }
void func_ov003_021e6274(Ov003Obj *self) {
    u8 n = 0; Ov003Part *t;
    t = func_ov000_02199ba0(self->unk_4c);
    switch (self->work->state) {
    case 0:
        if (self->unk_18 == 0) {
            self->unk_18 = 1;
            self->unk_93_1 = 1;
            func_ov000_02197dec(self, 1, -1);
            self->model->unk_c2_0 = 1;
            if (self->unk_0e == 0x4057) {
                func_ov000_02190cb0(self->model, "nut00", 0x1000, 0);
            } else {
                func_ov000_02190e98(self->model, n, 0x1000, 0);
            }
            if (self->unk_1a & 1) {
                func_ov000_021915a0(self->model);
            } else {
                func_ov000_02191618(self->model);
            }
            func_0204a028(data_02097e4c, 0x85, &self->pos, -0xf);
        } else {
            n = self->unk_18 - 1;
            func_ov000_02190e98(self->model, n, 0x1000, 0);
            if (self->unk_1a & (1 << n)) {
                func_ov000_021915a0(self->model);
            } else {
                func_ov000_02191618(self->model);
                func_ov000_02191318(self->model, -1);
            }
        }
        Ov003Sub44_Clear(self->unk_44);
        self->work->state++;
        break;
    case 1:
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        if (t != NULL) {
            func_ov000_0218d398(t, self->unk_0c, 3, 1, 0, 0);
        }
        self->unk_4c->unk_1c = 0xffff;
        func_020627a0(self->unk_0e, self->unk_0c);
        func_020627dc(4);
        func_020627ec(self->unk_93_1);
        data_ov000_021ccd54->unk_ac = 1;
        self->work->state++;
        break;
    case 2:
        n = self->unk_18;
        if (n == self->unk_93_1 || n == 0) {
            return;
        }
        func_ov000_02197dec(self, n, -1);
        self->unk_93_1 = n;
        n--;
        func_ov000_02190e98(self->model, n, 0x1000, 0);
        if (Bit6274(self, n)) {
            func_ov000_021915a0(self->model);
        } else {
            func_ov000_02191618(self->model);
        }
        self->work->state = 1;
        break;
    }
}

void func_ov003_021e651c(Ov003Obj *self) {
    switch (self->work->state) {
    case 0:
        Ov003Model_ResetAnim(self->model);
        self->model->unk_be = 20;
        self->work->state++;
    case 1: {
        u8 a;
        Ov003Work *w = self->work;
        u16 t;
        w->timer++;
        t = w->timer;
        a = 20 - t;
        a -= (u8)func_02040498(5);
        self->model->unk_be = a;
        if (t <= 12) {
            return;
        }
        func_020627ec(100);
        func_ov000_02197dec(self, 0xf, 4);
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        Ov003Obj_Destroy(self);
        break;
    }
    }
}

void func_ov003_021e661c(Ov003Obj *self) {
    func_ov000_02194758(self);
    func_ov000_02198360(self->work, 0x20, 0);
    func_ov000_02191008(self->model);
}

void func_ov003_021e6644(Ov003Obj *self) {
    switch (self->work->state) {
    case 0:
        func_0204a028(data_02097e4c, 0x25, &self->pos, -0xf);
        self->work->state++;
    case 1: {
        Ov003Work *w = self->work;
        u16 t;
        s32 s;
        w->timer++;
        t = w->timer;
        self->model->unk_be = t;
        Ov003Model_SetScale(self->model, 0x3000 - t * 0x19a);
        if (t <= 20) {
            return;
        }
        func_020627a0(self->unk_0e, self->unk_0c);
        func_020627dc(4);
        func_020627ec(1);
        data_ov000_021ccd54->unk_ac = 1;
        func_ov000_02198360(self->work, 1, 0);
        break;
    }
    }
}

void func_ov003_021e671c(Ov003Obj *self) {
    switch (self->work->state) {
    case 0:
        Ov003Model_ResetAnim(self->model);
        self->work->state++;
    case 1: {
        Ov003Work *w = self->work;
        u16 t;
        s32 s;
        w->timer++;
        t = w->timer;
        s = t * 0x7b;
        self->model->unk_be = 25 - t;
        Ov003Model_SetScale3(self->model, s + 0x1000, (s >> 1) + 0x1000, s + 0x1000);
        if (t <= 15) {
            return;
        }
        self->work->state++;
        self->work->timer = 0;
        break;
    }
    case 2: {
        Ov003Work *w = self->work;
        u16 t;
        s32 s;
        w->timer++;
        t = w->timer;
        s = t * 0x252;
        self->model->unk_be = 15 - t;
        Ov003Model_SetScale3(self->model, 0x1733 - s, s + 0x1733, 0x1733 - s);
        if (t <= 10) {
            return;
        }
        func_020627a0(self->unk_0e, self->unk_0c);
        func_020627dc(4);
        func_020627ec(100);
        data_ov000_021ccd54->unk_ac = 1;
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        Ov003Obj_Destroy(self);
        break;
    }
    }
}

}
}  // namespace m_021e6274

// ---- merged from ov003_021e694c.cpp
namespace m_021e694c {

extern "C" {

extern BOOL func_ov000_02194c08(void *self);
extern void *data_ov000_021ccd64;
extern Ov003PathPt *data_ov003_021f85c0[];
extern void func_ov000_02194758(void *self);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);

void func_ov003_021e68b4(Ov003Obj *self) {
    Ov003Unit *u;
    Ov003PathPt *p;
    func_ov000_02194758(self);
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_5 = 1;
        u->unk_a2_0 = 0;
        u->unk_a2_6 = 0;
    }
    if (self->unk_4c != NULL) {
        self->unk_4c->unk_18_5 = 1;
    }
    self->unk_ce = 0;
    p = data_ov003_021f85c0[self->unk_1a];
    if (p != NULL) {
        self->pos.x = p[self->unk_ce].pos.x;
        self->pos.y = p[self->unk_ce].pos.y;
        self->pos.z = p[self->unk_ce].pos.z;
    }
}



BOOL func_ov003_021e694c(Ov003Obj *self) {
    BOOL r = FALSE;
    if (self->model->unk_be != 0) {
        r = func_ov000_02194c08(self);
    }
    return r;
}

extern Ov003Obj *func_ov000_0219bf90(void);
extern void func_0203f364(Ov003Ctl *ctl);
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_021911c8(void *model, s32 v);
extern void VEC_Normalize(Ov003Vec3 *src, Ov003Vec3 *dst);
extern void VEC_Add(Ov003Vec3 *a, Ov003Vec3 *b, Ov003Vec3 *dst);
extern BOOL func_01ffc198(Ov003Vec3 *a, Ov003Vec3 *b, s32 r);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_0218d918(Ov003Obj *self, Ov003PathPt *pt, s32 a);

void func_ov003_021e6974(Ov003Obj *self) {
    Ov003Obj *pl;
    Ov003PathPt *pt;
    Ov003Work *w;
    s32 snd;
    if (self->unk_ce < 0) {
        return;
    }
    pt = data_ov003_021f85c0[self->unk_1a];
    if (pt == NULL) {
        return;
    }
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        u8 a;
        self->unk_90 = pl->unk_0c;
        a = self->model->unk_be;
        if (pl->unk_93_4) {
            Ov003Sub44 *s = self->unk_44;
            Ov003Ctl *ctl;
            if (s != NULL) {
                s->unk_22_1 = 0;
            }
            ctl = self->ctl;
            if (ctl != NULL) {
                ctl->unk_9a_3 = 0;
                func_0203f364(ctl);
            }
            if (a != 0) {
                self->model->unk_be = a - 1;
            }
        } else if (a < 0x1f) {
            self->model->unk_be = a + 1;
        }
    }
    pt = &pt[self->unk_ce];
    w = self->work;
    switch (w->state) {
    case 0:
        func_ov000_02190cb0(self->model, "nut00", 0x1000, 0);
        func_ov000_021915a0(self->model);
        func_ov000_021911c8(self->model, 0x2800);
        self->unk_4c->unk_1c = 0xffff;
        self->unk_cc_8 = 0;
        self->work->state++;
    case 1: {
        Ov003Vec3 *v = (Ov003Vec3 *)&self->unk_9c;
        s32 sp;
        v->x = pt->pos.x - self->pos.x;
        v->y = pt->pos.y - self->pos.y;
        v->z = pt->pos.z - self->pos.z;
        VEC_Normalize(v, v);
        sp = pt->speed;
        v->x = (s32)(((s64)v->x * sp + 0x800) >> 12);
        v->y = (s32)(((s64)v->y * sp + 0x800) >> 12);
        v->z = (s32)(((s64)v->z * sp + 0x800) >> 12);
        VEC_Add(&self->pos, v, &self->pos);
        if (func_01ffc198(&self->pos, &pt->pos, pt->speed << 3)) {
            self->work->state++;
            self->work->timer = pt->wait;
            self->unk_ce = pt->next;
            func_ov000_021911c8(self->model, 0x1000);
        }
        break;
    }
    case 2: {
        Ov003Vec3 *v = (Ov003Vec3 *)&self->unk_9c;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer == 0) {
            self->work->state = 0;
        }
        v->x = (s32)(((s64)v->x * 0x59a + 0x800) >> 12);
        v->y = (s32)(((s64)v->y * 0x59a + 0x800) >> 12);
        v->z = (s32)(((s64)v->z * 0x59a + 0x800) >> 12);
        VEC_Add(&self->pos, v, &self->pos);
        break;
    }
    }
    snd = 0x133;
    if (self->kind == 2) {
        if (pl != NULL && func_01ffc198(&pl->pos, &self->pos, pl->unk_64 + 0x2000)) {
            func_ov000_02198360(self->work, 0xe, 0);
        }
        snd = 0xcd;
    }
    func_ov000_0218d918(self, pt, snd);
}

}
}  // namespace m_021e694c

// ---- merged from ov003_021e6cb8.cpp
namespace m_021e6cb8 {

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern void *data_ov000_021ccd68;
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern void func_ov000_021911c8(void *model, s32 a);
extern BOOL func_ov000_02191120(void *model);
extern void func_0203f324(Ov003Ctl *ctl);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern Ov003Fx *func_02065f88(s32 id, const Ov003Vec3 *pos);
extern void func_ov000_02195d88(void *self);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern void func_ov000_0218bed8(void *mgr, s32 a, void *obj);
extern Ov003Part *func_ov000_02199ba0(Ov003Part *p);
extern void *func_02049f44(void *mgr, s32 id, Ov003Vec3 *pos, s32 a);
extern s32 func_02040528(s32 max);
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_0218d988(void *self, void *other, s32 a);

static inline void *Ov003_FindObj(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov003_021e6cb8(Ov003Obj *self) {
    switch (self->work->state) {
    case 0: {
        Ov003Ctl *ctl;
        Ov003Fx *fx;
        self->unk_4c->unk_1c = 0xffff;
        func_ov000_02190cb0(self->model, "nut00", 0x1000, 0);
        func_ov000_021915a0(self->model);
        func_ov000_021911c8(self->model, 0x2800);
        ctl = self->ctl;
        if (ctl != NULL) {
            ctl->unk_9a_0 = 1;
            ctl->unk_9a_3 = 1;
            func_0203f324(ctl);
        }
        Ov003Sub44_Set(self->unk_44);
        if (!self->unk_cc_8) {
            func_ov000_02198360(self->work, 1, 0);
            return;
        }
        self->unk_cc_8 = 0;
        fx = func_02065f88(0x322, &self->pos);
        fx->SetRot(0, self->unk_6c, 0);
        fx->SetScale(self->unk_64, self->unk_64, self->unk_64);
        self->work->state++;
        break;
    }
    case 1: {
        Ov003Work *w = self->work;
        w->timer++;
        if (w->timer <= 0x4b) {
            return;
        }
        func_ov000_02198360(self->work, 1, 0);
        break;
    }
    }
}

void func_ov003_021e6e20(Ov003Obj *self) {
    u16 t;
    if (self->work->state == 0) {
        self->unk_d0 = 0;
        func_ov000_021911c8(self->model, 0x5000);
    }
    func_ov000_02195d88(self);
    self->unk_d0++;
    t = self->unk_d0;
    if (t > 0x78) {
        Ov003Part *p;
        u8 k;
        if (self->kind == 1) {
            func_02065f88(0x12f, &self->pos)->SetSpeed(0xa66);
            func_ov000_02197dec(self, 0xf, -1);
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            Ov003Obj_Destroy(self);
            return;
        }
        p = func_ov000_02199ba0(self->unk_4c);
        k = 0;
        if (p != NULL && p->unk_40 != NULL) {
            k = p->unk_40->kind;
        }
        if (k == 0 || k == 1 || k == 2 || k == 4) {
            func_02049f44(data_02097e4c, 0x83, &self->pos, 0);
            func_ov000_02198360(self->work, 10, 0);
        }
        return;
    }
    {
        s32 r = 0x78 - t;
        if (r <= 0x1f && self->kind == 1) {
            self->model->unk_be = r;
            return;
        }
    }
    if (t & 0xf) {
        return;
    }
    {
        Ov003Fx *fx = func_02065f88(0x44d, &self->pos);
        s32 a = func_02040528(0x4cd);
        s32 b = func_02040528(0x4cd);
        fx->SetRot(a, -0x19a, b);
    }
}

void func_ov003_021e6fb4(Ov003Obj *self) {
    switch (self->work->state) {
    case 0:
        func_ov000_02190cb0(self->model, "att00", 0x1000, 0);
        self->work->state++;
    case 1:
        if (func_ov000_02191120(self->model)) {
            func_ov000_02190cb0(self->model, "nut00", 0x19a, 0);
            func_ov000_021915a0(self->model);
            func_ov000_021911c8(self->model, 0xccd);
            self->work->timer = 0;
            self->work->state++;
        } else {
            Ov003Work *w = self->work;
            w->timer++;
            if (w->timer <= 0x50) {
                void *o = Ov003_FindObj(self->unk_90);
                if (o != NULL) {
                    func_ov000_0218d988(self, o, 0x333);
                }
            }
        }
        break;
    case 2: {
        Ov003Work *w = self->work;
        w->timer++;
        if (w->timer > 0x50) {
            func_ov000_02198360(self->work, 1, 0);
        }
        break;
    }
    }
    if (self->unk_cc_8) {
        func_ov000_02198360(self->work, 10, 0);
    }
}

typedef struct {
    u8 a;
    u8 b;
    u8 c;
} Ov003MapId;

typedef struct {
    u8 unk_00[0x772];
    Ov003MapId map;
} Ov003Plyr;

typedef struct {
    u8 unk_00[0xe];
    u16 id;
} Ov003NearObj;

extern Ov003Game54 *data_ov000_021ccd54;
extern Ov003Plyr *func_ov000_0219bf90(void);
extern s32 func_ov000_0219a7bc(void *self, s32 a, Ov003Vec3 *pos, s32 r, s32 b, Ov003NearObj **list);
extern void func_ov000_02196860(void *self);

static inline BOOL Ov003MapId_Equal(const Ov003MapId *a, const Ov003MapId *b) {
    BOOL r = FALSE;
    const u8 *x = (const u8 *)a;
    const u8 *y = (const u8 *)b;
    if (x[0] == y[0] && x[1] == y[1] && x[2] == y[2]) {
        r = TRUE;
    }
    return r;
}

void func_ov003_021e7114(Ov003Obj *self) {
    if (self->work->state == 0 && self->unk_cc_8) {
        Ov003Plyr *p;
        self->unk_cc_8 = 0;
        p = func_ov000_0219bf90();
        if (p != NULL && !Ov003MapId_Equal((Ov003MapId *)&data_ov000_021ccd54->unk_ca, &p->map)) {
            Ov003Vec3 v;
            Ov003NearObj *list[32];
            s32 n;
            s32 i;
            BOOL found;
            v = self->pos;
            v.y -= 0x2800;
            found = FALSE;
            n = func_ov000_0219a7bc(self, 0x10, &v, 0x8000, 0x5000, list);
            if (n != 0) {
                for (i = 0; i < n; i++) {
                    if (list[i] != NULL) {
                        u16 id = list[i]->id;
                        if (id == 0x4008 || id == 0x4022 || id == 0x4031 || id == 0x4014) {
                            found = TRUE;
                            break;
                        }
                    }
                }
            }
            if (found) {
                self->unk_4c->unk_1c = 0xffff;
                func_ov000_02198360(self->work, 1, 0);
                return;
            }
        }
    }
    func_ov000_02196860(self);
}

}
}  // namespace m_021e6cb8
