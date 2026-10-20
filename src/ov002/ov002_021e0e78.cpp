#include "ov002/ov002.h"

extern "C" {

static inline void *ov002_Model_GetPart(void *self, int idx) {
    if (idx >= FIELD(self, 0x80, s32)) {
        return NULL;
    }
    return (u8 *)FIELD(self, 0x78, void *) + idx * 0x28;
}

static inline void ov002_Model_PlayPart(void *model, int idx) {
    void *res = FIELD(model, 0x28, void *);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = ov002_Model_GetPart(model, idx);
    if (part != NULL && FIELD(part, 0x4, void *) != NULL) {
        anim = FIELD(FIELD(part, 0x4, void *), 0x30, void *);
    } else {
        anim = NNS_G2dGetCellDataByIdx(FIELD(res, 0x4, void *), **(u16 **)FIELD(NNS_G2dGetAnimSequenceByIdx(FIELD(res, 0xc, void *), idx), 0xc, void *));
    }
    func_02042628(model, anim, part, 0);
}

void *func_ov002_021e0e78(void *self) {
    int i;
    *(VFunc **)self = data_ov002_021f000c;
    for (i = 0; i < 4; i++) {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(((VObject **)((u8 *)self + 8))[i]);
        HEAP_POP(saved);
    }
    {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(FIELD(self, 4, VObject *));
        HEAP_POP(saved);
    }
    return self;
}

void *func_ov002_021e0f34(void *self) {
    int i;
    *(VFunc **)self = data_ov002_021f000c;
    for (i = 0; i < 4; i++) {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(((VObject **)((u8 *)self + 8))[i]);
        HEAP_POP(saved);
    }
    {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(FIELD(self, 4, VObject *));
        HEAP_POP(saved);
    }
    func_0203de1c(self);
    return self;
}

void func_ov002_021e0ff8(void *self, void *model) {
    s32 x;
    s32 y;
    if (FIELD(self, 0x26, u16) == 0xffff) {
        return;
    }
    x = FIELD(self, 0x18, s32) >> 12;
    y = FIELD(self, 0x1c, s32) >> 12;
    if (FIELD(self, 0x29, u8) == 0) {
        int i;
        VObject *o;
        s32 by;
        /* i has a second, never-taken definition so the backend keeps the
           i = 0 / by order of the source in the loop preheader. */
        i = 0;
        if ((u32)self & 3) {
            i = 0;
        }
        by = y + 0x14;
        do {
            o = ((VObject **)((u8 *)self + 8))[i];
            o->v0x20(i < 2 ? x + 0x12 : x + 0x8a, by + (i % 2) * 16);
            o->v0x90();
        } while (++i < 4);
        o = FIELD(self, 4, VObject *);
        o->v0x20(x + 0x8c + (0x4c - FIELD(o, 0x44, s32)) / 2, y + 4);
        FIELD(self, 4, VObject *)->v0x90();
    }
    if (model == NULL) {
        return;
    }
    FIELD(model, 0x10c, s32) = x << 12;
    FIELD(model, 0x110, s32) = (y - 0x88) << 12;
    ov002_Model_PlayPart(model, 0);
}

}
