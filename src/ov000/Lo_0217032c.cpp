#include "ov000/LoCommon.h"

extern "C" {

extern u8 *data_ov000_021ccd54;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cad50[];
BOOL func_ov000_02184498(void *g);
extern void *data_0214a420;
BOOL func_020658cc(void *a, s32 b);
s32 func_0204c08c(void *res, u16 id, s32 *out, s32 d);
void func_02050748(void *p);
void func_020508f4(void *p, s32 n);
void *MsgRes_GetString(void *a, s32 b);
void func_ov000_0215c1bc(void *p, s32 a, void *b);
void func_ov000_0215ced8(void *p, s32 a, s32 b);

static inline void LoMsgInit(u8 *p, s32 n, s32 v) {
    LFLD(s32, p, 0x1c) = n;
    LFLD(s32, p, 0x20) = n;
    LFLD(s32, p, 0x24) = 0;
    LFLD(s32, p, 0x28) = v;
    func_020508f4(p, n);
}

struct Obj0217032c {
    u8 unk_00[0x24];
    s32 unk_24;
    u8 unk_28[0x4];
    u8 *unk_2c;
};

BOOL func_ov000_0217032c(Obj0217032c *self, void *res, u32 id) {
    s32 n;
    s32 v;
    u8 *p;
    if ((u32)(LFLD(s32, data_ov000_021ccd54, 0x98) - 0x11) > 2) {
        return FALSE;
    }
    if (self->unk_24 != 3) {
        return FALSE;
    }
    if (self->unk_2c) {
        return FALSE;
    }
    if (func_020658cc(data_0214a420, 0x2712) || func_020658cc(data_0214a420, 0x2713) || func_020658cc(data_0214a420, 0x191)) {
        return FALSE;
    }
    v = func_0204c08c(res, (u16)id, &n, 1);
    p = (u8 *)Heap_Alloc(0x210);
    if (p) {
        func_02050748(p);
    }
    self->unk_2c = p;
    LoMsgInit(p, n, v);
    LFLD(u16, self->unk_2c, 0) |= 2;
    self->unk_24 = 5;
    return TRUE;
}

struct Obj02170448 {
    u8 unk_00[0x24];
    s32 unk_24;
    u8 unk_28[0x8];
    VObj *unk_30;
};

BOOL func_ov000_02170448(Obj02170448 *self, void *res, u32 id) {
    u8 *g = data_ov000_021ccd54;
    u32 hi;
    u16 lo;
    VObj *p;
    if ((u32)(LFLD(s32, g, 0x98) - 0x11) > 2) {
        return FALSE;
    }
    if (self->unk_24 != 3) {
        return FALSE;
    }
    if (self->unk_30) {
        return FALSE;
    }
    if (!func_ov000_02184498(g)) {
        return FALSE;
    }
    hi = id >> 16;
    lo = id;
    p = (VObj *)Heap_Alloc(0xe8);
    if (p) {
        *(void **)p = data_ov000_021cac60;
        p->vfunc_28();
        *(void **)p = data_ov000_021cad50;
        p->vfunc_28();
    }
    self->unk_30 = p;
    p->vfunc_08();
    if ((hi & 0xfc00) == 0x8000) {
        func_ov000_0215c1bc(self->unk_30, hi, MsgRes_GetString(res, lo));
    } else {
        func_ov000_0215ced8(self->unk_30, hi, lo);
    }
    self->unk_30->vfunc_70();
    self->unk_24 = 6;
    return TRUE;
}

}
