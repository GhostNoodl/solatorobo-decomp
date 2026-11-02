#include "ov000/LoCommon.h"
#include "nitro/std.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/Model.h"


extern "C" {
extern int data_02097d78[];
extern void *data_02097e4c;
extern char data_ov000_021cc879[];
char *func_02061f94(u16 id);
void func_020359fc(void *a, void *b, s32 c, s32 d);
BOOL func_02035bd4(void *a, void *b, s32 c);
void *func_02035f30(void *a, void *b, s32 c);
void *Heap_Alloc(u32 size);
void *func_02034d88(void *a, void *b);
BOOL func_02054f10(void *a, s32 b);
void func_02041d8c(void *model);
void *func_02049a48(void *a, s32 b, s32 c, s32 d, s32 e);
s32 FX_Div(s32 a, s32 b);

static inline BOOL FadeIdle021b8284(void) {
    BOOL r;
    if (data_02097d78[3] == 0 && data_02097d78[0] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

static inline BOOL Fade4_021b8284(void) {
    if (data_02097d78[3] == 4) {
        return TRUE;
    }
    return data_02097d78[0] == 4 ? TRUE : FALSE;
}

struct Obj021b8284 {
    u8 unk_00[0x4];
    char arcName[0x20]; // the part of func_02061f94's path before the separator
    char fileName[0x20]; // the part after it

    s32 unk_44;
    u16 unk_48;
    u8 unk_4a[0x2];
    Model *unk_4c;
    u32 unk_50;
    s32 unk_54;
    u16 unk_58;
};

BOOL func_ov000_021b8284(Obj021b8284 *self) {
    switch (self->unk_44) {
    case 1: {
        char *c;
        STD_CopyString(self->arcName, func_02061f94(self->unk_48));
        c = STD_SearchString(self->arcName, data_ov000_021cc879);
        *c = 0;
        STD_CopyString(self->fileName, c + 1);
        func_020359fc(self->arcName, self->fileName, 2, 0);
        {
            GfxSys *g = data_02097d48;
            g->unk_8b0_4 = 0;
            g->unk_8b0_5 = 1;
        }
        *(vu16 *)0x4000060 &= 0xcfdf;
        self->unk_44 = 2;
        break;
    }
    case 2:
        if (!func_02035bd4(self->arcName, self->fileName, 2)) {
            break;
        }
        self->unk_44 = 4;
    case 4: {
        void *res = func_02035f30(self->arcName, self->fileName, 2);
        Model *p;
        u16 i;
        if (!FadeIdle021b8284() && !Fade4_021b8284()) {
            break;
        }
        p = (Model *)Heap_Alloc(sizeof(Model));
        if (p != NULL) {
            func_02041218(&p->pltt);
            func_02041440(p, self->fileName, 1);
            STD_CopyString(p->name, self->arcName);
        }
        self->unk_4c = p;
        func_020417e0(self->unk_4c, func_02034d88(res, p->unk_04c));
        self->unk_4c->flags |= 2;
        {
            u8 *q = ((u8 *)self->unk_4c->res);
            self->unk_58 = q != NULL ? *LFLD(u16 *, q, 0xc) : 0;
        }
        for (i = 0; i < self->unk_58; i++) {
            func_02041d9c(self->unk_4c, 0, i);
        }
        self->unk_44 = 5;
        break;
    }
    case 5:
        if (!func_02054f10(self->unk_4c, 0xffff)) {
            break;
        }
        func_02041d8c(self->unk_4c);
        if (Fade4_021b8284()) {
            self->unk_50 = 0x3e7000;
        } else {
            func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
            self->unk_50 = 0;
        }
        self->unk_44 = 7;
        break;
    case 7:
        self->unk_50 += 0x1000;
        if (self->unk_50 >= 0xa000) {
            self->unk_50 = 0xa000;
            self->unk_54 = 0x1000;
        } else {
            self->unk_54 = FX_Div(self->unk_50, 0xa000);
            break;
        }
        self->unk_44 = 0xb;
        break;
    case 11:
        if (!LBIT(self, 0).b0) {
            break;
        }
        if (!FadeIdle021b8284()) {
            self->unk_50 = 0x3e7000;
        } else {
            func_02049a48(data_02097e4c, 0x28, -1, -1, -1);
            self->unk_50 = 0;
        }
        self->unk_44 = 0xd;
        break;
    case 13:
        self->unk_50 += 0x1000;
        if (self->unk_50 >= 0xa000) {
            self->unk_50 = 0xa000;
            self->unk_54 = 0x1000;
        } else {
            self->unk_54 = 0x1000 - FX_Div(self->unk_50, 0xa000);
            break;
        }
        if (FadeIdle021b8284() || Fade4_021b8284()) {
            self->unk_44 = 0xf;
        }
        break;
    case 15:
        LO_FREE_M(self, 0x4c);
        return FALSE;
    }
    return TRUE;
}
}
