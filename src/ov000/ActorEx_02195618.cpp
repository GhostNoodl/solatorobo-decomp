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

struct Obj02195618 {
    u8 unk_00[0x40];
    u8 *unk_40;
    u8 *unk_44;
    u8 unk_48[0x10];
    void *unk_58;
    void *unk_5c;
    u8 unk_60[0x4];
    s32 unk_64;
    s32 unk_68;
    u8 unk_6c[0x4];
    VecFx32 unk_70;
    u8 unk_7c[0x2];
    u16 unk_7e;
    u8 unk_80[0x3c];
    void *unk_bc;
    u8 unk_c0[0xc];
    Bcc_02195618 unk_cc;
};

void func_ov000_02195618(Obj02195618 *self) {
    s32 k;
    s32 i;
    VObj *o;
    VecFx32 pos;
    VecFx32 ofs;
    VecFx32 v;

    if (self->unk_58 != NULL) {
        func_0203f920(self->unk_58);
    }
    k = LFLD(u8, self->unk_40, 0x13);
    for (i = 0; i < 15; i++) {
        if (k == *(s32 *)((u8 *)data_ov000_021c9e18 + i * 12)) {
            (((Act02195618Cls *)self)->*data_ov000_021c9e18[i].fn)();
            break;
        }
    }
    {
        u8 *st = self->unk_40;
        LFLD(s64, st, 4) = 0;
    }
    if (self->unk_5c != NULL) {
        if (PlayerIdle02195618()) {
            func_ov000_0219af3c((u8 *)self, self->unk_5c);
            if (!self->unk_cc.b7) {
                s32 r;
                u8 *hit = self->unk_44;
                if (hit != NULL) {
                    pos = *(VecFx32 *)hit;
                    if (LFLD(B22_02195618, hit, 0x22).b4) {
                        ofs.z = LFLD(s32, hit, 0x1c);
                        ofs.x = 0;
                        ofs.y = 0;
                        func_ov000_0219a210(&pos, &ofs, self->unk_7e);
                    }
                    r = LFLD(s32, self->unk_44, 0x10);
                    if (r == 0) {
                        r = LFLD(s32, self->unk_44, 0x1c);
                    }
                } else {
                    pos = self->unk_70;
                    r = self->unk_68;
                    if (r == 0) {
                        r = self->unk_64;
                    }
                }
                LFLD(VecFx32, self->unk_5c, 0x50) = pos;
                LFLD(s32, self->unk_5c, 0x5c) = r;
            }
            func_ov000_021bd624(self->unk_5c);
        } else {
            LFLD(u32, self->unk_5c, 0) &= ~2;
            func_ov000_021bd300(self->unk_5c);
        }
    }
    if (self->unk_bc == NULL) {
        return;
    }
    o = func_020657b0(data_0214a420, self->unk_bc);
    if (o == NULL) {
        self->unk_bc = NULL;
        return;
    }
    VEC_Add((VecFx32 *)((u8 *)self + 0xc0), (VecFx32 *)((u8 *)self + 0x70), &v);
    o->vfunc_18(&v);
}
}
