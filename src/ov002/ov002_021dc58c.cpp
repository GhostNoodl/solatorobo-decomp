#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e3b40(s32 *out, s32 x, s32 z, s32 *origin);

void func_02041c20(void *a, int b, void *c);

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

static inline void updateModel(u8 *m) {
    s32 v[3];
    func_ov002_021e3b40(v, FIELD(m, 0x74, s32), FIELD(m, 0x78, s32), (s32 *)(m + 0x7c));
    v[1] = FIELD(m, 0x84, s32);
    FIELD(m, 0x38, s32) = v[0];
    FIELD(m, 0x3c, s32) = v[1];
    FIELD(m, 0x40, s32) = v[2];
    if (FIELD(m, 0x1c, void *) != NULL && func_0203e63c(FIELD(m, 0x20, void *))) {
        NNS_G3dGlbSetBaseTrans(m + 0x38);
        NNS_G3dGlbSetBaseScale(m + 0x44);
        MI_Copy36B(m + 0x50, data_020928b4);
        NNS_G3dGlb.fc &= ~0xa4;
        NNS_G3dGlbFlushVP();
        NNS_G3dDraw(FIELD(m, 0x1c, void *));
        NNS_G3dGeFlushBuffer();
    }
}

void func_ov002_021dc58c(void *self, void *ev) {
    if (FIELD(self, 0x10, void *) != NULL) {
        func_02041c20(FIELD(self, 0x10, void *), 6, FIELD(FIELD(ev, 0x4, u8 *), 0x6c, void *));
        ov002_Model_PlayPart(FIELD(self, 0x10, void *), 6);
    }
    if (FIELD(self, 0x18, s32) != 20 && FIELD(self, 0x18, s32) / 10 != 0) {
        u8 *m = FIELD(self, 0x14, u8 *);
        FIELD(m, 0x74, s32) = FIELD(self, 0x24, s32);
        FIELD(m, 0x78, s32) = FIELD(self, 0x28, s32);
        updateModel(FIELD(self, 0x14, u8 *));
    }
    if (FIELD(self, 0xc, VObject *) != NULL) {
        FIELD(self, 0xc, VObject *)->v0x20();
    }
    FIELD(FIELD(self, 0x8, u8 *), 0x1d4, u8) = FIELD(self, 0x18, s32) == 20;
    func_ov002_021d7988(FIELD(self, 0x8, void *));
}

void func_ov002_021d9ed8(void *w, void *a, int b);

void func_ov002_021dd7f0(void *self, void *a, void *b, int c);

void func_ov002_021dc730(void *self) {
    BOOL done;
    u8 *w;
    u8 *a;
    u8 *next;
    w = FIELD(FIELD(self, 0x4, u8 *), 0x4, u8 *);
    switch (FIELD(self, 0x18, s32)) {
    case 0:
        for (a = FIELD(w, 0x6c, u8 *); a != NULL; a = FIELD(a, 0x70, u8 *)) {
            if (FIELD(a, 0x4a, u8) == 1 && FIELD(a, 0x6c, u8) && FIELD(a, 0xa4, s32) == 0) {
                FIELD(a, 0xa4, s32) = 0xd2;
                FIELD(a, 0xa8, s32) = 0xd2;
                FIELD(a, 0xac, s32) = 10;
            }
        }
        FIELD(self, 0x18, s32)++;
    case 1:
        done = TRUE;
        a = FIELD(w, 0x6c, u8 *);
        while (a != NULL) {
            next = FIELD(a, 0x70, u8 *);
            if (FIELD(a, 0x4a, u8) == 1 && FIELD(a, 0x6c, u8)) {
                if (FIELD(a, 0xac, s32) == 3) {
                    func_ov002_021d9ed8(w, a, 1);
                } else {
                    done = FALSE;
                }
            }
            a = next;
        }
        if (done) {
            func_ov002_021dd7f0(self, (u8 *)self + 0x24, (u8 *)self + 0x24, 1);
            FIELD(self, 0x18, s32) = 10;
        }
        break;
    }
}

}
