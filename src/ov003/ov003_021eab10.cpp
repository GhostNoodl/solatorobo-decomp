#include "types.h"
#include "Main/Math/Rot16.h"
#include "Main/Effect/Effect.h"
#include "Main/Sys/FieldState.h"
#include "ov003/Unit.h"
#include "ov003/ActorApi.h"
#include "ov000/ActorMgr.h"



typedef struct {
    u8 unk_00[0x16];
    u8 unk_16_0 : 2;
    u8 unk_16_2 : 1;
    u8 unk_17[0x4d];
    s32 radius;
    u8 unk_68[8];
    VecFx32 pos;
    u8 unk_7c[0x14];
    u16 unk_90;
} Ov003Player;

// The resource file ActorRes::unk_c0 points to: its animation event table follows an 8-byte header.
typedef struct {
    u8 unk_00[8];
    AnimEventTable tbl;
} Ov003AnimRes;

extern "C" {

extern void *gGroup;
extern char data_ov003_021f995c[];
extern char data_ov003_021f9967[];
extern char data_ov003_021f996d[];
extern char data_ov003_021f9978[];
extern Ov003Player *ActorMgr_FindPlayer(void);
extern void ActorMarker_Draw(void *p);
extern BOOL Hit_DiffInSphere(VecFx32 *a, VecFx32 *b, s32 r);
extern void ResSet_SetFile(ActorRes *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern BOOL ResSet_UpdateLoad(ActorRes *res);
extern BOOL Model0218fe1c_SetRes(Model0218fe1c *anim, ActorRes *res, s32 a, s32 b);
extern BOOL Model0218fe1c_SetAnim(void *model, const char *name, s32 a, s32 b);
extern void *Heap_Alloc(u32 size);
extern ActorSub4c *Target_Init(void *p);
extern void *func_0203db40(void *p);
extern void Model0218fe1c_UpdateAnim(void *a, void *b);
extern void Obj02190758_SetRot(Model0218fe1c *anim, Rot16 *rot, s32 a);
extern BOOL Model021903b4_Draw(Model0218fe1c *anim);
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);

static inline BOOL Ov003Game_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov003Game_IsIdle(FieldState *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    FieldState *g = gSceneCmd;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}







static inline BOOL Ov003_GameIdle2(void) {
    FieldState *g = gSceneCmd;
    if (g != NULL) {
        BOOL busy = FALSE;
        if (g->head != g->tail) {
            busy = TRUE;
        }
        if (busy) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

BOOL Ov003ActVt_021f98cc_Draw(ActorEx *self) {
    BOOL r = TRUE;
    if (!self->unk_cc_7) {
        if (self->unk_5c != NULL && Ov003_GameIdle()) {
            Ov003Player *pl = ActorMgr_FindPlayer();
            if (pl->unk_90 == self->id) {
                ActorMarker_Draw(self->unk_5c);
            }
        }
    } else if (self->targetObj->unk_03 != 10) {
        r = ActorEx_Draw(self);
    }
    return r;
}

void Ov003ActVt_021f98cc_StateIdle(ActorEx *self) {
    if (self->unk_cc_7) {
        return;
    }
    if (!Ov003_GameIdle()) {
        return;
    }
    if ((self->unk_ce & 0x7f) == 0 && self->unk_1a >= 0) {
        Ov003Player *pl = ActorMgr_FindPlayer();
        if (pl != NULL) {
            s32 r = 0xf000;
            if (self->unk_1a >= 1) {
                r = self->unk_1a << 4;
            }
            if (Hit_DiffInSphere(&pl->pos, &self->pos, r + pl->radius)) {
                Effect_SpawnId(0xc8, &self->pos);
            }
        }
    }
    self->unk_ce++;
}

void Ov003ActVt_021f9834_Init(Ov003ActExHome *self) {
    ActorEx_Init(self);
    ResSet_SetFile(&self->res, data_ov003_021f995c, 1, 1, 1, 0);
    self->res.unk_00 = 0;
    self->homePos.x = self->pos.x;
    self->homePos.y = self->pos.y;
    self->homePos.z = self->pos.z;
    self->homeRot.x = self->rot.x;
    self->homeRot.y = self->rot.y;
    self->homeRot.z = self->rot.z;
}

BOOL Ov003ActVt_021f9834_IsReady(Ov003ActExHome *self) {
    BOOL r = ActorEx_IsReady(self);
    if (self->res.unk_00 >= 0 && !ResSet_UpdateLoad(&self->res)) {
        r = FALSE;
    }
    return r;
}

void Ov003ActVt_021f9834_Start(Ov003ActExHome *self) {
    AnimEventTable *tbl;
    Ov003Player *pl;
    ActorEx_Start(self);
    tbl = NULL;
    Model0218fe1c_SetRes(&self->mdl, &self->res, 0, 1);
    self->mdl.actor_id = self->id;
    if (self->res.unk_c0 != NULL) {
        tbl = &(*(Ov003AnimRes **)self->res.unk_c0)->tbl;
    }
    if (tbl != NULL) {
        self->mdl.evTable = tbl;
        if (tbl != NULL && tbl->is_ptr == 0) {
            self->mdl.evData = (s16 *)&tbl->entries[tbl->count];
        }
    }
    Model0218fe1c_SetAnim(&self->mdl, data_ov003_021f9967, 0x1000, 0);
    pl = ActorMgr_FindPlayer();
    if (pl == NULL || !pl->unk_16_2) {
        return;
    }
    if (self->targetObj == NULL) {
        void *mem = Heap_Alloc(0x5c);
        if (mem != NULL) {
            mem = Target_Init(mem);
        }
        self->targetObj = (ActorSub4c *)mem;
    }
    self->targetObj->unk_03 = 0xb;
    self->targetObj->type = 7;
    self->targetObj->unk_01 = 4;
    self->targetObj->unk_02 = 0;
}

}
