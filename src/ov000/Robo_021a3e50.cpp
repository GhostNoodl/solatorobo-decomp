#include "ov000/LoCommon.h"

typedef struct {
    u8 a;
    u16 b;
    u8 c;
} Msg021a3e50;

extern "C" {
extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd30;
extern u8 *data_ov000_021ccd54;
extern u8 *data_0214a424;
extern u8 data_ov000_021cc5e3[];
extern u8 data_ov000_021cc648[];
void *func_ov000_0218e640(void *mgr, u16 id);
void func_ov000_0218d398(void *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
void func_ov000_0218d988(void *self, void *other, s32 step);
void func_ov000_02190cb0(void *p, void *a, s32 b, s32 c);
void func_ov000_021915a0(void *p);
void func_020627a0(u16 a, u16 b);
BOOL func_ov000_0216f674(void *mgr, s32 a);
BOOL func_ov000_021700c4(void *p);
void *func_ov000_02173610(s32 kind);
void func_ov000_02198360(void *p, s32 a, s32 b);

static inline void *FindActor021a3e50(u16 id) {
    void *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(mgr, id);
}

static inline BOOL IsBusy021a3e50(void) {
    BOOL r;
    u8 *m = data_ov000_021ccd30;
    if (m == NULL) {
        r = FALSE;
    } else if (func_ov000_0216f674(m, 6)) {
        r = TRUE;
    } else if (LFLD(void *, m, 0x11c) == NULL) {
        r = FALSE;
    } else {
        r = func_ov000_021700c4(LFLD(void *, m, 0x11c));
    }
    return r;
}

void func_ov000_021a3e50(u8 *self) {
    u8 *t;
    u8 *sub;
    LFLD(u16, LFLD(u8 *, self, 0x48), 0x9a) |= 0x20;
    if (LFLD(u8, self, 0xb2f) == 0) {
        LFLD(u8, self, 0xb2f)++;
    }
    t = (u8 *)FindActor021a3e50(LFLD(u16, self, 0x90));
    sub = LFLD(u8 *, self, 0x40);
    switch (LFLD(u16, sub, 0)) {
    case 0:
        if (t != NULL) {
            Msg021a3e50 m;
            m.a = 1;
            m.b = 0x19a;
            m.c = 1;
            func_ov000_0218d398(t, LFLD(u16, self, 0xc), 5, TRUE, 6, &m);
            if (LFLD(u16, t, 0xe) == 0x2003) {
                u16 v;
                LFLD(u16, LFLD(u8 *, self, 0x40), 0)++;
                v = LFLD(u16, LFLD(u8 *, self, 0x50), 2);
                func_ov000_0218d398(self, LFLD(u16, self, 0xc), 10, TRUE, 2, &v);
            } else {
                LFLD(u16, LFLD(u8 *, self, 0x40), 0) = 10;
                if (LFLD(u16, self, 0xbac) != LFLD(u16, self, 0x90)) {
                    u8 *g;
                    u32 n;
                    LFLD(u16, self, 0xbac) = LFLD(u16, self, 0x90);
                    g = data_0214a424;
                    n = LFLD(u16, g, 0x14) + 1;
                    if (n >= 0xffff) {
                        n = 0xffff;
                    }
                    LFLD(u16, g, 0x14) = n;
                }
            }
        }
        {
            u8 *anim = data_ov000_021cc5e3;
            if (!LBIT(self, 0xb24).b1) {
                anim = data_ov000_021cc648;
            }
            func_ov000_02190cb0(LFLD(void *, self, 0x38), anim, 0x400, 0);
        }
        func_ov000_021915a0(LFLD(void *, self, 0x38));
        LFLD(u16, LFLD(u8 *, self, 0x40), 2) = 0;
        LFLD(s32, self, 0x9c) = 0;
        LFLD(s32, self, 0xa0) = 0;
        LFLD(s32, self, 0xa4) = 0;
        LFLD(s32, self, 0xa8) = 0;
        break;
    case 1:
        LFLD(u16, sub, 2)++;
        if (LFLD(u16, sub, 2) > 0x1e) {
            LFLD(u16, LFLD(u8 *, self, 0x40), 0) = 10;
            LFLD(u16, LFLD(u8 *, self, 0x40), 2) = 0;
        }
        break;
    case 10:
        if (t != NULL) {
            func_020627a0(LFLD(u16, t, 0xe), LFLD(u16, t, 0xc));
            LFLD(u8, data_ov000_021ccd54, 0xac) = 1;
        }
        LFLD(u16, LFLD(u8 *, self, 0x40), 0)++;
        break;
    case 11:
        LFLD(u16, sub, 2)++;
        if (LFLD(u16, sub, 2) > 0x14) {
            LFLD(u16, LFLD(u8 *, self, 0x40), 0)++;
            LFLD(u16, LFLD(u8 *, self, 0x40), 2) = 0;
        }
        break;
    case 12:
        if (IsBusy021a3e50()) {
            break;
        }
        if (func_ov000_02173610(7)) {
            break;
        }
        if (t != NULL) {
            Msg021a3e50 m;
            m.a = 0;
            m.b = 0x19a;
            m.c = 1;
            func_ov000_0218d398(t, LFLD(u16, self, 0xc), 5, TRUE, 6, &m);
        }
        LFLD(u8, self, 0xb2f) = 0x2d;
        LFLD(u16, self, 0x90) = 0xffff;
        func_ov000_02198360(LFLD(void *, self, 0x40), 1, 0);
        break;
    }
    func_ov000_0218d988(self, t, 0x400);
}

}
