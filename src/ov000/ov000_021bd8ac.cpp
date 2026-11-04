#include "ov000/LoCommon.h"
#include "Main/Gfx/Model.h"
#include "Main/Res/ResArc.h"
#include "ov000/ActorMarker.h"
#include "ov000/ActorParts.h"

typedef struct {
    char *name;
    s32 x;
    s32 y;
} Ent_021bd8ac;

extern "C" {
extern char gCommonTextPath[];
extern const char *ResName_BattleCells;
extern const char *ArcPath_MenuBattle;
extern const char *ResName_CommonCells;
extern const char *ArcPath_Menu;
extern const char *ResName_TextCells;
extern Ent_021bd8ac data_ov000_021cc8f0[];
extern char data_ov000_021cc920[];
void *ResSet_Init(void *p);
BOOL ResSet_UpdateLoad(void *p);

static inline Model *NewModel_021bd8ac(const char **name) {
    const char *nm;
    Model *m = (Model *)Heap_Alloc(sizeof(Model));
    if (m != NULL) {
        nm = *name;
        PlttRes_Init_02041218(&m->pltt);
        TexObj_Init(m, nm, 0);
    }
    return m;
}

static inline void SetA_021bd8ac(u8 *p, const char *dir, const char *name) {
    STD_CopyString((char *)p + 0x10, dir);
    STD_CopyString((char *)p + 0x30, name);
    LFLD(u8, p, 3) |= 2;
}

static inline void SetB_021bd8ac(u8 *p, const char *dir, const char *name) {
    STD_CopyString((char *)p + 0x4c, dir);
    STD_CopyString((char *)p + 0x6c, name);
    LFLD(u8, p, 3) |= 4;
}

BOOL ActorMarker_LoadIcons(ActorMarker *self) {
    void *res;
    s32 n;

    if (!ResMgr_GetArcList(gCommonTextPath) || !ResMgr_GetArcList(ArcPath_Menu) || !ResMgr_GetArcList(ArcPath_MenuBattle)) {
        return FALSE;
    }
    n = self->nextKind;
    if (n >= 0xc && n < 0x10) {
        n = 0xb;
    }
    Model *mdl[4] = {NULL, NULL, NULL, NULL};
    switch (n) {
    case 0:
        res = ResList_FindType2(ResMgr_GetArcList(ArcPath_Menu), ResName_CommonCells);
        mdl[0] = NewModel_021bd8ac(&ResName_CommonCells);
        TexObj_SetRes(mdl[0], res);
        mdl[0]->flags |= 2;
        TexObj_SelectImage(mdl[0], 0, 3);
        break;
    case 1:
        res = ResList_FindType2(ResMgr_GetArcList(ArcPath_Menu), ResName_CommonCells);
        mdl[0] = NewModel_021bd8ac(&ResName_CommonCells);
        TexObj_SetRes(mdl[0], res);
        mdl[0]->flags |= 2;
        TexObj_SelectImage(mdl[0], 0, 4);
        break;
    case 2:
        res = ResList_FindType2(ResMgr_GetArcList(ArcPath_Menu), ResName_CommonCells);
        mdl[0] = NewModel_021bd8ac(&ResName_CommonCells);
        TexObj_SetRes(mdl[0], res);
        mdl[0]->flags |= 2;
        TexObj_SelectImage(mdl[0], 0, 0xf);
        break;
    case 3:
        res = ResList_FindType2(ResMgr_GetArcList(ArcPath_MenuBattle), ResName_BattleCells);
        mdl[0] = NewModel_021bd8ac(&ResName_BattleCells);
        TexObj_SetRes(mdl[0], res);
        mdl[0]->flags |= 2;
        TexObj_SelectImage(mdl[0], 0, 2);
        res = ResList_FindType2(ResMgr_GetArcList(ArcPath_Menu), ResName_CommonCells);
        mdl[1] = NewModel_021bd8ac(&ResName_CommonCells);
        TexObj_SetRes(mdl[1], res);
        mdl[1]->flags |= 2;
        TexObj_SelectImage(mdl[1], 0, 2);
        res = ResList_FindType2(ResMgr_GetArcList(gCommonTextPath), ResName_TextCells);
        mdl[2] = NewModel_021bd8ac(&ResName_TextCells);
        TexObj_SetRes(mdl[2], res);
        mdl[2]->flags |= 2;
        TexObj_SelectImage(mdl[2], 0, 7);
        break;
    case 4:
        res = ResList_FindType2(ResMgr_GetArcList(ArcPath_MenuBattle), ResName_BattleCells);
        mdl[0] = NewModel_021bd8ac(&ResName_BattleCells);
        TexObj_SetRes(mdl[0], res);
        mdl[0]->flags |= 2;
        TexObj_SelectImage(mdl[0], 0, 3);
        TexObj_SelectImage(mdl[0], 0, 0x10);
        break;
    case 5:
        res = ResList_FindType2(ResMgr_GetArcList(ArcPath_MenuBattle), ResName_BattleCells);
        mdl[0] = NewModel_021bd8ac(&ResName_BattleCells);
        TexObj_SetRes(mdl[0], res);
        mdl[0]->flags |= 2;
        TexObj_SelectImage(mdl[0], 0, 3);
        TexObj_SelectImage(mdl[0], 0, 0x11);
        break;
    case 6:
        res = ResList_FindType2(ResMgr_GetArcList(ArcPath_MenuBattle), ResName_BattleCells);
        mdl[0] = NewModel_021bd8ac(&ResName_BattleCells);
        TexObj_SetRes(mdl[0], res);
        mdl[0]->flags |= 2;
        TexObj_SelectImage(mdl[0], 0, 2);
        res = ResList_FindType2(ResMgr_GetArcList(ArcPath_Menu), ResName_CommonCells);
        mdl[1] = NewModel_021bd8ac(&ResName_CommonCells);
        TexObj_SetRes(mdl[1], res);
        mdl[1]->flags |= 2;
        TexObj_SelectImage(mdl[1], 0, 2);
        res = ResList_FindType2(ResMgr_GetArcList(gCommonTextPath), ResName_TextCells);
        mdl[2] = NewModel_021bd8ac(&ResName_TextCells);
        TexObj_SetRes(mdl[2], res);
        mdl[2]->flags |= 2;
        TexObj_SelectImage(mdl[2], 0, 6);
        break;
    case 7:
        res = ResList_FindType2(ResMgr_GetArcList(ArcPath_MenuBattle), ResName_BattleCells);
        mdl[0] = NewModel_021bd8ac(&ResName_BattleCells);
        TexObj_SetRes(mdl[0], res);
        mdl[0]->flags |= 2;
        TexObj_SelectImage(mdl[0], 0, 3);
        TexObj_SelectImage(mdl[0], 0, 4);
        break;
    case 8:
        res = ResList_FindType2(ResMgr_GetArcList(gCommonTextPath), ResName_TextCells);
        mdl[0] = NewModel_021bd8ac(&ResName_TextCells);
        TexObj_SetRes(mdl[0], res);
        mdl[0]->flags |= 2;
        TexObj_SelectImage(mdl[0], 0, 8);
        res = ResList_FindType2(ResMgr_GetArcList(ArcPath_Menu), ResName_CommonCells);
        mdl[1] = NewModel_021bd8ac(&ResName_CommonCells);
        TexObj_SetRes(mdl[1], res);
        mdl[1]->flags |= 2;
        TexObj_SelectImage(mdl[1], 0, 2);
        break;
    case 9:
        res = ResList_FindType2(ResMgr_GetArcList(gCommonTextPath), ResName_TextCells);
        mdl[0] = NewModel_021bd8ac(&ResName_TextCells);
        TexObj_SetRes(mdl[0], res);
        mdl[0]->flags |= 2;
        TexObj_SelectImage(mdl[0], 0, 9);
        res = ResList_FindType2(ResMgr_GetArcList(ArcPath_Menu), ResName_CommonCells);
        mdl[1] = NewModel_021bd8ac(&ResName_CommonCells);
        TexObj_SetRes(mdl[1], res);
        mdl[1]->flags |= 2;
        TexObj_SelectImage(mdl[1], 0, 2);
        break;
    case 10:
        res = ResList_FindType2(ResMgr_GetArcList(ArcPath_Menu), ResName_CommonCells);
        mdl[0] = NewModel_021bd8ac(&ResName_CommonCells);
        TexObj_SetRes(mdl[0], res);
        mdl[0]->flags |= 2;
        TexObj_SelectImage(mdl[0], 0, 0);
        TexObj_SelectImage(mdl[0], 0, 1);
        break;
    case 11:
        if (self->res == NULL) {
            Ent_021bd8ac *e = &data_ov000_021cc8f0[self->nextKind - 0xc];
            u8 *p = (u8 *)Heap_Alloc(0x138);
            if (p != NULL) {
                p = (u8 *)ResSet_Init(p);
            }
            self->res = (ActorRes *)p;
            SetA_021bd8ac(p, data_ov000_021cc920, e->name);
            SetB_021bd8ac((u8 *)self->res, data_ov000_021cc920, e->name);
            self->res->unk_00 = 0;
        }
        if (self->res != NULL) {
            ResSet_UpdateLoad(self->res);
            return self->res->unk_00 < 0 ? TRUE : FALSE;
        }
        break;
    }
    self->mdl[4] = mdl[0];
    self->mdl[5] = mdl[1];
    self->mdl[6] = mdl[2];
    return TRUE;
}
}
