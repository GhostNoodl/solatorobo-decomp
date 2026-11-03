#include "types.h"
#include "Main/Lang/TblRes.h"
#include "nitro/std.h"
#include "ov003/Actor.h"
#include "Main/Sys/FieldState.h"
#include "Main/Gfx/PlttRes.h"
#include "ov000/ActorMarker.h"

typedef struct {
    u8 pad00[0x12];
    u16 b0 : 5;
    u16 b5 : 3;
    u16 rest : 8;
    s16 unk_14;
    s16 unk_16;
} Ov003InInfo;

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u16 unk_04;
    u16 unk_06;
    TblActorPair unk_08;
    u32 unk_0c;
    u8 pad10[8];
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Ov003InObj4c;

typedef struct {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
} Ov003InObj54;

typedef struct {
    s32 frame;
    u32 unk_04;
    u8 *unk_08;
} Ov003InFrm;

typedef struct {
    Ov003InFrm *frm;
    u8 pad04[0x10d];
    u8 unk_111;
} Ov003InAnm;

extern "C" {
void *Heap_Alloc(u32 size);
Ov003InInfo *Tbl_FindEntry_0206fef8(u16 id);
Model0218fe1c *Model0218fe1c_Init(void *p);
void Model0218fe1c_Setup(Model0218fe1c *m, void *res, Ov003InInfo *info);
ActorSub48 *ActorSub48_Init(void *p);
void Body_SetOwner(ActorSub48 *o, u16 id);
void HitSphere_Link(ActorSub48 *o);
void ActorSub48_UpdatePos(ActorSub48 *o, VecFx32 *a, u16 *b);
ActorSub44 *Obj021984c8_Init(void *p);
void Obj021984c8_UpdatePos(ActorSub44 *o, void *a, s32 b);
Ov003InObj4c *Target_Init(void *p);
s32 NNS_G3dGetResDictIdxByName(const void *dict, const void *name);
BOOL Model0218fe1c_SetRes(Model0218fe1c *m, void *res, s32 idx, s32 b);
Ov003InAnm *Model0218fe1c_GetAnimCtrl(Model0218fe1c *m, s32 n);
void func_ov000_02191920(Model0218fe1c *m, s32 idx, s16 a, u8 b);
}

static inline Model0218fe1c *Ov003In_NewModel(void) {
    void *p = Heap_Alloc(0xe8);
    if (p != NULL) {
        p = Model0218fe1c_Init(p);
    }
    return (Model0218fe1c *)p;
}

static inline ActorSub48 *Ov003In_NewObj48(void) {
    void *p = Heap_Alloc(0x9c);
    if (p != NULL) {
        p = ActorSub48_Init(p);
    }
    return (ActorSub48 *)p;
}

static inline ActorSub44 *Ov003In_NewObj44(void) {
    void *p = Heap_Alloc(0x24);
    if (p != NULL) {
        p = Obj021984c8_Init(p);
    }
    return (ActorSub44 *)p;
}

static inline Ov003InObj4c *Ov003In_NewObj4c(void) {
    void *p = Heap_Alloc(0x5c);
    if (p != NULL) {
        p = Target_Init(p);
    }
    return (Ov003InObj4c *)p;
}

static inline ActorMarker *Ov003In_NewObj5c(void) {
    ActorMarker *p = (ActorMarker *)Heap_Alloc(0xa8);
    if (p != NULL) {
        ActorMarker_Init(p);
    }
    return p;
}

static inline ActorHp *Ov003In_NewObj50(void) {
    ActorHp *p = (ActorHp *)Heap_Alloc(0x1c);
    if (p != NULL) {
        p->cur = 100;
        p->max = 100;
        p->unk_04 = 0xffff;
        p->unk_0a = 0;
        p->unk_0e = 0;
        p->unk_0c = 0;
        p->unk_10 = 0;
        p->unk_14 = 0;
        p->unk_18 = 0;
    }
    return p;
}

static inline Ov003InObj54 *Ov003In_NewObj54(void) {
    Ov003InObj54 *p = (Ov003InObj54 *)Heap_Alloc(6);
    if (p != NULL) {
        p->unk_00 = 0;
        p->unk_02 = 0;
        p->unk_04 = 0;
    }
    return p;
}

