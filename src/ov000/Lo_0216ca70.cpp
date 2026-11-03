#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "ov000/Vec.h"
#include "Main/Gfx/Model.h"
#include "Main/Res/ResArc.h"
#include "ov000/Obj0216c954.h"
#include "ov000/MessageQueue.h"

extern "C" {

extern MessageQueue021cb980 *gMessageQueue;
extern s32 gFadeState[5];
extern VecFx32 data_ov000_021c9af8;
extern const char *data_0208cc94;
extern const char *data_0208cc88;
extern void *gGroup;
BOOL PauseNode_IsDrawPaused(void *node, BOOL recurse);
BOOL MessageQueue_GetById(MessageQueue *mgr, s32 a);
BOOL func_ov000_021705a0(ListBuffer021cb940 *self, s32 check);
void TexObj_SetOamFunc(void *a, int b, void *c, void *d);
BOOL Model_IsReady(void *a, s32 b);
void *func_ov000_0216c800(void);
s32 FX_Div(s32 a, s32 b);
Robo021ca458 *ActorMgr_FindPlayer(void);
s32 Group_GetSpawnPositions(void *mgr, s32 max, VecFx32 *out, s32 kind, u16 id);
s32 Math_ProjectToScreen(s32 *out, const VecFx32 *pos);
void func_ov000_021c194c(Obj021c2114 *self);

static inline BOOL LoGBusy(FieldState *g) {
    return g->head != g->tail ? TRUE : FALSE;
}

static inline BOOL LoD78Idle(void) {
    return (gFadeState[3] == 0 && gFadeState[0] == 0) ? TRUE : FALSE;
}

static inline BOOL Busy(void) {
    BOOL r;
    MessageQueue021cb980 *mgr = gMessageQueue;
    if (mgr == NULL) {
        r = FALSE;
    } else if (MessageQueue_GetById(mgr, 9)) {
        r = TRUE;
    } else if (MessageQueue_GetById(mgr, 0xa)) {
        r = TRUE;
    } else if (mgr->unk_11c == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_021705a0(mgr->unk_11c, 0);
    }
    return r;
}

static inline s32 MulK(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline s32 DistSq(const VecFx32 *a, const VecFx32 *b) {
    s32 dx = a->x - b->x;
    s32 dy = a->y - b->y;
    s32 dz = a->z - b->z;
    return (s32)((((s64)dx * dx + (s64)dy * dy + (s64)dz * dz) + 0x800) >> 12);
}

BOOL func_ov000_0216ca70(Obj0216c954 *self) {
    VecFx32 pts[0x20];
    s32 i;
    s32 scr[2];
    s32 best;
    Robo021ca458 *pl;
    Obj021c2114 *e;
    VecFx32 *p;
    void *res;
    Model *m;
    s32 n;
    s32 maxd;
    s32 d;
    s32 v;
    s32 x;
    s32 y;
    s32 z;
    u16 id;

    if (PauseNode_IsDrawPaused(gSceneCmd->pause, TRUE)) {
        self->show = 0;
        self->idleFrames = 0;
        self->state = 4;
    } else if (!self->stop && !LoGBusy(gSceneCmd) && !Busy() && LoD78Idle()) {
        if (self->idleFrames++ > 3) {
            self->idleFrames = 4;
            self->show = 1;
        }
    } else if (self->state == 7) {
        self->show = 0;
        self->idleFrames = 0;
    }
    switch (self->state) {
    case 2:
        self->state = 4;
        break;
    case 3:
        return FALSE;
    case 4:
        self->opening = 0;
        self->ratio = 0x1000;
        self->frame = 0;
        if (self->show) {
            self->opening = 1;
            self->state = 5;
        } else if (self->stop) {
            self->state = 3;
        }
        break;
    case 5:
        self->state = 6;
        if (self->effect == NULL && self->model == NULL) {
            id = self->kind;
            self->findKind = id;
            switch (id >> 12) {
            case 4:
                if (id == 0x400a) {
                    self->part = 0xf;
                } else {
                    self->part = 0xffff;
                }
                break;
            case 1:
            case 2:
            case 3:
            case 5:
            case 6:
                self->part = 0xffff;
                break;
            }
            if (self->mode != 0) {
                VecFx32 ofs = data_ov000_021c9af8;
                e = (Obj021c2114 *)Heap_Alloc(sizeof(Obj021c2114));
                if (e) {
                    func_ov000_021c2114(e);
                }
                self->effect = e;
                e->useOfs = 1;
                self->effect->ofs = ofs;
            }
            if (self->part != 0xffff) {
                res = ResList_FindType2(ResMgr_GetArcList(data_0208cc94), data_0208cc88);
                m = (Model *)Heap_Alloc(sizeof(Model));
                if (m) {
                    const char *name = data_0208cc88;
                    PlttRes_Init_02041218((struct PlttRes *)((u8 *)m + 0x88));
                    TexObj_Init(m, name, 0);
                }
                self->model = m;
                TexObj_SetRes(m, res);
                self->model->flags |= 2;
                TexObj_SelectImage(self->model, 0, 0xd);
                TexObj_SelectImage(self->model, 0, 0xe);
                TexObj_SelectImage(self->model, 0, self->part);
                TexObj_SelectImage(self->model, 0, 6);
                TexObj_SelectImage(self->model, 0, 8);
                TexObj_SetOamFunc(self->model, 6, (void *)func_ov000_0216c800, self);
            }
            func_ov000_0216d474(self);
        }
        break;
    case 6:
        if (self->model == NULL || Model_IsReady(self->model, 0xffff)) {
            self->frame = 0;
            self->ratio = 0x1000;
            self->state = 8;
        }
        break;
    case 8:
        self->ratio = FX_Div(++self->frame << 12, 0x19000);
        if (self->ratio >= 0x1000) {
            self->ratio = 0x1000;
            self->frame = 0;
            if (self->opening) {
                self->state = 7;
            } else {
                self->state = 4;
                break;
            }
        }
        self->ratio = FX_SinCosTable_[((self->ratio << 14) >> 16) * 2];
        if (self->opening) {
            self->ratio = 0x1000 - self->ratio;
        }
    case 7:
        if (++self->bounceFrame < 0x18) {
            v = self->bounce;
            self->bounce = v + MulK(0x3000 - v, 0x148);
        } else if (self->bounceFrame >= 0x40) {
            self->bounceFrame = 0;
            self->bounce = 0;
        } else {
            v = self->bounce;
            self->bounce = v + MulK(-v, 0xcd);
        }
        if (!self->show) {
            self->opening = 0;
            self->state = 8;
        }
        break;
    }
    if (self->effect != NULL) {
        if (self->show) {
            self->effect->active = 1;
            pl = ActorMgr_FindPlayer();
            {
                VecFx32 c;
                c.x = pl->pos.x;
                c.y = pl->pos.y + LO_FX_MUL(pl->height, 0xc00);
                c.z = pl->pos.z;
                self->effect->pos = *(VecFx32 *)&c;
                n = Group_GetSpawnPositions(gGroup, 0x20, pts, self->findKind >> 12, self->findKind);
                if (n != 0) {
                    maxd = self->range;
                    for (i = 0, best = 0; i < n; i++) {
                        d = DistSq(&c, &pts[i]);
                        if (maxd > d) {
                            best = i + 1;
                            maxd = d;
                        }
                    }
                    if (best != 0) {
                        z = Math_ProjectToScreen(scr, &pts[best - 1]);
                        if (z < -0xf000 || z > 0 || scr[0] < -0x20 || scr[0] > 0x120 || scr[1] < -0x20 || scr[1] > 0x100) {
                            e = self->effect;
                            p = &pts[best - 1];
                            e->target.x = p->x;
                            e->target.y = p->y;
                            e->target.z = p->z;
                        } else {
                            self->effect->active = 0;
                        }
                    } else {
                        self->effect->active = 0;
                    }
                } else {
                    self->effect->active = 0;
                }
            }
        } else {
            self->effect->active = 0;
        }
        func_ov000_021c194c(self->effect);
    }
    return TRUE;
}

}
