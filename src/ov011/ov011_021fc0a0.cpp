#include "ov011/ov011.h"

struct Ov011E40b {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 unk_02;
    s16 unk_04;
    u8 unk_06[0x2];
    Ov011E38 mover;
};

struct Ov011Mgr3 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 count;
    s32 unk_04;
    Ov011E40b *arr8;
    Ov011List *list;
    void *ent;
    u16 state;
    u16 timer;
    u64 flags;
    u8 unk_20[0x8];
    u8 unk_28[0xb8];
};

extern "C" {

void func_ov003_021d79d0(void *p);

extern void *data_02097e4c;
extern const Ov011Vec data_ov011_022072b4;

BOOL func_ov011_02201244(u8 *o);
void func_ov011_0220121c(u8 *o, s32 a);
void *__cxa_vec_new(u32 count, u32 size, u32 hdr, void *ctor, void *dtor);
void *func_ov011_021fb66c(void *self);
void *func_ov011_021fc0a0(void *self);
void func_ov011_02201f28(void *self, u16 id, const Ov011Vec *off, s16 c, s16 d, s16 e);
void func_ov011_02202464(void *self);
void func_02049f44(void *a, s32 b, Ov011Vec *c, s32 d);

static inline u8 *Ov011_Find(u16 id) {
    return data_ov000_021ccd68 == NULL ? NULL : (u8 *)func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline BOOL Ov011_NodeOk(Ov011Node *p) {
    if (p != NULL) {
        u8 *o = Ov011_Find(p->id);
        if (o != NULL && func_ov011_02201244(o)) {
            return TRUE;
        }
    }
    return FALSE;
}

void func_ov011_021fbe08(Ov011Mgr3 *self) {
    Ov011Node *head = self->list->head;
    u8 *actor = (u8 *)self->list->actor;
    switch (self->state) {
    case 0: {
        Ov011Node *p;
        s32 n = 0;
        s16 cnt;
        s32 i;
        u8 *a;
        Ov011Vec v;
        Ov011Vec w;
        for (p = head; p != NULL; p = p->next) {
            if (Ov011_NodeOk(p) == TRUE) {
                n++;
            }
        }
        cnt = n;
        self->count = cnt;
        self->arr8 = (Ov011E40b *)__cxa_vec_new(self->count, 0x40, 8, (void *)func_ov011_021fc0a0, (void *)func_ov011_021fb66c);
        i = 0;
        for (p = head; p != NULL; p = p->next) {
            u8 *o = Ov011_Find(p->id);
            if (func_ov011_02201244(o)) {
                u16 id = FLD(u16, o, 0xc);
                Ov011E40b *e = &self->arr8[i];
                e->b0 = 0;
                e->b1 = 0;
                e->unk_02 = id;
                e->unk_04 = 0;
                e->mover.v08();
                func_ov011_0220121c(o, 0);
                i++;
            }
        }
        *(Ov011Blk12 *)&v = *(const Ov011Blk12 *)&data_ov011_022072b4;
        a = (u8 *)self->list->actor;
        func_ov011_02201f28(self->unk_28, FLD(u16, a, 0xc), &v, cnt, 0x1000, 0x2333);
        func_ov011_02202464(self->unk_28);
        w.x = FLD(s32, a, 0x70);
        w.y = FLD(s32, a, 0x74);
        w.z = FLD(s32, a, 0x78);
        func_02049f44(data_02097e4c, 0x44, &w, 0);
        self->state = 1;
        break;
    }
    case 1: {
        Ov011Node *p;
        long x;
        long y;
        long z;
        self->timer++;
        if (self->timer >= 0x32) {
            self->flags |= 0x10;
        }
        x = FLD(s32, actor, 0x70);
        y = FLD(s32, actor, 0x74);
        z = FLD(s32, actor, 0x78);
        for (p = head; p != NULL; p = p->next) {
            u8 *o = Ov011_Find(p->id);
            if (func_ov011_02201244(o)) {
                FLD(s32, o, 0x70) = x;
                FLD(s32, o, 0x74) = y + 0x6800;
                FLD(s32, o, 0x78) = z;
            }
        }
        break;
    }
    }
}

#pragma force_active on
void *func_ov011_021fc0a0(void *self) {
    func_ov003_021d79d0((u8 *)self + 8);
    return self;
}
#pragma force_active reset
}
