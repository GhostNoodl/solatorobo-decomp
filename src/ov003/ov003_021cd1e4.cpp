#include "types.h"
#include "nitro/std.h"
#include "Main/Gfx/Model.h"
#include "Main/Res/ResArc.h"

class Ov003TlSub {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Move(s32 x, s32 y, s32 z);

    u32 unk_04;
    u8 unk_08[0xb0];
    u32 unk_b8;
};

typedef struct {
    u8 unk_00[4];
    u32 unk_04;
} Ov003TlRend;

class Ov003TlObj {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual s32 v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
};

class Ov003TlLabel : public Ov003TlObj {
public:
    u8 unk_04[8];
    u32 flags;
    u8 unk_10[0x10];
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2c;
    u8 unk_30[0x28];
    s32 unk_58;
    s32 unk_5c;
    s32 unk_60;
    s16 unk_64;
    s16 unk_66;
    s16 unk_68;
    u8 unk_6a[0x1a];
    Ov003TlSub *unk_84;
};

class Ov003Tl : public Ov003TlObj {
public:
    u8 unk_04[0x38];
    Ov003TlLabel *unk_3c;
    u8 unk_40[4];
    Model *unk_44;
    Model *unk_48;
    Model *unk_4c;
    char *unk_50;
    char *unk_54;
    u8 unk_58[4];
    u32 unk_5c;
    u8 unk_60[4];
    u16 unk_64;
    u16 unk_66;
    u8 unk_68;
    u8 unk_69;
    u8 unk_6a[0x22];
    char unk_8c[0x40];
};

