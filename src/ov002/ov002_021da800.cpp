#include "ov002/ov002.h"

extern "C" {

BOOL Obj021efe7c_IsLoaded(Obj021efe7c *self) {
    BOOL a = ResMgr_IsLoaded(data_ov002_021efdf6, 7) != 0 ? TRUE : FALSE;
    BOOL b;
    Obj021efe4c *d = self->board->field;
    b = TRUE;
    if (d->unk_04->unk_00 >= 0 && !ResSet_UpdateLoad(d->unk_04)) {
        b = FALSE;
    }
    if (d->unk_0c->unk_00 >= 0 && !ResSet_UpdateLoad(d->unk_0c)) {
        b = FALSE;
    }
    if (d->unk_14->unk_00 >= 0 && !ResSet_UpdateLoad(d->unk_14)) {
        b = FALSE;
    }
    return (a & b) ? TRUE : FALSE;
}

void Obj021efe7c_Start(Obj021efe7c *self) {
    Obj021efe6c_Start(self->board);
    Obj021efe7c_SetPhase(self, self->unk_0c);
    EffectMgr_SaveList(gEffectMgr);
    *(s32 *)gEffectMgr = 0;
    self->unk_10 = 1;
}

BOOL Obj021efe7c_Update(Obj021efe7c *self) {
    BOOL r = TRUE;
    VObj *o;
    Obj021efe6c_Update(self->board);
    o = self->unk_08;
    if (o != NULL) {
        o->vfunc_0c();
        self->unk_08->vfunc_10();
        if (self->unk_08->vfunc_18()) {
            Obj021efe7c_SetPhase(self, FIELD(((void *)self->unk_08), 8, int));
        }
    }
    if (((void *)self->unk_08) == NULL) {
        r = FALSE;
    }
    EffectMgr_Update(gEffectMgr);
    return r;
}

}
