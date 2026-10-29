#include "ov000/LoCommon.h"

typedef struct {
    u16 mode : 3;
    u16 rest : 13;
} B22_021b2d48;

extern "C" {
extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
void *func_ov000_0218d2e0(void *self);
void *func_ov000_0218e640(void *mgr, u16 id);
void *func_ov000_02199d78(void *p);
void *func_ov000_021b2f08(void *self, void *a, void *b, BOOL c);
void *func_02049a48(void *p, s32 id, s32 a, s32 b, s32 c);
void *func_ov000_021985c0(void *p);
BOOL func_ov000_02190a30(void *p, s32 a);
void func_ov000_021b3bd8(void *self);
void func_ov000_021b3738(void *self, void *t);

static inline void *FindActor021b2d48(u16 id) {
    void *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(mgr, id);
}

void func_ov000_021b2d48(u8 *self) {
    u8 *res = NULL;
    BOOL flag = FALSE;
    u8 *tgt = NULL;
    u8 *sub = NULL;
    BOOL search = FALSE;

    if (LFLD(u8, self, 0xb2f) != 0) {
        LFLD(u8, self, 0xb2f)--;
        res = (u8 *)func_ov000_0218d2e0(self);
    } else if ((LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x400) || LFLD(B22_021b2d48, self, 0xb22).mode > 1) {
        LFLD(u8, self, 0xb2f) = 0;
    } else {
        u8 *a = (u8 *)FindActor021b2d48(LFLD(u16, self, 0xb1c));
        if (a != NULL && (sub = LFLD(u8 *, a, 0x4c)) != NULL) {
            if (sub[1] == 6) {
                tgt = (u8 *)func_ov000_02199d78(sub);
            } else if (sub[1] == 1 || sub[1] == 5) {
                flag = TRUE;
            }
        }
        if (sub == NULL || tgt != NULL || flag) {
            search = TRUE;
        }
    }
    if (search) {
        res = (u8 *)func_ov000_021b2f08(self, tgt, sub, flag);
    }
    if (res != NULL) {
        if (LFLD(u16, self, 0x90) != LFLD(u16, res, 0x20)) {
            func_02049a48(data_02097e4c, 0x22, -1, -1, -1);
            LFLD(u16, self, 0x90) = LFLD(u16, res, 0x20);
        }
        if ((LFLD(u16, res, 0x20) >> 12) == 4) {
            u8 *t = (u8 *)func_ov000_021985c0(res);
            if (t != NULL && (tgt = LFLD(u8 *, t, 0x38)) != NULL) {
                flag = TRUE;
                if (!func_ov000_02190a30(tgt, 1)) {
                    LFLD(u16, tgt, 0xb6) = 0x73ff;
                    LFLD(u16, tgt, 0xb8) = 0x73ff;
                    LFLD(u16, tgt, 0xba) = 2;
                    LFLD(u16, tgt, 0xbc) = 1;
                }
            }
        }
    } else {
        LFLD(u16, self, 0x90) = 0xffff;
    }
    func_ov000_021b3bd8(self);
    func_ov000_021b3738(self, res);
}
}
