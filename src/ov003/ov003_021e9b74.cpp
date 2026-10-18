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

struct Ov003FlyPlayer {
    u8 unk_00[0x50];
    u16 *input;
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

struct Ov003FlyModel {
    u8 unk_00[0xa8];
    s32 unk_a8;
    u8 unk_ac[0x18];
    s16 unk_c4;
};

struct Ov003Fly {
    u8 unk_00[0x1a];
    s16 unk_1a;
    u8 unk_1c[0x1c];
    Ov003FlyModel *model;
    u8 unk_3c[4];
    Ov003Work *work;
    u8 unk_44[8];
    Ov003FlyLink *link;
    u8 unk_50[0x14];
    s32 unk_64;
    u8 unk_68[8];
    Ov003Vec pos;
    u16 rotX;
    u16 rotY;
    u16 rotZ;
    u8 unk_82[2];
    Ov003Vec home;
    u8 unk_90[0xc];
    s32 unk_9c;
    s32 speed;
    u8 unk_a4[0x2c];
    Ov003Vec target;
    Ov003Vec unk_dc;
    Ov003Vec unk_e8;
    Ov003Vec unk_f4;
    u16 unk_100;
    u8 unk_102;
};

struct Ov003FlyParam {
    s32 dist;
    s32 speed;
    s32 unk_08;
    u16 unk_0c;
};

extern "C" {

extern Ov003Game54 *data_ov000_021ccd54;
extern void *data_02097e4c;
extern const Ov003FlyNames data_ov003_021f6a80;
extern const Ov003FlyParam data_ov003_021f6b5c[];
extern const Ov003Vec data_ov003_021f6acc;
extern const s16 FX_SinCosTable_[];
extern void func_01ffc9fc(Ov003Vec *dst, const Ov003Vec *src, u16 angle);
extern void VEC_Add(const Ov003Vec *a, const Ov003Vec *b, Ov003Vec *ab);
extern void func_ov000_02190cb0(void *p, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *p);
extern s32 VEC_Distance(const Ov003Vec *a, const Ov003Vec *b);
extern Ov003FlyPlayer *func_ov000_0219bf90(void);
extern void func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, void *f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern void func_ov000_0218dbe0(void *self, s32 a);
extern void func_ov000_0218d918(void *self, const Ov003Vec *v, s32 a);
extern void func_0204a028(void *mgr, s32 id, const Ov003Vec *pos, s32 a);

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

static inline void Ov003_RotZ(Ov003Vec *out, const Ov003Vec *in, u16 ang) {
    s32 x = 0;
    s32 y = 0;
    s32 idx = ang >> 4;
    s32 s = FX_SinCosTable_[idx * 2];
    s32 c = FX_SinCosTable_[idx * 2 + 1];
    if (in->y != 0) {
        y += (s32)(((s64)c * in->y + 0x800) >> 12);
        x += (s32)(((s64)-s * in->y + 0x800) >> 12);
    }
    if (in->x != 0) {
        y += (s32)(((s64)s * in->x + 0x800) >> 12);
        x += (s32)(((s64)c * in->x + 0x800) >> 12);
    }
    out->x = x;
    out->y = y;
    out->z = in->z;
}

static inline void Ov003_RotZ2(Ov003Vec *out, const Ov003Vec *in, u16 ang) {
    s32 y = 0;
    s32 x = 0;
    s32 idx = ang >> 4;
    s32 s = FX_SinCosTable_[idx * 2];
    s32 c = FX_SinCosTable_[idx * 2 + 1];
    if (in->y != 0) {
        y += (s32)(((s64)c * in->y + 0x800) >> 12);
        x += (s32)(((s64)-s * in->y + 0x800) >> 12);
    }
    if (in->x != 0) {
        y += (s32)(((s64)s * in->x + 0x800) >> 12);
        x += (s32)(((s64)c * in->x + 0x800) >> 12);
    }
    out->x = x;
    out->y = y;
    out->z = in->z;
}

void func_ov003_021e9b74(Ov003Fly *self) {
    const Ov003FlyParam *prm = &data_ov003_021f6b5c[self->unk_1a];
    switch (self->work->state) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov003_021f6a80.names[1], 0x1000, 0);
        func_ov000_021915a0(self->model);
        self->work->timer = 0;
        self->work->state++;
    case 1:
        self->rotZ += prm->unk_0c;
        func_ov000_0218dbe0(self, 0);
        if (VEC_Distance(&self->pos, &self->unk_e8) >= prm->dist) {
            self->unk_e8 = self->home;
            self->home = (&self->target)[self->unk_102];
            self->unk_9c = -self->unk_9c;
            self->speed = -self->speed;
            func_ov000_02190cb0(self->model, data_ov003_021f6a80.names[2], 0x400, 0);
            func_ov000_021915a0(self->model);
            self->work->state++;
        }
        break;
    case 2: {
        Ov003Vec d;
        Ov003Work *w;
        d.x = self->home.x - self->unk_e8.x;
        d.y = self->home.y - self->unk_e8.y;
        d.z = self->home.z - self->unk_e8.z;
        func_01ffc9fc(&d, &d, -self->unk_100);
        VEC_Add(&d, &self->unk_e8, &d);
        func_ov000_0218d918(self, &d, 0x200);
        w = self->work;
        w->timer++;
        if (w->timer == 100) {
            self->unk_102 = self->unk_102 ? 0 : 1;
            self->work->state = 0;
        }
        break;
    }
    }
    Ov003Vec v = {0, 0, 0};
    v.y = prm->unk_08;
    Ov003_RotZ(&v, &v, self->rotZ);
    Ov003_RotX(&v, &v, self->rotX);
    func_01ffc9fc(&self->unk_f4, &v, self->unk_100);
    if (*func_ov000_0219bf90()->input != 0 && Ov003_GameIdle()) {
        Ov003Vec save = self->pos;
        Ov003Vec o = data_ov003_021f6acc;
        Ov003FlyLink *l;
        Ov003_RotZ2(&o, &o, self->rotZ);
        Ov003_RotX(&o, &o, self->rotX);
        func_01ffc9fc(&o, &o, self->unk_100);
        VEC_Add(&o, &self->unk_f4, &o);
        VEC_Add(&self->pos, &o, &self->pos);
        l = self->link;
        func_ov000_0219aae8(self, self, l->a, l->b, 2, NULL, 0, (s32)(((s64)self->model->unk_a8 * self->unk_64 + 0x800) >> 12), 0, 100, 0x1000);
        self->pos = save;
    }
    if (!Ov003_GameIdle()) {
        return;
    }
    if (self->model->unk_c4 != 1) {
        return;
    }
    func_0204a028(data_02097e4c, 0x48, &self->pos, -0xf);
}

}
