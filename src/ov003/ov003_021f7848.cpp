#include <nitro/fx.h>

// A header's zero rotation and vector, plus copies made at startup, among this TU's motion
// names, the pointers to them, two angle tables and six vectors. Other functions read the
// pointers, the tables and the named vectors; the unnamed ones are read through offsets.
// The functions after the data, func_ov003_021e83d0 to func_ov003_021ea588, are part of this TU:
// func_ov003_021e83d0 and func_ov003_021ea588 copy data_ov003_021f6ae4 through the .rodata base
// plus an offset. The files in between were merged in, each in its own namespace so that their
// local types and inlines keep their names; their functions are extern "C" either way.
typedef struct {
    s32 a;
    s32 b;
    s32 c;
} Ov003Blk12;

extern const char *const data_ov003_021f6a80;
extern const s16 data_ov003_021f6a96[4];
extern const s16 data_ov003_021f6a9e[5];
extern const Ov003Blk12 data_ov003_021f6aa8;
extern const Ov003Blk12 data_ov003_021f6ab4;
extern const Ov003Blk12 data_ov003_021f6ac0;
extern const VecFx32 data_ov003_021f6acc;
extern const VecFx32 data_ov003_021f6ad8;
extern char data_ov003_021f90e0[];
extern char data_ov003_021f90e6[];
extern char data_ov003_021f90ec[];
extern char data_ov003_021f90f8[];
const s16 data_ov003_021f6a9e[5] = {0x2d, 0x5b, 0xb6, 0x16c, 0x2d8};
static const char *const data_ov003_021f6a88 = data_ov003_021f90e0;
static const char *const data_ov003_021f6a8c = data_ov003_021f90ec;
const VecFx32 data_ov003_021f6ad8 = {0, 0, 0};
const char *const data_ov003_021f6a80 = data_ov003_021f90f8;
static const char *const data_ov003_021f6a84 = data_ov003_021f90e6;
const s16 data_ov003_021f6a96[4] = {0x5b, 0xb6, 0x16c, 0x2d8};
const Ov003Blk12 data_ov003_021f6ab4 = {0xe66, 0xe66, 0xe66};
char data_ov003_021f90f8[] = "act00";
const VecFx32 data_ov003_021f6acc = {0, FX32_ONE, 0};
char data_ov003_021f90e6[] = "run00";
char data_ov003_021f90ec[] = "att00";
const Ov003Blk12 data_ov003_021f6aa8 = {0x2000, 0x1000, 0x2000};
const Ov003Blk12 data_ov003_021f6ac0 = {0x8cd, 0x8cd, 0x8cd};
char data_ov003_021f90e0[] = "nut00";
static const VecFx32 data_ov003_021f6ae4 = {0, 0, 0};
static const VecFx16 data_ov003_021f6a90 = {0, 0, 0};
static const VecFx16 data_ov003_021f90f2 = data_ov003_021f6a90;
static const VecFx32 data_ov003_021f9100 = data_ov003_021f6ae4;

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

typedef struct {
    u16 state;
    u16 timer;
} Ov003Work;

typedef struct {
    u8 unk_00[0x50];
    u16 *input;
    u8 unk_54[0x1c];
    Ov003Vec pos;
} Ov003RtPlayer;

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
extern Ov003Game54 *data_ov000_021ccd54;
extern Ov003RtPlayer *func_ov000_0219bf90(void);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, void *f, void *g, s32 h, s32 i, s32 j, s32 k);

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

BOOL func_ov003_021e83d0(Ov003Rotor *self) {
    BOOL r = FALSE;
    if (func_ov000_0219bf90()->input[0] != 0 && Ov003_Game54Idle()) {
        VecFx32 v;
        Ov003Rot rot;
        u8 i;
        v = data_ov003_021f6ae4;
        v.y = 0x1666;
        rot = self->rot;
        rot.x += 0x4000;
        rot.y += self->angle;
        for (i = 0; i < self->count; i++) {
            r = func_ov000_0219aae8(self, self, self->link->a, self->link->b, 2, &v, &rot, 0x400, 0x3000, 100, 0x1000);
            if (r) {
                return r;
            }
            rot.y += self->step;
        }
    }
    return r;
}
}

