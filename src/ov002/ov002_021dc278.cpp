#include "ov002/ov002.h"

extern "C" {

void func_ov002_021dc730(void *self);
void func_ov002_021dc83c(void *self);
void func_ov002_021dcf00(void *self);
void func_ov002_021dd130(void *self);
void func_ov002_021dd29c(void *self);
void func_ov002_021dd434(void *self);
void func_ov002_021dd9dc(void *self);

static inline void ov002_Anim_Tick(void *a) {
    s32 v = FIELD(a, 0x30, s32);
    if (FIELD(a, 0x24, s32 *) != NULL) {
        *FIELD(a, 0x24, s32 *) = v;
    }
    if (FIELD(a, 0x28, s32 *) != NULL) {
        *FIELD(a, 0x28, s32 *) = v;
    }
    if (FIELD(a, 0x2c, s32 *) != NULL) {
        *FIELD(a, 0x2c, s32 *) = v;
    }
    FIELD(a, 0x30, s32) = (FIELD(a, 0x30, s32) + 0x1000) % FIELD(a, 0x34, s32);
}

static inline BOOL ov002_Msg_IsDone(void *m) {
    return FIELD(m, 4, s32) == 5;
}

void func_ov002_021dc278(void *self, void *other) {
    FIELD(self, 4, void *) = other;
    ov002_Anim_Tick(FIELD(self, 0x14, void *));
    if (FIELD(self, 0xc, VObject *) != NULL) {
        FIELD(self, 0xc, VObject *)->v0x1c();
    }
    {
        void *m = FIELD(self, 8, void *);
        ov002_Anim_Tick(m);
        FIELD(m, 0x1d8, u32) = (u16)(FIELD(m, 0x1d8, u32) + 1);
    }
    switch (FIELD(self, 0x18, s32) / 10 * 10) {
    case 0:
        func_ov002_021dc730(self);
        break;
    case 10:
        func_ov002_021dc83c(self);
        break;
    case 20:
        func_ov002_021dcf00(self);
        break;
    case 30:
        func_ov002_021dd130(self);
        break;
    case 40:
        func_ov002_021dd29c(self);
        break;
    case 50:
        func_ov002_021dd434(self);
        break;
    case 60:
        if (ov002_Msg_IsDone(FIELD(self, 0xc, void *))) {
            s32 r = FIELD(self, 0x1c, s32);
            if (r == 1 || r == -1) {
                func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
            } else if (r == 0) {
                FIELD(self, 0x18, s32) = 0x46;
                break;
            } else if (r == 2) {
                func_ov002_021dd9dc(self);
            } else {
                break;
            }
            FIELD(self, 0x18, s32) = 10;
        }
        break;
    case 70: {
        u8 *o4 = FIELD(FIELD(self, 4, void *), 4, u8 *);
        s32 row = FIELD(self, 0x28, s32);
        void *q = FIELD(o4, 4, void *);
        s32 col = FIELD(self, 0x24, s32);
        u8 *base;
        u8 *e;
        if (q == NULL || (base = FIELD(o4, 0x70, u8 *)) == NULL) {
            e = NULL;
        } else {
            e = base + (row * FIELD(FIELD(q, 0x6c, u8 *), 4, Nibbles16).n3 + col) * 0xc;
        }
        if (e[2] == 1) {
            u8 *t = FIELD(e, 8, u8 *);
            FIELD(t, 0xcd, u8) = 0;
            FIELD(t, 0x9c, s32) = 0xf85;
        } else if (e[2] == 2) {
            FIELD(FIELD(e, 8, u8 *), 0x9c, u8) = 0;
        }
        {
            void *o = FIELD(self, 4, void *);
            FIELD(o, 0x10, s32) = 0;
            FIELD(o, 0xc, s32) = 0x28;
        }
        FIELD(self, 0x18, s32) = 0x50;
        break;
    }
    }
    FIELD(self, 4, void *) = NULL;
}

}
