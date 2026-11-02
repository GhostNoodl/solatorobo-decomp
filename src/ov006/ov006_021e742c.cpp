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

extern const Ov006RacerEntry data_ov006_021eb930[];
extern const VecFx32 data_ov006_021eb8c8;
extern void *data_ov000_021ccd64;
extern const MtxFx43 data_02092844;
extern const MtxFx44 data_02092800;

void func_ov006_021e9f80(Ov006Racer *self);
void func_ov006_021e7fe4(Ov006Racer *self);
void func_ov006_021e76d8(Ov006Racer *self);
void Obj0218c208_AddPoint(void *a, const VecFx32 *pos, u16 rot);

static inline void Ov006Racer_Dispatch(Ov006Racer *self, u32 kind) {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (data_ov006_021eb930[i].kind != kind) {
            continue;
        }
        (self->*data_ov006_021eb930[i].fn)();
        return;
    }
}

void func_ov006_021e742c(Ov006Racer *self) {
    BOOL was;
    VecFx32 p;
    Ov006Racer_Dispatch(self, self->fsm->current);
    was = self->unk_19c_13;
    self->unk_19c_13 = 0;
    if (self->idx == data_ov006_021ec884->unk5) {
        FieldCam *cam = &data_ov000_021ccd54->cam;
        if (cam->unk_d9 == 0) {
            VecFx32 v = data_ov006_021eb8c8;
            cam->unk_dc = v;
            cam->unk_da_0 = 1;
            cam->unk_f4 = (self->radius << 2) + 0x5ccd + self->radius;
            cam->unk_da_2 = 1;
            cam->unk_e8 = self->pos;
            cam->unk_da_1 = 1;
        }
        if (data_ov006_021ec860->unk1C != 0 && data_ov006_021ec884->unk13D == 0 && !Ov006Racer_IsOver(self)) {
            u16 k = data_ov000_021ccd68->frame & 0x7f;
            if (k <= 0x3f && (k & 0xf) <= 0xc) {
                self->unk_19c_13 = 1;
            }
        }
    } else if (data_ov006_021ec884->unk13D == 0 && !Ov006Racer_IsOver(self)) {
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
            func_ov006_021dccc8(self->marker, &p, &data_02092844, &data_02092800, flag);
        }
        func_ov006_021dc9c8(self->marker);
    }
    func_ov006_021e9f80(self);
    func_ov006_021e7fe4(self);
    func_ov006_021e76d8(self);
    Obj0218c208_AddPoint(data_ov000_021ccd64, &self->pos, self->rot_y);
    {
        ActorSub40 *w = self->fsm;
        w->flags = 0;
    }
}

}
