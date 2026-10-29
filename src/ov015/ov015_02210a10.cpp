#include "ov015/ov015.h"

extern "C" {

extern void *data_02097e4c;
void *func_02049a48(void *a, int b, int c, int d, int e);
s32 FX_Div(s32 a, s32 b);
s32 func_02049210(s32 t, s32 a, s32 b);
extern void *data_0208cca0;
extern void *data_0208cb74;
void func_02035acc(void *a, void *b, int c);
void func_020359fc(void *a, void *b, int c, int d);
int func_02035bd4(void *a, void *b, int c);
void *func_ov015_0220fcec(u8 *self);
extern u8 data_ov015_02213198[];
extern u8 data_ov015_02213188[];
void func_ov015_0220ec40(void *self);
extern u8 data_ov015_022131ac[];
void func_ov000_021c2310(void *self);
extern Ov015Shared *data_ov015_02213368;
extern u8 data_ov015_02213200[];
void MIi_CpuClearFast(u32 val, void *dst, u32 size);

void func_ov015_02210a10(u8 *self) {
    FLD(u32, FLD(u8 *, self, 0x28), 0xc) |= 2;
    FLD(u32, FLD(u8 *, self, 0x2c), 0xc) |= 2;
    func_02049a48(data_02097e4c, 0x28, -1, -1, -1);
}

static inline BOOL Ov015_IsState5(u8 *o) {
    return FLD(s32, o, 0x4) == 5 ? TRUE : FALSE;
}
BOOL func_ov015_02210a58(u8 *self) {
    BOOL r = FALSE;
    switch (FLD(s32, self, 0x13c)) {
    case 0: {
        s32 t = FX_Div(FLD(s32, self, 0x140) << 12, 0x28000);
        FLD(s32, self, 0x1c) = 0x50000;
        FLD(s32, self, 0x20) = func_02049210(t, -0x46000, -0x66000);
        FLD(s32, self, 0x24) = -0x333;
        if (++FLD(s32, self, 0x140) > 0x28) {
            FLD(s32, self, 0x140) = 0x28;
            FLD(s32, self, 0x13c)++;
        }
        break;
    }
    case 1:
        if (Ov015_IsState5(FLD(u8 *, self, 0x28)) && Ov015_IsState5(FLD(u8 *, self, 0x2c))) {
            r = TRUE;
        }
        break;
    }
    VCALL(FLD(void *, self, 0x28))->v1c();
    VCALL(FLD(void *, self, 0x2c))->v1c();
    return r;
}

void func_ov015_02210b3c(u8 *self) {
    FLD(s32, self, 0x4) = 0;
    FLD(u8, self, 0x8) = 0;
    FLD(u8, self, 0x9) = 0;
    FLD(s32, self, 0xc) = 0;
    FLD(s32, self, 0x10) = 0;
}

void func_ov015_02210b58(u8 *self) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x4));
    HEAP_POP(saved);
    if (FLD(u8, self, 0x9) != 0) {
        func_02035acc(data_0208cca0, data_0208cb74, 2);
    }
}

int func_ov015_02210bd8(u8 *self) {
    if (FLD(u8, self, 0x9) == 0) {
        func_020359fc(data_0208cca0, data_0208cb74, 2, 0);
    }
    return func_02035bd4(data_0208cca0, data_0208cb74, 2);
}

BOOL func_ov015_02210c28(void) {
    return TRUE;
}

s32 func_ov015_02210c30(u8 *self, s32 a, s32 b) {
    s32 r = 0;
    switch (FLD(s32, self, 0xc)) {
    case 0:
        FLD(void *, self, 0x4) = (void *)VCALL(self)->v08(a, b);
        if (FLD(void *, self, 0x4) == NULL) {
            break;
        }
        FLD(s32, self, 0xc) = 1;
    case 1:
        if (VCALL(FLD(void *, self, 0x4))->v08() == 0) {
            u32 saved;
            HEAP_PUSH(saved);
            DELETE_V(FLD(void *, self, 0x4));
            HEAP_POP(saved);
            FLD(s32, self, 0xc) = 0;
        } else {
            r = VCALL(FLD(void *, self, 0x4))->v10();
        }
        break;
    }
    return r;
}

u8 func_ov015_02210cfc(u8 *self) {
    return FLD(u8, self, 0x4);
}

void func_ov015_02210d04(u8 *self) {
    void *o = FLD(void *, self, 0x4);
    if (o != NULL) {
        VCALL(o)->v0c();
    }
}

