#include "types.h"

typedef struct {
    u8 unk_00[0xa2];
    u8 active : 1;
} Ov003Unit;

typedef struct {
    u8 unk_00[0x22];
    u16 enable : 1;
    u16 visible : 1;
} Ov003MvPart;

typedef struct {
    u8 unk_00[0x1a];
    s16 mode;
    u8 unk_1c[4];
    u16 unitId;
    u8 unk_22[0x1e];
    void *work;
    Ov003MvPart *part;
} Ov003Mover2;

struct Ov003Vec {
    s32 x, y, z;
};

struct Ov003GtRot {
    u16 x, y, z;
};

struct Ov003GtWork {
    u16 state;
    u16 timer;
};

struct Ov003GtWork2 {
    u8 unk_00[0x13];
    u8 kind;
};

struct Ov003GtModel {
    void *res;
    u8 unk_04[0xb2];
    u16 unk_b6;
    u16 unk_b8;
    u16 unk_ba;
    u16 unk_bc;
    u8 unk_be[2];
    u8 unk_c0;
    u8 unk_c1;
    u16 unk_c2_0 : 1;
    u16 unk_c2_1 : 1;
};

struct Ov003GtLink {
    u8 unk_00[8];
    u16 a;
    u16 b;
};

struct Ov003GtSub {
    u8 unk_00[0xe];
    u16 type;
};

struct Ov003GtObj {
    u8 unk_00[0xc];
    u16 id;
    u8 unk_0e[0x32];
    Ov003GtWork2 *work;
    u8 unk_44[8];
    void *sub;
};

struct Ov003GtPlayer {
    u8 unk_00[0x50];
    u16 *input;
    u8 unk_54[0x1c];
    Ov003Vec pos;
    u8 unk_7c[0xaa6];
    u16 unk_b22_0 : 6;
    u16 mode : 3;
    u32 unk_b24_0 : 5;
    u32 state : 2;
};

struct Ov003Game54 {
    s32 state;
    u8 unk_04[0x8c];
    s32 unk_90;
    s32 unk_94;
};

struct Ov003Gate {
    u8 unk_00[0x18];
    s16 count;
    s16 max;
    u8 unk_1c[0x1c];
    Ov003GtModel *model;
    u8 unk_3c[4];
    Ov003GtWork *work;
    u8 unk_44[8];
    Ov003GtLink *link;
    u8 unk_50[0x20];
    Ov003Vec pos;
    Ov003GtRot rot;
    u8 unk_82[0x1a];
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
    s32 unk_a8;
    u8 unk_ac[0x22];
    u16 lastId;
    u16 flash;
};

extern "C" {

extern void *data_ov000_021ccd64;
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_02194758(void *self);
extern Ov003Unit *func_ov000_0218bd5c(void *mgr, u16 id);

void func_ov003_021e8eb0(Ov003Mover2 *self) {
    Ov003Unit *u = func_ov000_0218bd5c(data_ov000_021ccd64, self->unitId);
    Ov003MvPart *p;
    if (u != NULL) {
        u->active = 0;
    }
    func_ov000_02194758(self);
    if (self->mode == 0) {
        self->mode = 3;
    }
    p = self->part;
    p->enable = 0;
    p->visible = 0;
    func_ov000_02198360(self->work, 6, 0);
}

extern const char *const data_ov003_021f6a80[];
extern void *data_02097e4c;
extern Ov003Game54 *data_ov000_021ccd54;
extern void *data_ov000_021ccd68;
extern const Ov003Vec data_ov003_021f6af0;
extern const Ov003Vec data_ov003_021f6b08;
extern Ov003GtPlayer *func_ov000_0219bf90(void);
extern void func_ov000_02190cb0(void *p, const char *name, s32 a, s32 b);
extern void func_ov000_02191690(void *p);
extern void func_ov000_02191708(void *p);
extern void func_ov000_02191318(void *p, s32 a);
extern void func_ov000_0218ffdc(void *anim, void *res, s32 a, s32 b);
extern s32 VEC_Distance(const Ov003Vec *a, const Ov003Vec *b);
extern void VEC_Add(const Ov003Vec *a, const Ov003Vec *b, Ov003Vec *out);
extern void func_02049f44(void *mgr, s32 id, Ov003Vec *pos, s32 a);
extern void func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, const void *f, const void *g, s32 h, s32 i, s32 j, s32 k);
extern void *func_ov000_0218e6d0(void *mgr, s32 a, s32 b);
extern s32 func_ov000_0219a7bc(void *self, s32 a, Ov003Vec *pos, s32 r, s32 b, Ov003GtObj **list);
extern Ov003GtSub *func_ov000_02199ba0(void *p);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov000_0218d46c(Ov003GtObj *o, u16 id, s32 a);

