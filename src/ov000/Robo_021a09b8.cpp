#include "ov000/LoCommon.h"

typedef struct {
    u16 b0 : 4;
    u16 b4 : 2;
    u16 rest : 10;
} Bits021a09b8_2c;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Bits021a09b8_18;

extern "C" {
extern u8 *data_ov000_021ccd54;
extern void *data_ov000_021ccd68;
void *func_ov000_0218e640(void *mgr, u16 id);
s32 func_ov000_0219840c(void *s, s32 *list, s32 count, BOOL push);
BOOL func_ov000_02198360(void *s, s32 a, s32 b);
void func_020627a0(u16 a, u16 b);
void func_020627dc(u16 a);
void func_ov000_02182590(void *p);
BOOL func_0205b1fc(void);
void func_0205c234(s32 a, s32 b);

static inline void *FindActor021a09b8(u16 id) {
    void *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(mgr, id);
}

static inline void Ping021a09b8(void) {
    u8 *g = data_ov000_021ccd54;
    LFLD(u8, g, 0xac) = 1;
    func_ov000_02182590(g + 0xac);
}

s32 func_ov000_021a09b8(u8 *self, s32 *list, s32 count) {
    u8 *a;
    u8 kind;
    s32 r;
    u8 *sub;
    BOOL done;

    a = NULL;
    r = func_ov000_0219840c(LFLD(void *, self, 0x40), list, count, FALSE);
    if (r == 0) {
        return r;
    }
    a = (u8 *)FindActor021a09b8(LFLD(u16, self, 0x90));
    sub = NULL;
    if (a != NULL) {
        sub = LFLD(u8 *, a, 0x4c);
    }
    kind = 0;
    if (sub != NULL) {
        kind = sub[0];
    }
    done = FALSE;
    switch (r) {
    case 6:
        if (a == NULL || sub == NULL) {
            break;
        }
        if (kind != 4 && kind != 6 && kind != 0xc && kind != 0xd) {
            break;
        }
        if (LFLD(Bits021a09b8_18, sub, 0x18).b1 && sub[3] != 0xa && sub[3] != 0xb) {
            func_020627a0(LFLD(u16, a, 0xe), LFLD(u16, a, 0xc));
            func_020627dc(LFLD(u16, a, 0x18));
            Ping021a09b8();
            if (func_0205b1fc()) {
                done = TRUE;
            }
        }
        if (done) {
            r = 0;
        } else {
            switch (sub[0]) {
            case 6:
                if (LBIT(self, 0xb24).b1) {
                    r = 0;
                    func_0205c234(0x64, 0);
                }
                break;
            case 0xc:
            case 0xd:
                if (!LBIT(self, 0xb24).b1) {
                    r = 0;
                    func_0205c234(0x65, 0);
                }
                break;
            }
        }
        break;
    case 7:
    case 0x18:
        if (a == NULL || sub == NULL) {
            break;
        }
        if (kind != 5 && kind != 0xe && kind != 0xf && kind != 0x11 && kind != 0x13 && kind != 0x12 && kind != 0x14) {
            break;
        }
        if (LFLD(Bits021a09b8_18, sub, 0x18).b1) {
            func_020627a0(LFLD(u16, a, 0xe), LFLD(u16, a, 0xc));
            func_020627dc(LFLD(u16, a, 0x18));
            Ping021a09b8();
            if (func_0205b1fc()) {
                done = TRUE;
            }
        }
        if (done) {
            r = 0;
            LFLD(Bits021a09b8_2c, self, 0xb2c).b4 = 0;
        } else if (!LBIT(self, 0xb24).b1) {
            r = 0;
            func_0205c234(0x65, 0);
        }
        break;
    case 8:
    case 0x1e:
        if (a == NULL || sub == NULL) {
            break;
        }
        if (LFLD(Bits021a09b8_18, sub, 0x18).b1 && sub[3] != 0xa && sub[3] != 0xb) {
            func_020627a0(LFLD(u16, a, 0xe), LFLD(u16, a, 0xc));
            func_020627dc(LFLD(u16, a, 0x18));
            Ping021a09b8();
            if (func_0205b1fc()) {
                done = TRUE;
            }
        }
        if (done) {
            r = 0;
        } else if (LBIT(self, 0xb24).b1) {
            r = 0;
            func_0205c234(0x64, 0);
        }
        break;
    case 0x10:
        if (a == NULL) {
            break;
        }
        func_020627a0(LFLD(u16, a, 0xe), LFLD(u16, a, 0xc));
        Ping021a09b8();
        if (func_0205b1fc()) {
            r = 0;
        }
        break;
    case 0x1d:
        func_020627a0(LFLD(u16, a, 0xe), LFLD(u16, a, 0xc));
        Ping021a09b8();
        if (func_0205b1fc()) {
            r = 0;
        } else {
            switch (sub[0]) {
            case 8:
                if (LBIT(self, 0xb24).b1) {
                    func_0205c234(0x64, 0);
                    r = 0;
                }
                break;
            case 0x10:
                if (!LBIT(self, 0xb24).b1) {
                    func_0205c234(0x65, 0);
                    r = 0;
                }
                break;
            }
        }
        break;
    }
    if (r != 0) {
        func_ov000_02198360(LFLD(void *, self, 0x40), (u8)r, 0);
    }
    return r;
}

}
