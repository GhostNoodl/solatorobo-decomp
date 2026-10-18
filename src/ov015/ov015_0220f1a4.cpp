#include "ov015/ov015.h"

extern "C" {

Ov015V *func_ov015_021fa6d0(void);
void func_ov015_021fa6f8(Ov015Fade *self, u8 a, u8 b, s32 c, u16 d);
extern u8 *data_02097dc8;
extern void *data_02097e4c;
void func_02049a48(void *a, int b, int c, int d, int e);
extern u8 data_ov015_022128ec[];
extern u8 data_ov015_02213188[];
void func_02016e28(void *dst, u32 value, u32 size);
extern u8 *data_ov002_021f0f9c;
void func_ov002_021e7c1c(void *p);
void func_ov015_0220ec40(void *self);

static inline BOOL Ov015_IsKind5f1a4(u8 *o) {
    return FLD(s32, o, 0x4) == 5 ? TRUE : FALSE;
}
BOOL func_ov015_0220f1a4(u8 *self) {
    BOOL r = TRUE;
    switch (FLD(s32, self, 0x18)) {
    case 0:
        func_ov015_021fa6f8((Ov015Fade *)func_ov015_021fa6d0(), 0, 0x14, 0x3c000, 0x2639);
        FLD(s32, self, 0x18)++;
    case 1: {
        Ov015Fade *f = (Ov015Fade *)func_ov015_021fa6d0();
        if (f->unk_14 >= f->unk_0c) {
            FLD(s32, self, 0x1c) = 0;
            FLD(s32, self, 0x18)++;
        }
        break;
    }
    case 2:
        if (FLD(s32, self, 0x1c) <= 0x3c000) {
            FLD(s32, self, 0x1c) += 0x1000;
        } else {
            FLD(s32, self, 0x1c) = 0;
            FLD(s32, self, 0x18) = 10;
            FLD(u32, FLD(u8 *, self, 0x14), 0xc) &= ~2;
        }
        break;
    case 10: {
        u32 t;
        if (FLD(s32, self, 0x1c) >= FLD(s32, FLD(u8 *, self, 0x14), 0x34) && (t = FLD(u16, data_02097dc8, 0x12) & 1) != 0) {
            if (t) {
                func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            }
            FLD(u32, FLD(u8 *, self, 0x4), 0xc) |= 2;
            FLD(u32, FLD(u8 *, self, 0x8), 0xc) |= 2;
            FLD(u32, FLD(u8 *, self, 0xc), 0xc) |= 2;
            FLD(u32, FLD(u8 *, self, 0x10), 0xc) |= 2;
            FLD(u32, FLD(u8 *, self, 0x14), 0xc) |= 2;
            FLD(s32, self, 0x18) = 0x14;
            FLD(s32, self, 0x1c) = 0;
        } else {
            FLD(s32, self, 0x1c) += 0x1000;
        }
        break;
    }
    case 0x14:
        if (Ov015_IsKind5f1a4(FLD(u8 *, self, 0x4)) && Ov015_IsKind5f1a4(FLD(u8 *, self, 0x8)) && Ov015_IsKind5f1a4(FLD(u8 *, self, 0x14))) {
            FLD(s32, self, 0x18) = 0x1e;
        }
        break;
    case 0x1e:
        if (FLD(s32, self, 0x1c) <= 0xa000) {
            FLD(s32, self, 0x1c) += 0x1000;
        } else {
            FLD(s32, self, 0x1c) = 0;
            FLD(s32, self, 0x18) = -1;
        }
        break;
    default:
        FLD(s32, self, 0x18) = -1;
        r = FALSE;
        break;
    }
    if (FLD(s32, self, 0x18) >= 10) {
        FLD(Ov015V *, self, 0x4)->v1c();
        FLD(Ov015V *, self, 0x8)->v1c();
        FLD(Ov015V *, self, 0xc)->v1c();
        FLD(Ov015V *, self, 0x10)->v1c();
        FLD(Ov015V *, self, 0x14)->v1c();
    }
    return r;
}

u8 *func_ov015_0220f448(u8 *self) {
    SET_VT(self, data_ov015_022128ec);
    FLD(s32, self, 0x4) = 0;
    FLD(u8, self, 0x8) = 1;
    FLD(s32, self, 0xc) = 0;
    FLD(s32, self, 0x10) = 0;
    return self;
}

void func_ov015_0220f470(u8 *self) {
    u8 *p = (u8 *)func_0203dd9c(0x64);
    if (p != NULL) {
        SET_VT(p, data_ov015_02213188);
        FLD(s32, p, 0x4) = 0;
        FLD(s32, p, 0x8) = 0;
        FLD(s32, p, 0xc) = 0;
        FLD(s32, p, 0x10) = 0;
        FLD(s32, p, 0x14) = 0;
        FLD(s32, p, 0x18) = 0;
        FLD(s32, p, 0x1c) = 0;
        func_02016e28(p + 0x20, 0, 0x40);
        FLD(s32, p, 0x60) = -1;
    }
    FLD(u8 *, self, 0x10) = p;
}

void func_ov015_0220f4d4(u8 *self) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x10));
    HEAP_POP(saved);
    if (data_ov002_021f0f9c != NULL) {
        func_ov002_021e7c1c(data_ov002_021f0f9c);
    }
}

