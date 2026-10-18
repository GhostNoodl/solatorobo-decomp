#include "ov002/ov002.h"

extern "C" {

void *func_02035d5c(void *a);

void *func_02034ec0(void *a, void *b);

void *func_0202a970(void *a, char *name);

char *func_0203ed04(char *name, u32 a);

void *func_0203ebf8(char *name);

u32 func_02026410(void *a, void *b);

void func_02026470(void *a, void *b, void *c, int d);

void func_02026678(void *a, void *b);

static inline void ov002_strSet(char *dst, void **src, u32 n) {
    MIi_CpuClear32(0, dst, n);
    func_0201e5a0(dst, *src, n);
}

static inline void *ov002_findEntry(u8 *d, char *name) {
    u32 *e;
    if (d != NULL && (e = (u32 *)func_0202a970(d + 8, name)) != NULL) {
        return d + *e;
    }
    return NULL;
}

void func_ov002_021d7620(void *self) {
    void *res;
    char buf[16];
    u32 *q;
    char *name;
    res = func_02035d5c(FIELD(self, 0x4, void *));
    FIELD(self, 0x18, void *) = func_0203dd9c(0x54);
    FIELD(self, 0x10, u32 *) = (u32 *)func_02034ec0(res, FIELD(self, 0x8, void *));
    ov002_strSet(buf, &FIELD(self, 0x8, void *), sizeof(buf));
    FIELD(self, 0x14, void *) = ov002_findEntry((u8 *)func_0202ac90((void *)*FIELD(self, 0x10, u32 *)), buf);
    name = FIELD(self, 0x8, char *);
    if (FIELD(self, 0x10, u32 *) != NULL) {
        name = func_0203ed04(name, *FIELD(self, 0x10, u32 *));
    }
    FIELD(self, 0x1c, void *) = func_0203ebf8(name);
    func_02026508(FIELD(self, 0x18, void *), FIELD(self, 0x14, void *));
    q = (u32 *)func_02034ff8(res, FIELD(self, 0xc, void *));
    ov002_strSet(buf, &FIELD(self, 0xc, void *), sizeof(buf));
    if (q[0] != 0) {
        void *a = func_0202ad3c((void *)q[0], buf);
        FIELD(self, 0x20, void *) = func_0203de84(func_02026410(a, FIELD(self, 0x14, void *)), 4);
        func_02026470(FIELD(self, 0x20, void *), a, FIELD(self, 0x14, void *), 0);
        func_02026678(FIELD(self, 0x18, void *), FIELD(self, 0x20, void *));
    }
    if (q[1] != 0) {
        void *a = func_0202ad3c((void *)q[1], buf);
        FIELD(self, 0x24, void *) = func_0203de84(func_02026410(a, FIELD(self, 0x14, void *)), 4);
        func_02026470(FIELD(self, 0x24, void *), a, FIELD(self, 0x14, void *), 0);
        func_02026678(FIELD(self, 0x18, void *), FIELD(self, 0x24, void *));
    }
    if (q[2] != 0) {
        void *a = func_0202ad3c((void *)q[2], buf);
        FIELD(self, 0x28, void *) = func_0203de84(func_02026410(a, FIELD(self, 0x14, void *)), 4);
        func_02026470(FIELD(self, 0x28, void *), a, FIELD(self, 0x14, void *), 0);
        func_02026678(FIELD(self, 0x18, void *), FIELD(self, 0x28, void *));
    }
    if (FIELD(self, 0x20, void *) != NULL) {
        FIELD(self, 0x30, s32) = FIELD(FIELD(FIELD(self, 0x20, u8 *), 0x8, u8 *), 0x4, u16) << 12;
    } else if (FIELD(self, 0x24, void *) != NULL) {
        FIELD(self, 0x30, s32) = FIELD(FIELD(FIELD(self, 0x24, u8 *), 0x8, u8 *), 0x4, u16) << 12;
    } else if (FIELD(self, 0x28, void *) != NULL) {
        FIELD(self, 0x30, s32) = FIELD(FIELD(FIELD(self, 0x28, u8 *), 0x8, u8 *), 0x4, u16) << 12;
    }
}

}
