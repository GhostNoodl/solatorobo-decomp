#include "ov011/ov011.h"

typedef s16 fx16;
typedef Ov011Vec VecFx32;
struct VecFx16 { fx16 x, y, z; };
#define FX32_ONE 0x1000

// A header's zero rotation and vector, plus copies made at startup, and two scales of this TU
// that other functions read. MWCC emits this order as zero rotation, scales, zero vector.
// The functions of 0x02200aac..0x022030b4 (four files, merged in round dtB, each in its own
// namespace) are part of this TU: they read the zero vector through the .rodata base plus an
// offset, and name it (data_ov011_02207438) instead of an FLD view of data_ov011_02207418.
extern const VecFx16 data_ov011_02207418;
extern const VecFx32 data_ov011_02207420;
extern const VecFx32 data_ov011_0220742c;
extern const VecFx32 data_ov011_02207438;
const VecFx32 data_ov011_02207420 = {FX32_ONE / 2, FX32_ONE / 2, FX32_ONE};
const VecFx32 data_ov011_0220742c = {0x14cd, 0x14cd, FX32_ONE};
const VecFx32 data_ov011_02207438 = {0, 0, 0};
const VecFx16 data_ov011_02207418 = {0, 0, 0};
static const VecFx16 data_ov011_02207994 = data_ov011_02207418;
static const VecFx32 data_ov011_0220799c = data_ov011_02207438;

