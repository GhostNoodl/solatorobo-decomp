#include "ov000/LoCommon.h"
#include "nitro/fx.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/Model.h"
#include "Main/Res/ResArc.h"

extern "C" {

extern const char *data_0208cc88;
extern const char *data_0208cc94;
void func_02041c5c(void *m, void *fn);
void func_02041c20(void *m, s32 a, void *b);
BOOL Obj02152e5c_LoadModel(void *self);
void func_ov000_0215ec44(UiPanel *self);
void Obj0215e8b0_LoadModel(UiPanel *self);
void *func_ov000_021c77bc(u8 *self, u16 *cmd, void *arr, u16 *count);
void *func_ov000_021c782c(u8 *self, void *req, void *buf, u16 *count);

void LoBase021ccb54_021ccbe0_Setup(LoBase021ccb54_021ccbe0 *self) {
    ListRow *p;
    Model *m;
    UiPanel *o;

    self->hidden = 0;
    self->slideMode = 1;
    {
        s32 z = self->posZ;
        self->slideX = -(self->width + 0x20);
        self->slideZ = z;
    }
    self->slideY = 0;
    p = self->unk_94;
    if (p != NULL) {
        self->height = self->rows * p->height;
    } else {
        self->height = self->rows * 0xc;
    }
    self->height += 0xf;
    self->unk_c0 = (self->height - 0x14) << 12;
    if (self->unk_98 < self->rows) {
        self->unk_c8 = 0x1000;
    } else {
        self->unk_c8 = FX_Div(self->rows << 12, self->unk_98 << 12);
    }
    self->unk_c4 = FX_Div(self->unk_9c << 12, self->unk_98 << 12);
    if (self->unk_b4 == (s32)0x80000000) {
        self->unk_b4 = 0x4000;
    }
    if (self->unk_b0 == (s32)0x80000000) {
        if (self->flags & 0x40000) {
            self->unk_b0 = (((self->width << 12) - 0x20000) >> 12) - 4;
        } else {
            self->unk_b0 = self->width - 4;
        }
    }
    if (self->unk_b8 == (s32)0x80000000) {
        self->unk_b8 = 0x20000;
    }
    self->unk_a0 = self->unk_94;
    if (Obj02152e5c_LoadModel(self)) {
        TexObj_SelectImage(self->model, 0, 2);
        TexObj_SelectImage(self->model, 0, 4);
        TexObj_SelectImage(self->model, 0, 6);
        func_02041c5c(self->model, (void *)func_ov000_021c77bc);
        func_02041c20(self->model, 2, self);
    }
    if (self->flags & 0x400000) {
        m = (Model *)Heap_Alloc(sizeof(Model));
        if (m) {
            const char *arc;
            const char *name;
            name = data_0208cc88;
            arc = data_0208cc94;
            PlttRes_Init_02041218(&m->pltt);
            TexObj_Init(m, name, 0);
            STD_CopyString(m->name, arc);
        }
        self->unk_84 = m;
        TexObj_SetRes(self->unk_84, ResList_FindType2(ResMgr_GetArcList(m->name), self->unk_84->unk_04c));
        self->unk_84->flags |= 2;
        TexObj_SelectImage(self->unk_84, 0, 6);
        func_02041c20(self->unk_84, 6, self);
        if (self->flags & 0x800000) {
            TexObj_SelectImage(self->unk_84, 0, 7);
        }
        func_02041c5c(self->unk_84, (void *)func_ov000_021c782c);
    }
    if (self->unk_90 == NULL) {
        o = (UiPanel *)Heap_Alloc(sizeof(UiPanel));
        if (o != NULL) {
            func_ov000_0215ec44(o);
        }
        self->unk_90 = o;
        Obj0215e8b0_LoadModel(o);
        self->unk_90->width = self->unk_b0 << 12;
        self->unk_90->model->flags &= ~0x200000;
    }
    self->busy = 1;
}
}
