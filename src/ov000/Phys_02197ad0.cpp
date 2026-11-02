#include "ov000/Actor.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

typedef struct {
    s16 se;
    u8 pad_02[2];
    s16 se2;
    u8 pad_06[2];
    s16 m8;
    s16 ma;
    s16 mc;
    u8 shake;
    u8 shake2;
} Ent02197ad0;

typedef struct {
    u8 pad_00[0x50];
    u32 flags;
    u8 pad_54[4];
    s32 unk_58;
    u8 pad_5c[0x28];
    s32 unk_84;
} Body02197ad0;

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 pad_04[2];
    u16 unk_06;
} Def02197ad0;

extern "C" {
extern Ent02197ad0 data_ov000_021c9de8[];
extern void *data_02097e4c;
extern char data_ov000_021cc46f[];
u16 func_ov000_02198da8(Body02197ad0 *b, u16 angle);
void *func_02049f44(void *mgr, s32 id, VecFx32 *pos, s32 a);
void func_ov003_021f0c60(Actor *self, s32 a);

static inline s32 DistXZSq(const VecFx32 *a, const VecFx32 *b) {
    s32 dx = a->x - b->x;
    s32 dz = a->z - b->z;
    s64 sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Dist2D(sq);
}
void func_ov000_02197ad0(Actor *self, BOOL b) {
    Def02197ad0 *d = (Def02197ad0 *)self->targetObj;
    Ent02197ad0 *e = data_ov000_021c9de8;
    if (d->unk_02 == 3 || d->unk_02 == 4 || d->unk_01 == 6) {
        u16 k = d->unk_06;
        if (k >= 3) {
            k = 2;
        }
        e = &data_ov000_021c9de8[k];
    }
    if ((((Body02197ad0 *)self->hit)->flags & 0x40000000) || ((Body02197ad0 *)self->hit)->unk_58 != 0) {
        self->moveYaw = func_ov000_02198da8(((Body02197ad0 *)self->hit), self->moveYaw);
        if ((((Body02197ad0 *)self->hit)->flags & 0x40000000) && e->se >= 0 && ((Body02197ad0 *)self->hit)->unk_58 == 0) {
            func_02049f44(data_02097e4c, e->se, &self->pos, 0);
        }
        self->speed = FX_MUL(self->speed, e->m8);
        if (self->speed < 0x8f) {
            self->speed = 0x8f;
        }
        if (((Body02197ad0 *)self->hit)->unk_84 > 0x100 || ((Body02197ad0 *)self->hit)->unk_58 != 0) {
            if (self->velY < -0xcd) {
                self->velY = -0xcd;
            }
        }
        self->gravity = 0x52;
    }
    if (((Body02197ad0 *)self->hit)->flags & 0x20000000) {
        func_ov000_02190cb0(self->model, data_ov000_021cc46f, 0x1000, 0);
        if (self->unk_92 == 0 && e->se2 >= 0 && self->velY <= -0xcd) {
            Camera *cam = &data_ov000_021ccd54->cam.base;
            if (cam != NULL && DistXZSq(&cam->eye, &self->pos) < 0x19000) {
                func_02049f44(data_02097e4c, e->se2, &self->pos, 0);
                u8 s1;
                u8 s2;
                if ((s1 = e->shake) != 0 && (s2 = e->shake2) != 0) {
                    cam->shakeX = 1;
                    cam->shakeY = 1;
                    cam->shakeZ = 1;
                    cam->shakeTime = s1;
                    cam->shakeLen = s2;
                    cam->shakeCur = s2;
                }
            }
        }
        if (++self->unk_92 > 3) {
            self->velY = 0;
        } else {
            self->velY = FX_MUL(-self->velY, e->mc);
            if (self->velY <= 4) {
                self->velY = 0;
            }
        }
        self->speed = FX_MUL(self->speed, e->ma);
    }
    if (b && ((Def02197ad0 *)self->targetObj)->unk_03 != 0) {
        func_ov003_021f0c60(self, 0);
    }
}
}
