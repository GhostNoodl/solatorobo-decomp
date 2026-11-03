#include "ov014/ov014.h"
#include "Main/Math/Rot16.h"
#include "Main/Res/ResArc.h"
#include "nitro/mi.h"


// This TU's .rodata from its base to the last vector the static initialiser copies, and its .data
// up to the second copy. The copied vectors and their sources are weak: the stub loads each through
// its own pool word, not from the section base. Everything follows the empty asm function, so it
// keeps definition (address) order.
// ov014_02201dcc.cpp and ov014_02202964.cpp (0x02201dcc..0x02202f1c) were merged in round dtB,
// each in its own namespace (02202964 read the same vector as data_ov014_02216500[0x4c..0x4e]). The first
// reads data_ov014_02216630 through the .rodata base (it was an FLD view at data_ov014_02216500 +
// 0x130), so that source is not weak; the stub still matches with it non-weak.
// Round dtD folded in the readers of 0x021fd2bc..0x02201dcc and 0x02202f1c..0x022054f8 (16 files),
// so the TU's .text is 0x021fd2bc..0x022054f8. The 24-byte s32[6] objects are two vectors each
// (0x02216588/94, 0x022165a0/ac, 0x022165c4/d0, 0x0221660c/18), 0x022165f4 is one vector (it was
// s32[1] plus s32[2] at 0x022165f8), and 0x02216510 is u16 (its reader uses ldrh).

extern "C" {

extern const char *const data_ov014_02216500[4];
extern const u16 data_ov014_02216510[3];
extern const Rot16 data_ov014_02216516;
extern const Ov003Step data_ov014_0221651c[1];
extern const Ov003Step data_ov014_02216524[1];
extern const Ov003Step data_ov014_0221652c[1];
extern const Ov003Step data_ov014_02216534[1];
extern const Ov003Step data_ov014_0221653c[1];
extern const Ov003Step data_ov014_02216544[1];
extern const s32 data_ov014_0221654c[2];
extern const s32 data_ov014_02216554[2];
extern const Ov003Step data_ov014_0221655c[1];
extern const VecFx32 data_ov014_02216564;
extern const VecFx32 data_ov014_02216570;
extern const VecFx32 data_ov014_0221657c;
extern const VecFx32 data_ov014_02216588;
extern const VecFx32 data_ov014_022165a0;
extern const VecFx32 data_ov014_022165b8;
extern const VecFx32 data_ov014_022165c4;
extern const VecFx32 data_ov014_022165dc;
extern const VecFx32 data_ov014_022165e8;
extern const VecFx32 data_ov014_022165f4;
extern const VecFx32 data_ov014_02216600;
extern const VecFx32 data_ov014_0221660c;
extern const VecFx32 data_ov014_02216624;
extern const VecFx32 data_ov014_02216630;
extern char data_ov014_02217354[];
extern char data_ov014_02217360[];
extern char data_ov014_02217366[];
extern char data_ov014_0221736c[];
extern char data_ov014_02217372[];
extern char data_ov014_0221737e[];
extern char data_ov014_02217398[];
extern char data_ov014_022173a7[];
extern char data_ov014_022173b9[];
extern char data_ov014_022173c8[];
extern char data_ov014_022173ce[];
extern char data_ov014_022173d9[];
extern Ov014Res data_ov014_022173e0;
extern const VecFx32 data_ov014_0221738c;
extern const VecFx32 data_ov014_022173e8;

static asm void Ov014_Dummy(void) {}

const char *const data_ov014_02216500[4] = {data_ov014_02217354, data_ov014_02217360, data_ov014_0221736c, data_ov014_02217366};
const u16 data_ov014_02216510[3] = {0x0, 0x5554, 0xaaa8};
const Rot16 data_ov014_02216516 = {0, 0, 0};
const Ov003Step data_ov014_0221651c[1] = {{2, 0, 0, 0x1f4}};
const Ov003Step data_ov014_02216524[1] = {{11, 0, 0, 0x1e}};
const Ov003Step data_ov014_0221652c[1] = {{10, 0, 0, 0}};
const Ov003Step data_ov014_02216534[1] = {{0, 0x78, 3, 0}};
const Ov003Step data_ov014_0221653c[1] = {{1, 0x96, 3, 0}};
const Ov003Step data_ov014_02216544[1] = {{2, 0xa, 4, 2}};
const s32 data_ov014_0221654c[2] = {0x18001800, 0x18001800};
const s32 data_ov014_02216554[2] = {0x18001800, 0x18001800};
const Ov003Step data_ov014_0221655c[1] = {{12, 0x96, 0, 0x1e}};
__declspec(weak) const VecFx32 data_ov014_02216564 = {0x0, 0x0, 0x1000};
const VecFx32 data_ov014_02216570 = {0x0, -0x1000, 0x0};
const VecFx32 data_ov014_0221657c = {0x0, 0x2000, 0x0};
const VecFx32 data_ov014_02216588 = {0x0, 0x4759a, 0x0};
const VecFx32 data_ov014_02216594 = {0x0, -0x5000, 0x4000};
const VecFx32 data_ov014_022165a0 = {0x0, 0x0, 0x1800};
const VecFx32 data_ov014_022165ac = {0x0, 0x1000, 0x4000};
const VecFx32 data_ov014_022165b8 = {0x0, 0x0, 0x1800};
const VecFx32 data_ov014_022165c4 = {0x0, 0x0, 0x1800};
const VecFx32 data_ov014_022165d0 = {0x0, 0x1800, 0x1000};
const VecFx32 data_ov014_022165dc = {0x0, 0x4759a, 0x0};
const VecFx32 data_ov014_022165e8 = {0x0, 0x4719a, 0xf000};
const VecFx32 data_ov014_022165f4 = {0x0, 0x1000, 0x0};
const VecFx32 data_ov014_02216600 = {0x0, 0x0, 0x9000};
const VecFx32 data_ov014_0221660c = {0x0, -0x1000, 0x0};
const VecFx32 data_ov014_02216618 = {0x0, 0x0, -0x1800};
const VecFx32 data_ov014_02216624 = {0x0, 0x0, 0x1800};
const VecFx32 data_ov014_02216630 = {0x0, 0x0, 0x0};
char data_ov014_02217354[6] = "run00";
static const Rot16 data_ov014_0221735a = data_ov014_02216516;
char data_ov014_02217360[] = "att00";
char data_ov014_02217366[] = "nut00";
char data_ov014_0221736c[] = "att01";
char data_ov014_02217372[] = "ef3di1lcr11";
char data_ov014_0221737e[] = "ef3di1lcr10";
__declspec(weak) const VecFx32 data_ov014_0221738c = data_ov014_02216630;
char data_ov014_02217398[] = "ef/effect3dlcr";
char data_ov014_022173a7[] = "ef3di1lcr12.cceff";
char data_ov014_022173b9[] = "ef/effect3dlcr";
char data_ov014_022173c8[] = "nut01";
char data_ov014_022173ce[] = "blt/b1sha1";
char data_ov014_022173d9[] = "b1sha1";
Ov014Res data_ov014_022173e0 = {data_ov014_02217398, 0x37};
__declspec(weak) const VecFx32 data_ov014_022173e8 = data_ov014_02216564;

}


// ---- merged from ov014_021fd2bc.cpp
namespace m_021fd2bc {
typedef void (Ov003Actor::*Ov014ActorPmf)();

struct Ov014PmfEntry {
    u32 kind;
    Ov014ActorPmf fn;
};

struct Ov014D8a4Sub44 {
    VecFx32 pos;
    s32 unk_0c;
    s32 unk_10;
    u8 unk_14[0x8];
    s32 unk_1c;
    u8 unk_20[0x2];
    u16 unk_22_0 : 4;
    u16 unk_22_4 : 1;
    u16 unk_22_5 : 11;
};

struct Ov014D8a4Icon {
    u8 unk_00[0x50];
    VecFx32 pos;
    s32 unk_5c;
};

extern "C" {

extern u8 Ov014Act_021fd4d4_vtbl[];
extern void *Ov003Vt_021f7d10_Ctor(void *p);
extern void *Ov003Vt_021f7d10_Dtor(void *p);
extern void SndMgr_Stop(void *a, s32 b);
extern BOOL Actor_IsReady(Ov003Actor *self);
extern BOOL Ov003TickerSet_IsHeld(void *p);
extern void Ov003TickerSet_Apply(void *p, VecFx32 *a, VecFx32 *b, s32 c);

void Ov014ActEx_021fc24c_StateFly(Ov014ActEx_021fc24c *self) {
    History_SetState(self->fsm, 0x15, 0);
}

void Ov014ActEx_021fc24c_StateDie(Ov014ActEx_021fc24c *self) {
    if (self->unk_f8 & 0x100000) {
        Group_UpdateActor(gGroup, 0, self);
        self->vfunc_08();
    } else {
        ActorEx_StateDie(self);
    }
    if (self->unk_fc != 0) {
        Ov003FxList_Kill(self->unk_100, 0xff);
    }
}

void Ov014ActorEx_Animate(Ov003Actor *self) {
    if (self->model != NULL) {
        Model0218fe1c_UpdateAnim(self->model, func_0203db40((u8 *)self + 0x24));
    }
}

void Ov014ActorEx_State23(void) {
}

void Ov014ActorEx_State22(void) {
}

void Ov014ActorEx_State21(void) {
}

void Ov014ActorEx_State20(void) {
}

void Ov014ActorEx_StateHurt(void) {
}

void Ov014ActorEx_State0e(void) {
}

void Ov014ActorEx_StateMove(void) {
}

void Ov014_SelectTrackByHp(Ov003ScriptList *self, Ov003Actor *a) {
    Ov003Track *q = self->cur;
    s32 pct = (u16)(a->hp[0] * 100 / a->hp[1]);
    if (pct >= 80) {
        if (q->id != 0) {
            Ov003ScriptList_SelectTrack(self, 0, 0);
        }
    } else if (pct >= 55) {
        if (q->id != 1) {
            Ov003ScriptList_SelectTrack(self, 1, 0);
        }
    } else if (pct >= 30) {
        if (q->id != 2) {
            Ov003ScriptList_SelectTrack(self, 2, 0);
        }
    } else {
        if (q->id != 3) {
            Ov003ScriptList_SelectTrack(self, 3, 0);
        }
    }
}

void Ov014_SelectTrackByHp_021fd43c(Ov003ScriptList *self, Ov003Actor *a) {
    Ov003Track *q = self->cur;
    s32 pct = (u16)(a->hp[0] * 100 / a->hp[1]);
    if (pct >= 75) {
        if (q->id != 10) {
            Ov003ScriptList_SelectTrack(self, 10, 0);
        }
    } else if (pct >= 55) {
        if (q->id != 11) {
            Ov003ScriptList_SelectTrack(self, 11, 0);
        }
    } else {
        if (q->id != 12) {
            Ov003ScriptList_SelectTrack(self, 12, 0);
        }
    }
}

#pragma force_active on
Ov003Actor *Ov014Act_021fd4d4_Ctor(Ov014Act_021fd4d4 *self) {
    Ov003Actor_Ctor(self);
    *(void **)self = Ov014Act_021fd4d4_vtbl;
    Ov003Vt_021f7d10_Ctor((u8 *)self + 0x100);
    Ov003ScriptList_Init(&self->scripts);
    Ov003ScriptList_Init(&self->scripts2);
    self->unk_f4 = 0;
    self->unk_138 = 0;
    self->unk_f8 = 0xff;
    self->unk_fc = NULL;
    self->step = NULL;
    self->step2 = NULL;
    self->unk_f9 = 0;
    self->unk_13a = 0x1000;
    return self;
}
#pragma force_active reset

static inline void Ov014_StopSnd(void) {
    if (ResMgr_IsLoaded(data_ov014_022173b9, 7)) {
        ResMgr_ReleaseByName(gResMgr, data_ov014_022173b9, 7, 0);
    }
}

static inline void Ov014_FreeFC(Ov014Act_021fd4d4 *self) {
    void *saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (self->unk_fc != NULL) {
        Ov003FxList *p = self->unk_fc;
        if (p != NULL) {
            Ov003FxList_Dtor(p);
            Heap_Free(p);
        }
        self->unk_fc = NULL;
    }
    gSysState->cur = saved;
}

Ov014Act_021fd4d4 *Ov014Act_021fd4d4_Dtor(Ov014Act_021fd4d4 *self) {
    *(void **)self = Ov014Act_021fd4d4_vtbl;
    Ov014_FreeFC(self);
    ((Ov014V *)((u8 *)self + 0x100))->v08();
    SndMgr_Stop(gSndMgr, 0x38);
    Ov014_StopSnd();
    Ov003Vt_021f7974_Dtor(&self->scripts2);
    Ov003Vt_021f7974_Dtor(&self->scripts);
    Ov003Vt_021f7d10_Dtor((u8 *)self + 0x100);
    Ov003Actor_DtorBase(self);
    return self;
}

Ov014Act_021fd4d4 *Ov014Act_021fd4d4_DtorDelete(Ov014Act_021fd4d4 *self) {
    *(void **)self = Ov014Act_021fd4d4_vtbl;
    Ov014_FreeFC(self);
    ((Ov014V *)((u8 *)self + 0x100))->v08();
    SndMgr_Stop(gSndMgr, 0x38);
    Ov014_StopSnd();
    Ov003Vt_021f7974_Dtor(&self->scripts2);
    Ov003Vt_021f7974_Dtor(&self->scripts);
    Ov003Vt_021f7d10_Dtor((u8 *)self + 0x100);
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

void Ov014Act_021fd4d4_Init(Ov014Act_021fd4d4 *self) {
    Ov003Actor_Init(self);
    ResMgr_Load(data_ov014_022173b9, 7, 0);
    self->unk_f0 = self->unk_18;
}

BOOL Ov014Act_021fd4d4_IsReady(Ov014Act_021fd4d4 *self) {
    BOOL r = Actor_IsReady(self);
    return (r & ResMgr_IsLoaded(data_ov014_022173b9, 7)) ? TRUE : FALSE;
}

BOOL Ov014Act_021fd4d4_Draw(Ov014Act_021fd4d4 *self) {
    BOOL r;
    VecFx32 saved = self->pos;
    if (!Ov003TickerSet_IsHeld((u8 *)self + 0x100)) {
        if (self->hp[0] != 0 && self->unk_f0 == 1) {
            VecFx32 t = self->pos;
            VecFx32 d;
            s16 dir = self->unk_1a;
            if (dir == 0) {
                t.y += 0x1000;
            } else {
                t.y -= 0x1000;
            }
            d.x = t.x - self->unk_12c.x;
            d.y = t.y - self->unk_12c.y;
            d.z = t.z - self->unk_12c.z;
            VEC_MultAdd(0x29, &d, &self->unk_12c, &self->pos);
            self->unk_12c = self->pos;
            if (VEC_Distance(&self->pos, &t) <= 0x800) {
                if (dir == 0) {
                    self->unk_1a = 1;
                } else {
                    self->unk_1a = 0;
                }
            }
        }
        Ov003TickerSet_Apply((u8 *)self + 0x100, &self->pos, &self->pos, 0x300);
    }
    r = Ov003Actor_Draw(self);
    self->pos = saved;
    return r;
}

extern const Ov014PmfEntry data_ov014_022168c4[];
extern void func_ov000_0219af3c(Ov003Actor *self, void *icon);
extern void ActorMarker_Update(void *icon);
extern void Geom_AddRotatedOffset(VecFx32 *pos, VecFx32 *v, u16 ang);

static inline void Ov014_Dispatch(Ov003Actor *self, u32 kind) {
    s32 i;
    for (i = 0; i < 0x15; i++) {
        if (data_ov014_022168c4[i].kind != kind) {
            continue;
        }
        (self->*data_ov014_022168c4[i].fn)();
        return;
    }
}

void Ov014Act_021fd4d4_RunState(Ov014Act_021fd4d4 *self) {
    switch (self->unk_f0) {
    case 0:
        self->unk_ec = 0;
        Ov014_Dispatch(self, self->fsm->current);
        if (self->unk_5c != NULL && Ov014_GameIdle()) {
            VecFx32 pos;
            s32 r;
            func_ov000_0219af3c(self, self->unk_5c);
            if (self->unk_44 != NULL) {
                Ov014D8a4Sub44 *s44 = (Ov014D8a4Sub44 *)self->unk_44;
                pos = s44->pos;
                if (s44->unk_22_4) {
                    VecFx32 v;
                    v.z = s44->unk_1c;
                    v.x = 0;
                    v.y = 0;
                    Geom_AddRotatedOffset(&pos, &v, self->rot_y);
                }
                r = ((Ov014D8a4Sub44 *)self->unk_44)->unk_10;
                if (r == 0) {
                    r = ((Ov014D8a4Sub44 *)self->unk_44)->unk_1c;
                }
            } else {
                pos = self->pos;
                r = self->height;
                if (r == 0) {
                    r = self->radius;
                }
            }
            ((Ov014D8a4Icon *)self->unk_5c)->pos = pos;
            ((Ov014D8a4Icon *)self->unk_5c)->unk_5c = r;
            ActorMarker_Update(self->unk_5c);
        }
        self->fsm->flags = 0;
        break;
    case 1:
        Ov003Actor_RunState(self);
        break;
    }
    ((Ov014V *)((u8 *)self + 0x100))->v0c();
}

}
}  // namespace m_021fd2bc

// ---- merged from ov014_021fda78.cpp
namespace m_021fda78 {
extern "C" {

extern s32 Ov014Act_021fd4d4_HandleMsg6(Ov014Act_021fd4d4 *self, Ov014Msg *msg);
extern s32 Ov003Actor_HandleMsg(Ov003Actor *self, Ov014Msg *msg);

s32 Ov014Act_021fd4d4_HandleMsg(Ov014Act_021fd4d4 *self, Ov014Msg *msg) {
    s32 r = 0;
    switch (self->unk_f0) {
    case 0:
        r = Ov014Act_021fd4d4_HandleMsg6(self, msg);
        break;
    case 1:
        if (msg->type == 6) {
            self->unk_f8 = msg->idx;
            switch (msg->id) {
            case 0x482b:
                break;
            case 0x580c:
            case 0x580d:
            case 0x580e: {
                u16 n = self->unk_f8 - 1;
                if (!(n != 0 && n != 1 && n != 2)) {
                    u8 bit = 1 << n;
                    if (self->unk_138 & bit) {
                        self->unk_138 ^= bit;
                    }
                    self->unk_f8 = 0xff;
                    self->unk_f4 |= 1;
                }
                break;
            }
            }
            self->msg_flags |= 1 << msg->type;
            msg->type = 0;
            r = 0;
        } else {
            r = Ov003Actor_HandleMsg(self, msg);
        }
        break;
    }
    return r;
}

extern const VecFx32 data_ov014_02216704[];
extern const Ov003Step data_ov014_02216740[];
extern const Ov003Step data_ov014_022166aa[];
extern const Ov003Step data_ov014_022166d2[];
extern const Ov003Step data_ov014_02216788[];
extern const Ov003Step data_ov014_0221686c[];
extern BOOL Ov003TickerSet_Init(void *p);
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern void HitSphere_Link(ActorSub48 *p);
extern BOOL Stage_UseScaledStats(void);
extern void Vec_RotateY(VecFx32 *a, const VecFx32 *b, u16 ang);
extern void Ov014_SelectTrackByHp(Ov003ScriptList *self, Ov003Actor *a);
extern void Ov014_SelectTrackByHp_021fd43c(Ov003ScriptList *self, Ov003Actor *a);

void Ov014Act_021fd4d4_Start(Ov014Act_021fd4d4 *self) {
    VecFx32 w;
    VecFx32 v;
    Ov003Unit *u;
    ActorSub48 *m;
    Ov003Actor_Start(self);
    self->unk_fc = Ov014_NewFx();
    Ov003TickerSet_Init((u8 *)self + 0x100);
    u = Group_FindNode(gGroup, self->unk_20);
    if (u != NULL) {
        u->unk_a2_0 = 0;
    }
    m = self->hit;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    m = self->hit;
    m->unk_9a_2 = 0;
    m->unk_9a_5 = 0;
    self->hit->unk_30 = 0;
    m = self->hit;
    m->offset.x = 0;
    m->offset.y = -0xb33;
    m->offset.z = 0;
    switch (self->unk_f0) {
    case 0: {
        u8 i;
        ActorSub44 *n;
        self->unk_f4 |= 0x40;
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        m = self->hit;
        m->unk_9a_0 = 0;
        m->unk_9a_3 = 0;
        HitSphere_Unlink_0203f364(m);
        for (i = 0; i < 5; i++) {
            Actor *o = Ov003Actor_SpawnAtSelf(self, 0x5c19, 0x20);
            if (o != NULL) {
                o->unk_18 = i;
                v = data_ov014_02216704[i];
                Vec_RotateY(&v, &v, self->rot_y);
                VEC_Add(&self->pos, &v, &v);
                o->pos.x = v.x;
                o->pos.y = v.y;
                o->pos.z = v.z;
            }
        }
        break;
    }
    case 1:
        self->unk_139 = 0;
        Vec_RotateY(&w, &data_ov014_02216564, self->rot_y);
        VEC_Add(&self->pos, &w, &self->pos);
        self->unk_93_4 = 1;
        m = self->hit;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        HitSphere_Link(m);
        self->unk_12c.x = self->pos.x;
        self->unk_12c.y = self->pos.y;
        self->unk_12c.z = self->pos.z;
        break;
    }
    if (Stage_UseScaledStats()) {
        Ov003Actor_ScaleStats(self, data_ov014_0221654c);
        self->unk_13a = 0x1800;
    }
    switch (self->unk_f0) {
    case 0:
        Ov003ScriptList_AddTrack(&self->scripts, 0, 9, data_ov014_02216740);
        break;
    case 1:
        Ov003ScriptList_AddTrack(&self->scripts, 0, 5, data_ov014_022166aa);
        Ov003ScriptList_AddTrack(&self->scripts, 1, 6, data_ov014_022166d2);
        Ov003ScriptList_AddTrack(&self->scripts, 2, 9, data_ov014_02216788);
        Ov003ScriptList_AddTrack(&self->scripts, 3, 11, data_ov014_0221686c);
        Ov003ScriptList_AddTrack(&self->scripts2, 10, 1, data_ov014_0221652c);
        Ov003ScriptList_AddTrack(&self->scripts2, 11, 1, data_ov014_02216524);
        Ov003ScriptList_AddTrack(&self->scripts2, 12, 1, data_ov014_0221655c);
        self->scripts.arg = self;
        self->scripts2.arg = self;
        self->scripts.func = (Ov003ScriptFunc)Ov014_SelectTrackByHp;
        self->scripts2.func = (Ov003ScriptFunc)Ov014_SelectTrackByHp_021fd43c;
        break;
    }
}

}
}  // namespace m_021fda78

// ---- merged from ov014_021fdedc.cpp
namespace m_021fdedc {
extern "C" {

extern Ov003Actor *ActorMgr_FindPlayer(void);
extern void func_ov014_021fe0dc(Ov014Act_021fd4d4 *self);
extern void func_ov014_021fe210(Ov014Act_021fd4d4 *self);
extern s32 Ov003Actor_HandleMsg(Ov003Actor *self, Ov014Msg *msg);
extern void ActorMgr_SendToKindOthers(s32 a, u16 b, s32 c, s32 d, s32 e, u8 *f);
extern s32 Ov003_CountActorsOfKind(s32 a);

void Ov014Act_021fd4d4_Update(Ov014Act_021fd4d4 *self) {
    if (!Ov014_GameIdle()) {
        return;
    }
    {
        Ov003Actor *a;
        self->target = 0xffff;
        a = ActorMgr_FindPlayer();
        if (a != NULL) {
            self->target = a->id;
        }
    }
    if (self->fsm->current == 1 && self->unk_93_4) {
        s32 f = self->unk_f4;
        if (f == 0) {
            switch (self->unk_f0) {
            case 0:
                func_ov014_021fe0dc(self);
                break;
            case 1:
                func_ov014_021fe210(self);
                break;
            }
        } else if ((f & 1) && self->unk_138 == 0) {
            u16 lim = 30;
            const Ov003Step *p = self->step;
            if (p != NULL) {
                lim = p->b;
            }
            self->unk_b6++;
            if (self->unk_b6 >= lim) {
                self->unk_f4 ^= 1;
                self->unk_b6 = 0;
            }
        }
    }
    Ov003FxList_Prune(self->unk_fc);
}

s32 Ov014Act_021fd4d4_HandleMsg6(Ov014Act_021fd4d4 *self, Ov014Msg *msg) {
    switch (msg->type) {
    case 6: {
        u8 v = msg->idx;
        u16 n = v - 3;
        self->unk_f8 = v;
        switch (n) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4: {
            u8 bit = 1 << n;
            if (self->unk_138 & bit) {
                self->unk_138 ^= bit;
            }
            self->unk_f8 = 0xff;
            self->unk_f4 = 1;
            break;
        }
        }
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
        break;
    }
    case 14:
        self->unk_138 |= (u8)(1 << msg->unk_08);
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
        break;
    }
    return Ov003Actor_HandleMsg(self, msg);
}

void func_ov014_021fe0dc(Ov014Act_021fd4d4 *self) {
    u8 c;
    ActorSub40 *st;
    switch (self->unk_b4) {
    case 0:
        if (self->unk_138 == 0) {
            Ov003Track *t = self->scripts.cur;
            self->step = &t->steps[t->val];
            Ov003ScriptList_Step(&self->scripts);
            c = self->step->op;
            ActorMgr_SendToKindOthers(0x5c19, self->kind, 0xe, 1, 1, &c);
            self->fsm->timer = 0;
            self->unk_b4++;
        }
        break;
    case 1:
        st = self->fsm;
        st->timer++;
        if (st->timer < 10) {
            if (self->unk_f8 == 2) {
                self->unk_f8 = 0xff;
                self->unk_f4 |= 0x100000;
                self->fsm->timer = 0;
                self->unk_b4 = 0;
            }
        } else {
            self->fsm->timer = 0;
            self->unk_b4 = 0;
        }
        break;
    }
    if (!(self->unk_f4 & 0x1000) && !Ov003_CountActorsOfKind(0x5c19)) {
        self->unk_f4 |= 0x1000;
        History_SetState(self->fsm, 0x15, 0);
    }
}

}
}  // namespace m_021fdedc