struct Ov015Bits10d24 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 rest : 3;
};
static inline u8 *Ov015_NewMsg(void) {
    u8 *o = (u8 *)func_0203dd9c(0x144);
    if (o != NULL) o = (u8 *)func_ov015_0220fcec(o);
    return o;
}
u8 *func_ov015_02210d24(u8 *self, u8 *b, s32 msg) {
    u8 *r = NULL;
    switch (msg) {
    case 0x28:
        if (!FLD(Ov015Bits10d24, self, 0x8).b0) {
            r = Ov015_NewMsg();
            FLD(u16, r, 0xc) = 0;
            FLD(s32, r, 0x8) = 0x5a;
            FLD(u8, r, 0x4) = 1;
            FLD(Ov015Bits10d24, self, 0x8).b0 = 1;
        }
        break;
    case 0x32:
        if (!FLD(Ov015Bits10d24, self, 0x8).b4 && FLD(s32, b, 0x8) == 3) {
            r = Ov015_NewMsg();
            FLD(u16, r, 0xc) = 4;
            FLD(s32, r, 0x8) = 0x3c;
            FLD(u8, r, 0x4) = 0;
            FLD(s32, self, 0x10) = 0;
            FLD(u8, self, 0x8) |= 0x10;
            break;
        }
        if (!FLD(Ov015Bits10d24, self, 0x8).b1) {
            if ((u32)(FLD(s32, b, 0x10) - 2) <= 1) {
                r = Ov015_NewMsg();
                FLD(u16, r, 0xc) = 1;
                FLD(s32, r, 0x8) = 0x28;
                FLD(u8, r, 0x4) = 0;
                FLD(u8, self, 0x8) |= 0x2;
                break;
            }
        } else if (!FLD(Ov015Bits10d24, self, 0x8).b2) {
            s32 t4;
            s32 t3;
            BOOL x;
            t3 = FLD(s32, b, 0x14);
            t4 = FLD(s32, b, 0x10);
            if ((t3 == 2 && t4 == 3) || (t3 == 3 && t4 == 2)) {
                x = TRUE;
            } else {
                x = FALSE;
            }
            if (x) {
                FLD(s32, self, 0x10) -= 0x1000;
            } else {
                FLD(s32, self, 0x10) += 0x1000;
            }
            if (FLD(s32, self, 0x10) < 0) FLD(s32, self, 0x10) = 0;
            if (FLD(s32, self, 0x10) > 0x12c000) {
                r = Ov015_NewMsg();
                FLD(u16, r, 0xc) = 2;
                FLD(s32, r, 0x8) = 0x28;
                FLD(u8, r, 0x4) = 0;
                FLD(u8, self, 0x8) |= 0x4;
                break;
            }
        }
        if (!FLD(Ov015Bits10d24, self, 0x8).b3 && FLD(s32, b, 0x24) > 0x1e000) {
            r = Ov015_NewMsg();
            FLD(u16, r, 0xc) = 3;
            FLD(s32, r, 0x8) = 0;
            FLD(u8, r, 0x4) = 0;
            FLD(u8, self, 0x8) |= 0x8;
        }
        break;
    }
    return r;
}

void *func_ov015_02210f2c(u8 *self) {
    u32 saved;
    SET_VT(self, data_ov015_02213198);
    HEAP_PUSH(saved);
    DELETE_V(FLD(void *, self, 0x4));
    HEAP_POP(saved);
    if (FLD(u8, self, 0x9) != 0) {
        func_02035acc(data_0208cca0, data_0208cb74, 2);
    }
    return self;
}

void *func_ov015_02210fbc(void *self) {
    SET_VT(self, data_ov015_02213188);
    func_ov015_0220ec40(self);
    return self;
}

void *func_ov015_02210fdc(void *self) {
    SET_VT(self, data_ov015_022131ac);
    func_ov000_021c2310(self);
    func_0203de1c(self);
    return self;
}

void func_ov015_02211004(void) {
}

void func_ov015_02211008(void) {
}

void *func_ov015_0221100c(void *self) {
    SET_VT(self, data_ov015_022131ac);
    func_ov000_021c2310(self);

    return self;
}

void func_ov015_0221102c(void) {
    u8 *p;
    if (data_ov015_02213368 != NULL) {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_V(data_ov015_02213368);
        HEAP_POP(saved);
    }
    p = (u8 *)func_0203dd9c(0x30);
    if (p != NULL) {
        SET_VT(p, data_ov015_02213200);
        FLD(s32, p, 0x4) = 0;
        FLD(u16, p, 0x8) = 0xa000;
        FLD(u16, p, 0xa) = 0xd000;
        FLD(u16, p, 0xc) = 0xffff;
        MIi_CpuClearFast(0, p + 0x10, 0x18);
        FLD(s32, p, 0x28) = 0;
        FLD(s32, p, 0x2c) = 0;
    }
    data_ov015_02213368 = (Ov015Shared *)p;
}

void func_ov015_022110f0(void) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_V(data_ov015_02213368);
    HEAP_POP(saved);
}

void *func_ov015_0221114c(void *self) {
    func_0203de1c(self);
    return self;
}

extern u8 *func_0206f040(u16 id);
extern s32 func_02040498(s32 max);

u32 func_ov015_02211160(u8 *self, u16 *out, u32 n) {
    u32 cnt = 0;
    MIi_CpuClearFast(0xffff, out, n * 2);
    switch (FLD(u32, self, 0x4)) {
    case 3:
        cnt++;
        out[0] = 0x800b;
        break;
    case 4:
        cnt++;
        FLD(u16, self, 0x8) = 0xa005;
        out[0] = 0x8008;
        break;
    case 5:
        cnt++;
        FLD(u16, self, 0x8) = 0xa005;
        out[0] = 0x8003;
        break;
    case 1:
    case 2: {
        u32 i;
        for (i = cnt; i < n; i++) {
            out[i] = 0x800a;
            cnt++;
        }
        break;
    }
    default: {
        u32 j;
        for (j = 0; j < n; j++) {
            u32 k;
            s32 rnd;
            s32 acc;
            u32 m;
            u8 *e;
            e = func_0206f040(FLD(u16, self, 0xa));
            m = e[1];
            rnd = func_02040498(0x1000);
            acc = 0;
            for (k = 0; k < m; k++) {
                u16 w = FLD(u16, e + k * 2, 0xa);
                float f;
                if (w > 0) {
                    f = (float)(w << 12) + 0.5f;
                } else {
                    f = (float)(w << 12) - 0.5f;
                }
                acc += (s32)f / 100;
                if (rnd <= acc) {
                    break;
                }
            }
            if (k >= m) {
                k = m - 1;
            }
            out[j] = FLD(u16, e + k * 2, 0x2);
            cnt++;
        }
        break;
    }
    }
    return cnt;
}

}
