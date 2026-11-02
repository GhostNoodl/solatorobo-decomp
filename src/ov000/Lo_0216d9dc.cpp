#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"

extern "C" {

void func_020627fc(s32 a);
void func_ov000_02182590(void *p);
void func_ov000_02188140(void *p, s32 a, s32 b, s32 c);

void func_ov000_0216d9dc(void *self, s32 unused, u16 *msg) {
    u16 type = msg[0];
    void *p = LFLD(void *, msg, 8);
    u16 ang;
    if (type != 0x1e) {
        return;
    }
    ang = LFLD(u16, p, 0x44);
    MTX_Identity43_((MtxFx43 *)self);
    MTX_RotY43_((MtxFx43 *)self, FX_SinCosTable_[(ang >> 4) * 2], FX_SinCosTable_[(ang >> 4) * 2 + 1]);
}

struct Obj0216da2c {
    u8 unk_00[0x8];
    s32 unk_08;
    u8 unk_0c[0x10];
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
};

void func_ov000_0216da2c(Obj0216da2c *self, s32 a, s32 b, s32 c) {
    self->unk_08 = a;
    self->unk_24 = b;
    self->unk_28 = c;
    switch (a) {
    case 1:
        self->unk_20 = 0;
        self->unk_1c = 0;
        if (b == 0) {
            self->unk_24 = 0x7fffffff;
        }
        break;
    case 2:
        self->unk_20 = b;
        self->unk_1c = b;
        break;
    }
    LBIT(self, 0).b7 = 0;
}

struct Obj0216da78 {
    u8 unk_00[0x1c];
    s32 unk_1c;
    s32 unk_20;
};

void func_ov000_0216da78(Obj0216da78 *self) {
    s32 v = self->unk_1c;
    LBIT(self, 0).b9 = 1;
    LBIT(self, 0).b16 = 0;
    LBIT(self, 0).b5 = 1;
    LBIT(self, 0).b8 = 1;
    self->unk_20 = v;
    if (LBIT(self, 0).b6 == 1) {
        FieldState *d;
        func_020627fc(4);
        d = data_ov000_021ccd54;
        d->stageFlags = 1;
        func_ov000_02182590((u8 *)d + 0xac);
        func_ov000_02188140(data_ov000_021ccd54, 0xffff, 0, 0);
    }
}

}


typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
    u32 b9 : 1;
    u32 b10 : 4;
    u32 b14 : 1;
    u32 b15 : 1;
    u32 b16 : 1;
    u32 b17 : 1;
    u32 f18 : 4;
    u32 b22 : 1;
    u32 rest : 9;
} Bits0216dae4;