// ---- merged from ov011_02200aac.cpp
namespace m_02200aac {
extern "C" {

s16 func_ov003_021d7e58(void *p);
void func_ov000_021984f4(void *p, s32 a, s32 b);
void func_ov000_0219864c(void *p, s32 a, s32 b);
s32 func_0206fef8(u32 id);
void *func_ov000_0218fe1c(void *p);
BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
void func_ov000_0219badc(void *a, void *b, s32 c);

s32 func_ov011_02200aac(void *p, s32 b) {
    return Ov011_FxMul(func_ov003_021d7e58(p), b);
}

void func_ov011_02200ad0(Ov011Actor *self) {
    if (self->unk_44 != NULL) {
        func_ov000_021984f4(self->unk_44, 0, 0);
    }
}

void func_ov011_02200af0(Ov011Actor *self) {
    if (self->unk_48 != NULL) {
        func_ov000_0219864c(self->unk_48, 0, 0);
    }
}

void func_ov011_02200b10(void *self) {
}

void func_ov011_02200b14(void *self) {
}

void func_ov011_02200b18(void *self) {
}

void func_ov011_02200b1c(void *self) {
}

void func_ov011_02200b20(void *self) {
}

void func_ov011_02200b24(void *self) {
}

void func_ov011_02200b28(void *self) {
}

void func_ov011_02200b2c(void *self) {
}

void func_ov011_02200b30(Ov011V *self) {
    self->v54();
}

void func_ov011_02200b44(Ov011Actor *self) {
    self->unk_ee_5 = 1;
    self->v70();
}

void func_ov011_02200b64(Ov011Actor *self) {
    self->unk_ee_2 = 2;
    self->v64();
}

BOOL func_ov011_02200b88(Ov011Model2 *self, void *a, void *b) {
    s32 r;
    void *p;
    self->b0 = 1;
    self->b1 = 0;
    self->b2 = 0;
    self->unk_02 = 0;
    self->unk_04 = 0;
    r = func_0206fef8((u32)b);
    p = Heap_Alloc(0xe8);
    if (p != NULL) {
        p = func_ov000_0218fe1c(p);
    }
    self->model = (Ov011Sub38 *)p;
    func_ov000_0218ffdc(p, a, 0, 1);
    self->model->unk_b4 = 0xffff;
    func_ov000_0219badc(self->model, a, r);
    self->model->unk_c2_0 = 1;
    return TRUE;
}

}


extern "C" {

extern const Ov011Vec data_ov011_02207450;
extern const Ov011Vec data_ov011_0220745c;
s32 VEC_Distance(const Ov011Vec *a, const Ov011Vec *b);
s32 FX_Div(s32 a, s32 b);

static inline void Ov011Tw_InitA(Ov011Tw *t, const Ov011Vec *from, const Ov011Vec *to) {
    s32 x;
    s32 y;
    s32 z;
    t->b0 = 1;
    t->b1 = 0;
    t->unk_04 = 0;
    x = from->x;
    t->v08.x = x;
    y = from->y;
    t->v08.y = y;
    z = from->z;
    t->v08.z = z;
    t->v14.x = to->x;
    t->v14.y = to->y;
    t->v14.z = to->z;
    t->v20.x = x;
    t->v20.y = y;
    t->v20.z = z;
    t->unk_02 = FX_Div(0x1000, VEC_Distance(to, from));
}

static inline void Ov011Tw_InitB(Ov011Tw *t, s32 from, s32 to, u16 speed, s32 mul) {
    t->b0 = 1;
    t->unk_02 = speed;
    t->v08.x = from;
    t->v08.y = from;
    t->v08.z = from;
    t->v14.x = to;
    t->v14.y = to;
    t->v14.z = to;
    t->unk_04 = Ov011_FxMul(VEC_Distance(&t->v14, &t->v08), mul);
}

void func_ov011_02200c30(Ov011Model2 *self) {
    Ov011Vec a;
    Ov011Vec b;
    s16 v2;
    s16 v4;
    if (!self->b0) {
        return;
    }
    if (self->b1) {
        OV011_BLKCPY(&a, &data_ov011_02207450);
        OV011_BLKCPY(&b, &data_ov011_0220745c);
        self->b1 = 0;
        self->b2 = 1;
        v2 = self->unk_02;
        v4 = self->unk_04;
        OV011_TWV(self->m0c)->v08();
        OV011_TWV(self->m3c)->v08();
        Ov011Tw_InitA(OV011_TW(self->m0c), &a, &b);
        Ov011Tw_InitB(OV011_TW(self->m3c), v2, v4, 0x333, 0x14);
    } else if (self->b2) {
        if (OV011_TWV(self->m0c)->v14() && OV011_TWV(self->m3c)->v14()) {
            self->b1 = 0;
            self->b2 = 0;
            OV011_TWV(self->m0c)->v08();
            OV011_TWV(self->m3c)->v08();
        } else {
            self->model->alpha = *(s32 *)OV011_TWV(self->m0c)->v10() >> 12;
            self->model->scale = *(Ov011Vec *)OV011_TWV(self->m3c)->v10();
        }
    }
    OV011_TWV(self->m0c)->v0c();
    OV011_TWV(self->m3c)->v0c();
}

}

extern "C" {

extern u8 data_ov011_022079f0[];
void *ActorEx_Ctor(void *p);
void *func_ov000_0219429c(void *p);
void func_ov003_021d7ca8(void *p);
void func_ov003_021d7d8c(void *p);
void func_ov003_021d7ce0(void *p);

void *Ov011Npc_Ctor(Ov011Npc *self) {
    ActorEx_Ctor(self);
    *(void **)self = data_ov011_022079f0;
    func_ov003_021d7ca8(self->unk_d8);
    func_ov003_021d7ca8(self->unk_e4);
    func_ov003_021d7ca8(self->unk_f0);
    self->unk_ce_0 = 0;
    self->unk_ce_1 = 0;
    self->unk_d0 = 0xffff;
    self->unk_d4 = NULL;
    return self;
}

void *Ov011Npc_Dtor(Ov011Npc *self) {
    *(void **)self = data_ov011_022079f0;
    func_ov003_021d7d8c(self->unk_d8);
    func_ov003_021d7d8c(self->unk_e4);
    func_ov003_021d7d8c(self->unk_f0);
    self->unk_ce_0 = 0;
    self->unk_ce_1 = 0;
    self->unk_d0 = 0xffff;
    self->unk_d4 = NULL;
    func_ov003_021d7ce0(self->unk_f0);
    func_ov003_021d7ce0(self->unk_e4);
    func_ov003_021d7ce0(self->unk_d8);
    func_ov000_0219429c(self);
    return self;
}

void *Ov011Npc_DtorDelete(Ov011Npc *self) {
    *(void **)self = data_ov011_022079f0;
    func_ov003_021d7d8c(self->unk_d8);
    func_ov003_021d7d8c(self->unk_e4);
    func_ov003_021d7d8c(self->unk_f0);
    self->unk_ce_0 = 0;
    self->unk_ce_1 = 0;
    self->unk_d0 = 0xffff;
    self->unk_d4 = NULL;
    func_ov003_021d7ce0(self->unk_f0);
    func_ov003_021d7ce0(self->unk_e4);
    func_ov003_021d7ce0(self->unk_d8);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

extern u16 data_ov011_02207f00;
s32 func_ov011_02200aac(void *p, s32 b);
s32 func_ov000_02194c08(void *p);

#define OV011_ABS(x) ((x) < 0 ? -(x) : (x))

static inline void Ov011_ScaleV(Ov011Vec *v, s32 x, s32 y, s32 z, s32 s) {
    v->x = Ov011_FxMul(x, s);
    v->y = Ov011_FxMul(y, s);
    v->z = Ov011_FxMul(z, s);
}

s32 Ov011Npc_Draw(Ov011Npc *self) {
    s32 r;
    Ov011Vec saved;
    Ov011Vec v;
    Ov011Sub38 *m;
    u8 be;
    s32 a8;
    s32 ac;
    s32 b0;
    s32 old;
    OV011_BLKCPY(&saved, &self->pos);
    m = self->unk_38;
    be = m->alpha;
    a8 = m->scale.x;
    ac = m->scale.y;
    b0 = m->scale.z;
    if (self->unk_ce_1) {
        OV011_BLKCPY(&v, &saved);
        v.x += func_ov011_02200aac(self->unk_e4, 0x266);
        v.y += func_ov011_02200aac(self->unk_f0, 0x266);
        self->pos = v;
    }
    if (self->unk_ce_0) {
        Ov011_ScaleV(&self->unk_38->scale, a8, ac, b0, Ov011_FxMul(OV011_ABS(OV011_COS(data_ov011_02207f00)), 0xa00) + 0xd00);
    }
    old = self->unk_3c->unk_14;
    self->unk_3c->unk_14 = Ov011_FxMul(old, 0x2800);
    self->unk_38->pos = self->pos;
    r = func_ov000_02194c08(self);
    self->unk_3c->unk_14 = old;
    self->pos = saved;
    m = self->unk_38;
    m->scale.x = a8;
    m->scale.y = ac;
    m->scale.z = b0;
    self->unk_38->alpha = be;
    return r;
}

void func_ov011_022011c0(Ov011Npc *self, u16 v) {
    self->unk_d0 = v;
}

void func_ov011_022011c8(Ov011Npc *self, BOOL on) {
    if (on) {
        self->unk_ce_0 = 1;
        self->unk_4c->unk_1c = self->unk_d0;
    } else {
        self->unk_ce_0 = 0;
        self->unk_4c->unk_1c = 0xffff;
    }
}

void func_ov011_022011fc(Ov011Npc *self, u8 on) {
    self->unk_ce_1 = on;
}

void func_ov011_02201214(Ov011Npc *self, void *p) {
    self->unk_d4 = p;
}

void func_ov011_0220121c(Ov011Npc *self, BOOL on) {
    Ov011Sub38 *m = self->unk_38;
    if (m == NULL) {
        return;
    }
    if (on) {
        m->unk_c2_0 = 1;
    } else {
        m->unk_c2_0 = 0;
    }
}

u32 func_ov011_02201244(Ov011Npc *self) {
    return self->unk_ce_0;
}

void *func_ov011_02201254(Ov011Npc *self) {
    return self->unk_d4;
}

}


struct Ov011CVec {
    s32 x;
    s32 y;
    s32 z;
    Ov011CVec(s32 a, s32 b, s32 c) {
        x = a;
        y = b;
        z = c;
    }
};

struct Ov011Bits94 {
    u8 b0 : 1;
    u8 b1 : 2;
    u8 b3 : 5;
};

extern "C" {

void func_ov000_02194758(void *p);
BOOL func_ov003_021d7d24(void *p, s32 a, s32 b, s32 c, s32 d);
void func_ov000_021953b4(void *p);
void func_ov003_021d7dd0(void *p);
void func_ov000_02195848(void *p);
void *Target_Get(void *p);
Ov011Obj *Actor_GetTarget(void *p);
BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, Ov011Vec *v, s32 e, s32 f, s32 g, s32 h, s32 i);
void func_ov000_02196c40(void *p);
void func_ov000_02196060(void *p);
void func_ov000_0219763c(void *p);
void *func_ov000_02198328(void *p);
void func_ov011_02201688(Ov011Fx *p);

void Ov011Npc_Start(Ov011Npc *self) {
    Ov011Sub44 *p;
    func_ov000_02194758(self);
    func_ov003_021d7d24(self->unk_d8, 0, 0, 1, 1);
    func_ov003_021d7d24(self->unk_e4, 0, 0, 1, 1);
    func_ov003_021d7d24(self->unk_f0, 0, 0, 1, 1);
    self->unk_cc.b4 = 0;
    self->unk_48->unk_9a_7 = 1;
    self->unk_48->unk_38 = 0x800;
    p = self->unk_44;
    p->unk_1c = Ov011_FxMul(p->unk_1c, 0x1a00);
}

void Ov011Npc_Update(Ov011Npc *self) {
    func_ov000_021953b4(self);
    if (self->unk_ce_0) {
        self->unk_40->flags |= 2;
        self->unk_44->unk_22_1 = 0;
        self->unk_94_1 = 1;
    } else if (self->unk_ce_1) {
        self->unk_94_1 = 1;
    } else {
        self->unk_94_1 = 0;
    }
    func_ov003_021d7dd0(self->unk_d8);
    func_ov003_021d7dd0(self->unk_e4);
    func_ov003_021d7dd0(self->unk_f0);
}

void func_ov011_022013a8(Ov011Npc *self) {
    u16 mask;
    void *a;
    if (!self->unk_ce_0) {
        func_ov000_02195848(self);
    }
    mask = 0;
    a = Target_Get(self->unk_4c);
    if (a != NULL) {
        Ov011Obj *b = Actor_GetTarget(a);
        if (b != NULL) {
            mask |= (u16)(1 << (b->id >> 12));
        }
        b = Actor_GetTarget(self);
        if (b != NULL) {
            mask |= (u16)(1 << (b->id >> 12));
        }
    }
    Ov011Vec v = {0, 0, 0};
    v.y = -self->unk_68 / 2;
    if (mask == 0) {
        return;
    }
    func_ov000_0219aae8(self, self, self->unk_4c->unk_08, self->unk_4c->unk_0a, mask, (Ov011Vec *)&v, 0,
                        self->unk_64, self->unk_68, 100, 0x1000);
}

void func_ov011_022014ac(Ov011Npc *self) {
    if (self->unk_40->state == 1) {
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_a0 = 0;
        func_ov000_02196c40(self);
    } else {
        func_ov000_02196060(self);
    }
}

void func_ov011_022014e0(Ov011Npc *self) {
    if (self->unk_40->state == 0) {
        self->unk_ce_0 = 0;
        self->unk_64 = 0xb33;
    }
    func_ov000_0219763c(self);
}

void *func_ov011_02201510(Ov011Fx *self) {
    func_ov000_02198328(&self->state);
    func_ov003_021d7ca8(self->s5c);
    func_ov003_021d7ca8(self->s68);
    func_ov003_021d7ca8(self->s74);
    self->b0 = 0;
    return self;
}

void *func_ov011_0220154c(Ov011Fx *self) {
    func_ov011_02201688(self);
    func_ov003_021d7ce0(self->s74);
    func_ov003_021d7ce0(self->s68);
    func_ov003_021d7ce0(self->s5c);
    return self;
}

}


extern "C" {

void *func_ov000_0218e9c4(void *p);
void *func_ov000_0218ea20(void *p);
void *func_ov000_0218fee4(void *p);
void MTX_Identity33_(void *m);
void func_ov000_02193e5c(void *p, s32 a);
BOOL func_ov000_0218f110(void *p);
void MTX_MultVec33(const Ov011Vec *v, const void *m, Ov011Vec *out);
void VEC_Add(const Ov011Vec *a, const Ov011Vec *b, Ov011Vec *out);
Ov011V *func_02065f88(s32 id, Ov011Vec *v);

BOOL func_ov011_02201578(Ov011Fx *self) {
    void *p;
    self->b0 = 1;
    self->b1 = 0;
    self->b2 = 0;
    self->unk_02 = 0;
    p = Heap_Alloc(0x138);
    if (p != NULL) {
        p = func_ov000_0218e9c4(p);
    }
    self->anim = (Ov011Anim *)p;
    p = Heap_Alloc(0xe8);
    if (p != NULL) {
        p = func_ov000_0218fe1c(p);
    }
    self->model = (Ov011Sub38 *)p;
    {
        const Ov011Vec *src = &data_ov011_02207438;
        s32 x;
        s32 y;
        s32 z;
        x = src->x;
        self->v0c.x = x;
        y = src->y;
        self->v0c.y = y;
        z = src->z;
        self->v0c.z = z;
        self->v18.x = x;
        self->v18.y = y;
        self->v18.z = z;
    }
    MTX_Identity33_(self->mtx);
    func_ov003_021da48c(&self->state, 0);
    func_ov000_02193e5c(self->anim, 0x4812);
    func_ov003_021d7d24(self->s5c, 0, 0, 1, 0);
    func_ov003_021d7d24(self->s68, 0, 0, 1, 0);
    func_ov003_021d7d24(self->s74, 0, 0, 1, 0);
    return TRUE;
}

static inline void Ov011_FreeAnim(Ov011Fx *self) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->anim != NULL) {
        Ov011Anim *p = self->anim;
        if (p != NULL) {
            func_ov000_0218ea20(p);
            Heap_Free(p);
        }
        self->anim = NULL;
    }
    data_02097dd0->cur = saved;
}

