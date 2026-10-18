#include "types.h"

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
extern void func_ov000_02198360(void *p, s32 a, s32 b);
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
extern char data_ov003_021f856e[];
extern char data_ov003_021f8574[];
extern void VEC_Normalize(const Ov003Vec3 *a, Ov003Vec3 *out);
extern Ov003SpotUnit *func_ov000_0218bf1c(void *mgr, Ov003SpawnInfo *info, Ov003Vec3 *pos, Ov003Rot3 *rot, u16 a);
extern Ov003SpotUnit *func_ov000_0218e640(void *mgr, u16 id);
extern BOOL func_01ffc198(Ov003Vec3 *a, Ov003Vec3 *b, s32 r);
extern void func_02049f44(void *mgr, s32 id, Ov003Vec3 *pos, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov000_0218d398(Ov003SpotUnit *u, u16 id, u8 type, BOOL notify, u32 size, const void *data);
extern void func_ov000_0218d46c(Ov003SpotUnit *u, u16 id, s32 m);
extern void func_0203f920(void *p);
extern void func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
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
        func_ov000_02190cb0(self->unk_38, data_ov003_021f856e, 0x19a, 0);
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
        func_ov000_02190cb0(self->unk_38, data_ov003_021f8574, 0x111, 0);
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
