#include "ov000/LoCommon.h"

extern "C" {

typedef struct {
    s32 timer;
    s32 unk_04;
    VObj *obj;
} LoTimedObj;

typedef struct {
    u8 pad[0x360];
    LoTimedObj objs[10];
} LoTimedHost;

extern void *data_ov000_021ccd54;
extern u8 *data_02097d48;
void *func_ov000_0219bf90(void *self);
void VEC_Add(void *a, void *b, void *c);
BOOL func_0203dc9c(void *a, s32 b);
void func_ov000_0216c018(void *self);
void func_ov000_0216c310(void *self);
void func_ov000_0216c6fc(void *self);
s32 func_02043d84(void *a);
void MI_CpuFill8(void *dst, s32 v, s32 size);
void func_ov000_0216bcbc(void *self);

void func_ov000_0216adc0(void *self, s32 a, s32 b) {
    if (LFLD(s32, self, 8) == a) {
        LFLD(u32, self, 0) |= 6;
    } else {
        LFLD(u32, self, 0) &= ~2;
    }
    if (b < 0) {
        b = 0;
    } else if (b > 0x63) {
        b = 0x63;
    }
    LFLD(s32, self, 8) = a;
    LFLD(s32, self, 0x10) = b;
}

}

extern "C" {
extern u8 *data_ov000_021ccd30;
extern u8 data_02097d78[];
extern char *data_0208cc94;
extern char *data_0208cc88;
extern s16 FX_SinCosTable_[];
void *func_02035d5c(const char *name);
void *func_02034d88(void *a, const char *name);
void func_02041218(void *p);
void func_02041440(void *m, const char *name, s32 c);
void func_020417e0(void *m, void *res);
void func_02041d9c(void *m, s32 a, s32 b);
BOOL func_02054f10(void *m, s32 id);
s32 FX_Div(s32 a, s32 b);

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 rest : 29;
} Flags0216adf8;

typedef struct {
    u32 b0 : 2;
    u32 alpha : 5;
    u32 rest : 25;
} MdlFlags0216adf8;

static inline void *GetObj0216adf8(void) {
    void *o = LFLD(void *, data_ov000_021ccd30, 0x11c);
    return o != NULL ? LFLD(void *, o, 0x58) : NULL;
}

static inline BOOL Busy0216adf8(u8 *p) {
    return LFLD(s32, p, 0x90) != LFLD(s32, p, 0x94) ? TRUE : FALSE;
}

static inline BOOL Ready0216adf8(u8 *p) {
    if (p != NULL) {
        if (Busy0216adf8(p)) {
            return FALSE;
        }
        if (LFLD(s32, p, 0) != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline BOOL Idle0216adf8(void) {
    return LFLD(s32, data_02097d78, 0xc) == 0 && LFLD(s32, data_02097d78, 0) == 0 ? TRUE : FALSE;
}

static inline BOOL SubFlag0216adf8(void *o) {
    return LFLD(Flags0216adf8, o, 0xc).b1 ? TRUE : FALSE;
}

void func_ov000_0216adf8(u8 *self) {
    void *o = GetObj0216adf8();
    if (o == NULL) {
        return;
    }
    if (!Ready0216adf8((u8 *)data_ov000_021ccd54) || !Idle0216adf8()) {
        LFLD(Flags0216adf8, self, 0).b1 = 0;
    }
    switch (LFLD(s32, self, 4)) {
    case 0:
    case 1:
        break;
    case 2:
        LFLD(s32, self, 4) = 4;
        break;
    case 3:
        LO_FREE_M(self, 0xc);
        LFLD(s32, self, 4) = 4;
        break;
    case 4:
        if (SubFlag0216adf8(o)) {
            return;
        }
        if (LFLD(Flags0216adf8, self, 0).b1) {
            LFLD(Flags0216adf8, self, 0).b0 = TRUE;
            LFLD(s32, self, 4) = 5;
        }
        break;
    case 5: {
        void *res;
        void *m;
        LFLD(u16, self, 0x14) = 0xc;
        res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
        m = func_0203dd9c(0x160);
        if (m != NULL) {
            const char *nm = data_0208cc88;
            func_02041218((u8 *)m + 0x88);
            func_02041440(m, nm, 0);
        }
        LFLD(void *, self, 0xc) = m;
        func_020417e0(m, res);
        LFLD(u32, LFLD(void *, self, 0xc), 0x6c) |= 2;
        func_02041d9c(LFLD(void *, self, 0xc), 0, 0xb);
        func_02041d9c(LFLD(void *, self, 0xc), 0, LFLD(u16, self, 0x14));
        func_02041d9c(LFLD(void *, self, 0xc), 0, 7);
        func_02041d9c(LFLD(void *, self, 0xc), 0, 6);
        LFLD(u32, LFLD(void *, self, 0xc), 0x6c) |= 0x80000;
        LFLD(u32, LFLD(void *, self, 0xc), 0x6c) |= 0x200000;
        LFLD(MdlFlags0216adf8, LFLD(void *, self, 0xc), 0x6c).alpha = 0x1e;
        LFLD(s32, self, 4) = 6;
        break;
    }
    case 6:
        if (func_02054f10(LFLD(void *, self, 0xc), 0xffff)) {
            LFLD(s32, self, 0x18) = 0;
            LFLD(s32, self, 0x1c) = 0x1000;
            LFLD(s32, self, 4) = 8;
        }
        break;
    case 7:
        if (SubFlag0216adf8(o) || !LFLD(Flags0216adf8, self, 0).b2) {
            LFLD(Flags0216adf8, self, 0).b1 = 0;
        }
        LFLD(Flags0216adf8, self, 0).b2 = 0;
    case 8:
        if (!LFLD(Flags0216adf8, self, 0).b1) {
            LFLD(Flags0216adf8, self, 0).b0 = 0;
            LFLD(s32, self, 4) = 8;
        }
        if (LFLD(s32, self, 4) == 7) {
            return;
        }
        if (LFLD(Flags0216adf8, self, 0).b0) {
            LFLD(s32, self, 0x18)++;
            LFLD(s32, self, 0x1c) = FX_Div(LFLD(s32, self, 0x18) << 12, 0xc000);
            if (LFLD(s32, self, 0x1c) >= 0x1000) {
                LFLD(s32, self, 0x1c) = 0x1000;
                LFLD(s32, self, 4) = 7;
            }
        } else {
            LFLD(s32, self, 0x18)--;
            LFLD(s32, self, 0x1c) = FX_Div(LFLD(s32, self, 0x18) << 12, 0xc000);
            if (LFLD(s32, self, 0x1c) <= 0) {
                LFLD(s32, self, 0x1c) = 0;
                LFLD(s32, self, 4) = 3;
            }
        }
        LFLD(s32, self, 0x1c) = 0x1000 - FX_SinCosTable_[((LFLD(s32, self, 0x1c) << 14) >> 16) * 2];
        break;
    }
}

}