static inline void Ov011_FreeModel(Ov011Fx *self) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->model != NULL) {
        Ov011Sub38 *p = self->model;
        if (p != NULL) {
            func_ov000_0218fee4(p);
            Heap_Free(p);
        }
        self->model = NULL;
    }
    data_02097dd0->cur = saved;
}

void func_ov011_02201688(Ov011Fx *self) {
    if (!self->b0) {
        return;
    }
    Ov011_FreeAnim(self);
    Ov011_FreeModel(self);
    func_ov003_021d7d8c(self->s5c);
    func_ov003_021d7d8c(self->s68);
    func_ov003_021d7d8c(self->s74);
    self->b0 = 0;
}

void func_ov011_02201758(Ov011Fx *self) {
    Ov011Vec a;
    Ov011Vec b;
    if (!self->b0) {
        return;
    }
    if (!self->b1) {
        if (self->anim->unk_00 < 0) {
            s32 r;
            self->b1 = 1;
            r = func_0206fef8(0x4812);
            self->model->unk_b4 = 0xffff;
            func_ov000_0219badc(self->model, self->anim, r);
        } else {
            func_ov000_0218f110(self->anim);
        }
    } else if (self->b2) {
        switch (self->state) {
        case 0:
            self->unk_02 = 0x4cd;
            self->state = 1;
            OV011_BLKCPY(&a, &data_ov011_02207420);
            MTX_MultVec33(&self->v0c, self->mtx, &b);
            VEC_Add(&b, &self->v18, &b);
            func_02065f88(0x648, &b)->v10(&a);
            break;
        case 1:
            self->timer++;
            if (self->timer > 30) {
                self->timer = 0;
                self->state = 2;
            }
            break;
        case 2:
            self->unk_02 += 0x1ae;
            self->timer++;
            if (self->timer > 10) {
                self->unk_02 = 0x159a;
                self->timer = 0;
                self->state = 3;
            }
            break;
        case 3:
            self->timer++;
            if (self->timer > 25) {
                self->timer = 0;
                self->b2 = 0;
            }
            break;
        }
        func_ov003_021da40c(&self->state);
    }
    func_ov003_021d7dd0(self->s5c);
    func_ov003_021d7dd0(self->s68);
    func_ov003_021d7dd0(self->s74);
}

}