void *func_ov015_0220f540(void *self) {
    SET_VT(self, data_ov015_02213188);
    func_ov015_0220ec40(self);
    func_0203de1c(self);
    return self;
}

extern Ov015Globals data_ov015_02213320;
void func_ov002_021e7b58(void);
void func_ov002_021e9b28(s32 a);
s32 func_ov002_021e7ea8(void *p);
void func_ov015_021fa75c(Ov015Fade *self);
void func_ov015_0220f878(u8 *self);
void func_ov015_0220fb78(u8 *self);
void func_ov015_0220e634(void *a, s32 b);
BOOL func_ov015_0220ed70(void *p);
static inline void Ov015_SetCam14(s32 v) {
    u8 *g = data_ov002_021f0f9c;
    FLD(s32, g, 0x14) = v;
    FLD(u16, g, 0x18) = 0;
}
BOOL func_ov015_0220f568(u8 *self) {
    BOOL r = TRUE;
    switch (FLD(s32, self, 0x4)) {
    case 0:
        func_ov002_021e7b58();
        FLD(u8, data_ov002_021f0f9c, 0x1a) = 0;
        FLD(s32, data_ov002_021f0f9c, 0x130) = 1;
        FLD(s32, data_ov002_021f0f9c, 0x134) = 2;
        FLD(s8, self, 0x8) = FLD(s32, data_ov015_02213320.unk_00, 0x8);
        switch (FLD(s8, self, 0x8)) {
        case 1:
            func_ov015_0220f878(self);
            Ov015_SetCam14(0x51000);
            FLD(s32, self, 0xc) = 0x50000;
            break;
        case 0:
            func_ov015_0220fb78(self);
            Ov015_SetCam14(0x14a000);
            FLD(s32, self, 0xc) = 0x79000;
            break;
        default:
            func_ov002_021e9b28(0);
            FLD(s32, self, 0xc) = 0;
            break;
        }
        FLD(s32, self, 0x4) = 10;
    case 10:
        if (data_ov002_021f0f9c != NULL) func_ov002_021e7ea8(data_ov002_021f0f9c);
        {
            s32 v = FLD(s32, self, 0xc);
            u8 *g = data_ov002_021f0f9c;
            if (v <= FLD(s32, g, 0xd4) || v > FLD(s32, g, 0xd0)) {
                break;
            }
        }
        func_ov015_0220e634(FLD(void *, self, 0x10), FLD(s8, self, 0x8));
        FLD(s32, data_ov002_021f0f9c, 0x128) = 0;
        FLD(s32, self, 0x4) = 0x14;
    case 0x14: {
        BOOL ok = TRUE;
        switch (FLD(s32, FLD(u8 *, self, 0x10), 0x60)) {
        case 1:
            ok = func_ov015_0220ed70(FLD(void *, self, 0x10));
            break;
        case 0:
            ok = func_ov015_0220f1a4(FLD(u8 *, self, 0x10));
            break;
        case 2:
            ok = FALSE;
            break;
        }
        if (!ok) {
            u32 saved;
            HEAP_PUSH(saved);
            DELETE_V(FLD(void *, self, 0x10));
            HEAP_POP(saved);
            Ov015_SetCam14(-1);
            func_ov002_021e9b28(FLD(s32, data_ov002_021f0f9c, 0xd0));
            FLD(s32, self, 0x4) = 0x1e;
        }
        if (data_ov002_021f0f9c != NULL) func_ov002_021e7ea8(data_ov002_021f0f9c);
        break;
    }
    case 0x1e: {
        s32 busy;
        if (data_ov002_021f0f9c == NULL) {
            busy = 0;
        } else {
            busy = func_ov002_021e7ea8(data_ov002_021f0f9c);
        }
        if (busy == 0) {
            func_ov002_021e7c1c((void *)busy);
            func_ov015_021fa75c((Ov015Fade *)func_ov015_021fa6d0());
            r = FALSE;
        }
        break;
    }
    default:
        FLD(s32, self, 0x4) = 0x1e;
        break;
    }
    return r;
}

}
