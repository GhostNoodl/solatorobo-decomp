#include "ov014/ov014.h"

struct Ov014Slot {
    s32 id;
    u8 unk_04[0x30];
};

extern "C" {

extern u8 data_ov014_02217968[];
extern char data_ov014_02217a0c[];
extern Ov003Actor *Target_Get(void *p);
extern s32 func_ov000_0219a510(Actor *self, u16 mask, VecFx32 *pos, s32 r, s32 a, Ov003Actor **list);
extern Ov003Actor *func_ov000_021985c0(Ov003Actor *p);
extern void func_ov003_021f0c60(Actor *self, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void *func_ov003_021cf278(void *self, s32 a, s32 b);
extern void Ov003ScriptList_Init(void *p);
extern void *Ov003Vt_021f7974_Dtor(void *p);
extern void func_02049678(void *a, s32 b, s32 c, s32 d);
extern BOOL func_ov000_0218cf5c(Ov003Actor *self);
extern BOOL SndMgr_IsLoadDone(void *a);
extern BOOL func_ov003_021d1c00(Ov003Actor *self, Ov014Msg *msg);
extern u8 data_ov014_02216a60[];
extern u8 data_ov014_02216afc[];
extern u8 data_ov014_02216b6c[];
extern u8 data_ov014_02217a1b[];
extern u8 data_ov014_02217a1c[];
extern u8 data_ov014_02217a28[];
extern u8 data_ov014_02217a38[];
extern void func_ov003_021cf1f0(void *p, s32 a, s32 b, const void *c);
extern s32 func_ov000_021909a8(void *a, const void *b, const void *c);

void func_ov014_02208fe4(Ov014ActEx_02208618 *self) {
    Ov003Actor *list[0x20];
    s32 r;
    s32 n;
    u16 k;
    s32 i;
    r = self->radius + 0x4cd;
    if (r < 0xccd) {
        r = 0xccd;
    }
    self->hit->unk_44 = r;
    k = Target_Get(self->targetObj)->id & 0xf000;
    n = func_ov000_0219a510(self, ~(1 << (k >> 12)), &self->pos, r, 0, list);
    if (n == 0) {
        return;
    }
    for (i = 0; i < n; i++) {
        Ov003Actor *q;
        if (list[i] != NULL && (q = func_ov000_021985c0(list[i])) != NULL) {
            ActorSub4c *s = q->targetObj;
            if (s == NULL || k != (u16)(s->target & 0xf000)) {
                func_ov003_021f0c60(self, 0);
                self->unk_d0 |= 0x1000;
                func_ov000_02198360(self->fsm, 0x15, 0);
                func_ov000_0218996c(5, 8);
                return;
            }
        }
    }
}

void *Ov014ActExVt_02217838_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov014ActExVt_02217838_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov014ActExGrow_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov014ActExGrow_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void func_ov014_0220915c(u8 *self) {
    u8 *t = FLD(u8 *, FLD(u8 *, self, 4), 0x2c);
    s32 k;
    u32 i;
    u32 n;
    if (t == NULL || t[0] == 0) {
        return;
    }
    if (FLD(u32, self, 8) & 0x10) {
        k = FLD(u8, self, 0xae);
    } else {
        k = -1;
    }
    n = FLD(u32, t, 4);
    for (i = 0; i < n; i++) {
        if (k == FLD(s32, t + i * 0x34, 8)) {
            NNS_G3dGetCurrentMtx((MtxFx43 *)(t + 0xc + i * 0x34), 0);
            return;
        }
    }
}

void func_ov014_022091d4(u8 *self) {
    FLD(void *, self, 0x24) = (void *)func_ov014_0220915c;
    FLD(u8, self, 0x92) = 3;
}

void func_ov014_022091ec(void *self, Ov003Actor *a) {
    u16 *hp = a->hp;
    u32 cur = hp[0];
    u32 max = hp[1];
    u8 *q = FLD(u8 *, self, 0xc);
    if (cur >= max * 80 / 100) {
        if (FLD(u16, q, 4) != 0) {
            func_ov003_021cf278(self, 0, 0);
        }
    } else if (cur >= max * 35 / 100) {
        if (FLD(u16, q, 4) != 1) {
            func_ov003_021cf278(self, 1, 0);
        }
    } else {
        if (FLD(u16, q, 4) != 2) {
            func_ov003_021cf278(self, 2, 0);
        }
    }
}

#pragma force_active on
Ov003Actor *Ov014Act_02209280_Ctor(Ov014Act_02209280 *self) {
    s32 i;
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = data_ov014_02217968;
    Ov003ScriptList_Init((u8 *)self + 0x1c0);
    self->step = 0;
    self->unk_f4 = 0;
    self->unk_f8 = 0;
    self->unk_fc = 0;
    for (i = 0; i < 3; i++) {
        ((Ov014Slot *)((u8 *)self + 0x104))[i].id = -1;
        MTX_Identity43_((MtxFx43 *)((u8 *)self + 0x108 + i * 0x34));
    }
    self->unk_1a0 = 0;
    self->unk_1a2 = 0;
    self->unk_1a4 = 1;
    self->unk_1a5 = 0;
    self->unk_1a8 = 0;
    self->unk_1ac = 0;
    self->unk_1b0 = 0;
    self->unk_1b4.x = 0;
    self->unk_1b4.y = 0;
    self->unk_1b4.z = 0;
    self->unk_1dc = 0;
    self->unk_1e0 = 0;
    self->unk_1e4 = 0;
    self->unk_1e8 = 0;
    self->unk_1ec = 0;
    self->unk_1f0 = 0;
    return self;
}
#pragma force_active reset

static inline void Ov014_Kill1f0(Ov014Act_02209280 *self) {
    EffectObj *o;
    if (data_0214a420 != NULL && (o = func_020657b0(data_0214a420, self->unk_1f0)) != NULL) {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->heapHi;
        if (o != NULL) {
            if (o != NULL) {
                o->Delete();
            }
        }
        data_02097dd0->cur = saved;
    }
}

Ov014Act_02209280 *Ov014Act_02209280_Dtor(Ov014Act_02209280 *self) {
    FLD(void *, self, 0) = data_ov014_02217968;
    Ov014_Kill1f0(self);
    func_02036838(data_02097cdc, data_ov014_02217a0c, 7, 0);
    Ov003Vt_021f7974_Dtor((u8 *)self + 0x1c0);
    func_ov003_021d0edc(self);
    return self;
}

Ov014Act_02209280 *Ov014Act_02209280_DtorDelete(Ov014Act_02209280 *self) {
    FLD(void *, self, 0) = data_ov014_02217968;
    Ov014_Kill1f0(self);
    func_02036838(data_02097cdc, data_ov014_02217a0c, 7, 0);
    Ov003Vt_021f7974_Dtor((u8 *)self + 0x1c0);
    func_ov003_021d0edc(self);
    Heap_Free(self);
    return self;
}

void Ov014Act_02209280_Init(Ov014Act_02209280 *self) {
    func_ov003_021d0fc0(self);
    func_020359d0(data_ov014_02217a0c, 7, 0);
    func_02049678(data_02097e4c, 4, 0xc, -1);
}

BOOL Ov014Act_02209280_IsReady(Ov014Act_02209280 *self) {
    BOOL r = TRUE;
    r = (r & func_ov000_0218cf5c(self)) ? TRUE : FALSE;
    r = (r & func_02035b90(data_ov014_02217a0c, 7)) ? TRUE : FALSE;
    return (r & SndMgr_IsLoadDone(data_02097e4c)) ? TRUE : FALSE;
}

void func_ov014_02209520(Ov014Act_02209280 *self, Ov014Msg *msg) {
    func_ov003_021d1c00(self, msg);
}

void Ov014Act_02209280_Start(Ov014Act_02209280 *self) {
    Model0218fe1c *m;
    func_ov003_021d112c(self);
    {
        ActorSub48 *q = self->hit;
        q->unk_9a_1 = 0;
        q->unk_9a_4 = 0;
    }
    {
        ActorSub48 *q = self->hit;
        q->unk_9a_2 = 0;
        q->unk_9a_5 = 0;
    }
    {
        ActorSub44 *n = self->unk_44;
        FLD(s32, n, 0xc) = 0;
        n->unk_0c.y = -0x800;
        FLD(s32, n, 0x14) = 0x1000;
    }
    self->unk_44->unk_1c = 0x1000;
    {
        ActorSub44 *n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
    }
    func_ov003_021cf1f0((u8 *)self + 0x1c0, 0, 9, data_ov014_02216a60);
    func_ov003_021cf1f0((u8 *)self + 0x1c0, 1, 14, data_ov014_02216afc);
    func_ov003_021cf1f0((u8 *)self + 0x1c0, 2, 17, data_ov014_02216b6c);
    self->unk_fc = 0;
    self->unk_1d4 = self;
    self->unk_1d0 = (void *)func_ov014_022091ec;
    self->unk_100 = 3;
    self->unk_104 = func_ov000_021909a8(self->model, data_ov014_02217a1b, data_ov014_02217a1c);
    self->unk_138 = func_ov000_021909a8(self->model, data_ov014_02217a1b, data_ov014_02217a28);
    self->unk_16c = func_ov000_021909a8(self->model, data_ov014_02217a1b, data_ov014_02217a38);
    m = self->model;
    NNS_G3dRenderObjSetInitFunc((NNSG3dRenderObj *)m->unk_24, (NNSG3dSbcCallBackFunc)func_ov014_022091d4);
    m->clearInit = 0;
    self->model->flushVP = 1;
    self->model->renderUser = &self->unk_fc;
    FLD(Ov014Flags, self->model, 0xc2).b4 = 0;
    self->targetObj->unk_18 |= 0x10;
    self->unk_1a8 = self->pos.x;
    self->unk_1ac = self->pos.y;
    self->unk_1b0 = self->pos.z;
}

extern u8 *func_ov000_0219bf90(void);
extern void *func_ov003_021ceff4(void *p);
extern BOOL func_ov000_021983b0(void *p, s32 a, s32 b, s32 c);

static inline BOOL Ov014_TickB6(Ov014Act_02209280 *self) {
    BOOL r = FALSE;
    if (self->unk_b6 == 0) {
        r = TRUE;
    } else if (self->unk_b6 != 0xffff && self->unk_b6 != 0) {
        self->unk_b6--;
    }
    return r;
}

void Ov014Act_02209280_Update(Ov014Act_02209280 *self) {
    u8 *pl;
    if (!Ov014_GameIdle()) {
        return;
    }
    pl = func_ov000_0219bf90();
    self->target = 0xffff;
    if (pl != NULL) {
        self->target = FLD(u16, pl, 0xc);
    }
    if (self->unk_b4 != 0 && !FLD(Ov014Flags, self->unk_b0, 0xa).b12) {
        self->unk_93_4 = 1;
    }
    if (*self->hp == 0 || (self->fsm->flags & 0x200000)) {
        if (self->unk_b4 / 10 != 9) {
            self->unk_b4 = 0x5a;
        }
        *self->hp = 0;
        self->unk_93_4 = 0;
    }
    if (self->msg_flags != 0 && (self->msg_flags & 0x200)) {
        self->unk_fc = 0;
        EffectMgr_StopLoop(data_0214a420, self->unk_1dc);
        self->unk_1dc = NULL;
        EffectMgr_StopLoop(data_0214a420, self->unk_1e0);
        self->unk_1e0 = NULL;
        EffectMgr_StopLoop(data_0214a420, self->unk_1e4);
        self->unk_1e4 = 0;
    }
    switch (self->unk_b4) {
    case 0:
        if (func_ov000_021983b0(self->fsm, 0x14, 1, 1)) {
            self->unk_b4 = 0x64;
            break;
        }
        if (func_ov000_021983b0(self->fsm, 0xb, 3, 1)) {
            self->unk_b4 = 0x6e;
            break;
        }
        if (func_ov000_021983b0(self->fsm, 0x13, 1, 1)) {
            self->unk_b4 = 0x50;
        } else {
            self->unk_b4 = 10;
        }
        break;
    case 10:
        self->fsm->flags |= 2;
        self->fsm->st = 0;
        self->unk_b4 = 0x15;
        self->unk_b6 = 0xc8;
        break;
    case 0x14:
        func_ov003_021ceff4(&self->unk_1c0);
        self->unk_b4++;
    case 0x15: {
        u8 *t;
        u16 idx;
        u8 *a;
        if (!Ov014_TickB6(self) && self->fsm->st != 0xffff) {
            break;
        }
        t = self->unk_1cc;
        idx = FLD(u16, t, 8);
        a = FLD(u8 *, t, 0xc);
        self->step = (Ov014Step *)(a + idx * 8);
        switch (*(s16 *)(a + idx * 8)) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            self->unk_b4 = 0x1e;
            break;
        case 5:
        case 6:
        case 7:
            self->unk_b4 = 0x32;
            break;
        case 9:
        case 10:
            self->unk_b4 = 0x28;
            break;
        case 8:
            self->unk_b4 = 0x3c;
            break;
        case 11:
        case 12:
            self->unk_b4 = 0x78;
            break;
        case 13:
            self->unk_b4 = 0x82;
            break;
        }
        break;
    }
    case 0x1e:
        func_ov000_02198360(self->fsm, 0xe, 0);
        self->fsm->st = 0;
        self->unk_b6 = 0xffff;
        self->unk_b4++;
        break;
    case 0x1f:
        if (self->fsm->st != 0xffff) {
            break;
        }
        self->fsm->flags |= 2;
        self->fsm->st = 0;
        self->unk_b4 = 0x14;
        self->unk_b6 = self->step->unk_06;
        break;
    case 0x32:
        func_ov000_02198360(self->fsm, 0x10, 0);
        self->fsm->st = 0;
        self->unk_b6 = 0xffff;
        self->unk_b4++;
        break;
    case 0x33:
        if (self->fsm->st != 0xffff) {
            break;
        }
        self->fsm->flags |= 2;
        self->fsm->st = 0;
        self->unk_b4 = 0x14;
        self->unk_b6 = self->step->unk_06;
        break;
    case 0x28:
        func_ov000_02198360(self->fsm, 0xf, 0);
        self->fsm->st = 0;
        self->unk_b6 = 0xffff;
        self->unk_b4++;
        break;
    case 0x29:
        if (self->fsm->st != 0xffff) {
            break;
        }
        self->fsm->flags |= 2;
        self->fsm->st = 0;
        self->unk_b4 = 0x14;
        self->unk_b6 = self->step->unk_06;
        break;
    case 0x3c:
        func_ov000_02198360(self->fsm, 0x11, 0);
        self->fsm->st = 0;
        self->unk_b6 = 0xffff;
        self->unk_b4++;
        break;
    case 0x3d:
        if (self->fsm->st != 0xffff) {
            break;
        }
        self->fsm->flags |= 2;
        self->fsm->st = 0;
        self->unk_b4 = 0x14;
        self->unk_b6 = self->step->unk_06;
        break;
    case 0x46:
        if (self->fsm->current == 1) {
            self->unk_b4 = 0x14;
            self->unk_b6 = 0x3c;
        }
        break;
    case 0x47:
        if (self->fsm->st != 0xffff) {
            break;
        }
        self->fsm->flags |= 2;
        self->fsm->timer = 0;
        self->unk_b4 = 0x14;
        self->unk_b6 = 0x3c;
        break;
    case 0x50:
        if (self->fsm->current == 1) {
            self->unk_b4 = 0x14;
            self->unk_b6 = 0x3c;
        }
        break;
    case 0x5a:
        self->fsm->flags |= 0x200000;
        self->fsm->st = 0;
        self->unk_b6 = 0xffff;
        self->unk_b4++;
        break;
    case 0x64:
        self->hit->unk_9a_5 = 0;
        if (self->fsm->current == 1) {
            self->unk_b4 = 0x14;
            self->unk_b6 = 0x3c;
        }
        break;
    case 0x6e:
        self->hit->unk_9a_5 = 0;
        if (self->fsm->current == 1) {
            self->unk_b4 = 0x14;
            self->unk_b6 = 0x3c;
        }
        break;
    case 0x78:
        self->fsm->flags |= 4;
        self->fsm->st = 0;
        self->unk_b4++;
        break;
    case 0x79:
        if (self->fsm->st != 0xffff) {
            self->fsm->flags |= 4;
            break;
        }
        self->fsm->flags |= 2;
        self->fsm->timer = 0;
        self->unk_b4 = 0x14;
        self->unk_b6 = self->step->unk_06;
        self->velY = 0;
        self->gravity = 0;
        break;
    case 0x82:
        self->fsm->flags |= 0x400000000ULL;
        self->fsm->st = 0;
        self->unk_ea_0 = 4;
        self->unk_b4++;
        break;
    case 0x83:
        if (self->fsm->st != 0xffff) {
            break;
        }
        self->fsm->flags |= 2;
        self->fsm->timer = 0;
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
        self->unk_b4 = 0x14;
        self->unk_b6 = 0;
        break;
    case 0x5b:
    default:
        break;
    }
}

}
