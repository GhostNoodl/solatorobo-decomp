#include "types.h"

struct Ov003Vec {
    s32 x;
    s32 y;
    s32 z;
};

struct Ov003Work {
    u16 state;
    u16 timer;
};

struct Ov003Game54 {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
};

struct Ov003Unit {
    u8 unk_00[0x94];
    u16 unk_94;
    u8 unk_96[0xc];
    u8 unk_a2_0 : 5;
    u8 unk_a2_5 : 1;
};

struct Ov003FlyPlayer {
    u8 unk_00[0x50];
    u16 *input;
    u8 unk_54[0x1c];
    Ov003Vec pos;
};

struct Ov003FlyLink {
    u8 unk_00[8];
    u16 a;
    u16 b;
};

struct Ov003FlyNames {
    const char *names[4];
    u16 rot[3];
};

struct Ov003Fly {
    u8 unk_00[0x1a];
    s16 unk_1a;
    u8 unk_1c[4];
    u16 unitId;
    u8 unk_22[0x16];
    void *model;
    u8 unk_3c[4];
    Ov003Work *work;
    u8 unk_44[8];
    Ov003FlyLink *link;
    u8 unk_50[0x20];
    Ov003Vec pos;
    u16 rotX;
    u16 rotY;
    u16 rotZ;
    u8 unk_82[2];
    Ov003Vec home;
    u8 unk_90[3];
    u8 unk_93;
    u8 unk_94[4];
    u16 unk_98;
    u8 unk_9a[2];
    s32 unk_9c;
    s32 speed;
    u8 unk_a4[0x2c];
    Ov003Vec target;
    Ov003Vec unk_dc;
    Ov003Vec unk_e8;
    u8 unk_f4[0xc];
    u16 unk_100;
    u8 unk_102;
};

struct Ov003FlyParam {
    s32 dist;
    s32 speed;
    u8 unk_08[8];
};

extern "C" {

extern void *data_ov000_021ccd64;
extern Ov003Game54 *data_ov000_021ccd54;
extern const Ov003FlyNames data_ov003_021f6a80;
extern u8 data_ov003_021f6b20[];
extern const Ov003FlyParam data_ov003_021f6b5c[];
extern const s16 FX_SinCosTable_[];
extern void func_01ffc9fc(Ov003Vec *dst, const Ov003Vec *src, u16 angle);
extern void VEC_Add(const Ov003Vec *a, const Ov003Vec *b, Ov003Vec *ab);
extern u16 FX_Atan2(s32 y, s32 x);
extern void func_ov000_0219433c(void *self);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_ov000_02194758(void *self);
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_02190cb0(void *p, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *p);
extern void func_ov000_021911c8(void *p, s32 a);
extern s32 func_02040528(s32 max);
extern void VEC_MultAdd(s32 scale, const Ov003Vec *dir, const Ov003Vec *base, Ov003Vec *out);
extern s32 VEC_Distance(const Ov003Vec *a, const Ov003Vec *b);
extern Ov003FlyPlayer *func_ov000_0219bf90(void);
extern void func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, void *f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern void func_ov000_0218dbe0(void *self, s32 a);

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
    return true;
}

void func_ov003_021e93d8(Ov003Fly *self) {
    Ov003Unit *u;
    func_ov000_0219433c(self);
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unitId);
    if (u != NULL) {
        u->unk_a2_5 = 1;
    }
}

void func_ov003_021e940c(Ov003Fly *self) {
    func_ov000_02194758(self);
    self->home.x = self->pos.x;
    self->home.z = self->pos.z;
    self->home.y = self->pos.y + 0x800;
    func_ov000_02198360(self->work, 1, 0);
}

void func_ov003_021e9448(Ov003Fly *self) {
    Ov003Vec pp;
    Ov003Vec d;
    Ov003Work *w;
    switch (self->work->state) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov003_021f6a80.names[2], 0x89, 0);
        func_ov000_021915a0(self->model);
        self->work->timer = 0;
        self->work->state++;
    case 1: {
        w = self->work;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer == 0) {
            self->work->timer = 0x3c;
            self->target.x = self->home.x;
            self->target.y = self->home.y;
            self->target.z = self->home.z;
            self->target.x += func_02040528(0x800);
            self->target.y += func_02040528(0x800);
            self->target.z += func_02040528(0x800);
        }
        d.x = self->target.x - self->pos.x;
        d.y = self->target.y - self->pos.y;
        d.z = self->target.z - self->pos.z;
        VEC_MultAdd(0x3d, &d, &self->pos, &self->pos);
        break;
    }
    }
    if (!Ov003_GameIdle()) {
        return;
    }
    {
        Ov003FlyPlayer *pl = func_ov000_0219bf90();
        if (pl == NULL) {
            return;
        }
        pp.x = pl->pos.x;
        pp.y = pl->pos.y;
        pp.z = pl->pos.z;
        if (VEC_Distance(&self->pos, &pp) >= 0x6000) {
            return;
        }
    }
    func_ov000_02198360(self->work, 6, 0);
}