extern "C" {

extern u8 data_ov011_02207468[];
BOOL func_ov000_021903b4(void *p);
void MTX_RotY33_(void *m, s32 s, s32 c);
void MI_Copy36B(const void *src, void *dst);

void func_ov011_0220192c(Ov011Fx *self) {
    Ov011Vec p;
    Ov011Vec q;
    Ov011Vec s;
    s32 a8;
    s32 ac;
    s32 b0;
    if (!self->b0) {
        return;
    }
    if (!self->b1) {
        return;
    }
    if (!self->b2) {
        return;
    }
    MTX_MultVec33(&self->v0c, self->mtx, &p);
    VEC_Add(&p, &self->v18, &p);
    a8 = self->model->scale.x;
    ac = self->model->scale.y;
    b0 = self->model->scale.z;
    OV011_BLKCPY(&q, &p);
    OV011_BLKCPY(&s, data_ov011_02207468);
    s.x = self->unk_02;
    s.y = self->unk_02;
    q.x += func_ov011_02200aac(self->s68, 0x266);
    q.y += func_ov011_02200aac(self->s74, 0x266);
    s.x += func_ov011_02200aac(self->s5c, 0x333);
    s.y = s.x;
    if (s.x < 0) {
        s.x = 0;
    }
    if (s.y < 0) {
        s.y = 0;
    }
    self->model->pos = q;
    self->model->scale = s;
    func_ov000_021903b4(self->model);
    self->model->pos = p;
    {
        Ov011Sub38 *m = self->model;
        m->scale.x = a8;
        m->scale.y = ac;
        m->scale.z = b0;
    }
}

void func_ov011_02201aac(Ov011Fx *self, const Ov011Vec *pos) {
    if (!self->b0) {
        return;
    }
    if (self->b2) {
        return;
    }
    self->b2 = 1;
    self->v0c = *pos;
    self->v18 = data_ov011_02207438;
    MTX_Identity33_(self->mtx);
    func_ov003_021da48c(&self->state, 0);
}

void func_ov011_02201b28(Ov011Fx *self) {
    if (self->b0) {
        self->b2 = 0;
    }
}

BOOL func_ov011_02201b40(Ov011Fx *self) {
    BOOL r = FALSE;
    if (!self->b0) {
        return r;
    }
    if (!self->b2) {
        r = TRUE;
    }
    return r;
}

u32 func_ov011_02201b64(Ov011Fx *self) {
    u32 r = 0;
    if (self->b0) {
        r = self->b1;
    }
    return r;
}

void func_ov011_02201b80(Ov011Fx *self, const Ov011Vec *v) {
    if (!self->b0) {
        return;
    }
    self->v18 = *v;
}

void func_ov011_02201bac(Ov011Fx *self, u16 ang) {
    u8 m[0x24];
    if (self == NULL) {
        return;
    }
    MTX_RotY33_(m, OV011_SIN(ang), OV011_COS(ang));
    if (!self->b0) {
        return;
    }
    MI_Copy36B(m, self->mtx);
}

}
}  // namespace m_02200aac