// ---- from ov003_021e8544.cpp
namespace m_021e8544 {
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
    u16 state;
    u8 unk_02[0x11];
    u8 unk_13;
} Ov003Work2;

class Ov003SwFx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void SetScale(const Ov003Vec *s);
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void SetPos(const Ov003Vec *p);
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void SetRot(const Ov003Rot *r);
    u8 unk_04[0x20];
    void *handle;
};

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
    Ov003RtLink *link;
    u8 unk_50[0x20];
    Ov003Vec pos;
    Ov003Rot rot;
    u8 unk_82[2];
    Ov003Vec home;
    u8 unk_90[0xc];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x10];
    void *fx;
    Ov003Vec fxPos;
    u8 unk_cc[2];
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
extern void VEC_Add(const Ov003Vec *a, const Ov003Vec *b, Ov003Vec *out);
extern void func_ov000_021903b4(void *anim);
extern Ov003RtPlayer *func_ov000_0219bf90(void);
extern void func_ov000_02190cb0(void *p, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *p);
extern s32 VEC_Distance(const Ov003Vec *a, const Ov003Vec *b);
extern void func_02049f44(void *mgr, s32 id, Ov003Vec *pos, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov003Game54 *data_ov000_021ccd54;
extern const u16 data_ov003_021f6a96[];
extern void *data_0214a420;
extern void func_ov000_02196c40(void *self);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, void *f, void *g, s32 h, s32 i, s32 j, s32 k);
extern void func_ov000_021953b4(void *self);
extern void func_02065804(void *mgr, void *handle);
extern Ov003SwFx *func_02065f88(s32 id, const Ov003Vec *pos);
extern Ov003SwFx *func_020657b0(void *mgr, void *handle);
extern void func_0204a028(void *mgr, s32 id, Ov003Vec *pos, s32 a);
BOOL func_ov003_021e83d0(Ov003Rotor *self);

void func_ov003_021e8544(Ov003Swing *self) {
    Ov003Unit2 *u;
    s16 m;
    func_ov000_02194758(self);
    u = (Ov003Unit2 *)func_ov000_0218bd5c(data_ov000_021ccd64, self->unitId);
    if (u != NULL) {
        u->unk_a2_5 = 1;
        u->unk_a2_6 = 0;
    }
    self->angle = self->rot.y;
    switch (self->kind) {
    case 0:
        self->dir = -1;
        break;
    case 1:
        self->dir = 1;
        break;
    }
    m = self->mode;
    if (m > 3) {
        m = 3;
    }
    self->speed = data_ov003_021f6a96[m];
    self->tiltAngle = self->tilt * 0xb6;
    self->home.x = self->pos.x;
    self->home.y = self->pos.y;
    self->home.z = self->pos.z;
    switch (self->id) {
    case 0x4076:
        self->vals[0] = 0;
        self->vals[1] = 0x12e1;
        self->vals[2] = 0xb33;
        self->vals[3] = 0x1800;
        self->vals[4] = 0x1800;
        self->vals[5] = 0x1800;
        break;
    case 0x4086:
        self->vals[0] = 0;
        self->vals[1] = 0x4cd;
        self->vals[2] = 0x800;
        self->vals[3] = 0x2000;
        self->vals[4] = 0x1000;
        self->vals[5] = 0x2000;
        self->ctl->unk_60 = -0x19a;
        break;
    }
    self->timer = 0;
    func_ov000_02198360(self->work, 1, 0);
}

void func_ov003_021e8698(Ov003Swing *self) {
    func_ov000_021953b4(self);
    if (self->work->unk_13 != 1 && self->fx != NULL) {
        func_02065804(data_0214a420, self->fx);
        self->fx = NULL;
    }
}

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

