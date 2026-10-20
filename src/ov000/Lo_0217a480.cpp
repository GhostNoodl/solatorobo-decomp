#include "ov000/LoCommon.h"

typedef struct {
    u32 lo : 16;
    u32 b16 : 8;
    u32 hi : 8;
} W518_0217a480;

extern "C" {
extern u8 *data_0214a424;
extern void *data_02097e4c;
void func_0206c620(void *p);
void func_0206c670(void *p);
void func_ov000_0217a328(u8 *self, s32 a, s32 b);
BOOL func_ov000_0217a034(void *self, s32 msg);
void func_02049a48(void *mgr, s32 id, s32 a, s32 b, s32 c);

static inline u8 Raw0217a480(u8 *g) {
    return LFLD(W518_0217a480, g, 0x518).b16;
}

static inline u8 Lvl0217a480(u8 *g) {
    return Raw0217a480(g) & ~0xc0;
}

static inline BOOL IsB1_0217a480(void *p) {
    return LBIT(p, 0x48).b1 ? TRUE : FALSE;
}

static inline BOOL IsB2_0217a480(void *p) {
    return LBIT(p, 0x48).b2 ? TRUE : FALSE;
}

void func_ov000_0217a480(u8 *self) {
    if (LFLD(VObj *, self, 0x48) != NULL && !LFLD(VObj *, self, 0x48)->vfunc_1c()) {
        LO_FREE_V(self, 0x48);
    }
    if (LFLD(VObj *, self, 0x44) != NULL) {
        LFLD(VObj *, self, 0x44)->vfunc_0c();
    }
    switch (LFLD(s32, self, 0x3c)) {
    case 0:
        if (LFLD(s32, self, 0xc) == 0) {
            if (LFLD(VObj *, self, 0x48) != NULL) {
                return;
            }
            LFLD(void *, LoSwitchTaskC(3, 0), 0x30) = (void *)func_ov000_0217a034;
            ((VObj *)self)->vfunc_48();
            LFLD(s32, self, 0x3c) = 1;
        } else if (LFLD(s32, self, 0xc) == 1) {
            LFLD(s32, self, 0x3c) = 2;
        }
        break;
    case 1:
        if (LBIT(self, 4).b1 ? TRUE : FALSE) {
            return;
        }
        if (!((VObj *)self)->vfunc_54()) {
            return;
        }
        if (LFLD(s32, self, 0x4c) != -1) {
            LFLD(s32, self, 0x3c) = 2;
            return;
        }
        ((VObj *)self)->vfunc_0c(0);
        LFLD(s32, self, 0x3c) = 6;
        break;
    case 2: {
        u8 *g;
        LFLD(u8, data_02097dd0, 0x31) = 1;
        LFLD(s32, self, 0x40) = 0;
        if (LFLD(s32, self, 0xc) == 0) {
            func_0206c620(data_0214a424);
        } else if (LFLD(s32, self, 0xc) == 1) {
            func_0206c670(data_0214a424);
        }
        LBIT(LFLD(void *, self, 0x44), 0x48).b0 = TRUE;
        LFLD(u32, LFLD(void *, self, 0x44), 0x48) |= 0x20;
        g = data_0214a424;
        if (Lvl0217a480(g) > 0x14) {
            u16 n = LFLD(u8, g, 8);
            u8 *q = LFLD(u8 *, self, 0x44);
            LFLD(u32, q, 0x48) |= 0x210;
            LFLD(s32, q, 0x40) = n;
        } else {
            u16 n = LFLD(u8, g, 8);
            u8 *q = LFLD(u8 *, self, 0x44);
            LFLD(u32, q, 0x48) |= 0x200;
            LFLD(s32, q, 0x40) = n;
        }
        func_ov000_0217a328(self, 0x79, -1);
        LFLD(s32, self, 0x3c) = 3;
        break;
    }
    case 3:
        LFLD(s32, self, 0x40)++;
        if (IsB1_0217a480(LFLD(void *, self, 0x44))) {
            if (LFLD(s32, self, 0x40) <= 0x3c) {
                return;
            }
            LFLD(u32, LFLD(void *, self, 0x48), 0xc) |= 0x40000;
            LFLD(s32, self, 0x3c) = 4;
        } else {
            if (!IsB2_0217a480(LFLD(void *, self, 0x44))) {
                return;
            }
            func_ov000_0217a328(self, 0x8000, 0x77);
            LFLD(s32, self, 0x3c) = 5;
        }
        break;
    case 4:
        if (LFLD(VObj *, self, 0x48) != NULL) {
            return;
        }
        if (LFLD(s32, self, 0xc) == 0) {
            func_02049a48(data_02097e4c, 0x85, -1, -1, -1);
            func_ov000_0217a328(self, 0x7a, -1);
        }
        LFLD(s32, self, 0x3c) = 5;
        break;
    case 5:
        LFLD(u8, data_02097dd0, 0x31) = 0;
        if (LFLD(VObj *, self, 0x48) != NULL) {
            return;
        }
        ((VObj *)self)->vfunc_0c(0);
        LFLD(s32, self, 0x3c) = 6;
        break;
    }
}

}
