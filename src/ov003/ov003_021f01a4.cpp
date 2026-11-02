#include "types.h"
#include "Main/Math/Rot16.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "Main/Sys/FieldState.h"

typedef struct {
    VecFx32 pos;
    s16 speed;
    s16 next;
} Ov003FxWaypoint;


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
    VecFx32 pos;
    Rot16 rot;
    u8 unk_82[2];
    VecFx32 target;
    u8 unk_90[0xc];
    VecFx32 vel;
    u8 unk_a8[0x14];
    u32 unk_bc;
    u8 unk_c0[0x10];
    VecFx32 basePos;
    s16 unk_dc;
} Ov003FxProp;

extern "C" {

extern void *data_ov000_021ccd64;
extern const Ov003FxEntry data_ov003_021f6fc8[];
extern void func_ov000_02194758(void *self);
extern Ov003FxUnit *Group_FindNode(void *mgr, u16 id);
extern const char data_ov003_021fa1aa[];
extern BOOL func_ov000_02190cb0(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *model);
extern BOOL Hit_DiffInSphere(VecFx32 *a, VecFx32 *b, s32 r);
extern u32 Rand_UpTo(u32 max);
extern s32 func_02049bdc(SndMgr *mgr, s32 a, s32 b);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, VecFx32 *shape, Rot16 *rot, s32 f, s32 g, s32 h, s32 i);

static inline BOOL Ov003FxGame_IsBusy(FieldState *g) {
    BOOL r = g->head != g->tail;
    return r;
}

static inline BOOL Ov003FxGame_IsIdle(FieldState *g) {
    if (Ov003FxGame_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003Fx_GameIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003FxGame_IsIdle(g);
    }
    return TRUE;
}

void Ov003ActVt_021f9fe4_Start(Ov003FxProp *self) {
    Ov003FxUnit *u;
    const Ov003FxEntry *e;
    EffectObj *fx;
    func_ov000_02194758(self);
    u = Group_FindNode(data_ov000_021ccd64, self->unk_20);
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
    self->unk_bc = fx->id;
    fx->SetRot(&self->rot);
    fx->SetScaleAll(e->frame);
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
                    vol += (s16)Rand_UpTo(e->volumeRand);
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
            if (Hit_DiffInSphere(&self->pos, &self->target, e->path[self->unk_dc].speed)) {
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
        Rot16 rot;
        VecFx32 shape;
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
