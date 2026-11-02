#include "ov006/SlotManager.h"
#include "nitro/fx.h"
#include "Main/Save/PlayTime.h"
#include "Main/Sys/Pad.h"
#include "ov006/Racer.h"
#include "ov006/Window.h"

typedef struct ov006_GObjBits {
    u32 b0 : 13;
    u32 b13 : 1;
    u32 rest : 18;
} ov006_GObjBits;

typedef struct ov006_GObj021d6ff0 {
    union {
        u32 flags;
        ov006_GObjBits bits;
    };
    u8 unk4[8];
    int kind;
    u8 unk10[0xc];
    int time;
    int split;
} ov006_GObj021d6ff0;

typedef struct ov006_Gauge021d6ff0 {
    u8 unk0[4];
    u8 state;
    u8 unk5[7];
    u32 flags;
    u8 cur;
    u8 max;
    u8 lap;
    u8 flag13;
    void *unk14;
    void *unk18;
    ov006_GObj021d6ff0 *obj;
} ov006_Gauge021d6ff0;

typedef struct ov006_ResSub021d6ff0 {
    u8 unk0[0x82];
    u8 count;
} ov006_ResSub021d6ff0;

typedef struct ov006_ResBits {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} ov006_ResBits;

typedef struct ov006_Result021d6ff0 {
    u8 unk0[4];
    s16 state;
    u8 unk6[0xa];
    ov006_ResBits bits;
    u8 unk11;
    u8 unk12[0xa];
    void *unk1C;
    ov006_ResSub021d6ff0 *sub;
} ov006_Result021d6ff0;

typedef struct ov006_Rank021d6ff0 {
    u8 unk0[0x1c];
    u8 rank;
    u8 unk1D[7];
} ov006_Rank021d6ff0;

typedef struct ov006_Mark021d6ff0 {
    VecFx32 pos;
    u8 flag;
} ov006_Mark021d6ff0;

typedef struct ov006_Map021d6ff0 {
    u8 unk0[0x10];
    ov006_Mark021d6ff0 marks[4];
} ov006_Map021d6ff0;

typedef struct ov006_Info021d6ff0 {
    u8 unk0[8];
    u16 unk8;
    u8 unkA;
    u8 laps;
} ov006_Info021d6ff0;

struct ov006_Task021d6ff0 : public ov006_Task {
    u16 step;
    u16 subStep;
    u16 timer;
    u8 unk16[2];
    int frame;
    ov006_Gauge021d6ff0 *gauge;
    ov006_Result021d6ff0 *result;
    u8 unk24[8];
    ov006_Rank021d6ff0 *ranks;
    ov006_Map021d6ff0 *map;
    ov006_ListWin *win; // ov006_ShowListWin
    int unk38;
    int unk3C;
    int splits[10];
    int lastTime;
    u8 lap;
    u8 unk6D;
    u8 unk6E;
};


typedef struct ov006_E40021d6ff0 {
    u8 unk0[0x32];
    u16 unk32;
} ov006_E40021d6ff0;

typedef struct ov006_Speed021d6ff0 {
    s8 v;
    u8 unk1[0xb];
} ov006_Speed021d6ff0;