// ---- merged from ov014_021fe210.cpp
namespace m_021fe210 {
struct Ov014SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov014Spawn_Init(Ov014SpawnDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

static inline void Ov014Spawn_Set(Ov014SpawnDesc *d, u16 k) {
    d->kind = k;
    d->flags = k & 0xf000;
}

extern "C" {

struct Ov014V12 { s32 a[3]; };
extern const VecFx32 data_ov014_02216818[];
extern s32 Ov003_CountActorsOfKind(s32 a);
extern void Ov003TickerSet_SetPaused(void *p, s32 a);
extern void Ov003TickerSet_Start(void *p, s32 a, s32 b, s32 c, s32 d);
extern Ov003Actor *Factory_New4000(Ov014SpawnDesc *desc);

static inline const Ov003Step *Ov014_AnimCur(Ov003Track *t) {
    return &t->steps[t->val];
}

void func_ov014_021fe210(Ov014Act_021fd4d4 *self) {
    u8 m = self->unk_138;
    if (m == 0) {
        Ov003Track *t = self->scripts.cur;
        self->step = &t->steps[t->val];
        Ov003ScriptList_Step(&self->scripts);
        switch (self->step->op) {
        case 0:
        case 1:
        case 2:
            self->unk_f4 |= 4;
            self->fsm->flags |= 0x8000;
            break;
        case 3:
        case 4:
            self->unk_f4 |= 0x200000;
            self->unk_f4 |= 4;
            self->fsm->flags |= 0x8000;
            break;
        case 5:
            self->unk_f4 |= 0x10;
            self->fsm->flags |= 0x20000;
            break;
        }
    } else {
        s32 pct = (u16)(self->hp[0] * 100 / self->hp[1]);
        if (pct >= 30) {
            if (!(m & 0x80)) {
                if (!Ov003_CountActorsOfKind(0x482b)) {
                    self->unk_138 |= 0x80;
                } else if (self->msg_flags & 0x40) {
                    if (self->unk_f8 == 10) {
                        self->unk_138 |= 0x80;
                    }
                    self->unk_f8 = 0xff;
                }
            }
            if (self->unk_138 & 0x80) {
                Ov003Track *t;
                Ov003ScriptList_Step(&self->scripts2);
                t = self->scripts2.cur;
                self->step2 = Ov014_AnimCur(t);
                switch (self->step2->op) {
                case 10:
                    self->unk_138 ^= 0x80;
                    break;
                case 11:
                case 12:
                    self->unk_f4 |= 8;
                    self->fsm->flags |= 0x10000;
                    break;
                }
            }
        }
    }
    if ((self->msg_flags & 0x200) && self->hp[0] != 0) {
        Ov003TickerSet_SetPaused((u8 *)self + 0x100, 0);
        Ov003TickerSet_Start((u8 *)self + 0x100, 0x1e, 0, 0, 0);
    }
}
void func_ov014_021fe3ec(Ov014Act_021fd4d4 *self) {
    Ov014SpawnDesc desc;
    Ov003Actor *o;
    Ov014Spawn_Init(&desc, 0xffff);
    Ov014Spawn_Set(&desc, 0x482b);
    o = Factory_New4000(&desc);
    if (o == NULL) {
        return;
    }
    {
        const VecFx32 *p = &data_ov014_02216818[self->unk_139];
        o->pos.x = p->x;
        o->pos.y = p->y;
        o->pos.z = p->z;
    }
    if (++self->unk_139 >= 7) {
        self->unk_139 = 0;
    }
    o->vfunc_04();
    o->flags_0 = 1;
    o->target = self->target;
    if (o->targetObj != NULL) {
        o->targetObj->target = self->id;
    }
}

extern void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);
extern void *SndMgr_PlayAtPitch(void *a, s32 b, VecFx32 *c, s32 d);
extern void ActorMgr_SendToKindOthers(s32 a, u16 b, s32 c, s32 d, s32 e, void *f);
extern void Model0218fe1c_ResumeAnim(void *a);
void Shared_SetEventActor(u16 a, u16 b);
void func_020627dc(s32 a);

void Ov014Act_021fd4d4_State21(Ov014Act_021fd4d4 *self) {
    VecFx32 v1;
    VecFx32 v2;
    u8 b;
    if (self->unk_f0 != 0) {
        return;
    }
    switch (self->fsm->st) {
    case 0:
        b = 1;
        ActorMgr_SendToKindOthers(0x5c19, self->kind, 6, 1, 1, &b);
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    case 1: {
        EffectObj *e;
        if (self->unk_f8 != 1) {
            break;
        }
        self->unk_f8 = 0;
        e = Effect_SpawnId(0x68, &self->pos);
        e->SetScaleAll(0x4000);
        e->SetRotXYZ(0xbfff, self->rot_y, 0);
        e->SetOffset(&data_ov014_02216564);
        Model0218fe1c_ResumeAnim(self->model);
        Model0218fe1c_SetLoop(self->model);
        *(Ov014V12 *)&v1 = *(const Ov014V12 *)&data_ov014_02216600;
        VEC_Add(&v1, &self->pos, &v1);
        SndMgr_PlayAt(gSndMgr, 0x5b, &v1, 0);
        self->fsm->st++;
        break;
    }
    case 2:
        self->fsm->timer++;
        if (self->fsm->timer == 0x78) {
            b = 2;
            ActorMgr_SendToKindOthers(0x5c19, self->kind, 6, 1, 1, &b);
        } else if (self->fsm->timer == 0xdc) {
            self->unk_f4 ^= 0x40;
            self->unk_93_4 = 1;
            Shared_SetEventActor(self->kind, self->id);
            func_020627dc(4);
            gSceneCmd->stageFlags = 1;
        }
        if (Ov014_GameIdle()) {
            self->fsm->timer = 0;
            History_SetState(self->fsm, 1, 0);
        }
        if (self->fsm->timer % 0x44 == 0) {
            *(Ov014V12 *)&v2 = *(const Ov014V12 *)&data_ov014_02216600;
            VEC_Add(&v2, &self->pos, &v2);
            SndMgr_PlayAtPitch(gSndMgr, 0x39, &v2, -5);
        }
        break;
    }
}

extern void SndMgr_Stop(void *a, s32 b);
extern void Field_ShakeCamera(s32 a, s32 b);
extern void Ov003TickerSet_SetPaused(void *p, s32 a);

void Ov014Act_021fd4d4_State22(Ov014Act_021fd4d4 *self) {
    VecFx32 v;
    EffectObj *e;
    ActorSub40 *w;
    if (self->unk_f0 == 1) {
        *(Ov014V12 *)&v = *(const Ov014V12 *)&data_ov014_02216600;
        VEC_Add(&v, &self->pos, &v);
        w = self->fsm;
        switch (w->st) {
        case 0:
            Model0218fe1c_SetAnim(self->model, data_ov014_02216500[3], 0x400, 0);
            Model0218fe1c_SetLoop(self->model);
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            self->unk_f9 = 0;
            self->fsm->st++;
            break;
        case 1:
            w->timer++;
            if (w->timer >= 0x32 || self->unk_f9 != 0) {
                e = Effect_SpawnId(0x68, &self->pos);
                e->SetScaleAll(0x4000);
                e->AddPosXYZ(0, -0x2000, 0);
                SndMgr_PlayAt(gSndMgr, 0x44, &v, 0);
                SndMgr_PlayAt(gSndMgr, 0x27, &v, 0);
                Ov003FxList_Add(self->unk_fc, 0xff, e);
                self->unk_f9++;
                self->fsm->timer = 0;
                self->fsm->st++;
            }
            break;
        case 2: {
            BOOL r = Ov003FxList_Has(self->unk_fc, 0xff);
            if (self->unk_f9 >= 3) {
                if (!r) {
                    Model0218fe1c_SetAnim(self->model, data_ov014_02216500[2], 0x400, 0);
                    SndMgr_PlayAt(gSndMgr, 0x39, &v, 0);
                    self->fsm->st++;
                }
            } else if (!r) {
                Field_ShakeCamera(5, 0x14);
                self->fsm->st = 1;
            }
            break;
        }
        case 3:
            if (Model0218fe1c_IsAnimDone(self->model)) {
                Ov003TickerSet_SetPaused((u8 *)self + 0x100, 1);
                Field_ShakeCamera(10, 0x28);
                e = Effect_SpawnId(0x69, &self->pos);
                SndMgr_PlayAt(gSndMgr, 0x5c, &v, 0);
                SndMgr_PlayAt(gSndMgr, 0x1a, &v, 0);
                Ov003FxList_Add(self->unk_fc, 0xff, e);
                Model0218fe1c_SetAnim(self->model, data_ov014_022173c8, 0x89, 0);
                Model0218fe1c_SetLoop(self->model);
                self->fsm->st = 0x1e;
            }
            break;
        case 0x1e:
            w->timer++;
            if (w->timer >= 0x32) {
                SndMgr_Stop(gSndMgr, 0x38);
                Shared_SetEventActor(self->kind, self->id);
                func_020627dc(4);
                gSceneCmd->stageFlags = 1;
                self->fsm->timer = 0;
                self->fsm->st++;
            }
            break;
        }
        {
            EffectObj *o = Effect_Find_020657b0(gEffectMgr, Ov003FxList_Get(self->unk_fc, 0xff));
            if (o != NULL) {
                o->SetScaleAll(o->scale.x + 0x59a);
            }
        }
    }
    Ov003FxList_Prune(self->unk_fc);
}

}
}  // namespace m_021fe210

