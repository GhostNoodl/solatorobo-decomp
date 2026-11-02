#include "ov006/SlotManager.h"
#include "nitro/fx.h"
#include "Main/Effect/Effect.h"
#include "ov000/ObjLayouts.h"
#include "ov006/Racer.h"

// An item box: a plain ActorEx; it keeps its shown position in unk_84 and, once taken, flies it
// to the taker's position, kept in vel.

extern "C" {

int func_ov000_0219a510(Actor *self, int a, VecFx32 *pos, s32 r, int b, void **out);
Ov006Racer *func_ov000_021985c0(void *p);
BOOL func_ov006_021ea3e8(Ov006Racer *p);
void func_ov006_021ea328(Ov006Racer *p);

static inline void ov006_Model_SetScaleAll(Model0218fe1c *m, fx32 s) {
    m->scale.x = s;
    m->scale.y = s;
    m->scale.z = s;
}

static inline void ov006_Item_Next(ActorEx *self) {
    self->fsm->st++;
    self->fsm->timer = 0;
}

void func_ov006_021ea854(ActorEx *self) {
    ActorSub40 *fsm = self->fsm;
    switch (fsm->st) {
    case 0:
        self->model->visible = 1;
        self->model->alpha = 0x1f;
        ov006_Model_SetScaleAll(self->model, 0x1000);
        self->unk_84 = self->pos;
        self->fsm->st++;
    case 1: {
        void *hits[0x20];
        int i;
        int n;
        if (data_ov006_021ec884->unk13D == 2) {
            return;
        }
        n = func_ov000_0219a510(self, 0x80, &self->pos, self->radius + 0x3000, 0, hits);
        if (n == 0) {
            return;
        }
        for (i = 0; i < n; i++) {
            Ov006Racer *p;
            if (hits[i] == NULL) {
                continue;
            }
            p = func_ov000_021985c0(hits[i]);
            if (p == NULL) {
                continue;
            }
            if (func_ov006_021ea3e8(p)) {
                continue;
            }
            func_ov006_021ea328(p);
            self->vel = p->pos;
            func_02065f88(0x57d, &self->pos);
            ov006_Item_Next(self);
            return;
        }
        break;
    }
    case 2:
        fsm->timer++;
        if (fsm->timer < 0x1e) {
            VecFx32 d;
            u16 t;
            d.x = self->vel.x - self->unk_84.x;
            d.y = self->vel.y - self->unk_84.y;
            d.z = self->vel.z - self->unk_84.z;
            VEC_MultAdd(0x59a, &d, &self->unk_84, &self->unk_84);
            t = self->fsm->timer;
            self->model->alpha = 0x1f - t;
            ov006_Model_SetScaleAll(self->model, 0x1000 - (t << 7));
        } else {
            self->model->visible = 0;
            ov006_Item_Next(self);
        }
        break;
    case 3:
        fsm->timer++;
        if (fsm->timer > 0x1e) {
            self->fsm->st = 0;
            self->fsm->timer = 0;
        }
        break;
    }
}

}