extern "C" {

extern void *data_ov000_021ccd68;
extern void *data_02097e4c;
extern void *data_02149ef8;
extern u8 *data_0214a424;
extern ov006_E40021d6ff0 *data_02097e40;
extern ov006_Speed021d6ff0 data_ov006_021eb85c[];

ov006_Slot *ov006_SlotManager_GetSlot_021db060(ov006_SlotManager *self, u32 idx);
void *ActorMgr_GetActor(void *a, u16 id);
typedef struct ov006_RaceInfo021d6ff0 {
    u16 unk0;
    u8 unk2;
    u8 ranks;
} ov006_RaceInfo021d6ff0;
ov006_RaceInfo021d6ff0 *ov006_Slot_GetSub2C(ov006_Slot *self);
void ov006_Unk021dd5b8_SetText(void *p, u16 v, int a, int b);
void ov006_Unk021dd2d8_Show(void *p, s8 v);
void func_0203cb78(s32 a, int b, int c);
void func_0203cc58(s32 a, int b, int c);
struct EffectObj *ov006_CreateEffect(int type, const VecFx32 *pos);
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);
void func_020498ac(void *p, s32 a);
void SndMgr_StopSeqNo(void *p, int a, int b);
void *ActorMgr_GetGroup(void *mgr, u16 id);
void ActorGroup_BroadcastKind(void *p, u16 a, int b);
void func_ov000_0216da78(ov006_GObj021d6ff0 *p);
void *MsgRes_GetString(void *a, int id);
void ov006_ShowListWin(ov006_Task021d6ff0 *self, u16 a, char *text);
ov006_Result021d6ff0 *Ov006Vt_021ec23c_Ctor(ov006_Result021d6ff0 *p);
void ov006_Unk021dfce8_Load(ov006_Result021d6ff0 *p);
void ov006_Unk021dee68_SetRect(void *p, PlayTime *t, BOOL a, BOOL b);
void ov006_Unk021df9e8_SetRect(ov006_ResSub021d6ff0 *p, PlayTime *t, u8 i, BOOL hl);
u8 ov006_CountRepeatDigits(const PlayTime *t);
BOOL func_ov006_021cd2a8(ov006_Manager *m);
BOOL ov006_Menu_AllEntriesMatch(int a, u16 b);

static inline Ov006Racer *ov006_GetRacer(u8 i) {
    u16 id = ov006_SlotManager_GetSlot_021db060(data_ov006_021ec884, i)->actorId;
    return data_ov000_021ccd68 != NULL ? (Ov006Racer *)ActorMgr_GetActor(data_ov000_021ccd68, id) : NULL;
}

static inline u8 ov006_CountRemaining(void) {
    u8 num;
    u8 i;
    u8 count;
    num = data_ov006_021ec884->numActive;
    if (num <= 1) {
        return 0x63;
    }
    count = 0;
    for (i = 0; i < num; i++) {
        u16 id = ov006_SlotManager_GetSlot_021db060(data_ov006_021ec884, i)->actorId;
        Ov006Racer *prop = data_ov000_021ccd68 != NULL ? (Ov006Racer *)ActorMgr_GetActor(data_ov000_021ccd68, id) : NULL;
        if (prop != NULL && Ov006Racer_IsFinished(prop)) {
            count++;
        }
    }
    return num - count;
}

/* Same as ov006_CountFinished; the declaration order differs from ov006_CountRemaining
 * above and decides the register allocation at each inlined call site. */
static inline u8 ov006_CountRemainingB(void) {
    u8 count;
    u8 i;
    u8 num;
    num = data_ov006_021ec884->numActive;
    if (num <= 1) {
        return 0x63;
    }
    count = 0;
    for (i = 0; i < num; i++) {
        u16 id = ov006_SlotManager_GetSlot_021db060(data_ov006_021ec884, i)->actorId;
        Ov006Racer *prop = data_ov000_021ccd68 != NULL ? (Ov006Racer *)ActorMgr_GetActor(data_ov000_021ccd68, id) : NULL;
        if (prop != NULL && Ov006Racer_IsFinished(prop)) {
            count++;
        }
    }
    return num - count;
}

static inline u8 ov006_GetRank(u8 i) {
    return (ov006_Slot_GetSub2C(ov006_SlotManager_GetSlot_021db060(data_ov006_021ec884, 0))->ranks >> (i * 2)) & 3;
}

static inline void ov006_UpdateRanks(ov006_Task021d6ff0 *self) {
    u8 i;
    if (self->ranks == NULL) {
        return;
    }
    for (i = 0; i < 4; i++) {
        if (ov006_SlotManager_GetSlot_021db060(data_ov006_021ec884, i)->active) {
            self->ranks[i].rank = ov006_GetRank(i) + 1;
        } else {
            self->ranks[i].rank = 0;
        }
    }
}

static inline void ov006_UpdateMap(ov006_Task021d6ff0 *self) {
    u8 multi;
    u8 i;
    if (self->map == NULL) {
        return;
    }
    multi = TRUE;
    if (ov006_CountRemaining() <= 1) {
        multi = FALSE;
    }
    for (i = 0; i < 4; i++) {
        Ov006Racer *r = ov006_GetRacer(i);
        if (r != NULL) {
            VecFx32 p;
            BOOL fin;
            u8 f;
            ov006_Map021d6ff0 *map;
            p = r->pos;
            fin = Ov006Racer_IsFinished(r);
            f = (multi & !fin) ? 1 : 0;
            map = self->map;
            *(VecFx32 *)&map->marks[i] = p;
            map->marks[i].flag = f;
        }
    }
}

