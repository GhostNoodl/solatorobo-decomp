#include "ov000/LoCommon.h"

typedef struct {
    char *name;
    s32 x;
    s32 y;
} Ent_021bd8ac;

extern "C" {
extern char data_0214b105[];
extern char *data_0208cc88;
extern char *data_0208cc94;
extern char *data_0208cb74;
extern char *data_0208cca0;
extern char *data_0208cb7c;
extern Ent_021bd8ac data_ov000_021cc8f0[];
extern char data_ov000_021cc920[];
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void STD_CopyString(void *dst, const void *src);
void *func_ov000_0218e9c4(void *p);
BOOL func_ov000_0218f110(void *p);

static inline u8 *NewModel_021bd8ac(char **name) {
    char *nm;
    u8 *m = (u8 *)func_0203dd9c(0x160);
    if (m != NULL) {
        nm = *name;
        func_02041218(m + 0x88);
        func_02041440(m, nm, 0);
    }
    return m;
}

static inline void SetA_021bd8ac(u8 *p, const char *dir, const char *name) {
    STD_CopyString(p + 0x10, dir);
    STD_CopyString(p + 0x30, name);
    LFLD(u8, p, 3) |= 2;
}

static inline void SetB_021bd8ac(u8 *p, const char *dir, const char *name) {
    STD_CopyString(p + 0x4c, dir);
    STD_CopyString(p + 0x6c, name);
    LFLD(u8, p, 3) |= 4;
}

BOOL func_ov000_021bd8ac(u8 *self) {
    void *res;
    s32 n;

    if (!func_02035d5c(data_0214b105) || !func_02035d5c(data_0208cca0) || !func_02035d5c(data_0208cc94)) {
        return FALSE;
    }
    n = LFLD(s32, self, 0x48);
    if (n >= 0xc && n < 0x10) {
        n = 0xb;
    }
    u8 *mdl[4] = {NULL, NULL, NULL, NULL};
    switch (n) {
    case 0:
        res = func_02034d88(func_02035d5c(data_0208cca0), data_0208cb74);
        mdl[0] = NewModel_021bd8ac(&data_0208cb74);
        func_020417e0(mdl[0], res);
        LFLD(u32, mdl[0], 0x6c) |= 2;
        func_02041d9c(mdl[0], 0, 3);
        break;
    case 1:
        res = func_02034d88(func_02035d5c(data_0208cca0), data_0208cb74);
        mdl[0] = NewModel_021bd8ac(&data_0208cb74);
        func_020417e0(mdl[0], res);
        LFLD(u32, mdl[0], 0x6c) |= 2;
        func_02041d9c(mdl[0], 0, 4);
        break;
    case 2:
        res = func_02034d88(func_02035d5c(data_0208cca0), data_0208cb74);
        mdl[0] = NewModel_021bd8ac(&data_0208cb74);
        func_020417e0(mdl[0], res);
        LFLD(u32, mdl[0], 0x6c) |= 2;
        func_02041d9c(mdl[0], 0, 0xf);
        break;
    case 3:
        res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
        mdl[0] = NewModel_021bd8ac(&data_0208cc88);
        func_020417e0(mdl[0], res);
        LFLD(u32, mdl[0], 0x6c) |= 2;
        func_02041d9c(mdl[0], 0, 2);
        res = func_02034d88(func_02035d5c(data_0208cca0), data_0208cb74);
        mdl[1] = NewModel_021bd8ac(&data_0208cb74);
        func_020417e0(mdl[1], res);
        LFLD(u32, mdl[1], 0x6c) |= 2;
        func_02041d9c(mdl[1], 0, 2);
        res = func_02034d88(func_02035d5c(data_0214b105), data_0208cb7c);
        mdl[2] = NewModel_021bd8ac(&data_0208cb7c);
        func_020417e0(mdl[2], res);
        LFLD(u32, mdl[2], 0x6c) |= 2;
        func_02041d9c(mdl[2], 0, 7);
        break;
    case 4:
        res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
        mdl[0] = NewModel_021bd8ac(&data_0208cc88);
        func_020417e0(mdl[0], res);
        LFLD(u32, mdl[0], 0x6c) |= 2;
        func_02041d9c(mdl[0], 0, 3);
        func_02041d9c(mdl[0], 0, 0x10);
        break;
    case 5:
        res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
        mdl[0] = NewModel_021bd8ac(&data_0208cc88);
        func_020417e0(mdl[0], res);
        LFLD(u32, mdl[0], 0x6c) |= 2;
        func_02041d9c(mdl[0], 0, 3);
        func_02041d9c(mdl[0], 0, 0x11);
        break;
    case 6:
        res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
        mdl[0] = NewModel_021bd8ac(&data_0208cc88);
        func_020417e0(mdl[0], res);
        LFLD(u32, mdl[0], 0x6c) |= 2;
        func_02041d9c(mdl[0], 0, 2);
        res = func_02034d88(func_02035d5c(data_0208cca0), data_0208cb74);
        mdl[1] = NewModel_021bd8ac(&data_0208cb74);
        func_020417e0(mdl[1], res);
        LFLD(u32, mdl[1], 0x6c) |= 2;
        func_02041d9c(mdl[1], 0, 2);
        res = func_02034d88(func_02035d5c(data_0214b105), data_0208cb7c);
        mdl[2] = NewModel_021bd8ac(&data_0208cb7c);
        func_020417e0(mdl[2], res);
        LFLD(u32, mdl[2], 0x6c) |= 2;
        func_02041d9c(mdl[2], 0, 6);
        break;
    case 7:
        res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
        mdl[0] = NewModel_021bd8ac(&data_0208cc88);
        func_020417e0(mdl[0], res);
        LFLD(u32, mdl[0], 0x6c) |= 2;
        func_02041d9c(mdl[0], 0, 3);
        func_02041d9c(mdl[0], 0, 4);
        break;
    case 8:
        res = func_02034d88(func_02035d5c(data_0214b105), data_0208cb7c);
        mdl[0] = NewModel_021bd8ac(&data_0208cb7c);
        func_020417e0(mdl[0], res);
        LFLD(u32, mdl[0], 0x6c) |= 2;
        func_02041d9c(mdl[0], 0, 8);
        res = func_02034d88(func_02035d5c(data_0208cca0), data_0208cb74);
        mdl[1] = NewModel_021bd8ac(&data_0208cb74);
        func_020417e0(mdl[1], res);
        LFLD(u32, mdl[1], 0x6c) |= 2;
        func_02041d9c(mdl[1], 0, 2);
        break;
    case 9:
        res = func_02034d88(func_02035d5c(data_0214b105), data_0208cb7c);
        mdl[0] = NewModel_021bd8ac(&data_0208cb7c);
        func_020417e0(mdl[0], res);
        LFLD(u32, mdl[0], 0x6c) |= 2;
        func_02041d9c(mdl[0], 0, 9);
        res = func_02034d88(func_02035d5c(data_0208cca0), data_0208cb74);
        mdl[1] = NewModel_021bd8ac(&data_0208cb74);
        func_020417e0(mdl[1], res);
        LFLD(u32, mdl[1], 0x6c) |= 2;
        func_02041d9c(mdl[1], 0, 2);
        break;
    case 10:
        res = func_02034d88(func_02035d5c(data_0208cca0), data_0208cb74);
        mdl[0] = NewModel_021bd8ac(&data_0208cb74);
        func_020417e0(mdl[0], res);
        LFLD(u32, mdl[0], 0x6c) |= 2;
        func_02041d9c(mdl[0], 0, 0);
        func_02041d9c(mdl[0], 0, 1);
        break;
    case 11:
        if (LFLD(void *, self, 4) == NULL) {
            Ent_021bd8ac *e = &data_ov000_021cc8f0[LFLD(s32, self, 0x48) - 0xc];
            u8 *p = (u8 *)func_0203dd9c(0x138);
            if (p != NULL) {
                p = (u8 *)func_ov000_0218e9c4(p);
            }
            LFLD(u8 *, self, 4) = p;
            SetA_021bd8ac(p, data_ov000_021cc920, e->name);
            SetB_021bd8ac(LFLD(u8 *, self, 4), data_ov000_021cc920, e->name);
            LFLD(u16, LFLD(u8 *, self, 4), 0) = 0;
        }
        if (LFLD(void *, self, 4) != NULL) {
            func_ov000_0218f110(LFLD(void *, self, 4));
            return LFLD(s16, LFLD(u8 *, self, 4), 0) < 0 ? TRUE : FALSE;
        }
        break;
    }
    LFLD(u8 *, self, 0x18) = mdl[0];
    LFLD(u8 *, self, 0x1c) = mdl[1];
    LFLD(u8 *, self, 0x20) = mdl[2];
    return TRUE;
}
}
