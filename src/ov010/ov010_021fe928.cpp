#include "ov010/ov010.h"

struct Ov010Cmd {
    s32 a;
    s32 b;
    u8 unk_08[0x8];
};

struct Ov010Obj108 {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 4;
    u8 unk_05;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
};

struct Ov010Node {
    u8 unk_00[0x8];
    Ov010Node *next;
    u16 unk_0c;
    u16 unk_0e;
};

extern "C" {

extern const Ov010Vec data_ov010_0220fa94;
extern u8 data_ov010_0220fa2c[];
extern char data_ov010_0220fc25[];
extern u8 data_ov010_0220ebc0[];
extern void *data_ov000_021ccd68;
extern void func_ov003_021d8a7c(void *p, s32 a);
extern void func_ov003_021d97fc(void *p, s32 a);
extern void func_ov003_021d9740(void *p, s32 a);
extern void func_ov010_021fbb40(void *self);
extern void func_ov003_021da48c(void *p, s32 a);
extern void func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);
extern void func_ov003_021d88ec(Ov010Cmd *c);
extern void func_ov003_021d8b60(void *p, Ov010Cmd *c);
extern s32 func_02040528(s32 max);
extern void VEC_Add(Ov010Vec *a, const Ov010Vec *b, Ov010Vec *c);
extern Ov010V *func_02065f88(s32 a, Ov010Vec *b);
extern void *func_ov000_0218e4cc(void *a, s32 b);
extern u8 *func_ov000_0219bf90(void);
extern void func_ov003_021d969c(void *p, s32 a);

static inline void Ov010Cam_Start(u8 *cam) {
    if (FLD(u8, cam, 0x4) == 0) {
        FLD(u8, cam, 0x4) = 1;
        OV010_BLKCPY(cam + 0x4c, &data_ov010_0220fa94);
        FLD(s16, cam, 0x58) = FLD(s16, data_ov010_0220fa2c, 0x74);
        FLD(s16, cam, 0x5a) = FLD(s16, data_ov010_0220fa2c, 0x76);
        FLD(u16, cam, 0x5c) = FLD(u16, data_ov010_0220fa2c, 0x78);
        FLD(s16, cam, 0x5e) = FLD(s16, data_ov010_0220fa2c, 0x7a);
        FLD(s16, cam, 0x60) = FLD(s16, data_ov010_0220fa2c, 0x7c);
        FLD(s16, cam, 0x62) = FLD(s16, data_ov010_0220fa2c, 0x7e);
        FLD(s16, cam, 0x64) = FLD(s16, data_ov010_0220fa2c, 0x80);
        FLD(s16, cam, 0x66) = FLD(s16, data_ov010_0220fa2c, 0x82);
        func_ov003_021da48c(cam + 0x38, 0);
    }
}

void func_ov010_021fe928(void *self) {
    u16 st = FLD(u16, FLD(u8 *, self, 0x40), 0);
    if (st == 0) {
        Ov010Obj108 *o;
        FLD(u8, self, 0x1bc) = 2;
        FLD(u8, self, 0x1bd) = 3;
        func_ov003_021d8a7c((u8 *)self + 0x1c0, 1);
        o = FLD(Ov010Obj108 *, self, 0x108);
        o->b2 = 0;
        o->b3 = 0;
        o->unk_06 = 0;
        o->unk_08 = 0;
        o->unk_0a = 0;
    } else if (st == 100) {
        func_ov003_021d97fc((u8 *)self + 0x1ac, 0);
        func_ov003_021d9740((u8 *)self + 0x1ac, 0xff);
    }
    func_ov010_021fbb40(self);
}

void func_ov010_021fe9b4(void) {
}

void func_ov010_021fe9b8(void *self) {
    FLD(u16, FLD(u8 *, self, 0x50), 0xa) = 5;
}

void func_ov010_021fe9c8(void *self) {
    Ov010Vec v;
    Ov010Vec off;
    Ov010Cmd cmd;
    u16 *st;
    if (FLD(u16, FLD(u8 *, self, 0x40), 0) == 0) {
        Ov010Cam_Start(FLD(u8 *, self, 0x104));
        func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov010_0220fc25, 0x1000, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        FLD(u16, FLD(u8 *, self, 0x50), 0) = 0;
        {
            u8 *q = FLD(u8 *, self, 0x44);
            FLD(Ov010Flags, q, 0x22).b0 = 0;
            FLD(Ov010Flags, q, 0x22).b1 = 0;
        }
        FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
        func_ov003_021d88ec(&cmd);
        cmd.a = 2;
        cmd.b = 1;
        func_ov003_021d8b60((u8 *)self + 0x1c0, &cmd);
        FLD(u16, FLD(u8 *, self, 0x40), 0)++;
    }
    FLD(u16, FLD(u8 *, self, 0x40), 2)++;
    st = FLD(u16 *, self, 0x40);
    if (st[1] % 60 == 0) {
        Ov010V *p;
        u8 *q;
        st[1] = 0;
        v.x = FLD(s32, self, 0x70) + func_02040528(FLD(s32, self, 0x64));
        v.y = FLD(s32, self, 0x74) + func_02040528(FLD(s32, self, 0x64));
        v.z = FLD(s32, self, 0x78) + func_02040528(FLD(s32, self, 0x64));
        q = FLD(u8 *, self, 0x44);
        off.x = FLD(s32, q, 0xc);
        off.y = FLD(s32, q, 0x10);
        off.z = FLD(s32, q, 0x14);
        VEC_Add(&v, &off, &v);
        p = func_02065f88(0x325, &v);
        p->v34(0, 0x4000, 0);
        p->v14(0x2800, 0x2800, 0x2800);
    }
}

