#include "types.h"
#include "Main/Lang/TblRes.h"
#include "Main/Effect/Effect.h"
#include "nitro/fx.h"
#include "ov003/Actor.h"
#include "Main/Sys/FieldState.h"

typedef struct {
    u8 unk_00[0x50];
    VecFx32 pos;
    s32 unk_5c;
} Ov003EnSub5c;

typedef struct {
    u8 unk_00[0xc];
    u16 unk_0c;
    u8 unk_0e[0x90 - 0xe];
    u16 unk_90;
    u8 unk_92[0xb90 - 0x92];
    VecFx32 unk_b90;
    s32 unk_b9c;
} Ov003EnPl;

typedef struct {
    u8 unk_00[0x5c];
    void *unk_5c;
    void *unk_60;
} Ov003Mgr11c;

typedef struct {
    u8 unk_00[0x11c];
    Ov003Mgr11c *unk_11c;
} Ov003Game30;

typedef void (Ov003Actor::*Ov003EnPmf)();

typedef struct {
    u32 kind;
    Ov003EnPmf fn;
} Ov003EnEntry;

extern "C" {

extern const Ov003EnEntry data_ov003_021f4750[];
extern Ov003Game30 *data_ov000_021ccd30;
extern void func_ov000_0219a088(void *p);
extern void func_ov000_0219af3c(Ov003Actor *self, void *icon);
extern void Geom_AddRotatedOffset(VecFx32 *v, const VecFx32 *a, s32 rot);
extern void ActorMarker_Update(void *p);
extern void func_ov000_021697dc(void *p, u16 a, u16 b);
extern void func_ov000_0216912c(void *p, u16 id, s32 a, u16 b, u16 c, const VecFx32 *pos);
extern Ov003EnPl *ActorMgr_FindPlayer(void);

static inline BOOL Ov003Game_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov003Game_IsIdle(FieldState *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdleP(FieldState *g) {
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}

static inline void Ov003_Call5c(u16 a, u16 b) {
    Ov003Mgr11c *m = data_ov000_021ccd30->unk_11c;
    if (m != NULL && m->unk_5c != NULL) {
        func_ov000_021697dc(m->unk_5c, a, b);
    }
}

static inline void Ov003_Call60(u16 id, u16 a, u16 b, const VecFx32 *pos) {
    Ov003Mgr11c *m = data_ov000_021ccd30->unk_11c;
    if (m != NULL && m->unk_60 != NULL) {
        func_ov000_0216912c(m->unk_60, id, 0, a, b, pos);
    }
}

static inline void Dispatch(Ov003Actor *self, u32 kind) {
    s32 i;
    for (i = 0; i < 0x15; i++) {
        if (data_ov003_021f4750[i].kind != kind) {
            continue;
        }
        (self->*data_ov003_021f4750[i].fn)();
        return;
    }
}

void Ov003Actor_RunState(Ov003Actor *self) {
    u16 *p50;
    u8 kind;
    s32 i;
    self->unk_ec = 0;
    switch (self->unk_b0->unk_0c_0) {
    case 1:
        self->unk_94_1 = 1;
        break;
    case 2:
        if (self->fsm->current != 0x14) {
            self->unk_94_1 = 2;
        }
        break;
    case 5:
        self->unk_94_1 = 3;
        break;
    }
    Dispatch(self, self->fsm->current);
    if (self->unk_e8 != 0 && *self->hp != 0 && self->fsm->current != 0x14) {
        self->unk_e8 = 0;
        self->targetObj->type = func_02070558(self->kind)->target.type;
    }
    if (self->unk_e8 != 0) {
        self->unk_94_0 = 1;
    }
    p50 = self->hp;
    if (p50 != NULL && p50[5] != 0) {
        p50[5]--;
    }
    func_ov000_0219a088(self->unk_54);
    if (self->unk_ea_13) {
        if (self->unk_5c != NULL && Ov003_GameIdleP(data_ov000_021ccd54)) {
            VecFx32 pos;
            s32 r;
            func_ov000_0219af3c(self, self->unk_5c);
            if (self->unk_44 != NULL) {
                pos = self->unk_44->pos;
                if (self->unk_44->unk_22_4) {
                    VecFx32 v;
                    v.z = self->unk_44->unk_1c;
                    v.x = 0;
                    v.y = 0;
                    Geom_AddRotatedOffset(&pos, &v, self->rot_y);
                }
                r = self->unk_44->unk_0c.y;
                if (r == 0) {
                    r = self->unk_44->unk_1c;
                }
            } else {
                pos = self->pos;
                r = self->height;
                if (r == 0) {
                    r = self->radius;
                }
            }
            if (self->fsm->current == 0x13 || self->fsm->current == 0x14 || self->unk_94_0) {
                r >>= 2;
            }
            ((Ov003EnSub5c *)self->unk_5c)->pos = pos;
            ((Ov003EnSub5c *)self->unk_5c)->unk_5c = r;
            ActorMarker_Update(self->unk_5c);
        }
        if (self->unk_ea_6 != 1) {
            if (self->unk_b0->unk_0a_5) {
                Ov003_Call5c(self->hp[0], self->hp[1]);
            } else {
                BOOL b = FALSE;
                if (self->unk_ea_6 == 2) {
                    b = TRUE;
                } else if (self->fsm->current != 9) {
                    Ov003EnPl *pl;
                    if (self->targetObj != NULL && (self->msg_flags & 0x200)) {
                        b = TRUE;
                    }
                    pl = ActorMgr_FindPlayer();
                    if (pl != NULL && (pl->unk_90 == self->id || self->targetObj->target == pl->unk_0c)) {
                        b = TRUE;
                    }
                }
                if (b) {
                    Ov003_Call60(self->id, self->hp[0], self->hp[1], &self->pos);
                }
            }
        }
    }
    if (self->unk_e4 != NULL) {
        EffectObj *fx = Effect_Find_020657b0(data_0214a420, self->unk_e4);
        if (fx != NULL) {
            if (self->unk_e8 == 0 || (self->fsm->current != 0x14 && self->fsm->current != 0xb && self->fsm->current != 4)) {
                fx->state = 4;
                self->unk_e4 = NULL;
            } else {
                s32 s;
                fx->SetPos(&self->pos);
                s = self->height;
                switch (fx->unk_20) {
                default:
                    s -= (s >> 1) + (s >> 3);
                    break;
                case 0x385:
                case 0x387:
                    s >>= 3;
                    break;
                case 0x386:
                case 0x388:
                    break;
                }
                fx->AddPosXYZ(0, s, 0);
            }
        } else {
            self->unk_e4 = NULL;
        }
    }
    if (self->unk_e0 != NULL) {
        EffectObj *fx = Effect_Find_020657b0(data_0214a420, self->unk_e0);
        if (fx == NULL) {
            self->unk_e0 = NULL;
        } else {
            fx->SetPos(&self->pos);
            fx->AddPosXYZ(0, self->centerY, 0);
        }
    }
    if (self->unk_b0->unk_0a_6) {
        Ov003EnPl *pl = ActorMgr_FindPlayer();
        if (pl != NULL) {
            pl->unk_b90 = self->pos;
            pl->unk_b9c = 0x4b8;
        }
    }
    {
        ActorSub40 *w = self->fsm;
        w->flags = 0;
    }
}

}
