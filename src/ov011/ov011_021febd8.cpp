#include "ov011/ov011.h"

extern "C" {

void __cxa_vec_delete(void *arr, u32 size, u32 hdr, void *dtor);
void Ov011Fx_Stop(void *p);
void Ov011Chr_Reset_0220205c(void *p);
void Ov011Mov_Stop_02202fbc(void *p);
void Ov011Mgr_Reset(Ov011Mgr *p);

void func_ov011_021febd8(Ov011Scene *self) {
    Ov011Node *n;
    if (self->seq.st != 0) {
        return;
    }
    Ov011Fx_Stop(&self->fx);
    self->mgr2.b1 = 0;
    self->mgr2.count = 0;
    self->mgr2.unk_04 = -1;
    {
        void *saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->heapHi;
        if (self->mgr2.arr8 != NULL) {
            __cxa_vec_delete(self->mgr2.arr8, 0x40, 8, Ov011E40_Dtor);
            self->mgr2.arr8 = NULL;
        }
        data_02097dd0->cur = saved;
    }
    Ov003ActorSub40_ForceState(&self->mgr2.state, 0);
    Ov011Chr_Reset_0220205c(self->mgr2.unk_28);
    Ov011Mov_Stop_02202fbc(&self->mgr2.mov);
    self->s1b4.b1 = 0;
    self->s1b4.id = 0xffff;
    self->s1b4.ent = NULL;
    Ov003ActorSub40_ForceState(&self->s1b4.seq, 1);
    Ov011Mgr_Reset(&self->mgr);
    if (self->ent.active) {
        Ov011PNode *p = self->ent.nodes;
        while (p != NULL) {
            Ov011PNode *next = p->next;
            if (p != NULL) {
                Heap_Free(p);
            }
            p = next;
        }
        self->ent.nodes = NULL;
    }
    for (n = self->head; n != NULL; n = n->next) {
        Actor *a = Ov011_FindActor(n->id);
        if (a != NULL) {
            func_ov000_0218d46c((StageObj3D *)a, 0xffff, 0x15);
        }
    }
    self->b2 = 1;
    self->seq.st = 1;
}


extern u8 data_ov011_022078f0[];

u32 Ov011TwB_IsActive(void *p);
void Ov011Chr_Draw(void *p);
void Ov011Fx_Draw(void *p);
extern s32 data_ov011_02207258[];

#pragma force_active on
Ov011SceneActor *Ov011SceneActor_Ctor(Ov011SceneActor *self) {
    Ov003Actor_Ctor(self);
    *(void **)self = data_ov011_022078f0;
    self->unk_f0_0 = 0;
    self->unk_f0_1 = 0;
    self->unk_f2 = 0;
    self->unk_f4.x = data_ov011_02207258[8];
    self->unk_f4.y = data_ov011_02207258[9];
    self->unk_f4.z = data_ov011_02207258[10];
    self->scene = NULL;
    self->unk_104 = NULL;
    self->unk_108 = NULL;
    self->unk_10c = NULL;
    return self;
}

void *Ov011SceneActor_Dtor(Ov011SceneActor *self) {
    *(void **)self = data_ov011_022078f0;
    func_ov011_0220068c(self);
    Ov003Actor_DtorBase(self);
    return self;
}

void *Ov011SceneActor_DtorDelete(Ov011SceneActor *self) {
    *(void **)self = data_ov011_022078f0;
    func_ov011_0220068c(self);
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

s32 Ov011SceneActor_Draw(Ov011SceneActor *self) {
    VecFx32 save = self->pos;
    s32 old;
    s32 ret;
    Ov011Scene *c;
    if (self->unk_104 != NULL && Ov011TwB_IsActive(&self->unk_104->tw)) {
        self->pos.y += ((s32 *)self->unk_104->tw.v10())[1];
    }
    old = self->unk_3c->unk_14;
    self->unk_3c->unk_14 = old >> 1;
    ret = Ov003Actor_Draw(self);
    self->unk_3c->unk_14 = old;
    c = self->scene;
    if (c->b0) {
        if (c->mgr2.b0 && c->mgr2.b1) {
            Ov011Chr_Draw(c->mgr2.unk_28);
        }
        Ov011Fx_Draw(&c->fx);
    }
    self->pos.x = save.x;
    self->pos.y = save.y;
    self->pos.z = save.z;
    return ret;
}
#pragma force_active reset
}
