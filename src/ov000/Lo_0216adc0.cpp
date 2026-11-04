#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"
#include "ov000/Obj0216ad04.h"
#include "ov000/ObjLayouts.h"
#include "ov000/ModelPart.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/Model.h"
#include "Main/Res/ResArc.h"
#include "Main/Sys/FieldState.h"

extern "C" {

void *ActorMgr_FindPlayer(void);
BOOL PauseNode_IsDrawPaused(void *a, s32 b);
s32 Gfx3DState_NextPolyIdB(void *a);

void Obj0216ad04_Ask(Obj0216ad04 *self, s32 a, s32 b) {
    if (self->kind == a) {
        self->flags |= 6;
    } else {
        self->flags &= ~2;
    }
    if (b < 0) {
        b = 0;
    } else if (b > 0x63) {
        b = 0x63;
    }
    self->kind = a;
    self->value = b;
}

}

extern "C" {
extern MessageQueue021cb980 *gMessageQueue;
extern s32 gFadeState[5];
extern const char *ArcPath_MenuBattle;
extern const char *ResName_BattleCells;
BOOL Model_IsReady(void *m, s32 id);
s32 FX_Div(s32 a, s32 b);

static inline Lo021cb798 *GetObj0216adf8(void) {
    ListBuffer021cb940 *o = gMessageQueue->unk_11c;
    return o != NULL ? o->unk_58 : NULL;
}

static inline BOOL Busy0216adf8(FieldState *p) {
    return p->head != p->tail ? TRUE : FALSE;
}

static inline BOOL Ready0216adf8(FieldState *p) {
    if (p != NULL) {
        if (Busy0216adf8(p)) {
            return FALSE;
        }
        if (p->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline BOOL Idle0216adf8(void) {
    return gFadeState[3] == 0 && gFadeState[0] == 0 ? TRUE : FALSE;
}

static inline BOOL SubFlag0216adf8(Lo021cb798 *o) {
    return o->unk_0c_1 ? TRUE : FALSE;
}

void Obj0216ad04_Update(Obj0216ad04 *self) {
    Lo021cb798 *o = GetObj0216adf8();
    if (o == NULL) {
        return;
    }
    if (!Ready0216adf8(gSceneCmd) || !Idle0216adf8()) {
        self->want = 0;
    }
    switch (self->state) {
    case 0:
    case 1:
        break;
    case 2:
        self->state = 4;
        break;
    case 3:
        HEAP_DELETE_MODEL(self->model);
        self->state = 4;
        break;
    case 4:
        if (SubFlag0216adf8(o)) {
            return;
        }
        if (self->want) {
            self->opening = TRUE;
            self->state = 5;
        }
        break;
    case 5: {
        void *res;
        Model *m;
        self->part = 0xc;
        res = ResList_FindType2(ResMgr_GetArcList(ArcPath_MenuBattle), ResName_BattleCells);
        m = (Model *)Heap_Alloc(sizeof(Model));
        if (m != NULL) {
            const char *nm = ResName_BattleCells;
            PlttRes_Init_02041218((struct PlttRes *)((u8 *)m + 0x88));
            TexObj_Init(m, nm, 0);
        }
        self->model = m;
        TexObj_SetRes(m, res);
        self->model->flags |= 2;
        TexObj_SelectImage(self->model, 0, 0xb);
        TexObj_SelectImage(self->model, 0, self->part);
        TexObj_SelectImage(self->model, 0, 7);
        TexObj_SelectImage(self->model, 0, 6);
        self->model->flags |= 0x80000;
        self->model->flags |= 0x200000;
        MODEL_FLAGS(self->model)->alpha = 0x1e;
        self->state = 6;
        break;
    }
    case 6:
        if (Model_IsReady(self->model, 0xffff)) {
            self->frame = 0;
            self->ratio = 0x1000;
            self->state = 8;
        }
        break;
    case 7:
        if (SubFlag0216adf8(o) || !self->asked) {
            self->want = 0;
        }
        self->asked = 0;
    case 8:
        if (!self->want) {
            self->opening = 0;
            self->state = 8;
        }
        if (self->state == 7) {
            return;
        }
        if (self->opening) {
            self->frame++;
            self->ratio = FX_Div(self->frame << 12, 0xc000);
            if (self->ratio >= 0x1000) {
                self->ratio = 0x1000;
                self->state = 7;
            }
        } else {
            self->frame--;
            self->ratio = FX_Div(self->frame << 12, 0xc000);
            if (self->ratio <= 0) {
                self->ratio = 0;
                self->state = 3;
            }
        }
        self->ratio = 0x1000 - FX_SinCosTable_[((self->ratio << 14) >> 16) * 2];
        break;
    }
}

}
