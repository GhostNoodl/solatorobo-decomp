#include "ov000/LoCommon.h"

extern "C" {

void STD_CopyLString(void *dst, const void *src, s32 n);

static inline void LoInitEC44(void *self) {
    LFLD(s32, self, 0x0) = 0;
    LFLD(s32, self, 0x4) = 0;
    LFLD(s32, self, 0x8) = 0;
    LFLD(s32, self, 0xc) = 0;
    LFLD(s32, self, 0x1c) = 0;
    LFLD(s32, self, 0x18) = 0;
    LFLD(s32, self, 0x10) = 0x80000;
    LFLD(s32, self, 0x14) = 0xf000;
    LFLD(s32, self, 0x20) = 0;
    LFLD(s32, self, 0x24) = 0;
    LFLD(s32, self, 0x28) = 0;
}

void func_ov000_02162b40(void *self, const void *s0, const void *s1, const void *s2, const void *s3, s32 d, s32 e, s16 f) {
    STD_CopyLString((u8 *)self + 0xb, s0, 0x20);
    STD_CopyLString((u8 *)self + 0x2b, s1, 0x18);
    STD_CopyLString((u8 *)self + 0x43, s2, 0x20);
    STD_CopyLString((u8 *)self + 0x63, s3, 0x18);
    LFLD(u8, self, 0x7b) = e != 0 ? TRUE : FALSE;
    LFLD(u8, self, 0xa) = 1;
    LFLD(u8, self, 0x6bc) = 1;
    LFLD(s32, self, 0x6c0) = d;
    LFLD(s32, self, 0x6c4) = e;
    LFLD(s16, self, 0x6c8) = f;
}

}

#include "ov000/Vec.h"

