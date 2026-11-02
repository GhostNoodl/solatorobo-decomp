#include "ov015/ov015.h"

extern "C" {

extern char data_ov015_02213111[];
char *func_0207011c(u16 id);
u8 *func_0206fef8(u16 id);
u8 *func_02070744(u16 id);
extern char data_ov015_02213123[];
extern char data_ov015_0221312a[];
extern char data_ov015_02213131[];
extern char data_ov015_02213147[];
extern char data_ov015_0221314d[];
extern char data_ov015_02213158[];
extern u8 data_ov015_022131c4[];
extern u8 data_0208b318[];
extern u8 data_0208ba30[];
extern char data_ov015_02213163[];
extern char data_ov015_02213170[];
void func_0204bfcc(void *p);
void func_0204bfe4(void *p, const void *a, const void *b);

void func_ov015_0220f7a8(Ov015Result *self) {
    Ov015ResultPanel *o;
    if (data_ov002_021f0f9c != NULL) {
        func_ov002_021e8b3c(data_ov002_021f0f9c);
    }
    if (self->state < 0x14) {
        return;
    }
    o = self->panel;
    if (o == NULL) {
        return;
    }
    if (data_02097d48->unk_a30_4) {
        return;
    }
    if (o->unk_04 != NULL) VCALL(o->unk_04)->v20();
    if (o->unk_08 != NULL) VCALL(o->unk_08)->v20();
    if (o->unk_0c != NULL) VCALL(o->unk_0c)->v20();
    if (o->unk_10 != NULL) VCALL(o->unk_10)->v20();
    if (o->unk_14 != NULL) VCALL(o->unk_14)->v20();
}

struct Ov015ItemBitsF878 {
    u16 lo : 5;
    u16 kind : 3;
    u16 hi : 8;
};
// File names of the result stage's objects, one per data_ov015_02213368->unk_2c.
struct Ov015ResFile {
    char *arc;
    char *name;
};
struct Ov015ResNamePair { Ov002ResName v[2]; };
struct Ov015ResNameOne { Ov002ResName v[1]; }; // e and f are filled by a block copy
struct Ov015ResFilePair { Ov015ResFile v[2]; };
extern const Ov015ResNamePair data_ov015_022130d0;
extern const Ov015ResFilePair data_ov015_02213038;
extern const Ov015ResFilePair data_ov015_02213048;
extern const Ov015ResNamePair data_ov015_02213088;
extern const Ov015ResNameOne data_ov015_02212fb8;
extern const Ov015ResNameOne data_ov015_02212fdc;
extern char data_ov015_0221311c[];
void func_ov015_0220f878(Ov015Result *self) {
    Ov015StageMdl *o;
    u16 id;
    char *name;
    switch (*(u16 *)func_02070744(data_ov015_02213368->catchId)) {
    case 0:
        func_ov002_021e9e40(3);
        break;
    case 1:
        func_ov002_021e9e40(4);
        break;
    case 2:
    case 3:
        func_ov002_021e9e40(5);
        break;
    }
    o = (Ov015StageMdl *)Heap_Alloc(sizeof(Ov015StageMdl));
    if (o != NULL) {
        o = (Ov015StageMdl *)func_ov015_0220dde8(o);
    }
    o->unk_18 = 0;
    o->unk_1c = 0x96000;
    o->unk_08 = 3;
    id = data_ov015_02213368->catchId;
    name = func_0207011c(id);
    {
        u8 *info = func_0206fef8(id);
        u16 k = FLD(Ov015ItemBitsF878, info, 0x12).kind;
        o->unk_510 = name;
        o->unk_514 = data_ov015_02213111;
        o->unk_3a4 = k;
    }
    o->unk_498 = id;
    func_ov015_0220e570(o, data_ov015_0221311c, 0, 0, 0x1000);
    {
        Ov002ResName a[2];
        Ov015ResFile b[2];
        Ov015ResFile c[2];
        Ov002ResName d[2];
        Ov002ResName e;
        Ov002ResName f;
        s32 n;
        Ov002Obj021f07d4 *p5;
        Ov002Obj021f07d4 *p4;
        Ov002Obj021f075c *t;
        *(Ov015ResNamePair *)a = data_ov015_022130d0;
        *(Ov015ResFilePair *)b = data_ov015_02213038;
        *(Ov015ResFilePair *)c = data_ov015_02213048;
        *(Ov015ResNamePair *)d = data_ov015_02213088;
        *(Ov015ResNameOne *)&e = data_ov015_02212fb8;
        *(Ov015ResNameOne *)&f = data_ov015_02212fdc;
        n = data_ov015_02213368->unk_2c;
        p5 = (Ov002Obj021f07d4 *)func_ov002_021e91c8(0, 0x96000, 3, 0, 0);
        p4 = (Ov002Obj021f07d4 *)func_ov002_021e91c8(0, 0x96000, 3, 0, 0);
        p5->res.arc = a[n].arc;
        p5->res.name = a[n].name;
        p5->res.item = a[n].item;
        t = (Ov002Obj021f075c *)func_ov002_021e92b0(0, 0x50000, 3, 0, 0x1000);
        t->res = e;
        t->owner = p5;
        func_ov002_021e4dac(p5, t);
        t = (Ov002Obj021f075c *)func_ov002_021e92b0(0, 0x96000, 3, 0, 0x1000);
        t->unk_04 = 3;
        t->res = f;
        t->owner = p5;
        func_ov002_021e4dac(p5, t);
        p4->res.arc = b[n].arc;
        p4->res.name = b[n].name;
        p4->res.item = NULL;
        func_ov002_021e50d8(p4, c[n].arc, c[n].name);
        t = (Ov002Obj021f075c *)func_ov002_021e92b0(0, 0x78000, 3, 0, 0x1000);
        t->res.arc = d[n].arc;
        t->res.name = d[n].name;
        t->res.item = d[n].item;
        t->owner = p4;
        func_ov002_021e4dac(p4, t);
    }
}

struct Ov015ItemBits {
    u16 lo : 5;
    u16 kind : 3;
    u16 hi : 8;
};
void func_ov015_0220fb78(Ov015Result *self) {
    Ov015StageMdl *o;
    Ov002Obj021f075c *t;
    u16 id;
    char *name;
    func_ov002_021e9e40(6);
    o = (Ov015StageMdl *)Heap_Alloc(sizeof(Ov015StageMdl));
    if (o != NULL) {
        o = (Ov015StageMdl *)func_ov015_0220dde8(o);
    }
    o->unk_18 = 0;
    o->unk_1c = 0x168000;
    o->unk_08 = 3;
    id = data_ov015_02213368->catchId;
    name = func_0207011c(id);
    {
        u8 *info = func_0206fef8(id);
        u16 k = FLD(Ov015ItemBits, info, 0x12).kind;
        o->unk_510 = name;
        o->unk_514 = data_ov015_02213111;
        o->unk_3a4 = k;
    }
    o->unk_498 = id;
    func_ov015_0220e570(o, data_ov015_02213123, 0x78000, 0, 0x800);
    func_ov015_0220e570(o, data_ov015_0221312a, 0x168000, 1, 0x1000);
    t = (Ov002Obj021f075c *)func_ov002_021e92b0(0, 0x78000, 3, 0, 0x800);
    t->res.arc = data_ov015_02213131;
    t->res.name = data_ov015_02213147;
    t->res.item = data_ov015_0221314d;
    t->unk_04 = 3;
    func_ov002_021e4dac(o, t);
    t->owner = o;
    t = (Ov002Obj021f075c *)func_ov002_021e92b0(0x79000, 0x168000, 3, 1, 0x1000);
    t->res.arc = data_ov015_02213131;
    t->res.name = data_ov015_02213147;
    t->res.item = data_ov015_02213158;
    t->unk_04 = 3;
    func_ov002_021e4dac(o, t);
    t->owner = o;
}

void *Ov015Msg_Ctor(Ov015Msg *self) {
    SET_VT(self, data_ov015_022131c4);
    self->unk_04 = 0;
    self->msgIdx = 0;
    self->msgRes = NULL;
    self->model = NULL;
    self->textWin = NULL;
    self->posX = 0;
    self->posY = -0x100000;
    self->posZ = 0;
    self->label = NULL;
    self->textBox = NULL;
    MIi_CpuClear32(0, self->pages, 0x80);
    self->pageCount = 0;
    self->page = 0;
    MIi_CpuClearFast(0, self->text, 0x80);
    self->seq = 0;
    self->step = 0;
    self->timer = 0;
    self->unk_08 = 0;
    return self;
}

void *Ov015Msg_Dtor(Ov015Msg *self) {
    void *saved;
    SET_VT(self, data_ov015_022131c4);
    HEAP_PUSH(saved);
    DELETE_V(self->msgRes);
    HEAP_POP(saved);
    {
    void *saved2;
    HEAP_PUSH(saved2);
    {
    Model *o = self->model;
    if (o != NULL) {
        if (o != NULL) {
            func_02041558(o);
            func_02041278(&o->pltt);
            Heap_Free(o);
        }
        self->model = NULL;
    }
    }
    HEAP_POP(saved2);
    }

    HEAP_PUSH(saved);
    DELETE_V(self->textWin);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->label);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->textBox);
    HEAP_POP(saved);

    return self;
}

