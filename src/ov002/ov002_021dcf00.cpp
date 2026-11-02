// Built at a lower optimization level than the rest of the overlay: at the default level the
// registers of the camera temporaries don't match.
#pragma optimization_level 3
#include "ov002/ov002.h"

extern "C" {

void func_ov002_021dd7f0(Obj021eff10 *self, Vec2 *a, Vec2 *b, int c);

static inline void ov002_ShowMsg(void *self, void *str) {
    u8 *t = FIELD(self, 0x4, u8 *);
    func_ov000_0215bb14(FIELD(t, 0x20, void *), str);
    FIELD(t, 0x20, VObj *)->vfunc_70();
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

static inline void *ov002_NewDcee0(void) {
    void *p = Heap_Alloc(0x138);
    if (p != NULL) {
        *(VFunc **)p = data_ov002_021efef0;
        func_ov002_021ddd80(p);
    }
    return p;
}

static inline u16 sumItems(Obj021efe6c *w) {
    u16 sum = 0;
    s32 i;
    for (i = 0; i < 100; i++) {
        sum += w->unk_08[i];
    }
    return sum;
}

void func_ov002_021dcf00(Obj021eff10 *self) {
    s32 px;
    u16 trig;
    s32 py;
    s32 pz;
    s32 tz;
    s32 d;
    Obj021efe6c *w;
    void *msg;
    trig = data_02097dc8->trig;
    w = self->owner->board;
    msg = data_02149ef8;
    if (trig & 1) {
        if (sumItems(w) == 0) {
            ov002_ShowMsg(self, MsgRes_GetString(msg, 0x107));
            func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
            return;
        }
        {
            u8 *q = ((u8 *)w->field);
            void *p;
            self->unk_24 = FIELD(FIELD(q, 0x6c, u8 *), 6, Nibbles16).n0;
            self->unk_28 = FIELD(FIELD(q, 0x6c, u8 *), 6, Nibbles16).n1;
            Obj021eff50 *t;
            p = ov002_NewDcee0();
            t = self->owner;
            t->unk_10 = (VObj *)p;
            t->unk_0c = 0x14;
        }
        func_02049a48(data_02097e4c, 0x1e, -1, -1, -1);
        return;
    }
    if ((trig & 0x20) || (trig & 2)) {
        d = (u8)self->unk_28 - w->field->map->oy;
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
        ov002_CamMove(w, px, py, pz, 0, 0, tz);
        func_ov002_021dd7f0(self, (Vec2 *)((u8 *)self + 0x24), (Vec2 *)((u8 *)self + 0x24), 1);
        self->unk_18 = 10;
        func_02049a48(data_02097e4c, 0xf, -1, -1, -1);
    }
}

}
