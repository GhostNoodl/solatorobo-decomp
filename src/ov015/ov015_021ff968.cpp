#include "ov015/ov015.h"

extern "C" {

extern u8 data_ov015_022128fc[];
void func_ov015_02209270(Ov015Fish *p);
void func_0203f2b8(void *p);
void *func_ov000_02191b04(void *p);
void *func_ov000_0218fee4(void *p);
void *func_ov000_0218ea20(void *p);
void func_ov015_0220900c(void *p);
BOOL func_ov015_022121b4(Ov015Obj292c *self);
void func_ov015_022123c4(Ov015Obj292c *self);
void *func_ov000_02191318(void *a, s32 b);
BOOL func_ov015_02209790(Ov015Fish *self, s32 a);
void Ov015Fish_SetNextState(Ov015Fish *self, s32 a, s32 b);
Ov015FishState40 *Ov015FishState40_Ctor(Ov015FishState40 *self);

extern u8 data_ov015_0221292c[];
extern u8 data_ov015_022132e0[];
extern void *data_ov015_02213368;
void func_ov015_022120c0(Ov015Obj292c *self);
void func_ov015_02212180(Ov015Obj292c *self);
int func_ov015_0221219c(Ov015Obj292c *self);
void *func_ov000_0218e9c4(void *p);
void *func_ov000_0218fe1c(void *p);
void func_ov015_022119e8(Ov015Obj290 *self);
void func_ov015_021ff9e8(Ov015Obj30 *self);
BOOL func_ov015_021ffb90(Ov015Obj30 *self);
BOOL func_ov015_021ffdd4(Ov015Obj30 *self);
Ov015FishState08 *Ov015FishState08_Ctor(Ov015FishState08 *self);
s32 func_ov015_02209fb8(s32 x);
void func_ov015_02211334(void *a, u16 id);
void func_ov015_022029d4(void *list, void *obj);
void func_ov015_021fd00c(Ov015CamPair *self, s32 mode, const void *v);
void func_ov015_0220a058(Ov015Fish *self, void *out);

static inline s32 Ov015_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

BOOL func_ov015_021ff4a0(Ov015Obj30 *self, Ov015Ship *a1, Ov015CamPair *a2, Ov015List *a3, Ov015Info38 *a4) {
    BOOL ret = TRUE;
    self->info = a4;
    self->ship = a1;
    self->cam = a2;
    self->fishList = a3;
    switch (self->step) {
    case 0: {
        // One local for both allocations, as in the original.
        u8 *o = (u8 *)Heap_Alloc(0x34);
        if (o != NULL) {
            SET_VT(o, data_ov015_0221292c);
            func_ov015_022120c0((Ov015Obj292c *)o);
        }
        self->unk_10 = (Ov015Obj292c *)o;
        func_ov015_02212180((Ov015Obj292c *)o);
        o = (u8 *)Heap_Alloc(0x290);
        if (o != NULL) {
            SET_VT(o, data_ov015_022132e0);
            func_ov000_0218e9c4(&((Ov015Obj290 *)o)->res);
            func_ov000_0218fe1c(&((Ov015Obj290 *)o)->model);
            func_ov015_022119e8((Ov015Obj290 *)o);
        }
        self->unk_14 = (Ov015Obj290 *)o;
        VCALL(o)->v0c();
        self->step = 1;
    }
    case 1: {
        bool a = func_ov015_0221219c(self->unk_10) & 1;
        bool ok = a & VCALL(self->unk_14)->v10();
        if (!ok) {
            break;
        }
        self->step = 2;
    }
    case 2:
        func_ov015_021ff9e8(self);
        self->step = 3;
    case 3:
        if (!func_ov015_021ffb90(self)) {
            break;
        }
        self->step = 4;
    case 4:
        if (!func_ov015_021ffdd4(self)) {
            break;
        }
        if (self->fish != NULL) {
            u8 *m;
            Ov015Fish *obj;
            u8 *n;
            void *saved;
            m = (u8 *)Heap_Alloc(8);
            if (m != NULL) {
                m = (u8 *)Ov015FishState08_Ctor((Ov015FishState08 *)m);
            }
            Ov015Fish_SetNextState(self->fish, (s32)m, 6);
            (self->fish)->drawMode = 0;
            {
                Ov015Fish *q = self->fish;
                s32 x = q->pos.x;
                s32 t = FX_Div(q->pos.z + 0x37000, -0x73000) - a4->unk_14;
                if (t < 0x266) {
                    t = 0x266;
                }
                if (t > 0xa66) {
                    t = 0xa66;
                }
                q = self->fish;
                q->pos.x = x;
                q->pos.y = -0x32000;
                q->pos.z = Ov015_FxMul64(t, -0x73000) - 0x37000;
            }
            data_ov015_0221332c.unk_00 = func_ov015_02209fb8((self->fish)->pos.z);
            func_ov015_02211334(data_ov015_02213368, (self->fish)->info.id);
            n = FLD(u8 *, self->fishList, 0x4);
            while (n != NULL) {
                obj = FLD(Ov015Fish *, n, 0x4);
                n = FLD(u8 *, n, 0xc);
                if (obj != self->fish) {
                    func_ov015_022029d4(self->fishList, obj);
                    HEAP_PUSH(saved);
                    if (obj != NULL) {
                        if (obj != NULL) {
                            VCALL(obj)->v04();
                        }
                    }
                    HEAP_POP(saved);
                }
            }
            {
                Ov015Fish *q = self->fish;
                Ov015Ship *d = self->ship;
                d->unk_d4c.x = q->pos.x;
                d->unk_d4c.y = q->pos.y;
                d->unk_d4c.z = q->pos.z;
            }
            HEAP_PUSH(saved);
            DELETE_V(self->unk_10);
            HEAP_POP(saved);
            self->step = 6;
        } else {
            self->step = 5;
        }
        break;
    case 5: {
        BOOL done = FALSE;
        if (self->unk_0c == 0) {
            u8 *n;
            func_ov015_021fd00c(self->cam, 7, &self->unk_10->pos);
            for (n = FLD(u8 *, self->fishList, 0x4); n != NULL; n = FLD(u8 *, n, 0xc)) {
                func_ov015_02209790(FLD(Ov015Fish *, n, 0x4), 1);
            }
            if (VCALL(self->unk_14)->v18() == 0) {
                done = TRUE;
            }
        }
        if (done) {
            self->ship->unk_d3c = 2;
            VCALL(self->unk_14)->v08();
            self->step = 3;
        }
        break;
    }
    case 6: {
        BOOL done = FALSE;
        if (self->unk_0c == 0) {
            Ov015Vec v;
            func_ov015_0220a058(self->fish, &v);
            func_ov015_021fd00c(self->cam, 8, &v);
            VCALL(self->unk_14)->v18();
            func_ov015_02209790(self->fish, 1);
            if ((self->fish)->stateId == 2) {
                done = TRUE;
            }
        }
        if (done) {
            void *saved;
            HEAP_PUSH(saved);
            DELETE_V(self->unk_10);
            HEAP_POP(saved);
            HEAP_PUSH(saved);
            DELETE_V(self->unk_14);
            HEAP_POP(saved);
            self->step = 7;
        }
        break;
    }
    case 7:
        ret = FALSE;
        break;
    }
    self->ship = NULL;
    self->cam = NULL;
    self->fishList = NULL;
    self->info = NULL;
    if (--self->timer <= 0) {
        self->timer = 0;
    }
    return ret;
}

void *Ov015Fish_DtorDelete(Ov015Fish *self) {
    SET_VT(self, data_ov015_022128fc);
    func_ov015_02209270(self);
    func_0203f2b8(&self->hit);
    func_ov000_02191b04(&self->shadow);
    func_ov000_0218fee4(&self->model2);
    func_ov000_0218ea20(&self->res2);
    func_ov000_0218fee4(&self->model);
    func_ov000_0218ea20(&self->res);
    func_ov015_0220900c(&self->info);
    Heap_Free(self);
    return self;
}

void *func_ov015_021ff9d4(void *self) {
    func_ov000_02191b04(self);
    return self;
}

void func_ov015_021ff9e8(Ov015Obj30 *self) {
    u8 *n;
    s32 cnt;
    s32 i;
    func_ov015_022121b4(self->unk_10);
    {
        Ov015Obj292c *p = self->unk_10;
        i = 0;
        p->pos.x = 0;
        p->pos.y = 0x1800;
        p->pos.z = 0x1800 - 0x72000;
    }
    {
        s32 v = self->info->unk_10;
        Ov015Obj292c *p = self->unk_10;
        p->scale.x = v;
        p->scale.y = v;
        p->scale.z = v;
    }
    self->unk_10->unk_30 = self->info->unk_08;
    func_ov015_022123c4(self->unk_10);
    self->unk_14->animSpeed = self->info->unk_0c;
    VCALL(self->unk_14)->v14();
    self->ship->unk_d3c = 2;
    n = FLD(u8 *, self->fishList, 0x4);
    cnt = FLD(s32, self->fishList, 0xc);
    for (; n != NULL; n = FLD(u8 *, n, 0xc), i++) {
        Ov015Fish *obj = FLD(Ov015Fish *, n, 0x4);
        u8 *m = (u8 *)Heap_Alloc(0x40);
        s32 q;
        if (m != NULL) m = (u8 *)Ov015FishState40_Ctor((Ov015FishState40 *)m);
        Ov015Fish_SetNextState(obj, (s32)m, 5);
        q = FX_Div(i << 12, cnt << 12);
        obj->pos.x = FX_Mul(q, 0x64000) - 0x32000;
        obj->pos.y = -0x32000;
        obj->pos.z = FX_Mul(q, -0x41000) - 0x4b000;
        func_ov000_02191318(&obj->model, FX_Mul(q, 0x3c000));
        obj->minX = -0x32000;
        obj->maxX = 0x32000;
        obj->maxZ = -0x4b000;
        obj->minZ = -0x8c000;
        func_ov015_02209790(obj, 1);
    }
}


extern u8 *data_02097dc8;
BOOL func_ov015_0220a028(Ov015Fish *self, void *a);
void func_ov015_0221234c(Ov015Obj292c *self);
void func_ov015_02212250(Ov015Obj292c *self, s32 a);
void func_ov015_02207c30(Ov015Ship *p);

BOOL func_ov015_021ffb90(Ov015Obj30 *self) {
    BOOL r = FALSE;
    Ov015Fish *found;
    u8 *n;
    func_ov015_021fd00c(self->cam, 7, &self->unk_10->pos);
    if (self->unk_0c != 0) return r;
    if (FLD(u16, data_02097dc8, 0x12) & 1) {
        Ov015Vec v = self->unk_10->pos;
        EffectObj *e;
        VCALL(self->unk_14)->v28(&v, r);
        r = TRUE;
        self->ship->unk_d3c = r;
        // m[3] as a byte offset from the matrix: a field path folds to one constant and changes the code.
        e = func_02065f88(0x325, &FLD(Ov015Vec, &self->ship->nodeMtx, 0x24));
        e->unk_d4 = 3;
        func_02049a48(data_02097e4c, 0x19, -1, -1, -1);
    }
    found = NULL;
    n = FLD(u8 *, self->fishList, 0x4);
    while (n != NULL) {
        Ov015Fish *obj = FLD(Ov015Fish *, n, 0x4);
        Ov015Vec v;
        n = FLD(u8 *, n, 0xc);
        v = self->unk_10->pos;
        if (func_ov015_0220a028(obj, &v)) {
            found = obj;
            break;
        }
    }
    if (found != NULL) {
        s32 d = Ov015_FxMul64(found->scale.x, 0x14000);
        Ov015Vec t(*(Ov015Vec *)&found->pos);
        t.y += d;
        if (t.y < 0) t.y = 0;
        FLD(Ov015Vec, self->unk_10, 0x24) = t;
        func_ov015_0221234c(self->unk_10);
    } else {
        func_ov015_022123c4(self->unk_10);
    }
    func_ov015_02212250(self->unk_10, 0);
    for (n = FLD(u8 *, self->fishList, 0x4); n != NULL; n = FLD(u8 *, n, 0xc)) {
        func_ov015_02209790(FLD(Ov015Fish *, n, 0x4), 1);
    }
    func_ov015_02207c30(self->ship);
    {
        Ov015Obj292c *q = self->unk_10;
        Ov015Ship *d = self->ship;
        d->unk_d4c.x = q->pos.x;
        d->unk_d4c.y = q->pos.y;
        d->unk_d4c.z = q->pos.z;
    }
    {
        Ov015Ship *dd = self->ship;
        Ov015Obj292c *qq = self->unk_10;
        s32 dx = dd->pos.x;
        s32 dz = dd->pos.z;
        u16 a;
        dx = qq->pos.x - dx;
        dz = qq->pos.z - dz;
        a = FX_Atan2(dx, dz);
        Ov015Ship *d;
        d = self->ship;
        d->rotX = 0;
        d->rotY = a;
        d->rotZ = 0;
    }
    return r;
}

}
