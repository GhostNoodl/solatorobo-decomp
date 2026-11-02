#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "ov000/ModelPart.h"
#include "Main/Res/ResArc.h"

extern "C" {
extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;
extern const char *data_0208cc88;
extern const char *data_0208cc94;
void func_02041c5c(void *m, void *fn);
void func_02041c20(void *m, s32 a, void *b);
void *func_ov000_021540b0(void *self, u16 *msg, void *g, u16 *count);
void *func_ov000_02154128(u8 *self, void *req, void *buf, u16 *count);

typedef struct {
    u32 b0 : 1;
    u32 b1 : 2;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 rest : 27;
} PFlags0215429c;

class Panel0215429c {
public:
    PFlags0215429c flags;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    u8 *model;
    static void *operator new(unsigned long size) { return Heap_Alloc(size); }
    Panel0215429c() {
        *(u32 *)&flags = 0;
        unk_04 = 0;
        unk_08 = 0;
        unk_0c = 0;
        unk_1c = 0;
        unk_18 = 0;
        unk_10 = 0x80000;
        unk_14 = 0xf000;
        unk_20 = 0;
        unk_24 = 0;
        model = NULL;
    }
};

void Obj0215e8b0_LoadModel(Panel0215429c *p);

static inline BOOL LoadModel0215429c(UiList *self) {
    if (self->model != NULL) {
        return TRUE;
    }
    if (self->flag6 ? TRUE : FALSE) {
        self->model = new ModelObj(data_0208cb84, data_0208cc8c);
    } else {
        self->model = new ModelObj(data_0208cb74, data_0208cca0);
    }
    {
        ResList *a = ResMgr_GetArcList(self->model->name);
        TexObj_SetRes(self->model, ResList_FindType2(a, self->model->unk_04c));
    }
    self->model->flags |= 2;
    TexObj_SelectImage(self->model, 0, 7);
    return TRUE;
}

void UiList_Setup(UiList *self) {
    if (!(self->flags & 0x20000)) {
        self->rows = self->itemCount;
    }
    self->height = self->vfunc_44();
    if (LoadModel0215429c(self)) {
        if (self->flags & 0x40000) {
            TexObj_SelectImage(self->model, 0, 2);
            TexObj_SelectImage(self->model, 0, 10);
            TexObj_SelectImage(self->model, 0, 6);
        }
        func_02041c5c(self->model, (void *)func_ov000_021540b0);
        func_02041c20(self->model, 2, self);
        func_02041c20(self->model, 6, self);
    }
    if (self->flags & 0x400000) {
        Model *m = (Model *)Heap_Alloc(sizeof(Model));
        if (m) {
            const char *arc;
            const char *name;
            name = data_0208cc88;
            arc = data_0208cc94;
            PlttRes_Init_02041218(&m->pltt);
            TexObj_Init(m, name, 0);
            STD_CopyString(m->name, arc);
        }
        self->unk_b4 = m;
        {
            ResList *a = ResMgr_GetArcList(m->name);
            TexObj_SetRes(self->unk_b4, ResList_FindType2(a, self->unk_b4->unk_04c));
        }
        self->unk_b4->flags |= 2;
        TexObj_SelectImage(self->unk_b4, 0, 6);
        func_02041c20(self->unk_b4, 6, self);
        if (self->flags & 0x800000) {
            TexObj_SelectImage(self->unk_b4, 0, 7);
        }
        func_02041c5c(self->unk_b4, (void *)func_ov000_02154128);
    }
    if ((Panel0215429c *)self->panel == NULL) {
        self->panel = (UiPanel *)new Panel0215429c();
        if (self->flag6 ? TRUE : FALSE) {
            ((Panel0215429c *)self->panel)->flags.b4 = 1;
        }
        Obj0215e8b0_LoadModel((Panel0215429c *)self->panel);
        if (self->flags & 0x1000000) {
            ((Panel0215429c *)self->panel)->unk_10 = (self->width + 0x10) << 12;
            ((Panel0215429c *)self->panel)->flags.b0 = 1;
        } else {
            ((Panel0215429c *)self->panel)->unk_10 = (self->width + 0x10) << 12;
        }
    }
    self->slideMode = 1;
    self->slideY = 0;
    self->slideZ = 0;
    self->slideX = -(self->width + 0x10);
    self->busy = 1;
    self->vfunc_48(0, 0);
}

}
