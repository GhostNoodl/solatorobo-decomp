#include "ov010/ov010.h"

struct Ov010Heap {
    u32 cur;
    u32 unk_04;
    u32 def;
};

struct Ov010Rot {
    u16 x;
    u16 y;
    u16 z;
};

extern "C" {

extern Ov010Heap *data_02097dd0;
extern void *data_0214a420;
extern void *data_ov000_021ccd68;
extern u8 *data_ov000_021ccd54;
extern const Ov010Vec data_ov010_0220fa88;
extern u8 data_ov010_0220ebc0[];
extern void func_ov003_021cf404(s32 a);
extern void func_ov003_021cf400(s32 a);
extern void func_02065804(void *a, s32 b);
extern void func_ov010_02200db8(void *p);
extern void func_ov003_021d8fa8(void *p);
extern void func_ov003_021cf480(void *p);
extern void func_ov010_021fedd4(void *self);
extern void *func_ov000_0218e4cc(void *a, s32 b);
extern void *func_ov000_0218e6d0(void *a, u16 b, s32 c);
extern u8 *func_ov000_0219bf90(void);
extern u16 func_ov003_021d9c38(Ov010Vec *v);
extern s32 func_02013068(const Ov010Vec *a, const Ov010Vec *b);
extern void func_ov000_0218a358(void *a, void *b, Ov010Rot *c, s32 d, s32 e, s32 f, s32 g, s32 h);

static inline void Ov010_FreeV(void *self, u32 off) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, off) != NULL) {
        Ov010V *p = FLD(Ov010V *, self, off);
        if (p != NULL) {
            p->v04();
        }
        FLD(void *, self, off) = NULL;
    }
    data_02097dd0->cur = saved;
}

void func_ov010_021fee70(void *self) {
    u32 saved;
    func_ov003_021cf404(0);
    func_ov003_021cf400(0);
    func_02065804(data_0214a420, FLD(s32, self, 0xf4));
    FLD(s32, self, 0xf4) = 0;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, 0xf8) != NULL) {
        func_0203de1c(FLD(void *, self, 0xf8));
        FLD(void *, self, 0xf8) = NULL;
    }
    data_02097dd0->cur = saved;
    Ov010_FreeV(self, 0x110);
    Ov010_FreeV(self, 0x114);
    Ov010_FreeV(self, 0x118);
    if (FLD(void *, self, 0xfc) != NULL) {
        func_0203de1c(FLD(void *, self, 0xfc));
    }
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, 0x100) != NULL) {
        void *p = FLD(void *, self, 0x100);
        if (p != NULL) {
            func_ov010_02200db8(p);
            func_0203de1c(p);
        }
        FLD(void *, self, 0x100) = NULL;
    }
    data_02097dd0->cur = saved;
    Ov010_FreeV(self, 0x104);
    Ov010_FreeV(self, 0x108);
    Ov010_FreeV(self, 0x10c);
    if (FLD(Ov010Flags8, self, 0x138).b0) {
        func_02065804(data_0214a420, FLD(s32, self, 0x148));
        FLD(Ov010Flags8, self, 0x138).b0 = 0;
    }
    ((Ov010V *)((u8 *)self + 0x150))->v08();
    ((Ov010V *)((u8 *)self + 0x17c))->v08();
    ((Ov010V *)((u8 *)self + 0x19c))->v08();
    func_ov003_021d8fa8((u8 *)self + 0x1ac);
    ((Ov010V *)((u8 *)self + 0x1c0))->v08();
    func_ov003_021cf480((u8 *)self + 0x1d0);
    func_ov010_021fedd4(self);
}

void *func_ov010_021ff0fc(void *self) {
    func_0203de1c(self);
    return self;
}

void *func_ov010_021ff110(void *self) {
    func_0203de1c(self);
    return self;
}

void *func_ov010_021ff124(void *self) {
    func_0203de1c(self);
    return self;
}

void *func_ov010_021ff138(void *self) {
    func_0203de1c(self);
    return self;
}

void *func_ov010_021ff14c(void *self) {
    func_0203de1c(self);
    return self;
}

static inline void Ov010_VecSub(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *o) {
    o->x = a->x - b->x;
    o->y = a->y - b->y;
    o->z = a->z - b->z;
}

static inline void *Ov010_FindObj(u16 id, s32 kind) {
    if (data_ov000_021ccd68 != NULL) {
        return func_ov000_0218e6d0(data_ov000_021ccd68, id, kind);
    }
    return NULL;
}

static inline Ov010Vec Ov010_TargetPos(void) {
    void *o = Ov010_FindObj(FLD(u16, func_ov000_0218e4cc(data_ov000_021ccd68, 0x5000), 8), 0x5c06);
    Ov010Vec p = data_ov010_0220fa88;
    if (o != NULL) {
        p = FLD(Ov010Vec, o, 0x70);
        p.y = 0x7000;
    }
    return p;
}

BOOL func_ov010_021ff160(void *self) {
    FLD(u8, self, 4) = 0;
    FLD(s32, self, 8) = 0;
    FLD(Ov010Vec, self, 0xc) = Ov010_TargetPos();
    return TRUE;
}

}
