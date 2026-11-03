#include "ov002/ov002.h"

extern "C" {

void func_0206ecd4(u32 size, void *dst, u16 id);

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
    Obj0215bb14_SetText(t->unk_20, str);
    t->unk_20->vfunc_70();
    self->unk_20 = 0;
}

void func_ov002_021dd7f0(Obj021eff10 *self, Vec2 *a, Vec2 *b, int c) {
    Obj021efe6c *w = self->owner->board;
    Ov002Cell *cur = ov002_GetCell(w, b);
    Ov002Cell *nxt = ov002_GetCell(w, a);
    void *msg = gMsgRes;
    switch (nxt->unk_2) {
    case 1:
        if (nxt->obj != cur->obj || c != 0 || self->unk_20 != 0) {
            w->unk_74 = 1;
            w->unk_75 = 1;
            func_0206ecd4(0x100, (u8 *)self + 0x34, nxt->obj->unk_48);
            ov002_ShowMsg(self, self->unk_34);
        }
        break;
    case 0:
        if (nxt->unk_2 != cur->unk_2 || c != 0 || self->unk_20 != 0) {
            w->unk_74 = 2;
            w->unk_75 = 1;
            ov002_ShowMsg(self, MsgRes_GetString(msg, 0x109));
        }
        break;
    case 2:
        if (nxt->unk_2 != cur->unk_2 || c != 0 || self->unk_20 != 0) {
            w->unk_74 = 3;
            w->unk_75 = 1;
            ov002_ShowMsg(self, MsgRes_GetString(msg, 0x108));
        }
        break;
    }
    if (cur->obj == nxt->obj && c == 0) {
        return;
    }
    if (cur->unk_2 == 1) {
        Obj021efe9c *t = (Obj021efe9c *)cur->obj;
        t->unk_cd = 0;
        t->unk_9c = 0xf85;
    } else if (cur->unk_2 == 2) {
        ((Obj021efed4 *)cur->obj)->unk_9c = 0;
    }
    if (nxt->unk_2 == 1) {
        Obj021efe9c *t = (Obj021efe9c *)nxt->obj;
        t->unk_cd = 1;
        t->unk_d0 = 0;
    } else if (nxt->unk_2 == 2) {
        ((Obj021efed4 *)nxt->obj)->unk_9c = 1;
    }
}

}
