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

struct Ov003SnParam {
    u8 unk_00[0x8];
    u16 unk_08;
    u16 unk_0a;
};

struct Ov003SnSys {
    u8 unk_00[0x50];
    u16 *unk_50;
};

struct Ov003Sensor {
    u8 unk_00[0x18];
    s16 kind;
    u8 unk_1a[0x1e];
    void *model;
    u8 unk_3c[4];
    Ov003Work *work;
    u8 unk_44[0x8];
    Ov003SnParam *param;
    u8 unk_50[0x14];
    s32 unk_64;
    s32 unk_68;
    u8 unk_6c[4];
    Ov003Vec pos;
    u8 unk_7c[0x20];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x22];
    u16 wait;
};

struct Ov003SnModel {
    u8 unk_00[0xc4];
    s16 unk_c4;
};

struct Ov003VecA {
    s32 v[3];
};

struct Ov003Rot {
    u16 x, y, z;
};

struct Ov003Cannon {
    u8 unk_00[0x38];
    Ov003SnModel *model;
    u8 unk_3c[4];
    Ov003Work *work;
    u8 unk_44[0x8];
    Ov003SnParam *param;
    u8 unk_50[0x20];
    Ov003Vec pos;
    Ov003Rot rot;
    u8 unk_82[0x1a];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x22];
    s8 idx;
    u8 unk_cf;
    s16 dur;
};

struct Ov003RtModel {
    u8 unk_00[0xc2];
    u16 unk_c2_0 : 4;
    u16 unk_c2_4 : 1;
    s16 unk_c4;
};

struct Ov003Rotor {
    u8 unk_00[0x1a];
    s16 mode;
    u8 unk_1c[0x1c];
    Ov003RtModel *model;
    u8 unk_3c[4];
    Ov003Work *work;
    u8 unk_44[0x2c];
    Ov003Vec pos;
    u8 unk_7c[0x20];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
};

extern "C" {

extern Ov003Game54 *data_ov000_021ccd54;
extern const char *const data_ov003_021f6a80[];
extern void func_ov000_02194758(void *self);
extern BOOL func_ov000_02198360(void *p, s32 a, s32 b);
extern BOOL func_ov000_02190cb0(void *p, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *p);
extern void func_ov000_021911c8(void *model, s32 a);
BOOL func_ov003_021e7ee4(Ov003Rotor *self);
extern s32 func_ov000_0219a510(void *self, s32 a, Ov003Vec *pos, s32 b, s32 c, void **list);
extern BOOL func_ov000_021985c0(void *p);
extern Ov003SnSys *func_ov000_0219bf90(void);
extern const Ov003Vec data_ov003_021f6b44[];
extern void *data_02097e4c;
extern void func_01ffc9fc(Ov003Vec *src, Ov003Vec *dst, u16 angle);
extern void VEC_Add(const Ov003Vec *a, const Ov003Vec *b, Ov003Vec *out);
extern void *func_02049f44(void *mgr, s32 id, Ov003Vec *pos, s32 a);
extern BOOL func_ov000_02191120(void *p);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, const void *f, const void *g, s32 h, s32 i, s32 j, s32 k);

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

void func_ov003_021e7780(Ov003Sensor *self) {
    func_ov000_02194758(self);
    self->wait = self->kind;
    if (self->kind == 0) {
        self->wait = 0x64;
    }
    func_ov000_02198360(self->work, 1, 0);
}

void func_ov003_021e77b4(Ov003Sensor *self) {
    void *list[0x20];
    s32 n;
    s32 i;
    switch (self->work->state) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov003_021f6a80[2], 0x1000, 0);
        func_ov000_021915a0(self->model);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->work->state++;
    case 1:
        if (!Ov003_GameIdle()) {
            return;
        }
        n = func_ov000_0219a510(self, 2, &self->pos, self->unk_64, self->unk_68, list);
        if (n == 0) {
            return;
        }
        for (i = 0; i < n; i++) {
            if (list[i] != NULL && func_ov000_021985c0(list[i])) {
                func_ov000_02198360(self->work, 6, 0);
                return;
            }
        }
        break;
    }
}

