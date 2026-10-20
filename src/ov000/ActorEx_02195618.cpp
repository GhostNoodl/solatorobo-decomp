#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

class Act02195618Cls;
typedef void (Act02195618Cls::*Act02195618Pmf)();

typedef struct {
    s32 key;
    Act02195618Pmf fn;
} Act02195618Entry;

typedef struct {
    u16 b0 : 4;
    u16 b4 : 1;
    u16 rest : 11;
} B22_02195618;

typedef struct {
    u16 b0 : 7;
    u16 b7 : 1;
    u16 rest : 8;
} Bcc_02195618;

extern "C" {

extern Act02195618Entry data_ov000_021c9e18[];
extern u8 *data_ov000_021ccd54;
extern void *data_0214a420;
void func_0203f920(void *p);
void func_ov000_0219af3c(u8 *self, void *p);
void func_ov000_0219a210(VecFx32 *pos, const VecFx32 *ofs, s32 angle);
void func_ov000_021bd624(void *p);
void func_ov000_021bd300(void *p);
VObj *func_020657b0(void *mgr, void *h);
void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);

static inline BOOL PlayerIdle02195618(void) {
    u8 *pl = data_ov000_021ccd54;
    if (pl != NULL) {
        if (LFLD(s32, pl, 0x90) != LFLD(s32, pl, 0x94) ? TRUE : FALSE) {
            return FALSE;
        }
        if (LFLD(s32, pl, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

void func_ov000_02195618(u8 *self) {
    s32 k;
    s32 i;
    VObj *o;
    VecFx32 pos;
    VecFx32 ofs;
    VecFx32 v;

    if (LFLD(void *, self, 0x58) != NULL) {
        func_0203f920(LFLD(void *, self, 0x58));
    }
    k = LFLD(u8, LFLD(u8 *, self, 0x40), 0x13);
    for (i = 0; i < 15; i++) {
        if (k == *(s32 *)((u8 *)data_ov000_021c9e18 + i * 12)) {
            (((Act02195618Cls *)self)->*data_ov000_021c9e18[i].fn)();
            break;
        }
    }
    {
        u8 *st = LFLD(u8 *, self, 0x40);
        LFLD(s64, st, 4) = 0;
    }
    if (LFLD(void *, self, 0x5c) != NULL) {
        if (PlayerIdle02195618()) {
            func_ov000_0219af3c(self, LFLD(void *, self, 0x5c));
            if (!LFLD(Bcc_02195618, self, 0xcc).b7) {
                s32 r;
                u8 *hit = LFLD(u8 *, self, 0x44);
                if (hit != NULL) {
                    pos = *(VecFx32 *)hit;
                    if (LFLD(B22_02195618, hit, 0x22).b4) {
                        ofs.z = LFLD(s32, hit, 0x1c);
                        ofs.x = 0;
                        ofs.y = 0;
                        func_ov000_0219a210(&pos, &ofs, LFLD(u16, self, 0x7e));
                    }
                    r = LFLD(s32, LFLD(u8 *, self, 0x44), 0x10);
                    if (r == 0) {
                        r = LFLD(s32, LFLD(u8 *, self, 0x44), 0x1c);
                    }
                } else {
                    pos = LFLD(VecFx32, self, 0x70);
                    r = LFLD(s32, self, 0x68);
                    if (r == 0) {
                        r = LFLD(s32, self, 0x64);
                    }
                }
                LFLD(VecFx32, LFLD(u8 *, self, 0x5c), 0x50) = pos;
                LFLD(s32, LFLD(u8 *, self, 0x5c), 0x5c) = r;
            }
            func_ov000_021bd624(LFLD(void *, self, 0x5c));
        } else {
            LFLD(u32, LFLD(u8 *, self, 0x5c), 0) &= ~2;
            func_ov000_021bd300(LFLD(void *, self, 0x5c));
        }
    }
    if (LFLD(void *, self, 0xbc) == NULL) {
        return;
    }
    o = func_020657b0(data_0214a420, LFLD(void *, self, 0xbc));
    if (o == NULL) {
        LFLD(void *, self, 0xbc) = NULL;
        return;
    }
    VEC_Add((VecFx32 *)(self + 0xc0), (VecFx32 *)(self + 0x70), &v);
    o->vfunc_18(&v);
}
}
