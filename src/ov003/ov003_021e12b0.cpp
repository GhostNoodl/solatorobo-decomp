#include "types.h"

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