// ---- merged from ov014_021feae8.cpp
namespace m_021feae8 {
extern "C" {

void Model0218fe1c_PauseAnim(void *a);
void *Model0218fe1c_SetAnimFrame(void *a, s32 b);
s32 Actor_FindInRadius(Actor *self, u16 mask, VecFx32 *p, s32 r, s32 a, void **out);
Ov003Actor *Obj021984c8_GetActor(void *p);
void Actor_SendMsgU8(void *o, u16 id, s32 c);

#pragma force_active on
void Ov014Act_021fd4d4_StateIdle(Ov014Act_021fd4d4 *self) {
    switch (self->unk_f0) {
    case 0: {
        VecFx32 p;
        void *ids[32];
        s32 n;
        s32 i;
        if (self->fsm->st == 0) {
            Model0218fe1c_SetAnim(self->model, data_ov014_022173c8, 0x89, 0);
            if (((u32)self->unk_f4) & 0x40) {
                Model0218fe1c_PauseAnim(self->model);
                Model0218fe1c_SetAnimFrame(self->model, 0);
            } else {
                Model0218fe1c_SetLoop(self->model);
            }
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            self->fsm->st++;
        }
        p.x = self->hit->check.x;
        p.y = self->hit->check.y;
        p.z = self->hit->check.z;
        n = Actor_FindInRadius(self, 0xffdf, &p, self->hit->radius, 0, ids);
        if (n == 0) {
            return;
        }
        for (i = 0; i < n; i++) {
            if (ids[i] != NULL) {
                Ov003Actor *a = Obj021984c8_GetActor(ids[i]);
                if (a != NULL) {
                    u16 id = a->id;
                    if ((u16)(a->targetObj->target & 0xf000) != 0x5000) {
                        if (Actor_GetTargetSub44(a) != NULL) {
                            return;
                        }
                        Actor_SendMsgU8(a, id, 0x15);
                        return;
                    } else {
                        Actor_SendMsgU8(a, id, 0x15);
                        return;
                    }
                }
            }
        }
        break;
    }
    case 1:
        if (self->fsm->st == 0) {
            Model0218fe1c_SetAnim(self->model, data_ov014_02216500[3], 0x89, 0);
            Model0218fe1c_SetLoop(self->model);
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            self->fsm->st++;
        }
        break;
    }
}
#pragma force_active reset
extern void Model0218fe1c_SetAnimSpeed(void *a, s32 b);
extern void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);
extern void ActorMgr_BroadcastKind(void *mgr, s32 a, s32 b);
extern s32 Ov003_CountActorsOfKind(s32 kind);
extern void Vec_RotateY(VecFx32 *a, VecFx32 *b, u16 ang);

static inline void Ov014_SpawnPart(Ov014Act_021fd4d4 *self, u16 kind, u8 bit, s16 n) {
    Actor *o;
    self->unk_138 |= bit;
    o = Ov003Actor_SpawnAtSelf(self, kind, 0x20);
    if (o != NULL) {
        VecFx32 v;
        o->unk_18 = n;
        v.x = 0;
        v.y = 0;
        v.z = 0x9000;
        Vec_RotateY(&v, &v, self->rot_y);
        VEC_Add(&self->pos, &v, &v);
        o->pos.x = v.x;
        o->pos.y = v.y;
        o->pos.z = v.z;
    }
}

#pragma force_active on
void Ov014Act_021fd4d4_StateAttack(Ov014Act_021fd4d4 *self) {
    u16 lim = 0;
    if (self->unk_f0 != 1) {
        return;
    }
    switch (self->fsm->st) {
    case 0: {
        EffectObj *e;
        Model0218fe1c_SetAnim(self->model, data_ov014_02216500[2], 0x400, 0);
        self->fsm->st++;
        e = Effect_SpawnId(0x648, &self->pos);
        e->AddPosXYZ(0, 0, 0x7000);
        e->SetScaleAll(0x2000);
        break;
    }
    case 1:
        if (self->model->anim_state != 1) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, data_ov014_02216500[1], 0x400, 0);
        Model0218fe1c_SetAnimSpeed(self->model, 0x2000);
        SndMgr_PlayAt(gSndMgr, 0x44, &self->pos, 0);
        self->fsm->st++;
        break;
    case 2:
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, data_ov014_02216500[3], 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        if (self->unk_f4 & 0x200000) {
            ActorMgr_BroadcastKind(gActorMgr, 0x482b, 0x15);
        }
        self->fsm->st++;
        break;
    case 3: {
        s32 n = self->step->op;
        switch (n) {
        case 0:
            Ov014_SpawnPart(self, 0x580c, 1, 0);
            break;
        case 1:
            Ov014_SpawnPart(self, 0x580d, 2, 1);
            break;
        case 2:
            Ov014_SpawnPart(self, 0x580e, 4, 2);
            break;
        case 3:
            if (self->unk_f4 & 0x200000) {
                Ov014_SpawnPart(self, 0x580e, 4, 2);
                self->fsm->st = 0x14;
            } else {
                Ov014_SpawnPart(self, 0x580c, 1, 0);
                self->fsm->st = 0x15;
            }
            break;
        case 4:
            if (self->unk_f4 & 0x200000) {
                Ov014_SpawnPart(self, 0x580e, 4, 2);
                self->fsm->st = 0x14;
            } else {
                Ov014_SpawnPart(self, 0x580d, 2, 1);
                self->fsm->st = 0x15;
            }
            break;
        }
        switch (n) {
        case 0:
        case 1:
        case 2:
            self->fsm->st = 0x1e;
            break;
        }
        break;
    }
    case 0x14: {
        ActorSub40 *s = self->fsm;
        if (self->step != NULL) {
            lim = self->step->time;
        }
        s->timer++;
        if (s->timer < lim) {
            return;
        }
        if (self->unk_f4 & 0x200000) {
            self->unk_f4 ^= 0x200000;
        }
        self->fsm->st = 3;
        break;
    }
    case 0x15: {
        s32 c = 0;
        s32 k = 0x580c;
        c += Ov003_CountActorsOfKind(k);
        c += Ov003_CountActorsOfKind(k + 1);
        c += Ov003_CountActorsOfKind(k + 2);
        if (c != 0) {
            return;
        }
        if (self->unk_f4 & 4) {
            self->unk_f4 ^= 4;
        }
        History_SetState(self->fsm, 1, 0);
        break;
    }
    case 0x1e: {
        ActorSub40 *s = self->fsm;
        if (self->step != NULL) {
            lim = self->step->time;
        }
        s->timer++;
        if (s->timer < lim) {
            return;
        }
        if (self->unk_f4 & 4) {
            self->unk_f4 ^= 4;
        }
        History_SetState(self->fsm, 1, 0);
        break;
    }
    }
}
#pragma force_active reset

}
}  // namespace m_021feae8

