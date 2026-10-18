#include "types.h"

typedef struct {
    u8 unk_00[0x50];
    u32 flags;
} Ov003MvCtl;

typedef struct {
    u8 unk_00[0xa2];
    u8 active : 1;
    u8 unk_a2_1 : 4;
    u8 solid : 1;
    u8 moving : 1;
} Ov003Unit;

typedef struct {
    u8 unk_00[0x22];
    u16 enable : 1;
    u16 visible : 1;
} Ov003MvPart;

typedef struct {
    s32 x, y, z;
} Ov003Vec;

typedef struct {
    u16 state;
    u16 timer;
} Ov003MvWork;

typedef struct {
    u8 unk_00[0xc4];
    s16 unk_c4;
} Ov003MvModel;

typedef struct {
    u8 unk_00[8];
    u16 a;
    u16 b;
} Ov003MvLink;

class Ov003MvFx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void SetRate(s32 v);
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void SetPos(const Ov003Vec *p);
    u8 unk_04[0x20];
    void *handle;
};

typedef struct {
    u8 unk_00[0x10];
    Ov003Vec pos;
} Ov003MvTarget;

typedef struct {
    u8 unk_00[0xf4];
    Ov003MvTarget target;
} Ov003MvGame;

typedef struct {
    u8 unk_00[0x50];
    u16 *input;
} Ov003MvPlayer;

typedef struct {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
} Ov003Game54;

typedef struct {
    u8 unk_00[0xe];
    u16 id;
    u8 unk_10[8];
    s16 kind;
    s16 mode;
    u8 unk_1c[4];
    u16 unitId;
    u8 unk_22[0x16];
    Ov003MvModel *model;
    u8 unk_3c[4];
    Ov003MvWork *work;
    Ov003MvPart *part;
    Ov003MvCtl *ctl;
    Ov003MvLink *link;
    u8 unk_50[0x20];
    Ov003Vec pos;
    u8 unk_7c[0x20];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x10];
    void *fx;
    u8 unk_c0[0xe];
    u8 type;
    u8 unk_cf;
    s16 wait;
} Ov003Mover;

extern "C" {

extern void *data_ov000_021ccd64;
extern void func_ov000_02196c40(void *self);
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_02194758(void *self);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);
extern s32 func_02040498(s32 max);

void func_ov003_021e8a70(Ov003Mover *self) {
    func_ov000_02196c40(self);
    if (!(self->ctl->flags & 0x60000000)) {
        return;
    }
    func_ov000_02198360(self->work, 0x15, 0);
}

void func_ov003_021e8aa0(Ov003Mover *self) {
    func_ov000_02194758(self);
    switch (self->id) {
    case 0x405c:
    case 0x407b: {
        Ov003Unit *u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unitId);
        if (u != NULL) {
            u->solid = 1;
            u->active = 0;
            u->moving = 0;
        }
        self->type = 0;
        self->wait = self->kind;
        if (self->kind == 0) {
            self->wait = func_02040498(10) + 0x32;
        }
        break;
    }
    case 0x407c:
    case 0x407d:
        self->type = 1;
        break;
    }
    func_ov000_02198360(self->work, 1, 0);
}

extern const char *const data_ov003_021f6a80[];
extern const Ov003Vec data_ov003_021f6ad8;
extern Ov003Game54 *data_ov000_021ccd54;
extern void *data_02097e4c;
extern void *data_0214a420;
extern void func_ov000_02190cb0(void *p, const char *name, s32 a, s32 b);
extern void func_ov000_021911c8(void *p, s32 a);
extern void func_ov000_021915a0(void *p);
extern Ov003MvFx *func_02065f88(s32 id, const Ov003Vec *pos);
extern Ov003MvFx *func_020657b0(void *mgr, void *handle);
extern void func_0204a028(void *mgr, s32 id, Ov003Vec *pos, s32 a);
extern Ov003MvPlayer *func_ov000_0219bf90(void);
extern void func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, const void *f, const void *g, s32 h, s32 i, s32 j, s32 k);

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

static inline void Ov003_SetSqrtImm64(u64 param) {
    *(volatile u64 *)0x040002b8 = param;
}

static inline void Ov003_SetSqrt64(u64 param) {
    *(volatile u16 *)0x040002b0 = 1;
    Ov003_SetSqrtImm64(param);
}

static inline void Ov003_WaitSqrt(void) {
    while (*(volatile u16 *)0x040002b0 & 0x8000) {
    }
}

static inline u32 Ov003_GetSqrtResult32(void) {
    return *(volatile u32 *)0x040002b4;
}

static inline s32 Ov003_Dist2D(s64 sq) {
    Ov003_SetSqrt64((u64)(sq << 2));
    Ov003_WaitSqrt();
    return (s32)(Ov003_GetSqrtResult32() + 1) >> 1;
}

static inline s32 Ov003_DistXZ(const Ov003Vec *a, const Ov003Vec *b) {
    s32 dx = a->x - b->x;
    s32 dz = a->z - b->z;
    s64 sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov003_Dist2D(sq);
}

void func_ov003_021e8b70(Ov003Mover *self) {
    Ov003MvWork *w = self->work;
    switch (w->state) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov003_021f6a80[2], 0x1000, 0);
        if (self->type == 1) {
            func_ov000_021911c8(self->model, self->kind > 0 ? self->kind : 0x1000);
        }
        func_ov000_021915a0(self->model);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->work->timer = 0;
        self->work->state++;
    case 1:
        switch (self->type) {
        case 0:
            w = self->work;
            w->timer++;
            if (w->timer > self->wait) {
                self->work->state++;
            }
            break;
        case 1:
            if (self->model->unk_c4 == 1) {
                self->work->state++;
            }
            break;
        }
        break;
    case 2: {
        Ov003MvFx *fx;
        Ov003MvTarget *t = &((Ov003MvGame *)data_ov000_021ccd54)->target;
        if (t != NULL && Ov003_DistXZ(&t->pos, &self->pos) > 0xa000) {
            self->work->timer = 0;
            self->work->state = 1;
            return;
        }
        fx = func_02065f88(0x130, &self->pos);
        fx->SetPos(&data_ov003_021f6ad8);
        if (self->type == 0) {
            fx->SetRate(0xc00);
        }
        self->fx = fx->handle;
        func_0204a028(data_02097e4c, 0x54, &self->pos, 3);
        self->work->timer = 0;
        self->work->state++;
        break;
    }
    case 3:
        w->timer++;
        if (w->timer > 10 && *func_ov000_0219bf90()->input != 0 && Ov003_GameIdle()) {
            func_ov000_0219aae8(self, self, self->link->a, self->link->b, 2, &data_ov003_021f6ad8, NULL, self->type != 0 ? 0x3000 : 0x2400, 0x1800, 0x25f, 0x2800);
        }
        if (func_020657b0(data_0214a420, self->fx) == NULL) {
            self->fx = NULL;
            self->work->timer = 0;
            self->work->state = 1;
        }
        break;
    }
}

}