void func_ov010_021febfc(void *self) {
    Ov010Cmd cmd;
    u16 *st = FLD(u16 *, self, 0x40);
    if (*(const u16 *)st != 0) {
        return;
    }
    st[0]++;
    switch (FLD(u8, self, 0x1bd)) {
    case 0:
        func_ov003_021d8a7c((u8 *)self + 0x1c0, 3);
        break;
    case 1:
        func_ov003_021d8a7c((u8 *)self + 0x1c0, 2);
        func_ov003_021d88ec(&cmd);
        cmd.a = 4;
        cmd.b = 1;
        func_ov003_021d8b60((u8 *)self + 0x1c0, &cmd);
        break;
    case 2:
        func_ov003_021d8a7c((u8 *)self + 0x1c0, 1);
        break;
    }
}

void func_ov010_021fecb0(void *self) {
    u16 *c = FLD(u16 *, self, 0xf8);
    c[0] = 0;
    c[1] = 0;
    if (FLD(Ov010Flags8, self, 0x138).b0) {
        if (FLD(s32, self, 0x140) == 1) {
            FLD(s32, self, 0x140) = 2;
            FLD(u16, self, 0x13c) = 0;
        }
    }
}

static inline Ov010Node *Ov010List_Next(Ov010Node *head, Ov010Node *n) {
    if (n != NULL) {
        return n->next;
    }
    return head;
}

void func_ov010_021fecec(void *self) {
    void *list = func_ov000_0218e4cc(data_ov000_021ccd68, 0x4829);
    BOOL found = FALSE;
    u8 *pl = func_ov000_0219bf90();
    Ov010Node *head = FLD(Ov010Node *, list, 0xc);
    Ov010Node *n;
    for (n = head; n != NULL; n = Ov010List_Next(head, n)) {
        if (n->unk_0e == 0x4829 && FLD(u16, pl, 0xb1c) != n->unk_0c) {
            found = TRUE;
            break;
        }
    }
    if (found) {
        func_ov003_021d969c((u8 *)self + 0x1ac, 1);
    } else {
        func_ov003_021d969c((u8 *)self + 0x1ac, 0);
    }
}

void func_ov010_021fed88(void *self) {
    u8 k = FLD(u8, self, 0x1bd);
    if (k == 0) {
        FLD(Ov010Flags, FLD(u8 *, self, 0x38), 0xc2).b0 = 1;
    } else if (k == 1) {
        FLD(Ov010Flags, FLD(u8 *, self, 0x38), 0xc2).b0 = 0;
    }
}

void func_ov010_021fedc4(void *self) {
    FLD(Ov010Flags8, self, 0xf0).b1 = 1;
}

void func_ov010_021fedd4(void *self) {
    FLD(Ov010Flags8, self, 0xf0).b0 = 0;
    FLD(Ov010Flags8, self, 0xf0).b1 = 0;
    FLD(Ov010Flags8, self, 0xf0).b2 = 0;
    FLD(Ov010Flags8, self, 0xf0).b3 = 0;
    FLD(u16, self, 0xf2) = 0;
    FLD(s32, self, 0xf4) = 0;
    FLD(s32, self, 0xf8) = 0;
    FLD(s32, self, 0xfc) = 0;
    FLD(s32, self, 0x100) = 0;
    FLD(s32, self, 0x104) = 0;
    FLD(s32, self, 0x108) = 0;
    FLD(s32, self, 0x10c) = 0;
    FLD(s32, self, 0x110) = 0;
    FLD(s32, self, 0x114) = 0;
    FLD(s32, self, 0x118) = 0;
    FLD(s32, self, 0x11c) = -1;
    FLD(Ov010Vec, self, 0x120) = FLD(Ov010Vec, data_ov010_0220ebc0, 0x60);
    FLD(Ov010Vec, self, 0x12c) = FLD(Ov010Vec, self, 0x120);
    FLD(u8, self, 0x1bc) = 0;
    FLD(u8, self, 0x1bd) = 0xff;
}

}
