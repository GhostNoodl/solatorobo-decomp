#include "ov002/ov002.h"

extern "C" {

#define SIN_TABLE FX_SINCOS_TABLE

void func_ov002_021d91d8(void *self);

void func_ov002_021d8fac(void *self) {
    switch (FIELD(self, 0x98, s32)) {
    case 0:
        func_ov002_021d91d8(self);
        FIELD(self, 0x98, s32) = 10;
    case 10:
        *FIELD(self, 0x88, s32 *) = FIELD(self, 0xac, s32) << 12;
        if (FIELD(self, 0x9c, u8)) {
            FIELD(self, 0xa4, s32) = FX_MUL(SIN_TABLE[((FIELD(self, 0xa0, s32) * 0x444) >> 4) * 2], 0xccd) + 0x333;
            if (--FIELD(self, 0xa0, s32) < 0) {
                FIELD(self, 0xa0, s32) = 30;
            }
        } else {
            FIELD(self, 0xa4, s32) = 0x1000;
            FIELD(self, 0xa0, s32) = 0;
        }
        break;
    }
}

static inline void *ov002_Model_GetPart(void *self, int idx) {
    if (idx >= FIELD(self, 0x80, s32)) {
        return NULL;
    }
    return (u8 *)FIELD(self, 0x78, void *) + idx * 0x28;
}

static inline void ov002_Model_PlayPart(void *model, int idx) {
    void *res = FIELD(model, 0x28, void *);
    void *part;
    void *anim;
    if (res == NULL) {
        return;
    }
    part = ov002_Model_GetPart(model, idx);
    if (part != NULL && FIELD(part, 0x4, void *) != NULL) {
        anim = FIELD(FIELD(part, 0x4, void *), 0x30, void *);
    } else {
        anim = func_02023410(FIELD(res, 0x4, void *), **(u16 **)FIELD(func_02023390(FIELD(res, 0xc, void *), idx), 0xc, void *));
    }
    func_02042628(model, anim, part, 0);
}

static inline void ov002_setXY(void *o, s32 x, s32 y) {
    FIELD(o, 0xfc, s32) = x & ~0xfff;
    FIELD(o, 0x100, s32) = y << 12;
}

void func_ov002_021e3b6c(s32 *out, s32 *v, void *m);

void func_ov002_021d9070(void *self) {
    s32 out[2];
    if (FIELD(self, 0x80, void *) == NULL) {
        return;
    }
    if (!func_0203e63c(FIELD(self, 0x84, void *))) {
        return;
    }
    func_0202711c((u8 *)self + 0x4);
    MI_Copy36B((u8 *)self + 0x18, data_020928b4);
    data_020927f8.fc &= ~0xa4;
    func_0202714c((u8 *)self + 0x3c);
    func_020270a4();
    func_02027ae4(FIELD(self, 0x80, void *));
    func_0202a1d4();
    if (!FIELD(self, 0x94, u8)) {
        return;
    }
    {
    void *m = FIELD(self, 0xb0, void *);
    s32 v[3] = {0, 0, 0};
    v[0] = (FIELD(self, 0x54, s32) - 2) * 0x28f;
    v[1] = 0;
    v[2] = (FIELD(self, 0x58, s32) - 2) * 0x28f;
    func_ov002_021e3b6c(out, v, m);
    ov002_setXY(FIELD(self, 0x90, void *), out[0], out[1] >> 12);
    }
    ov002_Model_PlayPart(FIELD(self, 0x90, void *), 6);
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

void *func_02035de0(void *file, void *name);

void func_02041c20(void *a, int b, void *c);

void func_02041c34(void *a, int b, void *c, int d);

extern void *data_0208cc88;

void func_ov002_021e0420(void);

void func_ov002_021d8d00(void);

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

void func_ov002_021d91d8(void *self) {
    void *res;
    u8 *info;
    char buf[16];
    u32 *q;
    char *name;
    void *a;
    res = func_02035d5c(data_ov002_021efdf6);
    info = func_0206ede8(FIELD(self, 0x48, u16));
    FIELD(self, 0x78, u32 *) = (u32 *)func_02034ec0(res, FIELD(info, 0x8, void *));
    ov002_strSet(buf, &FIELD(info, 0xc, void *), sizeof(buf));
    FIELD(self, 0x7c, void *) = ov002_findEntry((u8 *)func_0202ac90((void *)*FIELD(self, 0x78, u32 *)), buf);
    name = (char *)FIELD(self, 0x78, u32 *);
    if (FIELD(self, 0x78, u32 *) != NULL) {
        name = func_0203ed04(buf, *FIELD(self, 0x78, u32 *));
    }
    FIELD(self, 0x84, void *) = func_0203ebf8(name);
    FIELD(self, 0x80, void *) = func_0203dd9c(0x54);
    func_02026508(FIELD(self, 0x80, void *), FIELD(self, 0x7c, void *));
    func_020267c0(FIELD(self, 0x80, void *), (void *)func_ov002_021e0420, 0, 4, 2);
    FIELD(FIELD(self, 0x80, void *), 0x2c, void *) = (u8 *)self + 0xa4;
    q = (u32 *)func_02034ff8(res, FIELD(info, 0x8, void *));
    func_0201e5a0(buf, FIELD(info, 0xc, void *), sizeof(buf));
    a = func_0202ad3c((void *)q[1], buf);
    FIELD(self, 0x88, void *) = func_0203de84(func_02026410(a, FIELD(self, 0x7c, void *)), 4);
    func_02026470(FIELD(self, 0x88, void *), a, FIELD(self, 0x7c, void *), (int)func_0202aca0((void *)*FIELD(self, 0x78, u32 *)));
    func_02026678(FIELD(self, 0x80, void *), FIELD(self, 0x88, void *));
    FIELD(FIELD(self, 0x88, void *), 0, s32) = FIELD(self, 0xac, s32) << 12;
    if (FIELD(self, 0x94, u8)) {
        void *m = func_0203dd9c(0x160);
        if (m != NULL) {
            void *file = data_0208cc94;
            void *nm = data_0208cc88;
            func_02041218((u8 *)m + 0x88);
            func_02041440(m, nm, 0);
            func_0201e520((u8 *)m + 0x2c, file);
        }
        FIELD(self, 0x90, void *) = m;
        func_020417e0(FIELD(self, 0x90, void *), func_02035de0(data_0208cc94, data_0208cc88));
        FIELD(FIELD(self, 0x90, void *), 0x6c, u32) |= 2;
        FIELD(FIELD(self, 0x90, void *), 0x150, s32) = -0x2000;
        func_02041c20(FIELD(self, 0x90, void *), 6, self);
        func_02041c34(FIELD(self, 0x90, void *), 6, (void *)func_ov002_021d8d00, 0);
        func_02041d9c(FIELD(self, 0x90, void *), 0, 6);
    }
    FIELD(self, 0x8, s32) = 0;
}

}
