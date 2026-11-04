#include "ov000/LoCommon.h"
#include "ov000/ModelPart.h"
#include "Main/Res/ResArc.h"
#include "ov000/ObjLayouts.h"

extern "C" {
extern const char *ResName_WifiCells;
extern const char *ArcPath_MenuWifi;
extern const char *ResName_CommonCells;
extern const char *ArcPath_Menu;
void Obj02153c48_CreateText(UiListItem *item, s32 font, s32 b, s32 c, s32 d);

// The list's highlight panel, made here with its reset values.
struct Panel0215aa78 : public UiPanel {
    static void *operator new(unsigned long size) { return Heap_Alloc(size); }
    Panel0215aa78() {
        flags = 0;
        x = 0;
        y = 0;
        z = 0;
        dy = 0;
        dx = 0;
        width = 0x80000;
        height = 0xf000;
        unk_20 = 0;
        unk_24 = 0;
        model = NULL;
    }
};

static inline void Panel0215aa78_SetOfs(UiPanel *p, s32 x, s32 y) {
    p->dx = x;
    p->dy = y;
}

void Obj0215e8b0_LoadModel(UiPanel *p);

void LoBase021cafc0_021cb0b8_Setup(LoBase021cafc0_021cb0b8 *self) {
    UiListItem *node;
    s32 maxw;

    node = self->items;
    maxw = 0;
    while (node != NULL) {
        Obj02153c48_CreateText(node, self->font, 0, 0, 0);
        if (LFLD(s32, node->label, 0x44) > maxw) {
            maxw = LFLD(s32, node->label, 0x44);
        }
        node = node->next;
    }
    self->rows = self->itemCount;
    if (self->width == -1) {
        if (self->flag3 ? TRUE : FALSE) {
            self->width = 0x100;
        } else {
            self->width = maxw + 0x40;
            if (self->width < 0x98) {
                self->width = 0x98;
            }
        }
    }
    self->height = self->vfunc_44();
    if (self->model == NULL) {
        if (self->flag6 ? TRUE : FALSE) {
            self->model = new ModelObj(ResName_WifiCells, ArcPath_MenuWifi);
        } else {
            self->model = new ModelObj(ResName_CommonCells, ArcPath_Menu);
        }
        {
            ResList *a = ResMgr_GetArcList(self->model->name);
            TexObj_SetRes(self->model, ResList_FindType2(a, self->model->unk_04c));
        }
        self->model->flags |= 2;
        TexObj_SelectImage(self->model, 0, 7);
    }
    if (self->panel == NULL) {
        self->panel = new Panel0215aa78();
        if (self->flag3 ? TRUE : FALSE) {
            self->panel->bits.b3 = 1;
            Panel0215aa78_SetOfs(self->panel, (maxw >> 1) + 0x10, 0);
        } else {
            self->panel->bits.b1 = 3;
            self->panel->bits.centered = 1;
        }
        Obj0215e8b0_LoadModel(self->panel);
        self->panel->width = (self->width - 0x20) << 12;
        self->panel->model->flags |= 0x200000;
        self->panel->model->flags |= 0x100000;
        self->panel->model->flags |= 0x80000;
        MODEL_FLAGS(self->panel->model)->alpha = 0x1e;
    }
    self->slideMode = 0;
    self->posX = 0x80 - (self->width >> 1);
    self->posY = 0x60 - (self->height >> 1);
    self->busy = 1;
}

}
