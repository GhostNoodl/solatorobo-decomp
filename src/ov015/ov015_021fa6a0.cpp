#include "ov015/ov015.h"

extern "C" {


extern Ov015Globals data_ov015_02213320;
extern u8 data_ov015_022127cc[];
extern u8 data_ov015_0221280c[];
void func_02043904(void *p);
void func_02043b20(void *p);
void func_ov015_021fa8ec(Ov015Main *self);
void func_ov015_022110f0(void);
extern void *data_0208cc94;
extern void *data_0208ccc8;
extern char data_0214b105[];
void GXx_SetMasterBrightness_(u32 reg, s32 v);






extern u8 *data_0214a424;
extern u8 data_ov015_022127fc[];
extern u8 data_ov015_022129e0[];
extern u8 data_ov015_0221296c[];
extern u8 data_ov015_022127ec[];
extern u8 data_ov015_022127dc[];
void func_ov015_0221102c(void);
void func_ov015_021ff350(Ov015Obj30 *self);
void func_ov015_0220015c(Ov015Obj34 *self);
void func_ov015_02211828(Ov015Info38 *p);
void func_ov015_02200f74(Ov015Game *p);
void func_ov015_021ff380(Ov015Obj30 *self);
void func_ov015_02200194(Ov015Obj34 *self);
u8 Gfx3DState_NextPolyId(void *p);
void func_02043db4(s32 a, s32 b, s32 c, s32 d);
BOOL func_ov015_021faa74(Ov015Main *self);

static inline Ov015V *Ov015_NewChild(Ov015Main *self, s32 kind) {
    Ov015V *c = NULL;
    switch (kind) {
    case 1: {
        Ov015SceneSeq *p = (Ov015SceneSeq *)Heap_Alloc(sizeof(Ov015SceneSeq));
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
        Ov015Game *p;
        data_ov015_02213368->unk_04 = self->unk_04;
        p = (Ov015Game *)Heap_Alloc(0xcc);
        if (p != NULL) {
            p->state = 0;
            p->unk_08 = 0;
            SET_VT(p, data_ov015_0221296c);
            SET_VT(&p->phase1, data_ov015_022127ec);
            func_ov015_021ff350(&p->phase1);
            SET_VT(&p->phase2, data_ov015_022127dc);
            func_ov015_0220015c(&p->phase2);
            func_ov015_02211828(&p->info);
            func_ov015_02200f74(p);
        }
        c = (Ov015V *)p;
        break;
    }
    }
    return c;
}

static inline s32 Ov015_Lerp(s32 from, s32 to, s32 t) {
    return from + FX_Mul(to - from, t);
}

static inline void Ov015Fade_Update(Ov015Fade *f) {
    s32 a = f->alphaFrom;
    s32 b = f->alphaTo;
    s32 to = b << 12;
    s32 from = a << 12;
    s32 t = FX_Div(f->time, f->duration);
    f->alpha = (from + FX_Mul(-from + to, t)) >> 12;
    f->time += 0x1000;
    if (f->time >= f->duration) {
        f->time = f->duration;
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

void func_ov015_021fa6cc(Ov015Child *self) {
}

Ov015V *func_ov015_021fa6d0(void) {
    return data_ov015_02213320.unk_04;
}

void func_ov015_021fa6e0(void) {
}

void *func_ov015_021fa6e4(Ov015Fade *self) {
    Heap_Free(self);
    return self;
}

void Ov015Fade_Start(Ov015Fade *self, u8 a, u8 b, s32 c, u16 d) {
    self->alphaFrom = a;
    self->alphaTo = b;
    self->duration = c;
    self->color = d;
    self->time = 0;
}

void Ov015Fade_ToClear(Ov015Fade *self, s32 c, u16 d) {
    self->alphaFrom = 0x1f;
    self->alphaTo = 0;
    self->duration = c;
    self->color = d;
    self->time = 0;
}

void Ov015Fade_ToOpaque(Ov015Fade *self, s32 c, u16 d) {
    self->alphaFrom = 0;
    self->alphaTo = 0x1f;
    self->duration = c;
    self->color = d;
    self->time = 0;
}

void Ov015Fade_Reset(Ov015Fade *self) {
    self->alphaFrom = 0;
    self->alphaTo = 0;
    self->duration = 0;
    self->color = 0;
    self->time = 0;
    self->alpha = 0;
}

void func_ov015_021fa77c(void) {
    Ov015Main *p;
    if (data_ov015_02213320.unk_00 != NULL) {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_V(data_ov015_02213320.unk_00);
        HEAP_POP(saved);
    }
    p = (Ov015Main *)Heap_Alloc(sizeof(Ov015Main));
    if (p != NULL) {
        GfxSys *sys;
        SET_VT(p, data_ov015_022127cc);
        p->unk_04 = 0;
        p->unk_08 = -1;
        p->unk_0c = 1;
        p->unk_10 = 0;
        p->unk_14 = 1;
        p->child = NULL;
        sys = data_02097d48;
        func_02043904(sys->unk_8b0);
        sys->unk_8b0[0] |= 0x30;
        REG16(0x4000060) = (REG16(0x4000060) & ~0x3000) | 0x20;
        func_02043b20(sys->unk_8b0);
    }
    data_ov015_02213320.unk_00 = (Ov015V *)p;
}

void func_ov015_021fa868(void) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_V(data_ov015_02213320.unk_00);
    HEAP_POP(saved);
}


Ov015Main *func_ov015_021fa8c4(Ov015Main *self) {
    SET_VT(self, data_ov015_022127cc);
    func_ov015_021fa8ec(self);
    Heap_Free(self);
    return self;
}

void func_ov015_021fa8ec(Ov015Main *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_V(self->child);
    HEAP_POP(saved);
    func_ov015_022110f0();
    HEAP_PUSH(saved);
    DELETE_V(data_ov015_02213320.unk_04);
    HEAP_POP(saved);
    func_02036838(data_02097cdc, data_0208cca0, 7, 0);
    func_02036838(data_02097cdc, (char *)data_0208cc94, 7, 0);
    func_02036838(data_02097cdc, (char *)data_0208ccc8, 7, 0);
    func_02036838(data_02097cdc, data_0214b105, 7, 0);
    if (data_ov000_021ccd54 != NULL) {
        *(void **)data_0214a420->task = data_ov000_021ccd54->pause;
    }
    GXx_SetMasterBrightness_(0x400006c, 0);
    GXx_SetMasterBrightness_(0x400106c, 0);
}

void *func_ov015_021faa54(Ov015Child *self) {
    SET_VT(self, data_ov015_0221280c);
    Heap_Free(self);
    return self;
}

BOOL func_ov015_021faa74(Ov015Main *self) {
    BOOL r = FALSE;
    switch (self->unk_10) {
    case 0:
        func_020359d0(data_0208cca0, 7, 0);
        func_020359d0((char *)data_0208cc94, 7, 0);
        func_020359d0((char *)data_0208ccc8, 7, 0);
        func_020359d0(data_0214b105, 7, 0);
        self->unk_10 = 10;
    case 10: {
        bool ok = func_02035b90(data_0208cca0, 7) != 0;
        ok &= func_02035b90((char *)data_0208cc94, 7);
        ok &= func_02035b90((char *)data_0208ccc8, 7);
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
    void *saved;
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
        f = (Ov015Fade *)Heap_Alloc(sizeof(Ov015Fade));
        if (f != NULL) {
            SET_VT(f, data_ov015_022127fc);
            f->posZ = -0x1000;
            f->alphaFrom = 0;
            f->alphaTo = 0;
            f->duration = 0;
            f->color = 0;
            f->time = 0;
            f->alpha = 0;
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
        *(void **)data_0214a420->task = NULL;
        kind = self->unk_14;
        {
            Ov015V *c = Ov015_NewChild(self, kind);
            self->unk_14 = kind;
            self->child = c;
        }
        self->unk_0c = 3;
        break;
    }
    case 3: {
        Ov015Child *c = (Ov015Child *)self->child;
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
            DELETE_V(self->child);
            HEAP_POP(saved);
            self->unk_0c = 4;
            r = FALSE;
        } else if (res != 0) {
            HEAP_PUSH(saved);
            DELETE_V(self->child);
            HEAP_POP(saved);
            {
                Ov015V *n = Ov015_NewChild(self, res);
                self->unk_14 = res;
                self->child = n;
            }
        }
        func_02065ac0(data_0214a420);
        Ov015Fade_Update((Ov015Fade *)data_ov015_02213320.unk_04);
        break;
    }
    case 4: {
        SndQueue *pad;
        pad = data_02097e48.queue;
        if (pad->flag3) {
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


void *Ov015Obj30_Dtor(Ov015Obj30 *self) {
    SET_VT(self, data_ov015_022127ec);
    func_ov015_021ff380(self);
    return self;
}

void *func_ov015_021fb068(Ov015Obj34 *self) {
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
    Ov015Child *c = (Ov015Child *)self->child;
    if (c != NULL && c->state == 3) {
        VCALL(c)->v1c();
    }
    fd = (Ov015Fade *)data_ov015_02213320.unk_04;
    if (fd == NULL || fd->alpha == 0) {
        return;
    }
    func_02043d20(data_02097d48->unk_8b0, 0);
    mtxMode = 2;
    NNS_G3dGeBufferOP_N(0x10, (unsigned int *)&mtxMode, 1);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    NNS_G3dGeBufferOP_N(0x15, NULL, 0);
    texParam = 0;
    NNS_G3dGeBufferOP_N(0x2a, (unsigned int *)&texParam, 1);
    polyAttr = G3_PackPolygonAttr(0, 0, 3, Gfx3DState_NextPolyId(data_02097d48->unk_8b0), fd->alpha, 0);
    NNS_G3dGeBufferOP_N(0x29, &polyAttr, 1);
    trans[2] = fd->posZ;
    trans[0] = 0;
    trans[1] = 0;
    NNS_G3dGeBufferOP_N(0x1c, (unsigned int *)trans, 3);
    func_02043db4(1, 0x100000, 0xc0000, fd->color);
    pop = 1;
    NNS_G3dGeBufferOP_N(0x12, (unsigned int *)&pop, 1);
}

void *func_ov015_021fb1c0(Ov015Obj34 *self) {
    SET_VT(self, data_ov015_022127dc);
    func_ov015_02200194(self);
    Heap_Free(self);
    return self;
}

void *Ov015Obj30_DtorDelete(Ov015Obj30 *self) {
    SET_VT(self, data_ov015_022127ec);
    func_ov015_021ff380(self);
    Heap_Free(self);
    return self;
}

Ov015Main *func_ov015_021fb210(Ov015Main *self) {
    SET_VT(self, data_ov015_022127cc);
    func_ov015_021fa8ec(self);
    return self;
}

void *func_ov015_021fb230(Ov015Child *self) {
    SET_VT(self, data_ov015_0221280c);
    return self;
}


void func_ov015_021fb240(Ov015Vec *dst, const Ov015Vec *src) {
    *dst = *src;
}

}