extern "C" {

extern void *UiObj_vtbl[];
extern void *Lo021cadcc_vtbl[];
extern char data_ov003_021f78c4[];
extern char data_ov003_021f78cd[];
extern void *Heap_Alloc(u32 size);
extern const char *Param_Get(u16 id);
extern void Ov003_FormatMsg(void *self, char *dst, u32 size, const char *arg);
extern void Obj0215bb14_SetText(Ov003TlLabel *l, char *s);
extern ResList *ResMgr_GetArchiveList(const char *a, const char *b, u16 c);
extern void TexObj_SetAllOamFuncs(Model *s, void *cb);
extern void func_02041c18(Model *s, s32 a);
extern void TexObj_SetOamFuncArg(Model *s, u16 a, u16 b);
extern void TaskList_Insert(Ov003Tl *self);
extern void func_ov003_021cceb4(u32 a, u32 b, u32 c, u32 d, u32 unused, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
extern void *Ov003Oam_Offset(void *owner, u16 *flip, void *oam, u16 *count);
extern void func_ov000_021c8408(void *self, int x, int y, int z, u16 color, const void *oam, const void *tex, u32 texBase, u32 plttBase, const void *mtx, u32 arg);

static inline void Ov003Model_Init(Model *s, const char *file, const char *name) {
    PlttRes_Init_02041218(&s->pltt);
    TexObj_Init(s, name, 0);
    STD_CopyString(s->name, file);
}

static inline void Ov003Model_Load(Model *s, const char *file, const char *name) {
    TexObj_SetRes(s, ResList_FindType2(ResMgr_GetArchiveList(file, name, 2), name));
}

void Ov003TaskVt_021f78f4_Start(Ov003Tl *self);

#ifdef NONMATCHING
// Status (round auA): demoted in the honesty audit. The match wrapped TexObj_Init in an always-true `if (name)` (name
// is a string address) so name and file stay in callee-saved registers; unconditional, block, Ov003Model_Init and
// swapped-order forms all differ. This file is the function's whole .text, so it has no delinks entry. The score is
// in docs/UNMATCHED.md;
// the default build takes this function from the dsd gap. History: docs/MATCHING.md round auA.
void Ov003TaskVt_021f78f4_Start(Ov003Tl *self) {
    Ov003TlLabel *l;
    void *res;
    if (self->v28()) {
        return;
    }
    l = (Ov003TlLabel *)Heap_Alloc(0x8c);
    if (l != NULL) {
        *(void ***)l = UiObj_vtbl;
        l->v28();
        *(void ***)l = Lo021cadcc_vtbl;
        l->v28();
    }
    self->unk_3c = l;
    l->unk_20 = 2;
    self->unk_3c->unk_24 = 0xf8;
    {
        Ov003TlLabel *p = self->unk_3c;
        p->unk_64 = 3;
        p->unk_66 = 0x96;
        p->unk_68 = -0x1000;
    }
    {
        Ov003TlLabel *p = self->unk_3c;
        p->unk_58 = -0x100;
        p->unk_5c = 0;
        p->unk_60 = -0x1000;
    }
    self->unk_3c->unk_2c = 1;
    Ov003_FormatMsg(self, self->unk_8c, 0x40, Param_Get(self->unk_64));
    Obj0215bb14_SetText(self->unk_3c, self->unk_8c);
    self->unk_3c->v70();
    self->unk_3c->unk_84->unk_04 |= 0x4000000;
    {
        Ov003TlLabel *p = self->unk_3c;
        if (!(p->flags & 0x80000)) {
            p->unk_84->unk_b8 &= ~1;
        }
    }
    self->unk_3c->v08();
    {
        Ov003TlLabel *p = self->unk_3c;
        p->unk_84->Move(p->unk_64 + p->unk_24 - 0x14, p->unk_66 + p->unk_28 - 0xc, -0xfe0);
    }
    self->unk_3c->flags &= ~2;

    {
        Model *s = (Model *)Heap_Alloc(sizeof(Model));
        if (s != NULL) {
            Ov003Model_Init(s, self->unk_50, self->unk_54);
        }
        self->unk_44 = s;
    }
    res = ResMgr_GetArchiveList(self->unk_50, self->unk_54, 2);
    TexObj_SetRes(self->unk_44, ResList_FindType2(res, self->unk_54));
    self->unk_44->flags |= 2;
    self->unk_44->flags |= 0x80000;
    self->unk_44->unk_150 = -0x1ccd;
    TexObj_SetAllOamFuncs(self->unk_44, NULL);
    func_02041c18(self->unk_44, 0xa0a);
    self->unk_44->unk_158 = (void *)func_ov003_021cceb4;
    TexObj_SetOamFuncArg(self->unk_44, self->unk_5c, 0x7fff);
    TexObj_SelectImage(self->unk_44, 0, (u16)self->unk_5c);

    {
        Model *s = (Model *)Heap_Alloc(sizeof(Model));
        if (s != NULL) {
            Ov003Model_Init(s, self->unk_50, self->unk_54);
        }
        self->unk_48 = s;
    }
    res = ResMgr_GetArchiveList(self->unk_50, self->unk_54, 2);
    TexObj_SetRes(self->unk_48, ResList_FindType2(res, self->unk_54));
    self->unk_48->flags |= 2;
    self->unk_48->flags |= 0x80000;
    self->unk_48->unk_150 = -0x2000;
    TexObj_SetAllOamFuncs(self->unk_48, (void *)Ov003Oam_Offset);
    func_02041c18(self->unk_48, 0xa0a);
    self->unk_48->unk_158 = (void *)func_ov000_021c8408;

    {
        Model *s = (Model *)Heap_Alloc(sizeof(Model));
        if (s != NULL) {
            const char *name = data_ov003_021f78cd;
            const char *file = data_ov003_021f78c4;
            PlttRes_Init_02041218(&s->pltt);
            TexObj_Init(s, name, 0);
            STD_CopyString(s->name, file);
        }
        self->unk_4c = s;
    }
    res = ResMgr_GetArchiveList(data_ov003_021f78c4, data_ov003_021f78cd, 2);
    TexObj_SetRes(self->unk_4c, ResList_FindType2(res, data_ov003_021f78cd));
    self->unk_4c->flags |= 2;
    self->unk_4c->flags |= 0x80000;
    self->unk_4c->unk_150 = -0x2000;
    TexObj_SetAllOamFuncs(self->unk_4c, (void *)Ov003Oam_Offset);
    func_02041c18(self->unk_4c, 0xa0a);
    self->unk_4c->unk_158 = (void *)func_ov000_021c8408;
    {
        u16 i;
        u16 mask = self->unk_66;
        u16 n = (u16)(s16)self->unk_69;
        for (i = 0; i < n; i++) {
            if (i != self->unk_5c) {
                if (mask & (1 << i)) {
                    TexObj_SelectImage(self->unk_48, 0, i);
                } else {
                    TexObj_SelectImage(self->unk_4c, 0, i);
                }
            }
        }
    }
    TaskList_Insert(self);
}
#endif

}
