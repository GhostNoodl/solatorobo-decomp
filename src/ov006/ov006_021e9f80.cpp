#include "ov006/SlotManager.h"
#include "ov006/ov006.h"
#include "nitro/fx.h"

#define OV006R_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV006R_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV006R_SQRT_PARAM (*(volatile u64 *)0x40002b8)

typedef struct ov006_Rot021e9f80 {
    u16 x;
    u16 y;
    u16 z;
} ov006_Rot021e9f80;

typedef struct ov006_Pt021e9f80 {
    VecFx32 pos;
    u16 rotY;
    u16 unkE;
} ov006_Pt021e9f80;

typedef struct ov006_Racer021e9f80 {
    u8 unk0[0x70];
    u8 col[0x12c];
    u16 unk19C_0 : 7;
    u16 unk19C_7 : 1;
    u16 unk19C_8 : 8;
    u8 unk19E;
    u8 unk19F;
    u8 unk1A0[0x60];
    ov006_Pt021e9f80 *pts;
    ov006_Pt021e9f80 *goal;
    u8 count;
    u8 prev;
    u8 cur;
    u8 laps;
    ov006_Rot021e9f80 rot;
} ov006_Racer021e9f80;

extern "C" {

extern const VecFx32 data_ov006_021eb8a4;
extern const VecFx32 data_ov006_021eb8b0;

BOOL func_01ffc318(void *col, const VecFx32 *pos, VecFx32 *min, VecFx32 *max, void *rot);
u16 FX_Atan2(s32 y, s32 x);
void *func_ov006_021e37d0(int type, int arg);

static inline BOOL ov006_Racer021e9f80_Done(ov006_Racer021e9f80 *self) {
    BOOL done = FALSE;
    if (self->unk19F > data_ov006_021ec884->unk8->unkB) {
        done = TRUE;
    }
    return done;
}

static inline int ov006_Racer021e9f80_Next(int i) {
    return i + 1;
}

static inline s64 ov006_Sq021e9f80(s32 v) {
    return (s64)v * v;
}

static inline s64 ov006_XZSq021e9f80(const VecFx32 *p, const VecFx32 *q) {
    s32 dx = p->x - q->x;
    s32 dz = p->z - q->z;
    return (s64)dx * dx + (s64)dz * dz;
}

void func_ov006_021e9f80(ov006_Racer021e9f80 *self) {
    s32 sqrtBusy;
    ov006_Pt021e9f80 *p;
    ov006_Pt021e9f80 *goal;
    ov006_Pt021e9f80 *a;
    ov006_Pt021e9f80 *b;
    ov006_SlotManagerInfo *info;
    VecFx32 min = data_ov006_021eb8a4;
    VecFx32 max = data_ov006_021eb8b0;
    info = data_ov006_021ec884->unk8;
    p = &self->pts[self->cur];

    if (p != NULL) {
        BOOL ok = TRUE;
        if (info->unkB == 0 && self->cur + 1 >= self->count) {
            ok = FALSE;
        }
        if (ok && func_01ffc318(self->col, &p->pos, &min, &max, &self->rot)) {
            self->prev = self->cur;
            if (self->prev == 0) {
                self->laps++;
            }
            self->cur = self->prev + 1;
            if (self->cur >= self->count) {
                self->cur = 0;
            }
            self->rot.x = 0;
            self->rot.y = 0;
            self->rot.z = 0;
            b = &self->pts[self->prev];
            a = &self->pts[self->cur];
            if (b != NULL && a != NULL) {
                sqrtBusy = 0x8000;
                if ((u32)self & 3) {
                    sqrtBusy = 0x8000;
                }
                s64 sq;
                self->rot.y = FX_Atan2(a->pos.x - b->pos.x, a->pos.z - b->pos.z);
                sq = ov006_Sq021e9f80(b->pos.x - a->pos.x);
                sq += ov006_Sq021e9f80(b->pos.z - a->pos.z);
                OV006R_SQRTCNT = 1;
                OV006R_SQRT_PARAM = (u64)(sq * 4);
                while (OV006R_SQRTCNT & sqrtBusy) {
                }
                self->rot.x = -FX_Atan2(a->pos.y - b->pos.y, (s32)(OV006R_SQRT_RESULT + 1) >> 1);
            }
        }
    }

    goal = self->goal;
    if (goal == NULL) {
        return;
    }
    if (ov006_Racer021e9f80_Done(self)) {
        return;
    }
    {
        ov006_Rot021e9f80 rot;
        u16 ry = self->goal->rotY;
        rot.x = 0;
        rot.y = ry;
        rot.z = 0;
        if (func_01ffc318(self->col, &self->goal->pos, &min, &max, &rot)) {
            if (!self->unk19C_7) {
                self->unk19F++;
                if (self->unk19E == data_ov006_021ec884->unk5 && data_ov006_021ec884->unk13D == 0 && info->unkB != 0) {
                    u8 n = self->unk19F;
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
                        func_ov006_021e37d0(type, (int)&v);
                    }
                }
            }
            self->unk19C_7 = 1;
        } else {
            self->unk19C_7 = 0;
        }
    }
}

}