static inline s32 Ov003_FxMulL(s32 a, s64 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

void func_ov003_021e86d8(Ov003Swing *self) {
    switch (self->work->state) {
    case 0: {
        Ov003SwFx *fx = func_02065f88(0x25a, &self->pos);
        fx->SetRot(&self->rot);
        func_01ffc9fc(&self->fxPos, (Ov003Vec *)&self->vals[0], self->rot.y);
        fx->SetPos(&self->fxPos);
        fx->SetScale((Ov003Vec *)&self->vals[3]);
        self->fx = fx->handle;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->work->state++;
    }
    case 1: {
        Ov003SwFx *fx;
        if (!Ov003_Game54Idle()) {
            return;
        }
        self->pos.x = self->home.x;
        self->pos.y = self->home.y;
        self->pos.z = self->home.z;
        self->rot.y = self->rot.y + self->speed * self->dir;
        if (self->tiltAngle != 0) {
            u16 d = self->rot.y - self->angle;
            if (d >= (self->tiltAngle >> 1) && d <= 0xffff - (self->tiltAngle >> 1)) {
                self->dir = -self->dir;
            }
        }
        if (self->id == 0x4086) {
            self->timer++;
            if (self->timer < 0x5a) {
                self->vals[3] = 0x2000;
                self->vals[4] = 0x1000;
                self->vals[5] = 0x2000;
            } else if (self->timer < 0xfa) {
                self->vals[3] = 0xe66;
                self->vals[4] = 0xe66;
                self->vals[5] = 0xe66;
            } else if (self->timer < 0x118) {
                self->vals[3] = 0x8cd;
                self->vals[4] = 0x8cd;
                self->vals[5] = 0x8cd;
            } else {
                func_0204a028(data_02097e4c, 0x35, &self->pos, -0xc);
                self->timer = 0;
            }
        }
        fx = func_020657b0(data_0214a420, self->fx);
        if (fx != NULL) {
            fx->SetRot(&self->rot);
            fx->SetScale((Ov003Vec *)&self->vals[3]);
            func_01ffc9fc(&self->fxPos, (Ov003Vec *)&self->vals[0], self->rot.y);
        }
        if (*func_ov000_0219bf90()->input == 0) {
            return;
        }
        if (!Ov003_Game54Idle()) {
            return;
        }
        {
            Ov003Rot r;
            r.x = self->rot.x;
            r.y = self->rot.y;
            r.z = self->rot.z;
            r.x += 0x4000;
            func_ov000_0219aae8(self, self, self->link->a, self->link->b, 2, &self->vals[0], &r, Ov003_FxMulL(self->vals[3], 0x19a), Ov003_FxMulL(self->vals[5], 0x3ccd), 600, 0x2800);
        }
        break;
    }
    }
}
}
}

// ---- from ov003_021e8a70.cpp
namespace m_021e8a70 {
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
}

