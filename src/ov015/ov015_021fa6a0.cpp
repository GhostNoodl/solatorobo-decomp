#include "ov015/ov015.h"

extern "C" {


extern Ov015Globals data_ov015_02213320;
extern u8 *data_02097d48;
extern u8 data_ov015_022127cc[];
extern u8 data_ov015_0221280c[];
void func_02043904(void *p);
void func_02043b20(void *p);
void func_ov015_021fa8ec(Ov015Main *self);
void func_ov015_022110f0(void);
extern void *data_02097cdc;
extern void *data_0208cca0;
extern void *data_0208cc94;
extern void *data_0208ccc8;
extern char data_0214b105[];
extern u8 *data_ov000_021ccd54;
extern void **data_0214a420;
void func_02036838(void *a, void *b, int c, int d);
void GXx_SetMasterBrightness_(u32 reg, s32 v);
void *func_020359d0(void *a, int b, int c);
s32 func_02035b90(void *a, int b);




extern Ov015Shared *data_ov015_02213368;


extern Ov015Pad *data_02097e48;
extern u8 *data_0214a424;
extern u8 data_ov015_022127fc[];
extern u8 data_ov015_022129e0[];
extern u8 data_ov015_0221296c[];
extern u8 data_ov015_022127ec[];
extern u8 data_ov015_022127dc[];
void func_ov015_0221102c(void);
void func_ov015_02206aa0(void *p);
void func_ov015_021ff350(void *p);
void func_ov015_0220015c(void *p);
void func_ov015_02211828(void *p);
void func_ov015_02200f74(void *p);
void func_02065ac0(void *p);
void func_ov015_021ff380(void *p);
void func_ov015_02200194(void *p);
void func_02043d20(void *p, s32 a);
u8 func_02043d48(void *p);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 n);
void func_02043db4(s32 a, s32 b, s32 c, s32 d);
s32 FX_Div(s32 a, s32 b);
BOOL func_ov015_021faa74(Ov015Main *self);

static inline Ov015V *Ov015_NewChild(Ov015Main *self, s32 kind) {
    Ov015V *c = NULL;
    switch (kind) {
    case 1: {
        Ov015Child *p = (Ov015Child *)func_0203dd9c(0x14);
        if (p != NULL) {
            p->state = 0;
            p->unk_08 = 0;
            SET_VT(p, data_ov015_022129e0);
            func_ov015_02206aa0(p);
        }
        c = (Ov015V *)p;
        break;
    }
    case 2: {
        Ov015Child *p;
        data_ov015_02213368->unk_04 = self->unk_04;
        p = (Ov015Child *)func_0203dd9c(0xcc);
        if (p != NULL) {
            p->state = 0;
            p->unk_08 = 0;
            SET_VT(p, data_ov015_0221296c);
            SET_VT((u8 *)p + 0x30, data_ov015_022127ec);
            func_ov015_021ff350((u8 *)p + 0x30);
            SET_VT((u8 *)p + 0x5c, data_ov015_022127dc);
            func_ov015_0220015c((u8 *)p + 0x5c);
            func_ov015_02211828((u8 *)p + 0x94);
            func_ov015_02200f74(p);
        }
        c = (Ov015V *)p;
        break;
    }
    }
    return c;
}

static inline s32 Ov015_Lerp(s32 from, s32 to, s32 t) {
    return from + Ov015_FxMul(to - from, t);
}

static inline void Ov015Fade_Update(Ov015Fade *f) {
    s32 a = f->unk_08;
    s32 b = f->unk_09;
    s32 to = b << 12;
    s32 from = a << 12;
    s32 t = FX_Div(f->unk_14, f->unk_0c);
    f->unk_18 = (from + Ov015_FxMul(-from + to, t)) >> 12;
    f->unk_14 += 0x1000;
    if (f->unk_14 >= f->unk_0c) {
        f->unk_14 = f->unk_0c;
    }
}

s32 func_ov015_021fa6a0(void) {
    return 1;
}

s32 func_ov015_021fa6a8(void) {
    return 1;
}

s32 func_ov015_021fa6b0(void) {
    return 1;
}

s32 func_ov015_021fa6b8(void) {
    return 0;
}

s32 func_ov015_021fa6c0(void) {
    return 3;
}

void func_ov015_021fa6c8(void) {
}

void func_ov015_021fa6cc(void *self) {
}

Ov015V *func_ov015_021fa6d0(void) {
    return data_ov015_02213320.unk_04;
}

void func_ov015_021fa6e0(void) {
}

void *func_ov015_021fa6e4(void *self) {
    func_0203de1c(self);
    return self;
}

void func_ov015_021fa6f8(Ov015Fade *self, u8 a, u8 b, s32 c, u16 d) {
    self->unk_08 = a;
    self->unk_09 = b;
    self->unk_0c = c;
    self->unk_10 = d;
    self->unk_14 = 0;
}

