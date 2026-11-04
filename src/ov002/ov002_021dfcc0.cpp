#include "ov002/ov002.h"

extern "C" {
s32 SndMgr_PlayPan(void *a, int b, int c);
}

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

static inline void ov002_SyncCursor(Obj021eff30 *self) {
    Obj021efe9c *g = self->unk_10;
    self->unk_1c = g->unk_54;
    self->unk_20 = g->unk_58;
    func_ov002_021e019c(self, self->unk_1c, self->unk_20);
}

static inline BOOL ov002_TryMove(Obj021efe9c *g, s32 dx, s32 dy, Ov002Shape *map) {
    BOOL r = FALSE;
    Vec2 d;
    if (g->unk_a4 != 0 || g->unk_ac != 1) {
        return FALSE;
    }
    d.x = dx;
    d.y = dy;
    if (func_ov002_021e4578((Vec2 *)&g->unk_54, &d, map, &g->shape)) {
        g->unk_54 += d.x;
        g->unk_58 += d.y;
        if (g->unk_ac == 1) {
            Ov002_CellToPos(&g->unk_b0.x, &g->unk_54, &g->unk_64);
            g->unk_b0.y = g->trans.y;
            g->unk_bc.x = g->trans.x;
            g->unk_bc.y = g->trans.y;
            g->unk_bc.z = g->trans.z;
            g->unk_a4 = 4;
            g->unk_a8 = 4;
            g->unk_ac = 4;
            SndMgr_PlayVolume(gSndMgr, 0x22, -1, -1, -1);
        }
        r = TRUE;
    }
    return r;
}

extern "C" {

static inline Obj021efe6c *GetUnit021dfcc0(Obj021eff30 *self) { return self->owner->board; }
static inline Ov002Shape *GetMap021dfcc0(Obj021efe6c *unit) { return unit->field->map; }
static inline void *GetMgr021dfcc0(void) { return gMsgRes; }

void Obj021eff30_Step01(Obj021eff30 *self) {
    Obj021efe6c *cam;
    void *mgr;
    Obj021efe9c *cur;
    Pad *pad = gPad;
    s32 trg = pad->trig;
    u16 rep = pad->repeat;
    Obj021efe6c *unit = GetUnit021dfcc0(self);
    mgr = GetMgr021dfcc0();
    Ov002Shape *map;
    if (trg & 2) {
        if (self->unk_10->unk_ac != 1) {
            return;
        }
        self->unk_18 = 0x1e;
        SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
        return;
    }
    if (trg & 1) {
        if (self->unk_10->unk_ac != 1) {
            return;
        }
        if (!func_ov002_021e45c4(self->unk_10, unit->pieces, unit->field->map)) {
            self->unk_18 = 0x14;
            return;
        }
        SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
        return;
    }
    map = GetMap021dfcc0(unit);
    if (rep & 0xf0) {
        Vec2 d = {0, 0};
        Vec2 p;
        Vec2 out;
        Obj021efe9c *g;
        if (rep & 0x40) {
            d.y--;
        } else if (rep & 0x80) {
            d.y++;
        } else if (rep & 0x20) {
            d.x--;
        } else if (rep & 0x10) {
            d.x++;
        }
        cur = self->unk_10;
        if (ov002_TryMove(cur, d.x, d.y, map)) {
            ov002_SyncCursor(self);
            return;
        }
        g = self->unk_10;
        p = *(Vec2 *)&g->unk_54;
        p.x += d.x;
        p.y += d.y;
        func_ov002_021e3dac(&p, map, &g->shape, &out);
        if (out.x < map->w) {
            return;
        }
        {
            void *s = MsgRes_GetString(mgr, 0x10c);
            Obj021eff50 *o = self->owner;
            Obj0215bb14_SetText(((void *)o->unk_20), s);
            ((VObj *)(((void *)o->unk_20)))->vfunc_70();
        }
        unit->unk_74 = 8;
        unit->unk_75 = 1;
        cam = self->owner->board;
        { s32 a44 = *(s32 *)(data_ov002_021eef74 + 0x44); s32 a48 = *(s32 *)(data_ov002_021eef74 + 0x48); ov002_CamMove(cam, 0xb33, a44, a48, 0xb33, 0, 0xa4); }
        self->unk_18 = 10;
        SndMgr_PlayVolume(gSndMgr, 0xe, -1, -1, -1);
        return;
    }
    if (!(trg & 0x300)) {
        return;
    }
    if (trg & 0x100) {
        func_ov002_021d8c34(self->unk_10, -1, map);
    } else if (trg & 0x200) {
        func_ov002_021d8c34(self->unk_10, 1, map);
    }
    ov002_SyncCursor(self);
    SndMgr_PlayPan(gSndMgr, 0x47, 6);
}

}