// ---- from ov003_021e8eb0.cpp
namespace m_021e8eb0 {
typedef struct {
    u8 unk_00[0xa2];
    u8 active : 1;
} Ov003Unit;

typedef struct {
    u8 unk_00[0x22];
    u16 enable : 1;
    u16 visible : 1;
} Ov003MvPart;

typedef struct {
    u8 unk_00[0x1a];
    s16 mode;
    u8 unk_1c[4];
    u16 unitId;
    u8 unk_22[0x1e];
    void *work;
    Ov003MvPart *part;
} Ov003Mover2;

struct Ov003Vec {
    s32 x, y, z;
};

struct Ov003GtRot {
    u16 x, y, z;
};

struct Ov003GtWork {
    u16 state;
    u16 timer;
};

struct Ov003GtWork2 {
    u8 unk_00[0x13];
    u8 kind;
};

struct Ov003GtModel {
    void *res;
    u8 unk_04[0xb2];
    u16 unk_b6;
    u16 unk_b8;
    u16 unk_ba;
    u16 unk_bc;
    u8 unk_be[2];
    u8 unk_c0;
    u8 unk_c1;
    u16 unk_c2_0 : 1;
    u16 unk_c2_1 : 1;
};

struct Ov003GtLink {
    u8 unk_00[8];
    u16 a;
    u16 b;
};

struct Ov003GtSub {
    u8 unk_00[0xe];
    u16 type;
};

struct Ov003GtObj {
    u8 unk_00[0xc];
    u16 id;
    u8 unk_0e[0x32];
    Ov003GtWork2 *work;
    u8 unk_44[8];
    void *sub;
};

struct Ov003GtPlayer {
    u8 unk_00[0x50];
    u16 *input;
    u8 unk_54[0x1c];
    Ov003Vec pos;
    u8 unk_7c[0xaa6];
    u16 unk_b22_0 : 6;
    u16 mode : 3;
    u32 unk_b24_0 : 5;
    u32 state : 2;
};

struct Ov003Game54 {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
};

struct Ov003Gate {
    u8 unk_00[0x18];
    s16 count;
    s16 max;
    u8 unk_1c[0x1c];
    Ov003GtModel *model;
    u8 unk_3c[4];
    Ov003GtWork *work;
    u8 unk_44[8];
    Ov003GtLink *link;
    u8 unk_50[0x20];
    Ov003Vec pos;
    Ov003GtRot rot;
    u8 unk_82[0x1a];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x22];
    u16 lastId;
    u16 flash;
};

extern "C" {

extern void *data_ov000_021ccd64;
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_02194758(void *self);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);

void func_ov003_021e8eb0(Ov003Mover2 *self) {
    Ov003Unit *u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unitId);
    Ov003MvPart *p;
    if (u != NULL) {
        u->active = 0;
    }
    func_ov000_02194758(self);
    if (self->mode == 0) {
        self->mode = 3;
    }
    p = self->part;
    p->enable = 0;
    p->visible = 0;
    func_ov000_02198360(self->work, 6, 0);
}

extern const char *const data_ov003_021f6a80[];
extern void *data_02097e4c;
extern Ov003Game54 *data_ov000_021ccd54;
extern void *data_ov000_021ccd68;
extern const Ov003Vec data_ov003_021f6af0;
extern const Ov003Vec data_ov003_021f6b08;
extern Ov003GtPlayer *func_ov000_0219bf90(void);
extern void func_ov000_02190cb0(void *p, const char *name, s32 a, s32 b);
extern void func_ov000_02191690(void *p);
extern void func_ov000_02191708(void *p);
extern void func_ov000_02191318(void *p, s32 a);
extern void func_ov000_0218ffdc(void *anim, void *res, s32 a, s32 b);
extern s32 VEC_Distance(const Ov003Vec *a, const Ov003Vec *b);
extern void VEC_Add(const Ov003Vec *a, const Ov003Vec *b, Ov003Vec *out);
extern void func_02049f44(void *mgr, s32 id, Ov003Vec *pos, s32 a);
extern void func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, const void *f, const void *g, s32 h, s32 i, s32 j, s32 k);
extern void *func_ov000_0218e6d0(void *mgr, s32 a, s32 b);
extern s32 func_ov000_0219a7bc(void *self, s32 a, Ov003Vec *pos, s32 r, s32 b, Ov003GtObj **list);
extern Ov003GtSub *func_ov000_02199ba0(void *p);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov000_0218d46c(Ov003GtObj *o, u16 id, s32 a);

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

static inline void *Ov003_FindActor(s32 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e6d0(data_ov000_021ccd68, 0x5000, id);
}

static inline Ov003GtSub *Ov003GtObj_GetSub(Ov003GtObj *o) {
    Ov003GtSub *s = NULL;
    if (o->sub != NULL) {
        s = func_ov000_02199ba0(o->sub);
    }
    return s;
}

