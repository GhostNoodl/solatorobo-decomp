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

typedef struct {
    u8 pad_00[4];
    VecFx32 pos;
    u8 pad_10[0x89];
    u8 unk_99;
    u8 unk_9a;
    u8 unk_9b;
    u8 b0 : 2;
    u8 sh0 : 1;
    u8 sh1 : 1;
    u8 sh2 : 1;
    u8 b5 : 3;
} Cam02197ad0;

extern "C" {
extern Ent02197ad0 data_ov000_021c9de8[];
extern void *data_02097e4c;
extern u8 data_ov000_021cc46f[];
u16 func_ov000_02198da8(Body02197ad0 *b, u16 angle);
void func_02049f44(void *mgr, s32 id, VecFx32 *pos, s32 a);
void func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov003_021f0c60(Actor *self, s32 a);

static inline s32 DistXZSq(const VecFx32 *a, const VecFx32 *b) {
    s32 dx = a->x - b->x;
    s32 dz = a->z - b->z;
    s64 sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Dist2D(sq);
}
void func_ov000_02197ad0(Actor *self, BOOL b) {
    Def02197ad0 *d = (Def02197ad0 *)self->unk_4c;
    Ent02197ad0 *e = data_ov000_021c9de8;
    if (d->unk_02 == 3 || d->unk_02 == 4 || d->unk_01 == 6) {
        u16 k = d->unk_06;
        if (k >= 3) {
            k = 2;
        }
        e = &data_ov000_021c9de8[k];
    }
    if ((LFLD(Body02197ad0 *, self, 0x48)->flags & 0x40000000) || LFLD(Body02197ad0 *, self, 0x48)->unk_58 != 0) {
        self->unk_98 = func_ov000_02198da8(LFLD(Body02197ad0 *, self, 0x48), self->unk_98);
        if ((LFLD(Body02197ad0 *, self, 0x48)->flags & 0x40000000) && e->se >= 0 && LFLD(Body02197ad0 *, self, 0x48)->unk_58 == 0) {
            func_02049f44(data_02097e4c, e->se, &self->pos, 0);
        }
        self->unk_9c = FX_MUL(self->unk_9c, e->m8);
        if (self->unk_9c < 0x8f) {
            self->unk_9c = 0x8f;
        }
        if (LFLD(Body02197ad0 *, self, 0x48)->unk_84 > 0x100 || LFLD(Body02197ad0 *, self, 0x48)->unk_58 != 0) {
            if (self->unk_a0 < -0xcd) {
                self->unk_a0 = -0xcd;
            }
        }
        self->unk_a8 = 0x52;
    }
    if (LFLD(Body02197ad0 *, self, 0x48)->flags & 0x20000000) {
        func_ov000_02190cb0(self->unk_38, data_ov000_021cc46f, 0x1000, 0);
        if (self->unk_92 == 0 && e->se2 >= 0 && self->unk_a0 <= -0xcd) {
            Cam02197ad0 *cam = (Cam02197ad0 *)((u8 *)data_ov000_021ccd54 + 0xf4);
            if (cam != NULL && DistXZSq(&cam->pos, &self->pos) < 0x19000) {
                func_02049f44(data_02097e4c, e->se2, &self->pos, 0);
                u8 s1;
                u8 s2;
                if ((s1 = e->shake) != 0 && (s2 = e->shake2) != 0) {
                    cam->sh0 = 1;
                    cam->sh1 = 1;
                    cam->sh2 = 1;
                    cam->unk_99 = s1;
                    cam->unk_9a = s2;
                    cam->unk_9b = s2;
                }
            }
        }
        if (++self->unk_92 > 3) {
            self->unk_a0 = 0;
        } else {
            self->unk_a0 = FX_MUL(-self->unk_a0, e->mc);
            if (self->unk_a0 <= 4) {
                self->unk_a0 = 0;
            }
        }
        self->unk_9c = FX_MUL(self->unk_9c, e->ma);
    }
    if (b && ((Def02197ad0 *)self->unk_4c)->unk_03 != 0) {
        func_ov003_021f0c60(self, 0);
    }
}
}