// ---- merged from ov014_021ff318.cpp
namespace m_021ff318 {
struct Ov014SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov014Spawn_Init(Ov014SpawnDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

static inline void Ov014Spawn_Set(Ov014SpawnDesc *d, u16 k) {
    d->kind = k;
    d->flags = k & 0xf000;
}

extern "C" {

extern void *SndMgr_PlayAtPitch(void *a, s32 b, VecFx32 *c, s32 d);
extern s32 Ov003_CountActorsOfKind(s32 id);
extern void func_ov014_021fe3ec(Ov014Act_021fd4d4 *self);

void Ov014Act_021fd4d4_StateAttack2(Ov014Act_021fd4d4 *self) {
    if (self->unk_f0 != 1) {
        return;
    }
    switch (self->fsm->st) {
    case 0: {
        EffectObj *e = Effect_SpawnId(0x2bd, &self->pos);
        e->AddPosXYZ(0, 0, 0x7000);
        e->SetScaleAll(0x8000);
        e->SetRotXYZ(0x4000, 0, 0);
        Ov003FxList_Add(self->unk_fc, 0, e);
        self->fsm->st++;
    }
    case 1: {
        u8 i;
        if (Ov003FxList_Has(self->unk_fc, 0)) {
            return;
        }
        for (i = 0; i < 2; i++) {
            EffectObj *e = Effect_SpawnId(0x57e, &self->pos);
            e->AddPosXYZ(0, 0, 0x7000);
            e->SetScaleAll(0x3000);
            SndMgr_PlayAtPitch(gSndMgr, 0x79, &self->pos, -5);
        }
        self->fsm->st++;
        break;
    }
    case 2: {
        ActorSub40 *w = self->fsm;
        w->timer++;
        if (w->timer < 10) {
            return;
        }
        self->fsm->timer = 0;
        if (self->step2->op == 12 && !Ov003_CountActorsOfKind(0x482b)) {
            self->fsm->st = 10;
        } else {
            self->fsm->st = 0x1e;
        }
        func_ov014_021fe3ec(self);
        break;
    }
    case 10: {
        ActorSub40 *w = self->fsm;
        w->timer++;
        if (w->timer < self->step2->time) {
            return;
        }
        self->fsm->timer = 0;
        self->fsm->st = 1;
        break;
    }
    case 0x1e: {
        u16 lim = 0;
        ActorSub40 *w = self->fsm;
        if (self->step2 != NULL) {
            lim = self->step2->b;
        }
        w->timer++;
        if (w->timer < lim) {
            return;
        }
        if (self->unk_f4 & 8) {
            self->unk_f4 ^= 8;
        }
        self->unk_138 ^= 0x80;
        self->fsm->timer = 0;
        History_SetState(self->fsm, 1, 0);
        break;
    }
    }
}
extern void ActorMgr_BroadcastKind(void *mgr, s32 a, s32 b);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern Ov003Actor *Factory_New4000(Ov014SpawnDesc *desc);
extern void func_ov000_0219bebc(Ov003Actor *a, s32 b);

void Ov014Act_021fd4d4_StateAttack3(Ov014Act_021fd4d4 *self) {
    if (self->unk_f0 != 1) {
        return;
    }
    switch (self->fsm->st) {
    case 0: {
        EffectObj *e;
        ActorMgr_BroadcastKind(gActorMgr, 0x482b, 0x15);
        e = Effect_SpawnId(0x2bd, &self->pos);
        e->AddPosXYZ(0, 0, 0x7000);
        e->SetScaleAll(0x8000);
        e->SetRotXYZ(0x4000, 0, 0);
        EffectObj_AddSndCue(e, 0x44, 0);
        Ov003FxList_Add(self->unk_fc, 0, e);
        self->unk_f9 = 0;
        self->fsm->st++;
        break;
    }
    case 1: {
        u8 i;
        if (!Ov003FxList_Has(self->unk_fc, 0)) {
            for (i = 0; i < 2; i++) {
                EffectObj *e = Effect_SpawnId(0x57e, &self->pos);
                e->AddPosXYZ(0, 0, 0x7000);
                e->SetScaleAll(0x3000);
                Ov003FxList_Add(self->unk_fc, 1, e);
            }
            if (self->unk_f9 == 1) {
                Ov014SpawnDesc desc;
                Ov003Actor *o;
                Ov014Spawn_Init(&desc, 0xffff);
                Ov014Spawn_Set(&desc, 0x482c);
                o = Factory_New4000(&desc);
                if (o != NULL) {
                    o->pos.x = 0;
                    o->pos.y = 0x4719a;
                    o->pos.z = 0xf000;
                    o->target = self->target;
                    o->vfunc_04();
                    o->flags_0 = 1;
                    func_ov000_0219bebc(o, self->unk_13a);
                    if (o->targetObj != NULL) {
                        o->targetObj->target = self->id;
                    }
                }
            }
            if (self->unk_f9 >= 2) {
                self->fsm->st = 0x1e;
            } else {
                self->fsm->st++;
            }
        } else {
            Robo021ca458 *pl = (Robo021ca458 *)ActorMgr_FindPlayer();
            if (pl != NULL) {
                pl->unk_b90.x = self->pos.x;
                pl->unk_b90.y = self->pos.y;
                pl->unk_b90.z = self->pos.z;
                pl->unk_b9c = 0x400;
            }
        }
        break;
    }
    case 2:
        if (!Ov003FxList_Has(self->unk_fc, 1)) {
            self->unk_f9++;
            self->fsm->st = 1;
        }
        break;
    case 0x1e:
        if (!Ov003_CountActorsOfKind(0x482c)) {
            if (self->unk_f4 & 0x10) {
                self->unk_f4 ^= 0x10;
            }
            self->unk_f4 |= 1;
            self->fsm->timer = 0;
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
}


static inline void Ov014Cam_SetY(FieldCam *cam, u16 x) {
    cam->unk_f8.y = x;
    cam->unk_da_4 = 1;
}
static inline void Ov014Cam_SetX(FieldCam *cam, u16 x) {
    cam->unk_f8.x = x;
    cam->unk_da_5 = 1;
}
static inline BOOL Ov014_PlBusy(Ov003Actor *pl) {
    return ((Robo021ca458 *)pl)->unk_b24_0 ? TRUE : FALSE;
}

extern void Shared_SetEventActor(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_ov000_02182590(void *p);
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern void *SndMgr_PlayAt(void *mgr, s32 id, VecFx32 *pos, s32 a);
extern void Field_ShakeCamera(s32 a, s32 b);
extern void Ov003TickerSet_SetPaused(void *p, s32 a);
extern void Ov003TickerSet_Start(void *p, s32 a, s32 b, s32 c, s32 d);
extern BOOL Actor_IsDead(Ov003Actor *p);
extern void *SndMgr_PlayVolume(void *mgr, s32 id, s32 a, s32 b, s32 c);

void Ov014Act_021fd4d4_StateDie(Ov014Act_021fd4d4 *self) {
    VecFx32 p = data_ov014_02216600;
    VEC_Add(&p, &self->pos, &p);
    switch (self->unk_f0) {
    case 0:
        switch (self->fsm->st) {
        case 0: {
            ActorSub48 *m;
            ActorSub44 *n;
            FieldState *g;
            Shared_SetEventActor(self->kind, self->id);
            func_020627dc(5);
            g = gSceneCmd;
            g->stageFlags = 1;
            func_ov000_02182590(&g->stageFlags);
            m = self->hit;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(m);
            n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
            self->targetObj->target = 0xffff;
            self->unk_1a = 0xb60;
            self->unk_1c = 0xaaa;
            self->unk_1e = 0x3c;
            self->unk_84 = self->pos;
            self->fsm->timer = 0;
            self->fsm->st++;
            break;
        }
        case 1: {
            ActorSub40 *s = self->fsm;
            s->timer++;
            if (s->timer == 50) {
                Model0218fe1c_SetAnim(self->model, data_ov014_02216500[1], 0x111, 0);
            } else if (self->fsm->timer > 50) {
                if (Model0218fe1c_IsAnimDone(self->model)) {
                    Model0218fe1c_SetAnim(self->model, data_ov014_02216500[3], 0x89, 0);
                    Model0218fe1c_SetLoop(self->model);
                    self->fsm->timer = 0;
                    self->fsm->st++;
                }
                if (self->fsm->timer == 0x46) {
                    EffectObj *e;
                    SndMgr_PlayAt(gSndMgr, 0x5b, &p, 0);
                    SndMgr_PlayAt(gSndMgr, 0x56, &p, 0);
                    e = Effect_SpawnId(0x68, &self->pos);
                    e->SetScaleAll(0x4000);
                    e->SetRotXYZ(0x4000, 0, 0);
                    Field_ShakeCamera(10, 0x14);
                }
            }
            break;
        }
        case 2: {
            ActorSub40 *s = self->fsm;
            u16 t;
            s->timer++;
            t = s->timer;
            if (t == 50) {
                Ov003TickerSet_SetPaused((u8 *)self + 0x100, 0);
                Ov003TickerSet_Start((u8 *)self + 0x100, 0x1e, 0, 0, 0);
            }
            if (t == 100) {
                VecFx32 q = data_ov014_022165f4;
                FieldState *g;
                EffectObj *e;
                VEC_Add(&self->pos, &q, &q);
                self->unk_b8 = q;
                g = gSceneCmd;
                g->cam.base.flags |= 0x1c;
                g->cam.base.shakeTime = 0xf;
                g->cam.base.shakeLen = 0xf;
                g->cam.base.shakeCur = 0xf;
                SndMgr_PlayAt(gSndMgr, 0x53, &p, 0);
                e = Effect_SpawnId(0x68, &self->pos);
                e->SetScaleAll(0x5000);
                e->SetRotXYZ(0x4000, 0, 0);
                self->fsm->timer = 50;
                self->fsm->st++;
            }
            break;
        }
        case 3: {
            VecFx32 d;
            s32 tx = self->unk_b8.x;
            s32 ty = self->unk_b8.y;
            s32 tz = self->unk_b8.z;
            d.x = tx - self->pos.x;
            d.y = ty - self->pos.y;
            d.z = tz - self->pos.z;
            VEC_MultAdd(0x4cd, &d, &self->pos, &self->pos);
            if (VEC_Distance(&self->pos, &self->unk_b8) < 0x19a) {
                self->fsm->st++;
            }
            break;
        }
        case 4: {
            ActorSub40 *s = self->fsm;
            if (s->timer) {
                s->timer--;
            }
            if (s->timer == 0) {
                EffectObj *e = Effect_SpawnId(0x2bd, &self->pos);
                e->AddPosXYZ(0, 0, 0x5000);
                e->SetScaleAll(0x8000);
                e->SetRotXYZ(0x4000, 0, 0);
                SndMgr_PlayAt(gSndMgr, 0x44, &p, 0);
                Ov003FxList_Add(self->unk_fc, 0, e);
                self->fsm->st++;
            }
            break;
        }
        case 5:
            if (!Ov003FxList_Has(self->unk_fc, 0)) {
                self->speed = 0;
                self->friction = 0;
                self->gravity = 0;
                self->velY = 0x29;
                Field_ShakeCamera(0x1e, 0x32);
                self->fsm->timer = 0x19;
                SndMgr_PlayAt(gSndMgr, 0x1b, &p, 0);
                SndMgr_PlayAt(gSndMgr, 0x53, &p, 0);
                self->unk_f9 = 0;
                self->fsm->st++;
            }
            break;
        case 6: {
            ActorSub40 *s;
            Actor_Move(self, 0);
            s = self->fsm;
            if (s->timer) {
                s->timer--;
            }
            if (s->timer == 0) {
                Field_ShakeCamera(10, 0x1e);
                self->fsm->timer = 0x19;
                self->unk_f9++;
            }
            if (self->unk_f9 == 7) {
                self->fsm->st = 0x1e;
            }
            break;
        }
        case 0x1e:
            self->unk_93_4 = 0;
            Ov003Actor_Defeat(self, 0, 1, 1);
            self->fsm->st++;
            break;
        }
        if (self->fsm->st < 0x1e) {
            Ov003Actor *pl = ActorMgr_FindPlayer();
            if (pl != NULL && !Ov014_PlBusy(pl)) {
                FieldCam *cam = &gSceneCmd->cam;
                s16 c;
                s16 a;
                s16 b;
                cam->unk_e8 = self->unk_84;
                cam->unk_da_1 = 1;
                cam->unk_f4 = -0x2000;
                cam->unk_da_2 = 2;
                c = self->unk_1e;
                a = self->unk_1a;
                b = self->unk_1c;
                if (c <= 0) {
                    if (a > 0) {
                        a = a - 0xb;
                        if (a <= 0) {
                            a = 0;
                        }
                        self->unk_1a = a;
                    }
                    if (b > 0) {
                        b = b - 0xc;
                        if (b <= 0) {
                            b = 0;
                        }
                        self->unk_1c = b;
                    }
                } else {
                    c = c - 1;
                    if (c <= 0) {
                        c = 0;
                    }
                    self->unk_1e = c;
                }
                Ov014Cam_SetY(cam, a + 0x7c71);
                Ov014Cam_SetX(cam, b - 0x4fa);
            }
        }
        break;
    case 1:
        self->unk_ea |= 0x200;
        switch (self->fsm->st) {
        case 0: {
            ActorSub48 *m = self->hit;
            ActorSub44 *n;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(m);
            n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
            self->targetObj->target = 0xffff;
            Ov003TickerSet_SetPaused((u8 *)self + 0x100, 0);
            Ov003TickerSet_Start((u8 *)self + 0x100, 0, 0, 1, 0);
            self->fsm->st++;
        }
        case 1:
            ActorMgr_BroadcastKind(gActorMgr, 0x482b, 0x15);
            ActorMgr_BroadcastKind(gActorMgr, 0x482c, 0x15);
            ActorMgr_BroadcastKind(gActorMgr, 0x580c, 0x15);
            ActorMgr_BroadcastKind(gActorMgr, 0x580d, 0x15);
            ActorMgr_BroadcastKind(gActorMgr, 0x580e, 0x15);
            self->unk_93_4 = 0;
            Ov003Actor_Defeat(self, 0, 1, 1);
            {
            Ov003Actor *pl = ActorMgr_FindPlayer();
            if (pl != NULL && !Actor_IsDead(pl)) {
                SndMgr_PlayVolume(gSndMgr, 0x38, 0x50, -1, -1);
            }
            }
            self->fsm->st++;
            break;
        }
        break;
    }
    Ov003FxList_Prune(self->unk_fc);
}

}
}  // namespace m_021ff318

// ---- merged from ov014_0220011c.cpp
namespace m_0220011c {
extern "C" {

extern u8 Ov014Act_0220011c_vtbl[];
extern const Ov003Step data_ov014_0221664c[];
extern const Ov003Step data_ov014_0221665c[];
extern const Ov003Step data_ov014_0221666c[];
extern const Ov003Step data_ov014_0221667c[];
extern BOOL Ov003Actor_HandleMsg(Ov003Actor *self, Ov014Msg *msg);
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);

#pragma force_active on
Ov003Actor *Ov014Act_0220011c_Ctor(Ov014Act_0220011c *self) {
    Ov003Actor_Ctor(self);
    *(void **)self = Ov014Act_0220011c_vtbl;
    Ov003ScriptList_Init(&self->scripts);
    self->unk_f4 = 0;
    self->unk_f8 = 0xff;
    self->unk_100 = NULL;
    self->step = NULL;
    self->unk_fc = 0xff;
    self->unk_fe = 0;
    return self;
}
#pragma force_active reset

static inline void Ov014_Free100(Ov014Act_0220011c *self) {
    void *saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (self->unk_100 != NULL) {
        Ov003FxList *p = self->unk_100;
        if (p != NULL) {
            Ov003FxList_Dtor(p);
            Heap_Free(p);
        }
        self->unk_100 = NULL;
    }
    gSysState->cur = saved;
}

Ov014Act_0220011c *Ov014Act_0220011c_Dtor(Ov014Act_0220011c *self) {
    *(void **)self = Ov014Act_0220011c_vtbl;
    Ov014_Free100(self);
    Ov003Vt_021f7974_Dtor(&self->scripts);
    Ov003Actor_DtorBase(self);
    return self;
}

Ov014Act_0220011c *Ov014Act_0220011c_DtorDelete(Ov014Act_0220011c *self) {
    *(void **)self = Ov014Act_0220011c_vtbl;
    Ov014_Free100(self);
    Ov003Vt_021f7974_Dtor(&self->scripts);
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

void Ov014Act_0220011c_HandleMsg(Ov014Act_0220011c *self, Ov014Msg *msg) {
    switch (msg->type) {
    case 6:
        self->unk_f8 = msg->idx;
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
        break;
    case 14:
        self->unk_fc = msg->idx;
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
        break;
    }
    Ov003Actor_HandleMsg(self, msg);
}

void Ov014Act_0220011c_Start(Ov014Act_0220011c *self) {
    Ov003Unit *a;
    ActorSub48 *m;
    Ov003Actor_Start(self);
    self->unk_f0 = self->unk_18 & 0xff;
    self->unk_100 = Ov014_NewFx();
    a = Group_FindNode(gGroup, self->unk_20);
    if (a != NULL) {
        a->unk_a2_0 = 0;
    }
    self->unk_ea_6 = 1;
    m = self->hit;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    HitSphere_Unlink_0203f364(m);
    m = self->hit;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    m = self->hit;
    m->unk_9a_2 = 0;
    m->unk_9a_5 = 0;
    self->hit->unk_30 = 0;
    m = self->hit;
    m->offset.x = 0;
    m->offset.y = -0x19a;
    m->offset.z = 0;
    switch (self->unk_f0) {
    case 0:
        Ov003ScriptList_AddTrack(&self->scripts, 0, 1, data_ov014_0221651c);
        break;
    case 1:
        Ov003ScriptList_AddTrack(&self->scripts, 1, 2, data_ov014_0221664c);
        break;
    case 2:
        Ov003ScriptList_AddTrack(&self->scripts, 2, 2, data_ov014_0221665c);
        break;
    case 3:
        Ov003ScriptList_AddTrack(&self->scripts, 3, 2, data_ov014_0221666c);
        break;
    case 4:
        Ov003ScriptList_AddTrack(&self->scripts, 4, 2, data_ov014_0221667c);
        break;
    }
}

}
}  // namespace m_0220011c

// ---- merged from ov014_02200444.cpp
namespace m_02200444 {
extern "C" {

extern const u8 data_ov014_0221668c[][6];
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern void ActorMgr_SendToKindOthers(s32 a, u16 b, s32 c, s32 d, s32 e, void *f);

static inline const Ov003Step *Ov014_AnimCur(Ov003Track *t) {
    return &t->steps[t->val];
}

void Ov014Act_0220011c_Update(Ov014Act_0220011c *self) {
    u8 b;
    s16 v;
    Ov003Actor *a;
    if (!Ov014_GameIdle()) {
        return;
    }
    self->target = 0xffff;
    a = ActorMgr_FindPlayer();
    if (a != NULL) {
        self->target = a->id;
    }
    if (self->fsm->current == 1) {
        u32 f = self->unk_f4;
        if (f == 0) {
            s16 m;
            if ((self->msg_flags & 0x4000) && (m = ((s16)self->unk_fc)) != 0xff && data_ov014_0221668c[self->unk_f0][m] != 0) {
                s32 sel = 0xff;
                switch (m) {
                case 0:
                    sel = 0;
                    break;
                case 1:
                case 2:
                    sel = 1;
                    break;
                case 3:
                case 4:
                case 5:
                    sel = 2;
                    break;
                }
                if (sel != 0xff) {
                    self->step = Ov014_AnimCur(self->scripts.cur);
                    while (sel != self->step->op) {
                        Ov003ScriptList_Step(&self->scripts);
                        self->step = Ov014_AnimCur(self->scripts.cur);
                    }
                    self->unk_fe = 0;
                    v = self->unk_f0;
                    ActorMgr_SendToKindOthers(0x5c0e, self->kind, 0xe, 1, 2, &v);
                    switch (self->step->op) {
                    case 0:
                        self->unk_f4 |= 4;
                        self->fsm->flags |= 0x8000;
                        break;
                    case 1:
                        self->unk_f4 |= 8;
                        self->fsm->flags |= 0x10000;
                        break;
                    case 2:
                        self->unk_f4 |= 0x10;
                        self->fsm->flags |= 0x20000;
                        break;
                    }
                    self->unk_fc = 0xff;
                }
            }
        } else if (f & 1) {
            self->unk_b6++;
            if (self->unk_b6 >= 10) {
                Ov003FxList_Kill(self->unk_100, 0xff);
                self->unk_f4 ^= 1;
                b = self->unk_f0 + 3;
                ActorMgr_SendToKindOthers(0x5c0e, self->kind, 6, 1, 1, &b);
                self->unk_b6 = 0;
            }
        }
    }
    Ov003FxList_Prune(self->unk_100);
}
}
}  // namespace m_02200444

// ---- merged from ov014_022006e4.cpp
namespace m_022006e4 {
// Word-array view used for a block copy: assigning through it emits the
// original's ldm/stm, where a plain VecFx32 assignment copies field by field.
struct Ov014Arr3 { s32 a[3]; };
extern "C" {

extern void Model0218fe1c_PauseAnim(void *a);
extern void Model0218fe1c_ResumeAnim(void *a);
extern void *SndMgr_PlayAtPitch(void *a, s32 b, VecFx32 *c, s32 d);
extern void ActorMgr_SendToKindOthers(s32 a, u16 b, s32 c, s32 d, s32 e, u8 *f);

void Ov014Act_0220011c_State20(Ov014Act_0220011c *self) {
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov014_02216500[1], 0x1000, 0);
        Model0218fe1c_PauseAnim(self->model);
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    case 1:
        if (self->unk_f8 == 1) {
            self->unk_f8 = 0;
            s->st++;
        }
        break;
    case 2:
        s->timer++;
        if (s->timer > (u16)(self->unk_f0 * 30)) {
            Effect_SpawnId(0x68, &self->pos)->SetRotXYZ(0xbfff, self->rot_y, 0);
            Model0218fe1c_ResumeAnim(self->model);
            SndMgr_PlayAtPitch(gSndMgr, 0x71, &self->pos, 5);
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    case 3:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            const char *a = data_ov014_02216500[3];
            Model0218fe1c_SetAnim(self->model, a, 0x89, 0);
            Model0218fe1c_SetLoop(self->model);
            if (self->unk_f0 == 4) {
                u8 b = 1;
                ActorMgr_SendToKindOthers(0x5c0e, self->kind, 6, 1, 1, &b);
            }
            Model0218fe1c_SetAnim(self->model, a, 0x89, 0);
            Model0218fe1c_SetLoop(self->model);
            self->fsm->st = 0x1e;
        }
        break;
    case 0x1e:
        if (self->unk_f8 == 2) {
            self->unk_f8 = 0;
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
}

extern void Model0218fe1c_SetReverse(void *a);
extern AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *self, u32 i);
extern void Model0218fe1c_SetAnim3(void *a, s32 b, s32 c, s32 d);
extern Ov003Actor *Actor_GetTarget(Actor *self);
extern void Actor_PitchToActor(Ov003Actor *self, Ov003Actor *target, s32 a);
extern s32 Actor_FindInRadius(Actor *self, u16 mask, VecFx32 *pos, s32 r, s32 a, Ov003Actor **list);
extern Ov003Actor *Obj021984c8_GetActor(Ov003Actor *p);
extern void Actor_SendMsgU8(Ov003Actor *a, u16 id, s32 msg);

void Ov014Act_0220011c_StateIdle(Ov014Act_0220011c *self) {
    Ov003Actor *list[0x20];
    Ov003Actor *t;
    s32 i;
    s32 n;
    if (self->fsm->st == 0) {
        ActorSub44 *s44;
        AnimCtrl *q;
        Model0218fe1c_SetAnim(self->model, data_ov014_02216500[1], 0x89, 0);
        Model0218fe1c_SetReverse(self->model);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        q = Model0218fe1c_GetAnimCtrl(self->model, 3);
        if (q != NULL) {
            self->model->unk_c2_6 = 1;
            Model0218fe1c_SetAnim3(self->model, 0, 0x1000, 0);
            if (q->cur != NULL) {
                q->cur->frame = 0;
            }
            q->paused = 1;
        }
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
    }
    t = Actor_GetTarget(self);
    Actor_TurnToActor(self, t, 0xcd);
    Actor_PitchToActor(self, t, 0xcd);
    n = Actor_FindInRadius(self, 0x10, &self->pos, self->radius, 0, list);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            Ov003Actor *q;
            if (list[i] != NULL && (q = Obj021984c8_GetActor(list[i])) != NULL) {
                if ((u16)(q->targetObj->target & 0xf000) != 0x5000) {
                    Actor_SendMsgU8(q, q->id, 0x15);
                    return;
                }
            }
        }
    }
}

struct Ov014SpawnDescA {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov014SpawnA_Init(Ov014SpawnDescA *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

extern Ov014Res data_ov014_022173e0;
extern const u8 data_ov014_0221663c[];
extern const u8 data_ov014_0221663d[];
extern const u8 data_ov014_0221663e[];
extern void Model0218fe1c_ClearReverse(void *a);
extern void Actor_PitchToPos(Ov003Actor *self, VecFx32 *v, s32 a);
extern void Field_ShakeCamera(s32 a, s32 b);
extern Ov003Actor *Group_SpawnActor(void *mgr, Ov014SpawnDescA *d, VecFx32 *pos, void *rot, u16 a);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void Vec_RotateY(VecFx32 *a, VecFx32 *b, u16 ang);

static inline Ov003Actor *Ov014_FindById(u16 id) {
    return gActorMgr != NULL ? ActorMgr_GetActor(gActorMgr, id) : NULL;
}

void Ov014Act_0220011c_StateAttack(Ov014Act_0220011c *self) {
    Ov003Actor *t = Actor_GetTarget(self);
    Ov014Res *tbl = &data_ov014_022173e0;
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 0: {
        EffectObj *e;
        s->timer++;
        if (s->timer < data_ov014_0221663c[self->unk_f0 * 3]) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, data_ov014_02216500[1], 0x89, 0);
        Model0218fe1c_ClearReverse(self->model);
        SndMgr_PlayAtPitch(gSndMgr, 0x71, &self->pos, 5);
        e = Effect_SpawnId(0x324, &self->pos);
        e->SetScaleAll(0x4000);
        e->AddPosXYZ(0, 0x4cd, 0x2800);
        Ov003FxList_Add(self->unk_100, 0xff, e);
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    }
    case 1: {
        ActorSub44 *s44;
        AnimCtrl *q;
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, data_ov014_02216500[3], 0x89, 0);
        Model0218fe1c_SetLoop(self->model);
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
        q = Model0218fe1c_GetAnimCtrl(self->model, 3);
        if (q != NULL) {
            self->model->unk_c2_6 = 1;
            Model0218fe1c_SetAnim3(self->model, 0, 0x1000, 0);
            if (q->cur != NULL) {
                q->cur->frame = 0x1000;
            }
            q->paused = 1;
        }
        self->fsm->st++;
        break;
    }
    case 2:
        Actor_TurnToActor(self, t, 0xcd);
        Actor_PitchToActor(self, t, 0xcd);
        {
            ActorSub40 *q = self->fsm;
            q->timer++;
            if (q->timer != 0x32) {
                return;
            }
        }
        Ov003FxList_Add(self->unk_100, 0xfe, Effect_SpawnId(0x196, &self->pos));
        SndMgr_PlayAtPitch(gSndMgr, 0x5b, &self->pos, 2);
        self->unk_84.x = 0;
        self->unk_84.y = -0x5000;
        self->unk_84.z = 0x4000;
        Vec_RotateY(&self->unk_84, &self->unk_84, self->rot_y);
        VEC_Add(&self->unk_84, &self->pos, &self->unk_84);
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    case 3: {
        Ov014SpawnDescA desc;
        Ov003Actor *o;
        Actor_TurnToActor(self, t, 0x19a);
        Actor_PitchToPos(self, &self->unk_84, 0xcd);
        if (Ov003FxList_Has(self->unk_100, 0xfe)) {
            return;
        }
        Field_ShakeCamera(8, 0x28);
        Ov014SpawnA_Init(&desc, 0x483c);
        o = Group_SpawnActor(gGroup, &desc, &self->pos, &self->rot_x, 0xffff);
        if (o != NULL) {
            o->unk_60 = tbl;
            o->flags_0 = 1;
            o->target = self->target;
            if (o->targetObj != NULL) {
                o->targetObj->target = self->id;
            }
            self->unk_fa = o->id;
        }
        self->unk_84.x = 0;
        self->unk_84.y = 0x1000;
        self->unk_84.z = 0x4000;
        Vec_RotateY(&self->unk_84, &self->unk_84, self->rot_y);
        VEC_Add(&self->unk_84, &self->pos, &self->unk_84);
        Ov003FxList_Kill(self->unk_100, 0xff);
        self->fsm->st++;
        break;
    }
    case 4: {
        Ov003Actor *o;
        EffectObj *e;
        u16 n;
        Actor_PitchToPos(self, &self->unk_84, 0x19a);
        o = Ov014_FindById(self->unk_fa);
        if (o != NULL) {
            o->rot_x = self->rot_x;
            o->rot_y = self->rot_y;
            o->rot_z = self->rot_z;
        }
        {
            ActorSub40 *q = self->fsm;
            u16 lim = tbl->n;
            q->timer++;
            if (lim != q->timer) {
                return;
            }
        }
        self->fsm->timer = 0;
        e = Effect_SpawnId(0x324, &self->pos);
        e->SetScaleAll(0x4000);
        e->AddPosXYZ(0, 0x4cd, 0x2800);
        Ov003FxList_Add(self->unk_100, 0xff, e);
        n = 0;
        if (((void *)self->step) != NULL) {
            n = self->step->a;
        }
        if (++self->unk_fe < n) {
            self->fsm->st = 10;
        } else {
            self->fsm->st = 0x1e;
        }
        break;
    }
    case 10:
        Actor_TurnToActor(self, t, 0xcd);
        Actor_PitchToActor(self, t, 0xcd);
        {
            ActorSub40 *q = self->fsm;
            q->timer++;
            if (q->timer < self->step->time) {
                return;
            }
        }
        self->fsm->timer = 0;
        self->fsm->st = 2;
        break;
    case 0x1e: {
        u16 lim = 0x3c;
        ActorSub44 *s44;
        if (((void *)self->step) != NULL) {
            lim = self->step->b;
        }
        s->timer++;
        if (lim != s->timer) {
            return;
        }
        if (self->unk_f4 & 4) {
            self->unk_f4 ^= 4;
        }
        self->unk_f4 |= 1;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        SndMgr_PlayAtPitch(gSndMgr, 0x78, &self->pos, 2);
        self->fsm->timer = 0;
        History_SetState(self->fsm, 1, 0);
        break;
    }
    }
}

extern void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);
extern s32 Ov003_CountActorsOfKind(s32 kind);

void Ov014Act_0220011c_StateAttack2(Ov014Act_0220011c *self) {
    VecFx32 v;
    ActorSub40 *s;
    Actor_GetTarget(self);
    s = self->fsm;
    switch (s->st) {
    case 0: {
        EffectObj *e;
        s->timer++;
        if (s->timer < data_ov014_0221663d[self->unk_f0 * 3]) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, data_ov014_02216500[1], 0x89, 0);
        Model0218fe1c_ClearReverse(self->model);
        SndMgr_PlayAtPitch(gSndMgr, 0x71, &self->pos, 5);
        e = Effect_SpawnId(0x324, &self->pos);
        e->SetScaleAll(0x4000);
        e->AddPosXYZ(0, 0x4cd, 0x2800);
        Ov003FxList_Add(self->unk_100, 0xff, e);
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    }
    case 1: {
        ActorSub44 *s44;
        AnimCtrl *q;
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, data_ov014_02216500[3], 0x89, 0);
        Model0218fe1c_SetLoop(self->model);
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
        q = Model0218fe1c_GetAnimCtrl(self->model, 3);
        if (q != NULL) {
            self->model->unk_c2_6 = 1;
            Model0218fe1c_SetAnim3(self->model, 0, 0x1000, 0);
            if (q->cur != NULL) {
                q->cur->frame = 0x2000;
            }
            q->paused = 1;
        }
        self->fsm->st++;
        break;
    }
    case 2:
        VEC_Add(&self->pos, &data_ov014_02216564, &v);
        Actor_TurnToPos(self, &v, 0x400);
        Actor_PitchToPos(self, &v, 0x400);
        {
            ActorSub40 *q = self->fsm;
            q->timer++;
            if (q->timer != 0x32) {
                return;
            }
        }
        Ov003FxList_Add(self->unk_100, 0xfe, Effect_SpawnId(0x195, &self->pos));
        SndMgr_PlayAt(gSndMgr, 0x36, &self->pos, 0);
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    case 3: {
        Ov003Actor *o;
        u16 n;
        if (Ov003FxList_Has(self->unk_100, 0xfe)) {
            return;
        }
        VecFx32 q;
        Ov014SpawnDescA desc;
        Ov014SpawnA_Init(&desc, 0x4827);
        *(Ov014Arr3 *)&q = *(const Ov014Arr3 *)&data_ov014_022165b8;
        VEC_Add(&self->pos, &q, &q);
        o = Group_SpawnActor(gGroup, &desc, &q, &self->rot_x, 0xffff);
        if (o != NULL) {
            o->flags_0 = 1;
            o->target = self->target;
            if (o->targetObj != NULL) {
                o->targetObj->target = self->id;
            }
        }
        n = 0;
        if (((void *)self->step) != NULL) {
            n = self->step->a;
        }
        if (++self->unk_fe < n) {
            self->fsm->st = 10;
        } else {
            self->fsm->st = 0x1e;
        }
        break;
    }
    case 10:
        s->timer++;
        if (s->timer < self->step->time) {
            return;
        }
        self->fsm->timer = 0;
        self->fsm->st = 3;
        break;
    case 0x1e: {
        u16 lim = 0x96;
        ActorSub44 *s44;
        if (((void *)self->step) != NULL) {
            lim = self->step->b;
        }
        s->timer++;
        if (lim != s->timer) {
            if (Ov003_CountActorsOfKind(0x4827)) {
                return;
            }
        }
        if (self->unk_f4 & 8) {
            self->unk_f4 ^= 8;
        }
        self->unk_f4 |= 1;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        SndMgr_PlayAtPitch(gSndMgr, 0x78, &self->pos, 2);
        self->fsm->timer = 0;
        History_SetState(self->fsm, 1, 0);
        break;
    }
    }
}


