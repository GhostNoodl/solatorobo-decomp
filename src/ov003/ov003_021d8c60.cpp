#include "types.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "ov003/Actor.h"
#include "ov003/Ticker.h"
#include "ov003/StateMachine.h"

class Ov003TickerSet {
public:
    virtual void v00();
    virtual void v04();
    virtual void Release();
    u8 active : 1;
    u8 loop : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    s16 count;
    Ov003Ticker tickers[3];
};

class Ov003Timer {
public:
    virtual void v00();
    virtual void v04();
    virtual void Release();
    u8 active : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    s16 unk_06;
    struct Ov003Actor *target;
    u16 state;
    u16 timer;
    u32 unk_10;
    u32 unk_14;
};

static inline Ov003StateNode *Ov003StateMachine_Find(Ov003StateMachine *self, u8 id) {
    Ov003StateNode *n;
    for (n = self->list; n != NULL; n = n->next) {
        if (n->id == id) {
            return n;
        }
    }
    return NULL;
}

extern "C" {

extern u32 data_ov003_021f7cf4;
extern u32 data_ov003_021f7cd8;
extern s16 Ov003Ticker_GetValue(Ov003Ticker *t);
extern void Heap_Free(void *p);
extern void *Heap_Alloc(u32 size);
extern ActorSub40 *History_Init(ActorSub40 *p);

void Ov003Timer_Stop(Ov003Timer *self) {
    if (self->active) {
        self->active = 0;
    }
}

extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void func_ov000_0218996c(u8 a, u8 b);
extern u32 Rand_UpTo(u32 max);

void Ov003Timer_Update(Ov003Timer *self) {
    BOOL fire;
    if (!self->active) {
        return;
    }
    if (!self->b1) {
        return;
    }
    fire = FALSE;
    switch (self->state) {
    case 0:
        if (self->b2 == 1) {
            self->state = 2;
        } else {
            self->state = 1;
        }
        break;
    case 1:
        if (self->timer % 20 == 0) {
            fire = TRUE;
        }
        if (self->timer >= 0x78) {
            self->timer = 0;
            self->state = 3;
        }
        self->timer++;
        break;
    case 2:
        if (self->timer % 20 == 0) {
            fire = TRUE;
        }
        self->timer++;
        break;
    case 3: {
        Ov003Actor *t = self->target;
        VecFx32 p;
        EffectObj *fx;
        s16 sc;
        ActorSub44 *sub;
        p.x = t->pos.x;
        p.y = t->pos.y;
        p.z = t->pos.z;
        sub = t->unk_44;
        if (sub != NULL) {
            VecFx32 o;
            o.x = sub->unk_0c.x;
            o.y = sub->unk_0c.y;
            o.z = sub->unk_0c.z;
            VEC_Add(&p, &o, &p);
        }
        fx = Effect_SpawnId(5, &p);
        sc = self->unk_06 + 0x3800;
        fx->SetScaleXYZ(sc, sc, sc);
        SndMgr_PlayAtPitch(data_02097e4c, 0x56, &p, -3);
        func_ov000_0218996c(0x10, 0x5a);
        self->state = 4;
        break;
    }
    case 4:
        self->target = NULL;
        self->b1 = 0;
        break;
    }
    if (!fire) {
        return;
    }
    {
        VecFx32 p;
        Ov003Actor_SpawnScatterFx(self->target, self->unk_06, Rand_UpTo(1) != 0 ? 4 : 3, 0x733, 0xe66);
        p.x = self->target->pos.x;
        p.y = self->target->pos.y;
        p.z = self->target->pos.z;
        func_ov000_0218996c(8, 0xc);
        SndMgr_PlayAt(data_02097e4c, 0x35, &p, 0);
    }
}

}
