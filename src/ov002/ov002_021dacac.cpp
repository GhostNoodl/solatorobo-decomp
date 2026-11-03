#include "ov002/ov002.h"

extern "C" {

extern VFunc data_ov000_021cadcc[];
extern u8 data_ov002_021efe30[];
int func_ov002_021dac8c(UiList *self, UiListItem *item);
BOOL func_ov000_0219d5a0(void);
void *ListOwner_GetNth(void *a, u8 b);

static inline void ov002_SetId(Ov002Hud *x, u16 id) {
    if (x != NULL) {
        Ov002Hud_SetInfo(x, id);
    }
}

static inline void ov002_CamInit(Obj021efe6c *c, const VecFx32 *pos) {
    c->unk_90 = 15;
    c->unk_94 = 15;
    c->unk_98 = c->cam->eye;
    c->unk_a4 = c->cam->at;
    if (pos != NULL) {
        c->unk_b0 = *pos;
    }
    c->unk_bc.x = -0x2b8;
    c->unk_bc.y = 0;
    c->unk_bc.z = 0x2b8;
}

void func_ov002_021dacac(Obj021eff74 *self) {
    void *g = data_02149ef8;
    UiObj *o;
    VObj *m;
    UiObj *s;
    Obj021efe6c *w;
    Task021efba4 *t;
    o = (UiObj *)Heap_Alloc(0xd4);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(VFunc **)o = data_ov000_021caec8;
        o->vfunc_28();
    }
    self->unk_0c = (UiList *)o;
    self->unk_0c->vfunc_10(MsgRes_GetString(g, 0xba));
    self->unk_0c->vfunc_14(MsgRes_GetString(g, 0xbb));
    self->unk_0c->rows = 2;
    self->unk_0c->width = 0x78;
    s = self->unk_0c;
    s->posX = 0;
    s->posY = 0x1e;
    s->posZ = -0x2000;
    self->unk_0c->posZ = -0x2000;
    s = self->unk_0c;
    s->slideX = -0xff;
    s->slideY = 0;
    s->slideZ = -0x2000;
    self->unk_0c->flags &= ~0x400000;
    self->unk_0c->flags &= ~0x80000;
    self->unk_0c->flags &= ~0x40000;
    self->unk_0c->flags |= 0x800000;
    self->unk_0c->owner = self;
    self->unk_0c->onDecide = (UiItemFn)func_ov002_021dac8c;
    self->unk_0c->vfunc_74(MsgRes_GetString(g, 0xbc), 0, 0xffff, 0xffff);
    if (DataRes_ReadEntry(data_02fe152c, 5, 1, 1)) {
        UiListItem *e = (UiListItem *)self->unk_0c->vfunc_74(MsgRes_GetString(g, 0xbe), 1, 0xffff, 0xffff);
        if (ActorMgr_FindPlayer()) {
            if ((self->unk_20 = func_ov000_0219d5a0()) != 0) {
                e->unk_24 = 0xe;
            }
        }
    }
    self->unk_0c->vfunc_74(MsgRes_GetString(g, 0xfa), 2, 0xffff, 0xffff);
    m = self->unk_0c;
    m->vfunc_a8(ListOwner_GetNth(m, data_ov002_021f0f90.unk_00));
    self->unk_0c->flags &= ~0x20000;
    self->unk_0c->flags &= ~0x40000;
    self->unk_0c->flags &= ~0x10000;
    self->unk_0c->vfunc_08();
    o = (UiObj *)Heap_Alloc(0x8c);
    if (o != NULL) {
        *(VFunc **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(VFunc **)o = data_ov000_021cadcc;
        o->vfunc_28();
    }
    self->unk_10 = (Lo021cadcc *)o;
    o->width = 0xf8;
    self->unk_10->rows = 2;
    s = self->unk_10;
    s->posX = 4;
    s->posY = 0x96;
    s->posZ = -0x2000;
    s = self->unk_10;
    s->slideX = -0x100;
    s->slideY = 0;
    s->slideZ = -0x2000;
    self->unk_10->slideMode = 1;
    self->unk_10->vfunc_08();
    {
        u8 kind = data_ov002_021f0f90.unk_00;
        if (self->unk_10 != NULL) {
            void *str;
            void *g2 = data_02149ef8;
            switch (kind) {
            case 0:
                str = MsgRes_GetString(g2, 0xbd);
                break;
            case 1:
                str = MsgRes_GetString(g2, 0xbf);
                break;
            case 2:
                str = MsgRes_GetString(g2, 0xfb);
                break;
            default:
                str = data_ov002_021efe30;
                break;
            }
            Obj0215bb14_SetText(self->unk_10, str);
            self->unk_10->vfunc_70();
        }
    }
    ov002_CamInit(self->board, (const VecFx32 *)(data_ov002_021eef74 + 0x70));
    if (func_ov002_isMode4()) {
        GfxSys_StartFadeIn(0xa000, 0, -1);
    }
    {
        Obj021efe6c *c = self->board;
        c->unk_74 = 0;
        c->unk_75 = 1;
    }
    w = self->board;
    if (data_0214a424->bits18.mode == 1) {
        func_ov000_021c9544(w->unk_76, w->pieces);
        Obj021c95ac_Init_021c95ac(w->unk_76, data_0214a424->bits18.unk_3 | 0x8000);
    } else {
        func_ov000_021c9544(w->unk_76, w->pieces);
    }
    t = (Task021efba4 *)Task_FindById(0x1b);
    if (t != NULL && data_0214a424->bits18.mode == 1) {
        ov002_SetId(t->hud, data_0214a424->bits18.unk_3 | 0x8000);
    }
}

}
