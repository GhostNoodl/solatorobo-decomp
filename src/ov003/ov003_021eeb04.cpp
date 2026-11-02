#include "types.h"
#include "ov000/ActorParts.h"
#include "ov003/ActEx.h"
#include "ov003/ActorApi.h"
#include "ov003/Unit.h"
#include "Main/Sys/SysState.h"


extern "C" {

extern void *data_ov000_021ccd64;
extern u8 data_ov003_021f9e10[];
extern char data_ov003_021f9fd6[];
extern char data_ov003_021f9fd0[];
extern void Heap_Free(void *p);
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);
extern BOOL func_ov000_021903b4(void *anim);
extern void *func_0203db40(void *p);
extern void func_ov000_02190a80(void *a, void *b);
extern void *Heap_Alloc(u32 size);
extern ActorSub48 *func_ov000_021985e8(void *p);
extern void func_ov000_02198c8c(ActorSub48 *p, u16 id);
extern void HitSphere_Link(ActorSub48 *p);
extern Model0218fe1c *func_ov000_0218fe1c(void *p);
extern BOOL func_ov000_0218ffdc(Model0218fe1c *anim, void *res, s32 a, s32 b);
extern void func_ov000_02190758(Model0218fe1c *anim, void *p, s32 a);
extern BOOL func_ov000_02198360(ActorSub40 *p, u8 a, BOOL b);
extern BOOL func_ov000_02190cb0(void *p, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *p);
extern void func_ov000_021911c8(void *p, s32 a);

static inline void Ov003Bridge_Dtor(Ov003Bridge *self) {
    Model0218fe1c *p;
    void *old;
    *(void **)self = data_ov003_021f9e10;
    old = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    p = self->anim;
    if (p != NULL) {
        if (p != NULL) {
            func_ov000_0218fee4(p);
            Heap_Free(p);
        }
        self->anim = NULL;
    }
    data_02097dd0->cur = old;
    func_ov000_0219429c(self);
}

Ov003Bridge *Ov003ActVt_021f9e10_Dtor(Ov003Bridge *self) {
    Ov003Bridge_Dtor(self);
    return self;
}

Ov003Bridge *Ov003ActVt_021f9e10_DtorDelete(Ov003Bridge *self) {
    Ov003Bridge_Dtor(self);
    Heap_Free(self);
    return self;
}

void Ov003ActVt_021f9e10_Init(Ov003Bridge *self) {
    Ov003Unit *u;
    func_ov000_0219433c(self);
    u = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_0 = 0;
    }
    func_ov000_02197d80(self);
    s16 kind;
    self->unk_93_1 = 0;
    kind = self->unk_18;
    if (self->unk_1a == 0) {
        if (kind == 1 || kind == 2 || (u16)(s16)(kind - 5) <= 1) {
            self->unk_93_1 = 1;
        }
    } else if ((u16)(s16)(kind - 3) <= 3) {
        self->unk_93_1 = 1;
    }
    self->anim = NULL;
}

BOOL Ov003ActVt_021f9e10_Draw(Ov003Bridge *self) {
    BOOL r = func_ov000_02194c08(self);
    if (r && self->anim != NULL) {
        func_ov000_021903b4(self->anim);
    }
    return r;
}

void Ov003Bridge_Animate(Ov003Bridge *self) {
    if (self->model != NULL) {
        func_ov000_02190a80(self->model, func_0203db40(&self->pause));
    }
    if (self->anim != NULL) {
        func_ov000_02190a80(self->anim, func_0203db40(&self->pause));
    }
}

void Ov003ActVt_021f9e10_Start(Ov003Bridge *self) {
    const char *name;
    func_ov000_02194758(self);
    if (self->unk_93_1 != 0) {
        void *res;
        s32 i;
        name = data_ov003_021f9fd6;
        self->unk_cc_0 = 0;
        if (self->hit == NULL) {
            ActorSub48 *c = (ActorSub48 *)Heap_Alloc(0x9c);
            if (c != NULL) {
                c = func_ov000_021985e8(c);
            }
            self->hit = c;
            func_ov000_02198c8c(c, self->id);
            self->hit->unk_28 = 0x10;
            self->hit->radius = self->radius;
            self->hit->offset.y = self->centerY;
            c = self->hit;
            c->unk_9a_0 = 1;
            c->unk_9a_3 = 1;
            HitSphere_Link(c);
            c = self->hit;
            c->unk_9a_1 = 0;
            c->unk_9a_4 = 0;
        }
        for (i = 0; i < 2; i++) {
            res = self->res[i];
            if (res != NULL) {
                break;
            }
        }
        if (res != NULL) {
            Model0218fe1c *a = (Model0218fe1c *)Heap_Alloc(0xe8);
            if (a != NULL) {
                a = func_ov000_0218fe1c(a);
            }
            self->anim = a;
            func_ov000_0218ffdc(a, res, 0, 1);
            { VecFx32 v; v.x = self->pos.x; v.y = self->pos.y; v.z = self->pos.z; v.y += self->unk_1c << 4; self->anim->trans = v; }
            func_ov000_02190758(self->anim, &self->rot, 0);
        }
        func_ov000_02198360(self->fsm, 1, 1);
        self->fsm->st = 10;
    } else {
        name = data_ov003_021f9fd0;
    }
    if (self->model != NULL) {
        func_ov000_02190cb0(self->model, name, 0x1000, 0);
        func_ov000_021915a0(self->model);
        func_ov000_021911c8(self->model, 0x4cd);
    }
}

}
