#include "ov002/ov002.h"

extern "C" {

BOOL func_ov000_02191120(void *a);
void func_ov000_02191780(void *a);
s32 **func_ov000_02190a30(void *a, int b);
void func_ov002_021d9c04(void *self);
extern VFunc data_ov002_021eff10[];

typedef struct Key021db9e8 {
    s16 t;
    s16 a;
    s16 b;
} Key021db9e8;

extern Key021db9e8 data_ov002_021eeffc[];

static inline void *ov002_Step_ctor(void *self) {
    *(VFunc **)self = data_ov002_021eff10;
    FIELD(self, 0x4, s32) = 0;
    FIELD(self, 0x8, s32) = 0;
    FIELD(self, 0xc, s32) = 0;
    FIELD(self, 0x10, s32) = 0;
    FIELD(self, 0x14, s32) = 0;
    FIELD(self, 0x18, s32) = 0;
    FIELD(self, 0x1c, s32) = -1;
    FIELD(self, 0x20, u8) = 0;
    FIELD(self, 0x24, s32) = 0;
    FIELD(self, 0x28, s32) = 0;
    FIELD(self, 0x2c, s32) = 0;
    FIELD(self, 0x30, s32) = 0;
    FIELD(self, 0x34, u8) = 0;
    return self;
}

static inline void ov002_SetNext(void *self, void *a, s32 b) {
    FIELD(self, 0x10, void *) = a;
    FIELD(self, 0xc, s32) = b;
}

static inline u8 ov002_IsDone(void *p) {
    u8 r; if (FIELD(p, 0x4, s32) == 5) { r = TRUE; } else { r = FALSE; } return r;
}

static inline bool ov002_Ready(u8 *m) {
    return m[0x5d] != 0 && FIELD(m, 0x10, void *) != NULL && func_ov000_02191120(FIELD(m, 0x10, void *));
}

void func_ov002_021db9e8(void *self) {
    switch (FIELD(self, 0x14, s32)) {
    case 0:
        if (FIELD(self, 0x34, s32) <= 0 || ov002_Ready(FIELD(FIELD(self, 0x4, u8 *), 0x4, u8 *))) {
            FIELD(self, 0x34, s32) = 20;
            FIELD(self, 0x14, s32)++;
        } else {
            FIELD(self, 0x34, s32)--;
            return;
        }
    case 1:
        if (FIELD(self, 0x34, s32) <= 0) {
            void *p = func_0203dd9c(0x134);
            if (p != NULL) {
                p = ov002_Step_ctor(p);
            }
            ov002_SetNext(self, p, 10);
        } else {
            FIELD(self, 0x34, s32)--;
            return;
        }
    case 10:
    case 20:
    case 30:
        if (FIELD(self, 0xc, s32) != -1) {
            if (FIELD(self, 0x18, VObject *) != NULL) {
                FIELD(self, 0x18, VObject *)->v0x10(self);
                {
                    u32 saved;
                    HEAP_PUSH(saved);
                    DELETE_VOBJ(FIELD(self, 0x18, VObject *));
                    HEAP_POP(saved);
                }
            }
            FIELD(self, 0x1c, s32) = FIELD(self, 0x14, s32);
            FIELD(self, 0x18, void *) = FIELD(self, 0x10, void *);
            FIELD(self, 0x14, s32) = FIELD(self, 0xc, s32);
            FIELD(self, 0x10, void *) = NULL;
            FIELD(self, 0xc, s32) = -1;
            if (FIELD(self, 0x18, VObject *) != NULL) {
                FIELD(self, 0x18, VObject *)->v0x8(self);
            }
        }
        if (FIELD(self, 0x18, VObject *) == NULL) {
            FIELD(self, 0x8, s32) = 0;
            FIELD(self, 0x14, s32) = 40;
            FIELD(FIELD(self, 0x20, void *), 0xc, u32) |= 2;
            FIELD(FIELD(self, 0x24, void *), 0xc, u32) |= 2;
        } else {
            FIELD(self, 0x18, VObject *)->v0xc(self);
        }
        FIELD(self, 0x20, VObject *)->v0x1c();
        FIELD(self, 0x24, VObject *)->v0x1c();
        break;
    case 40:
        FIELD(self, 0x20, VObject *)->v0x1c();
        FIELD(self, 0x24, VObject *)->v0x1c();
        if (!ov002_IsDone(FIELD(self, 0x20, void *))) {
            return;
        }
        if (!ov002_IsDone(FIELD(self, 0x24, void *))) {
            return;
        }
        {
            Key021db9e8 *k;
            u8 *m = FIELD(FIELD(self, 0x4, u8 *), 0x4, u8 *);
            s32 x;
            func_ov000_02191780(FIELD(m, 0x10, void *));
            k = data_ov002_021eeffc;
            FIELD(m, 0x60, Key021db9e8 *) = k;
            {
                s32 **pp = func_ov000_02190a30(FIELD(m, 0x10, void *), 0);
                x = 0;
                if (*pp != NULL) {
                    x = **pp;
                }
            }
            while (k->t < (x + 0x1000) >> 12) {
                if (k->t < 0) {
                    k--;
                    break;
                }
                k++;
            }
            FIELD(m, 0x64, Key021db9e8 *) = k;
            m[0x5d] = 0;
            func_ov002_021d9c04(FIELD(self, 0x4, void *));
            FIELD(self, 0x14, s32) = 50;
        }
        break;
    case 50:
        break;
    }
}

}
