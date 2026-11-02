#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "nitro/std.h"
#include "ov000/VObj.h"
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

void func_ov000_0215c1a8(void *self, s32 *msg) {
    if (msg[0] == 0x10) {
        *(s32 *)self = msg[1];
    }
}

extern VFunc0215c1bc data_0208ba70[];
extern char data_ov000_021cabf4[];
void *Heap_Alloc(u32 size);
void TextWin_Init(void *p);
s32 Text_Measure(s32 a, s32 b, char *c, void *d, void *e, BOOL f);
void Text_ScanTags(char *s, s32 a, s32 *out, void *cb);

static inline BOOL Bit3_0215c1bc(VObj *self) {
    return LBIT(self, 0xc).b3 ? TRUE : FALSE;
}

static inline BOOL Bit6_0215c1bc(VObj *self) {
    return LBIT(self, 0xc).b6 ? TRUE : FALSE;
}

struct Obj0215c1bc : public VObj {
    u8 unk_04[0x8];
    u32 unk_0c;
    u8 unk_10[0xc];
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    u8 unk_2c[0x1c];
    u16 unk_48;
    u8 unk_4a[0x1a];
    s16 unk_64;
    s16 unk_66;
    s16 unk_68;
    u8 unk_6a[0x1a];
    u32 unk_84;
    u16 unk_88;
    u8 unk_8a[0x6];
    char *unk_90;
    s32 unk_94;
    Text0215c1bc *unk_98;
};

void Obj0215c1bc_SetText(Obj0215c1bc *self, u32 flags, char *str) {
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
            self->unk_1c = 4;
            self->unk_0c |= 0x20000;
            break;
        case 0x20:
            self->unk_1c = 8;
            break;
        }
        switch (flags & 3) {
        case 1:
            self->unk_48 = 0;
            break;
        case 2:
            self->unk_48 = 0x2803;
            break;
        }
        switch (flags & 0xc) {
        case 4:
            self->unk_0c &= ~0x20000;
            break;
        case 8:
            self->unk_0c |= 0x20000;
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
        self->unk_24 = 0x100;
    } else {
        self->unk_24 = 0xd3;
    }
    self->unk_20 = n;
    self->unk_28 = self->vfunc_44();
    font = 0;
    Text_ScanTags(str, 1, &font, (void *)func_ov000_0215c1a8);
    f = font;
    tt = (Text0215c1bc *)Heap_Alloc(0xb8);
    if (tt != NULL) {
        tt->vtbl = data_0208ba70;
        TextWin_Init(tt);
    }
    tt->unk_28 = self->unk_1c;
    tt->unk_2c = f;
    ((TextFlags0215c1bc *)&tt->flags)->b6 = 1;
    ((TextFlags0215c1bc *)&tt->flags)->b24 = 1;
    ((TextFlags0215c1bc *)&tt->flags)->b22 = 1;
    ((TextFlags0215c1bc *)&tt->flags)->b30 = 1;
    if (Bit6_0215c1bc(self)) {
        ((TextFlags0215c1bc *)&tt->flags)->b31 = true;
    }
    self->unk_98 = tt;
    tt->str = str;
    tt->unk_4c = Text_Measure(tt->unk_28, tt->unk_38, tt->str, &tt->unk_44, &tt->unk_48, tt->unk_37 != 0);
    data_02097ce0->unk_004 = tt->unk_28;
    for (i = 1; i < 12; i++) {
        if (lines[i] != NULL) {
            lines[i]++;
            f = font;
            tt = (Text0215c1bc *)Heap_Alloc(0xb8);
            if (tt != NULL) {
                tt->vtbl = data_0208ba70;
                TextWin_Init(tt);
            }
            tt->unk_28 = self->unk_1c;
            tt->unk_2c = f;
            ((TextFlags0215c1bc *)&tt->flags)->b6 = 1;
            ((TextFlags0215c1bc *)&tt->flags)->b24 = 1;
            ((TextFlags0215c1bc *)&tt->flags)->b22 = 1;
            ((TextFlags0215c1bc *)&tt->flags)->b30 = 1;
            if (Bit6_0215c1bc(self)) {
                ((TextFlags0215c1bc *)&tt->flags)->b31 = true;
            }
            ((Text0215c1bc **)((u8 *)self + 0x98))[i] = tt;
            tt->str = lines[i];
            tt->unk_4c = Text_Measure(tt->unk_28, tt->unk_38, tt->str, &tt->unk_44, &tt->unk_48, tt->unk_37 != 0);
            data_02097ce0->unk_004 = tt->unk_28;
        }
    }
    w = self->unk_24 - self->vfunc_30() * 2;
    for (i = 0; i < 12; i++) {
        t = ((Text0215c1bc **)((u8 *)self + 0x98))[i];
        if (t != NULL && t->unk_44 > w) {
            w = t->unk_44;
        }
    }
    self->unk_24 = w + self->vfunc_30() * 2;
    if (self->unk_24 > 0x100) {
        self->unk_24 = 0x100;
    }
    self->unk_64 = (0x100 - self->unk_24) >> 1;
    self->unk_66 = (0xc0 - self->unk_28) >> 1;
    x = (self->unk_24 >> 1) - (self->unk_98->unk_44 >> 1);
    if (lines[1] != NULL) {
        y = self->vfunc_34();
    } else {
        y = (self->unk_28 >> 1) - (self->vfunc_40() >> 1);
    }
    ((VObj *)self->unk_98)->vfunc_20(x, y);
    if (!(self->unk_0c & 0x10000)) {
        s32 by;
        s32 bx;
        bx = self->unk_64 + self->unk_24 - self->vfunc_30();
        by = self->unk_66 + self->unk_28 - self->vfunc_38();
        if (Bit3_0215c1bc(self)) {
            by += 4;
        }
        if (self->unk_94 == 1) {
            by -= self->vfunc_40() >> 2;
        }
        ((VObj *)self->unk_98)->vfunc_1c(bx, by, self->unk_68);
    }
    for (i = 1; i < 12; i++) {
        if (((VObj **)((u8 *)self + 0x98))[i] != NULL) {
            x = (self->unk_24 >> 1) - (LFLD(s32, ((VObj **)((u8 *)self + 0x98))[i], 0x44) >> 1);
            y = self->vfunc_34();
            y += i * self->vfunc_40();
            ((VObj **)((u8 *)self + 0x98))[i]->vfunc_20(x, y);
        }
    }
}

