#include "ov002/ov002.h"
#include "ov000/ModelPart.h"

extern "C" {

void func_02041d8c(Model *model);

void Ov002Caption_Update(Ov002Caption *self);

void Ov002HudInfo_SetId(Ov002HudInfo *self, u16 id);

void Ov002Hud_Update(Ov002Hud *self) {
    if (self->pending != 0) {
        if ((self->pending & 1) && Model_IsReady(self->unk_04, 0) != 0) {
            func_02041d8c(self->unk_04);
            self->pending &= ~1;
        }
        if ((self->pending & 2) && Model_IsReady(self->unk_08, 0) != 0) {
            func_02041d8c(self->unk_08);
            self->pending &= ~2;
        }
        if ((self->pending & 4) && Model_IsReady(self->unk_0c, 0) != 0) {
            func_02041d8c(self->unk_0c);
            self->pending &= ~4;
        }
        if ((self->pending & 8) && Model_IsReady(self->unk_10, 0xffff) != 0) {
            self->pending &= ~8;
        }
        if (self->pending != 0) {
            return;
        }
    }
    {
        s32 i;
        Ov002HudInfo *w;
        for (i = 0; i < 5; i++) {
            Ov002Caption_Update(self->captions[i]);
        }
        w = self->info;
        if (w == NULL) {
            return;
        }
        if (w->shownId != w->id) {
            w->shownId = w->id;
            Ov002HudInfo_SetId(w, w->shownId);
            w->delay = 2;
        }
        for (i = 0; i < 4; i++) {
            w->lines[i]->vfunc_8c();
        }
        w->unk_04->vfunc_8c();
        if (w->delay != 0) {
            w->delay--;
        }
    }
}

void func_ov002_021e28b0(Ov002Hud *self);

void Ov002HudInfo_Draw(Ov002HudInfo *self, Model *model);

void func_ov002_021e2528(Ov002Hud *self) {
    s32 i;
    if (self->pending) {
        return;
    }
    func_ov002_021e28b0(self);
    {
        Model *m = self->unk_08;
        m->unk_10c = 0;
        m->unk_110 = 0;
    }
    Model_PlayPart(self->unk_08, 0);
    for (i = 0; i < 5; i++) {
        Ov002Caption *e = self->captions[i];
        if (e->anim != NULL) {
            e->anim->vfunc_20(e->x + (e->unk_1c - e->anim->width) / 2, e->y);
            e->anim->vfunc_90();
        }
    }
    if (self->info != NULL) {
        Ov002HudInfo_Draw(self->info, self->unk_0c);
    }
    Model_PlayPart(self->unk_04, 0);
}

void Ov002Hud_SetRow(Ov002Hud *self, u8 row, int force) {
    void *res = data_02149ef8;
    u16 *ids = data_ov002_021ef058[row];
    s32 i;
    for (i = 0; i < 5; i++) {
        u16 id = ids[i];
        s32 s;
        Ov002Caption *c;
        if (force == 0 && id == data_ov002_021ef058[self->row][i]) {
            continue;
        }
        s = (s32)MsgRes_GetString(res, id);
        c = self->captions[i];
        if (s != 0) {
            c->text = s;
            {
                s32 tx = c->nextX - 0x80;
                s32 ty = c->nextY;
                c->fromX = c->x;
                c->fromY = c->y;
                c->toX = tx;
                c->toY = ty;
            }
            // The first timer store is dead, but it makes 8 take r4 ahead of 3.
            c->timer = 8;
            c->mode = 3;
            c->timer = 8;
        }
    }
    self->row = row;
}

}
