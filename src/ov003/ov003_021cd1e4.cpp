#include "types.h"

class Ov003TlSub {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Move(s32 x, s32 y, s32 z);

    u32 unk_04;
    u8 unk_08[0xb0];
    u32 unk_b8;
};

typedef struct {
    u8 unk_00[4];
    u32 unk_04;
} Ov003TlRend;

class Ov003TlObj {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual s32 v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
};

class Ov003TlLabel : public Ov003TlObj {
public:
    u8 unk_04[8];
    u32 flags;
    u8 unk_10[0x10];
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    u8 unk_30[0x28];
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s16 unk_64;
    s16 unk_66;
    s16 unk_68;
    u8 unk_6a[0x1a];
    Ov003TlSub *unk_84;
};

typedef struct {
    u8 unk_00[0x2c];
    char unk_2c[0x40];
    u32 unk_6c;
    u8 unk_70[0x18];
    u8 unk_88[0xc8];
    s32 unk_150;
    u8 unk_154[4];
    void *unk_158;
    u8 unk_15c[4];
} Ov003TlSpr;

class Ov003Tl : public Ov003TlObj {
public:
    u8 unk_04[0x38];
    Ov003TlLabel *unk_3c;
    u8 unk_40[4];
    Ov003TlSpr *unk_44;
    Ov003TlSpr *unk_48;
    Ov003TlSpr *unk_4c;
    char *unk_50;
    char *unk_54;
    u8 unk_58[4];
    u32 unk_5c;
    u8 unk_60[4];
    u16 unk_64;
    u16 unk_66;
    u8 unk_68;
    u8 unk_69;
    u8 unk_6a[0x22];
    char unk_8c[0x40];
};

