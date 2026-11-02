#include "types.h"
#include "ov003/Actor.h"

typedef struct {
    s32 x, y, z;
} Ov003HtVec;

typedef struct {
    u8 unk_00[0xc];
    u16 id;
    u8 unk_0e[0x3a];
    ActorSub48 *ctl;
    s32 *unk_4c;
    s32 *unk_50;
} Ov003HtActor;

typedef struct {
    u8 unk_00[0x10];
    s32 unk_10;
    s32 unk_14;
} Ov003HtSlot;

class Ov003HtFx {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c(s32 a);
    virtual void v10();
    virtual void SetScale(s32 x, s32 y, s32 z);
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void SetRot(s32 x, u16 y, s32 z);
    u8 unk_04[0x38];
    s32 unk_3c;
};

typedef struct {
    u16 val;
    u8 kind;
    u16 id;
} Ov003HtMsg;

extern "C" {

extern void *data_02097e4c;
extern const char data_ov003_021f7a85[];
extern const char data_ov003_021f7a8b[];
void HitSphere_Link(ActorSub48 *ctl);
void func_0203f364(ActorSub48 *ctl);
void *func_02049f44(void *mgr, s32 id, void *pos, s32 a);
Ov003HtFx *func_02065f88(s32 id, void *pos);
void func_ov000_0218996c(u8 a, u8 b);
void Actor_SendMsg(Ov003Actor *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);
void Actor_Move(Ov003Actor *self, s32 a);
BOOL func_ov000_02190cb0(void *model, const char *name, s16 blend, u8 force);
BOOL func_ov000_02191120(void *model);
void func_ov000_021915a0(void *model);
BOOL func_ov000_02198360(ActorSub40 *w, s32 a, s32 b);
void func_ov000_021987b8(ActorSub48 *ctl, s32 a, s32 b, s32 c);
u16 func_ov000_02198da8(ActorSub48 *ctl, u16 angle);
Ov003HtActor *Target_Get(ActorSub4c *t);
u16 func_ov000_02199e94(ActorSub4c *t);
u8 func_ov000_02199f08(ActorSub4c *t);
void func_ov000_02199f48(ActorHp *t, Ov003HtActor *a);
s32 Filter_Apply(ActorHp *a, Ov003HtSlot *b, s32 value);
BOOL func_ov000_0219aae8(Ov003Actor *a, Ov003HtActor *b, u16 c, u8 d, u16 mask, Ov003HtVec *ofs, void *rot, s32 r, s32 rr, s16 h, s32 i);
u8 func_ov003_021cee68(void);

void func_ov003_021d3d28(Ov003Actor *self) {
    BOOL hit;
    u16 c;
    s32 h;
    Ov003HtActor *tgt;
    Ov003HtSlot *slot;
    switch (self->fsm->st) {
    case 0: {
        ActorSub48 *ctl = self->hit;
        ActorSub44 *s;
        ctl->unk_9a_0 = 1;
        ctl->unk_9a_3 = 1;
        HitSphere_Link(ctl);
        s = self->unk_44;
        if (s != NULL) {
            s->unk_22_0 = 1;
            s->unk_22_1 = 1;
        }
        self->fsm->st++;
        if (self->gravity == 0) {
            self->gravity = 0x52;
        }
    }
    case 1: {
        if (self->velY > 0 && (self->hit->unk_50 & 0x80000000)) {
            self->velY = -0xcd;
        }
        if (self->targetObj == NULL) {
            break;
        }
        tgt = Target_Get(self->targetObj);
        if (tgt != NULL && self->targetObj->unk_01 == 1) {
            ActorSub48 *ctl = self->hit;
            if ((ctl->unk_50 & 0x60000000) || ctl->unk_58 != 0) {
                slot = (Ov003HtSlot *)tgt->unk_50;
                hit = FALSE;
                c = func_ov000_02199e94(self->targetObj);
                switch (self->unk_b0->unk_0c_0) {
                case 3:
                    if (self->targetObj->unk_19 < 2) {
                        ActorSub4c *t;
                        c = 0;
                        func_02049f44(data_02097e4c, 0x66, &self->pos, 0);
                        t = self->targetObj;
                        t->unk_19 = 0;
                        t->unk_1b = 0;
                    }
                    break;
                case 4:
                    u8 n = func_ov003_021cee68();
                    if (self->targetObj->unk_1a < n) {
                        c = 0;
                    }
                    break;
                }
                h = 100;
                if (self->hit->unk_50 & 0x20000000) {
                    Ov003HtFx *fx = func_02065f88(0x67, &self->pos);
                    s32 r;
                    fx->SetRot(0, self->rot_y + 0x8000, 0);
                    r = self->radius;
                    if (self->targetObj->unk_19 != 0) {
                        s32 t = r + ((r >> 1) + 0x333);
                        fx->SetScale(t, t * 2, t);
                        fx->unk_3c = 0xc00;
                        fx = func_02065f88(0x57b, &self->pos);
                        fx->SetScale(0x159a, 0x159a, 0x159a);
                    } else {
                        fx->SetScale(r + ((r >> 2) + 0x333), r + ((r >> 2) + 0x333), r + ((r >> 2) + 0x333));
                        fx->unk_3c = 0x2000;
                    }
                } else {
                    h = -1;
                    if (self->targetObj->unk_19 != 0) {
                        Ov003HtFx *fx = func_02065f88(0x65, &self->pos);
                        fx->SetRot(0x1800, self->rot_y + 0x8000, 0);
                    } else {
                        Ov003HtFx *fx = func_02065f88(0x64, &self->pos);
                        fx->SetScale(0xccd, 0xccd, 0xccd);
                    }
                }
                if (self->targetObj->unk_19 != 0) {
                    s32 n = self->targetObj->unk_1a + 1;
                    func_ov000_0218996c(n + 8, n * 2 + 0x14);
                    func_02049f44(data_02097e4c, 0x1a, &self->pos, 0);
                } else {
                    func_ov000_0218996c(6, 10);
                    func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
                }
                if (self->targetObj->unk_03 == 1) {
                    Ov003HtVec ofs;
                    s32 r = self->radius;
                    u8 d;
                    if (r < 0xccd) {
                        r = 0xccd;
                    }
                    r += 0xccd;
                    ofs.y = self->centerY;
                    ofs.x = 0;
                    ofs.z = 0;
                    d = self->targetObj->unk_0a;
                    if (slot != NULL) {
                        s32 tmp = slot->unk_10;
                        slot->unk_10 = slot->unk_14;
                        slot->unk_14 = tmp;
                    }
                    hit = func_ov000_0219aae8(self, tgt, c, d, 0x30, &ofs, NULL, r, 0, h, 0x1000);
                    if (slot != NULL) {
                        s32 tmp = slot->unk_10;
                        slot->unk_10 = slot->unk_14;
                        slot->unk_14 = tmp;
                    }
                }
                if (self->hpObj->cur != 0) {
                    u32 kind = func_ov000_02199f08(self->targetObj);
                    Ov003HtMsg msg;
                    msg.val = Filter_Apply(self->hpObj, slot, c);
                    msg.kind = kind;
                    msg.id = 0xffff;
                    if (hit && kind == 0x41) {
                        tgt = (Ov003HtActor *)self;
                    }
                    Actor_SendMsg(self, tgt->id, 9, 0, sizeof(msg), &msg);
                } else {
                    ActorSub44 *s;
                    func_ov000_02199f48(self->hpObj, tgt);
                    func_ov000_02198360(self->fsm, 0x15, 0);
                    ctl = self->hit;
                    ctl->unk_9a_0 = 0;
                    ctl->unk_9a_3 = 0;
                    func_0203f364(ctl);
                    s = self->unk_44;
                    s->unk_22_0 = 0;
                    s->unk_22_1 = 0;
                }
                self->targetObj->target = 0xffff;
            }
        } else {
            ActorSub48 *ctl = self->hit;
            if ((ctl->unk_50 & 0x40000000) || ctl->unk_58 != 0) {
                self->moveYaw = func_ov000_02198da8(ctl, self->moveYaw);
                self->speed >>= 2;
                if (self->speed < 0x8f) {
                    self->speed = 0x8f;
                }
                ctl = self->hit;
                if (ctl->unk_84 > 0x100 || ctl->unk_58 != 0) {
                    if (self->velY < -0xcd) {
                        self->velY = -0xcd;
                    }
                }
                self->fsm->timer = 0;
            }
            if (self->hit->unk_50 & 0x20000000) {
                func_ov000_02190cb0(self->model, data_ov003_021f7a85, 0x800, 0);
                if (self->velY < -0x266) {
                    s32 se = 8;
                    if (self->hit->unk_50 & 0x400) {
                        se = 0x3d;
                    } else if (self->radius >= 0x1000 && self->velY < -0x400) {
                        Ov003HtFx *fx;
                        se = 0x17;
                        func_ov000_0218996c(10, 0x14);
                        fx = func_02065f88(0x12e, &self->pos);
                        fx->v0c(0x1400);
                    }
                    func_02049f44(data_02097e4c, se, &self->pos, 0);
                }
                self->fsm->st++;
                self->fsm->timer = 0;
                self->velY = 0;
                self->gravity = 0;
                self->friction = 0x800;
            } else {
                func_ov000_02190cb0(self->model, data_ov003_021f7a8b, 0x400, 0);
                func_ov000_021915a0(self->model);
            }
        }
        if (!(self->hit->unk_50 & 0x20000000)) {
            ActorSub40 *w = self->fsm;
            w->timer++;
            if (w->timer > 0x46) {
                self->fsm->timer = 0x46;
                if (!(self->hit->unk_54 & 0x20000000)) {
                    func_ov000_02198360(self->fsm, 0x15, 0);
                }
            }
        }
        break;
    }
    case 2: {
        ActorSub40 *w;
        self->hit->unk_9a_5 = 1;
        w = self->fsm;
        w->timer++;
        if (w->timer >= 5) {
            self->fsm->timer = 5;
            if (func_ov000_02191120(self->model) || self->fsm->flags != 0) {
                self->targetObj->target = 0xffff;
                self->speed = 0;
                self->velY = 0;
                self->friction = 0;
                self->gravity = 0;
                func_ov000_02198360(self->fsm, 1, 0);
            }
        }
        break;
    }
    }
    {
        ActorSub48 *other = NULL;
        BOOL restore;
        ActorSub4c *t;
        Actor_Move(self, 0);
        if (self->hit == NULL) {
            return;
        }
        t = self->targetObj;
        restore = FALSE;
        if (t != NULL && t->target != 0xffff && t->unk_01 == 1) {
            s32 r = self->radius + 0x4cd;
            Ov003HtActor *a;
            if (r < 0xccd) {
                r = 0xccd;
            }
            self->hit->unk_44 = r;
            a = Target_Get(self->targetObj);
            if (a != NULL && (other = a->ctl) != NULL && other->unk_9a_3) {
                other->unk_9a_3 = 0;
                func_0203f364(other);
                restore = TRUE;
            }
        }
        func_ov000_021987b8(self->hit, 1, 0, 0);
        if (restore) {
            other->unk_9a_3 = 1;
            HitSphere_Link(other);
        }
    }
}

}
