#include "ov015/ov015.h"
#include "Main/Gfx/TexObj.h"

namespace Dup { extern "C" Ov015Stat data_ov015_0221332c; }

extern "C" {

Ov015Glyph *Ov015Hud_OamDigits(TexObj *obj, TexObjEntry *entry, Ov015Glyph *e, u16 *count);
Ov015Glyph *Ov015Hud_OamLabel(TexObj *obj, TexObjEntry *entry, Ov015Glyph *e, u16 *count);
void LangData_LocalizePath(char *buf, const char *name);
void TexObj_SetOamFunc(void *a, int b, void *cb, void *arg);
extern char data_ov015_022128ab[];
extern char data_ov015_022128b5[];
extern void *ArcPath_MenuBattle;
extern void *ResName_BattleCells;

Ov015Glyph *Ov015Hud_OamLabel(TexObj *obj, TexObjEntry *entry, Ov015Glyph *e, u16 *count) {
    Ov015Glyph *last = &e[*count - 1];
    if (entry->index == 0x10) {
        e[0].w = last->w;
        e[0].x = 0;
        e[0].code = 0;
    }
    *count = 1;
    return e;
}

static inline void Ov015_LabelInit(Model *t, void *dict, void *name) {
    TexObj_Init(t, (char *)dict, 0);
    STD_CopyString(t->name, (char *)name);
}

s32 Ov015Hud_Setup(Ov015Hud *self) {
    char buf[0x20];
    void *res;
    LangData_LocalizePath(buf, data_ov015_022128ab);
    res = ResList_FindType2(ResMgr_GetArcList(buf), data_ov015_022128b5);
    TexObj_Init(self->mdl0, (char *)NULL, 0);
    TexObj_SetRes(self->mdl0, res);
    TexObj_SelectImage(self->mdl0, 0, 0xffff);
    self->mdl0->flags |= 2;
    self->mdl0->flags |= 0x80000;
    {
        void *arg = &data_ov015_0221332c;
        TexObj_SetOamFunc(self->mdl0, 0xf, (void *)Ov015Hud_OamDigits, arg);
        TexObj_SetOamFunc(self->mdl0, 0xe, (void *)Ov015Hud_OamDigits, arg);
    }
    res = ResList_FindType2(ResMgr_GetArcList((char *)ArcPath_MenuBattle), ResName_BattleCells);
    Ov015_LabelInit(self->mdl1, ResName_BattleCells, ArcPath_MenuBattle);
    TexObj_SetRes(self->mdl1, res);
    TexObj_SelectImage(self->mdl1, 0, 0x10);
    self->mdl1->flags |= 2;
    TexObj_SetOamFunc(self->mdl1, 0x10, (void *)Ov015Hud_OamLabel, NULL);
    return 1;
}

BOOL Ov015Hud_Update(Ov015Hud *self) {
    Ov015Stat *g;
    s32 t3;
    s32 t4;
    if (!gGfxSys->unk_a30_4) {
        return TRUE;
    }
    self->frame++;
    self->frame %= 0x7fff;
    g = &Dup::data_ov015_0221332c;
    if (data_ov015_0221332c.unk_00 >= 0x2bc000) {
        self->unk_0c = 1;
    } else {
        self->unk_0c = 2;
    }
    self->unk_18 = self->unk_10;
    self->unk_10 = g->unk_28;
    if (g->unk_10 != self->unk_14) {
        self->unk_1c = 0;
        self->unk_20 = 0x28;
    } else {
        self->unk_1c++;
        if (self->unk_1c > 0xffff) {
            self->unk_1c = 0xffff;
        }
        t3 = g->unk_14;
        t4 = g->unk_10;
        if ((t3 == 3 && t4 == 2) || (t3 == 2 && t4 == 3) || (t3 == 4 && t4 == 4) || ((t3 != 1 && t3 != 0) && t4 == 1)) {
            self->unk_20 = 0x28;
        } else {
            self->unk_20--;
            if (self->unk_20 < 0) {
                self->unk_20 = 0;
            }
        }
    }
    self->unk_14 = g->unk_10;
    self->unk_2c = (u16)(self->unk_2c + (FX_Mul(-g->unk_04, 0x1388000) >> 12));
    return TRUE;
}

}
