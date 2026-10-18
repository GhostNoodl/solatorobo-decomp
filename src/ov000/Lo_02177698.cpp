#include "ov000/LoCommon.h"

typedef struct {
    u8 unk_00[0x72];
    u16 unk_72;
} Data02fe1534;

extern "C" {
extern Data02fe1534 data_02fe1534;
extern u8 *data_0214a424;
extern void *data_02097e4c;
void func_ov000_0215d980(void *a, s32 b, s32 c);
s32 func_0206d1d4(void *a, u16 b);
void func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

static inline u8 *GetNth(u8 *m) {
    u8 *p = LFLD(u8 *, m, 0x98);
    s32 n;
    if (p == NULL) {
        return NULL;
    }
    n = LFLD(s8, m, 0xb1);
    while (n-- != 0) {
        p = LFLD(u8 *, p, 0x2c);
    }
    return p;
}


}

extern "C" {
extern void *data_02149ef8;
void *func_0204c0e8(void *p, s32 a);
void func_ov000_0215bb14(void *a, void *b);
void func_0206ecd4(s32 a, void *b, u16 c);

s32 func_ov000_02177698(u8 *self, u8 *item) {
    u8 *o = LFLD(u8 *, self, 0x8);
    VObj *t = LFLD(VObj *, o, 0x50);
    if (t != NULL) {
        if (item != NULL) {
            u16 id;
            u8 *a;
            func_0206ecd4(0x100, o + 0x5c, LFLD(u16, item, 6));
            func_ov000_0215bb14(t, o + 0x5c);
            t->vfunc_70();
            id = LFLD(u16, item, 6);
            a = LFLD(u8 *, o, 0x44);
            if (id & 0x2000) {
                u8 *b;
                if (a != NULL) {
                    func_ov000_0215d980(a, LFLD(u8, data_0214a424 + (u16)(id & 0xfff), 0x2a), 1);
                    LFLD(u32, a, 0xc) &= ~0x20;
                }
                b = LFLD(u8 *, o, 0x48);
                if (b != NULL) {
                    func_ov000_0215d980(b, func_0206d1d4(data_0214a424, LFLD(u16, item, 6)), 1);
                    LFLD(u32, b, 0xc) &= ~0x20;
                }
            } else {
                if (a != NULL) {
                    LFLD(u32, a, 0xc) |= 0x20;
                }
                if (LFLD(u8 *, o, 0x48) != NULL) {
                    LFLD(u32, LFLD(u8 *, o, 0x48), 0xc) |= 0x20;
                }
            }
        } else {
            func_ov000_0215bb14(t, func_0204c0e8(data_02149ef8, 0x9d));
            t->vfunc_70();
        }
    }
    return 1;
}

s32 func_ov000_021777d4(u8 *self, u16 id) {
    u8 *m = LFLD(u8 *, self, 0x4c);
    void *obj = LFLD(void *, self, 0x40);
    u8 *node = GetNth(m);
    u8 *g = data_0214a424;
    u32 t;
    data_02fe1534.unk_72 = id;
    t = LFLD(u32, node, 0xc);
    LFLD(u32, g, 0x20) = LFLD(u32, g, 0x20) > t ? LFLD(u32, g, 0x20) - t : 0;
    func_ov000_0215d980(obj, LFLD(u32, data_0214a424, 0x20), 0);
    if (id & 0x2000) {
        if (LFLD(void *, self, 0x44) != NULL) {
            func_ov000_0215d980(LFLD(void *, self, 0x44), LFLD(u8, data_0214a424 + (u16)(id & 0xfff), 0x2a), 1);
        }
        void *o48 = LFLD(void *, self, 0x48);
        if (o48 != NULL) {
            func_ov000_0215d980(o48, func_0206d1d4(data_0214a424, id), 1);
        }
    }
    func_02049a48(data_02097e4c, 0x31, -1, -1, -1);
    return 0;
}
}
