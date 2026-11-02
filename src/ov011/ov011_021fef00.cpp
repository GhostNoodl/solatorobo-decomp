#include "ov011/ov011.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Snd/SndMgr.h"

extern "C" {

extern const s16 data_ov011_0220726e[4];
void *History_Init(void *p);
void *Ov011Fx_Ctor(void *p);
void *Ov011Chr_Ctor(void *p);
void Ov011Mov_Init(void *p);
void *Ov011Vt_022079b0_Ctor(void *p);
BOOL Ov011Scene_Init(Ov011Scene *p, Actor *owner);
BOOL func_020621c4(void);

void Ov011SceneActor_Start(Ov011SceneActor *self) {
    Ov011Scene *p;
    Ov011Sa104 *q;
    Ov003Actor_Start(self);
    p = (Ov011Scene *)Heap_Alloc(0x23c);
    if (p != NULL) {
        p->ring.b0 = 0;
        History_Init(&p->seq);
        Ov011Fx_Ctor(&p->fx);
        History_Init(&p->mgr2.state);
        Ov011Chr_Ctor(p->mgr2.unk_28);
        Ov011Mov_Init(&p->mgr2.mov);
        p->mgr2.b0 = 0;
        History_Init(&p->s1b4.seq);
        p->s1b4.b0 = 0;
        History_Init(&p->mgr.state);
        p->mgr.b0 = 0;
        p->ent.active = 0;
        p->b0 = 0;
    }
    self->scene = p;
    Ov011Scene_Init(p, self);
    q = (Ov011Sa104 *)Heap_Alloc(0x3c);
    if (q != NULL) {
        History_Init(q);
        Ov011Vt_022079b0_Ctor(&q->tw);
    }
    self->unk_104 = q;
    self->unk_108 = (Ov011Sa108 *)Heap_Alloc(6);
    self->unk_10c = (Ov011Sa10c *)Heap_Alloc(4);
    {
        Ov011Sa104 *s = self->unk_104;
        Ov003ActorSub40_ForceState(s, 0);
        s->unk_38 = 0;
    }
    {
        Ov011Sa108 *s = self->unk_108;
        s->b0 = 0;
        s->b1 = 0;
        s->unk_02 = 0x1000;
        s->unk_04 = 0x1000;
    }
    {
        Ov011Sa10c *s = self->unk_10c;
        s->b0 = 0;
        s->b1 = 0;
        s->b2 = 1;
        s->timer = 0;
    }
    self->hit->unk_30 = 0x60000000;
    self->target = ((Actor *)func_ov000_0219bf90())->id;
    if (func_020621c4()) {
        Ov003Actor_ScaleStats(self, data_ov011_0220726e);
    }
    self->mode = 2;
}

extern const char *const data_ov011_02207258;
BOOL Ov003Actor_HandleMsg(Ov003Actor *self, Ov011ActMsg *msg);


BOOL Ov011SceneActor_HandleMsg(Ov011SceneActor *self, Ov011ActMsg *msg) {
    if (msg->type == 0xe) {
        switch (msg->cmd) {
        case 1: {
            ActorSub40 *st;
            s32 sub = msg->u.arg;
            if (sub == 0) {
                st = &self->unk_104->seq;
                if (st->current == 0) {
                    st->flags |= 2;
                    func_0204a028(data_02097e4c, 9, &self->pos, -2);
                }
            } else if (sub == 1) {
                st = &self->unk_104->seq;
                if (st->current == 1) {
                    st->flags |= 4;
                    func_02049f44(data_02097e4c, 0x5b, &self->pos, 0);
                }
            } else if (sub == 2) {
                st = &self->unk_104->seq;
                if (st->current == 2) {
                    st->flags |= 8;
                }
            }
            break;
        }
        case 2: {
            Ov011Sa108 *p = self->unk_108;
            if (p != NULL) {
                *(u8 *)p = msg->u.p.b;
                p->unk_02 = msg->u.p.x;
                p->unk_04 = msg->u.p.y;
            }
            break;
        }
        case 3:
            if (msg->u.p.b != 0) {
                Ov011Sa10c *s = self->unk_10c;
                s->b0 = 1;
                s->b1 = 1;
                s->b2 = 1;
                s->timer = 0;
            } else {
                Ov011Sa10c *s = self->unk_10c;
                s->b0 = 0;
                s->b1 = 0;
                s->b2 = 0;
                s->timer = 0;
                func_ov000_02190cb0(self->model, data_ov011_02207258, 0x1000, 0);
                func_ov000_021915a0(self->model);
            }
            break;
        }
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
        return TRUE;
    }
    return Ov003Actor_HandleMsg(self, msg);
}

}
