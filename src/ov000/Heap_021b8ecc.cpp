#include "ov000/VObj.h"
#include "ov000/HeapScope.h"
#include "nitro/fx.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 pad_00[4];
    VObj *unk_04;
    u8 pad_08[0xc];
    VObj *unk_14;
    VObj *unk_18;
    VObj *unk_1c;
    void *unk_20;
} Obj021b8ecc;

extern "C" {

void func_ov000_0214bc10(void);
void func_ov000_0214c210(void);

void func_ov000_021b8ecc(Obj021b8ecc *self) {
    HEAP_DELETE_VOBJ(self->unk_18);
    HEAP_DELETE_VOBJ(self->unk_1c);
    HEAP_DELETE_VOBJ(self->unk_14);
    HEAP_DELETE_MODEL(self->unk_20);
    HEAP_DELETE_VOBJ(self->unk_04);
    func_ov000_0214bc10();
    func_ov000_0214c210();
}

}

typedef struct {
    u8 pad_00[4];
    VObj *unk_04;
    s32 state;
    s32 mode;
    u16 unk_10;
    u16 unk_12;
    VObj *unk_14;
    VObj *unk_18;
    VObj *unk_1c;
    u8 *unk_20;
    s32 timer;
    s32 v28;
    s32 v2c;
    s32 v30;
    s32 v34;
    s32 v38;
} Obj021b9010;

typedef struct {
    u32 b0 : 1;
    u32 rest : 31;
} Bits021b9010;

typedef struct {
    u8 body[0x30];
    u16 h[4];
} Buf021b9010;

extern "C" {
void *func_0203dd9c(u32 size);
extern char *data_ov000_021cc858[];
extern u8 *data_ov000_021ccd54;
extern void *data_02149ef8;
extern u8 data_0208b318[];
extern u8 data_0208ba70[];
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021ca94c[];
extern u8 *data_02097ce0;
extern void *data_02097e4c;
void func_0206e900(void *buf, const char *s);
void func_ov000_0214bb80(void);
void func_ov000_0214c1ac(void);
BOOL func_ov000_0214c270(void);
BOOL func_ov000_0214bc6c(void);
s32 func_ov000_0214bc94(void);
void *func_02061d54(s32 id);
void *func_02061df0(u16 id);
void *func_02061e7c(u16 id);
void *func_0204c0e8(void *g, void *id);
void func_0204c7d0(void *p);
s32 func_0204c4fc(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void func_02041218(void *a);
void func_02041440(void *m, void *a, s32 b);
void *func_02034d88(s32 a, void *b);
void func_020417e0(void *m, void *a);
void func_02041d9c(void *m, s32 a, s32 b);
BOOL func_ov000_0219bf90(void);
void func_ov000_021b4774(void);
BOOL func_02054f10(void *m, s32 a);
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_02153f90(Buf021b9010 *b);
void func_ov000_02153fd8(Buf021b9010 *b);
void *func_ov000_0214c064(u16 id);
void func_0204c6bc(void *a, s32 b, Buf021b9010 *c, void *fn);
void func_ov000_0214dc20(void);
void func_ov000_0214c668(VObj *o, u16 a);
BOOL func_ov000_0214c6a0(void *o);

static inline VObj *NewTextWin_021b9010(void) {
    u8 *p = (u8 *)func_0203dd9c(0xb8);
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, data_0208ba70);
        func_0204c7d0(p);
    }
    return (VObj *)p;
}

static inline void TextWinStart_021b9010(u8 *w, void *text) {
    LFLD(void *, w, 0x24) = text;
    LFLD(s32, w, 0x4c) = func_0204c4fc(LFLD(s32, w, 0x28), LFLD(s32, w, 0x38), LFLD(s32, w, 0x24), w + 0x44, w + 0x48, LFLD(s8, w, 0x37) != 0);
    LFLD(s32, data_02097ce0, 0x4) = LFLD(s32, w, 0x28);
}

static inline s32 Ease_021b9010(s32 t, s32 d) {
    s32 r;
    if (t < 0) {
        t = 0;
    }
    r = FX_Div(t << 12, d);
    if (r >= 0x1000) {
        r = 0x1000;
    }
    return FX_SinCosTable_[((r * 0x4000) >> 16) * 2];
}

