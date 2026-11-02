#include "ov000/LoCommon.h"
#include "ov000/MessageQueue.h"
#include "nitro/std.h"
#include "Main/Gfx/Model.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"

typedef struct {
    u8 c[3];
} Rgb021bbd94;

extern "C" {
extern void *data_02149ef8;
extern MessageQueue021cb980 *data_ov000_021ccd30;
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb5a8[];
char *MsgRes_GetString(void *msg, s32 id);
void func_ov000_02165a20(s32 a, Rgb021bbd94 *c);

static inline s32 Ccd30_Value(void) {
    void *p = data_ov000_021ccd30->unk_118;
    s32 r = 0;
    if (p != NULL && LFLD(s32, p, 0x28) == 1) {
        r = LFLD(s32, p, 0x30);
    }
    return r;
}

static inline void Rgb_Set(Rgb021bbd94 *c, u8 r, u8 g, u8 b) {
    c->c[0] = r;
    c->c[1] = g;
    c->c[2] = b;
}

struct Obj021bbd94 {
    u8 unk_00[0x8];
    char arcName[0x20];
    char fileName[0x20];
    u8 unk_48[0x10];
    Model *unk_58;
    Lo021cb5a8 *unk_5c;
    u8 unk_60[0x14];
    u8 unk_74;
    u8 unk_75;
    u8 unk_76;
};

void func_ov000_021bbd94(Obj021bbd94 *self) {
    void *msg = data_02149ef8;
    Lo021cb5a8 *t;
    Model *m;
    Rgb021bbd94 c;

    t = (Lo021cb5a8 *)Heap_Alloc(sizeof(Lo021cb5a8));
    if (t != NULL) {
        VOBJ_SET_VTABLE(t, data_ov000_021cac60);
        t->vfunc_28();
        VOBJ_SET_VTABLE(t, data_ov000_021caec8);
        t->vfunc_28();
        VOBJ_SET_VTABLE(t, data_ov000_021cb5a8);
        t->vfunc_28();
    }
    self->unk_5c = t;
    t->flags |= 0x4000000;
    self->unk_5c->slideMode = 1;
    {
        Lo021cb5a8 *p = self->unk_5c;
        p->slideX = 0x100;
        p->slideY = 0;
        p->slideZ = 0;
    }
    {
        Lo021cb5a8 *p = self->unk_5c;
        p->posX = 0;
        p->posY = 0;
        p->posZ = -0x89a;
    }
    self->unk_5c->flags |= 0x20000000;
    self->unk_5c->flags |= 0x80000000;
    self->unk_5c->vfunc_f4(2, MsgRes_GetString(msg, 0x33));
    self->unk_5c->vfunc_08();
    m = (Model *)Heap_Alloc(sizeof(Model));
    if (m != NULL) {
        func_02041218(&m->pltt);
        func_02041440(m, self->fileName, 0);
        STD_CopyString(m->name, self->arcName);
    }
    self->unk_58 = m;
    func_020417e0(self->unk_58, (void *)VOBJ_AT(self, 4)->vfunc_10());
    self->unk_58->flags |= 2;
    func_02041d9c(self->unk_58, 0, 0xffff);
    {
        s32 v = Ccd30_Value();
        Rgb_Set(&c, self->unk_74, self->unk_75, self->unk_76);
        func_ov000_02165a20(v, &c);
    }
}
}
