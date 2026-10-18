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
        anim = func_02023410(FIELD(res, 0x4, void *), **(u16 **)FIELD(func_02023390(FIELD(res, 0xc, void *), idx), 0xc, void *));
    }
    func_02042628(model, anim, part, 0);
}

void func_ov002_021cdf58(void *self) {
    if (FIELD(self, 0x3c, void *) != NULL && func_02054f10(FIELD(self, 0x3c, void *), 0xffff)) {
        FIELD(FIELD(self, 0x3c, void *), 0x150, s32) = -0x1fe66;
        ov002_Model_PlayPart(FIELD(self, 0x3c, void *), 0);
    }
    if (FIELD(self, 0x24, s32) == 0) {
        return;
    }
    func_ov000_0217357c(self);
    FIELD(self, 0x40, VObject *)->v0x20();
    FIELD(self, 0x44, VObject *)->v0x20();
}

}
