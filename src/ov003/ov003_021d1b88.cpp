#include "types.h"
#include "ov003/Actor.h"

extern "C" {

typedef struct {
    u16 unk_00;
    s16 unk_02;
} Ov003DispPos;

extern s32 func_0203db40(void *p);
extern void func_ov000_02190a80(void *a, s32 b);
extern void func_ov000_02191418(Model0218fe1c *m, u16 a, BOOL b);
extern BOOL func_ov000_0218d494(Ov003Actor *self, ActorMsg *ev);

static inline void Ov003_SetColor(Model0218fe1c *m, u16 c0, u16 c1) {
    m->color = c0;
    m->color2 = c1;
    m->blend = 0xb;
    m->blendMax = 0xa;
}

void Ov003Actor_Animate(Ov003Actor *self) {
    s32 i;
    if (self->model != NULL) {
        func_ov000_02190a80(self->model, func_0203db40(&self->pause));
    }
    if (self->unk_d0 == NULL || self->unk_ea_3 == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        if (self->unk_d0->models[i] != NULL) {
            func_ov000_02190a80(self->unk_d0->models[i], 0x1000);
        }
    }
}

BOOL Ov003Actor_HandleMsg(Ov003Actor *self, ActorMsg *ev) {
    BOOL ret = FALSE;
    BOOL base = TRUE;
    switch (ev->type) {
    case 9: {
        ActorHp *st;
        base = FALSE;
        ret = TRUE;
        st = self->hpObj;
        if (st != NULL && st->unk_0a == 0 && self->fsm->current != 0x20) {
            s32 n;
            u8 b;
            u16 c0;
            u16 c1;
            s32 i;
            st->unk_04 = ev->id;
            n = Ov003Actor_ApplyHit(self, &ev->hit);
            b = self->hpObj->kind2;
            if (n != 0) {
                self->fsm->flags |= (1ULL << n);
            }
            if (b != 1) {
                func_ov000_02191418(self->model, 5, 0);
            }
            if (ev->id != self->id) {
                self->hpObj->unk_0a = 5;
            }
            c0 = 0x14bf;
            if (self->unk_ea_8) c0 = 0x5adf;
            c1 = 0x739f;
            Ov003_SetColor(self->model, c0, c1);
            if (self->unk_d0 != NULL && self->unk_ea_3 != 0) {
                for (i = 0; i < 2; i++) {
                    Model0218fe1c *m = self->unk_d0->models[i];
                    if (m != NULL) {
                        Ov003_SetColor(m, c0, c1);
                    }
                }
            }
        }
        break;
    }
    case 11: {
        ActorHp *st;
        base = FALSE;
        if (ev->unk_08 == 1) {
            u16 x = ev->unk_0c;
            s16 y = ev->unk_0a;
            Ov003DispPos *pos = (Ov003DispPos *)self->unk_54;
            pos->unk_02 = y;
            pos->unk_00 = x;
        }
        self->hpObj->unk_04 = ev->id;
        st = self->hpObj;
        st->dmg = 0;
        st->kind = 0;
        st->kind2 = 0;
        if (self->hpObj->cur != 0) {
            self->fsm->flags |= 0x40000;
        }
        ret = TRUE;
        break;
    }
    }
    if (base) {
        if (func_ov000_0218d494(self, ev)) {
            return TRUE;
        }
    }
    if (ret) {
        self->msg_flags |= 1 << ev->type;
        ev->type = 0;
    }
    return ret;
}

}
