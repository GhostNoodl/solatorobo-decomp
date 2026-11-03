#include "ov011/ov011.h"
#include "Main/Res/ResArc.h"

extern "C" {

extern char Ov011Act7da4_vtbl[];
extern char data_ov011_02207c35[];
struct Ov011PhotoCfg {
    void *photo;
    void *photoB;
    void *photoA;
    char photo1[8];
    char photo0[8];
};
extern Ov011PhotoCfg data_ov011_02207be0;
extern void *const data_ov011_02207500[2];
void *const data_ov011_02207500[2] = { data_ov011_02207be0.photo1, data_ov011_02207be0.photo0 };
Ov011PhotoCfg data_ov011_02207be0 = {
    data_ov011_02207500[0], data_ov011_02207500[1], data_ov011_02207500[0], "photo01", "photo00",
};
ResSet *ResSet_ReleaseAll(ResSet *p);
BOOL ResMgr_IsIdle(void);
BOOL Actor_IsReady(void *self);
void ActorMgr_BroadcastKind(void *mgr, u16 id, s32 c);

static inline void Ov011_FreeTwl(Twl0214b570 **slot) {
    void *saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (*slot != NULL) {
        Twl0214b570 *p = *slot;
        if (p != NULL) {
            Twl0214b570_Dtor(p);
            Heap_Free(p);
        }
        *slot = NULL;
    }
    gSysState->cur = saved;
}

Ov003Actor *Ov011Act7da4_Dtor(Ov011Act7da4 *self) {
    *(void **)self = Ov011Act7da4_vtbl;
    Ov011_FreeTwl(&self->unk_364);
    Ov011_FreeTwl(&self->unk_368);
    ResMgr_ReleaseByName(gResMgr, data_ov011_02207c35, 7, 0);
    __cxa_vec_cleanup(self->unk_f4, 2, 0x138, (void *)ResSet_ReleaseAll);
    Ov003Actor_DtorBase(self);
    return self;
}

Ov003Actor *Ov011Act7da4_DtorDelete(Ov011Act7da4 *self) {
    *(void **)self = Ov011Act7da4_vtbl;
    Ov011_FreeTwl(&self->unk_364);
    Ov011_FreeTwl(&self->unk_368);
    ResMgr_ReleaseByName(gResMgr, data_ov011_02207c35, 7, 0);
    __cxa_vec_cleanup(self->unk_f4, 2, 0x138, (void *)ResSet_ReleaseAll);
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

void Ov011Act7da4_Init(Ov011Act7da4 *self) {
    Ov003Actor_Init(self);
    ResMgr_Load(data_ov011_02207c35, 7, 0);
    if (OS_IsRunOnTwl()) {
        Twl0214b570 *p = (Twl0214b570 *)Heap_Alloc(sizeof(Twl0214b570));
        if (p != NULL) {
            p = Twl0214b570_Init(p);
        }
        self->unk_364 = p;
        Twl0214b570_Start(p, (const char *)data_ov011_02207500[1]);
        p = (Twl0214b570 *)Heap_Alloc(sizeof(Twl0214b570));
        if (p != NULL) {
            p = Twl0214b570_Init(p);
        }
        self->unk_368 = p;
        Twl0214b570_Start(p, (const char *)data_ov011_02207500[0]);
    }
    self->unk_398 = NULL;
    self->unk_394 = 0;
}

BOOL Ov011Act7da4_IsReady(Ov011Act7da4 *self) {
    BOOL r = Actor_IsReady(self);
    r = (r & ResMgr_IsLoaded(data_ov011_02207c35, 7)) ? TRUE : FALSE;
    if (self->unk_364 != NULL && self->unk_394 == 0) {
        if (Twl0214b570_GetStatus(self->unk_364) == 2) {
            r = FALSE;
            self->unk_394 = 1;
        }
        if (r && !Twl0214b570_IsDone(self->unk_364) && r && ResMgr_IsIdle()) {
            Twl0214b570_Poll(self->unk_364);
            r = FALSE;
        }
    }
    if (self->unk_368 != NULL && self->unk_394 == 0) {
        if (Twl0214b570_GetStatus(self->unk_368) == 2) {
            r = FALSE;
            self->unk_394 = 1;
        }
        if (r && !Twl0214b570_IsDone(self->unk_368) && r && ResMgr_IsIdle()) {
            Twl0214b570_Poll(self->unk_368);
            r = FALSE;
        }
    }
    return r;
}

void Ov011Act7da4_Start(Ov011Act7da4 *self) {
    Ov003Actor_Start(self);
    {
        void *saved = gSysState->cur;
        gSysState->cur = gSysState->heapHi;
        if (self->hit != NULL) {
            void *p = self->hit;
            if (p != NULL) {
                HitSphere_Unlink_0203f2b8(p);
                Heap_Free(p);
            }
            self->hit = NULL;
        }
        gSysState->cur = saved;
    }
    Ov011_VecSet(&self->unk_44->unk_0c, 0, 0x5000, 0x7800);
    {
        ActorSub44 *s = self->unk_44;
        s->unk_22_0 = 0;
        s->unk_22_1 = 0;
    }
    self->model->visible = 0;
    self->unk_ea_8 = 1;
    self->unk_ea_9 = 1;
    self->unk_ea_6 = 1;
    self->unk_36c = 0xffff;
    ActorMgr_BroadcastKind(gActorMgr, 0x400c, 0x15);
}

}
