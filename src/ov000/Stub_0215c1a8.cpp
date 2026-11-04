#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "nitro/std.h"
#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/PlttRes.h"

typedef void (*VFunc0215c1bc)(void);

typedef struct {
    u32 b0 : 6;
    u32 b6 : 1;
    u32 b7 : 15;
    u32 b22 : 1;
    u32 b23 : 1;
    u32 b24 : 1;
    u32 b25 : 5;
    u32 b30 : 1;
    u32 b31 : 1;
} TextFlags0215c1bc;

typedef struct Text0215c1bc {
    VFunc0215c1bc *vtbl;
    u32 flags;
    u8 pad08[0x1c];
    char *str;
    s32 unk_28;
    s32 unk_2c;
    u8 pad30[0x7];
    s8 unk_37;
    s32 unk_38;
    u8 pad3c[0x8];
    s32 unk_44;
    s32 unk_48;
    s32 unk_4c;
} Text0215c1bc;

typedef struct {
    u8 unk_00[0xc];
    u32 unk_0c_0 : 3;
    u32 unk_0c_3 : 1;
    u32 unk_0c_4 : 28;
} Obj0215c720;

static inline BOOL Obj0215c720_TestBit3(Obj0215c720 *self) {
    return self->unk_0c_3 ? TRUE : FALSE;
}