void func_ov003_021e7900(Ov003Sensor *self) {
    Ov003Work *w = self->work;
    switch (w->state) {
    case 0:
        if (!Ov003_GameIdle()) {
            func_ov000_02198360(w, 1, 0);
            return;
        }
        w->timer++;
        if (w->timer > (s16)self->wait) {
            func_ov000_02190cb0(self->model, data_ov003_021f6a80[3], 0x1000, 0);
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->work->timer = 0;
            self->work->state++;
        }
        break;
    case 1:
        w->timer++;
        if (w->timer > 0x40 && *func_ov000_0219bf90()->unk_50 != 0 && Ov003_GameIdle()) {
            func_ov000_0219aae8(self, self, self->param->unk_08, (u8)self->param->unk_0a, 2, 0, 0, self->unk_64, self->unk_68, 100, 0x1000);
        }
        if (func_ov000_02191120(self->model)) {
            self->work->timer = 0;
            self->work->state++;
        }
        break;
    case 2:
        w->timer++;
        if (w->timer > 0xf) {
            func_ov000_02190cb0(self->model, data_ov003_021f6a80[2], 0x111, 0);
            self->work->timer = 0;
            self->work->state = 0x1e;
        }
        break;
    case 0x1e:
        w->timer++;
        if (w->timer > 0x78) {
            func_ov000_02198360(self->work, 1, 0);
        }
        break;
    }
}

void func_ov003_021e7bac(Ov003Cannon *self) {
    switch (self->work->state) {
    case 0:
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        func_ov000_02190cb0(self->model, data_ov003_021f6a80[2], 0x1000, 0);
        func_ov000_021915a0(self->model);
        self->idx = -1;
        self->work->state++;
        break;
    case 1: {
        Ov003Vec v;
        switch (self->model->unk_c4) {
        case 1:
            self->idx = 0;
            self->dur = 0x32;
            break;
        case 2:
            self->idx = 1;
            self->dur = 0x28;
            break;
        }
        if (self->idx == -1) {
            return;
        }
        *(Ov003VecA *)&v = ((const Ov003VecA *)data_ov003_021f6b44)[self->idx];
        func_01ffc9fc(&v, &v, self->rot.y);
        VEC_Add(&v, &self->pos, &v);
        func_02049f44(data_02097e4c, 0x50, &v, 0);
        self->work->state++;
        break;
    }
    case 2: {
        Ov003Work *w;
        if (*func_ov000_0219bf90()->unk_50 != 0 && Ov003_GameIdle()) {
            Ov003Rot r;
            r = self->rot;
            r.x += 0x4000;
            func_ov000_0219aae8(self, self, self->param->unk_08, (u8)self->param->unk_0a, 2, &data_ov003_021f6b44[self->idx], &r, 0x14cd, 0x3800, 100, 0x1000);
        }
        w = self->work;
        w->timer++;
        if (w->timer > self->dur) {
            self->idx = -1;
            self->work->timer = 0;
            self->work->state = 1;
        }
        break;
    }
    }
}

void func_ov003_021e7e18(Ov003Rotor *self) {
    switch (self->work->state) {
    case 0:
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        func_ov000_02190cb0(self->model, data_ov003_021f6a80[2], 0x1000, 0);
        func_ov000_021911c8(self->model, self->mode > 0 ? self->mode : 0x1000);
        func_ov000_021915a0(self->model);
        self->model->unk_c2_4 = 0;
        self->work->state++;
    case 1: {
        s32 k = self->model->unk_c4;
        if (!(k != 1 && k != 2)) {
            func_02049f44(data_02097e4c, 0x65, &self->pos, 0);
        }
        func_ov003_021e7ee4(self);
        break;
    }
    }
}
}
