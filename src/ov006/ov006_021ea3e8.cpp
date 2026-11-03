#include "ov006/SlotManager.h"
#include "ov006/Racer.h"

typedef struct ov006_Pos {
    s32 x;
    s32 y;
    s32 z;
} ov006_Pos;

extern "C" {

Ov006Racer *Ov006ActVt_021ec4f4_Ctor(Ov006Racer *self);
void *Tbl_GetText(s32 id);
void Actor_JoinGroup(Actor *self, u16 type, u32 id, void *res);
void Obj021984c8_UpdatePos(ActorSub44 *a, int b, int c);
void ActorSub48_UpdatePos(ActorSub48 *a, int b, int c);
void *func_0203db40(PauseNode *a);
void Model0218fe1c_UpdateAnim(Model0218fe1c *a, void *b);

BOOL Ov006Racer_IsFinished(Ov006Racer *self) {
    BOOL result = FALSE;
    if (self->unk_19f > data_ov006_021ec884->info->unkB) {
        result = TRUE;
    }
    return result;
}

void Ov006Racer_SetFinished(Ov006Racer *self) {
    self->unk_19f = data_ov006_021ec884->info->unkB + 1;
}

Ov006Racer *Ov006Racer_New(u32 id, u8 a, const ov006_Pos *pos, const u16 *rot) {
    Ov006Racer *prop = (Ov006Racer *)Heap_Alloc(sizeof(Ov006Racer));
    if (prop != NULL) {
        prop = Ov006ActVt_021ec4f4_Ctor(prop);
    }
    if (prop != NULL) {
        Actor_JoinGroup(prop, id & 0xf000, id, Tbl_GetText(id));
        prop->idx = a;
        prop->pos.x = pos->x;
        prop->pos.y = pos->y;
        prop->pos.z = pos->z;
        prop->rot_x = rot[0];
        prop->rot_y = rot[1];
        prop->rot_z = rot[2];
        prop->vfunc_04();
    }
    return prop;
}

void Ov006Racer_UpdateSub44(Ov006Racer *self) {
    if (self->unk_44 != NULL) {
        Obj021984c8_UpdatePos(self->unk_44, 0, 0);
    }
}

void Ov006ActVt_021ec4f4_UpdateHit(Ov006Racer *self) {
    if (self->hit != NULL) {
        ActorSub48_UpdatePos(self->hit, 0, 0);
    }
}

void Ov006Racer_Animate(Ov006Racer *self) {
    if (self->model != NULL) {
        Model0218fe1c_UpdateAnim(self->model, func_0203db40(&self->pause));
    }
}

void Ov006ActorBase_UpdateMode3(void) {
}

void Ov006ActVt_021ec4f4_Update(void) {
}

}
