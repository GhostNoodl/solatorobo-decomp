#include "ov002/ov002.h"

extern "C" {

void func_02041d8c(void *a);

void func_ov002_021e0c28(void *a);

void func_ov002_021e1148(void *a, u16 b);

void func_ov002_021e23ac(void *self) {
    if (FIELD(self, 0x41, u8) != 0) {
        if ((FIELD(self, 0x41, u8) & 1) && func_02054f10(FIELD(self, 0x4, void *), 0) != 0) {
            func_02041d8c(FIELD(self, 0x4, void *));
            FIELD(self, 0x41, u8) &= ~1;
        }
        if ((FIELD(self, 0x41, u8) & 2) && func_02054f10(FIELD(self, 0x8, void *), 0) != 0) {
            func_02041d8c(FIELD(self, 0x8, void *));
            FIELD(self, 0x41, u8) &= ~2;
        }
        if ((FIELD(self, 0x41, u8) & 4) && func_02054f10(FIELD(self, 0xc, void *), 0) != 0) {
            func_02041d8c(FIELD(self, 0xc, void *));
            FIELD(self, 0x41, u8) &= ~4;
        }
        if ((FIELD(self, 0x41, u8) & 8) && func_02054f10(FIELD(self, 0x10, void *), 0xffff) != 0) {
            FIELD(self, 0x41, u8) &= ~8;
        }
        if (FIELD(self, 0x41, u8) != 0) {
            return;
        }
    }
    {
        s32 i;
        u8 *w;
        for (i = 0; i < 5; i++) {
            func_ov002_021e0c28((&FIELD(self, 0x14, void *))[i]);
        }
        w = FIELD(self, 0x28, u8 *);
        if (w == NULL) {
            return;
        }
        if (FIELD(w, 0x26, u16) != FIELD(w, 0x24, u16)) {
            FIELD(w, 0x26, u16) = FIELD(w, 0x24, u16);
            func_ov002_021e1148(w, FIELD(w, 0x26, u16));
            FIELD(w, 0x29, u8) = 2;
        }
        for (i = 0; i < 4; i++) {
            (&FIELD(w, 0x8, VObject *))[i]->v0x8c();
        }
        FIELD(w, 0x4, VObject *)->v0x8c();
        if (FIELD(w, 0x29, u8) != 0) {
            FIELD(w, 0x29, u8)--;
        }
    }
}

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

void func_ov002_021e28b0(void *self);

void func_ov002_021e0ff8(void *self, void *model);

void func_ov002_021e2528(void *self) {
    s32 i;
    if (FIELD(self, 0x41, u8)) {
        return;
    }
    func_ov002_021e28b0(self);
    {
        void *m = FIELD(self, 0x8, void *);
        FIELD(m, 0x10c, s32) = 0;
        FIELD(m, 0x110, s32) = 0;
    }
    ov002_Model_PlayPart(FIELD(self, 0x8, void *), 0);
    for (i = 0; i < 5; i++) {
        u8 *e = ((u8 **)((u8 *)self + 0x14))[i];
        if (FIELD(e, 0x4, VObject *) != NULL) {
            FIELD(e, 0x4, VObject *)->v0x20(FIELD(e, 0xc, s32) + (FIELD(e, 0x1c, s32) - FIELD(FIELD(e, 0x4, void *), 0x44, s32)) / 2, FIELD(e, 0x10, s32));
            FIELD(e, 0x4, VObject *)->v0x90();
        }
    }
    if (FIELD(self, 0x28, void *) != NULL) {
        func_ov002_021e0ff8(FIELD(self, 0x28, void *), FIELD(self, 0xc, void *));
    }
    ov002_Model_PlayPart(FIELD(self, 0x4, void *), 0);
}

}
