#include "types.h"
#include "ov000/MessageQueue.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"
#include "ov000/ObjLayouts.h"
#include "ov000/Obj0216ad04.h"

extern "C" {
extern MessageQueue021cb980 *data_ov000_021ccd30;
void TexObj_SetOamFunc(void *a, int b, void *c, void *d);
void *func_ov000_0216ac14(void *self, u16 *msg, void *arr, u16 *cnt);

static inline Lo021cb798 *GetObj0216b1b4(void) {
    ListBuffer021cb940 *o = data_ov000_021ccd30->unk_11c;
    return o != NULL ? o->unk_58 : NULL;
}

static inline BOOL SubFlag0216b1b4(Lo021cb744 *s) {
    return s->unk_0c_3 ? TRUE : FALSE;
}

static inline BOOL IsFlag0216b1b4(MessageQueue021cb980 *g) {
    Lo021cb744 *s;
    if (g->unk_11c == NULL) {
        return FALSE;
    }
    s = g->unk_11c->unk_64;
    if (s != NULL) {
        return SubFlag0216b1b4(s) != 0 ? TRUE : FALSE;
    }
    return FALSE;
}

static inline void SetPos0216b1b4(Model *o, s32 x, s32 y) {
    o->x = x;
    o->y = y;
}

void func_ov000_0216b1b4(Obj0216ad04 *self) {
    s32 base;
    if (GetObj0216b1b4() == NULL) {
        return;
    }
    if (self->state != 7 && self->state != 8) {
        return;
    }
    base = IsFlag0216b1b4(data_ov000_021ccd30) ? 0xae000 : 0xb6000;
    SetPos0216b1b4(self->model, -0x53000, (base + (s32)(((s64)self->ratio * 0x40000 + 0x800) >> 12) - 0x61000) & ~0xfff);
    TexObj_SetOamFunc(self->model, 6, (void *)func_ov000_0216ac14, self);
    self->model->unk_150 = -0x1f80;
    Model_PlayPart(self->model, 6);
    Model_PlayPart(self->model, 7);
    Model_PlayPart(self->model, self->part);
    self->model->unk_150 = -0x2000;
    Model_PlayPart(self->model, 0xb);
}
}
