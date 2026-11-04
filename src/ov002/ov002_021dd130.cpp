#include "ov002/ov002.h"

extern "C" {

static inline bool isState5(UiObj *p) {
    return p->state == 5;
}

void Lo021cae48_SetValue(Lo021cae48 *self, s32 value, BOOL both);


void *func_ov002_021e3874(s32 *v, int a, int b);


void Obj021eff10_ShowCellInfo(Obj021eff10 *self, void *a, void *b, int c);

void Obj021eff10_Step30(Obj021eff10 *self) {
    s32 out[3];
    s32 a[2];
    s32 b[2];
    Obj021efe6c *e;
    {
        BOOL st = isState5(self->unk_0c);
        if (!st) {
            return;
        }
    }
    e = self->owner->board;
    if (self->unk_1c == 0) {
        u16 y = self->unk_2c->unk_a8;
        u16 x = ((u16)e->unk_8a);
        e->unk_8a = x > y ? x - y : 0;
        Lo021cae48_SetValue(self->owner->unk_24, ((u16)e->unk_8a), 0);
        Obj021efe6c_RemovePiece(e, self->unk_2c, 1);
        SndMgr_PlayVolume(gSndMgr, 0x6e, -1, -1, -1);
        SndMgr_PlayVolume(gSndMgr, 0x44, -1, -1, -1);
        a[0] = self->unk_2c->unk_54;
        a[1] = self->unk_2c->unk_58;
        b[0] = self->unk_2c->unk_64;
        b[1] = self->unk_2c->unk_68;
        Ov002_CellToPos(out, a, b);
        out[1] = 0x266;
        func_ov002_021e3874(out, 0x80, 1);
        Effect_SpawnId(0x6d, (VecFx32 *)out); // out is s32[3]
        Obj021eff10_ShowCellInfo(self, (u8 *)self + 0x24, (u8 *)self + 0x24, 1);
    } else {
        SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
    }
    self->unk_18 = 10;
    self->unk_2c = NULL;
}

static inline bool ov002_flag1(UiObj *p) {
    return p->hidden;
}


s32 SndMgr_PlayPan(void *a, int b, int c);

void Obj021eff10_Step40(Obj021eff10 *self) {
    switch (self->unk_18) {
    case 0x28: {
        BOOL t = ov002_flag1(self->unk_0c);
        if (!t) {
            return;
        }
        if (self->unk_1c == 0) {
            Obj021efe9c *o = self->unk_30;
            if (o->unk_ac != 8 && o->unk_a4 == 0) {
                Ov002_CellToPos(&o->unk_bc.x, &o->unk_54, &o->unk_64);
                o->unk_bc.y = 0x400;
                o->unk_b0.x = 0xb33;
                o->unk_b0.z = 0;
                o->unk_b0.y = 0x400;
                o->unk_a4 = 0x14;
                o->unk_a8 = 0x14;
                o->unk_ac = 8;
            }
            self->unk_18++;
            SndMgr_PlayPan(gSndMgr, 0x47, -5);
        } else {
            self->unk_18 += 2;
            SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
        }
        break;
    }
    case 0x29: {
        Obj021efe9c *o = self->unk_30;
        Obj021efe6c *q;
        if (o->unk_ac != 0) {
            return;
        }
        q = self->owner->board;
        q->unk_08[(u16)(o->unk_48 & 0xfff)]++;
        Obj021efe6c_RemovePiece(q, o, 1);
        Obj021eff10_ShowCellInfo(self, (u8 *)self + 0x24, (u8 *)self + 0x24, 1);
        self->unk_18++;
        break;
    }
    case 0x2a:
        {
            BOOL st = isState5(self->unk_0c);
            if (st) {
                self->unk_18 = 10;
            }
        }
        break;
    }
}

extern u8 data_ov002_021efe30[];

void Obj021eff10_Step50(Obj021eff10 *self) {
    Obj021efe6c *w = self->owner->board;
    Obj021efe9c *o;
    switch (self->unk_18) {
    case 0x32: {
        BOOL t = ov002_flag1(self->unk_0c);
        if (!t) {
            return;
        }
        if (self->unk_1c == 0) {
            Obj021eff50 *m;
            for (o = (Obj021efe9c *)w->pieces; o != NULL; o = (Obj021efe9c *)o->next) {
                if (o->unk_4a == 1 && o->unk_ac != 8 && o->unk_a4 == 0) {
                    Ov002_CellToPos(&o->unk_bc.x, &o->unk_54, &o->unk_64);
                    o->unk_bc.y = 0x400;
                    o->unk_b0.x = 0xb33;
                    o->unk_b0.z = 0;
                    o->unk_b0.y = 0x400;
                    o->unk_a4 = 0x14;
                    o->unk_a8 = 0x14;
                    o->unk_ac = 8;
                }
            }
            m = self->owner;
            Obj0215bb14_SetText(m->unk_20, data_ov002_021efe30);
            m->unk_20->vfunc_70();
            self->unk_18++;
            SndMgr_PlayPan(gSndMgr, 0x5c, 5);
        } else {
            self->unk_18 += 2;
            SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
        }
        break;
    }
    case 0x33: {
        bool all = TRUE;
        Obj021efe9c *next;
        for (o = (Obj021efe9c *)w->pieces; o != NULL; o = (Obj021efe9c *)o->next) {
            if (o->unk_4a == 1) {
                all &= o->unk_ac == 0;
            }
        }
        if (!all) {
            return;
        }
        for (o = (Obj021efe9c *)w->pieces; o != NULL; o = next) {
            next = (Obj021efe9c *)o->next;
            if (o->unk_4a == 1) {
                Obj021efe6c *q = self->owner->board;
                (&FIELD(q, 8, u8))[(u16)(o->unk_48 & 0xfff)]++;
                Obj021efe6c_RemovePiece(q, o, 1);
            }
        }
        self->unk_18++;
        break;
    }
    case 0x34: {
        BOOL st = isState5(self->unk_0c);
        if (!st) {
            return;
        }
        Obj021eff10_ShowCellInfo(self, (u8 *)self + 0x24, (u8 *)self + 0x24, 1);
        self->unk_18 = 10;
        break;
    }
    }
}

extern VFunc Ov000Vt_021cb1b0_vtbl[];

extern VFunc Ov000Vt_021cb0b8_vtbl[];

BOOL func_ov002_021e046c(UiList *self, UiListItem *item);

void *func_ov002_021dd6a4(Obj021eff10 *self, char *text, u16 msgId) {
    Lo021cb0b8 *p;
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(self->unk_0c);
        HEAP_POP(saved);
    }
    p = (Lo021cb0b8 *)Heap_Alloc(0x1e4);
    if (p != NULL) {
        *(VFunc **)p = UiObj_vtbl;
        p->vfunc_28();
        *(VFunc **)p = UiList_vtbl;
        p->vfunc_28();
        *(VFunc **)p = Ov000Vt_021cb1b0_vtbl;
        p->vfunc_28();
        *(VFunc **)p = Ov000Vt_021cb0b8_vtbl;
        p->vfunc_28();
    }
    self->unk_0c = p;
    p->msgId = msgId;
    self->unk_0c->text = text;
    self->unk_0c->key = 1;
    self->unk_0c->onDecide = func_ov002_021e046c;
    self->unk_0c->owner = (u8 *)self + 0x1c;
    self->unk_0c->vfunc_08();
    self->unk_0c->posZ = -0x1666;
    self->unk_0c->flags &= ~2;
    return self->unk_0c;
}

}
