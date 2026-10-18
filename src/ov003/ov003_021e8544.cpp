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
