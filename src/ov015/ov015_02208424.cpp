#include "ov015/ov015.h"
#include "Main/Gfx/TexObj.h"

extern "C" {

extern Ov015Ship *data_ov015_02213364;
extern void *data_0208cb74;
void *func_02035f30(void *a, void *b, int c);
void func_02041c34(void *a, int b, void *cb, void *arg);
Ov015Glyph *func_ov015_0220848c(TexObj *obj, TexObjEntry *entry, Ov015Glyph *e, u16 *count);
void func_ov015_02208bac(char *out, s32 *outId, u32 n, const char *src);
void func_ov015_02208a28(Ov015UiText *self, void *p);
s32 func_02041b10(void *m, void *anim);
s32 func_02041bb0(void *m, void *anim);
extern u8 data_0208ba70[];
void func_0204c7d0(void *p);
u32 Text_Measure(u32 a, u32 b, u32 c, u32 *outW, u32 *outH, BOOL d);
u8 Gfx3DState_NextPolyId(void *p);
const char *func_0206ffa0(u16 id);
s32 func_0201e950(const void *s, const void *t, s32 n);
BOOL func_0204cc18(void *p, const char **s);
int func_02054f10(void *a, int b);
s32 func_0203e63c(void *p);
extern u8 data_ov015_02212d3c[];
extern u8 data_ov000_021cac60[];
extern u8 data_ov015_022128fc[];
extern u8 data_ov015_02212e84[];
extern u8 data_ov015_022129d0[];
void *func_ov000_0218e9c4(void *a);
void *func_ov000_0218fe1c(void *a);
void *func_ov000_0219196c(void *a);
void func_0203f260(void *a);
extern u8 data_ov015_02212eb0[];

void func_ov000_02191c24(void *a, void *b);
void func_ov000_02190758(void *m, const void *rot, s32 c);
BOOL func_ov000_021903b4(void *m);

#define OV015_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV015_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV015_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline s32 Ov015_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov015_02208070(Ov015Ship *self) {
    Ov015Vec p;
    Ov015Vec d;
    Ov015Vec out;
    Ov015Vec diff;
    u16 rot[3];
    if (self->loadStep != 0x32) {
        return;
    }
    data_ov015_02213364 = self;
    if (self->unk_d41 != 0) {
        func_ov000_02191c24(&self->shadow, &self->pos);
    }
    *(Ov015Vec *)&self->model.trans = self->pos;
    func_ov000_02190758(&self->model, &self->rotX, 0);
    func_ov000_021903b4(&self->model);
    {
        s32 h;
        p = self->nodeMtx.m[3];
        d.x = self->unk_d4c.x - p.x;
        d.y = self->unk_d4c.y - p.y;
        d.z = self->unk_d4c.z - p.z;
        {
            s64 sq = (s64)d.x * d.x;
            sq += (s64)d.z * d.z;
            OV015_SQRTCNT = 1;
            OV015_SQRT_PARAM = (u64)(sq * 4);
        }
        while (OV015_SQRTCNT & 0x8000) {
        }
        h = ((s32)OV015_SQRT_RESULT + 1) >> 1;
        rot[0] = 0;
        rot[1] = 0;
        rot[2] = 0;
        rot[0] = FX_Atan2(-d.y, h);
        rot[1] = FX_Atan2(d.x, d.z);
        VEC_Normalize(&d, &d);
        d.x = FX_Mul(d.x, 0x1c00);
        d.y = FX_Mul(d.y, 0x1c00);
        d.z = FX_Mul(d.z, 0x1c00);
        switch (self->unk_d3c) {
        case 1: {
            s32 i;
            for (i = 0; i < 8; i++) {
                // Byte offsets kept: indexing unk_358[i] makes the compiler hoist and reorder
                // the address math, which changes the register allocation.
                func_ov000_02190758((u8 *)self + 0x358 + i * 0xe8, rot, 0);
                FLD(Ov015Vec, (u8 *)self + i * 0xe8, 0x3d0) = p;
                func_ov000_021903b4((u8 *)self + 0x358 + i * 0xe8);
                VEC_Add(&d, &p, &p);
            }
            self->unk_d08 = p;
            break;
        }
        case 2:
            MI_Copy36B(self->nodeMtx.m, self->model3.rot);
            *(Ov015Vec *)&self->model3.trans = p;
            func_ov000_021903b4(&self->model3);
            break;
        }
    }
    NNS_G3dGeFlushBuffer();
    data_ov015_02213364 = NULL;
    if (self->unk_d42 == 0) {
        return;
    }
    if (self->fx != NULL) {
        s32 t = FX_Div(self->fxTimer << 12, 0x5a000);
        diff.x = self->nodeMtx.m[3].x - self->unk_d08.x;
        diff.y = self->nodeMtx.m[3].y - self->unk_d08.y;
        diff.z = self->nodeMtx.m[3].z - self->unk_d08.z;
        VEC_MultAdd(t, &diff, (&self->unk_d08), &out);
        self->fx->SetPos(&out);
    }
    if (self->fx2 != NULL) {
        s32 t = FX_Div(self->fxTimer2 << 12, 0xa000);
        s32 sc = Ov015_FxMul64(t, 0x6000) + 0xc000;
        s32 v = Ov015_FxMul64(self->unk_d44, sc);
        self->fx2->SetScaleXYZ(v, v, v);
        self->fx2->SetPos(&self->unk_d4c);
    }
}

