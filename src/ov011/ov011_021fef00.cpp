#include "ov011/ov011.h"

extern "C" {

extern const s16 data_ov011_0220726e[4];
void *History_Init(void *p);
void *func_ov011_02201510(void *p);
void *func_ov011_02201c18(void *p);
void Ov011Mov_Init(void *p);
void *Ov011Vt_022079b0_Ctor(void *p);
BOOL func_ov011_021fd4d8(void *p, void *owner);
BOOL func_020621c4(void);

void Ov011SceneActor_Start(Ov011SceneActor *self) {
    Ov011Scene *p;
    Ov011Sa104 *q;
    func_ov003_021d112c(self);
    p = (Ov011Scene *)Heap_Alloc(0x23c);
    if (p != NULL) {
        p->ring.b0 = 0;
        History_Init(&p->seq);
        func_ov011_02201510(&p->fx);
        History_Init(&p->mgr2.state);
        func_ov011_02201c18(p->mgr2.unk_28);
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
    func_ov011_021fd4d8(p, self);
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
        func_ov003_021da48c(s, 0);
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
        func_ov003_021d6bac(self, data_ov011_0220726e);
    }
    self->mode = 2;
}

extern void *data_02097e4c;
extern const char *const data_ov011_02207258;
extern void *func_0204a028(void *a, s32 b, VecFx32 *c, s32 d);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
BOOL func_ov003_021d1c00(Ov003Actor *self, Ov011ActMsg *msg);


BOOL func_ov011_021ff084(Ov011SceneActor *self, Ov011ActMsg *msg) {
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
    return func_ov003_021d1c00(self, msg);
}

}
