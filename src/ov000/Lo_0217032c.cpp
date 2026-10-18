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
void *func_0204c0e8(void *a, s32 b);
void func_ov000_0215c1bc(void *p, s32 a, void *b);
void func_ov000_0215ced8(void *p, s32 a, s32 b);

static inline void LoMsgInit(u8 *p, s32 n, s32 v) {
    LFLD(s32, p, 0x1c) = n;
    LFLD(s32, p, 0x20) = n;
    LFLD(s32, p, 0x24) = 0;
    LFLD(s32, p, 0x28) = v;
    func_020508f4(p, n);
}

BOOL func_ov000_0217032c(void *self, void *res, u32 id) {
    s32 n;
    s32 v;
    u8 *p;
    if ((u32)(LFLD(s32, data_ov000_021ccd54, 0x98) - 0x11) > 2) {
        return FALSE;
    }
    if (LFLD(s32, self, 0x24) != 3) {
        return FALSE;
    }
    if (LFLD(void *, self, 0x2c)) {
        return FALSE;
    }
    if (func_020658cc(data_0214a420, 0x2712) || func_020658cc(data_0214a420, 0x2713) || func_020658cc(data_0214a420, 0x191)) {
        return FALSE;
    }
    v = func_0204c08c(res, (u16)id, &n, 1);
    p = (u8 *)func_0203dd9c(0x210);
    if (p) {
        func_02050748(p);
    }
    LFLD(u8 *, self, 0x2c) = p;
    LoMsgInit(p, n, v);
    LFLD(u16, LFLD(u8 *, self, 0x2c), 0) |= 2;
    LFLD(s32, self, 0x24) = 5;
    return TRUE;
}

BOOL func_ov000_02170448(void *self, void *res, u32 id) {
    u8 *g = data_ov000_021ccd54;
    u32 hi;
    u16 lo;
    VObj *p;
    if ((u32)(LFLD(s32, g, 0x98) - 0x11) > 2) {
        return FALSE;
    }
    if (LFLD(s32, self, 0x24) != 3) {
        return FALSE;
    }
    if (LFLD(void *, self, 0x30)) {
        return FALSE;
    }
    if (!func_ov000_02184498(g)) {
        return FALSE;
    }
    hi = id >> 16;
    lo = id;
    p = (VObj *)func_0203dd9c(0xe8);
    if (p) {
        *(void **)p = data_ov000_021cac60;
        p->vfunc_28();
        *(void **)p = data_ov000_021cad50;
        p->vfunc_28();
    }
    LFLD(VObj *, self, 0x30) = p;
    p->vfunc_08();
    if ((hi & 0xfc00) == 0x8000) {
        func_ov000_0215c1bc(LFLD(void *, self, 0x30), hi, func_0204c0e8(res, lo));
    } else {
        func_ov000_0215ced8(LFLD(void *, self, 0x30), hi, lo);
    }
    LFLD(VObj *, self, 0x30)->vfunc_70();
    LFLD(s32, self, 0x24) = 6;
    return TRUE;
}

}
