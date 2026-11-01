#include "ov000/LoCommon.h"
#include "ov000/Vec.h"
#include "ov000/Actor.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 2;
    u32 rest : 28;
} Bits021b12c0;

typedef struct {
    u16 b0 : 8;
    u16 b8 : 1;
    u16 b9 : 1;
    u16 rest : 6;
} Bits0214a424;

typedef struct {
    u8 unk_00[0x108];
    u8 unk_108;
    u8 unk_109[7];
    u8 unk_110;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
} Anm021b12c0;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 st : 3;
    u16 b9 : 2;
    u16 b11 : 2;
    u16 b13 : 1;
    u16 b14 : 2;
} Bits021b1814;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 2;
    u16 b3 : 13;
} Save021b1814;

extern "C" {
extern u8 data_ov000_021cc5e3[];
extern u8 data_ov000_021cc5e9[];
extern u8 *data_0214a424;
void func_ov000_02190a80(void *a, s32 b);
void NNS_G3dRenderObjRemoveAnmObj(void *obj, void *anm);
void func_02062764(s32 a, s32 b);

struct Obj021b1814 : public VObj {
    u8 unk_04[0x3c];
    ActorSub40 *unk_40;
    u8 unk_44[0x2c];
    VecFx32 unk_70;
    u16 unk_7c;
    u16 unk_7e;
    u16 unk_80;
    u8 unk_82[0xf6];
    s16 unk_178;
    u8 unk_17a[0x20a];
    Anm021b12c0 *unk_384;
    u8 unk_388[0x3d4];
    VecFx32 unk_75c;
    u8 unk_768[0x4];
    u16 unk_76c;
    u16 unk_76e;
    u16 unk_770;
    u8 unk_772[0x3b0];
    Bits021b1814 unk_b22;
    Bits021b12c0 unk_b24;
};

static inline void Reset12c0(Obj021b1814 *self, BOOL flag) {
    Anm021b12c0 *anm;
    self->unk_b24.b1 = 1;
    self->unk_b24.b2 = 0;
    self->vfunc_18();
    self->unk_75c = self->unk_70;
    self->unk_76c = self->unk_7c;
    self->unk_76e = self->unk_7e;
    self->unk_770 = self->unk_80;
    func_ov000_02190cb0((u8 *)self + 0x368, data_ov000_021cc5e3, 0x1000, 1);
    anm = self->unk_384;
    if (anm != NULL) {
        NNS_G3dRenderObjRemoveAnmObj((u8 *)self + 0x38c, *(void **)anm);
        anm->unk_108 = 0;
        anm->unk_110 = 0xff;
        anm->b0 = 0;
        anm->b1 = 0;
    }
    self->unk_178 = -1;
    LFLD(Bits0214a424, data_0214a424, 0x18).b8 = 0;
    LFLD(Bits0214a424, data_0214a424, 0x18).b9 = 0;
    func_02062764(3, 1);
    if (flag) {
        LFLD(u8, data_ov000_021ccd54, 0xac) = 1;
    }
}

void func_ov000_021b1814(Obj021b1814 *self, BOOL flag, BOOL mode) {
    if (self->unk_b22.b3) {
        return;
    }
    if (self->unk_b22.b9) {
        return;
    }
    if (!self->unk_b24.b1) {
        Reset12c0(self, flag);
    }
    if (LFLD(Save021b1814, data_0214a424, 0x18).b1 == 2) {
        LFLD(Save021b1814, data_0214a424, 0x18).b1 = 1;
    }
    if (mode) {
        self->unk_b22.b4 = 1;
        self->unk_b22.b5 = 0;
        self->unk_b22.b13 = 1;
    } else {
        self->unk_b22.b4 = 0;
        if (self->unk_b22.st == 1 || self->unk_b22.st == 3) {
            self->unk_b22.b5 = 1;
        }
        self->unk_b22.b13 = 0;
    }
    if (self->unk_b22.b9 < 2) {
        self->unk_b22.st = 4;
        self->unk_b22.b9 = 1;
        self->unk_40->flags |= 0x80000000;
        func_ov000_02198360(self->unk_40, 0x1f, 0);
    }
    func_02062764(0xc00, 0x800);
    if (flag) {
        LFLD(u8, data_ov000_021ccd54, 0xac) = 1;
    }
}
}

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 st : 3;
    u16 b9 : 2;
    u16 b11 : 2;
    u16 b13 : 1;
    u16 b14 : 2;
} Bits021b1a54;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 2;
    u16 b3 : 13;
} Save021b1a54;

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 2;
    u32 rest : 28;
} Bits021b1b88b;

