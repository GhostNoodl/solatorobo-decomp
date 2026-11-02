#include "ov002/ov002.h"
#include "ov000/ModelPart.h"

extern "C" {

Ov002HudInfo *Ov002Vt_021f000c_Dtor(Ov002HudInfo *self) {
    int i;
    *(VFunc **)self = data_ov002_021f000c;
    for (i = 0; i < 4; i++) {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(self->lines[i]);
        HEAP_POP(saved);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(self->unk_04);
        HEAP_POP(saved);
    }
    return self;
}

Ov002HudInfo *Ov002Vt_021f000c_DtorDelete(Ov002HudInfo *self) {
    int i;
    *(VFunc **)self = data_ov002_021f000c;
    for (i = 0; i < 4; i++) {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(self->lines[i]);
        HEAP_POP(saved);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(self->unk_04);
        HEAP_POP(saved);
    }
    Heap_Free(self);
    return self;
}

void func_ov002_021e0ff8(Ov002HudInfo *self, Model *model) {
    s32 x;
    s32 y;
    if (self->shownId == 0xffff) {
        return;
    }
    x = self->pos.x >> 12;
    y = self->pos.y >> 12;
    if (self->delay == 0) {
        int i;
        Ov002Text2 *o;
        s32 by;
        /* i has a second, never-taken definition so the backend keeps the
           i = 0 / by order of the source in the loop preheader. */
        i = 0;
        if ((u32)self & 3) {
            i = 0;
        }
        by = y + 0x14;
        do {
            o = self->lines[i];
            o->vfunc_20(i < 2 ? x + 0x12 : x + 0x8a, by + (i % 2) * 16);
            o->vfunc_90();
        } while (++i < 4);
        o = self->unk_04;
        o->vfunc_20(x + 0x8c + (0x4c - o->width) / 2, y + 4);
        self->unk_04->vfunc_90();
    }
    if (model == NULL) {
        return;
    }
    model->unk_10c = x << 12;
    model->unk_110 = (y - 0x88) << 12;
    Model_PlayPart(model, 0);
}

}