void *Ov015Msg_DtorDelete(Ov015Msg *self) {
    void *saved;
    SET_VT(self, data_ov015_022131c4);
    HEAP_PUSH(saved);
    DELETE_V(self->msgRes);
    HEAP_POP(saved);
    {
    void *saved2;
    HEAP_PUSH(saved2);
    {
    Model *o = self->model;
    if (o != NULL) {
        if (o != NULL) {
            func_02041558(o);
            func_02041278(&o->pltt);
            Heap_Free(o);
        }
        self->model = NULL;
    }
    }
    HEAP_POP(saved2);
    }

    HEAP_PUSH(saved);
    DELETE_V(self->textWin);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->label);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->textBox);
    HEAP_POP(saved);

    Heap_Free(self);
    return self;
}

static inline void Ov015_SetSeq(Ov015Msg *self, s32 n) {
    self->seq = n;
    self->step = 0;
    self->timer = 0;
}
BOOL func_ov015_02210014(Ov015Msg *self) {
    BOOL r = TRUE;
    switch (self->seq) {
    case 0:
        VCALL(self)->v14();
        Ov015_SetSeq(self, self->seq + 1);
    case 1:
        if (VCALL(self)->v18()) {
            Ov015_SetSeq(self, 10);
        }
        break;
    case 10:
        if (VCALL(self)->v1c()) {
            Ov015_SetSeq(self, 20);
        }
        break;
    case 20:
        if (VCALL(self)->v20()) {
            self->unk_08 = 0;
            Ov015_SetSeq(self, 30);
        }
        break;
    case 30:
        if (!VCALL(self)->v24()) {
            VCALL(self)->v28();
            self->unk_08 = 0;
            Ov015_SetSeq(self, 40);
        }
        break;
    case 40:
        if (VCALL(self)->v2c()) {
            Ov015_SetSeq(self, 50);
        }
        break;
    case 50:
        r = FALSE;
        break;
    }
    return r;
}