void Ov014Act_0220011c_StateAttack3(Ov014Act_0220011c *self) {
    VecFx32 v;
    ActorSub40 *s;
    Actor_GetTarget(self);
    s = self->fsm;
    switch (s->st) {
    case 0: {
        EffectObj *e;
        s->timer++;
        if (s->timer < data_ov014_0221663e[self->unk_f0 * 3]) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, data_ov014_02216500[1], 0x89, 0);
        Model0218fe1c_ClearReverse(self->model);
        SndMgr_PlayAtPitch(gSndMgr, 0x71, &self->pos, 5);
        e = Effect_SpawnId(0x324, &self->pos);
        e->SetScaleAll(0x4000);
        e->AddPosXYZ(0, 0x4cd, 0x2800);
        Ov003FxList_Add(self->unk_100, 0xff, e);
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    }
    case 1: {
        ActorSub44 *s44;
        AnimCtrl *q;
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, data_ov014_02216500[3], 0x89, 0);
        Model0218fe1c_SetLoop(self->model);
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
        q = Model0218fe1c_GetAnimCtrl(self->model, 3);
        if (q != NULL) {
            self->model->unk_c2_6 = 1;
            Model0218fe1c_SetAnim3(self->model, 0, 0x1000, 0);
            if (q->cur != NULL) {
                q->cur->frame = 0x3000;
            }
            q->paused = 1;
        }
        self->fsm->st++;
        break;
    }
    case 2:
        VEC_Add(&self->pos, &data_ov014_02216564, &v);
        Actor_TurnToPos(self, &v, 0x400);
        Actor_PitchToPos(self, &v, 0x400);
        {
            ActorSub40 *q = self->fsm;
            q->timer++;
            if (q->timer != 0x32) {
                return;
            }
        }
        {
            EffectObj *e = Effect_SpawnId(0x391, &self->pos);
            e->SetScaleAll(0x2000);
            Ov003FxList_Add(self->unk_100, 0xfe, e);
        }
        SndMgr_PlayAt(gSndMgr, 0x36, &self->pos, 0);
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    case 3: {
        Ov003Actor *o;
        u16 n;
        s->timer++;
        if (s->timer != 0x1e) {
            return;
        }
        VecFx32 q;
        Ov014SpawnDescA desc;
        Ov014SpawnA_Init(&desc, 0x4828);
        *(Ov014Arr3 *)&q = *(const Ov014Arr3 *)&data_ov014_022165c4;
        VEC_Add(&self->pos, &q, &q);
        o = Group_SpawnActor(gGroup, &desc, &q, &self->rot_x, 0xffff);
        if (o != NULL) {
            o->flags_0 = 1;
            o->target = self->target;
            if (o->targetObj != NULL) {
                o->targetObj->target = self->id;
            }
        }
        n = 0;
        if (((void *)self->step) != NULL) {
            n = self->step->a;
        }
        self->unk_fe++;
        self->fsm->timer = 0;
        if (self->unk_fe < n) {
            self->fsm->st = 10;
        } else {
            self->fsm->st = 0x1e;
        }
        break;
    }
    case 10:
        s->timer++;
        if (s->timer < self->step->time) {
            return;
        }
        self->fsm->timer = 0;
        self->fsm->st = 3;
        break;
    case 0x1e: {
        u16 lim = 0x190;
        ActorSub44 *s44;
        if (((void *)self->step) != NULL) {
            lim = self->step->b;
        }
        s->timer++;
        if (lim != s->timer) {
            if (Ov003_CountActorsOfKind(0x4828)) {
                return;
            }
        }
        if (self->unk_f4 & 0x10) {
            self->unk_f4 ^= 0x10;
        }
        self->unk_f4 |= 1;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        SndMgr_PlayAtPitch(gSndMgr, 0x78, &self->pos, 2);
        self->fsm->timer = 0;
        History_SetState(self->fsm, 1, 0);
        break;
    }
    }
}
}
}  // namespace m_022006e4

// ---- merged from ov014_02201b94.cpp
namespace m_02201b94 {
extern "C" {

extern Ov003Actor *ActorMgr_FindKind(void *mgr, u16 a, u16 b);
extern void ActorMgr_SendToKindOthers(s32 a, u16 b, s32 c, s32 d, s32 e, u8 *f);
extern void Field_ShakeCamera(s32 a, s32 b);
extern void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);

void Ov014Act_0220011c_StateDie(Ov014Act_0220011c *self) {
    if (self->fsm->st == 0) {
        FieldState *g = gSceneCmd;
        u8 c;
        Ov003Actor *a;
        EffectObj *e;
        g->cam.base.flags |= 0x1c;
        g->cam.base.shakeTime = 0xf;
        g->cam.base.shakeLen = 0xf;
        g->cam.base.shakeCur = 0xf;
        c = self->unk_f0 + 3;
        ActorMgr_SendToKindOthers(0x5c0e, self->kind, 6, 1, 1, &c);
        if (gActorMgr == NULL) {
            a = NULL;
        } else {
            a = ActorMgr_FindKind(gActorMgr, 0x4000, 0x483c);
        }
        if (a != NULL) {
            a->unk_1a = 1;
        }
        Ov003FxList_Kill(self->unk_100, 0xff);
        Ov003FxList_Kill(self->unk_100, 0xfe);
        Field_ShakeCamera(0x19, 0x3c);
        SndMgr_PlayAt(gSndMgr, 0x56, &self->pos, 0);
        SndMgr_PlayAt(gSndMgr, 0x79, &self->pos, 0);
        Effect_SpawnId(0x322, &self->pos)->SetScaleAll(0x1400);
        e = Effect_SpawnId(0x68, &self->pos);
        e->SetScaleAll(0x1800);
        e->SetRotXYZ(0x4000, 0, 0);
    }
    Ov003Actor_StateDie(self);
}

extern u8 Ov014Act_02201b94_vtbl[];
extern void *Ov003Vt_021f7d10_Ctor(void *p);
extern void *Ov003Vt_021f7d10_Dtor(void *p);
extern void *ResSet_Init(void *p);
extern void *Model0218fe1c_Init(void *p);
extern void *Model0218fe1c_FreeAnims(void *p);
extern void *ResSet_ReleaseAll(void *p);
extern BOOL Actor_IsReady(Ov003Actor *self);
extern BOOL ResSet_UpdateLoad(void *p);
extern BOOL Ov003TickerSet_IsHeld(void *p);
extern void Ov003TickerSet_Apply(void *p, VecFx32 *a, VecFx32 *b, s32 c);
extern BOOL Model021903b4_Draw(void *p);
extern BOOL Ov003Actor_HandleMsg(Ov003Actor *self, Ov014Msg *msg);

#pragma force_active on
Ov003Actor *Ov014Act_02201b94_Ctor(Ov014Act_02201b94 *self) {
    Ov003Actor_Ctor(self);
    *(void **)self = Ov014Act_02201b94_vtbl;
    Ov003Vt_021f7d10_Ctor((u8 *)self + 0x100);
    Ov003ScriptList_Init(&self->scripts);
    ResSet_Init((u8 *)self + 0x150);
    Model0218fe1c_Init((u8 *)self + 0x288);
    self->unk_f4 = 0x40;
    self->unk_f8 = 0xff;
    self->unk_fc = NULL;
    self->step = NULL;
    self->unk_f9 = 0;
    self->unk_12e = 0;
    self->unk_12c = 0x1000;
    return self;
}
#pragma force_active reset

static inline void Ov014_FreeFC(Ov014Act_02201b94 *self) {
    void *saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (self->unk_fc != NULL) {
        Ov003FxList *p = self->unk_fc;
        if (p != NULL) {
            Ov003FxList_Dtor(p);
            Heap_Free(p);
        }
        self->unk_fc = NULL;
    }
    gSysState->cur = saved;
}

Ov014Act_02201b94 *Ov014Act_02201b94_Dtor(Ov014Act_02201b94 *self) {
    *(void **)self = Ov014Act_02201b94_vtbl;
    Ov014_FreeFC(self);
    ((Ov014V *)((u8 *)self + 0x100))->v08();
    Model0218fe1c_FreeAnims((u8 *)self + 0x288);
    ResSet_ReleaseAll((u8 *)self + 0x150);
    Ov003Vt_021f7974_Dtor(&self->scripts);
    Ov003Vt_021f7d10_Dtor((u8 *)self + 0x100);
    Ov003Actor_DtorBase(self);
    return self;
}

Ov014Act_02201b94 *Ov014Act_02201b94_DtorDelete(Ov014Act_02201b94 *self) {
    *(void **)self = Ov014Act_02201b94_vtbl;
    Ov014_FreeFC(self);
    ((Ov014V *)((u8 *)self + 0x100))->v08();
    Model0218fe1c_FreeAnims((u8 *)self + 0x288);
    ResSet_ReleaseAll((u8 *)self + 0x150);
    Ov003Vt_021f7974_Dtor(&self->scripts);
    Ov003Vt_021f7d10_Dtor((u8 *)self + 0x100);
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}


void Ov014Act_02201b94_Init(Ov014Act_02201b94 *self) {
    Ov003Actor_Init(self);
    {
        const char *a = data_ov014_022173ce;
        const char *b = data_ov014_022173d9;
        if (a) {
            STD_CopyString((char *)self + 0x160, a);
            STD_CopyString((char *)self + 0x180, b);
            self->unk_153 |= 2;
            STD_CopyString((char *)self + 0x19c, a);
            STD_CopyString((char *)self + 0x1bc, b);
            self->unk_153 |= 4;
        }
    }
    self->unk_150 = 0;
    self->unk_ea |= 0x4000;
}

}
}  // namespace m_02201b94
// ---- merged from ov014_02201dcc.cpp
namespace m_02201dcc {
extern "C" {

extern u8 Ov014Act_02201b94_vtbl[];
extern void *Ov003Vt_021f7d10_Ctor(void *p);
extern void *Ov003Vt_021f7d10_Dtor(void *p);
extern void *ResSet_Init(void *p);
extern void *Model0218fe1c_Init(void *p);
extern void *Model0218fe1c_FreeAnims(void *p);
extern void *ResSet_ReleaseAll(void *p);
extern BOOL Actor_IsReady(Ov003Actor *self);
extern BOOL ResSet_UpdateLoad(void *p);
extern BOOL Ov003TickerSet_IsHeld(void *p);
extern void Ov003TickerSet_Apply(void *p, VecFx32 *a, VecFx32 *b, s32 c);
extern BOOL Model021903b4_Draw(void *p);
extern BOOL Ov003Actor_HandleMsg(Ov003Actor *self, Ov014Msg *msg);
extern BOOL Ov003TickerSet_Init(void *p);
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern BOOL Model0218fe1c_SetRes(void *anim, void *res, s32 a, s32 b);
extern BOOL Stage_UseScaledStats(void);

BOOL Ov014Act_02201b94_IsReady(Ov014Act_02201b94 *self) {
    BOOL r = Actor_IsReady(self);
    if (((s16)self->unk_150) >= 0) {
        r = (r & ResSet_UpdateLoad((u8 *)self + 0x150)) ? TRUE : FALSE;
    }
    return r;
}

BOOL Ov014Act_02201b94_Draw(Ov014Act_02201b94 *self) {
    s32 f;
    BOOL r;
    VecFx32 saved = self->pos;
    if (!Ov003TickerSet_IsHeld((u8 *)self + 0x100)) {
        Ov003TickerSet_Apply((u8 *)self + 0x100, &self->pos, &self->pos, 0x200);
    }
    r = Ov003Actor_Draw(self);
    f = ((s32)self->unk_f4);
    if ((f & 0x40) || (f & 0x1000)) {
        self->unk_300 = self->pos;
        r = Model021903b4_Draw((u8 *)self + 0x288);
    }
    self->pos = saved;
    return r;
}

void Ov014Act_02201b94_RunState(Ov014Act_02201b94 *self) {
    Ov003Actor_RunState(self);
    ((Ov014V *)((u8 *)self + 0x100))->v0c();
}

void Ov014Act_02201b94_Animate(Ov014Act_02201b94 *self) {
    Ov003Actor_Animate(self);
    Model0218fe1c_UpdateAnim((u8 *)self + 0x288, func_0203db40((u8 *)self + 0x24));
}

void Ov014Act_02201b94_HandleMsg(Ov014Act_02201b94 *self, Ov014Msg *msg) {
    if (msg->type == 6) {
        self->unk_f8 = msg->idx;
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
    }
    Ov003Actor_HandleMsg(self, msg);
}

void Ov014Act_02201b94_Start(Ov014Act_02201b94 *self) {
    Ov003Unit *u;
    Ov003Actor_Start(self);
    self->unk_f0 = (u8)self->unk_18;
    self->unk_fc = Ov014_NewFx();
    Ov003TickerSet_Init((u8 *)self + 0x100);
    u = Group_FindNode(gGroup, self->unk_20);
    if (u != NULL) {
        u->unk_a2_0 = 0;
    }
    self->model->alpha = 0;
    self->unk_ea_6 = 1;
    {
        ActorSub48 *m = self->hit;
        m->unk_9a_0 = 0;
        m->unk_9a_3 = 0;
        HitSphere_Unlink_0203f364(m);
    }
    switch (self->unk_f0) {
    case 0:
        Ov003ScriptList_AddTrack(&self->scripts, 0, 1, data_ov014_02216534);
        break;
    case 1:
        Ov003ScriptList_AddTrack(&self->scripts, 1, 1, data_ov014_0221653c);
        break;
    case 2:
        Ov003ScriptList_AddTrack(&self->scripts, 2, 1, data_ov014_02216544);
        break;
    }
    Model0218fe1c_SetRes((u8 *)self + 0x288, (u8 *)self + 0x150, 0, 1);
    self->unk_34a.b0 = 1;
    self->unk_330 = data_ov014_02216630.x;
    self->unk_334 = data_ov014_02216630.y;
    self->unk_338 = data_ov014_02216630.z;
    switch (self->unk_f0) {
    case 0:
        self->hit->offset.y = -0x800;
        break;
    case 1: {
        ActorSub44 *n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->hit->offset.y = -0x4cd;
        break;
    }
    case 2:
        self->unk_12e = Rand_UpTo(5);
        break;
    }
    if (Stage_UseScaledStats()) {
        Ov003Actor_ScaleStats(self, data_ov014_02216554);
        self->unk_12c = 0x1800;
    }
}
struct Ov014Blk12 {
    s32 a[3];
};
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern BOOL Actor_IsDead(Ov003Actor *a);
extern void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);

void Ov014Act_02201b94_Update(Ov014Act_02201b94 *self) {
    Ov003Actor *pl;
    VecFx32 v;
    if (!Ov014_GameIdle()) {
        return;
    }
    self->target = 0xffff;
    pl = ActorMgr_FindPlayer();
    if (pl != NULL) {
        self->target = pl->id;
        if (Actor_IsDead(pl)) {
            return;
        }
    }
    if (self->fsm->current == 1) {
        u32 f = self->unk_f4;
        if (f == 0) {
            Ov003Track *t = self->scripts.cur;
            self->step = &t->steps[t->val];
            Ov003ScriptList_Step(&self->scripts);
            switch (self->step->op) {
            case 0:
                self->unk_f4 |= 4;
                self->fsm->flags |= 0x8000;
                break;
            case 1:
                self->unk_f4 |= 8;
                self->unk_f4 |= 0x3000000;
                self->fsm->flags |= 0x10000;
                break;
            case 2:
                self->unk_f4 |= 0x20;
                self->fsm->flags |= 0x4000;
                break;
            }
        } else if (f & 1) {
            self->unk_b6++;
            if (self->unk_b6 >= 10) {
                self->unk_b6 = 0;
                self->unk_f4 = f ^ 1;
            }
        }
    }
    if (self->msg_flags & 0x200) {
        SndMgr_PlayAt(gSndMgr, 0x67, &self->pos, 0);
    }
    Ov003FxList_Prune(self->unk_fc);
    if (self->pos.y <= 0x4519a) {
        self->fsm->flags |= 0x200000;
    }
    *(Ov014Blk12 *)&v = *(Ov014Blk12 *)&data_ov014_022165e8;
    v.y = self->pos.y;
    if (VEC_Distance(&self->pos, &v) > 0xf000) {
        self->fsm->flags |= 0x200000;
    }
}

}
}  // namespace m_02201dcc

