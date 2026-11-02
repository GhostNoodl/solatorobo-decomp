#include "ov000/LoCommon.h"

typedef struct {
    u8 unk_00[0x10];
    u16 cont;
    u16 trig;
} LoPad02155770;

extern "C" {

extern LoPad02155770 *data_02097dc8;
extern void *data_02149ef8;
void *MsgRes_GetString(void *a, s32 b);
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
BOOL func_ov000_021521ec(void *self, void *msg);

struct Obj02155770 : public VObj {
    s32 unk_04;
    s32 unk_08;
    u32 unk_0c;
    u8 unk_10[0x10];
    s32 unk_20;
    u8 unk_24[0x44];
    s16 unk_68;
    u8 unk_6a[0xa];
    VObj *unk_74;
    u8 unk_78[0x14];
    void *unk_8c;
    void *unk_90;
    void *unk_94;
    void *unk_98;
    s16 unk_9c;
    s16 unk_9e;
    u8 unk_a0[0x4];
    void *unk_a4;
    u8 unk_a8[0x9];
    s8 unk_b1;
    s8 unk_b2;
    s8 unk_b3;
};

static inline void Lo_OpenSub02155770(Obj02155770 *self, u16 a, s32 b, s32 c) {
    void *res = data_02149ef8;
    VObj *p;
    p = (VObj *)Heap_Alloc(0x1e4);
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
    self->unk_74 = p;
    LFLD(u16, p, 0x1d8) = a;
    LFLD(void *, self->unk_74, 0x1dc) = MsgRes_GetString(res, b);
    LFLD(u16, self->unk_74, 0x1e0) = 0;
    LFLD(s32, self->unk_74, 8) = self->unk_08;
    LFLD(s32, self->unk_74, 0x84) = c;
    self->unk_74->vfunc_08();
    LFLD(s16, self->unk_74, 0x68) = self->unk_68 + 0x200;
    LBIT(self, 0xc).b0 = 1;
}

static inline BOOL Lo_Active02155770(Obj02155770 *self) {
    return LBIT(self, 0xc).b0 ? FALSE : TRUE;
}

static inline BOOL Lo_Settled02155770(Obj02155770 *self) {
    BOOL r = FALSE;
    if (self->unk_98 == self->unk_a4 && self->unk_b3 == 0) {
        r = TRUE;
    }
    return r;
}

static inline BOOL Lo_Busy02155770(Obj02155770 *self) {
    return Lo_Settled02155770(self) ? FALSE : TRUE;
}

void func_ov000_02155770(Obj02155770 *self) {
    u16 cont;
    u16 trig;
    if (!Lo_Active02155770(self)) {
        return;
    }
    if (self->unk_98 == self->unk_a4 && LBIT(self, 0xc).b1) {
        LBIT(self, 0xc).b0 = 1;
        self->unk_04 = 1;
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
    if (self->unk_94 != NULL) {
        if (cont == 0) {
            self->unk_b3 = 0;
        }
        self->unk_b2--;
        if (self->unk_9e == 0) {
            if (self->unk_b2 < (self->unk_b3 >> 1)) {
                self->unk_b2 = 0;
                if (cont & 0x40) {
                    self->vfunc_ac(1, 0);
                } else if (cont & 0x80) {
                    self->vfunc_b4(1, 0);
                } else {
                    if (self->unk_9c > self->unk_20 && (self->unk_0c & 0x10000)) {
                        if (cont & 0x200) {
                            self->vfunc_b0(self->unk_20, 0);
                        } else if (cont & 0x100) {
                            self->vfunc_b8(self->unk_20, 0);
                        }
                    }
                    self->unk_b3 = 0;
                }
            } else if (trig & 3) {
                self->unk_b3 = 0;
            }
        }
    }
    if (Lo_Busy02155770(self)) {
        return;
    }
    if (self->unk_94 != NULL && (trig & 1)) {
        u8 *item = (u8 *)self->unk_98;
        if (item == NULL) {
            item = NULL;
        } else {
            s32 n = self->unk_b1;
            while (n-- != 0) {
                item = LFLD(u8 *, item, 0x2c);
            }
        }
        if (!self->vfunc_98(item)) {
            self->unk_0c |= 2;
        }
        return;
    }
    if (trig & 2) {
        if (!self->vfunc_98(NULL)) {
            self->unk_0c |= 2;
        }
        return;
    }
    if (self->unk_94 == NULL) {
        return;
    }
    if (!(trig & 0x400) || self->unk_8c == NULL) {
        return;
    }
    Lo_OpenSub02155770(self, 0x8f, 0x18, (s32)func_ov000_021521ec);
    self->unk_90 = self->unk_8c;
}

}
