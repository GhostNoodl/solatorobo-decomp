#include "ov002/ov002.h"

extern "C" {

static inline bool isState5(void *p) {
    return FIELD(p, 0x4, s32) == 5;
}

void Lo021cae48_SetValue(void *a, u16 b, int c);


void *func_ov002_021e3874(s32 *v, int a, int b);


void func_ov002_021dd7f0(Obj021eff10 *self, void *a, void *b, int c);

void func_ov002_021dd130(Obj021eff10 *self) {
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
        u16 y = FIELD(((u8 *)self->unk_2c), 0xa8, u16);
        u16 x = ((u16)e->unk_8a);
        e->unk_8a = x > y ? x - y : 0;
        Lo021cae48_SetValue(FIELD(((u8 *)self->owner), 0x24, void *), ((u16)e->unk_8a), 0);
        Obj021efe6c_RemovePiece(e, self->unk_2c, 1);
        SndMgr_PlayVolume(data_02097e4c, 0x6e, -1, -1, -1);
        SndMgr_PlayVolume(data_02097e4c, 0x44, -1, -1, -1);
        a[0] = FIELD(((u8 *)self->unk_2c), 0x54, s32);
        a[1] = FIELD(((u8 *)self->unk_2c), 0x58, s32);
        b[0] = FIELD(((u8 *)self->unk_2c), 0x64, s32);
        b[1] = FIELD(((u8 *)self->unk_2c), 0x68, s32);
        Ov002_CellToPos(out, a, b);
        out[1] = 0x266;
        func_ov002_021e3874(out, 0x80, 1);
        Effect_SpawnId(0x6d, (VecFx32 *)out); // out is s32[3]
        func_ov002_021dd7f0(self, (u8 *)self + 0x24, (u8 *)self + 0x24, 1);
    } else {
        SndMgr_PlayVolume(data_02097e4c, 0x1f, -1, -1, -1);
    }
    self->unk_18 = 10;
    self->unk_2c = NULL;
}

static inline bool ov002_flag1(void *p) {
    return FIELD(p, 0xc, Bits32).b1;
}


s32 SndMgr_PlayPan(void *a, int b, int c);

void func_ov002_021dd29c(Obj021eff10 *self) {
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
            SndMgr_PlayPan(data_02097e4c, 0x47, -5);
        } else {
            self->unk_18 += 2;
            SndMgr_PlayVolume(data_02097e4c, 0x1f, -1, -1, -1);
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
        func_ov002_021dd7f0(self, (u8 *)self + 0x24, (u8 *)self + 0x24, 1);
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

void func_ov002_021dd434(Obj021eff10 *self) {
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
            SndMgr_PlayPan(data_02097e4c, 0x5c, 5);
        } else {
            self->unk_18 += 2;
            SndMgr_PlayVolume(data_02097e4c, 0x1f, -1, -1, -1);
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
        func_ov002_021dd7f0(self, (u8 *)self + 0x24, (u8 *)self + 0x24, 1);
        self->unk_18 = 10;
        break;
    }
    }
}

extern VFunc data_ov000_021cb1b0[];

extern VFunc data_ov000_021cb0b8[];

BOOL func_ov002_021e046c(UiList *self, UiListItem *item);

void *func_ov002_021dd6a4(Obj021eff10 *self, s32 a, u16 b) {
    UiObj *p;
    {
        void *saved;
        HEAP_PUSH(saved);
        DELETE_VOBJ(self->unk_0c);
        HEAP_POP(saved);
    }
    p = (UiObj *)Heap_Alloc(0x1e4);
    if (p != NULL) {
        *(VFunc **)p = data_ov000_021cac60;
        p->vfunc_28();
        *(VFunc **)p = data_ov000_021caec8;
        p->vfunc_28();
        *(VFunc **)p = data_ov000_021cb1b0;
        p->vfunc_28();
        *(VFunc **)p = data_ov000_021cb0b8;
        p->vfunc_28();
    }
    self->unk_0c = (LoBase021cafc0_021cb0b8 *)p;
    FIELD(p, 0x1d8, u16) = b;
    FIELD(self->unk_0c, 0x1dc, s32) = a;
    FIELD(self->unk_0c, 0x1e0, u16) = 1;
    self->unk_0c->onDecide = func_ov002_021e046c;
    self->unk_0c->owner = (u8 *)self + 0x1c;
    self->unk_0c->vfunc_08();
    self->unk_0c->posZ = -0x1666;
    self->unk_0c->flags &= ~2;
    return self->unk_0c;
}

}
