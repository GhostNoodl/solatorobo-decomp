#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003Vec;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
} Ov003Rot;

struct Ov003VecC {
    s32 x;
    s32 y;
    s32 z;
    Ov003VecC() {}
};

typedef struct {
    u16 *input;
} Ov003RtInput;

typedef struct {
    u16 state;
    u16 timer;
} Ov003Work;

typedef struct {
    u8 unk_00[0xa2];
    u8 active : 1;
} Ov003Unit;

typedef struct {
    u8 unk_00[0x50];
    u16 *input;
    u8 unk_54[0x1c];
    Ov003Vec pos;
} Ov003RtPlayer;

typedef struct {
    const char *names[4];
    u8 unk_10[0x54];
    Ov003VecC offset;
} Ov003RtNames;

typedef struct {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
} Ov003Game54;

typedef struct {
    u8 unk_00[0x50];
    u32 flags;
    u8 unk_54[0xc];
    s32 unk_60;
} Ov003RtCtl;

typedef struct {
    u8 unk_00[8];
    u16 a;
    u16 b;
} Ov003RtLink;

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 5;
    u8 unk_a2_5 : 1;
    u8 unk_a2_6 : 1;
} Ov003Unit2;

typedef struct {
    u8 unk_00[0x13];
    u8 unk_13;
} Ov003Work2;

typedef struct {
    u8 unk_00[0xe];
    u16 id;
    u8 unk_10[8];
    s16 kind;
    s16 mode;
    s16 tilt;
    u8 unk_1e[2];
    u16 unitId;
    u8 unk_22[0x1e];
    Ov003Work2 *work;
    u8 unk_44[4];
    Ov003RtCtl *ctl;
    u8 unk_4c[0x24];
    Ov003Vec pos;
    Ov003Rot rot;
    u8 unk_82[2];
    Ov003Vec home;
    u8 unk_90[0x2c];
    void *fx;
    u8 unk_c0[0xe];
    s8 dir;
    u8 unk_cf;
    u16 speed;
    u16 tiltAngle;
    u16 angle;
    u16 timer;
    s32 vals[6];
} Ov003Swing;

typedef struct {
    u8 unk_00[0x18];
    s16 kind;
    s16 mode;
    u8 unk_1c[4];
    u16 unitId;
    u8 unk_22[0x12];
    void *res;
    void *model;
    u8 unk_3c[4];
    Ov003Work *work;
    u8 unk_44[4];
    Ov003RtCtl *ctl;
    Ov003RtLink *link;
    u8 unk_50[0x20];
    Ov003Vec pos;
    Ov003Rot rot;
    u8 unk_82[0x1a];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x20];
    u16 unk_cc_0 : 2;
    u16 spin : 1;
    u8 unk_ce[2];
    u8 anim[0x78];
    Ov003Vec animPos;
    u8 unk_154[0x24];
    Ov003Vec scale;
    u8 unk_184[0xe];
    u16 active : 1;
    u8 unk_194[0x24];
    u8 count;
    u8 unk_1b9;
    u16 speed;
    u16 angle;
    u16 step;
} Ov003Rotor;

