#include "ov014/ov014.h"

extern "C" {

extern s32 Ov003Actor_HandleMsg(Ov003Actor *self, Ov014Msg *msg);

s32 Ov014Act_0221267c_HandleMsg(Ov014Act_0221267c *self, Ov014Msg *msg) {
    s32 r = 0;
    if (msg->type == 6) {
        self->unk_310 |= msg->idx;
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
    } else {
        r = Ov003Actor_HandleMsg(self, msg);
    }
    return r;
}


extern Ov003Actor *ActorMgr_FindPlayer(void);
extern Ov003Actor *Actor_GetTarget(Actor *self);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);

static inline Ov003Actor *Ov014_FindById(u16 id) {
    return gActorMgr != NULL ? ActorMgr_GetActor(gActorMgr, id) : NULL;
}

static inline BOOL Ov014_WaitB6(Ov003Actor *self) {
    BOOL r = FALSE;
    if (self->fsm->st == 0xffff || self->unk_b6 == 0) {
        r = TRUE;
    } else if (self->unk_b6 != 0xffff && self->unk_b6 != 0) {
        self->unk_b6--;
    }
    return r;
}

void Ov014Act_0221267c_Update(Ov014Act_0221267c *self) {
    Ov003Actor *pl;
    if (!Ov014_GameIdle()) {
        return;
    }
    self->target = 0xffff;
    pl = ActorMgr_FindPlayer();
    if (pl != NULL) {
        self->target = pl->id;
    }
    if (Actor_GetTarget(self) == NULL) {
        return;
    }
    if (*self->hp == 0 || (self->fsm->flags & 0x200000)) {
        if (self->unk_b4 != 0x1e) {
            *self->hp = 0;
            self->fsm->flags |= 0x200000;
            self->fsm->st = 0;
            self->unk_b4 = 0x1e;
            self->unk_b6 = 0xffff;
        }
    }
    if (self->msg_flags != 0) {
        if ((self->msg_flags & 0x200) && *self->hp != 0) {
            Ov003Actor *a;
            self->fsm->flags = 0;
            self->fsm->flags |= 0x40000;
            self->fsm->st = 0;
            a = Ov014_FindById(self->target_id);
            if (a != NULL) {
                a->unk_1a = 1;
            }
            self->unk_b4 = 10;
            self->unk_b6 = 0xffff;
            return;
        }
        if (self->msg_flags & 0x40) {
            if (self->unk_b4 != 0x1e) {
                u16 m = self->unk_310;
                if (m & 1) {
                    self->fsm->st = 0xffff;
                    self->unk_b4 = 10;
                    self->unk_b6 = 0xffff;
                }
                if (m & 2) {
                    Ov003Actor *a;
                    self->fsm->st = 0xffff;
                    a = Ov014_FindById(self->target_id);
                    if (a != NULL) {
                        a->unk_1a = 1;
                    }
                    self->unk_b4 = 0x14;
                    self->unk_b6 = 0xffff;
                }
                if (m & 4) {
                    self->unk_348 = 0;
                } else if (m & 8) {
                    self->unk_348 = 1;
                } else if (m & 0x10) {
                    self->unk_348 = 2;
                }
                if (m & 0x20) {
                    self->unk_354 = 0;
                } else if (m & 0x40) {
                    self->unk_354 = 1;
                }
            }
            self->unk_310 = 0;
        }
    }
    switch (self->unk_b4) {
    case 0:
        self->fsm->flags |= 0x100000000ULL;
        self->fsm->st = 0;
        self->unk_b6 = 0xffff;
        self->unk_b4++;
        break;
    case 1:
        if (!Ov014_WaitB6(self)) {
            break;
        }
        self->fsm->flags |= 2;
        self->fsm->st = 0;
        self->unk_b4 = 10;
        self->unk_b6 = 0xffff;
        break;
    case 10:
        if (!Ov014_WaitB6(self)) {
            break;
        }
        History_SetState(self->fsm, 1, 0);
        self->fsm->st = 0;
        self->unk_b6 = 0xffff;
        break;
    case 0x14:
        switch (self->unk_348) {
        case 0:
            History_SetState(self->fsm, 0xf, 0);
            break;
        case 1:
            History_SetState(self->fsm, 0x10, 0);
            break;
        case 2:
            History_SetState(self->fsm, 0x11, 0);
            break;
        default:
            self->fsm->flags |= 0x8000;
            break;
        }
        self->fsm->st = 0;
        self->unk_b4++;
        break;
    case 0x15:
        if (!Ov014_WaitB6(self)) {
            break;
        }
        self->fsm->flags |= 2;
        self->fsm->st = 0;
        self->unk_b4 = 10;
        self->unk_b6 = 0xffff;
        break;
    case 0x1e: {
        ActorSub44 *q = self->unk_44;
        q->unk_22_0 = 0;
        q->unk_22_1 = 0;
        break;
    }
    }
}

}
