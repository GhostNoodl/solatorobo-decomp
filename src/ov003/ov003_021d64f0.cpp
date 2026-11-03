#include "types.h"
#include "ov003/Actor.h"
#include "Main/Sys/FieldState.h"

extern "C" {

typedef struct {
    u8 pad_00[0xb24];
    u32 unk_b24_0 : 1;
    u32 unk_b24_1 : 1;
} Ov003EvPlayer;

extern void Shared_SetEventActor(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern BOOL History_SetState(ActorSub40 *p, u8 a, BOOL b);

void Ov003Actor_State20(Ov003Actor *self) {
    if (self->unk_b0->unk_0a_5) {
        Shared_SetEventActor(self->kind, self->id);
        func_020627dc(4);
        gSceneCmd->stageFlags = 1;
    }
    History_SetState(self->fsm, 1, 0);
}

extern const u8 data_ov003_021f43dc[];
extern const u8 data_ov003_021f43e1[];
extern const u8 data_ov003_021f43e6[];
extern const u8 data_ov003_021f43eb[];
extern const u8 data_ov003_021f4428[];
extern const u8 data_ov003_021f442d[];
extern const u8 data_ov003_021f4432[];
extern const u8 data_ov003_021f4437[];
extern const u8 data_ov003_021f443c[];
extern const u8 data_ov003_021f4441[];
extern void Ov003_AddMeter_021cedf4(u16 n);
extern Ov003EvPlayer *ActorMgr_FindPlayer(void);

static inline BOOL Ov003EvPlayer_Flag(Ov003EvPlayer *pl) {
    return pl->unk_b24_1 ? TRUE : FALSE;
}

u8 Ov003Actor_ApplyHit(Ov003Actor *self, ActorMsgHit *hit) {
    ActorHp *hp;
    u16 old;
    u8 res;
    u8 kind;
    u8 kind2;
    u16 dmg;
    s32 cur;
    kind = hit->kind;
    dmg = hit->dmg;
    hp = self->hpObj;
    old = hp->cur;
    res = 0;
    kind2 = kind;

    if (dmg >= old) {
        hp->cur = 0;
    } else {
        hp->cur = old - dmg;
    }
    cur = hp->cur;
    if (cur <= 0) {
        if (self->unk_b0->unk_0a_0 == 0 || ((s32)old <= 0 && (kind == 0x40 || kind == 0x41))) {
            res = 0x15;
        } else {
            res = 0x14;
        }
    } else {
        if (kind == 0x41) {
            res = 0x14;
            kind2 = 0x41;
        } else if (self->unk_e8 != 0) {
            res = 0x14;
        } else if (kind != 1) {
            u16 step = self->unk_dc;
            s32 th = step;
            s32 i;
            for (i = 1; i < self->unk_b0->unk_0a_0; i++, th += step) {
                {
                    if (old <= th) {
                        break;
                    }
                    if (cur <= th) {
                        res = 0x13;
                        kind2 = 0x21;
                        self->unk_ea_0 = 4;
                        break;
                    }
                }
            }
        }
        if (dmg != 0) {
            Ov003_AddMeter_021cedf4(8);
        }
    }
    if (res == 0 && kind2 != 2 && kind2 != 1) {
        switch (kind) {
        case 0x10:
            kind2 = data_ov003_021f4428[self->unk_ea_0];
            res = data_ov003_021f43dc[self->unk_ea_0];
            break;
        case 0x11:
            kind2 = data_ov003_021f442d[self->unk_ea_0];
            res = data_ov003_021f43e1[self->unk_ea_0];
            break;
        case 0x20:
            kind2 = data_ov003_021f4432[self->unk_ea_0];
            res = data_ov003_021f43e6[self->unk_ea_0];
            break;
        case 0x21:
        case 0x40:
        case 0x42:
            kind2 = data_ov003_021f4437[self->unk_ea_0];
            res = data_ov003_021f43e6[self->unk_ea_0];
            break;
        case 0x30:
            kind2 = data_ov003_021f443c[self->unk_ea_0];
            res = data_ov003_021f43eb[self->unk_ea_0];
            break;
        case 0x31:
            kind2 = data_ov003_021f4441[self->unk_ea_0];
            res = data_ov003_021f43eb[self->unk_ea_0];
            break;
        case 0x41:
            kind2 = 0x41;
            res = 0x14;
            break;
        }
        if (self->hit != NULL && !(self->hit->unk_50 & 0x20000000)) {
            switch (self->unk_ea_0) {
            case 0:
            case 1:
                if (res != 0x13 && res != 0x14) {
                    res = 0x13;
                    kind2 = 0x20;
                }
                break;
            default:
                if (res != 0) {
                    res = 0;
                    kind2 = 2;
                }
                break;
            }
        }
    }
    if (res == 0x12 && kind2 == 2) {
        u8 f = self->unk_ec_0;
        u8 k = self->fsm->current;
        if (!f && k != 1 && k != 2) {
            res = 0;
        }
    }
    self->unk_ea_11 = 0;
    if (dmg == 0 && (res == 0x12 || res == 0x13)) {
        Ov003EvPlayer *pl = ActorMgr_FindPlayer();
        if (pl != NULL && Ov003EvPlayer_Flag(pl) == FALSE) {
            self->unk_ea_11 = 1;
        }
    }
    hp = self->hpObj;
    hp->dmg = dmg;
    hp->kind = kind;
    hp->kind2 = kind2;
    return res;
}

}