// ---- merged from ov011_02201c18.cpp
namespace m_02201c18 {
struct Ov011Chr {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    s16 unk_02;
    s16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 id;
    s32 mode;
    Ov011Vec off;
    Ov011Anim *anim;
    Ov011Sub38 *model;
    s32 unk_24;
    Ov011Model2 m28;
    u8 s88[0xc];
    u8 s94[3][0xc];
};

typedef void (Ov011Chr::*Ov011ChrFn)();

struct Ov011ChrEntry {
    s32 key;
    Ov011ChrFn fn;
};

extern "C" {

extern u8 data_ov011_022079d0[];
extern u8 data_ov011_022079b0[];
extern const Ov011ChrEntry data_ov011_022074b0[];
void func_ov003_021d7ca8(void *p);
void func_ov003_021d7ce0(void *p);
void func_ov003_021d7d8c(void *p);
void func_ov003_021d7dd0(void *p);
BOOL func_ov003_021d7d24(void *p, s32 a, s32 b, s32 c, s32 d);
void __cxa_vec_ctor(void *arr, s32 count, u32 size, void *ctor, void *dtor);
void *func_ov000_0218e9c4(void *p);
void *func_ov000_0218fe1c(void *p);
void *func_ov000_0218ea20(void *p);
void *func_ov000_0218fee4(void *p);
void func_ov000_02193e5c(void *p, s32 a);
BOOL func_ov000_0218f110(void *p);
s32 func_0206fef8(u32 id);
void func_ov000_0219badc(void *a, void *b, s32 c);
void VEC_Add(const Ov011Vec *a, const Ov011Vec *b, Ov011Vec *out);
BOOL func_ov011_02200b88(Ov011Model2 *self, void *a, u32 b);
void func_ov011_02200c30(Ov011Model2 *self);
s32 func_ov011_02200aac(void *p, s32 b);
BOOL func_ov000_021903b4(void *p);
}

static inline void Ov011_FreeModelP(Ov011Sub38 **pp) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (*pp != NULL) {
        Ov011Sub38 *p = *pp;
        if (p != NULL) {
            func_ov000_0218fee4(p);
            Heap_Free(p);
        }
        *pp = NULL;
    }
    data_02097dd0->cur = saved;
}

static inline void Ov011_FreeAnimP(Ov011Anim **pp) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (*pp != NULL) {
        Ov011Anim *p = *pp;
        if (p != NULL) {
            func_ov000_0218ea20(p);
            Heap_Free(p);
        }
        *pp = NULL;
    }
    data_02097dd0->cur = saved;
}

static inline Ov011Obj *Ov011_FindActorN(u16 id) {
    Ov011Obj *a = NULL;
    if (data_ov000_021ccd68 != NULL) {
        a = (Ov011Obj *)ActorMgr_GetActor(data_ov000_021ccd68, id);
    }
    return a;
}

static inline void Ov011Model2_Reset(Ov011Model2 *m) {
    if (m->b0) {
        m->b0 = 0;
        Ov011_FreeModelP(&m->model);
        OV011_TWV(m->m0c)->v08();
        OV011_TWV(m->m3c)->v08();
    }
}

static inline void Ov011Chr_Reset(Ov011Chr *self) {
    u32 i;
    if (!self->b0) {
        return;
    }
    Ov011Model2_Reset(&self->m28);
    func_ov003_021d7d8c(self->s88);
    for (i = 0; i < 3; i++) {
        func_ov003_021d7d8c(self->s94[i]);
    }
    self->b0 = 0;
}

static inline void Ov011TwA_Ctor(void *obj) {
    *(void **)obj = data_ov011_022079d0;
    OV011_TW(obj)->b0 = 0;
}

static inline void Ov011Tw_SetBoth(Ov011Tw *t, const Ov011Vec *src) {
    s32 x;
    s32 y;
    s32 z;
    x = src->x;
    t->v08.x = x;
    y = src->y;
    t->v08.y = y;
    z = src->z;
    t->v08.z = z;
    t->v14.x = x;
    t->v14.y = y;
    t->v14.z = z;
}

static inline void Ov011TwB_Ctor(void *obj) {
    Ov011Tw *t;
    *(void **)obj = data_ov011_022079b0;
    t = OV011_TW(obj);
    t->b0 = 0;
    t->b1 = 0;
    t->unk_02 = 0;
    Ov011Tw_SetBoth(t, &data_ov011_02207438);
}

extern "C" {

Ov011Chr *func_ov011_02201c18(Ov011Chr *self) {
    void *p;
    Ov011TwA_Ctor(self->m28.m0c);
    Ov011TwB_Ctor(self->m28.m3c);
    self->m28.b0 = 0;
    func_ov003_021d7ca8(self->s88);
    __cxa_vec_ctor(self->s94, 3, 0xc, func_ov003_021d7ca8, func_ov003_021d7ce0);
    self->b0 = 0;
    self->b1 = 0;
    p = Heap_Alloc(0x138);
    if (p != NULL) {
        p = func_ov000_0218e9c4(p);
    }
    self->anim = (Ov011Anim *)p;
    p = Heap_Alloc(0xe8);
    if (p != NULL) {
        p = func_ov000_0218fe1c(p);
    }
    self->model = (Ov011Sub38 *)p;
    return self;
}

}

static inline void Ov011TwB_Dtor(void *obj) {
    *(void **)obj = data_ov011_022079b0;
    OV011_TWV(obj)->v08();
}

static inline void Ov011TwA_Dtor(void *obj) {
    *(void **)obj = data_ov011_022079d0;
    OV011_TWV(obj)->v08();
}

