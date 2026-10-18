#include "ov002/ov002.h"

extern "C" {

typedef struct Bits021eceb8 {
    u32 lo : 2;
    u32 b : 5;
    u32 c : 6;
    u32 hi : 19;
} Bits021eceb8;

static inline bool isMode3(void *self) {
    return FIELD(self, 0x8, s32) == 3;
}

void func_ov002_021eceb8(void *self) {
    s32 x;
    s32 y;
    s32 z;
    void *model;
    void *res;
    void *anim;
    void *arg;
    void *t;
    if (FIELD(self, 0x38, void *) == NULL || !FIELD(self, 0x48, u8)) {
        return;
    }
    x = FIELD(self, 0x3c, s32) & -0x1000;
    y = FIELD(self, 0x40, s32) & -0x1000;
    {
        BOOL m3 = isMode3(self);
        if (m3) {
            z = -0x2000;
        } else {
            z = -0x1ccd;
        }
    }
    FIELD(FIELD(self, 0x38, void *), 0x6c, Bits021eceb8).c = (u32)func_02043d48(data_02097d48 + 0x8b0);
    FIELD(FIELD(self, 0x38, void *), 0x6c, Bits021eceb8).b = FIELD(self, 0x48, u8);
    {
        u8 *m = FIELD(self, 0x38, u8 *);
        FIELD(m, 0xfc, s32) = x;
        FIELD(m, 0x100, s32) = y;
    }
    FIELD(FIELD(self, 0x38, void *), 0x150, s32) = z;
    model = FIELD(self, 0x38, void *);
    if ((res = FIELD(model, 0x28, void *)) == NULL) {
        return;
    }
    anim = NULL;
    if (FIELD(model, 0x80, s32) > 0) {
        anim = FIELD(model, 0x78, void *);
    }
    if (anim != NULL && (t = FIELD(anim, 0x4, void *)) != NULL) {
        arg = FIELD(t, 0x30, void *);
    } else {
        void *e = func_02023390(FIELD(res, 0xc, void *), 0);
        arg = func_02023410(FIELD(res, 0x4, void *), **(u16 **)FIELD(e, 0xc, void *));
    }
    func_02042628(model, arg, anim, 0);
}

}
