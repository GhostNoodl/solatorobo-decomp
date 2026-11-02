#include "types.h"
#include "ov003/Actor.h"

extern "C" {

extern void Obj021984c8_UpdatePos(void *p, int a, int b);
extern void ActorSub48_UpdatePos(ActorSub48 *p, VecFx32 *a, u16 *b);

void Ov003Actor_UpdateSub44(Ov003Actor *self) {
    if (self->unk_44 != NULL) {
        Obj021984c8_UpdatePos(self->unk_44, 0, 0);
    }
}

void Ov003Actor_UpdateHit(Ov003Actor *self) {
    if (self->hit != NULL) {
        ActorSub48_UpdatePos(self->hit, 0, 0);
    }
}

void Ov003Actor_UpdateMode1() {

}

void Ov003Actor_UpdateMode3() {

}

void func_ov003_021d6d3c() {

}

void Ov003Actor_State25() {

}

void Ov003Actor_State24() {

}

void Ov003Actor_State23() {

}

void Ov003Actor_State22() {

}

void Ov003Actor_State21() {

}

void Ov003Actor_State16(Ov003Actor *self) {
    self->vfunc_54();
}

void Ov003Actor_Shoot2(Ov003Actor *self) {
    self->unk_ee_5 = 1;
    self->vfunc_70();
}

void Ov003Actor_StateAttack3(Ov003Actor *self) {
    self->unk_ee_2 = 2;
    self->vfunc_64();
}

void Ov003Actor_StateAttack2(Ov003Actor *self) {
    self->unk_ee_2 = 1;
    self->vfunc_64();
}

void Ov003ActVt_021f7c0c_Start(Ov003Actor *self) {
    Ov003Actor_Start(self);
    if (self->unk_1a != 0) {
        self->fsm->flags |= 0x100000000ULL;
    }
}

}
