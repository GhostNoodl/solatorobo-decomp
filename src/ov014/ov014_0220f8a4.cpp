#include "ov014/ov014.h"
#include "nitro/mi.h"

extern "C" {

extern char data_ov014_02217c72[];
extern char data_ov014_02217c81[];
extern char data_ov014_02217c93[];
extern char data_ov014_02217c9f[];
extern char data_ov014_02217cb1[];
extern char data_ov014_02217cbd[];
extern char data_ov014_02217ccf[];
extern u8 data_ov014_02217e6c[];
extern char data_ov014_02217d1d[];
extern void *History_Init(void *p);
extern BOOL func_ov000_0218cf5c(Ov003Actor *self);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern BOOL func_ov003_021d1c00(Ov003Actor *self, Ov014Msg *msg);
extern u8 data_ov014_02217d2c[];
extern u8 data_ov014_02217d33[];
extern u8 data_ov014_02217db0[];
extern const Ov003Step data_ov014_02216c80[];
extern const Ov003Step data_ov014_02216e50[];
extern const Ov003Step data_ov014_02216ea8[];
extern const Ov003Step data_ov014_02216f00[];
extern void func_0203f2b8(void *p);
extern s32 func_ov000_021909a8(void *a, const void *b, const void *c);

EffectObj *func_ov014_0220f7f0(s32 k, VecFx32 *pos) {
    EffectObj *r = NULL;
    switch (k) {
    case 0:
        r = EffectGroup_Create(data_ov014_02217c72, data_ov014_02217c81, pos);
        break;
    case 1:
        r = Effect3D_Create(data_ov014_02217c72, data_ov014_02217c93, 0, pos);
        r->unk_28 = 2;
        break;
    case 2:
        r = EffectGroup_Create(data_ov014_02217c72, data_ov014_02217c9f, pos);
        break;
    case 3:
        r = Effect3D_Create(data_ov014_02217c72, data_ov014_02217cb1, 0, pos);
        r->unk_28 = 2;
        break;
    case 4:
        r = EffectGroup_Create(data_ov014_02217c72, data_ov014_02217cbd, pos);
        break;
    case 5:
        r = EffectGroup_Create(data_ov014_02217c72, data_ov014_02217ccf, pos);
        break;
    }
    return r;
}

void func_ov014_0220f8a4(u8 *self) {
    u8 *t = FLD(u8 *, FLD(u8 *, self, 4), 0x2c);
    s32 k;
    if (t == NULL) {
        return;
    }
    if (FLD(u32, self, 8) & 0x10) {
        k = FLD(u8, self, 0xae);
    } else {
        k = -1;
    }
    if (k == FLD(s32, t, 0)) {
        NNS_G3dGetCurrentMtx((MtxFx43 *)(t + 4), 0);
    }
}

void func_ov014_0220f8e4(u8 *self) {
    FLD(void *, self, 0x24) = (void *)func_ov014_0220f8a4;
    FLD(u8, self, 0x92) = 3;
}

// arg is the actor that owns the list.
void func_ov014_0220f8fc(Ov003ScriptList *self, Ov014Act_0220f9d0 *a) {
    u16 pct = a->hp[0] * 100 / a->hp[1];
    u16 s;
    if (a->unk_154 != NULL) {
        s = a->unk_154->count;
    } else {
        s = 0;
    }
    if (pct < 40) {
        if (s == 0) {
            if (self->cur->id != 3) {
                func_ov003_021cf278(self, 3, 0);
            }
        } else {
            if (self->cur->id != 2) {
                func_ov003_021cf278(self, 2, 0);
            }
        }
    } else if (pct < 80) {
        if (self->cur->id != 1) {
            func_ov003_021cf278(self, 1, 0);
        }
    } else {
        if (self->cur->id != 0) {
            func_ov003_021cf278(self, 0, 0);
        }
    }
}

#pragma force_active on
Ov003Actor *Ov014Act_0220f9d0_Ctor(Ov014Act_0220f9d0 *self) {
    func_ov003_021d0c1c(self);
    *(void **)self = data_ov014_02217e6c;
    Ov003ScriptList_Init(&self->scripts);
    self->unk_15c.unk_b4 = 0;
    self->unk_15c.unk_b6 = 0;
    History_Init((u8 *)self + 0x16c);
    self->target_id = 0xffff;
    MIi_CpuClear32(0, &self->unk_f0, sizeof(Ov014JointMtx));
    self->step = NULL;
    self->unk_14c = 0;
    self->unk_154 = NULL;
    self->unk_180 = 1;
    self->unk_14e = 0xffff;
    self->unk_150 = 0xffff;
    return self;
}
#pragma force_active reset

static inline void Ov014_Free154(Ov014Act_0220f9d0 *self) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_154 != NULL) {
        Ov014Watch *p = self->unk_154;
        if (p != NULL) {
            p->vfunc_04();
        }
        self->unk_154 = NULL;
    }
    data_02097dd0->cur = saved;
}

