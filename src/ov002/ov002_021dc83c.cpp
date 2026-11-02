#include "ov002/ov002.h"

extern "C" {

s32 func_02049bdc(void *a, int b, int c);
void *func_ov002_021dd6a4(Obj021eff10 *self, s32 a, u16 b);
void func_ov002_021dd7f0(Obj021eff10 *self, Vec2 *a, Vec2 *b, int c);

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

static inline void ov002_ShowMsg(Obj021eff10 *self, void *str) {
    Obj021eff50 *t = self->owner;
    func_ov000_0215bb14(t->unk_20, str);
    t->unk_20->vfunc_70();
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

void func_ov002_021dc83c(Obj021eff10 *self) {
    u16 trig = data_02097dc8->trig;
    Obj021efe6c *w = self->owner->board;
    void *msg = data_02149ef8;
    u16 rep = data_02097dc8->repeat;
    Ov002Cell *cell;
    if (trig & 2) {
        self->unk_18 = 0x46;
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        return;
    }
    if (trig & 1) {
        cell = ov002_GetCell(w, (Vec2 *)((u8 *)self + 0x24));
        switch (cell->unk_2) {
        case 1: {
            Obj021eff30 *p;
            self->unk_30 = (Obj021efe9c *)cell->obj;
            func_02049bdc(data_02097e4c, 0x47, -5);
            p = (Obj021eff30 *)Heap_Alloc(0x30);
            if (p != NULL) {
                *(VFunc **)p = data_ov002_021eff30;
                p->owner = NULL;
                p->unk_08 = -1;
                p->unk_0c = NULL;
                p->unk_10 = NULL;
                p->unk_14 = NULL;
                p->unk_18 = 0;
                p->unk_20 = 0;
                p->unk_1c = 0;
                p->unk_28 = 0;
                p->unk_24 = 0;
                p->unk_2c = 0;
            }
            {
                Obj021eff50 *t = self->owner;
                t->unk_10 = p;
                t->unk_0c = 0x1e;
            }
            return;
        }
        case 2: {
            Obj021efed4 *o = (Obj021efed4 *)cell->obj;
            if (((u16)w->unk_8a) >= o->unk_a8) {
                self->unk_2c = o;
                func_ov002_021dd6a4(self, (s32)MsgRes_GetString(data_02149ef8, 0x1f), 0x8d);
                self->unk_18 = 0x1e;
                return;
            }
            ov002_ShowMsg(self, MsgRes_GetString(msg, 0x106));
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            self->unk_20 = 1;
            return;
        }
        case 0: {
            int i;
            u16 sum = 0;
            Obj021efef0 *p;
            for (i = 0; i < 100; i++) {
                sum += w->unk_08[i];
            }
            if (sum == 0) {
                ov002_ShowMsg(self, MsgRes_GetString(msg, 0x107));
                func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
                self->unk_20 = 1;
                return;
            }
            p = (Obj021efef0 *)Heap_Alloc(sizeof(Obj021efef0));
            if (p != NULL) {
                *(VFunc **)p = data_ov002_021efef0;
                func_ov002_021ddd80(p);
            }
            {
                Obj021eff50 *t = self->owner;
                t->unk_10 = p;
                t->unk_0c = 0x14;
            }
            func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
            return;
        }
        }
        return;
    }
    if (trig & 0x400) {
        func_ov002_021dd6a4(self, (s32)MsgRes_GetString(msg, 0x20), 0x8d);
        self->unk_18 = 0x32;
        return;
    }
    if (trig & 0x800) {
        cell = ov002_GetCell(w, (Vec2 *)((u8 *)self + 0x24));
        if (cell->unk_2 != 1) {
            return;
        }
        self->unk_30 = (Obj021efe9c *)cell->obj;
        func_ov002_021dd6a4(self, (s32)MsgRes_GetString(data_02149ef8, 0x21), 0x8d);
        self->unk_18 = 0x28;
        return;
    }
    if (rep & 0xf0) {
        Vec2 np;
        Ov002Shape *v = func_02070dcc(4);
        Ov002Shape *map = w->field->map;
        np.x = self->unk_24;
        np.y = self->unk_28;
        if (rep & 0x20) {
            np.x--;
        } else if (rep & 0x10) {
            np.x++;
        } else if (rep & 0x40) {
            np.y--;
        } else if (rep & 0x80) {
            np.y++;
        }
        if (!func_ov002_021e3dac(&np, map, v, NULL)) {
            Vec2 old;
            Obj021efe6c *c;
            s32 d;
            s32 px, py, pz, tz;
            func_02049a48(data_02097e4c, 0x22, -1, -1, -1);
            old.x = self->unk_24;
            old.y = self->unk_28;
            func_ov002_021dd7f0(self, &np, &old, 0);
            c = self->owner->board;
            d = (u8)np.y - self->owner->board->field->map->oy;
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
            self->unk_24 = np.x;
            self->unk_28 = np.y;
            return;
        }
        if (np.x <= self->unk_24) {
            return;
        }
        if (np.x < map->w) {
            return;
        }
        func_02049a48(data_02097e4c, 0xe, -1, -1, -1);
        {
            Obj021efe6c *c = self->owner->board;
            s32 py = *(s32 *)(data_ov002_021eef74 + 0x5c);
            s32 pz = *(s32 *)(data_ov002_021eef74 + 0x60);
            ov002_CamMove(c, 0xb33, py, pz, 0xb33, 0, 0x148);
        }
        w->unk_74 = 4;
        w->unk_75 = 1;
        ov002_ShowMsg(self, MsgRes_GetString(msg, 0x10b));
        cell = ov002_GetCell(w, (Vec2 *)((u8 *)self + 0x24));
        if (cell->unk_2 == 1) {
            Obj021efe9c *t = (Obj021efe9c *)cell->obj;
            t->unk_cd = 0;
            t->unk_9c = 0xf85;
        } else if (cell->unk_2 == 2) {
            ((Obj021efed4 *)cell->obj)->unk_9c = 0;
        }
        self->unk_18 = 0x14;
    }
}

}
