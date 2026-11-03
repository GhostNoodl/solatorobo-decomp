#include "types.h"
#include "Main/Math/Rot16.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "Main/Sys/FieldState.h"
#include "Main/Res/StageCmd.h"
#include "ov003/ActEx.h"
#include "ov003/ActorApi.h"


typedef struct {
    u8 unk_00[0x20];
    u8 unk_20[4];
    u8 unk_24[4];
} Ov003BmInfo;

extern "C" {

extern void *data_ov000_021ccd64;
extern u16 Camera_GetYaw(Camera *cam);
extern void Vec_RotateY(VecFx32 *src, VecFx32 *dst, u16 angle);
extern void ActorMgr_BroadcastKind(void *mgr, u16 a, s32 b);
extern Ov003BmInfo *Tbl_Elem_020704b4(u16 id);
extern void Drop_SpawnWeighted(void *a, void *b, s32 c, VecFx32 *pos, Rot16 *rot, s32 d);
extern void Group_UpdateActor(void *mgr, s32 a, void *obj);
extern void *Spawn_ScatterEffect(VecFx32 *pos, VecFx32 *sc, s32 a, s32 b, s32 c, s32 d);
extern void Field_ShakeCamera(u8 a, u8 b);

static inline u16 Camera_GetAngle(Camera *cam) {
    return cam->mode != 0 ? cam->yaw : Camera_GetYaw(cam);
}

void Ov003ActVt_021f8480_State21(Ov003Bomb *self) {
    switch (self->fsm->st) {
    case 0:
        if (self->unk_1a == 0) {
            VecFx32 v;
            EffectObj *fx;
            Camera *cam = &data_ov000_021ccd54->cam.base;
            v.x = -0x2000;
            v.y = 0;
            v.z = 0x5000;
            Vec_RotateY(&v, &v, Camera_GetAngle(cam) + 0x8000);
            VEC_Add(&v, &self->pos, &v);
            fx = Effect_SpawnId(5, &v);
            fx->SetScaleXYZ(0x7800, 0x7800, 0x7800);
            fx->speed = 0xccd;
            fx = Effect_SpawnId(0x6d, &v);
            fx->SetScaleXYZ(0x3000, 0x3000, 0x3000);
            fx->speed = 0x333;
            cam->shakeX = 1;
            cam->shakeY = 1;
            cam->shakeZ = 1;
            cam->shakeTime = 0x19;
            cam->shakeLen = 0x32;
            cam->shakeCur = 0x32;
            SndMgr_PlayAtPitch(data_02097e4c, 0x79, &self->pos, -0xf);
            SndMgr_PlayAt(data_02097e4c, 0x56, &self->pos, 0);
        }
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4030, 0x15);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4031, 0x15);
        self->fsm->timer = 1;
        self->fsm->st++;
        break;
    case 1:
        if (self->fsm->timer >= 0x120) {
            Ov003BmInfo *inf = Tbl_Elem_020704b4(self->kind);
            Drop_SpawnWeighted(inf->unk_20, inf->unk_24, 2, &self->pos, &self->rot, 0);
            func_ov000_02197dec(self, 0xf, 4);
            Group_UpdateActor(data_ov000_021ccd64, 0, self);
            self->vfunc_08();
            return;
        }
        if ((self->fsm->timer & 0xf) == 0) {
            VecFx32 sc;
            s32 a = -1;
            s32 b = 100;
            switch (self->fsm->timer & 0x3f) {
            case 0:
                a = 1;
                break;
            case 0x10:
                break;
            case 0x20:
                a = 3;
                break;
            case 0x30:
                a = 3;
                b = 25;
                break;
            }
            sc.x = 0x5000;
            sc.y = 0x3000;
            sc.z = 0x3800;
            Spawn_ScatterEffect(&self->pos, &sc, 0x1000, 0x2800, a, b);
            Field_ShakeCamera(0xf, 0x1e);
        }
        self->fsm->timer++;
        break;
    }
}

}
