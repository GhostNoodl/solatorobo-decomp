#include "ov015/ov015.h"
#include "Main/Gfx/TexObj.h"

namespace Dup { extern "C" Ov015Stat data_ov015_0221332c; }

extern "C" {

Ov015Glyph *func_ov015_021fb25c(TexObj *obj, TexObjEntry *entry, Ov015Glyph *e, u16 *count);
Ov015Glyph *func_ov015_021fb408(TexObj *obj, TexObjEntry *entry, Ov015Glyph *e, u16 *count);
void LangData_LocalizePath(char *buf, const char *name);
void func_02041c34(void *a, int b, void *cb, void *arg);
extern char data_ov015_022128ab[];
extern char data_ov015_022128b5[];
extern void *data_0208cc94;
extern void *data_0208cc88;

Ov015Glyph *func_ov015_021fb408(TexObj *obj, TexObjEntry *entry, Ov015Glyph *e, u16 *count) {
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

s32 func_ov015_021fb474(Ov015Hud *self) {
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
        func_02041c34(self->mdl0, 0xf, (void *)func_ov015_021fb25c, arg);
        func_02041c34(self->mdl0, 0xe, (void *)func_ov015_021fb25c, arg);
    }
    res = ResList_FindType2(ResMgr_GetArcList((char *)data_0208cc94), data_0208cc88);
    Ov015_LabelInit(self->mdl1, data_0208cc88, data_0208cc94);
    TexObj_SetRes(self->mdl1, res);
    TexObj_SelectImage(self->mdl1, 0, 0x10);
    self->mdl1->flags |= 2;
    func_02041c34(self->mdl1, 0x10, (void *)func_ov015_021fb408, NULL);
    return 1;
}

BOOL func_ov015_021fb5d4(Ov015Hud *self) {
    Ov015Stat *g;
    s32 t3;
    s32 t4;
    if (!data_02097d48->unk_a30_4) {
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
