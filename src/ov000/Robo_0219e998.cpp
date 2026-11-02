#include "ov000/Actor.h"
#include "ov000/ObjLayouts.h"
#include "ov000/LoCommon.h"
#include "Main/Effect/Effect.h"
#include "ov000/ActorMarker.h"

extern "C" {

BOOL Actor_HandleMsg(Actor *self, ActorMsg *msg);

static inline void MinB32_0219e998(Robo021ca458 *self, u16 n) {
    if (self->unk_b32 < n) {
        self->unk_b32 = n;
    }
}

// g is a local; as a trailing parameter it gets the target's registers.
BOOL Robo021ca458_HandleMsg(Actor *self, ActorMsg *msg, FieldState *g) {
    Robo021ca458 *s = (Robo021ca458 *)self;
    BOOL callBase;
    BOOL ok;
    if (!self->vfunc_14()) {
        u8 t = msg->type;
        if (t == 9 || t == 0xb || (u8)(t + 0xf9) <= 1) {
            self->msg_flags |= 1 << t;
            msg->type = 0;
            return TRUE;
        }
        return FALSE;
    }
    ok = TRUE;
    callBase = ok;
    switch (msg->type) {
    case 9:
        callBase = FALSE;
        if (!s->unk_b29_0 && s->hpObj->unk_0a == 0) {
            g = data_ov000_021ccd54;
            if (g != NULL) {
                ok = g->head != g->tail ? TRUE : FALSE;
                if (ok) {
                    ok = FALSE;
                } else {
                    if (g->state != 3) ok = FALSE; else ok = TRUE;
                }
            }
        if (ok) {
            u16 dmg;
            u16 hp;
            s32 bit;
            u8 kind;
            ActorHp *p50 = (ActorHp *)s->hp;
            p50->unk_04 = msg->id;
            dmg = *(u16 *)msg->data;
            if (s->fsm->current == 0x16 && !(s->hit->unk_50 & 0x20000000)) {
                dmg += dmg / 2;
            }
            if (s->unk_93_5 != 0 && dmg > 1) {
                dmg = dmg / 2;
            }
            p50 = (ActorHp *)s->hp;
            if (dmg >= p50->cur) {
                p50->cur = 0;
            } else {
                p50->cur -= dmg;
            }
            bit = 0;
            hp = p50->cur;
            kind = msg->data[2];
            MinB32_0219e998(s, 0x5a);
            if (hp != 0) {
                u32 mode = s->unk_b24_12;
                if ((mode == 0 || mode == 3) && !s->unk_b2c_0 && !s->unk_b2c_1 &&
                    !s->unk_b2c_2 && (!s->unk_b22_3 || kind == 0x50)) {
                    switch (kind) {
                    case 0x10:
                    case 0x11:
                        bit = 0x12;
                        if (!(s->hit->unk_50 & 0x20000000) || mode == 3) {
                            MinB32_0219e998(s, 0x96);
                            bit = 0x13;
                            kind = 0x20;
                        }
                        break;
                    case 0x20:
                    case 0x21:
                    case 0x30:
                    case 0x31:
                    case 0x50:
                        bit = 0x13;
                        MinB32_0219e998(s, 0x96);
                        break;
                    }
                }
            } else if (s->unk_b24_12 - 1 <= 1) {
                s->hpObj->cur = 1;
            } else {
                s->unk_b24_0 = 1;
                s->unk_93_5 = 0;
                MinB32_0219e998(s, 0x96);
                s->target = 0xffff;
                s->unk_5c->show = 0;
                bit = 0x13;
                kind = 0x20;
                func_ov000_021bd300(s->unk_5c);
                s->unk_9b0->show = 0;
                func_ov000_021bd300(s->unk_9b0);
            }
            p50 = (ActorHp *)s->hp;
            p50->dmg = dmg;
            p50->kind = kind;
            p50->kind2 = kind;
            if (bit != 0) {
                ((ActorSub40 *)self->fsm)->flags |= (u64)1 << bit;
            }
            if (msg->data[2] != 1) {
                s->hpObj->unk_0a = 0x5a;
            } else {
                s->hpObj->unk_0a = 10;
            }
            {
                Model0218fe1c *m = s->model;
                m->color = 0x14bf;
                m->color2 = 0x739f;
                m->blend = 0xb;
                m->blendMax = 0xa;
            }
            s->unk_b2a |= 2;
            if ((msg->id >> 12) == 4) {
                s->unk_b2a |= 0x10;
            }
        }
        }
        break;
    case 10: {
        ActorHp *p;
        EffectObj *e;
        callBase = FALSE;
        s->hpObj->unk_04 = msg->id;
        p = s->hpObj;
        p->cur += *(u16 *)msg->data;
        if (p->cur > p->max) {
            p->cur = p->max;
        }
        {
            Model0218fe1c *m = s->model;
            m->color = 0x73ea;
            m->color2 = 0x7ffc;
            m->blend = 0xb;
            m->blendMax = 0xa;
        }
        e = Effect_SpawnId(0xcb, &s->pos);
        s->unk_b44 = e->id;
        e->SetScaleXYZ(0x99a, 0x1000, 0x99a);
        MinB32_0219e998(s, 0x5a);
        break;
    }
    case 11:
        callBase = FALSE;
        switch (msg->data[0]) {
        case 1: {
            u16 a = *(u16 *)(msg->data + 4);
            u8 *p = ((u8 *)s->unk_54);
            LFLD(s16, p, 2) = *(s16 *)(msg->data + 2);
            LFLD(u16, p, 0) = a;
            break;
        }
        case 2:
            LFLD(u16, s->unk_54, 4) = *(u16 *)(msg->data + 4);
            break;
        }
        break;
    case 12:
        callBase = FALSE;
        if (msg->data[0] == 2) {
            LFLD(u16, s->unk_54, 4) = 0;
        }
        break;
    case 7: {
        s32 v;
        callBase = FALSE;
        s->unk_b29_4 = 1;
        s->pos.x = *(s32 *)(msg->data + 0);
        s->pos.y = *(s32 *)(msg->data + 4);
        s->pos.z = *(s32 *)(msg->data + 8);
        s->rot_x = *(u16 *)(msg->data + 0xc);
        s->rot_y = *(u16 *)(msg->data + 0xe);
        s->rot_z = *(u16 *)(msg->data + 0x10);
        v = *(s32 *)(msg->data + 0x14);
        if (v > 0) {
            s->gravity = v;
        } else if (v == 0) {
            if (s->unk_b24_1) {
                if ((data_ov000_021ccd68->frame & 0x3f) >= 0x2a) {
                    s->velY -= s->velY >> 2;
                } else {
                    s->velY -= s->velY >> 3;
                }
            } else if ((data_ov000_021ccd68->frame & 0x3f) >= 0x2a) {
                if (s->velY < 0) {
                    s->velY -= s->velY >> 1;
                }
            } else {
                if (s->velY < 0) {
                    s->velY -= s->velY >> 2;
                }
            }
            s->gravity = 0x52;
            s->hit->unk_9a_5 = 0;
            s->unk_b24_16 = 0;
        }
        break;
    }
    }
    if (callBase && Actor_HandleMsg(self, msg)) {
        return TRUE;
    }
    self->msg_flags |= 1 << msg->type;
    msg->type = 0;
    return TRUE;
}
}
