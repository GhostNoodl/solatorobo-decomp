#include "ov000/LoCommon.h"

typedef struct {
    u8 unk_00[0x10];
    u16 cont;
    u16 trig;
} LoPad02155770;

extern "C" {

extern LoPad02155770 *data_02097dc8;
extern void *data_02149ef8;
void *func_0204c0e8(void *a, s32 b);
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
BOOL func_ov000_021521ec(void *self, void *msg);

static inline void Lo_OpenSub02155770(void *self, u16 a, s32 b, s32 c) {
    void *res = data_02149ef8;
    VObj *p;
    p = (VObj *)func_0203dd9c(0x1e4);
    if (p) {
        *(void **)p = data_ov000_021cac60;
        p->vfunc_28();
        *(void **)p = data_ov000_021caec8;
        p->vfunc_28();
        *(void **)p = data_ov000_021cb1b0;
        p->vfunc_28();
        *(void **)p = data_ov000_021cb0b8;
        p->vfunc_28();
    }
    LFLD(VObj *, self, 0x74) = p;
    LFLD(u16, p, 0x1d8) = a;
    LFLD(void *, LFLD(VObj *, self, 0x74), 0x1dc) = func_0204c0e8(res, b);
    LFLD(u16, LFLD(VObj *, self, 0x74), 0x1e0) = 0;
    LFLD(s32, LFLD(VObj *, self, 0x74), 8) = LFLD(s32, self, 8);
    LFLD(s32, LFLD(VObj *, self, 0x74), 0x84) = c;
    LFLD(VObj *, self, 0x74)->vfunc_08();
    LFLD(s16, LFLD(VObj *, self, 0x74), 0x68) = LFLD(s16, self, 0x68) + 0x200;
    LBIT(self, 0xc).b0 = 1;
}

static inline BOOL Lo_Active02155770(VObj *self) {
    return LBIT(self, 0xc).b0 ? FALSE : TRUE;
}

static inline BOOL Lo_Settled02155770(VObj *self) {
    BOOL r = FALSE;
    if (LFLD(void *, self, 0x98) == LFLD(void *, self, 0xa4) && LFLD(s8, self, 0xb3) == 0) {
        r = TRUE;
    }
    return r;
}

static inline BOOL Lo_Busy02155770(VObj *self) {
    return Lo_Settled02155770(self) ? FALSE : TRUE;
}

void func_ov000_02155770(VObj *self) {
    u16 cont;
    u16 trig;
    if (!Lo_Active02155770(self)) {
        return;
    }
    if (LFLD(void *, self, 0x98) == LFLD(void *, self, 0xa4) && LBIT(self, 0xc).b1) {
        LBIT(self, 0xc).b0 = 1;
        LFLD(s32, self, 4) = 1;
        return;
    }
    if (LBIT(self, 0xc).b2) {
        return;
    }
    if (LBIT(self, 0xc).b1) {
        return;
    }
    cont = data_02097dc8->cont;
    trig = data_02097dc8->trig;
    if (LFLD(void *, self, 0x94) != NULL) {
        if (cont == 0) {
            LFLD(s8, self, 0xb3) = 0;
        }
        LFLD(s8, self, 0xb2)--;
        if (LFLD(s16, self, 0x9e) == 0) {
            if (LFLD(s8, self, 0xb2) < (LFLD(s8, self, 0xb3) >> 1)) {
                LFLD(s8, self, 0xb2) = 0;
                if (cont & 0x40) {
                    self->vfunc_ac(1, 0);
                } else if (cont & 0x80) {
                    self->vfunc_b4(1, 0);
                } else {
                    if (LFLD(s16, self, 0x9c) > LFLD(s32, self, 0x20) && (LFLD(u32, self, 0xc) & 0x10000)) {
                        if (cont & 0x200) {
                            self->vfunc_b0(LFLD(s32, self, 0x20), 0);
                        } else if (cont & 0x100) {
                            self->vfunc_b8(LFLD(s32, self, 0x20), 0);
                        }
                    }
                    LFLD(s8, self, 0xb3) = 0;
                }
            } else if (trig & 3) {
                LFLD(s8, self, 0xb3) = 0;
            }
        }
    }
    if (Lo_Busy02155770(self)) {
        return;
    }
    if (LFLD(void *, self, 0x94) != NULL && (trig & 1)) {
        u8 *item = LFLD(u8 *, self, 0x98);
        if (item == NULL) {
            item = NULL;
        } else {
            s32 n = LFLD(s8, self, 0xb1);
            while (n-- != 0) {
                item = LFLD(u8 *, item, 0x2c);
            }
        }
        if (!self->vfunc_98(item)) {
            LFLD(u32, self, 0xc) |= 2;
        }
        return;
    }
    if (trig & 2) {
        if (!self->vfunc_98(NULL)) {
            LFLD(u32, self, 0xc) |= 2;
        }
        return;
    }
    if (LFLD(void *, self, 0x94) == NULL) {
        return;
    }
    if (!(trig & 0x400) || LFLD(void *, self, 0x8c) == NULL) {
        return;
    }
    Lo_OpenSub02155770(self, 0x8f, 0x18, (s32)func_ov000_021521ec);
    LFLD(void *, self, 0x90) = LFLD(void *, self, 0x8c);
}

}
