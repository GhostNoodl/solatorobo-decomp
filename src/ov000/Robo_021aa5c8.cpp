#include "ov000/LoCommon.h"
#include "ov000/ActorMgr.h"
#include "Main/Sys/FieldState.h"
#include "Main/Math/Rot16.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 rest : 3;
} Bits8021aa5c8;

typedef struct {
    u8 lo : 4;
    u8 hi : 4;
} Nib021aa5c8;

extern "C" {

extern FieldId data_ov000_021c9fe8;
extern void *data_02097e4c;
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
void func_ov003_021cedf4(u16 n);
s32 Rand_UpTo(s32 max);
s32 func_02049bdc(void *a, s32 b, s32 c);
void func_ov000_021aa978(u8 *self);
void func_ov000_021aaf80(u8 *self);
void func_ov000_021ab68c(u8 *self);
void func_ov000_0218a358(FieldCam *self, const VecFx32 *pos, const Rot16 *rot, s32 dist, u8 clamp, s16 a6, s16 a7, u8 a8);
BOOL func_ov000_02198360(void *s, s32 a, s32 b);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);

static inline Actor *FindActor021aa5c8(u16 id) {
    ActorMgr *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(mgr, id);
}

static inline BOOL FieldId_Eq(FieldId *a, FieldId b) {
    BOOL r = FALSE;
    if (a->c[0] == b.c[0] && a->c[1] == b.c[1] && a->c[2] == b.c[2]) {
        r = TRUE;
    }
    return r;
}

static inline s32 FxMulL021aa5c8(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

void func_ov000_021aa5c8(Robo021ca458 *self) {
    Actor *actor;
    ActorSub4c *sub;
    FieldState *g;
    VecFx32 d;
    VecFx32 out;
    actor = FindActor021aa5c8(self->unk_b1c);
    sub = NULL;
    if (actor != NULL) {
        sub = (ActorSub4c *)((u8 *)actor->targetObj);
    }
    g = data_ov000_021ccd54;
    if (self->fsm->st == 0) {
        EffectObj *e = func_02065f88(0x391, &self->pos);
        e->AddPosXYZ(0, self->height - (self->height >> 2), 0);
        e->SetScaleXYZ(0x159a, 0x159a, 0x159a);
        e->speed = 0x4000;
        g->cam.base.shakeX = 1;
        g->cam.base.shakeY = 1;
        g->cam.base.shakeZ = 1;
        g->cam.base.shakeTime = 8;
        g->cam.base.shakeLen = 6;
        g->cam.base.shakeCur = 6;
        func_02049a48(data_02097e4c, 0x44, -1, -1, -1);
        func_02049a48(data_02097e4c, 0x30c, -1, -1, -1);
        if (!self->unk_b22_3) {
            u16 n = 0x14;
            if (sub != NULL) {
                n += (u16)(sub->unk_1a * 2);
            }
            if (self->unk_ba4 != NULL) {
                n += LFLD(Nib021aa5c8, self->unk_ba4, 5).hi;
            }
            func_ov003_021cedf4(n);
        }
        if (FieldId_Eq(&data_ov000_021ccd54->unk_ca, data_ov000_021c9fe8)) {
            func_02049bdc(data_02097e4c, 0x5e, Rand_UpTo(3));
        }
    }
    if (self->unk_b2c_0) {
        func_ov000_021aa978((u8 *)self);
    } else if (self->unk_b2c_1) {
        func_ov000_021aaf80((u8 *)self);
    } else if (self->unk_b2c_2) {
        func_ov000_021ab68c((u8 *)self);
    }
    if (self->fsm->st <= 1 && sub != NULL && !(sub->unk_18_4 ? TRUE : FALSE)) {
        d = actor->pos;
        d.x -= self->pos.x;
        d.y -= self->pos.y;
        d.z -= self->pos.z;
        d.x = FxMulL021aa5c8(d.x, 0x733);
        d.y = FxMulL021aa5c8(d.y, 0x733);
        d.z = FxMulL021aa5c8(d.z, 0x733);
        d.y = self->centerY;
        VEC_Add(&d, (VecFx32 *)((u8 *)self + 0x70), &out);
        func_ov000_0218a358(&g->cam, &out, NULL, actor->radius + 0x8c00, 1, 0x2333, 0x1000, 1);
    }
    if (self->fsm->current != 0x11) {
        return;
    }
    if (self->unk_b2c_0 || self->unk_b2c_1 || self->unk_b2c_2) {
        return;
    }
    func_ov000_02198360(self->fsm, 1, 0);
}

}