void func_ov015_02208424(NNSG3dRS *rs) {
    Ov015ShipMtx *t = &data_ov015_02213364->nodeMtx;
    s32 id = (rs->flag & 0x10) ? rs->currentNodeDesc : -1;
    if (id != t->id) {
        return;
    }
    NNS_G3dGetCurrentMtx((MtxFx43 *)(t->m), (MtxFx33 *)0);
    rs->cbVecFunc[NNS_G3D_SBC_NODEDESC] = NULL;
    rs->cbVecTiming[NNS_G3D_SBC_NODEDESC] = 0;
}

void func_ov015_02208474(NNSG3dRS *rs) {
    rs->cbVecFunc[NNS_G3D_SBC_NODEDESC] = func_ov015_02208424;
    rs->cbVecTiming[NNS_G3D_SBC_NODEDESC] = NNS_G3D_SBC_CALLBACK_TIMING_C;
}

Ov015Glyph *func_ov015_0220848c(TexObj *obj, TexObjEntry *entry, Ov015Glyph *e, u16 *count) {
    u16 n = *count;
    if (entry->index == 0) {
        u32 x0 = e[0].x;
        u32 c0 = e[0].code;
        u32 p0 = e[0].pal;
        u32 v = (u32)entry->unk_08 & 0xff;
        s32 i;
        for (i = 0; i < n; i++) {
            e[i].x = e[i].x - (x0 + 0x80);
            e[i].code = e[i].code - (c0 + 0x60);
            e[i].pal = v + p0;
        }
    }
    *count = n;
    return e;
}

void func_ov015_02208544(Ov015UiText *self) {
    self->flags |= 0x10000;
    self->unk_84 = 0;
    MIi_CpuClearFast(0, self->text, 0x20);
    self->textId = -1;
    self->unk_b0 = 0;
}

static inline void Ov015Label_Ctor(Model *l, const char *name, void *dict) {
    func_02041218(&l->pltt);
    func_02041440(l, (char *)dict, 0);
    STD_CopyString(l->name, name);
}

void func_ov015_02208584(Ov015UiText *self) {
    Model *l = (Model *)Heap_Alloc(sizeof(Model));
    void *r;
    if (l != NULL) {
        Ov015Label_Ctor(l, data_0208cca0, data_0208cb74);
    }
    self->model = l;
    r = func_02034d88(func_02035f30(l->name, l->unk_04c, 2), self->model->unk_04c);
    func_020417e0(self->model, r);
    self->model->flags |= 2;
    func_02041c34(self->model, 0, (void *)func_ov015_0220848c, NULL);
    if (self->title != NULL) {
        func_02041d9c(self->model, 0, 7);
    }
    func_02041d9c(self->model, 0, 0);
    self->flags &= ~2;
}

void func_ov015_0220866c(Ov015UiText *self, void *msg) {
    if (msg == NULL) {
        return;
    }
    func_ov015_02208bac(self->text, &self->textId, 0x20, (const char *)msg);
    if (self->text[0] == 0 && self->textId < 0) {
        return;
    }
    if ((self->flags & 0x10000) && self->unk_84 != NULL) {
        self->unk_b0 = 0xf;
        return;
    }
    func_ov015_02208a28(self, self->text);
}

