#include "ov015/ov015.h"

extern "C" {

extern u8 Ov015Result_vtbl[];
void *Ov015Ship_Dtor(Ov015Ship *p);
extern u8 Ov015Vt_0221294c_vtbl[];
void *Model0218fe1c_FreeAnims(void *p);
void *ResSet_ReleaseAll(void *p);
extern u8 Ov015Hud_vtbl[];
extern char data_ov015_022128ab[];
void LangData_LocalizePath(char *buf, const char *name);
extern u8 Ov015MsgMgr_vtbl[];
void Ov015MsgMgr_DtorBase(void *p);

s32 func_ov015_02200ec8(Ov015Obj34 *self, Ov015Stat *st, s32 base) {
    s32 m = st->unk_28;
    s32 b = st->unk_14;
    s32 a = st->unk_10;
    switch (m) {
    case 3:
        base += 0x7b;
        break;
    case 2:
        base = 0x333;
        break;
    default:
        if (a == 0) {
            base = 0;
        } else {

            if (b == 4) {
                base = 0x333;
            } else {
                base += 0x1e;
            }
            if ((self->unk_0c >> 12) % 20 == 0) {

                SndMgr_PlayVolume(gSndMgr, 0x48, -1, -1, -1);
            }
        }
        break;
    }
    return base;
}

void Ov015Game_Reset(Ov015Game *self) {
    self->unk_08 = 2;
    self->step = 0;
    self->unk_10 = 0;
    self->unk_14 = 1;
    self->ship = 0;
    self->fishList = 0;
    self->unk_20 = 0;
    self->cam = 0;
    self->hud = 0;
    self->result = NULL;
    self->unk_90 = 0;
    data_ov015_0221332c.unk_00 = 0x1f4000;
    data_ov015_0221332c.unk_04 = 0;
    data_ov015_0221332c.unk_08 = 1;
    data_ov015_0221332c.unk_0c = 0;
    data_ov015_0221332c.unk_14 = 1;
    data_ov015_0221332c.unk_10 = 1;
    data_ov015_0221332c.unk_18 = 0;
    data_ov015_0221332c.unk_1c = 0;
    data_ov015_0221332c.unk_1d = 0;
    data_ov015_0221332c.unk_20 = 0;
    data_ov015_0221332c.unk_24 = 0;
    data_ov015_0221332c.unk_28 = 0;
    data_ov015_0221332c.unk_2c = 0;
    data_ov015_0221332c.unk_30 = -1;
}

void *Ov015Result_DtorDelete(Ov015Result *self) {
    SET_VT(self, Ov015Result_vtbl);
    Ov015Result_DtorBase(self);
    Heap_Free(self);
    return self;
}

void Ov015Game_FreeAll(Ov015Game *self) {
    void *saved;
    HEAP_PUSH(saved);
    {
    Ov015Ship *o = self->ship;
    if (o != NULL) {
        if (o != NULL) {
            Ov015Ship_Dtor(o);
            Heap_Free(o);
        }
        self->ship = NULL;
    }
    }
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_20);
    HEAP_POP(saved);
    if (self->fishList != NULL) {
        Ov015Node *n;
        for (n = self->fishList->head; n != NULL; n = n->next) {
            if (n->fish != NULL) n->fish->vfunc_04();
        }
        HEAP_PUSH(saved);
        DELETE_V(self->fishList);
        HEAP_POP(saved);
    }
    HEAP_PUSH(saved);
    DELETE_V(self->cam);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->hud);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_90);
    HEAP_POP(saved);
}

void *Ov015Vt_0221294c_DtorDelete(u8 *self) {
    SET_VT(self, Ov015Vt_0221294c_vtbl);
    Model0218fe1c_FreeAnims(self + 0x57c);
    ResSet_ReleaseAll(self + 0x444);
    Model0218fe1c_FreeAnims(self + 0x35c);
    ResSet_ReleaseAll(self + 0x224);
    Model0218fe1c_FreeAnims(self + 0x13c);
    ResSet_ReleaseAll(self + 0x4);
    Heap_Free(self);
    return self;
}

void *Ov015Hud_DtorDelete(Ov015Hud *self) {
    char buf[0x20];
    SET_VT(self, Ov015Hud_vtbl);
    {
        void *saved;
        HEAP_PUSH(saved);
        {
            Model *o = self->mdl0;
            if (o != NULL) {
                if (o != NULL) {
                    TexObj_Release(o);
                    PlttRes_Release(&o->pltt);
                    Heap_Free(o);
                }
                self->mdl0 = NULL;
            }
        }
        HEAP_POP(saved);
    }
    {
        void *saved;
        HEAP_PUSH(saved);
        {
            Model *o = self->mdl1;
            if (o != NULL) {
                if (o != NULL) {
                    TexObj_Release(o);
                    PlttRes_Release(&o->pltt);
                    Heap_Free(o);
                }
                self->mdl1 = NULL;
            }
        }
        HEAP_POP(saved);
    }
    LangData_LocalizePath(buf, data_ov015_022128ab);
    ResMgr_ReleaseByName(gResMgr, buf, 7, 0);
    Heap_Free(self);
    return self;
}

void *Ov015MsgMgr_DtorDelete(Ov015MsgMgr *self) {
    SET_VT(self, Ov015MsgMgr_vtbl);
    Ov015MsgMgr_DtorBase(self);
    Heap_Free(self);
    return self;
}

}
