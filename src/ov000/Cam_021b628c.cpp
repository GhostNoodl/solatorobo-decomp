#include "types.h"
#include "ov000/FieldMgr.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "nitro/fx.h"

class Cam021b628c {
public:
    virtual void vfunc_00();
};

extern "C" {

FieldExit *LangBlockB_GetData0(LangBlockB *b);
FieldStart *LangBlockB_GetData(LangBlockB *b);
BOOL Shared_HasMark_02062698(void);
void Shared_GetMarkPos(VecFx32 *pos);
u16 Shared_GetMarkRot(void);
void Shared_ClearMark(void);
BOOL Shared_HasPendingPos(void);
void Shared_TakePendingPos(VecFx32 *v);
BOOL Shared_HasPendingCamPitch(void);
u16 Shared_TakePendingCamPitch(void);
BOOL Shared_HasPendingCamYaw(void);
u16 Shared_TakePendingCamYaw(void);
BOOL Shared_HasPendingCamDist(void);
s32 Shared_TakePendingCamDist(void);
Robo021ca458 *ActorMgr_FindPlayer(void);
void Robo021ca458_SetPosRot(Robo021ca458 *pl, VecFx32 *pos, u16 *rot);
void TouchQuad_Init(void *q, u16 a, u16 b, u16 c, u16 d);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);

static inline void SetRot021b628c(u16 *r, u16 x, u16 y, u16 z) {
    r[0] = x;
    r[1] = y;
    r[2] = z;
}

class Pl021b628c {
public:
    virtual void vfunc_00();
    virtual void vfunc_04();
    virtual void vfunc_08();
    virtual void vfunc_0c();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
};

void FieldMgr_PlacePlayerAtExit(FieldMgr *self) {
    VecFx32 pos;
    VecFx32 t;
    u16 rot[3];
    FieldCam *cam;
    Robo021ca458 *pl;
    LangBlockB *r;
    u8 idx = self->destExit;

    self->exit = 0xff;
    self->destExit = 0xff;
    self->curExit = idx;
    if (idx != 0xff && self->blockB != NULL && self->blockB->count0 != 0) {
        FieldExit *items = LangBlockB_GetData0(self->blockB);
        if (items != NULL) {
            FieldExit *it = &items[self->curExit];
            pos.x = it->ox << 4;
            pos.y = it->oy << 4;
            pos.z = it->oz << 4;
            VEC_Add(&pos, &it->pos, &pos);
        }
        SetRot021b628c(rot, 0, items[self->curExit].dir, 0);
    } else if (Shared_HasMark_02062698()) {
        Shared_GetMarkPos(&pos);
        SetRot021b628c(rot, 0, Shared_GetMarkRot(), 0);
    } else if (self->blockB != NULL && self->blockB->count1 != 0) {
        FieldStart *st = LangBlockB_GetData(self->blockB);
        if (st != NULL) {
            pos = st->pos;
            SetRot021b628c(rot, 0, st->rot, 0);
        }
    } else {
        pos.x = 0;
        pos.y = 0;
        pos.z = 0;
        SetRot021b628c(rot, 0, 0, 0);
    }
    Shared_ClearMark();
    cam = &gSceneCmd->cam;
    if (cam != NULL) {
        cam->unk_da = 0;
        cam->base.pitch = rot[0];
        cam->base.yaw = rot[1];
        cam->base.roll = rot[2];
        cam->unk_bc = pos;
        cam->base.at = pos;
        t = pos;
        t.x -= FX_SinCosTable_[(rot[1] >> 4) * 2];
        t.z -= FX_SinCosTable_[(rot[1] >> 4) * 2 + 1];
        cam->base.eye = t;
        if (Shared_HasPendingPos()) {
            Shared_TakePendingPos(&t);
            cam->unk_e8 = t;
            cam->unk_da_1 = 1;
        }
        if (Shared_HasPendingCamPitch()) {
            cam->unk_f8.x = Shared_TakePendingCamPitch();
            cam->unk_da_4 = 1;
        }
        if (Shared_HasPendingCamYaw()) {
            cam->unk_f8.y = Shared_TakePendingCamYaw();
            cam->unk_da_5 = 1;
        }
        if (Shared_HasPendingCamDist()) {
            cam->unk_f4 = Shared_TakePendingCamDist();
            cam->unk_da_2 = 1;
        }
        cam->base.smooth = 0;
        ((Cam021b628c *)cam)->vfunc_00();
        cam->base.smooth = 1;
    }
    pl = ActorMgr_FindPlayer();
    if (pl == NULL) {
        return;
    }
    Robo021ca458_SetPosRot(pl, &pos, rot);
    ((Pl021b628c *)pl)->vfunc_18();
    if (pl->unk_b2e < 10) {
        pl->unk_b2e = 10;
    }
    pl->unk_b2f = pl->unk_b2e;
    self->playerPos = pos;
    r = self->blockB;
    if (r != NULL) {
        TouchQuad_Init(pl->unk_b70, r->unk_0a, r->unk_0c, r->unk_0e, r->unk_10);
        pl->unk_b0c = self->blockB->unk_12;
    } else {
        TouchQuad_Init(pl->unk_b70, 0, 0x4000, 0x8000, 0xc000);
        pl->unk_b0c = 0x1000;
    }
}

}