static inline void Ov014_StopSnd(void) {
    if (func_02035b90(data_ov014_02217d1d, 7)) {
        func_02036838(data_02097cdc, data_ov014_02217d1d, 7, 0);
    }
}

Ov014Act_0220f9d0 *Ov014Act_0220f9d0_Dtor(Ov014Act_0220f9d0 *self) {
    *(void **)self = data_ov014_02217e6c;
    Ov014_Free154(self);
    Ov014_StopSnd();
    Ov003Vt_021f7974_Dtor(&self->scripts);
    func_ov003_021d0edc(self);
    return self;
}

Ov014Act_0220f9d0 *Ov014Act_0220f9d0_DtorDelete(Ov014Act_0220f9d0 *self) {
    *(void **)self = data_ov014_02217e6c;
    Ov014_Free154(self);
    Ov014_StopSnd();
    Ov003Vt_021f7974_Dtor(&self->scripts);
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

void Ov014Act_0220f9d0_Init(Ov014Act_0220f9d0 *self) {
    func_ov003_021d0fc0(self);
    func_020359d0(data_ov014_02217d1d, 7, 0);
}

BOOL Ov014Act_0220f9d0_IsReady(Ov014Act_0220f9d0 *self) {
    BOOL r = func_ov000_0218cf5c(self);
    return (r & func_02035b90(data_ov014_02217d1d, 7)) ? TRUE : FALSE;
}

void func_ov014_0220fc00(Ov014Act_0220f9d0 *self, Ov014Msg *msg) {
    if (msg->type == 9) {
        Ov003Actor *a;
        u16 id = msg->unk_0c;
        self->unk_14e = id;
        if (data_ov000_021ccd68 == NULL) {
            a = NULL;
        } else {
            a = ActorMgr_GetActor(data_ov000_021ccd68, id);
        }
        self->unk_150 = a->kind;
    }
    func_ov003_021d1c00(self, msg);
}

void Ov014Act_0220f9d0_Start(Ov014Act_0220f9d0 *self) {
    Model0218fe1c *m;
    Ov014Watch *p;
    func_ov003_021d112c(self);
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = 0;
    self->rot_x = 0;
    self->rot_y = 0;
    self->rot_z = 0;
    {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->heapHi;
        if (self->unk_3c != NULL) {
            VObj *v = self->unk_3c;
            if (v != NULL) {
                v->vfunc_04();
            }
            self->unk_3c = NULL;
        }
        data_02097dd0->cur = saved;
    }
    {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->heapHi;
        if (self->hit != NULL) {
            ActorSub48 *q = self->hit;
            if (q != NULL) {
                func_0203f2b8(q);
                Heap_Free(q);
            }
            self->hit = NULL;
        }
        data_02097dd0->cur = saved;
    }
    self->unk_44->unk_1c = 0x2000;
    {
        ActorSub44 *n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
    }
    self->unk_f0.joint = func_ov000_021909a8(self->model, data_ov014_02217d2c, data_ov014_02217d33);
    MTX_Identity43_(&self->unk_f0.mtx);
    m = self->model;
    NNS_G3dRenderObjSetInitFunc((NNSG3dRenderObj *)m->unk_24, (NNSG3dSbcCallBackFunc)func_ov014_0220f8e4);
    m->clearInit = 0;
    self->model->flushVP = 1;
    self->model->renderUser = &self->unk_f0;
    self->model->boxTest = 0;
    p = (Ov014Watch *)Heap_Alloc(sizeof(Ov014Watch));
    if (p != NULL) {
        *(void **)p = data_ov014_02217db0;
        MIi_CpuClear16(0xffff, p->ids, sizeof(p->ids));
        p->count = 0;
        p->unk_0a = 0;
        p->unk_0b = 0;
        p->step = 0;
        p->mode = 0xffff;
        p->wait = 0;
    }
    self->unk_154 = p;
    func_ov003_021cf1f0(&self->scripts, 0, 7, data_ov014_02216c80);
    func_ov003_021cf1f0(&self->scripts, 1, 11, data_ov014_02216e50);
    func_ov003_021cf1f0(&self->scripts, 2, 11, data_ov014_02216ea8);
    func_ov003_021cf1f0(&self->scripts, 3, 12, data_ov014_02216f00);
    self->scripts.arg = self;
    self->scripts.func = (Ov003ScriptFunc)func_ov014_0220f8fc;
}

struct Ov014SpawnDescB {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov014SpawnB_Init(Ov014SpawnDescB *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

extern VecFx32 data_ov014_02216c18[];
extern Ov003Actor *func_ov000_0219bf90(void);
extern BOOL func_ov014_02213cfc(Ov014Watch *self);
extern Ov003Actor *Group_SpawnActor(void *mgr, Ov014SpawnDescB *d, VecFx32 *pos, Ov014Vec16 *rot, u16 a);

static inline BOOL Ov014_WaitB6(Ov003Actor *self) {
    BOOL r = FALSE;
    if (self->fsm->st == 0xffff || self->unk_b6 == 0) {
        r = TRUE;
    } else if (self->unk_b6 != 0xffff && self->unk_b6 != 0) {
        self->unk_b6--;
    }
    return r;
}

static inline void Ov014_SpawnPair(Ov014Act_0220f9d0 *self) {
    Ov014Watch *p = self->unk_154;
    u32 i;
    for (i = 0; i < 2; i++) {
        if (p->ids[i] == 0xffff) {
            Ov014SpawnDescB desc;
            Ov014Vec16 rot;
            Ov003Actor *o;
            Ov014SpawnB_Init(&desc, 0x5c16);
            rot.x = 0;
            rot.y = 0;
            rot.z = 0;
            o = Group_SpawnActor(data_ov000_021ccd64, &desc, &data_ov014_02216c18[i], &rot, 0xffff);
            o->flags_0 = 1;
            p->ids[i] = o->id;
        }
    }
}

void Ov014Act_0220f9d0_Update(Ov014Act_0220f9d0 *self) {
    Ov003Actor *pl;
    if (!Ov014_GameIdle()) {
        return;
    }
    self->target = 0xffff;
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        self->target = pl->id;
    }
    if (!self->unk_b0->unk_0a_12) {
        self->unk_93_4 = 1;
    }
    if (*self->hp == 0 || (self->fsm->flags & 0x200000)) {
        if (self->unk_b4 != 0x50) {
            self->unk_b6 = 0xffff;
            self->unk_b4 = 0x50;
            self->fsm->flags |= 0x200000;
            self->fsm->st = 0;
        }
    }
    if (self->msg_flags != 0 && (self->msg_flags & 0x200)) {
        if (*self->hp != 0 && self->unk_180 != 0) {
            MIi_CpuCopyFast(&self->unk_b4, &self->unk_15c, sizeof(Ov014B4Save));
            MIi_CpuCopyFast(self->fsm, &self->unk_16c, 0x14);
            self->unk_b4 = 0x3c;
            self->unk_b6 = 0xffff;
        }
        if (self->fsm->flags == 0x15) {
            *self->hp = 0;
        }
    }
    func_ov014_02213cfc(self->unk_154);
    switch (self->unk_b4) {
    case 0:
        self->fsm->flags |= 0x100000000ULL;
        self->fsm->timer = 0xffff;
        self->fsm->st = 0;
        self->unk_b4++;
        break;
    case 1:
        if (self->fsm->st != 0xffff) {
            break;
        }
        self->fsm->flags |= 2;
        self->fsm->st = 0;
        Ov014_SpawnPair(self);
        {
            u16 m = self->unk_b4;
            self->unk_b6 = 0xf0;
            self->unk_b4 = m + 1;
        }
        break;
    case 2:
        if (self->unk_b6 != 0) {
            self->unk_b6--;
        }
        if (self->unk_b6 == 0) {
            self->unk_b4 = 0xb;
        }
        break;
    case 10: {
        Ov014Watch *p = self->unk_154;
        if (p->timer == 0 && p->count == 0) {
            self->unk_b4 = 0x46;
            self->unk_b6 = 0xffff;
            break;
        }
        if (p->unk_0a == 0) {
            break;
        }
        if (!Ov014_WaitB6(self)) {
            break;
        }
        func_ov003_021ceff4(&self->scripts);
        self->unk_b4++;
    }
    case 11: {
        Ov003Track *t = self->scripts.cur;
        self->step = &t->steps[t->val];
        switch (self->step->op) {
        case 0:
        case 1:
        case 2:
            self->unk_b4 = 0x14;
            break;
        case 6:
        case 7:
        case 8:
            self->unk_b4 = 0x1e;
            break;
        case 3:
            self->unk_b4 = 0x28;
            break;
        case 4:
        case 5:
            self->unk_b4 = 0x32;
            break;
        }
        break;
    }
    case 0x14:
        self->fsm->flags |= 0x4000;
        self->fsm->st = 0;
        self->unk_b6 = 0xffff;
        self->target_id = 0;
        self->unk_b4++;
        break;
    case 0x15:
        if (!Ov014_WaitB6(self)) {
            break;
        }
        self->fsm->flags |= 2;
        self->unk_b4 = 10;
        self->unk_b6 = self->step->b;
        break;
    case 0x1e: {
        Ov014Watch *p;
        s32 v;
        self->fsm->flags |= 2;
        self->fsm->st = 0;
        v = self->step->op - 6;
        p = self->unk_154;
        if (p->unk_0a != 0) {
            p->mode = v;
            p->step = 0;
            p->wait = 0;
        }
        self->unk_b4++;
        break;
    }
    case 0x1f:
        self->fsm->flags |= 2;
        self->unk_b4 = 10;
        self->unk_b6 = self->step->b;
        break;
    case 0x28:
        self->target_id = 0;
        self->unk_180 = 0;
        func_ov000_02198360(self->fsm, 0xf, 0);
        self->fsm->st = 0;
        self->unk_b6 = 0xffff;
        self->unk_b4++;
        break;
    case 0x29:
        if (!Ov014_WaitB6(self)) {
            break;
        }
        self->fsm->flags |= 2;
        self->fsm->st = 0;
        self->unk_180 = 1;
        self->unk_b4++;
        break;
    case 0x2a: {
        Ov003Actor *a;
        u16 id = self->target_id;
        if (data_ov000_021ccd68 == NULL) {
            a = NULL;
        } else {
            a = ActorMgr_GetActor(data_ov000_021ccd68, id);
        }
        if (a == NULL) {
            self->unk_b4 = 10;
            self->unk_b6 = self->step->b;
        }
        break;
    }
    case 0x32:
        self->target_id = 0;
        self->unk_180 = 0;
        if (self->step->op == 4) {
            func_ov000_02198360(self->fsm, 0x10, 0);
        } else {
            func_ov000_02198360(self->fsm, 0x11, 0);
        }
        self->fsm->st = 0;
        self->unk_b6 = 0xffff;
        self->unk_b4++;
        break;
    case 0x33:
        if (!Ov014_WaitB6(self)) {
            break;
        }
        self->unk_180 = 1;
        self->fsm->flags |= 2;
        self->fsm->st = 0;
        self->unk_b4 = 10;
        self->unk_b6 = self->step->b;
        break;
    case 0x3c:
        self->fsm->flags = 0;
        self->fsm->flags |= 0x40000;
        self->fsm->st = 0;
        self->unk_180 = 0;
        self->unk_b6 = 0xffff;
        self->unk_b4++;
        break;
    case 0x3d:
        if (!Ov014_WaitB6(self)) {
            break;
        }
        self->unk_180 = 1;
        self->fsm->flags |= 2;
        self->fsm->st = 0;
        self->unk_b4 = 10;
        self->unk_b6 = 0x1e;
        break;
    case 0x46:
        self->fsm->flags |= 2;
        self->fsm->st = 0;
        Ov014_SpawnPair(self);
        {
            u16 m = self->unk_b4;
            self->unk_b6 = 0x78;
            self->unk_b4 = m + 1;
        }
        break;
    case 0x47:
        if (Ov014_WaitB6(self)) {
            self->unk_b4 = 10;
            self->unk_b6 = 0x1e;
        }
        break;
    case 0x50:
    default:
        break;
    }
}

}
