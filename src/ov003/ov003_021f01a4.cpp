#include "types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov003FxVec;

class Ov003FxObj {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void SetFrame(s32 frame);
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void SetRot(void *rot);
    u8 unk_04[0x20];
    u32 unk_24;
};

typedef struct {
    Ov003FxVec pos;
    s16 speed;
    s16 next;
} Ov003FxWaypoint;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
} Ov003FxRot;

typedef struct {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
    s16 shape[5];
    u16 rot[3];
    s16 effect;
    s16 frame;
    s16 unk_18;
    s16 unk_1a;
    s16 sound;
    s16 volume;
    s16 volumeRand;
    u16 wait;
    Ov003FxWaypoint *path;
} Ov003FxEntry;

typedef struct {
    u16 state;
    u16 timer;
} Ov003FxTask;

typedef struct {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
} Ov003FxGame;

typedef struct {
    u8 unk_00[0xa2];
    u8 unk_a2_0 : 5;
    u8 unk_a2_5 : 1;
} Ov003FxUnit;

typedef struct {
    void *vtbl;
    u8 unk_04[0xa];
    u16 id;
    u8 unk_10[0xa];
    s16 unk_1a;
    u16 unk_1c;
    u16 unk_1e;
    u16 unk_20;
    u8 unk_22[0x16];
    void *model;
    u8 unk_3c[4];
    Ov003FxTask *task;
    u8 unk_44[0x2c];
    Ov003FxVec pos;
    Ov003FxRot rot;
    u8 unk_82[2];
    Ov003FxVec target;
    u8 unk_90[0xc];
    Ov003FxVec vel;
    u8 unk_a8[0x14];
    u32 unk_bc;
    u8 unk_c0[0x10];
    Ov003FxVec basePos;
    s16 unk_dc;
} Ov003FxProp;

extern "C" {

extern void *data_ov000_021ccd64;
extern const Ov003FxEntry data_ov003_021f6fc8[];
extern void func_ov000_02194758(void *self);
extern Ov003FxUnit *func_ov000_0218bd5c(void *mgr, u16 id);
extern Ov003FxObj *func_02065f88(s32 id, Ov003FxVec *pos);
extern Ov003FxGame *data_ov000_021ccd54;
extern void *data_02097e4c;
extern const char data_ov003_021fa1aa[];
extern void func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern void VEC_Add(const Ov003FxVec *a, const Ov003FxVec *b, Ov003FxVec *out);
extern void VEC_Normalize(const Ov003FxVec *a, Ov003FxVec *out);
extern BOOL func_01ffc198(Ov003FxVec *a, Ov003FxVec *b, s32 r);
extern s32 func_02040498(s32 max);
extern void func_02049bdc(void *mgr, s32 a, s32 b);
extern void func_0204a028(void *mgr, s32 id, Ov003FxVec *pos, s32 a);
extern void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, Ov003FxVec *shape, Ov003FxRot *rot, s32 f, s32 g, s32 h, s32 i);

static inline BOOL Ov003FxGame_IsBusy(Ov003FxGame *g) {
    BOOL r = g->unk_90 != g->unk_94;
    return r;
}

static inline BOOL Ov003FxGame_IsIdle(Ov003FxGame *g) {
    if (Ov003FxGame_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003Fx_GameIdle(void) {
    Ov003FxGame *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003FxGame_IsIdle(g);
    }
    return TRUE;
}

void func_ov003_021f01a4(Ov003FxProp *self) {
    Ov003FxUnit *u;
    const Ov003FxEntry *e;
    Ov003FxObj *fx;
    func_ov000_02194758(self);
    u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_5 = 1;
    }
    self->basePos = self->pos;
    self->unk_dc = 1;
    e = &data_ov003_021f6fc8[self->unk_1a];
    if (e->effect == -1) {
        return;
    }
    fx = func_02065f88(e->effect, &self->pos);
    if (fx == NULL) {
        return;
    }
    self->unk_bc = fx->unk_24;
    fx->SetRot(&self->rot);
    fx->SetFrame(e->frame);
}

void func_ov003_021f0258(Ov003FxProp *self) {
    const Ov003FxEntry *e = &data_ov003_021f6fc8[self->unk_1a];
    if (e->path != NULL) {
        Ov003FxTask *task = self->task;
        switch (task->state) {
        case 0:
        case 10: {
            Ov003FxWaypoint *wp;
            s32 spd;
            func_ov000_02190cb0(self->model, data_ov003_021fa1aa, 0x400, 0);
            func_ov000_021915a0(self->model);
            wp = &e->path[self->unk_dc];
            spd = wp->speed;
            self->target = self->basePos;
            if (self->task->state == 0) {
                VEC_Add(&self->target, &wp->pos, &self->target);
            }
            self->vel.x = self->target.x - self->pos.x;
            self->vel.y = self->target.y - self->pos.y;
            self->vel.z = self->target.z - self->pos.z;
            VEC_Normalize(&self->vel, &self->vel);
            self->vel.x = (s32)(((s64)self->vel.x * spd + 0x800) >> 12);
            self->vel.y = (s32)(((s64)self->vel.y * spd + 0x800) >> 12);
            self->vel.z = (s32)(((s64)self->vel.z * spd + 0x800) >> 12);
            if (e->sound >= 0 && Ov003Fx_GameIdle()) {
                s16 vol = e->volume;
                if (e->volumeRand != 0) {
                    vol += (s16)func_02040498(e->volumeRand);
                }
                if (self->id == 0x4048) {
                    func_02049bdc(data_02097e4c, e->sound, vol);
                } else {
                    func_0204a028(data_02097e4c, e->sound, &self->pos, vol);
                }
            }
            self->task->state++;
        }
        case 1:
        case 11:
            VEC_Add(&self->pos, &self->vel, &self->pos);
            if (func_01ffc198(&self->pos, &self->target, e->path[self->unk_dc].speed)) {
                self->pos = self->target;
                self->task->state++;
                self->task->timer = 0;
            }
            break;
        case 2:
        case 12:
            task->timer++;
            if (task->timer > e->wait) {
                self->unk_dc = e->path[self->unk_dc].next;
                if (self->unk_dc == 0) {
                    self->task->state = 10;
                } else {
                    self->task->state = 0;
                }
            } else if (self->task->state == 12 && self->id == 0x4048 && Ov003Fx_GameIdle()) {
                if (self->task->timer % 120 == 30) {
                    func_02049a48(data_02097e4c, 0x3e, 0x28, -1, -1);
                }
            }
            self->vel.x = (s32)(((s64)self->vel.x * 0x80 + 0x800) >> 12);
            self->vel.y = (s32)(((s64)self->vel.y * 0x80 + 0x800) >> 12);
            self->vel.z = (s32)(((s64)self->vel.z * 0x80 + 0x800) >> 12);
            VEC_Add(&self->pos, &self->vel, &self->pos);
            break;
        }
    }
    if (Ov003Fx_GameIdle()) {
        Ov003FxRot rot;
        Ov003FxVec shape;
        rot = self->rot;
        rot.x += e->rot[0];
        rot.y += e->rot[1];
        rot.z += e->rot[2];
        shape.x = e->shape[0] << 4;
        shape.y = e->shape[1] << 4;
        shape.z = e->shape[2] << 4;
        if (func_ov000_0219aae8(self, self, e->unk_00, e->unk_02, 2, &shape, &rot, e->shape[3] << 4, e->shape[4] << 4, e->unk_18, e->unk_1a)) {
            if (e->unk_18 == 6) {
                func_0204a028(data_02097e4c, 0x79, &self->pos, 5);
            }
        }
    }
}

}