void func_ov003_021e9628(Ov003Fly *self) {
    Ov003Work *w = self->work;
    s32 top = self->home.y;
    switch (w->state) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov003_021f6a80.names[3], 0x400, 0);
        func_ov000_021915a0(self->model);
        self->speed = -0x8f;
        self->work->timer = 0;
        self->work->state++;
    case 1:
        if (self->pos.y < top - 0x3000) {
            func_ov000_021911c8(self->model, 0x99a);
            self->work->timer = 0;
            self->work->state++;
        }
        if (*func_ov000_0219bf90()->input != 0 && Ov003_GameIdle()) {
            Ov003FlyLink *l = self->link;
            func_ov000_0219aae8(self, self, l->a, l->b, 2, data_ov003_021f6b20, 0, 0x1c00, 0x800, 0x64, 0x1000);
        }
        break;
    case 2:
        w->timer++;
        if (w->timer <= 0xf) {
            self->speed -= self->speed >> 2;
            break;
        }
        func_ov000_02190cb0(self->model, data_ov003_021f6a80.names[2], 0x89, 0);
        func_ov000_021915a0(self->model);
        self->speed = 0x3d;
        self->work->state++;
        break;
    case 3:
        if (self->pos.y >= top) {
            func_ov000_02198360(w, 1, 0);
        }
        break;
    }
    func_ov000_0218dbe0(self, 0);
}

void func_ov003_021e9824(Ov003Fly *self) {
    Ov003Unit *u;
    func_ov000_0219433c(self);
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unitId);
    if (u != NULL) {
        u->unk_a2_5 = 1;
    }
}

static inline void Ov003_RotX(Ov003Vec *out, const Ov003Vec *in, u16 ang) {
    s32 y = 0;
    s32 z = 0;
    s32 idx = ang >> 4;
    s32 s = FX_SinCosTable_[idx * 2];
    s32 c = FX_SinCosTable_[idx * 2 + 1];
    if (in->y != 0) {
        y += (s32)(((s64)c * in->y + 0x800) >> 12);
        z += (s32)(((s64)s * in->y + 0x800) >> 12);
    }
    if (in->z != 0) {
        y += (s32)(((s64)-s * in->z + 0x800) >> 12);
        z += (s32)(((s64)c * in->z + 0x800) >> 12);
    }
    out->x = in->x;
    out->y = y;
    out->z = z;
}

static inline void Ov003_SetSqrt64(u64 param) {
    *(volatile u16 *)0x040002b0 = 1;
    *(volatile u64 *)0x040002b8 = param;
}

static inline s32 Ov003_Dist2D(s64 sq) {
    Ov003_SetSqrt64((u64)(sq << 2));
    while (*(volatile u16 *)0x040002b0 & 0x8000) {
    }
    return (s32)(*(volatile u32 *)0x040002b4 + 1) >> 1;
}

void func_ov003_021e9858(Ov003Fly *self) {
    const Ov003FlyParam *prm;
    s32 dx, dz;
    s64 sq;
    s32 dist;
    u16 ang;
    s32 idx;
    func_ov000_02194758(self);
    self->unk_93 = 0;
    prm = &data_ov003_021f6b5c[(s16)self->unk_1a];
    self->unk_100 = self->rotY;
    self->target = self->pos;
    Ov003Vec v = {0, 0, 0};
    v.z = prm->dist;
    Ov003_RotX(&v, &v, self->rotX);
    func_01ffc9fc(&v, &v, self->rotY);
    VEC_Add(&v, &self->pos, &v);
    self->unk_dc = v;
    self->unk_e8 = self->target;
    self->home = self->unk_dc;
    self->unk_102 = 0;
    dx = self->pos.x - self->unk_dc.x;
    dz = self->pos.z - self->unk_dc.z;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    dist = Ov003_Dist2D(sq);
    ang = FX_Atan2(dist, self->unk_dc.y - self->pos.y);
    idx = ang >> 4;
    {
    s32 spd = prm->speed;
    self->unk_9c = (s32)(((s64)spd * FX_SinCosTable_[idx * 2] + 0x800) >> 12);
    self->speed = (s32)(((s64)spd * FX_SinCosTable_[idx * 2 + 1] + 0x800) >> 12);
    }
    self->unk_98 = self->rotY;
    self->rotX = data_ov003_021f6a80.rot[0];
    self->rotY = data_ov003_021f6a80.rot[1];
    self->rotZ = data_ov003_021f6a80.rot[2];
    self->rotX = func_ov000_0218bd5c(data_ov000_021ccd64, self->unitId)->unk_94;
    func_ov000_02198360(self->work, 6, 0);
}

}
