#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d80a0(void *self) {
    if (FIELD(self, 0x80, void *) == NULL) {
        return;
    }
    if (!func_0203e63c(FIELD(self, 0x84, void *)) || FIELD(self, 0xac, s32) == 0) {
        return;
    }
    func_ov002_021d83f0(self);
    if (FIELD(self, 0x9c, s32) != 0x1000) {
        func_0202a8f0(FIELD(self, 0x7c, void *), func_02043d48(data_02097d48 + 0x8b0));
    }
    func_0202711c((u8 *)self + 0x4);
    func_02016dbc((u8 *)self + 0x18, data_020928b4);
    data_020927f8.fc &= ~0xa4;
    func_0202714c((u8 *)self + 0x3c);
    func_020270a4();
    func_02027ae4(FIELD(self, 0x80, void *));
    func_0202a1d4();
}

void *func_02035d5c(void *a);

void *func_02034ec0(void *a, void *b);

void *func_0202a970(void *a, char *name);

char *func_0203ed04(char *name, u32 a);

void *func_0203ebf8(char *name);

u32 func_02026410(void *a, void *b);

void func_02026470(void *a, void *b, void *c, int d);

void func_02026678(void *a, void *b);

void func_020267c0(void *a, void *fn, int b, int c, int d);

void func_0202a8b0(void *a, int b);

void func_0202a930(void *a, int b);

void func_ov002_021e0420(void);

static inline void *ov002_findEntry(u8 *d, char *name) {
    u32 *e;
    if (d != NULL && (e = (u32 *)func_0202a970(d + 8, name)) != NULL) {
        return d + *e;
    }
    return NULL;
}

void func_ov002_021d8148(void *self) {
    void *res;
    char *name;
    void *n8;
    void *nc;
    u32 *q;
    char buf[16];
    u8 *info;
    info = func_0206ede8(FIELD(self, 0x48, u16));
    n8 = FIELD(info, 0x8, void *);
    nc = FIELD(info, 0xc, void *);
    res = func_02035d5c(data_ov002_021efdf6);
    FIELD(self, 0x78, u32 *) = (u32 *)func_02034ec0(res, n8);
    func_02016cd8(0, buf, sizeof(buf));
    func_0201e5a0(buf, nc, sizeof(buf));
    FIELD(self, 0x7c, void *) = ov002_findEntry((u8 *)func_0202ac90((void *)*FIELD(self, 0x78, u32 *)), buf);
    name = FIELD(info, 0x8, char *);
    if (FIELD(self, 0x78, u32 *) != NULL) {
        name = func_0203ed04(name, *FIELD(self, 0x78, u32 *));
    }
    FIELD(self, 0x84, void *) = func_0203ebf8(name);
    FIELD(self, 0x80, void *) = func_0203dd9c(0x54);
    func_02026508(FIELD(self, 0x80, void *), FIELD(self, 0x7c, void *));
    func_0202a8b0(FIELD(self, 0x7c, void *), 2);
    func_0202a930(FIELD(self, 0x7c, void *), 0);
    func_020267c0(FIELD(self, 0x80, void *), (void *)func_ov002_021e0420, 0, 4, 2);
    FIELD(FIELD(self, 0x80, void *), 0x2c, void *) = (u8 *)self + 0x9c;
    q = (u32 *)func_02034ff8(res, n8);
    func_02016cd8(0, buf, sizeof(buf));
    func_0201e5a0(buf, nc, sizeof(buf));
    if (q[0] != 0) {
        void *a = func_0202ad3c((void *)q[0], buf);
        if (a != NULL) {
            FIELD(self, 0x88, void *) = func_0203de84(func_02026410(a, FIELD(self, 0x7c, void *)), 4);
            func_02026470(FIELD(self, 0x88, void *), a, FIELD(self, 0x7c, void *), 0);
            func_02026678(FIELD(self, 0x80, void *), FIELD(self, 0x88, void *));
        }
    }
    if (q[1] != 0) {
        void *a = func_0202ad3c((void *)q[1], buf);
        if (a != NULL) {
            FIELD(self, 0x8c, void *) = func_0203de84(func_02026410(a, FIELD(self, 0x7c, void *)), 4);
            func_02026470(FIELD(self, 0x8c, void *), a, FIELD(self, 0x7c, void *), 0);
            func_02026678(FIELD(self, 0x80, void *), FIELD(self, 0x8c, void *));
        }
    }
    if (q[2] != 0) {
        void *a = func_0202ad3c((void *)q[2], buf);
        if (a != NULL) {
            FIELD(self, 0x90, void *) = func_0203de84(func_02026410(a, FIELD(self, 0x7c, void *)), 4);
            func_02026470(FIELD(self, 0x90, void *), a, FIELD(self, 0x7c, void *), (int)func_0202aca0((void *)*FIELD(self, 0x78, u32 *)));
            func_02026678(FIELD(self, 0x80, void *), FIELD(self, 0x90, void *));
        }
    }
    if (FIELD(self, 0x88, void *) != NULL) {
        FIELD(self, 0x98, s32) = FIELD(FIELD(FIELD(self, 0x88, u8 *), 0x8, u8 *), 0x4, u16) << 12;
    } else if (FIELD(self, 0x8c, void *) != NULL) {
        FIELD(self, 0x98, s32) = FIELD(FIELD(FIELD(self, 0x8c, u8 *), 0x8, u8 *), 0x4, u16) << 12;
    } else if (FIELD(self, 0x90, void *) != NULL) {
        FIELD(self, 0x98, s32) = FIELD(FIELD(FIELD(self, 0x90, u8 *), 0x8, u8 *), 0x4, u16) << 12;
    }
}

}