static inline s32 Ov003GtObj_GetKind(Ov003GtObj *o) {
    return o->work != NULL ? o->work->kind : 0;
}

static inline void Ov003Gate_Anim(Ov003Gate *self, s32 a) {
    Ov003GtModel *m = self->model;
    if (m->unk_c0 != a) {
        func_ov000_0218ffdc(m, m->res, a, m->unk_c2_1 ? 1 : 0);
    }
}

void func_ov003_021e8f24(Ov003Gate *self) {
    Ov003GtPlayer *pl = func_ov000_0219bf90();
    switch (self->work->state) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov003_021f6a80[0], 0x1000, 0);
        func_ov000_02191690(self->model);
        self->lastId = 0;
        self->flash = 0;
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
        if (VEC_Distance(&self->pos, &p) > 0x8000) {
            return;
        }
        func_ov000_02191708(self->model);
        func_02049f44(data_02097e4c, 0x46, &self->pos, 0);
        self->work->state++;
        break;
    }
    case 2: {
        Ov003Vec v;
        Ov003GtObj *list[0x20];
        s32 n;
        s32 i;
        pl = func_ov000_0219bf90();
        if (*pl->input != 0 && Ov003_GameIdle()) {
            Ov003GtRot r;
            s32 h = 0x1400;
            r.x = self->rot.x;
            r.y = self->rot.y;
            r.z = self->rot.z;
            r.x += 0x2d80;
            if (pl->mode == 4) {
                h += 0x800;
            }
            func_ov000_0219aae8(self, self, self->link->a, self->link->b, 2, &data_ov003_021f6b08, &r, 0x2000, h, 100, 0x1000);
        }
        if (Ov003_FindActor(0x504a) == NULL && Ov003_FindActor(0x504b) == NULL) {
            func_ov000_02198360(self->work, 0x15, 0);
            return;
        }
        VEC_Add(&data_ov003_021f6af0, &self->pos, &v);
        n = func_ov000_0219a7bc(self, 0x10, &v, 0x299a, 0, list);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                Ov003GtSub *sub;
                if (list[i] == NULL) {
                    continue;
                }
                sub = Ov003GtObj_GetSub(list[i]);
                if (sub == NULL || self->lastId == list[i]->id) {
                    continue;
                }
                if (sub->type != 0x1000) {
                    continue;
                }
                if (Ov003GtObj_GetKind(list[i]) != 0xb) {
                    continue;
                }
                if (func_ov000_0219bf90()->state != 0) {
                    continue;
                }
                self->lastId = list[i]->id;
                func_ov000_0218996c(10, 10);
                func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
                s16 c = self->count + 1;
                self->count = c;
                if (self->max <= c) {
                    func_ov000_02198360(self->work, 0x15, 0);
                } else {
                    Ov003Gate_Anim(self, 1);
                    func_ov000_02190cb0(self->model, data_ov003_021f6a80[0], 0, 1);
                    func_ov000_02191318(self->model, -1);
                    {
                        Ov003GtModel *m = self->model;
                        m->unk_b6 = 0x14bf;
                        m->unk_b8 = 0x739f;
                        m->unk_ba = 0xb;
                        m->unk_bc = 10;
                    }
                    self->flash = 10;
                }
                func_ov000_0218d46c(list[i], self->lastId, 0x15);
                break;
            }
        }
        if (self->flash == 0) {
            return;
        }
        if (self->flash == 1) {
            Ov003Gate_Anim(self, 0);
            func_ov000_02190cb0(self->model, data_ov003_021f6a80[0], 0, 1);
            func_ov000_02191318(self->model, -1);
        }
        self->flash--;
        break;
    }
    }
}

}
}

// ---- from ov003_021e93d8.cpp
namespace m_021e93d8 {
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
}

