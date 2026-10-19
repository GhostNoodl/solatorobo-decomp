#include "ov006/SlotManager.h"
#include "nitro/fx.h"

typedef struct ov006_Model021ea548 {
    u8 unk0[0xa8];
    VecFx32 scale;
    u8 unkB4[0xa];
    u8 alpha;
    u8 unkBF[3];
    u16 unkC2_0 : 1;
    u16 unkC2_1 : 15;
} ov006_Model021ea548;

typedef struct ov006_State021ea548 {
    u16 state;
    u16 timer;
} ov006_State021ea548;

typedef struct ov006_Obj021ea548 {
    u8 unk0[0x38];
    ov006_Model021ea548 *model;
    u8 unk3C[4];
    ov006_State021ea548 *st;
    u8 unk44[0x20];
    s32 unk64;
    u8 unk68[8];
    VecFx32 pos;
    u8 unk7C[8];
    VecFx32 cur;
    u8 unk90[0xc];
    VecFx32 target;
} ov006_Obj021ea548;

typedef struct ov006_Prop021ea548 {
    u8 unk0[0x70];
    VecFx32 pos;
} ov006_Prop021ea548;

extern "C" {

int func_ov000_0219a510(void *self, int a, VecFx32 *pos, s32 r, int b, void **out);
ov006_Prop021ea548 *func_ov000_021985c0(void *p);
BOOL func_ov006_021ea3e8(ov006_Prop021ea548 *p);
void func_ov006_021ea244(ov006_Prop021ea548 *p);
void *func_02065f88(int id, void *pos);

static inline void ov006_Model021ea548_SetScale(ov006_Model021ea548 *m, fx32 s) {
    m->scale.x = s;
    m->scale.y = s;
    m->scale.z = s;
}

static inline void ov006_Obj021ea548_Next(ov006_Obj021ea548 *self) {
    self->st->state++;
    self->st->timer = 0;
}

void func_ov006_021ea548(ov006_Obj021ea548 *self) {
    ov006_State021ea548 *st = self->st;
    switch (st->state) {
    case 0:
        self->model->unkC2_0 = 1;
        self->model->alpha = 0x1f;
        ov006_Model021ea548_SetScale(self->model, 0x1000);
        self->cur = self->pos;
        self->st->state++;
    case 1: {
        void *hits[0x20];
        int i;
        int n;
        if (data_ov006_021ec884->unk13D == 2) {
            return;
        }
        n = func_ov000_0219a510(self, 0x80, &self->pos, self->unk64 + 0x3000, 0, hits);
        if (n == 0) {
            return;
        }
        for (i = 0; i < n; i++) {
            ov006_Prop021ea548 *p;
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
            func_ov006_021ea244(p);
            self->target = p->pos;
            func_02065f88(0x57a, &self->pos);
            ov006_Obj021ea548_Next(self);
            return;
        }
        break;
    }
    case 2:
        st->timer++;
        if (st->timer < 0x1e) {
            VecFx32 d;
            u16 t;
            d.x = self->target.x - self->cur.x;
            d.y = self->target.y - self->cur.y;
            d.z = self->target.z - self->cur.z;
            VEC_MultAdd(0x59a, &d, &self->cur, &self->cur);
            t = self->st->timer;
            self->model->alpha = 0x1f - t;
            ov006_Model021ea548_SetScale(self->model, 0x1000 - (t << 7));
        } else {
            self->model->unkC2_0 = 0;
            ov006_Obj021ea548_Next(self);
        }
        break;
    case 3:
        st->timer++;
        if (st->timer > 0x5a) {
            self->st->state = 0;
            self->st->timer = 0;
        }
        break;
    }
}

}
