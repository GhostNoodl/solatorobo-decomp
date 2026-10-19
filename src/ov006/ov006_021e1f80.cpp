#include "ov006/Model.h"
#include "nitro/fx.h"

typedef struct ov006_Marker {
    void *vtbl;
    u16 state;
    u16 unk6;
    s16 timer;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    int unk10;
    int unk14;
    VecFx32 pos;
} ov006_Marker;

extern "C" {

static inline void ov006_Marker_SetState(ov006_Marker *self, u16 state) {
    self->state = state;
    self->unk6 = 0;
    self->timer = 0;
}

static inline void ov006_Marker_SlotPos(VecFx32 *v, u8 slot) {
    v->x = 0;
    v->y = (slot - 1) << 17;
    v->z = 0;
}

static inline void ov006_Marker_Move(ov006_Marker *self) {
    VecFx32 from;
    VecFx32 to;
    VecFx32 d;
    fx32 t;
    ov006_Marker_SlotPos(&from, self->unkA);
    ov006_Marker_SlotPos(&to, self->unkB);
    t = FX_Div(self->timer << 12, 0xa000);
    d.x = to.x - from.x;
    d.y = to.y - from.y;
    d.z = to.z - from.z;
    VEC_MultAdd(t, &d, &from, &self->pos);
    self->timer++;
    if (self->timer > 10) {
        self->unkA = self->unkB;
        ov006_Marker_SetState(self, 1);
    }
}

void func_ov006_021e1f80(ov006_Marker *self) {
    if (self->state == 0) {
        return;
    }
    switch (self->state) {
    case 1:
        ov006_Marker_SlotPos(&self->pos, self->unkA);
        if (self->unkA == self->unkC) {
            return;
        }
        if (self->unkA < self->unkC) {
            self->unkB = self->unkC;
            ov006_Marker_SetState(self, 2);
        } else if (self->unkA > self->unkC) {
            self->unkB = self->unkC;
            ov006_Marker_SetState(self, 3);
        }
        break;
    case 2:
        ov006_Marker_Move(self);
        break;
    case 3:
        ov006_Marker_Move(self);
        break;
    }
}

}