// ---- merged from ov014_02202964.cpp
namespace m_02202964 {
extern "C" {

extern void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);
extern BOOL Ov003TickerSet_IsHeld(void *p);
extern void Ov003TickerSet_SetPaused(void *p, s32 a);
extern void HitSphere_Link(ActorSub48 *p);
extern Ov003Actor *Actor_GetTarget(Actor *self);

extern void Model0218fe1c_SetAnimSpeed(void *a, s32 b);

static inline s32 Ov014e_FxMul64(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

void Ov014Act_02201b94_State20(Ov014Act_02201b94 *self) {
    Model0218fe1c *m38 = self->model;
    ActorSub40 *s = self->fsm;
    s32 hp = Ov014e_FxMul64(m38->scale.x, 0x1333);
    s32 v = self->unk_330;
    switch (ActorSub40_State(s)) {
    case 0: {
        const char *anim = data_ov014_02216500[3];
        EffectObj *e;
        Model0218fe1c_SetAnim((u8 *)self + 0x288, anim, 0x1000, 0);
        Model0218fe1c_SetAnimSpeed((u8 *)self + 0x288, 0xb33);
        Model0218fe1c_SetLoop((u8 *)self + 0x288);
        Model0218fe1c_SetAnim(self->model, anim, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        self->unk_f4 |= 0x300000;
        e = Effect_SpawnId(0x648, &self->pos);
        hp >>= 1;
        e->SetScaleAll(hp);
        e = Effect_SpawnId(0x322, &self->pos);
        e->SetScaleAll(hp + 0x800);
        e->loopCount = -1;
        Ov003FxList_Add(self->unk_fc, 0xff, e);
        self->fsm->st++;
        break;
    }
    case 1:
        if (v >= hp) {
            break;
        }
        v += Ov014e_FxMul64(hp >> 1, 0x1ec);
        if (v >= hp) {
            s->st++;
        }
        self->unk_330 = v;
        self->unk_334 = v;
        self->unk_338 = v;
        break;
    case 2:
        s->timer++;
        if (s->timer != 0x1e) {
            break;
        }
        Effect_SpawnId(0x38a, &self->pos)->SetScaleAll(hp >> 1);
        SndMgr_PlayAt(gSndMgr, 0x67, &self->pos, 0);
        Ov003FxList_Kill(self->unk_fc, 0xff);
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    case 3: {
        u8 c = m38->alpha;
        if (c < 0x1f) {
            c = c + 1;
            if (c >= 0x1f) {
                self->unk_f4 ^= 0x100000;
                c = 0x1f;
                m38->alpha = c;
            }
            self->model->alpha = c;
        }
        if (v > 0) {
            v -= Ov014e_FxMul64(hp >> 1, 0x266);
            if (v <= 0) {
                v = 0;
                self->unk_f4 ^= 0x200000;
                self->unk_34a.b0 = 0;
            }
            self->unk_330 = v;
            self->unk_334 = v;
            self->unk_338 = v;
        }
        if (self->unk_f4 & 0x100000) {
            break;
        }
        if (self->unk_f4 & 0x200000) {
            break;
        }
        self->fsm->st++;
        break;
    }
    case 4:
        switch (self->unk_f0) {
        case 0:
            s->timer++;
            if (s->timer != 10) {
                break;
            }
            self->friction = 0;
            self->gravity = 0;
            self->speed = 0x52;
            self->velY = -0x148;
            self->fsm->timer = 0;
            self->fsm->st++;
            break;
        case 1: {
            ActorSub44 *n;
            s->timer++;
            if (s->timer != 10) {
                break;
            }
            self->hit->unk_30 = 0;
            n = self->unk_44;
            n->unk_22_0 = true;
            n->unk_22_1 = true;
            self->speed = 0;
            self->friction = 0;
            self->gravity = 0;
            self->velY = -0x133;
            self->fsm->timer = 0;
            self->fsm->st++;
            break;
        }
        case 2:
            self->unk_f4 ^= 0x40;
            History_SetState(s, 1, 0);
            break;
        }
        break;
    case 5:
        switch (self->unk_f0) {
        case 0: {
            ActorSub40 *w;
            Actor_Move(self, 0);
            w = self->fsm;
            w->timer++;
            if (w->timer != 0x19) {
                break;
            }
            self->fsm->timer = 0;
            self->unk_f4 ^= 0x40;
            History_SetState(self->fsm, 1, 0);
            break;
        }
        case 1: {
            ActorSub40 *w;
            ActorSub48 *m;
            Actor_Move(self, 0);
            w = self->fsm;
            w->timer++;
            if (w->timer != 0x37) {
                break;
            }
            m = self->hit;
            m->unk_9a_0 = true;
            m->unk_9a_3 = true;
            HitSphere_Link(m);
            self->fsm->timer = 0;
            self->unk_f4 ^= 0x40;
            History_SetState(self->fsm, 1, 0);
            break;
        }
        }
        break;
    }
}

void Ov014Act_02201b94_StateIdle(Ov014Act_02201b94 *self) {
    switch (self->fsm->st) {
    case 0: {
        ActorSub44 *n;
        ActorSub48 *m;
        Model0218fe1c_SetAnim(self->model, data_ov014_02216500[3], 0x89, 0);
        Model0218fe1c_SetLoop(self->model);
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        switch (self->unk_f0) {
        case 0:
            self->hit->offset.y = -0x800;
            break;
        case 1:
            self->hit->offset.y = -0x4cd;
            break;
        }
        m = self->hit;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        HitSphere_Link(m);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
    }
    case 1: {
        u32 f = self->unk_f4;
        if (!(f & 1) && f != 0) {
            s32 off = 0;
            switch (self->unk_f0) {
            case 0:
                off = 0x1000;
                break;
            case 1:
                off = 0x800;
                break;
            }
            if (self->pos.y < off + (self->radius + 0x4719a)) {
                self->velY = 0x333;
                Actor_Move(self, 0);
            } else {
                ActorSub44 *n = self->unk_44;
                n->unk_22_0 = 1;
                n->unk_22_1 = 1;
                self->unk_f4 = 1;
            }
        }
        break;
    }
    }
    Actor_TurnToActor(self, Actor_GetTarget(self), 0xcd);
}

void Ov014Act_02201b94_StateThrown(Ov014Act_02201b94 *self) {
    if (self->fsm->st == 0) {
        self->hit->unk_30 = 0;
    }
    Ov003Actor_StateThrown(self);
}

void Ov014Act_02201b94_StateDown(Ov014Act_02201b94 *self) {
    Ov003FxList_KillAll(self->unk_fc);
    self->hit->unk_30 = 0x40000000;
    if (self->fsm->st == 0) {
        SndMgr_PlayAt(gSndMgr, 0x67, &self->pos, 0);
        self->hit->offset.y = 0;
        if (!Ov003TickerSet_IsHeld((u8 *)self + 0x100)) {
            Ov003TickerSet_SetPaused((u8 *)self + 0x100, 1);
        }
    }
    Ov003Actor_StateDown(self);
    if (self->fsm->st == 0 && self->unk_e8 == 0) {
        self->speed = 0;
        self->friction = 0;
        self->gravity = 0;
        self->velY = 0x29;
    }
}

extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern void Ov003TickerSet_Start(void *p, s32 a, s32 b, s32 c, s32 d);
extern void ActorMgr_SendToKindOthers(s32 a, u16 b, s32 c, s32 d, s32 e, void *f);

void Ov014Act_02201b94_StateDie(Ov014Act_02201b94 *self) {
    s32 off;
    Model0218fe1c *m38 = self->model;
    ActorSub40 *s = self->fsm;
    s32 v = self->unk_330;
    s32 hp = m38->scale.x;
    self->unk_94_1 = 1;
    switch (s->st) {
    case 0: {
        ActorSub48 *m;
        ActorSub44 *n;
        const char *anim;
        Ov003FxList_KillAll(self->unk_fc);
        m = self->hit;
        m->unk_9a_0 = 0;
        m->unk_9a_3 = 0;
        HitSphere_Unlink_0203f364(m);
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->targetObj->target = 0xffff;
        self->unk_34a.b0 = 1;
        self->unk_330 = data_ov014_02216630.x;
        self->unk_334 = data_ov014_02216630.y;
        self->unk_338 = data_ov014_02216630.z;
        anim = data_ov014_02216500[3];
        Model0218fe1c_SetAnim((u8 *)self + 0x288, anim, 0x1000, 0);
        Model0218fe1c_SetAnimSpeed((u8 *)self + 0x288, 0xccd);
        Model0218fe1c_SetLoop((u8 *)self + 0x288);
        Model0218fe1c_SetAnim(self->model, anim, 0x400, 0);
        Model0218fe1c_SetLoop(self->model);
        self->unk_f4 |= 0x1000;
        self->unk_f4 |= 0x1300000;
        Ov003TickerSet_SetPaused((u8 *)self + 0x100, FALSE);
        off = 0x100;
        // Kept (round auA honesty audit): never-true pointer-bit test, no honest form found (jkK); the file
        // has .data and the function is mid-file, so it can't be cut out to a dsd gap.
        if ((u32)self & 3) {
            off = 0x100;
        }
        Ov003TickerSet_Start((u8 *)self + off, FALSE, 0, TRUE, NULL);
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    }
    case 1:
        if (v >= hp) {
            break;
        }
        v += Ov014e_FxMul64(hp >> 1, 0x19a);
        if (v >= hp) {
            SndMgr_PlayAt(gSndMgr, 0x68, &self->pos, 0);
            self->fsm->st++;
        }
        self->unk_330 = v;
        self->unk_334 = v;
        self->unk_338 = v;
        break;
    case 2: {
        EffectObj *e;
        s->timer++;
        if (s->timer != 10) {
            break;
        }
        e = Effect_SpawnId(0x322, &self->pos);
        hp >>= 1;
        e->SetScaleAll(hp);
        e->loopCount = -1;
        Ov003FxList_Add(self->unk_fc, 0xff, e);
        e = Effect_SpawnId(0x648, &self->pos);
        e->SetScaleAll(hp);
        Ov003FxList_Add(self->unk_fc, 0xfe, e);
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    }
    case 3: {
        u8 c = m38->alpha;
        s32 h;
        EffectObj *e;
        if (c != 0) {
            c--;
            if (c == 0) {
                c = 0;
            }
            m38->alpha = c;
        }
        if (c == 0) {
            self->unk_f4 &= ~0x100000;
        }
        m38 = self->model;
        h = m38->scale.x;
        if (h > 0) {
            h -= Ov014e_FxMul64(hp >> 1, 0xcd);
            if (h <= 0) {
                h = 0;
            }
            m38->scale.x = h;
            m38->scale.y = h;
            m38->scale.z = h;
        }
        if (v > 0) {
            v -= Ov014e_FxMul64(hp >> 1, 0x19a);
            if (v <= 0) {
                v = 0;
                self->unk_f4 ^= 0x200000;
                self->unk_34a.b0 = 0;
            }
            self->unk_330 = v;
            self->unk_334 = v;
            self->unk_338 = v;
        }
        if ((self->unk_f4 & 0x1000000) && !(self->unk_f4 & 0x200000)) {
            e = Effect_SpawnId(0x69, &self->pos);
            e->SetScaleAll(0x40);
            Ov003FxList_Add(self->unk_fc, 0xfd, e);
            self->unk_f4 ^= 0x1000000;
            SndMgr_PlayAt(gSndMgr, 0x77, &self->pos, 0);
            Ov003FxList_Kill(self->unk_fc, 0xff);
        }
        e = Effect_Find_020657b0(gEffectMgr, Ov003FxList_Get(self->unk_fc, 0xfd));
        if (e != NULL) {
            e->SetScaleAll(e->scale.x + 0x148);
        }
        if (self->unk_f4 & 0x100000) {
            break;
        }
        if (self->unk_f4 & 0x200000) {
            break;
        }
        if (Ov003FxList_Has(self->unk_fc, 0xfe)) {
            break;
        }
        if (Ov003FxList_Has(self->unk_fc, 0xfd)) {
            break;
        }
        {
            u8 b[4];
            b[0] = self->unk_f0 + 1;
            ActorMgr_SendToKindOthers(0x5c0e, self->kind, 6, 1, 1, b);
        }
        Group_UpdateActor(gGroup, 0, self);
        self->vfunc_08();
        break;
    }
    }
}
}
}  // namespace m_02202964

// ---- merged from ov014_02202f1c.cpp
namespace m_02202f1c {
extern "C" {

extern void func_ov014_02202fe8(Ov014Act_02201b94 *self);
extern void func_ov014_022033a8(Ov014Act_02201b94 *self);
extern void func_ov014_022038b8(Ov014Act_02201b94 *self);

void Ov014Act_02201b94_StateAttack(Ov014Act_02201b94 *self) {
    switch (self->fsm->st) {
    case 0:
    case 1:
    case 2:
        func_ov014_02202fe8(self);
        break;
    case 10:
    case 11:
    case 12:
        func_ov014_022033a8(self);
        break;
    case 20:
    case 21:
    case 22:
        func_ov014_022038b8(self);
        break;
    case 30:
        if (self->unk_f4 & 4) {
            self->unk_f4 ^= 4;
        }
        self->unk_f4 |= 1;
        History_SetState(self->fsm, 0x15, 0);
        break;
    }
}


extern Ov003Actor *Actor_GetTarget(Actor *self);
extern void Vec_RotateY(VecFx32 *out, const void *a, s32 b);
extern void *SndMgr_PlayAt(void *mgr, s32 id, const VecFx32 *pos, s32 a);

#define OV014_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014_SQRT_PARAM (*(volatile u64 *)0x40002b8)

struct Ov014Blk12F {
    s32 w[3];
};

void func_ov014_02202fe8(Ov014Act_02201b94 *self) {
    VecFx32 v;
    VecFx32 tp;
    VecFx32 c;
    VecFx32 diff;
    s32 zero = 0;
    Ov003Actor *pl = Actor_GetTarget(self);
    tp = pl->pos;
    self->unk_94_1 = 1;
    switch (self->fsm->st) {
    case 0: {
        s32 h;
        u16 ang;
        Model0218fe1c_SetAnim(self->model, data_ov014_02216500[0], 0x111, zero);
        Model0218fe1c_SetLoop(self->model);
        v.x = zero;
        v.y = 0x1800;
        v.z = 0x1000;
        Vec_RotateY(&v, &v, self->rot_y);
        VEC_Add(&self->pos, &v, &v);
        self->speed = zero;
        self->velY = zero;
        self->friction = zero;
        self->gravity = zero;
        {
            s64 sq;
            s32 dx = self->pos.x - v.x;
            s32 dz = self->pos.z - v.z;
            sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            OV014_SQRTCNT = 1;
            OV014_SQRT_PARAM = (u64)(sq * 4);
        }
        while (OV014_SQRTCNT & 0x8000) {
        }
        h = ((s32)OV014_SQRT_RESULT + 1) >> 1;
        ang = FX_Atan2(h, v.y - self->pos.y);
        self->speed = FX_Mul(OV014_SIN(ang), 0x23d);
        self->velY = FX_Mul(OV014_COS(ang), 0x23d);
        SndMgr_PlayAt(gSndMgr, 0x57, &self->pos, 0);
        self->fsm->st++;
        break;
    }
    case 1: {
        ActorSub40 *w;
        Actor_Move(self, zero);
        w = self->fsm;
        w->timer++;
        if (w->timer != 0x1e) {
            break;
        }
        self->velY = zero;
        self->friction = zero;
        self->gravity = zero;
        self->speed = 0x400;
        self->fsm->timer = zero;
        self->fsm->st++;
        break;
    }
    case 2: {
        s32 d;
        Actor_TurnToPos(self, &tp, 0x19a);
        self->moveYaw = self->rot_y;
        tp.y = self->pos.y;
        d = VEC_Distance(&self->pos, &tp);
        if (d <= 0x1000) {
            *(Ov014Blk12F *)&c = *(const Ov014Blk12F *)&data_ov014_0221657c;
            VEC_Add(&self->pos, &c, &v);
            self->unk_b8 = v;
            SndMgr_PlayAt(gSndMgr, 0x50, &self->pos, zero);
            self->fsm->timer = zero;
            self->fsm->st = 10;
        }
        if (d >= 0x3000) {
            Actor_Move(self, 0);
        } else {
            Model0218fe1c_SetAnim(self->model, data_ov014_02216500[3], 0x111, zero);
            Model0218fe1c_SetLoop(self->model);
            v.z = 0x1000;
            v.x = zero;
            v.y = zero;
            Vec_RotateY(&v, &v, self->rot_y);
            VEC_Add(&tp, &v, &v);
            diff.x = v.x - self->pos.x;
            diff.y = v.y - self->pos.y;
            diff.z = v.z - self->pos.z;
            VEC_MultAdd(0x19a, &diff, &self->pos, &self->pos);
        }
        Body_Update(self->hit, 1, 0, 0);
        break;
    }
    }
}


extern BOOL func_ov000_0219aca8(Actor *a, Actor *b, u16 c, u8 d, void *e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern void HitSphere_Link(ActorSub48 *p);

static inline s32 Ov014B_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov014B_Approach(Ov003Actor *self, s32 k) {
    VecFx32 d;
    {
        s32 bx = self->unk_b8.x;
        s32 by = self->unk_b8.y;
        s32 bz = self->unk_b8.z;
        d.x = bx - self->pos.x;
        d.y = by - self->pos.y;
        d.z = bz - self->pos.z;
    }
    VEC_MultAdd(k, &d, &self->pos, &self->pos);
}

void func_ov014_022033a8(Ov014Act_02201b94 *self) {
    s32 h = FX_Mul(self->model->scale.y, 0x15c3);
    Actor_GetTarget(self);
    switch (self->fsm->st) {
    case 10: {
        FieldCam *cam;
        Ov014B_Approach(self, 0x19a);
        if (VEC_Distance(&self->pos, &self->unk_b8) <= 0x4cd) {
            Model0218fe1c_SetAnim(self->model, data_ov014_02216500[1], 0x400, 0);
            SndMgr_PlayAt(gSndMgr, 0x54, &self->pos, 0);
            {
                s32 z = self->pos.z;
                self->unk_b8.x = self->pos.x;
                self->unk_b8.y = h + 0x4719a;
                self->unk_b8.z = z;
            }
            self->speed = 0;
            self->friction = 0;
            self->gravity = 0;
            self->velY = -0x59a;
            self->hit->offset.y = -0x2000;
            self->unk_f4 |= 0x400000;
            self->fsm->st++;
        }
        cam = &gSceneCmd->cam;
        cam->unk_f8.x = 0xaab;
        cam->unk_da_4 = 1;
        break;
    }
    case 11: {
        VecFx32 save;
        EffectObj *e;
        FieldState *g;
        Actor_Move(self, 0);
        save = self->unk_b8;
        if (VEC_Distance(&self->pos, &self->unk_b8) > 0x4cd && self->pos.y > save.y) {
            break;
        }
        if (self->unk_f4 & 0x400000) {
            self->unk_f4 ^= 0x400000;
        }
        self->unk_f4 |= 0x800000;
        g = gSceneCmd;
        g->cam.base.shakeX = 0;
        g->cam.base.shakeY = 1;
        g->cam.base.shakeZ = 0;
        g->cam.base.shakeTime = 0x1e;
        g->cam.base.shakeLen = 0x3c;
        g->cam.base.shakeCur = 0x3c;
        SndMgr_PlayAt(gSndMgr, 0x17, &self->pos, 0);
        e = Effect_SpawnId(0x66, &self->pos);
        e->SetScaleAll(0x2000);
        {
            VecFx32 r = {0, 0, 0};
            r.y = -h;
            e->AddPos(&r);
        }
        Ov003FxList_Add(self->unk_fc, 0xfb, e);
        {
        VecFx32 c;
        *(Ov014Blk12F *)&c = *(const Ov014Blk12F *)&data_ov014_02216588;
        c.x = self->pos.x;
        c.z = self->pos.z;
        e = Effect_SpawnId(0x68, &c);
        e->alpha = FX_Div(0x10000, 0x1f000);
        Ov003FxList_Add(self->unk_fc, 0xfd, e);
        }
        self->pos = save;
        {
            ActorSub48 *m = self->hit;
            m->unk_9a_0 = 1;
            m->unk_9a_3 = 1;
            HitSphere_Link(m);
        }
        self->fsm->st++;
        break;
    }
    case 12: {
        ActorSub40 *s = self->fsm;
        EffectObj *o;
        if (self->unk_f4 & 0x800000) {
            s->timer++;
            if (s->timer == 10) {
                self->fsm->timer = 0;
                self->unk_f4 ^= 0x800000;
            }
        }
        o = Effect_Find_020657b0(gEffectMgr, Ov003FxList_Get(self->unk_fc, 0xfd));
        if (o != NULL) {
            o->SetScaleAll(o->scale.x + 0x19a);
        }
        if (!Ov003FxList_Has(self->unk_fc, 0xfb)) {
            s = self->fsm;
            s->timer++;
            if (s->timer == 0x14) {
                self->fsm->timer = 0;
                self->fsm->st = 0x14;
            }
        }
        break;
    }
    }
    {
    VecFx32 v = {0, 0, 0};
    v.y = -h;
    if (self->unk_f4 & 0x400000) {
        func_ov000_0219aca8(self, self, Ov014B_FxMul64(self->unk_12c, 0x5a), 0x30, &v, 0, self->radius, 0x3000, 100, 0x1000);
        self->unk_94_1 = 1;
    }
    if (self->unk_f4 & 0x800000) {
        func_ov000_0219aca8(self, self, Ov014B_FxMul64(self->unk_12c, 0x5a), 0x30, &v, 0, 0x2ccc, 0x1000, 100, 0x1000);
        self->unk_94_1 = 1;
    }
    }
}

}
}  // namespace m_02202f1c

// ---- merged from ov014_022038b8.cpp
namespace m_022038b8 {
extern "C" {

extern BOOL Ov003TickerSet_IsHeld(void *p);
extern void Ov003TickerSet_SetPaused(void *p, s32 a);
extern void Ov003TickerSet_SetHold(void *p, s32 a);
extern void *SndMgr_PlayAtPitch(void *a, s32 b, VecFx32 *c, s32 d);
extern void Ov003TickerSet_Start(void *p, s32 a, s32 b, s32 c, s32 d);

void func_ov014_022038b8(Ov014Act_02201b94 *self) {
    switch (self->fsm->st) {
    case 0x14:
        Model0218fe1c_SetAnim(self->model, data_ov014_02216500[3], 0x111, 0);
        Model0218fe1c_SetLoop(self->model);
        self->hit->offset.y = -0x800;
        self->speed = 0;
        self->velY = -0x148;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
        break;
    case 0x15: {
        u16 n = 0;
        ActorSub40 *w;
        Actor_Move(self, 0);
        w = self->fsm;
        w->timer++;
        if (w->timer != 15) {
            return;
        }
        self->fsm->timer = 0;
        if (self->step != NULL) {
            n = self->step->a;
        }
        self->unk_f9++;
        if (self->unk_f9 >= n) {
            self->fsm->st = 0x1e;
            return;
        }
        Ov003TickerSet_Start((u8 *)self + 0x100, 0, 0, 1, 0);
        self->fsm->st++;
        break;
    }
    case 0x16: {
        u16 t;
        ActorSub40 *w = self->fsm;
        w->timer++;
        t = w->timer;
        if (t <= 70) {
            if (!Ov003TickerSet_IsHeld((u8 *)self + 0x100)) {
                Ov003TickerSet_SetHold((u8 *)self + 0x100, 1);
            }
        } else {
            if (Ov003TickerSet_IsHeld((u8 *)self + 0x100) == 1) {
                Ov003TickerSet_SetPaused((u8 *)self + 0x100, 0);
            }
        }
        if (t == 50 && !Ov003FxList_Has(self->unk_fc, 0xfc)) {
            VecFx32 v = data_ov014_022165dc;
            EffectObj *e;
            v.x = self->pos.x;
            v.z = self->pos.z;
            e = Effect_SpawnId(0x2bd, &v);
            e->SetScaleAll(0x4000);
            e->speed = 0x2000;
            e->alpha = FX_Div(0x10000, 0x1f000);
            e->loopCount = -1;
            Ov003FxList_Add(self->unk_fc, 0xfc, e);
        }
        if (t == self->step->time) {
            SndMgr_PlayAtPitch(gSndMgr, 0x71, &self->pos, -2);
            Ov003TickerSet_SetPaused((u8 *)self + 0x100, 1);
            Ov003FxList_Kill(self->unk_fc, 0xfc);
            self->fsm->timer = 0;
            self->fsm->st = 0;
        }
        break;
    }
    }
}
}
}  // namespace m_022038b8

// ---- merged from ov014_02203b34.cpp
namespace m_02203b34 {
extern "C" {

extern void func_ov014_02203c00(Ov014Act_02201b94 *self);
extern void func_ov014_02204134(Ov014Act_02201b94 *self);
extern void func_ov014_0220446c(Ov014Act_02201b94 *self);

void Ov014Act_02201b94_StateAttack2(Ov014Act_02201b94 *self) {
    switch (self->fsm->st) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        func_ov014_02203c00(self);
        break;
    case 10:
    case 11:
    case 12:
        func_ov014_02204134(self);
        break;
    case 20:
    case 21:
        func_ov014_0220446c(self);
        break;
    case 30:
        if (self->unk_f4 & 8) {
            self->unk_f4 ^= 8;
        }
        self->unk_f4 |= 1;
        History_SetState(self->fsm, 0x15, 0);
        break;
    }
}

}
}  // namespace m_02203b34

// ---- merged from ov014_022045d0.cpp
namespace m_022045d0 {
extern "C" {

extern Ov003Actor *Actor_GetTarget(Actor *self);
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern void HitSphere_Link(ActorSub48 *p);
extern void *SndMgr_PlayAt(void *mgr, s32 id, VecFx32 *pos, s32 a);
extern BOOL func_ov000_0219aca8(Actor *a, Actor *b, u16 c, u8 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern Ov003Actor *ActorMgr_FindPlayer(void);

struct Ov014bBlk12 {
    s32 w[3];
};

static inline void Ov014b_Begin(Ov014Act_02201b94 *self, VecFx32 *w) {
    self->speed = 0x400;
    self->velY = 0;
    self->friction = 0;
    self->gravity = 0;
    {
        VecFx32 v = {0, 0, 0};
        v.x = Rand_PlusMinus(0x3000);
        v.z = Rand_PlusMinus(0x2800);
        VEC_Add(&v, &data_ov014_022165e8, w);
        w->y = self->pos.y;
        self->unk_b8 = *w;
        self->unk_f4 |= 0x400000;
        SndMgr_PlayAt(gSndMgr, 0x57, &self->pos, 0);
    }
    self->fsm->st++;
}

static inline void Ov014b_Effect(Ov014Act_02201b94 *self) {
    VecFx32 t;
    *(Ov014bBlk12 *)&t = *(const Ov014bBlk12 *)&data_ov014_02216570;
    if (self->unk_f4 & 0x400000) {
        func_ov000_0219aca8(self, self, (u16)(((s64)self->unk_12c * 0x6e + 0x800) >> 12), 0x30, (s32)&t, 0, 0x2800, 0x1000, 0x64, 0x1000);
        self->unk_94_1 = 1;
    }
}

extern void *SndMgr_PlayAtPitch(void *a, s32 b, VecFx32 *c, s32 d);
extern void Model0218fe1c_PauseAnim(void *a);
extern void Model0218fe1c_ResumeAnim(void *a);
extern s32 Ov003TickerSet_IsHeld(void *p);
extern void Ov003TickerSet_SetPaused(void *p, s32 a);
extern void Ov003TickerSet_Start(void *p, s32 a, s32 b, s32 c, s32 d);

static inline s32 Ov014c_FxMul64(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

void func_ov014_02203c00(Ov014Act_02201b94 *self) {
    VecFx32 tp;
    VecFx32 t;
    Ov003Actor *tg = Actor_GetTarget(self);
    tp.x = tg->pos.x;
    tp.y = tg->pos.y;
    tp.z = tg->pos.z;
    switch (self->fsm->st) {
    case 0: {
        EffectObj *e;
        Model0218fe1c_SetAnim(self->model, data_ov014_02216500[1], 0x3f, 0);
        Model0218fe1c_SetLoop(self->model);
        SndMgr_PlayAtPitch(gSndMgr, 0x71, &self->pos, -2);
        e = Effect_SpawnId(0x5e4, &self->pos);
        e->SetScaleAll(0x2000);
        Ov003FxList_Add(self->unk_fc, 0xf9, e);
        self->fsm->st++;
        break;
    }
    case 1: {
        EffectObj *e;
        if (self->unk_f9 != 0) {
            Actor_TurnToPos(self, &tp, 0x148);
            self->moveYaw = self->rot_y;
        }
        if (Ov003FxList_Has(self->unk_fc, 0xf9)) {
            break;
        }
        Model0218fe1c_PauseAnim(self->model);
        e = Effect_SpawnId(0x68, &self->pos);
        e->SetScaleAll(0x1800);
        e->SetRotXYZ(0x71c, self->rot_y, self->rot_z);
        e->alpha = FX_Div(0xf000, 0x1f000);
        Ov003FxList_Add(self->unk_fc, 0xfd, e);
        SndMgr_PlayAtPitch(gSndMgr, 0x66, &self->pos, -5);
        Effect_SpawnId(0x579, &self->pos)->SetScaleAll(0x2000);
        if (Ov003TickerSet_IsHeld((u8 *)self + 0x100) == 1) {
            Ov003TickerSet_SetPaused((u8 *)self + 0x100, 0);
        }
        Ov003TickerSet_Start((u8 *)self + 0x100, 0, 0, 1, 0);
        self->fsm->st++;
        break;
    }
    case 2:
        if (!Ov003FxList_Has(self->unk_fc, 0xfd)) {
            u8 i;
            ActorSub48 *m;
            Model0218fe1c_ResumeAnim(self->model);
            Ov003TickerSet_SetPaused((u8 *)self + 0x100, 1);
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            self->speed = 0x4cd;
            self->unk_f4 |= 0x400000;
            m = self->hit;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(m);
            for (i = 0; i < 3; i++) {
                EffectObj *e = Effect_SpawnId(0x3ea, &self->pos);
                e->SetScaleAll(0x6800);
                e->SetRotXYZ(0, (u16)(self->rot_y + data_ov014_02216510[i]), 0);
                e->alpha = FX_Div(0xb000, 0x1f000);
                MIi_CpuClear32(0xffffffff, (u8 *)e + 0x84, 0x40);
                e->loopCount = -1;
                Ov003FxList_Add(self->unk_fc, 0xfa, e);
            }
            SndMgr_PlayAt(gSndMgr, 0x57, &self->pos, 0);
            self->fsm->st++;
        } else {
            EffectObj *o = Effect_Find_020657b0(gEffectMgr, Ov003FxList_Get(self->unk_fc, 0xfd));
            if (o != NULL) {
                o->SetScaleAll(o->scale.x + 0xa4);
            }
        }
        self->unk_94_1 = 1;
        break;
    case 3:
        tp.y = self->pos.y;
        if (VEC_Distance(&self->pos, &tp) < 0x5000) {
            self->fsm->st++;
        } else {
            Actor_TurnToPos(self, &tp, 0x148);
            self->moveYaw = self->rot_y;
            Actor_Move(self, 0);
        }
        Ov003FxList_Place(self->unk_fc, 0xfa, &self->pos, NULL, 0, 0, 0);
        break;
    case 4:
        Actor_Move(self, 0);
        Body_Update(self->hit, 1, 0, 0);
        if (self->hit->unk_50 & 0x40000000) {
            if (self->unk_f4 & 0x400000) {
                self->unk_f4 ^= 0x400000;
            }
            self->hit->unk_30 = 0;
            self->fsm->st = 10;
        }
        Ov003FxList_Place(self->unk_fc, 0xfa, &self->pos, NULL, 0, 0, 0);
        break;
    }
    if (self->pos.z >= 0xc000) {
        if (self->unk_f4 & 0x1000000) {
            self->unk_f4 ^= 0x1000000;
            self->hit->unk_30 = 0x40000000;
        }
    }
    if (self->fsm->st >= 2) {
        self->unk_94_1 = 1;
    }
    *(Ov014bBlk12 *)&t = *(const Ov014bBlk12 *)&data_ov014_0221660c;
    if (self->unk_f4 & 0x400000) {
        func_ov000_0219aca8(self, self, (u16)Ov014c_FxMul64(self->unk_12c, 0x6e), 0x30, (s32)&t, 0, 0x2800, 0x1000, 0x64, 0x1000);
        self->unk_94_1 = 1;
    }
}

void func_ov014_02204134(Ov014Act_02201b94 *self) {
    VecFx32 w;
    Robo021ca458 *pl;
    Actor_GetTarget(self);
    switch (self->fsm->st) {
    case 10:
        Ov014b_Begin(self, &w);
    case 11:
        w = self->unk_b8;
        Actor_TurnToPos(self, &w, 0xcd);
        self->moveYaw = self->rot_y;
        Actor_Move(self, 0);
        Ov003FxList_Place(self->unk_fc, 0xfa, &self->pos, NULL, 0, 0, 0);
        if (VEC_Distance(&self->pos, &self->unk_b8) <= 0x4000) {
            self->friction = 0xf5c;
            self->fsm->st++;
        }
        break;
    case 12:
        w = self->unk_b8;
        Actor_TurnToPos(self, &w, 0xcd);
        self->moveYaw = self->rot_y;
        Actor_Move(self, 0);
        if (Ov003FxList_Has(self->unk_fc, 0xfa)) {
            Ov003FxList_Place(self->unk_fc, 0xfa, &self->pos, NULL, 0, 0, 0);
        }
        if (self->speed <= 0x19a) {
            if (self->unk_f4 & 0x400000) {
                self->unk_f4 ^= 0x400000;
            }
            Ov003FxList_Kill(self->unk_fc, 0xfa);
        }
        if (self->speed <= 0x52) {
            ActorSub48 *m;
            self->hit->unk_30 = 0x40000000;
            m = self->hit;
            m->unk_9a_0 = 1;
            m->unk_9a_3 = 1;
            HitSphere_Link(m);
            self->fsm->st = 20;
        }
        break;
    }
    Ov014b_Effect(self);
    pl = (Robo021ca458 *)ActorMgr_FindPlayer();
    if (pl != NULL) {
        pl->unk_b90.x = self->pos.x;
        pl->unk_b90.y = self->pos.y;
        pl->unk_b90.z = self->pos.z;
        pl->unk_b9c = 0x4cd;
    }
}


void func_ov014_0220446c(Ov014Act_02201b94 *self) {
    VecFx32 v;
    Ov003Actor *t = Actor_GetTarget(self);
    v.x = t->pos.x;
    v.y = t->pos.y;
    v.z = t->pos.z;
    switch (self->fsm->st) {
    case 20: {
        s32 n;
        const Ov003Step *p;
        Model0218fe1c_SetAnim(self->model, data_ov014_02216500[3], 0x52, 0);
        Model0218fe1c_SetLoop(self->model);
        {
            ActorSub48 *m = self->hit;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(m);
        }
        if (self->unk_f4 & 0x2000000) {
            self->unk_f4 ^= 0x2000000;
        }
        n = 0;
        p = self->step;
        if (p != NULL) {
            n = p->a;
        }
        if (++self->unk_f9 >= n) {
            self->fsm->st = 30;
            return;
        }
        {
            ActorSub48 *m = self->hit;
            m->unk_9a_0 = 1;
            m->unk_9a_3 = 1;
            HitSphere_Link(m);
        }
        self->fsm->st++;
        break;
    }
    case 21: {
        ActorSub40 *s;
        Actor_TurnToPos(self, &v, 0x148);
        self->moveYaw = self->rot_y;
        s = self->fsm;
        s->timer++;
        if (self->step->time == s->timer) {
            self->fsm->timer = 0;
            self->fsm->st = 0;
        }
        break;
    }
    }
}

extern const VecFx32 data_ov014_022167d0[];

void func_ov014_022046ac(Ov014Act_02201b94 *self);

extern void func_ov014_022049e8(Ov014Act_02201b94 *self);
extern void func_ov014_022053f8(Ov014Act_02201b94 *self);

void Ov014Act_02201b94_StateShoot(Ov014Act_02201b94 *self) {
    switch (self->fsm->st) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        func_ov014_022046ac(self);
        break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
        func_ov014_022049e8(self);
        break;
    case 20:
    case 21:
        func_ov014_022053f8(self);
        break;
    case 30:
        if (self->unk_f4 & 0x20) {
            self->unk_f4 ^= 0x20;
        }
        self->unk_f4 |= 1;
        History_SetState(self->fsm, 0x15, 0);
        break;
    }
}


void func_ov014_022046ac(Ov014Act_02201b94 *self) {
    VecFx32 w;
    Robo021ca458 *pl;
    Actor_GetTarget(self);
    switch (self->fsm->st) {
    case 0:
        self->speed = 0xb33;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        w.x = 0;
        w.y = 0x4719a;
        w.z = 0xf000;
        w.y = self->pos.y;
        self->unk_b8 = w;
        SndMgr_PlayAt(gSndMgr, 0x57, &self->pos, 0);
        self->fsm->st++;
    case 1:
        w = self->unk_b8;
        Actor_TurnToPos(self, &w, 0x400);
        self->moveYaw = self->rot_y;
        Actor_Move(self, 0);
        if (VEC_Distance(&self->pos, &self->unk_b8) <= 0x2000) {
            self->fsm->st++;
        }
        break;
    case 2: {
        EffectObj *e;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->speed = 0xb33;
        w = data_ov014_022167d0[self->unk_12e];
        w.y = self->pos.y;
        self->unk_b8 = w;
        e = Effect_SpawnId(0x4b0, &self->pos);
        e->SetScaleXYZ(0x99a, 0x99a, 0x1000);
        Ov003FxList_Add(self->unk_fc, 0, e);
        self->fsm->st++;
        break;
    }
    case 3:
        w = self->unk_b8;
        Actor_TurnToPos(self, &w, 0x11f);
        self->moveYaw = self->rot_y;
        Actor_Move(self, 0);
        Ov003FxList_Place(self->unk_fc, 0, &self->pos, &self->rot, 0, 0, 0);
        if (VEC_Distance(&self->pos, &self->unk_b8) <= 0x6000) {
            self->friction = 0xecd;
            SndMgr_PlayAt(gSndMgr, 0x57, &self->pos, 0);
            self->fsm->st++;
        }
        break;
    case 4:
        w = self->unk_b8;
        Actor_TurnToPos(self, &w, 0x19a);
        self->moveYaw = self->rot_y;
        Actor_Move(self, 0);
        Ov003FxList_Place(self->unk_fc, 0, &self->pos, &self->rot, 0, 0, 0);
        if (self->speed <= 0x52) {
            if (++self->unk_12e >= 6) {
                self->unk_12e = 0;
            }
            self->fsm->st = 10;
        }
        break;
    }
    if (self->speed > 0x19a) {
        pl = (Robo021ca458 *)ActorMgr_FindPlayer();
        if (pl != NULL) {
            pl->unk_b90.x = self->pos.x;
            pl->unk_b90.y = self->pos.y;
            pl->unk_b90.z = self->pos.z;
            pl->unk_b9c = 0x400;
        }
    }
}

}
}  // namespace m_022045d0

// ---- merged from ov014_022049e8.cpp
namespace m_022049e8 {
struct Ov014eDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};


extern "C" {

extern Ov003Actor *Actor_GetTarget(Actor *self);
extern void *SndMgr_PlayAtPitch(void *a, s32 b, VecFx32 *c, s32 d);
extern s32 Ov003_CountActorsOfKind(s32 a);
extern void Vec_RotateY(VecFx32 *a, VecFx32 *b, u16 ang);
extern void Actor_PitchToPos(Ov003Actor *self, VecFx32 *v, s32 a);
extern Ov003Actor *Group_SpawnActor(void *mgr, Ov014eDesc *d, VecFx32 *pos, u16 *rot, u16 a);
extern void func_ov000_0219bebc(Ov003Actor *a, s32 b);
extern void Actor_MoveToPos(Actor *self, VecFx32 *v, s32 a);

#define OV014E_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014E_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014E_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline void Ov014e_RotX(VecFx32 *out, const VecFx32 *in, u16 ang) {
    s32 y = 0;
    s32 z = 0;
    s32 idx = ang >> 4;
    s32 s = FX_SinCosTable_[idx * 2];
    s32 c = FX_SinCosTable_[idx * 2 + 1];
    if (in->y != 0) {
        y += (s32)(((s64)c * in->y + 0x800) >> 12);
        z += (s32)(((s64)s * in->y + 0x800) >> 12);
    }
    if (in->z != 0) {
        y += (s32)(((s64)-s * in->z + 0x800) >> 12);
        z += (s32)(((s64)c * in->z + 0x800) >> 12);
    }
    out->x = in->x;
    out->y = y;
    out->z = z;
}

// Same rotation as Ov014e_RotX, written with the table reads first (codegen differs).
static inline void Ov014e_RotX2(VecFx32 *out, const VecFx32 *in, u16 ang) {
    s32 idx = ang >> 4;
    s32 c;
    s32 s;
    s = FX_SinCosTable_[idx * 2];
    c = FX_SinCosTable_[idx * 2 + 1];
    s32 y = 0;
    s32 z = 0;
    if (in->y != 0) {
        y += (s32)(((s64)c * in->y + 0x800) >> 12);
        z += (s32)(((s64)s * in->y + 0x800) >> 12);
    }
    if (in->z != 0) {
        y += (s32)(((s64)-s * in->z + 0x800) >> 12);
        z += (s32)(((s64)c * in->z + 0x800) >> 12);
    }
    out->x = in->x;
    out->y = y;
    out->z = z;
}

static inline void Ov014e_Target(Ov003Actor *self, s32 n, VecFx32 &v) {
    v.x = 0 - self->pos.x;
    v.y = 0x4719a - self->pos.y;
    v.z = 0xf000 - self->pos.z;
    v.y += 0x1000;
    Vec_RotateY(&v, &v, (u16)(Rand_PlusMinus(n) * 0xb6));
    VEC_Add(&v, &self->pos, &v);
    self->unk_84 = v;
}

static inline void Ov014e_Spawn(Ov014eDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

static inline Ov003Actor *Ov014e_SpawnAt(Ov003Actor *self, u16 kind, const VecFx32 *off) {
    Ov014eDesc d;
    Ov014e_Spawn(&d, kind);
    VecFx32 w = *off;
    Ov014e_RotX2(&w, &w, self->rot_x);
    Vec_RotateY(&w, &w, self->rot_y);
    VEC_Add(&self->pos, &w, &w);
    return Group_SpawnActor(gGroup, &d, &w, &self->rot_x, 0xffff);
}

static inline void Ov014e_Toward(Ov003Actor *self, const VecFx32 *t, s32 sp) {
    VecFx32 dd;
    dd.x = t->x - self->pos.x;
    dd.y = t->y - self->pos.y;
    dd.z = t->z - self->pos.z;
    VEC_MultAdd(sp, &dd, &self->pos, &self->pos);
}

void func_ov014_022049e8(Ov014Act_02201b94 *self) {
    VecFx32 t;
    VecFx32 pl;
    VecFx32 tv;
    {
        Ov003Actor *p = Actor_GetTarget(self);
        pl.x = p->pos.x;
        pl.y = p->pos.y;
        pl.z = p->pos.z;
    }
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 10: {
        Model0218fe1c_SetAnim(self->model, data_ov014_02216500[1], 0x400, 0);
        SndMgr_PlayAtPitch(gSndMgr, 0x35, &self->pos, 0xa);
        s32 c = 0;
        c += Ov003_CountActorsOfKind(0x580c);
        c += Ov003_CountActorsOfKind(0x580d);
        if (c != 0) {
            Ov014e_Target(self, 0x14, tv);
            self->unk_f4 |= 0x1000000;
        }
        self->unk_12f = 0;
        self->fsm->st++;
    }
    case 11:
        if (self->unk_f4 & 0x1000000) {
            Actor_TurnToPos(self, &self->unk_84, 0x11f);
            self->moveYaw = self->rot_y;
            Actor_PitchToPos(self, &self->unk_84, 0x11f);
        } else {
            Actor_TurnToPos(self, &pl, 0x11f);
            self->moveYaw = self->rot_y;
            Actor_PitchToPos(self, &pl, 0x11f);
        }
        if (Model0218fe1c_IsAnimDone(self->model)) {
            self->fsm->st++;
        }
        break;
    case 12: {
        Rot16 r = {0, 0, 0};
        r.x = self->rot_x + 0x4000;
        r.y = self->rot_y;
        VecFx32 v = data_ov014_022165a0;
        Ov014e_RotX(&v, &v, self->rot_x);
        Vec_RotateY(&v, &v, self->rot_y);
        EffectObj *e = Effect_SpawnId(0x66, &self->pos);
        e->SetRot(&r);
        e->AddPos(&v);
        e->SetScaleAll(0x40);
        Ov003FxList_Add(self->unk_fc, 0xfd, e);
        if (!(self->unk_f4 & 0x1000000)) {
            self->unk_84 = pl;
            self->unk_84.y += 0x1000;
        }
        {
            Ov003Actor *a = Ov014e_SpawnAt(self, 0x482a, &data_ov014_02216624);
            if (a != NULL) {
                a->unk_16 = (a->unk_16 & ~1) | 1;
                a->unk_84 = self->unk_84;
                func_ov000_0219bebc(a, self->unk_12c);
                if (a->targetObj != NULL) {
                    a->targetObj->target = self->id;
                }
            }
        }
        SndMgr_PlayAtPitch(gSndMgr, 0x32, &self->pos, 0xa);
        {
            VecFx32 o;
            o.x = 0;
            o.y = 0;
            o.z = -0x1800;
            Ov014e_RotX(&o, &o, self->rot_x);
            Vec_RotateY(&o, &o, self->rot_y);
            VEC_Add(&self->pos, &o, &t);
        }
        self->unk_b8 = t;
        self->unk_84 = self->pos;
        self->fsm->st++;
        break;
    }
    case 13: {
        t = self->unk_b8;
        Ov014e_Toward(self, &t, 0x4cd);
        if (VEC_Distance(&self->pos, &self->unk_b8) <= 0x4cd) {
            s32 r;
            u16 ang;
            {
                s64 sq;
                s32 dx;
                s32 dz;
                dx = self->pos.x - self->unk_84.x;
                dz = self->pos.z - self->unk_84.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                self->speed = 0;
                self->velY = 0;
                self->friction = 0;
                self->gravity = 0;
                OV014E_SQRTCNT = 1;
                OV014E_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV014E_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014E_SQRT_RESULT + 1) >> 1;
            ang = FX_Atan2(r, self->unk_84.y - self->pos.y);
            self->speed = (s32)(((s64)OV014_SIN(ang) * (s64)0x19a + 0x800) >> 12);
            self->velY = (s32)(((s64)OV014_COS(ang) * (s64)0x19a + 0x800) >> 12);
            self->unk_b8 = self->unk_84;
            self->fsm->st++;
        }
        break;
    }
    case 14:
        t = self->unk_b8;
        Actor_MoveToPos(self, &t, 0);
        if (VEC_Distance(&self->pos, &self->unk_b8) <= 0x19a) {
            s32 n = 0;
            self->pos = t;
            if (self->step != NULL) {
                n = self->step->b;
            }
            if (++self->unk_12f < n) {
                if (self->unk_f4 & 0x1000000) {
                    Ov014e_Target(self, 0x32, tv);
                }
                self->fsm->st++;
            } else {
                self->fsm->st = 16;
            }
        }
        break;
    case 15:
        if (self->unk_f4 & 0x1000000) {
            Actor_TurnToPos(self, &self->unk_84, 0x266);
            self->moveYaw = self->rot_y;
            Actor_PitchToPos(self, &self->unk_84, 0x266);
        } else {
            Actor_TurnToPos(self, &pl, 0x266);
            self->moveYaw = self->rot_y;
            Actor_PitchToPos(self, &pl, 0x266);
        }
        s = self->fsm;
        s->timer++;
        if (s->timer == 30) {
            self->fsm->timer = 0;
            self->fsm->st = 12;
        }
        break;
    case 16:
        s->timer++;
        if (s->timer == 30) {
            if (self->unk_f4 & 0x1000000) {
                self->unk_f4 ^= 0x1000000;
            }
            self->fsm->timer = 0;
            self->fsm->st = 20;
        }
        break;
    }
    {
        EffectObj *x = Effect_Find_020657b0(gEffectMgr, Ov003FxList_Get(self->unk_fc, 0xfd));
        if (x != NULL) {
            x->SetScaleAll(x->scale.x + 0x266);
        }
    }
}

}
}  // namespace m_022049e8

// ---- merged from ov014_022053f8.cpp
namespace m_022053f8 {
extern "C" {

extern void *Actor_GetTarget(Actor *self);
extern void Actor_PitchToPos(Ov003Actor *self, VecFx32 *v, s32 a);

void func_ov014_022053f8(Ov014Act_02201b94 *self) {
    Actor_GetTarget(self);
    switch (self->fsm->st) {
    case 20: {
        s32 n = 0;
        const Ov003Step *p;
        Model0218fe1c_SetAnim(self->model, data_ov014_02216500[3], 0x400, 0);
        Model0218fe1c_SetLoop(self->model);
        p = self->step;
        if (p != NULL) {
            n = p->a;
        }
        if (++self->unk_f9 < n) {
            self->fsm->st++;
        } else {
            self->fsm->st = 30;
        }
        break;
    }
    case 21: {
        VecFx32 v = {0, 0, 0};
        v.y = self->pos.y;
        Actor_PitchToPos(self, &v, 0x400);
        ActorSub40 *s = self->fsm;
        s->timer++;
        if (self->step->time == s->timer) {
            self->fsm->timer = 0;
            self->fsm->st = 2;
        }
        break;
    }
    }
}

}
}  // namespace m_022053f8
