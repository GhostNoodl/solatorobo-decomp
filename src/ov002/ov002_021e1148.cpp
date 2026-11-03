#include "ov002/ov002.h"

extern "C" {

s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void TextWin_InitLines(Ov002Text2 *a, int b);

static inline void ov002_Anim1148_Start(Ov002Text2 *s, s32 str) {
    s->str = str;
    s->unk_4c = Text_Measure(s->font, s->spacing, s->str, &s->width, &s->height, s->unk_37 != 0 ? TRUE : FALSE);
    gGfxMgr->unk_004 = s->font;
}

static inline void ov002_Anim1148_Show(Ov002Text2 *a, s32 text, s32 font, s32 pal) {
    a->vfunc_08();
    a->font = font;
    a->unk_2c = pal;
    a->unk_34 = 0;
    ov002_Anim1148_Start(a, text);
    TextWin_InitLines(a, 0xc);
    a->flags |= 4;
}

static inline void ov002_Slot1148(Ov002HudInfo *self, s32 *n, s32 text) {
    if (*n < 4) {
        Ov002Text2 *a = self->lines[*n];
        if (a != NULL) {
            ov002_Anim1148_Show(a, text, 3, 0);
        }
    }
    (*n)++;
}

void Ov002HudInfo_SetId(Ov002HudInfo *self, u16 id) {
    void *mgr;
    int i;
    Param0206ef10 *info;
    for (i = 0; i < 4; i++) {
        Ov002Text2 *o = self->lines[i];
        if (o != NULL) {
            o->vfunc_08();
        }
    }
    self->unk_04->vfunc_08();
    if (id == 0xffff) {
        return;
    }
    info = func_0206ef10(id);
    mgr = gMsgRes;
    if (id == 0x8008) {
        s32 text = (s32)MsgRes_GetString(gMsgRes, 0x15f);
        Ov002Text2 *a = self->lines[0];
        if (a != NULL) {
            ov002_Anim1148_Show(a, text, 3, 0);
        }
    } else {
        s32 n = 0;
        if (info->unk_06_0) {
            ov002_Slot1148(self, &n, (s32)MsgRes_GetString(gMsgRes, 0x156));
        }
        if (info->unk_06_1) {
            ov002_Slot1148(self, &n, (s32)MsgRes_GetString(mgr, 0x157));
        }
        if (info->unk_06_2) {
            ov002_Slot1148(self, &n, (s32)MsgRes_GetString(mgr, 0x158));
        }
        if (info->unk_06_3) {
            ov002_Slot1148(self, &n, (s32)MsgRes_GetString(mgr, 0x159));
        }
        if (info->unk_06_4) {
            ov002_Slot1148(self, &n, (s32)MsgRes_GetString(mgr, 0x15a));
        }
        if (info->unk_06_5) {
            ov002_Slot1148(self, &n, (s32)MsgRes_GetString(mgr, 0x15b));
        }
        if (info->unk_06_6) {
            ov002_Slot1148(self, &n, (s32)MsgRes_GetString(mgr, 0x15c));
        }
        if (info->unk_06_7) {
            ov002_Slot1148(self, &n, (s32)MsgRes_GetString(mgr, 0x15d));
        }
        if (info->unk_06_8) {
            ov002_Slot1148(self, &n, (s32)MsgRes_GetString(mgr, 0x15e));
        }
    }
    {
        s32 text = (s32)Param_Get(id);
        if (self->unk_04 == NULL) {
            return;
        }
        self->unk_04->vfunc_08();
        self->unk_04->font = 7;
        self->unk_04->unk_2c = 4;
        self->unk_04->unk_34 = 0;
        ov002_Anim1148_Start(self->unk_04, text);
        TextWin_InitLines(self->unk_04, 0xc);
        self->unk_04->flags |= 4;
    }
}

}