static inline BOOL IsA_021b9010(s32 v) {
    return (v == 0x14 || (u32)(v - 0x16) <= 1) ? TRUE : FALSE;
}

static inline BOOL Idle_021b9010(VObj *o) {
    return LFLD(Bits021b9010, o, 0xc).b0 == 0 ? TRUE : FALSE;
}

BOOL func_ov000_021b9010(Obj021b9010 *self) {
    char buf[0x20];
    Buf021b9010 tb;

    switch (self->state) {
    case 1: {
        VObj *p = (VObj *)func_0203dd9c(0x4c);
        if (p != NULL) {
            VOBJ_SET_VTABLE(p, data_0208b318);
            p->vfunc_08();
        }
        self->unk_04 = p;
        func_0206e900(buf, data_ov000_021cc858[0]);
        LFLD(s32, self->unk_04, 0x44) = 7;
        self->unk_04->vfunc_1c(buf);
        func_ov000_0214bb80();
        func_ov000_0214c1ac();
        self->state = 2;
        break;
    }
    case 2:
        if (!func_ov000_0214c270()) {
            break;
        }
        if (!self->unk_04->vfunc_2c()) {
            break;
        }
        if (!func_ov000_0214bc6c()) {
            break;
        }
        self->state = 4;
    case 4: {
        s32 v = LFLD(s32, data_ov000_021ccd54, 0x98);
        void *text;
        void *text1;
        u8 *w;
        u8 *m;
        VObj *o;
        if (!IsA_021b9010(v) && (u32)(v - 0x11) > 2) {
            break;
        }
        if (self->mode <= 1) {
            text = func_02061d54(0x8a);
        } else {
            text = func_02061d54(0x8b);
        }
        text1 = func_0204c0e8(data_02149ef8, text);
        self->unk_18 = NewTextWin_021b9010();
        LFLD(s32, self->unk_18, 0x28) = 4;
        LFLD(s32, self->unk_18, 0x2c) = 0;
        TextWinStart_021b9010((u8 *)self->unk_18, text1);
        self->unk_18->vfunc_14();
        LFLD(u32, self->unk_18, 4) |= 0x40;
        LFLD(u32, self->unk_18, 4) |= 0x40000000;
        LFLD(u32, self->unk_18, 4) |= 4;
        if (self->mode <= 1) {
            text = func_02061df0(self->unk_10);
        } else {
            text = func_02061e7c(self->unk_10);
        }
        self->unk_1c = NewTextWin_021b9010();
        LFLD(s32, self->unk_1c, 0x28) = 8;
        LFLD(s32, self->unk_1c, 0x2c) = 0;
        TextWinStart_021b9010((u8 *)self->unk_1c, text);
        self->unk_1c->vfunc_14();
        LFLD(u32, self->unk_1c, 4) |= 0x40;
        LFLD(u32, self->unk_1c, 4) |= 0x40000000;
        LFLD(u32, self->unk_1c, 4) |= 4;
        m = (u8 *)func_0203dd9c(0x160);
        if (m != NULL) {
            char *nm = data_ov000_021cc858[1];
            func_02041218(m + 0x88);
            func_02041440(m, nm, 0);
        }
        self->unk_20 = m;
        func_020417e0(self->unk_20, func_02034d88(self->unk_04->vfunc_10(), self->unk_20 + 0x4c));
        LFLD(u32, self->unk_20, 0x6c) |= 2;
        func_02041d9c(self->unk_20, 0, 1);
        if (self->mode == 1 || self->mode == 3) {
            LFLD(u32, self->unk_20, 0x6c) |= 2;
            func_02041d9c(self->unk_20, 0, 0);
            if (func_ov000_0219bf90()) {
                func_ov000_021b4774();
            }
        }
        func_ov000_0214bc94();
        o = (VObj *)func_0203dd9c(0x21c);
        if (o != NULL) {
            VOBJ_SET_VTABLE(o, data_ov000_021cac60);
            o->vfunc_28();
            VOBJ_SET_VTABLE(o, data_ov000_021ca94c);
            VOBJ_SET_VTABLE((u8 *)o + 0x90, data_0208ba70);
            func_0204c7d0((u8 *)o + 0x90);
            VOBJ_SET_VTABLE((u8 *)o + 0x148, data_0208ba70);
            func_0204c7d0((u8 *)o + 0x148);
            o->vfunc_28();
        }
        self->unk_14 = o;
        o->vfunc_08();
        LFLD(s16, self->unk_14, 0x68) = -0x91a;
        self->state = 10;
        break;
    }
    case 10:
        if (!func_02054f10(self->unk_20, 0xffff)) {
            break;
        }
        self->state = 11;
    case 11:
        if (!func_02054f10(self->unk_20, 0xffff)) {
            break;
        }
        if (self->mode == 0 || self->mode == 2) {
            if (self->timer == 0) {
                func_02049a48(data_02097e4c, 0x25, -1, -1, -1);
            }
            if (++self->timer > 0xb4) {
                self->timer = 0;
                self->state = 12;
                break;
            }
            self->v28 = Ease_021b9010(self->timer, 0x3c000);
            self->v2c = Ease_021b9010(self->timer, 0x3c000);
            self->v30 = Ease_021b9010(self->timer - 0x1e, 0x3c000);
            self->v34 = Ease_021b9010(self->timer - 0x5a, 0x5a000);
        } else {
            if (self->timer == 0) {
                func_02049a48(data_02097e4c, 0x26, -1, -1, -1);
            }
            if (++self->timer > 0x78) {
                self->timer = 0;
                self->state = 12;
                break;
            }
            self->v28 = Ease_021b9010(self->timer, 0x1e000);
            self->v2c = Ease_021b9010(self->timer - 0x3c, 0xf000);
            self->v30 = Ease_021b9010(self->timer - 0x4b, 0xf000);
            self->v34 = Ease_021b9010(self->timer - 0x3c, 0xf000);
            self->v38 = Ease_021b9010(self->timer - 0x5a, 0x1e000);
        }
        break;
    case 12:
        if (++self->timer > 0x3c) {
            self->timer = 0;
            self->v38 = 0;
            self->v34 = 0;
            self->v30 = 0;
            self->v2c = 0;
            self->v28 = 0;
            self->state = 13;
        }
        break;
    case 13:
        if (self->mode == 0 || self->mode == 2) {
            s32 v;
            if (++self->timer > 0x28) {
                self->timer = 0;
                self->state = 0x11;
                break;
            }
            v = Ease_021b9010(self->timer, 0x28000);
            self->v28 = v;
            self->v2c = v;
            self->v30 = v;
            self->v34 = v;
        } else {
            s32 v;
            if (++self->timer > 0x3c) {
                self->timer = 0;
                if (self->mode == 3) {
                    self->state = 0x10;
                } else {
                    self->state = 0x11;
                }
                break;
            }
            self->v38 = Ease_021b9010(self->timer, 0x1e000);
            self->v2c = Ease_021b9010(self->timer - 0x2d, 0xf000);
            self->v30 = Ease_021b9010(self->timer - 0x1e, 0xf000);
            v = Ease_021b9010(self->timer - 0x1e, 0x1e000);
            self->v28 = v;
            self->v34 = v;
        }
        break;
    case 16: {
        VObj *o = self->unk_14;
        if (o == NULL) {
            self->state = 0x11;
            break;
        }
        switch (self->unk_12) {
        case 0:
            if (Idle_021b9010(o)) {
                self->unk_12++;
            }
            break;
        case 0xf:
            func_ov000_02153f90(&tb);
            tb.h[0] = 0;
            tb.h[1] = 0;
            tb.h[2] = 0;
            tb.h[3] = 0;
            func_0204c6bc(func_ov000_0214c064(self->unk_10), 1, &tb, (void *)func_ov000_0214dc20);
            func_ov000_0214c668(self->unk_14, tb.h[3]);
            self->unk_12 = 0x10;
            func_ov000_02153fd8(&tb);
            break;
        case 0x10:
            if (!func_ov000_0214c6a0(o)) {
                self->unk_12++;
            }
            break;
        case 0x4c:
            LFLD(u32, o, 0xc) |= 2;
            self->unk_12 = 0x4d;
            break;
        case 0x4d:
            break;
        default:
            self->unk_12++;
            break;
        }
        if (!self->unk_14->vfunc_1c()) {
            HEAP_DELETE_VOBJ(self->unk_14);
            self->state = 0x11;
        }
        break;
    }
    case 17:
        return FALSE;
    }
    return TRUE;
}
}