static inline BOOL ov006_Racer_B8(Ov006Racer *me) {
    return me->swap ? TRUE : FALSE;
}

static inline void ov006_Gauge_SetCount(ov006_Gauge021d6ff0 *g, u8 cur, u8 n) {
    g->cur = cur > n ? n : cur;
    g->max = n;
}

static inline void ov006_Gauge_SetSpeed(ov006_Gauge021d6ff0 *g, u16 v, int flag) {
    if (g->unk18 != NULL) {
        ov006_Unk021dd5b8_SetText(g->unk18, v, 0x7530, flag);
    }
}

static inline void ov006_Gauge_Finish(ov006_Gauge021d6ff0 *g, BOOL on) {
    if (g->obj != NULL) {
        if (on) {
            g->obj->flags |= 0x20000;
        } else {
            g->obj->flags &= ~0x20000;
        }
        func_ov000_0216da78(g->obj);
    }
}

static inline void ov006_GObj_Split(ov006_GObj021d6ff0 *o) {
    o->flags &= ~0x10000;
    o->split = o->time;
    o->flags |= 0x120;
}

static inline int ov006_Gauge_Split(ov006_Gauge021d6ff0 *g) {
    if (g->obj == NULL) {
        return -1;
    }
    ov006_GObj_Split(g->obj);
    return g->obj->time;
}

static inline void ov006_Gauge_SetTilt(ov006_Gauge021d6ff0 *g, s8 v) {
    if (g->unk14 != NULL) {
        ov006_Unk021dd2d8_Show(g->unk14, v);
    }
}

static inline BOOL ov006_GObj_Done(ov006_GObj021d6ff0 *o) {
    return o->bits.b13 == 1 ? TRUE : FALSE;
}

static inline int ov006_Gauge_Time(ov006_Gauge021d6ff0 *g) {
    return g->obj != NULL ? g->obj->time : -1;
}

static inline void ov006_DeleteWin(ov006_Task021d6ff0 *self) {
    OV006_DELETE_OBJECT(self->win);
}

static inline BOOL ov006_Win_Busy(ov006_Task021d6ff0 *self) {
    BOOL busy;
    if (self->win == NULL) {
        busy = FALSE;
    } else {
        busy = TRUE;
        self->win->vfunc_1c();
        if (self->win->state == 5 ? busy : FALSE) {
            busy = FALSE;
            ov006_DeleteWin(self);
        }
    }
    return busy;
}

static inline BOOL ov006_Gauge_Done(ov006_Gauge021d6ff0 *g) {
    if (g->obj != NULL) {
        return ov006_GObj_Done(g->obj) ? TRUE : FALSE;
    }
    return FALSE;
}

static inline u8 ov006_GetBonus(ov006_SlotManager *m, u8 j) {
    if (j < 3) {
        return m->items[j];
    }
    return 0;
}

static inline void ov006_SetBonus(ov006_SlotManager *m, u8 j, u8 v) {
    if (j < 3) {
        m->unk14D[j] = v;
    }
}

static inline u8 ov006_Min10(u8 c) {
    return c > 10 ? 10 : c;
}

static inline u16 ov006_StageId(ov006_SlotManager *m) {
    return m->unk6 & 0xfff;
}

static inline void ov006_SetBest(u8 *save, u8 idx, int v) {
    if (idx < 5) {
        ((int *)(save + 0x624))[idx] = v;
    }
}