static inline BOOL Ov003Game_IsBusy(Ov003Game54 *g) {
    return g->unk_90 != g->unk_94;
}

static inline BOOL Ov003Game_IsIdle(Ov003Game54 *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    Ov003Game54 *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}

static inline void *Ov003_FindActor(s32 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e6d0(data_ov000_021ccd68, 0x5000, id);
}

static inline Ov003GtSub *Ov003GtObj_GetSub(Ov003GtObj *o) {
    Ov003GtSub *s = NULL;
    if (o->sub != NULL) {
        s = func_ov000_02199ba0(o->sub);
    }
    return s;
}

static inline s32 Ov003GtObj_GetKind(Ov003GtObj *o) {
    return o->work != NULL ? o->work->kind : 0;
}

static inline void Ov003Gate_Anim(Ov003Gate *self, s32 a) {
    Ov003GtModel *m = self->model;
    if (m->unk_c0 != a) {
        func_ov000_0218ffdc(m, m->res, a, m->unk_c2_1 ? 1 : 0);
    }
}

void func_ov003_021e8f24(Ov003Gate *self) {
    Ov003GtPlayer *pl = func_ov000_0219bf90();
    switch (self->work->state) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov003_021f6a80[0], 0x1000, 0);
        func_ov000_02191690(self->model);
        self->lastId = 0;
        self->flash = 0;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->work->state++;
    case 1: {
        Ov003Vec p;
        p.x = pl->pos.x;
        p.y = pl->pos.y;
        p.z = pl->pos.z;
        if (VEC_Distance(&self->pos, &p) > 0x8000) {
            return;
        }
        func_ov000_02191708(self->model);
        func_02049f44(data_02097e4c, 0x46, &self->pos, 0);
        self->work->state++;
        break;
    }
    case 2: {
        Ov003Vec v;
        Ov003GtObj *list[0x20];
        s32 n;
        s32 i;
        pl = func_ov000_0219bf90();
        if (*pl->input != 0 && Ov003_GameIdle()) {
            Ov003GtRot r;
            s32 h = 0x1400;
            r.x = self->rot.x;
            r.y = self->rot.y;
            r.z = self->rot.z;
            r.x += 0x2d80;
            if (pl->mode == 4) {
                h += 0x800;
            }
            func_ov000_0219aae8(self, self, self->link->a, self->link->b, 2, &data_ov003_021f6b08, &r, 0x2000, h, 100, 0x1000);
        }
        if (Ov003_FindActor(0x504a) == NULL && Ov003_FindActor(0x504b) == NULL) {
            func_ov000_02198360(self->work, 0x15, 0);
            return;
        }
        VEC_Add(&data_ov003_021f6af0, &self->pos, &v);
        n = func_ov000_0219a7bc(self, 0x10, &v, 0x299a, 0, list);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                Ov003GtSub *sub;
                if (list[i] == NULL) {
                    continue;
                }
                sub = Ov003GtObj_GetSub(list[i]);
                if (sub == NULL || self->lastId == list[i]->id) {
                    continue;
                }
                if (sub->type != 0x1000) {
                    continue;
                }
                if (Ov003GtObj_GetKind(list[i]) != 0xb) {
                    continue;
                }
                if (func_ov000_0219bf90()->state != 0) {
                    continue;
                }
                self->lastId = list[i]->id;
                func_ov000_0218996c(10, 10);
                func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
                s16 c = self->count + 1;
                self->count = c;
                if (self->max <= c) {
                    func_ov000_02198360(self->work, 0x15, 0);
                } else {
                    Ov003Gate_Anim(self, 1);
                    func_ov000_02190cb0(self->model, data_ov003_021f6a80[0], 0, 1);
                    func_ov000_02191318(self->model, -1);
                    {
                        Ov003GtModel *m = self->model;
                        m->unk_b6 = 0x14bf;
                        m->unk_b8 = 0x739f;
                        m->unk_ba = 0xb;
                        m->unk_bc = 10;
                    }
                    self->flash = 10;
                }
                func_ov000_0218d46c(list[i], self->lastId, 0x15);
                break;
            }
        }
        if (self->flash == 0) {
            return;
        }
        if (self->flash == 1) {
            Ov003Gate_Anim(self, 0);
            func_ov000_02190cb0(self->model, data_ov003_021f6a80[0], 0, 1);
            func_ov000_02191318(self->model, -1);
        }
        self->flash--;
        break;
    }
    }
}

}
