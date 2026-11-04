// Built at a lower optimization level than the rest of the overlay: at the default level the
// registers of the camera temporaries don't match.
#pragma optimization_level 3
#include "ov002/ov002.h"

extern "C" {

void Obj021eff10_ShowCellInfo(Obj021eff10 *self, Vec2 *a, Vec2 *b, int c);

static inline void ov002_ShowMsg(Obj021eff10 *self, void *str) {
    Obj021eff50 *t = self->owner;
    Obj0215bb14_SetText(t->unk_20, str);
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

static inline Obj021efef0 *ov002_NewDcee0(void) {
    Obj021efef0 *p = (Obj021efef0 *)Heap_Alloc(sizeof(Obj021efef0));
    if (p != NULL) {
        *(VFunc **)p = Ov002Vt_021efef0_vtbl;
        Obj021efef0_Init(p);
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

void Obj021eff10_Step20(Obj021eff10 *self) {
    s32 px;
    u16 trig;
    s32 py;
    s32 pz;
    s32 tz;
    s32 d;
    Obj021efe6c *w;
    void *msg;
    trig = gPad->trig;
    w = self->owner->board;
    msg = gMsgRes;
    if (trig & 1) {
        if (sumItems(w) == 0) {
            ov002_ShowMsg(self, MsgRes_GetString(msg, 0x107));
            SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
            return;
        }
        {
            Obj021efe4c *q = w->field;
            Obj021efef0 *p;
            self->unk_24 = q->map->ox;
            self->unk_28 = q->map->oy;
            Obj021eff50 *t;
            p = ov002_NewDcee0();
            t = self->owner;
            t->unk_10 = p;
            t->unk_0c = 0x14;
        }
        SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
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
        Obj021eff10_ShowCellInfo(self, (Vec2 *)((u8 *)self + 0x24), (Vec2 *)((u8 *)self + 0x24), 1);
        self->unk_18 = 10;
        SndMgr_PlayVolume(gSndMgr, 0xf, -1, -1, -1);
    }
}

}
