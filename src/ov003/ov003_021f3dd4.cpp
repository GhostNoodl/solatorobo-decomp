#include "types.h"
#include "Main/Effect/Effect.h"
#include "nitro/std.h"
#include "ov003/Prop.h"


struct Ov003Names {
    const char *name;
    const char *name2;
    const char *altName;
    const char *altName2;
    u8 unk_10[8];
    u8 count;
};

struct Ov003FxPlayer {
    u8 unk_00[0xba0];
    Ov003Names *names;
};

struct Ov003Info {
    u8 unk_00[0x12];
    u16 unk_12_0 : 12;
    u16 shadow : 2;
};

struct Ov003PropDef {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    u8 alt;
};

struct Ov003AnimFrames {
    u8 unk_00[4];
    u16 count;
};

struct Ov003AnimCtl {
    s32 frame;
    u8 unk_04[4];
    Ov003AnimFrames *frames;
};

struct Ov003AnimLayer {
    Ov003AnimCtl *ctl;
    u8 unk_04[0x10d];
    u8 unk_111_0 : 3;
    u8 loop : 1;
};

struct Ov003Save {
    u8 unk_00[0x18];
    u16 unk_18_0 : 1;
    u16 unk_18_1 : 2;
    u16 unk_18_3 : 4;
};

