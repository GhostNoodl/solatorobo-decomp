#include "types.h"
#include "Main/Sys/SysState.h"

struct Ov003PropDef {
    u16 id;
    u16 arg;
};

struct Ov003PropInfo {
    u8 unk_00[0x12];
    u16 loop : 1;
    u16 reverse : 1;
    u16 unk_12_2 : 10;
    u16 shadow : 2;
};

struct Ov003PropRes {
    s16 handle;
};

struct Ov003PropShadow {
    u8 unk_00[0x1c];
};

struct Ov003Prop {
    void *vtbl;
    u8 unk_04[0xa];
    u16 id;
    u8 unk_10[0x24];
    Ov003PropRes *res;
    u8 unk_38[4];
    Ov003PropShadow *shadow;
    u8 unk_40[0x6c];
    void *unk_ac;
    u32 unk_b0;
};

extern "C" {

extern u8 Ov003ActVt_021fa1b8_vtbl[];
extern void *Heap_Alloc(u32 size);
extern void Heap_Free(void *p);
extern void *Actor_Ctor(void *p);
extern void Actor_JoinGroup(void *p, u16 a, u16 b, s32 c);
extern s32 Tbl_GetText(u16 id);
extern void ActorMarker_Release(void *p);
extern void *Actor_DtorBase(void *p);
extern Ov003PropInfo *Tbl_FindEntry_0206fef8(u16 id);
extern void *Tbl_GetResFile(s32 id);
extern Ov003PropRes *ResSet_Init(void *p);
extern Ov003PropShadow *Shadow_Ctor(void *p);
extern void Shadow_Load(Ov003PropShadow *p);
extern void ResSet_SetFile(Ov003PropRes *p, void *res, s32 a, s32 b, s32 c, s32 d);

Ov003Prop *Ov003Prop_New(Ov003PropDef *def) {
    Ov003Prop *p = (Ov003Prop *)Heap_Alloc(0xb4);
    if (p != NULL) {
        Actor_Ctor(p);
        p->vtbl = Ov003ActVt_021fa1b8_vtbl;
        p->unk_ac = NULL;
        p->unk_b0 = 0;
    }
    Actor_JoinGroup(p, def->arg, def->id, Tbl_GetText(def->id));
    return p;
}

static inline void Ov003Prop_Dtor(Ov003Prop *self) {
    void *p;
    void *old;
    self->vtbl = Ov003ActVt_021fa1b8_vtbl;
    old = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    p = self->unk_ac;
    if (p != NULL) {
        if (p != NULL) {
            ActorMarker_Release(p);
            Heap_Free(p);
        }
        self->unk_ac = NULL;
    }
    gSysState->cur = old;
    Actor_DtorBase(self);
}

Ov003Prop *Ov003ActVt_021fa1b8_Dtor(Ov003Prop *self) {
    Ov003Prop_Dtor(self);
    return self;
}

Ov003Prop *Ov003ActVt_021fa1b8_DtorDelete(Ov003Prop *self) {
    Ov003Prop_Dtor(self);
    Heap_Free(self);
    return self;
}

void Ov003ActVt_021fa1b8_Init(Ov003Prop *self) {
    Ov003PropInfo *info = Tbl_FindEntry_0206fef8(self->id);
    void *data = Tbl_GetResFile(self->id);
    Ov003PropRes *res;
    Ov003PropShadow *sh;
    if (data == NULL) {
        return;
    }
    res = (Ov003PropRes *)Heap_Alloc(0x138);
    if (res != NULL) {
        res = ResSet_Init(res);
    }
    self->res = res;
    {
        BOOL loop = info->loop ? 1 : 0;
        BOOL reverse = info->reverse ? 1 : 0;
        ResSet_SetFile(self->res, data, loop, reverse, 0, 0);
    }
    self->res->handle = 0;
    if (!info->shadow) {
        return;
    }
    sh = (Ov003PropShadow *)Heap_Alloc(0x1c);
    if (sh != NULL) {
        sh = Shadow_Ctor(sh);
    }
    self->shadow = sh;
    Shadow_Load(sh);
}
}
