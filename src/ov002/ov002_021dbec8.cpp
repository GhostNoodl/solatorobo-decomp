#include "ov002/ov002.h"

namespace K { extern "C" const char data_ov002_021efdea[]; }
namespace K { extern "C" const char data_ov002_021efdf6[]; }
namespace K { extern "C" const char data_ov002_021efe02[]; }
namespace K { extern "C" const char data_ov002_021efe0e[]; }
namespace K { extern "C" const char data_ov002_021efe1a[]; }
namespace K { extern "C" const char data_ov002_021efe26[]; }

extern "C" {

void *func_02035de0(const char *file, const char *name);
void TexObj_SetOamFunc(void *a, int b, void *c, int d);
void *func_ov002_021e0488(void *a, void *b, void *c, u16 *d);

static inline void ov002_CamMove(Obj021efe6c *c, s32 px, s32 py, s32 pz, s32 tx, s32 ty, s32 tz) {
    c->unk_90 = 15;
    c->unk_94 = 15;
    c->unk_98 = c->cam->eye;
    c->unk_a4 = c->cam->at;
    c->unk_b0.x = px;
    c->unk_b0.y = py;
    c->unk_b0.z = pz;
    c->unk_bc.x = tx;
    c->unk_bc.y = ty;
    c->unk_bc.z = tz;
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

void func_ov002_021dbec8(Obj021eff10 *self, Obj021eff50 *owner) {
    Obj021efe5c *m;
    MtxFx22 r;
    self->owner = owner;
    m = (Obj021efe5c *)Heap_Alloc(sizeof(Obj021efe5c));
    if (m != NULL) {
        *(VFunc **)m = data_ov002_021efe5c;
        Ov002Vt_021efe3c_Ctor(&m->mdl);
        PlttRes_Init_02041218(&m->model.pltt);
        TexObj_Init(&m->model, NULL, 0);
        m->unk_1d4 = 0;
        m->pos.x = 0;
        m->pos.y = 0;
        m->pos.z = 0;
    }
    self->unk_08 = m;
    m->mdl.arc = K::data_ov002_021efdf6;
    m->mdl.name = K::data_ov002_021efe0e;
    m->mdl.anmName = K::data_ov002_021efe0e;
    Ov002Mdl021efe3c_Load(&m->mdl);
    {
        char *nm = ((char *)K::data_ov002_021efe1a);
        char *file = ((char *)K::data_ov002_021efe26);
        TexObj_Init(&m->model, nm, 0);
        STD_CopyString(m->model.name, file);
        TexObj_SetRes(&m->model, func_02035de0(file, nm));
    }
    m->model.flags |= 2;
    m->model.unk_150 = -0x2000;
    TexObj_SelectImage(&m->model, 0, 4);
    MTX_Identity22_(&m->model.mtx[0]);
    MTX_Rot22_(&r, FX_SINCOS(0xbff * 2), FX_SINCOS(0xbff * 2 + 1));
    MTX_Concat22(&r, &m->model.mtx[0], &m->model.mtx[0]);
    {
        Obj021efe5c *q = self->unk_08;
        q->pos.x = 0xb33;
        q->pos.y = 0x23d;
        q->pos.z = 0;
    }
    {
        Model *mdl = (Model *)Heap_Alloc(sizeof(Model));
        if (mdl != NULL) {
            const char *file = data_0208cc94;
            const char *nm = data_0208cc88;
            PlttRes_Init_02041218(&mdl->pltt);
            TexObj_Init(mdl, nm, 0);
            STD_CopyString(mdl->name, file);
        }
        self->unk_10 = mdl;
    }
    TexObj_SetRes(self->unk_10, func_02035de0(data_0208cc94, data_0208cc88));
    self->unk_10->flags |= 2;
    self->unk_10->unk_150 = -0x2000;
    TexObj_SetOamFunc(self->unk_10, 6, (void *)func_ov002_021e0488, 0);
    TexObj_SelectImage(self->unk_10, 0, 6);
    {
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
        self->unk_14 = c;
        {
            Ov002Shape *map = owner->board->field->map;
            s32 w = map->ox;
            s32 h = map->oy;
            c->unk_7c = w;
            c->unk_80 = h;
        }
    }
    self->unk_14->mode = 0;
    ov002_Cursor_SetMode(self->unk_14);
    self->unk_24 = owner->unk_28;
    self->unk_28 = owner->unk_2c;
    {
        s32 d;
        s32 px;
        s32 py;
        s32 pz;
        s32 tz;
        Obj021efe6c *c;
        c = owner->board;
        d = (u8)self->unk_28 - c->field->map->oy;
        px = *(s32 *)(data_ov002_021eef74 + 0x58);
        py = *(s32 *)(data_ov002_021eef74 + 0x5c);
        pz = *(s32 *)(data_ov002_021eef74 + 0x60);
        tz = 0x148;
        if (d < -1) {
            pz -= 0x1ec;
            tz -= 0x1ec;
        } else if (d > 1) {
            pz += 0x1ec;
            tz += 0x1ec;
        }
        ov002_CamMove(c, px, py, pz, 0, 0, tz);
    }
    self->unk_18 = 0;
    self->owner = NULL;
}

}
