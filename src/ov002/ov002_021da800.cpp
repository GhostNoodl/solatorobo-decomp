#include "ov002/ov002.h"

extern "C" {

BOOL Obj021efe7c_IsLoaded(Obj021efe7c *self) {
    BOOL a = ResMgr_IsLoaded(data_ov002_021efdf6, 7) != 0 ? TRUE : FALSE;
    BOOL b;
    u8 *d = FIELD(((u8 *)self->board), 4, u8 *);
    b = TRUE;
    if (*FIELD(d, 4, s16 *) >= 0 && !ResSet_UpdateLoad(FIELD(d, 4, s16 *))) {
        b = FALSE;
    }
    if (*FIELD(d, 0xc, s16 *) >= 0 && !ResSet_UpdateLoad(FIELD(d, 0xc, s16 *))) {
        b = FALSE;
    }
    if (*FIELD(d, 0x14, s16 *) >= 0 && !ResSet_UpdateLoad(FIELD(d, 0x14, s16 *))) {
        b = FALSE;
    }
    return (a & b) ? TRUE : FALSE;
}

void Obj021efe7c_Start(Obj021efe7c *self) {
    func_ov002_021d95e0(self->board);
    func_ov002_021dab58(self, self->unk_0c);
    EffectMgr_SaveList(data_0214a420);
    *(s32 *)data_0214a420 = 0;
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
            func_ov002_021dab58(self, FIELD(((void *)self->unk_08), 8, int));
        }
    }
    if (((void *)self->unk_08) == NULL) {
        r = FALSE;
    }
    EffectMgr_Update(data_0214a420);
    return r;
}

}
