#include "ov015/ov015.h"

extern "C" {

extern u8 Ov015Fish_vtbl[];
void Ov015Fish_DtorBase(Ov015Fish *p);
void HitSphere_Unlink_0203f2b8(void *p);
void *Shadow_DtorBase(void *p);
void *Model0218fe1c_FreeAnims(void *p);
void *ResSet_ReleaseAll(void *p);
void Ov015FishInfo_Dtor(Ov015FishInfo *p);
BOOL Ov015Obj292c_Setup(Ov015Obj292c *self);
void Ov015Obj292c_HideMarker(Ov015Obj292c *self);
void *Model0218fe1c_SetAnimFrame(void *a, s32 b);
BOOL Ov015Fish_Update(Ov015Fish *self, s32 a);
void Ov015Fish_SetNextState(Ov015Fish *self, s32 a, s32 b);
Ov015FishState40 *Ov015FishState40_Ctor(Ov015FishState40 *self);

extern u8 Ov015Obj292c_vtbl[];
extern u8 Ov015Obj290_vtbl[];
void Ov015Obj292c_Init(Ov015Obj292c *self);
void Ov015Obj292c_Load(Ov015Obj292c *self);
int Ov015Obj292c_IsLoaded(Ov015Obj292c *self);
void *ResSet_Init(void *p);
void *Model0218fe1c_Init(void *p);
void Ov015Obj290_Reset(Ov015Obj290 *self);
void Ov015Obj30_Prepare(Ov015Obj30 *self);
BOOL Ov015Obj30_WaitThrow(Ov015Obj30 *self);
BOOL Ov015Obj30_WaitHit(Ov015Obj30 *self);
Ov015FishState08 *Ov015FishState08_Ctor(Ov015FishState08 *self);
s32 func_ov015_02209fb8(s32 x);
void Ov015List_Remove(Ov015List *self, Ov015Fish *fish);
void Ov015CamPair_SetMode(Ov015CamPair *self, s32 mode, const void *v);
void Ov015Fish_GetFrontPos(Ov015Fish *self, void *out);

static inline s32 Ov015_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

BOOL Ov015Obj30_Run(Ov015Obj30 *self, Ov015Ship *a1, Ov015CamPair *a2, Ov015List *a3, Ov015Info38 *a4) {
    BOOL ret = TRUE;
    self->info = a4;
    self->ship = a1;
    self->cam = a2;
    self->fishList = a3;
    switch (self->step) {
    case 0: {
        // One local for both allocations, as in the original.
        VObj *o = (VObj *)Heap_Alloc(0x34);
        if (o != NULL) {
            SET_VT(o, Ov015Obj292c_vtbl);
            Ov015Obj292c_Init((Ov015Obj292c *)o);
        }
        self->unk_10 = (Ov015Obj292c *)o;
        Ov015Obj292c_Load((Ov015Obj292c *)o);
        o = (VObj *)Heap_Alloc(0x290);
        if (o != NULL) {
            SET_VT(o, Ov015Obj290_vtbl);
            ResSet_Init(&((Ov015Obj290 *)o)->res);
            Model0218fe1c_Init(&((Ov015Obj290 *)o)->model);
            Ov015Obj290_Reset((Ov015Obj290 *)o);
        }
        self->unk_14 = (Ov015Obj290 *)o;
        o->vfunc_0c();
        self->step = 1;
    }
    case 1: {
        bool a = Ov015Obj292c_IsLoaded(self->unk_10) & 1;
        bool ok = a & self->unk_14->vfunc_10();
        if (!ok) {
            break;
        }
        self->step = 2;
    }
    case 2:
        Ov015Obj30_Prepare(self);
        self->step = 3;
    case 3:
        if (!Ov015Obj30_WaitThrow(self)) {
            break;
        }
        self->step = 4;
    case 4:
        if (!Ov015Obj30_WaitHit(self)) {
            break;
        }
        if (self->fish != NULL) {
            u8 *m;
            Ov015Fish *obj;
            Ov015Node *n;
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
            Ov015Shared_SetCatch(gOv015Shared, (self->fish)->info.id);
            n = self->fishList->head;
            while (n != NULL) {
                obj = n->fish;
                n = n->next;
                if (obj != self->fish) {
                    Ov015List_Remove(self->fishList, obj);
                    HEAP_PUSH(saved);
                    if (obj != NULL) {
                        if (obj != NULL) {
                            obj->vfunc_04();
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
            Ov015Node *n;
            Ov015CamPair_SetMode(self->cam, 7, &self->unk_10->pos);
            for (n = self->fishList->head; n != NULL; n = n->next) {
                Ov015Fish_Update(n->fish, 1);
            }
            if (self->unk_14->vfunc_18() == 0) {
                done = TRUE;
            }
        }
        if (done) {
            self->ship->unk_d3c = 2;
            self->unk_14->vfunc_08();
            self->step = 3;
        }
        break;
    }
    case 6: {
        BOOL done = FALSE;
        if (self->unk_0c == 0) {
            Ov015Vec v;
            Ov015Fish_GetFrontPos(self->fish, &v);
            Ov015CamPair_SetMode(self->cam, 8, &v);
            self->unk_14->vfunc_18();
            Ov015Fish_Update(self->fish, 1);
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
    SET_VT(self, Ov015Fish_vtbl);
    Ov015Fish_DtorBase(self);
    HitSphere_Unlink_0203f2b8(&self->hit);
    Shadow_DtorBase(&self->shadow);
    Model0218fe1c_FreeAnims(&self->model2);
    ResSet_ReleaseAll(&self->res2);
    Model0218fe1c_FreeAnims(&self->model);
    ResSet_ReleaseAll(&self->res);
    Ov015FishInfo_Dtor(&self->info);
    Heap_Free(self);
    return self;
}

void *Ov015Shadow_Dtor(Ov015Shadow *self) {
    Shadow_DtorBase(self);
    return self;
}

void Ov015Obj30_Prepare(Ov015Obj30 *self) {
    Ov015Node *n;
    s32 cnt;
    s32 i;
    Ov015Obj292c_Setup(self->unk_10);
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
    Ov015Obj292c_HideMarker(self->unk_10);
    self->unk_14->animSpeed = self->info->unk_0c;
    self->unk_14->vfunc_14();
    self->ship->unk_d3c = 2;
    n = self->fishList->head;
    cnt = self->fishList->count;
    for (; n != NULL; n = n->next, i++) {
        Ov015Fish *obj = n->fish;
        u8 *m = (u8 *)Heap_Alloc(0x40);
        s32 q;
        if (m != NULL) m = (u8 *)Ov015FishState40_Ctor((Ov015FishState40 *)m);
        Ov015Fish_SetNextState(obj, (s32)m, 5);
        q = FX_Div(i << 12, cnt << 12);
        obj->pos.x = FX_Mul(q, 0x64000) - 0x32000;
        obj->pos.y = -0x32000;
        obj->pos.z = FX_Mul(q, -0x41000) - 0x4b000;
        Model0218fe1c_SetAnimFrame(&obj->model, FX_Mul(q, 0x3c000));
        obj->minX = -0x32000;
        obj->maxX = 0x32000;
        obj->maxZ = -0x4b000;
        obj->minZ = -0x8c000;
        Ov015Fish_Update(obj, 1);
    }
}


BOOL Ov015Fish_HitTest(Ov015Fish *self, void *a);
void Ov015Obj292c_ShowMarker(Ov015Obj292c *self);
void func_ov015_02212250(Ov015Obj292c *self, s32 a);
void Ov015Ship_Update(Ov015Ship *p);

BOOL Ov015Obj30_WaitThrow(Ov015Obj30 *self) {
    BOOL r = FALSE;
    Ov015Fish *found;
    Ov015Node *n;
    Ov015CamPair_SetMode(self->cam, 7, &self->unk_10->pos);
    if (self->unk_0c != 0) return r;
    if (gPad->trig & 1) {
        Ov015Vec v = self->unk_10->pos;
        EffectObj *e;
        self->unk_14->vfunc_28(&v, r);
        r = TRUE;
        self->ship->unk_d3c = r;
        // m[3] as a byte offset from the matrix: a field path folds to one constant and changes the code.
        e = Effect_SpawnId(0x325, &FLD(Ov015Vec, &self->ship->nodeMtx, 0x24));
        e->unk_d4 = 3;
        SndMgr_PlayVolume(gSndMgr, 0x19, -1, -1, -1);
    }
    found = NULL;
    n = self->fishList->head;
    while (n != NULL) {
        Ov015Fish *obj = n->fish;
        Ov015Vec v;
        n = n->next;
        v = self->unk_10->pos;
        if (Ov015Fish_HitTest(obj, &v)) {
            found = obj;
            break;
        }
    }
    if (found != NULL) {
        s32 d = Ov015_FxMul64(found->scale.x, 0x14000);
        Ov015Vec t(found->pos);
        t.y += d;
        if (t.y < 0) t.y = 0;
        self->unk_10->unk_24 = t;
        Ov015Obj292c_ShowMarker(self->unk_10);
    } else {
        Ov015Obj292c_HideMarker(self->unk_10);
    }
    func_ov015_02212250(self->unk_10, 0);
    for (n = self->fishList->head; n != NULL; n = n->next) {
        Ov015Fish_Update(n->fish, 1);
    }
    Ov015Ship_Update(self->ship);
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