BOOL ov006_Race_Update(ov006_Task021d6ff0 *self) {
    BOOL result = TRUE;
    u8 lap;
    BOOL finished;
    u8 mode;
    int best;
    ov006_Info021d6ff0 *info;
    int time;
    int kind;
    Ov006Racer *me;
    ov006_Result021d6ff0 *res;
    int i;
    BOOL hl;
    PlayTime *t;
    int k;
    int n;
    int laps;
    PlayTime split[10];
    VecFx32 v;
    PlayTime total;
    PlayTime sum;
    PlayTime diff;
    u8 cnt;
    u8 j;
    {
        u16 id = ov006_SlotManager_GetSlot_021db060(data_ov006_021ec884, data_ov006_021ec884->unk5)->actorId;
        me = data_ov000_021ccd68 != NULL ? (Ov006Racer *)ActorMgr_GetActor(data_ov000_021ccd68, id) : NULL;
    }
    info = (ov006_Info021d6ff0 *)data_ov006_021ec884->info;
    switch (self->step) {
    case 0:
        self->gauge->flag13 = ov006_Racer_B8(me);
        switch (self->subStep) {
        case 0: {
            u8 i;
            ov006_Gauge_SetCount(self->gauge, me->unk_19f, info->laps);
            self->gauge->lap = data_ov006_021ec884->unk5 + 1;
            ov006_Gauge_SetSpeed(self->gauge, me->boost, 0);
            for (i = 0; i < 4; i++) {
                self->ranks[i].rank = ov006_SlotManager_GetSlot_021db060(data_ov006_021ec884, i)->active ? i + 1 : 0;
            }
            ov006_UpdateMap(self);
            self->subStep++;
            self->timer = 0;
            break;
        }
        case 1:
            if (data_ov006_021ec860->unk1C != 0 && self->unk6E != 0) {
                break;
            }
            self->timer++;
            if (self->timer < 5) {
                break;
            }
            func_0203cb78(0xa000, 0, 0);
            func_0203cb78(0xa000, 0, 1);
            self->step = 1;
            self->subStep = 0;
            self->timer = 0;
            break;
        }
        break;
    case 1:
        self->gauge->flag13 = ov006_Racer_B8(me);
        ov006_UpdateMap(self);
        switch (self->subStep) {
        case 0:
            self->timer++;
            if (self->timer >= 30) {
                v.x = 0;
                v.y = 0;
                v.z = -0x1000;
                ov006_CreateEffect(0, &v);
                func_02049a48(data_02097e4c, 0x4a, -1, -1, -1);
                self->timer = 0;
                self->subStep++;
            }
            break;
        case 1: {
            u16 t;
            self->timer++;
            t = self->timer;
            if (t < 90 && t % 30 == 0) {
                func_02049a48(data_02097e4c, 0x4a, -1, -1, -1);
            }
            if (self->timer >= 30 && self->timer >= 60 && self->timer >= 90) {
                void *o;
                if (self->gauge->obj != NULL) {
                    self->gauge->obj->flags |= 0x80;
                }
                o = ActorMgr_GetGroup(data_ov000_021ccd68, 0x7000);
                if (o != NULL) {
                    ActorGroup_BroadcastKind(o, 0xffff, 2);
                }
                func_020498ac(data_02097e4c, info->unk8);
                func_02049a48(data_02097e4c, 0x2c, -1, -1, -1);
                self->step = 2;
                self->subStep = 0;
                self->timer = 0;
            }
            break;
        }
        }
        break;
    case 2: {
        if (self->unk6E != 0) {
            void *o;
            if (self->gauge->obj != NULL) {
                self->gauge->obj->flags &= ~0x80;
            }
            o = ActorMgr_GetGroup(data_ov000_021ccd68, 0x7000);
            if (o != NULL) {
                ActorGroup_BroadcastKind(o, 0xffff, 1);
            }
            self->step = 8;
            self->subStep = 0;
            self->timer = 0;
            break;
        }
        if (data_ov006_021ec860->unk1C == 0) {
            if (self->win == NULL) {
                if (ov006_Slot_GetSub2C(ov006_SlotManager_GetSlot_021db060(data_ov006_021ec884, 0))->unk0 & 8) {
                    ov006_ShowListWin(self, 0x8d, (char *)MsgRes_GetString(data_02149ef8, 0x28));
                    break;
                }
            } else {
                if (ov006_Win_Busy(self) || self->unk38 != 1) {
                    break;
                }
                data_ov006_021ec860->unk20 = 5;
            }
            if (data_ov006_021ec860->unk20 == 5) {
                self->step = 7;
                self->subStep = 0;
                self->timer = 0;
                break;
            }
        }
        lap = me->rank + 1;
        finished = FALSE;
        if (Ov006Racer_IsFinished(me)) {
            finished = TRUE;
        } else if (data_ov006_021ec884->numActive != 1 && ov006_CountRemainingB() <= 1) {
            u8 n = data_ov006_021ec884->numActive;
            if (lap != n) {
                Ov006Racer_SetFinished(me);
                finished = TRUE;
            } else {
                data_ov006_021ec884->lap = n;
                data_ov006_021ec884->time = ov006_Gauge_Time(self->gauge);
                data_ov006_021ec884->unk13D = 2;
                ov006_Gauge_Finish(self->gauge, FALSE);
                SndMgr_StopSeqNo(data_02097e4c, info->unk8, 0);
                func_020498ac(data_02097e4c, 0x24);
                ov006_UpdateRanks(self);
                ov006_UpdateMap(self);
                self->step = 4;
                self->subStep = 0;
                self->timer = 0;
            }
        }
        if (finished) {
            v.x = 0;
            v.y = 0;
            v.z = -0x1000;
            ov006_CreateEffect(0xb, &v);
            data_ov006_021ec884->lap = lap;
            data_ov006_021ec884->time = ov006_Gauge_Time(self->gauge);
            data_ov006_021ec884->unk13D = 1;
            ov006_Gauge_Finish(self->gauge, TRUE);
            SndMgr_StopSeqNo(data_02097e4c, info->unk8, 0);
            func_020498ac(data_02097e4c, 0x26);
            self->step = 3;
            self->subStep = 0;
            self->timer = 0;
        }
        {
            u8 cur = me->unk_19f;
            int flag;
            if (info->laps != 0) {
                if (self->lap < cur && self->lap <= 10) {
                    int t = ov006_Gauge_Split(self->gauge);
                    self->splits[self->lap - 1] = t - self->lastTime;
                    self->lastTime = t;
                }
                self->lap = cur;
            }
            ov006_Gauge_SetCount(self->gauge, cur, info->laps);
            self->gauge->lap = lap;
            self->gauge->flag13 = ov006_Racer_B8(me);
            flag = 0;
            if (data_ov006_021ec884->unk13D == 0 && me->boosting) {
                flag = 1;
            }
            ov006_Gauge_SetSpeed(self->gauge, me->boost, flag);
            ov006_Gauge_SetTilt(self->gauge, data_ov006_021eb85c[me->unk_1aa].v);
            if (!(ov006_Gauge_Time(self->gauge) & 0x2f)) {
                ov006_UpdateRanks(self);
            }
            ov006_UpdateMap(self);
        }
        break;
    }
    case 3:
    case 4:
        if (!(++self->frame & 0x1f)) {
            ov006_UpdateRanks(self);
        }
        ov006_UpdateMap(self);
        switch (self->subStep) {
        case 0: {
            if (!ov006_Gauge_Done(self->gauge)) {
                break;
            }
            self->timer = 0;
            self->subStep++;
            res = (ov006_Result021d6ff0 *)Heap_Alloc(0x24);
            if (res != NULL) {
                res = Ov006Vt_021ec23c_Ctor(res);
            }
            self->result = res;
            ov006_Unk021dfce8_Load(res);
            self->result->unk11 = data_ov006_021ec884->lap;
            kind = self->gauge->obj != NULL ? self->gauge->obj->kind : 0;
            n = info->laps;
            time = data_ov006_021ec884->time;
            mode = data_ov006_021ec884->unk13D;
            if (n > 10U) {
                n = 10;
            }
            laps = self->lap - 1;
            if (laps >= 0) {
                if (laps > n) {
                    laps = n;
                }
            } else {
                laps = 0;
            }
            if (mode == 1 && kind == 2) {
                best = time;
            } else {
                best = data_ov006_021ec884->unk144;
            }
            PlayTime_FromFrames(&total, time);
            total.millis = total.millis / 10 * 10;
            func_02048bfc(&total, TRUE);
            PlayTime_Clamp(&total, 0, 99, 59, 990);
            MI_CpuFill8(split, 0, sizeof(split));
            for (i = 0; i < n; i++) {
                t = &split[i];
                PlayTime_FromFrames(t, self->splits[i]);
                split[i].millis = (split[i].millis + 5) / 10 * 10;
                func_02048bfc(t, TRUE);
                PlayTime_Clamp(t, 0, 99, 59, 990);
            }
            PlayTime_Clear(&sum);
            for (k = 0; k < n; k++) {
                PlayTime_Add(&sum, &sum, &split[k]);
            }
            func_02048e74(&diff, &sum, &total);
            diff.millis = diff.millis / 10 * 10;
            if (laps > 1) {
                func_02048e74(&split[laps - 1], &split[laps - 1], &diff);
            }
            if (self->result->unk1C != NULL) {
                ov006_Unk021dee68_SetRect(self->result->unk1C, &total, mode == 1, kind == 2);
            }
            if (self->result->sub != NULL) {
                self->result->sub->count = ov006_Min10(n);
            }
            for (i = 0; i < n; i++) {
                hl = i < laps;
                func_02048bfc(&split[i], TRUE);
                if (self->result->sub != NULL) {
                    /* Byte arithmetic keeps MWCC from reusing the &split[i] above. */
                    ov006_Unk021df9e8_SetRect(self->result->sub, (PlayTime *)((u8 *)split + i * 8), i, hl);
                }
            }
            data_ov006_021ec884->unk148 = kind;
            data_ov006_021ec884->time = time;
            data_ov006_021ec884->unk144 = best;
            cnt = ov006_CountRepeatDigits(&total);
            for (i = 0; i < info->laps; i++) {
                cnt += ov006_CountRepeatDigits(&split[i]);
            }
            me->unk_21e[6] = cnt;
            for (j = 0; j < 3; j++) {
                ov006_SlotManager *m = data_ov006_021ec884;
                u8 v = ov006_GetBonus(m, j);
                if (v >= 1 && v <= 7) {
                    ov006_SetBonus(m, j, me->unk_21e[v]);
                }
            }
            if (!func_ov006_021cd2a8(data_ov006_021ec860)) {
                ov006_SetBest(data_0214a424, ov006_StageId(data_ov006_021ec884), best);
            }
            self->gauge->flags |= 2;
            break;
        }
        case 1:
            if (self->gauge->state == 6 && self->result->state == 6) {
                self->result->bits.b0 = 1;
            }
            if (self->result->state != 3) {
                break;
            }
            if (data_ov006_021ec860->unk1C != 0) {
                self->timer = 0;
                self->subStep++;
                break;
            }
            if (func_ov006_021cd2a8(data_ov006_021ec860)) {
                self->timer++;
                if (self->timer > 150 || (data_02097dc8->trig & 3)) {
                    self->result->bits.b1 = 1;
                    self->step = 7;
                    self->subStep = 0;
                    self->timer = 0;
                }
            } else if (data_02097dc8->trig & 3) {
                self->result->bits.b1 = 1;
                self->step = 7;
                self->subStep = 0;
                self->timer = 0;
            }
            break;
        case 2:
            if (self->unk6E != 0) {
                break;
            }
            if (ov006_SlotManager_GetSlot_021db060(data_ov006_021ec884, data_ov006_021ec884->unk5)->aid == 0) {
                if (ov006_Menu_AllEntriesMatch(9, data_02097e40->unk32 & ~1) && (data_02097dc8->trig & 3)) {
                    self->unk6D = 9;
                    self->subStep++;
                    self->timer = 0;
                }
            } else {
                self->unk6D = 9;
                self->subStep++;
                self->timer = 0;
            }
            break;
        case 3:
            if (self->unk6E != 0) {
                break;
            }
            if (!ov006_Menu_AllEntriesMatch(9, data_02097e40->unk32)) {
                break;
            }
            self->result->bits.b1 = 1;
            self->step = 7;
            self->subStep = 0;
            self->timer = 0;
            break;
        }
        break;
    case 8:
        break;
    case 7:
        if (self->unk6E != 0) {
            break;
        }
        switch (self->subStep) {
        case 0:
            if (self->result != NULL) {
                self->result->bits.b1 = 1;
            }
            self->timer = 0;
            self->subStep++;
            break;
        case 1:
            if (self->result != NULL && self->result->state != 6) {
                break;
            }
            func_0203cc58(0xf000, 0, 0);
            func_0203cc58(0xf000, 0, 1);
            self->timer = 0;
            self->subStep++;
            break;
        case 2:
            if (self->timer++ > 15) {
                if (data_ov006_021ec860->unk20 == 5) {
                    self->unk3C = 2;
                    result = FALSE;
                } else {
                    self->unk3C = 3;
                    result = FALSE;
                }
            }
            break;
        }
        break;
    }
    return result;
}

}
