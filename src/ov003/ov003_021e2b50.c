#include "types.h"

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
extern void func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern s32 func_ov000_0219b808(u16 id, void *pos, Ov003LtHit *entry, u16 *ids, s32 max);
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern BOOL func_ov000_02191120(void *model);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_0204a028(void *mgr, s32 id, void *pos, s32 a);
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

