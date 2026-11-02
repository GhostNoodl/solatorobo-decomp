#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"
#include "Main/Res/ResArc.h"

extern "C" {

extern const char *data_0208cb84;
extern const char *data_0208cc8c;
extern const char *data_0208cb74;
extern const char *data_0208cca0;
extern const char *data_0208cc88;
extern const char *data_0208cc94;
void func_02041c20(void *model, s32 a, void *b);
void func_02041c5c(void *model, void *cb);
void *func_ov000_02160e28(u8 *self, u16 *cmd, void *arr, u16 *count);

static inline BOOL EnsureModel(Lo021cacd8 *self) {
    if (self->model) {
        return TRUE;
    }
    if (self->flag6 ? TRUE : FALSE) {
        MODEL_NEW(self->model, data_0208cb84, data_0208cc8c);
    } else {
        MODEL_NEW(self->model, data_0208cb74, data_0208cca0);
    }
    {
        ResList *a = func_02035d5c(self->model->name);
        void *b = func_02034d88(a, self->model->unk_04c);
        func_020417e0(self->model, b);
    }
    self->model->flags |= 2;
    func_02041d9c(self->model, 0, 7);
    return TRUE;
}

void func_ov000_02160ff8(Lo021cacd8 *self) {
    self->width = 0x50;
    self->height = 0x1e;
    self->posX = 0x80;
    self->posY = 0x60;
    self->slideMode = 0;
    self->color = 0x294a;
    MODEL_NEW(self->unk_84, data_0208cc88, data_0208cc94);
    func_020417e0(self->unk_84, func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88));
    self->unk_84->flags |= 2;
    func_02041d9c(self->unk_84, 0, 6);
    func_02041c20(self->unk_84, 6, self);
    func_02041d9c(self->unk_84, 0, 8);
    func_02041c5c(self->unk_84, (void *)func_ov000_02160e28);
    if (EnsureModel(self)) {
        func_02041d9c(self->model, 0, 10);
        self->model->flags |= 0x80000;
    }
}

}
