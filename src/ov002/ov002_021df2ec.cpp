#pragma opt_lifetimes on
#include "ov002/ov002.h"

namespace K { extern "C" const char data_ov002_021efdea[]; }
namespace K { extern "C" const char data_ov002_021efdf6[]; }
namespace K { extern "C" const char data_ov002_021efe02[]; }
namespace K { extern "C" const char data_ov002_021efe0e[]; }
namespace K { extern "C" const char data_ov002_021efe1a[]; }
namespace K { extern "C" const char data_ov002_021efe26[]; }

extern "C" {


void *ResMgr_FindArcType2(const char *file, const char *name);

static inline Ov002Cell *ov002_GetCell(Obj021efe6c *w, Vec2 *pos) {
    s32 y = pos->y;
    s32 x = pos->x;
    Obj021efe4c *q = w->field;
    Ov002Cell *base;
    if (q == NULL || (base = w->cells) == NULL) {
        return NULL;
    }
    return &base[y * q->map->h + x];
}

static inline void ov002_Cursor_SetMode(Obj021efe8c *c) {
    switch (c->mode) {
    case 0:
        { const char *s = ((char *)K::data_ov002_021efdea);
        c->mdl.arc = K::data_ov002_021efdf6;
        c->mdl.name = s;
        c->mdl.anmName = s; }
        c->unk_84 = 0x29;
        break;
    case 1:
        { const char *s = ((char *)K::data_ov002_021efe02);
        c->mdl.arc = K::data_ov002_021efdf6;
        c->mdl.name = s;
        c->mdl.anmName = s; }
        c->unk_84 = 0xcd;
        break;
    }
    Ov002Mdl021efe3c_Load(&c->mdl);
}


#ifdef NONMATCHING
void Obj021eff30_Enter(Obj021eff30 *self, Obj021eff50 *own);
// Status (round auA): demoted in the honesty audit. The match declared the locals y, x, id and w as unused parameters
// past (self, own); as locals the registers differ. This file is the function's whole .text, so it has no delinks
// entry. The score is in docs/UNMATCHED.md;
// the default build takes this function from the dsd gap. History: docs/MATCHING.md round auA.
void Obj021eff30_Enter(Obj021eff30 *self, Obj021eff50 *own) {
    s32 y;
    s32 x;
    u16 id;
    Obj021efe6c *w;
    s32 kind;
    Obj021efe8c *c;
    Obj021efe9c *o;
    Ov002Shape *map;
    MtxFx22 r;
    Obj021efe5c *m;
    self->owner = own;
    kind = own->unk_1c;
    w = own->board;
    self->unk_08 = kind;
    if (kind == 10) {
        self->unk_10 = (Obj021efe9c *)ov002_GetCell(w, (Vec2 *)&own->unk_28)->obj;
        Obj021efe6c_RemovePiece(w, self->unk_10, 0);
        o = self->unk_10;
        if (o->unk_a4 == 0 && o->unk_ac == 2) {
            o->unk_a4 = 5;
            o->unk_a8 = 5;
            o->unk_ac = 7;
        }
        o = self->unk_10;
        self->unk_24 = o->unk_54;
        self->unk_28 = o->unk_58;
        self->unk_2c = o->shape.rot;
    } else {
        id = own->unk_30;
        Param_GetEntry(id);
        x = own->unk_28;
        y = own->unk_2c;
        o = (Obj021efe9c *)Heap_Alloc(sizeof(Obj021efe9c));
        if (o != NULL) {
            *(VFunc **)o = Ov002Vt_021efeb8_vtbl;
            Obj021efeb8_Init(o);
            *(VFunc **)o = Ov002Vt_021efe9c_vtbl;
            Obj021efe9c_Init(o);
        }
        self->unk_10 = o;
        o->unk_48 = id;
        self->unk_10->vfunc_08();
        map = w->field->map;
        {
            s32 mw = map->ox;
            s32 mh = map->oy;
            o = self->unk_10;
            o->unk_64 = mw;
            o->unk_68 = mh;
        }
        o = self->unk_10;
        o->unk_54 = (u16)x;
        o->unk_58 = (u16)y;
        Ov002_CellToPos(&o->trans.x, &o->unk_54, &o->unk_64);
        o = self->unk_10;
        o->shape.rot = 0;
        o->unk_10 = 0;
        o->unk_12 = 0;
        o->unk_14 = 0;
        MTX_Identity33_(&o->rot);
        o = self->unk_10;
        map = w->field->map;
        if (o->unk_ac != 9 && o->unk_a4 == 0) {
            Obj021efe9c_ClampToBoard(o, map);
            Ov002_CellToPos(&o->unk_b0.x, &o->unk_54, &o->unk_64);
            o->unk_b0.y = 0x400;
            o->unk_bc.x = 0xb33;
            o->unk_bc.z = 0;
            o->unk_bc.y = 0x400;
            o->unk_a4 = 0x14;
            o->unk_a8 = 0x14;
            o->unk_ac = 9;
        }
        w->unk_08[(u16)(id & 0xfff)]--;
        self->unk_24 = x;
        self->unk_28 = y;
        self->unk_2c = 0;
    }
    {
        c = (Obj021efe8c *)Heap_Alloc(sizeof(Obj021efe8c));
        if (c != NULL) {
            *(VFunc **)c = Ov002Vt_021efe8c_vtbl;
            Ov002Vt_021efe3c_Ctor(&c->mdl);
            c->unk_78 = 0;
            c->unk_74 = 0;
            c->unk_80 = 0;
            c->unk_7c = 0;
            c->unk_84 = 0;
            c->mode = 0;
            c->unk_8a = 0x7fff;
        }
        self->unk_14 = c;
        {
            Ov002Shape *map = self->owner->board->field->map;
            s32 mw = map->ox;
            s32 mh = map->oy;
            c->unk_7c = mw;
            c->unk_80 = mh;
        }
    }
    self->unk_14->mode = 1;
    ov002_Cursor_SetMode(self->unk_14);
    m = (Obj021efe5c *)Heap_Alloc(sizeof(Obj021efe5c));
    if (m != NULL) {
        *(VFunc **)m = Ov002Vt_021efe5c_vtbl;
        Ov002Vt_021efe3c_Ctor(&m->mdl);
        PlttRes_Init_02041218(&m->model.pltt);
        TexObj_Init(&m->model, NULL, 0);
        m->unk_1d4 = 0;
        m->pos.x = 0;
        m->pos.y = 0;
        m->pos.z = 0;
    }
    self->unk_0c = m;
    m->mdl.arc = K::data_ov002_021efdf6;
    m->mdl.name = K::data_ov002_021efe0e;
    m->mdl.anmName = K::data_ov002_021efe0e;
    Ov002Mdl021efe3c_Load(&m->mdl);
    {
        char *nm = ((char *)K::data_ov002_021efe1a);
        char *file = ((char *)K::data_ov002_021efe26);
        TexObj_Init(&m->model, nm, 0);
        STD_CopyString(m->model.name, file);
        TexObj_SetRes(&m->model, ResMgr_FindArcType2(file, nm));
    }
    m->model.flags |= 2;
    m->model.unk_150 = -0x2000;
    TexObj_SelectImage(&m->model, 0, 4);
    MTX_Identity22_(&m->model.mtx[0]);
    MTX_Rot22_(&r, FX_SINCOS(0xbff * 2), FX_SINCOS(0xbff * 2 + 1));
    MTX_Concat22(&r, &m->model.mtx[0], &m->model.mtx[0]);
    {
        Obj021efe5c *q = self->unk_0c;
        q->pos.x = 0xb33;
        q->pos.y = 0x23d;
        q->pos.z = 0;
    }
    {
        void *str = Param_Get(FIELD(((u8 *)self->unk_10), 0x48, u16));
        Obj021eff50 *t = self->owner;
        Obj0215bb14_SetText(((void *)t->unk_20), str);
        t->unk_20->vfunc_70();
    }
    {
        Obj021efe6c *b = self->owner->board;
        b->unk_74 = 7;
        b->unk_75 = 1;
    }
    {
        s32 px;
        s32 py;
        py = FIELD(((u8 *)self->unk_10), 0x58, s32);
        px = FIELD(((u8 *)self->unk_10), 0x54, s32);
        func_ov002_021e019c(self, px, py);
        self->unk_1c = px;
        self->unk_20 = py;
    }
    self->unk_18 = 0;
    self->owner = NULL;
}
#else
// Round fkA fakematch (docs/FAKEMATCHES.md). The honest draft is the NONMATCHING branch above.
// FAKEMATCH: y, x, id and w are locals declared as fake trailing parameters (the dispatcher passes self and
// own); all four are needed (round fkA subset test: 51-114 with any of them a local).
void Obj021eff30_Enter(Obj021eff30 *self, Obj021eff50 *own, s32 y, s32 x, u16 id, Obj021efe6c *w) {
    s32 kind;
    Obj021efe8c *c;
    Obj021efe9c *o;
    Ov002Shape *map;
    MtxFx22 r;
    Obj021efe5c *m;
    self->owner = own;
    kind = own->unk_1c;
    w = own->board;
    self->unk_08 = kind;
    if (kind == 10) {
        self->unk_10 = (Obj021efe9c *)ov002_GetCell(w, (Vec2 *)&own->unk_28)->obj;
        Obj021efe6c_RemovePiece(w, self->unk_10, 0);
        o = self->unk_10;
        if (o->unk_a4 == 0 && o->unk_ac == 2) {
            o->unk_a4 = 5;
            o->unk_a8 = 5;
            o->unk_ac = 7;
        }
        o = self->unk_10;
        self->unk_24 = o->unk_54;
        self->unk_28 = o->unk_58;
        self->unk_2c = o->shape.rot;
    } else {
        id = own->unk_30;
        Param_GetEntry(id);
        x = own->unk_28;
        y = own->unk_2c;
        o = (Obj021efe9c *)Heap_Alloc(sizeof(Obj021efe9c));
        if (o != NULL) {
            *(VFunc **)o = Ov002Vt_021efeb8_vtbl;
            Obj021efeb8_Init(o);
            *(VFunc **)o = Ov002Vt_021efe9c_vtbl;
            Obj021efe9c_Init(o);
        }
        self->unk_10 = o;
        o->unk_48 = id;
        self->unk_10->vfunc_08();
        map = w->field->map;
        {
            s32 mw = map->ox;
            s32 mh = map->oy;
            o = self->unk_10;
            o->unk_64 = mw;
            o->unk_68 = mh;
        }
        o = self->unk_10;
        o->unk_54 = (u16)x;
        o->unk_58 = (u16)y;
        Ov002_CellToPos(&o->trans.x, &o->unk_54, &o->unk_64);
        o = self->unk_10;
        o->shape.rot = 0;
        o->unk_10 = 0;
        o->unk_12 = 0;
        o->unk_14 = 0;
        MTX_Identity33_(&o->rot);
        o = self->unk_10;
        map = w->field->map;
        if (o->unk_ac != 9 && o->unk_a4 == 0) {
            Obj021efe9c_ClampToBoard(o, map);
            Ov002_CellToPos(&o->unk_b0.x, &o->unk_54, &o->unk_64);
            o->unk_b0.y = 0x400;
            o->unk_bc.x = 0xb33;
            o->unk_bc.z = 0;
            o->unk_bc.y = 0x400;
            o->unk_a4 = 0x14;
            o->unk_a8 = 0x14;
            o->unk_ac = 9;
        }
        w->unk_08[(u16)(id & 0xfff)]--;
        self->unk_24 = x;
        self->unk_28 = y;
        self->unk_2c = 0;
    }
    {
        c = (Obj021efe8c *)Heap_Alloc(sizeof(Obj021efe8c));
        if (c != NULL) {
            *(VFunc **)c = Ov002Vt_021efe8c_vtbl;
            Ov002Vt_021efe3c_Ctor(&c->mdl);
            c->unk_78 = 0;
            c->unk_74 = 0;
            c->unk_80 = 0;
            c->unk_7c = 0;
            c->unk_84 = 0;
            c->mode = 0;
            c->unk_8a = 0x7fff;
        }
        self->unk_14 = c;
        {
            Ov002Shape *map = self->owner->board->field->map;
            s32 mw = map->ox;
            s32 mh = map->oy;
            c->unk_7c = mw;
            c->unk_80 = mh;
        }
    }
    self->unk_14->mode = 1;
    ov002_Cursor_SetMode(self->unk_14);
    m = (Obj021efe5c *)Heap_Alloc(sizeof(Obj021efe5c));
    if (m != NULL) {
        *(VFunc **)m = Ov002Vt_021efe5c_vtbl;
        Ov002Vt_021efe3c_Ctor(&m->mdl);
        PlttRes_Init_02041218(&m->model.pltt);
        TexObj_Init(&m->model, NULL, 0);
        m->unk_1d4 = 0;
        m->pos.x = 0;
        m->pos.y = 0;
        m->pos.z = 0;
    }
    self->unk_0c = m;
    m->mdl.arc = K::data_ov002_021efdf6;
    m->mdl.name = K::data_ov002_021efe0e;
    m->mdl.anmName = K::data_ov002_021efe0e;
    Ov002Mdl021efe3c_Load(&m->mdl);
    {
        char *nm = ((char *)K::data_ov002_021efe1a);
        char *file = ((char *)K::data_ov002_021efe26);
        TexObj_Init(&m->model, nm, 0);
        STD_CopyString(m->model.name, file);
        TexObj_SetRes(&m->model, ResMgr_FindArcType2(file, nm));
    }
    m->model.flags |= 2;
    m->model.unk_150 = -0x2000;
    TexObj_SelectImage(&m->model, 0, 4);
    MTX_Identity22_(&m->model.mtx[0]);
    MTX_Rot22_(&r, FX_SINCOS(0xbff * 2), FX_SINCOS(0xbff * 2 + 1));
    MTX_Concat22(&r, &m->model.mtx[0], &m->model.mtx[0]);
    {
        Obj021efe5c *q = self->unk_0c;
        q->pos.x = 0xb33;
        q->pos.y = 0x23d;
        q->pos.z = 0;
    }
    {
        void *str = Param_Get(FIELD(((u8 *)self->unk_10), 0x48, u16));
        Obj021eff50 *t = self->owner;
        Obj0215bb14_SetText(((void *)t->unk_20), str);
        t->unk_20->vfunc_70();
    }
    {
        Obj021efe6c *b = self->owner->board;
        b->unk_74 = 7;
        b->unk_75 = 1;
    }
    {
        s32 px;
        s32 py;
        py = FIELD(((u8 *)self->unk_10), 0x58, s32);
        px = FIELD(((u8 *)self->unk_10), 0x54, s32);
        func_ov002_021e019c(self, px, py);
        self->unk_1c = px;
        self->unk_20 = py;
    }
    self->unk_18 = 0;
    self->owner = NULL;
}
#endif

}