extern "C" {

// The Text_ScanTags callback of Obj0215c1bc_SetText / func_ov000_0215c744: tag 0x10 sets the font.
void Obj0215c1bc_ScanTagCallback(s32 *font, s32 *tag) {
    if (tag[0] == 0x10) {
        *font = tag[1];
    }
}

extern VFunc0215c1bc TextWin_vtbl[];
extern char data_ov000_021cabf4[];
void *Heap_Alloc(u32 size);
void TextWin_Init(void *p);
s32 Text_Measure(s32 a, s32 b, char *c, void *d, void *e, BOOL f);
void Text_ScanTags(char *s, s32 a, s32 *out, void *cb);

static inline BOOL Bit3_0215c1bc(UiObj *self) {
    return self->flag3 ? TRUE : FALSE;
}

static inline BOOL Bit6_0215c1bc(UiObj *self) {
    return self->flag6 ? TRUE : FALSE;
}

// Lo021cad50::unk_98 holds one TextWin (Text0215c1bc) per line.
static inline Text0215c1bc **Lo021cad50_Lines(Lo021cad50 *w) {
    return (Text0215c1bc **)w->unk_98;
}

void Obj0215c1bc_SetText(Lo021cad50 *self, u32 flags, char *str) {
    char *lines[13];
    s32 font;
    s32 i;
    char *p;
    Text0215c1bc *t;
    s32 n;
    s32 w;
    s32 x;
    s32 y;
    s32 f;
    Text0215c1bc *tt;
    self->vfunc_2c();
    self->unk_84 = flags;
    self->unk_88 = 0;
    self->unk_94 = 1;
    if (flags & 0x8000) {
        switch (flags & 0x30) {
        case 0x10:
            self->font = 4;
            self->flags |= 0x20000;
            break;
        case 0x20:
            self->font = 8;
            break;
        }
        switch (flags & 3) {
        case 1:
            self->color = 0;
            break;
        case 2:
            self->color = 0x2803;
            break;
        }
        switch (flags & 0xc) {
        case 4:
            self->flags &= ~0x20000;
            break;
        case 8:
            self->flags |= 0x20000;
            break;
        }
    }
    for (i = 0; i < 13; i++) {
        lines[i] = NULL;
    }
    if (STD_SearchString(str, data_ov000_021cabf4) != NULL) {
        self->unk_90 = (char *)Heap_AllocHi(STD_GetStringLength(str) + 1, 4);
        STD_CopyString(self->unk_90, str);
        str = self->unk_90;
        p = STD_SearchString(str, data_ov000_021cabf4);
        lines[1] = p;
        for (i = 1; i < 12; i++) {
            if (p != NULL) {
                *p++ = 0;
                self->unk_94++;
                p = STD_SearchString(p, data_ov000_021cabf4);
                lines[i + 1] = p;
            }
        }
    }
    n = self->unk_94;
    if (n < 2) {
        n = 2;
    }
    if (Bit3_0215c1bc(self)) {
        self->width = 0x100;
    } else {
        self->width = 0xd3;
    }
    self->rows = n;
    self->height = self->vfunc_44();
    font = 0;
    Text_ScanTags(str, 1, &font, (void *)Obj0215c1bc_ScanTagCallback);
    f = font;
    tt = (Text0215c1bc *)Heap_Alloc(0xb8);
    if (tt != NULL) {
        tt->vtbl = TextWin_vtbl;
        TextWin_Init(tt);
    }
    tt->unk_28 = self->font;
    tt->unk_2c = f;
    ((TextFlags0215c1bc *)&tt->flags)->b6 = 1;
    ((TextFlags0215c1bc *)&tt->flags)->b24 = 1;
    ((TextFlags0215c1bc *)&tt->flags)->b22 = 1;
    ((TextFlags0215c1bc *)&tt->flags)->b30 = 1;
    if (Bit6_0215c1bc(self)) {
        ((TextFlags0215c1bc *)&tt->flags)->b31 = true;
    }
    Lo021cad50_Lines(self)[0] = tt;
    tt->str = str;
    tt->unk_4c = Text_Measure(tt->unk_28, tt->unk_38, tt->str, &tt->unk_44, &tt->unk_48, tt->unk_37 != 0);
    gGfxMgr->unk_004 = tt->unk_28;
    for (i = 1; i < 12; i++) {
        if (lines[i] != NULL) {
            lines[i]++;
            f = font;
            tt = (Text0215c1bc *)Heap_Alloc(0xb8);
            if (tt != NULL) {
                tt->vtbl = TextWin_vtbl;
                TextWin_Init(tt);
            }
            tt->unk_28 = self->font;
            tt->unk_2c = f;
            ((TextFlags0215c1bc *)&tt->flags)->b6 = 1;
            ((TextFlags0215c1bc *)&tt->flags)->b24 = 1;
            ((TextFlags0215c1bc *)&tt->flags)->b22 = 1;
            ((TextFlags0215c1bc *)&tt->flags)->b30 = 1;
            if (Bit6_0215c1bc(self)) {
                ((TextFlags0215c1bc *)&tt->flags)->b31 = true;
            }
            Lo021cad50_Lines(self)[i] = tt;
            tt->str = lines[i];
            tt->unk_4c = Text_Measure(tt->unk_28, tt->unk_38, tt->str, &tt->unk_44, &tt->unk_48, tt->unk_37 != 0);
            gGfxMgr->unk_004 = tt->unk_28;
        }
    }
    w = self->width - self->vfunc_30() * 2;
    for (i = 0; i < 12; i++) {
        t = Lo021cad50_Lines(self)[i];
        if (t != NULL && t->unk_44 > w) {
            w = t->unk_44;
        }
    }
    self->width = w + self->vfunc_30() * 2;
    if (self->width > 0x100) {
        self->width = 0x100;
    }
    self->posX = (0x100 - self->width) >> 1;
    self->posY = (0xc0 - self->height) >> 1;
    x = (self->width >> 1) - (Lo021cad50_Lines(self)[0]->unk_44 >> 1);
    if (lines[1] != NULL) {
        y = self->vfunc_34();
    } else {
        y = (self->height >> 1) - (self->vfunc_40() >> 1);
    }
    self->unk_98[0]->vfunc_20(x, y);
    if (!(self->flags & 0x10000)) {
        s32 by;
        s32 bx;
        bx = self->posX + self->width - self->vfunc_30();
        by = self->posY + self->height - self->vfunc_38();
        if (Bit3_0215c1bc(self)) {
            by += 4;
        }
        if (self->unk_94 == 1) {
            by -= self->vfunc_40() >> 2;
        }
        self->unk_98[0]->vfunc_1c(bx, by, self->posZ);
    }
    for (i = 1; i < 12; i++) {
        if (self->unk_98[i] != NULL) {
            x = (self->width >> 1) - (Lo021cad50_Lines(self)[i]->unk_44 >> 1);
            y = self->vfunc_34();
            y += i * self->vfunc_40();
            self->unk_98[i]->vfunc_20(x, y);
        }
    }
}

s32 Lo021cad50_GetPadLeft(void) {
    return 0x14;
}

s32 Lo021cad50_GetPadTop(Obj0215c720 *self) {
    return Obj0215c720_TestBit3(self) ? 9 : 0xc;
}

extern void *gMsgRes;
u16 StageId_Strip(u16 a);
char *MsgRes_GetString(void *p, s32 a);
char *Str_FindCharMb(char *str, int c);
void Tbl_Format_02070874(char *dst, const char *fmt, const char *arg);
void Tbl_FormatChar(char *dst, const char *fmt, const char *arg, int c);
BOOL Item_Give(u16 id, int n);
void SceneCmd_Push10(void *self, s32 a);
char *Text0215cfd0_FormatValue(void *self);

static inline u16 ItemKind_0215c744(u16 v) { return v >> 12; }

void func_ov000_0215c744(Lo021cad50 *self, u32 flags, u16 id) {
    char *lines[13];
    BOOL star;
    s32 i;
    BOOL center;
    char *str;
    char *p;
    s32 len;
    s32 n;
    s32 w;
    s32 x;
    s32 y;
    Text0215c1bc *t;
    Text0215c1bc *tt;
    BOOL ok;
    u16 v;

    self->vfunc_2c();
    self->unk_88 = id;
    self->unk_94 = 1;
    self->unk_84 = flags;
    { void *msg = gMsgRes; str = MsgRes_GetString(msg, StageId_Strip(flags & 0x3ff)); }
    center = FALSE;
    star = FALSE;
    for (i = 0; i < 13; i++) {
        lines[i] = NULL;
    }
    lines[0] = Text0215cfd0_FormatValue(self);
    if (lines[0] != NULL) {
        self->unk_94++;
    }
    if (STD_SearchString(str, data_ov000_021cabf4) != NULL || Str_FindCharMb(str, '%') != NULL) {
        len = STD_GetStringLength(str) + 1;
        if (Str_FindCharMb(str, '%') != NULL) {
            self->unk_90 = (char *)Heap_AllocHi(len + STD_GetStringLength(lines[0]), 4);
            Tbl_Format_02070874(self->unk_90, str, lines[0]);
            id = 0;
            lines[0] = NULL;
            self->unk_94--;
        } else if (Str_FindCharMb(str, '*') != NULL) {
            self->unk_90 = (char *)Heap_AllocHi(len + STD_GetStringLength(lines[0]), 4);
            Tbl_FormatChar(self->unk_90, str, lines[0], '*');
            self->unk_94--;
            id = 0;
            lines[0] = NULL;
            star = TRUE;
        } else {
            self->unk_90 = (char *)Heap_AllocHi(len, 4);
            STD_CopyString(self->unk_90, str);
        }
        p = self->unk_90;
        if (lines[0] == NULL) {
            lines[0] = p;
        }
        p = STD_SearchString(p, data_ov000_021cabf4);
        lines[1] = p;
        for (i = 1; i < 12; i++) {
            if (p != NULL) {
                *p++ = 0;
                self->unk_94++;
                p = STD_SearchString(p, data_ov000_021cabf4);
                lines[i + 1] = p;
                center = TRUE;
            }
        }
    } else if (lines[0] == NULL) {
        lines[0] = str;
    } else {
        lines[1] = str - 1;
    }
    if (id == 0) {
        center = TRUE;
    }
    if (star) {
        center = FALSE;
    }
    n = self->unk_94;
    if (n < 2) {
        n = 2;
    }
    if (Bit3_0215c1bc(self)) {
        self->width = 0x100;
    } else {
        self->width = 0xd3;
    }
    self->rows = n;
    self->height = self->vfunc_44();
    if (lines[0] != NULL) {
        tt = (Text0215c1bc *)Heap_Alloc(0xb8);
        if (tt != NULL) {
            tt->vtbl = TextWin_vtbl;
            TextWin_Init(tt);
        }
        tt->unk_28 = self->font;
        tt->unk_2c = 0;
        ((TextFlags0215c1bc *)&tt->flags)->b6 = 1;
        ((TextFlags0215c1bc *)&tt->flags)->b24 = 1;
        ((TextFlags0215c1bc *)&tt->flags)->b22 = 1;
        ((TextFlags0215c1bc *)&tt->flags)->b30 = 1;
        if (Bit6_0215c1bc(self)) {
            ((TextFlags0215c1bc *)&tt->flags)->b31 = true;
        }
        Lo021cad50_Lines(self)[0] = tt;
        tt->str = lines[0];
        tt->unk_4c = Text_Measure(tt->unk_28, tt->unk_38, tt->str, &tt->unk_44, &tt->unk_48, tt->unk_37 != 0);
        gGfxMgr->unk_004 = tt->unk_28;
    }
    for (i = 1; i < 12; i++) {
        if (lines[i] != NULL) {
            lines[i]++;
            tt = (Text0215c1bc *)Heap_Alloc(0xb8);
            if (tt != NULL) {
                tt->vtbl = TextWin_vtbl;
                TextWin_Init(tt);
            }
            tt->unk_28 = self->font;
            tt->unk_2c = 0;
            ((TextFlags0215c1bc *)&tt->flags)->b6 = 1;
            ((TextFlags0215c1bc *)&tt->flags)->b24 = 1;
            ((TextFlags0215c1bc *)&tt->flags)->b22 = 1;
            ((TextFlags0215c1bc *)&tt->flags)->b30 = 1;
            if (Bit6_0215c1bc(self)) {
                ((TextFlags0215c1bc *)&tt->flags)->b31 = true;
            }
            Lo021cad50_Lines(self)[i] = tt;
            tt->str = lines[i];
            tt->unk_4c = Text_Measure(tt->unk_28, tt->unk_38, tt->str, &tt->unk_44, &tt->unk_48, tt->unk_37 != 0);
            gGfxMgr->unk_004 = tt->unk_28;
        }
    }
    w = self->width - self->vfunc_30() * 2;
    for (i = 0; i < 12; i++) {
        t = Lo021cad50_Lines(self)[i];
        if (t != NULL && t->unk_44 > w) {
            w = t->unk_44;
        }
    }
    self->width = w + self->vfunc_30() * 2;
    if (self->width > 0x100) {
        self->width = 0x100;
    }
    self->posX = (0x100 - self->width) >> 1;
    self->posY = (0xc0 - self->height) >> 1;
    if (self->unk_98[0] != NULL) {
        x = Lo021cad50_Lines(self)[0]->unk_44;
        if (center) {
            x = (self->width >> 1) - (x >> 1);
        } else {
            w = self->width - self->vfunc_30() * 2;
            x = self->vfunc_30() + (w >> 1) - x - 8;
            if (x < self->vfunc_30()) {
                x = self->vfunc_30();
            }
        }
        if (lines[1] != NULL) {
            y = self->vfunc_34();
        } else {
            y = (self->height >> 1) - (self->vfunc_40() >> 1);
        }
        self->unk_98[0]->vfunc_20(x, y);
    }
    if (!(self->flags & 0x10000)) {
        s32 by;
        s32 bx;
        bx = self->posX + self->width - self->vfunc_30();
        by = self->posY + self->height - self->vfunc_38();
        if (Bit3_0215c1bc(self)) {
            by += 4;
        }
        if (self->unk_94 == 1) {
            by -= self->vfunc_40() >> 2;
        }
        self->unk_98[0]->vfunc_1c(bx, by, self->posZ);
    }
    for (i = 1; i < 12; i++) {
        if (self->unk_98[i] != NULL) {
            x = Lo021cad50_Lines(self)[i]->unk_44;
            if (center) {
                x = (self->width >> 1) - (x >> 1);
            } else {
                s32 lim;
                s32 r;
                y = self->width;
                lim = y - self->vfunc_30() - 8;
                r = x + (y >> 1);
                x = y >> 1;
                if (r > lim) {
                    x += lim - r;
                }
            }
            y = self->vfunc_34();
            y += i * self->vfunc_40();
            self->unk_98[i]->vfunc_20(x, y);
        }
    }
    if (self->unk_88 == 0) {
        return;
    }
    if ((self->unk_84 & 0xfc00) != 0x800) {
        return;
    }
    if (!(self->unk_88 & 0xf000)) {
        return;
    }
    ok = TRUE;
    if (self->unk_84 == 0x854) {
        ok = Item_Give(self->unk_88, 1);
    }
    v = self->unk_88;
    if (ItemKind_0215c744(v) - 1 == 1 && !ok) {
        SceneCmd_Push10(gSceneCmd, v);
    }
}

}
