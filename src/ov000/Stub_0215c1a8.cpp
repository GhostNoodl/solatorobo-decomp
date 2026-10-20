#include "ov000/LoCommon.h"
#include "ov000/VObj.h"

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

extern "C" {

void func_ov000_0215c1a8(void *self, s32 *msg) {
    if (msg[0] == 0x10) {
        *(s32 *)self = msg[1];
    }
}

extern VFunc0215c1bc data_0208ba70[];
extern char data_ov000_021cabf4[];
extern u8 *data_02097ce0;
void *func_0203dd9c(u32 size);
void *func_0203de84(u32 size, u32 align);
void func_0204c7d0(void *p);
s32 func_0204c4fc(s32 a, s32 b, char *c, void *d, void *e, BOOL f);
void func_0204c6bc(char *s, s32 a, s32 *out, void *cb);
char *STD_SearchString(const char *s, const char *t);
s32 STD_GetStringLength(const char *s);
void STD_CopyString(char *d, const char *s);

static inline BOOL Bit3_0215c1bc(VObj *self) {
    return LBIT(self, 0xc).b3 ? TRUE : FALSE;
}

static inline BOOL Bit6_0215c1bc(VObj *self) {
    return LBIT(self, 0xc).b6 ? TRUE : FALSE;
}

void func_ov000_0215c1bc(VObj *self, u32 flags, char *str) {
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
    LFLD(u32, self, 0x84) = flags;
    LFLD(u16, self, 0x88) = 0;
    LFLD(s32, self, 0x94) = 1;
    if (flags & 0x8000) {
        switch (flags & 0x30) {
        case 0x10:
            LFLD(s32, self, 0x1c) = 4;
            LFLD(u32, self, 0xc) |= 0x20000;
            break;
        case 0x20:
            LFLD(s32, self, 0x1c) = 8;
            break;
        }
        switch (flags & 3) {
        case 1:
            LFLD(u16, self, 0x48) = 0;
            break;
        case 2:
            LFLD(u16, self, 0x48) = 0x2803;
            break;
        }
        switch (flags & 0xc) {
        case 4:
            LFLD(u32, self, 0xc) &= ~0x20000;
            break;
        case 8:
            LFLD(u32, self, 0xc) |= 0x20000;
            break;
        }
    }
    for (i = 0; i < 13; i++) {
        lines[i] = NULL;
    }
    if (STD_SearchString(str, data_ov000_021cabf4) != NULL) {
        LFLD(char *, self, 0x90) = (char *)func_0203de84(STD_GetStringLength(str) + 1, 4);
        STD_CopyString(LFLD(char *, self, 0x90), str);
        str = LFLD(char *, self, 0x90);
        p = STD_SearchString(str, data_ov000_021cabf4);
        lines[1] = p;
        for (i = 1; i < 12; i++) {
            if (p != NULL) {
                *p++ = 0;
                LFLD(s32, self, 0x94)++;
                p = STD_SearchString(p, data_ov000_021cabf4);
                lines[i + 1] = p;
            }
        }
    }
    n = LFLD(s32, self, 0x94);
    if (n < 2) {
        n = 2;
    }
    if (Bit3_0215c1bc(self)) {
        LFLD(s32, self, 0x24) = 0x100;
    } else {
        LFLD(s32, self, 0x24) = 0xd3;
    }
    LFLD(s32, self, 0x20) = n;
    LFLD(s32, self, 0x28) = self->vfunc_44();
    font = 0;
    func_0204c6bc(str, 1, &font, (void *)func_ov000_0215c1a8);
    f = font;
    tt = (Text0215c1bc *)func_0203dd9c(0xb8);
    if (tt != NULL) {
        tt->vtbl = data_0208ba70;
        func_0204c7d0(tt);
    }
    tt->unk_28 = LFLD(s32, self, 0x1c);
    tt->unk_2c = f;
    ((TextFlags0215c1bc *)&tt->flags)->b6 = 1;
    ((TextFlags0215c1bc *)&tt->flags)->b24 = 1;
    ((TextFlags0215c1bc *)&tt->flags)->b22 = 1;
    ((TextFlags0215c1bc *)&tt->flags)->b30 = 1;
    if (Bit6_0215c1bc(self)) {
        ((TextFlags0215c1bc *)&tt->flags)->b31 = true;
    }
    LFLD(Text0215c1bc *, self, 0x98) = tt;
    tt->str = str;
    tt->unk_4c = func_0204c4fc(tt->unk_28, tt->unk_38, tt->str, &tt->unk_44, &tt->unk_48, tt->unk_37 != 0);
    LFLD(s32, data_02097ce0, 4) = tt->unk_28;
    for (i = 1; i < 12; i++) {
        if (lines[i] != NULL) {
            lines[i]++;
            f = font;
            tt = (Text0215c1bc *)func_0203dd9c(0xb8);
            if (tt != NULL) {
                tt->vtbl = data_0208ba70;
                func_0204c7d0(tt);
            }
            tt->unk_28 = LFLD(s32, self, 0x1c);
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
            tt->unk_4c = func_0204c4fc(tt->unk_28, tt->unk_38, tt->str, &tt->unk_44, &tt->unk_48, tt->unk_37 != 0);
            LFLD(s32, data_02097ce0, 4) = tt->unk_28;
        }
    }
    w = LFLD(s32, self, 0x24) - self->vfunc_30() * 2;
    for (i = 0; i < 12; i++) {
        t = ((Text0215c1bc **)((u8 *)self + 0x98))[i];
        if (t != NULL && t->unk_44 > w) {
            w = t->unk_44;
        }
    }
    LFLD(s32, self, 0x24) = w + self->vfunc_30() * 2;
    if (LFLD(s32, self, 0x24) > 0x100) {
        LFLD(s32, self, 0x24) = 0x100;
    }
    LFLD(s16, self, 0x64) = (0x100 - LFLD(s32, self, 0x24)) >> 1;
    LFLD(s16, self, 0x66) = (0xc0 - LFLD(s32, self, 0x28)) >> 1;
    x = (LFLD(s32, self, 0x24) >> 1) - (LFLD(Text0215c1bc *, self, 0x98)->unk_44 >> 1);
    if (lines[1] != NULL) {
        y = self->vfunc_34();
    } else {
        y = (LFLD(s32, self, 0x28) >> 1) - (self->vfunc_40() >> 1);
    }
    LFLD(VObj *, self, 0x98)->vfunc_20(x, y);
    if (!(LFLD(u32, self, 0xc) & 0x10000)) {
        s32 by;
        s32 bx;
        bx = LFLD(s16, self, 0x64) + LFLD(s32, self, 0x24) - self->vfunc_30();
        by = LFLD(s16, self, 0x66) + LFLD(s32, self, 0x28) - self->vfunc_38();
        if (Bit3_0215c1bc(self)) {
            by += 4;
        }
        if (LFLD(s32, self, 0x94) == 1) {
            by -= self->vfunc_40() >> 2;
        }
        LFLD(VObj *, self, 0x98)->vfunc_1c(bx, by, LFLD(s16, self, 0x68));
    }
    for (i = 1; i < 12; i++) {
        if (((VObj **)((u8 *)self + 0x98))[i] != NULL) {
            x = (LFLD(s32, self, 0x24) >> 1) - (LFLD(s32, ((VObj **)((u8 *)self + 0x98))[i], 0x44) >> 1);
            y = self->vfunc_34();
            y += i * self->vfunc_40();
            ((VObj **)((u8 *)self + 0x98))[i]->vfunc_20(x, y);
        }
    }
}

}
