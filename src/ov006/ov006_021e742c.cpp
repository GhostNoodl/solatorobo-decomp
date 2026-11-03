#include "ov006/SlotManager.h"
#include "nitro/fx.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Actor.h"
#include "ov006/Racer.h"

typedef void (Ov006Racer::*Ov006RacerFn)();

typedef struct Ov006RacerEntry {
    u32 kind;
    Ov006RacerFn fn;
} Ov006RacerEntry;

extern "C" {

extern const Ov006RacerEntry Ov006Racer_StateTable[];
extern const VecFx32 data_ov006_021eb8c8;
extern void *gGroup;
extern const MtxFx43 data_02092844;
extern const MtxFx44 data_02092800;

void Ov006Racer_UpdateCheckpoint(Ov006Racer *self);
void Ov006Racer_CheckItems(Ov006Racer *self);
void Ov006Racer_UpdateCamera(Ov006Racer *self);
void Obj0218c208_AddPoint(void *a, const VecFx32 *pos, u16 rot);

static inline void Ov006Racer_Dispatch(Ov006Racer *self, u32 kind) {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (Ov006Racer_StateTable[i].kind != kind) {
            continue;
        }
        (self->*Ov006Racer_StateTable[i].fn)();
        return;
    }
}

void Ov006ActVt_021ec4f4_RunState(Ov006Racer *self) {
    BOOL was;
    VecFx32 p;
    Ov006Racer_Dispatch(self, self->fsm->current);
    was = self->unk_19c_13;
    self->unk_19c_13 = 0;
    if (self->idx == gOv006SlotManager->unk5) {
        FieldCam *cam = &gSceneCmd->cam;
        if (cam->timer == 0) {
            VecFx32 v = data_ov006_021eb8c8;
            cam->unk_dc = v;
            cam->unk_da_0 = 1;
            cam->unk_f4 = (self->radius << 2) + 0x5ccd + self->radius;
            cam->unk_da_2 = 1;
            cam->unk_e8 = self->pos;
            cam->unk_da_1 = 1;
        }
        if (gOv006Manager->unk1C != 0 && gOv006SlotManager->unk13D == 0 && !Ov006Racer_IsOver(self)) {
            u16 k = gActorMgr->frame & 0x7f;
            if (k <= 0x3f && (k & 0xf) <= 0xc) {
                self->unk_19c_13 = 1;
            }
        }
    } else if (gOv006SlotManager->unk13D == 0 && !Ov006Racer_IsOver(self)) {
        self->unk_19c_13 = 1;
    }
    if (self->unk_19c_13) {
        p = self->pos;
        p.y += self->height;
        {
            u8 flag = FALSE;
            if (!was) {
                flag = TRUE;
            }
            Ov006Marker_Project(self->marker, &p, &data_02092844, &data_02092800, flag);
        }
        Ov006Marker_Update(self->marker);
    }
    Ov006Racer_UpdateCheckpoint(self);
    Ov006Racer_CheckItems(self);
    Ov006Racer_UpdateCamera(self);
    Obj0218c208_AddPoint(gGroup, &self->pos, self->rot_y);
    {
        ActorSub40 *w = self->fsm;
        w->flags = 0;
    }
}

}
