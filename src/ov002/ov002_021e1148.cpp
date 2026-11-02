#include "ov002/ov002.h"

typedef struct ov002_Info021e1148 {
    u8 unk0[6];
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 b3 : 1;
    u16 b4 : 1;
    u16 b5 : 1;
    u16 b6 : 1;
    u16 b7 : 1;
    u16 b8 : 1;
} ov002_Info021e1148;

extern "C" {

s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void TextWin_InitLines(Ov002Text2 *a, int b);

static inline void ov002_Anim1148_Start(Ov002Text2 *s, s32 str) {
    s->str = str;
    s->unk_4c = Text_Measure(s->font, s->spacing, s->str, &s->width, &s->height, s->unk_37 != 0 ? TRUE : FALSE);
    data_02097ce0->unk_004 = s->font;
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

void func_ov002_021e1148(Ov002HudInfo *self, u16 id) {
    void *mgr;
    int i;
    ov002_Info021e1148 *info;
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
    info = (ov002_Info021e1148 *)func_0206ef10(id);
    mgr = data_02149ef8;
    if (id == 0x8008) {
        s32 text = (s32)MsgRes_GetString(data_02149ef8, 0x15f);
        Ov002Text2 *a = self->lines[0];
        if (a != NULL) {
            ov002_Anim1148_Show(a, text, 3, 0);
        }
    } else {
        s32 n = 0;
        if (info->b0) {
            ov002_Slot1148(self, &n, (s32)MsgRes_GetString(data_02149ef8, 0x156));
        }
        if (info->b1) {
            ov002_Slot1148(self, &n, (s32)MsgRes_GetString(mgr, 0x157));
        }
        if (info->b2) {
            ov002_Slot1148(self, &n, (s32)MsgRes_GetString(mgr, 0x158));
        }
        if (info->b3) {
            ov002_Slot1148(self, &n, (s32)MsgRes_GetString(mgr, 0x159));
        }
        if (info->b4) {
            ov002_Slot1148(self, &n, (s32)MsgRes_GetString(mgr, 0x15a));
        }
        if (info->b5) {
            ov002_Slot1148(self, &n, (s32)MsgRes_GetString(mgr, 0x15b));
        }
        if (info->b6) {
            ov002_Slot1148(self, &n, (s32)MsgRes_GetString(mgr, 0x15c));
        }
        if (info->b7) {
            ov002_Slot1148(self, &n, (s32)MsgRes_GetString(mgr, 0x15d));
        }
        if (info->b8) {
            ov002_Slot1148(self, &n, (s32)MsgRes_GetString(mgr, 0x15e));
        }
    }
    {
        s32 text = (s32)func_0206ec48(id);
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
