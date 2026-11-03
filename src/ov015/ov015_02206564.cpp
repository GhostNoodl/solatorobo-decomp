#include "ov015/ov015.h"

extern "C" {

extern u8 gTaskSwitchPending;
extern void *gMsgRes;
void *MsgRes_GetString(void *a, int id);
u8 *func_0206f000(u16 id);
BOOL Item_Give(u16 id, s32 n);
BOOL Item_Set_0206f5e4(u16 id, s32 n);
void Obj0215c1bc_SetText(void *a, s32 b, void *c);
extern Ov015Globals gOv015Globals;
void TaskHost_Create(s32 a, s32 b);
extern u8 data_ov015_02213360[];

void Ov015Scene2b08_UpdateActive(Ov015Scene2b08 *self) {
    Pad *pd = gPad;
    u16 pad = pd->trig;
    BOOL on = self->unk_4c->hidden ? TRUE : FALSE;
    if (!on) {

        return;
    }
    if (!(pad & 2)) {
        return;
    }
    SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
    self->unk_54 = 0;
    self->unk_3c->flags |= 2;
    self->unk_44->flags |= 2;
    self->unk_40->flags |= 2;
    self->unk_48->flags |= 2;
    self->unk_50->flags |= 2;
    TaskHost_RequestSwitch(gTaskHost, 0x1f, self->param);
    self->unk_04 |= 6;
}

static inline BOOL Ov015_IsFinished(UiObj *o) {
    BOOL r = FALSE;
    if (o->hidden ? TRUE : FALSE) {
        if (o->vfunc_0c() == 0) r = TRUE;
    }
    return r;
}
void Ov015Scene2b08_PreUpdate(Ov015Scene2b08 *self) {
    switch (self->state) {
    case 8:
        SndMgr_PlayVolume(gSndMgr, 0x27, -1, -1, -1);
        break;
    case 0xa:
        SndMgr_PlayVolume(gSndMgr, 0x27, -1, -1, -1);
        break;
    }
    if (!Ov015_IsFinished(self->unk_4c) || !Ov015_IsFinished(self->unk_50)) {
        gTaskSwitchPending = 1;
        self->unk_3c->flags |= 4;
    } else {
        gTaskSwitchPending = 0;
        self->unk_3c->flags &= ~4;
    }

    self->unk_3c->vfunc_1c();
    self->unk_40->vfunc_1c();
    self->unk_44->vfunc_1c();
    self->unk_48->vfunc_1c();
    self->unk_4c->vfunc_1c();
    self->unk_50->vfunc_1c();
}

static inline bool Ov015Child_Is2(Ov015Child *c) {
    return c->state == 2;
}

bool Ov015Vt_02212d3c_IsShown(Ov015Child *self) {
    BOOL r = Ov015Child_Is2(self);
    return r;
}

void Ov015Scene2b08_PostUpdate(Ov015Scene2b08 *self) {
    s32 a = self->unk_58;
    s32 r = 0;
    if (a < 0x1000000) {
        r = a + 0x8000;
    }
    self->unk_58 = r;
    if (self->unk_5c <= 0) {
        self->unk_5c = 0x1000000;
    } else {
        self->unk_5c -= 0x8000;
    }
}

void Ov015Scene2b08_Draw(Ov015Scene2b08 *self) {
    if (self->vfunc_28() == 0) {
        return;
    }
    Task_Draw(self);
    self->unk_3c->vfunc_20();
    self->unk_40->vfunc_20();
    self->unk_44->vfunc_20();
    self->unk_48->vfunc_20();
    self->unk_4c->vfunc_20();
    self->unk_50->vfunc_20();
}

static inline UiListItem *Ov015_ListNth3(UiList *o) {
    UiListItem *p = o->topItem;
    s32 n;
    if (p == NULL) return NULL;
    n = o->cursor;
    while (n-- != 0) {
        p = p->next;
    }
    return p;
}
static inline void Ov015_ShopMsg(Ov015Scene2b08 *self, s32 id) {
    Obj0215c1bc_SetText(self->unk_50, 0x8000, MsgRes_GetString(gMsgRes, id));
    self->unk_50->flags &= ~2;
    self->unk_50->vfunc_70();
}
static inline void Ov015_SetMoney24(u16 v) {
    if (v > 9999) v = 9999;
    gStageFlags->unk_024 = v;
}
BOOL func_ov015_02206888(Ov015Scene2b08 *self) {
    UiListItem *item = Ov015_ListNth3(self->unk_3c);
    u16 id = item->unk_10;
    u8 *def = func_0206f000(id);
    BOOL consume = TRUE;
    BOOL r = TRUE;
    if (self->unk_40->value < item->unk_0c) {
        if (self->unk_50 != NULL) Ov015_ShopMsg(self, 0x9c);
        return FALSE;
    }
    switch (def[0]) {
    case 0:
        if (gStageFlags->itemTotal >= 100) {
            if (self->unk_50 != NULL) Ov015_ShopMsg(self, 0x9e);
            r = FALSE;
        } else {
            Item_Give(FLD(u16, def, 0x2), consume);
            if (def[1] == 0) consume = FALSE;
        }
        break;
    case 1: {
        u32 s = def[1] + gStageFlags->unk_024;
        if (s > 9999) s = 9999;
        Ov015_SetMoney24(s);
        break;
    }
    }
    if (r) {
        Lo021cae48_SetValue(self->unk_40, self->unk_40->value - item->unk_0c, 0);
        if (consume) {
            self->unk_3c->vfunc_70(item);
            Item_Set_0206f5e4(id, 1);
        }
        {
            StageFlags *save = gStageFlags;
            u32 m = self->unk_40->value;
            if (m > 99999) m = 99999;
            save->unk_618 = m;

        }
    }
    return r;
}

void func_ov015_02206aa0(Ov015SceneSeq *self) {
    self->unk_08 = 1;
    self->scene = NULL;
    self->next = 5;
}

BOOL func_ov015_02206abc(void) {
    TaskHost_Create(0x1e, gOv015Globals.mainSeq->unk_04);
    return TRUE;
}

BOOL func_ov015_02206ae0(void) {
    BOOL r = FALSE;
    if (gFinishingTask != NULL) {
        r = TRUE;
    }
    return r;
}

BOOL func_ov015_02206afc(void) {
    data_ov015_02213360[0] = 0;
    data_ov015_02213360[1] = 0;
    data_ov015_02213360[2] = 0;
    return TRUE;
}

static inline bool Ov015Task_Flag1(Task *t) {
    return t->unk_04_1;
}

static inline bool Ov015Host_Flag1(TaskHost *t) {
    return t->unk_00_1;
}

BOOL func_ov015_02206b1c(Ov015SceneSeq *self) {
    BOOL r;
    Task *t;
    self->scene = gFinishingTask;
    r = TRUE;
    {
        BOOL b = Ov015Host_Flag1(gTaskHost);
        if (b) {
            r = FALSE;
        }
    }
    t = self->scene;
    if (t != NULL && Ov015Task_Flag1(t) != 0) {
        switch (t->id) {
        case 0x1f:
            self->next = ((Ov015Scene2a08 *)t)->unk_94;
            break;
        case 0x20:
            self->next = ((Ov015Scene2c08 *)t)->unk_58;
            break;
        case 0x21:
            self->next = ((Ov015Scene2b88 *)t)->unk_50;
            break;
        case 0x22:
            self->next = ((Ov015Scene2b08 *)t)->unk_54;
            break;
        }
    }
    return r;
}

void func_ov015_02206bcc(void) {
}

s32 func_ov015_02206bd0(Ov015SceneSeq *self) {
    s32 r;
    switch (self->next) {
    case 4:
        r = 2;
        break;
    case 5:
        r = 3;
        break;
    }
    return r;
}


typedef struct {
    u32 y : 8;
    u32 attr0hi : 8;
    u32 x : 9;
    u32 attr1hi : 7;
    u32 charName : 10;
    u32 prio : 2;
    u32 pal : 4;
    u32 attr3 : 16;
} Ov015Oam;

typedef struct {
    u32 sizeS;
    u32 sizeT;
    u32 fmt;
    u32 bExtendedPlt;
    u32 plttUse;
    u32 mappingType;
} Ov015ImgAttr;

extern u32 data_ov015_02212600[];
void Oam_GetSize(const Ov015Oam *attr, u32 *w, u32 *h);

static inline void Ov015_G3Cmd2(u32 op, u32 a, u32 b) {
    u32 v[2];
    v[0] = a;
    v[1] = b;
    NNS_G3dGeBufferOP_N(op, v, 2);
}

static inline void Ov015_G3Cmd1(u32 op, u32 v) {
    u32 a = v;
    NNS_G3dGeBufferOP_N(op, &a, 1);
}

void func_ov015_02206bf0(s32 idx, s32 x, s32 y, s32 z, s32 unused, Ov015Oam *oam,
                         const Ov015ImgAttr *img, u32 charBase, u32 plttBase, s32 unused2, const s32 *ofs) {
    s32 mv[3];
    s32 tv[3];
    s32 sv[3];
    u32 fmt;
    u32 pal;
    u32 h;
    u32 w;
    s32 shift;
    u16 charName;
    s32 ox;
    s32 oy;

    charName = (u16)oam->charName;
    shift = ((s32)(img->mappingType & 0x700000) >> 20) + 5;
    ox = ofs[0];
    oy = ofs[1];
    Oam_GetSize(oam, &w, &h);
    *(vu32 *)0x40004a8 = ((charBase + (charName << shift)) >> 3) | (img->fmt << 26) | 0x40000000 | (w << 20) |
                         (h << 23) | 0x30000 | (img->plttUse << 29);
    fmt = data_ov015_02212600[(*(u32 *)oam << 18) >> 31];
    if (img->bExtendedPlt != 0) {
        pal = (u16)oam->pal << 9;
    } else if (fmt == 4) {
        pal = 0;
    } else {
        pal = (u16)oam->pal << 5;
    }
    *(vu32 *)0x40004ac = (plttBase + pal) >> (4 - (fmt == 2));
    Ov015_G3Cmd1(0x10, 3);
    mv[0] = ox & -0x1000;
    mv[1] = oy & -0x1000;
    mv[2] = 0;
    NNS_G3dGeBufferOP_N(0x1c, (unsigned int *)mv, 3);
    Ov015_G3Cmd1(0x10, 2);
    NNS_G3dGeBufferOP_N(0x11, NULL, 0);
    tv[0] = x - 0x80000;
    tv[1] = y - 0x60000;
    tv[2] = z;
    NNS_G3dGeBufferOP_N(0x1c, (unsigned int *)tv, 3);
    sv[0] = 0x100000;
    sv[1] = 0xc0000;
    sv[2] = 0x1000;
    NNS_G3dGeBufferOP_N(0x1b, (unsigned int *)sv, 3);
    Ov015_G3Cmd1(0x40, 1);
    Ov015_G3Cmd1(0x20, 0x2214);
    Ov015_G3Cmd1(0x22, 0xc000000);
    Ov015_G3Cmd2(0x23, 0x10000000, 0);
    Ov015_G3Cmd1(0x22, 0xc001000);
    Ov015_G3Cmd1(0x25, 0x10001000);
    Ov015_G3Cmd1(0x20, 0x7fff);
    Ov015_G3Cmd1(0x22, 0x1000);
    Ov015_G3Cmd1(0x25, 0x1000);
    Ov015_G3Cmd1(0x22, 0);
    Ov015_G3Cmd1(0x25, 0);
    NNS_G3dGeBufferOP_N(0x41, NULL, 0);
    Ov015_G3Cmd1(0x12, 1);
}

}
