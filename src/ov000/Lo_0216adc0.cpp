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
void *func_ov000_0219bf90(void);
void VEC_Add(void *a, void *b, void *c);
BOOL PauseNode_IsDrawPaused(void *a, s32 b);
void func_ov000_0216c018(void *self);
void func_ov000_0216c310(void *self);
void func_ov000_0216c6fc(void *self);
s32 func_02043d84(void *a);
void MI_CpuFill8(void *dst, s32 v, s32 size);
void func_ov000_0216bcbc(void *self);

struct Obj0216adc0 {
    u32 unk_00;
    u8 unk_04[0x4];
    s32 unk_08;
    u8 unk_0c[0x4];
    s32 unk_10;
};

void func_ov000_0216adc0(Obj0216adc0 *self, s32 a, s32 b) {
    if (self->unk_08 == a) {
        self->unk_00 |= 6;
    } else {
        self->unk_00 &= ~2;
    }
    if (b < 0) {
        b = 0;
    } else if (b > 0x63) {
        b = 0x63;
    }
    self->unk_08 = a;
    self->unk_10 = b;
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

struct Obj0216adf8 {
    Flags0216adf8 unk_00;
    s32 unk_04;
    u8 unk_08[0x4];
    void *unk_0c;
    u8 unk_10[0x4];
    u16 unk_14;
    u8 unk_16[0x2];
    s32 unk_18;
    s32 unk_1c;
};

void func_ov000_0216adf8(Obj0216adf8 *self) {
    void *o = GetObj0216adf8();
    if (o == NULL) {
        return;
    }
    if (!Ready0216adf8((u8 *)data_ov000_021ccd54) || !Idle0216adf8()) {
        self->unk_00.b1 = 0;
    }
    switch (self->unk_04) {
    case 0:
    case 1:
        break;
    case 2:
        self->unk_04 = 4;
        break;
    case 3:
        LO_FREE_M(self, 0xc);
        self->unk_04 = 4;
        break;
    case 4:
        if (SubFlag0216adf8(o)) {
            return;
        }
        if (self->unk_00.b1) {
            self->unk_00.b0 = TRUE;
            self->unk_04 = 5;
        }
        break;
    case 5: {
        void *res;
        void *m;
        self->unk_14 = 0xc;
        res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
        m = Heap_Alloc(0x160);
        if (m != NULL) {
            const char *nm = data_0208cc88;
            func_02041218((struct PlttRes *)((u8 *)m + 0x88));
            func_02041440(m, nm, 0);
        }
        self->unk_0c = m;
        func_020417e0(m, res);
        LFLD(u32, self->unk_0c, 0x6c) |= 2;
        func_02041d9c(self->unk_0c, 0, 0xb);
        func_02041d9c(self->unk_0c, 0, self->unk_14);
        func_02041d9c(self->unk_0c, 0, 7);
        func_02041d9c(self->unk_0c, 0, 6);
        LFLD(u32, self->unk_0c, 0x6c) |= 0x80000;
        LFLD(u32, self->unk_0c, 0x6c) |= 0x200000;
        LFLD(MdlFlags0216adf8, self->unk_0c, 0x6c).alpha = 0x1e;
        self->unk_04 = 6;
        break;
    }
    case 6:
        if (func_02054f10(self->unk_0c, 0xffff)) {
            self->unk_18 = 0;
            self->unk_1c = 0x1000;
            self->unk_04 = 8;
        }
        break;
    case 7:
        if (SubFlag0216adf8(o) || !self->unk_00.b2) {
            self->unk_00.b1 = 0;
        }
        self->unk_00.b2 = 0;
    case 8:
        if (!self->unk_00.b1) {
            self->unk_00.b0 = 0;
            self->unk_04 = 8;
        }
        if (self->unk_04 == 7) {
            return;
        }
        if (self->unk_00.b0) {
            self->unk_18++;
            self->unk_1c = FX_Div(self->unk_18 << 12, 0xc000);
            if (self->unk_1c >= 0x1000) {
                self->unk_1c = 0x1000;
                self->unk_04 = 7;
            }
        } else {
            self->unk_18--;
            self->unk_1c = FX_Div(self->unk_18 << 12, 0xc000);
            if (self->unk_1c <= 0) {
                self->unk_1c = 0;
                self->unk_04 = 3;
            }
        }
        self->unk_1c = 0x1000 - FX_SinCosTable_[((self->unk_1c << 14) >> 16) * 2];
        break;
    }
}

}