extern "C" void Ov003Actor_Start(Ov003Actor *self) {
    TblActorTarget *param;
    Ov003InInfo *info;
    u8 n;
    s32 i;
    info = Tbl_FindEntry_0206fef8(self->kind);
    param = &func_02070558(self->kind)->target;
    self->radius = info->unk_14 << 4;
    self->height = info->unk_16 << 4;
    self->centerY = self->height >> 1;
    self->model = Ov003In_NewModel();
    self->model->actor_id = self->id;
    Model0218fe1c_Setup(self->model, self->unk_34, info);
    if (self->unk_3c != NULL) {
        self->unk_3c->unk_14 = self->radius << 1;
    }
    {
        ActorSub48 *o;
        self->hit = Ov003In_NewObj48();
        Body_SetOwner(self->hit, self->id);
        self->hit->unk_28 = 0x20;
        self->hit->radius = self->radius;
        self->hit->offset.y = self->centerY;
        o = self->hit;
        o->unk_9a_0 = 1;
        o->unk_9a_3 = 1;
        HitSphere_Link(o);
        *(u16 *)((u8 *)self->hit + 0x9a) |= 0x12;
        self->hit->unk_9a_5 = 1;
        if (self->radius >> 1 < 0x4cd) {
            self->hit->unk_48 = 0x4cd;
        }
        ActorSub48_UpdatePos(self->hit, NULL, 0);
    }
    for (i = 0; i < 2; i++) {
        if (self->unk_b0->unk_10[i] != NULL || self->unk_b0->unk_0e[i] != 0) {
            Ov003SubD0 *pp = (Ov003SubD0 *)Heap_AllocHi(0x70, 4);
            s32 j;
            self->unk_d0 = pp;
            for (j = 0; j < 2; j++) {
                pp->idx[j] = 0xff;
                pp->unk_62[j] = 0xffff;
                pp->models[j] = NULL;
            }
            break;
        }
    }
    if (self->unk_d0 != NULL) {
        Ov003InAnm *anm;
        Model0218fe1c *m;
        long k2;
        self->unk_ea_3 = 1;
        for (k2 = 0; k2 < 2; k2++) {
            if (self->unk_b0->unk_10[k2] != NULL) {
                u32 name[4];
                u32 k;
                u8 *dict;
                s32 idx;
                for (k = 0; k < 4; k++) {
                    name[k] = 0;
                }
                STD_CopyString((char *)name, self->unk_b0->unk_10[k2]);
                dict = NULL;
                if (self->model->mdl != NULL) {
                    dict = (u8 *)self->model->mdl + 0x40;
                }
                if (dict == NULL) {
                    idx = -1;
                } else {
                    idx = NNS_G3dGetResDictIdxByName(dict, name);
                }
                if (idx < 0) {
                    continue;
                }
                self->unk_d0->idx[k2] = idx;
                n = self->unk_b0->unk_0e[k2];
                if (n == 0) {
                    continue;
                }
                m = (Model0218fe1c *)Heap_Alloc(0xe8);
                if (m != NULL) {
                    m = Model0218fe1c_Init(m);
                }
                self->unk_d0->models[k2] = m;
                if (info->b5 != 0 && self->unk_b0->unk_0c_5) {
                    Model0218fe1c_SetRes(m, self->unk_34, n, 1);
                    anm = Model0218fe1c_GetAnimCtrl(m, 3);
                    if (anm != NULL) {
                        s32 f;
                        Ov003InFrm *frm;
                        func_ov000_02191920(m, n, 0x1000, 0);
                        {
                            s32 x = info->b5 << 12;
                            f = (s32)(info->b5 != 0 ? x + 0.5f : x - 0.5f);
                        }
                        frm = anm->frm;
                        if (frm != NULL) {
                            if (f >= 0) {
                                frm->frame = f;
                            } else {
                                frm->frame = (*(u16 *)(frm->unk_08 + 4) << 12) - 1;
                            }
                        }
                        anm->unk_111 |= 8;
                    }
                } else {
                    Model0218fe1c_SetRes(m, self->unk_34, n, 0);
                }
                m->boxTest = 0;
            }
        }
    }
    {
        ActorSub44 *o;
        self->unk_44 = Ov003In_NewObj44();
        self->unk_44->unk_1c = self->radius;
        self->unk_44->unk_0c.y = self->centerY;
        self->unk_44->unk_20 = self->id;
        o = self->unk_44;
        o->unk_22_0 = 1;
        o->unk_22_1 = 1;
        Obj021984c8_UpdatePos(self->unk_44, NULL, 0);
        if (self->unk_b0->unk_0a_3 != 0) {
            self->unk_44->unk_22_2 = (u8)self->unk_b0->unk_0a_3;
        }
    }
    {
    Ov003InObj4c *o4c = Ov003In_NewObj4c();
    self->targetObj = (ActorSub4c *)o4c;
    if (param != NULL) {
        o4c->unk_00 = param->type;
        o4c->unk_01 = param->unk_01;
        o4c->unk_02 = param->unk_02;
        o4c->unk_03 = param->unk_03;
        o4c->unk_04 = param->unk_04;
        o4c->unk_06 = param->unk_06;
        o4c->unk_08 = param->unk_08;
        o4c->unk_0c = param->unk_0c;
    }
    }
    self->targetObj->unk_18_1 = 0;
    {
        u16 n = self->unk_b0->unk_08;
        if (n != 0) {
            u16 d;
            self->hpObj = Ov003In_NewObj50();
            self->hpObj->cur = n;
            self->hpObj->max = n;
            d = self->unk_b0->unk_0a_0;
            self->unk_dc = d < 2 ? 0 : n / d;
            self->hpObj->unk_0c = 2;
        }
    }
    self->unk_54 = Ov003In_NewObj54();
    {
        ActorMarker *p = Ov003In_NewObj5c();
        self->unk_5c = p;
        ActorMarker_SetKind(p, 1);
        self->unk_5c->height = self->height;
    }
    if (data_ov000_021ccd54->unk_ca.c[0] == 0x11) {
        self->unk_ea_14 = 1;
    }
}