// ---- from ov003_021e9af4.c
namespace m_021e9af4 {
extern "C" {

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003Vec;

typedef struct {
    s32 m[9];
} Ov003Mtx33;

typedef struct {
    u8 unk_00[0x78];
    Ov003Vec pos;
    u8 unk_84[0x24];
} Ov003SpinModel;

typedef struct {
    u8 unk_00[0x38];
    Ov003SpinModel *model;
    u8 unk_3c[0x34];
    Ov003Vec pos;
    u8 rot[0x17];
    u8 visible : 1;
    u8 unk_94[0x60];
    Ov003Vec offset;
    u8 unk_100[0];
    u16 angle;
} Ov003Spin;

extern void func_ov003_021ea234(Ov003Spin *self, Ov003Mtx33 *m, void *rot, u16 angle);
extern void MI_Copy36B(Ov003Mtx33 *src, void *dst);
extern void VEC_Add(const Ov003Vec *a, const Ov003Vec *b, Ov003Vec *out);
extern BOOL func_ov000_02194c08(void *self);

BOOL func_ov003_021e9af4(Ov003Spin *self) {
    Ov003Mtx33 m;
    Ov003Vec v;
    Ov003SpinModel *model;
    self->visible = 1;
    func_ov003_021ea234(self, &m, self->rot, self->angle);
    MI_Copy36B(&m, self->model->unk_84);
    VEC_Add(&self->offset, &self->pos, &v);
    model = self->model;
    model->pos.x = v.x;
    model->pos.y = v.y;
    model->pos.z = v.z;
    return func_ov000_02194c08(self);
}

}
}

// ---- from ov003_021e9b74.cpp
namespace m_021e9b74 {
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
}

