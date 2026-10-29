#include "nitro/fx.h"
#include "ov000/VObj.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u16 st;
    u16 timer;
} State021971c4;

typedef struct {
    u8 unk_00[0x158];
    u32 flags[1][4];
} Save021971c4;

extern "C" {
extern char data_ov000_021cc469[];
extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern Save021971c4 *data_0214a424;
void *func_ov000_02199ba0(void *p);
BOOL func_ov000_02190cb0(void *a, const char *b, s32 c, s32 d);
void *func_ov000_0218e640(void *mgr, u16 id);
void func_ov000_0218d46c(void *o, u16 id, s32 c);
void func_ov000_02199b88(void *a, void *b);
BOOL func_ov000_02199cd8(void *a, u16 id);
BOOL func_ov000_02191120(void *a);
void func_ov000_0218d398(void *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
u8 *func_020704b4(u16 id);
void func_ov000_0219b400(u16 *ids, u8 *rates, s32 n, void *pos, void *rot, u8 check);
BOOL func_ov000_02198360(void *s, s32 a, s32 b);
u16 func_0206e7ec(u32 a, u32 b);
void func_020627c8(void);
void func_ov000_0218bed8(void *a, s32 b, void *c);
u16 func_ov000_02199bc8(void *a, void *pos, s32 b, s32 c);

static inline void *FindActor021971c4(u16 id) {
    void *mgr = data_ov000_021ccd68;
    if (mgr == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(mgr, id);
}

static inline void SetNibble021971c4(s32 row, s32 idx, u32 value) {
    s32 sh = idx % 8;
    u32 *p;

    sh *= 4;
    p = &data_0214a424->flags[row][idx / 8];
    *p = (*p & ~(0xf << sh)) | ((value & 0xf) << sh);
}

static inline int GetNibble021971c4(s32 row, s32 idx) {
    u32 v = data_0214a424->flags[row][idx / 8];
    return (v >> ((idx % 8) * 4)) & 0xf;
}

void func_ov000_021971c4(VObj *obj) {
    u8 *self = (u8 *)obj;
    u32 none = 0xffff;
    s32 zero = 0;
    u8 *tgt = (u8 *)func_ov000_02199ba0(LFLD(u8 *, self, 0x4c));
    switch (LFLD(State021971c4 *, self, 0x40)->st) {
    case 0:
        if (LFLD(void *, self, 0x38) != NULL) {
            func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc469, 0x1000, zero);
        }
        if (tgt != NULL) {
            if (LFLD(u16, self, 0x90) != none) {
                u8 *a;
                obj->vfunc_88();
                a = (u8 *)FindActor021971c4(LFLD(u16, self, 0x90));
                if (a != NULL) {
                    func_ov000_0218d46c(a, LFLD(u16, self, 0xc), 6);
                    LFLD(u16, a, 0x90) = none;
                    if (LFLD(void *, a, 0x4c) != NULL) {
                        func_ov000_02199b88(LFLD(void *, a, 0x4c), self);
                    }
                }
            } else if (func_ov000_02199cd8(LFLD(void *, self, 0x4c), LFLD(u16, tgt, 0xe))) {
                obj->vfunc_8c();
                LFLD(u16, LFLD(u8 *, self, 0x4c), 0x1c) = none;
            }
        }
        LFLD(State021971c4 *, self, 0x40)->st++;
        break;
    case 1:
        if (LFLD(void *, self, 0x38) != NULL && !func_ov000_02191120(LFLD(void *, self, 0x38))) {
            break;
        }
        if (tgt != NULL) {
            func_ov000_0218d398(tgt, LFLD(u16, self, 0xc), 3, 1, zero, (const void *)zero);
        }
        if (LFLD(u8, LFLD(u8 *, self, 0x4c), 1) == 8) {
            u8 *d = func_020704b4(LFLD(u16, self, 0xe));
            func_ov000_0219b400((u16 *)(d + 0x20), d + 0x24, 2, self + 0x70, self + 0x7c, zero);
        }
        if (LFLD(u16, self, 0x90) != none) {
            u8 *m = LFLD(u8 *, self, 0x4c);
            if (LFLD(u8, m, 2) != 0 && LFLD(u8, m, 2) != 7) {
                LFLD(u16, m, 0x1c) = none;
            } else {
                func_ov000_02198360(LFLD(void *, self, 0x40), 9, 0);
            }
            LFLD(u16, self, 0x90) = none;
        } else {
            LFLD(u16, LFLD(u8 *, self, 0x4c), 0x1c) = none;
            func_ov000_02198360(LFLD(void *, self, 0x40), 1, 0);
        }
        if (LFLD(u8, LFLD(u8 *, self, 0x4c), 2) == 5) {
            u8 idx = LFLD(u8, self, 0x17);
            s32 row;
            if (idx != 0xff) {
                row = func_0206e7ec(LFLD(u8, self, 0xac), LFLD(u8, self, 0xad));
                if (row != none) {
                    u8 val = 0xf;
                    val |= GetNibble021971c4(row, idx) & 8;
                    SetNibble021971c4(row, idx, val);
                }
            }
            func_020627c8();
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            obj->vfunc_08();
        }
        break;
    }
    if (tgt != NULL && LFLD(u16, self, 0x90) != none) {
        func_ov000_02199bc8(LFLD(void *, self, 0x4c), self + 0x70, 0, 0);
        LFLD(u16, self, 0x7c) = LFLD(u16, tgt, 0x7c);
        LFLD(u16, self, 0x7e) = LFLD(u16, tgt, 0x7e);
        LFLD(u16, self, 0x80) = LFLD(u16, tgt, 0x80);
    }
}

}
