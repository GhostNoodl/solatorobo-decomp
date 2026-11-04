#include "types.h"
#include "ov000/ModelPart.h"
#include "Main/Gfx/Model.h"
#include "Main/Res/ResArc.h"
#include "ov000/LoTimer.h"

extern "C" {
extern char gCommonTextPath[];
extern const char *ResName_TextCells;
extern const char *ArcPath_MenuBattle;
extern const char *ResName_BattleCells;
void *Heap_Alloc(u32 size);
void TexObj_SetOamFunc(void *model, s32 a, void *cb, void *arg);
void *LoTimer_OamCallback(u8 *self, u16 *cmd, void *arr, u16 *count);

void LoTimer_LoadModels(LoTimer *self) {
    void *res;
    Model *m;
    Model *m2;
    void *res2;
    if (self->built == 1) {
        return;
    }
    res = ResList_FindType2(ResMgr_GetArcList(gCommonTextPath), ResName_TextCells);
    m = (Model *)Heap_Alloc(sizeof(Model));
    if (m) {
        const char *n = ResName_TextCells;
        PlttRes_Init_02041218(&m->pltt);
        TexObj_Init(m, n, 0);
    }
    self->unk_10 = m;
    TexObj_SetRes(m, res);
    self->unk_10->flags |= 2;
    self->unk_10->unk_150 = -0x2000;
    TexObj_SelectImage(self->unk_10, 0, 0xc);
    TexObj_SelectImage(self->unk_10, 0, 0xf);
    self->unk_10->flags |= 0x80000;
    MODEL_FLAGS(self->unk_10)->alpha = 0x1e;
    res2 = ResList_FindType2(ResMgr_GetArcList(ArcPath_MenuBattle), ResName_BattleCells);
    m2 = (Model *)Heap_Alloc(sizeof(Model));
    if (m2) {
        const char *n = ResName_BattleCells;
        PlttRes_Init_02041218(&m2->pltt);
        TexObj_Init(m2, n, 0);
    }
    self->unk_14 = m2;
    TexObj_SetRes(m2, res2);
    self->unk_14->flags |= 2;
    self->unk_14->unk_150 = -0x2000;
    {
        Model *q = self->unk_14;
        q->unk_144 = 0x800;
        q->unk_148 = 0x800;
        q->unk_14c = 0x800;
    }
    TexObj_SelectImage(self->unk_14, 0, 0x1e);
    TexObj_SetOamFunc(self->unk_14, 0x1e, (void *)LoTimer_OamCallback, self);
    TexObj_SelectImage(self->unk_14, 0, 0x1f);
    TexObj_SetOamFunc(self->unk_14, 0x1f, (void *)LoTimer_OamCallback, self);
    TexObj_SelectImage(self->unk_14, 0, 0x20);
    self->unk_14->flags |= 0x80000;
    MODEL_FLAGS(self->unk_14)->alpha = 0x1e;
    self->b17 = 1;
    self->built = 1;
}
}