extern "C" {

void __cxa_vec_cleanup(void *arr, s32 count, u32 size, void *dtor);

Ov011Chr *func_ov011_02201d10(Ov011Chr *self) {
    Ov011Chr_Reset(self);
    Ov011_FreeAnimP(&self->anim);
    Ov011_FreeModelP(&self->model);
    __cxa_vec_cleanup(self->s94, 3, 0xc, func_ov003_021d7ce0);
    func_ov003_021d7ce0(self->s88);
    Ov011Model2_Reset(&self->m28);
    Ov011TwB_Dtor(self->m28.m3c);
    Ov011TwA_Dtor(self->m28.m0c);
    return self;
}

BOOL func_ov011_02201f28(Ov011Chr *self, u16 id, const Ov011Vec *off, u16 c, s16 d, s16 e) {
    Ov011Obj *a;
    u32 i;
    self->id = id;
    self->b0 = 1;
    self->unk_02 = e;
    self->unk_04 = d;
    self->unk_06 = c;
    self->unk_08 = 0;
    self->mode = 0;
    self->off = *off;
    self->unk_24 = 0;
    func_ov000_02193e5c(self->anim, 0x4812);
    a = Ov011_FindActorN(self->id);
    if (a != NULL) {
        Ov011Vec p;
        p = a->pos;
        VEC_Add(&p, &self->off, &p);
        self->model->pos = p;
    }
    func_ov003_021d7d24(self->s88, 0, 0, 1, 0);
    for (i = 0; i < 3; i++) {
        func_ov003_021d7d24(self->s94[i], 0, 0, 1, 0);
    }
    return TRUE;
}

void func_ov011_0220205c(Ov011Chr *self) {
    Ov011Chr_Reset(self);
}

void func_ov011_02202130(Ov011Chr *self) {
    s32 key;
    u32 i;
    if (!self->b0) {
        return;
    }
    // Read through a const view (as CFLD did): a plain read lets MWCC reuse the b0 load.
    if (!((const Ov011Chr *)self)->b1) {
        if (self->anim->unk_00 < 0) {
            s32 r;
            self->b1 = 1;
            r = func_0206fef8(0x4812);
            self->model->unk_b4 = 0xffff;
            func_ov000_0219badc(self->model, self->anim, r);
            self->model->unk_c2_0 = 0;
            func_ov011_02200b88(&self->m28, self->anim, 0x4812);
        } else {
            func_ov000_0218f110(self->anim);
        }
        return;
    }
    key = self->mode;
    for (i = 0; i < 6; i++) {
        if (key == data_ov011_022074b0[i].key && *(s32 *)&data_ov011_022074b0[i].fn != 0) {
            (self->*data_ov011_022074b0[i].fn)();
            break;
        }
    }
    func_ov003_021d7dd0(self->s88);
    for (i = 0; i < 3; i++) {
        func_ov003_021d7dd0(self->s94[i]);
    }
    func_ov011_02200c30(&self->m28);
}

void func_ov011_02202260(Ov011Chr *self) {
    if (!self->b0) {
        return;
    }
    if (self->model != NULL) {
        Ov011Vec p;
        Ov011Vec sv;
        Ov011Vec sa;
        Ov011Vec q;
        Ov011Vec s;
        Ov011Obj *a = Ov011_FindActor(self->id);
        if (a != NULL) {
            p = a->pos;
            VEC_Add(&p, &self->off, &p);
            self->model->pos = p;
        }
        sv = self->model->pos;
        sa = self->model->scale;
        OV011_BLKCPY(&q, &sv);
        OV011_BLKCPY(&s, &sa);
        q.x += func_ov011_02200aac(self->s94[0], 0x19a);
        q.y += func_ov011_02200aac(self->s94[1], 0x19a);
        q.z += func_ov011_02200aac(self->s94[2], 0x19a);
        s.x += func_ov011_02200aac(self->s88, 0x19a);
        s.y = s.x;
        self->model->pos = q;
        self->model->scale = s;
        func_ov000_021903b4(self->model);
        self->model->pos = sv;
        self->model->scale = sa;
    }
    if (!self->m28.b0) {
        return;
    }
    if (!self->m28.b2) {
        return;
    }
    func_ov000_021903b4(self->m28.model);
}

void func_ov011_02202464(Ov011Chr *self) {
    if (self->b0) {
        self->unk_08 = 0;
        self->unk_24 = 0;
        self->mode = 1;
    }
}

void func_ov011_02202488(Ov011Chr *self, u16 v) {
    if (self->b0) {
        self->unk_24 = 0;
        self->mode = 3;
        self->unk_08 = v;
    }
}

void func_ov011_022024ac(Ov011Chr *self, u16 v) {
    if (self->b0 && v != 0) {
        self->unk_24 = 0;
        self->mode = 5;
        self->unk_08 = v;
    }
}


Ov011Vec func_ov011_022024d4(const Ov011Chr *self) {
    Ov011Vec v = data_ov011_02207438;
    if (self->b0) {
        Ov011Sub38 *m = self->model;
        v.x = m->pos.x;
        v.y = m->pos.y;
        v.z = m->pos.z;
    }
    return v;
}

}
}  // namespace m_02201c18