struct Ov015Bits0c {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 rest : 30;
};

void func_ov015_022086d0(Ov015UiText *self) {
    if (self->state != 2) {
        return;
    }
    if (self->unk_84 != NULL) {
        self->unk_84->unk_vf8c();
    }
    if (self->flags & 0x10000) {
        if (--self->unk_b0 < 0) {
            self->unk_b0 = 0;
        }
        if (self->unk_b0 == 7) {
            func_ov015_02208a28(self, self->text);
        }
    }
    if (((Ov015Bits0c *)&self->flags)->b1 == 1) {
        self->state = 1;
    }
}

void func_ov015_02208750(Ov015UiText *self, s32 a, s32 b, s32 c) {
    self->vfunc_60(a, b, c);
    self->vfunc_70(a, b, c);
}

static inline void *Ov015_MdlAnim0(Model *m) {
    ModelRes *res = m->res;
    ModelPart *part = Ov015Model_GetPart(m, 0);
    if (part != NULL && part->res != NULL) {
        return part->res->tex;
    }
    return NNS_G2dGetCellDataByIdx(res->texRes, **FLD(u16 **, NNS_G2dGetAnimSequenceByIdx(res->mdlRes, 0), 0xc));
}
void func_ov015_02208790(Ov015UiText *self, s32 b, u8 *p) {
    s32 x;
    s32 w;
    s32 h;
    TextWin *o;
    if (self->model == NULL || self->unk_84 == NULL) {
        return;
    }
    x = FX_Mul(0x1000 - b, self->slideX << 12);
    if (self->flags & 0x10000) {
        s32 t = FX_Div(self->unk_b0 << 12, 0xf000);
        t = (s32)(((s64)t * 0xffff000 + 0x800) >> 12);
        x += FX_Mul(FX_SinCosTable_[(t >> 16) * 2 + 1], 0x80000) - 0x80000;
    }
    { Model *m = self->model; w = func_02041b10(m, Ov015_MdlAnim0(m)); }
    { Model *m = self->model; h = func_02041bb0(m, Ov015_MdlAnim0(m)); }
    { s32 py = FLD(s32, p, 0x4) >> 12; Model *m = self->model;
    m->x = (x - 0x20000) & -0x1000;
    m->y = py << 12; }
    self->model->unk_150 = self->posZ;
    func_02041c20(self->model, 0, (void *)(self->unk_ac));
    Ov015Model_PlayPart(self->model, 0, 0);
    o = self->unk_84;
    {
        s32 ax = (((w - 0x20) - (s32)o->width) >> 1) + (x >> 12);
        s32 ay = ((h - (s32)o->height) >> 1) + (FLD(s32, p, 0x4) >> 12) - 1;
        if (o == NULL) return;
        o->unk_vf20(ax, ay);
    }
    self->unk_84->posZ = self->posZ + 0x20;
    self->unk_84->Render();
}

void func_ov015_02208a28(Ov015UiText *self, void *name) {
    void *saved;
    TextWin *o;
    TextWin *p;
    const char *id;
    if (name == NULL) return;
    HEAP_PUSH(saved);
    DELETE_V(self->unk_84);
    HEAP_POP(saved);
    o = (TextWin *)Heap_Alloc(0xb8);
    if (o != NULL) {
        SET_VT(o, data_0208ba70);
        func_0204c7d0(o);
    }
    self->unk_84 = o;
    self->unk_84->font = 4;
    self->unk_84->unk_2c = 0;
    p = self->unk_84;
    p->str = (u32)name;
    p->unk_4c = Text_Measure(p->font, p->spacing, p->str, &p->width, &p->height, (s8)p->unk_37 != 0);
    data_02097ce0->unk_004 = p->font;
    self->unk_84->unk_4_13 = Gfx3DState_NextPolyId(data_02097d48->unk_8b0);
    self->unk_84->flag24 = 1;
    self->unk_84->noVram = 1;
    self->unk_84->rendering = 1;
    id = func_0206ffa0(0x1000);
    if (func_0201e950(name, id, STD_GetStringLength((char *)name)) == 0) {
        self->unk_ac = 0;
    } else {
        self->unk_ac = 1;
    }
}