// ---- from ov003_021ea3d0.c
namespace m_021ea3d0 {
extern "C" {

typedef struct {
    u8 unk_00[0x18];
    s16 kind;
    u8 unk_1a[0x26];
    void *work;
} Ov003Spin2;

extern BOOL func_ov000_02194c08(void *self);
extern void func_ov000_02198360(void *p, s32 a, s32 b);

typedef struct {
    s32 m[9];
} Ov003EaMtx;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
} Ov003EaRot;

extern const s16 FX_SinCosTable_[];
extern void MTX_Identity33_(Ov003EaMtx *m);
extern void MTX_RotX33_(Ov003EaMtx *m, s32 s, s32 c);
extern void MTX_RotY33_(Ov003EaMtx *m, s32 s, s32 c);
extern void MTX_RotZ33_(Ov003EaMtx *m, s32 s, s32 c);
extern void MTX_Concat33(Ov003EaMtx *a, Ov003EaMtx *b, Ov003EaMtx *out);

#define OV003EA_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003EA_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

void func_ov003_021ea234(void *self, Ov003EaMtx *m, Ov003EaRot *rot, s32 ang) {
    Ov003EaMtx t;
    BOOL set = FALSE;
    MTX_Identity33_(m);
    if (ang != 0) {
        MTX_RotY33_(m, OV003EA_SIN(ang), OV003EA_COS(ang));
        set = TRUE;
    }
    if (rot->x != 0) {
        if (set) {
            MTX_RotX33_(&t, OV003EA_SIN(rot->x), OV003EA_COS(rot->x));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotX33_(m, OV003EA_SIN(rot->x), OV003EA_COS(rot->x));
            set = TRUE;
        }
    }
    if (rot->z != 0) {
        if (set) {
            MTX_RotZ33_(&t, OV003EA_SIN(rot->z), OV003EA_COS(rot->z));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotZ33_(m, OV003EA_SIN(rot->z), OV003EA_COS(rot->z));
            set = TRUE;
        }
    }
    if (rot->y != 0) {
        if (set) {
            MTX_RotY33_(&t, OV003EA_SIN(rot->y), OV003EA_COS(rot->y));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotY33_(m, OV003EA_SIN(rot->y), OV003EA_COS(rot->y));
            set = TRUE;
        }
    }
}

BOOL func_ov003_021ea3d0(Ov003Spin2 *self) {
    BOOL r = func_ov000_02194c08(self);
    if (self->kind == 1 && r == FALSE) {
        func_ov000_02198360(self->work, 0x15, 0);
    }
    return r;
}

typedef struct {
    s32 x, y, z;
} Ov003EaVec;

typedef struct {
    u8 unk_00[0x10];
    Ov003EaVec pos;
    u8 unk_1c[0x24];
    u16 unk_40;
    u8 unk_42[2];
    u16 unk_44;
} Ov003EaCam;

typedef struct {
    u8 unk_00[0xf4];
    Ov003EaCam cam;
} Ov003EaGame;

typedef struct {
    Ov003EaVec pos;
    u16 angle;
    u8 unk_0e[2];
} Ov003EaSpot;

typedef struct {
    u8 unk_00[0x30];
    s32 unk_30;
    u8 unk_34[0x66];
    u16 unk_9a_0 : 1;
    u16 unk_9a_1 : 2;
    u16 unk_9a_3 : 1;
} Ov003EaCtl;

typedef struct {
    u8 unk_00[0x1a];
    s16 kind;
    u8 unk_1c[0x24];
    void *work;
    u8 unk_44[4];
    Ov003EaCtl *ctl;
    u8 unk_4c[0x24];
    Ov003EaVec pos;
    u16 rot_x;
    u16 rot_y;
    u16 rot_z;
    u8 unk_82[0x16];
    u16 unk_98;
} Ov003EaObj;

extern Ov003EaGame *data_ov000_021ccd54;
extern const Ov003EaSpot data_ov003_021f6b8c[];
extern void func_ov000_02194758(void *self);
extern void func_0203f364(Ov003EaCtl *ctl);
extern u16 func_0204bfa8(Ov003EaCam *cam);
extern s32 func_02040528(s32 n);

static inline s32 Ov003Ea_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline u16 Ov003EaCam_Angle(Ov003EaCam *cam) {
    if (cam->unk_40 != 0) {
        return cam->unk_44;
    }
    return func_0204bfa8(cam);
}

void func_ov003_021ea408(Ov003EaObj *self) {
    Ov003EaCtl *ctl;
    func_ov000_02194758(self);
    ctl = self->ctl;
    ctl->unk_9a_0 = 0;
    ctl->unk_9a_3 = 0;
    func_0203f364(ctl);
    self->ctl->unk_30 = 0;
    if (self->kind == 0) {
        Ov003EaCam *cam = &data_ov000_021ccd54->cam;
        u16 a = Ov003EaCam_Angle(cam);
        a = a + (u16)(func_02040528(3) * 0xb6);
        self->pos.x = cam->pos.x;
        self->pos.y = cam->pos.y;
        self->pos.z = cam->pos.z;
        self->pos.x += Ov003Ea_FxMul(FX_SinCosTable_[(a >> 4) * 2], 0x14000);
        self->pos.z += Ov003Ea_FxMul(FX_SinCosTable_[(a >> 4) * 2 + 1], 0x14000);
        self->pos.y += 0x4000;
    } else {
        const Ov003EaSpot *sp = &data_ov003_021f6b8c[self->kind - 1];
        self->pos.x = sp->pos.x;
        self->pos.y = sp->pos.y;
        self->pos.z = sp->pos.z;
        self->rot_y += (u16)(sp->angle * 0xb6);
    }
    self->unk_98 = self->rot_y;
    func_ov000_02198360(self->work, 6, 0);
}

}
}

