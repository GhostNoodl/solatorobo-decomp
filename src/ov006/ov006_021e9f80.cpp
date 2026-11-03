#include "ov006/SlotManager.h"
#include "ov006/ov006.h"
#include "nitro/fx.h"
#include "ov006/Racer.h"

#define OV006R_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV006R_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV006R_SQRT_PARAM (*(volatile u64 *)0x40002b8)


extern "C" {

extern const VecFx32 data_ov006_021eb8a4;
extern const VecFx32 data_ov006_021eb8b0;

BOOL Hit_PointInRotBox(VecFx32 *col, const VecFx32 *pos, VecFx32 *min, VecFx32 *max, Rot16 *rot);
struct EffectObj *ov006_CreateEffect(int type, const VecFx32 *pos);

static inline s64 ov006_Sq021e9f80(s32 v) {
    return (s64)v * v;
}

void Ov006Racer_UpdateCheckpoint(Ov006Racer *self) {
    s32 sqrtBusy;
    Ov006RacerPt *p;
    Ov006RacerPt *goal;
    Ov006RacerPt *a;
    Ov006RacerPt *b;
    ov006_SlotManagerInfo *info;
    VecFx32 min = data_ov006_021eb8a4;
    VecFx32 max = data_ov006_021eb8b0;
    info = gOv006SlotManager->info;
    p = &self->pts[self->nextPt];

    if (p != NULL) {
        BOOL ok = TRUE;
        if (info->unkB == 0 && self->nextPt + 1 >= self->ptCount) {
            ok = FALSE;
        }
        if (ok && Hit_PointInRotBox(&self->pos, &p->pos, &min, &max, &self->courseRot)) {
            self->lastPt = self->nextPt;
            if (self->lastPt == 0) {
                self->laps++;
            }
            self->nextPt = self->lastPt + 1;
            if (self->nextPt >= self->ptCount) {
                self->nextPt = 0;
            }
            self->courseRot.x = 0;
            self->courseRot.y = 0;
            self->courseRot.z = 0;
            b = &self->pts[self->lastPt];
            a = &self->pts[self->nextPt];
            if (b != NULL && a != NULL) {
                sqrtBusy = 0x8000;
                if ((u32)self & 3) {
                    sqrtBusy = 0x8000;
                }
                s64 sq;
                self->courseRot.y = FX_Atan2(a->pos.x - b->pos.x, a->pos.z - b->pos.z);
                sq = ov006_Sq021e9f80(b->pos.x - a->pos.x);
                sq += ov006_Sq021e9f80(b->pos.z - a->pos.z);
                OV006R_SQRTCNT = 1;
                OV006R_SQRT_PARAM = (u64)(sq * 4);
                while (OV006R_SQRTCNT & sqrtBusy) {
                }
                self->courseRot.x = -FX_Atan2(a->pos.y - b->pos.y, (s32)(OV006R_SQRT_RESULT + 1) >> 1);
            }
        }
    }

    goal = self->goal;
    if (goal == NULL) {
        return;
    }
    if (Ov006Racer_IsOver(self)) {
        return;
    }
    {
        Rot16 rot;
        u16 ry = self->goal->rotY;
        rot.x = 0;
        rot.y = ry;
        rot.z = 0;
        if (Hit_PointInRotBox(&self->pos, &self->goal->pos, &min, &max, &rot)) {
            if (!self->unk_19c_7) {
                self->unk_19f++;
                if (self->idx == gOv006SlotManager->unk5 && gOv006SlotManager->unk13D == 0 && info->unkB != 0) {
                    u8 n = self->unk_19f;
                    if (n > 1 && n <= info->unkB) {
                        VecFx32 v;
                        int type;
                        if (n != info->unkB) {
                            type = n - 1;
                            type += 1;
                        } else {
                            type = 10;
                        }
                        v.x = 0;
                        v.y = 0;
                        v.z = -0x1000;
                        ov006_CreateEffect(type, &v);
                    }
                }
            }
            self->unk_19c_7 = 1;
        } else {
            self->unk_19c_7 = 0;
        }
    }
}

}
