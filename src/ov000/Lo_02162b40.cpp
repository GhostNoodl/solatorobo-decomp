#include "ov000/LoCommon.h"

extern "C" {

int STD_CopyLString(void *dst, const void *src, s32 n);

struct LoInitEC44Self {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
};

static inline void LoInitEC44(LoInitEC44Self *self) {
    self->unk_00 = 0;
    self->unk_04 = 0;
    self->unk_08 = 0;
    self->unk_0c = 0;
    self->unk_1c = 0;
    self->unk_18 = 0;
    self->unk_10 = 0x80000;
    self->unk_14 = 0xf000;
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_28 = 0;
}

struct Obj02162b40 {
    u8 unk_00[0xa];
    u8 unk_0a;
    u8 unk_0b[0x70];
    u8 unk_7b;
    u8 unk_7c[0x640];
    u8 unk_6bc;
    u8 unk_6bd[0x3];
    s32 unk_6c0;
    s32 unk_6c4;
    s16 unk_6c8;
};

void func_ov000_02162b40(Obj02162b40 *self, const void *s0, const void *s1, const void *s2, const void *s3, s32 d, s32 e, s16 f) {
    STD_CopyLString((u8 *)self + 0xb, s0, 0x20);
    STD_CopyLString((u8 *)self + 0x2b, s1, 0x18);
    STD_CopyLString((u8 *)self + 0x43, s2, 0x20);
    STD_CopyLString((u8 *)self + 0x63, s3, 0x18);
    self->unk_7b = e != 0 ? TRUE : FALSE;
    self->unk_0a = 1;
    self->unk_6bc = 1;
    self->unk_6c0 = d;
    self->unk_6c4 = e;
    self->unk_6c8 = f;
}

}

#include "ov000/Vec.h"

extern "C" {

void func_ov000_0218ec60(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_0218edf0(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_02161fac(void *p);
BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_ov000_021911c8(void *a, s32 b);
void func_ov000_021915a0(void *a);
void func_ov000_02191870(void *a, void *b);
u8 *func_ov000_02190a30(void *a, s32 b);
void func_ov000_02191920(void *a, s32 b, s32 c, s32 d);
BOOL func_02049244(void *out, s32 speed, const void *from, const void *to, s32 minDist);
void VEC_Normalize(const VecFx32 *src, VecFx32 *dst);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *pDest);

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

#define V(off) LFLD(VecFx32, self, off)

struct Obj02162bd4 {
    u8 unk_00[0x8];
    u8 unk_08;
    u8 unk_09;
    u8 unk_0a[0x6ae];
    s32 unk_6b8;
    u8 unk_6bc;
    u8 unk_6bd[0x3];
    void *unk_6c0;
    s32 unk_6c4;
    s16 unk_6c8;
    u8 unk_6ca[0x3a];
    s32 unk_704;
};

void func_ov000_02162bd4(Obj02162bd4 *self) {
    switch (self->unk_6b8) {
    case 0:
        if (self->unk_6bc) {
            self->unk_6b8 = 10;
            self->unk_6bc = 0;
        }
        break;
    case 10:
        LFLD(CamFlags, self, 0x61e).b0 = 0;
        StopSlot((u8 *)self + 4, LFLD(u8, (u8 *)self + 4, 5));
        self->unk_6b8++;
        break;
    case 11: {
        u8 *ctrl;

        func_ov000_02161fac((u8 *)self + 4);
        if (self->unk_08 != 0x14) {
            break;
        }
        self->unk_09 ^= 1;
        func_ov000_0218ffdc((u8 *)self + 0x55c, (u8 *)self + 0x7c + self->unk_09 * 0x138, 0, 1);
        LFLD(CamFlags, self, 0x61e).b6 = 1;
        func_ov000_02190cb0((u8 *)self + 0x55c, self->unk_6c0, 0x1000, 0);
        func_ov000_021911c8((u8 *)self + 0x55c, self->unk_6c8);
        func_ov000_021915a0((u8 *)self + 0x55c);
        LFLD(CamFlags, self, 0x61e).b4 = 0;
        LFLD(CamFlags, self, 0x61e).b0 = 0;
        if (LFLD(void *, (u8 *)self + 0x2ec + self->unk_09 * 0x138, 0x48) != NULL &&
            LFLD(s32, LFLD(void *, (u8 *)self + 0x2ec + self->unk_09 * 0x138, 0x48), 0xc) != 0) {
            func_ov000_02191870((u8 *)self + 0x55c, (u8 *)self + 0x2ec + self->unk_09 * 0x138);
            ctrl = func_ov000_02190a30((u8 *)self + 0x55c, 3);
            if (ctrl != NULL) {
                s32 v;
                float f;
                s32 frame;
                func_ov000_02191920((u8 *)self + 0x55c, 0, 0x1000, 0);
                v = self->unk_6c4;
                if (v > 0) {
                    f = (float)(v << 12) + 0.5f;
                } else {
                    f = (float)(v << 12) - 0.5f;
                }
                frame = (s32)f;
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
            func_ov000_02191870((u8 *)self + 0x55c, (u8 *)self + 0x7c + self->unk_09 * 0x138);
        }
        self->unk_6b8 = 0x14;
        self->unk_6bc = 0;
    }
    case 20:
        self->unk_704 = 0xc;
        V(0x6d8) = V(0x6ec);
        self->unk_6b8++;
    case 21:
        if (self->unk_704 != 0) {
            if (self->unk_6bc) {
                self->unk_6b8 = 10;
                self->unk_6bc = 0;
            }
            self->unk_704--;
            break;
        }
        LFLD(CamFlags, self, 0x61e).b0 = 1;
        if (func_02049244((u8 *)self + 0x6d8, 0x266, (u8 *)self + 0x6d8, (u8 *)self + 0x6cc, 0xcd)) {
            self->unk_6b8++;
        }
        break;
    case 22:
        V(0x6d8) = V(0x6cc);
        if (self->unk_6bc) {
            self->unk_6b8 = 0x1e;
            self->unk_6bc = 0;
        }
        break;
    case 30: {
        VecFx32 d;
        d.x = V(0x6f8).x - V(0x6cc).x;
        d.y = V(0x6f8).y - V(0x6cc).y;
        d.z = V(0x6f8).z - V(0x6cc).z;
        VEC_Normalize(&d, &d);
        VEC_MultAdd(0xcd, &d, &V(0x6cc), &V(0x6d8));
        self->unk_6b8++;
        break;
    }
    case 31: {
        VecFx32 d;
        d.x = V(0x6d8).x - V(0x6cc).x;
        d.y = V(0x6d8).y - V(0x6cc).y;
        d.z = V(0x6d8).z - V(0x6cc).z;
        VEC_MultAdd(0x14cd, &d, &V(0x6cc), &V(0x6d8));
        if ((s32)(((s64)d.x * (V(0x6f8).x - V(0x6d8).x) + (s64)d.y * (V(0x6f8).y - V(0x6d8).y) + (s64)d.z * (V(0x6f8).z - V(0x6d8).z) + 0x800) >> 12) <= 0) {
            self->unk_6b8 = 10;
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
        self->unk_6b8++;
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
        LFLD(CamFlags, self, 0x61e).b0 = 0;
        self->unk_6b8++;
        break;
    }
    case 42: // empty case; moves the compare-tree pivot to 30
        break;
    }
}

}
