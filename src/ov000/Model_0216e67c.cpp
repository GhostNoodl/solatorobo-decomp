#include "types.h"
#include "ov000/ModelPart.h"
#include "Main/Gfx/Model.h"
#include "Main/Res/ResArc.h"
#include "ov000/LoTimer.h"

extern "C" {
extern char data_0214b105[];
extern const char *data_0208cb7c;
extern const char *data_0208cc94;
extern const char *data_0208cc88;
void *Heap_Alloc(u32 size);
void func_02041c34(void *model, s32 a, void *cb, void *arg);
void *func_ov000_0216d5b0(u8 *self, u16 *cmd, void *arr, u16 *count);

void func_ov000_0216e67c(LoTimer *self) {
    void *res;
    Model *m;
    Model *m2;
    void *res2;
    if (self->built == 1) {
        return;
    }
    res = ResList_FindType2(ResMgr_GetArcList(data_0214b105), data_0208cb7c);
    m = (Model *)Heap_Alloc(sizeof(Model));
    if (m) {
        const char *n = data_0208cb7c;
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
    res2 = ResList_FindType2(ResMgr_GetArcList(data_0208cc94), data_0208cc88);
    m2 = (Model *)Heap_Alloc(sizeof(Model));
    if (m2) {
        const char *n = data_0208cc88;
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
    func_02041c34(self->unk_14, 0x1e, (void *)func_ov000_0216d5b0, self);
    TexObj_SelectImage(self->unk_14, 0, 0x1f);
    func_02041c34(self->unk_14, 0x1f, (void *)func_ov000_0216d5b0, self);
    TexObj_SelectImage(self->unk_14, 0, 0x20);
    self->unk_14->flags |= 0x80000;
    MODEL_FLAGS(self->unk_14)->alpha = 0x1e;
    self->b17 = 1;
    self->built = 1;
}
}