extern "C" {
extern const s16 FX_SinCosTable_[];
extern int data_02097d78[];
bool func_ov000_021735e8(void);
void func_ov000_0216e67c(void *self);
void func_ov000_0216eaf8(void *self);
void func_ov000_0216e968(void *self);
BOOL func_02054f10(void *a, s32 b);
s32 FX_Div(s32 a, s32 b);
void func_020627fc(s32 a);
void func_ov000_02182590(void *p);
void func_ov000_02188140(void *p, s32 a, s32 b, s32 c);


static inline BOOL GBusy0216dae4(FieldState *g) {
    return g->head != g->tail ? TRUE : FALSE;
}

static inline BOOL GIdle0216dae4(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        if (GBusy0216dae4(g)) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline BOOL FadeIdle0216dae4(void) {
    return (data_02097d78[3] == 0 && data_02097d78[0] == 0) ? TRUE : FALSE;
}

struct Obj0216dae4 {
    u8 unk_00[0x4];
    s32 unk_04;
    s32 unk_08;
    u8 unk_0c[0x4];
    void *unk_10;
    void *unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    u8 unk_28[0x4];
    s32 unk_2c;
    s32 unk_30;
};

static inline BOOL Ready0216dae4(Obj0216dae4 *self) {
    if (!func_02054f10(self->unk_10, 0xffff) || !func_02054f10(self->unk_14, 0xffff)) {
        return FALSE;
    }
    return TRUE;
}

static inline void Done0216dae4(Obj0216dae4 *self) {
    s32 v = self->unk_1c;
    self->unk_20 = v;
    LBIT(self, 0).b9 = 1;
    LBIT(self, 0).b16 = 0;
    LBIT(self, 0).b5 = 1;
    LBIT(self, 0).b8 = 1;
    if (LBIT(self, 0).b6 == 1) {
        FieldState *d;
        func_020627fc(4);
        d = data_ov000_021ccd54;
        d->stageFlags = 1;
        func_ov000_02182590((u8 *)d + 0xac);
        func_ov000_02188140(data_ov000_021ccd54, 0xffff, 0, 0);
    }
}

BOOL func_ov000_0216dae4(Obj0216dae4 *self) {
    if (LFLD(Bits0216dae4, self, 0).b2 == 1) {
        if (!LFLD(Bits0216dae4, self, 0).b0 && !func_ov000_021735e8()) {
            LFLD(Bits0216dae4, self, 0).b4 = 1;
        } else if (self->unk_04 == 7 || self->unk_04 == 9) {
            LFLD(Bits0216dae4, self, 0).b4 = 0;
            LFLD(Bits0216dae4, self, 0).f18 = 0;
        }
    }
    switch (self->unk_04) {
    case 3:
        return FALSE;
    case 0:
        self->unk_04 = 1;
    case 1:
        self->unk_04 = 4;
    case 4:
        if (LFLD(Bits0216dae4, self, 0).b2 && LFLD(Bits0216dae4, self, 0).b4) {
            LFLD(Bits0216dae4, self, 0).b3 = 1;
            self->unk_04 = 5;
        } else {
            if (LFLD(Bits0216dae4, self, 0).b0) {
                self->unk_04 = 3;
            }
            break;
        }
    case 5:
        func_ov000_0216e67c(self);
        self->unk_04 = 6;
    case 6:
        if (!Ready0216dae4(self)) {
            break;
        }
        LFLD(Bits0216dae4, self, 0).b5 = 1;
        self->unk_2c = 0;
        self->unk_30 = 0x1000;
        self->unk_04 = 8;
    case 8: {
        s32 t;
        self->unk_2c += 0x1000;
        t = FX_Div(self->unk_2c, 0x1e000);
        if (t >= 0x1000) {
            self->unk_2c = 0;
            LFLD(Bits0216dae4, self, 0).b5 = 0;
            t = 0x1000;
            if (LFLD(Bits0216dae4, self, 0).b3) {
                self->unk_04 = 7;
            } else {
                self->unk_04 = 4;
                break;
            }
        }
        self->unk_30 = FX_SinCosTable_[(((t * 0x4000) >> 12) >> 4) * 2];
        if (LFLD(Bits0216dae4, self, 0).b3) {
            self->unk_30 = 0x1000 - self->unk_30;
        }
    }
    case 7:
        if (LFLD(Bits0216dae4, self, 0).b9 == 1) {
            func_ov000_0216eaf8(self);
        } else if ((LFLD(Bits0216dae4, self, 0).b22 || FadeIdle0216dae4()) && (!LFLD(Bits0216dae4, self, 0).b6 || GIdle0216dae4()) && LFLD(Bits0216dae4, self, 0).b7 == 1) {
            if (self->unk_08 == 2) {
                self->unk_1c -= self->unk_18;
                if (self->unk_1c <= 0) {
                    self->unk_1c = 0;
                    LFLD(Bits0216dae4, self, 0).b14 = 1;
                    if (LFLD(Bits0216dae4, self, 0).b6 == 1) {
                        Done0216dae4(self);
                    }
                }
            } else {
                self->unk_1c += self->unk_18;
                if (self->unk_1c >= 0x57e40) {
                    self->unk_1c = 0x57e40;
                }
                if (self->unk_1c > self->unk_24) {
                    self->unk_1c = self->unk_24;
                    LFLD(Bits0216dae4, self, 0).b14 = 1;
                    if (LFLD(Bits0216dae4, self, 0).b6 == 1) {
                        Done0216dae4(self);
                    }
                }
            }
        }
        if (LFLD(Bits0216dae4, self, 0).b8 != 1) {
            self->unk_20 = self->unk_1c;
        } else {
            func_ov000_0216e968(self);
        }
    case 9:
        if (!LFLD(Bits0216dae4, self, 0).b2 || !LFLD(Bits0216dae4, self, 0).b4) {
            LFLD(Bits0216dae4, self, 0).b5 = 1;
            LFLD(Bits0216dae4, self, 0).b3 = 0;
            self->unk_04 = 8;
        }
        break;
    }
    return TRUE;
}
}
