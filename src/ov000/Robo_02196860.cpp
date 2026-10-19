#include "types.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u16 st;
    u16 timer;
} State02196860;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 rest : 11;
} Bits02196860;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec02196860;

extern "C" {
extern char data_ov000_021cc456[];
extern u8 *data_0214a424;
void func_ov000_02190cb0(void *a, const char *b, s32 c, s32 d);
void func_ov000_021915a0(void *a);
void func_0203f324(void *a);
void func_0203f364(void *a);
void func_ov000_02198360(void *s, s32 a, s32 b);
void *func_ov000_0219bf90(void);
void *func_ov000_02199ba0(void *p);
void func_ov000_02199b88(void *a, void *b);
void func_ov003_021f0c60(void *self, s32 a);
void *func_ov003_021f0868(void *pos, s32 a, s32 b);
s32 func_02040498(s32 n);
u16 FX_Atan2(s32 a, s32 b);
s32 func_01ffbd6c(Vec02196860 *a, Vec02196860 *b, s32 c, s32 d, s32 e, s32 f);
void VEC_MultAdd(s32 fx, const Vec02196860 *a, const Vec02196860 *b, Vec02196860 *dst);

void func_ov000_02196860(u8 *self) {
    switch (LFLD(State02196860 *, self, 0x40)->st) {
    case 0: {
        u8 *m = LFLD(u8 *, self, 0x4c);
        if (LFLD(u16, m, 0x1c) != 0xffff && (u8)(LFLD(u8, m, 2) + 0xff) <= 1) {
            BOOL done = FALSE;
            u8 *p = (u8 *)func_ov000_0219bf90();
            if (LFLD(u16, p, 0xc) == LFLD(u16, LFLD(u8 *, self, 0x4c), 0x1c)) {
                u8 *g = data_0214a424;
                u32 n = LFLD(u16, g, 0x16) + 1;
                if (n >= 0xffff) {
                    n = 0xffff;
                }
                LFLD(u16, g, 0x16) = n;
                if (LFLD(u8 *, self, 0x44) != NULL) {
                    u8 *q = LFLD(u8 *, self, 0x44);
                    LFLD(Bits02196860, q, 0x22).b0 = 0;
                    LFLD(Bits02196860, q, 0x22).b1 = 0;
                }
                if (LFLD(u8 *, self, 0x48) != NULL) {
                    u8 *q = LFLD(u8 *, self, 0x48);
                    LFLD(Bits02196860, q, 0x9a).b0 = 0;
                    LFLD(Bits02196860, q, 0x9a).b3 = 0;
                    func_0203f364(q);
                    q = LFLD(u8 *, self, 0x48);
                    LFLD(Bits02196860, q, 0x9a).b1 = 0;
                    LFLD(Bits02196860, q, 0x9a).b4 = 0;
                }
                if (LFLD(u8, LFLD(u8 *, self, 0x4c), 3) != 0) {
                    LFLD(u16, LFLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
                    func_ov003_021f0c60(self, 0);
                }
                done = TRUE;
            }
            if (done) {
                func_ov000_02198360(LFLD(void *, self, 0x40), 0x15, 0);
                break;
            }
        }
        func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc456, 0x1000, 0);
        func_ov000_021915a0(LFLD(void *, self, 0x38));
        if (LFLD(u8 *, self, 0x44) != NULL) {
            u8 *q = LFLD(u8 *, self, 0x44);
            LFLD(Bits02196860, q, 0x22).b0 = 1;
            LFLD(Bits02196860, q, 0x22).b1 = 1;
        }
        if (LFLD(u8 *, self, 0x48) != NULL) {
            LFLD(s32, self, 0x9c) = 0xf6 - func_02040498(0x7b);
            LFLD(s32, self, 0xa0) = 0x2e1 - func_02040498(0x5c);
            LFLD(s32, self, 0xa4) = 0;
            LFLD(s32, self, 0xa8) = 0x52;
            if (LFLD(u16, LFLD(u8 *, self, 0x4c), 0x1c) == 0xffff) {
                LFLD(u16, self, 0x98) = LFLD(u16, self, 0x7e);
            } else {
                u8 *t = (u8 *)func_ov000_02199ba0(LFLD(u8 *, self, 0x4c));
                if (t != NULL) {
                    Vec02196860 a;
                    Vec02196860 b;
                    s32 y;
                    LFLD(u16, self, 0x98) = FX_Atan2(LFLD(s32, self, 0x70) - LFLD(s32, t, 0x70), LFLD(s32, self, 0x78) - LFLD(s32, t, 0x78));
                    a = *(Vec02196860 *)(t + 0x70);
                    b = *(Vec02196860 *)(self + 0x70);
                    a.y += LFLD(s32, t, 0x6c);
                    y = b.y + LFLD(s32, self, 0x6c);
                    b.y = y;
                    if (func_01ffbd6c(&a, &b, -1, 0, 0, -1) != -0x1000) {
                        a.x = a.x - b.x;
                        a.y = a.y - b.y;
                        a.z = a.z - b.z;
                        VEC_MultAdd(0xc00, &a, &b, &b);
                        if (b.y < y) {
                            b.y = y;
                        }
                        *(Vec02196860 *)(self + 0x70) = b;
                    }
                }
            }
            {
                u8 *q = LFLD(u8 *, self, 0x48);
                LFLD(Bits02196860, q, 0x9a).b0 = 1;
                LFLD(Bits02196860, q, 0x9a).b3 = 1;
                func_0203f324(q);
                LFLD(u16, LFLD(u8 *, self, 0x48), 0x9a) |= 0x12;
                LFLD(Bits02196860, LFLD(u8 *, self, 0x48), 0x9a).b4 = 0;
            }
            LFLD(State02196860 *, self, 0x40)->st++;
        } else {
            func_ov000_02198360(LFLD(void *, self, 0x40), 1, 0);
        }
        LFLD(u16, LFLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
        break;
    }
    case 1:
        if (LFLD(u8 *, self, 0x48) != NULL) {
            LFLD(Bits02196860, LFLD(u8 *, self, 0x48), 0x9a).b4 = 0;
        }
        func_ov000_02198360(LFLD(void *, self, 0x40), 4, 0);
        break;
    }
    if (LFLD(u8 *, self, 0x4c) != NULL && LFLD(u8, LFLD(u8 *, self, 0x4c), 0) == 2) {
        void *r = func_ov003_021f0868(self + 0x70, LFLD(s32, self, 0x64), LFLD(s32, self, 0x68));
        if (r != NULL) {
            func_ov000_02199b88(LFLD(u8 *, self, 0x4c), r);
            func_ov000_02198360(LFLD(void *, self, 0x40), 0xd, 0);
        }
    }
}

}