extern "C" {

extern void *data_ov000_021cac60[];
extern void *data_ov000_021cadcc[];
extern char data_ov003_021f78c4[];
extern char data_ov003_021f78cd[];
extern void *func_0203dd9c(u32 size);
extern const char *func_0206ec48(u16 id);
extern void func_ov003_021ce2a8(void *self, char *dst, u32 size, const char *arg);
extern void func_ov000_0215bb14(Ov003TlLabel *l, char *s);
extern void func_02041218(void *p);
extern void func_02041440(Ov003TlSpr *s, const char *name, s32 a);
extern void STD_CopyString(char *dst, const char *src);
extern void *func_02035f30(const char *a, const char *b, s32 c);
extern void *func_02034d88(void *a, const char *b);
extern void func_020417e0(Ov003TlSpr *s, void *res);
extern void func_02041c5c(Ov003TlSpr *s, void *cb);
extern void func_02041c18(Ov003TlSpr *s, s32 a);
extern void func_02041c20(Ov003TlSpr *s, u16 a, u16 b);
extern void func_02041d9c(Ov003TlSpr *s, s32 a, u16 b);
extern void func_ov000_02173648(Ov003Tl *self);
extern void func_ov003_021cceb4(void);
extern void *func_ov003_021cce20(void);
extern void func_ov000_021c8408(void);

static inline void Ov003TlSpr_Init(Ov003TlSpr *s, const char *file, const char *name) {
    func_02041218(s->unk_88);
    func_02041440(s, name, 0);
    STD_CopyString(s->unk_2c, file);
}

static inline void Ov003TlSpr_Load(Ov003TlSpr *s, const char *file, const char *name) {
    func_020417e0(s, func_02034d88(func_02035f30(file, name, 2), name));
}

void func_ov003_021cd1e4(Ov003Tl *self) {
    Ov003TlLabel *l;
    void *res;
    if (self->v28()) {
        return;
    }
    l = (Ov003TlLabel *)func_0203dd9c(0x8c);
    if (l != NULL) {
        *(void ***)l = data_ov000_021cac60;
        l->v28();
        *(void ***)l = data_ov000_021cadcc;
        l->v28();
    }
    self->unk_3c = l;
    l->unk_20 = 2;
    self->unk_3c->unk_24 = 0xf8;
    {
        Ov003TlLabel *p = self->unk_3c;
        p->unk_64 = 3;
        p->unk_66 = 0x96;
        p->unk_68 = -0x1000;
    }
    {
        Ov003TlLabel *p = self->unk_3c;
        p->unk_58 = -0x100;
        p->unk_5c = 0;
        p->unk_60 = -0x1000;
    }
    self->unk_3c->unk_2c = 1;
    func_ov003_021ce2a8(self, self->unk_8c, 0x40, func_0206ec48(self->unk_64));
    func_ov000_0215bb14(self->unk_3c, self->unk_8c);
    self->unk_3c->v70();
    self->unk_3c->unk_84->unk_04 |= 0x4000000;
    {
        Ov003TlLabel *p = self->unk_3c;
        if (!(p->flags & 0x80000)) {
            p->unk_84->unk_b8 &= ~1;
        }
    }
    self->unk_3c->v08();
    {
        Ov003TlLabel *p = self->unk_3c;
        p->unk_84->Move(p->unk_64 + p->unk_24 - 0x14, p->unk_66 + p->unk_28 - 0xc, -0xfe0);
    }
    self->unk_3c->flags &= ~2;

    {
        Ov003TlSpr *s = (Ov003TlSpr *)func_0203dd9c(0x160);
        if (s != NULL) {
            Ov003TlSpr_Init(s, self->unk_50, self->unk_54);
        }
        self->unk_44 = s;
    }
    res = func_02035f30(self->unk_50, self->unk_54, 2);
    func_020417e0(self->unk_44, func_02034d88(res, self->unk_54));
    self->unk_44->unk_6c |= 2;
    self->unk_44->unk_6c |= 0x80000;
    self->unk_44->unk_150 = -0x1ccd;
    func_02041c5c(self->unk_44, NULL);
    func_02041c18(self->unk_44, 0xa0a);
    self->unk_44->unk_158 = (void *)func_ov003_021cceb4;
    func_02041c20(self->unk_44, self->unk_5c, 0x7fff);
    func_02041d9c(self->unk_44, 0, self->unk_5c);

    {
        Ov003TlSpr *s = (Ov003TlSpr *)func_0203dd9c(0x160);
        if (s != NULL) {
            Ov003TlSpr_Init(s, self->unk_50, self->unk_54);
        }
        self->unk_48 = s;
    }
    res = func_02035f30(self->unk_50, self->unk_54, 2);
    func_020417e0(self->unk_48, func_02034d88(res, self->unk_54));
    self->unk_48->unk_6c |= 2;
    self->unk_48->unk_6c |= 0x80000;
    self->unk_48->unk_150 = -0x2000;
    func_02041c5c(self->unk_48, (void *)func_ov003_021cce20);
    func_02041c18(self->unk_48, 0xa0a);
    self->unk_48->unk_158 = (void *)func_ov000_021c8408;

    {
        Ov003TlSpr *s = (Ov003TlSpr *)func_0203dd9c(0x160);
        if (s != NULL) {
            const char *name = data_ov003_021f78cd;
            const char *file = data_ov003_021f78c4;
            func_02041218(s->unk_88);
            // fake match: the always-true check splits the block so name/file stay in
            // callee-saved registers instead of being rematerialized after the call
            if (name) {
                func_02041440(s, name, 0);
            }
            STD_CopyString(s->unk_2c, file);
        }
        self->unk_4c = s;
    }
    res = func_02035f30(data_ov003_021f78c4, data_ov003_021f78cd, 2);
    func_020417e0(self->unk_4c, func_02034d88(res, data_ov003_021f78cd));
    self->unk_4c->unk_6c |= 2;
    self->unk_4c->unk_6c |= 0x80000;
    self->unk_4c->unk_150 = -0x2000;
    func_02041c5c(self->unk_4c, (void *)func_ov003_021cce20);
    func_02041c18(self->unk_4c, 0xa0a);
    self->unk_4c->unk_158 = (void *)func_ov000_021c8408;
    {
        u16 i;
        u16 mask = self->unk_66;
        u16 n = (u16)(s16)self->unk_69;
        for (i = 0; i < n; i++) {
            if (i != self->unk_5c) {
                if (mask & (1 << i)) {
                    func_02041d9c(self->unk_48, 0, i);
                } else {
                    func_02041d9c(self->unk_4c, 0, i);
                }
            }
        }
    }
    func_ov000_02173648(self);
}

}
