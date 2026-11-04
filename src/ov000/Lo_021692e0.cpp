#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/Model.h"
#include "Main/Res/ResArc.h"

extern "C" {

extern s32 gFadeState[5];
BOOL Model_IsReady(void *a, s32 b);
extern const char *ArcPath_MenuBattle;
extern const char *ResName_BattleCells;
void Obj0215fdfc_SetEntry(ObjBase021cac0c_021cb6f0 *self, s32 a, const void *b);
extern u8 data_ov000_021c9ab0[];
extern s32 data_ov000_021c9bb4[];

typedef struct {
    s32 a;
    u8 **list;
} LoPair;

typedef struct {
    s32 a;
    s32 b;
} LoIdx2;

static inline BOOL LoGBusy(FieldState *g) {
    return g->head != g->tail ? TRUE : FALSE;
}

static inline BOOL LoGIdle(void) {
    FieldState *g = gSceneCmd;
    if (g != NULL) {
        if (LoGBusy(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline BOOL LoD78Idle(void) {
    return (gFadeState[3] == 0 && gFadeState[0] == 0) ? TRUE : FALSE;
}

void Lo021cb7ec_Setup(Lo021cb7ec *self) {
    void *res = ResList_FindType2(ResMgr_GetArcList(ArcPath_MenuBattle), ResName_BattleCells);
    Model *m = (Model *)Heap_Alloc(sizeof(Model));
    if (m) {
        const char *nm = ResName_BattleCells;
        PlttRes_Init_02041218(&m->pltt);
        TexObj_Init(m, nm, 0);
    }
    self->unk_9c = m;
    TexObj_SetRes(m, res);
    self->unk_9c->flags |= 2;
    self->unk_9c->flags |= 0x200000;
    self->unk_9c->flags |= 0x80000;
    TexObj_SelectImage(self->unk_9c, 0, 1);
    self->unk_30 = 0xc000;
    self->unk_50 = 0x30;
    self->unk_54 = 3;
    self->unk_28 = 0;
    self->unk_0c |= 0x360;
    self->unk_74 = 0;
    self->unk_78 = 0;
    self->unk_7c = 0xffffe333;
    Obj0215fdfc_SetEntry(self, 2, data_ov000_021c9ab0);
}

BOOL Lo021cb7ec_CanUpdate(Lo021cb7ec *self) {
    if (!LoGIdle() || !LoD78Idle()) {
        self->unk_0c_1 = 1;
    }
    switch (self->unk_04) {
    case 6:
        if (!self->unk_0c_1 ? TRUE : FALSE) {
            self->unk_04 = 0;
            return TRUE;
        }
        return FALSE;
    case 1:
        if (!Model_IsReady(self->unk_9c, 0xffff)) {
            return FALSE;
        }
        self->unk_0c_3 = 1;
        break;
    }
    return TRUE;
}

}
