#include "ov011/ov011.h"

struct Ov011E40 {
    u8 b0 : 1;
    u8 b1 : 7;
    u8 unk_01[0x3];
    s16 unk_04;
    u8 unk_06[0x2];
    Ov011E38 mover;
};

class Ov011Mgr2 {
public:
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    u16 count;
    s32 unk_04;
    Ov011E40 *arr8;
    Ov011List *list;
    Ov011Ent *ent;
    u16 state;
    u16 timer;
    u8 unk_18[0xf];
    u8 unk_27;
    u8 unk_28[0xb8];
    u8 unk_e0[0x4];
};

typedef void (Ov011Mgr2::*Ov011Mgr2Fn)();

struct Ov011Mgr2Entry {
    s32 key;
    Ov011Mgr2Fn fn;
};

static inline s32 Ov011Ent_GetA(Ov011Ent *e) {
    if (e->b0) {
        return e->unk_24;
    }
    return 0;
}

static inline s32 Ov011Ent_GetB(Ov011Ent *e) {
    if (e->b0) {
        return e->unk_0c;
    }
    return 0;
}

static inline u16 Ov011Ent_GetC(Ov011Ent *e) {
    if (e->b0) {
        return e->unk_18;
    }
    return 0;
}

static inline void Ov011Ent_LerpA(Ov011Ent *e, s32 from, s32 to, s32 frames) {
    if (e->b0) {
        e->b4 = 1;
        Ov011_SetLerp(&e->unk_24, from, to, frames);
    }
}

static inline void Ov011Ent_LerpB(Ov011Ent *e, s32 from, s32 to, s32 frames) {
    if (e->b0) {
        e->b2 = 1;
        Ov011_SetLerp(&e->unk_0c, from, to, frames);
    }
}

static inline void Ov011Ent_LerpC(Ov011Ent *e, s32 from, s32 to, s32 frames) {
    if (e->b0) {
        e->b3 = 1;
        Ov011_SetLerp(&e->unk_18, from, to, frames);
    }
}

static inline void Ov011Ent_RestoreA(Ov011Ent *e, s32 to, s32 frames) {
    if (e->b0) {
        Ov011Ent_LerpA(e, e->unk_24, to, frames);
    }
}

static inline void Ov011Ent_RestoreB(Ov011Ent *e, s32 to, s32 frames) {
    if (e->b0) {
        Ov011Ent_LerpB(e, e->unk_0c, to, frames);
    }
}

static inline void Ov011Ent_RestoreC(Ov011Ent *e, s32 to, s32 frames) {
    if (e->b0) {
        Ov011Ent_LerpC(e, (u16)e->unk_18, to, frames);
    }
}

extern "C" {

extern const Ov011Mgr2Entry data_ov011_022072d8[];
void func_ov003_021d79ec(void *p);
void __cxa_vec_delete(void *arr, u32 size, u32 hdr, void *dtor);
void func_ov003_021da40c(void *p);
void func_ov003_021da48c(void *p, s32 a);
void func_ov011_0220205c(void *p);
void func_ov011_02202130(void *p);
void func_ov011_02202fbc(void *p);
void func_ov011_02202ff0(void *p);

void *func_ov011_021fb66c(Ov011E40 *self) {
    func_ov003_021d79ec(&self->mover);
    return self;
}

static inline void Ov011Mgr2_Reset(Ov011Mgr2 *self) {
    u32 saved;
    self->b1 = 0;
    self->count = 0;
    self->unk_04 = -1;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->arr8 != NULL) {
        __cxa_vec_delete(self->arr8, 0x40, 8, func_ov011_021fb66c);
        self->arr8 = NULL;
    }
    data_02097dd0->cur = saved;
    func_ov003_021da48c(&self->state, 0);
    func_ov011_0220205c(self->unk_28);
    func_ov011_02202fbc(self->unk_e0);
}

void func_ov011_021fb684(Ov011Mgr2 *self) {
    u32 i;
    s32 j;
    u8 key;
    if (!self->b0) {
        return;
    }
    if (!self->b1) {
        return;
    }
    if (self->list->head == NULL) {
        Ov011Mgr2_Reset(self);
        self->b1 = 0;
        if (self->ent == NULL) {
            return;
        }
        Ov011Ent_RestoreA(self->ent, 0x2000, 1);
        Ov011Ent_RestoreB(self->ent, 0x3333, 1);
        Ov011Ent_RestoreC(self->ent, 0x71c, 1);
        return;
    }
    key = self->unk_27;
    for (i = 0; i < 4; i++) {
        if (key == data_ov011_022072d8[i].key && *(s32 *)&data_ov011_022072d8[i].fn != 0) {
            (self->*data_ov011_022072d8[i].fn)();
            break;
        }
    }
    func_ov003_021da40c(&self->state);
    func_ov011_02202130(self->unk_28);
    func_ov011_02202ff0(self->unk_e0);
    for (j = 0; j < self->count; j++) {
        Ov011E40 *p = &self->arr8[j];
        if (p->b0) {
            p->unk_04++;
        }
        p->mover.v0c();
    }
}

void func_ov011_021fb8d4(Ov011Mgr2 *self, s32 a, Ov011List *list, Ov011Ent *ent) {
    if (!self->b0) {
        return;
    }
    self->b1 = 1;
    self->unk_04 = a;
    self->list = list;
    self->ent = ent;
    if (a == 0) {
        func_ov003_021da48c(&self->state, 3);
    } else if (a == 1) {
        func_ov003_021da48c(&self->state, 2);
    }
}

void func_ov011_021fb92c(Ov011Mgr2 *self) {
    Ov011Mgr2_Reset(self);
}

}
