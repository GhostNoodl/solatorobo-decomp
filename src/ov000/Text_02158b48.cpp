#include "ov000/LoCommon.h"
#include "Main/Gfx/FieldMsg.h"
#include "nitro/std.h"
#include "ov000/ObjLayouts.h"

extern "C" {
extern char data_ov000_021cabf4[];
void func_ov000_0215429c(void *self);

void func_ov000_02158b48(Lo021cb3a8 *self) {
    u16 line;
    BOOL done;
    char *p;
    char *s;
    u8 *n;
    self->unk_64 = (0x100 - self->unk_24) >> 1;
    line = 0;
    done = FALSE;
    if (self->str == NULL) {
        self->strSize = STD_GetStringLength(self->srcStr) + 1;
        self->str = (char *)func_0203de84(self->strSize, 4);
        STD_CopyString(self->str, self->srcStr);
    }
    s = self->str;
    do {
        p = STD_SearchString(s, data_ov000_021cabf4);
        if (p != NULL) {
            *p = 0;
        } else {
            done = TRUE;
        }
        self->vfunc_74(s, line, 0xffff, 0xffff);
        s = p + 1;
        line++;
    } while (!done && *s != 0);
    func_ov000_0215429c(self);
    LFLD(s32, self->unk_ac, 0x10) = (self->unk_24 - 0x10) << 12;
    for (n = (u8 *)self->unk_94; n != NULL; n = LFLD(u8 *, n, 0x2c)) {
        if (LFLD(u16, n, 6) == 0) {
            break;
        }
    }
    self->vfunc_a8(n);
}
}

extern "C" {
void func_0204ca70(void *p);

struct Obj02158c60 : public VObj {
    u8 unk_04[0xe8];
    TextWin *unk_ec;
};

void func_ov000_02158c60(Obj02158c60 *self, s32 arg) {
    TextWin *p;
    LO_FREE_V(self, 0xec);
    p = (TextWin *)Heap_Alloc(0xb8);
    if (p != NULL) {
        VOBJ_SET_VTABLE(p, data_0208ba70);
        func_0204c7d0(p);
    }
    self->unk_ec = p;
    p->font = 8;
    p = self->unk_ec;
    p->str = arg;
    p->unk_4c = func_0204c4fc(p->font, p->spacing, p->str, &p->vramSize, &p->vramArg, (s8)p->unk_37 != 0);
    data_02097ce0->unk_004 = p->font;
    self->unk_ec->flags |= 0x40;
    self->unk_ec->flags |= 0x1000000;
    self->unk_ec->flags |= 0x400000;
    self->unk_ec->flags |= 0x40000000;
    self->unk_ec->flags |= 0x4;
    func_0204ca70(self->unk_ec);
}
}