extern "C" {

void func_ov000_0218ec60(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_0218edf0(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_02161fac(void *p);
void func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
void func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021911c8(void *a, s32 b);
void func_ov000_021915a0(void *a);
void func_ov000_02191870(void *a, void *b);
u8 *func_ov000_02190a30(void *a, s32 b);
void func_ov000_02191920(void *a, s32 b, s32 c, s32 d);
BOOL func_02049244(void *out, s32 speed, const void *from, const void *to, s32 minDist);
void VEC_Normalize(const VecFx32 *src, VecFx32 *dst);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);
u32 _fflt(s32 v);
u32 _fadd(u32 a, u32 b);
u32 _fsub(u32 a, u32 b);
s32 _ffix(u32 v);

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 1;
} CamFlags;

typedef struct {
    s16 unk_00;
    u8 pad02[0x136];
} Track;
typedef struct {
    u8 pad[0x78];
    Track a[2];
    Track b[2];
} Slot;

static inline void StopSlot(u8 *self, u8 i) {
    if (i > 2) {
        return;
    }
    Track *a = ((Slot *)self)->a;
    Track *b = ((Slot *)self)->b;
    func_ov000_0218ec60(&a[i], 0, 0, 1, 0);
    func_ov000_0218edf0(&a[i], 0, 0, 1, 0);
    a[i].unk_00 = 0;
    func_ov000_0218edf0(&b[i], 0, 0, 1, 0);
    b[i].unk_00 = 0;
}

#define CF LFLD(CamFlags, self, 0x61e)
#define V(off) LFLD(VecFx32, self, off)

void func_ov000_02162bd4(u8 *self) {
    switch (LFLD(s32, self, 0x6b8)) {
    case 0:
        if (LFLD(u8, self, 0x6bc)) {
            LFLD(s32, self, 0x6b8) = 10;
            LFLD(u8, self, 0x6bc) = 0;
        }
        break;
    case 10:
        CF.b0 = 0;
        StopSlot(self + 4, LFLD(u8, self + 4, 5));
        LFLD(s32, self, 0x6b8)++;
        break;
    case 11: {
        u8 *ctrl;

        func_ov000_02161fac(self + 4);
        if (LFLD(u8, self, 8) != 0x14) {
            break;
        }
        LFLD(u8, self, 9) ^= 1;
        func_ov000_0218ffdc(self + 0x55c, self + 0x7c + LFLD(u8, self, 9) * 0x138, 0, 1);
        CF.b6 = 1;
        func_ov000_02190cb0(self + 0x55c, LFLD(void *, self, 0x6c0), 0x1000, 0);
        func_ov000_021911c8(self + 0x55c, LFLD(s16, self, 0x6c8));
        func_ov000_021915a0(self + 0x55c);
        CF.b4 = 0;
        CF.b0 = 0;
        if (LFLD(void *, self + 0x2ec + LFLD(u8, self, 9) * 0x138, 0x48) != NULL &&
            LFLD(s32, LFLD(void *, self + 0x2ec + LFLD(u8, self, 9) * 0x138, 0x48), 0xc) != 0) {
            func_ov000_02191870(self + 0x55c, self + 0x2ec + LFLD(u8, self, 9) * 0x138);
            ctrl = func_ov000_02190a30(self + 0x55c, 3);
            if (ctrl != NULL) {
                s32 v;
                u32 f;
                s32 frame;
                func_ov000_02191920(self + 0x55c, 0, 0x1000, 0);
                v = LFLD(s32, self, 0x6c4);
                if (v > 0) {
                    f = _fadd(0x3f000000, _fflt(v << 12));
                } else {
                    f = _fsub(_fflt(v << 12), 0x3f000000);
                }
                frame = _ffix(f);
                if (LFLD(u8 *, ctrl, 0) != NULL) {
                    if (frame >= 0) {
                        LFLD(s32, LFLD(u8 *, ctrl, 0), 0) = frame;
                    } else {
                        LFLD(s32, LFLD(u8 *, ctrl, 0), 0) = (LFLD(u16, LFLD(u8 *, LFLD(u8 *, ctrl, 0), 8), 4) << 12) - 1;
                    }
                }
                LFLD(u8, ctrl, 0x111) |= 8;
            }
        } else {
            func_ov000_02191870(self + 0x55c, self + 0x7c + LFLD(u8, self, 9) * 0x138);
        }
        LFLD(s32, self, 0x6b8) = 0x14;
        LFLD(u8, self, 0x6bc) = 0;
    }
    case 20:
        LFLD(s32, self, 0x704) = 0xc;
        V(0x6d8) = V(0x6ec);
        LFLD(s32, self, 0x6b8)++;
    case 21:
        if (LFLD(s32, self, 0x704) != 0) {
            if (LFLD(u8, self, 0x6bc)) {
                LFLD(s32, self, 0x6b8) = 10;
                LFLD(u8, self, 0x6bc) = 0;
            }
            LFLD(s32, self, 0x704)--;
            break;
        }
        CF.b0 = 1;
        if (func_02049244(self + 0x6d8, 0x266, self + 0x6d8, self + 0x6cc, 0xcd)) {
            LFLD(s32, self, 0x6b8)++;
        }
        break;
    case 22:
        V(0x6d8) = V(0x6cc);
        if (LFLD(u8, self, 0x6bc)) {
            LFLD(s32, self, 0x6b8) = 0x1e;
            LFLD(u8, self, 0x6bc) = 0;
        }
        break;
    case 30: {
        VecFx32 d;
        d.x = V(0x6f8).x - V(0x6cc).x;
        d.y = V(0x6f8).y - V(0x6cc).y;
        d.z = V(0x6f8).z - V(0x6cc).z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(0xcd, &d, &V(0x6cc), &V(0x6d8));
        LFLD(s32, self, 0x6b8)++;
        break;
    }
    case 31: {
        VecFx32 d;
        d.x = V(0x6d8).x - V(0x6cc).x;
        d.y = V(0x6d8).y - V(0x6cc).y;
        d.z = V(0x6d8).z - V(0x6cc).z;
        VEC_MultAdd(0x14cd, &d, &V(0x6cc), &V(0x6d8));
        if ((s32)(((s64)d.x * (V(0x6f8).x - V(0x6d8).x) + (s64)d.y * (V(0x6f8).y - V(0x6d8).y) + (s64)d.z * (V(0x6f8).z - V(0x6d8).z) + 0x800) >> 12) <= 0) {
            LFLD(s32, self, 0x6b8) = 10;
        }
        break;
    }
    case 40: {
        VecFx32 d;
        d.x = V(0x6f8).x - V(0x6cc).x;
        d.y = V(0x6f8).y - V(0x6cc).y;
        d.z = V(0x6f8).z - V(0x6cc).z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(0xcd, &d, &V(0x6cc), &V(0x6d8));
        LFLD(s32, self, 0x6b8)++;
        break;
    }
    case 41: {
        VecFx32 d;
        d.x = V(0x6d8).x - V(0x6cc).x;
        d.y = V(0x6d8).y - V(0x6cc).y;
        d.z = V(0x6d8).z - V(0x6cc).z;
        VEC_MultAdd(0x14cd, &d, &V(0x6cc), &V(0x6d8));
        if ((s32)(((s64)d.x * (V(0x6f8).x - V(0x6d8).x) + (s64)d.y * (V(0x6f8).y - V(0x6d8).y) + (s64)d.z * (V(0x6f8).z - V(0x6d8).z) + 0x800) >> 12) > 0) {
            break;
        }
        CF.b0 = 0;
        LFLD(s32, self, 0x6b8)++;
        break;
    }
    case 42: // empty case; moves the compare-tree pivot to 30
        break;
    }
}

}
