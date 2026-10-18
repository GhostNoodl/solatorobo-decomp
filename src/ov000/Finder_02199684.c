#include "types.h"
#include "ov000/Vec.h"

#define REG_SQRTCNT (*(volatile u16 *)0x40002b0)
#define REG_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define REG_SQRT_PARAM (*(volatile u64 *)0x40002b8)

typedef struct {
    VecFx32 pos;
    VecFx32 offset;
    u16 angle;
    u16 unk_1a;
    s32 radius;
    u16 owner;
    u16 active : 1;
    u16 enabled : 1;
    u16 mode : 2;
    u16 unk_22_4 : 1;
    u16 directional : 1;
    u16 unk_22_6 : 10;
} Part;

typedef struct {
    u8 unk_00[0xc];
    u16 id;
    u16 kind;
    u8 unk_10[0x54];
    s32 radius;
    s32 height;
    u8 unk_6c[0x4];
    VecFx32 pos;
} ActorF;

typedef struct {
    VecFx32 pos;
    u16 dir;
    u16 mask;
    u16 kind;
    u16 angle_lo;
    u16 angle_hi;
    u8 unk_16[0x2];
    s32 dist_min;
    s32 dist_max;
    s32 y_min;
    s32 y_max;
    u16 owner;
    u8 use_mode : 1;
    u8 flat : 1;
    u8 use_radius : 1;
    u8 use_height : 1;
    u8 unk_2a_4 : 4;
} Query;

typedef struct {
    Query *query;
} Finder;

typedef struct {
    VecFx32 pos;
    s32 radius;
    s32 height;
    u16 angle;
    u8 has_angle;
} Shape;

static inline void CP_SetSqrtImm64_NS_(u64 param) {
    REG_SQRT_PARAM = param;
}

static inline void CP_SetSqrt64(u64 param) {
    REG_SQRTCNT = 1;
    CP_SetSqrtImm64_NS_(param);
}

static inline void CP_WaitSqrt(void) {
    while (REG_SQRTCNT & 0x8000) {
    }
}

static inline u32 CP_GetSqrtResult32(void) {
    return REG_SQRT_RESULT;
}

static inline s32 Dist2D(s64 sq) {
    CP_SetSqrt64((u64)(sq << 2));
    CP_WaitSqrt();
    return (s32)(CP_GetSqrtResult32() + 1) >> 1;
}

u16 FX_Atan2(s32 x, s32 z);
s32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);
BOOL func_ov000_02199a34(Finder *self, Shape *s);

static inline BOOL Query_CheckHeight(Query *q, Shape *s) {
    BOOL ok = TRUE;
    s32 lo = q->y_min;
    s32 hi = q->y_max;
    if (lo < hi) {
        s32 dy = s->pos.y - q->pos.y;
        if (dy > hi || dy + s->height < lo) {
            ok = FALSE;
        }
    }
    return ok;
}

static inline BOOL Finder_CheckAngle(Finder *self, Shape *s) {
    Query *q = self->query;
    BOOL ok = TRUE;
    u16 lo = q->angle_lo;
    u16 hi = q->angle_hi;

    if (lo != hi) {
        u16 a = s->angle;
        if (!s->has_angle) {
            a = FX_Atan2(s->pos.x - q->pos.x, s->pos.z - q->pos.z);
        }
        if ((u16)((u16)(a - self->query->dir) - lo) > (u16)(hi - lo)) {
            ok = FALSE;
        }
    }
    return ok;
}

static inline BOOL Part_IsActive(Part *p) {
    if (p->active == 1 && p->enabled == 1) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov000_02199684(Finder *self, ActorF *actor) {
    Shape s;
    Query *q = self->query;

    if (q->owner == actor->id) {
        return FALSE;
    }
    s.has_angle = 0;
    s.pos.x = actor->pos.x;
    s.pos.y = actor->pos.y;
    s.pos.z = actor->pos.z;
    if (q->use_radius) {
        s.radius = actor->radius;
    } else {
        s.radius = 0;
    }
    if (self->query->use_height) {
        s.height = actor->height;
    } else {
        s.height = 0;
    }
    if (!Query_CheckHeight(self->query, &s)) {
        return FALSE;
    }
    if (!Finder_CheckAngle(self, &s)) {
        return FALSE;
    }
    return func_ov000_02199a34(self, &s) ? TRUE : FALSE;
}

BOOL func_ov000_021997e8(Finder *self, Part *part) {
    Shape s;
    Query *q = self->query;

    if (q->owner == part->owner) {
        return FALSE;
    }
    if (!Part_IsActive(part)) {
        return FALSE;
    }
    if (q->use_mode) {
        u32 mode = part->mode;
        if (mode == 0) {
            return FALSE;
        }
        if (mode == 3) {
            return TRUE;
        }
    }
    s.has_angle = 0;
    s.pos.x = part->pos.x;
    s.pos.y = part->pos.y;
    s.pos.z = part->pos.z;
    if (self->query->use_radius) {
        s.radius = part->radius;
    } else {
        s.radius = 0;
    }
    if (self->query->use_height) {
        s.height = part->radius * 2;
        s.pos.y -= part->radius;
    } else {
        s.height = 0;
    }
    q = self->query;
    if (!Query_CheckHeight(q, &s)) {
        return FALSE;
    }
    if (part->directional) {
        u16 a = FX_Atan2(s.pos.x - q->pos.x, s.pos.z - q->pos.z);
        if ((u16)(a + 0xc000 - part->angle) > 0x8000) {
            return FALSE;
        }
        s.angle = a;
        s.has_angle = 1;
    }
    if (!Finder_CheckAngle(self, &s)) {
        return FALSE;
    }
    return func_ov000_02199a34(self, &s) ? TRUE : FALSE;
}

BOOL func_ov000_02199a34(Finder *self, Shape *s) {
    BOOL ok = TRUE;
    Query *q = self->query;
    s32 lo = q->dist_min;
    s32 hi = q->dist_max;

    if (lo < hi && lo >= 0 && hi >= 0) {
        s32 d;
        if (q->flat) {
            s32 dx = q->pos.x - s->pos.x;
            s32 dz = q->pos.z - s->pos.z;
            s64 sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            d = Dist2D(sq);
        } else {
            d = VEC_Distance(&q->pos, &s->pos);
        }
        d -= s->radius;
        if (d < 0) {
            d = 0;
        }
        if (d < lo || d > hi) {
            ok = FALSE;
        }
    }
    return ok;
}