// ---- func_ov003_021ea588
namespace m_021ea588 {
extern "C" {
typedef struct { u16 x; u16 y; u16 z; } Ov003EaRot;
typedef struct {
    s32 x, y, z;
} Ov003EaVec;

typedef struct {
    u8 unk_00[0x50];
    u16 *input;
} Ov003EbPlayer;

typedef struct {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
} Ov003EbGame;

typedef struct {
    u8 unk_00[8];
    u16 a;
    u16 b;
} Ov003EbLink;

typedef struct {
    u8 unk_00[0xa8];
    s32 unk_a8;
    s32 unk_ac;
} Ov003EbParam;

typedef struct {
    u8 unk_00[0x18];
    s16 unk_18;
    u8 unk_1a[0x1e];
    Ov003EbParam *param;
    u8 unk_3c[4];
    u16 *work;
    u8 unk_44[8];
    Ov003EbLink *link;
    u8 unk_50[0x20];
    Ov003EaVec pos;
    Ov003EaRot rot;
    u8 unk_82[2];
    Ov003EaVec unk_84;
    u8 unk_90[0xc];
    s32 unk_9c;
    s32 unk_a0;
    u8 unk_a4[4];
    s32 unk_a8;
    u8 unk_ac[0x22];
    s16 unk_ce;
} Ov003EbObj;

extern void *data_02097e4c;
extern void func_ov000_0218dbe0(void *self, s32 a);
extern s32 func_ov000_0219a2f4(Ov003EaVec *v, s32 y, s32 d);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_02049f44(void *mgr, s32 id, Ov003EaVec *pos, s32 a);

static inline s32 Ov003Eb_FxMul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline BOOL Ov003Eb_GameIdle(void) {
    Ov003EbGame *g = (Ov003EbGame *)data_ov000_021ccd54;
    if (g != NULL) {
        BOOL busy = FALSE;
        if (g->unk_90 != g->unk_94) {
            busy = TRUE;
        }
        if (busy) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline void VecCopy_a588(const Ov003EaVec *src, Ov003EaVec *dst) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}

void func_ov003_021ea588(Ov003EbObj *self) {
    s32 y;
    u16 *w = self->work;
    if (w[0] == 0) {
        self->unk_9c = 0x333;
        self->unk_a0 = 0xcd - 0x333;
        self->unk_ce = 0xaab;
        w[1] = 0;
        self->work[0]++;
    }
    func_ov000_0218dbe0(self, 0);
    self->rot.x += self->unk_ce;
    if (((Ov003EbPlayer *)func_ov000_0219bf90())->input[0] != 0 && Ov003Eb_GameIdle()) {
        Ov003EaVec v;
        Ov003EaRot rot;
        s32 a;
        s32 b;
        a = Ov003Eb_FxMul(self->param->unk_ac, 0xccd);
        b = Ov003Eb_FxMul(self->param->unk_a8, 0x24cd);
        v.x = data_ov003_021f6ae4.x;
        v.y = data_ov003_021f6ae4.y;
        v.z = data_ov003_021f6ae4.z;
        v.x = b >> 1;
        rot = self->rot;
        rot.z += 0x4000;
        func_ov000_0219aae8(self, self, self->link->a, self->link->b, 2, &v, &rot, a, b, 100, 0x1000);
    }
    self->unk_ce -= 0x2d;
    if (self->unk_ce < 0x38e) {
        self->unk_ce = 0x38e;
    }
    VecCopy_a588(&self->pos, &self->unk_84);
    if (func_ov000_0219a2f4(&self->unk_84, self->pos.y, -0xa000) == -0x1000) {
        return;
    }
    y = self->unk_84.y + Ov003Eb_FxMul(self->param->unk_ac, 0xccd);
    self->unk_84.y = y;
    if (self->pos.y >= y) {
        return;
    }
    self->pos.y = y;
    self->unk_9c = 0x400;
    self->unk_a0 = 0x19a;
    self->unk_a8 = 0x14;
    self->unk_ce = 0xaab;
    func_ov000_0218996c(5, 5);
    func_02049f44(data_02097e4c, 0x7e, &self->pos, 0);
    if (self->unk_18 == 0) {
        self->unk_18 = 1;
    }
}
}
}