struct Ov015TagRes {
    s32 type;
    s32 value;
};
// A TextWin (0xb8) built on the stack; a plain struct, since a local TextWin would get an implicit
// constructor. code/value/text are TextWin::code, value and text.
struct Ov015TagParser {
    void *vt;
    u8 pad[0x7c];
    Ov015TagRes res;
    u8 pad2[0x10];
    char str[0x20];
};
typedef s32 (*Ov015CharFn)(const char **s);
void func_ov015_02208bac(char *out, s32 *outId, u32 n, const char *src) {
    Ov015CharFn fn = *(Ov015CharFn *)((u8 *)GfxMgr_GetFont(data_02097ce0) + 4);
    const char *s;
    Ov015TagParser p;
    s = src;
    SET_VT(&p, data_0208ba70);
    func_0204c7d0(&p);
    out[0] = 0;
    *outId = -1;
    while (*s != 0) {
        if (fn(&s) == '<') {
            func_0204cc18(&p, &s);
            Ov015TagRes *r = &p.res;
            if (r->type == 0) {
                *outId = r->value;
                STD_CopyLString(out, func_0206ffa0(*outId), n);
            } else if (r->type == 1) {
                STD_CopyLString(out, p.str, n);
            }
        }
    }
    SET_VT(&p, data_0208ba70);
    ((TextWin *)&p)->unk_vf08();
}

s32 func_ov015_02208cb0(void) {
    return 1;
}

static inline BOOL Ov015Res_Ready(TextWin *t) {
    if (t->unk_6c == NULL) {
        return TRUE;
    }
    if (func_0203e63c(t->unk_6c) != 0) {
        t->unk_6c = NULL;
    } else {
        return !t->noVram;
    }
    return TRUE;
}

BOOL func_ov015_02208cb8(Ov015UiText *self) {
    BOOL r = TRUE;
    TextWin *t;
    if (self->model != NULL && func_02054f10(self->model, 0xffff) == 0) {
        r = FALSE;
    }
    t = (TextWin *)self->title;
    if (t != NULL && !Ov015Res_Ready(t)) {
        r = FALSE;
    }
    t = (TextWin *)self->caption;
    if (t != NULL && !Ov015Res_Ready(t)) {
        r = FALSE;
    }
    return r;
}


void func_ov015_02208d8c(Ov015UiText *self, void *arg, void *arg2) {
    UiDrawItemFn cb = self->onDrawItem;
    if (cb == NULL) {
        return;
    }
    cb(arg, self, arg2);
}
s32 func_ov015_02208db0(Ov015UiText *self) {
    s32 a = self->vfunc_40() * self->rows;
    s32 b = self->vfunc_34();
    s32 c = self->vfunc_38();
    s32 d = a + b;
    return d + c;
}

s32 func_ov015_02208dfc(Ov015UiText *self) {
    s32 a;
    data_02097ce0->unk_004 = self->font;
    a = (*(s8 **)GfxMgr_GetFont(data_02097ce0))[1];
    return a + self->vfunc_3c();
}

s32 func_ov015_02208e40(void) {
    return 0;
}

s32 func_ov015_02208e48(void) {
    return 0;
}

s32 func_ov015_02208e50(void) {
    return 0;
}

s32 func_ov015_02208e58(void) {
    return 0;
}

s32 func_ov015_02208e60(Ov015UiText *self, s32 a, s32 b, s32 c) {
    return self->vfunc_60(a, b, c);
}

void *func_ov015_02208e74(Ov015UiText *self) {
    void *saved;
    SET_VT(self, data_ov015_02212d3c);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_84);
    HEAP_POP(saved);
    SET_VT(self, data_ov000_021cac60);
    self->vfunc_2c();
    Heap_Free(self);
    return self;
}

void *func_ov015_02208efc(Ov015UiText *self) {
    void *saved;
    SET_VT(self, data_ov015_02212d3c);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_84);
    HEAP_POP(saved);
    SET_VT(self, data_ov000_021cac60);
    self->vfunc_2c();
    return self;
}