void func_ov015_021fa71c(Ov015Fade *self, s32 c, u16 d) {
    self->unk_08 = 0x1f;
    self->unk_09 = 0;
    self->unk_0c = c;
    self->unk_10 = d;
    self->unk_14 = 0;
}

void func_ov015_021fa73c(Ov015Fade *self, s32 c, u16 d) {
    self->unk_08 = 0;
    self->unk_09 = 0x1f;
    self->unk_0c = c;
    self->unk_10 = d;
    self->unk_14 = 0;
}

void func_ov015_021fa75c(Ov015Fade *self) {
    self->unk_08 = 0;
    self->unk_09 = 0;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
}

void func_ov015_021fa77c(void) {
    Ov015Main *p;
    if (data_ov015_02213320.unk_00 != NULL) {
        u32 saved;
        HEAP_PUSH(saved);
        DELETE_V(data_ov015_02213320.unk_00);
        HEAP_POP(saved);
    }
    p = (Ov015Main *)func_0203dd9c(sizeof(Ov015Main));
    if (p != NULL) {
        u8 *sys;
        SET_VT(p, data_ov015_022127cc);
        p->unk_04 = 0;
        p->unk_08 = -1;
        p->unk_0c = 1;
        p->unk_10 = 0;
        p->unk_14 = 1;
        p->unk_18 = NULL;
        sys = data_02097d48;
        func_02043904(sys + 0x8b0);
        sys[0x8b0] |= 0x30;
        REG16(0x4000060) = (REG16(0x4000060) & ~0x3000) | 0x20;
        func_02043b20(sys + 0x8b0);
    }
    data_ov015_02213320.unk_00 = (Ov015V *)p;
}

void func_ov015_021fa868(void) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_V(data_ov015_02213320.unk_00);
    HEAP_POP(saved);
}


Ov015Main *func_ov015_021fa8c4(Ov015Main *self) {
    SET_VT(self, data_ov015_022127cc);
    func_ov015_021fa8ec(self);
    func_0203de1c(self);
    return self;
}

void func_ov015_021fa8ec(Ov015Main *self) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_V(self->unk_18);
    HEAP_POP(saved);
    func_ov015_022110f0();
    HEAP_PUSH(saved);
    DELETE_V(data_ov015_02213320.unk_04);
    HEAP_POP(saved);
    func_02036838(data_02097cdc, data_0208cca0, 7, 0);
    func_02036838(data_02097cdc, data_0208cc94, 7, 0);
    func_02036838(data_02097cdc, data_0208ccc8, 7, 0);
    func_02036838(data_02097cdc, data_0214b105, 7, 0);
    if (data_ov000_021ccd54 != NULL) {
        *data_0214a420 = data_ov000_021ccd54 + 8;
    }
    GXx_SetMasterBrightness_(0x400006c, 0);
    GXx_SetMasterBrightness_(0x400106c, 0);
}

void *func_ov015_021faa54(void *self) {
    SET_VT(self, data_ov015_0221280c);
    func_0203de1c(self);
    return self;
}

BOOL func_ov015_021faa74(Ov015Main *self) {
    BOOL r = FALSE;
    switch (self->unk_10) {
    case 0:
        func_020359d0(data_0208cca0, 7, 0);
        func_020359d0(data_0208cc94, 7, 0);
        func_020359d0(data_0208ccc8, 7, 0);
        func_020359d0(data_0214b105, 7, 0);
        self->unk_10 = 10;
    case 10: {
        bool ok = func_02035b90(data_0208cca0, 7) != 0;
        ok &= func_02035b90(data_0208cc94, 7);
        ok &= func_02035b90(data_0208ccc8, 7);
        ok &= func_02035b90(data_0214b105, 7);
        if (!ok) {
            break;
        }
        self->unk_10 = 20;
    }
    case 20:
        self->unk_10 = -1;
        r = TRUE;
        break;
    default:
        self->unk_10 = -1;
        r = TRUE;
        break;
    }
    return r;
}