typedef struct {
    u16 b0 : 8;
    u16 b8 : 1;
    u16 b9 : 1;
    u16 rest : 6;
} Save021b1b88;

typedef struct {
    u8 unk_00[0x108];
    u8 unk_108;
    u8 unk_109[7];
    u8 unk_110;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
} Anm021b1b88;

extern "C" {
extern u8 data_ov000_021cc5e3[];
void NNS_G3dRenderObjRemoveAnmObj(void *obj, void *anm);
extern u8 *data_0214a424;
void func_02062764(s32 a, s32 b);

static inline void SetSt(u8 *self, u16 st) {
    Bits021b1a54 *b = &LFLD(Bits021b1a54, self, 0xb22);
    if (LFLD(Bits021b1a54, self, 0xb22).b9 < 2) {
        b->st = st;
        b->b9 = 1;
        LFLD(ActorSub40 *, self, 0x40)->flags |= 0x80000000;
        func_ov000_02198360(LFLD(void *, self, 0x40), 0x1f, 0);
    }
}

struct Obj021b1a54 {
    u8 unk_00[0xb22];
    Bits021b1a54 unk_b22;
};

void func_ov000_021b1a54(Obj021b1a54 *self, BOOL flag) {
    u32 st;
    if (!self->unk_b22.b3) {
        return;
    }
    if (self->unk_b22.b9) {
        return;
    }
    st = 0;
    if (LFLD(Save021b1a54, data_0214a424, 0x18).b1 == 1) {
        if (self->unk_b22.b5) {
            st = 3;
        } else {
            st = 2;
        }
    } else if (self->unk_b22.b5) {
        st = 1;
    }
    if (self->unk_b22.b4) {
        self->unk_b22.b13 = 1;
    }
    self->unk_b22.b4 = 0;
    self->unk_b22.b5 = 0;
    SetSt((u8 *)self, st);
    func_02062764(0xc00, 0x400);
    if (flag) {
        LFLD(u8, data_ov000_021ccd54, 0xac) = 1;
    }
}

void func_ov000_021b1b88(VObj *self, s32 mode) {
    u32 st;
    switch (mode) {
    default:
        st = 0;
        break;
    case 1:
        st = 2;
        break;
    case 2:
        if (!LFLD(Bits021b1b88b, self, 0xb24).b1) {
            Anm021b1b88 *anm;
            LFLD(Bits021b1b88b, self, 0xb24).b1 = 1;
            LFLD(Bits021b1b88b, self, 0xb24).b2 = 0;
            self->vfunc_18();
            LFLD(VecFx32, self, 0x75c) = LFLD(VecFx32, self, 0x70);
            LFLD(u16, self, 0x76c) = LFLD(u16, self, 0x7c);
            LFLD(u16, self, 0x76e) = LFLD(u16, self, 0x7e);
            LFLD(u16, self, 0x770) = LFLD(u16, self, 0x80);
            func_ov000_02190cb0((u8 *)self + 0x368, data_ov000_021cc5e3, 0x1000, 1);
            anm = LFLD(Anm021b1b88 *, self, 0x384);
            if (anm != NULL) {
                NNS_G3dRenderObjRemoveAnmObj((u8 *)self + 0x38c, *(void **)anm);
                anm->unk_108 = 0;
                anm->unk_110 = 0xff;
                anm->b0 = 0;
                anm->b1 = 0;
            }
            LFLD(s16, self, 0x178) = -1;
            LFLD(Save021b1b88, data_0214a424, 0x18).b8 = 0;
            LFLD(Save021b1b88, data_0214a424, 0x18).b9 = 0;
            func_02062764(3, 1);
        }
        st = 5;
        break;
    }
    LFLD(Bits021b1a54, self, 0xb22).b13 = 1;
    SetSt((u8 *)self, st);
}

struct Obj021b1d28 {
    u8 unk_00[0xb22];
    Bits021b1a54 unk_b22;
};

void func_ov000_021b1d28(Obj021b1d28 *self) {
    u32 st = self->unk_b22.st;
    switch (st) {
    case 4:
    case 5:
        return;
    }
    if (st != 2 && st != 3) {
        st = 2;
    }
    self->unk_b22.b13 = 0;
    SetSt((u8 *)self, st);
}
}
