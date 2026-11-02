#include "ov002/ov002.h"

namespace K {
extern "C" const char data_ov002_021efdea[];
extern "C" const char data_ov002_021efdf6[];
extern "C" const char data_ov002_021efe02[];
}

extern "C" {

extern VFunc data_ov000_021ccbe0[];
extern VFunc data_ov002_021f0044[];
extern VFunc data_ov002_021ef684[];
extern VFunc data_ov002_021f002c[];
void func_ov000_021c3af4(void *self);
void ListRow_Init(void *self);
void Obj021f002c_Init(Obj021f002c *self);
void LoBase021ccb54_021ccbe0_AppendRow(void *list, void *item);
BOOL func_ov002_021ddcbc(LoBase021ccb54_021ccbe0 *self, Obj021f002c *ev);
BOOL func_ov002_021ddd30(LoBase021ccb54_021ccbe0 *self, Obj021f002c *ev);

static inline void ov002_AddItem(LoBase021ccb54_021ccbe0 *list, s32 k, void *str, void *desc) {
    Obj021f002c *q = (Obj021f002c *)Heap_Alloc(sizeof(Obj021f002c));
    if (q != NULL) {
        *(VFunc **)q = data_ov002_021ef684;
        ListRow_Init(q);
        *(VFunc **)q = data_ov002_021f002c;
        Obj021f002c_Init(q);
    }
    q->index = k;
    q->str = str;
    q->unk_40 = desc;
    q->unk_44 = 1;
    LoBase021ccb54_021ccbe0_AppendRow(list, q);
}

static inline Obj021efe8c *ov002_NewCursor(void) {
    Obj021efe8c *c = (Obj021efe8c *)Heap_Alloc(sizeof(Obj021efe8c));
    if (c != NULL) {
        *(VFunc **)c = data_ov002_021efe8c;
        Ov002Vt_021efe3c_Ctor(&c->mdl);
        c->unk_78 = 0;
        c->unk_74 = 0;
        c->unk_80 = 0;
        c->unk_7c = 0;
        c->unk_84 = 0;
        c->mode = 0;
        c->unk_8a = 0x7fff;
    }
    return c;
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

static inline void ov002_CamMove(Obj021efe6c *c, const VecFx32 *pos, s32 tx, s32 ty, s32 tz) {
    c->unk_90 = 20;
    c->unk_94 = 20;
    c->unk_98 = c->cam->eye;
    c->unk_a4 = c->cam->at;
    if (pos != NULL) {
        c->unk_b0.x = pos->x;
        c->unk_b0.y = pos->y;
        c->unk_b0.z = pos->z;
    }
    c->unk_bc.x = tx;
    c->unk_bc.y = ty;
    c->unk_bc.z = tz;
}

static inline void *GetMgr021ddf18(void) { return data_02149ef8; }

// h and cam are locals passed as unused register parameters (the locals-as-parameters lever).
// As user variables they number above every temp and the registers rotate (124-127 diffs, round jkE).
void func_ov002_021ddf18(Obj021efef0 *self, Obj021eff50 *owner, s32 h, Obj021efe6c *cam) {
    s32 w;
    void *g;
    UiObj *p;
    Obj021efe8c *c;
    self->owner = owner;
    cam = owner->board;
    g = GetMgr021ddf18();
    p = (UiObj *)Heap_Alloc(0xf4);
    if (p != NULL) {
        *(VFunc **)p = data_ov000_021cac60;
        p->vfunc_28();
        *(VFunc **)p = data_ov000_021ccbe0;
        func_ov000_021c3af4(p);
        *(VFunc **)p = data_ov002_021f0044;
    }
    self->unk_08 = (Ov002RowList *)p;
    p->rows = 5;
    self->unk_08->width = 0x69;
    {
        LoBase021ccb54_021ccbe0 *s = self->unk_08;
        s->posX = 0x96;
        s->posY = 0x19;
        s->posZ = -0x199a;
    }
    self->unk_08->flags &= ~0x20000;
    self->unk_08->flags &= ~0x40000;
    ov002_AddItem(self->unk_08, 0, MsgRes_GetString(g, 0x48), MsgRes_GetString(g, 0x160));
    ov002_AddItem(self->unk_08, 1, MsgRes_GetString(g, 0x49), MsgRes_GetString(g, 0x161));
    ov002_AddItem(self->unk_08, 2, MsgRes_GetString(g, 0x4a), MsgRes_GetString(g, 0x162));
    ov002_AddItem(self->unk_08, 3, MsgRes_GetString(g, 0x4b), MsgRes_GetString(g, 0x163));
    ov002_AddItem(self->unk_08, 4, MsgRes_GetString(g, 0x4c), MsgRes_GetString(g, 0x164));
    self->unk_08->vfunc_08();
    {
        LoBase021ccb54_021ccbe0 *s = self->unk_08;
        s->slideX = 0x100;
        s->slideY = 0;
        s->slideZ = -0x199a;
    }
    self->unk_08->slideMode = 1;
    self->unk_08->owner = (u8 *)self + 0x20;
    self->unk_08->onDecide = (void *)func_ov002_021ddcbc;
    self->unk_08->onCursor = (void *)func_ov002_021ddd30;
    self->unk_08->flags |= 2;
    self->unk_08->flags &= ~4;
    self->unk_08->flags |= 0x10;

    c = ov002_NewCursor();
    self->unk_10 = c;
    {
        Ov002Shape *map = owner->board->field->map;
        h = map->oy;
        w = map->ox;
    }
    c->unk_7c = w;
    c->unk_80 = h;
    self->unk_10->mode = 0;
    ov002_Cursor_SetMode(self->unk_10);

    c = ov002_NewCursor();
    self->unk_14 = c;
    c->unk_7c = w;
    c->unk_80 = h;
    self->unk_14->mode = 1;
    ov002_Cursor_SetMode(self->unk_14);
    self->unk_14->unk_84 = 0x11f;

    self->unk_2c = owner->unk_28;
    self->unk_30 = owner->unk_2c;
    cam->unk_74 = 5;
    cam->unk_75 = 1;
    ov002_CamMove(owner->board, (const VecFx32 *)(data_ov002_021eef74 + 0x28), 0x99a, 0, 0x148);
    {
        u16 id = self->unk_18;
        if (id == 0xffff) {
            self->unk_1c = 0;
        } else {
            self->unk_28 = *Param_GetEntry(id);
            self->unk_1c = 10;
        }
    }
    self->owner = NULL;
}

}
