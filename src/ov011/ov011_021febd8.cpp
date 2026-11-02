#include "ov011/ov011.h"

extern "C" {

void __cxa_vec_delete(void *arr, u32 size, u32 hdr, void *dtor);
void *func_ov011_021fb66c(void *self);
void func_ov011_02201b28(void *p);
void func_ov011_0220205c(void *p);
void func_ov011_02202fbc(void *p);
void func_ov011_021fab74(void *p);
void func_ov000_0218d46c(void *o, u16 id, s32 c);

void func_ov011_021febd8(Ov011Scene *self) {
    Ov011Node *n;
    if (self->seq.state != 0) {
        return;
    }
    func_ov011_02201b28(&self->fx);
    self->mgr2.b1 = 0;
    self->mgr2.count = 0;
    self->mgr2.unk_04 = -1;
    {
        u32 saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (self->mgr2.arr8 != NULL) {
            __cxa_vec_delete(self->mgr2.arr8, 0x40, 8, func_ov011_021fb66c);
            self->mgr2.arr8 = NULL;
        }
        data_02097dd0->cur = saved;
    }
    func_ov003_021da48c(&self->mgr2.state, 0);
    func_ov011_0220205c(self->mgr2.unk_28);
    func_ov011_02202fbc(&self->mgr2.mov);
    self->s1b4.b1 = 0;
    self->s1b4.id = 0xffff;
    self->s1b4.ent = NULL;
    func_ov003_021da48c(&self->s1b4.seq, 1);
    func_ov011_021fab74(&self->mgr);
    if (self->ent.b0) {
        Ov011PNode *p = self->ent.unk_04;
        while (p != NULL) {
            Ov011PNode *next = p->next;
            if (p != NULL) {
                func_0203de1c(p);
            }
            p = next;
        }
        self->ent.unk_04 = NULL;
    }
    for (n = self->head; n != NULL; n = n->next) {
        Ov011Obj *a = Ov011_FindActor(n->id);
        if (a != NULL) {
            func_ov000_0218d46c(a, 0xffff, 0x15);
        }
    }
    self->b2 = 1;
    self->seq.state = 1;
}


extern u8 data_ov011_022078f0[];
void func_ov011_0220068c(void *self);
void *func_ov003_021d0edc(void *self);

void func_ov003_021d0c1c(void *self);
u32 func_ov011_02202ecc(void *p);
void func_ov011_02202260(void *p);
void func_ov011_0220192c(void *p);
u16 func_ov003_021d16cc(void *p);
extern s32 data_ov011_02207258[];

#pragma force_active on
Ov011SceneActor *Ov011SceneActor_Ctor(Ov011SceneActor *self) {
    func_ov003_021d0c1c(self);
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

void *Ov011SceneActor_Dtor(void *self) {
    *(void **)self = data_ov011_022078f0;
    func_ov011_0220068c(self);
    func_ov003_021d0edc(self);
    return self;
}

void *Ov011SceneActor_DtorDelete(void *self) {
    *(void **)self = data_ov011_022078f0;
    func_ov011_0220068c(self);
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

s32 Ov011SceneActor_Draw(Ov011SceneActor *self) {
    Ov011Vec save = self->pos;
    s32 old;
    s32 ret;
    Ov011Scene *c;
    if (self->unk_104 != NULL && func_ov011_02202ecc(&self->unk_104->tw)) {
        self->pos.y += ((s32 *)self->unk_104->tw.v10())[1];
    }
    old = self->unk_3c->unk_14;
    self->unk_3c->unk_14 = old >> 1;
    ret = func_ov003_021d16cc(self);
    self->unk_3c->unk_14 = old;
    c = self->scene;
    if (c->b0) {
        if (c->mgr2.b0 && c->mgr2.b1) {
            func_ov011_02202260(c->mgr2.unk_28);
        }
        func_ov011_0220192c(&c->fx);
    }
    self->pos.x = save.x;
    self->pos.y = save.y;
    self->pos.z = save.z;
    return ret;
}
#pragma force_active reset
}
