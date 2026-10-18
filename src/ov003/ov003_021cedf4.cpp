#include "types.h"

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

struct Ov003HeapCtx {
    void *cur;
    u32 unk_04;
    void *alt;
};

class Ov003Script {
public:
    virtual void v00();
    virtual void Delete();
    u16 id;
    u16 max;
    u16 val;
    u16 unk_0a;
    u32 unk_0c;
    Ov003Script *next;
};

typedef void (*Ov003ScriptFunc)(void *self, void *arg);

struct Ov003Step {
    s16 op;
    s16 chance;
    u16 a;
    u16 b;
};

struct Ov003Track {
    void *vtbl;
    u16 id;
    u16 max;
    u16 val;
    u16 unk_0a;
    Ov003Step *steps;
    Ov003Track *next;
};

struct Ov003ScriptList {
    void *vtbl;
    Ov003Script *head;
    u16 count;
    u16 unk_0a;
    Ov003Track *cur;
    Ov003ScriptFunc func;
    void *arg;
    u8 enabled;
};

extern "C" {

extern Ov003Save *data_0214a424;
extern void *data_02097e4c;
extern Ov003HeapCtx *data_02097dd0;
extern u8 data_ov003_021f7974[];
extern void func_02049bdc(void *mgr, s32 a, s32 b);
extern Ov003Area *func_0206ef10(u16 id);
extern void func_0203de1c(void *p);
extern s32 func_02040498(s32 max);

void func_ov003_021cedf4(u16 add) {
    u16 c;
    if (data_0214a424->mode != 1) {
        return;
    }
    c = data_0214a424->meter;
    if (c < 0x2d0) {
        c += add;
        if (c >= 0x2d0) {
            func_02049bdc(data_02097e4c, 0x44, 5);
            c = 0x2d0;
        }
    } else {
        c = 0x2d0;
    }
    data_0214a424->meter = c;
}

u8 func_ov003_021cee68(void) {
    u8 r = 3;
    if (data_0214a424->mode == 1) {
        Ov003Area *area = func_0206ef10(data_0214a424->area | 0x8000);
        if (area != NULL) {
            r += area->bonus;
        }
    }
    return r;
}

void func_ov003_021ceec4(void) {
}

void *func_ov003_021ceec8(void *self) {
    func_0203de1c(self);
    return self;
}

void func_ov003_021ceedc(Ov003ScriptList *self) {
    self->vtbl = data_ov003_021f7974;
    self->head = NULL;
    self->cur = NULL;
    self->count = 0;
    self->func = NULL;
    self->arg = NULL;
    self->enabled = 1;
}

static inline void Ov003ScriptList_Clear(Ov003ScriptList *self) {
    Ov003Script *s = self->head;
    while (s != NULL) {
        void *old;
        Ov003Script *next;
        next = s->next;
        old = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->alt;
        if (s != NULL) {
            if (s != NULL) {
                s->Delete();
            }
        }
        data_02097dd0->cur = old;
        s = next;
    }
}

Ov003ScriptList *func_ov003_021cef0c(Ov003ScriptList *self) {
    self->vtbl = data_ov003_021f7974;
    Ov003ScriptList_Clear(self);
    return self;
}

Ov003ScriptList *func_ov003_021cef7c(Ov003ScriptList *self) {
    self->vtbl = data_ov003_021f7974;
    Ov003ScriptList_Clear(self);
    func_0203de1c(self);
    return self;
}

static inline BOOL Ov003_Chance(s32 p) {
    return func_02040498(0x1000) <= p ? TRUE : FALSE;
}

static inline void Ov003Track_Set(Ov003Track *t, u16 v) {
    if (v < t->max) {
        t->val = v;
    }
}

static inline Ov003Track *Ov003ScriptList_Select(Ov003ScriptList *self, u16 id, u16 val) {
    Ov003Track *t;
    for (t = (Ov003Track *)self->head; t != NULL; t = t->next) {
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

Ov003Step *func_ov003_021ceff4(Ov003ScriptList *self) {
    Ov003Step *step;
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
                v = lo + func_02040498(hi - lo);
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
