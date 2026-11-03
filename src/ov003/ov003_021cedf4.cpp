#include "types.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "Main/Sys/SysState.h"
#include "ov003/Script.h"

struct Ov003Save {
    u8 unk_00[0x18];
    u16 unk_18_0 : 1;
    u16 mode : 2;
    u16 area : 4;
    u8 level;
    u32 exp;
    u8 unk_20[6];
    u16 meter;
};

struct Ov003Area {
    u8 unk_00[4];
    u8 bonus : 4;
};

extern "C" {

extern Ov003Save *gStageFlags;
extern u8 Ov003Vt_021f7974_vtbl[];
extern s32 SndMgr_PlayPan(SndMgr *mgr, s32 a, s32 b);
extern Ov003Area *func_0206ef10(u16 id);
extern void Heap_Free(void *p);
extern s32 Rand_UpTo(s32 max);

void Ov003_AddMeter_021cedf4(u16 add) {
    u16 c;
    if (gStageFlags->mode != 1) {
        return;
    }
    c = gStageFlags->meter;
    if (c < 0x2d0) {
        c += add;
        if (c >= 0x2d0) {
            SndMgr_PlayPan(gSndMgr, 0x44, 5);
            c = 0x2d0;
        }
    } else {
        c = 0x2d0;
    }
    gStageFlags->meter = c;
}

u8 Ov003_GetMaxCombo(void) {
    u8 r = 3;
    if (gStageFlags->mode == 1) {
        Ov003Area *area = func_0206ef10(gStageFlags->area | 0x8000);
        if (area != NULL) {
            r += area->bonus;
        }
    }
    return r;
}

void Ov003Track_Dtor(void) {
}

void *Ov003Track_DtorDelete(Ov003Track *self) {
    Heap_Free(self);
    return self;
}

void Ov003ScriptList_Init(Ov003ScriptList *self) {
    self->vtbl = Ov003Vt_021f7974_vtbl;
    self->head = NULL;
    self->cur = NULL;
    self->count = 0;
    self->func = NULL;
    self->arg = NULL;
    self->enabled = 1;
}

static inline void Ov003ScriptList_Clear(Ov003ScriptList *self) {
    Ov003Track *s = self->head;
    while (s != NULL) {
        void *old;
        Ov003Track *next;
        next = s->next;
        old = gSysState->cur;
        gSysState->cur = gSysState->heapHi;
        if (s != NULL) {
            if (s != NULL) {
                s->Delete();
            }
        }
        gSysState->cur = old;
        s = next;
    }
}

Ov003ScriptList *Ov003Vt_021f7974_Dtor(Ov003ScriptList *self) {
    self->vtbl = Ov003Vt_021f7974_vtbl;
    Ov003ScriptList_Clear(self);
    return self;
}

Ov003ScriptList *Ov003Vt_021f7974_DtorDelete(Ov003ScriptList *self) {
    self->vtbl = Ov003Vt_021f7974_vtbl;
    Ov003ScriptList_Clear(self);
    Heap_Free(self);
    return self;
}

static inline BOOL Ov003_Chance(s32 p) {
    return Rand_UpTo(0x1000) <= p ? TRUE : FALSE;
}

static inline void Ov003Track_Set(Ov003Track *t, u16 v) {
    if (v < t->max) {
        t->val = v;
    }
}

static inline Ov003Track *Ov003ScriptList_Select(Ov003ScriptList *self, u16 id, u16 val) {
    Ov003Track *t;
    for (t = self->head; t != NULL; t = t->next) {
        if (id == t->id) {
            break;
        }
    }
    if (t != NULL) {
        self->cur = t;
        if (val < t->max) {
            t->val = val;
        }
    }
    return self->cur;
}

static inline void Ov003Track_Advance(Ov003Track *t) {
    t->val++;
    t->val = (u32)t->val % t->max;
}

const Ov003Step *Ov003ScriptList_Step(Ov003ScriptList *self) {
    const Ov003Step *step;
    Ov003Track *cur;
    if (self->func != NULL && self->enabled) {
        self->func(self, self->arg);
    }
    cur = self->cur;
    Ov003Track_Advance(cur);
    for (step = &cur->steps[cur->val]; step->op < 0; step = &cur->steps[cur->val]) {
        switch (step->op) {
        case -1:
            if (Ov003_Chance(step->chance)) {
                s32 hi = step->b;
                u16 lo = step->a;
                u16 v;
                if (hi == 0xffff) {
                    hi = cur->max - 1;
                }
                v = lo + Rand_UpTo(hi - lo);
                if (v < cur->max) {
                    cur->val = v;
                }
            } else {
                Ov003Track_Advance(cur);
            }
            break;
        case -2:
            if (Ov003_Chance(step->chance)) {
                Ov003Track_Set(cur, step->a);
            } else {
                Ov003Track_Advance(cur);
            }
            break;
        case -3:
            if (Ov003_Chance(step->chance)) {
                Ov003Track_Set(cur, step->a);
            } else {
                Ov003Track_Set(cur, step->b);
            }
            break;
        case -4:
            if (Ov003_Chance(step->chance)) {
                cur = Ov003ScriptList_Select(self, step->a, step->b);
            } else {
                Ov003Track_Advance(cur);
            }
            break;
        default:
            Ov003Track_Advance(cur);
            break;
        }
    }
    self->cur = cur;
    return step;
}

}