// ---- merged from ov011_02202538.cpp
namespace m_02202538 {
struct Ov011Chr {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    u16 id;
    s32 mode;
    Ov011Vec off;
    Ov011Anim *anim;
    Ov011Sub38 *model;
    Ov011V *unk_24;
    Ov011Model2 m28;
    u8 s88[0xc];
    u8 s94[3][0xc];
};

extern "C" {

extern Ov011Vec data_ov011_02207474;
extern const Ov011Vec data_ov011_02207480;
extern u8 data_ov011_0220748c[];
extern void *data_0214a420;
s32 FX_Div(s32 a, s32 b);
Ov011V *func_02065f88(s32 id, Ov011Vec *v);
BOOL func_02065748(void *mgr, void *p);
void MI_Copy36B(const void *src, void *dst);

// unk_06 is read through a const view; a plain read schedules differently.
static inline s32 Ov011_Progress(Ov011Chr *c, s32 n) {
    return FX_Div(n << 12, ((const Ov011Chr *)c)->unk_06 << 12);
}

void func_ov011_02202538(Ov011Chr *self) {
    switch (self->mode) {
    case 1: {
        Ov011Vec s;
        Ov011Vec pos;
        Ov011Vec c;
        Ov011Vec t;
        s32 r = Ov011_Progress(self, self->unk_06);
        s32 lo = self->unk_04;
        s32 hi = self->unk_02;
        s32 v = lo + Ov011_FxMul(hi - lo, r);
        v = v > hi ? hi : (v < lo ? lo : v);
        OV011_BLKCPY(&t, &data_ov011_02207474);
        t.x = v;
        t.y = v;
        OV011_BLKCPY(&s, &t);
        self->model->scale = s;
        self->model->unk_c2_0 = 1;
        pos = self->model->pos;
        OV011_BLKCPY(&c, &data_ov011_02207480);
        self->unk_24 = func_02065f88(0x38a, &pos);
        self->unk_24->v10(&c);
        self->unk_24->v24(0, -0x14cd, 0);
        self->mode = 2;
        break;
    }
    case 2:
        if (!func_02065748(data_0214a420, self->unk_24)) {
            self->mode = 0;
            self->unk_24 = NULL;
        }
        break;
    }
}


static inline BOOL Ov011Model2_Idle(Ov011Model2 *m) {
    BOOL r = FALSE;
    if (m->b0) {
        if (!m->b2) {
            r = TRUE;
        }
    }
    return r;
}

void func_ov011_022026b4(Ov011Chr *self) {
    switch (self->mode) {
    case 3: {
        Ov011Vec s;
        Ov011Vec pos;
        Ov011Vec t;
        s16 a;
        s16 b;
        s32 r = FX_Div(self->unk_08 << 12, ((const Ov011Chr *)self)->unk_06 << 12);
        s32 lo = self->unk_04;
        s32 hi = self->unk_02;
        s32 v = lo + Ov011_FxMul(hi - lo, r);
        v = v > hi ? hi : (v < lo ? lo : v);
        OV011_BLKCPY(&t, &data_ov011_02207474);
        t.x = v;
        t.y = v;
        OV011_BLKCPY(&s, &t);
        self->model->scale = s;
        self->model->unk_c2_0 = 1;
        pos = self->model->pos;
        self->unk_24 = func_02065f88(0x648, &pos);
        self->unk_24->v14(0x2000, 0x2000, 0x2000);
        b = s.x + 0x1500;
        a = s.x;
        if (self->m28.b0) {
            self->m28.b1 = 1;
            self->m28.b2 = 0;
            MI_Copy36B(data_ov011_0220748c, self->m28.model->mtx);
            self->m28.model->pos = pos;
            self->m28.unk_02 = a;
            self->m28.unk_04 = b;
        }
        self->mode = 4;
        break;
    }
    case 4: {
        BOOL done = func_02065748(data_0214a420, self->unk_24) ? FALSE : TRUE;
        if (done) {
            done = Ov011Model2_Idle(&self->m28);
        }
        if (done) {
            self->mode = 0;
            self->unk_24 = NULL;
        }
        break;
    }
    }
}

void func_ov011_022028a8(Ov011Chr *self) {
    switch (self->mode) {
    case 5: {
        Ov011Vec s;
        Ov011Vec c;
        Ov011Vec pos;
        Ov011Vec t;
        s32 r;
        s32 lo;
        s32 hi;
        s32 v;
        if (self->unk_08 <= 1) {
            self->model->unk_c2_0 = 0;
            self->mode = 0;
            return;
        }
        self->model->unk_c2_0 = 1;
        r = FX_Div((s16)(self->unk_08 - 1) << 12, self->unk_06 << 12);
        lo = self->unk_04;
        hi = self->unk_02;
        v = lo + Ov011_FxMul(hi - lo, r);
        v = v > hi ? hi : (v < lo ? lo : v);
        OV011_BLKCPY(&t, &data_ov011_02207474);
        t.x = v;
        t.y = v;
        OV011_BLKCPY(&s, &t);
        self->model->scale = s;
        OV011_BLKCPY(&c, &data_ov011_0220742c);
        pos = self->model->pos;
        self->unk_24 = func_02065f88(0x579, &pos);
        self->unk_24->v10(&c);
        self->mode = 6;
        break;
    }
    case 6:
        if (!func_02065748(data_0214a420, self->unk_24)) {
            self->mode = 0;
            self->unk_24 = NULL;
        }
        break;
    }
}

}
}  // namespace m_02202538