void func_ov015_0221015c(Ov015Msg *self) {
    TextWin *p;
    if (!data_02097d48->unk_a30_4) {
        return;
    }
    if (self->label != NULL) {
        VCALL(self->label)->v20();
    }
    if (self->textBox != NULL) {
        VCALL(self->textBox)->v20();
    }
    if (self->model != NULL) {
        Model *m = self->model;
        m->x = self->posX;
        m->y = self->posY;
        Ov015Model_PlayPart(self->model, 0x1d, 0);
    }
    p = self->textWin;
    if (p == NULL) {
        return;
    }
    p->unk_vf20(((self->posX >> 12) + 0x80) - (s32)p->width / 2, ((self->posY >> 12) + 0x60) - (s32)p->height / 2);
    self->textWin->Render();
}

void func_ov015_02210298(Ov015Msg *self) {
    void *p = Heap_Alloc(0x58);
    if (p != NULL) {
        SET_VT(p, data_0208b318);
        VCALL(p)->v08();
        SET_VT(p, data_0208ba30);
        func_0204bfcc(p);
    }
    self->msgRes = p;
    func_0204bfe4(p, data_ov015_02213163, data_ov015_02213170);
}

void func_ov015_022102fc(Ov015Msg *self) {
    VCALL(self->msgRes)->v2c();
}


extern void *data_0208cc88;
extern void *data_0208cc94;
extern void *data_02149ef8;
extern u8 data_0208ba70[];
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cadcc[];
extern u8 data_ov015_02212d3c[];
BOOL func_0204c030(void *p);
s32 func_0204c08c(void *p, u16 id, void *buf, s32 n);
void *func_02035de0(void *a, void *b);
void func_0204c7d0(void *p);
void *MsgRes_GetString(void *a, s32 b);
u32 Text_Measure(u32 a, u32 b, u32 c, u32 *outW, u32 *outH, BOOL d);
void func_0204ca70(void *p);
void func_ov015_02208544(Ov015UiText *self);
s32 func_0204c2f4(void *p, s32 n, void *src);
void func_ov000_0215bb14(void *a, void *b);
void func_ov015_0220866c(Ov015UiText *self, void *msg);

