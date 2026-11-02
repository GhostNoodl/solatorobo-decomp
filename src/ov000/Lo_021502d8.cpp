#include "ov000/LoCommon.h"
#include "ov000/SceneCmd.h"
#include "ov000/ObjLayouts.h"
#include "ov000/Task.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/Model.h"
#include "ov000/SceneRes.h"

extern "C" {

extern void *data_02fe152c;
extern void *data_02097e4c;
void *func_0205976c(void *a, s32 b);
u32 func_0205975c(void *a, s32 b);
u32 func_ov000_0214bf2c(u16 a);
u16 func_02059544(void *a, void *b, void *c, s32 d, s32 e);
BOOL StageRes_IsAllLoaded(void *p);
void func_0204c7d0(void *p);
void *Task_FindById(s32 kind);
Robo021ca458 *func_ov000_0219bf90(void);
void *func_02049a48(void *p, s32 a, s32 b, s32 c, s32 d);

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
} LoBits8;

typedef struct {
    u32 y : 8;
    u32 a : 8;
    u32 x : 9;
    u32 b : 7;
    u32 unk_04;
} LoOam;

static inline BOOL LoIsLoaded24(void) {
    BOOL r = TRUE;
    if (!StageRes_IsAllLoaded(data_ov000_021ccd24.unk_08)) {
        r = FALSE;
    }
    return r;
}

BOOL func_ov000_021502d8(Lo021ca9c4 *self) {
    BOOL r = TRUE;
    if (self->unk_42 == 0xffff) {
        if (!LoIsLoaded24()) {
            r = FALSE;
        }
    }
    if (!self->unk_3c->vfunc_2c()) {
        r = FALSE;
    }
    return r;
}

}


extern "C" {
extern void *data_02149ef8;
extern const char *data_ov000_021ca8d8[];
extern const char *data_0208cca0;
extern const char *data_0208cb74;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb5a8[];
extern u8 data_ov000_021cb4a8[];
extern u8 data_ov000_021caac8[];
extern char data_ov000_021ca93e[];
void *MsgRes_GetString(void *g, u32 id);
BOOL func_0205aa30(void *p);
void *func_02034d88(void *a, void *b);
void *func_02035d5c(void *a);
s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, BOOL f);
void func_0204ca70(void *p);
s32 func_02061e7c(u16 a);
void *func_0204c08c(void *a, u16 id, void *out, s32 n);
void func_0204c6bc(void *a, void *b, void *c, void *fn);
void func_02040a98(char *buf, s32 n);
SceneScript *func_ov000_021824d0(SceneStage *self, u16 index);
void func_ov000_02153f90(void *p);
void func_ov000_0214dc20(void *self, s32 *msg);
s32 func_ov000_02151610(VObj *self, s32 a, s32 b, s32 c);
void func_ov000_0215158c(void *self);

static inline void LoTextInit(u8 *t) {
    LFLD(s32, t, 0x4c) = Text_Measure(LFLD(s32, t, 0x28), LFLD(s32, t, 0x38), LFLD(s32, t, 0x24), t + 0x44, t + 0x48, LFLD(s8, t, 0x37) != 0);
    data_02097ce0->unk_004 = LFLD(s32, t, 0x28);
}