void func_ov015_02208f7c(NNSG3dRS *rs) {
    u8 m[0x24];
    s32 id = (rs->flag & 0x10) ? rs->currentNodeDesc : -1;
    u8 *t = (u8 *)rs->pRenderObj->ptrUser;
    if (id != FLD(s32, t, 0x30)) {
        return;
    }
    NNS_G3dGetCurrentMtx((MtxFx43 *)t, (MtxFx33 *)0);
    MTX_Scale33_((MtxFx33 *)m, FX_Inv(0xa000), FX_Inv(0xa000), FX_Inv(0xa000));
    MTX_Concat33((MtxFx33 *)t, (MtxFx33 *)m, (MtxFx33 *)t);
}

void func_ov015_0220900c(Ov015FishInfo *self) {
}

void *func_ov015_02209010(Ov015FishInfo *self) {
    Heap_Free(self);
    return self;
}

#define OV015_MUL64(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

void func_ov015_02209024(Ov015FishInfo *self, u16 a, const void *src) {
    s32 v;
    self->id = a;
    MI_CpuCopy8(src, &self->unk_06, 0x14);
    v = self->unk_10 << 12;
    s32 lim;
    if (self->unk_28 < 0xe10000) {
        lim = FX_Mul(v, 0x1000);
    } else if (self->unk_28 < 0x1c20000) {
        lim = FX_Mul(v, 0xccd);
    } else {
        lim = FX_Mul(v, 0xb33);
    }
    self->unk_1c = lim;

}

s32 func_ov015_022090bc(Ov015FishInfo *self) {
    return (s32)(((s64)(self->unk_0a << 4) * 0x2000 + 0x800) >> 12) + 0x19a;
}

s32 func_ov015_022090f0(Ov015FishInfo *self) {
    return self->unk_16 << 4;
}

void func_ov015_022090fc(NNSG3dRS *rs) {
    rs->cbVecFunc[NNS_G3D_SBC_NODEDESC] = func_ov015_02208f7c;
    rs->cbVecTiming[NNS_G3D_SBC_NODEDESC] = NNS_G3D_SBC_CALLBACK_TIMING_C;
}

void *Ov015Fish_Ctor(Ov015Fish *self) {
    SET_VT(self, data_ov015_022128fc);
    SET_VT(&self->info, data_ov015_02212e84);
    self->info.id = 0xffff;
    MIi_CpuClearFast(0, &self->info.unk_06, 0x14);
    self->info.unk_1c = 0;
    self->info.unk_20 = 0;
    self->info.unk_24 = 0;
    self->info.unk_28 = 0;
    func_ov000_0218e9c4(&self->res);
    func_ov000_0218fe1c(&self->model);
    func_ov000_0218e9c4(&self->res2);
    func_ov000_0218fe1c(&self->model2);
    func_ov000_0219196c(&self->shadow);
    SET_VT(&self->shadow, data_ov015_022129d0);
    func_0203f260(&self->hit);
    self->id = 0xffff;
    self->unk_08 = 0;
    MIi_CpuClearFast(0, &self->rot2[0].x, 0x34);
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = 0;
    MTX_Identity33_((MtxFx33 *)(&self->rot[0].x));
    self->radius = 0;
    self->unk_84 = 0;
    self->unk_88 = 0;
    self->shadowAlpha = 0;
    self->unk_94 = 0;
    self->unk_98 = 0;
    self->dir.y = 0;
    self->dir.z = 0;
    self->unk_a8 = 0;
    self->unk_bc = 0;
    self->nextState = 0;
    self->state = 0;
    self->prevState = 0;
    self->drawMode = 0;
    self->scale.x = 0x1000;
    self->scale.y = 0x1000;
    self->scale.z = 0x1000;
    self->scaleMul = 0x1000;
    self->unk_8c = 0x1000;
    self->dir.x = 0x1000;
    self->minX = -0x32000;
    self->maxX = 0x32000;
    self->maxZ = -0x37000;
    self->minZ = -0xaa000;
    self->nextStateId = 1;
    self->stateId = 1;
    self->prevStateId = 1;
    self->animSpeed = 0x800;
    return self;
}

void func_ov015_02209270(Ov015Fish *self) {
    void *saved;
    HEAP_PUSH(saved);
    DELETE_V(self->nextState);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->prevState);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->state);
    HEAP_POP(saved);
}

void *Ov015FishState_DtorDelete(Ov015FishState *self) {
    SET_VT(self, data_ov015_02212eb0);
    Heap_Free(self);
    return self;
}

}