extern "C" {

extern void *data_ov000_021ccd64;
extern void *data_02097e4c;
extern const u16 data_ov003_021f6a9e[];
extern const Ov003Vec data_ov003_021f6afc;
extern const Ov003RtNames data_ov003_021f6a80;
extern void func_ov000_0219433c(void *self);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_ov000_02194758(void *self);
extern void func_ov000_0218ffdc(void *anim, void *res, s32 a, s32 b);
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern BOOL func_ov000_02194c08(void *self);
extern void func_ov000_02190758(void *anim, Ov003Rot *rot, s32 a);
extern void func_01ffc9fc(Ov003Vec *dst, const Ov003Vec *src, u16 angle);
extern void func_02012be8(const Ov003Vec *a, const Ov003Vec *b, Ov003Vec *out);
extern void func_ov000_021903b4(void *anim);
extern Ov003RtPlayer *func_ov000_0219bf90(void);
extern void func_ov000_02190cb0(void *p, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *p);
extern s32 func_02013068(const Ov003Vec *a, const Ov003Vec *b);
extern void func_02049f44(void *mgr, s32 id, Ov003Vec *pos, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov003Game54 *data_ov000_021ccd54;
extern const u16 data_ov003_021f6a96[];
extern void *data_0214a420;
extern void func_ov000_02196c40(void *self);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, void *f, void *g, s32 h, s32 i, s32 j, s32 k);
extern void func_ov000_021953b4(void *self);
extern void func_02065804(void *mgr, void *handle);
BOOL func_ov003_021e83d0(Ov003Rotor *self);

extern s32 **func_ov000_02190a30(void *model, s32 a);

static inline BOOL Ov003Game54_IsBusy(Ov003Game54 *g) {
    return g->unk_90 != g->unk_94;
}

static inline BOOL Ov003Game54_IsIdle(Ov003Game54 *g) {
    if (Ov003Game54_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_Game54Idle(void) {
    Ov003Game54 *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game54_IsIdle(g);
    }
    return TRUE;
}

BOOL func_ov003_021e7ee4(Ov003Rotor *self) {
    Ov003Rot rot;
    Ov003Vec v;
    s32 d;
    s32 t;
    s32 *p;
    if (func_ov000_0219bf90()->input[0] != 0 && Ov003_Game54Idle()) {
        rot = self->rot;
        rot.x += 0x4000;
        d = 0;
        p = *func_ov000_02190a30(self->model, 0);
        if (p != NULL) {
            d = *p;
        }
        if (d > 0x32000) {
            d = 0x64000 - d;
        }
        t = d - 0x19000;
        v.x = (t >> 1) - (t >> 3) + 0x1800;
        v.y = 0x3333;
        v.z = -0x667;
        return func_ov000_0219aae8(self, self, self->link->a, self->link->b, 2, &v, &rot, 0x3333 - 0x1000, 0x4000 - 0x3333, 100, 0x1000);
    }
    return FALSE;
}

void func_ov003_021e8030(Ov003Rotor *self) {
    Ov003Unit *u;
    func_ov000_0219433c(self);
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unitId);
    if (u != NULL) {
        u->active = 0;
    }
}

void func_ov003_021e8064(Ov003Rotor *self) {
    s16 m;
    func_ov000_02194758(self);
    func_ov000_0218ffdc(self->anim, self->res, 1, 0);
    self->scale.x = 0x1000;
    self->active = 0;
    self->count = self->kind;
    self->scale.y = 0x1000;
    self->scale.z = 0;
    if (self->count == 0) {
        self->count = 1;
    } else if (self->count > 3) {
        self->count = 3;
    }
    m = self->mode;
    if (m > 4) {
        m = 4;
    }
    self->speed = data_ov003_021f6a9e[m];
    self->angle = 0;
    self->step = 0x10000 / self->count;
    self->spin = 1;
    func_ov000_02198360(self->work, 1, 0);
}

BOOL func_ov003_021e812c(Ov003Rotor *self) {
    BOOL r = func_ov000_02194c08(self);
    if (r) {
        Ov003Rot rot;
        Ov003Vec v;
        u8 i;
        rot.x = self->rot.x;
        rot.y = self->rot.y;
        rot.z = self->rot.z;
        rot.y += self->angle;
        for (i = 0; i < self->count; i++) {
            func_ov000_02190758(self->anim, &rot, 0);
            func_01ffc9fc(&v, &data_ov003_021f6afc, rot.y);
            func_02012be8(&self->pos, &v, &v);
            self->animPos.x = v.x;
            self->animPos.y = v.y;
            self->animPos.z = v.z;
            func_ov000_021903b4(self->anim);
            rot.y += self->step;
        }
    }
    return r;
}

void func_ov003_021e8210(Ov003Rotor *self) {
    Ov003RtPlayer *pl = func_ov000_0219bf90();
    Ov003Work *w = self->work;
    switch (w->state) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov003_021f6a80.names[2], 0x1000, 0);
        func_ov000_021915a0(self->model);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->work->state++;
    case 1: {
        Ov003Vec p;
        p.x = pl->pos.x;
        p.y = pl->pos.y;
        p.z = pl->pos.z;
        p.y = self->pos.y;
        if (func_02013068(&self->pos, &p) >= 0x5800) {
            return;
        }
        func_02049f44(data_02097e4c, 0x71, &self->pos, 0);
        self->active = 1;
        self->work->state++;
        break;
    }
    case 2: {
        s32 s = self->scale.z;
        if (s >= 0x1000) {
            return;
        }
        s += 0x11f;
        if (s >= 0x1000) {
            s = 0x1000;
            func_ov000_0218996c(4, 4);
            func_02049f44(data_02097e4c, 0x66, &self->pos, 0);
            self->work->state++;
        }
        self->scale.x = s;
        self->scale.y = s;
        self->scale.z = s;
        break;
    }
    case 3:
        self->angle += self->speed;
        func_ov003_021e83d0(self);
        break;
    }
}

void func_ov003_021e83a0(Ov003Rotor *self) {
    func_ov000_02196c40(self);
    if (!(self->ctl->flags & 0x60000000)) {
        return;
    }
    func_ov000_02198360(self->work, 0x15, 0);
}

}