BOOL func_ov015_021faba0(Ov015Main *self) {
    BOOL r = TRUE;
    u32 saved;
    switch (self->unk_0c) {
    case 1:
        if (!func_ov015_021faa74(self)) {
            break;
        }
        self->unk_0c = 2;
    case 2: {
        Ov015Fade *f;
        s32 kind;
        func_ov015_0221102c();
        data_ov015_02213368->unk_2c = ((Ov015Flags18 *)(data_0214a424 + 0x18))->b1 ? 1 : 0;
        HEAP_PUSH(saved);
        DELETE_V(data_ov015_02213320.unk_04);
        HEAP_POP(saved);
        f = (Ov015Fade *)func_0203dd9c(sizeof(Ov015Fade));
        if (f != NULL) {
            SET_VT(f, data_ov015_022127fc);
            f->unk_04 = -0x1000;
            f->unk_08 = 0;
            f->unk_09 = 0;
            f->unk_0c = 0;
            f->unk_10 = 0;
            f->unk_14 = 0;
            f->unk_18 = 0;
        }
        data_ov015_02213320.unk_04 = (Ov015V *)f;
        switch (self->unk_04) {
        case 3:
        case 4:
        case 5:
            self->unk_14 = 2;
            break;
        default:
            self->unk_14 = 1;
            break;
        }
        *data_0214a420 = NULL;
        kind = self->unk_14;
        {
            Ov015V *c = Ov015_NewChild(self, kind);
            self->unk_14 = kind;
            self->unk_18 = c;
        }
        self->unk_0c = 3;
        break;
    }
    case 3: {
        Ov015Child *c = (Ov015Child *)self->unk_18;
        s32 res = 0;
        switch (c->state) {
        case 0:
            if (!VCALL(c)->v08()) {
                break;
            }
            c->state = 1;
        case 1:
            if (!VCALL(c)->v0c()) {
                break;
            }
            c->state = 2;
        case 2:
            if (!VCALL(c)->v10()) {
                break;
            }
            c->state = 3;
        case 3:
            if (VCALL(c)->v14()) {
                break;
            }
            c->state = 4;
        case 4:
            res = VCALL(c)->v18();
            break;
        }
        if (res == 3) {
            HEAP_PUSH(saved);
            DELETE_V(self->unk_18);
            HEAP_POP(saved);
            self->unk_0c = 4;
            r = FALSE;
        } else if (res != 0) {
            HEAP_PUSH(saved);
            DELETE_V(self->unk_18);
            HEAP_POP(saved);
            {
                Ov015V *n = Ov015_NewChild(self, res);
                self->unk_14 = res;
                self->unk_18 = n;
            }
        }
        func_02065ac0(data_0214a420);
        Ov015Fade_Update((Ov015Fade *)data_ov015_02213320.unk_04);
        break;
    }
    case 4: {
        Ov015Pad *pad;
        pad = data_02097e48;
        if (pad->b3) {
            pad->unk_06 = 0x8000;
            pad->unk_08 = 0x1e;
            pad->unk_02 = 0;
        }
        r = FALSE;
        break;
    }
    }
    return r;
}


void *func_ov015_021fb048(void *self) {
    SET_VT(self, data_ov015_022127ec);
    func_ov015_021ff380(self);
    return self;
}

void *func_ov015_021fb068(void *self) {
    SET_VT(self, data_ov015_022127dc);
    func_ov015_02200194(self);
    return self;
}

static inline u32 G3_PackPolygonAttr(int light, int polyMode, int cullMode, int polygonID, int alpha, int misc) {
    return (u32)(light | (polyMode << 4) | (cullMode << 6) | misc | (polygonID << 24) | (alpha << 16));
}

void func_ov015_021fb088(Ov015Main *self) {
    Ov015Fade *fd;
    s32 pop;
    u32 polyAttr;
    s32 mtxMode;
    s32 texParam;
    s32 trans[3];
    Ov015Child *c = (Ov015Child *)self->unk_18;
    if (c != NULL && c->state == 3) {
        VCALL(c)->v1c();
    }
    fd = (Ov015Fade *)data_ov015_02213320.unk_04;
    if (fd == NULL || fd->unk_18 == 0) {
        return;
    }
    func_02043d20(data_02097d48 + 0x8b0, 0);
    mtxMode = 2;
    NNS_G3dGeBufferOP_N(0x10, &mtxMode, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    NNS_G3dGeBufferOP_N(0x15, NULL, 0);
    texParam = 0;
    NNS_G3dGeBufferOP_N(0x2a, &texParam, 1);
    polyAttr = G3_PackPolygonAttr(0, 0, 3, func_02043d48(data_02097d48 + 0x8b0), fd->unk_18, 0);
    NNS_G3dGeBufferOP_N(0x29, &polyAttr, 1);
    trans[2] = fd->unk_04;
    trans[0] = 0;
    trans[1] = 0;
    NNS_G3dGeBufferOP_N(0x1c, trans, 3);
    func_02043db4(1, 0x100000, 0xc0000, fd->unk_10);
    pop = 1;
    NNS_G3dGeBufferOP_N(0x12, &pop, 1);
}

void *func_ov015_021fb1c0(void *self) {
    SET_VT(self, data_ov015_022127dc);
    func_ov015_02200194(self);
    func_0203de1c(self);
    return self;
}

void *func_ov015_021fb1e8(void *self) {
    SET_VT(self, data_ov015_022127ec);
    func_ov015_021ff380(self);
    func_0203de1c(self);
    return self;
}

Ov015Main *func_ov015_021fb210(Ov015Main *self) {
    SET_VT(self, data_ov015_022127cc);
    func_ov015_021fa8ec(self);
    return self;
}

void *func_ov015_021fb230(void *self) {
    SET_VT(self, data_ov015_0221280c);
    return self;
}


void func_ov015_021fb240(Ov015VecC *dst, const Ov015VecC *src) {
    *dst = *src;
}

}