void func_ov000_02150338(Lo021ca9c4 *self) {
    Model *m;
    const char *arc;
    const char *name;
        VObj *o;
    void *g;
    u8 *p;
    void *out[2];
    char buf[0x100];
    self->unk_04 &= ~2;
    if (self->vfunc_28()) {
        return;
    }
    func_ov000_02173648(self);
    if (self->unk_42 == 0xffff) {
        if (!data_ov000_021ccd24.unk_08->vfunc_34()) {
            func_0205aa30(data_ov000_021ccd24.unk_08);
        }
    }
    m = (Model *)Heap_Alloc(sizeof(Model));
    if (m != NULL) {
        arc = data_ov000_021ca8d8[0];
        name = data_ov000_021ca8d8[1];
        func_02041218(&m->pltt);
        func_02041440(m, name, 0);
        STD_CopyString(m->name, arc);
    }
    self->unk_44 = m;
    func_020417e0(self->unk_44, func_02034d88((void *)self->unk_3c->vfunc_10(), (u8 *)self->unk_44 + 0x4c));
    self->unk_44->flags |= 2;
    func_02041d9c(self->unk_44, 0, 0);
    m = (Model *)Heap_Alloc(sizeof(Model));
    if (m != NULL) {
        arc = data_0208cca0;
        name = data_0208cb74;
        func_02041218(&m->pltt);
        func_02041440(m, name, 0);
        STD_CopyString(m->name, arc);
    }
    self->unk_48 = m;
    func_020417e0(self->unk_48, func_02034d88(func_02035d5c(m->name), self->unk_48->unk_04c));
    self->unk_48->flags |= 2;
    func_02041d9c(self->unk_48, 0, 0xb);
    g = data_02149ef8;
    if (self->unk_42 == 0xffff) {
        o = (VObj *)Heap_Alloc(0xe0);
        if (o != NULL) {
            *(void **)o = data_ov000_021cac60;
            o->vfunc_28();
            *(void **)o = data_ov000_021caec8;
            o->vfunc_28();
            *(void **)o = data_ov000_021cb5a8;
            o->vfunc_28();
        }
        self->unk_4c = (Lo021cb5a8 *)o;
        LFLD(u32, o, 0xc) |= 0x4000000;
        self->unk_4c->slideMode = 1;
        {
            UiList *t = (UiList *)self->unk_4c;
            t->slideX = 0x100;
            t->slideY = 0;
            t->slideZ = 0;
        }
        self->unk_4c->openLen = 0x6000;
        {
            UiList *t = (UiList *)self->unk_4c;
            t->posX = 0;
            t->posY = 0x11;
            t->posZ = -0x1ccd;
        }
        self->unk_4c->flags |= 0x20000000;
        self->unk_4c->flags |= 0x80000000;
        self->unk_4c->vfunc_f4(2, MsgRes_GetString(g, 0x33));
        self->unk_4c->vfunc_08();
    }
    o = (VObj *)Heap_Alloc(0xe4);
    if (o != NULL) {
        *(void **)o = data_ov000_021cac60;
        o->vfunc_28();
        *(void **)o = data_ov000_021caec8;
        o->vfunc_28();
        *(void **)o = data_ov000_021cb4a8;
        o->vfunc_28();
        *(void **)o = data_ov000_021caac8;
        o->vfunc_28();
    }
    self->unk_50 = (Lo021caac8 *)o;
    if (self->unk_42 == 0xffff) {
        self->unk_50->vfunc_10(MsgRes_GetString(g, 0x112));
        self->unk_50->vfunc_14(MsgRes_GetString(g, 0x113));
    }
    self->unk_50->owner = self;
    self->unk_50->rows = 3;
    {
        UiList *t = (UiList *)self->unk_50;
        t->posX = 0;
        t->posY = 0;
        t->posZ = -0x199a;
    }
    self->unk_50->unk_dc = 0x20;
    self->unk_50->openLen = 0x6000;
    LFLD(void *, self->unk_50, 0x7c) = (void *)func_ov000_02151610;
    LFLD(void *, self->unk_50, 0x78) = (void *)func_ov000_0215158c;
    self->unk_50->vfunc_a8(LFLD(s32, self->unk_50, 0x98));
    self->unk_50->vfunc_08();
    {
        UiList *t = (UiList *)self->unk_50;
        t->posX = 0;
        t->posY = 0;
        t->posZ = -0x199a;
    }
    p = (u8 *)Heap_Alloc(0x38);
    if (p != NULL) {
        func_ov000_02153f90(p);
        LFLD(u16, p, 0x30) = 0;
        LFLD(u16, p, 0x32) = 0;
        LFLD(u16, p, 0x34) = 0;
        LFLD(u16, p, 0x36) = 0;
    }
    self->unk_54 = p;
    if (self->unk_42 != 0xffff) {
        LFLD(u16, p, 6) = self->unk_42;
    } else {
        LFLD(u16, self->unk_54, 6) = func_ov000_021824d0(&SceneCmd_Get()->stage, 0)->id;
    }
    {
        void *r = func_0204c08c(data_ov000_021ccd24.unk_08->sub, LFLD(u16, self->unk_54, 6), out, 2);
        func_0204c6bc(out[0], r, self->unk_54, (void *)func_ov000_0214dc20);
    }

    self->unk_88 = 8;
    self->unk_84 = func_02061e7c(LFLD(u16, self->unk_54, 6));
    LoTextInit((u8 *)self + 0x60);
    self->unk_d4 = 0x7fff;
    self->unk_d6 = 0x67f;
    self->unk_d8 = 0x9000;
    self->unk_64 |= 0x40;
    self->unk_64 |= 0x1400000;
    self->unk_64 |= 0x40000004;
    func_0204ca70((u8 *)self + 0x60);

    self->unk_150 = 3;
    self->unk_140 = 8;
    self->unk_13c = MsgRes_GetString(data_ov000_021ccd24.unk_08->sub, LFLD(u16, self->unk_54, 6));
    LoTextInit((u8 *)self + 0x118);
    self->unk_11c |= 0x40;
    self->unk_11c |= 0x1000000;
    self->unk_11c |= 0x40000004;
    func_0204ca70((u8 *)self + 0x118);

    self->unk_1f8 = 8;
    self->unk_1f4 = MsgRes_GetString(g, 0x115);
    LoTextInit((u8 *)self + 0x1d0);
    self->unk_244 = 0x7fff;
    self->unk_246 = 0x67f;
    self->unk_248 = 0x9000;
    self->unk_1d4 |= 0x40;
    self->unk_1d4 |= 0x1400000;
    self->unk_1d4 |= 0x40000004;
    func_0204ca70((u8 *)self + 0x1d0);

    if (LFLD(u16, self->unk_54, 0x32) != 0) {
        func_02040a98(buf, LFLD(u16, self->unk_54, 0x32));
        STD_ConcatenateString(buf, data_ov000_021ca93e);
        STD_ConcatenateString(buf, (const char *)MsgRes_GetString(g, 0x3e));
    } else {
        STD_CopyString(buf, (const char *)out[1]);
    }
    self->unk_2ac = buf;
    self->unk_2b0 = 8;
    LoTextInit((u8 *)self + 0x288);
    self->unk_28c |= 0x40;
    self->unk_28c |= 0x1000000;
    self->unk_28c |= 0x4;
    func_0204ca70((u8 *)self + 0x288);

    self->unk_368 = 8;
    self->unk_364 = MsgRes_GetString(g, 0x116);
    LoTextInit((u8 *)self + 0x340);
    self->unk_3b4 = 0x7fff;
    self->unk_3b6 = 0x67f;
    self->unk_3b8 = 0x9000;
    self->unk_344 |= 0x40;
    self->unk_344 |= 0x1400000;
    self->unk_344 |= 0x40000004;
    func_0204ca70((u8 *)self + 0x340);

    {
        u16 n = LFLD(u16, self->unk_54, 0x34);
        if (n == 0) {
            n = 1;
        }
        func_02040a98(buf, n);
    }
    self->unk_420 = 8;
    self->unk_41c = buf;
    LoTextInit((u8 *)self + 0x3f8);
    self->unk_3fc |= 0x40;
    self->unk_3fc |= 0x1000000;
    self->unk_3fc |= 0x40000004;
    func_0204ca70((u8 *)self + 0x3f8);
}

}