static inline void Ov015T_SetPos(UiObj *o, s16 x, s16 y, s16 z) {
    o->posX = x;
    o->posY = y;
    o->posZ = z;
}

static inline void Ov015T_SetSlide(UiObj *o, s32 x, s32 y, s32 z) {
    o->slideX = x;
    o->slideY = y;
    o->slideZ = z;
}

BOOL func_ov015_02210314(Ov015Msg *self) {
    u8 *p;
    func_0204c030(self->msgRes);
    self->pageCount = func_0204c08c(self->msgRes, self->msgIdx, self->pages, 0x20);
    p = (u8 *)Heap_Alloc(0x160);
    if (p != NULL) {
        void *file = data_0208cc94;
        void *name = data_0208cc88;
        func_02041218((PlttRes *)(p + 0x88));
        func_02041440((Model *)p, (char *)name, 0);
        STD_CopyString((char *)(p + 0x2c), (char *)file);
    }
    self->model = (Model *)p;
    func_020417e0(self->model, func_02035de0(data_0208cc94, data_0208cc88));
    self->model->flags |= 2;
    func_02041d9c((Model *)(self->model), 0, 0x1d);
    self->model->unk_150 = -0xccd;
    {
        TextWin *w = (TextWin *)Heap_Alloc(0xb8);
        if (w != NULL) {
            SET_VT(w, data_0208ba70);
            func_0204c7d0(w);
        }
        self->textWin = w;
        w->font = 4;
        {
            void *t = MsgRes_GetString(data_02149ef8, 0x118);
            w = self->textWin;
            w->str = (u32)t;
            w->unk_4c = Text_Measure(w->font, w->spacing, w->str, &w->width, &w->height, (s8)w->unk_37 != 0);
            data_02097ce0->unk_004 = w->font;
        }
    }
    self->textWin->color0 = 0x7fff;
    self->textWin->color1 = 0x67f;
    self->textWin->unk_78 = 0x7000;
    self->textWin->flags |= 0x40;
    self->textWin->flags |= 0x1000000;
    self->textWin->unk_vf14();
    self->textWin->unk_4_8 = 0x1e;
    self->textWin->flags |= 0x40000000;
    self->textWin->flags |= 4;
    func_0204ca70(self->textWin);
    p = (u8 *)Heap_Alloc(0x8c);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov000_021cadcc);
        VCALL(p)->v28();
    }
    FLD(u8 *, self, 0x28) = p;
    FLD(s32, p, 0x24) = 0xf8;
    Ov015T_SetSlide(self->label, -0x100, 0, -0xccd);
    self->label->slideMode = 1;
    self->label->flags |= 0x80000;
    self->label->rows = 3;
    Ov015T_SetPos(self->label, 4, 0x86, -0xccd);
    VCALL(self->label)->v08();
    p = (u8 *)Heap_Alloc(0xb4);
    if (p != NULL) {
        SET_VT(p, data_ov000_021cac60);
        VCALL(p)->v28();
        SET_VT(p, data_ov015_02212d3c);
        func_ov015_02208544((Ov015UiText *)p);
    }
    self->textBox = (Ov015UiText *)p;
    Ov015T_SetPos((UiObj *)p, 0, 0x7b, -0x99a);
    Ov015T_SetSlide(self->textBox, -0x100, 0, -0x99a);
    self->textBox->slideMode = 1;
    self->textBox->flags &= ~0x10000;
    VCALL(self->textBox)->v08();
    if (self->label != NULL && self->pages[0] != NULL) {
        u8 *o;
        func_0204c2f4(self->text, 0x80, self->pages[0]);
        func_ov000_0215bb14(self->label, self->text);
        VCALL(self->label)->v70();
        FLD(u32, self->label->unk_84, 0x4) |= 0x4000000;
        o = ((u8 *)self->label);
        VCALL(FLD(u8 *, o, 0x84))->v1c(FLD(s16, o, 0x64) + FLD(s32, o, 0x24) - 0x14, FLD(s16, o, 0x66) + FLD(s32, o, 0x28) - 0xc, -0xcbd);
        func_ov015_0220866c(self->textBox, self->pages[0]);
    }
    return TRUE;
}

}