// ---- merged from ov011_02202a38.cpp
namespace m_02202a38 {
struct Ov011TwA {
    Ov011V *vt;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_05;
    s16 speed;
    s32 t;
    Ov011Vec from;
    Ov011Vec to;
    Ov011Vec cur;
};

struct Ov011TwB {
    Ov011V *vt;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_05;
    s16 speed;
    s32 dist;
    Ov011Vec cur;
    Ov011Vec to;
};


extern "C" {

extern u16 data_ov011_02207f00;
extern u8 data_ov011_022079d0[];
extern u8 data_ov011_022079b0[];
extern u8 data_ov011_022074f8[];
s32 VEC_Distance(const Ov011Vec *a, const Ov011Vec *b);
s32 FX_Div(s32 a, s32 b);
void VEC_MultAdd(s32 scale, const Ov011Vec *dir, const Ov011Vec *base, Ov011Vec *out);
s32 VEC_Mag(const Ov011Vec *v);
void VEC_Add(const Ov011Vec *a, const Ov011Vec *b, Ov011Vec *out);
s32 func_0203db40(void *p);
void func_ov000_02190a80(void *a, s32 b);
void func_ov003_021d112c(void *p);
BOOL func_020621c4(void);
void func_ov003_021d6bac(void *p, void *data);

void func_ov011_02202a38(void) {
    data_ov011_02207f00 += 0x51e;
}

Ov011TwA *Ov011Vt_022079d0_Ctor(Ov011TwA *self) {
    self->vt = (Ov011V *)data_ov011_022079d0;
    self->b0 = 0;
    return self;
}

Ov011TwA *Ov011Vt_022079d0_Dtor(Ov011TwA *self) {
    self->vt = (Ov011V *)data_ov011_022079d0;
    ((Ov011V *)self)->v08();
    return self;
}

Ov011TwA *Ov011Vt_022079d0_DtorDelete(Ov011TwA *self) {
    self->vt = (Ov011V *)data_ov011_022079d0;
    ((Ov011V *)self)->v08();
    Heap_Free(self);
    return self;
}

BOOL func_ov011_02202ac8(Ov011TwA *self, const Ov011Vec *to, const Ov011Vec *from, s32 speed, u8 loop) {
    self->b0 = 1;
    self->b1 = loop;
    self->t = 0;
    self->from = *from;
    self->to = *to;
    self->cur = *from;
    self->speed = FX_Div(speed, VEC_Distance(to, from));
    return TRUE;
}

void func_ov011_02202b5c(Ov011TwA *self) {
    if (self->b0) {
        self->b0 = 0;
    }
}

static inline void Ov011_Lerp(s32 t, const Ov011Vec *a, const Ov011Vec *b, Ov011Vec *out) {
    Ov011Vec d;
    d.x = b->x - a->x;
    d.y = b->y - a->y;
    d.z = b->z - a->z;
    VEC_MultAdd(t, &d, a, out);
}

void func_ov011_02202b74(Ov011TwA *self) {
    if (!self->b0) {
        return;
    }
    self->t += self->speed;
    if (!self->b1 && self->t >= 0x1000) {
        self->t = 0x1000;
        return;
    }
    Ov011_Lerp(self->t, &self->from, &self->to, &self->cur);
}

Ov011Vec *func_ov011_02202c10(Ov011TwA *self) {
    Ov011Vec *r = NULL;
    if (self->b0) {
        r = &self->cur;
    }
    return r;
}

BOOL func_ov011_02202c2c(Ov011TwA *self) {
    if (self->b0 && self->t >= 0x1000) {
        return TRUE;
    }
    return FALSE;
}

static inline void Ov011TwB_SetBoth(Ov011TwB *t, const Ov011Vec *src) {
    s32 x;
    s32 y;
    s32 z;
    x = src->x;
    t->cur.x = x;
    y = src->y;
    t->cur.y = y;
    z = src->z;
    t->cur.z = z;
    t->to.x = x;
    t->to.y = y;
    t->to.z = z;
}

Ov011TwB *Ov011Vt_022079b0_Ctor(Ov011TwB *self) {
    self->vt = (Ov011V *)data_ov011_022079b0;
    self->b0 = 0;
    self->b1 = 0;
    self->speed = 0;
    Ov011TwB_SetBoth(self, &data_ov011_02207438);
    return self;
}

Ov011TwB *Ov011Vt_022079b0_Dtor(Ov011TwB *self) {
    self->vt = (Ov011V *)data_ov011_022079b0;
    ((Ov011V *)self)->v08();
    return self;
}

Ov011TwB *Ov011Vt_022079b0_DtorDelete(Ov011TwB *self) {
    self->vt = (Ov011V *)data_ov011_022079b0;
    ((Ov011V *)self)->v08();
    Heap_Free(self);
    return self;
}

BOOL func_ov011_02202d04(Ov011TwB *self, const Ov011Vec *to, const Ov011Vec *from, s16 speed) {
    self->b0 = 1;
    self->cur = *from;
    self->to = *to;
    self->speed = speed;
    self->dist = Ov011_FxMul(VEC_Distance(&self->to, &self->cur), 0x14);
    return TRUE;
}

void func_ov011_02202d88(Ov011TwB *self) {
    if (!self->b0) {
        return;
    }
    self->b0 = 0;
    self->b1 = 0;
    self->speed = 0;
    Ov011TwB_SetBoth(self, &data_ov011_02207438);
}

void func_ov011_02202de0(Ov011TwB *self) {
    Ov011Vec d;
    s32 len;
    if (!self->b0) {
        return;
    }
    if (self->b1) {
        return;
    }
    d.x = self->to.x - self->cur.x;
    d.y = self->to.y - self->cur.y;
    d.z = self->to.z - self->cur.z;
    len = VEC_Mag(&d);
    if (len < 0) {
        len = -len;
    }
    if (len <= self->dist) {
        self->cur = self->to;
        self->b1 = 1;
    } else {
        VEC_MultAdd(self->speed, &d, &self->cur, &self->cur);
    }
}

Ov011Vec *func_ov011_02202ea4(Ov011TwB *self) {
    return self->b0 ? &self->cur : NULL;
}

u32 func_ov011_02202ebc(Ov011TwB *self) {
    return self->b1;
}

u32 func_ov011_02202ecc(Ov011TwB *self) {
    return self->b0;
}

void Ov011Mov_Init(Ov011Mov *self) {
    self->active = 0;
    self->accel = 0;
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = 0;
    self->vel.x = 0;
    self->vel.y = 0;
    self->vel.z = 0;
}

void func_ov011_02202f04(Ov011Mov *self) {
    if (!self->active) {
        return;
    }
    self->active = 0;
    self->accel = 0;
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = 0;
    self->vel.x = 0;
    self->vel.y = 0;
    self->vel.z = 0;
}

BOOL Ov011Mov_Start(Ov011Mov *self, const Ov011Vec *pos, const Ov011Vec *vel, s32 scale, s32 accel) {
    self->active = 1;
    self->pos = *pos;
    self->vel.x = Ov011_FxMul(vel->x, scale);
    self->vel.y = Ov011_FxMul(vel->y, scale);
    self->vel.z = Ov011_FxMul(vel->z, scale);
    self->accel = accel;
    return TRUE;
}

void func_ov011_02202fbc(Ov011Mov *self) {
    if (!self->active) {
        return;
    }
    self->active = 0;
    self->accel = 0;
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = 0;
    self->vel.x = 0;
    self->vel.y = 0;
    self->vel.z = 0;
}

void Ov011Mov_Update(Ov011Mov *self) {
    if (!self->active) {
        return;
    }
    self->vel.y += self->accel;
    VEC_Add(&self->pos, &self->vel, &self->pos);
}

Ov011Vec *Ov011Mov_GetPos(Ov011Mov *self) {
    Ov011Vec *r = NULL;
    if (self->active) {
        r = &self->pos;
    }
    return r;
}

void func_ov011_02203040(Ov011Obj *self) {
    if (self->unk_38 == NULL) {
        return;
    }
    func_ov000_02190a80(self->unk_38, func_0203db40(self->unk_24));
}

void func_ov011_0220306c(void *self) {
}

void func_ov011_02203070(void *self) {
}

void func_ov011_02203074(void *self) {
}

void func_ov011_02203078(void *self) {
}

void func_ov011_0220307c(void *self) {
}

void func_ov011_02203080(void *self) {
}

void func_ov011_02203084(void *self) {
}

void Ov011ActVt_02207b34_Start(void *self) {
    func_ov003_021d112c(self);
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov011_022074f8);
    }
}

}
}  // namespace m_02202a38
