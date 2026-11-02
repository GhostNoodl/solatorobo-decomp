#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "ov000/Group.h"
#include "nitro/mi.h"

typedef struct {
    u16 b0 : 12;
    u16 b12 : 2;
    u16 b14 : 2;
} Info12_02194c08;

typedef struct {
    s32 m[12];
} Mtx_02194c08;

extern "C" {
extern void *data_ov000_021ccd64;
u8 *Target_Get(void *p);
GroupNode *Group_FindNode(void *mgr, u16 id);
u8 *func_0206fef8(u16 id);
void func_ov000_02190758(void *a, void *b, s32 c);
BOOL func_ov000_021903b4(void *a);
void func_ov000_02191c24(void *a, void *b);
void func_ov000_02191ec4(void *a, s32 b, u32 c);
void func_ov000_021bd7a0(void *p);
s32 FX_Div(s32 a, s32 b);

static inline BOOL GBusy02194c08(FieldState *g) {
    return g->head != g->tail ? TRUE : FALSE;
}

static inline BOOL GIdle02194c08(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (GBusy02194c08(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline BOOL GD4_02194c08(void) {
    return data_ov000_021ccd54->event != 0 ? TRUE : FALSE;
}

static inline BOOL GHasD4_02194c08(void) {
    return GD4_02194c08() ? TRUE : FALSE;
}

static inline s32 Fade02194c08(s32 dist, GroupNode *node) {
    s32 r = 0x1000;
    if (dist > node->fadeStart) {
        if (dist >= node->spawnRange) {
            r = 0;
        } else {
            r -= FX_Div(dist - node->fadeStart, node->spawnRange - node->fadeStart);
        }
    }
    return r;
}

BOOL func_ov000_02194c08(ActorEx *self) {
    BOOL ret;
    u8 *p;
    u8 *q;
    if (!GIdle02194c08() && self->targetObj != NULL && *((u8 *)self->targetObj) == 2) {
        return FALSE;
    }
    p = NULL;
    q = p;
    ret = TRUE;
    if (self->model != NULL) {
        u8 alpha;
        GroupNode *node;
        if (self->targetObj != NULL) {
            p = Target_Get(((u8 *)self->targetObj));
        }
        if (p == NULL) {
            p = (u8 *)self;
        }
        if (p != NULL) {
            q = LFLD(u8 *, p, 0x48);
        }
        if (q != NULL) {
            Model0218fe1c *s = self->model;
            if (LFLD(u32, q, 0x54) & 0x80000) {
                s->bright = 5;
            } else {
                s->bright = 0x1f;
            }
        }
        if (self->targetObj != NULL && self->targetObj->unk_18_0) {
            Mtx_02194c08 m;
            Model0218fe1c *s;
            MI_Copy48B(((u8 *)self->targetObj) + 0x20, &m);
            s = self->model;
            MI_Copy36B(&m, &s->rot);
            s->trans.x = m.m[9];
            s->trans.y = m.m[10];
            s->trans.z = m.m[11];
            self->unk_93_0 = 1;
        }
        if (!self->unk_93_0) {
            Model0218fe1c *s = self->model;
            s->trans.x = self->pos.x;
            s->trans.y = self->pos.y;
            s->trans.z = self->pos.z;
            func_ov000_02190758(((u8 *)self->model), (u8 *)self + 0x7c, 0);
        }
        self->unk_93_0 = 0;
        alpha = 0x1f;
        node = Group_FindNode(data_ov000_021ccd64, self->unk_20);
        if (node != NULL) {
            s32 dist;
            s32 r;
            FieldState *g = data_ov000_021ccd54;
            Model0218fe1c *s = self->model;
            s32 dx = g->cam.base.eye.x - s->trans.x;
            s32 dz = g->cam.base.eye.z - s->trans.z;
            {
                s64 sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                REG_SQRTCNT = 1;
                REG_SQRT_PARAM = (u64)(sq << 2);
            }
            while (REG_SQRTCNT & 0x8000) {
            }
            dist = (s32)(REG_SQRT_RESULT + 1) >> 1;
            r = Fade02194c08(dist, node);
            if (r == 0) {
                alpha = 0;
            } else if (r < 0x1000) {
                alpha = (r * 31) >> 12;
            }
        }
        if (alpha == 0x1f) {
            ret = func_ov000_021903b4(((u8 *)self->model));
        } else if (alpha != 0) {
            u8 old = self->model->alpha;
            if (old > alpha) {
                self->model->alpha = alpha;
            }
            ret = func_ov000_021903b4(((u8 *)self->model));
            self->model->alpha = old;
        }
    }
    if (ret && self->unk_3c != NULL) {
        u8 *info = func_0206fef8(self->kind);
        ActorSub48 *o = self->hit;
        u8 *t = Target_Get(((u8 *)self->targetObj));
        if (t != NULL) {
            if (self->fsm->current == 9) {
                o = (ActorSub48 *)LFLD(u8 *, t, 0x48);
            }
        } else if (LFLD(Info12_02194c08, info, 0x12).b12 == 2) {
            o = NULL;
        }
        if (o != NULL) {
            s32 m;
            self->unk_3c->unk_10 = self->pos.y - o->check.y;
            m = 1;
            switch (LFLD(Info12_02194c08, info, 0x12).b14) {
            case 0:
                m = 1;
                break;
            case 1:
                m = 0;
                break;
            case 2:
                m = 3;
                break;
            case 3:
                m = 2;
                break;
            }
            func_ov000_02191ec4(self->unk_3c, m, o->unk_54);
            func_ov000_02191c24(self->unk_3c, (u8 *)self + 0x70);
        }
    }
    if (ret && self->unk_5c != NULL) {
        if (GIdle02194c08() && !GHasD4_02194c08()) {
            func_ov000_021bd7a0(((u8 *)self->unk_5c));
        }
    }
    return ret;
}
}