s32 func_ov000_0215c718(void) {
    return 0x14;
}

s32 func_ov000_0215c720(Obj0215c720 *self) {
    return Obj0215c720_TestBit3(self) ? 9 : 0xc;
}

extern void *data_02149ef8;
u16 func_02061d54(u16 a);
char *MsgRes_GetString(void *p, s32 a);
char *Str_FindCharMb(char *str, int c);
void Tbl_Format_02070874(char *dst, const char *fmt, const char *arg);
void func_020707e8(char *dst, const char *fmt, const char *arg, int c);
BOOL Item_Give(u16 id, int n);
void func_ov000_02184ea4(void *self, s32 a);
char *func_ov000_0215cfd0(void *self);

static inline u16 ItemKind_0215c744(u16 v) { return v >> 12; }

struct Obj0215c744 : public VObj {
    u8 unk_04[0x8];
    u32 unk_0c;
    u8 unk_10[0xc];
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    u8 unk_2c[0x38];
    s16 unk_64;
    s16 unk_66;
    s16 unk_68;
    u8 unk_6a[0x1a];
    u32 unk_84;
    u16 unk_88;
    u8 unk_8a[0x6];
    char *unk_90;
    s32 unk_94;
    Text0215c1bc *unk_98;
};

void func_ov000_0215c744(Obj0215c744 *self, u32 flags, u16 id) {
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
    { void *msg = data_02149ef8; str = MsgRes_GetString(msg, func_02061d54(flags & 0x3ff)); }
    center = FALSE;
    star = FALSE;
    for (i = 0; i < 13; i++) {
        lines[i] = NULL;
    }
    lines[0] = func_ov000_0215cfd0(self);
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
            func_020707e8(self->unk_90, str, lines[0], '*');
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
        self->unk_24 = 0x100;
    } else {
        self->unk_24 = 0xd3;
    }
    self->unk_20 = n;
    self->unk_28 = self->vfunc_44();
    if (lines[0] != NULL) {
        tt = (Text0215c1bc *)Heap_Alloc(0xb8);
        if (tt != NULL) {
            tt->vtbl = data_0208ba70;
            TextWin_Init(tt);
        }
        tt->unk_28 = self->unk_1c;
        tt->unk_2c = 0;
        ((TextFlags0215c1bc *)&tt->flags)->b6 = 1;
        ((TextFlags0215c1bc *)&tt->flags)->b24 = 1;
        ((TextFlags0215c1bc *)&tt->flags)->b22 = 1;
        ((TextFlags0215c1bc *)&tt->flags)->b30 = 1;
        if (Bit6_0215c1bc(self)) {
            ((TextFlags0215c1bc *)&tt->flags)->b31 = true;
        }
        self->unk_98 = tt;
        tt->str = lines[0];
        tt->unk_4c = Text_Measure(tt->unk_28, tt->unk_38, tt->str, &tt->unk_44, &tt->unk_48, tt->unk_37 != 0);
        data_02097ce0->unk_004 = tt->unk_28;
    }
    for (i = 1; i < 12; i++) {
        if (lines[i] != NULL) {
            lines[i]++;
            tt = (Text0215c1bc *)Heap_Alloc(0xb8);
            if (tt != NULL) {
                tt->vtbl = data_0208ba70;
                TextWin_Init(tt);
            }
            tt->unk_28 = self->unk_1c;
            tt->unk_2c = 0;
            ((TextFlags0215c1bc *)&tt->flags)->b6 = 1;
            ((TextFlags0215c1bc *)&tt->flags)->b24 = 1;
            ((TextFlags0215c1bc *)&tt->flags)->b22 = 1;
            ((TextFlags0215c1bc *)&tt->flags)->b30 = 1;
            if (Bit6_0215c1bc(self)) {
                ((TextFlags0215c1bc *)&tt->flags)->b31 = true;
            }
            ((Text0215c1bc **)((u8 *)self + 0x98))[i] = tt;
            tt->str = lines[i];
            tt->unk_4c = Text_Measure(tt->unk_28, tt->unk_38, tt->str, &tt->unk_44, &tt->unk_48, tt->unk_37 != 0);
            data_02097ce0->unk_004 = tt->unk_28;
        }
    }
    w = self->unk_24 - self->vfunc_30() * 2;
    for (i = 0; i < 12; i++) {
        t = ((Text0215c1bc **)((u8 *)self + 0x98))[i];
        if (t != NULL && t->unk_44 > w) {
            w = t->unk_44;
        }
    }
    self->unk_24 = w + self->vfunc_30() * 2;
    if (self->unk_24 > 0x100) {
        self->unk_24 = 0x100;
    }
    self->unk_64 = (0x100 - self->unk_24) >> 1;
    self->unk_66 = (0xc0 - self->unk_28) >> 1;
    if (self->unk_98 != NULL) {
        x = self->unk_98->unk_44;
        if (center) {
            x = (self->unk_24 >> 1) - (x >> 1);
        } else {
            w = self->unk_24 - self->vfunc_30() * 2;
            x = self->vfunc_30() + (w >> 1) - x - 8;
            if (x < self->vfunc_30()) {
                x = self->vfunc_30();
            }
        }
        if (lines[1] != NULL) {
            y = self->vfunc_34();
        } else {
            y = (self->unk_28 >> 1) - (self->vfunc_40() >> 1);
        }
        ((VObj *)self->unk_98)->vfunc_20(x, y);
    }
    if (!(self->unk_0c & 0x10000)) {
        s32 by;
        s32 bx;
        bx = self->unk_64 + self->unk_24 - self->vfunc_30();
        by = self->unk_66 + self->unk_28 - self->vfunc_38();
        if (Bit3_0215c1bc(self)) {
            by += 4;
        }
        if (self->unk_94 == 1) {
            by -= self->vfunc_40() >> 2;
        }
        ((VObj *)self->unk_98)->vfunc_1c(bx, by, self->unk_68);
    }
    for (i = 1; i < 12; i++) {
        if (((VObj **)((u8 *)self + 0x98))[i] != NULL) {
            x = LFLD(s32, ((VObj **)((u8 *)self + 0x98))[i], 0x44);
            if (center) {
                x = (self->unk_24 >> 1) - (x >> 1);
            } else {
                s32 lim;
                s32 r;
                y = self->unk_24;
                lim = y - self->vfunc_30() - 8;
                r = x + (y >> 1);
                x = y >> 1;
                if (r > lim) {
                    x += lim - r;
                }
            }
            y = self->vfunc_34();
            y += i * self->vfunc_40();
            ((VObj **)((u8 *)self + 0x98))[i]->vfunc_20(x, y);
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
        func_ov000_02184ea4(data_ov000_021ccd54, v);
    }
}

}
