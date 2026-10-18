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
    u8 unk_00[0xa2];
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
};

struct Ov003Fly {
    u8 unk_00[0x20];
    u16 unitId;
    u8 unk_22[0x16];
    void *model;
    u8 unk_3c[4];
    Ov003Work *work;
    u8 unk_44[8];
    Ov003FlyLink *link;
    u8 unk_50[0x20];
    Ov003Vec pos;
    u8 unk_7c[8];
    Ov003Vec home;
    u8 unk_90[0x10];
    s32 speed;
    u8 unk_a4[0x2c];
    Ov003Vec target;
};

extern "C" {

extern void *data_ov000_021ccd64;
extern Ov003Game54 *data_ov000_021ccd54;
extern const Ov003FlyNames data_ov003_021f6a80;
extern u8 data_ov003_021f6b20[];
extern void func_ov000_0219433c(void *self);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_ov000_02194758(void *self);
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_02190cb0(void *p, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *p);
extern void func_ov000_021911c8(void *p, s32 a);
extern s32 func_02040528(s32 max);
extern void func_02012fb8(s32 scale, const Ov003Vec *dir, const Ov003Vec *base, Ov003Vec *out);
extern s32 func_02013068(const Ov003Vec *a, const Ov003Vec *b);
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
        func_02012fb8(0x3d, &d, &self->pos, &self->pos);
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
        if (func_02013068(&self->pos, &pp) >= 0x6000) {
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
}
