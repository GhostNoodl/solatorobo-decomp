#include "types.h"

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
extern char data_ov003_021f857a[];
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
        STD_ConcatenateString(buf, data_ov003_021f857a);
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
extern void func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
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
extern void func_0204a028(void *mgr, s32 id, void *pos, s32 a);
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
