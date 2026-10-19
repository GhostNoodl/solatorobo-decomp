#include "ov000/LoCommon.h"

extern "C" {
extern u8 data_0208ba70[];
extern u8 *data_02097ce0;
extern void *data_02149ef8;
extern void *data_0208cc88;
extern void *data_0208cc94;
void func_0204c7d0(void *p);
void *func_0204c0e8(void *a, s32 b);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_02041c5c(void *model, void *fn);
void STD_CopyString(void *dst, void *src);
void func_ov000_021c5a0c(void);

void func_ov000_021c5bd4(u8 *self) {
    void *res;
    u8 *p;
    u8 *m;
    if (LFLD(u8, self, 0x44) != 0) {
        return;
    }
    res = data_02149ef8;
    p = (u8 *)func_0203dd9c(0xb8);
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, data_0208ba70);
        func_0204c7d0(p);
    }
    LFLD(u8 *, self, 0x30) = p;
    LFLD(s32, p, 0x28) = 8;
    {
        void *t = LFLD(void *, self, 0x38);
        if (t == NULL) {
            t = func_0204c0e8(res, 0x50);
        }
        p = LFLD(u8 *, self, 0x30);
        LFLD(void *, p, 0x24) = t;
    }
    LFLD(s32, p, 0x4c) = func_0204c4fc(LFLD(s32, p, 0x28), LFLD(s32, p, 0x38), LFLD(s32, p, 0x24), p + 0x44, p + 0x48, LFLD(s8, p, 0x37) != 0);
    LFLD(s32, data_02097ce0, 0x4) = LFLD(s32, p, 0x28);
    LFLD(s32, LFLD(u8 *, self, 0x30), 0x2c) = 0;
    LFLD(u32, LFLD(u8 *, self, 0x30), 0x4) |= 0x40;
    LFLD(u32, LFLD(u8 *, self, 0x30), 0x4) |= 0x1000000;
    LFLD(u32, LFLD(u8 *, self, 0x30), 0x4) |= 0x400000;
    LFLD(u32, LFLD(u8 *, self, 0x30), 0x4) |= 0x4;
    m = (u8 *)func_0203dd9c(0x160);
    if (m != NULL) {
        void *arc;
        void *name;
        name = data_0208cc88;
        arc = data_0208cc94;
        func_02041218(m + 0x88);
        func_02041440(m, name, 0);
        STD_CopyString(m + 0x2c, arc);
    }
    LFLD(u8 *, self, 0x34) = m;
    func_020417e0(LFLD(u8 *, self, 0x34), func_02034d88(func_02035d5c(m + 0x2c), LFLD(u8 *, self, 0x34) + 0x4c));
    LFLD(u32, LFLD(u8 *, self, 0x34), 0x6c) |= 2;
    func_02041d9c(LFLD(u8 *, self, 0x34), 0, 6);
    func_02041d9c(LFLD(u8 *, self, 0x34), 0, 7);
    func_02041c5c(LFLD(u8 *, self, 0x34), (void *)func_ov000_021c5a0c);
    LFLD(u8, self, 0x44) = 1;
}

}