extern "C" {
extern s32 Rand_PlusMinus(s32 max);
extern u32 Rand_UpTo(u32 max);
extern Ov003FxPlayer *ActorMgr_FindPlayer(void);
extern Ov003Info *Tbl_FindEntry_0206fef8(u16 id);
extern u8 *func_020705fc(s32 id);
extern void *Heap_Alloc(u32 size);
extern ActorRes *ResSet_Init(void *p);
extern ActorShadow *Shadow_Ctor(void *p);
extern void Shadow_Load(ActorShadow *p);
extern BOOL Shadow_UpdateLoad(ActorShadow *p);
extern BOOL ResSet_UpdateLoad(ActorRes *p);
extern Ov003Save *data_0214a424;
extern char data_ov003_021fa662[];
extern BOOL Model0218fe1c_SetAnim(void *model, const char *name, s32 a, s32 b);
extern void func_ov000_02191870(void *model, ActorRes *res);
extern Ov003AnimLayer *Model0218fe1c_GetAnimCtrl(void *model, s32 n);
extern void func_ov000_02191920(void *model, s32 a, s32 b, s32 c);
extern ActorSub40 *History_Init(void *p);
extern u8 *func_0206ef10(u16 id);
extern void Model0218fe1c_StopAnim(Model0218fe1c *model);
extern void ResSet_SetName0(ActorRes *res, s32 a, s32 b, s32 c, s32 d);
extern void ResSet_SetName1(ActorRes *res, s32 a, s32 b, s32 c, s32 d);
extern void func_ov000_0218ef10(ActorRes *res, s32 a, s32 b, s32 c, s32 d);
extern BOOL Model0218fe1c_SetRes(Model0218fe1c *model, ActorRes *res, s32 a, s32 b);

// Actor::unk_34 is the actor's main ActorRes (built by ResSet_Init).
static inline ActorRes *Ov003Prop_MainRes(Ov003Prop021fa548 *self) {
    return (ActorRes *)self->unk_34;
}

static inline Ov003PropDef *Ov003_GetDef(u16 a) {
    Ov003PropDef *def = NULL;
    u8 *p = func_0206ef10(a | 0x8000);
    if (p != NULL) {
        def = (Ov003PropDef *)(p + 0xc);
    }
    return def;
}

static inline void Model0218fe1c_SetVisible(Model0218fe1c *m, BOOL v) {
    m->visible = v;
}

static inline BOOL ActorShadow_IsIdle(ActorShadow *sh) {
    BOOL r = TRUE;
    if (sh->unk_1b != 3 && sh->unk_1b != 0) {
        r = FALSE;
    }
    return r;
}

BOOL Ov003ActVt_021fa548_IsReady(Ov003Prop021fa548 *self) {
    BOOL r = TRUE;
    if (Ov003Prop_MainRes(self)->unk_00 >= 0 && !ResSet_UpdateLoad(Ov003Prop_MainRes(self))) {
        r = FALSE;
    }
    if (self->altFrame != 0 && self->res.unk_00 >= 0 && !ResSet_UpdateLoad(&self->res)) {
        r = FALSE;
    }
    if (self->unk_3c != NULL && !ActorShadow_IsIdle(self->unk_3c)) {
        if (!Shadow_UpdateLoad(self->unk_3c)) {
            r = FALSE;
        }
    }
    return r;
}

void Ov003ActVt_021fa548_Start(Ov003Prop021fa548 *self) {
    Ov003AnimLayer *layer;
    Ov000ActVt_021cc7cc_Start(self);
    Model0218fe1c_SetAnim(self->model, data_ov003_021fa662, 0x1000, 1);
    if (self->altFrame != 0) {
        func_ov000_02191870(self->model, &self->res);
        layer = Model0218fe1c_GetAnimCtrl(self->model, 3);
        if (layer != NULL) {
            s32 frame;
            s32 n;
            Ov003AnimCtl *ctl;
            func_ov000_02191920(self->model, 0, 0x1000, 0);
            n = self->altFrame << 12;
            if (self->altFrame != 0) {
                frame = (s32)((float)n + 0.5f);
            } else {
                frame = (s32)((float)n - 0.5f);
            }
            ctl = layer->ctl;
            if (ctl != NULL) {
                if (frame >= 0) {
                    ctl->frame = frame;
                } else {
                    ctl->frame = (ctl->frames->count << 12) - 1;
                }
            }
            layer->loop = 1;
        }
        self->model->unk_c2_6 = 1;
    }
    ActorSub40 *task = (ActorSub40 *)Heap_Alloc(0x14);
    if (task != NULL) {
        task = History_Init(task);
    }
    self->fsm = task;
}

void Ov003ActVt_021fa548_RunState(Ov003Prop021fa548 *self) {
    Ov003Save *save = data_0214a424;
    u16 a = save->unk_18_3;
    u16 b = save->unk_18_1;
    switch (self->fsm->st) {
    case 0: {
        Ov003PropDef *def;
        VecFx32 v;
        if (self->unk_1ea == b && self->unk_1ec == a) {
            return;
        }
        self->unk_1ea = b;
        self->unk_1ec = a;
        def = Ov003_GetDef(a);
        if (def == NULL) {
            return;
        }
        v.x = self->pos.x;
        v.y = self->pos.y;
        v.z = self->pos.z;
        v.y += 0xccd;
        Effect_SpawnId(0x5dc, &v);
        Effect_SpawnId(0x384, &v);
        Model0218fe1c_SetVisible(self->model, FALSE);
        Model0218fe1c_StopAnim(self->model);
        ResSet_SetName0(Ov003Prop_MainRes(self), def->a, def->b, 1, 0);
        ResSet_SetName1(Ov003Prop_MainRes(self), def->c, def->d, 1, 0);
        func_ov000_0218ef10(Ov003Prop_MainRes(self), def->e, def->f, 1, 0);
        if (def->alt != 0) {
            ResSet_SetName1(&self->res, def->a, def->b, 1, 0);
        }
        self->altFrame = def->alt;
        (self->fsm->st)++;
        break;
    }
    case 1: {
        BOOL r = TRUE;
        if (Ov003Prop_MainRes(self)->unk_00 >= 0 && !ResSet_UpdateLoad(Ov003Prop_MainRes(self))) {
            r = FALSE;
        }
        if (self->altFrame != 0 && self->res.unk_00 >= 0 && !ResSet_UpdateLoad(&self->res)) {
            r = FALSE;
        }
        if (!r) {
            return;
        }
        Model0218fe1c_SetRes(self->model, Ov003Prop_MainRes(self), 0, 1);
        Model0218fe1c_SetVisible(self->model, TRUE);
        Model0218fe1c_SetAnim(self->model, data_ov003_021fa662, 0x1000, 1);
        if (self->altFrame != 0) {
            Ov003AnimLayer *layer;
            func_ov000_02191870(self->model, &self->res);
            layer = Model0218fe1c_GetAnimCtrl(self->model, 3);
            if (layer != NULL) {
                s32 frame;
                s32 n;
                Ov003AnimCtl *ctl;
                func_ov000_02191920(self->model, 0, 0x1000, 0);
                n = self->altFrame << 12;
                if (self->altFrame != 0) {
                    frame = (s32)((float)n + 0.5f);
                } else {
                    frame = (s32)((float)n - 0.5f);
                }
                ctl = layer->ctl;
                if (ctl != NULL) {
                    if (frame >= 0) {
                        ctl->frame = frame;
                    } else {
                        ctl->frame = (ctl->frames->count << 12) - 1;
                    }
                }
                layer->loop = 1;
            }
            self->model->unk_c2_6 = 1;
        }
        self->fsm->st = 0;
        break;
    }
    }
}
}
